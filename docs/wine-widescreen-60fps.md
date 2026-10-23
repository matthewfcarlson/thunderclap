# Widescreen and 60 fps (milestone 7)

Options of the Wine build's platform layer (`src/platform/sdl/`). Every default keeps the original's behaviour: a replay
at default settings has the same checkpoint hashes as before (see "Checks").

| Option | Values | What it does |
|---|---|---|
| `HULK_GFX_SIZE=WxH` (+ `HULK_GFX_WINDOW=WxH`) | any size, default 640x480 (`play.py` uses 1280x720) | The scene target and the display the game sees. `bgfxDisplay::vfunc_16` (GetAspectRatio) returns w/h, so the 3D view is Hor+ (the vertical FOV stays, the horizontal one grows). 16:9, 21:9 and so on need nothing else. |
| `HULK_HUD=edge\|centre` | default `centre` | `centre`: the original's HUD, a 4:3 frame in the middle of the picture. `edge`: the HUD frame models move out to the screen edges (below). |
| `HULK_FPS_CAP=30\|60\|0` | default 30 | Frame pacing after the present. 30: the game's own rule (the flag at 0x5554a0 that `d3dDisplay::SwapBuffers` 0x31b190 reads: clear = two vblanks per frame = 30 fps in gameplay, set = 60 in the front end). 60: always 60. 0: only the swap chain's vsync. Unset it is off for replays (`HULK_INPUT_SOURCE=replay:`) and the noop renderer, so replays and tests run as fast as before; set explicitly it applies everywhere. |
| `HULK_FPS_LOG=1` | | `pddi: frame time avg ... worst ...` in the trace every 120 presents. |

Test knobs: `HULK_VDT_US=N` (the replay's fixed step, default 33333; 16667 for 60 fps), `HULK_REPLAY_STRETCH=N` (each
recorded frame of the input lasts N game frames), `HULK_CKPT_CAM=1` (with `HULK_CKPT_ALL=1`: the camera position and the
clock block at every checkpoint), `HULK_HUD_LOG=1` (the HUD layout size when it changes, the projections the game sets).

## Widescreen

**What the game does at 16:9.** `ComputeRealFOV` (0x9f790) turns the nominal FOV into H = 2 atan(aspect x 0.75 tan(f/2))
and V = 2 atan(0.75 tan(f/2)): Hor+. The HUD is a 3D overlay (`COverlayManager`, 0xd6970) with its own camera (near 0.1,
far 100, FOV from the same function, so 106.3 degrees at 16:9) and a layout frame `0x4de600 x 0x4de604` = 22.3 x aspect
x 0.75 by 17.3 (29.73 x 17.3 at 16:9; 0xd6970, 0xd6b20, 0xd6c70 set it). Logged with `HULK_HUD_LOG=1` it is 22.3 at
640x480 and 29.73 at 1280x720, so the width follows the aspect. But the corner brackets and their bars are not placed
from it. They are four static models, drawn at world scale 4 with a 16x16 texture at depth 13, with fixed positions
(the same four draws every frame: 46, 120, 28 and 106 vertices), so they sit in a 4:3 frame in the middle of a wide
picture (brackets at 0.19 and 0.81 of the width, against 0.09 and 0.91 at 4:3). The text, the message box and the
icons (scales 0.04 to 1.0) are placed from the layout width by the game, and are left alone.

**`HULK_HUD=edge`.** The fixed-function vertex shader (`shaders/vp/vs_vp_ff.sh`, constant `u_vc[55]`) moves vertices of
those frame models outwards: when the current projection is the HUD camera (near 0.1, far 100, tan(fov/2) = 0.75 x
aspect, aspect above 1.4), the shift is `1 - (4/3)/aspect` in ndc (0.25 at 16:9, 0.4375 at 21:9) for vertices more than 0.2
of the 4:3 region away from its middle, none within 0.05 of the middle (smoothstep between). The frame models keep their
shape and their margin in units of the picture's height (0.12 H from the edge, as at 4:3). A draw is a frame model if
its world matrix scales by 2 or more (`ffConstants`, `bgfx_draw.cpp`). It costs nothing when off: the constant is 0.

Screenshots (play3 replay, game frame 840 and 3000, 1280x720; scratch, not committed):

- default: `/private/tmp/claude-501/-Users-matthewcarlson-git-hulk-ultimate-destruction-decomp/b2f33896-95c9-4c81-9afe-5f89753bb2fd/scratchpad/sky3/w720-840.png`
- 4:3 for comparison: `.../sky3/s43-840.png`
- `HULK_HUD=edge`: `.../sky3/hud-edge-1280x720-840.png` and `.../sky3/hud-edge-1280x720-3000.png`

**Refraction.** `bgfxRefractShader::vfunc_24` (`bgfx_shader.cpp`, the backend's own copy of 0x32f3b0) already uploads the
back buffer's real size as the viewport (c107) and scales the frame texture by back buffer / mode size, so the 640 and
480 literals of the original never reach the shader. Nothing to change; no refraction scene was in the replay to look at.

**Movies.** `movie::RenderStrategyBink::vfunc_6` (0x334620) reads the display's width, height and aspect and scales the
movie by (movie aspect / display aspect): a 640x480 movie at 1280x720 comes out 1.5 x 1.5 = 960x720, centred, black
bars at the sides. Checked by arithmetic on the function only: the boot movies rendered black in the screenshots taken
(not looked into).

**Front end.** The title screen and the difficulty menu (replay frames 60 and 400, 1280x720) draw full-width bars and
centred text and look right at 16:9; `HULK_HUD=edge` does not touch them (their draws are not the HUD camera's).
Further screens (pause, mission end, map) are not reachable from the play3 replay and have not been looked at.

**What is left.** Elements the game builds from the layout width are as the game places them: the tutorial message box
sits right of the middle (centre at layout x = 2.97, so 0.59 of the width at 16:9; not looked at in the 4:3 shot).
Health and rage meters, the minimap, boss bars: not in the replay's first 12,000 frames, so whether they are frame
models (shifted by `edge`) or layout-placed is unknown. A true 21:9 run was not made; the shift formula covers it and
`HULK_GFX_SIZE=2560x1080` is the knob.

## 60 fps

**The original's lock.** 30 fps in gameplay is `SwapBuffers`' vblank wait (above); the platform swap never ran it, so the
Wine build was vsync-paced (about 57 to 60 fps here). `HULK_FPS_CAP` puts the pacing back (`platformFramePace`, after the
present: sleep most of the rest, spin the last 2 ms; it re-bases when a frame ran long, so a load is not caught up).

Measured (this laptop, Wine 7.7, MoltenVK, 1280x720, replay): cap 30 gives 33.33 ms average, worst 34.3 ms over 120
presents; cap 60 gives 16.66 ms average (60.0 fps), worst 17.5 ms. Loading windows run longer than the cap.

**What the game does with dt.** Variable step by the measured time, clamped at 66,666 us; the replay uses a fixed 33,333
us virtual clock, which is why replays do not care about pacing. To look at dt = 16.7 ms in the replay the clock
step is `HULK_VDT_US=16667` and `HULK_REPLAY_STRETCH=2` repeats every recorded input frame, so the 60 fps run plays the
same game time of the same inputs.

**Result (play3, 640x480, camera position from `HULK_CKPT_CAM`, 30 fps at frame N against 60 fps at frame 2N):**

| game frame at 30 fps | 450 | 750 | 1050 | 1350 | 1650 | 2250 | 3150 |
|---|---|---|---|---|---|---|---|
| distance of the cameras (world units) | 0 | 2.7 | 3.3 | 5.7 | 22 | 40 | 137 |
| same, 30 fps against 30 fps with dt 33,000 us (1% shorter) | 0 | 1.7 | 2.4 | 3.7 | 30 | 82 | 219 |

The game clock agrees (frame 3000 at 60 fps: 35,498,446 ticks, frame 1500 at 30 fps: 35,430,719, 0.2% apart), the camera
travels the same distance in the same game time (a speed or animation-rate bug would show as a steady drift), and past
frame 1500 the two runs part ways exactly as fast as two 30 fps runs do with a 1% different step (the Hulk's path
bifurcates at some contact or jump): that is the floor of what a replay can tell, not a 60 fps effect. Screenshots at
equal game time (frame 840 at 30 fps against 1680 at 60) show the same scene, Hulk in the same run cycle phase to a
few frames, HUD identical.

Found nothing to fix. Not covered: input or animation events counted in frames that the replay does not reach
(menus, cut scenes, saving), and real-time play with the cap at 60 for a long session (only the replay was run). Audio
in a replay runs on the frame clock (`HULK_AUDIO_CLOCK=frame`), so the sound engine at 60 fps in real time is also untested.

## Checks

- Default replay hashes: 65 checkpoints (frames 0 to 25,500) of a 1280x720 play3 replay with the first image of this work (HEAD
  plus `HULK_FPS_CAP` only, pacing off in replays) are identical to the final image's, with `HULK_HUD=edge` set too; the
  middle image gave the same hashes with `HULK_HUD=edge HULK_FPS_CAP=60` and with `HULK_FPS_CAP=30` (41 checkpoints each). The one-step baseline: the tree and the game functions are unchanged by
  this work, and timing.cpp / replay read their new variables only when set.
- `tools/wine_gfx.py pddi` + `smoke`: 548 of 548 probes pass (Metal), `slots`: ok, 23 classes.
