#!/usr/bin/env python3
"""The Android app of the wasm2c build (wand1; docs/wasm-port.md "The Android app"): the macOS app's module and
runner, compiled by the NDK for arm64-v8a (Android 12+, API 31) into libmain.so and packaged as a debug APK.

  build/venv/bin/python tools/wasm_android.py bgfx                 # bx/bimg/bgfx for android-arm64 (Vulkan + GLES)
  build/venv/bin/python tools/wasm_android.py build [--wasm-dir build/wasm-app] [--jobs 2]   # -> <out>/libmain.so
  build/venv/bin/python tools/wasm_android.py apk [--out <out>/hulk.apk]                    # tools/android_apk.py

`build` takes the HULK_WASM_GFX=1 module a `tools/wasm_app.py build` made (<wasm-dir>/hulk.wasm: the macOS app's,
so the two runners run the same module), runs wasm2c on it into <out>/aot and compiles the C with the NDK clang at the
macOS app's flags (-O2, -fno-strict-aliasing); then the runner (src/platform/wasm/run/native.c with HULK_APP, its
`main` as SDL_main, run/app/, the bgfx sink and bridge host half, platform_events.cpp) and run/android/ (log
redirection), and links libmain.so with SDL3 (tools/native_android_sdl.py --config app) and bgfx. Objects are cached
by content and flags. The module is the game built from the player's own XBE: libmain.so and the APK stay under build/,
debug-signed, never committed or published.

Environment: HULK_NDK (default build/android/ndk), HULK_ANDROID_SDL (default build/third_party/out/sdl-android-arm64-app),
HULK_WAND_OUT (default build/wand1/android). `apk` needs JAVA_HOME / ANDROID_HOME (build/android/env.sh).
"""
import argparse
import concurrent.futures
import hashlib
import json
import os
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
PY = sys.executable
API = 31
TRIPLE = "aarch64-linux-android%d" % API
TP = os.path.join(ROOT, "build/third_party")
NDK = os.environ.get("HULK_NDK") or os.path.join(ROOT, "build/android/ndk")
NDKBIN = os.path.join(NDK, "toolchains/llvm/prebuilt/darwin-x86_64/bin")
CC = [os.path.join(NDKBIN, "clang"), "--target=" + TRIPLE, "-fPIC"]
CXX = [os.path.join(NDKBIN, "clang++"), "--target=" + TRIPLE, "-fPIC"]
AR = os.path.join(NDKBIN, "llvm-ar")
SDL = os.environ.get("HULK_ANDROID_SDL") or os.path.join(TP, "out/sdl-android-arm64-app")
OUT = os.environ.get("HULK_WAND_OUT") or os.path.join(ROOT, "build/wand1/android")
BGFX_OUT = os.path.join(TP, "out/android-arm64")
HOST = os.path.join(ROOT, "src/platform/wasm")
SDLDIR = os.path.join(ROOT, "src/platform/sdl")
RENDERER_DEFS = ["-DBGFX_CONFIG_RENDERER_VULKAN=1", "-DBGFX_CONFIG_RENDERER_OPENGLES=30",
                 "-DBGFX_CONFIG_RENDERER_OPENGL=0", "-DBGFX_CONFIG_RENDERER_METAL=0"]


def wabt_share():
    import shutil
    w = os.environ.get("HULK_WASM2C") or shutil.which("wasm2c") or "wasm2c"
    pre = os.path.dirname(os.path.dirname(os.path.realpath(w)))
    return w, os.path.join(pre, "share/wabt/wasm2c"), os.path.join(pre, "include")


def _run(job):
    cmd, obj = job
    r = subprocess.run(cmd + ["-o", obj + ".tmp"], capture_output=True, text=True, errors="replace")
    if r.returncode:
        return obj, (" ".join(cmd[-3:]) + "\n" + r.stderr[-3000:])
    os.replace(obj + ".tmp", obj)
    return obj, None


def compile_all(jobs, n):
    """jobs: [(argv without -o, obj)]; only the missing objects are compiled."""
    todo = [j for j in jobs if not os.path.exists(j[1])]
    if todo:
        print("compiling %d of %d objects" % (len(todo), len(jobs)), flush=True)
    with concurrent.futures.ProcessPoolExecutor(n) as ex:
        for obj, err in ex.map(_run, todo):
            if err:
                raise SystemExit("compile failed: %s\n%s" % (obj, err))
            print("  " + os.path.basename(obj), flush=True)


# FFmpeg for Android (tools/wine_ffmpeg.py build --target android-arm64: Bink decoders and demuxer only, LGPL 2.1+,
# shared). run/app/movie.c is built against its headers and loads the libraries at run time from HULK_FFMPEG_DIR
# (GameActivity: <files dir>/ffmpeg when it holds them, else the APK's own lib dir, where `apk --ffmpeg` puts them for
# local tests); without them the movies play black and can be skipped.
FFMPEG = os.environ.get("HULK_ANDROID_FFMPEG") or os.path.join(TP, "out/ffmpeg-android-arm64/install")


def ffmpeg_flags():
    if os.path.exists(os.path.join(FFMPEG, "include/libavformat/avformat.h")):
        return ["-DHULK_HAVE_FFMPEG=1", "-I" + os.path.join(FFMPEG, "include"), '-DHULK_FFMPEG_LIBDIR=""']
    print("build: no FFmpeg headers at %s: the movies play black" % FFMPEG)
    return []


def key(*parts):
    h = hashlib.sha1()
    for p in parts:
        h.update(p if isinstance(p, bytes) else str(p).encode())
    return h.hexdigest()[:16]


# --------------------------------------------------------------------------------------------- bgfx
def cmd_bgfx(a):
    import wine_gfx as wg
    os.makedirs(os.path.join(BGFX_OUT, "obj"), exist_ok=True)
    os.makedirs(os.path.join(BGFX_OUT, "lib"), exist_ok=True)
    cxx = CXX + ["-std=c++20", "-O2", "-fno-exceptions", "-fno-rtti", "-Wno-deprecated-declarations",
                 "-ffunction-sections", "-fdata-sections"] + wg.COMMON_DEFS + RENDERER_DEFS + \
        ["-DHULK_VK_NO_TIMER_QUERY=1", "-DHULK_VK_PRECISE_OCCLUSION=1"]
    jobs, libs = [], {}
    for lib, srcs in wg.lib_units("android").items():
        for src, extra in srcs:
            obj = os.path.join(BGFX_OUT, "obj", "%s-%s.o" % (lib, os.path.splitext(os.path.basename(src))[0]))
            if os.path.exists(obj):
                os.remove(obj)
            jobs.append((cxx + extra + ["-c", src], obj))
            libs.setdefault(lib, []).append(obj)
    t = time.time()
    compile_all(jobs, a.jobs)
    for lib, objs in libs.items():
        out = os.path.join(BGFX_OUT, "lib", lib + ".a")
        if os.path.exists(out):
            os.remove(out)
        subprocess.run([AR, "rcs", out] + objs, check=True)
    json.dump({"target": "android-arm64", "api": API, "commands": [" ".join(j[0]) for j in jobs]},
              open(os.path.join(BGFX_OUT, "build.json"), "w"), indent=1)
    print("bgfx android-arm64: %s in %.0f s" % (os.path.relpath(os.path.join(BGFX_OUT, "lib"), ROOT), time.time() - t))


# --------------------------------------------------------------------------------------------- build
def cmd_build(a):
    import wine_gfx as wg
    w2c, share, inc = wabt_share()
    wasm = os.path.join(os.path.abspath(a.wasm_dir), "hulk.wasm")
    if not os.path.exists(wasm):
        raise SystemExit("no %s (tools/wasm_app.py build)" % wasm)
    for p in (os.path.join(SDL, "lib/libSDL3.a"), os.path.join(BGFX_OUT, "lib/bgfx.a")):
        if not os.path.exists(p):
            raise SystemExit("no %s (tools/native_android_sdl.py --config app / tools/wasm_android.py bgfx)" % p)
    t = time.time()
    d = os.path.join(OUT, "aot")
    os.makedirs(d, exist_ok=True)
    wkey = key(open(wasm, "rb").read(), a.outputs)
    stamp = os.path.join(d, "wasm.key")
    if not (os.path.exists(stamp) and open(stamp).read() == wkey):
        for f in os.listdir(d):
            if f.endswith(".c") or f.endswith(".h"):
                os.remove(os.path.join(d, f))
        r = subprocess.run([w2c, wasm, "-n", "game", "--num-outputs=%d" % a.outputs, "-o", os.path.join(d, "game.c")],
                           capture_output=True, text=True)
        if r.returncode:
            raise SystemExit("wasm2c: " + r.stderr[-2000:])
        open(stamp, "w").write(wkey)
        print("wasm2c %.0f s" % (time.time() - t), flush=True)
    od = os.path.join(OUT, "obj")
    os.makedirs(od, exist_ok=True)
    gflags = [a.opt, "-I", d, "-I", share, "-I", inc, "-w", "-fno-strict-aliasing"]
    impl = open(os.path.join(d, "game-impl.h"), "rb").read()
    jobs = []
    srcs = [os.path.join(d, f) for f in sorted(os.listdir(d)) if f.endswith(".c")] + \
        [os.path.join(share, f) for f in ("wasm-rt-impl.c", "wasm-rt-mem-impl.c", "wasm-rt-exceptions-impl.c")]
    for src in srcs:
        cmd = CC + gflags + ["-c", src]
        jobs.append((cmd, os.path.join(od, "%s.%s.o" % (os.path.basename(src)[:-2], key(open(src, "rb").read(), impl,
                                                                                         " ".join(cmd))))))
    # the runner
    gen = os.path.join(OUT, "app-gen")
    wg.embed_shaders(gen, ["spirv", "essl"])        # the sink picks by renderer (bgfx_sink.cpp rendererProfile)
    run = os.path.join(HOST, "run")
    cxx = CXX + ["-std=c++20", "-O2", "-g", "-fno-exceptions", "-fno-rtti", "-Wall", "-Wno-unused-parameter",
                 "-Wno-unused-private-field", "-Wno-deprecated-declarations", "-I" + os.path.join(SDLDIR, "pddi"),
                 "-I" + gen, "-I" + SDLDIR, "-I" + os.path.join(SDL, "include"), "-I" + d, "-I" + share, "-I" + inc,
                 "-I" + os.path.join(TP, "src/bx/include"), "-I" + os.path.join(TP, "src/bimg/include"),
                 "-I" + os.path.join(TP, "src/bgfx/include")] + wg.COMMON_DEFS + RENDERER_DEFS
    cc = CC + ["-std=c11", "-O2", "-g", "-Wall", "-Wno-unused-parameter", "-I" + SDLDIR]
    host = [(os.path.join(run, "native.c"), CC + gflags + ["-DHULK_APP=1", "-Dmain=SDL_main"])]
    for sub in ("app", "android"):
        for f in sorted(os.listdir(os.path.join(run, sub))):
            if f.endswith(".cpp"):
                host.append((os.path.join(run, sub, f), cxx))
            elif f.endswith(".c"):          # (movie.c: FFmpeg's headers; its libraries loaded at run time, or black)
                host.append((os.path.join(run, sub, f), cc + ["-I" + os.path.join(SDL, "include")] + ffmpeg_flags()))
    for f in ("bgfx_sink.cpp", "bgfx_bridge.cpp"):
        host.append((os.path.join(SDLDIR, "pddi", f), cxx + ["-DHULK_PDDI_HOST=1", "-DHULK_PDDI_EMBED_SHADERS=1",
                                                            "-DHULK_PDDI_BRIDGE_HOST=1", "-DHULK_SINK_OVERLAY=1"]))
    host.append((os.path.join(SDLDIR, "platform_events.cpp"), cxx + ["-DHULK_SDL_LINKED=1"]))
    hdrs = b"".join(open(os.path.join(dp, f), "rb").read()
                    for dp in (os.path.join(run, "app"), os.path.join(SDLDIR, "pddi"), gen, os.path.join(SDLDIR, "input"),
                               os.path.join(SDLDIR, "movies"), os.path.join(SDLDIR, "audio"))
                    if os.path.isdir(dp) for f in sorted(os.listdir(dp))
                    if os.path.isfile(os.path.join(dp, f)))
    for src, flags in host:
        cmd = flags + ["-c", src]
        jobs.append((cmd, os.path.join(od, "%s.%s.o" % (os.path.basename(src).rsplit(".", 1)[0],
                                                        key(open(src, "rb").read(), hdrs, impl, " ".join(cmd))))))
    compile_all(jobs, a.jobs)
    keep = {j[1] for j in jobs}
    for f in os.listdir(od):
        if os.path.join(od, f) not in keep:
            os.remove(os.path.join(od, f))
    out = os.path.join(OUT, "libmain.so")
    lib = os.path.join(BGFX_OUT, "lib")
    cmd = CXX + ["-shared", "-o", out + ".tmp"] + [j[1] for j in jobs] + \
        [os.path.join(lib, n + ".a") for n in ("bgfx", "bimg", "bx")] + [os.path.join(SDL, "lib/libSDL3.a")] + \
        ["-static-libstdc++", "-landroid", "-llog", "-lEGL", "-lGLESv2", "-lOpenSLES", "-laaudio", "-lm", "-ldl",
         "-Wl,-z,max-page-size=16384", "-Wl,--gc-sections", "-Wl,--no-undefined"]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("link: " + r.stderr[-4000:])
    os.replace(out + ".tmp", out)
    json.dump({"wasm": wasm, "wasm_key": wkey, "api": API, "sdl": SDL, "link": " ".join(cmd)},
              open(os.path.join(OUT, "build.json"), "w"), indent=1)
    print("libmain.so: %s %d MB in %.0f s" % (os.path.relpath(out, ROOT), os.path.getsize(out) >> 20, time.time() - t))


def cmd_apk(a):
    so = os.path.join(OUT, "libmain.so")
    out = a.out or os.path.join(OUT, "hulk.apk")
    if not os.path.abspath(out).startswith(os.path.join(ROOT, "build") + os.sep):
        raise SystemExit("the APK stays under build/ (built from the game: never committed or published)")
    import android_apk           # (its steps, with this app's manifest and activities, Android 12+)
    android_apk.OUR = os.path.join(HOST, "android")
    android_apk.MIN_SDK = str(API)
    if a.ffmpeg:                    # (local tests only: FFmpeg's libraries in the APK; see the user's decision)
        os.environ["HULK_ANDROID_FFMPEG"] = FFMPEG
    else:
        os.environ.pop("HULK_ANDROID_FFMPEG", None)
    sys.argv = ["android_apk.py", so, "--out", out]
    raise SystemExit(android_apk.main())


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("bgfx")
    c.add_argument("--jobs", type=int, default=2)
    c = sp.add_parser("build")
    c.add_argument("--wasm-dir", default=os.path.join(ROOT, "build/wasm-app"))
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--outputs", type=int, default=32)
    c.add_argument("--opt", default="-O2")
    c = sp.add_parser("apk")
    c.add_argument("--out")
    c.add_argument("--ffmpeg", action="store_true", help="put FFmpeg's libraries (LGPL) in the APK: local tests only")
    a = ap.parse_args(argv)
    {"bgfx": cmd_bgfx, "build": cmd_build, "apk": cmd_apk}[a.cmd](a)


if __name__ == "__main__":
    main()
