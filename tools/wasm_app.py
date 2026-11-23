#!/usr/bin/env python3
"""The macOS app of the wasm2c build (docs/wasm-port.md "The macOS app"; D190).

  build/venv/bin/python tools/wasm_app.py sdl                      # SDL3 with video -> build/third_party/out/sdl-video
  build/venv/bin/python tools/wasm_app.py build [--jobs 2]         # the gfx module and hulk-app (HULK_WASM_DIR)
  build/venv/bin/python tools/wasm_app.py bundle --out build/<lane>/Hulk.app [--with-game PACK|ISO] [--with-texpack F]

`build` runs, with HULK_WASM_GFX=1 in its own HULK_WASM_DIR (default build/wasm-app): `wasm_port.py compile`
(every TU on a first build; afterwards only the two TUs the gfx hooks change, unless --all), `wasm_gfx.py compile`,
`wasm_port.py link` and `aot --app`. Inputs as wasm_port.py's (HULK_WASM_SNAP, HULK_WASM_BINDINGS), from
`tools/wasm_inputs.py` at the commit being built. The directory's tree objects are tied to the inputs they were
compiled from (app-inputs.json: a digest of the snapshot, the binding map, the compiler tools and the wasm build
knobs); when any of them changed, or objects come without that record (copied from another build directory), `build`
compiles every TU again instead of linking stale objects (wapp2). Host files (src/platform/wasm) are compiled from
the checkout the tools run in.

`bundle` wraps hulk-app as an .app (Contents/MacOS/hulk-app, Info.plist). --with-game puts the player's own disc pack
(tools/disc_pack.py) or .iso in as Contents/Resources/game.hulkdisc / game.iso, which the app then plays with no setup;
--with-texpack puts a one-file texture pack (texpack_convert.py bundle) in as Contents/Resources/<its name>.hulkpack,
listed by Video Options > Texture Pack (wpkg1; copies are APFS clones where the volume allows). Such a bundle holds
the game: a personal build that never leaves the player's machine. Not signed or notarised, and never
published: it is built from the player's own game (D190; public binaries need the maintainer's check first). At start
the app takes the game from the command line (HULK_XBE / HULK_DATA_DIR), else the disc remembered in
~/Library/Application Support/HulkUD/game.txt, else .../HulkUD/disc, else it asks the player to choose the extracted
disc (default.xbe and its files) and remembers it; saves go to .../HulkUD/save (src/platform/wasm/run/app/start.cpp;
docs/wasm-port.md "First launch")."""
import argparse
import hashlib
import json
import os
import plistlib
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PY = sys.executable
TP = os.path.join(ROOT, "build/third_party")
SDL_VIDEO = os.path.join(TP, "out/sdl-video")
HOOKED_TUS = ["src/platform/xbox/pure3d/d3dDevice.cpp", "src/game/Render/Canvas/HulkShaderCallback.cpp",
              "src/game/Render/LevelLoader.cpp"]


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
    """SDL3 with video (Cocoa, Metal views) for the app: tools/wine_sdl.py build_host's configuration otherwise. The
    dialog subsystem is on: the first-launch game chooser (NSOpenPanel; run/app/start.cpp)."""
    out = os.path.abspath(a.out)
    bd = os.path.join(out, "cmake")
    os.makedirs(bd, exist_ok=True)
    cfg = ["cmake", "-S", os.path.join(TP, "src/SDL"), "-B", bd, "-G", "Ninja", "-DCMAKE_BUILD_TYPE=Release",
           "-DCMAKE_OSX_ARCHITECTURES=arm64", "-DCMAKE_OSX_DEPLOYMENT_TARGET=11.0", "-DCMAKE_C_COMPILER=/usr/bin/clang",
           "-DCMAKE_INSTALL_PREFIX=" + out, "-DSDL_SHARED=OFF", "-DSDL_STATIC=ON", "-DSDL_TEST_LIBRARY=OFF",
           "-DSDL_TESTS=OFF", "-DSDL_EXAMPLES=OFF", "-DSDL_VIDEO=ON", "-DSDL_OPENGL=OFF", "-DSDL_OPENGLES=OFF",
           "-DSDL_VULKAN=OFF", "-DSDL_GPU=OFF", "-DSDL_RENDER=OFF", "-DSDL_CAMERA=OFF", "-DSDL_DIALOG=ON",
           "-DSDL_TRAY=OFF", "-DSDL_POWER=OFF", "-DSDL_SENSOR=ON", "-DSDL_AUDIO=ON", "-DSDL_JOYSTICK=ON",
           "-DSDL_HAPTIC=ON", "-DSDL_HIDAPI=ON"]
    with open(os.path.join(out, "build.log"), "w") as f:
        for cmd in (cfg, ["cmake", "--build", bd, "-j", str(a.jobs)], ["cmake", "--install", bd]):
            if subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT).returncode:
                raise SystemExit("SDL3 (video) failed at %s (log %s/build.log)" % (cmd[1], out))
    shutil.rmtree(bd, ignore_errors=True)       # (the install is what the app links)
    print("sdl: %s" % os.path.join(out, "lib/libSDL3.a"))


# what the tree objects of a build directory depend on besides the hooked TUs (wasm_port.py's inputs and knobs)
STAMP = "app-inputs.json"
KNOBS = ["HULK_WASM_OPT", "HULK_WASM_ZEROINIT", "HULK_WASM_OPT_EXCLUDE", "HULK_WASM_FPFIX", "HULK_WASM_DEBUG_HOOKS", "HULK_LLVM_BIN"]


def _digest_tree(top):
    h = hashlib.sha1()
    for dp, dns, fns in os.walk(top):
        dns.sort()
        for f in sorted(fns):
            p = os.path.join(dp, f)
            h.update(os.path.relpath(p, top).encode() + b"\0")
            with open(p, "rb") as fh:
                h.update(hashlib.sha1(fh.read()).digest())
    return h.hexdigest()


def _digest_file(p):
    with open(p, "rb") as fh:
        return hashlib.sha1(fh.read()).hexdigest()


def inputs_stamp(e):
    """The inputs the directory's tree objects were compiled from (paths resolved as wasm_port.py does)."""
    out = e["HULK_WASM_DIR"]
    snap = e.get("HULK_WASM_SNAP") or os.path.join(out, "cp/snap")
    bind = e.get("HULK_WASM_BINDINGS") or os.path.join(out, "maps/bindings.json")
    for p in (os.path.join(snap, "manifest.json"), bind):
        if not os.path.exists(p):
            raise SystemExit("no %s: point HULK_WASM_SNAP / HULK_WASM_BINDINGS at tools/wasm_inputs.py's output" % p)
    return {"snap": _digest_tree(snap), "bindings": _digest_file(bind),
            "tools": {t: _digest_file(os.path.join(ROOT, "tools", t)) for t in ("wasm_port.py", "wasm_ir.py")},
            # (wbuild1) the replay hooks wasm_port places at bind time in every TU they name
            "hooks": _digest_file(os.path.join(ROOT, "src/platform/sdl/host/native_hooks.h")),
            "knobs": {k: e.get(k) for k in KNOBS}}


# The build's id (wver1): the short commit the app is built from, shown to the player (start-up line, window title,
# Info.plist; the Android APK's versionName and setup screen). HULK_BUILD_ID when set (wasm_build_run.py: the job's
# commit, "+N" for N overlay files and deletions); else git's HEAD here, "+dirty" when the files this checkout feeds the
# build (the host code and the tools; the tree comes from the HULK_WASM_SNAP inputs) have uncommitted changes. It goes
# into <dir>/aot/app-gen/hulk_build_id.h (run/app/start.cpp), which only the runner's objects depend on: a new id
# recompiles them, never a game TU (app-inputs.json does not hold it), and <dir>/build-id.txt (`bundle`).
BUILD_ID_TXT = "build-id.txt"
DIRTY_PATHS = ["src/platform/wasm", "src/platform/sdl", "tools"]


def build_id():
    bid = os.environ.get("HULK_BUILD_ID")
    if bid:
        return bid
    try:
        head = subprocess.run(["git", "rev-parse", "--short=7", "HEAD"], cwd=ROOT, capture_output=True, text=True,
                              check=True).stdout.strip()
        dirty = subprocess.run(["git", "status", "--porcelain", "--"] + DIRTY_PATHS, cwd=ROOT, capture_output=True,
                               text=True, check=True).stdout.strip()
    except (OSError, subprocess.CalledProcessError):
        return "unknown"
    return head + ("+dirty" if dirty else "")


def exe_build_id(exe):
    """The id compiled into a runner (start.cpp's "HULK_BUILD_ID=" tag), or None."""
    with open(exe, "rb") as f:
        data = f.read()
    i = data.find(b"HULK_BUILD_ID=")
    if i < 0:
        return None
    return data[i + 14:data.index(b"\0", i)].decode(errors="replace")


def write_build_id(gen, out, bid):
    """The id's header in the runner's generated include dir (written only when it changed) and <out>/build-id.txt."""
    os.makedirs(gen, exist_ok=True)
    h = os.path.join(gen, "hulk_build_id.h")
    text = "/* generated by tools/wasm_app.py (wver1): the build's id */\n#define HULK_BUILD_ID %s\n" % json.dumps(bid)
    try:
        same = open(h).read() == text
    except OSError:
        same = False
    if not same:
        with open(h, "w") as f:
            f.write(text)
    with open(os.path.join(out, BUILD_ID_TXT), "w") as f:
        f.write(bid + "\n")
    print("build id: %s" % bid, flush=True)


def cmd_build(a):
    e = env()
    out = e["HULK_WASM_DIR"]
    os.makedirs(out, exist_ok=True)
    write_build_id(os.path.join(out, "aot", "app-gen"), out, build_id())
    stamp = inputs_stamp(e)
    sp = os.path.join(out, STAMP)
    first = not os.path.exists(os.path.join(out, "compile.json"))
    full = first or a.all
    if not full:
        try:
            old = json.load(open(sp))
        except (OSError, ValueError):
            old = None
        if old != stamp:
            what = "no %s (objects of unknown inputs)" % STAMP if old is None else \
                "changed: " + ", ".join(k for k in stamp if old.get(k) != stamp[k])
            print("build: the tree objects in %s are stale (%s): compiling every TU" % (out, what), flush=True)
            full = True
    if full and os.path.exists(sp):
        os.remove(sp)       # (an interrupted full compile leaves no record)
    tools = os.path.join(ROOT, "tools")
    run([PY, os.path.join(tools, "wasm_port.py"), "compile", "--jobs", str(a.jobs)] +
        ([] if full else ["--only"] + HOOKED_TUS), e)
    rep = json.load(open(os.path.join(out, "compile.json")))
    if rep.get("failed"):
        raise SystemExit("build: %d TUs failed to compile (compile.json)" % len(rep["failed"]))
    with open(sp, "w") as f:
        json.dump(stamp, f, indent=1)
    run([PY, os.path.join(tools, "wasm_gfx.py"), "compile", "--jobs", str(a.jobs)], e)
    run([PY, os.path.join(tools, "wasm_port.py"), "link"], e)
    # the runner's own shaders (run/app/shaders: per-pixel lighting) beside the sink's, in aot --app's include dir
    run([PY, os.path.join(tools, "rm_shaders.py"), os.path.join(out, "aot", "app-gen")], e)
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
    bid = exe_build_id(exe) or build_id()       # (the id hulk-app was built with; wver1)
    info = {"CFBundleName": "Hulk UD", "CFBundleDisplayName": "Hulk UD", "CFBundleIdentifier": "local.hulkud.wasm",
            "CFBundleExecutable": "hulk-app", "CFBundlePackageType": "APPL", "CFBundleVersion": bid,
            "CFBundleShortVersionString": "0.1 (%s)" % bid, "CFBundleGetInfoString": "Hulk UD 0.1, build %s" % bid,
            "LSMinimumSystemVersion": "11.0", "NSHighResolutionCapable": True,
            "LSApplicationCategoryType": "public.app-category.action-games"}
    with open(os.path.join(app, "Contents/Info.plist"), "wb") as f:
        plistlib.dump(info, f)
    res = os.path.join(app, "Contents/Resources")
    extra = []
    for src, kinds in ((a.with_game, (".hulkdisc", ".iso")), (a.with_texpack, (".hulkpack",))):
        if not src:
            continue
        ext = os.path.splitext(src)[1].lower()
        if ext not in kinds:
            raise SystemExit("bundle: %s is not a %s file" % (src, " / ".join(kinds)))
        os.makedirs(res, exist_ok=True)
        dst = os.path.join(res, "game" + ext if kinds[0] == ".hulkdisc" else os.path.basename(src))
        if subprocess.run(["cp", "-c", src, dst], capture_output=True).returncode:      # (an APFS clone, else a copy)
            shutil.copyfile(src, dst)
        extra.append("%s %.2f GB" % (os.path.basename(dst), os.path.getsize(dst) / 1e9))
    print("bundle: %s (build %s; unsigned; %s)" % (os.path.relpath(app, ROOT), bid, "with " + ", ".join(extra) if extra else
          "the game: chosen at first launch, or ~/Library/Application Support/HulkUD/disc"))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    c = sp.add_parser("sdl")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--out", default=SDL_VIDEO, help="install prefix (the app links HULK_APP_SDL, default %(default)s)")
    c = sp.add_parser("build")
    c.add_argument("--jobs", type=int, default=2)
    c.add_argument("--all", action="store_true", help="compile every TU (after an inputs change)")
    c = sp.add_parser("bundle")
    c.add_argument("--exe")
    c.add_argument("--out", required=True, help="build/<lane>/Hulk.app; build/Hulk.app is the user's and only the lead writes it")
    c.add_argument("--with-game", help="the player's disc pack (.hulkdisc) or .iso: Contents/Resources/game.*")
    c.add_argument("--with-texpack", help="a one-file texture pack (.hulkpack): Contents/Resources/")
    a = ap.parse_args(argv)
    {"sdl": cmd_sdl, "build": cmd_build, "bundle": cmd_bundle}[a.cmd](a)


if __name__ == "__main__":
    main()
