#!/usr/bin/env python3
"""In-guest trace gate: record real game states for trace replay with every target armed at once
(docs/tasks/ingame-trace.md; docs/equivalence.md, "Trace replay").

  tools/trace_gate.py --session g1 --script build/replays/play2.json [--minutes 10] [--until-polls N]
                      [--per-func 30] [--burst 5] [--spread-polls 1800] [--matches-sample 300] [--also FILE]
  tools/trace_gate.py --census-only --session c1 ...      # only count which targets run, and when (no captures)
  tools/trace_gate.py --session g2 --script R.json --from-frame 9000 [--shard 0/2]   # start from a VM snapshot
  tools/trace_gate.py --session g2 --merge g2a g2b         # one session from parallel shards

tools/trace_capture.py arms a GDB breakpoint on each target's entry, at most --window (96) at a time, because
QEMU slows down with every breakpoint set; a function that runs only briefly is recorded only if it happens to
be armed then. Here the build itself does the arming (tools/patch_xbe.py trace_stubs): every target's entry
jumps to a small trampoline that counts the call in a per-function table in the guest and, only when the host
asked for that call, stops at one shared gate address -- the single permanent breakpoint -- with every register
as it was at the function's entry. The host then records the call exactly as trace_capture.py does (CallCapture:
the original bytes co-simulated in Unicorn, pages read from the paused game per memory epoch, callee results,
the self-check), so the sessions have the same format and tools/equiv_replay.py replays them unchanged. Calls
the host did not ask for run at full speed.

Which calls are recorded (per function, at most --per-func): the first --burst calls, then one more each time
the game has advanced --spread-polls pad polls (about a minute of play) since the last one. The table also gives
a census of every target: how often it ran and the poll/frame of its first call (session.json "census").

Checkpoints: with a recording (tools/hybrid_test.py record) as --script, the game's checkpoint hashes are read
from g_hybrid as it runs and compared with the recorded ones (session.json "checkpoints"), so a session that
left the recorded path shows where.

Captures go to build/traces/SESSION/trace.sqlite (never committed: game data). One xemu at a time; it always
runs with -snapshot and a copied config (tools/hybrid_run.py). No screenshots: the QMP framebuffer read is what
wedges xemu during loads (see trace_capture.py --shot-every).
"""
import argparse
import json
import os
import struct
import sys
import threading
import time
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv  # noqa: E402
import equiv_replay as er  # noqa: E402
import hybrid_run  # noqa: E402
import hybrid_test  # noqa: E402
import patch_xbe  # noqa: E402
import trace_capture as tc  # noqa: E402
from trace_capture import Abort, CallCapture, CapGdb, MAX_DEPTH, SYNC_TIMEOUT  # noqa: E402

ROOT = equiv.ROOT
NEVER = patch_xbe.NEVER


def default_targets(matches_sample=300, also=None):
    """The targets a default run arms (Capture.targets without a session): for recording builds that carry the
    trampolines (tools/hybrid_test.py record)."""
    class _A:
        pass
    a = _A()
    a.matches_sample, a.also, a.shard = matches_sample, also, None
    o = tc.Capture.__new__(tc.Capture)
    o.a, o.prog = a, equiv.Program.get()
    return tc.Capture.targets(o)


def merge_sessions(out, sessions):
    """One session from several (e.g. parallel --shard runs): calls, pages, per-function stats; the configs and
    censuses side by side. equiv_replay.py reads the result like any session."""
    dst_dir = os.path.join(er.TRACES, out)
    if os.path.exists(os.path.join(dst_dir, "trace.sqlite")):
        raise SystemExit("%s exists" % dst_dir)
    os.makedirs(dst_dir, exist_ok=True)
    dst = er.TraceStore(dst_dir, create=True)
    configs, census, totals = [], {}, Counter()
    for sname in sessions:
        sdir = sname if os.path.isdir(sname) else os.path.join(er.TRACES, sname)
        src = er.TraceStore(sdir)
        for sha, data in src.db.execute("SELECT sha, data FROM pages"):
            dst.db.execute("INSERT OR IGNORE INTO pages VALUES (?, ?)", (sha, data))
        for row in src.db.execute("SELECT func, n, ok, data FROM calls"):
            if dst.db.execute("SELECT 1 FROM calls WHERE func = ? AND n = ?", row[:2]).fetchone():
                # (the demoted/wanted targets are in every shard): number its calls on after the others
                n = dst.db.execute("SELECT MAX(n) FROM calls WHERE func = ?", row[:1]).fetchone()[0] + 1
                row = (row[0], n) + tuple(row[2:])
            dst.db.execute("INSERT INTO calls VALUES (?, ?, ?, ?)", row)
            totals["calls"] += 1
        for row in src.db.execute("SELECT * FROM funcs"):
            old = dst.db.execute("SELECT hits, captured, failed FROM funcs WHERE func = ?", row[:1]).fetchone()
            if old:
                row = (row[0], row[1] + old[0], row[2] + old[1], row[3] + old[2], row[4])
            dst.db.execute("INSERT OR REPLACE INTO funcs VALUES (?, ?, ?, ?, ?)", row)
        configs.append(dict(src.meta("config") or {}, session=os.path.basename(os.path.normpath(sdir))))
        for f, v in (src.meta("census") or {}).items():
            c = census.get(f)
            census[f] = v if not c else [c[0] + v[0], min(c[1], v[1]), min(c[2], v[2])]
        targets = dict(dst.meta("targets") or {})
        targets.update(src.meta("targets") or {})
        dst.meta("targets", targets)
    dst.meta("config", {"recorder": "gate", "merged": configs})
    dst.meta("census", census)
    dst.commit()
    rep = {"session": out, "from": sessions, "calls": totals["calls"],
           "functions": len(dst.funcs()), "census_reached": len(census)}
    json.dump(rep, open(os.path.join(dst_dir, "session.json"), "w"), indent=1)
    return rep


class GateCapture(tc.Capture):
    """trace_capture.Capture with the in-guest gate instead of rotating entry breakpoints."""

    # -- the gate ----------------------------------------------------------------------------------
    def gate_log(self, f, what):
        if self.a.log_gates:
            self.log.write("%7.1fs gate %#x esp=%#x %s\n" % (time.time() - self.t0, f, self.gate_esp, what))

    def gate_hit(self, r):
        """At the gate: which function, and send the guest on to its displaced entry code. Returns f (or None)."""
        tr = self.man["trace"]
        busy, fn, cont = struct.unpack("<3I", self.g.read(tr["hdr"], 12))
        self.g.cmd("P8=%s" % struct.pack("<I", cont).hex())         # eip = the trampoline's displaced code
        self.g.write(tr["hdr"], b"\0\0\0\0")                          # busy = 0: the next gate may be taken
        self.stats["gates"] += 1
        i, rem = divmod(fn - tr["table"], tr["entry_bytes"])
        if rem or not 0 <= i < len(self.funcs):
            self.say("gate: bad entry %#x (cont %#x)" % (fn, cont))
            return None
        f = self.funcs[i]
        r["eip"] = f
        self.gate_esp = r["esp"]
        return f

    def set_next(self, f, v):
        tr = self.man["trace"]
        self.g.write(tr["table"] + tr["entry_bytes"] * self.index[f] + 4, struct.pack("<I", v & 0xFFFFFFFF))
        self.next_state[f] = v

    def budget_left(self, f):
        return f not in self.heavy and super().budget_left(f)

    def arm(self, f):                   # the next call of f stops at the gate
        if self.next_state.get(f) != 0:
            self.set_next(f, 0)
            self.armed_at[f] = time.time()

    def disarm(self, f):
        if self.next_state.get(f) != NEVER:
            self.set_next(f, NEVER)

    def fill(self):
        return 0

    def rotate(self):
        return 0

    # -- capture loop --------------------------------------------------------------------------------
    def cont_until(self, cc, pred, diverged=None):
        """trace_capture.Capture.cont_until, with target hits arriving through the gate."""
        t0 = time.time()
        t_end = t0 + SYNC_TIMEOUT
        nested_s = 0.0
        try:
            self.step_off_bp()      # (trace_capture.Capture.cont_until: a guest sitting on a breakpoint)
            while True:
                left = t_end + nested_s - time.time()
                if left <= 0:
                    cc.abort("the game did not get there in %ds%s" % (SYNC_TIMEOUT, getattr(cc, "near", None) and " [callee-saved: %s]" % cc.near or ""))
                rep = self.g.cont_timeout(left)
                if rep is None:
                    cc.abort("the game did not get there in %ds%s" % (SYNC_TIMEOUT, getattr(cc, "near", None) and " [callee-saved: %s]" % cc.near or ""))
                if not rep.startswith(("T", "S")):
                    cc.abort("stop reply %r" % rep[:40])
                r = self.g.regs_full()
                self.stats["stops"] += 1
                if pred(r):
                    return r
                if diverged and diverged(r):
                    cc.abort("the game took another path (returned at %#x)%s" % (r["eip"], getattr(cc, "near", None) and " [callee-saved: %s]" % cc.near or ""))
                cc.stops = getattr(cc, "stops", 0) + 1
                if self.a.max_stops and cc.stops > self.a.max_stops:
                    # a function whose call runs much of the game (a frame, a load) costs a stop per callee
                    # return and gate; it is given up for the session (the guest just carries on)
                    self.heavy.add(cc.f)
                    cc.abort("over %d stops (heavy: not captured again)" % self.a.max_stops)
                if r["eip"] == self.gate:
                    t1 = time.time()
                    f = self.gate_hit(r)
                    if f is None:
                        continue
                    if cc.depth + 1 < MAX_DEPTH and abs(r["esp"] - cc.cur_e) < 0x10000 and self.budget_left(f):
                        self.on_hit(f, r, cc.depth + 1)       # nested, in the callee
                        nested_s += time.time() - t1
                        r = self.g.regs_full()
                        if pred(r):
                            return r
                        if diverged and diverged(r):
                            cc.abort("the game took another path (returned at %#x)%s" % (r["eip"], getattr(cc, "near", None) and " [callee-saved: %s]" % cc.near or ""))
                        if r["eip"] in self.g.bps and r["eip"] != self.gate:
                            self.g.step_over(r["eip"])
                        continue
                    # another thread, or too deep: this call runs uncaptured; f waits for the outer capture
                    self.gate_log(f, "skipped (depth %d, esp %#x from the capture's)" % (cc.depth, abs(r["esp"] - cc.cur_e)))
                    self.disarm(f)
                    self.parked.add(f)
                    self.stats["gates_skipped"] += 1
                    nested_s += time.time() - t1
                elif r["eip"] in self.g.bps:
                    self.stepped[r["eip"]] += 1
                    self.g.step_over(r["eip"])
                else:
                    self.stepped["other"] += 1
        finally:
            self.stats["guest_s"] += time.time() - t0 - nested_s

    def on_hit(self, f, regs, depth):
        self.hits[f] += 1
        if not self.budget_left(f):
            self.disarm(f)
            return
        self.disarm(f)          # (while capturing: a recursive call is nested through the parked set)
        t1 = time.time()
        stops0 = self.stats["stops"]
        cc = CallCapture(self, f, regs, depth)
        if depth == 0:
            why = cc.run(regs)
        else:
            box = []
            t = threading.Thread(target=lambda: box.append(cc.run(regs)), daemon=True)
            t.start()
            t.join()
            why = box[0] if box else "nested capture crashed"
        dt = time.time() - t1
        if depth == 0:
            self.stats["capture_s"] += dt
        self.stats["captures_depth%d" % depth] += 1
        if why is None:
            self.captured[f] += 1
            self.consec_fail[f] = 0
        else:
            self.failed[f] += 1
            self.consec_fail[f] += 1
            self.fail_why.setdefault(f, []).append(why)
            if self.failed[f] <= 2:
                self.say("%#x (%s) capture failed: %s" % (f, self.tgt[f], why))
        self.since_arm[f] += 1
        self.last_cap[f] = self.polls or 0
        if self.budget_left(f) and self.since_arm[f] < self.a.burst:
            self.arm(f)
        nst = self.stats["stops"] - stops0
        if (dt > 20 or nst > 2000) and depth == 0:
            self.say("%#x took %.0fs, %d stops" % (f, dt, nst))

    def rearm_spread(self):
        """More calls of functions already captured: those that rested --spread-polls polls since their last
        capture get their next call, as many as the --duty budget allows (the share of wall time spent capturing
        over the last interval), the least-captured first. First calls are never throttled: they are the reach."""
        if self.polls is None:
            return
        now = time.time()
        dt = max(1e-3, now - self.duty_t)
        spent = self.stats["capture_s"] - self.duty_cap
        self.duty_t, self.duty_cap = now, self.stats["capture_s"]
        n_cap = sum(self.captured.values()) + sum(self.failed.values())
        avg = self.stats["capture_s"] / n_cap if n_cap else 0.2
        room = self.a.duty * dt - spent + self.duty_debt
        self.duty_debt = max(-30.0, min(0.0, room))     # (overspent: the next intervals pay some of it back)
        if room <= 0:
            return
        want = [f for f, p in self.last_cap.items()
                if self.next_state.get(f) == NEVER and f not in self.parked and self.budget_left(f)
                and self.polls - p >= self.a.spread_polls]
        want.sort(key=lambda f: (self.captured[f] + self.failed[f], self.last_cap[f]))
        for f in want[:max(0, int(room / max(avg, 1e-3)))]:
            self.since_arm[f] = self.a.burst - 1          # one more call, then rest again
            self.arm(f)
            self.stats["spread_arms"] += 1

    # -- census and checkpoints ----------------------------------------------------------------------
    def read_census(self):
        tr = self.man["trace"]
        raw = self.g.read_pages(tr["table"], tr["entry_bytes"] * len(self.funcs))
        hdr = self.g.read_safe(tr["hdr"], 4 * len(tr["hdr_fields"]))
        if hdr:
            self.gate_hdr = dict(zip(tr["hdr_fields"], struct.unpack("<%dI" % len(tr["hdr_fields"]), hdr)))
        if raw is None:
            return
        for i, f in enumerate(self.funcs):
            cnt, _nxt, p0, fr0 = struct.unpack_from("<4I", raw, tr["entry_bytes"] * i)
            if cnt:
                self.census[f] = (cnt, p0, fr0)

    def read_checkpoints(self):
        lay = self.man["g_hybrid_layout"]
        base = self.man["g_hybrid"]
        n = struct.unpack("<I", self.g.read(base + 4 * 7, 4))[0]
        if n <= self.ck_seen:
            return
        k = min(n - self.ck_seen, lay["ckpt_ring"])
        raw = self.g.read_pages(base + lay["ckpt"], 8 * lay["ckpt_ring"])
        for j in range(n - k, n):
            fr, h = struct.unpack_from("<II", raw, 8 * (j % lay["ckpt_ring"]))
            self.ckpts[fr] = h
        self.ck_seen = n

    def ckpt_summary(self):
        if not self.want_ck:
            return None
        common = sorted(set(self.ckpts) & set(self.want_ck))
        bad = [f for f in common if self.ckpts[f] != self.want_ck[f]]
        return {"recorded": len(self.want_ck), "seen": len(self.ckpts), "common": len(common),
                "matching": len(common) - len(bad), "first_divergence": bad[0] if bad else None,
                "last_frame": max(self.ckpts) if self.ckpts else None}

    def housekeeping(self, force=False):
        now = time.time()
        self.feed_ring()
        if force or now - self.last_hk >= 10:
            self.last_hk = now
            hdr = self.g.read_safe(self.man["g_hybrid"], 4 * len(hybrid_run.CTL_FIELDS))
            if hdr:
                st = dict(zip(hybrid_run.CTL_FIELDS, struct.unpack("<%dI" % len(hybrid_run.CTL_FIELDS), hdr)))
                self.polls, self.frame = st["polls"], st["frame"]
            try:
                self.read_census()
                self.read_checkpoints()
            except (IOError, struct.error) as e:
                self.say("census read failed: %r" % e)
            if not self.a.census_only:
                self.rearm_spread()
                for p in list(self.parked):
                    if self.budget_left(p):
                        self.arm(p)
                self.parked = set()
            reached = sum(1 for f in self.tgt if self.captured.get(f))
            ck = self.ckpt_summary()
            self.timeline.append({"t": round(now - self.t0), "polls": self.polls, "frame": self.frame,
                                  "functions_captured": reached, "calls": sum(self.captured.values()),
                                  "census_reached": len(self.census)})
            self.say("polls=%s frame=%s reached=%d functions=%d calls=%d failed=%d | gates=%d skipped=%d stops=%d "
                     "pages=%d guest=%.0fs capture=%.0fs nested=%d%s" % (
                         self.polls, self.frame, len(self.census), reached, sum(self.captured.values()),
                         sum(self.failed.values()), self.stats["gates"], self.stats["gates_skipped"],
                         self.stats["stops"], self.stats["pages"], self.stats["guest_s"], self.stats["capture_s"],
                         sum(v for k, v in self.stats.items() if k.startswith("captures_depth") and k[-1] != "0"),
                         "" if not ck else " | ckpts %d/%d match%s" % (
                             ck["matching"], ck["common"],
                             "" if ck["first_divergence"] is None else ", first diverged at frame %d"
                             % ck["first_divergence"])))
            self.flush_stats()

    def flush_stats(self):
        super().flush_stats()
        with self.store_lock:
            self.store.meta("census", {"0x%08x" % f: list(v) for f, v in sorted(self.census.items())})
            self.store.commit()

    # -- session -------------------------------------------------------------------------------------
    def run(self):
        a = self.a
        self.tgt = self.targets()
        if a.only:
            keep = patch_xbe.read_addr_file(a.only)
            self.tgt = {f: k for f, k in self.tgt.items() if f in keep}
        if a.from_snapshot is not None or a.from_frame is not None:
            return self.run_resumed()
        hooks = hybrid_test.hooks_cfg(a.script, vclock=True)
        if "pollkey" not in hooks["flags"]:
            hooks["flags"].append("pollkey")
        self.feed = None
        doc = json.load(open(a.script)) if a.script else None
        if isinstance(doc, dict) and len(doc.get("inputs", [])) > patch_xbe.INPUT_MAX:
            hooks["replay"] = doc["inputs"]
            self.feed = {"entries": doc["inputs"], "avail": patch_xbe.INPUT_MAX}
        self.want_ck = {f: h for f, h in doc.get("checkpoints", [])} if isinstance(doc, dict) else {}
        self.end_polls = a.until_polls or (doc.get("polls") if isinstance(doc, dict) else None)
        xbe = os.path.join(self.session, "capture.xbe")
        first = NEVER if a.census_only else 0
        self.man = patch_xbe.build([], xbe, tweaks=hybrid_test.TWEAKS, hooks=hooks,
                                   trace={"targets": sorted(self.tgt), "next": first})
        tr = self.man["trace"]
        self.gate = tr["gate"]
        self.funcs = [e[0] for e in tr["functions"]]
        self.index = {f: i for i, f in enumerate(self.funcs)}
        self.next_state = {f: first for f in self.funcs}
        for f in list(self.tgt):
            if f not in self.index:
                del self.tgt[f]
        hybrid_run.install(xbe)
        self.store.meta("config", {"recorder": "gate", "script": os.path.relpath(a.script, ROOT),
                                   "per_func": a.per_func, "burst": a.burst, "spread_polls": a.spread_polls,
                                   "minutes": a.minutes, "census_only": a.census_only,
                                   "targets": dict(Counter(self.tgt.values())),
                                   "not_trampolined": tr["rejected"]})
        self.store.meta("targets", {"0x%08x" % f: k for f, k in self.tgt.items()})
        self.t0 = time.time()
        self.x = hybrid_run.Xemu("trace-" + a.session, True, ["-S"])
        self.g = CapGdb()
        return self.loop(tr)

    def run_resumed(self):
        """Start from one of the recording's VM snapshots (tools/hybrid_test.py record --snap-every): its build
        carries a trampoline for every default target with the entry left alone; arm this run's targets by writing
        their entry jmps and table entries, then go on as usual."""
        a = self.a
        doc = json.load(open(a.script))
        snap = hybrid_test.find_snapshot(doc, a.from_snapshot, a.from_frame)
        self.t0 = time.time()
        self.resumed = hybrid_test.resume_snapshot(doc, snap, "trace-" + a.session, gdb_cls=CapGdb)
        self.x, self.g, self.man = self.resumed["x"], self.resumed["g"], self.resumed["man"]
        tr = self.man["trace"]
        if tr.get("entries_patched", True):
            raise SystemExit("this recording's build has its trampolines armed already")
        self.gate = tr["gate"]
        entry = {e[0]: e for e in tr["functions"]}
        self.funcs = [e[0] for e in tr["functions"]]
        self.index = {f: i for i, f in enumerate(self.funcs)}
        self.tgt = {f: k for f, k in self.tgt.items() if f in entry}
        first = NEVER if a.census_only else 0
        self.next_state = {f: NEVER for f in self.funcs}
        # the table: next for this run's targets (the others stay NEVER and keep their original entries)
        raw = bytearray(self.g.read_pages(tr["table"], tr["entry_bytes"] * len(self.funcs)))
        for f in self.tgt:
            struct.pack_into("<I", raw, tr["entry_bytes"] * self.index[f] + 4, first & 0xFFFFFFFF)
            self.next_state[f] = first
        for o in range(0, len(raw), 2040):
            self.g.write(tr["table"] + o, bytes(raw[o:o + 2040]))
        for f in sorted(self.tgt):                       # entry -> trampoline (QEMU drops the stale translations)
            tva = entry[f][2]
            self.g.write(f, b"\xe9" + struct.pack("<i", tva - (f + 5)))
        n = len(doc["inputs"])
        self.feed = {"entries": doc["inputs"], "avail": self.resumed["avail"]} if n > self.resumed["avail"] else None
        self.want_ck = {f: h for f, h in doc.get("checkpoints", []) if f > snap["frame"]}
        self.end_polls = a.until_polls or doc.get("polls")
        self.store.meta("config", {"recorder": "gate", "script": os.path.relpath(a.script, ROOT),
                                   "snapshot": {k: snap.get(k) for k in ("tag", "frame", "polls", "ckpt")},
                                   "shard": a.shard, "per_func": a.per_func, "burst": a.burst,
                                   "spread_polls": a.spread_polls, "minutes": a.minutes,
                                   "census_only": a.census_only, "targets": dict(Counter(self.tgt.values())),
                                   "not_trampolined": tr["rejected"]})
        self.store.meta("targets", {"0x%08x" % f: k for f, k in self.tgt.items()})
        self.say("resumed snapshot %s (frame %d) in %.1f s; armed %d targets" % (
            snap["tag"], snap["frame"], self.resumed["resume_s"], len(self.tgt)))
        try:
            return self.loop(tr)
        finally:
            if os.path.exists(self.resumed["clone"]):
                os.unlink(self.resumed["clone"])

    def loop(self, tr):
        a = self.a
        self.armed = set()              # (trace_capture's entry breakpoints: none here)
        self.parked = set()
        self.armed_at = {}
        self.pinned = set()
        self.last_cap = {}
        self.heavy = set()
        self.duty_t, self.duty_cap, self.duty_debt = time.time(), 0.0, 0.0
        self.census = {}
        self.gate_hdr = {}
        self.ckpts, self.ck_seen = {}, 0
        self.polls = self.frame = None
        self.last_hk = self.last_arm = time.time()
        self.last_shot = float("inf")
        self.say("trampolined %d targets (%s; %d not: %s)" % (
            len(self.funcs), dict(Counter(self.tgt.values())), len(tr["rejected"]),
            dict(Counter(v.split(" (")[0].split(" at ")[0] for v in tr["rejected"].values()))))
        self.g.bp_on(self.gate)
        stop_at = self.t0 + 60 * a.minutes
        end_why = "time"
        try:
            while time.time() < stop_at:
                if not self.x.alive():
                    end_why = "xemu exited (%s)" % self.x.p.returncode
                    self.say(end_why)
                    break
                if self.end_polls and self.polls is not None and self.polls >= self.end_polls:
                    end_why = "reached poll %d" % self.end_polls
                    break
                rep = self.g.cont_timeout(2.0)
                if rep is None:
                    self.housekeeping()
                    continue
                r = self.g.regs_full()
                if r["eip"] == self.gate:
                    f = self.gate_hit(r)
                    if f is not None:
                        self.gate_log(f, "depth 0")
                    if f is not None and not a.census_only:
                        self.on_hit(f, r, 0)
                        for p in self.parked:
                            if self.budget_left(p):
                                self.arm(p)
                        self.parked = set()
                    elif f is not None:
                        self.disarm(f)
                    self.housekeeping()
                elif r["eip"] in self.g.bps:
                    self.g.step_over(r["eip"])
        except (ConnectionError, OSError) as e:
            end_why = "gdb connection lost: %r" % e
            self.say(end_why)
        finally:
            try:
                self.housekeeping(force=True)
            except Exception:
                pass
            self.flush_stats()
            try:
                self.g.close()
            except Exception:
                pass
            self.x.close()
        rep = self.report()
        rep["end"] = end_why
        json.dump(rep, open(os.path.join(self.session, "session.json"), "w"), indent=1)
        print(json.dumps({k: v for k, v in rep.items() if k not in ("timeline", "not_reached", "census",
                                                                    "checkpoint_hashes", "reached_not_captured")},
                         indent=1))
        return rep

    def report(self):
        rep = super().report()
        kinds = rep["kinds"]
        for f, k in self.tgt.items():
            kinds[k].setdefault("census_reached", 0)
            kinds[k]["census_reached"] += f in self.census
        rep["recorder"] = "gate"
        rep["heavy"] = ["0x%08x" % f for f in sorted(self.heavy)]
        rep["polls"], rep["frame"] = self.polls, self.frame
        rep["gate"] = self.gate_hdr
        rep["checkpoints"] = self.ckpt_summary()
        rep["checkpoint_hashes"] = sorted([f, h] for f, h in self.ckpts.items())
        rep["census"] = {"0x%08x" % f: list(v) for f, v in sorted(self.census.items())}
        # reached by the census but never captured (budget, failures, or only on another thread)
        rep["reached_not_captured"] = ["0x%08x" % f for f in sorted(self.census) if not self.captured.get(f)]
        rep["not_reached"] = ["0x%08x" % f for f, k in sorted(self.tgt.items())
                              if k == "equivalent" and f not in self.census]
        return rep


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--session", default=time.strftime("g%Y%m%d-%H%M"))
    ap.add_argument("--minutes", type=float, default=30)
    ap.add_argument("--until-polls", type=int, default=None, help="stop once the game has made this many pad polls "
                    "(default: the end of a recording given as --script)")
    ap.add_argument("--per-func", type=int, default=30, help="recorded calls per function")
    ap.add_argument("--burst", type=int, default=1, help="the first calls of each function recorded back to back")
    ap.add_argument("--spread-polls", type=int, default=1800, help="after the burst, one more call each time the game "
                    "has advanced this many pad polls (about 1 per frame)")
    ap.add_argument("--duty", type=float, default=0.5, help="share of wall time spent on further calls of functions "
                    "already captured (first calls are always captured); the rest lets the game move on")
    ap.add_argument("--max-stops", type=int, default=3000, help="give up a call after this many guest stops (callee "
                    "returns, gates); its function is then not captured again (0: no limit)")
    ap.add_argument("--max-fail", type=int, default=10, help="give up on a function after this many failed captures")
    ap.add_argument("--matches-sample", type=int, default=300, help="matched functions to capture as controls")
    ap.add_argument("--script", default=tc.DEFAULT_SCRIPT)
    ap.add_argument("--also", default=None, help="file of extra addresses to capture")
    ap.add_argument("--only", default=None, help="file of addresses: record only these targets (e.g. "
                    "build/traces/capture-wanted.txt)")
    ap.add_argument("--log-gates", action="store_true", help="log every gate stop to capture.log (diagnostics)")
    ap.add_argument("--census-only", action="store_true", help="no captures: only count which targets run, and when")
    ap.add_argument("--from-snapshot", type=int, help="start from the --script recording's VM snapshot K "
                    "(tools/hybrid_test.py record --snap-every; negative: from the end)")
    ap.add_argument("--from-frame", type=int, help="start from the recording's latest snapshot at or before this frame")
    ap.add_argument("--shard", help="K/N: a disjoint slice of the targets, for parallel runs (HULK_XEMU_INSTANCE)")
    ap.add_argument("--merge", nargs="+", metavar="SESSION", help="merge these sessions into --session and exit")
    a = ap.parse_args(argv)
    if a.merge:
        print(json.dumps(merge_sessions(a.session, a.merge), indent=1))
        return 0
    # (Capture.targets reads these)
    a.unseen, a.window, a.rotate, a.shot_every = False, 0, 0, 0
    port = "tcp::%d" % hybrid_run.GDB_PORT
    if any("xemu" in l and port in l.split() for l in os.popen("ps -axo command").read().splitlines()):
        raise SystemExit("another xemu is using this instance's GDB port %s (set HULK_XEMU_INSTANCE)" % port)
    GateCapture(a).run()
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
