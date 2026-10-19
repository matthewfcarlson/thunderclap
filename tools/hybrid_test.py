#!/usr/bin/env python3
"""Hybrid-build test harness (docs/tasks/10-hybrid-test-plan.md, docs/hybrid-build.md).

  tools/hybrid_test.py determinism [--replay R] [--seconds 60] [--runs 2]
        two runs of the *unmodified* game with only the test hooks patched in (fixed dt, constant seed,
        input replay, checkpoints); their checkpoints must be identical.
  tools/hybrid_test.py compare --matches all [--equivalent] [--set FILE] [--replay R] [--seconds 60]
        the same replay on the hooks-only build and on a hybrid build; reports the first checkpoint that
        differs, whether the patched build reached the title, and which patched functions ran.

  tools/hybrid_test.py record NAME [--minutes 30] [--pad GUID]
        play the unmodified game in xemu (hooks: virtual clock, constant seed, input recording, checkpoints) and
        save the pad input and checkpoints to tests/replays/NAME.json. Stop with Ctrl-C (or --minutes).
  tools/hybrid_test.py replay tests/replays/NAME.json [--until-frame N]
        replay a recording on the same build and compare its checkpoints with the recorded ones.
  tools/hybrid_test.py replay NAME.json --drawlog EVERY[:FIRST[:LAST]] [--drawlog-out PATH]
        the same, on a build that also logs the pddi state of every draw in those frames (tools/drawlog_diff.py;
        docs/hybrid-build.md "drawlog").
  tools/hybrid_test.py replay NAME.json --from-snapshot K | --from-frame F
        start from one of the recording's VM snapshots (record --snap-every, default every 5 min).
  tools/hybrid_test.py salvage OLD.json NEW.json
        rewrite a version-1 recording made with several pads bound (interleaved by poll) as one pad's.

Recordings are version 2 (docs/tasks/record-replay.md): the game sees one virtual pad whatever xemu has bound, the
date follows the virtual clock, and the audio sequencer no longer draws from the gameplay RNG.

Every run uses the tweaks skip-intro and no-fmv (movies stall the frame counter that replays are keyed on)
and writes build/hybrid/test/<name>.json.
"""
import argparse
import json
import os
import struct
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import hybrid_run  # noqa: E402
import patch_xbe  # noqa: E402

ROOT = patch_xbe.ROOT
TEST_DIR = os.path.join(patch_xbe.OUT_DIR, "test")
DEFAULT_REPLAY = os.path.join(ROOT, "tests/replays/newgame-normal.json")
TWEAKS = ("skip-intro", "no-fmv")
SEED = 0x1234


MASK_FILE = os.path.join(ROOT, "tests/replays/wide-mask.json")     # .data pages excluded from the hash


PIN_FLAGS = ["vclock", "sound-rng"]


def hooks_cfg(replay, wide=False, snap_frame=0, vclock=False):
    """vclock: pin everything after the new-game load too (PIN_FLAGS): every game timer read (core:: and Pure3D)
    returns the virtual clock (hooks.cpp hybrid_qpc), and the sound code gets its own random generators."""
    h = {"seed": SEED, "flags": ["fixed-dt", "ckpt", "autostart"] + (PIN_FLAGS if vclock else []), "dt_us": 33333,
         "ckpt_interval": 30}
    if replay:
        data = json.load(open(replay))
        if isinstance(data, dict):          # a recording (record below): keyed by pad polls, START is in it
            h["replay"] = data["inputs"][:patch_xbe.INPUT_MAX]    # only `replay` feeds the ring past that
            if len(data["inputs"]) > patch_xbe.INPUT_MAX:
                print("  %s: replaying the first %d of %d pad changes (use `hybrid_test.py replay` for all)"
                      % (replay, patch_xbe.INPUT_MAX, len(data["inputs"])), file=sys.stderr)
            h["flags"] = [f for f in h["flags"] if f != "autostart"] + ["pollkey"]
            # version 2: the input pinning the recording was made with (virtual pad, virtual date)
            h["flags"] += [f for f in RECORDING_PINS if f in data.get("flags", ()) and f not in h["flags"]]
            if data.get("vpad_count"):
                h["vpad_count"] = data["vpad_count"]
        else:
            h["replay"] = data
    if wide:
        h["flags"].append("wide")
        h["snap_frame"] = snap_frame
        if os.path.exists(MASK_FILE):
            m = json.load(open(MASK_FILE))
            mask = [0] * (patch_xbe.WIDE_PAGES // 32)
            for p in m.get("pages", []):
                mask[p >> 5] |= 1 << (p & 31)
            h["mask"] = mask
            h["skip"] = [(int(a, 16), n) for a, n, *_ in m.get("skip", [])]
    return h


def build_and_run(name, records, replay, seconds, interval=10, coverage=False, wide=False, snap_frame=0, shots=True,
                  vclock=True):
    """Build XBE `name` from records (may be empty), install, boot, return the boot report."""
    os.makedirs(TEST_DIR, exist_ok=True)
    out = os.path.join(TEST_DIR, name + ".xbe")
    man = patch_xbe.build(records, out, tweaks=TWEAKS, hooks=hooks_cfg(replay, wide, snap_frame, vclock))
    hybrid_run.install(out)
    cov = [f["ours"] for f in man["functions"]] if coverage and man["functions"] else None
    rep = hybrid_run.boot(seconds, interval, tag="test-" + name, coverage=cov, manifest=man, shots=shots)
    rep["patched"] = man["patched"]
    json.dump(rep, open(os.path.join(TEST_DIR, name + "-report.json"), "w"), indent=1)   # name.json is the manifest
    return rep


def checkpoints(rep):
    return [tuple(c) for c in (rep.get("hybrid") or {}).get("checkpoints", [])]


# Checkpoints after this frame are not compared: on newgame-normal.json the game is deterministic through
# the front end (frames 0-450); after the new-game load the loop's frame count depends on load time.
MAX_FRAME = 450


def first_divergence(a, b, max_frame=MAX_FRAME):
    """{frame, a, b} of the first differing checkpoint over the common frames (<= max_frame), else None."""
    ma, mb = dict(a), dict(b)
    for f in sorted(set(ma) & set(mb)):
        if max_frame and f > max_frame:
            break
        if ma[f] != mb[f]:
            return {"frame": f, "a": "%08x" % ma[f], "b": "%08x" % mb[f]}
    return None


def common_frames(a, b, max_frame=MAX_FRAME):
    return len([f for f in set(dict(a)) & set(dict(b)) if not max_frame or f <= max_frame])


def determinism(args):
    reps = [build_and_run("determinism-%d" % i, [], args.replay, args.seconds, wide=args.wide,
                          snap_frame=args.snap_frame, shots=args.shots, vclock=not args.no_vclock)
            for i in range(args.runs)]
    cks = [checkpoints(r) for r in reps]
    res = {"runs": args.runs, "checkpoints": [len(c) for c in cks], "frames": [(r.get("hybrid") or {}).get("frame") for r in reps],
           "monitor_errors": sum(bool(r.get("monitor_error")) for r in reps),
           "divergence": None}
    for c in cks[1:]:
        d = first_divergence(cks[0], c, args.max_frame)
        if d:
            res["divergence"] = d
            break
    res["state"] = [{k: (r.get("hybrid") or {}).get(k) for k in ("game_state", "polls", "max_extra_us", "vreads")}
                    for r in reps]
    res["common"] = min(common_frames(cks[0], c, args.max_frame) for c in cks[1:]) if len(cks) > 1 else len(cks[0])
    res["deterministic"] = res["divergence"] is None and res["common"] > 0
    if args.wide:
        snaps = [((r.get("hybrid") or {}).get("wide") or {}) for r in reps]
        if all(sn.get("snap_taken") for sn in snaps):
            lo = snaps[0]["lo"]
            diff = sorted({i for sn in snaps[1:] for i, (p, q) in enumerate(zip(snaps[0]["snap"], sn["snap"])) if p != q})
            res["snap_frames"] = [sn["snap_taken"] for sn in snaps]
            res["varying_pages"] = [{"page": i, "va": "%#x" % (lo + 0x1000 * i)} for i in diff]
    return res


# no autostart: START is in the recording. No wide: .data holds heap and stack pointers, and the memory layout
# isn't the same from run to run (thread stacks, heap base), so its page hashes would never match.
RECORD_FLAGS = ["fixed-dt", "ckpt", "pollkey"] + PIN_FLAGS
# Recording format version 2 (docs/tasks/record-replay.md): the game sees one virtual pad in port 1 whatever xemu
# has bound (vpad), and the date follows the virtual clock (vdate). Version 1 recordings (no "version") were made
# without them and replay without them.
RECORDING_PINS = ["vpad", "vdate", "seq-rng"]
RECORDING_VERSION = 2


PAD_DIAG = ("nhandles", "poll_errors", "last_error", "real_errors", "real_active", "vpad_given", "real_pad0", "real_pad1",
            "real_pad2", "real_pad3")


def _pad_entry(raw, o):
    f, b, *rest = struct.unpack_from("<IH8B4hH", raw, o)
    return [f, b, list(rest[:8]), list(rest[8:12])]


def _read_ring(x, va, size, n, i0, i1, parse):
    """Entries i0..i1-1 of a guest ring of n entries of `size` bytes at va (at most two memsaves)."""
    out = []
    i = i0
    while i < i1:
        j = min(i1, (i // n + 1) * n)
        raw = x.read(va + size * (i % n), size * (j - i))
        out += [parse(raw, size * k) for k in range(j - i)]
        i = j
    return out


def _drain(x, man, rec, seen):
    """Read g_hybrid; append record-ring entries not seen yet and merge the checkpoint ring into rec."""
    # Only what is new since the last drain: the header, then the new record entries and checkpoints (the whole
    # rings were 230 KB of memsave every drain).
    st = hybrid_run.read_hybrid(x, man)
    lay = man["g_hybrid_layout"]
    base = man["g_hybrid"]
    new = st["record_count"] - seen["inputs"]
    if new > lay["input_max"]:
        print("  WARNING: %d inputs lost (drain slower than the ring)" % (new - lay["input_max"]), file=sys.stderr)
    if new > 0:
        rec["inputs"] += _read_ring(x, base + lay["record"], lay["pad_bytes"], lay["input_max"],
                                    st["record_count"] - min(new, lay["input_max"]), st["record_count"], _pad_entry)
    seen["inputs"] = st["record_count"]
    c0 = max(seen.get("ckpts", 0), st["ckpt_count"] - lay["ckpt_ring"])
    if st["ckpt_count"] > c0:
        rec["checkpoints"].update(_read_ring(x, base + lay["ckpt"], 8, lay["ckpt_ring"], c0, st["ckpt_count"],
                                             lambda raw, o: struct.unpack_from("<II", raw, o)))
    seen["ckpts"] = st["ckpt_count"]
    rec["frames"], rec["polls"] = st["frame"], st["polls"]
    tl = rec.setdefault("timeline", [])            # [wall s, frame, polls]: where polls ran ahead of frames
    if not tl or tl[-1][1:] != [st["frame"], st["polls"]]:
        tl.append([round(time.time() - seen.get("t0", time.time()), 1), st["frame"], st["polls"]])
    rec["pads"] = {k: st[k] for k in PAD_DIAG if k in st}
    return st


def record(args):
    import time
    hooks = hooks_cfg(None, vclock=True)
    hooks["flags"] = RECORD_FLAGS + ([] if args.v1 else RECORDING_PINS) + ["record"] \
        + ([] if args.no_quant else ["quant"])
    if args.script:         # a stand-in player: drive the recording build with a pad script (keyed by polls)
        hooks["replay"] = json.load(open(args.script))
        hooks["flags"] += ["autostart"]
    os.makedirs(TEST_DIR, exist_ok=True)
    path = args.out or os.path.join(ROOT, "tests/replays", args.name + ".json")
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)   # a missing --out dir killed the first save
    snaps_on = args.snap_every > 0 and not args.v1
    sp = snapshot_paths(os.path.abspath(path))
    trace = None
    out = os.path.join(TEST_DIR, "record.xbe")
    if snaps_on:
        for k in ("disk", "xbe"):
            if os.path.exists(sp[k]):
                raise SystemExit("%s exists (a recording's snapshots are never overwritten): pick another --out"
                                 % os.path.relpath(sp[k], ROOT))
        trace = {"targets": sorted(trace_targets()), "next": patch_xbe.NEVER, "patch_entries": False}
        out = sp["xbe"]
    t_build = time.time()
    man = patch_xbe.build([], out, tweaks=TWEAKS, hooks=hooks, trace=trace)
    print("  built %s in %.0f s" % (os.path.relpath(out, ROOT), time.time() - t_build), file=sys.stderr)
    hybrid_run.install(out)
    if snaps_on:
        hybrid_run.make_overlay(sp["disk"])
    rec = {"version": 1 if args.v1 else RECORDING_VERSION, "key": "polls", "flags": hooks["flags"], "seed": SEED,
           "tweaks": list(TWEAKS),
           "mask": hooks.get("mask", []), "skip": hooks.get("skip", []), "inputs": [], "checkpoints": {},
           "frames": 0, "polls": 0}
    if snaps_on:
        rec["snapshot_files"] = {k: os.path.relpath(v, ROOT) for k, v in sp.items()}
        rec["snapshots"] = []
        rec["snap_every_min"] = args.snap_every
    seen = {"inputs": 0}

    def save():
        doc = dict(rec, checkpoints=sorted([f, h] for f, h in rec["checkpoints"].items()))
        json.dump(doc, open(path, "w"), separators=(",", ":"))

    x = hybrid_run.Xemu("record-" + args.name, pad=args.pad, hdd=sp["disk"] if snaps_on else None,
                        snapshot=not snaps_on, sound=not args.mute)
    seen["t0"] = x.t0
    print("recording to %s: play, then press Ctrl-C here (closing the xemu window loses the last 2 s)" % path,
          file=sys.stderr)
    want_snap = []
    if snaps_on:
        import signal
        import threading
        signal.signal(signal.SIGUSR1, lambda *_: want_snap.append("request"))
        print("  VM snapshot every %g min; type s + Enter here (or kill -USR1 %d) for one now"
              % (args.snap_every, os.getpid()), file=sys.stderr)
        if sys.stdin and sys.stdin.isatty():
            def keys():
                for line in sys.stdin:
                    if line.strip().lower().startswith("s"):
                        want_snap.append("request")
            threading.Thread(target=keys, daemon=True).start()
    next_snap = x.t0 + 60 * args.snap_every
    try:
        while x.alive() and time.time() - x.t0 < args.minutes * 60:
            time.sleep(2)
            try:
                st = _drain(x, man, rec, seen)
                if snaps_on and st["frame"] > 0 and (want_snap or time.time() >= next_snap):
                    take_snapshot(x, man, rec, seen, sp["disk"], want_snap.pop() if want_snap else "every")
                    want_snap.clear()
                    next_snap = time.time() + 60 * args.snap_every
                    save()
            except RuntimeError:             # g_hybrid not mapped yet (booting)
                continue
            except OSError as e:             # xemu closed, or its monitor stopped answering
                print("  monitor: %r" % e, file=sys.stderr)
                break
            if int(time.time() - x.t0) % 30 < 2:
                # the game runs at full speed at ~25-30 fps: much less and it plays in slow motion (game time is
                # frames x 33 ms), though the recording still replays exactly
                tl = [e for e in rec.get("timeline", []) if e[0] >= time.time() - x.t0 - 30]
                fps = (tl[-1][1] - tl[0][1]) / max(1e-3, tl[-1][0] - tl[0][0]) if len(tl) > 1 else 0
                print("  %4ds frame %d (%.0f fps), %d inputs" % (time.time() - x.t0, rec["frames"], fps,
                                                               len(rec["inputs"])), file=sys.stderr)
                save()
    except KeyboardInterrupt:
        try:
            _drain(x, man, rec, seen)
        except Exception:
            pass
    finally:
        x.close()
    save()
    out = {"recording": os.path.relpath(path, ROOT), "frames": rec["frames"], "polls": rec["polls"],
           "inputs": len(rec["inputs"]), "checkpoints": len(rec["checkpoints"])}
    if snaps_on:
        out["snapshots"] = [{k: sn[k] for k in ("tag", "frame", "pause_s", "disk_bytes")} for sn in rec["snapshots"]]
        os.chmod(sp["disk"], 0o444)      # finished: resumes work on copies
    return out


class ReplayFeeder:
    """Keeps g_hybrid.replay (a ring of INPUT_MAX entries) ahead of the game for replays longer than the ring,
    over the GDB stub (QMP can't write guest memory). Stopping the VM for a write is harmless: game time is
    virtual."""

    def __init__(self, man, entries, g=None, avail=None):
        from xemu_gdb import Gdb
        self.man, self.entries = man, entries
        self.g = g or Gdb()
        self.g._send("c")                    # the stub stops the VM when it attaches (a resumed VM: it starts here)
        lay = man["g_hybrid_layout"]
        self.base, self.max, self.pad = man["g_hybrid"], lay["input_max"], lay["pad_bytes"]
        self.avail_va = self.base + lay["ext"] + 4 * lay["ext_fields"].index("replay_avail")
        self.ring_va = self.base + patch_xbe.CTL_REPLAY
        self.avail = min(len(entries), self.max) if avail is None else avail

    def feed(self, st):
        if self.avail >= len(self.entries):
            return
        end = min(len(self.entries), st["replay_pos"] + self.max - 64)
        if end - self.avail < 1024:
            return
        self.g.interrupt()
        self.g._recv_packet()
        i = self.avail
        while i < end:
            j = min(end, (i // self.max + 1) * self.max)          # up to the end of the ring
            data = patch_xbe.pack_replay(self.entries[i:j])
            for o in range(0, len(data), 2040):
                self.g.write(self.ring_va + self.pad * (i % self.max) + o, data[o:o + 2040])
            i = j
        self.g.write(self.avail_va, struct.pack("<I", end))
        self.g._send("c")
        self.avail = end

    def close(self):
        self.g.close()


def replay(args):
    """Replay a recording on the record build (same hooks, minus recording) and compare checkpoints."""
    import time
    data = json.load(open(args.recording))
    if args.from_snapshot is not None or args.from_frame is not None:
        return replay_from_snapshot(args, data)
    hooks = {"seed": data.get("seed", SEED), "flags": [f for f in data["flags"] if f != "record"] + ["replay"],
             "dt_us": 33333, "ckpt_interval": 30, "replay": data["inputs"], "mask": data.get("mask", []),
             "skip": data.get("skip", []), "vpad_count": data.get("vpad_count", 0)}
    if getattr(args, "drawlog", None):
        hooks["drawlog"] = patch_xbe.parse_drawlog(args.drawlog)
    os.makedirs(TEST_DIR, exist_ok=True)
    out = os.path.join(TEST_DIR, "replay-drawlog.xbe" if hooks.get("drawlog") else "replay.xbe")
    man = patch_xbe.build([], out, tweaks=data.get("tweaks", TWEAKS), hooks=hooks)
    hybrid_run.install(out)
    rec = {"inputs": [], "checkpoints": {}, "frames": 0, "polls": 0}
    seen = {"inputs": 0}
    want = data["frames"]
    limit = args.seconds or (want / 8 + 180)           # gameplay can drop to ~10 fps on a loaded host
    long = len(data["inputs"]) > patch_xbe.INPUT_MAX
    x = hybrid_run.Xemu("replay", gdb=long)
    seen["t0"] = x.t0
    feeder = ReplayFeeder(man, data["inputs"]) if long else None
    dl = {"seen": 0, "records": [], "lost": 0} if hooks.get("drawlog") else None
    try:
        stop = min(want, args.until_frame or want)
        while x.alive() and time.time() - x.t0 < limit and rec["frames"] < stop:
            time.sleep(1 if dl else 5)
            try:
                if dl:
                    hdr, new = hybrid_run.read_drawlog(x, man, dl["seen"])
                    dl["records"] += new
                    dl["lost"] += hdr["lost"]
                    dl["seen"], dl["draws"] = hdr["count"], hdr["draws"]
                st = _drain(x, man, rec, seen)
                if feeder:
                    feeder.feed(st)
            except RuntimeError:
                continue
            except OSError as e:
                print("  monitor: %r" % e, file=sys.stderr)
                break
            print("  %4ds frame %d / %d" % (time.time() - x.t0, rec["frames"], want), file=sys.stderr)
        if dl and x.alive():
            try:
                hdr, new = hybrid_run.read_drawlog(x, man, dl["seen"])
                dl["records"] += new
                dl["lost"] += hdr["lost"]
                dl["seen"], dl["draws"] = hdr["count"], hdr["draws"]
            except (RuntimeError, OSError):
                pass
    finally:
        if feeder:
            feeder.close()
        x.close()
    a, b = [tuple(c) for c in data["checkpoints"]], sorted(rec["checkpoints"].items())
    if dl:
        b = [(f, h) for f, h in b if f <= rec["frames"]]
        a_cut = [(f, h) for f, h in a if f <= max([f for f, _h in b] or [0])]
    d = first_divergence(a, b, 0)
    ma = dict(a)
    extra = {}
    if dl:
        path = args.drawlog_out or os.path.join(TEST_DIR, "drawlog.jsonl")
        write_drawlog(path, dl["records"], {"source": "hybrid", "recording": args.recording, "spec": args.drawlog,
                                            "draws_seen": dl.get("draws"), "lost": dl["lost"],
                                            "sites": man["g_drawlog_layout"]["sites"]})
        extra = {"drawlog": os.path.relpath(path, ROOT), "drawlog_records": len(dl["records"]),
                 "drawlog_lost": dl["lost"], "draws_seen": dl.get("draws"),
                 "checkpoints_compared": len([1 for f, h in b if f in ma]),
                 "recorded_checkpoints_in_range": len(a_cut)}
    return dict({"recording": args.recording, "recorded_frames": want, "replayed_frames": rec["frames"],
            "common": common_frames(a, b, 0), "divergence": d,
            "matching": sum(1 for f, h in b if ma.get(f) == h),
            "checkpoints": [[f, h] for f, h in b], "polls": rec["polls"], "pads": rec.get("pads"),
            "timeline": rec.get("timeline", []),
            "identical": d is None and common_frames(a, b, 0) > 0}, **extra)


def write_drawlog(path, records, meta):
    """A draw log as JSON lines: a header object, then one object per draw (hybrid_run.DRAWLOG_FIELDS)."""
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    with open(path, "w") as f:
        f.write(json.dumps(dict(meta, format="drawlog-1", fields=list(hybrid_run.DRAWLOG_FIELDS))) + "\n")
        for r in records:
            f.write(json.dumps(dict(zip(hybrid_run.DRAWLOG_FIELDS, r)), separators=(",", ":")) + "\n")


def replay_from_snapshot(args, data):
    """Resume the recording's VM snapshot (on a throwaway copy of its disk) and replay from there to the end."""
    snap = find_snapshot(data, args.from_snapshot, args.from_frame)
    want = data["frames"]
    res = resume_snapshot(data, snap, "replay-snap", syncio=not args.no_syncio)
    x, man = res["x"], res["man"]
    io = {}
    rec = {"inputs": [], "checkpoints": {}, "frames": snap["frame"], "polls": snap["polls"]}
    seen = {"inputs": snap.get("inputs", 0), "t0": x.t0, "ckpts": res["ckpt_count"]}
    feeder = ReplayFeeder(man, data["inputs"], g=res["g"], avail=res["avail"])        # (this starts the VM)
    t_run = time.time()
    limit = args.seconds or ((want - snap["frame"]) / 8 + 120)
    try:
        stop = min(want, args.until_frame or want)
        while x.alive() and time.time() - t_run < limit and rec["frames"] < stop:
            time.sleep(5)
            try:
                st = _drain(x, man, rec, seen)
                io = {k: st.get(k) for k in ("io_waits", "io_timeouts")}
                feeder.feed(st)
            except RuntimeError:
                continue
            except OSError as e:
                print("  monitor: %r" % e, file=sys.stderr)
                break
            print("  %4ds frame %d / %d" % (time.time() - x.t0, rec["frames"], want), file=sys.stderr)
    finally:
        feeder.close()
        close_resumed(res)
    a = [tuple(c) for c in data["checkpoints"] if c[0] > snap["frame"]]
    b = sorted((f, h) for f, h in rec["checkpoints"].items() if f > snap["frame"])
    d = first_divergence(a, b, 0)
    ma = dict(a)
    return {"recording": args.recording, "snapshot": {k: snap.get(k) for k in ("tag", "frame", "polls", "ckpt")},
            "resume_s": res["resume_s"], "syncio": dict(io, on=not args.no_syncio), "recorded_frames": want, "replayed_frames": rec["frames"],
            "common": common_frames(a, b, 0), "divergence": d, "matching": sum(1 for f, h in b if ma.get(f) == h),
            "checkpoints": [[f, h] for f, h in b], "timeline": rec.get("timeline", []),
            "identical": d is None and common_frames(a, b, 0) > 0}


# ---------------------------------------------------------------------------------------------
# VM snapshots of a recording (docs/tasks/record-replay.md, "Snapshots"). The recording runs on its own qcow2
# overlay of the read-only base HDD, without -snapshot; `savevm` stores each snapshot (machine state, ~60 MB)
# inside that overlay. Resuming copies the overlay (an APFS clone: instant), boots xemu paused on the copy, waits
# for xemu's pad, `loadvm`s the snapshot and turns the recording build into a replay over the GDB stub (flags, the
# replay ring from the snapshot's poll on). The recording build also carries the trace_gate trampolines with every
# entry left alone, so tools/trace_gate.py can resume the same snapshots and arm what it wants.
SNAP_EVERY = 5.0


def snapshot_paths(path):
    b = path[:-5] if path.endswith(".json") else path
    return {"disk": b + ".disk.qcow2", "xbe": b + ".rec.xbe", "manifest": b + ".rec.json"}


def trace_targets():
    """The trace_gate target set (as a default trace_gate run would arm it), for the recording build."""
    import trace_gate
    return trace_gate.default_targets()


def _usb_pads(info):
    """[(port, id)] of the Xbox pads in HMP `info usb`, and the set of hub ports."""
    pads, hubs = [], set()
    for line in info.splitlines():
        m = __import__("re").search(r"Port ([\d.]+),.*Product (.*?)(?:, ID: (\S+))?\s*$", line.strip())
        if not m:
            continue
        if "Hub" in m.group(2):
            hubs.add(m.group(1))
        elif m.group(3):
            pads.append((m.group(1), m.group(3)))
    return pads, hubs


def take_snapshot(x, man, rec, seen, disk, why):
    """Pause, drain, savevm into the overlay, resume. Returns the timeline entry."""
    t = time.time()
    x.q.cmd("stop")
    try:
        st = _drain(x, man, rec, seen)
        tag = "s%d" % len(rec["snapshots"])
        r = x.hmp("savevm %s" % tag)
        if r.strip():
            raise RuntimeError("savevm: %s" % r.strip())
        usb = x.hmp("info usb")
    finally:
        x.q.cmd("cont")
    cks = [f for f in rec["checkpoints"] if f <= st["frame"]]
    ck = max(cks) if cks else None
    ent = {"tag": tag, "frame": st["frame"], "polls": st["polls"], "inputs": st["record_count"],
           "ckpt": [ck, rec["checkpoints"][ck]] if ck is not None else None, "t": round(t - x.t0, 1),
           "pause_s": round(time.time() - t, 3), "disk_bytes": os.path.getsize(disk), "why": why,
           "usb": _usb_pads(usb)[0]}
    rec["snapshots"].append(ent)
    print("  snapshot %s at frame %d (poll %d): %.2f s paused, disk %.0f MB" % (
        tag, ent["frame"], ent["polls"], ent["pause_s"], ent["disk_bytes"] / 1e6), file=sys.stderr)
    return ent


def find_snapshot(data, k=None, frame=None):
    snaps = data.get("snapshots") or []
    if not snaps:
        raise SystemExit("this recording has no VM snapshots (record it with --snap-every)")
    if k is not None:
        if not -len(snaps) <= k < len(snaps):
            raise SystemExit("snapshot %d: the recording has %d" % (k, len(snaps)))
        return snaps[k]
    cand = [sn for sn in snaps if sn["frame"] <= frame]
    if not cand:
        raise SystemExit("no snapshot at or before frame %d (the first is at %d)" % (frame, snaps[0]["frame"]))
    return max(cand, key=lambda sn: sn["frame"])


def resume_snapshot(data, snap, tag, gdb_cls=None, syncio=True):
    """Boot xemu paused on a copy of the recording's disk, loadvm the snapshot, attach GDB, and turn the recording
    build into a replay from there (with syncio unless asked not to). Returns {x, g, man, avail, ckpt_count, clone,
    resume_s}; the VM is still stopped (the caller continues it through g)."""
    import shutil
    import subprocess
    from xemu_gdb import Gdb
    files = {k: os.path.join(ROOT, v) for k, v in data["snapshot_files"].items()}
    man = json.load(open(files["manifest"]))
    t0 = time.time()
    hybrid_run.install(files["xbe"])            # (sections the game loads later come from the disc's default.xbe)
    clone = os.path.join(patch_xbe.OUT_DIR, "resume%s.qcow2" % hybrid_run._SFX)
    if os.path.exists(clone):
        os.unlink(clone)
    if subprocess.run(["cp", "-c", files["disk"], clone]).returncode:
        shutil.copy(files["disk"], clone)
    os.chmod(clone, 0o644)                      # (the recording's disk is read-only once recorded)
    x = hybrid_run.Xemu(tag, gdb=True, extra=["-S"], hdd=clone, snapshot=False)
    try:
        # xemu attaches its pads (and their hubs) after QEMU starts; loadvm needs the snapshot's device set
        want = [tuple(p) for p in snap.get("usb") or []]
        have = []
        t1 = time.time()
        while time.time() - t1 < 20:
            have, hubs = _usb_pads(x.hmp("info usb"))
            if len(have) >= max(1, len(want)) or (have and time.time() - t1 > 5):
                break
            time.sleep(0.25)
        for port, pid in want:
            if (port, pid) in have:
                continue
            hub = port.rsplit(".", 1)[0]
            if hub not in hubs:
                x.q.cmd("device_add", driver="usb-hub", port=hub)
                hubs.add(hub)
            x.q.cmd("device_add", driver="usb-xbox-gamepad", id=pid, port=port)
        r = x.hmp("loadvm %s" % snap["tag"])
        if r.strip():
            raise RuntimeError("loadvm %s: %s" % (snap["tag"], r.strip()))
        g = (gdb_cls or Gdb)()
        base, lay = man["g_hybrid"], man["g_hybrid_layout"]
        hdr = struct.unpack("<%dI" % len(hybrid_run.CTL_FIELDS), g.read(base, 4 * len(hybrid_run.CTL_FIELDS)))
        st = dict(zip(hybrid_run.CTL_FIELDS, hdr))
        if (st["frame"], st["polls"]) != (snap["frame"], snap["polls"]):
            raise RuntimeError("snapshot %s loaded at frame %d poll %d, recorded %d/%d" % (
                snap["tag"], st["frame"], st["polls"], snap["frame"], snap["polls"]))
        # the recording build becomes the replay build: the flags replay() would use, the replay ring from here
        flags = 0
        for f in [f for f in data["flags"] if f != "record"] + ["replay"]:
            flags |= patch_xbe.HF[f]
        entries = data["inputs"]
        pos = 0
        for i, e in enumerate(entries):
            if e[0] > st["polls"]:
                break
            pos = i
        end = min(len(entries), pos + lay["input_max"])
        ring, n, pad = base + patch_xbe.CTL_REPLAY, lay["input_max"], lay["pad_bytes"]
        i = pos
        while i < end:
            j = min(end, (i // n + 1) * n)
            raw = patch_xbe.pack_replay(entries[i:j])
            for o in range(0, len(raw), 2040):
                g.write(ring + pad * (i % n) + o, raw[o:o + 2040])
            i = j
        ext = lambda k: base + lay["ext"] + 4 * lay["ext_fields"].index(k)
        g.write(ext("replay_avail"), struct.pack("<I", end))
        g.write(base + 4 * 8, struct.pack("<II", len(entries), pos))     # replay_count, replay_pos
        g.write(base + 4 * 1, struct.pack("<I", flags))
        if syncio:
            install_syncio(g, man, data)
    except BaseException:
        x.close()
        os.unlink(clone)
        raise
    return {"x": x, "g": g, "man": man, "avail": end, "ckpt_count": st["ckpt_count"], "clone": clone,
            "resume_s": round(time.time() - t0, 2)}


# syncio (docs/tasks/record-replay.md, "Snapshot resumes that diverged at 51570"): the game streams the open world
# through core::DriveThread, whose request handlers run on the drive threads, and the game reads their results as
# soon as they are there. Which frame a result lands in followed the host (and how much emulated time a frame took),
# so an AI decision (CPathAgent -> CAvoidBehaviour at frame 51565 of play3) went either way, and replays parted from
# the recording at the next checkpoint. With syncio the main thread waits, after each request it posts
# (core::DriveThread 0x272fc0), until that drive is idle: every request completes in the frame that made it, as on
# a fast host. It is machine code written over GDB into the build's unused rnglog area (any recording build has it),
# so resumes of existing recordings get it too.
SYNCIO_SITE = 0x0027303F          # 0x272fc0's tail: pop edi; pop esi; ret 0xc (edi = drive + 0xc)
SYNCIO_TAIL = bytes.fromhex("5f5ec20c00")
SYNCIO_SLEEP = 0x0020C723         # XAPI Sleep (hooks.cpp XSleep)
SYNCIO_LIMIT = 2000               # 1 ms sleeps before giving up on a drive (counted in io_timeouts)


def syncio_stub(man):
    """(address, code) of the wait: on the main thread, Sleep(1) until [drive + 0x8c] (requests queued or being
    processed) is 0, counting sleeps in io_waits; then the original tail."""
    base, lay = man["g_hybrid"], man["g_hybrid_layout"]
    ext = lambda k: base + lay["ext"] + 4 * lay["ext_fields"].index(k)
    p = lambda v: struct.pack("<I", v)
    c = bytearray(b"\x50" + b"\x64\xa1\x28\x00\x00\x00" + b"\x3b\x05" + p(ext("main_thread")))   # push eax;
    j_done = len(c)                                     # mov eax, fs:[28h]; cmp eax, [main_thread]
    c += b"\x75\x00"                                    # jne done
    c += b"\x51\xb9" + p(SYNCIO_LIMIT)                  # push ecx; mov ecx, LIMIT
    loop = len(c)
    c += b"\x8b\x87\x80\x00\x00\x00\x85\xc0"            # mov eax, [edi + 0x80]; test eax, eax
    j_out = len(c)
    c += b"\x74\x00\x49"                                # jz out; dec ecx
    j_to = len(c)
    c += b"\x74\x00"                                    # jz timeout
    c += b"\x51\x6a\x01\xb8" + p(SYNCIO_SLEEP) + b"\xff\xd0\x59"   # push ecx; Sleep(1); pop ecx
    c += b"\xff\x05" + p(ext("io_waits"))               # inc [io_waits]
    c += b"\xeb" + bytes([(loop - (len(c) + 2)) & 0xFF])            # jmp loop
    timeout = len(c)
    c += b"\xff\x05" + p(ext("io_timeouts"))            # inc [io_timeouts]
    out = len(c)
    c += b"\x59"                                        # pop ecx
    done = len(c)
    c += b"\x58" + SYNCIO_TAIL                          # pop eax; pop edi; pop esi; ret 0xc
    for j, t in ((j_done, done), (j_out, out), (j_to, timeout)):
        c[j + 1] = t - (j + 2)
    return base + patch_xbe.CTL_RNGLOG + 4, bytes(c)


def install_syncio(g, man, data):
    """Write the syncio wait into a stopped VM running a recording build (over GDB)."""
    if "rng-log" in data.get("flags", ()):
        raise SystemExit("syncio: this build uses the rnglog area")
    if g.read(SYNCIO_SITE, 5) != SYNCIO_TAIL:
        raise RuntimeError("syncio: unexpected bytes at %#x" % SYNCIO_SITE)
    at, code = syncio_stub(man)
    base, lay = man["g_hybrid"], man["g_hybrid_layout"]
    ext = lambda k: base + lay["ext"] + 4 * lay["ext_fields"].index(k)
    g.write(at, code)
    g.write(ext("io_waits"), struct.pack("<II", 0, 0))                  # io_waits, io_timeouts
    g.write(SYNCIO_SITE, b"\xe9" + struct.pack("<i", at - (SYNCIO_SITE + 5)))


def close_resumed(res):
    try:
        res["g"].close()
    except OSError:
        pass
    res["x"].close()
    if os.path.exists(res["clone"]):
        os.unlink(res["clone"])          # (the throwaway copy; the recording's own disk is never written again)


def _zero(e):
    return not e[1] and not any(e[2]) and not any(e[3])


def interleaved_pads(inputs):
    """A version-1 recording made with several pads bound (e.g. the keyboard in port 1 and a gamepad xemu
    auto-bound to port 2): the poll counter counts every pad, so pad j of N owns polls p with (p - 1) % N == j.
    Returns (N, j) when every non-zero entry falls on one pad's polls, else None."""
    live = [e[0] for e in inputs if not _zero(e)]
    if not live:
        return None
    for n in (2, 3, 4):
        res = {(p - 1) % n for p in live}
        if len(res) == 1:
            return n, res.pop()
    return None


def collapse_pads(inputs, n, j):
    """Inputs as one pad's stream keyed by poll round. The other pads were idle (all zero), and an entry is only
    written when the pad state differs from the last entry, so pad j's state at its poll in round q is the last
    entry at or before that poll: the entry at poll p applies from the first round whose pad-j poll is >= p."""
    out = []
    for e in inputs:
        q = (e[0] - j - 1 + n - 1) // n + 1
        if out and out[-1][0] == q:
            out[-1] = [q] + list(e[1:])
        else:
            out.append([q] + list(e[1:]))
    dedup = []
    for e in out:
        if not dedup or dedup[-1][1:] != e[1:]:
            dedup.append(e)
    return dedup


def salvage(args):
    """Rewrite an old recording made with several pads bound as a single-pad recording (a new file)."""
    data = json.load(open(args.recording))
    il = interleaved_pads(data["inputs"])
    if not il:
        raise SystemExit("%s: not an interleaved multi-pad recording" % args.recording)
    n, j = il
    doc = dict(data, inputs=collapse_pads(data["inputs"], n, j), polls=data.get("polls", 0) // n,
               salvaged={"from": os.path.relpath(os.path.abspath(args.recording), ROOT), "pads": n, "port": j + 1})
    json.dump(doc, open(args.out, "w"), separators=(",", ":"))
    return {"recording": args.out, "pads": n, "port": j + 1, "inputs": len(doc["inputs"]),
            "was": len(data["inputs"])}


def select_records(args):
    jobs = patch_xbe.tier_filter(patch_xbe.select(args), args)
    if args.set:
        keep = patch_xbe.read_addr_file(args.set)
        jobs = [j for j in jobs if j[0] in keep]
    drop = patch_xbe.read_addr_file(args.exclude) if args.exclude else set()
    if not args.no_default_exclude:
        drop |= patch_xbe.default_exclude()
    jobs = [j for j in jobs if j[0] not in drop]
    cache = patch_xbe.load_cache()
    recs = patch_xbe.check_extent(patch_xbe.prepare_all(jobs, args.jobs, cache))
    patch_xbe.save_cache(cache)
    classes = set(args.classes.split(","))
    for r in recs:
        if r.get("status") == "ok" and r["class"] not in classes:
            r["status"] = "skip"
    return recs


def compare(args, recs=None, name="patched", baseline=None):
    """Hooks-only baseline vs the hybrid build with `recs`. Returns a verdict dict."""
    if recs is None:
        recs = select_records(args)
    if baseline is None:
        baseline = build_and_run("baseline", [], args.replay, args.seconds)
    pat = build_and_run(name, recs, args.replay, args.seconds, coverage=args.coverage)
    a, b = checkpoints(baseline), checkpoints(pat)
    mf = getattr(args, "max_frame", MAX_FRAME)
    d = first_divergence(a, b, mf)
    v = {"patched": pat["patched"], "title": pat["title"], "exited": pat["exited"], "frozen": pat["frozen"],
         "frames": (pat.get("hybrid") or {}).get("frame"), "baseline_frames": (baseline.get("hybrid") or {}).get("frame"),
         "common_checkpoints": common_frames(a, b, mf), "divergence": d}
    if "coverage" in pat:
        v["functions_run"] = pat["coverage"]["hit"]
    # it must also keep running: reach the end of the compared window if the baseline did
    need = min(mf or 1 << 30, v["baseline_frames"] or 0)
    v["ran_far_enough"] = (v["frames"] or 0) >= need
    v["pass"] = bool(pat["title"] and not pat["exited"] and d is None and v["common_checkpoints"] > 0
                     and v["ran_far_enough"])
    return v


def add_selection_args(ap):
    ap.add_argument("--matches")
    ap.add_argument("--equivalent", action="store_true")
    ap.add_argument("--only")
    ap.add_argument("--set")
    ap.add_argument("--exclude")
    ap.add_argument("--no-default-exclude", action="store_true")
    ap.add_argument("--classes", default="identical")
    ap.add_argument("--jobs", type=int, default=8)
    patch_xbe.add_tier_args(ap)


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    d = sub.add_parser("determinism")
    d.add_argument("--runs", type=int, default=2)
    d.add_argument("--max-frame", type=int, default=0, help="compare checkpoints up to this frame (0: all)")
    d.add_argument("--wide", action="store_true", help="also hash all of .data/.bss (minus wide-mask.json)")
    d.add_argument("--snap-frame", type=int, default=0, help="with --wide: keep page hashes at this frame")
    d.add_argument("--no-vclock", action="store_true", help="only GameClock is virtual (the old hooks)")
    d.add_argument("--shots", action="store_true", help="also take screenshots (can wedge xemu's monitor during loads)")
    r = sub.add_parser("record")
    r.add_argument("name")
    r.add_argument("--minutes", type=float, default=240)
    r.add_argument("--pad", default=None, help="port-1 binding: 'keyboard' or a gamepad GUID (default: your xemu "
                   "config's, else the keyboard)")
    r.add_argument("--out", help="default tests/replays/NAME.json")
    r.add_argument("--no-quant", action="store_true", help="record raw analog values (by default sticks and pressure "
                   "buttons are snapped to coarse steps, which the game is given too, so pad changes stay rare)")
    r.add_argument("--mute", action="store_true", help="record without sound (sound is on for recordings, off for replays)")
    r.add_argument("--snap-every", type=float, default=SNAP_EVERY, help="minutes between VM snapshots (0: none; "
                   "they need the recording's own disk overlay, NAME.disk.qcow2, ~60 MB each)")
    r.add_argument("--v1", action="store_true", help="the old format: no virtual pad (the game polls every pad xemu "
                   "has bound) and the host's date; for comparisons only")
    r.add_argument("--script", help="test the pipeline without a player: feed this pad script (keyed by polls); "
                   "what the game was given is recorded")
    p = sub.add_parser("replay")
    p.add_argument("recording")
    p.add_argument("--seconds", type=float, default=0)
    p.add_argument("--until-frame", type=int, default=0, help="stop once the game reaches this frame")
    p.add_argument("--from-snapshot", type=int, help="resume the recording's VM snapshot K (negative: from the end)")
    p.add_argument("--from-frame", type=int, help="resume the latest snapshot at or before this frame")
    p.add_argument("--no-syncio", action="store_true", help="with --from-snapshot/--from-frame: let the game's file "
                   "requests complete in host time, as before (they diverged; docs/tasks/record-replay.md)")
    p.add_argument("--drawlog", help="also log the pddi state of every draw (hooks.cpp HYBRID_DRAWLOG) in frames "
                   "EVERY[:FIRST[:LAST]] (off by default); checkpoints are still compared")
    p.add_argument("--drawlog-out", help="where to write the draw log (default build/hybrid/test/drawlog.jsonl)")
    sv = sub.add_parser("salvage")
    sv.add_argument("recording")
    sv.add_argument("out")
    c = sub.add_parser("compare")
    add_selection_args(c)
    c.add_argument("--coverage", action="store_true")
    c.add_argument("--max-frame", type=int, default=MAX_FRAME)
    for p in (d, c):
        p.add_argument("--replay", default=DEFAULT_REPLAY if os.path.exists(DEFAULT_REPLAY) else None)
        p.add_argument("--seconds", type=float, default=60)
    a = ap.parse_args(argv)
    res = {"determinism": determinism, "compare": compare, "record": record, "replay": replay,
           "salvage": salvage}[a.cmd](a)
    print(json.dumps(res, indent=1))
    json.dump(res, open(os.path.join(TEST_DIR, a.cmd + "-result.json"), "w"), indent=1)
    return 0 if res.get("deterministic", res.get("pass", res.get("identical", True))) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
