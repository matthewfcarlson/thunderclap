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
