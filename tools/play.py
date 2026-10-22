#!/usr/bin/env python3
"""Play the native image interactively (a real window, sound, keyboard or gamepad). docs/native-play.md.

  build/venv/bin/python tools/play.py                  # run build/native/link/hulk-strict.exe (the --gfx image)
  build/venv/bin/python tools/play.py --build          # (re)build the backends and link first (tools/native_link.py --gfx)
  build/venv/bin/python tools/play.py --no-movies --window 1280x960
  build/venv/bin/python tools/play.py --check          # only report the prerequisites

Prerequisites (all local, nothing is downloaded or committed):
  * Whisky's Wine (or WINE=/path/to/wine64). The game runs in its own prefix, build/native/wineprefix; your Whisky
    bottles are never touched.
  * Your own extracted disc in isos/extracted (default.xbe, *.rcf ...; HULK_DATA_DIR overrides).
  * The built image: build/native/link/hulk-strict.exe (use --build, or --image FILE) and, next to it or under
    build/third_party/out, SDL3.dll and (for the cut scenes) the FFmpeg DLLs plus hulkmovie.dll.
Saves live in build/play/save and title storage in build/play/tdata (kept between runs).

Keys can be remapped: --keys FILE (see config/keymap.example.txt, which lists the defaults).
Controls (keyboard is pad 0 whenever no gamepad is connected; HULK_KEYBOARD=0 disables it):
  WASD left stick, IJKL right stick (camera), arrows D-pad, Space A, F B, R X, G Y, Z White, X Black,
  Left Shift left trigger, Left Ctrl right trigger, Enter Start, Esc Back, Tab L3, V R3. F11 / Alt+Enter: fullscreen.
Gamepad: an SDL3 gamepad (Xbox, PlayStation, Switch Pro ...) connected before or during the run becomes pad 0 and
replaces the keyboard; A/B/X/Y = bottom/right/left/top, shoulders = White/Black, triggers, sticks, D-pad as expected.
Under Wine on macOS controllers reach SDL through Wine's own HID layer; if yours is not seen, use the keyboard.
"""
import argparse
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import native_run  # noqa: E402

ROOT = native_run.ROOT


def prereqs(exe, data):
    ok = True
    def line(good, what, hint=""):
        nonlocal ok
        ok = ok and good
        print("  [%s] %s%s" % ("ok" if good else "MISSING", what, "" if good else "  -> " + hint))
    line(os.path.exists(native_run.WINE), "Wine: %s" % native_run.WINE, "install Whisky (or set WINE=...)")
    line(os.path.exists(os.path.join(data, "default.xbe")), "game files: %s" % data,
         "extract your own disc into isos/extracted (docs/native-files-saves.md)")
    line(os.path.exists(exe), "image: %s" % exe, "run with --build")
    out3 = os.environ.get("HULK_SDL_OUT") or os.path.join(ROOT, "build/third_party/out")
    have_sdl = os.path.exists(os.path.join(os.path.dirname(exe), "SDL3.dll")) or os.path.exists(os.path.join(out3, "sdl-win32/SDL3.dll"))
    line(have_sdl, "SDL3.dll", "python tools/native_sdl.py build")
    have_ff = os.path.exists(os.path.join(os.path.dirname(exe), "hulkmovie.dll")) or os.path.exists(os.path.join(out3, "ffmpeg-win32/movies/hulkmovie.dll"))
    print("  [%s] FFmpeg movie decoder (hulkmovie.dll + avcodec/avformat/avutil)%s" %
          ("ok" if have_ff else "absent", "" if have_ff else ": cut scenes will be skipped (python tools/native_ffmpeg.py)"))
    return ok


def build():
    py = sys.executable
    env = dict(os.environ)
    # (native_link.py rebuilds hulk_sdl / hulk_movies / hulk_fs when their sources under src/platform/sdl are newer)
    for cmd in ([py, "tools/native_link.py", "--reuse-map", "--gfx"],):
        print("+", " ".join(cmd))
        if subprocess.run(cmd, cwd=ROOT, env=env).returncode:
            sys.exit("build step failed")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--image", help="the image (default build/native/link/hulk-strict.exe)")
    ap.add_argument("--build", action="store_true", help="build the backends and link the image first")
    ap.add_argument("--check", action="store_true", help="only check the prerequisites")
    ap.add_argument("--no-movies", action="store_true", help="skip every movie (HULK_MOVIES=0)")
    ap.add_argument("--window", metavar="WxH", default="1280x720",
                    help="window size (HULK_GFX_WINDOW; default 1280x720, the game's own 16:9 frame); the frame keeps its "
                         "aspect (bars), the window can be resized")
    ap.add_argument("--fullscreen", action="store_true", help="start fullscreen (F11 / Alt+Enter toggle it anyway)")
    ap.add_argument("--keys", metavar="FILE", help="keyboard map (HULK_KEYMAP); format: config/keymap.example.txt")
    ap.add_argument("--audio", default="wasapi", help="SDL audio driver under Wine: wasapi (default), winmm, dummy (mute)")
    ap.add_argument("--audio-log", action="store_true", help="log the mixer's peak level and voice counts every 5 s")
    ap.add_argument("--script", metavar="KEYS", help="HULK_KEY_SCRIPT: unattended key presses, 'from-to:Key+Key,...' in tenths of a second")
    ap.add_argument("--shots", metavar="FRAMES", help="HULK_GFX_SHOT frame numbers (comma separated), written to --shot-dir")
    ap.add_argument("--shot-dir", default=os.path.join(ROOT, "build/play/shots"))
    ap.add_argument("--timeout", type=float, default=0, help="stop after this many seconds (default: run until you quit)")
    a = ap.parse_args()
    exe = os.path.abspath(a.image or os.path.join(ROOT, "build/native/link/hulk-strict.exe"))
    data = os.environ.get("HULK_DATA_DIR_HOST") or os.path.join(ROOT, "isos/extracted")
    if a.build:
        build()
    print("prerequisites:")
    if not prereqs(exe, data) or a.check:
        return 0 if a.check else 2
    out = os.path.join(ROOT, "build/play")
    for d in ("save", "tdata", "run"):
        os.makedirs(os.path.join(out, d), exist_ok=True)
    out3 = os.environ.get("HULK_SDL_OUT") or os.path.join(ROOT, "build/third_party/out")
    import shutil
    for dll in ("sdl-win32/SDL3.dll", "ffmpeg-win32/movies/hulkmovie.dll", "ffmpeg-win32/dll/avutil-60.dll",
                "ffmpeg-win32/dll/avcodec-62.dll", "ffmpeg-win32/dll/avformat-62.dll"):
        src = os.path.join(out3, dll)
        dst = os.path.join(os.path.dirname(exe), os.path.basename(dll))
        if os.path.exists(src) and not os.path.exists(dst):
            shutil.copy2(src, dst)
    w = native_run.to_wine_path
    env = {"HULK_TRACE_FILE": w(os.path.join(out, "run/trace.txt")), "HULK_DATA_DIR": w(data),
           "HULK_SAVE_DIR": w(os.path.join(out, "save")), "HULK_TDATA_DIR": w(os.path.join(out, "tdata")),
           "SDL_AUDIO_DRIVER": a.audio}
    if a.no_movies:
        env["HULK_MOVIES"] = "0"
    if a.window and not a.fullscreen:
        env["HULK_GFX_WINDOW"] = a.window
    if a.keys:
        if not os.path.exists(a.keys):
            sys.exit("--keys: no such file: %s" % a.keys)
        env["HULK_KEYMAP"] = w(os.path.abspath(a.keys))
    if a.fullscreen:
        env["HULK_GFX_FULLSCREEN"] = "1"
    if a.audio_log:
        env["HULK_AUDIO_LOG"] = "1"
    if a.script:
        env["HULK_KEY_SCRIPT"] = a.script
    if a.shots:
        os.makedirs(a.shot_dir, exist_ok=True)
        env["HULK_GFX_SHOT"] = a.shots
        env["HULK_GFX_SHOT_DIR"] = w(a.shot_dir)
    prefix = os.path.join(ROOT, "build/native/wineprefix")
    print("starting %s (Ctrl-C or close the window to quit; trace: build/play/run/trace.txt)" % os.path.basename(exe))
    try:
        r = native_run.run(exe, prefix, a.timeout or None, env, os.path.join(out, "run"))
    except KeyboardInterrupt:
        native_run.kill_wineserver(prefix)
        return 130
    print(r)
    return 0


if __name__ == "__main__":
    sys.exit(main())
