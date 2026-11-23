# Model replacement: feasibility (wmodel1, 2026-11-22)

Can some of the game's models be replaced, and where would replacements come from: authored by an agent, taken
from other sources, or derived at run time from the player's own disc? This page answers that for the wasm app's
model override layer ([texture-packs.md](texture-packs.md) "Models", [remaster.md](remaster.md) 2.7 and R5).

**Short answer.**
- Props and vehicles: yes, by script, from the player's own dump, today.
- Characters: only by run-time enhancement of the player's own models, or by original models a person makes.
- Other games' models: never.

Everything measured here (dumps, test packs, screenshots) stays under `build/wmodel1/` on the laptop.

## 1. What the models are

Census of the extracted `.p3d` files (`tools/p3d.py` parser, every Geometry/PolySkin/PrimGroup), plus one
`HULK_PACK_DUMP` run of the app: 8,000 scripted frames covering start-up, menus and the desert tutorial.

| Category | Where | Count | Triangles |
|---|---|---|---|
| **World rooms** (buildings, streets, terrain) | `rooms.rcf`, 784 room files in 15 locations | 899 meshes, 23,975 prim groups | 1.18 M in all; a room file has a median of 1,633 and at most 2,461 |
| **Characters** (skinned) | `art/global_*` (the Hulk and his skins), mission and location files, `nischars` | 37 distinct skins (146 copies across files); skeletons of up to 63 joints (the Hulk 38) | 2.2k to 3.8k per skin (`hulk_skin` 3,752; `devil_hulk_skin` 3,836); pedestrians and soldiers 0.6k to 1.2k |
| **Vehicles** | mission and location files | about 35 types, about 110 meshes: each type has *clean*, *damaged* and *husk* (or *rubble*) states, plus colour variants (`milJeepClean1..4`) | 100 to 500 per mesh |
| **Props and breakables** (barrels, fences, towers, rocks, generators, debris chunks) | mission and location files | about 770 distinct meshes | median 45, 90th percentile 182 |
| **Front end / HUD models** | `misc`, `global_nonchar` | about 330 | mostly 2 to 16 |

**Lighting and normals.**
- The world's lighting is baked into vertex colours.
- 70% of room prim groups have no normals.
- Characters, vehicles and dynamic props carry normals.

**Collision is separate data.**
- 805 files carry collision chunks: `WorldCollisionObject` 0x7010025 and `PhysicsObject` 0x7011000. That is 732 room
  files, 58 mission files and 15 location files.
- A draw-time replacement never touches them.
- A file-level `.p3d` override would, so it must never be used (remaster.md section 4, "Model replacement").

### What the dump shows

406 `mdl` keys over the 8,000 frames. By vertex layout:

| Flags | Keys | What they are | Space |
|---|---|---|---|
| 0x2021 / 0x2022 / 0x2032 (vertex colour, 1 or 2 UV sets) | 176 / 97 / 13 | rooms and pre-lit placed props | **world space, one key per placement** |
| 0x2011 (normal, 1 UV set) | 102 | vehicles, dynamic props, character attachments | model space, one key per mesh |
| 0x2191 (weights, indices, normal) | 18 | skinned prim groups | bind pose; at most 25 bones each |

**Finding: one key per placement.** A pre-lit prop placed in the world is baked into world space with its own
lighting. Each placement is therefore a separate buffer with its own key.
- Example: the sandbag mesh `bunker_bunkerBagsShape` appears under 8 keys, all with identical topology and different
  positions.
- So a "replace every sandbag" pack must list every placement, in every location and time of day.
- The tool needed for this is an **instance fitter**. It takes one canonical replacement in model space and solves
  the rigid transform from the canonical mesh to each placement's vertices (Kabsch; the vertex order is the same).
  It then writes one OBJ per key.
- The same prop also occurs as a dynamic (0x2011) object in model space. Replacing it there takes one key.

### How replacement works today (run/app/meshpack.cpp)

- **Mechanism.**
  - `<mods>/<pack>/models/mdl-<key>.obj` replaces one prim buffer's vertex and index buffers at its draws.
  - The game's transform, shader, textures, render state and bone matrices are kept.
  - Draws that an occlusion query counts keep the original mesh.
- **Attributes.**
  - Position, the first UV set and the normal come from the OBJ.
  - Everything else is copied from the nearest original vertex: vertex colours (baked light), the second UV set,
    skin weights and palette indices.
- **What works.**
  - Static meshes.
  - Skinned groups, as long as the replacement stays inside the group's volume and its 25-bone palette.

**What is missing:**
1. **Materials and textures per replacement.**
   - A replacement can only use the original draw's textures through its own UVs. It has no texture of its own and
     no `mat` key.
   - Today a new texture means a `tex` pack entry that replaces the original texture everywhere it is used.
   - Needed: per-model texture slots (glTF materials), or `mat` keys (remaster.md 2.7).
2. **Normals.** They are taken from the OBJ, which works. Rooms have no normals in the original, so a replacement's
   normals are ignored by the unlit world shaders until the remaster's lighting pass exists.
3. **LOD.** The game has none and there is nothing for it in the override layer. Replacements of 10 to 30 times the
   original's triangles are fine for a few props (about 5k triangles cost nothing). Whole districts would need the
   remaster's LOD/far-field work.
4. **Skinning by joint name (R5).**
   - Missing pieces: glTF input, the joint-name map from the `.p3d` Skeleton/MatrixPalette, a manifest replacing a
     whole character's groups, and suppression of the original groups.
   - These need the instance tags (remaster.md 2.6).
   - Without them a character can only be reshaped group by group, inside the original's volume.
5. **Shadows.** Shadow volumes (`ShadowSkin`, `ShadowMeshBuffer`) are separate meshes with their own keys. A new
   silhouette keeps the old shadow unless those keys are replaced too.
6. **Instance fitting** for pre-lit placed props, described in the finding above.
7. **Loader performance.** The nearest-vertex search is brute force: original vertices x new vertices, once per key.
   It is fine at prop sizes; a 60k-vertex replacement over a 3k-vertex original would take a noticeable moment on
   first draw.

## 2. Option A: models authored by Claude (an agent)

**Realistic for an agent:**
- **Parametric hard-surface solids** generated by code: drums, tanks, pipes, crates, bevelled boxes, posts, girders,
  fences, simple vehicles built from boxes and cylinders.
  - The geometry is exact and fits the original's bounds.
  - Normals are clean.
  - The triangle count is whatever is asked for.
- **Higher-poly versions of simple shapes**, such as round things that the game cut to 6 or 8 sides (barrels,
  wheels, pipes, tanks, columns).
- **Smoothing and subdivision of existing low-poly meshes**, computed from the player's own dump on their machine.
- **Procedural textures**: noise, rust, grime, panel lines, as PNGs through the existing `tex` path.

**Not realistic for an agent:**
- Sculpted organic forms: characters, faces, muscles, animals, rocks with character.
- Anything whose quality depends on an artist's eye. Code-built organic shapes look like blobs.
- Skinned characters in particular need topology that deforms well around joints. Generating that is far beyond
  parametric scripts.

**Tooling.**
- Blender 4.4.3 is installed (`/Applications/Blender.app`, not on PATH). Its Python API (`--background --python`)
  could build richer procedural props: bevel and array modifiers, booleans, UV unwrapping, glTF export.
- It was not used for this study. The proof below uses only numpy, so it runs anywhere the tools run.
- Blender is GPL, but files made with it are not covered by that licence.

### Proof (local only)

`tools/mesh_remodel.py` takes one dumped OBJ and writes its replacement.
- **No new textures.** Every new triangle takes its UVs from the original triangle it lies over (nearest, facing the
  same way), so the original texture is kept.
- `fit --shape cylinder|box`: each connected part of the mesh becomes a parametric solid within its bounds.
- `smooth`: curved PN-triangle tessellation. Edges at hard vertices stay straight, so the mesh does not crack.

It was tried on two props of the desert tutorial, installed as a test pack under `build/wmodel1/mods/` and run in the
app (remastered, pack selected). Results:

| Prop | Original | Replacement | Result |
|---|---|---|---|
| `oilBarrel_barrelGroupShape`, 6 steel drums | 228 triangles, 8-sided | `fit --shape cylinder --segments 32 --ribs 2`: 5,376 triangles, rolled hoops | **Clearly better.** Round silhouettes and rims; the original texture's hoop stripe and logo carry over. The texture stays the original's low resolution and is slightly stretched where UVs were extended. A few seconds to make. |
| `taxi_taxi_damageShape` body | 216 triangles | `smooth --levels 2`: 3,456 triangles | **Barely visible.** The car's edges are hard (split normals), so most edges stay straight by design; panels round slightly. Smoothing helps organic or rounded originals, not boxy ones. |

Other results:
- Both loaded and drew correctly on first use, with the right winding and placement.
- Frame rate unchanged (about 54 frames/s unpaced, the same as without the pack).
- wpack1 already showed that the game's state is unaffected by a model pack (checkpoint records identical). Free runs
  of the app are not deterministic (the real-time mixer), so this study compared screenshots only.

**Honest quality verdict.**
- Agent-made hard-surface props at "2005 game plus" detail are achievable and look right in the game's style,
  because they keep the game's textures and baked light.
- They are not "modern AAA". That needs authored textures (normal, roughness) and an artist.
- Per prop type an agent can produce a recipe in minutes.
- The real cost is coverage:
  - finding every key: each damage state, each colour variant and, for pre-lit placements, every instance;
  - checking each prop in the game;
  - for cars, modelling a recognisable vehicle from boxes is possible but looks generic.

## 3. Option B: assets from other sources

**Models taken from other commercial games are copyrighted. They are not usable and not distributable.**
- This holds whatever the game, whether "ripped" files from model-rip sites or fan conversions, and whether the pack
  is bundled or "just a mod".
- The project never downloads, converts, links or recommends them. None were downloaded for this study.
- The same applies to Marvel-licensed assets from other Hulk or Marvel games and films.

**Permissively licensed libraries.** Licences were read from each source's own page on 2026-11-22. Web pages are
treated as data, and each asset's own licence file is still checked before use.

| Source | Licence (as its page states) | Attribution | Fit with this game |
|---|---|---|---|
| **Kenney** (kenney.nl) | "public domain licensed (CC0)", commercial use allowed | not required; don't use the Kenney logo on its own | low-poly, stylised and flat-coloured: wrong style for a realistic 2005 city, good for placeholders |
| **Quaternius** | CC0 or "QAL" per kit; QAL "does not allow direct reselling" | not required | stylised low-poly; same style problem |
| **Poly Haven** | "all licensed as CC0"; may be redistributed, even in sold products | not required | photoscanned realistic props, barrels, crates and furniture; the best fit in style. Real-world scale (metres). Usually 5k to 100k triangles, often with 2k to 8k PBR textures: they need decimating and the textures need baking down |
| **ambientCG** | "CC0 1.0 Universal"; raw files may be included in a game | not required | mostly textures (PBR materials) and a few models: good for procedural or retextured props |
| **Sketchfab** | per model, chosen by the uploader; the store licences ("Standard", "Editorial") forbid redistribution "as a stand-alone file". Its terms say the uploader "is solely responsible" and Sketchfab makes no warranty of the uploader's rights | CC-BY needs credit | **high provenance risk**: much of it is fan-ripped game content mislabelled as CC. Use only from uploaders with a clear original-work record, never game-character content |

**Fitting library assets.**
- Scale: the game's units look like metres (a jeep is about 5.1 units long), so scale matches roughly.
- A library model must be aligned to the original's bounds and pivot. `fit` could be extended with an `--import`
  mode that does this.
- Material: the replacement must bring its own texture. That needs the per-replacement material slot (missing item
  1). Without it, a Poly Haven barrel would be drawn with the game's barrel texture through the barrel's own UVs,
  which looks wrong.

**Distribution rules.**
- CC0 assets may be bundled.
- CC-BY assets may be bundled only with credit text in `pack.json`.
- Anything else stays user-installed.
- The project itself ships no content packs (D11 "tools only").

**Character IP.**
- The Hulk, Banner, Blonsky/Abomination, Ross, Mercy and the other characters are Marvel's IP (characters and
  trademarks). The pedestrians and soldiers are the game developer's copyrighted designs.
- Replacement character models must be original designs, or supplied by the user for their own use.
- The project never creates, commissions or ships lookalikes of trademarked character designs. "A better-looking
  Hulk" made from scratch is a lookalike of a trademarked design.
- **The safe route for characters is run-time enhancement of the player's own disc models on their own machine**
  (option C). Nothing new is distributed; the player's copy is drawn more smoothly.

## 4. Option C: run-time enhancement and modder tooling

**Run-time enhancement pass** (remaster build, a toggle; no new art, no IP issue, covers every model).
- **Smooth normals** where the original has none or has faceted ones. The 70% of room groups without normals need
  this for any lighting work anyway (remaster.md section 4, PBR).
- **PN-triangle or Phong tessellation** on characters and round props, done at upload in the backend.
  - It is the same algorithm as `mesh_remodel.py smooth`, applied per buffer and cached.
  - Characters are the best case: they have smooth normals, so the whole surface curves. The Hulk's 3.7k triangles
    would become about 15k (level 1) to 60k (level 2).
  - The skin weights come from the original vertices by barycentric interpolation, which is exact for PN triangles.
    This avoids nearest-vertex lookup.
  - Silhouettes (shoulders, arms, heads) visibly improve. Texture resolution is unchanged; that is the texture
    packs' job.
  - Risks:
    - Hard-edge cracks: avoided by the hard-vertex rule.
    - Fingers and other thin parts swelling: level and parameters are tuned per buffer.
    - Shadow volumes keep the old silhouette until they are tessellated too.
- **Generated normal maps**: bake detail from the texture's luminance (a height estimate). This is cheap but
  approximate; it suits world surfaces under PBR.
- **Cost.** It all runs in the backend at buffer upload, like the texture packs. Nothing reaches game state.

**Modder tooling** (the community makes packs; the project ships tools, not content).
- Dump: done (`HULK_PACK_DUMP` OBJ).
- Name the keys: a `tools/` script that matches dump keys to `.p3d` mesh, prim-group and shader names on the
  player's machine. This study did it by vertex count; matching by content hash would be exact.
- Import to and export from Blender: OBJ works today. glTF with joint names and materials is R5.
- Instance fitter for pre-lit placements (section 1).
- `mesh_remodel.py` as the scripted path.
- **Recipe packs.**
  - A shareable pack holds no game data: only geometry recipes or original meshes plus original textures, keyed by
    `mdl` keys.
  - The tool builds the final OBJs on the player's machine from their own dump.
  - This keeps UVs and shapes derived from game data off the internet.
  - Whether the bare keys (hashes of game data) may be published is a question for the user. Dolphin and PCSX2
    packs publish such hashes routinely.

## 5. Recommendation

| Step | What | Effort (agent lane-days) | Risk |
|---|---|---|---|
| 1 | **Run-time smoothing pass** in the app's remaster options: normals for normal-less groups, PN tessellation for skinned and round groups, weights by barycentric interpolation, shadows tessellated alike, cached per key | 3-5 | thin parts swelling (tunable); GPU cost on handhelds (a level setting); checkpoint records must stay identical (runner-only, as wpack1) |
| 2 | **Key naming tool** (dump key to `.p3d` mesh, prim group and shader, local) and an **instance fitter** for pre-lit placements | 2 | the hash recipe must match the sink's byte for byte (texpack_convert did the same for `tex`) |
| 3 | **Per-replacement materials**: an OBJ `mtllib`/`usemtl` or glTF texture, loaded through texpack's decoder and cache, bound in place of stage 0 | 2-3 | layered and reflective shaders need rules for the second stage |
| 4 | **Agent prop recipes** for about 20 round and boxy prop types: drums, tanks, pipes, girders, fences, crates, posts, generators | 3-4 | coverage of every key and damage state; quality ceiling "clean 2005-plus" |
| 5 | **R5 skinned replacement** (glTF, joint names, manifests, group suppression, instance tags) | 10+ | the largest item; only useful for user-supplied character models |
| - | Library assets (Poly Haven CC0) | after step 3; 0.5 per prop to fit and decimate | style mismatch; per-asset licence check |
| - | Other games' models | **never** | copyright |

**Recommendation.**
- Do steps 1 and 2 first. They improve every character and round prop for every player, with no content and no IP
  question.
- Then steps 3 and 4 for props.
- Leave characters to step 1 (smoothing the player's own models).
- Park step 5 until there is a concrete user-made character to support.

**Decisions for the user:**
1. **Run-time smoothing pass** (step 1) as a remaster toggle, default off?
   Recommendation: yes, about 4 lane-days.
2. **Per-replacement materials and instance fitter** (steps 2 and 3)?
   Recommendation: yes, after step 1.
3. **Agent-made prop recipes** (step 4): commit the generator recipes (no game data) under `tools/`, outputs built
   locally?
   Recommendation: yes for a small set, to prove the recipe-pack format.
4. **Library assets**: allow CC0 sources (Poly Haven, ambientCG; Kenney/Quaternius for placeholders only) in
   user-installed packs, and refuse Sketchfab assets in anything the project points to?
   Recommendation: yes.
5. **Publishing**: may a pack that lists `mdl`/`tex` keys (hashes of game data) be shared publicly?
   - This is the Dolphin norm but still a choice.
   - **Check with your employer before any public release of packs, tools or binaries** (standing caution).
   Recommendation: keep everything local until that check.
6. **Characters**: confirm the rule "no new character models from the project; only run-time enhancement of the
   player's own models, or the user's own original models".
   Recommendation: yes.
