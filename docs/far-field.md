# The far-field layer (wr2, D236 item 4: design and prototype)

remaster.md 3.3 (4): beyond the rooms the game keeps loaded, the renderer draws the rest of the location itself,
straight from the player's disc, without the game knowing. This note is the design and the state of the prototype in
the macOS app (run/app/farfield.cpp, Video Options > Far Field: Off / On (Experimental); remastered default Off).

## Why it has to be the renderer's

- The game's streaming (`CWorldStreamManager`, remaster.md 3.4) decides which rooms are resident from the anchor's
  position and fires room load / unload events into ambients, trigger volumes and smart props. Loading more rooms
  through the game changes the simulation, so the far field never goes through it.
- World::Render 0x1c88f0 skips resident rooms beyond the draw distance (fade start 270, band 25; the app's Draw
  Distance sets 400 or 700 while it runs, wvid1), and the game keeps rooms resident only to about 390 units. Beyond
  that, today, there is sky.

## Data (counts from the player's disc; nothing is committed)

| location | rooms | triangles | room files |
|---|---|---|---|
| outskirts_dusk / _day | 188 / 181 | 300k / 295k | 29 MB |
| downtown_dusk / _night / _day | 128 / 128 / 56 | 209k / 187k / 99k | 25 / 25 / 12 MB |
| desert_tutorial_dusk | 27 | 44k | 4.5 MB |
| the other 9 | 3..18 | 2k..30k | < 3 MB |

Locations are 1,400 to 4,000 units across. Every room file (rooms.rcf `art\locations\<loc>\<prefix>_rNNN.p3d`) is in
world space; base textures are in districts.rcf (`<prefix>_district_N.p3d`), the rooms carry their own lightmaps
(docs/formats/p3d.md "Locations"). A whole location is at most 300k triangles: one draw of everything is cheap on
any target GPU; the cost is the number of draws (below).

## How the prototype works

All of it is an rm pass (rm_pass.h); the module's memory is never read or written.
1. **Index** (a worker thread, when the option is first turned on): every room file of rooms.rcf (read straight from
   the archive by its name table, docs/formats/rcf.md), every vertex position on a quarter-unit grid, hashed ->
   (location, room), sorted (all locations: 1.3 M positions, 0.2 s). Three findings shaped it:
   - the game splits a prim group into several prim buffers (33 to 139 vertices each in downtown), so whole groups
     cannot be keyed by their vertex count: 7 of 8 buffers never matched;
   - the positions the game hands the sink differ from the file's in the last bits ((x, 4.8e-06, z) for (x, 0, z)),
     hence the grid;
   - downtown day, dusk and night (and the tutorial and the outskirts) share most of their geometry, so a position
     names every location that has it, and the location is decided by votes.
2. **Match**: every prim buffer the game writes (`Pass::vertices`) is looked up by up to 8 of its vertices spread over
   the buffer; per location, the room at least half of them name is the buffer's. The location is the one most live
   room buffers belong to. In downtown about 1,600 of the game's buffers are rooms', and ~15% of its buffer draws a
   frame; the rest are props, cars, characters and effects. This answers remaster.md's open measurement (which rooms
   are resident and drawn) without reading game memory: the game draws 2 to 8 rooms a frame in downtown.
3. **Load** (a worker, per location): every room's prim groups (positions, vertex colours = the baked lighting, uv
   sets 0 and 1, strips turned into lists, 16-bit indices) and the textures their shaders name (TEX, TTEX). Most
   shaders are defined in the location's district files, not the rooms: those are read too. DDS payloads are
   uploaded as the game would upload them (rows as stored). Made in the sink between frames (downtown_night: 128
   rooms, 187k triangles, 910 textures, 40 ms to parse, 8 ms to make).
4. **Draw**: at the frame's first room draw in the world pass (the scene pass with the most room draws last frame:
   another scene pass draws rooms for the map), the far rooms are submitted just before it (`Pass::draw`, so it works
   for interpolated presents too), each prim group as a copy of that draw's packet: the same pipeline (combiner and
   vertex program) and the same constants, which for a room draw are the camera's transforms (rooms are in world
   space) and the fog. Only the buffers, the counts and the stage textures change. A far room is one none of whose
   buffers the game drew in the last two frames, with its bounds beyond (draw distance + 25) x 1.3 horizontally from
   the camera (1.3: downtown's height scaling of the distance).
- `HULK_FARFIELD_DEBUG=1` draws the far field magenta and untextured, to see it in a screenshot.

The game state is unchanged with it on (checkpoint records byte-identical in the scripted run and in play3).

## What the prototype does not do yet (the plan to finish it)

1. **Draw count.** Each prim group is a draw: outskirts_dusk is about 2,900 draws a frame (the game itself makes
   ~200), 1.8 ms of render-thread time and 3.6 ms of GPU at 640x480. Merge each room's groups by (texture, lightmap)
   into one buffer at load (32-bit indices or split at 64k vertices), then whole districts by texture: expected
   about 100 draws.
2. **One template.** The copied draw's combiner decides the look: a `simple` far group drawn through a `layered`
   template gets white for the lightmap stage, and the reverse loses the lightmap. Keep one template per shader kind
   (simple / layered / layeredReflect) from the frame's room draws, and use the matching one.
3. **Fog.** The game's fog planes (scripts: 30..900, 30..1200) hide everything beyond ~1,200 units: the far field is
   only visible with Fog Reduced (x2.5) or Off. Give the far field its own fog (the game's colour, planes beyond the
   location's extent) once a template per kind exists.
4. **Handover.** No fade: a room appears at the threshold as the game's own copy fades out (its f58 alpha). Draw the
   far copy with the complementary alpha over the band, or start it at the end of the band only.
5. **Far plane.** The game's projection ends at 3,000 (CGameCamera 0xa9400), which clips the far side of the two big
   locations. The render-side far plane (remaster.md 3.3 (3)) belongs in the sink's projection for the far draws.
6. **Destruction.** The far field draws the intact city; buildings the player destroyed reappear beyond the
   threshold. Read destruction state per room later, or skip rooms the game has drawn damaged this session.
7. **Props and dynamic objects** (cars, people, smart props) are never in the far field.
8. **R1.** Under the RHI the far field is a pass of its own with real instancing and its own fog/LOD; the loader,
   the index and the match carry over as they are.

## Files

- src/platform/wasm/run/app/farfield.cpp: the index, the match, the loader, the pass.
- `HULK_RM_LOG=1` logs the index, the location, the load and the far draws a frame.
