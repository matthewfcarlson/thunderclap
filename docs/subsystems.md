# Subsystem map for QoL (task 07)

Where the code behind each quality-of-life target lives: display mode and back buffer, projection /
aspect / FOV and HUD layout, frame timing, and boot flow. Addresses are XBE virtual addresses.
Names in *italics* are ours (Ghidra carries them as `[port]` plate comments, via
`tools/ghidra_scripts/ApplyPortLabels.java`; function names themselves are unchanged). The full
list, with subsystem tags, is `QOL` in `tools/platform_map.py`.

Confidence: **high** = read in the decompiler and the data checked; **medium** = the role is clear
but not every caller or field is pinned down; **low** = a lead.

The class names in the task brief (`VCRenderManager`, `VHUDOverlay`, `VCGameFlowManager`, …) don't
exist in this binary. The real ones are `CGame`, `CGameFlowManager`, `CCameraManager`,
`CGameCamera`/`CChaseCamera`, `COverlayManager`/`HUDOverlay`/`CSimOverlayManager`, `CFEManager`,
`CFMVManager`, and Pure3D's `pure3d::Camera` / `pddiBaseContext` / `d3dDisplay`.

## Quick answers

| Question | Answer | Confidence |
|---|---|---|
| Hard-coded 640×480? | **No.** The game asks for up to **1280×720** (`-pal`: 640×576) and picks the best mode the dashboard allows from a table with 1080i, 720p, 480p and **16:9** modes. 640×480 is only the fallback. | high |
| Widescreen? | **Yes, natively**: a 16:9 mode is chosen when the dashboard's widescreen flag is set; the display then reports aspect 16/9 and cameras widen horizontally (Hor+). | high |
| Frame rate | Variable timestep, but **gameplay is paced to every 2nd vblank (30 fps)**; front end and movies run at 60. | high |
| Fixed-step physics? | None found. `dt` is measured each frame with QPC, **clamped to 66.67 ms**, scaled by a 16.16 time scale and passed down to everything, physics included. A few gameplay actions use 1/30 constants. | medium |
| Skip intros | One byte: the front end's boot step counter (`0x49fb40`). The legal screen is a 5 s splash plus a 3 s hold in `CGame::Run`. | high |

## 1. Resolution, back buffer and present parameters

Call chain (all high confidence):

```
main 0x8ee30
 └ CGame::Init 0x88020 … CPlatform::InitRender 0x8dec0
    ├ SetupDisplayInit 0x8ecd0          fills pddiDisplayInit: 0x49ca1c × 0x49ca20 (= 1280 × 720),
    │                                    -pal (0x4dd839) → 640 × 576; bpp 32; +0x2f "search modes" = 1,
    │                                    +0x30 "allow 16:9" = 1, +0x24 multisample = 0x11 (none)
    └ pure3d::InitPlatform 0x292560     prints "Pure3D v3.19.Hairclub"; d3dCreateDevice 0x31ba60 →
       │                                 d3dDevice::NewDisplay 0x31b830 → d3dDisplay ctor 0x31b520
       └ d3dDisplay::InitDisplay 0x31ae70   (pure3d::d3dDisplay vtable slot 4)
          ├ IsModeAllowed 0x31adf0      XGetVideoFlags (0x356667, NV setting 8): 480 lines need
          │                              WIDESCREEN (bit 0) for 16:9 and HDTV_480p (bit 3) for
          │                              progressive; 720 needs bit 1; 1080 needs bit 2
          ├ D3DPRESENT_PARAMETERS at display+0x14
          └ Direct3D_CreateDevice / D3DDevice_Reset, SetVerticalBlankCallback(0x31acc0)
```

Mode table `g_DisplayModeTable` at `0x4d3508`, 12 bytes per entry (`int w, h; u8 progressive,
widescreen`), searched in order; the first mode that is allowed and fits inside the request wins:

| # | Mode | Scan | Aspect |
|---|---|---|---|
| 0 | 1920×1080 | interlaced | 16:9 |
| 1 | 1280×720 | progressive | 16:9 |
| 2 | 720×480 | progressive | 16:9 |
| 3 | 640×480 | progressive | 16:9 |
| 4 | 720×480 | interlaced | 16:9 |
| 5 | 640×480 | interlaced | 16:9 |
| 6 | 640×480 | progressive | 4:3 |
| 7 | 640×480 | interlaced | 4:3 |

With the 1280×720 request, 1080i is never chosen (too wide). Present parameters set by
`InitDisplay`: back buffer = chosen mode, format 6 (A8R8G8B8) at 32 bpp else 5 (R5G6B5), one back
buffer, `D3DMULTISAMPLE_NONE`, discard, auto depth-stencil (`0x2a` D24S8 at 32 bpp, otherwise D24S8
or `0x2c` D16 by a flag). **Modes wider than 720 pixels force 16 bpp** (`InitDisplay` sets the
depth to 16 when width > 720), so 720p runs with a 16-bit back buffer, presumably for memory.
`Flags` = progressive/interlaced/widescreen from the table, refresh 60 if the PAL60 video flag
(0x40) is set, **`FullScreen_PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE`**: the game paces
frames itself (section 3). `d3dDisplay::GetAspectRatio` (`0x31b500`, slot 16) returns 4/3
(`0x432480`) or 16/9 (`0x432484`) from display+0x437 (the chosen mode's widescreen byte).

QoL notes:
- Native high resolution in the port: the backend ignores the table and reports the window size;
  everything above reads the size back through `pddiDisplay` (slot 7 = width, 6 = height, 16 = aspect).
- Hybrid build: raising `0x49ca1c/0x49ca20` and the table enables nothing new (720p already wins
  when allowed); xemu needs its dashboard video flags set to get 16:9/720p.
- Spot that will break at other resolutions: `d3dRefractVertexShader` (`0x32f3b0`) uses literal
  `640.0`/`480.0` (screen-space refraction scale). Medium confidence that it is the only one: no
  other game function loads 640.0 or 480.0 as a float.

## 2. Projection, aspect, FOV and HUD layout

**Projection matrix** (high): `pure3d::d3dContext::LoadProjectionMatrix` (`0x323ee0`, d3dContext
slot 109) builds the D3D projection from the current `pddiViewState` (`context+0x48`): near
`+0x24`, far `+0x28`, FOV `+0x2c`, aspect `+0x30`, normalized viewport window `+0x14..+0x20`.
Mode 0 is perspective (`fptan(fov × 0.5)` with an off-centre window), mode 1 orthographic with
aspect, mode 2 orthographic in pixels (display width/height). It calls `SetViewportRect` (`0x321520`)
and `D3DDevice_SetTransform(D3DTS_PROJECTION)`. Slot 108 (`0x323eb0`) loads world/view matrices.

**FOV and aspect** (high):

```
CGameCamera::Update 0xa97e0 (CGameCamera slot 35; debug page "Show FOVs" prints
│                            "Aspect Ratio: %.3f" and "FOV: nominal %.1f real H%.1f V%.1f")
├ display->GetAspectRatio()          re-run when the aspect changes
├ ComputeRealFOV 0x9f790             t = tan(nominal/2);  H = 2·atan(aspect · 0.75 · t),
│                                    V = 2·atan(0.75 · t)   (degrees)
└ this->SetFOV(H in radians, 1.0)    = pure3d::Camera::SetFOV 0x2926d0 (slot 5): stores fov and
                                       aspect × display->GetAspectRatio(), precomputes the frustum
```

So the nominal FOV is the horizontal FOV *at 4:3*; the vertical FOV is fixed and 16:9 widens the
horizontal one (Hor+). `CGameCamera`'s constructor (`0xa9400`) sets nominal FOV 75°, near 0.1, far
3000 (`0xa9090(75.0)`, presumably the nominal-FOV setter; `Camera::vfunc_7(0.1)`, `vfunc_9(3000)`). Script bindings
`cm_SetChaseCamFOV`/`cm_GetChaseCamFOV` and `cm_SetScriptCamFova*` (registered in `0x9dd20`) set
the nominal FOV per camera mode. **FOV slider**: scale the nominal FOV passed to `ComputeRealFOV`
(or the value `cm_SetChaseCamFOV` stores).

**HUD / overlays** (medium): `COverlayManager` (ctor `0xd6970`, owned by `CGame+0x2c`) draws the
HUD as a 3D overlay scene with its own `pure3d::Camera`: nominal FOV 90° through the same
`ComputeRealFOV`, and a layout half-width `0x4de600 = 22.3 × aspect × 0.75` (22.3 at 4:3, 29.7 at
16:9). `0xd6a20`, `0xd6b20`, `0xd6c70` recompute both when the aspect changes. HUD elements are
therefore laid out against an aspect-dependent width (text, message box and icons follow it; the corner-bracket
frame is four static models at scale 4 and stays a 4:3 frame: measured in [wine-widescreen-60fps.md](wine-widescreen-60fps.md),
which also has the `HULK_HUD=edge` option that moves them to the screen edges). Front-end screens do the same (`FEScreenBase::vfunc_10`, `0xef4f0`, per-screen
nominal FOV at `+0x98c`). The TV-safe area is a debug overlay only (0.075–0.925, "Xbox Certification
Safe Area" in `0xa97e0`). Not yet checked: which HUD elements are anchored to edges vs centred, and
the 2D text/sprite path (`pddiBaseContext` 2D mode, `pure3d::TextureFont`). Movies letterbox via
`movie::RenderStrategyBink::vfunc_6` (`0x334620`), which reads display width, height and aspect.

**Where to patch for widescreen in the hybrid build**: nothing for the 3D view (already Hor+); force
`d3dDisplay::GetAspectRatio` to return the wanted aspect to get 16:9 without a 16:9 video mode
(anamorphic), or 21:9 for ultrawide in the port.

## 3. Frame timing, main loop and dt

Call chain (high):

```
main 0x8ee30 → CGame::CGame 0x87e80, CGame::Run 0x88530
  ├ CGame::Init 0x88020                 GameClock at CGame+8 (ctor 0x87e30, 0x50 bytes)
  ├ ShowCopyrightScreen3s 0x879c0       holds the "copyright-<lang>" screen for 3000 ms
  └ CGame::MainLoop 0x87940             while state != GS_QUIT(8):
      ├ CGame::Tick 0x87630
      │   ├ PumpPlatformServices 0x8db00   radcore service pumps and the movie player
      │   ├ GameClock::Update 0x86450       (below)
      │   ├ ApplyStateChange 0x873a0        GS_NONE/FRONTEND/PREGAME/PRESSSTART/GAME/POSTGAME/
      │   │                                 PAUSE/FMV/QUIT (state at *(CGame+4))
      │   ├ script system update 0x1d1160(dt), UpdateFrontEnd 0x86a40(dt)
      │   └ in GS_GAME: UpdateSimulation 0x88c30(GameClock::GetScaledDtSeconds)  ["Enable simulation"]
      │        → ~25 subsystem updates with the same dt, incl. physics 0x1e6f10 ("DoPhysics")
      └ CGame::Render 0x86cb0 → 0x1b93a0 (world/overlay render); the frame ends in
         d3dDisplay::SwapBuffers 0x31b190 (a virtual call; the exact caller isn't pinned down)
```

**GameClock** (`CGame+8`, high):

| Offset | Meaning |
|---|---|
| +0x00 | max dt = `0x1046a` = 66,666 µs (≈ 15 fps floor) |
| +0x08 | last timestamp (µs, `core::GetMicroseconds64` 0x267f40 = QPC × 10⁶ / freq) |
| +0x20 | raw frame time (µs) |
| +0x28 | clamped frame time (0 while paused) → `GetDtSeconds` 0x85fc0 |
| +0x30 | scaled dt = clamped × timescale >> 16, × "Debug time dilation" / 16 → `GetScaledDtSeconds` 0x860c0 (also the script function `time_GetElapsedTime`) |
| +0x38 | time scale, 16.16 fixed point (0x10000 = 1.0; reset on entering GS_GAME) |
| +0x10 / +0x18 | accumulated real / scaled time |

The timer base is `core::InitTimerFrequency` (`0x267a50`) caching `QueryPerformanceFrequency`
(a constant 733,333,333 Hz on Xbox); `core::GetMilliseconds` (`0x267f80`) and
`GetMicroseconds` (`0x267f00`/`0x267f40`) divide QPC by it.

**Frame pacing** (high): `d3dDisplay::SwapBuffers` (`0x31b190`, slot 14) uses the vblank counter
`0x55549c` (incremented by the vertical-blank callback `0x31acc0`) and the flag `0x5554a0`:

- flag set: wait for one vblank, then `Swap` → at most 60 fps;
- flag clear: wait until at least **two** vblanks have passed since the last swap → at most
  **30 fps** (25 at PAL 50 Hz).

`SetFrontEndVSync60` (`0x8db60`) sets the flag: 1 on entering press-start (`0x86790`) and while a
movie plays (`0x1b80e2`), **0 on entering GS_GAME** (`0x873a0`) and in `0x86900`; `0x1b8732`
restores the saved value after a movie. So menus and FMVs run at 60 and gameplay at 30. The
`-framerateicon` switch (`0x4dd8e4`) times the frame, simulation and physics with
`core::GetMicroseconds` and `pddiBaseContext::DrawFrameRate` (`0x31d3f0`) prints
`"%.2fms (%2.0ffps)"`; there's also a "BLock to VSync" debug-menu string.

**Does gameplay assume 30 Hz?** (medium) The architecture is variable-step: every update takes the
measured dt, the clamp is at 15 fps, and the physics update (`0x1e6f10`) has no fixed sub-step
(it passes dt, and dt × 1000, per object). Animation is time-based: frame controllers carry the
clip's own frame rate (`pure3d::SimpleFrameController::vfunc_10` returns it, 30.0 by default).
Risks for 60 fps: a few gameplay functions use per-frame constants, 1/30 in
`CHeliDeathSpiralAction::vfunc_7` (`0x18170`), `0xfee10` (`CHand2HandAgent` area) and
`pure3d::MultiController::vfunc_23` (`0x2b1df0`), 1/60 in `0x38660` and the controller/drive error
callbacks. `CSoundVoiceManager` pre-rolls voices with 100 fixed 1/60 s steps (`0x1f6580`,
`0x1f6650`), which is audio, not physics.

**60 fps experiment for the hybrid build**: make `SetFrontEndVSync60` always store 1 (or NOP the
two-vblank branch in `0x31b190`), then compare replays. Unlocked frame rate in the port: replace
`SwapBuffers` pacing with the host's vsync/present mode; the clamp at `GameClock+0` is the only other
limit.

## 4. Boot flow and intro movies

High confidence:

1. `main` (`0x8ee30`) → `PlatformEarlyInit` (`0x8d660`), radcore/memory setup, `ReadArgsTxt`
   (`0x8fca0`) → `ParseCommandLineSwitches` (`0x8f880`).
2. `CGame::Init` (`0x88020`): language from `XGetLanguage` (or `-lang`), loads `sound_<lang>.rcf`,
   builds the managers, checks `XGetDiskSectorSizeA("D:\")` (2048 = running from DVD).
3. `ShowCopyrightScreen3s` (`0x879c0`): the "copyright-<lang>" image for **3000 ms**.
4. Main loop, GS_FRONTEND: `CFEManager::Update` (`0xc5180`, front-end screen state machine,
   "splash" state) → `CFEManager::BootSequence` (`0xc4220`), stepping `g_BootSequenceStep`
   (`0x49fb40`):

| Step | What | How |
|---|---|---|
| 0 | `copyright-<lang>` splash | `ShowSplashImage 0xc3900(name, 5000, 5000, …)`: up to 5 s |
| 1 | `dolby` movie | `CFMVManager::QueueMovie 0x1b7310(name, 1000, skippable=1)` |
| 2 | `marvel` movie | same |
| 3 | `radical` movie | same |
| 4 | `sierra` movie | same |
| 5 | `attract` movie | same |
| 6 | done | "FE_screen_enter_start" (press start) |

Movies are `movies\<name>.rmv` (`movies-pal\` with `-pal`), played by `CFMVManager::OpenMovie`
(`0x1b7f40`) through `movie::PlayerBink`. `QueueMovie`'s last argument is 1 for all of them
(probably "skippable"; `fmvm_GetUserSkippedLastTime` exists as a script function). After 66.6 s idle
on the title screen the attract movie plays again (`CFEManager::AttractIdleTimer`, `0xbfbe0`,
threshold at `0x409298`).

**Skip intros**: start `g_BootSequenceStep` at 6 (or 5 to keep the attract loop), i.e. initialize
`0x49fb40` to 6, and patch the `3000` in `0x879c0` (and the 5000 ms splash) for a faster start.
The legal screen is required on console, not in a port.

**`args.txt` switches** (`ParseCommandLineSwitches`, `0x8f880`; read from `D:\args.txt`, the retail
disc ships `-fmvvol 0.9`): `-nocd`, `-level <name>` (boot straight into a level, skipping the front
end: `CGame::ApplyStateChange` case 1 uses `0x4dd890`), `-firewire`, `-displaymemoryusage`,
`-nosound`, `-english`/`-italian`/`-french`, `-fakexp`, `-savemissionstats`, `-pal`, `-drawcode`,
`-lang <xx>`, `-fmvvol <f>`, `-difficulty <n>`, `-lighthack`, `-autotester`, `-nofilenotfound`,
`-caminvertx/-caminverty/-caminvert1x/-caminvert1y`, `-notintextbible`, `-nodpad`,
`-notargeticon`, `-framerateicon`. Several are QoL by themselves (camera inversion, frame-rate
display, level select).

## Priority list

`docs/port-priority.txt` (= `build/farm/priority.txt`), 2,011 functions, 228 KB, in order:

| Group | Functions | Bytes | Already matched (when generated; every one has verified source now) |
|---|---|---|---|
| seam functions that call the platform (render, core-platform, audio-hal, movie), then the 8 leaks, then the rest of the seam ranges | 1,597 | 147,540 | 1,102 (37,564 B, 25%) |
| other vtable slots of seam classes | 22 | 714 | 20 |
| QoL functions above | 54 | 18,509 | 12 (863 B, 5%) |
| direct game-code callees of all of the above | 338 | 60,918 | 205 (7,451 B, 12%) |
| **total** | **2,011** | **227,681** | **1,339 (46,282 B, 20%)** |

Regenerate with `build/venv/bin/python tools/platform_map.py --priority` (match status is read
from `matches/` at that time).

## Open leads

- HUD element anchoring and the 2D sprite/text path in 16:9 (section 2).
- Audit of per-frame constants for 60 fps (section 3); a replay comparison in the hybrid build
  (task 06) would settle it.
- The `-level` switch and `CGameFlowManager` script bindings as a level-select / debug-menu QoL.
- Bink entry points are unnamed (12 functions, all called from `movie::PlayerBink`).
