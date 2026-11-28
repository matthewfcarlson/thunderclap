# Night lights and atmosphere (the app's Night Lights and Atmosphere options)

wlook2, 2026-11-23. User decision D243 (11-23): the remaster's look is the hybrid direction of docs/look.md (C), with
open-world superhero city games as the inspiration: a grounded, glossy, dense modern city with strong night lighting
and atmosphere. This lane owns the night lights and the atmosphere. Both are rm passes of the wasm app's runner
(run/app, docs/hdr-shadows.md "Views between the game's passes"): output only, nothing that draws reads or writes the
module's memory, so the game's state and play3's checkpoint records are the same with any setting. General techniques
only (tiled forward lighting, analytic in-scattering, exponential height fog); no other game's assets or shaders.

| row | values (faithful first) | remastered default | Quality index |
|---|---|---|---|
| `night_lights` Night Lights | Off (Original), On | On | rm::kNightLights = 13 |
| `atmosphere` Atmosphere | Original, Enhanced | Enhanced | rm::kAtmosphere = 14 |

## 1. Night lights (run/app/nightlights.cpp, shaders/rm_city.sh)

### Where the lights come from

The night city's light sources are in the game's own draw stream, drawn after the world's opaque traversal: street
lamps, signs, vehicle lights and the mission markers carry additive glows (blend one/one or src-alpha/one, unlit, fixed
function, depth tested), most of them camera-facing sprites of 6 transient vertices (`HULK_NIGHT_DUMP`, play3's
downtown at present 24,150: white lamp halos 2.6-3 units across about 12 units above the street, red and blue
challenge markers 5.6 units across, a green marker beam high above). Every such glow of the world's pass is a light:

- **position**: the sprite's centre (its transient vertices, which the runner now hands the passes:
  `rm::transientVertices`) or a small buffer's bounds centre, through the draw's modelview, then into world space by
  the frame's view (the first room draw's modelview, as the lighting and shadow passes take it);
- **colour**: the glow texture's mean colour (texpack.cpp now keeps the mean of every small texture's top level, by
  ordinal: `texpack_mean`) times the vertex colour; white glows (lamps, headlights) at full strength, saturated ones
  (signs, markers, tail lights) at 0.6;
- **radius**: 9 x the glow's world size, between 10 and 30 units (a lamp head ~12 units up must reach the street).

Excluded: glows without depth test (lens flares, the HUD), outside the world's pass, streams of more than 12 vertices
(rain, particle ribbons), glows larger than 14 units or farther than 200, and dark ones. Glows within a unit of each
other in one frame are one light (sparks and particle swarms).

### Steady from frame to frame

The game sorts its blended draws back to front, so the order of the glows changes from frame to frame (wpol1); this
pass never uses draw order or adjacency. Each frame's glows are matched to the lights already known in world space by
distance (within the larger of 1 unit and 0.6 x the glow's size). A light that has stayed within 1 unit of where it was first seen over four or
more frames is static: it outlives frames in which its glow is not drawn (a lamp's pool stays on the street while its
head is above the picture), for up to 3,600 presented frames and 220 units, but goes once its place is on screen within
80 units and nothing has been drawn there for 90 frames, 3 s (a lamp the Hulk knocked down). A moving light (a car's)
lives only while drawn (two frames of grace). Every light fades in and out over ~8 frames; positions of static lights are
low-passed, colours of all of them; a static light's colour and size follow its glow up at once and down slowly
(wwin3: the game dims or hides a lamp's glow while something is in front of it, its occlusion query, and with 12 frames
and a symmetric low pass the lamp's pool and the facades it lit dimmed and faded out and back whenever the Hulk or a
thrown object passed before the lamp).

### How they light the world (tiled forward lighting)

Each presented frame, at its first room draw (when the camera is known), the lights in the view frustum are sorted by
`brightness x radius / (distance + 4)` and the first 128 (64 on Android) are written to a 64 x 64 RGBA32F texture: three
texels a light (camera-space position and radius, colour and kind, a spot's direction or a shop front's axis: wlook4),
then a per-screen-tile index (tiles of 32 pixels or more, at most 32 x 32 tiles and as many as the texture holds; 24
lights a tile, 8 on Android; 16 before wlook4): each light's bounding sphere is projected to a screen rectangle and
added to the tiles it covers. The per-pixel lighting (lighting.cpp, fs_px_stage.sh) reads the pixel's tile
(`gl_FragCoord`) and sums its lights: a smooth falloff to zero at the radius with an inverse-square shape near the
light, a wrapped N.L, and for static lights (lamps) most of the light downwards (30% sideways), so a lamp makes a pool on
the street and a softer spill on the walls beside it. For the baked world the light adds to the vertex colour before the
combiner's texture modulation (the light takes the street's own colour, like the health orbs' light, docs/lighting.md);
for lit draws (characters, props, cars) it adds to the lights' diffuse sum. Every opaque draw of the world's pass that a
light's sphere reaches takes a per-pixel program (with Shadows on, all of them already do).

The light is scaled by the night (0 by day: the rooms' fog luminance above 0.30; 1 below 0.12, downtown night 0.087).
The halos themselves keep drawing as the game draws them; with HDR on they bloom as before.

## 2. Atmosphere (run/app/atmosphere.cpp, shaders/fs_rm_sky.sc, fs_rm_atmos.sc)

### The sky

The game draws its sky dome first in the world's pass: opaque, unlit, fixed function, one stage (texture x vertex
colour, linear fog), with a projection of its own (other near and far planes than the rooms'). That draw keeps its
packet and takes the runner's program (vs_px_ff + fs_rm_sky.sc), which draws the dome exactly as the game does and then
re-grades it by the view direction in world space (the dome's own modelview, inverted):

- a deeper, bluer zenith and a lifted horizon (the city's glow at night, haze by day);
- the dome's clouds (its brighter texels) lit from below by the city: a warm sodium-and-white glow strongest near the
  horizon, tinted by the location's fog;
- stars where the dome is dark and clear, fading into the glow towards the horizon, with a slow twinkle;
- the moon (night) or the sun's glow (day) in the direction of the location's key light (the strongest directional
  light of the lit draws, the same light the sun shadows use), so the moon and the shadows agree; above 1 under HDR, so
  it blooms.

The game's other sky draws (lightning bolts, flares, the moon-like sprites) draw over it as before. The dome writes no
depth while this is on (its pixels stay at the far plane, so the air below leaves them alone).

### The air

Over the world's opaque draws and before its translucent ones (where ambient occlusion runs; after it), a full-screen
view reads the scene's depth (kept readable while Atmosphere or AO is on) and adds, blended one / src-alpha:

- **exponential height fog** above a ground estimate (the lower quartile of the lowest points of the room buffers drawn
  this frame, smoothed): dense in the streets, thin over the roofs, integrated in closed form along each view ray;
- a little **aerial perspective** (uniform extinction) so distance reads;
- both in the location's fog colour, darkened and warmed by the city's glow at night, brightened towards the sun by
  day, starting a few units from the camera (the Hulk stays crisp);
- the **lamps' glow in the mist**: each night light's in-scattering along the view ray (closed form of a point light's
  1/d^2 in a uniform medium, windowed by its radius), from the same tile lists, so every lamp has a soft volume of light
  around its head and over the street, against the sky too.

This is on top of the game's own linear fog, which stays the faithful baseline: the Fog row still sets it (Original /
Reduced / Off), and scales this one (Reduced halves the height fog and aerial perspective, Off removes them; the lamps'
glow stays at half). Draw Distance is untouched. (wsweep1: Reduced scales the game's planes x2.5 at night and, by day, keeps the start
and takes the end x1.15, by rm::nightAmount; docs/look.md "Canyon wall stripes".)

## 3. Results, checks and cost

- **What it looks like** (play3 on Metal, render 2x, MSAA 4x, every remastered option on, Night Lights and Atmosphere
  off / on; build/wlook2/shots, never committed: `before-*` / `after-*` / `cmp-*` at game frames 6,000-24,000). From
  the rooftops (22,000) the night streets now carry warm pools under every lamp and red tail lights on the roads; at
  street level (24,000) the lamps make pools on the paving and the grass, the Hulk and the path, each lamp head has a
  soft volume in the mist, and the sky keeps the game's deep blue with a narrow warm glow along the skyline. By day
  (the desert, 6,000-9,000) nothing changes but a slightly deeper zenith and a little aerial perspective.
- **Steady**: with lights matched by place, static lamps stay lit across frames (`HULK_NIGHT_DUMP` cache: every lamp
  seen hundreds of frames, no light dropping and returning); a light whose glow leaves the screen keeps lighting.
- **Game state**: play3 to 60,000 with `null`, settings pinned `remastered=1,lighting=1,dyn_lights=1,hdr=1,ao=1,
  shadows=2,msaa=4,windows=1,reflections=2,night_lights=1,atmosphere=1`: records identical to the control (test 111752:
  candidate 111751, control 111750 at a5cf6f6d3, mac2; before the rebase tests 111737 and 111743 against 111722 at
  a11bc7cbd, likewise). `tools/wasm_android.py build` links libmain.so with both passes (the shaders build for spirv
  and essl).
- **Cost** (play3's night city, game frames 15,000-24,600, Metal, render 1280x960, MSAA 4x, every remastered option on;
  each pass off and on in turns of 30 frames within one run, `HULK_NIGHT_AB=30` / `HULK_ATMOS_AB=30`). The laptop's GPU
  was shared with two other lanes' Metal runs throughout, so its frame times (~90-100 ms against ~10 ms idle in
  docs/hdr-shadows.md) are mostly waiting; read the differences as relative upper bounds:

| option | GPU a frame, off -> on (loaded) | relative | render thread |
|---|---|---|---|
| Night Lights | 96.5 -> 100.6 ms (+4.1) | +4% | +0.07 ms |
| Atmosphere | 90.4 -> 99.4 ms (+9.1) | +10% | +0.13 ms |

  On an idle M-series laptop that is roughly +0.4 ms (night lights) and +1 ms (atmosphere) on the ~10 ms frame.
  Estimates for the targets: the night lights cost a tile lookup and at most 16 light evaluations (8 on Android) per
  pixel of the per-pixel programs, plus a 64 KB texture upload a frame: Deck (800p) ~0.4 ms, an Android handheld
  (720p) ~0.6 ms. The atmosphere is one full-screen pass (depth read, closed-form fog, up to 16 / 8 lamp
  in-scatterings) blended into the scene target (per sample under MSAA, most of its cost here) and a few ALU ops in the
  sky's own draw: Deck ~0.6 ms, Android ~0.8-1 ms (without MSAA there). Both fit the budgets of docs/look.md section 3.

## 4. Shop fronts and headlights (wlook4)

Round 2 of the night lights (the reference: open-world superhero games' night city, general techniques only): the
light that lit shop windows and lobbies throw onto the sidewalks, and cars' headlights on the road ahead. Both are
more lights in the same tiled list, so every per-pixel program (the world's opaque draws, characters, cars, grass)
takes them as before, and nothing samples noise: they are analytic, the same with MSAA or no anti-aliasing as with TAA.
The light record has a third texel now (rm_city.sh: 3 texels a light; up to 24 lights a tile, 8 on Android).

### Shop fronts (a segment light along a facade's foot)

- **Where.** A building draw (`layeredReflect` with its faithful combiner, whose facade alpha is 0 on the glass:
  docs/look.md 5.1) is read once per prim buffer pair from the buffers the runner already sees written (nightlights.cpp
  keeps the positions and two uv sets of buffers written once, and the index buffers): every wall triangle (normal
  within 0.2 of horizontal) whose two lowest corners lie at the buffer's foot gives its bottom edge, split into pieces
  of at most 10 units. A piece is a shop front when the band 0.6-2.2 units above it is glass: the facade texture's
  alpha (texpack.cpp now keeps a 16 x 16 grid of the mean alpha of every small texture with partial alpha:
  `texpack_alpha_grid`), sampled through the stage's own texture coordinates and transform at points a unit apart.
  Pieces of one place found in two draws count once.
- **On the street.** The walls' feet are kept on a 4-unit grid; a shop front whose foot is more than a unit above the
  lowest foot within 8 units stands on an upper section of its building, not on the street, and is left out. (Rooftop
  structures with glass at their foot, as on play3's roofs at 15,000, count: they read as lit roof rooms.)
- **Lit and colour** by the piece's place (a hash of its position, stable across frames, reloads and rollbacks): 72%
  lit; warm 2,700-3,000 K interiors most often, a neutral white, a cool white, now and then a pink or cyan neon tint
  (the interiors' palette, fs_rm_window.sc's `winKelvin`), scaled by the piece's share of glass.
- **The light** is a segment along the facade 1.7 units up: the falloff from the segment's nearest point (radius 9),
  soft over 2 units past each end so the pieces of one facade join without a seam, strongest out of the facade (a
  wall beside it takes 30%), with the night lights' wrapped N.L. Within 80 units of the camera, fading out over the
  last 28; the 56 strongest (20 on Android) of the frame's view compete with the lamps for the 128 (64) places.
  Shop fronts do not scatter in the mist.

### Headlights and tail lights (spots)

- **Cars** are lit opaque draws of the world pass whose prim buffer's box, through the draw's modelview, is car-sized
  (one model axis up, 2.8-9 units long, 1.1-3.6 wide, under 4 high; the body is the biggest of a car's parts): its
  length axis in world space. play3's cars are `simple` lit draws with their length along model x.
- **The game draws tail light glows but no headlight glows.** A red glow at one end of a car is a tail light: a spot
  shining backwards (radius 7, a hemisphere, red); its headlight is synthesised at the car's other end, mirrored
  through the car's middle: a warm white cone (radius 22, outer cosine 0.8, tilted 0.1 down) lighting the road ahead.
  So a car with its lights on (moving traffic, the parked police cars) has headlights, a car without tail glows none.
  A white glow at a car's end (none in play3) would be a headlight itself. A light that leaves its car keeps its
  direction from its own motion near the street (headlights forwards, tail lights backwards); moving lights are matched
  across frames where their motion puts them.
- **In the mist** (Atmosphere Enhanced) a spot scatters as the glare where the view ray passes the lamp facing it, and
  as a beam where the ray crosses the cone's axis (a gaussian across the cone widening with distance, fading to its
  end): headlight beams in the night air.

### Results, checks and cost

- **Pictures** (queue Metal, mac2, the player's settings: MSAA 2x, render 1080, FSR 1, aspect 4:3, every remastered
  option on; build/wlook4/m, never committed). Shop fronts: warm pools on the paving and lawns before lit lobbies and
  shop windows and a glow up the wall under a lit window band (16,500, 22,200), a warm spill before a rooftop
  structure's lit shutters (15,000). Headlights: the police cars at the crossing (20,500) throw beams on the road ahead
  of them; a car parked behind a barrier (22,200) lights the barrier. Day frames unchanged.
- **Game state**: play3:2000 with the candidate against its control: records identical (test 111970, mac2).
- **Cost** (`HULK_NIGHT_AB=30`, the whole pass off and on in turns within one run, see the table in section 3 for the
  method), studio, the player's
  settings at 1280x960, candidate and control in one job (111977): over the night city (game frames ~15,000-24,600,
  from the cumulative cost lines) the Night Lights pass costs 0.63 ms of bgfx GPU time a frame with shop fronts and
  headlights against 0.32 ms before (+0.31 ms; bgfx's frame timer reads ~1.8x high, docs/performance.md); over the
  whole run (day included) 0.29 against 0.15 ms. The render thread is unchanged (the shop fronts are read once per
  building buffer; placing them is a loop over the known ones, ~1,800 in the city). On the M3 Air that is roughly
  +0.5-1 ms on the ~7.5 ms remastered frame, inside the 12 ms budget; Deck/Android pay for at most 8 more light
  evaluations a pixel where shop fronts and headlights cover a tile (Android keeps 8 a tile, 20 shop fronts).

## 5. Not done yet

- **Upper floors.** Only shop fronts at the street spill light; lit offices above light nothing (their spill would
  reach only roofs and the facade itself).
- **Cars without tail glows** (parked with their lights off, or a model the game gives none) get no headlights.
- **Volumetric shafts.** The lamps' in-scattering is unshadowed (a glow volume, not shafts); froxel shafts are left out
  for cost (Deck and Android).
- **The moon** sits at the key light, which in play3's city is high (54 degrees): rarely in view. Dusk and day
  downtown are untested (play3 has neither).
- The sky dome is found by shape; a location whose dome is not a shader-kind-0 mesh around the camera keeps the game's
  sky (the air pass then treats view depth beyond 600 units as sky).

## 6. Knobs (development)

- `HULK_NIGHT=strength,radiusScale,minRadius,maxRadius,dayStrength,warm` (1.5, 8, 10, 18, 0, 0.35; wsweep1, from 3, 8, 10,
  24, 0, 0.7: docs/look.md "The night wash"); `HULK_NIGHT_LOG=1` (sources,
  lights placed, shop fronts and vehicle lights among them, cars a frame, cache, night estimate, fog colour, and the
  shop fronts' reading and placing counts every 300 frames); `HULK_NIGHT_SHOPS=strength,radius,far,lit,height` (1.8, 9,
  80, 0.72, 1.7); `HULK_NIGHT_CARS=headStrength,headRadius,headCos,headTilt,tailStrength,tailRadius` (0.6, 22, 0.8, 0.1,
  0.6, 7); `HULK_NIGHT_DUMP=a:b[:path]` (every source of
  presented frames a..b); `HULK_NIGHT_AB=N` (cost turns).
- `HULK_ATMOS=sky,stars,horizon,fogNight,fogDay,falloff,aerial,lamps` (1, 1, 0.5, 0.006, 0.003, 0.04, 0.0006, 0.035);
  `HULK_ATMOS_LOG=1`; `HULK_ATMOS_DUMP=a:b[:path]` (the draws before each frame's first room draw: the sky's
  identification); `HULK_ATMOS_AB=N`.
