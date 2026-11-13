#!/usr/bin/env python3
"""native_android_sdl.py [--config headless|app] [--jobs N]: SDL3 for the arm64 Android native image (libmain.so).

A static libSDL3.a for aarch64-linux-android29, compiled by the NDK (HULK_NDK, default build/android/ndk) with its CMake
toolchain file, from the SDL sources tools/wine_sdl.py fetched (build/third_party/src/SDL). tools/native_elf.py links
it into libmain.so when present (elf_sdl): the shim then has the SDL3 backends and the replay layer, as on macOS and
x86-64 Linux. Output: build/third_party/out/sdl-android-arm64[-app]/{lib,include}.

  headless  (default) for the image run outside an app (tests/android/libmain_run.sh: adb shell, a plain process that
            dlopens libmain.so and calls SDL_main): nothing the game initialises needs the Java VM. Off: joystick,
            haptic, sensor, camera, power, HIDAPI, GPU and render (SDL's Android drivers for them call into
            SDLActivity through JNI, and a plain process has no VM); the Android video driver stays in (SDL's Android
            core calls it; nothing initialises it headless); audio with SDL's dummy and disk drivers (SDL_AUDIO_DRIVER=dummy) next to
            AAudio / OpenSL ES. The filesystem calls the game makes take absolute paths (HULK_DATA_DIR, HULK_SAVE_DIR),
            which SDL serves through stdio without JNI.
  app       the APK's configuration (tools/android_apk.py): SDL's Android video, joystick, haptic and sensor drivers
            and HIDAPI on top, with SDL's Java activity (SDLActivity) providing the VM; libmain.so carries SDL3 statically, so
            the activity loads only "main" (src/platform/sdl/android/).
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
API = 29
SDL_SRC = os.path.join(ROOT, "build/third_party/src/SDL")
OUT = {"headless": os.path.join(ROOT, "build/third_party/out/sdl-android-arm64"),
       "app": os.path.join(ROOT, "build/third_party/out/sdl-android-arm64-app")}
COMMON_OFF = ["CAMERA", "DIALOG", "TRAY", "SHARED", "TEST_LIBRARY", "TESTS", "EXAMPLES", "ANDROID_JAR",
              "VULKAN", "OPENGL"]
CONFIGS = {
    # (SDL's Android core, SDL_android.c, calls the Android video driver's functions: video stays on, unused)
    "headless": dict(off=COMMON_OFF + ["HIDAPI", "GPU", "RENDER", "JOYSTICK", "HAPTIC", "SENSOR", "POWER", "OPENGLES"],
                     on=["STATIC", "AUDIO", "VIDEO"]),
    "app": dict(off=COMMON_OFF, on=["STATIC", "AUDIO", "VIDEO", "JOYSTICK", "HAPTIC", "SENSOR", "POWER", "OPENGLES"]),
}


def ndk_root():
    return os.environ.get("HULK_NDK") or os.path.join(ROOT, "build/android/ndk")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--config", choices=sorted(CONFIGS), default="headless")
    ap.add_argument("--jobs", type=int, default=2)
    a = ap.parse_args()
    ndk = ndk_root()
    tcf = os.path.join(ndk, "build/cmake/android.toolchain.cmake")
    if not os.path.exists(tcf):
        sys.exit("no NDK at %s (HULK_NDK): docs/native-android.md section 12 installs one" % ndk)
    if not os.path.isdir(SDL_SRC):
        sys.exit("no SDL sources at %s: run tools/wine_sdl.py fetch first" % SDL_SRC)
    out = OUT[a.config]
    bd = os.path.join(out, "cmake")
    shutil.rmtree(bd, ignore_errors=True)
    os.makedirs(bd, exist_ok=True)
    c = CONFIGS[a.config]
    cfg = (["cmake", "-S", SDL_SRC, "-B", bd, "-G", "Ninja", "-DCMAKE_TOOLCHAIN_FILE=" + tcf,
            "-DANDROID_ABI=arm64-v8a", "-DANDROID_PLATFORM=android-%d" % API, "-DCMAKE_BUILD_TYPE=Release",
            "-DCMAKE_POSITION_INDEPENDENT_CODE=ON", "-DCMAKE_INSTALL_PREFIX=" + out]
           + ["-DSDL_%s=OFF" % x for x in c["off"]] + ["-DSDL_%s=ON" % x for x in c["on"]])
    logf = os.path.join(out, "build.log")
    t0 = time.time()
    with open(logf, "w") as f:
        for cmd in (cfg, ["cmake", "--build", bd, "-j", str(a.jobs)], ["cmake", "--install", bd]):
            f.write("$ " + " ".join(cmd) + "\n")
            f.flush()
            if subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT).returncode:
                sys.exit("SDL3 android-arm64 (%s) build failed at %s (log %s)" % (a.config, cmd[1],
                                                                                 os.path.relpath(logf, ROOT)))
    shutil.rmtree(bd, ignore_errors=True)
    lib = os.path.join(out, "lib/libSDL3.a")
    json.dump({"target": "android-arm64", "config": a.config, "api": API, "ndk": os.path.relpath(ndk, ROOT),
               "configure": " ".join(cfg)}, open(os.path.join(out, "build.json"), "w"), indent=1)
    print("android-arm64 (%s): %s %d KB in %d s" % (a.config, os.path.relpath(lib, ROOT), os.path.getsize(lib) >> 10,
                                                   time.time() - t0))


if __name__ == "__main__":
    main()
