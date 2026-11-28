# HDR, ambient occlusion and sun shadows (the app's HDR, Ambient Occlusion and Shadows options)

wr3a, 2026-11-23: the first slice of R3 (docs/remaster.md section 6) for the remastered edition of the wasm app (user,
11-23: "sun shadows, ambient occlusion and HDR with tone mapping, the game's bloom re-hosted on top"). Three Video
Options rows (port_settings.c; faithful value off, remastered-only), each an rm pass of the runner
(run/app/hdr.cpp, ao.cpp, shadows.cpp; rm_pass.h). Output only: nothing that draws reads or writes the module's memory,
so the game state and play3's checkpoint records are the same with any setting, and the faithful edition draws exactly
as before (with all three off the game's pass ids reach the sink unchanged and no view of the runner's runs).

| row | values (faithful first) | remastered default |
|---|---|---|
| `hdr` HDR | Off (Original), On | On |
| `ao` Ambient Occlusion | Off (Original), On | On |
| `shadows` Shadows | Original, Low, High | High |

## Views between the game's passes (rm_pass.h)

The three passes draw *inside* the game's frame: tone mapping before the game's effects, occlusion between the world's
opaque and translucent draws, shadow maps before the scene. bgfx runs views in id order and the game numbers its
passes 0..250 as it goes, so while a pass asks for it (`Pass::midFrame`) the runner renumbers the game's passes in
submission order, with its own views among them:
- `rm::newView()`: a view that runs after everything so far and before the game's next pass;
- `rm::viewsBefore(gamePass, n)` / `rm::viewsHere(n)`: n views before the rest of a game pass; when the pass has already
  drawn, it goes on in a new view (same target and viewport, no clear: `rm::splitPass`), so the runner's views run
  between its draws so far and the rest;
- every sink call that names a pass goes through rm (`setPass`, `submitDraw`, and now `copyFrame` and `fxDraw`, which
  app.cpp and interp.cpp used to hand the sink directly); passes see the sink's view in a packet's `pass` and the game's
  pass id from `rm::currentGamePass()` (stable across a split; the lighting pass's world-pass test uses it);
- new hooks: `passSet` (every pass), `copy` and `fx` (the game's frame copies and effect quads, before the sink).
With no pass asking, the ids are the game's (the faithful path is untouched). If the game ever used all 251 views the
runner's passes skip that frame.

The sink's part is app-only (bgfx_sink.cpp under HULK_SINK_OVERLAY: `hulk_gfx_sink_targets(hdr, depthRead)`,
`hulk_gfx_sink_scene_hdr()`); the 15 pddi units compile byte-identical with the Wine build's i686 flags (D194).
Helpers for full-screen passes are run/app/rm_post.h (programs, targets, views, quads); shaders are in run/app/shaders
(`fs_rm_*`, `vs_rm_*`), compiled by tools/rm_shaders.py like the lighting pass's.

## HDR (hdr.cpp)

- **The scene in half floats.** The scene target is RGBA16F (the sink makes it again between frames, like MSAA; it
  stays 8-bit where the renderer can't draw, blit or multisample RGBA16F), and so are the frame copies, which the game's
  effects and refraction blit from it (one format for blits; a copy made before the change is skipped until it is made
  again). Additive light (glows, sparks, the health orbs, explosions) now sums past 1 instead of clipping per draw.
- **Tone mapping before the game's effects.** At the frame's first effect copy or quad (the game's colour pass and
  bloom, extension slots 6 and 9; a copy into the display's refraction copy is mid-scene and does not count) the runner
  maps the scene back into the displayable range in views of its own: the scene is blitted to a copy, the light above 1
  is averaged into a quarter-size target and blurred (two 9-tap passes), and fs_rm_tonemap.sc writes scene + glow back:
  below the knee (0.8) the picture is the game's; above it, the brightest channel rolls off towards 1 (hue kept) and
  light far above 1 turns towards white.
- **The game's bloom re-hosted on top.** The colour pass, the bloom (copy, bright pass, gaussian, composite), the overlay
  (motion trail: the previous presented frame), the fader and the HUD then run exactly as before, on the tone-mapped
  frame, so they look as they always did; the extra glow is only the light the 8-bit target used to clip. A frame with
  no effects (the front end) is not tone mapped; nothing in it exceeds 1.
- What the player sees: overbright effects keep their colour and gain a soft glow instead of flat white cores (the
  health orbs stay green at the centre); the rest of the picture is unchanged (in play3's city and tutorial frames,
  0.15-0.3% of the pixels differ by more than 2/255, all around glows).
- `HULK_HDR=knee,glow,threshold` tunes (0.8, 0.35, 1.0); `HULK_HDR_LOG=1`; `HULK_HDR_AB=N` (cost turns).

## Ambient occlusion (ao.cpp)

- **Where.** In the world's pass, once its opaque room draws have started, at the first draw that is blended without
  depth writes, stencil-tested or 2D (the game draws its translucent effects, decals, particles and the stencil-shadow
  quad after the opaque traversal), or else at the frame's first effect: the world and the objects drawn so far get the
  occlusion; sky (far depth), particles, glows, translucent draws, characters drawn after the split (skinned draws come
  after the shadow quad in play3) and the HUD do not.
- **How.** The scene's depth is sampled (the sink drops BGFX_TEXTURE_RT_WRITE_ONLY from it while this is on; under MSAA
  bgfx resolves it at the end of the view) with the world pass's projection (c4..c7 of a room draw: the sky has its own
  near and far): view-space positions, normals from the nearer neighbours, a 12-sample Alchemy-style obscurance estimate
  in a disc of 3 world units at half size (fs_rm_ao.sc), then a 4x4 depth-weighted blur multiplied into the scene's
  colour (fs_rm_aoapply.sc, a frame buffer of the scene's colour alone, since the depth is read). It fades out between
  150 and 300 units. The spiral's rotation per pixel is a 4x4 Bayer matrix (wlook3; it was interleaved gradient
  noise): the apply's 4x4 blur takes each of the 16 rotations once, so the estimate's noise cancels instead of
  reading as grain, which nothing resolved without TAA. The grass blades are drawn after the apply (docs/grass.md),
  and after its submits the lighting pass's samplers are bound again for the draw the hooks are handing over
  (`rm::lightingRebind`: the occlusion's quads took them, an unbound descriptor on Vulkan, wlinux2).
- What the player sees: contact darkening where walls meet streets, in window recesses and doorways, under cars, props
  and vegetation; moderate, so it does not double the baked occlusion in the vertex colours.
- **Banding** (wlook1): the desert ground's horizontal stripes under the remastered defaults (docs/look.md section 1,
  first taken for shadow acne) were the occlusion's: the 24-bit depth's terraces on ground seen at a grazing angle
  tilted the one-texel normal row by row, and the samples read the tilt as occlusion. The normal now takes a two-texel
  baseline and a sample must rise ~4 degrees above the surface's plane (an angle bias of 0.07 x its distance) to
  occlude: flat ground and walls stay open, corners, steps and contacts keep their darkening.
- `HULK_AO=radius,strength,fade0,fade1` (3, 1.5, 150, 300); `HULK_AO_SHOW=1|2|3|4` shows the occlusion, the view depth,
  the raw depth or the half-size output; `HULK_AO_LOG=1`; `HULK_AO_AB=N`.

## Sun shadows (shadows.cpp)

- **The sun.** The key light of the game's lit draws (the strongest directional light, camera space, into world space by
  the frame's view; smoothed): in play3's desert and city it is the same world direction in every frame whatever the
  camera, (-0.58, -0.81, 0.07) (the light rig is the location's, not the camera's). A light from below the horizon is
  ignored; `HULK_SUN=x,y,z` fixes one.
- **The map.** A D16 atlas, two rows of cascades: Low one 1024 square to 60 units, High two 2048 squares, to 30 and
  150 units (a 4096x4096 atlas). Each cascade is a sphere around its slice of the view, its radius fixed by the field of
  view and its centre snapped to texels (no shimmering as the camera moves). The views are taken at the frame's first
  scene pass, before the world (rm::newView).
- **Casters.** Every opaque draw of the world pass (fixed function, two-sided, skin, onebone; not transient, not
  blended, not stencil, no query) is drawn again into the atlas as it reaches the sink, once per cascade, with the
  faithful vertex transform and the sun's view (vs_rm_cast_*.sc: vs_px_ff.sh / vs_px_skin.sh under PX_CAST), alpha-tested
  holes kept (fs_rm_cast.sc). Rooms (unlit world shaders, `simple`, `layered` or `layeredReflect`, whose modelview is
  the view itself) go to the world row, the rest (characters, props, cars) to the first row. play3's city: 90-190
  casters a frame, 25-45 of them rooms. (wlook1: `simple` rooms, the desert's ground and the tutorial's buildings, were
  counted as objects until then: they cast into the first row and took it, shadowing themselves; `rm::shadowWorldDraw`
  is the one test, shared with the lighting pass's receivers.)
- **Receivers.** The lighting pass's per-pixel programs (fs_px_stage.sh pxShadow: normal offset, depth bias, 2x2
  compare taps; wlook1: each cascade's own bias from its texel size, scaled by the slope to the sun: a normal offset of
  texel x (0.6 + 1.4 sin) and a depth bias of texel x (0.35 + 0.6 tan), tan capped at 4, so the far cascade's ~5x
  larger texels no longer streak walls at 30-150 units while the near cascade's bias stays a few centimetres and the
  Hulk's contact shadow stays on his feet; `HULK_SHADOW_BIAS=n0,n1,b0,b1` in texels): with Shadows on, every opaque draw of the world pass takes a per-pixel program (as with Lighting:
  Per-Pixel). The baked world takes only the first row (it already holds its own shadows; world-on-world shadows would
  double them), darkened by 45% where it faces the sun; characters and objects take both rows on their key light (85%).
- **The game's own shadow.** Its stencil volumes' darkening quad (a stencil-tested, blended 2D draw in the world pass) is
  hidden; the volumes write only stencil.
- What the player sees: the Hulk, cars, people, props, lamp posts and the bunkers cast sharp-edged, soft-filtered sun
  shadows on the streets, walls and each other, and buildings shadow the characters; the old stencil blob is gone.
- `HULK_SHADOW=baked,key,far0,far1` (0.45, 0.85, 30, 150); `HULK_SHADOW_LOG=1` (casters a frame, the sun);
  `HULK_SHADOW_AB=N`.

## Contact shadows and bounce light (contact.cpp)

wshadow1, 2026-11-27 (the user's visual pick #3): objects and characters sit on the ground instead of floating. Two
Video Options rows, both remastered-only, faithful Off, remastered default On, each borrowing `hdr`'s choice strings
(fe_options.c k_borrow: no new choice strings, two labels): `contact` Contact Shadows (rm::kContact = 23) and `bounce`
Bounce Light (rm::kBounce = 24). One rm pass draws both (run/app/contact.cpp; shaders fs_rm_contact.sc,
fs_rm_contactapply.sc); either row on keeps the scene's depth readable (rm_pass.cpp's QualityPass).

- **Where.** In the world's pass, once the characters are in the depth and before the translucent effects, in two views
  of the runner's own (rm::viewsHere; the draw being handed over gets the lighting pass's samplers again,
  `rm::lightingRebind`). play3's world pass draws: opaque rooms and objects (some characters among them), ~80
  translucent decals, the stencil shadow volumes and their quad, the skinned characters (the Hulk), then props and
  translucent effects mixed, then the particles. The terms run at the first translucent or 2D draw after a skinned
  draw that follows the stencil quad; a frame without them (no characters) takes them at its first effect, like HDR.
  Applied at the first effect (the first version), the darkening went over the smoke (a drain pipe's contact line
  through a cloud) and dimmed the Sonic Clap's ground glow and a shock wave, with speckle: translucent draws must come
  after. Props drawn after the characters neither cast nor receive (those after the trigger are not in the depth yet).
- **Contact shadows.** At half size, from each pixel (normal from the depth, as the occlusion's) a ray of 0.8 units
  towards the key light (the sun: the strongest directional light of the world pass's lit draws through the inverse
  view, smoothed in world space, as shadows.cpp takes it, but computed here so it works with Shadows off) in 12 steps,
  each projected and compared with the depth: a surface 0.01 + 0.0015 z to 1 unit in front of the ray point occludes
  (1 - 0.6 t at its step t). Strength 0.6, weighted by the surface's slope to the sun and by the key light's brightness
  (play3: 0.66 by day, ~0.5 at night), faded out from 60 to 100 units. It shades the Hulk's feet and shins on the
  street, a slab he holds onto his hips and legs, tank fronts and their contact with the road, the drain pipe on its wall.
- **Bounce light.** In the same shader: 8 samples of the scene's colour (sampled directly: the world view's draws so far
  are resolved when its split ends) in a disc of 2.5 units, weighted by the receiver's cosine to each sample and its
  distance, sky excluded, strength 1.2. It is applied as a tint, destination x (1 + bounce): one bounce of the lit
  surroundings, so dark stays dark and nothing glows (the sunlit ground up onto the Hulk's legs and car sides, the Hulk's
  green onto the ground beside him).
- **Noise and stability.** Ray offsets and the bounce's rotation come from a 4x4 Bayer matrix per half-size pixel; the
  apply's 4x4 depth-weighted blur (each half-size texel's depth read where the terms read it) takes each of the 16 once,
  so the estimate's noise cancels without TAA (wlook3). Nothing is kept between frames. Aligned frame pairs (wwin3's
  flick.py) without TAA (MSAA 4x): the same flicker with both rows on as off (pixels changing by more than 12/255:
  7000 6.11% / 6.08%, 36000 13.20 / 13.13, 54000 14.26 / 14.16; 42000's shock wave 68.9 both).
- `HULK_CONTACT=len,thick,strength,bounce,radius,fade0,fade1` (0.8, 1, 0.6, 1.2, 2.5, 60, 100); `HULK_CONTACT_SHOW=1|2`
  shows the visibility or the bounce (development: later passes still tone map it); `HULK_CONTACT_LOG=1` (frames run,
  how many at the first effect, the sun and the key light); `HULK_CONTACT_AB=N`; `HULK_SUN=x,y,z` fixes the sun as for
  the shadows.
- **Cost.** metal-ab (studio, play3 from boot to 25,000, 1280x960, every remastered default on with TAA, both rows on,
  `HULK_CONTACT_AB=30`, ~11,300 frames a side): GPU 1.75 -> 2.02 ms (+0.27 by bgfx's timer, which reads ~1.8x high:
  ~0.15 ms), render thread +0.015 ms.
- **Linux / Vulkan.** Every sampler the two programs declare is bound for every quad (s_rmTex0 the depth, s_rmTex1 the
  scene's colour or the half-size terms); after the terms run mid-pass the handed-over draw's samplers are bound again
  (`rm::lightingRebind`, wlinux2). New handles: one RGBA16F half-size target (texture + frame buffer) and one frame
  buffer over the scene's colour (remade when the scene target is), no vertex or index buffers. The shaders build for
  metal, spirv and essl. Not run on a Linux device yet: check with Khronos validation on a city scene with HUD, cars and
  enemies.

## Lens effects (lens.cpp)

wlens1, 2026-11-28 (the user's visual pick #9, D249): five Video Options rows, all remastered-only, faithful Off, each
borrowing `hdr`'s choice strings (fe_options.c k_borrow: five labels, no choice strings): `dof` Cutscene Depth of Field
(rm::kDof = 26, remastered On), `lens_flare` Lens Flare (kLensFlare = 27, On), `vignette` Vignette (kVignette = 28,
Off: Colour Grade Cinematic already has a soft one), `aberration` Chromatic Aberration (kAberration = 29, On: impacts
only), `grain` Film Grain (kGrain = 30, Off). One rm pass draws them (run/app/lens.cpp; shaders fs_rm_lens.sc,
fs_rm_lensmul.sc, fs_rm_dfocus.sc, fs_rm_dprep.sc, fs_rm_dgather.sc, fs_rm_fbright.sc, fs_rm_fghost.sc, with
fs_rm_blur.sc); Depth of Field or Lens Flare on keeps the scene's depth readable (QualityPass).

- **Where.** In views of the runner's own before the game's first framebuffer effect (its bloom and colour pass;
  rm::viewsBefore at the same copy / effect hook as HDR, after HDR's tone map and the grade, order 32). The game's
  bloom, motion-trail overlay, fader and the whole HUD (menus, subtitles, the letterbox bars) come after, so the HUD is
  never touched by any of them; a frame without effects (the front end) gets none. Vignette and grain alone are one
  multiply quad (blend dst x src x 2); anything else blits the scene into a copy and writes one composite back.
- **What the module tells the runner.** gfx/lens.c hands a packed word to the runner at each present (gfx_quality what
  0x101, like the menu arrows' 0x100; picture only, nothing written): bit 0 the letterbox (nism_IsLetterBoxOn's test,
  as wskip1's "in play"), bit 1 a scripted camera, bit 2 no controller slot, and the camera's shake: an entry hook on
  CGameCamera::vfunc_35 0x000a97e0 (every caller is a derived camera's update in another TU) reads the six shakes at
  +0xf4 (time, duration, amplitude, frequency; offset = sin(t f) e^-t amplitude) after the original. Under the null
  renderer the module's d3d layer is d3d_null and the word is not sent (records and `HULK_LENS_LOG` letterbox lines
  need a Metal run).
- **Cutscenes.** The depth of field runs only while the letterbox is up (and no movie plays), easing in and out over 12
  updates. play3 has 31 letterboxed spans (75 to 876 updates: mission intros and objective cut-ins; frames 634, 3318,
  4064, 4883, 6209, 7521, ... 54959); the scripted camera and the controller slot change within them and are not used.
- **Depth of field.** The focus (1x1 RGBA16F, ping-pong): the main actor when he is in the shot (gfx/lens.c hands his
  scene node's position over as what 0x102..0x104 while the letterbox is up; his chest, 1.4 units up, projected within
  the frame's middle 88% x 85%) and the depth there is not nearer than 0.75x his distance; else 25 depth taps over the
  frame's upper middle (x 0.32..0.68, y 0.24..0.64), the nearest cluster (within 1.6x the nearest + 0.5) averaged in
  log depth, centre-weighted, capped at 400 units. Eased 18% a frame from the last focus (a new cutscene takes it at
  once). The circle of confusion is a thin lens's, `sign(z - f) clamp((8 |1/f - 1/z| - 0.1) x 1.25, 0, 1)`: a close-up
  (focus at a few units) blurs its background, a wide or aerial shot stays sharp. The first version used the relative
  defocus |z - f| / z, scale-free, and play3's aerial intro shots (3450, 6300) and the city overviews (29000, 49800)
  took a tilt-shift miniature look with the wrong things in focus. Half size: colour and the signed circle (the nearest
  of the four depths), then a 36-tap golden-angle gather out to 4 half-size pixels at 480 lines (scaled with the
  height: 16 px at 960): a tap counts where its own circle covers the distance, a tap behind the pixel only out to
  twice the pixel's own circle (a sharp subject keeps its edge), taps brighter than 0.7 weigh up to 1.75x (bokeh). The
  composite blends towards the gather by the pixel's own circle or the foreground's that spilled over it. The game
  draws the letterbox bars before its effects (they are in the scene, not the HUD's tail): rows black across the copy
  (5 taps) are bars, in focus for the gather and left as drawn by the composite (blurred, the bars' edges went soft).
  Translucent effects write no depth and blur with what is behind them (a shock wave around a sharp Hulk).
- **Lens flare.** Quarter size. Strong small lights: a bright pass of texels over 0.82 and 0.25 brighter than a ring of
  8 taps at 6 quarter-size texels (a bright sky or a sunlit wall gives nothing), mirrored through the centre at four
  scales with tints and a slight colour split, plus a halo; the sun: the key light's direction (the strongest
  directional light of the lit draws through the inverse view, as the shadows and the atmosphere's sun glow take it)
  projected, by day (night estimate < 0.6, fading from 0.2), above the horizon and within 15% of the screen; its
  visibility is the share of 9 depth taps around it that are sky (view depth > 600), its strength x0.35 .. 1 by the
  scene's brightness there; a glow, a faint horizontal streak and five tinted ghosts along the line through the
  centre. Blurred (fs_rm_blur.sc x and y) and added.
- **Chromatic aberration.** Red and blue sampled 1.1% x d x edge apart (edge: 0 inside 30% of the half-diagonal, 1 at
  the corners), only while the camera shakes: play3's shakes are 0.1 .. 0.6 units of translation (none of rotation),
  a quarter second each (the footsteps and hits 0.1 .. 0.3, heavy landings, throws and explosions 0.4 .. 0.6); the
  strength is (amplitude / 0.6 - 0.4) / 0.6, decaying 18% an update.
- **Vignette** 32% darker at the corners, smoothstep from 35% of the half-diagonal. **Grain** two octaves of hash noise
  (a pixel's and a 2x2 cell's), new each presented frame, weighted to the mid-tones (7% at mid grey). Under a temporal
  upscaler the grain goes in before the accumulation and is partly averaged out.
- Knobs: `HULK_LENS_LOG=1` (the letterbox and each update's shake from the module, the pass's runs every 300 frames;
  2: the impact each update), `HULK_LENS_AB=N`, `HULK_LENS_FORCE=1` (the depth of field always) / `2` (the aberration
  at full strength) / `3` (both), `HULK_LENS_DOF=band,aperture,maxR` (0.1, 8, 4), `HULK_LENS_FLARE=sun,ghosts,halo,threshold`,
  `HULK_LENS_FX=vignette,aberration,grain`, `HULK_LENS_SHAKE=units,degrees`.
- **Checks.** Records: play3 to 60,000 with `null` and every lens row on (all remastered defaults pinned), candidate
  112354 against HEAD control 112353 on studio: identical (test 112355; under `null` the lens word is not sent, so
  this checks the hook and the rows). Metal, all remastered defaults pinned (build/wsweep1/settings.txt), 1280x960,
  aspect 43, against the same control: records identical in 112360 (to 56,000), 112363 (55,100, vignette and grain on
  too), 112370 (55,000) and 112375 (the final build 112373, to 56,000, mac2). Gameplay shots (4400, 4600, 5500, 5700,
  5800, 7000, 25000) differ only by the flare's ghosts and grain where on; cutscene shots: the aerial intro and city
  overviews stay sharp, close-ups (12800, 12900, 22700, 49700) blur foreground and background around the subject
  (49700: the Hulk in focus by his position). The sun flare draws only where the sky is clear at the key light's
  direction by day: play3's desert keeps it behind the canyon walls, so it shows on few frames (44 .. 119 of 300 in
  4,200 .. 6,000, at the screen's edge). `HULK_LENS_FORCE=2` (112371) shows the aberration at full strength: fringes of
  ~7 px at the corners of 1280x960, none in the middle and none on the HUD.
- **Cost** (metal-ab, studio, play3 to 25,000, 1280x960, all remastered defaults with TAA, `HULK_LENS_AB=30`, 11,340
  frames a side): the defaults (flare every frame, aberration on impacts, depth of field in cutscenes) 1.942 -> 2.100
  ms (+0.16 by bgfx's timer, which reads ~1.8x high: ~0.09 ms), render thread +0.04 ms (112376); with the depth of
  field forced on every frame (`HULK_LENS_FORCE=1`) 1.960 -> 2.209 ms (+0.25, ~0.14 ms) (112377).
- **Linux / Vulkan.** Every sampler each program declares is bound for every quad: the composite binds s_rmTex0..4 (the
  copy where the gather, depth, focus or flare is not used this frame), the focus 0..1, the half-size preparation 0..2,
  the gather and the blur 0, the bright pass 0, the ghosts 0..2 (the copy for the depth when there is no camera), the
  multiply quad none. New handles: 7 textures (the scene copy; two 1x1 focus targets; two half-size and two
  quarter-size RGBA16F targets) and their 6 frame buffers plus one over the scene's colour (remade with the scene
  target); no vertex or index buffers (transient quads). The depth of field and the flare need RGBA16F render targets
  (rm::hdrSupported; else they are off). The shaders build for metal, spirv and essl; not run on a Linux device yet:
  check with Khronos validation on a city scene with HUD, cars and enemies, and a cutscene.

## Checks and cost

- Game state: checkpoint records identical with every setting: play3 on Metal to 34,100 with each option off and on and
  all together (laptop); the scripted 8,000-frame HULK_INPUT run on Metal, all three on vs off, records identical
  (laptop, the queue build 111632); play3 to 60,000 with `null`, candidate 111632 against control 111631 (HEAD
  0aa3189fd) on studio: records identical, target reached (test 111633); HULK_ROLLTEST 6500:7600 on Metal with all three
  on, MSAA 4x and per-pixel lighting: identical after the restore (test 111634). `tools/wasm_android.py build` links
  libmain.so (the shaders build for spirv and essl). The 15 pddi units compile byte-identical for the Wine build (D194).
- Cost: see the table below (play3's city, frames 19,000-25,000, Metal, render 1280x960, MSAA 4x and every other
  remastered option on; each pass off and on in turns of 30 frames within one run; a laptop under other lanes' load, so
  the numbers are upper bounds).

| option | GPU a frame, off -> on | render thread |
|---|---|---|
| HDR (its views; the half-float scene stays) | 10.40 -> 11.62 ms (+1.2) | +0.06 ms |
| Ambient Occlusion | 9.07 -> 11.39 ms (+2.3) | +0.06 ms |
| Shadows High (2 x 2048, ~150 casters x 2) | 9.51 -> 11.45 ms (+1.9) | +0.22 ms |
| Shadows Low (1 x 1024) | 9.34 -> 9.79 ms (+0.45) | +0.10 ms |

Averages over ~11,300 frames per side (`HULK_HDR_AB` / `HULK_AO_AB` / `HULK_SHADOW_AB=30`, play3 from boot to 25,000,
unpaced). The occlusion's cost is mostly its full-size apply into the 4x multisampled half-float target; at 1x and
without MSAA every pass costs a fraction of this.

## Not done yet

- The lighting pass's Per-Vertex setting is overridden for opaque draws while Shadows are on (they take the per-pixel
  model); a per-vertex receiver would need its own programs.
- Shadows only in the world's pass (not the HUD's models or the far field); transient (prim stream) draws neither cast
  nor receive.
- OpenGL (origin bottom-left) is handled in the shadow and quad maths but untested; Android Vulkan builds the shaders
  (spirv, essl) and has not run on a device.
- Night locations: the key light is the moon's or a street rig's; a pack or a per-location value can override the sun.

## SSR interface

Screen-space reflections (wssr1, run/app/ssr.cpp) are a fourth pass of this kind; another pass (the interior-mapped
windows) reads its reflection and G-buffer through run/app/ssr.h `rm::ssrResult`: docs/reflections.md "SSR interface".
