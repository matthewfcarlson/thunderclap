#!/usr/bin/env python3
"""The Linux app of the wasm2c build (wlinux1; docs/wasm-port.md "The Linux app"): the macOS app's module and runner,
compiled for x86-64 Linux (SteamOS / Fedora-based handhelds) into one folder bundle with SDL3 (static, its back ends
loaded at run time), bgfx (Vulkan) and the player's game.

  build/venv/bin/python tools/wasm_linux.py prep [--wasm-dir build/wasm-app]   # (macOS) wasm2c + shaders -> <out>
  build/venv/bin/python tools/wasm_linux.py pack                               # (macOS) <out>/linux-src.tar.gz
  python3 tools/wasm_linux.py sdl|bgfx [--jobs N]                              # (Linux) SDL3 / bx, bimg, bgfx
  python3 tools/wasm_linux.py build [--jobs N]                                 # (Linux) -> <out>/hulk-app
  python3 tools/wasm_linux.py bundle --out DIR [--with-game PACK|ISO] [--with-texpack F.hulkpack] [--ffmpeg-from D]

`prep` runs wasm2c on <wasm-dir>/hulk.wasm (the HULK_WASM_GFX=1 module a `tools/wasm_app.py build` or a wasm_build_job
made: the macOS app's, so all the runners run the same module) into <out>/aot, embeds the sink's and the runner's
SPIR-V shaders (bgfx shaderc runs here, not on the Linux host) into <out>/app-gen with the build id (wver1), and copies
wasm2c's runtime and FFmpeg's headers next to them. `pack` puts those and the sources the Linux side compiles
(src/platform/wasm, src/platform/sdl, bx/bimg/bgfx/SDL/zstd from build/third_party/src, these tools) into one tarball,
paths relative to the repository, to unpack on a Linux host (or in a container: Debian trixie with clang, cmake,
ninja and the X11 / Wayland / PipeWire / PulseAudio / ALSA / udev / D-Bus / Vulkan headers; docs/wasm-port.md).
On Linux, `sdl` builds SDL3 static with X11 and Wayland video and its audio/input back ends loaded at run time, `bgfx`
the renderer (Vulkan only), and `build` compiles the module's C at the macOS app's flags (-O2, -fno-strict-aliasing),
the runner (run/native.c with HULK_APP, run/app/, the bgfx sink and bridge host half, platform_events.cpp) and links
<out>/hulk-app (libstdc++ static, RUNPATH $ORIGIN/lib). `bundle` makes the folder: hulk-app, lib/ (FFmpeg's shared
libraries when --ffmpeg-from names a directory holding them; else the system's are used, same majors as the headers),
resources/game.hulkdisc (start.cpp's bundled game on Linux), hulk.sh and a .desktop template.

The app folder (<app dir>) on Linux is $XDG_DATA_HOME/HulkUD, else ~/.local/share/HulkUD (saves in <app dir>/save).
Everything built here is the game built from the player's own XBE: it stays under build/ (or the player's own
machine), never committed or published.

Environment: HULK_LINUX_OUT (default build/wlinux1/linux), CC / CXX (default clang / clang++).
"""
import argparse
import concurrent.futures
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tarfile
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
TP = os.path.join(ROOT, "build/third_party")
OUT = os.path.abspath(os.environ.get("HULK_LINUX_OUT") or os.path.join(ROOT, "build/wlinux1/linux"))
HOST = os.path.join(ROOT, "src/platform/wasm")
SDLDIR = os.path.join(ROOT, "src/platform/sdl")
CC = [os.environ.get("CC") or "clang"]
CXX = [os.environ.get("CXX") or "clang++"]
SDL_OUT = os.path.join(OUT, "sdl")
BGFX_OUT = os.path.join(OUT, "bgfx")
AOT = os.path.join(OUT, "aot")
GEN = os.path.join(OUT, "app-gen")
WABT = os.path.join(OUT, "wabt")            # wasm2c's runtime (share) and headers (include), copied by prep
FFINC = os.path.join(OUT, "ffmpeg/include")
# (-msse4.2: bx's SIMD as on the win32 target; the runner's host code only, never the module's C)
RENDERER_DEFS = ["-msse4.2", "-DBGFX_CONFIG_RENDERER_VULKAN=1", "-DBGFX_CONFIG_RENDERER_OPENGL=0",
                 "-DBGFX_CONFIG_RENDERER_OPENGLES=0", "-DBGFX_CONFIG_RENDERER_METAL=0"]
# FFmpeg's headers: any FFmpeg 8 install's (avconfig.h is the same for little-endian targets); the libraries are
# loaded at run time by their sonames (run/app/movie.c), the bundle's lib/ first, then the system's
FFMPEG_HDRS = [os.environ.get("HULK_FFMPEG_INCLUDE") or "",
               os.path.join(TP, "out/ffmpeg-android-arm64/install/include"), "/opt/homebrew/opt/ffmpeg/include"]


def key(*parts):
    h = hashlib.sha1()
    for p in parts:
        h.update(p if isinstance(p, bytes) else str(p).encode())
    return h.hexdigest()[:16]


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


# --------------------------------------------------------------------------------------------- prep / pack (macOS)
def cmd_prep(a):
    import wine_gfx as wg
    import rm_shaders
    import wasm_app
    w2c = os.environ.get("HULK_WASM2C") or shutil.which("wasm2c") or "wasm2c"
    pre = os.path.dirname(os.path.dirname(os.path.realpath(w2c)))
    wasm = os.path.join(os.path.abspath(a.wasm_dir), "hulk.wasm")
    if not os.path.exists(wasm):
        raise SystemExit("no %s (tools/wasm_app.py build, or a wasm_build_job with --keep-wasm)" % wasm)
    t = time.time()
    os.makedirs(AOT, exist_ok=True)
    wkey = key(open(wasm, "rb").read(), a.outputs)
    stamp = os.path.join(AOT, "wasm.key")
    if not (os.path.exists(stamp) and open(stamp).read() == wkey):
        for f in os.listdir(AOT):
            if f.endswith(".c") or f.endswith(".h"):
                os.remove(os.path.join(AOT, f))
        r = subprocess.run([w2c, wasm, "-n", "game", "--num-outputs=%d" % a.outputs, "-o", os.path.join(AOT, "game.c")],
                           capture_output=True, text=True)
        if r.returncode:
            raise SystemExit("wasm2c: " + r.stderr[-2000:])
        open(stamp, "w").write(wkey)
        print("wasm2c %.0f s" % (time.time() - t), flush=True)
    for sub, src in (("share", os.path.join(pre, "share/wabt/wasm2c")), ("include", os.path.join(pre, "include"))):
        d = os.path.join(WABT, sub)
        shutil.rmtree(d, ignore_errors=True)
        os.makedirs(d)
        for f in os.listdir(src):
            if f.startswith("wasm-rt"):
                shutil.copy2(os.path.join(src, f), d)
    # the build's id (wver1): the module's (the hulk-app beside it, or its build-id.txt), else this checkout's
    bid = os.environ.get("HULK_BUILD_ID")
    wd = os.path.dirname(wasm)
    if not bid and os.path.exists(os.path.join(wd, "hulk-app")):
        bid = wasm_app.exe_build_id(os.path.join(wd, "hulk-app"))
    if not bid and os.path.exists(os.path.join(wd, wasm_app.BUILD_ID_TXT)):
        bid = open(os.path.join(wd, wasm_app.BUILD_ID_TXT)).read().strip()
    bid = bid or wasm_app.build_id()
    if bid != wasm_app.build_id():
        print("prep: the module's build id %s; this checkout (the runner's sources) is %s" % (bid, wasm_app.build_id()))
    wasm_app.write_build_id(GEN, OUT, bid)
    wg.embed_shaders(GEN, ["spirv"])            # the sink picks by renderer (bgfx_sink.cpp rendererProfile)
    rm_shaders.build(GEN, ("spirv",))           # the runner's own (run/app/shaders)
    for p in FFMPEG_HDRS:
        if p and os.path.exists(os.path.join(p, "libavformat/avformat.h")):
            shutil.rmtree(FFINC, ignore_errors=True)
            shutil.copytree(p, FFINC)
            break
    else:
        print("prep: no FFmpeg headers: the Linux app's movies play black")
    # wine_gfx's bgfx units and defines, for the Linux side (wine_gfx needs the clang_probe toolchain resolver)
    units = {lib: [[os.path.relpath(src, ROOT), ["-I" + os.path.relpath(f[2:], ROOT) if f.startswith("-I") else f
                                                 for f in extra]] for src, extra in srcs]
             for lib, srcs in wg.lib_units("linux").items()}
    json.dump({"wasm": wasm, "wasm_key": wkey, "build_id": bid, "common_defs": wg.COMMON_DEFS, "bgfx_units": units},
              open(os.path.join(OUT, "prep.json"), "w"), indent=1)
    print("prep: %s in %.0f s" % (os.path.relpath(OUT, ROOT), time.time() - t))


PACK_SRC = ["src/platform/wasm", "src/platform/sdl", "tools/wasm_linux.py", "tools/wine_gfx.py", "tools/disc_pack.py",
            "tools/wasm_app.py", "tools/native_replay.py", "tools/ckpt_ref.py", "build/third_party/src/bx",
            "build/third_party/src/bimg", "build/third_party/src/bgfx/include", "build/third_party/src/bgfx/src",
            "build/third_party/src/bgfx/3rdparty", "build/third_party/src/SDL", "build/third_party/src/zstd",
            "build/third_party/out/LICENSES-SDL.txt", "build/third_party/out/LICENSES-FFMPEG.txt",
            "build/third_party/out/COPYING.LGPLv2.1-FFMPEG"]


def cmd_pack(a):
    if not os.path.exists(os.path.join(OUT, "prep.json")):
        raise SystemExit("no %s/prep.json (wasm_linux.py prep first)" % OUT)
    out = a.out or os.path.join(OUT, "linux-src.tar.gz")
    rel_out = os.path.relpath(OUT, ROOT)
    skip = {".git", "examples", "__pycache__"}

    def filt(ti):
        return None if os.path.basename(ti.name) in skip else ti
    with tarfile.open(out + ".tmp", "w:gz", compresslevel=6) as tf:
        for p in PACK_SRC:
            full = os.path.join(ROOT, p)
            if os.path.exists(full):
                tf.add(full, arcname=p, filter=filt)
        for sub in ("aot", "app-gen", "wabt", "ffmpeg", "prep.json", "build-id.txt"):
            full = os.path.join(OUT, sub)
            if os.path.exists(full):
                tf.add(full, arcname=os.path.join(rel_out, sub), filter=filt)
    os.replace(out + ".tmp", out)
    print("pack: %s %d MB (unpack at the repository's root on the Linux host; HULK_LINUX_OUT=%s)" % (
        os.path.relpath(out, ROOT), os.path.getsize(out) >> 20, rel_out))


# --------------------------------------------------------------------------------------------- sdl / bgfx (Linux)
def cmd_sdl(a):
    """SDL3 static for the app: X11 and Wayland video (libdecor), PipeWire / PulseAudio / ALSA audio, udev, HIDAPI and
    D-Bus (the portal file dialog of the first-launch chooser), every back end's library loaded at run time (SDL's
    *_SHARED defaults), so the one binary runs on desktops without some of them."""
    bd = os.path.join(SDL_OUT, "cmake")
    os.makedirs(bd, exist_ok=True)
    cfg = ["cmake", "-S", os.path.join(TP, "src/SDL"), "-B", bd, "-G", "Ninja", "-DCMAKE_BUILD_TYPE=Release",
           "-DCMAKE_C_COMPILER=" + CC[0], "-DCMAKE_POSITION_INDEPENDENT_CODE=ON", "-DCMAKE_INSTALL_PREFIX=" + SDL_OUT,
           "-DSDL_SHARED=OFF", "-DSDL_STATIC=ON", "-DSDL_TEST_LIBRARY=OFF", "-DSDL_TESTS=OFF", "-DSDL_EXAMPLES=OFF",
           "-DSDL_VIDEO=ON", "-DSDL_X11=ON", "-DSDL_WAYLAND=ON", "-DSDL_WAYLAND_LIBDECOR=ON", "-DSDL_KMSDRM=OFF",
           "-DSDL_OPENGL=ON", "-DSDL_OPENGLES=ON", "-DSDL_VULKAN=ON", "-DSDL_GPU=OFF", "-DSDL_RENDER=OFF",
           "-DSDL_CAMERA=OFF", "-DSDL_DIALOG=ON", "-DSDL_TRAY=OFF", "-DSDL_POWER=ON", "-DSDL_SENSOR=ON",
           "-DSDL_AUDIO=ON", "-DSDL_PIPEWIRE=ON", "-DSDL_PULSEAUDIO=ON", "-DSDL_ALSA=ON", "-DSDL_JACK=OFF",
           "-DSDL_SNDIO=OFF", "-DSDL_JOYSTICK=ON", "-DSDL_HAPTIC=ON", "-DSDL_HIDAPI=ON", "-DSDL_LIBUDEV=ON",
           "-DSDL_DBUS=ON", "-DSDL_IBUS=OFF", "-DSDL_LIBURING=OFF"]
    with open(os.path.join(OUT, "sdl-build.log"), "w") as f:
        for cmd in (cfg, ["cmake", "--build", bd, "-j", str(a.jobs)], ["cmake", "--install", bd]):
            if subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT).returncode:
                raise SystemExit("SDL3 failed at %s (log %s/sdl-build.log)" % (cmd[1], OUT))
    shutil.rmtree(bd, ignore_errors=True)
    print("sdl: %s" % os.path.join(SDL_OUT, "lib/libSDL3.a"))


def prep_info():
    """prep.json: wine_gfx's COMMON_DEFS and bgfx units (paths relative to the repository)"""
    p = json.load(open(os.path.join(OUT, "prep.json")))
    units = {lib: [(os.path.join(ROOT, src), ["-I" + os.path.join(ROOT, f[2:]) if f.startswith("-I") else f
                                              for f in extra]) for src, extra in srcs]
             for lib, srcs in p["bgfx_units"].items()}
    return p["common_defs"], units


def cmd_bgfx(a):
    common, units = prep_info()
    os.makedirs(os.path.join(BGFX_OUT, "obj"), exist_ok=True)
    os.makedirs(os.path.join(BGFX_OUT, "lib"), exist_ok=True)
    cxx = CXX + ["-std=c++20", "-O2", "-fPIC", "-fno-exceptions", "-fno-rtti", "-Wno-deprecated-declarations",
                 "-ffunction-sections", "-fdata-sections"] + common + RENDERER_DEFS + \
        ["-DHULK_VK_NO_TIMER_QUERY=1", "-DHULK_VK_PRECISE_OCCLUSION=1"]
    jobs, libs = [], {}
    for lib, srcs in units.items():
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
        subprocess.run(["ar", "rcs", out] + objs, check=True)
    shutil.rmtree(os.path.join(BGFX_OUT, "obj"), ignore_errors=True)
    print("bgfx linux-x64: %s in %.0f s" % (os.path.join(BGFX_OUT, "lib"), time.time() - t))


# --------------------------------------------------------------------------------------------- build (Linux)
def cmd_build(a):
    common, _ = prep_info()
    import disc_pack            # the disc sources (run/disc.c: folders, .iso images, disc packs; zstd's decompressor)
    for p in (os.path.join(AOT, "game-impl.h"), os.path.join(GEN, "pddi_shaders.h")):
        if not os.path.exists(p):
            raise SystemExit("no %s (wasm_linux.py prep, then pack)" % p)
    for p in (os.path.join(SDL_OUT, "lib/libSDL3.a"), os.path.join(BGFX_OUT, "lib/bgfx.a")):
        if not os.path.exists(p):
            raise SystemExit("no %s (wasm_linux.py sdl / bgfx)" % p)
    t = time.time()
    share, inc = os.path.join(WABT, "share"), os.path.join(WABT, "include")
    od = os.path.join(OUT, "obj")
    os.makedirs(od, exist_ok=True)
    gflags = [a.opt, "-I", AOT, "-I", share, "-I", inc, "-w", "-fno-strict-aliasing"]
    impl = open(os.path.join(AOT, "game-impl.h"), "rb").read()
    jobs = []
    srcs = [os.path.join(AOT, f) for f in sorted(os.listdir(AOT)) if f.endswith(".c")] + \
        [os.path.join(share, f) for f in ("wasm-rt-impl.c", "wasm-rt-mem-impl.c", "wasm-rt-exceptions-impl.c")]
    for src in srcs:
        cmd = CC + gflags + ["-c", src]
        jobs.append((cmd, os.path.join(od, "%s.%s.o" % (os.path.basename(src)[:-2], key(open(src, "rb").read(), impl,
                                                                                         " ".join(cmd))))))
    ff = ["-DHULK_HAVE_FFMPEG=1", "-I" + FFINC, '-DHULK_FFMPEG_LIBDIR=""'] \
        if os.path.exists(os.path.join(FFINC, "libavformat/avformat.h")) else []
    if not ff:
        print("build: no FFmpeg headers at %s: the movies play black" % FFINC)
    run = os.path.join(HOST, "run")
    cxx = CXX + ["-std=c++20", "-O2", "-g", "-fno-exceptions", "-fno-rtti", "-Wall", "-Wno-unused-parameter",
                 "-Wno-unused-private-field", "-Wno-deprecated-declarations", "-I" + os.path.join(SDLDIR, "pddi"),
                 "-I" + GEN, "-I" + SDLDIR, "-I" + os.path.join(SDL_OUT, "include"), "-I" + AOT, "-I" + share,
                 "-I" + inc, "-I" + os.path.join(TP, "src/bx/include"), "-I" + os.path.join(TP, "src/bimg/include"),
                 "-I" + os.path.join(TP, "src/bgfx/include")] + common + RENDERER_DEFS
    cc = CC + ["-std=c11", "-O2", "-g", "-Wall", "-Wno-unused-parameter", "-D_GNU_SOURCE", "-I" + SDLDIR]
    host = [(os.path.join(run, "native.c"), CC + gflags + ["-DHULK_APP=1", "-D_GNU_SOURCE"]),
            (os.path.join(run, "disc.c"), cc + disc_pack.zstd_flags()),
            (os.path.join(run, "zstd_dec.c"), cc + disc_pack.zstd_flags())]
    for f in sorted(os.listdir(os.path.join(run, "app"))):
        if f.endswith(".cpp"):
            host.append((os.path.join(run, "app", f), cxx))
        elif f.endswith(".c"):          # (movie.c: FFmpeg's headers; its libraries loaded at run time, or black)
            host.append((os.path.join(run, "app", f), cc + ["-I" + os.path.join(SDL_OUT, "include")] + ff))
    for f in ("bgfx_sink.cpp", "bgfx_bridge.cpp"):
        host.append((os.path.join(SDLDIR, "pddi", f), cxx + ["-DHULK_PDDI_HOST=1", "-DHULK_PDDI_EMBED_SHADERS=1",
                                                            "-DHULK_PDDI_BRIDGE_HOST=1", "-DHULK_SINK_OVERLAY=1"]))
    host.append((os.path.join(SDLDIR, "platform_events.cpp"), cxx + ["-DHULK_SDL_LINKED=1"]))
    hdrs = b"".join(open(os.path.join(dp, f), "rb").read()
                    for dp in (run, os.path.join(run, "app"), os.path.join(SDLDIR, "pddi"), GEN, os.path.join(SDLDIR, "input"),
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
    out = os.path.join(OUT, "hulk-app")
    lib = os.path.join(BGFX_OUT, "lib")
    cmd = CXX + ["-o", out + ".tmp"] + [j[1] for j in jobs] + \
        [os.path.join(lib, n + ".a") for n in ("bgfx", "bimg", "bx")] + [os.path.join(SDL_OUT, "lib/libSDL3.a")] + \
        ["-static-libstdc++", "-static-libgcc", "-lm", "-ldl", "-lpthread", "-lrt", "-Wl,--gc-sections",
         "-Wl,-rpath,$ORIGIN/lib", "-Wl,--enable-new-dtags"]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit("link: " + r.stderr[-4000:])
    os.replace(out + ".tmp", out)
    json.dump({"link": " ".join(cmd)}, open(os.path.join(OUT, "build.json"), "w"), indent=1)
    print("hulk-app: %s %d MB in %.0f s" % (out, os.path.getsize(out) >> 20, time.time() - t))


# --------------------------------------------------------------------------------------------- bundle
LAUNCHER = """#!/bin/sh
# Hulk UD (the wasm2c app; tools/wasm_linux.py bundle). The game is resources/game.hulkdisc when present, else the
# one remembered in <app dir>/game.txt, else <app dir>/disc, else a chooser. <app dir>: $XDG_DATA_HOME/HulkUD or
# ~/.local/share/HulkUD (saves in <app dir>/save). Extra arguments go to hulk-app (--choose-game: ask again).
here=$(dirname "$(readlink -f "$0")")
cd "$here" || exit 1
exec "$here/hulk-app" "$@"
"""
DESKTOP = """[Desktop Entry]
Type=Application
Name=Hulk UD
Comment=The Incredible Hulk: Ultimate Destruction (the player's own game)
Exec=@DIR@/hulk.sh
Path=@DIR@
Icon=applications-games
Terminal=false
Categories=Game;ActionGame;
"""
FFMPEG_LIBS = ("avutil", "avcodec", "avformat", "swresample", "dav1d", "opus")


def cmd_bundle(a):
    exe = a.exe or os.path.join(OUT, "hulk-app")
    if not os.path.exists(exe):
        raise SystemExit("no %s (wasm_linux.py build)" % exe)
    dst = os.path.abspath(a.out)
    shutil.rmtree(dst, ignore_errors=True)
    os.makedirs(os.path.join(dst, "lib"))
    shutil.copy2(exe, os.path.join(dst, "hulk-app"))
    with open(os.path.join(dst, "hulk.sh"), "w") as f:
        f.write(LAUNCHER)
    os.chmod(os.path.join(dst, "hulk.sh"), 0o755)
    with open(os.path.join(dst, "hulkud.desktop"), "w") as f:   # (copy to ~/.local/share/applications/)
        f.write(DESKTOP.replace("@DIR@", dst))
    for lic in ("LICENSES-SDL.txt", "LICENSES-FFMPEG.txt", "COPYING.LGPLv2.1-FFMPEG"):
        p = os.path.join(TP, "out", lic)
        if os.path.exists(p):
            shutil.copy2(p, os.path.join(dst, "lib", lic))
    if a.ffmpeg_from:               # (FFmpeg's shared libraries, LGPL: e.g. a distribution's, copied with their links)
        for f in sorted(os.listdir(a.ffmpeg_from)):
            if any(f.startswith("lib%s.so." % n) for n in FFMPEG_LIBS):
                shutil.copy2(os.path.join(a.ffmpeg_from, f), os.path.join(dst, "lib", f), follow_symlinks=True)
    extra = []
    for src, kinds in ((a.with_game, (".hulkdisc", ".iso")), (a.with_texpack, (".hulkpack",))):
        if not src:
            continue
        ext = os.path.splitext(src)[1].lower()
        if ext not in kinds:
            raise SystemExit("bundle: %s is not a %s file" % (src, " / ".join(kinds)))
        os.makedirs(os.path.join(dst, "resources"), exist_ok=True)
        to = os.path.join(dst, "resources", "game" + ext if kinds[0] == ".hulkdisc" else os.path.basename(src))
        try:
            os.link(src, to)        # (a hard link where it can be: no second copy of the game)
        except OSError:
            shutil.copyfile(src, to)
        extra.append("%s %.2f GB" % (os.path.basename(to), os.path.getsize(to) / 1e9))
    print("bundle: %s (%s)" % (dst, "with " + ", ".join(extra) if extra else "the game: chosen at first launch"))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("prep")
    c.add_argument("--wasm-dir", default=os.path.join(ROOT, "build/wasm-app"))
    c.add_argument("--outputs", type=int, default=32)
    c = sp.add_parser("pack")
    c.add_argument("--out")
    for n in ("sdl", "bgfx"):
        c = sp.add_parser(n)
        c.add_argument("--jobs", type=int, default=4)
    c = sp.add_parser("build")
    c.add_argument("--jobs", type=int, default=4)
    c.add_argument("--opt", default="-O2")
    c = sp.add_parser("bundle")
    c.add_argument("--exe")
    c.add_argument("--out", required=True)
    c.add_argument("--with-game", help="the player's disc pack (.hulkdisc) or .iso: resources/game.*")
    c.add_argument("--with-texpack", help="a one-file texture pack (.hulkpack): resources/")
    c.add_argument("--ffmpeg-from", help="a directory with FFmpeg's shared libraries to put in lib/")
    a = ap.parse_args(argv)
    {"prep": cmd_prep, "pack": cmd_pack, "sdl": cmd_sdl, "bgfx": cmd_bgfx, "build": cmd_build,
     "bundle": cmd_bundle}[a.cmd](a)


if __name__ == "__main__":
    main()
