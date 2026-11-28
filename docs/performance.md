# Performance: the frame budget of the wasm app (wperf1)

wperf1, 2026-11-23. User (11-23): a single effect costing +3 ms "when we have 16 ms to play around in" is too much: set
and meet a frame budget. This document is the measured baseline of the remastered edition on the user's laptop, the
per-pass budgets, and what the upscalers, TAA and the other optimisations change. Everything here is renderer-only:
the game's state and play3's checkpoint records are the same with every setting (checks at the end).

## 1. How it is measured

- **Machine.** The user's MacBook Air M3 (Mac15,13; 10-core GPU, 8 CPU cores, fanless). The app's default window is
  640x480 points: 1280x960 pixels on the built-in Retina display (640x480 on the 1x external display the laptop was
  attached to while measuring); Render Resolution's remastered default is Window, so the default render size on the
  Air is 1280x960. Runs here use a hidden window of 1280x960 pixels (`HULK_GFX_WINDOW`), Metal, unless noted.
- **Workload.** play3 replayed from boot, unpaced (each update presents as fast as it can), the night city of game
  frames 15,000-17,400 (the heaviest part of play3: wet streets, lit windows, lamps, 280-310 game draws and ~580 sink
  draws a frame with every pass on).
- **Frame time** is the unpaced wall time a presented frame (`HULK_GFX_STATS` "wall", or the image's frames/s): the
  remastered frame is GPU-bound (bgfx::frame waits for a free frame in flight), so this is the GPU's throughput. The
  frame rate "reached" is its inverse; paced at 60 or 120 the frame has that much headroom.
- **Quiet.** Other lanes run Metal replays on the same laptop most of the day; every measured run waited for a moment
  with no other hulk-app process and records how many 5 s samples saw one start meanwhile (build/wperf1/scripts/
  meas.sh; runs marked "loaded" below were not quiet throughout). The M3 Air throttles after minutes of full GPU load
  (no fan): long unpaced runs are a worst case, not a typical frame.
- **GPU per pass**, two ways. (a) The pass's A/B switch: off and on in turns of 30 presented frames within one run
  (`HULK_<PASS>_AB=30`; the same scenes on both sides), compared on bgfx's frame GPU timer. That timer spans a command
  buffer's start to end, and consecutive frames overlap on the tile GPU (one frame's vertex work under the last one's
  fragments): it reads ~1.8x the frame's real GPU time (16-19 ms against 10 ms frames), so its deltas rank the passes
  but overstate them. (b) The frame time of a run with the pass off against the same settings with it on (quiet runs,
  noise about +-0.3 ms): the real cost. bgfx's per-view timers (`BGFX_DEBUG_PROFILER`) give unusable numbers on Metal
  here (sums 10-100x the frame's) and split every view into its own render pass, which itself costs on a tile GPU.
- **CPU.** `HULK_GFX_STATS=300` (gfxstats.cpp), now with the runner's split: the rm passes' hooks (their own encoding
  and redraws), the game's draws into the sink, `bgfx::frame` (Metal encoding and submission: this build runs bgfx
  single-threaded, so this is the render thread's work, plus any wait for a free frame in flight), interp's replays at
  60 / 120 fps, and the module's own time (game update and scene traversal) as the rest of the wall time.

## 2. Baseline (before this lane's default changes)

Quiet runs (no other Metal process in any 5 s sample), app at 761e91dfd plus wperf1's working tree, play3's night city:

| settings | render | frame | reached | module (game) | rm hooks | bgfx::frame |
|---|---|---|---|---|---|---|
| every picture option off (Original), Window | 1280x960 | 2.2 ms | 472 fps | 1.5 ms | 0.05 ms | 0.4 ms |
| **remastered defaults** (MSAA 4x, Reflections High) | 1280x960 | **11.6 ms** | 86 fps | 2.3-4.8 ms | 1.15 ms | 4.8 ms |
| the same, Anti-Aliasing off | 1280x960 | 7.3 ms | 137 fps | 2.2 ms | 0.5 ms | 4.2 ms |
| the same, TAA | 1280x960 | 8.2 ms | 122 fps | 2.3 ms | 0.6 ms | 4.9 ms |
| remastered defaults, default window on a 1x display | 640x480 | 4.9 ms | 210 fps | 2.1 ms | 0.5 ms | 2.0 ms |
| remastered defaults, 1920x1440 window | 1920x1440 | 21.6 ms | 46 fps | 3.8 ms | 0.9 ms | 16.2 ms |

At the display rates (interp.cpp re-draws every update's stream; presents a second, unpaced):

| settings, 1280x960 | 60 fps target | 120 fps target |
|---|---|---|
| remastered defaults (MSAA 4x) | 100 presents/s (10.0 ms each): holds 60, 6.7 ms spare | not reached |
| the same with TAA | 134 (7.5 ms) | 136 (7.4 ms): holds 120 barely |
| Performance (TAA, Render Scale 50%, FSR 1, Shadows Low, Reflections Low) | | 328 (3.0 ms) |

**CPU** (TAA, a present at 30 fps): the module's update and scene traversal 2.3 ms, the rm passes' hooks (their own
redraws and encoding: shadow casters, the G-buffer, the velocity draws) 0.6 ms, the game's draws into the sink 0.16 ms,
`bgfx::frame` 4.9 ms of which Metal encoding is ~1.5-2 ms (bgfx's own CPU timer) and the rest waiting for the GPU. At
60 fps interp's replay of a present costs ~1 ms of CPU beyond bgfx (matching, constants, the rm hooks again). The CPU
has room: ~4-5 ms of a present's work against 16.7 (60) or 8.3 (120) ms, so the budget is the GPU's.

**Per pass** (the night city, 1280x960):

| pass | A/B GPU timer, MSAA 4x | A/B GPU timer, TAA | frame time without it (TAA) |
|---|---|---|---|
| Anti-aliasing: MSAA 4x (vs off) | | | **+4.3 ms** (11.6 vs 7.3) |
| Anti-aliasing: TAA (vs off) | | +1.35 | +0.9 ms |
| Shadows High (2 x 2048) | +8.4 | +6.1 | +1.4 ms |
| Shadows Low (1 x 1024) | | | +0.5 ms |
| Reflections High (full-size trace) | +4.0 | +3.2 | +1.6 ms (a loaded run; about) |
| Reflections Low (half-size trace) | | +1.2 | +0.9 ms |
| Ambient Occlusion | +2.1 | +0.7 | under 0.3 ms (a loaded run) |
| HDR (its views; grade inside its tone map) | +1.05 | +0.33 | +0.8 ms (with the grade) |
| Atmosphere | +2.5 | +0.7 | +0.3 ms |
| Night Lights | +1.2 | | +0.75 ms |
| Windows (interiors) | +0.7 | | +0.2 ms |
| Colour Grade | +0.2 | | |
| Contact Shadows + Bounce Light (wshadow1; studio, play3 to 25,000) | | +0.27 | |

What the numbers say: **MSAA 4x on the half-float scene is the largest single cost** (+4.3 ms, ~40% of the frame): it
multiplies every full-screen runner pass by four samples (AO's apply +2.1 ms under MSAA, +0.7 without; the atmosphere
+2.5 vs +0.7), and every view the runner inserts between the game's passes (shadows, the G-buffer, AO, the trace, HDR)
stores and reloads a 4x RGBA16F target on the tile GPU. Next are Shadows High and Reflections High. Shadow casters
culled per cascade (wperf1, 40% fewer cascade draws: ~150 of ~370) did not move the cost: it is the fill of the
2 x 2048 rows (the rooms drawn twice, both faces), not the draw count.

## 3. Budgets

The remastered defaults must hold 60 fps on the M3 Air with the GPU at or under ~12 ms a frame and CPU headroom; a
Performance path must reach 120 fps. Per-pass budgets (M3 Air, 1280x960, GPU frame time a pass may add):

| pass | budget | measured (TAA) | at the defaults |
|---|---|---|---|
| the game's own frame (rooms, characters, effects, HUD) at the render size | 2.5 ms | 2.2 ms | |
| per-pixel lighting, HDR, colour grade | 1.0 ms | 0.8 ms | on |
| anti-aliasing | 1.0 ms | TAA 0.9 ms (MSAA 4x 4.3 ms) | TAA |
| shadows | 1.5 ms | High 1.4, Low 0.5 | High |
| reflections | 1.0 ms | Low 0.9, High 1.6 | Low |
| ambient occlusion | 0.5 ms | < 0.3 ms | on |
| atmosphere + night lights | 1.0 ms | 1.05 ms | on |
| windows | 0.3 ms | 0.2 ms | on |
| soft particles (wfx1, docs/particles.md) | 0.3 ms | +0.42 ms bgfx timer on mac2's M3 Max over play3 (~0.23 ms real; fade alone +0.17) | Soft |
| water (wwater1, docs/water.md) | 0.2 ms | +0.10 ms bgfx timer on studio over play3 (~0.06 ms real) | Enhanced |
| upscaling | 0.5 ms | FSR 1: two passes at the present size | Auto |
| the performance overlay | 0.1 ms | | off |
| **frame** | **≤ 12 ms (60 fps)** | **~7.5 ms** | |

**Defaults changed** (port_settings.c): Anti-Aliasing MSAA 4x -> **TAA** (-3.4 ms; image section 5.1), Reflections
High -> **Low** (-0.7 ms; the half-size trace with the composite's depth-weighted, roughness-sized gather as the
edge-aware upsample; High stays the full-size option), Render Scale **Auto** with Upscaler Auto: a window of more than
1280x960 pixels draws the scene at the largest scale (at least 50%) within 1280x960 pixels and FSR 1 brings it to the
window (the Air's full screen, 2219x1664 at 4:3, draws at 57%), so the default frame stays ~7.5-8 ms at any window size
(1920x1440 native MSAA 4x was 21.6 ms; FSR 67% + TAA 9.4 ms). The remastered defaults now draw a 1280x960 frame in
~7.5 ms: 60 fps with ~9 ms to spare, and 120 fps at the 120 setting with about 1 ms.

**Performance** (120 fps): TAA, Render Scale Balanced or Performance, Shadows Low, Reflections Low: 3.0 ms a present at
50% (328 presents/s unpaced). Render Scale is the preset row (Native / Auto / Ultra Quality / Quality / Balanced /
Performance); the rest are the passes' own rows.

**Other targets** (estimates from the M3 Air's numbers by pixels and GPU throughput; not measured): Steam Deck (RDNA2,
1.6 TFLOPS, 88 GB/s; 800p, the 4:3 picture 1067x800 = 0.7x the pixels; ~0.45x the M3's throughput): the remastered
defaults ~11-12 ms, 60 fps with Render Scale Auto; Quality (67%) gives ~7 ms. Android, Adreno 740 class (tile-based like
Apple's, ~0.55x): 720p's 960x720 picture ~8-9 ms at the defaults; Mali-G710 class (~0.3x, half the bandwidth): ~16 ms:
Shadows Low, Reflections Low and Render Scale Quality bring it to ~9 ms, and MSAA there is out of the question (4x
half-float samples). TAA's history (2 x RGBA16F) and the velocity target cost ~15 MB at 1280x960.

## 4. Upscaling (Upscaler, Render Scale)

Two Video Options rows (port_settings.c; output only, remastered-only):

| row | values (faithful first) | remastered default | Quality index |
|---|---|---|---|
| `upscaler` Upscaler | Off (Original), Auto, FSR 1, Temporal (TAA), MetalFX (TAA) | Auto | rm::kUpscaler = 17 |
| `render_scale` Render Scale | Native, Auto, Ultra Quality (77), Quality (67), Balanced (59), Performance (50) | Auto | rm::kRenderScale = 18 |

- **Render Scale** is the preset row: the scene target is made at that share of the render resolution (app.cpp
  `rrSize`; the scales are FSR's Ultra Quality 1.3x, Quality 1.5x, Balanced 1.7x and Performance 2x). Auto (value 0) is
  the largest scale, at least 50%, that keeps the scene within 1280x960 pixels (section 3). Everything that
  is sized from the scene (the frame copies, the effects, every runner pass) follows; the game still sees 640x480, and
  the occlusion queries' counts are scaled back as for any render size.
- **Upscaler** decides how the frame reaches the present size. Off: the sink's bilinear stretch, as before. FSR 1:
  run/app/upscale.cpp, the last pass of the frame (postScene, after the HUD), two full-screen passes at the present
  size: EASU (shaders/fs_rm_easu.sc, edge-adaptive Lanczos-2 from 12 taps, deringed) and RCAS (fs_rm_rcas.sc, 0.25 stops
  of contrast-adaptive sharpening; `HULK_FSR=stops`), then presented 1:1 (`hulk_gfx_sink_present_source`, bgfx_sink.cpp
  under HULK_SINK_OVERLAY). Temporal and MetalFX (wperf2): section 4.2; both do the anti-aliasing too, so they imply
  TAA whatever the Anti-Aliasing row says ("(TAA)" in their names). Auto: the platform's temporal upscaler (MetalFX on
  macOS, ours elsewhere) when Anti-Aliasing is TAA, else FSR 1 (an MSAA choice stays MSAA: the Linux player's MSAA 2x
  keeps FSR 1 under Auto, and choosing Temporal turns the scene to TAA); on Android FSR 1. An upscaler runs only when
  the present rectangle is larger than the scene (Native at Window size does nothing: TAA resolves as before).
- **Spatial first, the HUD included.** The whole frame is upscaled at the end, so the HUD and the game's effects are
  drawn at the render size and upscaled with the world: at 67% and above the HUD's text stays clean (EASU keeps edges);
  at 50% it softens. HUD Resolution Display (whud1, 4.3, a remastered default) draws the HUD at the present size
  instead.

### 4.1 Cost

| settings (TAA) | render | present | frame | reached |
|---|---|---|---|---|
| Native | 1280x960 | 1280x960 | 8.2 ms | 122 fps |
| Quality (67%) + FSR 1 | 858x643 | 1280x960 | 5.8 ms | 175 fps |
| Native, MSAA 4x (the old default) | 1920x1440 | 1920x1440 | 21.6 ms | 46 fps |
| Quality (67%) + FSR 1 | 1286x965 | 1920x1440 | 9.4 ms | 107 fps |
| Performance (50%) + FSR 1, Shadows / Reflections Low, 120 fps | 640x480 | 1280x960 | 3.0 ms | 328 presents/s |

EASU and RCAS are two full-screen passes at the present size: about 0.2-0.4 ms at 1920x1440 by their shape (12 and 5
taps); they are not separable in these runs from the scene's own saving. Picture: build/wperf1/png (not committed): at
67% the city's edges and the HUD stay clean (EASU keeps edges, RCAS restores contrast); at 50% fine textures soften and
the HUD's small text blurs.

### 4.2 Temporal upscaling: Temporal (ours) and MetalFX (wperf2)

- **The frame, not the world.** The temporal upscalers run where FSR 1 does, on the finished frame (the game's effects
  and HUD drawn at the render size), so the scene target's contract is unchanged. TAA (taa.cpp) still jitters every
  scene draw and draws the objects' velocities; under a temporal upscaler (rm::upscalerTemporal; upscale.h) it does not
  resolve: where its resolve would run (the frame's first effect) it writes each pixel's screen motion (RG16F, the
  camera's through the depth, an object's own where the velocity target holds it; fs_rm_tumotion.sc) and copies the
  depth (D32F, gl_FragDepth), stops jittering, and from then on draws every scene draw (the HUD: drawn after the first
  effect, not jittered) again into an R8 mask of its coverage (vs_rm_mask_ff.sc / fs_rm_mask.sc: alpha for blended
  draws, the brightest channel for additive ones). The jitter has 8 x scale^2 Halton phases (8 to 32). The rm passes see
  the Anti-Aliasing row as TAA (rm::settings() is the effective table); the menu keeps the player's choice.
- **Temporal (ours, every platform):** fs_rm_tupscale.sc, one pass into a history of the present size (RGBA16F: colour
  and the accumulated weight), then RCAS (0.25 stops). An FSR 2-class resolve written from the published algorithm
  (FidelityFX Super Resolution 2's description), our own code: each output pixel takes the 3x3 jittered samples
  around it weighted by a narrow kernel in output pixels (exp(-2 d^2)), with that kernel's sum as the sample's weight
  (over the phases every output pixel gathers the samples that fell on it: the detail of the present size); the frame's
  own FSR 1 EASU at the jittered grid's coordinates (rm_easu.sh, the MIT port) is the prior and the fallback where the
  history is weak; the history is reprojected (Catmull-Rom) by the motion of the nearest-depth sample of the 3x3,
  clipped to the samples' YCoCg box (mean +- 1.25 sigma; a clip divides the accumulated weight by its distance
  squared), capped at 12 frames and down to 15% of that at 24 output pixels of motion a frame; the HUD mask takes the
  frame as drawn (Catmull-Rom of its unjittered samples) with no history. Knobs (development): `HULK_TU=max,gamma,
  falloff,prior`, `HULK_TU_STOPS=ours,metalfx`, `HULK_TU_SIGN`, `HULK_TU_DEBUG=1` (motion and weight as colour),
  `HULK_TU_LOG=1`.
- **MetalFX (macOS 13+):** mfx.cpp, Apple's MTLFXTemporalScaler loaded at run time (dlopen of the system framework and
  the Objective-C runtime from C++; nothing linked or vendored). bgfx keeps its command queue and buffer to itself, so
  our bgfx build has a view hook (tools/wine_gfx.py PATCHES, renderer_mtl.cpp, Metal only: `bgfx_hulk_mtl_set_view_hook`
  asks a hook at each view's start, after its blits, and hands it bgfx's command buffer with no encoder open;
  `bgfx_hulk_mtl_texture` gives a texture's MTLTexture; nothing changes while no hook is set): upscale.cpp reserves a
  view and touches it, the hook encodes the scaler there (colour: the scene target, RGBA16F or BGRA8; depth D32F;
  motion RG16F scaled by the render size; the HUD mask as its reactive mask on macOS 14.4+), and the next views put the
  HUD back (fs_rm_tucomp.sc) and run RCAS (0.5 stops: its output is a little soft). Same frame, no latency. Jitter and
  motion follow FSR 2's conventions (pixels, y down; motion = last - current); `HULK_MFX_SIGN=x,y,motion` flips them;
  `HULK_MFX=0` makes it unavailable.
- **Fallbacks.** A frame without TAA's inputs (the front end: nothing jittered) or without views takes FSR 1; MetalFX
  unavailable (an older Mac, not Metal) takes ours. The performance overlay names the upscaler the frame used (TEMPORAL /
  METALFX / FSR1 / BILINEAR / NATIVE; no AA label with a temporal one).
- **Pictures** (queue Metal, play3, 1280x960 window, Quality 67% = 858x643; build/wperf2/cmp, never committed): static
  city (5000, 7600) ours keeps more texture detail than FSR 1 (window frames, roof ribs) and matches MetalFX; the HUD is
  as sharp as drawn in both (the mask); in the fast pan at 3010 (20 output pixels a frame) MetalFX has the cleanest
  silhouettes, ours is sharper than FSR 1 with slight stair steps left on the Hulk's outline (the history cannot follow
  at that speed and EASU of the aliased frame stands in). At 3x (640x480 to 1280x960) an earlier, Lanczos-only version
  of ours showed a grid pattern and smears: the output-pixel kernel and the EASU prior fixed it.
- **Cost** (bgfx's frame GPU timer, which reads ~1.8x high; `HULK_UPSCALE_AB=N`: temporal off, i.e. TAA's resolve +
  FSR 1, and on in turns). Queue mac2 (M3 Max), play3 to 6,000, 858x643 to 1280x960, other options off: ours 0.744 ->
  0.793 ms (+0.05), MetalFX 0.606 -> 1.372 ms (+0.77). The laptop (M3 Air, quiet, once), every remastered default,
  1920x1440 window (Auto: 1280x960 to 1920x1440): MetalFX 8.24 -> 8.16 ms (no cost over TAA + FSR 1), ours 8.78 ->
  10.10 ms (+1.3). At the 1280x960 budget window Auto stays Native (TAA as before): 7.0-8.0 ms, within the 12.
- **Android.** Auto keeps FSR 1 there (rm::upscalerTemporal): temporal upscaling on Mali-class GPUs costs about what
  it saves at 720p; Temporal can still be chosen (the shaders build for spirv and essl).

### 4.3 HUD Resolution (whud1, D249)

Video Options > HUD Resolution: Render (Original) / Display (`hud_res=0|1`, rm::kHudRes = 20, remastered-only,
remastered default Display). Output only; the game still sees 640x480.

- **What is the HUD.** In play the game's frame is the world pass, its effects (a frame copy, the bloom chain into
  smaller targets, the bloom composite as a full-screen quad) and then one more scene pass that clears depth and draws
  the HUD (2D and HUD-camera draws, every one depth-tested `always` with no depth write); in the front end and the
  pause menu the menus come the same way after the frame's last effect (`HULK_RM_TRACE=1` prints a frame's sink calls
  around each screenshot request). So the HUD is the frame's **tail**: the scene draws after its last copy or effect.
- **Holding the tail** (rm_pass.cpp, `Pass::holdTail`). While a pass asks for it (run/app/hud.cpp, when the last frame
  was drawn below its present size), rm keeps the scene passes and draws after each effect (deep copies: constants,
  transient vertices, matrices, lights, combiner key) instead of sending them on. At the next copy or effect they go
  on in order through the usual path, hooks and all, as if they had just come; a pass into another target or a draw
  that is not HUD-like (a depth write under a depth test, the stencil, an occlusion query) ends holding the same way.
  What is still kept at the present is the tail. The module's destroys wait for the frame's end while draws are kept
  (interp.cpp).
- **Drawing it.** The post views now follow the game's when rm renumbers, so there is room after the upscaler. The
  upscaler reads the scene without the tail; hud.cpp (order 1010) then makes the present-size frame: the upscaler's
  output (`rm::upscaledFrame`, blitted), or with Upscaler Off the scene stretched bilinearly (fs_rm_copy.sc), and draws
  the tail over it (`rm::drawTail`: the game's passes with their viewports scaled to the present; the 2D and HUD
  projections are in clip space), and presents it. rm then draws the tail into the scene target too, after those views,
  so the scene (the front buffer the motion-trail overlay reads) ends as the game drew it. The TAA HUD mask of the
  temporal upscalers is left with what came between effects; the tail is no longer in their input.
- **Unchanged:** at the render size (Native at window size: no hold), with the row off, and in faithful. The overlays
  (movie ring / pad banner slot 0, performance overlay slot 1, menu arrows slot 2) are drawn by the sink at the present
  in window pixels, as before. 30/60/120 fps: interp.cpp replays each update's stream through the same rm calls, so
  every presented frame holds its own tail.
- **The f39000 missing HUD** (all remastered settings with renumbering, not only this row): the game's pass ids follow
  on from the previous frame's last id, so a frame's first pass (set before the world, never drawn into) carries the id
  the HUD pass takes when the frame has one more effect pass than the one before (an explosion's extra filter pass).
  rm's renumbering mapped the HUD's draws to that first view, before the world, whose clear wiped them: a one-frame
  HUD dropout at the start of each such effect. A game pass set again after others, whose view had no work yet this
  frame, now takes a new view in order (`forgetIdle`).
- `HULK_HUD_RES=0|1|2` (development: 2 also at the render size), `HULK_HUD_LOG=1`, `HULK_HUD_AB=N` (cost turns).

## 5. TAA (Anti-Aliasing: TAA)

The Anti-Aliasing row (msaa) gains a value: TAA (1), next to Off, MSAA 2x / 4x / 8x; run/app/taa.cpp, order 20.

- **Jitter.** Each presented frame takes the next of 8 Halton (2, 3) sub-pixel offsets, added to the clip-space x / y
  rows of every scene draw's vertex constants (`late`, so the passes that redraw the world, reflections' G-buffer, the
  shadows' casters and ambient occlusion's projection, see the same jitter): `row_x += jx row_w` in each vertex
  program's layout (fixed function c4.., the skin programs c98.., the refraction programs' four clip rows). Only from
  the world's first room draw on: the sky dome before it and frames without a world (the front end) are untouched.
- **Motion.** The camera's: each pixel's camera-space position (the scene's depth and the world projection without
  jitter) taken to the last presented frame's clip space by `P' V' V^-1` (the views from the frames' first room draws).
  The objects' own: every opaque buffer draw that is not a room (characters, cars, props; ~40-90 a frame in the city) is
  drawn again into a velocity target (RGBA16F + depth) with this frame's constants and the last frame's constants of the
  same draw (matched by buffers, count, program and first texture, the nearest origin in camera space within 3 units):
  per vertex, so the Hulk's limbs carry their own motion (vs_rm_vel.sh: fixed function, three-bone and one-bone skins).
  The resolve uses an object's vector where its depth agrees with the scene's (it is what the pixel shows).
- **Resolve** (fs_rm_taa.sc) at the frame's first effect (where HDR tone maps, before it; at the frame's end when
  there is none): 3x3 neighbourhood moments in YCoCg, the nearest depth of the 3x3 (edges reproject with the
  foreground), the history by a 5-tap Catmull-Rom, clipped to mean +- 1.25 sigma, blended at 10% (up to 35% with fast
  motion) with 1 / (1 + luma) weights (the scene is half float: no flicker from bright pixels); off-screen history and
  camera cuts (the view turning more than ~25 degrees in a frame) start from the current frame. Written back with a
  light, range-clamped sharpen (fs_rm_taasharp.sc, 0.35). `HULK_TAA=alpha,gamma,sharpen`, `HULK_TAA_MOTION=0` (camera
  only), `HULK_TAA_LOG=1`, `HULK_TAA_AB=N` (cost turns).
- **60 / 120 fps.** Interpolated frames are presented frames like any other (interp.cpp replays them through rm): each
  takes the next jitter phase and reprojects from the frame shown before it with the interpolated constants, so the
  history is per presented frame (checked: play3 at 60, consecutive interpolated and recorded frames at 14,998-14,999).
- **With an upscaler.** TAA resolves at the render size; FSR 1 then upscales the anti-aliased frame (the usual
  TAA + spatial pairing until temporal upscaling lands, 4.2).
- **Single-sampled.** With TAA the scene has no MSAA, which is most of its saving: every full-screen runner pass (AO's
  apply, SSR's composite, the atmosphere, HDR's tone map) writes one sample per pixel instead of four, and the view
  splits between the game's passes no longer resolve and reload a 4x half-float target.

### 5.1 Cost and quality

- Cost: +0.9 ms against no anti-aliasing (+1.35 on the A/B GPU timer), against MSAA 4x's +4.3 ms: the scene is
  single-sampled, so every other pass gets cheaper too. The velocity draws add ~40-90 object draws a frame (0.1 ms of
  CPU in the hooks).
- Quality (build/wperf1/png, never committed; cmpt3-15000.png: MSAA 4x / TAA camera-only / TAA with object motion): the
  city's long edges, window frames and the wet street's reflections are smoother than MSAA 4x (which leaves the shader
  aliasing of the per-pixel lighting, the SSR and the texture detail alone); the picture is slightly softer at rest
  (the sharpen keeps most of it). With object motion the Hulk stays sharp while running; the camera-only version
  smeared him (the history clip held most of it). At 60 fps the interpolated frames show the same stability
  (taa60-*.png). Not yet handled: transparent effects (particles, glows) have no motion of their own and can trail
  slightly in fast pans; the grass blades (wgrass1, drawn by the runner) are not jittered.
- **Verdict**: TAA replaces MSAA 4x as the remastered default (it wins clearly on cost, and on quality everywhere but
  a slight softness); MSAA 2x / 4x / 8x stay in the row.

## 6. bgfx's render thread (P1)

Assessed, not enabled. The app links bgfx with `BGFX_CONFIG_MULTITHREADED=0` (tools/wasm_port.py BGFX_DEFS): the
module's update, the runner's passes and bgfx's Metal encoding share the main thread, and `bgfx::frame` does the
encoding. With bgfx's render thread, encoding of frame N would overlap the module's update of frame N+1.

- **Gain.** On the remastered defaults the frame is GPU-bound on the M3 Air (section 2): a render thread does not
  shorten the GPU's work. At the Performance settings, where the GPU time falls under the CPU's, it would hide most of
  `bgfx::frame`'s share of the CPU (section 2's split) and is worth a measured try then.
- **Cost and risk.** On macOS bgfx's render thread must be the main thread (Cocoa / CAMetalLayer), so the module (the
  game, its Asyncify scheduler, the SDL event pump's callers) would move to a second thread: the pad thread's lock rules
  (wpad1), the movie and audio callbacks, `bgfx::getStats` / screenshot / readback users in the runner, and every pass
  that creates or updates bgfx resources mid-frame (frame copies, the night lights' texture, packs) would need review.
  Occlusion query results already arrive a frame late on Metal and the game handles pending results, but their timing
  would shift again. Not clearly beneficial at today's GPU-bound defaults and not safe without that review: left off;
  revisit with the Performance preset's CPU numbers.

## 7. The performance overlay (Video Options > Performance Overlay: Off / FPS / Graph)

`perf_overlay` (rm::kPerfOverlay = 19; both editions, default Off), run/app/perfov.cpp, the last rm pass:

- **FPS**: a corner readout: presented frames a second and the frame time (averaged over the last second), the render
  size, its share of the present size, the upscaler (Native / FSR1 / bilinear) and the anti-aliasing.
- **Graph** adds the last 240 presented frames' times as bars (green to 8.3 ms, yellow to 16.7, orange to 33.3, red
  beyond; lines at 8.3 and 16.7 ms, 0-33 ms tall), the 1% low (the 99th percentile frame time as a rate) and, below, the
  CPU per frame stacked (blue: the module's update with its own draws; violet: interp's replays at 60 / 120 fps; cyan:
  bgfx::frame, Metal encoding plus any wait for the GPU) with bgfx's GPU timer as white dots (an overlapping timer:
  section 1), and their averages in the legend in the same colours.
- Drawn from the runner: a small B, G, R, A image (a 3x5 pixel font, doubled on windows 900 pixels tall or more) made
  every second presented frame and drawn by the sink over the presented frame in a second overlay slot
  (bgfx_sink.cpp `hulk_gfx_sink_overlay_slot`: slot 0 stays the movie ring and the controller banner, which movie.c
  arbitrates; slot 1 is the overlay, drawn after). Its times come from hooks in interp_pace, drawStream and
  gs_sink_frame that are one flag test when it is off. Nothing reads or writes the module's memory.
- Screenshots: build/wperf1/png/overlay-graph-60fps.png, overlay-fps.png (queue Metal tests 111847 / 111848, never
  committed).

## 8. Licences

| component | licence | how it is used |
|---|---|---|
| FSR 1 EASU / RCAS (AMD FidelityFX Super Resolution 1.0, ffx_fsr1.h) | MIT, (c) 2021 Advanced Micro Devices | ported to bgfx's shader language in fs_rm_easu.sc / fs_rm_rcas.sc, the MIT notice in each |
| FSR 2 / 3 (AMD FidelityFX SDK) | MIT | not used or vendored: our temporal upscaler (fs_rm_tupscale.sc) is written from the published algorithm description; no FidelityFX source in the tree (were it vendored, its MIT licence file goes with it) |
| FSR 1 EASU as a function (rm_easu.sh) | MIT, (c) 2021 Advanced Micro Devices | the same port as fs_rm_easu.sc, the MIT notice in the file |
| MetalFX | Apple system framework (macOS 13+) | loaded at run time (dlopen + the Objective-C runtime, mfx.cpp); nothing linked or vendored |
| TAA, motion vectors, Catmull-Rom history | the runner's own code | general techniques (jittered temporal supersampling, YCoCg variance clipping, 5-tap bicubic); no third-party code |
| bgfx / bx / bimg | BSD-2-Clause | two small patches (tools/wine_gfx.py PATCHES, wperf2): the Metal view hook (4.2) and the Vulkan swapchain's image count (the Linux and Android apps); the licence unchanged |

## 9. Checks

- Game state: play3 to 60,000 with `null` against a control of HEAD on the same host, every option of this lane pinned
  on (TAA, Upscaler FSR 1 / Auto, Render Scale 50% or Auto, the overlay's graph) with every remastered option: records
  identical (tests 111779, 111782 for the upscaler and TAA; 111846 for the defaults, Auto scale, shadow culling and the
  overlay; candidate 111845 against control 111841 at 09082935d). Metal on the laptop: play3 to 15,100 with MSAA 4x,
  TAA (camera only, with object motion, at 60 fps) and FSR 1 at 50% gave the same checkpoint records.
- Pictures: queue Metal tests 111837-111840 (TAA + Reflections Low, MSAA 4x + High, TAA + High; FSR 67% to 1920x1440)
  and the laptop's runs; build/wperf1/png, never committed.
- Android: the runner's new files compile with the NDK (API 31); the shaders build for spirv and essl.
- wperf2 (temporal upscaling): play3:2000 null, candidate 111990 against control 111989 (5c5e1a2d6): records
  identical; Metal play3 to 2,000 with Temporal pinned, pair 111992: records identical. Pictures: queue Metal runs
  111948 (FSR 1), 111960 (MetalFX), 111984 / 111990 (ours / Auto = MetalFX), 111993 (ours at 60 fps). Linux: the
  Z2 Extreme (Vulkan, RADV) under headless gamescope with Khronos validation, every remastered default with MSAA 2x
  (Auto: FSR 1) and with Temporal: no validation message after the swapchain fix; shots at 6,000 / 12,000 / 16,000
  (HUD, minimap, enemies) right. bgfx's GPU timers are off in the Linux build and presents are paced at 60 Hz there,
  so the device gave no cost numbers. Android: the runner's files compile with the NDK; the shaders build for spirv
  and essl.

## 10. Open items

- Temporal upscaling (4.2): ours could reject history by depth (disocclusion) and lock thin features as FSR 2 does;
  drawing the HUD at the present size would need the scene-target split (4, "Spatial first"). MetalFX spatial was not
  added (EASU costs about the same).
- Shadows High's cost is the fill of the two 2048 rows: cache the world row (static rooms; redraw when its snapped
  centre moves by a coarse step) or draw it at 1024, with per-row receiver matrices in fs_px_stage.sh.
- Reflections' G-buffer redraw (~300 draws): the scene's depth plus reconstructed normals could replace most of it,
  but the per-draw reflectance class needs a channel the game's own shaders do not write (MRT is not available: the
  pddi shaders are the faithful ones).
- AO's apply under MSAA is moot with TAA (+0.7 timer, < 0.3 ms); a 2x2 bilateral upsample would trim it further.
- Dynamic resolution (Render Scale following the frame time) is not done: Auto's pixel cap holds the budget at any
  window size on the Air.
- Measure on a quiet laptop again: AO and Reflections High off-runs were contaminated by another lane's run.
