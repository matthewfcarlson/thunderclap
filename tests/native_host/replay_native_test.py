#!/usr/bin/env python3
"""The native replay driver (src/platform/sdl/host/replay_native.cpp) and the link's replay hooks (tools/native_bind.py
plan_hooks, src/platform/sdl/host/native_hooks.h) on arm64 macOS (docs/native-android.md section 14).

  build/venv/bin/python tests/native_host/replay_native_test.py [--out DIR]

The real GameClock::Update (matches/0x00086450.cpp) goes through the tree's pipeline (the MS-ABI front end for
aarch64-pc-windows-msvc, native_mac.retarget, the backend), with a stand-in game world (tests/native_host/
replay_native_world.cpp: the debug menu Update asks, the game's data items, a game loop calling Update). The link step
is the image's: native_bind binds the CRT table and applies native_hooks.h's rows for 0x00086450 (the entry hook
`hulk_nhook_clock_update` and the site rebind of its GetMicroseconds64 call to the shim's virtual clock
`hulk_clock_tick`, src/platform/sdl/xdk/timing.cpp compiled as host code), and writes the `hulk_orig_` thunk. The host
side is the driver, the input layer with the replay reader (SDL3 for the host, build/third_party/out/sdl-host), the
shim's timing and the host glue.

The recording (written here) carries the checkpoints a Python model of the 32-bit layout computes (hulk_replay.h: FNV-1a
over the frame, the RNG, g_BootSequenceStep, the camera at +0x4c, the GameClock's +0x10 block with step and scaled step
zero) for frames 0, 30, 60, 90; the camera singleton is null until frame 30, then moves. The driver must match all
four; the control run (one recorded hash off) must report one divergence, at frame 30. That shows: the entry hook runs
before every update, the site rebind gives Update the virtual clock (300 s, then +33,333 us), the hashed regions are
read from the 64-bit objects at the right offsets, the recording's skip-intro tweak reaches g_BootSequenceStep.
"""
import argparse
import json
import os
import re
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import clang_probe as cp  # noqa: E402
import native_bind as nb  # noqa: E402
import native_mac as nmac  # noqa: E402

FRONT = ["--target=aarch64-pc-windows-msvc", "-fms-extensions", "-fms-compatibility", "-fms-compatibility-version=13.10",
         "-std=c++14", "-O0", "-S", "-emit-llvm", "-I" + os.path.join(ROOT, "include"), "-fno-strict-aliasing", "-fwrapv",
         "-fno-delete-null-pointer-checks", "-Xclang", "-fno-wchar", "-fcheck-new", "-ffp-eval-method=double",
         "-ffp-contract=off", "-w"]
SDL = os.path.join(ROOT, "build/third_party/out/sdl-host")
HOST = ["src/platform/sdl/host/replay_native.cpp", "src/platform/sdl/input/hulk_input.cpp",
        "src/platform/sdl/xdk/timing.cpp", "src/platform/sdl/xdk/trace.cpp", "src/platform/sdl/host/host_crt_posix.cpp",
        "src/platform/sdl/host/crt_posix.cpp", "src/platform/sdl/host/win32_posix.cpp", "src/platform/sdl/crt/softx87.cpp"]
SDL_LINK = ["-framework", "CoreAudio", "-framework", "AudioToolbox", "-framework", "CoreFoundation", "-framework", "IOKit",
            "-framework", "GameController", "-framework", "CoreHaptics", "-framework", "ForceFeedback", "-framework",
            "Foundation", "-framework", "AVFoundation", "-framework", "CoreMotion", "-framework", "Carbon", "-framework",
            "AppKit", "-framework", "Metal", "-framework", "QuartzCore", "-framework", "UniformTypeIdentifiers",
            "-framework", "CoreVideo", "-framework", "CoreMedia", "-liconv"]
FRAMES, INTERVAL = 91, 30
RNG, BOOT_BEFORE = (0x1234, 0x5678), 2


def fnv(h, b):
    for x in b:
        h = ((h ^ x) * 16777619) & 0xffffffff
    return h


def model():
    """{frame: hash} of the checkpoints, from the 32-bit layout (hulk_replay.h) and the world's rules."""
    out = {}
    for f in range(0, FRAMES, INTERVAL):
        h = fnv(2166136261, struct.pack("<I", f))
        h = fnv(h, struct.pack("<II", *RNG))
        h = fnv(h, struct.pack("<I", 6))                         # skip-intro: g_BootSequenceStep 6
        if f >= 30:                                               # the camera singleton exists from frame 30
            h = fnv(h, struct.pack("<fff", float(f), 2.0, 3.0))
        d = 33333                                                 # the virtual clock's step (the first update: 300 s,
        total = d * f                                             # 33,333 us after the constructor's 300 s - dt)
        h = fnv(h, struct.pack("<QQQQQQ", total, total, d if f else 0, 0, 0, 0x10000))
        out[f] = h
    return out


def run(cmd, what, **kw):
    r = subprocess.run(cmd, capture_output=True, text=True, errors="replace", **kw)
    if r.returncode:
        sys.exit("%s failed (rc %d):\n%s\n%s" % (what, r.returncode, " ".join(cmd)[:800], (r.stdout + r.stderr)[-3000:]))
    return r


def game_obj(src, out, name):
    ll, tl, o = (os.path.join(out, name + x) for x in (".ll", ".t.ll", ".o"))
    run([cp.tool("clang++")] + FRONT + [src, "-o", ll], "front end " + name)
    open(tl, "w", errors="surrogateescape").write(nmac.retarget(open(ll, errors="surrogateescape").read()))
    run([cp.tool("clang")] + nmac.BACK + [tl, "-o", o], "backend " + name)
    return o


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=os.path.join(ROOT, "build/a2s1/replay-native-test"))
    a = ap.parse_args()
    out = a.out
    os.makedirs(out, exist_ok=True)
    if not os.path.exists(os.path.join(SDL, "lib/libSDL3.a")):
        sys.exit("no host SDL3 (tools/wine_sdl.py builds build/third_party/out/sdl-host)")
    objs = [game_obj(os.path.join(ROOT, "matches/0x00086450.cpp"), out, "clock"),
            game_obj(os.path.join(ROOT, "tests/native_host/replay_native_world.cpp"), out, "world")]
    syms = nmac.nm_macho(objs)
    defined = set().union(*(d for d, _u in syms.values()))
    update = next(s for s in defined if s.startswith("?FUN_00086450@"))
    sym64 = {0x00086450: update, 0x00267f40: "FUN_00267f40"}.get
    rows = [r for r in nb.hook_rows() if r[1] == 0x00086450 and r[2] in (0, 0x00267f40)]
    ren, thunks, rep = nb.plan_hooks(syms, sym64, "macho", rows=rows)
    print("hooks: " + json.dumps(rep))
    table = nb.Table()
    binding = nb.plan(set().union(*(u for _d, u in syms.values())) - defined, table)
    objs, st = nb.apply(objs, binding, syms, os.path.join(out, "bound"), "macho", extra=ren)
    print("apply: " + json.dumps(st))
    if not all(r.get("applied") == "yes" for r in rep):
        sys.exit("a hook was not applied")
    th = os.path.join(out, "thunks.s")
    open(th, "w").write(nb.thunk_asm(thunks, "macho", "arm64"))
    host = [th]
    for src in HOST:
        o = os.path.join(out, os.path.basename(src) + ".o")
        run(["xcrun", "clang++", "-arch", "arm64", "-std=c++17", "-O1", "-g", "-mmacosx-version-min=13.0", "-DHULK_NATIVE_SDL=1",
             "-I" + os.path.join(ROOT, "src/platform/sdl"), "-I" + os.path.join(SDL, "include"), "-c",
             os.path.join(ROOT, src), "-o", o], "host " + src)
        host.append(o)
    main_o = os.path.join(out, "main.o")
    run(["xcrun", "clang++", "-arch", "arm64", "-std=c++17", "-O1", "-mmacosx-version-min=13.0",
         "-I" + os.path.join(ROOT, "src/platform/sdl"), "-c", os.path.join(ROOT, "tests/native_host/replay_native_test.cpp"),
         "-o", main_o], "test main")
    # the game functions the driver reaches through thunks that this world does not define: stubs that abort
    allsyms = nmac.nm_macho(objs + [o for o in host if o.endswith(".o")] + [main_o])
    d_all = set().union(*(d for d, _u in allsyms.values())) | {n for n, f in thunks.items() if f}
    missing = sorted({s for _d, u in allsyms.values() for s in u if s.startswith("hulk_orig_")} - d_all)
    stub = os.path.join(out, "stubs.s")
    open(stub, "w").write("\t.text\n" + "".join('\t.globl _%s\n_%s:\n\tbrk #1\n' % (s, s) for s in missing))
    image = os.path.join(out, "replay_native")
    run(["xcrun", "clang++", "-arch", "arm64", "-mmacosx-version-min=13.0", main_o, stub] + objs + host +
        [os.path.join(SDL, "lib/libSDL3.a")] + SDL_LINK + ["-o", image], "link")
    want = model()
    rc = 0
    for control in (False, True):
        ck = dict(want)
        if control:
            ck[30] ^= 1
        rec = os.path.join(out, "control.json" if control else "recording.json")
        json.dump({"version": 2, "flags": ["fixed-dt", "vclock", "ckpt"], "tweaks": ["skip-intro"], "seed": 4660,
                   "inputs": [[0, 0, [0] * 8, [0] * 4]], "checkpoints": [[f, h] for f, h in sorted(ck.items())]},
                  open(rec, "w"))
        env = dict(os.environ, HULK_INPUT_SOURCE="replay:" + rec, HULK_CKPT="1", HULK_VCLOCK="1",
                   SDL_VIDEO_DRIVER="dummy", SDL_AUDIO_DRIVER="dummy")
        r = subprocess.run([image, str(FRAMES)], capture_output=True, text=True, env=env)
        print(r.stdout.strip())
        m = re.search(r"^stats frames (\d+) checked (\d+) matched (\d+) mismatched (\d+) first_bad (-?\d+)", r.stdout, re.M)
        if not m:
            print(r.stderr[-2000:])
            return 1
        frames, checked, matched, mism, first_bad = map(int, m.groups())
        ok = (frames == FRAMES and checked == len(want) and
              ((matched, mism, first_bad) == (len(want) - 1, 1, 30) if control else (matched, mism) == (len(want), 0)))
        print("%s: %s" % ("control (one recorded hash off)" if control else "replay", "ok" if ok else "FAILED"))
        rc |= 0 if ok else 1
    print("replay_native_test: %s" % ("ok" if rc == 0 else "FAILED"))
    return rc


if __name__ == "__main__":
    sys.exit(main())
