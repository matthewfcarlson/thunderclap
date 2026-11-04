#!/usr/bin/env python3
"""The XDK shim and the native host layer on the 64-bit targets (docs/native-android.md section 14, A2 item 4).

  build/venv/bin/python tests/native_host/shim_test.py --target mac            # build, link and run
  build/venv/bin/python tests/native_host/shim_test.py --target linux-x64      # build and link (no Linux machine)
  build/venv/bin/python tests/native_host/shim_test.py --target android-arm64  # build and link (NDK)

Compiles src/platform/sdl/xdk/ (every stand-in file but startup.cpp, the Windows entry point entry_posix.cpp replaces,
and replay_hooks.cpp, the Wine build's replay bridge replay_native.cpp replaces) as host code for the target, in its
stand-in configuration (no HULK_NATIVE_SDL: the SDL3 backends are the next step), with the native host layer
(host_crt_posix, win32_posix, crt_posix, softx87, shim_posix, replay_native's driver compiled too). Checks:
  * every file compiles for the target with -Wall (-Werror for the new host files);
  * the shim links with the host layer: no undefined name but the system libraries' (the link fails otherwise);
  * on macOS, tests/native_host/shim_test.cpp runs: the Xbox counter frequency, D:\\ files through HULK_DATA_DIR
    (open, size, read, seek), a T:\\ save through HULK_SAVE_DIR, the import list of the start-up trace.
"""
import argparse
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools"))

XDK = sorted(f for f in os.listdir(os.path.join(ROOT, "src/platform/sdl/xdk"))
             if f.endswith(".cpp") and f not in ("startup.cpp", "replay_hooks.cpp"))
HOST = ["src/platform/sdl/host/host_crt_posix.cpp", "src/platform/sdl/host/win32_posix.cpp",
        "src/platform/sdl/host/crt_posix.cpp", "src/platform/sdl/crt/softx87.cpp", "src/platform/sdl/host/shim_posix.cpp"]
NEW = {"src/platform/sdl/host/host_crt_posix.cpp", "src/platform/sdl/host/shim_posix.cpp",
       "src/platform/sdl/host/replay_native.cpp"}
SDL_INC = os.path.join(ROOT, "build/third_party/out/sdl-host/include")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--target", default="mac", choices=["mac", "linux-x64", "android-arm64"])
    ap.add_argument("--out")
    a = ap.parse_args()
    out = a.out or os.path.join(ROOT, "build/a2s1/shim-" + a.target)
    os.makedirs(out, exist_ok=True)
    if a.target == "mac":
        cxx = ["xcrun", "clang++", "-arch", "arm64", "-mmacosx-version-min=13.0", "-std=c++17", "-O1", "-g"]
        link_flags, run = [], True
    else:
        import native_elf as ne
        tc = ne.Toolchain(a.target)
        cxx = tc.cxx + tc.host_flags()
        link_flags = ["-pie", "-Wl,--build-id=none"] + tc.link_flags + (["-lpthread"] if a.target == "linux-x64" else [])
        run = False
    inc = ["-I" + os.path.join(ROOT, "src/platform/sdl")]
    objs, bad = [], 0
    for src in ["src/platform/sdl/xdk/" + f for f in XDK] + HOST + ["src/platform/sdl/host/replay_native.cpp",
                                                                      "tests/native_host/shim_test.cpp"]:
        o = os.path.join(out, os.path.basename(src) + ".o")
        w = ["-Wall", "-Werror"] if src in NEW else ["-Wall", "-Wno-unused-function", "-Wno-unused-variable"]
        extra = ["-I" + SDL_INC] if src.endswith("replay_native.cpp") else []
        r = subprocess.run(cxx + w + inc + extra + ["-c", os.path.join(ROOT, src), "-o", o], capture_output=True, text=True)
        if r.returncode:
            print("COMPILE FAIL %s\n%s" % (src, r.stderr[-2000:]))
            bad += 1
        elif not src.endswith("replay_native.cpp"):   # (the driver needs the replay reader and SDL3: compiled only)
            objs.append(o)
    if bad:
        return 1
    image = os.path.join(out, "shim_test")
    r = subprocess.run(cxx + objs + ["-o", image] + link_flags, capture_output=True, text=True)
    if r.returncode:
        print("LINK FAIL\n" + r.stderr[-3000:])
        return 1
    print("%s: %d shim files + %d host files compile, the shim links" % (a.target, len(XDK), len(HOST)))
    if not run:
        print("shim_test %s: ok (built and linked; not run on this host)" % a.target)
        return 0
    r = subprocess.run([image, os.path.join(out, "scratch")], capture_output=True, text=True)
    print(r.stdout.strip() + r.stderr[-1500:])
    print("shim_test %s: %s" % (a.target, "ok" if r.returncode == 0 else "FAILED"))
    return r.returncode


if __name__ == "__main__":
    sys.exit(main())
