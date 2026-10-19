#!/usr/bin/env python3
"""Hybrid recordings for the native replay input source (docs/native-replay.md).

  tools/replay_pack.py pack IN.json OUT.hrp         # recording JSON (v1/v2, or a bare entry list) -> compact binary
  tools/replay_pack.py unpack IN.hrp OUT.json
  tools/replay_pack.py info FILE
  tools/replay_pack.py stream FILE [--polls N]      # reference pad stream: FNV-1a of the 18 bytes of polls 1..N
  tools/replay_pack.py hash --frame F --rng HEX --boot HEX --camera HEX --clock HEX   # a checkpoint hash
  tools/replay_pack.py synth [--check]              # write (or verify) tests/native_input/synth_replay.{hrp,inc}

The .hrp layout (little endian), read by src/platform/sdl/replay/hulk_replay.cpp:
  0  "HRP1"  4 u16 version=1  6 u16 key (0 polls, 1 frames)  8 u32 vpad_count  12 u32 flags (hybrid HF_* bits,
  16 u32 ckpt_interval  20 u32 seed  24 u32 tweaks (1 skip-intro, 2 no-fmv)  28 u32 n_inputs  32 u32 n_checkpoints
  36 n_inputs x 24: u32 key, u16 buttons, u8 analog[8], s16 thumb[4], u16 0      then n_checkpoints x (u32 frame, u32 hash)
seq-rng (no runtime bit in the hybrid build) is bit 13 of flags, rng-log bit 14.

`stream` is an independent implementation of the hybrid build's poll semantics (hybrid/hooks.cpp
hybrid_xinput_get_state): poll p gets the last entry whose key <= p, or an idle pad before the first entry.
"""
import argparse
import json
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HF = {"fixed-dt": 1, "replay": 2, "record": 4, "ckpt": 8, "autostart": 16, "wide": 32, "pollkey": 64,
      "vclock": 128, "iosync": 256, "sound-rng": 512, "quant": 1024, "vpad": 2048, "vdate": 4096,
      "seq-rng": 1 << 13, "rng-log": 1 << 14}
TWEAKS = {"skip-intro": 1, "no-fmv": 2}
HEADER = struct.Struct("<4sHHIIIIIII")        # 36 bytes
ENTRY = struct.Struct("<IH8B4hH")             # 24 bytes


def load(path):
    """-> dict(frame_keyed, vpad_count, flags, ckpt_interval, seed, tweaks, inputs, checkpoints)"""
    with open(path, "rb") as f:
        raw = f.read()
    if raw[:4] == b"HRP1":
        return parse_hrp(raw)
    doc = json.loads(raw)
    if isinstance(doc, list):                                  # tests/replays/*.json: frame-keyed, auto-START
        return dict(frame_keyed=True, vpad_count=1, flags=HF["autostart"], ckpt_interval=30, seed=0, tweaks=0,
                    inputs=[norm(e) for e in doc], checkpoints=[])
    flags = sum(HF.get(n, 0) for n in doc.get("flags", []))
    ck = doc.get("checkpoints", [])
    if isinstance(ck, dict):
        ck = [[int(k), v] for k, v in ck.items()]
    return dict(frame_keyed=not (doc.get("key") == "polls" or flags & HF["pollkey"]),
                vpad_count=doc.get("vpad_count") or 1, flags=flags, ckpt_interval=30, seed=doc.get("seed", 0),
                tweaks=sum(TWEAKS.get(n, 0) for n in doc.get("tweaks", []) if isinstance(n, str)),
                inputs=[norm(e) for e in doc["inputs"]], checkpoints=[[int(a), int(b)] for a, b in ck])


def norm(e):
    key, buttons = e[0], e[1] if len(e) > 1 else 0
    analog = list(e[2]) if len(e) > 2 else []
    thumbs = list(e[3]) if len(e) > 3 else []
    return [key, buttons, analog + [0] * (8 - len(analog)), thumbs + [0] * (4 - len(thumbs))]


def pack(r):
    out = HEADER.pack(b"HRP1", 1, 1 if r["frame_keyed"] else 0, r["vpad_count"], r["flags"], r["ckpt_interval"],
                      r["seed"] & 0xFFFFFFFF, r["tweaks"], len(r["inputs"]), len(r["checkpoints"]))
    out += b"".join(ENTRY.pack(k, b & 0xFFFF, *a, *t, 0) for k, b, a, t in r["inputs"])
    out += b"".join(struct.pack("<II", f, h) for f, h in r["checkpoints"])
    return out


def parse_hrp(raw):
    magic, ver, key, vpad, flags, interval, seed, tweaks, n, nc = HEADER.unpack_from(raw, 0)
    assert magic == b"HRP1" and ver == 1
    ins = []
    for i in range(n):
        k, b, *rest = ENTRY.unpack_from(raw, HEADER.size + ENTRY.size * i)
        ins.append([k, b, list(rest[:8]), list(rest[8:12])])
    o = HEADER.size + ENTRY.size * n
    ck = [list(struct.unpack_from("<II", raw, o + 8 * i)) for i in range(nc)]
    return dict(frame_keyed=key == 1, vpad_count=vpad, flags=flags, ckpt_interval=interval, seed=seed,
                tweaks=tweaks, inputs=ins, checkpoints=ck)


def fnv(h, data):
    for b in data:
        h = ((h ^ b) * 16777619) & 0xFFFFFFFF
    return h


def stream_hash(r, polls):
    """FNV-1a over polls 1..polls of the 18-byte pad state; (hash, last state)"""
    import bisect
    keys = [e[0] for e in r["inputs"]]
    h, last = 2166136261, bytes(18)
    for p in range(1, polls + 1):
        i = bisect.bisect_right(keys, p) - 1
        if i < 0:
            last = bytes(18)
        else:
            _, b, a, t = r["inputs"][i]
            last = struct.pack("<H8B4h", b & 0xFFFF, *a, *t)
        h = fnv(h, last)
    return h, last


def ckpt_hash(frame, rng, boot, camera, clock):
    """hybrid/hooks.cpp checkpoint() without HF_WIDE: frame, rng (8), boot step (4), camera pos (12), clock (48)"""
    h = fnv(2166136261, struct.pack("<I", frame))
    for part in (rng, boot, camera, clock):
        if part is not None:
            h = fnv(h, part)
    return h


# ---------------------------------------------------------------------------------------------
# the synthetic recording of tests/native_input (a few polls, two checkpoints, a wrong one)
def synth_memory():
    """Deterministic stand-in game memory: the checkpoint regions as the C++ test lays them out."""
    def region(n, k):
        return bytes((i * 7 + 3 + k) & 0xFF for i in range(n))
    return dict(rng=region(8, 0), boot=region(4, 10), cam_obj=region(0x60, 20), clock_obj=region(0x40, 40))


def synth_doc():
    m = synth_memory()
    cam, clk = m["cam_obj"][0x4C:0x4C + 12], m["clock_obj"][0x10:0x40]
    good = lambda f: ckpt_hash(f, m["rng"], m["boot"], cam, clk)
    bad = ckpt_hash(60, bytes(8), m["boot"], cam, clk)             # the recording saw another RNG state at 60
    return {"version": 2, "key": "polls",
            "flags": ["fixed-dt", "ckpt", "pollkey", "vclock", "sound-rng", "vpad", "vdate", "seq-rng", "record", "quant"],
            "seed": 4660, "tweaks": ["skip-intro", "no-fmv"],
            "inputs": [[3, 0, [0] * 8, [0] * 4],
                       [5, 16, [0] * 8, [0] * 4],
                       [8, 0, [0] * 8, [0] * 4],
                       [10, 0, [255, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0]],
                       [14, 3, [0, 255, 0, 0, 0, 0, 128, 255], [-15360, 31744, -32768, 32767]],
                       [21, 0, [0] * 8, [0, 0, 100, -100]]],
            "checkpoints": [[0, good(0)], [30, good(30)], [60, bad]],
            "frames": 61, "polls": 25}


def synth_files():
    doc = synth_doc()
    text = json.dumps(doc, indent=1) + "\n"
    tmp = os.path.join(ROOT, "build", "rp1", "synth.json")
    os.makedirs(os.path.dirname(tmp), exist_ok=True)
    with open(tmp, "w") as f:
        f.write(text)
    hrp = pack(load(tmp))
    return text, hrp


def c_array(name, data):
    rows = ["    " + ", ".join("0x%02x" % b for b in data[i:i + 16]) + "," for i in range(0, len(data), 16)]
    return "static const unsigned char %s[%d] = {\n%s\n};\n" % (name, len(data), "\n".join(rows))


def c_string(name, text):
    lines = [json.dumps(l + "\n") for l in text.split("\n")[:-1]]
    return "static const char %s[] =\n%s;\n" % (name, "\n".join("    " + l for l in lines))


def cmd_synth(args):
    text, hrp = synth_files()
    d = os.path.join(ROOT, "tests", "native_input")
    inc = ("// Generated by tools/replay_pack.py synth: the synthetic recording of synth_replay.json as text and as .hrp.\n"
           + c_string("kSynthJson", text) + c_array("kSynthHrp", hrp))
    want = {"synth_replay.json": text.encode(), "synth_replay.hrp": hrp, "synth_replay.inc": inc.encode()}
    bad = 0
    for name, data in want.items():
        p = os.path.join(d, name)
        if args.check:
            if not os.path.exists(p) or open(p, "rb").read() != data:
                print("stale: " + name)
                bad = 1
        else:
            open(p, "wb").write(data)
    print("synth: ok" if not bad else "synth: STALE (run tools/replay_pack.py synth)")
    return bad


# ---------------------------------------------------------------------------------------------
def cmd_pack(args):
    r = load(args.input)
    data = pack(r)
    open(args.output, "wb").write(data)
    print("%s: %d entries, %d checkpoints, %s-keyed, %d pad(s) -> %d bytes" % (
        args.output, len(r["inputs"]), len(r["checkpoints"]), "frame" if r["frame_keyed"] else "poll",
        r["vpad_count"], len(data)))


def cmd_unpack(args):
    r = load(args.input)
    names = [n for n, b in HF.items() if r["flags"] & b]
    doc = {"version": 2, "key": "frames" if r["frame_keyed"] else "polls", "flags": names, "seed": r["seed"],
           "tweaks": [n for n, b in TWEAKS.items() if r["tweaks"] & b], "inputs": r["inputs"],
           "checkpoints": r["checkpoints"]}
    if r["vpad_count"] > 1:
        doc["vpad_count"] = r["vpad_count"]
    json.dump(doc, open(args.output, "w"))
    print("wrote " + args.output)


def cmd_info(args):
    r = load(args.input)
    print(json.dumps({k: v for k, v in r.items() if k not in ("inputs", "checkpoints")}))
    print("entries %d, checkpoints %d, last key %s" % (len(r["inputs"]), len(r["checkpoints"]),
                                                      r["inputs"][-1][0] if r["inputs"] else None))


def cmd_stream(args):
    r = load(args.input)
    if r["frame_keyed"]:
        sys.exit("stream: frame-keyed file (the reference needs the frame of each poll)")
    n = args.polls or (r["inputs"][-1][0] + 10 if r["inputs"] else 0)
    h, last = stream_hash(r, n)
    print("replay-stream %08x polls %d last %s" % (h, n, last.hex()))


def cmd_hash(args):
    h = ckpt_hash(args.frame, bytes.fromhex(args.rng), bytes.fromhex(args.boot),
                  bytes.fromhex(args.camera) if args.camera else None, bytes.fromhex(args.clock))
    print("%08x" % h)


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name, fn in (("pack", cmd_pack), ("unpack", cmd_unpack)):
        p = sub.add_parser(name)
        p.add_argument("input")
        p.add_argument("output")
        p.set_defaults(fn=fn)
    p = sub.add_parser("info")
    p.add_argument("input")
    p.set_defaults(fn=cmd_info)
    p = sub.add_parser("stream")
    p.add_argument("input")
    p.add_argument("--polls", type=int)
    p.set_defaults(fn=cmd_stream)
    p = sub.add_parser("hash")
    p.add_argument("--frame", type=int, required=True)
    for k in ("rng", "boot", "camera", "clock"):
        p.add_argument("--" + k, default="" if k == "camera" else None, required=k != "camera")
    p.set_defaults(fn=cmd_hash)
    p = sub.add_parser("synth")
    p.add_argument("--check", action="store_true")
    p.set_defaults(fn=cmd_synth)
    args = ap.parse_args(argv)
    return args.fn(args) or 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
