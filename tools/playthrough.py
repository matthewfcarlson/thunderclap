#!/usr/bin/env python3
"""Playthroughs: record yourself playing on from the end of play3 (or of an earlier session) in the macOS app, and
chain the sessions into one replay of the whole game (wplay4, D244; docs/playthrough.md).

    build/venv/bin/python tools/playthrough.py record --name play4 [--app build/Hulk.app] [--settings K=V,...]
    build/venv/bin/python tools/playthrough.py replay --name play4 [--exe EXE] [--frames N] [--out DIR]
    build/venv/bin/python tools/playthrough.py check --name play4 RUN.ckref [--frames N]
    build/venv/bin/python tools/playthrough.py list
    build/venv/bin/python tools/playthrough.py merge --name play4        # rebuild play4.hrp and the references

A playthrough lives in build/playthrough/NAME/ (derived game data: never committed):
  playthrough.json      the base recording, the settings, every segment's start and end (present, frame, poll)
  NAME.hrp              the base's inputs to the first segment's start, then every segment's, with a SEG1 trailer
                        (tools/native_replay.py run --rec NAME; wasm_build_job --test NAME:FRAMES)
  NAME.ckref            the reference: the Xbox's play3 records to their end (56,575), our own records after it
  NAME.self.ckref       our own records only (the base replay's to the first segment, then the sessions'): a replay
                        of the playthrough must give exactly these
  segments/NNN/         a session: its inputs (.hrp entries keyed by poll), .seg (start / end), trace and records
  snapshots/EXE/F.snap  the state at GameClock frame F for one executable (sha256 of the hulk-app): `record` restores the
                        newest one at the playthrough's end; another build replays from frame 0 to make its own
                        (headless-fast in a hidden window, a few minutes), with the save folders beside it

A session runs under replay rules (the recording's virtual clock and generators, lockstep I/O, no FMV, the
simulation's settings pinned), so it is a function of its recording: the player's pad is the only input, and from the
hand-off the voices advance 533 frames a DoWork instead of the replays' 800 (sound at the console's rate; recorded in
the SEG1 trailer). Quitting (the menu's Quit Game, Cmd+Q, the window's close button) ends the session: the app writes
its state at the next frame end and exits, and the segment is appended.
"""
import argparse
import datetime
import glob
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
TOP = os.environ.get("HULK_PLAYTHROUGH_DIR") or os.path.join(ROOT, "build/playthrough")   # (tests: elsewhere)
BASES = {"play3": ("build/rp1/play3.hrp", "build/ckpt/play3.ckref")}
DS_LIVE_WORK = 533
# simulation rows that a playthrough may not set (port_settings.c changes_game): every session and replay must agree
SIM_KEYS = {"aspect", "hud_frame", "draw_distance", "tutorial_skip", "remaster_moves", "developer"}
STATE_DIRS = ("save", "tdata", "udata")
PROGRESS_EVERY = 5.0       # seconds between the catch-up's progress lines
PLAYER_DIR = os.path.expanduser("~/Library/Application Support/HulkUD")


def die(msg):
    sys.exit("playthrough: " + msg)


def pdir(name):
    if not name or "/" in name or name.startswith("."):
        die("bad name %r" % name)
    return os.path.join(TOP, name)


def load(name, create=False, base="play3"):
    p = os.path.join(pdir(name), "playthrough.json")
    if os.path.exists(p):
        return json.load(open(p))
    if not create:
        die("no playthrough %s (%s)" % (name, p))
    hrp, ref = BASES.get(base, (base, None))
    return {"name": name, "base": base, "base_hrp": hrp, "base_ref": ref, "settings": "", "ds_live_work": DS_LIVE_WORK,
            "segments": [], "created": now()}


def save(pt):
    d = pdir(pt["name"])
    os.makedirs(d, exist_ok=True)
    tmp = os.path.join(d, "playthrough.json.tmp")
    json.dump(pt, open(tmp, "w"), indent=1)
    os.replace(tmp, os.path.join(d, "playthrough.json"))


def now():
    return datetime.datetime.now().isoformat(timespec="seconds")


def absr(p):
    return p if os.path.isabs(p) else os.path.join(ROOT, p)


# ------------------------------------------------------------------------------------------------ .hrp
HDR = struct.Struct("<4sHHIIIIIII")


def read_hrp(path):
    d = open(path, "rb").read()
    h = HDR.unpack_from(d, 0)
    if h[0] != b"HRP1":
        die("%s: not an .hrp" % path)
    n, nc = h[8], h[9]
    at = 36
    ent = [d[at + 24 * i: at + 24 * i + 24] for i in range(n)]
    at += 24 * n
    ck = [struct.unpack_from("<2I", d, at + 8 * i) for i in range(nc)]
    at += 8 * nc
    pk = []
    if d[at:at + 4] == b"PRN1":
        k = struct.unpack_from("<I", d, at + 4)[0]
        pk = [struct.unpack_from("<2I", d, at + 8 + 8 * i) for i in range(k)]
        at += 8 + 8 * k
    return {"hdr": h, "entries": ent, "ckpts": ck, "prng": pk}


def entry_key(e):
    return struct.unpack_from("<I", e, 0)[0]


def write_hrp(path, base, segs, inputs, ds_work):
    """base's header and its entries / checkpoints up to the first segment's start, then each segment's entries
    (keys within the segment), then PRN1 and SEG1."""
    h = base["hdr"]
    if segs:
        p0, f0 = segs[0]["start"]["polls"], segs[0]["start"]["frame"]
        ent = [e for e in base["entries"] if entry_key(e) <= p0]
        ck = [c for c in base["ckpts"] if c[0] < f0]
        pk = [c for c in base["prng"] if c[0] < f0]
    else:
        ent, ck, pk = list(base["entries"]), list(base["ckpts"]), list(base["prng"])
    for s, es in zip(segs, inputs):
        lo, hi = s["start"]["polls"], s["end"]["polls"]
        last = entry_key(ent[-1]) if ent else 0
        for e in es:
            k = entry_key(e)
            if lo < k <= hi and k > last:
                ent.append(e)
                last = k
    out = bytearray(HDR.pack(b"HRP1", h[1], h[2], h[3], h[4], h[5], h[6], h[7], len(ent), len(ck)))
    for e in ent:
        out += e
    for c in ck:
        out += struct.pack("<2I", *c)
    out += b"PRN1" + struct.pack("<I", len(pk))
    for c in pk:
        out += struct.pack("<2I", *c)
    if segs:
        out += b"SEG1" + struct.pack("<3I", 1, len(segs), ds_work)
        for s in segs:
            out += struct.pack("<6I", s["start"]["present"], s["start"]["frame"], s["start"]["polls"],
                               s["end"]["present"], s["end"]["frame"], s["end"]["polls"])
    tmp = path + ".tmp"
    open(tmp, "wb").write(out)
    os.replace(tmp, path)
    return len(ent)


def read_inputs(path):
    if not os.path.exists(path):
        return []
    d = open(path, "rb").read()
    return [d[i:i + 24] for i in range(0, len(d) - 23, 24)]


def read_seg(path):
    """the .seg the app writes: {start: {present, frame, polls}, end: {...}, entries, ...}"""
    if not os.path.exists(path):
        return None
    w = open(path).read().split()
    out = {}
    try:
        i = w.index("start")
        out["start"] = {"present": int(w[i + 2]), "frame": int(w[i + 4]), "polls": int(w[i + 6])}
        i = w.index("end")
        out["end"] = {"present": int(w[i + 2]), "frame": int(w[i + 4]), "polls": int(w[i + 6])}
        out["entries"] = int(w[i + 8])
        out["ds_live_work"] = int(w[w.index("ds_live_work") + 1])
        out["restored"] = int(w[w.index("restored") + 1])
        out["dowork_per_frame"] = float(w[w.index("dowork_per_frame") + 1])
    except (ValueError, IndexError):
        return out or None
    return out


# ------------------------------------------------------------------------------------------------ references
def write_ref(path, pv, recs, unav):
    with open(path + ".tmp", "wb") as f:
        f.write(struct.pack("<3I", 0x464b4348, 1, pv))
        for fr in sorted(recs):
            tags = recs[fr]
            f.write(struct.pack("<3I", fr, sum(1 << t for t in tags), unav.get(fr, 0)))
            for t in sorted(tags):
                f.write(struct.pack("<2I", *tags[t]))
    os.replace(path + ".tmp", path)


def build_refs(pt):
    """NAME.self.ckref (ours: the base replay's records to the first segment's start, then each session's within
    its segment) and NAME.ckref (the Xbox's base reference where it has records, ours after)."""
    import ckpt_ref
    d = pdir(pt["name"])
    segs = pt["segments"]
    srcs = []
    base_rec = os.path.join(d, "base.ckref")
    if os.path.exists(base_rec):
        srcs.append((base_rec, 0, segs[0]["start"]["frame"] if segs else 1 << 31))
    for s in segs:
        srcs.append((os.path.join(d, s["dir"], "trace.txt.ckref"), s["start"]["frame"], s["end"]["frame"]))
    recs, unav, pv = {}, {}, None
    for p, lo, hi in srcs:
        if not os.path.exists(p):
            print("playthrough: no records %s (frames %d..%d are not in the references)" % (p, lo, hi - 1))
            continue
        _, v, r, u = ckpt_ref.read(p)
        pv = v if pv is None else pv
        if v != pv:
            die("%s: probe version %d, the others %d" % (p, v, pv))
        for fr in r:
            if lo <= fr < hi:
                recs[fr] = r[fr]
                unav[fr] = u.get(fr, 0)
    if pv is None:
        return None
    write_ref(os.path.join(d, pt["name"] + ".self.ckref"), pv, recs, unav)
    comb, cun, xbox_to = dict(recs), dict(unav), None
    if pt.get("base_ref") and os.path.exists(absr(pt["base_ref"])):
        _, v, r, u = ckpt_ref.read(absr(pt["base_ref"]))
        if v == pv:
            # the Xbox's records stand for the base's own inputs only: to the first segment's start
            cut = segs[0]["start"]["frame"] if segs else 1 << 31
            r = {fr: t for fr, t in r.items() if fr < cut}
            xbox_to = max(r) if r else None
            for fr in list(comb):
                if xbox_to is not None and fr <= xbox_to:
                    del comb[fr]
                    cun.pop(fr, None)
            comb.update(r)
            for fr in r:
                cun[fr] = u.get(fr, 0)
    write_ref(os.path.join(d, pt["name"] + ".ckref"), pv, comb, cun)
    meta = {"recording": os.path.join(d, pt["name"] + ".hrp"), "name": pt["name"],
            "xbox_reference": pt.get("base_ref"), "xbox_to_frame": xbox_to,
            "self_recorded_from_frame": (xbox_to + 1) if xbox_to is not None else 0,
            "frames": len(comb), "last_frame": max(comb) if comb else None,
            "note": "frames past xbox_to_frame are this port's own records (the base replay, then the sessions)"}
    json.dump(meta, open(os.path.join(d, pt["name"] + ".ckref.json"), "w"), indent=1)
    return meta


def merge(pt):
    d = pdir(pt["name"])
    base = read_hrp(absr(pt["base_hrp"]))
    inputs = [read_inputs(os.path.join(d, s["dir"], "seg.inputs")) for s in pt["segments"]]
    n = write_hrp(os.path.join(d, pt["name"] + ".hrp"), base, pt["segments"], inputs, pt["ds_live_work"])
    meta = build_refs(pt)
    return n, meta


def base_hrp(pt):
    """what a new session starts from: the playthrough so far, or its base recording"""
    if pt["segments"]:
        p = os.path.join(pdir(pt["name"]), pt["name"] + ".hrp")
        if not os.path.exists(p):
            merge(pt)
        return p
    return absr(pt["base_hrp"])


# ------------------------------------------------------------------------------------------------ the app
def find_exe(a):
    if a.exe:
        return os.path.abspath(a.exe)
    app = absr(a.app)
    exe = os.path.join(app, "Contents/MacOS/hulk-app") if app.endswith(".app") else app
    if not os.path.exists(exe):
        die("no app at %s (--app build/Hulk.app or --exe PATH)" % exe)
    return exe


def exe_key(exe):
    h = hashlib.sha256()
    with open(exe, "rb") as f:
        for b in iter(lambda: f.read(1 << 20), b""):
            h.update(b)
    bid = None
    try:
        s = open(exe, "rb").read()
        i = s.find(b"HULK_BUILD_ID=")
        if i >= 0:
            bid = s[i + 14:i + 40].split(b"\0")[0].decode(errors="replace")
    except OSError:
        pass
    return h.hexdigest()[:16], bid


def check_not_player(p):
    rp = os.path.realpath(p)
    if rp == os.path.realpath(PLAYER_DIR) or rp.startswith(os.path.realpath(PLAYER_DIR) + "/"):
        die("%s is the player's own folder: playthroughs keep their saves under build/playthrough" % p)


def fresh_dirs(root, pt=None):
    """empty save folders, or a save-start playthrough's seed save (its T, U, Z drives) in save/"""
    for sub in STATE_DIRS:
        p = os.path.join(root, sub)
        if os.path.isdir(p):
            shutil.rmtree(p)
        os.makedirs(p)
    seed = seed_dir(pt) if pt else None
    if seed:
        shutil.rmtree(os.path.join(root, "save"))
        shutil.copytree(seed, os.path.join(root, "save"))


def seed_dir(pt):
    d = os.path.join(pdir(pt["name"]), "seed", "save")
    return d if pt.get("base") == "save" and os.path.isdir(d) else None


def make_boot_hrp(path, like):
    """a recording with no play of its own, for a playthrough that starts from a save: play3's header (its flags:
    the virtual clock and generators; its tweaks: skip-intro, no-fmv; its seed) and one idle entry at poll 0, so the
    hand-off is the first frame end"""
    h = read_hrp(like)["hdr"]
    out = HDR.pack(b"HRP1", h[1], h[2], h[3], h[4], h[5], h[6], h[7], 1, 0) + bytes(24) + b"PRN1" + struct.pack("<I", 0)
    open(path, "wb").write(out)


def import_save(src, dst):
    """the game's drives (T, U, Z) of a save folder (an app folder's save/, or a folder holding U/) into dst"""
    src = os.path.abspath(os.path.expanduser(src))
    if os.path.isdir(os.path.join(src, "save", "U")):
        src = os.path.join(src, "save")
    if not os.path.isdir(os.path.join(src, "U")):
        die("--from-save %s: no U folder (give the app folder's save/, which holds T, U and Z)" % src)
    if os.path.exists(dst):
        shutil.rmtree(dst)
    os.makedirs(dst)
    for drive in ("T", "U", "Z"):
        if os.path.isdir(os.path.join(src, drive)):
            shutil.copytree(os.path.join(src, drive), os.path.join(dst, drive))      # (read only: copied, never moved)
    return src


def copy_dirs(src, dst):
    for sub in STATE_DIRS:
        s, t = os.path.join(src, sub), os.path.join(dst, sub)
        if os.path.isdir(t):
            shutil.rmtree(t)
        if os.path.isdir(s):
            shutil.copytree(s, t)
        else:
            os.makedirs(t)


def app_env(a, pt, run_dir, extra):
    env = dict(os.environ)
    for k in list(env):
        if k.startswith("HULK_") and k not in ("HULK_MAC_SDL",):
            del env[k]                                  # (nothing of the caller's runs reaches a session)
    appdir = absr(a.app_dir) if a.app_dir else os.path.join(pdir(pt["name"]), "appdir")
    check_not_player(appdir)
    os.makedirs(appdir, exist_ok=True)
    env.update({"HULK_CKPT": "1", "HULK_CKPT_ALL": "1", "HULK_CKREF": "1", "HULK_CKPT_REGIONS": "0",
                "HULK_TRACE_FILE": os.path.join(run_dir, "trace.txt"), "HULK_DATA_DIR": absr(a.data),
                "HULK_SAVE_DIR": os.path.join(run_dir, "save"), "HULK_TDATA_DIR": os.path.join(run_dir, "tdata"),
                "HULK_UDATA_DIR": os.path.join(run_dir, "udata"), "HULK_APP_DIR": appdir,
                "HULK_MODS_DIR": os.path.join(appdir, "mods"), "HULK_GFX_RENDERER": a.renderer})
    if pt.get("settings"):
        env["HULK_SETTINGS"] = pt["settings"]
    env.update(extra)
    for kv in a.env or []:
        k, _, v = kv.partition("=")
        env[k] = v
    return env


PLAY3_END = 56564          # play3's hand-off: the GameClock frame where its last input takes effect (wplay4)
FRAME_LINE = re.compile(rb"ckpt frame (\d+) |hulk: frame (\d+) \(")


def last_frame(trace, so):
    """the run's latest GameClock frame: the trace's last "ckpt frame N" (every frame with HULK_CKPT_ALL), else the
    last "hulk: frame N (...)" report in stdout.txt (presents: within a fraction of a percent of frames)"""
    for path in (trace, so):
        try:
            with open(path, "rb") as f:
                f.seek(0, 2)
                f.seek(max(0, f.tell() - 8192))
                hits = FRAME_LINE.findall(f.read())
        except OSError:
            continue
        if hits:
            a, b = hits[-1]
            return int(a or b)
    return None


def catchup_target(pt):
    """the frame the hidden replay to the start runs to: the end of the last segment, or play3's end"""
    if pt["segments"]:
        return pt["segments"][-1]["end"]["frame"]
    return PLAY3_END if pt.get("base") == "play3" else None


def run_app(exe, env, run_dir, args, show=False, timeout=None, progress=None):
    """PROGRESS = the target frame: every few seconds "frame X of Y (N%, ~M s left)" while the app runs"""
    so = os.path.join(run_dir, "stdout.txt")
    trace = env.get("HULK_TRACE_FILE", os.path.join(run_dir, "trace.txt"))
    t0 = time.time()
    with open(so, "wb") as f:
        p = subprocess.Popen([exe] + args, cwd=run_dir, env=env, stdout=f, stderr=subprocess.STDOUT,
                             start_new_session=True)
        try:
            if progress:
                hist, next_t = [], time.time() + PROGRESS_EVERY
                while True:
                    try:
                        rc = p.wait(timeout=1.0)
                        break
                    except subprocess.TimeoutExpired:
                        pass
                    if timeout and time.time() - t0 > timeout:
                        raise subprocess.TimeoutExpired(exe, timeout)
                    if time.time() < next_t:
                        continue
                    next_t = time.time() + PROGRESS_EVERY
                    fr = last_frame(trace, so)
                    if fr is None:
                        continue
                    hist = (hist + [(time.time(), fr)])[-6:]      # (the rate over the last ~30 s)
                    left = ""
                    if len(hist) > 1 and hist[-1][1] > hist[0][1]:
                        rate = (hist[-1][1] - hist[0][1]) / (hist[-1][0] - hist[0][0])
                        left = ", ~%d s left" % max(0, (progress - fr) / rate)
                    print("playthrough: frame %d of %d (%d%%%s)" % (fr, progress, min(100, 100 * fr // max(1, progress)),
                                                                   left), flush=True)
            else:
                rc = p.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            p.kill()
            rc = p.wait()
            print("playthrough: the app ran past %d s and was stopped" % timeout)
        except KeyboardInterrupt:
            print("\nplaythrough: interrupted; asking the app to quit")
            p.terminate()
            rc = p.wait()
    lines = open(so, errors="replace").read().splitlines()
    if show:
        for l in lines:
            if "playthrough" in l or "ff_fatal" in l or "fatal" in l.lower():
                print("  " + l)
    return rc, lines, time.time() - t0


def snapshots(pt, key):
    d = os.path.join(pdir(pt["name"]), "snapshots", key)
    out = {}
    for p in glob.glob(os.path.join(d, "*.snap")):
        try:
            out[int(os.path.basename(p)[:-5])] = p
        except ValueError:
            pass
    return d, out


def playthrough_end(pt):
    return pt["segments"][-1]["end"]["frame"] if pt["segments"] else None


def prepare(a, pt, exe, key, base):
    """replay the playthrough so far (hidden, unpaced) to its end; keep the state there for this executable"""
    sd, _ = snapshots(pt, key)
    prep = os.path.join(sd, "prep")
    os.makedirs(prep, exist_ok=True)
    fresh_dirs(prep, pt)
    for p in glob.glob(os.path.join(prep, "trace.txt*")):
        os.remove(p)
    tmp = os.path.join(prep, "handoff.snap")
    if os.path.exists(tmp):
        os.remove(tmp)
    extra = {"HULK_RECORD_BASE": base, "HULK_SNAP_AT_HANDOFF": tmp, "HULK_GFX_HIDDEN": "1"}
    if a.from_frame and not pt["segments"]:
        extra["HULK_RECORD_FROM"] = str(a.from_frame)
    env = app_env(a, pt, prep, extra)
    print("playthrough: replaying %s to its end for this build (hidden window, a few minutes) ..." % (
        pt["name"] if pt["segments"] else pt["base"]))
    rc, lines, wall = run_app(exe, env, prep, [os.path.join(absr(a.data), "default.xbe")], show=True,
                              timeout=a.prep_timeout,
                              progress=a.from_frame if a.from_frame and not pt["segments"] else catchup_target(pt))
    hand = [l for l in lines if "handoff snapshot at present" in l]
    if rc != 0 or not hand or not os.path.exists(tmp):
        die("the replay to the end failed (exit %d; %s/stdout.txt)" % (rc, prep))
    present = int(hand[-1].split("(frame ")[1].split(",")[0])      # (snapshots are named by GameClock frame)
    snap = os.path.join(sd, "%d.snap" % present)
    os.replace(tmp, snap)
    copy_dirs(prep, os.path.join(sd, str(present)))
    # the base replay's records (to the first segment's start) for the references, once
    rec = os.path.join(prep, "trace.txt.ckref")
    br = os.path.join(pdir(pt["name"]), "base.ckref")
    if os.path.exists(rec) and (not os.path.exists(br) or not pt["segments"]):
        shutil.copy(rec, br)
    print("playthrough: state at frame %d kept (%.0f s)" % (present, wall))
    return present, snap


def cmd_record(a):
    pt = load(a.name, create=True, base=a.base)
    if a.from_save:
        if pt["segments"]:
            die("%s already has segments: a save starts a new playthrough (another --name)" % a.name)
        d = pdir(a.name)
        os.makedirs(d, exist_ok=True)
        src = import_save(a.from_save, os.path.join(d, "seed", "save"))
        make_boot_hrp(os.path.join(d, "boot.hrp"), absr(BASES.get(a.base, (a.base,))[0]))   # (--base: its header)
        pt.update(base="save", base_hrp=os.path.join(d, "boot.hrp"), base_ref=None, save_from=src,
                  parent=a.parent, note="starts from a save: the game boots with it, the inputs run from boot")
        print("playthrough: %s starts from the save in %s (copied to %s/seed/save); load it from the game's menu" % (
            a.name, src, d))
    if a.settings is not None:
        keys = {kv.partition("=")[0] for kv in a.settings.split(",") if kv}
        bad = keys & SIM_KEYS or {k for k in keys if k.startswith("dev_")}
        if bad:
            die("--settings %s change the game: a playthrough keeps them faithful" % ",".join(sorted(bad)))
        if pt["segments"] and a.settings != pt.get("settings", ""):
            die("--settings differ from the playthrough's (%r): every session of a playthrough uses the same" %
                pt.get("settings", ""))
        pt["settings"] = a.settings
    save(pt)
    exe = find_exe(a)
    key, bid = exe_key(exe)
    base = base_hrp(pt)
    end = playthrough_end(pt)
    sd, snaps = snapshots(pt, key)
    snap = None
    if not a.no_snapshot and not (pt["base"] == "save" and not pt["segments"]):   # (a save start boots)
        if end is not None and end in snaps:
            snap = snaps[end]
        elif end is None and snaps and not a.from_frame:
            snap = snaps[max(snaps)]               # (play3's end: one per build)
        if snap is None:
            _, snap = prepare(a, pt, exe, key, base)
    k = len(pt["segments"]) + 1
    seg_dir = os.path.join(pdir(pt["name"]), "segments", "%03d" % k)
    if os.path.exists(seg_dir):
        shutil.rmtree(seg_dir)
    os.makedirs(seg_dir)
    present = int(os.path.basename(snap)[:-5]) if snap else None
    if snap:
        copy_dirs(os.path.join(sd, str(present)), seg_dir)
    else:
        fresh_dirs(seg_dir, pt)
    extra = {"HULK_RECORD_BASE": base, "HULK_RECORD": os.path.join(seg_dir, "seg")}
    if snap:
        extra["HULK_RESTORE"] = snap
    if a.from_frame and not pt["segments"]:
        extra["HULK_RECORD_FROM"] = str(a.from_frame)
    if a.until:
        extra["HULK_RECORD_UNTIL"] = str(a.until)
    elif a.for_frames:
        if not snap:
            die("--for needs the snapshot start (it counts from the snapshot's frame)")
        extra["HULK_RECORD_UNTIL"] = str(present + a.for_frames)
    if a.input:
        extra["HULK_INPUT"] = a.input
    if a.hidden:
        extra["HULK_GFX_HIDDEN"] = "1"
    env = app_env(a, pt, seg_dir, extra)
    print("playthrough: %s segment %d (build %s, exe %s)%s; quit the game (menu Quit Game, Cmd+Q or close the "
          "window) to end the session" % (pt["name"], k, bid, key, " from frame %d" % present if snap else ""))
    rc, lines, wall = run_app(exe, env, seg_dir, [os.path.join(absr(a.data), "default.xbe")], show=True,
                              timeout=a.timeout)
    seg = read_seg(os.path.join(seg_dir, "seg.seg"))
    if not seg or "end" not in seg:
        die("the session wrote no segment (exit %d; %s/stdout.txt)" % (rc, seg_dir))
    ended = any("session ends at present" in l for l in lines)
    sp = os.path.join(seg_dir, "seg.snap")
    s = {"dir": os.path.relpath(seg_dir, pdir(pt["name"])), "kind": "continue", "start": seg["start"],
         "end": seg["end"], "entries": seg.get("entries"), "recorded": now(), "exe": key, "build": bid,
         "restored": bool(snap), "complete": ended, "wall_s": round(wall), "dowork_per_frame": seg.get(
             "dowork_per_frame"), "frames": seg["end"]["frame"] - seg["start"]["frame"]}
    if s["frames"] <= 0:
        die("the session ended before it began (segment %s)" % seg_dir)
    pt["segments"].append(s)
    save(pt)
    if ended and os.path.exists(sp):
        os.makedirs(sd, exist_ok=True)
        os.replace(sp, os.path.join(sd, "%d.snap" % seg["end"]["frame"]))
        copy_dirs(seg_dir, os.path.join(sd, str(seg["end"]["frame"])))
    else:
        print("playthrough: the app did not end cleanly (exit %d): the segment ends at its last mark, frame %d; the "
              "next session replays to it" % (rc, seg["end"]["frame"]))
    br = os.path.join(pdir(pt["name"]), "base.ckref")
    if not snap and k == 1 and os.path.exists(os.path.join(seg_dir, "trace.txt.ckref")):
        shutil.copy(os.path.join(seg_dir, "trace.txt.ckref"), br)     # (the base replay ran in the session)
    n, meta = merge(pt)
    print("playthrough: segment %d: frames %d..%d (%d frames, %.1f min of play), %d inputs; %s.hrp has %d entries" % (
        k, s["start"]["frame"], s["end"]["frame"], s["frames"], s["frames"] / 1800.0, s["entries"] or 0, pt["name"],
        n))
    if meta:
        print("playthrough: references to frame %s (the Xbox's to %s, ours after)" % (meta["last_frame"],
                                                                                    meta["xbox_to_frame"]))
    return 0


def cmd_merge(a):
    pt = load(a.name)
    n, meta = merge(pt)
    print("%s.hrp: %d entries, %d segments; references: %s" % (pt["name"], n, len(pt["segments"]), meta))


def cmd_list(a):
    for p in sorted(glob.glob(os.path.join(TOP, "*", "playthrough.json"))):
        pt = json.load(open(p))
        segs = pt["segments"]
        tot = sum(s["end"]["frame"] - s["start"]["frame"] for s in segs)
        print("%s: base %s, %d segment%s, %d frames recorded (%.1f min); ends at frame %s" % (
            pt["name"], pt["base"], len(segs), "" if len(segs) == 1 else "s", tot, tot / 1800.0,
            segs[-1]["end"]["frame"] if segs else "(the base's end)"))
        for i, s in enumerate(segs):
            print("  %03d %-8s frames %6d..%6d (%5d) %s%s %s" % (
                i + 1, s.get("kind", "continue"), s["start"]["frame"], s["end"]["frame"],
                s["end"]["frame"] - s["start"]["frame"], s.get("recorded", ""), "" if s.get("complete") else
                " (ended at its last mark)", s.get("note", "")))


def cmd_replay(a):
    pt = load(a.name)
    if not pt["segments"]:
        die("%s has no segments yet" % a.name)
    merge(pt)
    end = pt["segments"][-1]["end"]["frame"]
    frames = a.frames or end - 1
    out = os.path.abspath(a.out or os.path.join(pdir(a.name), "runs", "replay"))
    exe = find_exe(a)
    cmd = [sys.executable, os.path.join(ROOT, "tools/native_replay.py"), "run", "--exe", exe, "--out", out,
           "--rec", a.name, "--frames", str(frames), "--no-check"]     # (a save start's seed: native_replay finds it)
    for kv in ["HULK_GFX_RENDERER=" + a.renderer] + (["HULK_SETTINGS=" + pt["settings"]] if pt.get("settings")
                                                      else []) + (a.env or []):
        cmd += ["--env", kv]
    cmd += ["--", os.path.join(absr(a.data), "default.xbe")]
    r = subprocess.run(cmd)
    if r.returncode:
        return r.returncode
    return check(pt, os.path.join(out, "trace.txt.ckref"), frames)


def check(pt, run, frames):
    """the run against our own records (exactly), then against the combined reference (the Xbox's where it has them)"""
    nr = os.path.join(ROOT, "tools/native_replay.py")
    d = pdir(pt["name"])
    rc1 = subprocess.run([sys.executable, nr, "check", run, "--ref", os.path.join(d, pt["name"] + ".self.ckref"),
                          "--strict", "--frames", str(frames)]).returncode
    print("playthrough: against our own records (every tag, every frame to %d): %s" % (frames,
                                                                                     "identical" if not rc1 else
                                                                                     "DIFFERENT"))
    subprocess.run([sys.executable, nr, "check", run, "--ref", os.path.join(d, pt["name"] + ".ckref")])
    return rc1


def cmd_check(a):
    pt = load(a.name)
    frames = a.frames or pt["segments"][-1]["end"]["frame"] - 1
    return check(pt, a.run, frames)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)

    def common(p):
        p.add_argument("--name", required=True, help="the playthrough (build/playthrough/NAME)")
        p.add_argument("--app", default="build/Hulk.app", help="the app (default build/Hulk.app)")
        p.add_argument("--exe", help="a hulk-app (or hulk-aot) executable instead of --app")
        p.add_argument("--data", default="isos/extracted", help="the game's folder (default isos/extracted)")
        p.add_argument("--env", action="append", help="K=V for the app (tests)")

    r = sp.add_parser("record", help="play on from the playthrough's end (or play3's), recording")
    common(r)
    r.add_argument("--base", default="play3", help="a new playthrough's base recording (default play3)")
    r.add_argument("--from-save", help="start a new playthrough from a game save: an app folder's save/ (T, U, Z); "
                                       "it is copied, and the recording holds it and the inputs from boot")
    r.add_argument("--parent", help="(with --from-save) the playthrough this save came from, as a note")
    r.add_argument("--settings", help="renderer settings for every session of the playthrough (HULK_SETTINGS "
                                      "syntax; set once, at the first session)")
    r.add_argument("--renderer", default="metal")
    r.add_argument("--app-dir", help="the app folder (default build/playthrough/NAME/appdir; never the player's)")
    r.add_argument("--no-snapshot", action="store_true", help="replay to the hand-off in the session itself")
    r.add_argument("--hidden", action="store_true", help="no window (scripted sessions)")
    r.add_argument("--from-frame", type=int, help="(tests) a new playthrough hands off at this GameClock frame")
    r.add_argument("--until", type=int, help="(tests) end the session at this GameClock frame")
    r.add_argument("--for", dest="for_frames", type=int, help="(tests) end the session this many frames in")
    r.add_argument("--input", help="(tests) HULK_INPUT: a scripted stand-in for the player")
    r.add_argument("--timeout", type=int)
    r.add_argument("--prep-timeout", type=int, default=3600)
    p = sp.add_parser("replay", help="replay the whole playthrough headless and check it")
    common(p)
    p.add_argument("--renderer", default="null")
    p.add_argument("--frames", type=int)
    p.add_argument("--out")
    c = sp.add_parser("check", help="a run's records against the playthrough's")
    c.add_argument("--name", required=True)
    c.add_argument("run")
    c.add_argument("--frames", type=int)
    m = sp.add_parser("merge", help="rebuild NAME.hrp and the references from the segments")
    m.add_argument("--name", required=True)
    sp.add_parser("list")
    a = ap.parse_args()
    sys.exit({"record": cmd_record, "replay": cmd_replay, "check": cmd_check, "merge": cmd_merge,
              "list": cmd_list}[a.cmd](a) or 0)


if __name__ == "__main__":
    main()
