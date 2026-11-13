#!/usr/bin/env python3
"""android_apk.py LIBMAIN [--out APK]: package the arm64 Android image as a debug APK (docs/native-android.md
"Running the image"). Local use only: the APK is a build output under build/, never committed or published.

  build/venv/bin/python tools/android_apk.py build/native-android-arm64/link/libmain.so --out build/and1/hulk.apk
  build/venv/bin/python tools/android_apk.py --setup     # once: the SDK packages it needs (sdkmanager, ~120 MB)

No Gradle: the steps of SDL's android-project template done by hand with the SDK's tools. javac (JDK 17+, JAVA_HOME)
compiles SDL3's Java glue (build/third_party/src/SDL/android-project/.../org/libsdl/app, the same SDL release as the
static libSDL3.a in libmain.so) and src/platform/sdl/android's HulkActivity against android.jar; d8 makes classes.dex;
aapt2 links src/platform/sdl/android/AndroidManifest.xml (no resources); the image goes in as lib/arm64-v8a/libmain.so
(plus HULK_ANDROID_FFMPEG's lib/*.so when set); zipalign -P 16 (16 KB pages) and apksigner with a local debug key
(ANDROID_USER_HOME/debug.keystore, made on first use). The image should be linked against the app configuration of
SDL3 (HULK_ANDROID_SDL=build/third_party/out/sdl-android-arm64-app): the headless one has no video or joystick drivers.

Environment: ANDROID_HOME (default build/android/sdk), ANDROID_USER_HOME (default build/android/user), JAVA_HOME
(build/android/env.sh sets all three).
"""
import argparse
import glob
import os
import shutil
import subprocess
import sys
import zipfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PLATFORM = "android-35"
BUILD_TOOLS = "35.0.0"
SDL_JAVA = os.path.join(ROOT, "build/third_party/src/SDL/android-project/app/src/main/java")
OUR = os.path.join(ROOT, "src/platform/sdl/android")


def sdk():
    return os.environ.get("ANDROID_HOME") or os.path.join(ROOT, "build/android/sdk")


def java_bin(n):
    jh = os.environ.get("JAVA_HOME")
    return os.path.join(jh, "bin", n) if jh else n


def run(cmd, **kw):
    r = subprocess.run(cmd, capture_output=True, text=True, **kw)
    if r.returncode:
        sys.exit("failed: %s\n%s%s" % (" ".join(cmd[:4]), r.stdout[-3000:], r.stderr[-3000:]))
    return r


def setup():
    sm = os.path.join(sdk(), "cmdline-tools/latest/bin/sdkmanager")
    pk = ["platforms;" + PLATFORM, "build-tools;" + BUILD_TOOLS]
    r = subprocess.run([sm, "--sdk_root=" + sdk()] + pk, input="y\n" * 8, text=True)
    return r.returncode


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("libmain", nargs="?")
    ap.add_argument("--out", default=os.path.join(ROOT, "build/android/hulk.apk"))
    ap.add_argument("--setup", action="store_true", help="install the SDK platform and build tools")
    a = ap.parse_args()
    if a.setup:
        return setup()
    if not a.libmain or not os.path.exists(a.libmain):
        sys.exit("no image %s" % a.libmain)
    bt = os.path.join(sdk(), "build-tools", BUILD_TOOLS)
    jar = os.path.join(sdk(), "platforms", PLATFORM, "android.jar")
    if not os.path.exists(jar) or not os.path.isdir(bt):
        sys.exit("missing %s / %s: run tools/android_apk.py --setup" % (jar, bt))
    if not os.path.isdir(SDL_JAVA):
        sys.exit("no SDL sources at %s: run tools/wine_sdl.py fetch first" % SDL_JAVA)
    w = a.out + ".work"
    shutil.rmtree(w, ignore_errors=True)
    os.makedirs(os.path.join(w, "classes"))
    srcs = sorted(glob.glob(os.path.join(SDL_JAVA, "org/libsdl/app/*.java")) +
                  glob.glob(os.path.join(OUR, "java/**/*.java"), recursive=True))
    run([java_bin("javac"), "-nowarn", "-encoding", "UTF-8", "--release", "11", "-classpath", jar,
         "-d", os.path.join(w, "classes")] + srcs)
    classes = glob.glob(os.path.join(w, "classes/**/*.class"), recursive=True)
    run([os.path.join(bt, "d8"), "--release", "--min-api", "29", "--lib", jar, "--output", w] + classes)
    base = os.path.join(w, "base.apk")
    run([os.path.join(bt, "aapt2"), "link", "-I", jar, "--manifest", os.path.join(OUR, "AndroidManifest.xml"),
         "--min-sdk-version", "29", "--target-sdk-version", "35", "-o", base])
    libs = [a.libmain]
    ff = os.environ.get("HULK_ANDROID_FFMPEG")
    if ff:
        libs += sorted(glob.glob(os.path.join(ff, "lib", "*.so")))
    with zipfile.ZipFile(base, "a", zipfile.ZIP_DEFLATED) as z:
        z.write(os.path.join(w, "classes.dex"), "classes.dex")
        for p in libs:
            z.write(p, "lib/arm64-v8a/" + ("libmain.so" if p == a.libmain else os.path.basename(p)))
    aligned = os.path.join(w, "aligned.apk")
    run([os.path.join(bt, "zipalign"), "-f", "-P", "16", "4", base, aligned])
    ks = os.path.join(os.environ.get("ANDROID_USER_HOME") or os.path.join(ROOT, "build/android/user"),
                      "debug.keystore")
    if not os.path.exists(ks):
        os.makedirs(os.path.dirname(ks), exist_ok=True)
        run([java_bin("keytool"), "-genkeypair", "-keystore", ks, "-storepass", "android", "-keypass", "android",
             "-alias", "androiddebugkey", "-keyalg", "RSA", "-keysize", "2048", "-validity", "10000",
             "-dname", "CN=Android Debug,O=Android,C=US"])
    run([os.path.join(bt, "apksigner"), "sign", "--ks", ks, "--ks-pass", "pass:android", "--key-pass", "pass:android",
         "--out", a.out, aligned])
    shutil.rmtree(w, ignore_errors=True)
    print("%s %d KB (libmain.so %d KB)" % (os.path.relpath(a.out, ROOT), os.path.getsize(a.out) >> 10,
                                          os.path.getsize(a.libmain) >> 10))
    return 0


if __name__ == "__main__":
    sys.exit(main())
