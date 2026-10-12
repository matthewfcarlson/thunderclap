#!/usr/bin/env python3
"""Record real game states for trace-driven equivalence (docs/equivalence.md, "Trace replay").

  tools/trace_capture.py --session play1 [--minutes 20] [--per-func 50] [--burst 5] [--rearm 45]
                         [--matches-sample 300] [--script tests/replays/capture-gameplay.json]
  tools/trace_capture.py --write-script        # regenerate the default input script

Boots the ORIGINAL game (the hooks-only build: fixed frame time, constant RNG seed, scripted pad input keyed
by pad polls; skip-intro and no-fmv) in xemu with the GDB stub, with a breakpoint on the entry of every
function in equivalent/ (plus the known-wrong ones in build/farm/equiv-demoted/ and a sample of matches, as
controls). For each hit, up to --per-func calls per function (--burst at a time, re-armed every --rearm
seconds so samples spread over the session), it co-simulates the call:

  * the function's original bytes run in Unicorn (equiv.py's Run, as in level 3) from the real registers and
    stack; every page it touches is read from the paused guest when first touched in a memory epoch, and
    recorded;
  * at each call Unicorn would stub, the real game runs the callee (a breakpoint on the return address,
    checked against esp and the callee-saved registers); its eax/edx/ecx, x87 result and the bytes it changed
    in the caller's frame (located relative to the pointer arguments, so a different frame layout can replay
    them) are recorded and fed back to Unicorn; pages touched afterwards are re-read (the next epoch);
  * at the end the game runs to the function's return, and Unicorn's result (registers, esp, the memory
    written since the last call) must equal the game's: the capture's self-check.

A captured function hit again inside a callee is captured too (nested, up to MAX_DEPTH; its Unicorn run gets
its own thread), otherwise its breakpoint is parked until the outer capture is done.

Captures go to build/traces/SESSION/trace.sqlite (never committed: game data). Replay with
tools/equiv_replay.py. One xemu at a time; it always runs with -snapshot and a copied config.
"""
import argparse
import json
import os
import random
import socket
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
from equiv import CALLEE_SAVED, PAGE, STACK_HI, STACK_LO  # noqa: E402
from xemu_gdb import Gdb  # noqa: E402

ROOT = equiv.ROOT
DEFAULT_SCRIPT = os.path.join(ROOT, "tests/replays/capture-gameplay.json")
CAP_STEPS = 400000          # Unicorn steps per captured call (the real data can loop long)
SYNC_TIMEOUT = 60           # seconds the game may take inside one callee (nested captures not counted)
BELOW = 0x2000              # guest stack bytes read below esp at each sync
MAX_DEPTH = 3               # nested captures
NO_FETCH = [(0xF0000000, 0x100000000)]       # MMIO (NV2A, APU, ...): never read through the stub
GDB_TIMEOUT = 60


class Abort(Exception):
    pass


# ---------------------------------------------------------------------------------------------
# GDB: full registers, breakpoint bookkeeping, timeouts everywhere, stale stop replies skipped.
class CapGdb(Gdb):
    def __init__(self, *a, **kw):
        super().__init__(*a, **kw)
        self.bps = set()
        self.ops = 0
        self.lock = threading.RLock()

    def _recv_packet(self, timeout=GDB_TIMEOUT):
        self.s.settimeout(timeout)
        try:
            return super()._recv_packet()
        finally:
            self.s.settimeout(None)

    def cmd(self, data):
        with self.lock:
            self._send(data)
            while True:
                r = self._recv_packet()
                if r[:1] in ("W", "X"):
                    raise ConnectionError("the guest exited: %s" % r)
                if r[:1] in ("T", "S") and data[:1] not in ("?", "c", "s"):
                    continue                # a stale stop reply (an interrupt that crossed a breakpoint stop)
                return r

    def bp_on(self, a):
        if a not in self.bps:
            self.ops += 1
            self.set_break(a)
            self.bps.add(a)

    def bp_off(self, a):
        if a in self.bps:
            self.ops += 1
            self.clear_break(a)
            self.bps.discard(a)

    def regs_full(self):
        r = bytes.fromhex(self.cmd("g"))
        names = ("eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi", "eip", "eflags")
        d = dict(zip(names, struct.unpack_from("<10I", r)))
        st = [struct.unpack_from("<QH", r, 64 + 10 * i) for i in range(8)]
        d["fctrl"], d["fstat"], d["ftag"] = struct.unpack_from("<III", r, 144)
        d["st0"] = equiv._x87_value(st[(d["fstat"] >> 11) & 7])     # (QEMU sends physical registers)
        return d

    def cont_timeout(self, timeout):
        """Continue; the stop reply, or None after `timeout` seconds (the guest is then interrupted)."""
        with self.lock:
            self._send("c")
            try:
                return self._recv_packet(timeout)
            except socket.timeout:
                self.interrupt()
                self._recv_packet(30)
                return None

    def step_over(self, a):
        with self.lock:
            self.ops += 2
            self.clear_break(a)
            self._send("s")
            self._recv_packet(30)
            self.set_break(a)

    def read_safe(self, addr, n):
        try:
            return self.read(addr, n)
        except IOError:
            return None

    def read_pages(self, addr, n, must=None):
        """Bytes [addr, addr+n), page by page; unreadable pages read as zeros. None if the page holding `must`
        is unreadable."""
        out = bytearray()
        a = addr
        while a < addr + n:
            k = min(addr + n - a, PAGE - (a & 0xFFF))
            b = self.read_safe(a, k)
            if b is None:
                if must is not None and a <= must < a + k:
                    return None
                b = bytes(k)
            out += b
            a += k
        return bytes(out)


# ---------------------------------------------------------------------------------------------
def insn_known(c):
    return c.get("known", True)


class CallCapture:
    """One captured call: the TraceRun syncer (sync/finish) and the end-of-call self-check."""

    def __init__(self, cap, f, regs, depth):
        self.cap, self.f, self.depth = cap, f, depth
        self.g = cap.g
        self.entry_g = regs["esp"]
        self.abort_why = None
        self.noreturn = False
        self.final_regs = None
        self.cur_e = self.entry_g

    def abort(self, why):
        self.abort_why = self.abort_why or why
        raise Abort(why)

    def to_guest(self, u):
        return (self.entry_g + (u - equiv.ENTRY_ESP)) & 0xFFFFFFFF

    def to_unicorn(self, g):
        return equiv.ENTRY_ESP + (g - self.entry_g)

    def g_stack(self, v):
        """A Unicorn stack value as the game's address (other values unchanged)."""
        return self.to_guest(v) if STACK_LO <= v < STACK_HI else v

    def cont_until(self, pred, diverged=None):
        try:
            return self.cap.cont_until(self, pred, diverged)
        except Abort as e:
            self.abort_why = self.abort_why or str(e)
            raise

    # -- TraceRun syncer interface
    def sync(self, run, insn, target, tail, k, esp):
        rec = {"target": target, "at": insn.addr, "tail": tail}
        self.rec["results"].append(rec)
        if insn.target is not None and self.cap.prog.noreturn(target):
            rec["noreturn"] = True
            self.noreturn = True
            return rec
        e_g = self.to_guest(esp)
        self.cur_e = e_g
        want = {r: self.g_stack(run.reg(r)) for r in CALLEE_SAVED}
        entry_g, ret_g = self.entry_g, self.ret_g
        if tail:
            ret = ret_g

            def ok(r):
                return r["eip"] == ret_g and entry_g < r["esp"] <= entry_g + 0x404 and \
                    all(r[x] == want[x] for x in CALLEE_SAVED)
            diverged = None
        else:
            ret = insn.addr + insn.size
            self.cap.bp_temp(ret, True)

            def ok(r):
                return r["eip"] == ret and e_g <= r["esp"] <= e_g + 0x1000 and \
                    all(r[x] == want[x] for x in CALLEE_SAVED)

            def diverged(r):
                return r["eip"] == ret_g and entry_g < r["esp"] <= entry_g + 0x404
        try:
            regs = self.cont_until(ok, diverged)
        finally:
            if not tail:
                self.cap.bp_temp(ret, False)
        rec["_regs"] = regs
        rec["st0"] = regs["st0"]
        if tail:
            self.final_regs = regs
        else:
            top_g = entry_g + 4 + 4 * er.STACK_WORDS
            g = self.g.read_pages(e_g, top_g - e_g, must=e_g)
            if g is None:
                self.abort("could not read the game's stack at %#x" % e_g)
            rec["_frame"] = (e_g, g)
        return rec

    def base_for(self, run, u, k):
        """(pointer key, offset) placing Unicorn stack address u relative to a pointer this call got: an argument
        or a register pointing at most BASE_REACH below u (the nearest one)."""
        best = None
        c = run.calls[k]
        ext = (self.cap.prog.callee_writes(c["target"]) or {}) if c.get("known", True) else {}
        cands = [(("arg", j), v, ext.get(j, 0)) for j, (v, _) in enumerate(c["args"])] + \
                [(("reg", r), c["regs"][r], ext.get(r, 0)) for r in ("ecx", "edx", "eax", "esi", "edi", "ebx")]
        for key, v, w in cands:
            reach = er.BASE_REACH       # (the nearest pointer below: the object the callee wrote into)
            if STACK_LO <= v <= u and u - v < reach and (best is None or v > best[1]):
                best = (key, v)
        if best is None:
            return ("entry",), u - equiv.ENTRY_ESP
        return best[0], u - best[1]

    def encode(self, run, v, k):
        e = self.entry_g
        if e - er.FRAME_BELOW <= v < e:
            key, off = self.base_for(run, self.to_unicorn(v), k)
            return ("ptr", key, off)
        return ("raw", v)

    def finish(self, run, rec, snap, esp, k, tail):
        regs = rec.pop("_regs")
        for r in ("eax", "edx", "ecx"):
            rec[r] = self.encode(run, regs[r], k)
        rec["delta"], rec["fills"] = [], []
        if tail:
            return
        e_g, g = rec.pop("_frame")
        # Unicorn's frame equals the game's before the call (it started from the game's stack and takes the
        # game's frame after every call), so what differs now is what the callee wrote
        rec["frame"] = (esp - equiv.ENTRY_ESP, g)
        n = min(len(g), len(snap))
        runs = []
        ra = equiv.ENTRY_ESP - esp          # the return-address slot: the game's caller vs Unicorn's sentinel
        for i in range(n):
            if g[i] != snap[i] and not ra <= i < ra + 4:
                if runs and runs[-1][1] == i:
                    runs[-1][1] = i + 1
                else:
                    runs.append([i, i + 1])
        for i0, i1 in runs:
            key, off = self.base_for(run, esp + i0, k)
            rec["delta"].append((key, off, bytes(g[i0:i1])))
        # a callee may write a value that was there already: also keep what its static write extent covers
        # through each pointer into the frame (equiv.py's stubs fill the same extents)
        c = run.calls[k]
        if insn_known(c):
            for loc, w in (self.cap.prog.callee_writes(c["target"]) or {}).items():
                v = c["args"][loc][0] if isinstance(loc, int) and loc < len(c["args"]) else \
                    c["regs"].get(loc) if isinstance(loc, str) else None
                if v is None or not (esp <= v < esp + n):
                    continue
                w = min(w, 0x400, esp + n - v)
                key, off = self.base_for(run, v, k)
                rec["fills"].append((key, off, bytes(g[v - esp:v - esp + w])))
        run.seg_stack_w.clear()

    # -- the whole call
    def run(self, regs):
        cap, g, f = self.cap, self.g, self.f
        oview, own_float = cap.view(f)
        esp = regs["esp"]
        lo = esp - BELOW
        top_g = esp + 4 + 4 * er.STACK_WORDS
        raw = g.read_pages(lo, top_g - lo, must=esp)
        if raw is None:
            return "stack unreadable"
        self.ret_g = ret_g = struct.unpack_from("<I", raw, esp - lo)[0]
        stack = list(struct.unpack_from("<%dI" % er.STACK_WORDS, raw, esp + 4 - lo))
        pop = cap.prog.callee_pop(f)
        nargs = cap.prog.callee_stack_args(f)
        if nargs is None:
            nargs = (pop or 0) // 4
        n = cap.captured.get(f, 0) + cap.failed.get(f, 0)
        self.rec = rec = {
            "func": f, "n": n, "results": [], "pages": {},
            "entry": {"regs": {r: regs[r] for r in ("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp")},
                      "stack": stack, "own_args": min(nargs, er.STACK_WORDS), "own_pop": pop,
                      "fpcw": regs["fctrl"] & 0xFFFF, "esp_g": esp, "ret_g": ret_g, "below": raw[:esp - lo]},
            "context": {"t": round(time.time() - cap.t0, 1), "polls": cap.polls, "frame": cap.frame,
                        "depth": self.depth}}
        prev_esp = er.set_entry_esp(esp)
        cap.bp_temp(ret_g, True)
        mach = er.TraceMemory(cap.prog, fetch=cap.fetch_page)
        inp = er.make_input(rec["entry"])
        run = er.TraceRun(cap.prog, oview, mach, inp, ours_image=None, sig=None, max_steps=CAP_STEPS,
                          own_float_ret=own_float, coverage=True, helpers=cap.helpers, trace=rec, side="orig",
                          syncer=self)
        run.pointee_sizes, run.convs, run.slot_arity, run.loop_limits, run.varargs = {}, {}, {}, {}, set()
        why = None
        o = None
        try:
            o = run.run(f)
            if self.abort_why:
                why = self.abort_why
            elif o["status"] != "ret":
                why = "the original's run: %s" % o["status"]
            elif mach.bad:
                why = "unreadable page %#x" % min(mach.bad)
            elif not self.noreturn:      # (a call that never returns: compared up to it)
                why = self.final_check(run, o)
        except Abort as e:
            why = self.abort_why or str(e)
        finally:
            cap.bp_temp(ret_g, False)
            equiv.ENTRY_ESP = prev_esp
        rec["selfcheck"] = why or "ok"
        if why is None:
            rec["outcome"] = {"status": o["status"], "targets": [x["target"] for x in o["calls"]],
                              "eax": o["eax"], "edx": o["edx"], "st0": o["st0"], "fdepth": o["fdepth"],
                              "noreturn": bool(o.get("noreturn")), "writes": dict(o["segments"][-1])}
            rec["pages"] = {key: cap.store.put_page(b) for key, b in mach.captured.items()}
            rec["steps"] = len(run.executed)
        with cap.store_lock:
            cap.store.put_call(f, n, rec)
        return why

    def final_check(self, run, o):
        entry_g, ret_g = self.entry_g, self.ret_g
        want = {r: self.g_stack(o["saved"][r]) for r in CALLEE_SAVED}
        want_esp = self.to_guest(o["esp"])
        if run.ended_by_tail:
            r = self.final_regs
        else:
            r = self.cont_until(lambda r: r["eip"] == ret_g and entry_g < r["esp"] <= entry_g + 0x404
                                and all(r[x] == want[x] for x in CALLEE_SAVED))
        if r["esp"] != want_esp:
            return "esp after return %#x, Unicorn %#x" % (r["esp"], want_esp)
        if r["eax"] != self.g_stack(o["eax"]) or r["edx"] != self.g_stack(o["edx"]):
            return "returned eax=%#x edx=%#x, Unicorn %#x %#x" % (r["eax"], r["edx"], o["eax"], o["edx"])
        if o["fdepth"] and o["st0"] is not None and r["st0"] == r["st0"] and \
                not equiv._feq(r["st0"], o["st0"], 1e-4, 1e-6):
            return "returned st0=%r, Unicorn %r" % (r["st0"], o["st0"])
        if run.ended_by_tail:
            return None
        pages = {}
        for a, v in o["segments"][-1].items():
            p = a & ~0xFFF
            if p not in pages:
                pages[p] = self.cap.fetch_page(p)
            if pages[p] is None or pages[p][a - p] != v:
                return "memory at %#x is %s in the game, %#x in Unicorn" % (
                    a, "unreadable" if pages[p] is None else "%#x" % pages[p][a - p], v)
        return None


# ---------------------------------------------------------------------------------------------
class Capture:
    def __init__(self, args):
        self.a = args
        self.prog = equiv.Program.get()
        self.session = os.path.join(er.TRACES, args.session)
        os.makedirs(self.session, exist_ok=True)
        self.store = er.TraceStore(self.session, create=True)
        self.store_lock = threading.Lock()
        self.helpers = dict(equiv.HELPERS)
        self.helpers.update({a: n for n, a in equiv.crt_table(self.prog).items()})
        self.views = {}
        self.hits, self.captured, self.failed, self.consec_fail = Counter(), Counter(), Counter(), Counter()
        self.fail_why = {}
        for f, st in self.store.func_stats().items():       # resume a session
            self.hits[f], self.captured[f], self.failed[f] = st["hits"], st["captured"], st["failed"]
        self.since_arm = Counter()
        self.log = open(os.path.join(self.session, "capture.log"), "a")
        self.timeline = []
        self.stats = Counter()
        self.depth = 0
        self.temp = Counter()           # temporary breakpoints (return addresses) -> users

    def say(self, msg):
        line = "%7.1fs %s" % (time.time() - self.t0, msg)
        print(line, file=sys.stderr, flush=True)
        self.log.write(line + "\n")
        self.log.flush()

    # -- targets ---------------------------------------------------------------------------------
    def targets(self):
        """{addr: kind}: equivalent/, the demoted (known wrong) ones, and a sample of matches."""
        out = {}
        for _, a in er.sources("equivalent"):
            out[a] = "equivalent"
        dem = os.path.join(ROOT, "build/farm/equiv-demoted")
        if os.path.isdir(dem):
            for f in os.listdir(dem):
                if f.startswith("0x") and f.endswith(".cpp"):
                    out.setdefault(int(f[:-4], 16), "demoted")
        ms = [a for _, a in er.sources("matches") if self.prog.funcs.get(a, (0,))[0] >= 24 and a not in out]
        random.Random(1).shuffle(ms)
        for a in ms[:self.a.matches_sample]:
            out[a] = "match"
        return {a: k for a, k in out.items() if a in self.prog.funcs and self.prog.is_code(a)}

    def view(self, f):
        v = self.views.get(f)
        if v is None:
            size = self.prog.funcs[f][0]
            v = equiv.CodeView(self.prog.read, f, (f, f + size), self.prog).build()
            used, _ = self.prog.callers_use_return(f)
            fl = used == "st0" or equiv.ghidra_ret_kind(f) in ("f32", "f64")
            v = self.views[f] = (v, fl)
        return v

    # -- guest -----------------------------------------------------------------------------------
    def fetch_page(self, page):
        if any(lo <= page < hi for lo, hi in NO_FETCH):
            return None
        self.stats["pages"] += 1
        return self.g.read_safe(page, PAGE)

    def bp_temp(self, a, on):
        if on:
            self.temp[a] += 1
            self.g.bp_on(a)
        else:
            self.temp[a] -= 1
            if self.temp[a] <= 0:
                del self.temp[a]
                if a not in self.armed:
                    self.g.bp_off(a)

    def arm(self, f):
        if f not in self.armed:
            self.g.bp_on(f)
            self.armed.add(f)

    def disarm(self, f):
        if f in self.armed:
            self.armed.discard(f)
            if f not in self.temp:
                self.g.bp_off(f)

    def budget_left(self, f):
        return self.captured[f] < self.a.per_func and self.failed[f] < self.a.max_fail and self.consec_fail[f] < 4

    def cont_until(self, cc, pred, diverged=None):
        t0 = time.time()
        t_end = t0 + SYNC_TIMEOUT
        nested_s = 0.0
        try:
            while True:
                left = t_end + nested_s - time.time()
                if left <= 0:
                    cc.abort("the game did not get there in %ds" % SYNC_TIMEOUT)
                rep = self.g.cont_timeout(left)
                if rep is None:
                    cc.abort("the game did not get there in %ds" % SYNC_TIMEOUT)
                if not rep.startswith(("T", "S")):
                    cc.abort("stop reply %r" % rep[:40])
                r = self.g.regs_full()
                self.stats["stops"] += 1
                if pred(r):
                    return r
                if diverged and diverged(r):
                    cc.abort("the game took another path (returned at %#x)" % r["eip"])
                if r["eip"] in self.armed:
                    t1 = time.time()
                    if cc.depth + 1 < MAX_DEPTH and abs(r["esp"] - cc.cur_e) < 0x10000:
                        self.on_hit(r["eip"], r, cc.depth + 1)       # nested, in the callee
                        nested_s += time.time() - t1
                        # the nested capture ends at its return address, which may be the one we wait for
                        r = self.g.regs_full()
                        if pred(r):
                            return r
                        if diverged and diverged(r):
                            cc.abort("the game took another path (returned at %#x)" % r["eip"])
                        if r["eip"] in self.g.bps:
                            self.g.step_over(r["eip"])
                        continue
                    else:
                        # (another thread, or too deep): off until the outermost capture is done
                        self.disarm(r["eip"])
                        self.parked.add(r["eip"])
                    nested_s += time.time() - t1
                elif r["eip"] in self.g.bps:
                    self.g.step_over(r["eip"])
        finally:
            self.stats["guest_s"] += time.time() - t0 - nested_s

    def on_hit(self, f, regs, depth):
        self.hits[f] += 1
        if not self.budget_left(f):
            self.disarm(f)
            return
        self.disarm(f)
        t1 = time.time()
        cc = CallCapture(self, f, regs, depth)
        if depth == 0:
            why = cc.run(regs)
        else:
            # Unicorn instances must not nest on one thread: the outer run is waiting inside its code hook
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
        if self.budget_left(f) and self.since_arm[f] < self.a.burst:
            self.arm(f)
        if dt > 20 and depth == 0:
            self.say("%#x took %.0fs" % (f, dt))

    # -- session ---------------------------------------------------------------------------------
    def rearm(self):
        n = 0
        for f in self.tgt:
            if f not in self.armed and self.budget_left(f):
                self.since_arm[f] = 0
                self.arm(f)
                n += 1
        return n

    def housekeeping(self, force=False):
        now = time.time()
        if force or now - self.last_hk >= 10:
            self.last_hk = now
            hdr = self.g.read_safe(self.man["g_hybrid"], 4 * len(hybrid_run.CTL_FIELDS))
            if hdr:
                st = dict(zip(hybrid_run.CTL_FIELDS, struct.unpack("<%dI" % len(hybrid_run.CTL_FIELDS), hdr)))
                self.polls, self.frame = st["polls"], st["frame"]
            reached = sum(1 for f in self.tgt if self.captured.get(f))
            self.timeline.append({"t": round(now - self.t0), "polls": self.polls, "frame": self.frame,
                                  "functions_captured": reached, "calls": sum(self.captured.values())})
            self.say("polls=%s frame=%s armed=%d functions=%d calls=%d failed=%d | stops=%d bp_ops=%d pages=%d "
                     "guest=%.0fs capture=%.0fs nested=%d" % (
                         self.polls, self.frame, len(self.armed), reached, sum(self.captured.values()),
                         sum(self.failed.values()), self.stats["stops"], self.g.ops, self.stats["pages"],
                         self.stats["guest_s"], self.stats["capture_s"],
                         sum(v for k, v in self.stats.items() if k.startswith("captures_depth") and k[-1] != "0")))
            self.flush_stats()
        if self.x and (force or now - self.last_shot >= self.a.shot_every):
            self.last_shot = now
            try:
                path = os.path.join(self.session, "shots", "%04ds-p%s.png" % (now - self.t0, self.polls))
                os.makedirs(os.path.dirname(path), exist_ok=True)
                self.x.screenshot(path)
            except Exception as e:          # the QMP monitor sometimes dies; capture goes on over GDB
                self.say("screenshot failed (%r); no more screenshots" % e)
                self.last_shot = float("inf")
        if now - self.last_arm >= self.a.rearm:
            self.last_arm = now
            n = self.rearm()
            if n:
                self.say("re-armed %d functions" % n)

    def flush_stats(self):
        with self.store_lock:
            for f in self.tgt:
                if self.hits.get(f):
                    self.store.set_func(f, self.hits[f], self.captured[f], self.failed[f],
                                        {"kind": self.tgt[f], "why": self.fail_why.get(f, [])[:5]})
            self.store.meta("timeline", self.timeline)
            self.store.meta("stats", dict(self.stats))
            self.store.commit()

    def run(self):
        a = self.a
        self.tgt = self.targets()
        script = json.load(open(a.script))
        hooks = hybrid_test.hooks_cfg(None)
        hooks["replay"] = script
        hooks["flags"].append("pollkey")
        xbe = os.path.join(self.session, "capture.xbe")
        self.man = patch_xbe.build([], xbe, tweaks=hybrid_test.TWEAKS, hooks=hooks)
        hybrid_run.install(xbe)
        self.store.meta("config", {"script": os.path.relpath(a.script, ROOT), "per_func": a.per_func,
                                   "burst": a.burst, "rearm": a.rearm, "minutes": a.minutes,
                                   "targets": dict(Counter(self.tgt.values()))})
        self.store.meta("targets", {"0x%08x" % f: k for f, k in self.tgt.items()})
        self.t0 = time.time()
        self.x = hybrid_run.Xemu("trace-" + a.session, True, ["-S"])
        self.g = CapGdb()
        self.armed = set()
        self.parked = set()
        self.polls = self.frame = None
        self.last_hk = self.last_shot = self.last_arm = time.time()
        self.say("arming %d functions (%s)" % (len(self.tgt), dict(Counter(self.tgt.values()))))
        self.rearm()
        stop_at = self.t0 + 60 * a.minutes
        try:
            while time.time() < stop_at:
                if not self.x.alive():
                    self.say("xemu exited (%s)" % self.x.p.returncode)
                    break
                rep = self.g.cont_timeout(2.0)
                if rep is None:
                    self.housekeeping()
                    continue
                r = self.g.regs_full()
                f = r["eip"]
                if f in self.armed:
                    self.on_hit(f, r, 0)
                    for p in self.parked:
                        if self.budget_left(p):
                            self.arm(p)
                    self.parked = set()
                    self.housekeeping()
                elif f in self.g.bps:
                    self.g.step_over(f)
        except (ConnectionError, OSError) as e:
            self.say("gdb connection lost: %r" % e)
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
        json.dump(rep, open(os.path.join(self.session, "session.json"), "w"), indent=1)
        print(json.dumps({k: v for k, v in rep.items() if k not in ("timeline", "not_reached")}, indent=1))
        return rep

    def report(self):
        size = sum(os.path.getsize(os.path.join(self.session, f)) for f in os.listdir(self.session)
                   if f.startswith("trace.sqlite"))
        kinds = {}
        for f, k in self.tgt.items():
            d = kinds.setdefault(k, {"targets": 0, "reached": 0, "captured_ok": 0, "calls_ok": 0, "calls_failed": 0})
            d["targets"] += 1
            d["reached"] += bool(self.hits.get(f))
            d["captured_ok"] += bool(self.captured.get(f))
            d["calls_ok"] += self.captured.get(f, 0)
            d["calls_failed"] += self.failed.get(f, 0)
        return {"session": os.path.relpath(self.session, ROOT), "seconds": round(time.time() - self.t0),
                "bytes": size, "kinds": kinds, "stats": dict(self.stats), "timeline": self.timeline,
                "not_reached": ["0x%08x" % f for f, k in sorted(self.tgt.items())
                                if k == "equivalent" and not self.hits.get(f)]}


def gameplay_script(path):
    """The scripted pad input (keyed by pad polls, ~1 per frame): title -> New Game -> Normal, A taps through the
    opening cutscene and tutorial prompts, then a loop of running, turning, light/heavy attacks, jumps and grabs."""
    E = []

    def tap(k, buttons=0, analog=(), n=6):
        E.append([k, buttons, list(analog), []])
        E.append([k + n, 0, [], []])
    tap(150, 0x10)                  # START on the title
    tap(300, 0, [255])              # A: New Game
    tap(450, 0, [255])              # A: Normal
    for k in range(700, 2000, 150):
        tap(k, 0, [255])            # A through the cutscene and prompts
    k = 2000
    fwd, right, left = [0, 32767, 0, 0], [24000, 20000, 0, 0], [-30000, 0, 0, 0]
    while k < 60000:
        E.append([k, 0, [], fwd]); k += 90                          # run
        E.append([k, 0, [0, 0, 255], fwd]); k += 8                   # X while running
        E.append([k, 0, [], right]); k += 40                         # turn
        for _ in range(3):                                           # X combo
            E.append([k, 0, [0, 0, 255], []]); k += 6
            E.append([k, 0, [], []]); k += 10
        E.append([k, 0, [0, 0, 0, 255], []]); k += 8                 # Y (heavy)
        E.append([k, 0, [], []]); k += 20
        E.append([k, 0, [255], left]); k += 8                        # jump while turning
        E.append([k, 0, [], left]); k += 60
        E.append([k, 0, [0, 255], []]); k += 8                       # B (grab)
        E.append([k, 0, [], []]); k += 30
    with open(path, "w") as f:
        f.write("[\n" + ",\n".join(json.dumps(e) for e in E) + "\n]\n")
    return E


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--session", default=time.strftime("s%Y%m%d-%H%M"))
    ap.add_argument("--minutes", type=float, default=20)
    ap.add_argument("--per-func", type=int, default=50, help="recorded calls per function")
    ap.add_argument("--burst", type=int, default=5, help="calls captured per arming of a function")
    ap.add_argument("--rearm", type=float, default=45, help="seconds between re-arming functions under budget")
    ap.add_argument("--max-fail", type=int, default=10, help="give up on a function after this many failed captures")
    ap.add_argument("--matches-sample", type=int, default=300, help="matched functions to capture as controls")
    ap.add_argument("--shot-every", type=float, default=30)
    ap.add_argument("--script", default=DEFAULT_SCRIPT)
    ap.add_argument("--write-script", action="store_true", help="(re)write the default input script and exit")
    a = ap.parse_args(argv)
    if a.write_script or not os.path.exists(a.script):
        gameplay_script(DEFAULT_SCRIPT)
        if a.write_script:
            print("wrote", os.path.relpath(DEFAULT_SCRIPT, ROOT))
            return 0
    if any("xemu" in l and "-gdb" in l for l in os.popen("ps -axo command").read().splitlines()):
        raise SystemExit("another xemu with a GDB stub is running (one xemu at a time)")
    Capture(a).run()
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
