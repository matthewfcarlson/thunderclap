#!/usr/bin/env python3
"""The disc pack's optional AV1 movies (wpkg1, D237; docs/wasm-port.md "Disc sources"): the game's Bink movies (.rmv
in the movie archives) re-encoded for the app's decoder, so the pack drops the Bink pictures.

  build/venv/bin/python tools/disc_av1.py encode SRC OUTDIR [--crf 30] [--preset 6] [--audio-kbps 32]
  build/venv/bin/python tools/disc_pack.py build SRC OUT.hulkdisc --av1 OUTDIR

SRC is the extracted disc folder, an .iso or a pack. Every RCF entry that is a Bink file becomes OUTDIR/<archive>/
<entry hash>.mkv: Matroska with the picture as AV1 (SVT-AV1, 8-bit 4:2:0, the same size, frame count and rate: every
frame passed through) and each Bink sound track as a mono/stereo Opus track in the Bink file's track order. Each
encode is checked: its decoded frame count must be the Bink header's. OUTDIR/av1.json records the settings and the
movies.

What the game reads stays the Bink file's: bink_null.c reads the first 44 bytes of the movie through the game's own
I/O (which reads the first KiB), and the archives' headers and directories are untouched; the pack keeps the first
KEEP bytes of every movie (its header and frame index with room to spare) and stores the rest as zeros (no bytes).
The runner (run/app/movie.c) decodes .hulk/av1/<archive>/<hash>.mkv instead when the pack has it, taking the frame
count, the rate and the sound tracks' ids from the kept Bink header. Needs FFmpeg with libsvtav1 and libopus to
encode (Homebrew's), and an FFmpeg with an AV1 decoder (libdav1d) and Opus to play. The outputs are the game's
movies: build/ only, never committed or published.
"""
import argparse
import json
import os
import struct
import subprocess
import sys
import tempfile
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import disc_pack  # noqa: E402

KEEP = 64 * 1024          # bytes of each movie the pack keeps (the game reads its first KiB)
RCF_MAGIC = b"ATG CORE CEMENT LIBRARY"


def rcf_movies(src, name):
    """[(entry name, hash, offset, size, header bytes)] of the archive's Bink entries"""
    h = src.read(name, 0, 0x3C)
    if h[:23] != RCF_MAGIC:
        return []
    dir_off, dir_size, names_off, names_size, _, count = struct.unpack_from("<6I", h, 0x24)
    d = src.read(name, dir_off, dir_size)
    by_hash = {}
    for i in range(count):
        hh, off, size = struct.unpack_from("<3I", d, 12 * i)
        by_hash[hh] = (off, size)
    nt = src.read(name, names_off, names_size)
    p = 8
    out = []
    for _ in range(count):
        _mt, _al, _z, n = struct.unpack_from("<4I", nt, p)
        p += 16
        ename = nt[p:p + n - 1].decode("latin1")
        p += n + 3
        hh = rhash(ename)
        off, size = by_hash[hh]
        head = src.read(name, off, 0x200)
        if head[:3] == b"BIK":
            out.append((ename, hh, off, size, head))
    return out


def rhash(s):
    h = 0
    for ch in s.encode("latin1"):
        c = ch - 256 if ch > 127 else ch
        if c < ord("a"):
            c += 0x20
        h = (h * 31 + c) & 0xFFFFFFFF
    return h


def bink_info(head):
    frames, = struct.unpack_from("<I", head, 8)
    w, hgt, num, den = struct.unpack_from("<4I", head, 20)
    tracks, = struct.unpack_from("<I", head, 40)
    ids = list(struct.unpack_from("<%dI" % tracks, head, 44 + 8 * tracks)) if tracks <= 16 else []
    return {"frames": frames, "width": w, "height": hgt, "fps": [num, den], "tracks": tracks, "track_ids": ids}


def count_frames(path):
    r = subprocess.run(["ffprobe", "-v", "error", "-count_frames", "-select_streams", "v:0", "-show_entries",
                        "stream=nb_read_frames,codec_name,width,height", "-of", "json", path],
                       capture_output=True, text=True)
    s = json.loads(r.stdout or "{}").get("streams", [{}])[0]
    return int(s.get("nb_read_frames", -1)), s


def cmd_encode(a):
    src = disc_pack.open_source(a.src)
    os.makedirs(a.out, exist_ok=True)
    movies = {}
    t0 = time.time()
    total_in = total_out = 0
    for name in sorted(src.files):
        if not name.lower().endswith(".rcf"):
            continue
        for ename, hh, off, size, head in rcf_movies(src, name):
            info = bink_info(head)
            dest = os.path.join(a.out, name, "%08x.mkv" % hh)
            os.makedirs(os.path.dirname(dest), exist_ok=True)
            key = "%s:%08x" % (name, hh)
            if not os.path.exists(dest):
                with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as td:
                    bik = os.path.join(td, "in.bik")
                    with open(bik, "wb") as f:
                        for o in range(0, size, 8 << 20):
                            f.write(src.read(name, off + o, min(8 << 20, size - o)))
                    cmd = ["ffmpeg", "-hide_banner", "-loglevel", "error", "-y", "-i", bik, "-map", "0:v:0"]
                    cmd += ["-map", "0:a?", "-c:v", "libsvtav1", "-preset", str(a.preset), "-crf", str(a.crf),
                            "-pix_fmt", "yuv420p", "-svtav1-params", "lp=2", "-g", "300", "-fps_mode", "passthrough", "-c:a", "libopus",
                            "-b:a", "%dk" % a.audio_kbps, "-f", "matroska", dest + ".part"]
                    r = subprocess.run(cmd, capture_output=True, text=True)
                    if r.returncode:
                        raise SystemExit("%s: ffmpeg: %s" % (key, r.stderr[-2000:]))
                os.replace(dest + ".part", dest)
            n, s = count_frames(dest)
            ok = n == info["frames"] and s.get("width") == info["width"] and s.get("height") == info["height"]
            movies[key] = dict(info, entry=ename, offset=off, size=size, av1=os.path.relpath(dest, a.out),
                               av1_size=os.path.getsize(dest), decoded_frames=n, ok=ok)
            total_in += size
            total_out += os.path.getsize(dest)
            print("%-14s %-32s %5d frames %3dx%d: %6.1f MB -> %5.1f MB%s" % (
                name, ename, info["frames"], info["width"], info["height"], size / 1e6,
                os.path.getsize(dest) / 1e6, "" if ok else "  FAIL (decoded %d frames, %s)" % (n, s)), flush=True)
            if not ok:
                os.rename(dest, dest + ".bad")
    json.dump({"crf": a.crf, "preset": a.preset, "audio_kbps": a.audio_kbps, "keep": KEEP, "movies": movies},
              open(os.path.join(a.out, "av1.json"), "w"), indent=1, sort_keys=True)
    bad = [k for k, v in movies.items() if not v["ok"]]
    print("disc_av1: %d movies, %.1f MB of Bink -> %.1f MB (%.1f%%) in %.0f s%s" % (
        len(movies), total_in / 1e6, total_out / 1e6, 100.0 * total_out / max(total_in, 1), time.time() - t0,
        "; FAIL: %s" % bad if bad else ""))
    return 1 if bad else 0


def load_for_pack(outdir, src):
    """For disc_pack.py build --av1: the ranges to store as zeros, the members, the manifest part"""
    j = json.load(open(os.path.join(outdir, "av1.json")))
    zero, members, man = {}, {}, {"keep": j["keep"], "crf": j["crf"], "audio_kbps": j["audio_kbps"], "movies": {}}
    for key, m in sorted(j["movies"].items()):
        if not m["ok"]:
            continue
        name, hh = key.rsplit(":", 1)
        if name not in src.files:
            raise SystemExit("%s: %s is not on this disc" % (outdir, name))
        head = src.read(name, m["offset"], 0x200)
        if bink_info(head)["frames"] != m["frames"]:
            raise SystemExit("%s: %s differs from the disc the movies were encoded from" % (outdir, key))
        lo, hi = m["offset"] + j["keep"], m["offset"] + m["size"]
        if hi > lo:
            zero.setdefault(name, []).append((lo, hi))
        member = ".hulk/av1/%s/%s.mkv" % (name, hh)
        members[member] = open(os.path.join(outdir, m["av1"]), "rb").read()
        man["movies"][key] = {"entry": m["entry"], "frames": m["frames"], "member": member}
    man["zero"] = zero
    return {"zero": zero, "members": members, "manifest": man}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("encode")
    c.add_argument("src")
    c.add_argument("out")
    c.add_argument("--crf", type=int, default=30)
    c.add_argument("--preset", type=int, default=6)
    c.add_argument("--audio-kbps", type=int, default=32)
    a = ap.parse_args(argv)
    return cmd_encode(a)


if __name__ == "__main__":
    sys.exit(main())
