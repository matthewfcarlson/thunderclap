# Playing the Wine build (play1)

```sh
build/venv/bin/python tools/play.py --check          # prerequisites
build/venv/bin/python tools/play.py --build          # backends + link (--reuse-map --gfx), then run
build/venv/bin/python tools/play.py --no-movies      # skip the ~2 minutes of boot movies
```

Prerequisites: Whisky's Wine (own prefix `build/native/wineprefix`; your bottles are untouched), your extracted disc in
`isos/extracted`, the built image, SDL3.dll, optionally the FFmpeg DLLs for cut scenes. Saves: `build/play/save`.

Keyboard (pad 0 while no gamepad is connected; `HULK_KEYBOARD=0` off, also off with a hidden window): WASD left stick,
IJKL right stick, arrows D-pad, Space A, F B, R X, G Y, Z White, X Black, Left Shift / Left Ctrl triggers, Enter Start,
Esc Back, Tab L3, V R3; F11 / Alt+Enter fullscreen. A gamepad (SDL3) replaces the keyboard when connected.

Env knobs added by play1: `HULK_MOVIES=0` (skip movies), `HULK_AUDIO_LOG=1` (mixer peak and voices every 5 s in the
trace), `HULK_KEY_SCRIPT="from-to:Key+Key,..."` (unattended key holds, tenths of a second since the first pad poll).

Measured 2026-10-21 (this laptop, Wine 7.7, MoltenVK): boot movies play with sound, title screen, Start reaches the first
mission (tutorial, "Walk Hulk around the junkyard"), Hulk moves with WASD, the in-game sound engine mixes 4-15 voices
(peaks near full scale), roughly 50 fps. Blockers and plans: build/play1/notes.md.

## play2 additions (2026-10-21)

- **Stale libraries.** `tools/wine_link.py` now rebuilds `hulk_sdl.lib`, `hulk_movies.lib` and `hulk_fs.lib` itself when
  a source under `src/platform/sdl` (audio, input, replay, fs, movies, top-level headers; mtime) is newer than the
  library (fs and movies only if they were built once). `HULK_WINE_REFRESH_LIBS=0` skips it. `HULK_TP_OUT=DIR`
  (tools/wine_gfx.py) moves the third-party output dir, for a private build. `play.py --build` is just the link now.
- **Window.** `play.py` defaults to `--window 1280x720` (the game's own frame; the 4:3 UI is pillarboxed by the game).
  `--window WxH` and `--fullscreen` still work, F11 / Alt+Enter toggle.
- **Key map.** `play.py --keys FILE` (or `HULK_KEYMAP=FILE`): `Control = Key[, Key]` lines, SDL key names, `#` comments.
  The defaults are listed in `config/keymap.example.txt`; unknown controls or keys are logged and skipped.
- **Limiter.** The mix bus soft-limits above 0.8 full scale (a smooth curve with the same slope at the knee, so |y| < 1 for any
  sum; below the knee nothing changes). `HULK_AUDIO_LIMIT=0` restores the old hard clip. `HULK_AUDIO_LOG=1` now also prints
  the pre-limiter peak and the number of limited samples. A 7-minute run to the tutorial: pre-limiter peaks up to 2.68
  (a burst), output peak 0.98, no output sample at full scale; 15,313 samples (of about 42 million) touched.
- **Joysticks.** The input backend logs what SDL sees (`input: SDL sees N joystick(s), M gamepad(s)` plus names) whenever it changes.

## Saving and loading

- Story Mode > New Game goes straight to difficulty selection and the tutorial: no memory-card prompt, nothing written.
  `U:` (build/play/save/UDATA/56550039) stays empty through the tutorial; Save is greyed in the tutorial pause menu, so
  the game first offers saving after the tutorial mission (not reached: needs a longer scripted run or a recording).
- Story Mode > Load Game works against the empty save area: `XFindFirstSaveGame` is called, fails with 18, and the game shows
  "No The Incredible Hulk: Ultimate Destruction saved game present on Xbox hard disk." with Ok.
- The write and read-back path (`XCreateSaveGame`, the signed blocks, `XFindFirstSaveGame`) is covered by `tools/wine_fs.py
  test` / `wine-test`, not yet from a real in-game save. Open: finish the tutorial unattended (HULK_KEY_SCRIPT, times in tenths of
  a second; reaching the tutorial takes about 3000 tenths with HULK_MOVIES=0: Return at 700, Space every 150 from 1000) and look
  for a UDATA directory, then Continue/Load Game.
- Menu timing: Return is Start (title only); menus select with Space (A). The title ignores Start for about a minute after
  launch with movies off.

## Gamepad under Wine on macOS (untested: no pad here)

What a test needs: a controller paired or plugged into the Mac; `play.py` without `HULK_KEYBOARD=0`. Watch the stderr in
build/play/run/stderr.txt for `input: SDL sees N joystick(s), M gamepad(s)`:
- 0 joysticks: Wine's HID layer (winebus, IOHID on macOS) did not expose the device. Try a PlayStation or other generic HID
  pad (Xbox pads are often claimed by macOS's own driver), grant Terminal / the launcher "Input Monitoring" in System Settings,
  and try SDL hints in the environment: `SDL_JOYSTICK_HIDAPI=0`, `SDL_JOYSTICK_RAWINPUT=0`, `SDL_JOYSTICK_WGI=0` (Wine 7.7
  lacks Windows.Gaming.Input), one at a time.
- joystick but "(no gamepad mapping)": SDL has no mapping for the device; set `SDL_GAMECONTROLLERCONFIG` to a mapping string.
- gamepad: it becomes pad 0 and the keyboard is off. A real pad replaces the keyboard for the session; hot-plug is handled.
Failing all that, a native macOS pad bridge (outside Wine) is the larger fallback.
