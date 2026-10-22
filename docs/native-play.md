# Playing the native build (play1)

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
