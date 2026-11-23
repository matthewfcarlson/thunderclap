# The look of the remastered edition (wlook0: survey, art directions, window interiors)

wlook0, 2026-11-23. The user (11-23): "I feel like we might need to revamp the whole look. It could also be interesting
to do a technique like Into the Spider-Verse where the windows into buildings are textures that project a room inside
rather than being just a piece of poorly textured glass with no real reflections."

This note has three parts: what the remastered edition looks like today (section 1), two or three coherent art
directions for "the game made today" with the passes each needs and its cost on the targets (sections 2-4), and the
first new technique, interior mapping for building windows, built as a prototype in the app (section 5). Everything
here is a renderer pass of the runner (run/app, rm_pass.h, docs/remaster.md 5.3): output only, the faithful port and
the game's state untouched. Techniques only: no other game's or film's assets, shaders or art are used or copied.

Screenshots for review are in build/wlook0/runs/ (local, never committed): `orig/` the faithful edition, `rem/` the
remastered defaults, `win*/` with Windows: Interiors; `*/contact.png` and `cmp*.png` are side-by-side sheets.

## 1. Where the remastered edition is today

**What was captured.** play3 replayed on Metal (hidden window, render 2x, MSAA 4x) at the remastered defaults
(per-pixel lighting, health-orb lights, HDR with the game's bloom on top, AO, sun shadows High, full mips, 16x
anisotropy, Draw Distance Far, Fog Reduced) and at the faithful values, at game frames 3,000 to 28,000: the desert
tutorial by day (3,000-12,000: the canyon, a tutorial tower, the desert town) and the city at night (15,000-28,000:
rooftops, streets, a glass tower climbed at 28,000). A free run from a saved game (build/wlook0/usersave, the player's
four-mission save copied by whang1) reaches the Church hub at night; a scripted run did not get the Hulk into the
city's travel beam (it needs a context action the scripts didn't find), so downtown by day and at dusk and the
outskirts are not in this survey: they need a recording or a save that starts there.

**What the remaster already does well.** Per-pixel lighting makes the Hulk and props read as solid (round speculars, no
Gouraud banding); sun shadows ground the characters, cars and props, and buildings shade the Hulk; AO puts contact
darkening into the city's corners; HDR keeps the orbs and explosions coloured with a soft glow; MSAA, full mips and 16x
anisotropy clean the streets' shimmer; draw distance and reduced fog open up the night skyline.

**What still says 2005.**
- *Materials.* Everything is one diffuse texture times baked vertex colour. Walls, glass, metal, asphalt and the Hulk's
  skin have the same response; there are no normal, roughness or metal maps (remaster.md 2.3). The building glass is a
  painted pane plus a sphere-map reflection (stages 1 and 2 of layeredReflect) that slides with the camera: it reads as
  "poorly textured glass", exactly the user's complaint.
- *Night.* Night is a dark-teal multiply of the day: the city's light comes from painted windows and a few additive
  glows; streets have no light pools, signs and windows light nothing, wet asphalt does not reflect.
- *Sky and atmosphere.* The sky is a dome texture; fog is a linear tint (Reduced in the remaster). There is no aerial
  perspective, no sun disc or scattering, no volumetric light, so distance reads flat.
- *Texture resolution.* World textures are 64-128 px (55% with only their top level); at 2x render size the facades are
  soft. HD packs (texture-packs.md) fix this where a pack exists.
- *Effects.* Particles are unlit sprites with hard depth intersections; impacts have no screen response beyond the
  game's own shake and flash.
- *Shadow acne* (fixed, wlook1, L4). In the desert at the remastered defaults the ground showed horizontal banding
  (game frame 12,000) and the tutorial tower's wall fine streaks (6,000). Two causes: the ground's bands were the
  ambient occlusion's (the 24-bit depth's terraces tilting its one-texel normal; with AO off they were gone, with
  shadows off they stayed), and the walls' streaks were shadow acne: `simple` rooms (the desert's ground and the
  tutorial's buildings) were treated as objects, so they cast into the objects' row and shadowed themselves, with one
  bias for both cascades (the far cascade's texels are ~5x the near one's). Fixed in fs_rm_ao.sc (a two-texel
  normal and an angle bias) and shadows.cpp (every unlit world shader is a room; a per-cascade, slope-scaled normal
  offset and depth bias): docs/hdr-shadows.md. Before/after: build/wlook1/png/acne-6000.png, acne-12000.png.

## 2. Three art directions

All three keep what is faithful (section 4) and share most of the new passes; they differ in grade, light model and
how much stylisation sits on top. Each is a preset over individual Video Options rows, so the player can mix.

### A. Grounded modern ("a 2020s open-world city")

Physically based materials and light, the baked lighting kept as the world's indirect light. The city at night is lit
by its own windows, signs and street lamps; glass and wet streets reflect; distance has atmosphere.

| pass | state | notes |
|---|---|---|
| per-pixel lighting, HDR + tone map, AO, sun shadows, MSAA, mips, aniso, draw distance, far field | exists | wlight1, wr3a, wr2 |
| window interiors | prototype (section 5) | Windows: Interiors |
| screen-space reflections | in progress (wssr1) | glass, wet streets, water; falls back to the game's sphere maps |
| material classes | new | from shader kind and texture keys: glass (layeredReflect's mask), metal, asphalt, concrete, foliage, skin; a small per-texture table made offline from the player's own textures, overridable by packs (`mat` keys, remaster.md 2.7) |
| PBR packs | new, content | albedo/normal/roughness for the ~1,600 textures a session uploads; generated normals where none (70% of room groups) |
| emissive night | exists (wlook2, docs/night.md) | Night Lights: the game's lamp, sign and vehicle glows as a tiled light list in the per-pixel lighting; light pools on streets. Window spill is still to do |
| sky and atmosphere | exists (wlook2, docs/night.md) | Atmosphere: the game's dome re-graded (zenith, horizon glow, city-lit clouds, stars, moon at the key light), height fog and aerial perspective over the game's fog, lamps' in-scattering |
| volumetrics | new | froxel or ray-marched sun shafts and lamp cones (half/quarter resolution) |
| colour grading | new | a 3D LUT after tone mapping (filmic ACES-like curve, per-location LUTs; authored in any grading tool as a neutral 33^3 PNG strip) |
| particles | new | soft particles (depth fade), lit smoke from the sun and the orb lights, HDR sparks |
| characters | new | skin and cloth presets (wrapped diffuse, sheen), rim light from the sky, contact shadows |
| temporal AA / upscale | new | TAA, then MetalFX on macOS and FSR 2 elsewhere (motion vectors need instance tags, remaster.md 2.6) |

Risk: the more realistic the lighting, the more the 2005 geometry and 128 px textures show. It depends on PBR packs
to pay off, and night needs emissive light the data doesn't have.

### B. Comic / graphic ("the Hulk's comics in motion")

The look of printed comics: ink, flat light, halftone. It suits a game whose hero is a comic character and whose city
is a backdrop for destruction, and it hides low-poly geometry and soft textures instead of exposing them.

| pass | state | notes |
|---|---|---|
| per-pixel lighting | exists | quantised: 2-3 cel bands with a soft step, the key light from the game's rig (characters) and the sun |
| sun shadows | exists | hard-edged, filled with a halftone instead of darkening |
| AO | exists | as hatching or halftone density instead of darkening |
| HDR | exists | for bright effects; grade clamps highlights to a paper white |
| ink outlines | new | screen-space edges from depth, normals (derivatives where the world has none) and a per-draw id (silhouette vs crease); line weight by distance, thicker on characters; 1 full-screen pass |
| halftone / Ben-Day | new | screen-space dot screens (dot size from the light level, world-space anchoring so dots don't swim) in shadows and on the sky |
| texture flattening | new | an edge-preserving filter on world textures at upload (Kuwahara-style, made once per texture in texpack.cpp's worker threads) so 2005 noise reads as painted flats |
| colour | new | a posterising LUT with a limited, saturated palette per location; Hulk green kept as the anchor |
| sky | new | a graded gradient with drawn clouds and a stylised moon/sun |
| effects | new | impact frames (one-frame inverted or high-contrast flash on big hits), speed lines on charges and leaps, onomatopoeia sprites on impacts (our own art) |
| window interiors | prototype | fits well: flat-shaded rooms with ink edges; a comic city's lit windows |

Risk: stylisation needs consistent treatment of every draw (HUD, menus, movies stay as they are), and a few effects
need game events (impact frames: hit strength from the fight system, a read-only hook).

### C. Hybrid ("graphic realism") — recommended

Modern light and materials where they make the world solid (A's lighting, shadows, AO, SSR, interiors, atmosphere),
with a graphic layer that makes it read as a comic-book world: ink outlines on characters, vehicles and destructibles
(and lightly on architecture), a punchy grade with lifted greens, halftone only in deep shadow and the sky, comic
impact frames and speed lines. Night is cinematic: lit windows (interiors), sodium street light, wet streets in SSR.

Why C: it keeps everything already built (no pass is thrown away), adds the two features that change the picture most
for the least content (interiors and outlines, neither needs packs), works without PBR packs (B's flattening and C's
grade cover low-res textures) and gets better with them, and it gives the remaster a recognisable identity instead of
a generic "realistic" filter. The presets would be Look: Original / Modern (A) / Graphic (C, default) / Comic (B).

## 3. Cost on the targets

GPU time at 1280x960 (render 2x) unless stated. *Measured* numbers are this laptop (M-series, Metal) under other lanes'
load (upper bounds); the others are estimates from the passes' work (full-screen taps, draws) scaled by the targets'
fill and bandwidth: Steam Deck (RDNA2 8 CU, 1.6 TFLOPs, 88 GB/s; Vulkan, renders 800p), an Android handheld (Adreno
740-class or Mali-G710-class; tile-based, ~50-70 GB/s; 720p-1080p). The game itself is cheap (~0.8 ms at 640x480 with
everything off, about 255 draws a frame).

| pass | M-series (Metal) | Deck (800p) | Android (720p) | in |
|---|---|---|---|---|
| HDR | +1.2 ms measured | ~1 ms | ~1.5 ms (RGBA16F bandwidth) | A B C |
| AO (half-res) | +2.3 ms measured (at MSAA 4x) | ~1.5 ms | ~2 ms; quarter-res there | A B C |
| Shadows High / Low | +1.9 / +0.45 ms measured | ~1.5 / 0.4 ms | Low only (~0.6 ms) | A B C |
| Window interiors | +0.6 ms measured (city, 20-140 decals a frame) | < 0.5 ms | < 1 ms (a decal over the glass; no full-screen pass) | A B C |
| SSR (half-res) | wssr1 | ~1.5 ms | ~2.5 ms; off or quarter-res | A C |
| outlines | ~0.3 ms (1 pass, 9 depth/normal taps) | ~0.4 ms | ~0.6 ms | B C |
| halftone + grade LUT | ~0.2 ms | ~0.3 ms | ~0.4 ms | B C (grade in A too) |
| sky + aerial perspective | ~0.2 ms (LUT per frame + in the fog term) | ~0.3 ms | ~0.4 ms | A C |
| volumetric shafts (quarter-res) | ~1 ms | ~1.5 ms | off | A (C optional) |
| PBR materials (forward) | ~0.5-1 ms more shading | ~1 ms | ~1.5 ms | A (C with packs) |
| TAA / upscaler | ~0.5 ms / MetalFX | ~0.7 ms / FSR 2 | TAA only | A C |

Budgets: 60 fps is 16.7 ms. On M-series all of A or C fits with room (the measured total of today's options at MSAA
4x is ~11 ms; MSAA is the biggest single cost and TAA would replace it). The Deck fits C at 800p without volumetrics.
Android fits B or C's light preset (no SSR, quarter-res AO, Low shadows, outlines and grade on).

## 4. What stays faithful in every direction

- The simulation and every checkpoint record: the passes never read or write the module's memory (play3 null records
  byte-identical with any setting).
- The game's own composition: camera, framing, HUD, menus, movies and the fader are untouched (stylisation applies to
  the scene before the game's effects, like HDR's tone map).
- The baked lighting stays the world's indirect light (it is the art direction of 2005; relighting the world needs
  de-lit albedo).
- The game's effects pipeline (colour pass, bloom, motion trail) runs on top, as with HDR.
- Every option has an Original value and the edition switch restores all of them (D233).

## 5. Interior mapping for windows (prototype: Video Options > Windows: Original / Interiors)

### 5.1 How the game draws windows

- **Buildings are layeredReflect** (`ShaderKind` kShaderBuilding). Every one of them in play3's city uses one combiner:
  `c4.0.2a2.2.0r1 | c20.1.2a2.1.0r1 | c20.1.2a2.1.0r1`: colour = vertex colour (baked light) x facade (stage 0),
  alpha = the facade's alpha; then twice `current + stage x (1 - current.alpha)` (D3D MODULATEINVALPHA_ADDCOLOR) with
  stages 1 and 2. So **the facade texture's alpha is the glass mask**, and in
  the facades it is 0 exactly on the window glass and 1 on frames, mullions, sills and walls (a sheet of the 195
  textures with partial alpha: build/wlook0/runs/alphasheet.png). The windows are in the game's own data, texel-exact;
  no mask pack, colour heuristic or texture-key list is needed.
- **Stages 1 and 2 are two different things.** One has generated texture coordinates (vs_vp_ff's texgen, `u_vc[48 + s].x`
  above 3: the camera-space reflection vector): the sphere/environment map that slides over the glass. The other is
  mapped by a second UV set and holds **the window lights the game paints at night**: the lit/unlit office pattern of
  the night city is that layer, not the facade (debug views in build/wlook0/showcase/debug-views.png: the painted pane
  under the mask is a flat pale blue on every window; the mapped layer is the pattern). The prototype tells them apart
  by their coordinate source per draw.
- **Layout.** Facade textures are small (64-128 px, BC2/BC3 for the alpha) and each holds one window bay (one to six
  panes, sometimes two floors) tiled across the wall by UVs that run past 0..1: one texture tile = one bay. The
  night city's lit offices are the second layer above, not the facade.
- **Counts.** City at night (game frame 19,000): 427 draws, 93 of them layeredReflect; at the glass tower (28,000) 19
  of 377. The tutorial's buildings are `layered`/`simple` with windows painted into opaque texture (no alpha mask):
  Interiors don't touch them (5.6).

### 5.2 The technique

Interior mapping ("fake interiors"): the glass shows a box room behind it, found per pixel by intersecting the view ray
with the room's planes in the facade's own frame, so it has parallax but no geometry.

- **The frame.** The world's rooms carry no normals or tangents, so the shader builds them per pixel from screen-space
  derivatives of the camera-space position and the facade UV (the cotangent frame: dP/du, dP/dv, and the face normal
  towards the camera). The world's up in camera space (the draw's modelview's second column) decides which UV axis is
  vertical and which way is up.
- **The room.** One room per texture tile: x across the bay, y up, z into the wall, its depth 0.9 of the bay's width in
  world units. The ray starts at the pixel's place in the tile and the nearest of the five inner faces is hit: back wall,
  side walls, floor, ceiling.
- **Contents** (procedural, from a hash of the tile and a per-building seed taken from the prim buffer's centre, so a
  room keeps its look across frames and reloads): wall colour from a muted palette; a skirting band; a door or a
  picture on the back wall; wood planks or carpet; a ceiling light panel; a furniture silhouette on a plane part-way in
  (desk, sofa or cabinet); blinds over the top or curtains at the sides, just behind the glass. No textures, no art.
- **Light.** The daylight baked into the facade's vertex colour, falling off with depth; the game's own glass (the
  painted pane times the baked light, plus its window-light layer) as a fill, so the original's exposure and palette
  carry through; a lamp where the game's window-light layer is lit (its colour pulls the lamp's warm or cool white
  towards the game's own tint), plus a share of rooms chosen by the seed (more at night, judged from the baked
  light's level). So the city keeps the original's pattern of lit and dark offices, now with rooms behind them. The
  ceiling panel is emissive when the room is lit, which HDR turns into a soft glow.
- **Glass.** The game's environment-map stage over the room by Schlick's Fresnel (F0 0.12): the room shows looking in,
  the reflection takes over at grazing angles. wssr1's SSR buffer replaces the sphere maps here
  once it lands (the hook is `refl` from `winStages` in fs_rm_window.sc).
- **Distance.** Where a bay is only a few pixels wide the room's detail fades to its average colour (no shimmer).

### 5.3 How it is drawn (run/app/windows.cpp, shaders/fs_rm_window.sc, vs_rm_window.sc)

The pass replaces nothing: each building draw is drawn again right after itself as a decal. The packet (prim buffers,
constants, textures, fog) is kept with copies of its constants, then submitted at the runner's next hook (the next
draw, pass, copy, effect or the frame's end) into the view the building was drawn in, with the runner's program,
depth test less-equal, no depth or alpha writes, blended by the glass mask. Its vertex shader is the per-pixel
lighting's faithful transform (vs_px_ff.sh) with the depth pulled 4e-6 x w towards the camera (PX_DECAL), so it wins
the depth test over its own surface and nothing else. The pass's order (3) puts the decal before any other pass's
state for the next draw (the shadows' casters at 5, the lighting pass's uniforms at 10). The faithful combiner, the
lighting pass and shadows are untouched; the decal composes with all of them (the game's glass under it is simply
covered).

### 5.4 Settings and knobs

- `windows` (Video Options > Windows): 0 Original, 1 Interiors; faithful 0, remastered default 1; remastered-only;
  rm::kWindows = 11.
- `HULK_WINDOWS=depth,F0,reflection,lamp,nightBias,debug,dayLit,nightLit` tunes (0.9, 0.12, 1.0, 0.8, 0, 0, 0.12, 0.2);
  debug 1 shows the mask in magenta, 2 the game's painted pane, 3 its window-light layer, 4 the environment map. `HULK_WINDOWS_LOG=1` (decal draws a frame),
  `HULK_WINDOWS_AB=N` (cost: off and on in turns of N frames).

### 5.5 Results and cost

- **What it looks like** (play3, Metal, render 2x, every remastered option on; build/wlook0/showcase/: `before-*` /
  `after-*` at game frames 19,000-28,000 and two zoomed pairs). Across the night skyline (19,000) the towers keep the
  game's pattern of lit and dark offices, but each lit window is now a room with depth: warm and cool interiors, a
  ceiling light, furniture and blinds, shifting with parallax as the camera moves; dark offices show a dim room instead
  of flat teal glass. Climbing the glass tower (28,000) the panes show rooms the Hulk can look into, with the sphere map
  only at grazing angles. Faraway bays fade to their average colour (no shimmer).
- **What is weaker** (wlook0; wlook1 brightened the rooms, chose them per window and fixed the speckle: 5.7). At the
  original's exposure the rooms are darker overall than the game's flat glow (the game paints
  every pane with an env-map shine, the interiors show that shine only at grazing angles); some pane edges show a few
  pixels of colour noise where a 2x2 pixel quad straddles two triangles and the derivative frame is wrong; one room
  per texture tile means a wall between two bays of the same office. Daylight facades are untested (play3 has no city
  by day).
- **Cost** (laptop, Metal, 1280x960, MSAA 4x and every remastered option on, the city part of play3, 15,000-28,000;
  `HULK_WINDOWS_AB=30`, turns of 30 frames within one run, the laptop under other lanes' load, so upper bounds):
  **+0.6 ms GPU** and **+0.19 ms render thread** a frame, for 20-140 decal draws a frame (93 building draws in the
  19,000 view). The fragment shader is ~150 ALU ops and 4 texture reads per glass pixel, no extra target or full-screen
  pass; on a Deck or a tile-based Android GPU the cost scales with glass pixels (the decal re-reads nothing from the
  frame), estimated well under 1 ms at 720p-800p.
- **Checks.** play3 to 60,000 with `null`: records identical to the control (HEAD e0d79a12f, control app 111684,
  candidate 111685): test 111689 (faithful settings, mac2) and test 111690 (`remastered=1,windows=1` and every renderer
  option, studio): both "records_identical, no divergence". On Metal (laptop) play3 to 28,100 with every remastered
  option and Windows off, on, and on/off in A/B turns: the checkpoint records are byte-identical (over the common
  length) to each other and to the faithful edition's. `tools/wasm_android.py build` compiles windows.cpp and the
  shaders (spirv, essl) and links libmain.so.

### 5.6 Not done yet

- Buildings drawn with `simple` / `layered` (the desert tutorial's tower and town, many low buildings) have windows
  painted into opaque textures: they need a mask. The way: a small per-texture mask pack made offline from the
  player's own textures (window panes found by colour and the rectangular grid, verified by eye), keyed like texture
  packs (`win-<key>.png`), read by the same pass.
- Interiors are a pass per window texel; rooms are not shared across neighbouring tiles (a wide office spanning two
  bays shows a wall between them).
- An interior atlas (a few hand-made or CC0 room cubemaps) could replace the procedural rooms for close-ups; the
  procedural rooms are the fallback and the far look.
- Reflections are the game's sphere maps until SSR (wssr1).
- Daytime facades are not in play3: tune the day look from a save in downtown day.

### 5.7 Room variety (wlook1, L2)

The user (11-23, D243 L2): "let's keep interiors on ... Let's make sure we have a few interiors". fs_rm_window.sc now
chooses a room per window, not per texture tile:
- **Rooms, not tiles.** A bay larger than a room is split into rooms of a storey (~3.4 units) and an office's width
  (~4.5 units), up to 3 x 3. Each room's identity is its centre in world space (the decal's position moved to the room's
  middle along the facade's axes, through the modelview's inverse: rooms are in world space), quantised to 1.25 units:
  two bays with the same texture tile on one face, on two faces or on two buildings get different rooms, and a room
  keeps its look across frames, reloads and rollbacks.
- **Types.** Office (desks in a row with monitors that glow, a ceiling grid with every other panel lit, a door or a
  whiteboard, carpet), home (a sofa, a floor lamp with a glowing shade, art in a frame or a shelf, a rug on planks, six
  wall colours), storage (stacked boxes, shelving, one bare bulb, mostly dark), and on the first storey above the street
  (the lowest building foot drawn lately: windows.cpp tracks the prim buffers' height ranges) shops (a counter, spots, a
  neon sign in pink, cyan or amber) and lobbies (a double-height box, stone floor, a reception desk, a plant, a pillar).
  Above the street: 42% offices, 44% homes, 14% storage.
- **The box.** The floor is below the sill and the ceiling just above the head (a lobby's well above it), so a window
  looks into a room rather than a box of its own size; depth 0.9 of the room's width (x1.4 lobbies, x0.8 storage).
- **Light.** Each room its own colour temperature (homes 2700-3000 K, offices 3500-6500 K, lobbies warm, shops cool),
  pulled towards the game's own window-light colour where the game paints the pane lit; on or off: the game's lit panes
  stay lit, and a share by type and time of day beyond them (storage a third, shops and lobbies twice as often). Lit
  rooms are as bright as the game's night layer (the lamp follows the painted window light's luminance, at least a
  typical lit window's), unlit rooms take the city's glow (a dim blue fill), so the skyline keeps the original's glow.
  Faces are shaded (floor 0.72, sides 0.8, ceiling 0.9) and the light falls off into the room.
- **What is behind the glass.** Venetian blinds (anti-aliased: slats finer than a pixel blend to their average, no
  moire), a roller blind glowing when the room is lit, or curtains; sometimes (14% of lit offices and homes) a
  silhouette standing in the room.
- **The frame.** On walls the room's vertical is the world's up and the face normal is made horizontal; only the bay's
  size comes from the derivatives. Room identity, type and light are per room, so they can't flicker per pixel.
- Debug: `HULK_WINDOWS=...,5,...` (the sixth value) shows the room types (blue office, orange home, white lobby, grey
  storage, magenta shop; brighter when lit).
- Pictures: build/wlook1/png/ (`win-*` before/after at game frames 15,000-28,000, `windows-contact.png` a sheet of 12
  windows).
- **Cost.** Windows too small to show a room (most of a skyline: a room under ~4 pixels) take only the room's average
  (type, light and colour) and skip the box, its contents and the blinds, so the variety costs only where rooms are
  seen. A/B turns of 30 frames within one run, play3's night city (game frames 14,400-27,600, 5,940 frames a side),
  1280x960, MSAA 4x, every remastered option on: the windows pass of HEAD (wlook0's rooms) +0.93 ms GPU and +0.29 ms
  render thread, wlook1's +1.10 ms and +0.18 ms. Neither laptop run was free of other lanes' Metal replays (wperf1,
  wgrass1: frames took 30 ms and 57 ms instead of ~10 ms), which inflates every GPU number; relative to its frame the
  new pass costs no more than the old (1.9% against 3.1%). An idle measurement is still owed (`HULK_WINDOWS_AB=30`).

## 6. Decisions for the user

| id | question | options | recommendation |
|---|---|---|---|
| L1 | The remaster's art direction | A grounded modern / B comic / C hybrid "graphic realism" (presets over the same passes) | C as the default, A and B as presets (Look: Original / Modern / Graphic / Comic) |
| L2 | Windows: Interiors as a remastered default | on / off (experimental) | on: renderer-only, cheap, and it keeps the game's lit-window pattern |
| L3 | The next passes, in order | outlines + grade LUT (C's identity), emissive night lights, sky/atmosphere, a window-mask pack for `simple`/`layered` buildings, volumetrics | outlines + LUT first (smallest cost, biggest change), then emissive night |
| L4 | Shadow acne on the desert ground (section 1) | fix in shadows.cpp now / later | now (a slope-scaled bias for the world row; separate from this lane) |
