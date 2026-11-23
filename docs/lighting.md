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
  the view axis), evaluated per vertex. play3's tutorial and city frames draw none: Hulk and the other characters come
  through the fixed-function path with two-sided lighting (vertex program 6, `vs_vp_ff2s`), lit by four directional
  lights (a key, a fill and two weak ones from the side), and props through vertex program 0 lit.
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

## Settings and cost

Rows in `port_settings.c` (faithful value off, remastered default on): `lighting` 0/1, `dyn_lights` 0/1/2. With
Shadows on (docs/hdr-shadows.md) every opaque draw of the world pass takes a per-pixel program too, which samples the
sun's shadow atlas (fs_px_stage.sh `pxShadow`); the world pass is identified by the game's pass id
(`rm::currentGamePass`), since the runner's views may split it. Costs are
in docs/wasm-port.md's renderer options table (measured with HULK_RM_LOG / HULK_LIGHT_LOG).
