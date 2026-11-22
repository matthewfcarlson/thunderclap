#!/usr/bin/env python3
"""The macOS app of the wasm2c build (docs/wasm-port.md "The macOS app"; D190).

  build/venv/bin/python tools/wasm_app.py sdl                      # SDL3 with video -> build/third_party/out/sdl-video
  build/venv/bin/python tools/wasm_app.py build [--jobs 2]         # the gfx module and hulk-app (HULK_WASM_DIR)
  build/venv/bin/python tools/wasm_app.py bundle [--out build/app/Hulk.app]

`build` runs, with HULK_WASM_GFX=1 in its own HULK_WASM_DIR (default build/wasm-app): `wasm_port.py compile`
(every TU on a first build; afterwards only the two TUs the gfx hooks change, unless --all), `wasm_gfx.py compile`,
`wasm_port.py link` and `aot --app`. Inputs as wasm_port.py's (HULK_WASM_SNAP, HULK_WASM_BINDINGS).

`bundle` wraps hulk-app as an .app (Contents/MacOS/hulk-app, Info.plist). Not signed or notarised, and never
published: it is built from the player's own game (D190; public binaries need the maintainer's check first). At start
the app takes the game from HULK_XBE / HULK_DATA_DIR, else from ~/Library/Application Support/HulkUD/disc (the
extracted disc: default.xbe and its files), and keeps saves in ~/Library/Application Support/HulkUD/save
(src/platform/wasm/run/app/app.cpp)."""
import argparse
import os
import plistlib
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PY = sys.executable
TP = os.path.join(ROOT, "build/third_party")
SDL_VIDEO = os.path.join(TP, "out/sdl-video")
HOOKED_TUS = ["src/platform/xbox/pure3d/d3dDevice.cpp", "src/game/Render/Canvas/HulkShaderCallback.cpp"]


def env():
    e = dict(os.environ)
    e["HULK_WASM_GFX"] = "1"
    e.setdefault("HULK_WASM_DIR", os.path.join(ROOT, "build/wasm-app"))
    e.setdefault("HULK_APP_SDL", SDL_VIDEO)
    return e


def run(cmd, e):
    print("$ " + " ".join(cmd), flush=True)
    r = subprocess.run(cmd, env=e, cwd=ROOT)
    if r.returncode:
        raise SystemExit("failed: %s" % " ".join(cmd))


def cmd_sdl(a):
    """SDL3 with video (Cocoa, Metal views) for the app: tools/wine_sdl.py build_host's configuration otherwise."""
    bd = os.path.join(SDL_VIDEO, "cmake")
    os.makedirs(bd, exist_ok=True)
    cfg = ["cmake", "-S", os.path.join(TP, "src/SDL"), "-B", bd, "-G", "Ninja", "-DCMAKE_BUILD_TYPE=Release",
           "-DCMAKE_OSX_ARCHITECTURES=arm64", "-DCMAKE_OSX_DEPLOYMENT_TARGET=11.0", "-DCMAKE_C_COMPILER=/usr/bin/clang",
           "-DCMAKE_INSTALL_PREFIX=" + SDL_VIDEO, "-DSDL_SHARED=OFF", "-DSDL_STATIC=ON", "-DSDL_TEST_LIBRARY=OFF",
           "-DSDL_TESTS=OFF", "-DSDL_EXAMPLES=OFF", "-DSDL_VIDEO=ON", "-DSDL_OPENGL=OFF", "-DSDL_OPENGLES=OFF",
           "-DSDL_VULKAN=OFF", "-DSDL_GPU=OFF", "-DSDL_RENDER=OFF", "-DSDL_CAMERA=OFF", "-DSDL_DIALOG=OFF",
           "-DSDL_TRAY=OFF", "-DSDL_POWER=OFF", "-DSDL_SENSOR=ON", "-DSDL_AUDIO=ON", "-DSDL_JOYSTICK=ON",
           "-DSDL_HAPTIC=ON", "-DSDL_HIDAPI=ON"]
    with open(os.path.join(SDL_VIDEO, "build.log"), "w") as f:
        for cmd in (cfg, ["cmake", "--build", bd, "-j", str(a.jobs)], ["cmake", "--install", bd]):
            if subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT).returncode:
                raise SystemExit("SDL3 (video) failed at %s (log %s/build.log)" % (cmd[1], SDL_VIDEO))
    shutil.rmtree(bd, ignore_errors=True)       # (the install is what the app links)
    print("sdl: %s" % os.path.join(SDL_VIDEO, "lib/libSDL3.a"))


def cmd_build(a):
    e = env()
    out = e["HULK_WASM_DIR"]
    first = not os.path.exists(os.path.join(out, "compile.json"))
    tools = os.path.join(ROOT, "tools")
    run([PY, os.path.join(tools, "wasm_port.py"), "compile", "--jobs", str(a.jobs)] +
        ([] if first or a.all else ["--only"] + HOOKED_TUS), e)
    run([PY, os.path.join(tools, "wasm_gfx.py"), "compile", "--jobs", str(a.jobs)], e)
    run([PY, os.path.join(tools, "wasm_port.py"), "link"], e)
    run([PY, os.path.join(tools, "wasm_port.py"), "aot", "--app", "--jobs", str(a.jobs)], e)
    print("app: %s" % os.path.join(out, "hulk-app"))


def cmd_bundle(a):
    exe = a.exe or os.path.join(env()["HULK_WASM_DIR"], "hulk-app")
    if not os.path.exists(exe):
        raise SystemExit("no %s (tools/wasm_app.py build)" % exe)
    app = os.path.abspath(a.out)
    if not app.startswith(os.path.join(ROOT, "build") + os.sep):
        raise SystemExit("the bundle stays under build/ (it is built from the game: never committed or published)")
    shutil.rmtree(app, ignore_errors=True)
    macos = os.path.join(app, "Contents/MacOS")
    os.makedirs(macos)
    shutil.copy2(exe, os.path.join(macos, "hulk-app"))
    info = {"CFBundleName": "Hulk UD", "CFBundleDisplayName": "Hulk UD", "CFBundleIdentifier": "local.hulkud.wasm",
            "CFBundleExecutable": "hulk-app", "CFBundlePackageType": "APPL", "CFBundleVersion": "1",
            "CFBundleShortVersionString": "0.1", "LSMinimumSystemVersion": "11.0", "NSHighResolutionCapable": True,
            "LSApplicationCategoryType": "public.app-category.action-games"}
    with open(os.path.join(app, "Contents/Info.plist"), "wb") as f:
        plistlib.dump(info, f)
    print("bundle: %s (unsigned; data: ~/Library/Application Support/HulkUD/disc)" % os.path.relpath(app, ROOT))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("sdl")
    c.add_argument("--jobs", type=int, default=2)
    c = sp.add_parser("build")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--all", action="store_true", help="compile every TU (after an inputs change)")
    c = sp.add_parser("bundle")
    c.add_argument("--exe")
    c.add_argument("--out", default=os.path.join(ROOT, "build/app/Hulk.app"))
    a = ap.parse_args(argv)
    {"sdl": cmd_sdl, "build": cmd_build, "bundle": cmd_bundle}[a.cmd](a)


if __name__ == "__main__":
    main()
