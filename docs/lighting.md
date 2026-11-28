# Per-pixel lighting and dynamic lights (the app's Lighting and Dynamic Lights options)

wlight1, 2026-11-22 (user: "per-pixel lighting as well as the health orbs giving off light and making the ground
glow"). Remastered-edition picture options of the wasm app's runner (docs/wasm-port.md "The macOS app",
docs/remaster.md 2.5 and 5.3): output only, so game state is the same with them on or off.

## How the game lights things

- **Baked world.** Rooms and the location's static geometry are drawn unlit (`LIT` 0 in 3,368 of 3,390 world shaders):
  their light is in the vertex colours, often with a second modulated texture layer (remaster.md 2.3). 70% of room prim
  groups carry no normals.
- **Fixed-function lights** (vertex program 0, `vs_vp_ff.sh`): characters' props, pickups and the lit shaders. Up to
  four Direct3D lights (directional, point; spots lit as points), in camera space, with the D3D material, the ambient
  light and Blinn specular with a local viewer, evaluated per vertex. The game never sets NORMALIZENORMALS, so a scaled
  model's normals keep their length.
- **The skin programs** (`skin`, `skin_onebone`): four directional lights, specular from the first (half vector with
  the view axis), evaluated per vertex. The Hulk is drawn with `skin` (whulk1: 4 meshes, texture ordinal 1209, the
  first three twice, in the world's pass, at play3's 7,000 and 36,000 alike; hiding the texture with HULK_LIGHT_HIDE
  removes him). The fixed-function path with two-sided lighting (vertex program 6, `vs_vp_ff2s`) draws foliage (the
  city's trees and bushes at 36,000), lit by four directional lights (a key, a fill and two weak ones from the side),
  and props come through vertex program 0 lit. (wlight1 took the vp6 draws for the characters.)
- **Lights the game chooses** per object (`LightsChooser`, remaster.md 2.5). Nothing lights the world dynamically.

## Per-pixel lighting (Lighting: Per-Vertex (Original) / Per-Pixel)

A lit draw (vertex program 0 with LIGHTING on, or a skin program) is drawn with a per-pixel program of the runner's
(`src/platform/wasm/run/app/shaders`, compiled by `tools/rm_shaders.py` into the app; the faithful shaders under
`src/platform/sdl/pddi/shaders` and the Wine image are unchanged):

- the vertex shader is the faithful transform (same constants, bones, texture coordinates, HUD shift) that outputs the
  camera-space position and normal (direction plus the faithful length) and the colour without the lights;
- the fragment shader evaluates exactly the faithful light model per pixel (the same functions, constants and clamps),
  then includes the faithful combiner (`shaders/vp/fs_vp_stage.sh`) with its two vertex colours replaced by the lit
  ones: every combiner key gets a generated per-pixel program `fs_pxcmb_<hash>` beside `fs_cmb_<hash>`, and draws the
  faithful sink combines generically use the generic per-pixel combiner.

At a vertex both give the same colour; between vertices the per-pixel light is smooth (no Gouraud banding on low-poly
characters, round specular highlights). Draws the game counts pixels of (occlusion queries), 2D and orthographic views
and the other vertex programs (refraction, proximity, two-sided) keep the faithful programs.

## Dynamic lights (Dynamic Lights: Off (Original) / Health Orbs)

Health orbs become point lights for the draws around them:

- **Finding them** (identification): in the draw stream, no game state read. An orb is drawn as a pair, twice a frame
  (two passes): a camera-facing sprite (6 transient vertices, already in camera space) and then a 14-vertex mesh with
  no vertex colours and the same texture, both additive (one, one), unlit, fixed function. The mesh's content key
  differs between locations (the tutorial's and the city's), the pair's shape does not, so the pair is the signature
  (found with `HULK_LIGHT_DUMP=a:b:file`, a list of a frame's draws, and `HULK_LIGHT_HIDE=ordinal,...`, which hides the
  draws of a texture). The textures are grey and the draws carry no colour of their own, so the light is the orbs'
  green. The other glowing pickups and effects (the red and blue pickups in the city) are a follow-up.
  The game sorts its blended draws back to front, so the sprite and the mesh are adjacent only in some frames, and
  in either order: an adjacent pair names the mesh (its prim buffer and texture), and a named mesh is an orb by itself
  from then on (wpol1). Counting only adjacent pairs found each orb in some frames and not the next: the flicker.
  The position is the draw's camera-space translation, read from its vertex constants (so the interpolated position
  under the 60/120 fps display rates, which re-draw recorded streams with blended constants).
- **Applying them:** a draw receives the lights through its per-pixel program: a smooth falloff to zero at the
  light's radius (8 units) and a wrapped N.L. For the baked world (unlit draws) the light adds to the vertex colour (the baked
  irradiance) before the combiner's texture modulation, so the ground under an orb glows in its texture's colour.
  Surfaces without normals use the face normal from screen-space derivatives.
- **Order within a frame:** the world is drawn before the effects, so a frame's orbs are known only after the ground
  is drawn. The lights are kept in world space and applied the next presented frame: each frame's camera (the view
  matrix) is taken from the first static world draw, whose modelview is the view. One presented frame of latency in
  world space is invisible for a pickup (they hardly move); the camera's own motion is exact. The draws before the
  frame's first world draw (the Hulk, ~6 a frame) take the lights placed by the last frame's camera (wpol1).
- **Which draws take them** is decided as each presented frame is drawn (`rm::Pass::late`), never when an interpolated
  update's draws are recorded (`packet`), when no frame's lights are known yet: before wpol1, at 60/120 fps with
  Shadows off the ground never took an orb's light.
- Lights are render-only state, rebuilt every presented frame from the stream (nothing to snapshot or restore:
  rollback and HULK_ROLLTEST are unaffected), at most 8 per frame (the nearest to the camera). Only opaque draws of
  the world's pass receive them (not the glows themselves, nor the HUD's models, which have a camera of their own).
- `HULK_LIGHT_LOG=1`: per-pixel draws and lights a frame, and some orb positions; `HULK_LIGHT_ORB=strength,radius`
  tunes the lights (development). `HULK_LIGHT_TRACE=a:b`: one line for each presented frame a..b (counted from the
  start): the camera, the draws that took the lights, the orbs found (camera space) and the lights applied
  (build/wpol1/scripts/lt.py, lt2.py count the frames where a light goes off and on again).

## Characters (Character Lighting: Original / Enhanced)

whulk1, 2026-11-25 (D249, the user's visual pick 4: "the Hulk reads flat and dark at night"). The game draws the Hulk
(and so every co-op Hulk) with the skin vertex program, four directional lights a vertex. His light is mostly the
material's ambient and the key, and in most of play3 it reaches the vertex colour's clamp at 1 over much of his body:
a flat, saturated green that a rim or a normal change added under the clamp does not alter (whulk1's first builds
changed at most 5 of 255 levels). With the row on (remastered default) every skin draw takes the per-pixel program
`fs_px_char` (the generic combiner; with Lighting off too), whose character path (`PX_CHAR` in fs_px_stage.sh, uniform
`u_rmChar[3]`, set by lighting.cpp for each draw; all zero is the faithful per-pixel light) changes the skin model:

- **detail normals** from the base texture: its luminance (stage 0 as the combiner samples it) read at the pixel and one
  screen pixel across and down, as a height, perturbs the normal (Mikkelsen's bump mapping of unparametrised surfaces:
  no tangents, no generated textures or handles, three texture reads). The painted muscle lines and creases read as
  dents under every light. Depth 0.1 camera units for a luminance step of 1 (0.2 looked embossed, 0.04 invisible).
- **wrapped diffuse**: each of the four lights reaches past the terminator ((N.L + w) / (1 + w), w = 0.25, the faithful
  term at full facing), the wrapped part a little warm (1, 0.8, 0.65): a softer, skin-like falloff.
- **a soft shoulder** instead of the clamp: the light is the faithful one up to 0.4, then rolls off exponentially
  towards 1, so the shape of the light stays where the faithful clamp made a flat area (a light of 1 ends at 0.78,
  1.5 at 0.90).
- **a rim** along the silhouette ((1 - N.V)^3), added after the shoulder (up to 2 before the combiner's texture
  modulation, which clamps; so the rim takes the skin's own colour, no white glow): the key light's (the first light, the sun
  or the moon; stronger when it is behind the figure, and only on its side; 0.8 x 0.35 by day, 0.8 at night), the
  night lights' (rm_city.sh's `cityLight` with the normal bent away from the camera: the lamps and signs behind the
  figure, soft-limited c / (1 + max(c)) so that a big glow such as play3's 30,000 mission beacon is not a floodlight;
  0.8) and the night sky's (the rooms' fog colour lifted to a luminance of 1.4 x 0.25 = 0.35, times the night amount:
  0 by day).

Identification is the draw class (the skin programs), not a texture or buffer key: it holds for every location, every
Hulk skin and every co-op Hulk, and any other skinned character gets the same treatment. Output only (no module memory
is read or written); play3's records are identical with the row on or off. `HULK_CHAR_LOOK=key,night,wrap,detail,sky,
knee` tunes the terms (development); `HULK_CHAR_AB=N` times the look off and on in turns (`hulk-app: character
lighting cost:`).

**Co-op tints (wskin2).** A skin draw the module tags as an extra co-op Hulk wearing player 0's skin (a mission's
forced skin; `DrawPacket::instance` = "HULK" << 32 | k, gfx/skins.c, docs/multiplayer.md section 20) takes
`fs_px_chartint`, fs_px_char's program with `PX_TINT`: the combiner's output (its final `saturate(c)`, redefined as
fs_px_soft.sc does) keeps its luminance and moves 60% towards player k's tint (`u_rmTint`; player 1 red, player 2
blue; `HULK_SKIN_TINT=r,g,b,s;r,g,b,s`). It applies whatever Character Lighting is (off: u_rmChar zero, the faithful
per-pixel light). The other programs are unchanged (`PX_TINT` is defined only there).

## Settings and cost

Rows in `port_settings.c` (faithful value off, remastered default on): `lighting` 0/1, `dyn_lights` 0/1/2,
`char_light` 0/1 (rm::kCharLight). With
Shadows on (docs/hdr-shadows.md) every opaque draw of the world pass takes a per-pixel program too, which samples the
sun's shadow atlas (fs_px_stage.sh `pxShadow`); the world pass is identified by the game's pass id
(`rm::currentGamePass`), since the runner's views may split it. Costs are
in docs/wasm-port.md's renderer options table (measured with HULK_RM_LOG / HULK_LIGHT_LOG).
