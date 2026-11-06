#!/usr/bin/env python3
"""native_linux_sdl.py [--jobs N]: SDL3 for the x86-64 Linux native image, cross-built on the build host.

A static, headless libSDL3.a (no video, no GPU or render; audio with SDL's dummy and disk drivers; joystick and haptic
through evdev) compiled by the tree's LLVM against the glibc sysroot tools/linux_sysroot.py makes, from the same SDL
sources tools/wine_sdl.py fetched (build/third_party/src/SDL). Output: build/third_party/out/sdl-linux-x64/{lib,include}.
tools/native_elf.py links it when present (elf_sdl): the shim then has the SDL3 backends and the replay layer, as on
macOS. On the Linux box itself a build against the system's X11/Wayland/PipeWire packages replaces it for play;
headless replays need only this one.
"""
import argparse
import json
import os
import shutil
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import clang_probe as cp  # noqa: E402

ROOT = cp.ROOT
SDL_SRC = os.path.join(ROOT, "build/third_party/src/SDL")
OUT = os.path.join(ROOT, "build/third_party/out/sdl-linux-x64")
OFF = ["VIDEO", "GPU", "RENDER", "CAMERA", "DIALOG", "TRAY", "POWER", "HIDAPI", "ALSA", "PULSEAUDIO", "PIPEWIRE",
       "JACK", "SNDIO", "OSS", "LIBUDEV", "DBUS", "IBUS", "X11", "WAYLAND", "KMSDRM", "OPENGL", "OPENGLES", "VULKAN",
       "LIBURING", "SHARED", "TEST_LIBRARY", "TESTS", "EXAMPLES"]
ON = ["STATIC", "SENSOR", "AUDIO", "JOYSTICK", "HAPTIC", "UNIX_CONSOLE_BUILD"]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    sysroot = os.environ.get("HULK_LINUX_SYSROOT") or os.path.join(ROOT, "build/elf1/sysroot-x64")
    if not os.path.isdir(sysroot):
        sys.exit("no sysroot at %s: run tools/linux_sysroot.py first" % sysroot)
    if not os.path.isdir(SDL_SRC):
        sys.exit("no SDL sources at %s: run tools/wine_sdl.py fetch first" % SDL_SRC)
    llvm = cp.LLVM
    bd = os.path.join(OUT, "cmake")
    os.makedirs(bd, exist_ok=True)
    tcf = os.path.join(OUT, "toolchain.cmake")
    with open(tcf, "w") as f:
        f.write("\n".join([
            "set(CMAKE_SYSTEM_NAME Linux)", "set(CMAKE_SYSTEM_PROCESSOR x86_64)", "set(CMAKE_SYSROOT %s)" % sysroot,
            "set(CMAKE_C_COMPILER %s/clang)" % llvm, "set(CMAKE_C_COMPILER_TARGET x86_64-linux-gnu)",
            "set(CMAKE_CXX_COMPILER %s/clang++)" % llvm, "set(CMAKE_CXX_COMPILER_TARGET x86_64-linux-gnu)",
            "set(CMAKE_AR %s/llvm-ar)" % llvm, "set(CMAKE_RANLIB %s/llvm-ranlib)" % llvm,
            'set(CMAKE_EXE_LINKER_FLAGS_INIT "-fuse-ld=lld")', 'set(CMAKE_SHARED_LINKER_FLAGS_INIT "-fuse-ld=lld")',
            'set(CMAKE_C_FLAGS_INIT "-fPIC")', "set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)",
            "set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)", "set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)",
            "set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)", ""]))
    cfg = (["cmake", "-S", SDL_SRC, "-B", bd, "-G", "Ninja", "-DCMAKE_TOOLCHAIN_FILE=" + tcf,
            "-DCMAKE_BUILD_TYPE=Release", "-DCMAKE_INSTALL_PREFIX=" + OUT]
           + ["-DSDL_%s=OFF" % x for x in OFF] + ["-DSDL_%s=ON" % x for x in ON])
    logf = os.path.join(OUT, "build.log")
    t0 = time.time()
    with open(logf, "w") as f:
        for cmd in (cfg, ["cmake", "--build", bd, "-j", str(a.jobs)], ["cmake", "--install", bd]):
            f.write("$ " + " ".join(cmd) + "\n")
            f.flush()
            if subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT).returncode:
                sys.exit("SDL3 linux-x64 build failed at %s (log %s)" % (cmd[1], os.path.relpath(logf, ROOT)))
    shutil.rmtree(bd, ignore_errors=True)
    lib = os.path.join(OUT, "lib/libSDL3.a")
    json.dump({"target": "linux-x64", "sysroot": os.path.relpath(sysroot, ROOT), "configure": " ".join(cfg)},
              open(os.path.join(OUT, "build.json"), "w"), indent=1)
    print("linux-x64: %s %d KB in %d s" % (os.path.relpath(lib, ROOT), os.path.getsize(lib) >> 10, time.time() - t0))


if __name__ == "__main__":
    main()
