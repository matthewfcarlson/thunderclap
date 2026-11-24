# Grass blades (the app's Grass option)

wgrass1, 2026-11-23 (user, 11-23: "Yes grass should be completely Matte. Ideally we could render grass particles or
instances rather than having it be a flat mesh."). A remastered-edition picture option of the wasm app's runner
(run/app/grass.cpp, shaders vs_rm_grass.sc / fs_rm_grass.sc / rm_grass.sh), an rm pass like the window interiors and
reflections. Output only: the blades are drawn by the runner and nothing reads or writes the module's memory, so they
never collide with anything or change the game, and play3's checkpoint records are the same with any setting.

| row | values (faithful first) | remastered default |
|---|---|---|
| `grass` Grass | Original, Blades Low, Blades High | Blades High |

## Matte grass (Reflections)

The reflections' G-buffer (docs/reflections.md) gives grass and leaves on the ground no reflection. The grass test is
shaders/rm_grass.sh `rmGrassiness`, on chromaticity (the colour divided by its sum, so brightness and night drop out):

    score = (g - r) + 0.6 (0.27 - b)       (r, g, b the chromaticity)
    grass = smoothstep(-0.005, 0.02, score) x smoothstep(0.02, 0.05, g - b)

Green over red; olive and brownish leaves (green about red) where blue is low; not grey asphalt or stone (blue at a
third), blue-tinted night surfaces, sand (red above green, blue ~0.25) or dirt. The mask applies it to the texture and
to texture x baked colour and takes the larger. The old test (green above red and blue by 0.01-0.05 in absolute
colour) missed play3's dark night lawns: the plaza at 24,000 mirrored its tree trunks in the grass.

## Where blades grow

- **Textures.** Every texture's level 0 is read as the game uploads it (the game's own bytes, before any pack replaces
  them) and turned on the runner's worker thread (BGRA8, BC1, BC2, BC3 decoded) into a 64x64 RGBA thumbnail, a 5x5
  box-blurred copy of it (the local mean: a lawn texture's dark gaps between its painted blades are not bare ground)
  and the share of blurred texels that read as grass; a texture is grassy at 15% or more. Thumbnails live in memory
  only (~16 KB a texture); nothing is written to disk and there is no key list.
- **Ground.** A room draw (fixed function, unlit, shader kind 1/2, opaque, a prim buffer, the scene target) whose
  stage-0 or stage-1 texture is grassy (play3's lawns are `c3.0.2 | c14.2.1 | c4.0.1`: the base texture, a second
  texture blended over it by its own alpha, times the baked vertex colour). The rooms' prim buffers are kept on the
  runner's side as they are written (positions, texture coordinates, colours; indices): room vertices are in world
  space (their modelview is the view itself). Buffers written frame after frame (dynamic) are not kept.
- **Clumps.** The first time a ground draw is seen, a job for the worker strews its level triangles (|normal.y| >= 0.8
  of the normal: within ~37 degrees) with clump roots, a fixed number per unit of area (High 12, Low 7; at most 400,000
  a buffer), placed by a hash of the triangle's corners (the same lawn gets the same clumps whenever its room is
  loaded). At each root the draw's own combiner (the faithful fs_vp_stage.sh ops and arguments, evaluated on the CPU)
  runs on the thumbnails' texels at the draw's texture coordinates for every stage: with white for the vertex colour
  on the blurred texels (the surface itself; a night tint does not change what is grass), and the root is kept only
  where that reads as grass, so paths and bare patches painted in either texture stay bare; and with the baked vertex
  colour on the sharp texels, the clump's colour. Each takes a random rank. Clumps are sorted into 8-unit cells (x, z),
  each cell by rank, and handed back at a frame end: one static instance buffer per ground draw (48 bytes a clump).
  Rooms stream in far beyond the blades' reach (~270 units against 24), so a lawn is ready before its blades show.

## Drawing

- Right after its ground draw (from the next rm hook, like the window interiors; order 4, before the shadows' casters
  and the lighting pass set state for the next draw), into the same view: the cells near the camera and in the view
  frustum, instanced (one draw a cell): a cell draws the prefix of its clumps whose rank the density at its nearest
  point keeps.
- A clump (vs_rm_grass.sc) is 5 blades (Low 3), each 3 segments and a tip, at their own angles, offsets, leans and
  heights (~0.34 units tall, 0.045 wide at the root). Density falls from 1 at the near distance (High 9, Low 5 units)
  to 0 at the far one (High 24, Low 12); a clump grows out of the ground as the density at its own distance passes its
  rank, and every blade shrinks away towards the far end, so nothing pops as the camera moves; beyond, the game's flat
  grass texture is the lawn, and the blades' colour is the ground's, so the edge is soft.
- Blades are at least ~0.7 pixels wide (they widen with distance) so a far lawn does not shimmer.
- Colour: the ground's colour under the clump, darker at the root (x0.85: blades shade each other), lighter and a
  little yellower at the tip (x1.25), +-8% between clumps; the sun's shadows (fs_rm_grass.sc: the shadow pass's
  characters' and objects' row, darkened as the baked ground is: the Hulk's and the cars' shadows fall on the blades)
  and the ground draw's fog; with Night Lights on (wlook2, rm_city.sh) the lamps light the blades as they light the
  ground (added to the surface's light before its textures modulate it: each clump also carries the surface colour).
- Wind: two sines of the display clock (interp.h `interp_display_time`: seconds of the original's fields, between two
  updates' times at 60/120 fps, so a still picture is the same at any rate) and the clump's position, bending the
  blades with their height squared.
- Characters bend the grass aside: the origins of the two-sided fixed-function draws (vertex program 6: the Hulk and the
  people) in the last presented frame, into world space by that frame's view, up to 4; a clump within 1.4 units of one
  leans away and flattens. Runner-only (positions from the draw stream).
- Scene alpha stays the ground's (colour and depth written, no alpha). The blades write depth, so ambient occlusion
  takes them; they cast no shadows and are not in the reflections' G-buffer (grass is matte).

`HULK_GRASS=near,far,density,height,width,wind` tunes (development); `HULK_GRASS_LOG=1` (per 300 frames: ground draws,
cells and clumps a frame, lawns and their clumps, kept buffers; each lawn as it is made, with its combiner), `2` adds the
grassy textures as they are classified, `3` the room textures drawn and their grass shares; `HULK_GRASS_SHOW=1` tints
the blades magenta; `HULK_GRASS_AB=N` (cost turns).

## Checks and cost

- Game state: play3 to 60,000 with `null`, candidate 111813 against control 111809 (HEAD b858408e4) on the queue,
  settings pinned `remastered=1,grass=2` with every other remastered picture option on: records identical, target
  reached (test 111816; before the rebase onto wlook1/wperf1, 111785 and 111767 likewise).
- Pictures: queue Metal test 111808 (mac2, 1280x960, play3 frames 13,800 / 22,200 / 23,400 / 24,000, candidate against
  a control without grass); on the laptop the same frames and the desert (6,000 / 9,600 / 12,000: the sand and dirt
  textures read 0-1% grass, no blades). build/wgrass1/png (never committed).
- Display rates: at 60 fps (`HULK_DISPLAY_FPS=60`, consecutive frames 23,990-24,003) the blades' pixels change frame to
  frame 0.94-1.30x as much as the same pixels with Grass Original (sway and parallax), no flicker or popping. Before
  the combiner keys were kept by hash (interp.cpp clears a recorded draw's key), no lawn was made at 60/120 fps.
- Cost (queue `metal-ab`, mac2 M3 Max 40-core GPU, play3 to 24,600, 1280x960, MSAA 4x, every remastered option on; A/B
  turns of 30 frames counted only on frames with a lawn drawn, ~5,100 a side):

| setting | GPU a frame, off -> on | render thread | clumps a frame |
|---|---|---|---|
| Blades High | 2.565 -> 2.600 ms (+0.035) | 0.925 -> 0.946 ms (+0.02) | 759 |
| Blades Low | 1.776 -> 1.777 ms (+0.001) | 0.835 -> 0.855 ms (+0.02) | 188 |

  Estimates (GPU scaled by cores): an M3 Air (8-10 cores) ~0.15 ms High; a Steam Deck or an Android handheld GPU
  0.2-0.5 ms High, Low well under 0.1 ms. The average hides the peaks: a park filling the screen drew ~5,000 clumps
  a frame (13,200; not timed separately). The worker's builds (thumbnails, clumps) are off the runner's thread.
- `tools/wasm_android.py build` links libmain.so with the pass (the shaders build for spirv and essl).

## Not done yet

- Only grass ground in a room draw's stage 0 or 1; grass drawn as decals, props or alpha-tested cards (the desert's
  tufts) is not classified.
- The blades take no per-frame A/B on peak scenes yet; a density cap by on-screen clumps would bound the worst frame.
- The blades are lit as the baked ground (its colour, the sun's shadows); per-pixel lights (health orbs) do not light
  them yet.
- Pushers are the character draws' origins; cars and props do not bend the grass.
