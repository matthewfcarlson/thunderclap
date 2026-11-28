# Water (the app's Water option)

wwater1, 2026-11-28 (D249/D250: the user's visual pick #7). A remastered-edition picture option of the wasm app's
runner: run/app/water.cpp, shaders fs_px_water.sc, fs_rm_ssrwater.sc and rm_water.sh, an rm pass (rm_pass.h, wr2), plus
the reflection pass's water draws (ssr.cpp). Output only: the game's own water draws change program, nothing reads or
writes the module's memory, and play3's checkpoint records are the same with any setting.

| row | values (faithful first) | remastered default |
|---|---|---|
| `water` Water (`rm::kWater` = 31) | Original, Enhanced (char_light's strings, `k_borrow`) | Enhanced |

## Where the water is

From the disc (tools/p3d.py over build/rcf: every `Shader` chunk and every `PrimGroup` that uses a water texture;
build/wwater1/scripts/shscan.py, pgscan.py, never committed):

| place | geometry | texture, shader | how it is drawn (Metal draw logs) |
|---|---|---|---|
| the sea around the city (downtown day / dusk / night, church_night, turning_point_night) | the location's `waterShape`: one plane of 101 vertices, x -3136..1017, z -3086..599, model y 0 placed at world y -10, with a vertex animation (`VRTX_waterShape`) | WATER2_TILE (128x128, dark teal), `simple`, BLMD 1 (alpha), vertex alpha 204..239 | streamed every frame as 180 transient vertices, src-alpha / inv-src-alpha, depth write on; its modelview is the view with a 10-unit offset; usually inside the world pass after the rooms, sometimes before them (with the sky's draws) |
| the outskirts' strip of sea (outskirts day / dusk) | a 26-vertex `waterShape` at x -3136..-2529 | WATER2_TILE, as above | 39 transient vertices |
| the dam's lake (the_dam_night) | `waterShape`, 25 vertices, +-2564 | WATER3_TILE (teal), alpha | not reached by play3 / play4 |
| the outskirts' river (rooms r301..r489) | room prim groups, one level sheet at y -25.2 | WATEROS (day) / waterOS (dusk), opaque `simple`, a 10-frame flipbook | not reached by play3 / play4 |
| Banner's cabin pond (bc_day rooms r406, r437, r438) | room groups at y -10 | waterOS flipbook, opaque | play3 8,944..9,006 (the cutscene: hidden by the trees) |
| Banner's cabin waterfall, spray, mist | vertical strips, sprites | WATERTILE4SM1 / WATERMIST / WATERWAVE, additive or alpha | left alone (not level, or additive) |

Faithfully the sea is a flat, slightly transparent dark teal sheet: under it the game draws its own night lights and a
moon glint, which show through its 80-94% opacity.

In the replays: play3's night city draws the sea on every city frame from 13,086; it is on screen at the harbour front
(f17,170: the bay beside the Harbourhill Inn; f56,570: the promenade) and around the Church hub (f13,800, f29,995,
f54,980). play4 shows it at 57,255 and 66,500 (city) and 76,816 / 76,920 (the outskirts' sea by day). `HULK_WATER_LOG=1`
prints `present N covers X% of the view` (the water's clipped screen area, occlusion not counted) every 30 presents.

## Which draws

A draw of the world's pass (the game pass of the frame's first room draw; before it, the previous frame's) that is fixed
function, unlit, shader kind 0 (`simple`), one texture stage, a rigid (unscaled) modelview, opaque or src-alpha /
inv-src-alpha blended (never additive), depth tested, no stencil or occlusion query, whose vertices are one level sheet
(every vertex at one model height, at least 8 units across: the transient stream, or a prim buffer as it was written),
and whose texture's mean colour (`texpack_mean`, the game's own level 0) is blue-green: red well below green and blue,
green and blue within 0.07 in chromaticity. On disc that colour test alone also takes signs, neon tubes, lightmaps and
reflection maps (build/wwater1/scripts/rule.py over 2,213 textures); the level-sheet test removes every one of them
seen in play3 / play4. The program also keeps the faithful texture x colour on any face that is not level.

## The look (fs_px_water.sc)

- **Ripples** (rm_water.sh): seven travelling waves (wavelengths 9.7 .. 0.43 units, deep-water speeds) in the draw's
  model space, warped slowly so they never read as a lattice, each faded out where a pixel covers more than a sixth of
  its length (no shimmer in the distance, no reliance on TAA: wlook3). Model space is the world's for the sea and the
  rooms (the ripples stay put as the camera moves; no camera needed). The clock is `interp_display_time()`, so a
  picture is the same at any display rate.
- **Shading**: the waves shade the game's colour as the key light falls across them (the shadow pass's sun, which is
  the moon in the night city; slope x 1.5, clamped to 0.55..1.45), so the surface moves even where nothing reflects.
- **Refraction**: at the frame's first blended water draw drawn with the world's projection the pass splits the world
  pass (`rm::viewsHere`) and copies the scene so far (a blit of the colour, a linear R32F depth through
  fs_rm_softdepth.sc, as soft particles do). The water shows that copy bent by the ripples, under the game's own
  colour at the game's own opacity: the game draws a mirrored layer under the sea (the bridge towers, a moon glint,
  lit wave sparkles: `HULK_WATER_SHOW=4`), which shows through as before, now moving with the waves; where the water
  is shallow (depth below the surface < 1.5 units) it turns clear. Only the surface is fogged (the copy is fogged
  already: fogging it twice sank the towers and the moon's glint into the fog in the first build).
- **Fresnel**: Schlick, F0 0.02, towards the sky's colour at the horizon (the draw's fog colour) at 0.35.
- **Screen-space reflections** (with Reflections on): ssr.cpp draws each water draw into its G-buffer with
  fs_rm_ssrwater.sc (the same rippled normal, smooth, Fresnel class 0, strength 0.45), so the trace and the composite
  treat it like glass; strength 0.45 keeps the game's own glints visible under the reflection. Only water drawn with the
  world's projection goes in (the sea drawn among the sky's draws has its own near and far).
- **Glint**: with the shadow pass on (its key light), a sharp highlight on the ripples: the sun's by day (3), the
  moon's at night (1.2: the sparkling path around the Church hub).
- **Shore**: foam in water shallower than 0.6 units (a drifting pattern, in the light of the water's own vertex colour,
  so dim at night) and a soft edge over the last 0.15 units where the water meets the ground.

Opaque water (the river, the pond) is drawn among the rooms: it gets ripples, Fresnel, the reflections and the glint,
not the copies (refraction, shore).

## Knobs

`HULK_WATER=ripples,refraction,clarity,foam,shore,edge,glint,sky,ssr,shade` (1, 0.04, 1.5, 0.8, 0.6, 0.15, 3, 0.35,
0.45, 1.5); `HULK_WATER_SHOW=1|2|3|4` (the normal, the depth below the surface, Fresnel, the scene behind); `HULK_WATER_LOG=1` (draws, copies, screen
coverage), `2` (each water texture's first draw), `3` (level sheets that are not water), `4` (every water-coloured draw
not taken, with the reason); `HULK_WATER_AB=N` (cost turns).

## Linux / Android

Every sampler the program declares is bound for every draw (stages 4 and 5: the copies, or a 1x1 white texture when the
draw has none; stages 0..3 by the sink); a copy of a water draw submitted again by another pass is bound again through
`rm::lightingRebind` -> `rm::waterRebind`. Handles: one blit texture, one R32F target with its frame buffer, the 1x1
texture, two programs and four uniforms; nothing per frame. The shaders compile for metal, spirv and essl.

## Checks and cost

All on the queue (Metal, 1280x960, every remastered default pinned: build/whud1/settings.txt plus hud_res, particles,
char_light, text_spacing, move_prompts; aspect 4:3, `HULK_MOVIES=0`), app 112388 at a67cba7c4 + this change against the
HEAD control 112389:
- Water on, play3 to 56,620 (112390): records identical to the control; shots differ only on water (f13,800: 0.47% of
  pixels off by more than 8, the moon's glints; f54,980 0.39%).
- Water unset (faithful, 112391): records identical; shots identical or off by at most 4 levels on no pixel by more than
  8, the same as the control against itself (112392: max 4 at f17,170, max 2 at f56,570): run-to-run noise.
- Cost (metal-ab 112386, studio, `HULK_WATER_AB=30`, play3 to 56,500, 17,947 of 25,380 water-on frames with water
  drawn): GPU 2.036 -> 2.136 ms by bgfx's timer (+0.10 ms; it reads ~1.8x high, so ~0.06 ms real), render thread +0.02 ms.
- play4 (`play4:N` tests with the Metal environment passed by hand: build/wwater1/scripts/play4metal.sh; the metal test
  kinds replay play3 only) replays to 91,000 with the row on; its outskirts sea is drawn (76,335..77,486) but never seen.
- The shaders compile for metal, spirv and essl (tools/rm_shaders.py's shaderc with the same arguments).

## Not done yet

- The river, the dam's lake and the daytime sea are not on screen in play3 or play4: the daylight look (sun glint, the
  blue sky in the Fresnel term) and the opaque river's path are checked only on the disc's data and by the program's
  code paths, not in a picture. A save in the outskirts (c02m01 onwards) or at the dam would show them.
- Opaque water has no shore (foam, soft edge, clear shallows): it is drawn among the rooms, before its banks' depth.
- The sea drawn among the sky's draws (before the rooms, a few frames in play3) takes no copies and no screen-space
  reflection that frame (its projection is the sky's).
- Caustics, wakes around the Hulk and splashes are not modelled; the game's own splash sprites are unchanged.
