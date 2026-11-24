# Screen-space reflections (the app's Reflections option)

wssr1, 2026-11-23 (user, 11-23: "We should also figure out screen space reflections, usually you're in the city at
night"). A remastered-edition picture option of the wasm app's runner (docs/remaster.md section 4's SSR row, R3):
run/app/ssr.cpp and three shaders, an rm pass like the HDR, ambient occlusion and shadow passes
(docs/hdr-shadows.md). Output only: nothing that draws reads or writes the module's memory, so game state and play3's
checkpoint records are the same with any setting.

| row | values (faithful first) | remastered default |
|---|---|---|
| `reflections` Reflections | Off (Original), Low, High | Low (High until wperf1: docs/performance.md, Low costs ~0.9 ms, High ~1.6) |

## What reflects

The game's world is baked (docs/remaster.md 2.3): no normal, roughness or metal maps, 70% of room prim groups without
normals, and only two materials that reflect at all, `layeredReflect` (buildings, a `REFL` environment map) and
`environment` (a sphere map, `ENVB`). The pass decides per draw, from the draw packet alone:

| surface | how it is found | strength | Fresnel F0 | roughness |
|---|---|---|---|---|
| wet ground: streets, pavements, roofs | a room draw (unlit fixed function, shader kind 1/2, modelview = the view) whose face is within ~32 degrees of level (world up from the view) | 1 at night, 0 by day | 0.15 | 0.1 (0.3 by day) |
| grass and leaves on the ground | the same, where the texture (or texture x baked colour) reads as grass by shaders/rm_grass.sh (wgrass1: chromaticity, so dark night lawns and olive or brownish grass count; sand, dirt and asphalt do not) | 0 (matte) | | |
| building glass | shader kind 2 (`layeredReflect`) where stage 0's alpha is 0 (the game's own glass mask, the one wlook0's Windows use) | 0.8 | 0.04 | 0.03 |
| building facades | the same where the alpha is 1 | 0.2 | 0.04 | 0.4 |
| environment-mapped objects | shader kind 3 (`environment`) | 0.8 | 0.5 | 0.06 |
| characters, props, the rest | | 0 (they only occlude and are reflected) | | |
| glows (street lamps' halos, orbs, fire, explosions, the green beams) | additive (one / src alpha, one) fixed-function draws in the world pass | depth only, where the texture is bright | | |

Night is the rooms' fog colour: play3's downtown night has fog luminance 0.087, the desert 0.50; below 0.15 the
streets are wet (it rains in the night city). By day only buildings and environment-mapped objects reflect (dry sand
and asphalt do not).

## How (ssr.cpp)

1. **The G-buffer.** At the frame's first scene pass the pass takes a view of its own before the world (rm::newView):
   an RGBA16F target and a sampled depth (D32F, else D24) of the scene's size, no MSAA. Every opaque draw of the world
   pass (fixed function, two-sided, skin, onebone; transient streams included) is drawn again into it as it reaches the
   sink, with the faithful vertex transform (the lighting pass's vs_px_ff / vs_px_skin) and fs_rm_ssrmask.sc: depth,
   a camera-space normal (the vertex normal where the draw has one that agrees with the face, the face normal from
   screen-space derivatives otherwise, and always the flat face on wet ground), the strength and Fresnel class and
   roughness above; the draw's alpha test keeps its holes. Glows go in as depth where their texture times their colour
   is bright, so a ray finds them and a glow in front of a wet street is not overdrawn by the street's reflection.
   The world's view and projection come from the frame's first room draw (as the other passes: the sky has its own).
   The pass's order is 7: before the lighting pass's draw hook (10), which binds the draw's own textures.
2. **The trace** (fs_rm_ssr.sc). At the frame's first effect copy or quad (where HDR tone maps; the refraction copy
   does not count) the scene so far is copied (the world, its translucent draws, glows, particles and effects) and,
   in a view before HDR's, each reflective pixel's view ray is mirrored about its normal and marched across the screen
   against the G-buffer's depth: perspective-correct (1/w and z/w step linearly in screen space), clipped to the
   screen and to the near plane, 120 units at most, a step every 2 pixels up to 24 (Low, half size) or 48 (High, full
   size), a hit when the ray passes behind the depth by less than a thickness (3% of the depth, at least 0.4 units, or
   its own last step up to a quarter of the depth, so a coarse march does not skip thin surfaces),
   then 5 bisection steps. The hit takes the scene's colour (half floats: lamps and glows above 1 stay bright),
   weighted by a confidence: faded at the screen's edges, at the ray's far end and for rays turning back to the camera.
   The start offset is a fixed per-pixel pattern (interleaved gradient noise of the pixel, not of the frame), so a
   still picture does not shimmer at any display rate.
3. **The composite** (fs_rm_ssrapply.sc): the traced reflection gathered over a ring whose radius grows with the
   roughness (depth-weighted, so silhouettes stay sharp), at least 1.25 trace texels on Low and 0.75 on High (wlook3,
   user 11-24 "grainy at times" with MSAA 2x: taken one texel at a time, the start offsets' hits and misses and Low's
   half-size texels made smooth wet ground and glass reflect a dotted, crawling pattern; nothing resolves it without
   TAA), weighted by Schlick's Fresnel (F0 by class, the grazing peak
   lowered on rough surfaces) and the strength, and blended over the scene (source alpha, colour only). Where no ray
   hit, the game's own surface stays: its `REFL` / sphere-map reflection is the fallback, as it always was.

Display rates: interp.cpp re-draws every presented frame's draws through rm, so the G-buffer, the trace and the
composite are made for every presented frame from the interpolated constants; nothing is accumulated across frames
(no reprojection, no history to smear or to restore after a rollback).

`HULK_SSR=strength,wetNight,wetDay,building,maxRay,wetF0` tunes (1, 1, 0, 0.8, 120, 0.15); `HULK_SSR_SHOW=1|2|3` shows
the G-buffer (grey-blue wet ground, green buildings and glass, red metal-like; brightness the strength), the weight and
confidence, or the reflection alone; `HULK_SSR_LOG=1` (G-buffer draws a frame, glows, the fog and night);
`HULK_SSR_AB=N` (cost turns).

## SSR interface (for other runner passes)

wlook0's interior-mapped windows (and any later pass) read the reflection through run/app/ssr.h:

```cpp
#include "ssr.h"
rm::SsrResult r;
if (rm::ssrResult(&r)) {    // traced this frame (from the composite, at the frame's first effect, to the frame's end)
    // r.reflection: RGBA16F, r.width x r.height (half the scene's size at Low, the scene's at High):
    //   rgb = reflected colour x confidence (premultiplied), a = confidence (0: no hit)
    // r.gbuffer: RGBA16F, r.gwidth x r.gheight (the scene's): xy camera-space normal (octahedral; fs_rm_ssr.sc's
    //   octDecode), z strength (0: not reflective), w = Fresnel class (floor: 0 glass/stone, 1 wet ground, 2 metal) +
    //   roughness / 2
    // r.depth: the G-buffer's depth (D3D depth of the world's projection; linearise with r.proj = c4..c7 as
    //   fs_rm_ssr.sc's viewZ: (c6.w - d c7.w) / min(d c7.z - c6.z, -eps))
}
```

- Sample them in views that run after the composite: views taken later in the frame (rm::viewsBefore of a later game
  pass, rm::newView after the composite, or postScene). The reflection exists only while Reflections is on and the
  frame has a world pass with an effect.
- The window interiors (wlook0, windows.cpp) are drawn as decals right after their building, inside the world pass,
  before the trace (at the frame's first effect), so the frame's reflection does not exist yet when they draw, and
  windows.cpp's `refl` (fs_rm_window.sc winStages) stays the game's sphere maps. They get SSR anyway: the composite
  runs after them over the same pixels, and the G-buffer marks the glass by the same stage-0 alpha (strength 0.8,
  smooth), so where a ray hits the reflection is blended over the interior by Fresnel (source alpha: the interior and
  its sphere-map reflection are scaled by 1 - w, not doubled); where none hits, the window keeps the interior with
  the game's reflection. A pass drawing later in the frame (after the composite) can sample `r.reflection` itself:
  `rgb / a` at the pixel's screen uv, weighted by its own Fresnel and `a`.
- Treat the handles as read-only; they are remade when the render size changes.

## What the player sees

In the night city the streets, pavements and roofs read as wet: the lit windows of the buildings, the taxis and other
cars, people, the street lamps and their halos, the Hulk and the glowing pickups are mirrored in them, blurred a little
and strongest towards the distance (Fresnel), and grass stays matte (wgrass1: no reflection at all on lawns, also the dark night ones the first test missed). The windows of `layeredReflect`
buildings (with Windows: Interiors, over the rooms behind them) pick up the street and the buildings across it, most
at grazing angles; the facades between them only faintly. Steep views down from a roof show little (Fresnel is low
head-on, as it should be), and the reflections end where the reflected thing leaves the screen. By day (the desert
tutorial) nothing changes but buildings and environment-mapped objects.

## Checks and cost

- Game state: play3 to 60,000 with `null`, candidate 111708 against control 111709 (HEAD 968851e17) on mac2, settings
  pinned `remastered=1,reflections=2,windows=1,hdr=1,ao=1,shadows=2,msaa=4`: records identical, target reached (test
  111711; before the rebase onto wlook0's Windows, test 111669 likewise). On Metal (laptop) play3 to 30,100 with
  Reflections High and Off gave the same checkpoint records.
- Pictures: play3 on Metal, render 1280x960, MSAA 4x, every remastered option on, Reflections Off / Low / High at
  frames 9,600-30,000 (build/wssr1/png, never committed); the G-buffer view (`HULK_SSR_SHOW=1`) at 12,000 and 15,000.
- Cost (measured before the coarse-march thickness and the glass mask; play3 to 25,000, A/B turns of 30 frames within one run, the city by night from ~13,000; a laptop shared with
  other lanes, so upper bounds):

| setting | GPU a frame, off -> on | render thread |
|---|---|---|
| Reflections High (full-size trace, 48 steps) | 8.84 -> 11.80 ms (+3.0) | 1.64 -> 2.16 ms (+0.5) |
| Reflections Low (half-size trace, 24 steps) | 9.09 -> 10.99 ms (+1.9) | 1.41 -> 1.78 ms (+0.4) |

  Most of Low's cost is fixed: the G-buffer's second draw of the world pass (~300 draws a frame in the city, ~180 of
  them reflective, ~30 glows) and the full-size composite into the 4x multisampled target.
- Stability at 60 fps (`HULK_DISPLAY_FPS=60`, consecutive game frames 18,600-18,605 and 24,000-24,003): on the
  reflecting pixels the frame-to-frame change is 1.2-1.3x the change with Reflections off (the reflected content moves
  with the camera at twice the parallax), no flicker: the trace has no per-frame noise and no history.
- `tools/wasm_android.py build` links libmain.so with the pass (the shaders build for spirv and essl).

## Not done yet

- Rays can only hit what is on screen and in the world pass's depth: reflections of things off screen, behind the
  camera, or hidden behind other geometry are missing (the fallback is the surface as the game draws it). Translucent
  draws that are not additive (smoke, decals) are reflected only where an opaque surface is behind them.
- No temporal accumulation: Low's half-size trace is gathered (a ring of 1.25 texels at least) but not denoised; a rough-surface blur and a temporal
  filter would let Low trace fewer rays.
- Puddles: the wet ground is uniformly wet; a world-space wetness pattern (puddles, drier patches) needs the world
  position (the inverse view is known) and a noise or pack texture.
- Water surfaces (refract shader kind 4) and car paint beyond the `environment` shader are not classified yet; a
  `mat` pack (remaster.md 2.7) could name reflective materials by texture key.
- OpenGL's bottom-left origin is handled in the maths but untested; Android Vulkan builds the shaders (spirv, essl).
