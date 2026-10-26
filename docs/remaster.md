# Remastered renderer (R0: design and feasibility)

**Vision (user, 2026-10-26).** The project builds two versions of the game from one tree:
- **The faithful port** is the 2005 game, exact. It is replay-checked against the Xbox. Its simulation never changes.
- **The remaster** answers "what would this game be like if it were made today?". It goes well beyond graphics: new
  mechanics such as co-op (section 6.1), modern systems and rendering are all in scope.

The remaster is therefore free to change gameplay. The render-only rule and the "replay equal to the normal build" gate
in the sections below now apply only to the remaster's *faithful-gameplay preset*. That preset is the baseline its
graphics work is tested against; it is not a limit on the remaster as a whole. Gameplay changes sit behind their own
flags (`HULK_COOP` and later ones), with the remaster's own tests. They never touch the faithful port, and every
verified source keeps its proof with the flags off.

**Pace.** The effort figures below were written in human-team weeks. This project went from an empty repository to
every function verified, a Wine build matching the Xbox replay to frame 8,640 and a linking arm64 build in under a month.
Read the stage sizes as relative weights, not schedules.

Written 2026-10-25 (R0). Design study for a second, "remastered" renderer for the native port. It adds ray tracing,
reflections, PBR materials, full mip chains, fog control, longer draw distances and replacement models. The faithful
pddi/bgfx backend ([graphics-backend.md](graphics-backend.md)) stays the reference. Nothing here is built yet. No
source or tool was changed for this study.

Inputs:
- The docs: [graphics-backend.md](graphics-backend.md), [shaders.md](shaders.md), [texture-packs.md](texture-packs.md),
  [wine-widescreen-60fps.md](wine-widescreen-60fps.md), [native-mac.md](native-mac.md), [platform-boundary.md](platform-boundary.md),
  [wine-replay.md](wine-replay.md), [subsystems.md](subsystems.md) and [formats/p3d.md](formats/p3d.md).
- The verified sources cited below (`matches/`, `equivalent/`, the generated tree `build/tree/`) and the backend in
  `src/platform/sdl/pddi/`.
- Counts from the player's own data. The probe scripts are in `build/remaster/probes/` (local, untracked) and print
  only counts.
- Web research on the graphics APIs and libraries, checked 2026-10-25. Each claim is marked *verified* (with a source)
  or *unverified*.

## Recommendations in one table

| Question | Recommendation |
|---|---|
| Two builds | `HULK_REMASTER` is a compile-time flag of the **platform layer only**. The normal build has no remaster code. MSVC and the verified game sources never see the flag (one optional exception, rule G3 below, is proven to leave the MSVC objects unchanged). |
| Where to cut | **Keep the pddi cut.** Split today's backend into (a) a backend-neutral pddi front end: the 23 classes, the D3D-state model, combiner keys, constants and draw log; and (b) a **draw sink**. The normal build's sink is today's bgfx code. The remaster's sink records the whole frame as packets and hands it to a new renderer. Every pddi draw already funnels through one function, `bgfxContext::draw(shader, DrawSource)` (`src/platform/sdl/pddi/bgfx_draw.cpp:889`). |
| Graphics API and library | **A small RHI of our own with native Vulkan 1.3 and native Metal 3 backends**, using inline ray queries only. Libraries: volk + VMA (MIT) on Vulkan, metal-cpp (Apache-2.0) on Metal. Shaders are HLSL, built offline with DXC to SPIR-V and SPIRV-Cross to MSL; Slang is the alternative to re-check later. The Forge (Apache-2.0, ray queries on Vulkan and Metal) is the runner-up. Not suitable: MoltenVK and KosmicKrisp (no ray tracing), wgpu (ray tracing is experimental), Diligent (its Metal backend is commercial), NVRHI (no Metal), bgfx and SDL_gpu (no ray tracing). |
| Faithful bgfx backend | **Keep it as it is** (after the front-end/sink split, which must leave its draw logs, 548 probes and frames identical). It is the normal build and the replay-checked reference. |
| Scene data | Enough for raster features at the pddi level: per-draw matrices, textures, lights, state and stable prim-buffer objects. Ray tracing and model replacement also need **instance and draw-phase identity** (which drawable, which phase of the frame) and **world space** (pddi only sees the modelview). Get these from a few tag points at the traversals, through either platform-side interposition or guarded edits (section 2.6). |
| Simulation coupling | **Fog, the occlusion query and the world draw-distance fade (270/25 units) are render-only. The camera's far plane, FOV and aspect are not**: they feed a logic view that gates ambient despawn, `om::Stream` instantiation and a Lua rubble spawn. Change the far plane and FOV only in the backend's projection, never in the game's camera. Room streaming is driven by the anchor position, not by the camera (section 3). |
| Longer draw distance | (1) A render-only override of the three fade constants read only by `World::Render` 0x1c88f0. (2) Fog planes overridden in the backend. (3) The projection's far plane overridden in the backend. (4) Beyond the rooms the game keeps loaded, a **far-field layer** owned by the renderer: it draws unloaded rooms straight from the extracted data and never registers them with the game. |
| Assets | One override layer, `mods/<pack>/`, for textures, materials and models. One key form: `<kind>-<xxh64>`, where the hash is a content hash of what the backend receives (section 2.7). Packs are user-installed, never shipped or committed. |
| Plan | R1 skeleton matching the faithful image (5-8 weeks). R2 cheap wins (2-4). R3 PBR and lighting (6-10). R4 ray tracing (6-10). R5 model packs (4-8). Estimates are agent-assisted weeks, like graphics-backend.md's 10-16 weeks for G0-G5, which in the event were built in about two days. |

## 1. Renderer foundation and library

### 1.1 What the targets offer

| Target | API | Ray tracing | Evidence |
|---|---|---|---|
| Steam Deck (Van Gogh, RDNA2, Mesa RADV) | Vulkan 1.3 | `VK_KHR_ray_query` and acceleration structures default-on since Mesa 22.2. `VK_KHR_ray_tracing_pipeline` default-on since Mesa 23.2. Mesa 26.0 (Feb 2026) improved RADV ray-tracing performance. | verified: [Phoronix ray_query](https://www.phoronix.com/news/RADV-Lands-KHR_ray_query), [Phoronix default](https://www.phoronix.com/news/RADV-Ray-Queries-Default), [Phoronix 23.2](https://www.phoronix.com/news/RADV-RT-Default-Mesa-23.2), [Mesa 26.0](https://linuxiac.com/mesa-26-0-released-with-radv-ray-tracing-performance-gains/) |
| | | That a current SteamOS lists all three extensions on the Deck is inferred from RDNA2 and Mesa 23.2 or later. Run `vulkaninfo` on a Deck to confirm. Reports call ray tracing on the Deck "very slow". | unverified (the extensions); verified (the report: [frvr](https://frvr.com/blog/valve-helps-amd-gpus-gain-significant-ray-tracing-and-vulkan-improvements-on-steam-deck-and-more/)) |
| Desktop Linux (AMD RDNA2+, NVIDIA) | Vulkan 1.3 | Same extensions (RADV; NVIDIA's driver) | unverified for each driver version |
| arm64 macOS (M1-M5) | Metal 3 | `MTLAccelerationStructure` plus `intersection_query`/`intersector` in MSL (inline queries) and intersection function tables. **No equivalent of the Vulkan ray-tracing pipeline** (raygen/hit/miss stages). Hardware ray tracing on Apple GPU family 9 (M3, A17 Pro) and later. | verified: hardware RT on M3 ([WWDC23 tech talk](https://nonstrict.eu/wwdcindex/tech-talks/111375)); Blender Cycles enables Metal RT by default only on M3+ ([PR](https://projects.blender.org/blender/blender/pulls/114296/files)). API shape from Apple's documentation and [WWDC21](https://developer.apple.com/videos/play/wwdc2021/10149/), not re-read for this study. M1/M2 speed: unverified. |

The common subset is the **inline ray query**: Vulkan `VK_KHR_ray_query` and Metal `intersection_query`. Designing
ray tracing around inline queries in compute and fragment shaders gives one shader per effect on both APIs. The
Vulkan ray-tracing pipeline (shader binding tables) is not used.

### 1.2 The options

| Option | Licence | Vulkan RT | Metal RT | Maturity | Verdict |
|---|---|---|---|---|---|
| **Own RHI: native Vulkan + native Metal** | ours, with volk (MIT), VMA (MIT) and metal-cpp (Apache-2.0); licences from memory, unverified | yes (direct) | yes (direct) | the APIs are mature; the RHI is new code, scoped to what this game needs | **recommended** |
| Vulkan everywhere via MoltenVK | Apache-2.0 | yes on Linux | **no**: MoltenVK implements Vulkan 1.4 but none of the three RT extensions; Khronos now calls it deprecated in favour of KosmicKrisp on Apple Silicon | verified: [README](https://raw.githubusercontent.com/KhronosGroup/MoltenVK/main/README.md), [user guide](https://github.com/KhronosGroup/MoltenVK/blob/main/Docs/MoltenVK_Runtime_UserGuide.md) | raster-only stopgap at most |
| Vulkan everywhere via KosmicKrisp (LunarG, Mesa) | MIT (Mesa; unverified) | yes on Linux | **no**: passed the Vulkan 1.3 CTS (Sept 2025), in Mesa 26.0; ray tracing is listed only as a "potential" goal | verified: [LunarG XDC 2025](https://www.lunarg.com/lunarg-at-xdc-2025-kosmickrisp-overview/) | watch; a possible future single-API route |
| The Forge | Apache-2.0 for PC, macOS, Steam Deck (consoles commercial) | ray query | ray query (examples on M2) | release 1.63 on 2025-03-20; work continues on codeberg | verified: [GitHub](https://github.com/ConfettiFX/The-Forge). **Runner-up**: a whole framework with its own conventions, build and resource model |
| wgpu (Rust; `wgpu-native` C API) | MIT/Apache-2.0 (unverified) | experimental | Metal acceleration structures in v29 (2026-03-18), `intersection_query` in v30 (2026-07-01); `EXPERIMENTAL_*` features | verified: [CHANGELOG](https://raw.githubusercontent.com/gfx-rs/wgpu/trunk/CHANGELOG.md). Whether the C API exposes ray tracing is unverified | no: experimental API, adds a Rust toolchain |
| Diligent Engine | Apache-2.0, **but its Metal backend is "available under commercial license"** | yes | Metal RT unverified | verified: [README](https://github.com/DiligentGraphics/DiligentEngine) | no |
| NVRHI | MIT | yes | **no Metal backend** (D3D11/12, Vulkan) | verified: [GitHub](https://github.com/NVIDIA-RTX/NVRHI) | no |
| bgfx, sokol, SDL_gpu | BSD-2 / zlib / zlib | no | no | SDL_gpu's documentation puts cutting-edge features out of scope (verified: [SDL wiki](https://wiki.libsdl.org/SDL3/CategoryGPU)); bgfx and sokol from memory (unverified) | no ray tracing; keep bgfx for the faithful build only |
| bgfx + a native ray-tracing side-car (bgfx's Vulkan/Metal device via `getInternalData`, our RT passes writing textures that bgfx samples through `overrideInternal`) | BSD-2 | via our code | via our code | needs synchronisation across bgfx's command submission, which bgfx does not expose | no: fragile; it ties the remaster to bgfx internals |

**Shaders.**
- **HLSL** compiled offline by DXC to SPIR-V (Vulkan). SPIR-V goes to MSL through SPIRV-Cross, which gained MSL
  `intersection_query` output for `SPV_KHR_ray_query` in 2021 (verified indirectly, [commit log](https://git.tizen.org/cgit/platform/upstream/SPIRV-Cross/log/spirv_msl.hpp?h=tizen)).
  Its coverage is unverified: **the first R4 task is to push a ray-query shader through it**.
- **Slang** (Apache-2.0 with LLVM exception) is the more modern route, but its Metal target is "experimental" and
  "Ray-tracing support for Metal is a work in progress" (verified: [Slang targets](https://shader-slang.org/slang/user-guide/targets.html)).
  Re-check it at R4.
- The faithful shaders (`src/platform/sdl/pddi/shaders/`, bgfx `.sc`) are ported to HLSL for the remaster's faithful
  pass (R1). The independent CPU references that proved them (`tools/d3d_combiner.py`, `tools/d3d_ff.py`,
  `tools/xps.py`, `tools/nv2a_vp.py` + `tools/shader_equiv.py`, [shaders.md](shaders.md)) prove the ports too. Only
  the GPU half of the harness changes.

**Why our own RHI.**
- The game is small: about 255 draws a frame, measured from the hybrid draw log (5,357 draws in 21 frames,
  graphics-backend.md section 7), with up to 6.5k triangles a room and about 0.5 M a whole location.
- The renderer needs a narrow set of features: render targets, compute, BC textures, bindless-style texture arrays,
  acceleration structures and inline ray queries, plus timestamps.
- A focused RHI of a few thousand lines per backend is smaller than adapting a framework. It keeps the ray-tracing
  model exactly the common subset.
- The faithful bgfx backend already shows the team can own a renderer at this level (548 self-test probes on Metal
  and under Wine/Vulkan).

**Why not MoltenVK for raster first.** It would save the Metal backend until R4, but the R4 Metal backend would then
be a second backend written late, under ray-tracing pressure. Writing both backends in R1, raster only, keeps them in
step.

### 1.3 The ABI boundary

- The game and the pddi classes are compiled for the MS C++ ABI, also on macOS (decided;
  [native-mac.md](native-mac.md) section 1: an `aarch64-pc-windows-msvc` front end retargeted to Mach-O).
- Metal, metal-cpp, Objective-C++ and the host C++ library are compiled natively (Itanium).
- So the remaster renderer sits behind a **plain C interface** (`extern "C"`, POD structs, fixed-width integer types;
  no `long`, `wchar_t`, `bool` members, C++ classes or exceptions across it). The MS-ABI pddi front end calls it.
- The same rule applies to bgfx on the native builds and to the SteamOS x86-64 build. There, the `char*` `va_list`
  mismatch noted in native-mac.md section 5 is one more reason to keep varargs off the interface.

## 2. Scene data: what the engine knows above pddi

### 2.1 The frame, from the game's side

```
CRenderManager FUN_001b93a0 (equivalent/0x001b93a0.cpp, tree game/global/CRenderManager.cpp)   every in-game frame
├ region tracking, camera FUN_001bc720
├ DebugRender FUN_001c3e10 ("Rendering")
│  ├ Canvas FUN_001c1f30   logic view -> private camera + 6 frustum planes (equivalent/0x001c1f30.cpp)
│  ├ FUN_001c2210          fade pass; copies fog colour/planes into the pure3d View -> pddi (FUN_00293ef0)
│  ├ World::Render 0x1c88f0 (equivalent/0x001c88f0.cpp)
│  │   background (sky) drawables (World+0x08/+0x0c) via FUN_001c25c0, "Draw Background"
│  │   per room: distance fade/cull (270/25 units), Room::FUN_001c6800 -> Canvas FUN_001c26a0 -> drawable->vfunc_8
│  │   per dynamic Render::Object (max 0x100, World+0x138): frustum test FUN_001c2820, vfunc_3 0x1c5460
│  │   "Compute Shadows" FUN_001c84e0 per visible object
│  └ Canvas FUN_001c1340   flush the display list: DisplayList First/Second/Third
└ framebuffer effects (extension 0x103: overlay, colour pass, bloom), fader, HUD overlays (COverlayManager), menus
```

`Render::Canvas` (ctor 0x1c1a40, equivalent/0x001c1a40.cpp) is the renderer object. It owns:
- a `DisplayList` (capacity 0x400);
- `OpaqueTraversal` (vfunc_3 0x2a2a30 radix-sorts by shader key; vfunc_4 0x2a2af0 binds, runs the shader callback,
  draws);
- `TranslucentTraversal` (vfunc_4 0x2a1b60, back to front, insertion sort 0x2a23d0);
- `ShadowTraversal` (vfunc_4 0x2a1400, depth state x 0.995);
- two `LightsChooser`s (normal and "special" lights), a `LightGroup` and an `AmbientLight`;
- the fog defaults: colour 0x808080, planes 50/650.

`DisplayList` add (`FUN_0029b750`, equivalent/0x0029b750.cpp) culls each drawable's AABB against the Canvas volume
(`FUN_001c2870`) and queues {matrix, item, part}.

### 2.2 How a draw reaches pddi

| Leaf | Function | pddi entry |
|---|---|---|
| static mesh | `PrimGroupOptimized::vfunc_6` 0x2df540 | context slot 32 (draw prim buffer with shader) |
| skinned mesh | `PrimGroupSkinnedOptimized::vfunc_6` 0x2e0110 | bone matrices through `d3dExtHardwareSkinning::vfunc_5` 0x322200 (bone x modelview, transposed, c113+3i), then `vfunc_6` 0x3245d0 |
| streamed geometry (particles, billboards, `PrimGroupStreamed` 0x2df5a0) | `SpriteParticleRenderer::vfunc_4` 0x2d6790, `BillboardQuadGroup` | context slots 30/31 (begin/end prims: transient vertices) |
| everything | | `bgfxContext::draw(bgfxShader*, DrawSource)`, `bgfx_draw.cpp:889` |

At that one function the backend knows:
- the shader object: kind, pddi name, change serial at +0xc, and its parameters (TEX/TTEX/REFL, blend, alpha test,
  two-sided, colours);
- the four stage textures (`bgfxTexture*`, with their mip levels);
- the modelview (`worldMatrix()`: D3D's VIEW is the identity here, so the camera is folded in) and the projection;
- up to 8 lights, already in camera space (`updateLights`, FUN_00321310), and the material;
- fog, blend, depth, stencil and cull state;
- the vertex program and declaration flags;
- the vertex source: a persistent `bgfxPrimBuffer` with a CPU copy of its vertices and indices, or a transient
  stream;
- whether the draw is inside a visibility test.

The hybrid draw log (`hybrid/hooks.cpp` drawlog, `tools/drawlog_diff.py`) records the same fields from the original
game.

### 2.3 Static world geometry

- **Levels and rooms.** `Render::LevelLoader::vfunc_5` 0x1c9160 (chunk 0x60000700, one per location) finds
  `<name>_static` / `<name>_dynamic` `DrawableHierarchy`s and the `<name>_static` `LightGroup`. `RoomLoader::vfunc_5`
  0x1c6fe0 (0x60000701, one per room file) makes a 0x60-byte `Render::Room`: name, centre, AABB, radius, mode, and
  0xa8-byte records (guess: visibility volumes). The room's geometry is a `Geometry`/`CompositeDrawable` from the same
  `.p3d`; its shaders and textures resolve by name from `districts.rcf`.
- **Budget** (probe `geo_budget.py`):
  - 3 to 188 rooms per location;
  - 6k to 544k triangles per location (`outskirts_dusk` 544k in 188 rooms);
  - at most 6.5k triangles per room.
- **Lighting is baked.**
  - `LIT` = 0 in 3,368 of 3,390 world shaders.
  - 98% of room prim groups carry vertex colours.
  - 72% carry a second UV set: the `layered` shader's `TTEX` layer, modulated (`TBLM` 1).
  - Room files carry no Light chunks.
  - **70% of room prim groups have no normals** (16,952 of 24,307; probe `normals.py`). Characters and props mostly do.
- **Materials** (probe `materials.py`): `simple`, `layered`, `layeredReflect` (buildings, with a `REFL` environment
  map) and `environment` (sphere-map reflection, `ENVB`). There are no normal, roughness or metal maps.
  `MMIN`/`MMAX` = 0/7 and `FIMD` = 4 everywhere.
- **Where to build acceleration structures.** A world prim buffer is created at load (device slot 10) and its
  contents arrive at unlock. The backend keeps the CPU copy (`bgfxPrimBuffer::m_vertices`/`m_indices`) and converts
  it at first draw (`bgfx_draw.cpp:1080`).
  - So a **bottom-level acceleration structure (BLAS) per static prim buffer** can be built at its first upload and
    freed with the buffer, entirely in the backend.
  - Room loading and unloading is the game's streaming (`CWorldStreamManager`, section 3.4). The backend follows it
    through prim-buffer creation and destruction, without a hook.
  - The top-level acceleration structure (TLAS) is rebuilt each frame from the frame's instances, which cost little
    at these counts.

### 2.4 Skinned meshes

- **Bones.** At most **25 bones per draw** (`d3dExtHardwareSkinning::vfunc_1` returns 0x19). Larger skins are split
  into several prim groups, each with its own palette.
- **Pose.** `Pose` (world = local x parent, `FUN_002844f0`) is computed above pddi. `PolySkin::vfunc_8` 0x2b7900
  updates it before the container draws.
- **What the backend sees.** The bind-pose vertices in the prim buffer: 4 weights packed 11:11:10, palette indices as
  bytes. The bone matrices per draw: bone x modelview in c113.., camera folded in.
- **Size.** Hulk: 38 joints, 4 prim groups of about 3.4k triangles. The largest skinned mission file: about 20k
  triangles.
- **For ray tracing.** A compute pre-skin pass in the backend writes posed vertices into a per-instance buffer,
  then a BLAS refit (or rebuild: a few thousand triangles) per skinned draw per frame. The bone matrices must be
  turned back into world space (section 2.6).

### 2.5 Lights and shadows

- **Light types.** `pure3d::Light` subclasses: `DirectionalLight` (vfunc_9 0x2a2ff0), `PointLight` (0x2c3f70),
  `SpotLight` and `AmbientLight`. They reach pddi through context slot 37, as type, colour, position, direction and
  range. The backend keeps 8 (`kLights`). The skin programs read the first 4 directional lights.
- **Light selection.** `LightsChooser` picks lights per object. The volume tests are in `FUN_002a0d00`.
- **Script lighting.** Scripts set the building light (`rm_SetBuildingShaderLight` 0x1b9290) and the shadow colour
  (`rm_SetShadowColour` 0x1b9b40).
- **Dynamic lighting** therefore covers characters and props only. The world is baked.
- **Shadows.**
  - `ShadowSkin` (0x10019, 22 chunks) and `ShadowMeshBuffer` (0x10023, 166) carry topology and vertices. With the
    stencil slots 64-74 and `ShadowTraversal`, they look like stencil shadow volumes (guess).
  - `FUN_001c84e0` ("Compute Shadows") also passes an alpha from velocity per object, which may be a blob or
    projected shadow (unresolved).
- **The remaster's approach.** It replaces both shadow kinds with shadow maps or ray-traced shadows, by recognising
  and dropping those draws: tag `ShadowTraversal`, or match colour writes off plus a stencil-increment pattern.

### 2.6 What pddi lacks, and the tag points that supply it

| Need | Available at pddi? | Source above pddi | How to get it |
|---|---|---|---|
| world space (for ray tracing, shadow maps, world-space PBR) | no: modelview only | the camera's view matrix. The logic view object at 0x4e231c (camera position at +0x4c, read already by the replay checkpoint hash; `CCameraManager` 0x9bb50 copies the view, FOV, aspect and near/far into it every frame) or the matrix the pure3d View loads at frame start | **read the view once per frame**: either the bottom of the pddi matrix stack (to confirm in R1) or the logic view object, through a named data reference as `src/platform/sdl/xdk/replay_hooks.cpp` reads checkpoint state. Then world = modelview x view⁻¹ per draw. |
| draw phase (sky, world, objects, translucent, shadow volumes, effects, HUD, front end) | partly: the HUD camera (near 0.1, far 100: used by `HULK_HUD=edge`), 2D mode, the effects extension's views, blend state | `FUN_001c3e10`'s order; `World::Render`'s background block; the three traversals | **tag points**: the traversals' `vfunc_4` (0x2a2af0, 0x2a1b60, 0x2a1400) and `FUN_001c25c0` (sky) |
| instance identity (which character a skinned draw belongs to; one object = several prim groups) | no (the sorted traversal interleaves instances) | the display-list entry {matrix, item, part} in the traversal's vfunc_4 | the same tag points pass `item` (drawable pointer) |
| asset names (mesh, shader) | no: lost at pddi | `GeometryLoader::vfunc_5` 0x2c2ab0, `PolySkinLoader`, `PrimGroupLoader`, the `pure3d::Shader` wrapper | not needed for the key scheme (content hashes, section 2.7); a debug-only name map is optional |
| full pose (every joint, including joints with no skin weights) | partly: only the joints a draw's palette uses | `Pose` in `PolySkin::vfunc_8` 0x2b7900 | for R5, the union of an instance's palettes is enough when a replacement weights only joints the original skin weights. Otherwise add a tag at 0x2b7900. |
| world lights for the level (positions of lights not currently picked) | no | `LevelLoader` 0x1c9160: the `<name>_static` LightGroup, "Background Lights" | tag point, or read the light group by name |

**Three ways to place a tag point** (rule G3 decides which one is allowed):
1. **Platform-side interposition, no source change.** The traversals' `vfunc_4` are virtual slots. The remaster build
   replaces those vftable entries at start-up with wrappers that emit a tag (`hulk_rm_tag(phase, item)`) and call the
   original. The game's code and proofs are untouched. The vftables are in our image, so this is a startup write in
   the platform layer. It is fragile only if a vftable moves, and the link knows every vftable by name.
2. **Guarded source edit.** `HULK_RM_TAG(phase, item);` in the source, a macro defined to nothing unless
   `HULK_REMASTER`. MSVC never defines it, so the MSVC 7.1 object is byte-identical. This is checked the way
   `tools/ptr1.py proof` checks the 64-bit fixes: compile both, compare objects. `compare.py` MATCH and
   `verify_relocs.py` for `matches/`, or an identical object for `equivalent/`, so the proof stands unchanged. The
   `--wine` check of an equivalent runs on the normal build's object, which has no tag.
3. **Heuristics only**: classify from the state at pddi (projection, blend, stencil, vertex program, draw order). No
   tags at all. Good enough for R1-R3 (raster), not for R4/R5 (instances).

Recommendation: heuristics in R1-R3, interposition (1) for R4/R5, and (2) only where a non-virtual call has to be
tagged.

### 2.7 One asset-override layer, one key scheme

```
mods/<pack>/pack.json                 name, version, author, licence text, priority, which key kinds it provides
mods/<pack>/textures/tex-<xxh64>.png  (or .dds/.ktx2: BC7/BC5 accepted as is)
mods/<pack>/materials/mat-<xxh64>.json  PBR description: maps (by file), factors, flags
mods/<pack>/models/mdl-<xxh64>.glb      replacement mesh(es) for one prim buffer key, or a manifest listing several
```

- **One key form: `<kind>-<16 hex digits>`**, XXH64 with seed 0, over a canonical byte string. Every kind is a
  content hash of what the backend receives, so it works the same for the original data, `mods/` overlays and new
  levels.

  | kind | hashed bytes | notes |
  |---|---|---|
  | `tex` | the mip-0 ImageData payload (DDS/PNG bytes), as in [texture-packs.md](texture-packs.md) | The backend receives only the locked surface. Either (A) redefine the key as (format, width, height, mip-0 surface bytes) and update `tools/texpack_convert.py`, or (B) keep the payload key and pass it to the backend with a tag at the image loader. graphics-backend.md section 5 recommends A. **Decision D9.** |
  | `mat` | (pddi shader kind, the `tex` keys of stages TEX/TTEX/REFL, blend mode, alpha test, two-sided) | most materials are identified by their base texture. A pack may also give `mat` files keyed by the base `tex` key alone (lower priority), so one PBR set covers every material using that texture |
  | `mdl` | (vertex flags, vertex count, the vertex bytes in the prim buffer's packed layout, index bytes, prim type) | stable across loads. The same mesh repeated in several rooms has one key, as textures do. Skinned groups: one key per prim group (palette split), and a model manifest can replace a whole character by listing its group keys |

- **Lookup.** At start-up, index every pack by key (no file opened until needed). Resolve priority by pack order, so
  a later pack overrides an earlier one. Load at first use on a worker thread and fall back to the original until it
  is ready. GPU caches (BC7-compressed HD textures, generated mips) go under the user cache directory, keyed by
  (key, source file hash).
- **Dump mode** (`HULK_RM_DUMP=tex,mat,mdl`) writes each key the first time it is seen, with a preview: a PNG; a JSON
  of the original material; a glTF of the original prim buffer with joint names from the offline pack tool. Modders
  can then work from the Xbox data directly.
- **Never shipped.** Packs are made from the player's own files or by the community. The repo commits neither packs
  nor tools that embed game data. The pack tools (`tools/rmpack_*.py`, future) run on the player's machine, like
  `texpack_convert.py`.

## 3. Simulation coupling: what draw distance touches

### 3.1 Verdicts

| Parameter | Where it is set | Readers | Verdict |
|---|---|---|---|
| **Fog** (colour, start/end, enable) | defaults in the Canvas ctor 0x1c1a40 (0x808080, 50, 650); scripts: `rm_EnableFog` 0x1b8770, `rm_SetFogPlanes` 0x1b88c0, `rm_SetFogColour` 0x1b9ab0 (192 location script call sites, e.g. planes 30..1200 or 30..900) | only `FUN_001c2210` in the render frame, which copies them to the pure3d View, then pddi fog state | **render-only** |
| **World draw distance**: `flt_004c53bc` = 270 (fade start), `flt_004c53c4` = 25 (fade band), `flt_004c53c0` = 150 (near-volume radius); values read from the player's XBE (probe `read_floats.py`) | writable `.data` (config/data.json: object Render/LevelLoader.cpp; declared `extern "C" float DAT_004c53bc` etc. in `include/decls/data/game/Render.h`) | only `World::Render` 0x1c88f0 (data.json xrefs). Rooms beyond 295 horizontal units are skipped. The distance is scaled 1.0-1.3 by camera height and direction in `dt` (downtown) levels, smoothed in `DAT_004c546c`. The function writes only the room fade `f58` (read by the fade code 0x1c68e0) and `DAT_004c546c` | **render-only** (side effects stay in render state) |
| **Occlusion queries** | `d3dExtVisibilityTest` (extension 0x500002) | only `BillboardQuadGroup::FUN_002ba220`, which scales flare intensity (`BillboardCutOffQuadGroup::vfunc_11` 0x2ba600) | **render-only**: bgfx's one-frame latency changes only the flare's brightness |
| **Camera near/far** (`Camera+0x1c/+0x20`; `CGameCamera` ctor 0xa9400: 0.1/3000; `CScriptCamera` 0xacaa0; `CBlendCamera` 0x985b0; p3d camera chunks 0x2c1970; animated by 0x2931c0/0x293450) | `Camera::vfunc_7/9` 0x2927a0/0x2927b0 | `CCameraManager` 0x9bb50 copies them each frame into the logic view (`FUN_001c3d90`, global 0x4e231c), whose frustum (`FUN_001c1f30`) the tests below use | **feeds simulation** |
| **FOV and aspect** (`ComputeRealFOV` 0x9f790, Hor+; `bgfxDisplay::vfunc_16` aspect) | `Camera::SetFOV` 0x2926d0 | the same logic view | **feeds simulation** (see 3.3) |
| Mesh LOD | | none: no LOD switching, no distance thresholds in drawables, no impostors (only texture `MIN/MAX_LOD` clamps) | nothing to change |
| Room streaming | `CWorldStreamManager` (`FUN_002089f0` pump; wanted room `FUN_00203cd0` from the anchor position; eviction `FUN_00204ad0`, farthest room first; scripts `wsm_LoadRoomTemp` / `wsm_UnloadTempRooms` / `wsm_SetCurrentRoom`) | room load and unload events go to ambients (0x7da70), trigger volumes (0x1fd180) and smart props (0x1dd320); `wm_FindRoomWithPoint` 0x204200 (43 Lua uses) and 9 C++ callers | **simulation**: driven by the anchor's position (Hulk's, not yet confirmed), not by the camera. The remaster must not load more rooms through the game. |

### 3.2 What the logic view gates (all simulation)

| Function | Role |
|---|---|
| `cm_IsPointInCameraView` 0x99d60 (matches/0x00099d60.cpp) -> 0x1c4050 / 0x1c4010 | Lua: all 16 uses are one `killBuild` script (`misc/scripts/fight/common.fig` and per-location copies). It spawns rubble with `math.random` only when the point is **not** in view, which changes state and RNG consumption |
| ambient update `FUN_0007efc0` (equivalent/0x0007efc0.cpp) via 0x84c40 | an entity is removed after 150 frames outside the frustum (radius-5 sphere) |
| `om::Stream` 0x1e6390 (`game/om/Stream.cpp`) | object slots are instantiated and destroyed by distance buckets (60/150/250) and view (reading partly unconfirmed) |
| 0x25ff0 / 0x25110 (from the update 0x88c30), 0x36a20 -> 0x2b590 | selector active flags; off-screen items evicted first when over a limit |
| `tvm_IsLocatorInCameraView` 0x1fd8f0 | Lua binding, unused by the scripts |

### 3.3 Consequences for the remaster

1. **Never change the game's camera.** Far plane, FOV and aspect stay as the game computes them.
   - `bgfxContext` builds the projection itself (the D3D backend's `LoadProjectionMatrix` 0x323ee0 is a backend
     override, slot 109, from pddiViewState near +0x24, far +0x28, FOV +0x2c, aspect +0x30).
   - So the remaster's far plane (and a wider render FOV, if ever wanted) is a **render-side substitution in the
     backend**. It needs no game change and is invisible to the logic view.
2. **Hor+ widescreen already changes simulation.** The aspect the display reports reaches the logic view through
   `ComputeRealFOV`. Two runs of one recording at 4:3 and 16:9 can therefore diverge (ambient despawn timing, rubble
   spawns), even in the normal build. Today's replays match because play3 is replayed at one aspect.
   - Test rule: the normal-versus-remaster replay comparison runs both builds at the same aspect.
   - Optional fix (decision D7): a "logic aspect" pin that gives the logic view the recording's aspect while the
     renderer shows the wider picture. Objects the logic frustum culls would then be missing at the screen edges,
     because `Render::Object`s are culled with it (`World::Render`, `FUN_001c2820`). So the pin is a test-mode
     knob, not a play option.
3. **Draw distance can be render-only**, in four parts:
   1. **Room fade constants.** Override the three floats (270/25/150) at start-up. The remaster's platform layer
      writes the named data items after data initialisation (an override table). No source edit; `World::Render`'s
      code and proof are untouched (it behaves as proven, with other values in its inputs). Replay equality
      (section 5.4) confirms nothing else changed.
   2. **Fog.** The planes reach the backend as pddi fog state (`m_rs.fogStart/End`). Override, scale or disable them
      there. The scripts' calls are untouched.
   3. **Far plane.** Substituted in the backend's projection (point 1). The game's far plane of 3000 already exceeds
      the room cut-off, so loaded rooms are not clipped.
   4. **Far field.** Rooms the game has not loaded: the streaming budget decides which rooms are resident, and
      loading more would fire room events into simulation. So the remaster owns a **far-field layer**. Its own `.p3d`
      reader (the format is fully mapped, [formats/p3d.md](formats/p3d.md); `tools/p3d.py city` already merges a
      location) loads every room of the current location from the extracted data, in the renderer only. It draws
      the rooms the game has not loaded, beyond the game's loaded set, with merged static meshes, no props and no
      dynamic objects. The handover at the boundary is a distance fade like the game's own.
      - Rooms the game loads are recognised by their prim-buffer `mdl` keys (or a room tag) and drawn by the game's
        path instead.
      - Destroyed or changed geometry (the game breaks buildings) appears only in the game's loaded rooms. The far
        field shows the intact city. That is acceptable at distance, and a later refinement can read destruction
        state.
      - **Open measurement:** how far the game's resident set reaches in each location. Log resident rooms and their
        distances during a replay; this sets how much the far field must cover.

### 3.4 Game functions the remaster touches

| Function / item | Change | Mechanism | Why the proof stays valid |
|---|---|---|---|
| `flt_004c53bc`, `flt_004c53c0`, `flt_004c53c4` (read by `World::Render` 0x1c88f0, equivalent) | larger fade start and band (user option) | **override table**: a start-up write by name in the remaster platform layer | no source or object changes. The function is proven for its inputs; replay equality checks the simulation. |
| fog (Canvas 0x1c1a40, scripts 0x1b8770/0x1b88c0/0x1b9ab0) | none in game code | backend override of pddi fog state | untouched |
| far plane, FOV (0xa9400, 0x2927b0, 0x9bb50) | none in game code | backend projection substitution | untouched |
| `OpaqueTraversal::vfunc_4` 0x2a2af0, `TranslucentTraversal::vfunc_4` 0x2a1b60, `ShadowTraversal::vfunc_4` 0x2a1400 | tags (phase, drawable) | **interposition** of the vftable slots (G3 option 1) | untouched |
| `FUN_001c25c0` (sky), `PolySkin::vfunc_8` 0x2b7900 (pose), `LevelLoader::vfunc_5` 0x1c9160 (level lights) | tags, only if R4/R5 need them | interposition where virtual (0x2b7900, 0x1c9160 are vfuncs), else a **guarded source edit** (G3 option 2) | MSVC object identical, compared per source (as `ptr1.py proof`); no `--wine` change in the normal build |
| shadow volumes, blob shadows (`ShadowTraversal`, `FUN_001c84e0`) | dropped when remaster shadows are on | recognised at pddi (tag or state pattern) and not drawn | untouched; nothing in simulation reads the stencil buffer |
| framebuffer effects (bloom, colour pass, motion trail, refraction copies) | re-implemented in HDR | they are backend classes already (`bgfx_effects.cpp`) | not game code |

Rules:
- **G1.** The remaster never writes game state except the override table's render-only items.
- **G2.** A new item goes into the override table only after its readers are listed (data.json xrefs) and shown to
  be render-only.
- **G3.** Tags use interposition where the function is virtual. A guarded edit is allowed only with the MSVC object
  identity check, and is listed in this table.

## 4. Features

Cost is new code and content for the feature. Risk is what can go wrong (determinism, image parity, performance on
the Deck). Stage is when it lands.

| Feature | Approach | Cost | Risk | Stage |
|---|---|---|---|---|
| **Fog off / tuned** | backend: per-location scale or off for the pddi fog planes; keep fog for haze (scripts use it for mood: brown at 30..1200), add height/aerial fog in the PBR pass later | small | low. Removing fog reveals the 295-unit room cut-off, so ship it with the draw-distance work | R2 |
| **More mips, anisotropic filtering** | the game supplies a short chain and D3D clamps at its last level ([graphics-backend.md](graphics-backend.md) section 14: `MIP_COUNT(mips + 1)`). The remaster decodes BC1-3 at upload, generates the full chain in a compute pass, re-encodes to BC7 (or keeps RGBA8 for small textures) and caches it; 16x anisotropic sampling; LOD bias tied to the render scale | small-medium | low. Alpha-tested foliage and fences need coverage-preserving mips | R2 |
| **Resolution** | already arbitrary (`HULK_GFX_SIZE`). The remaster adds a render scale, MSAA (forward passes) and temporal upscaling: FSR 2 (FidelityFX, MIT, unverified) on both; MetalFX on macOS | small (scale, MSAA) / medium (temporal) | temporal upscaling needs motion vectors: previous-frame modelview per instance, which needs the instance tags (2.6) | R2 (scale, MSAA), R3 (temporal) |
| **Render distance** | section 3.3: the three-float override, fog, far plane, then the far-field layer (own `.p3d` reader, merged room meshes per location, distance handover) | small (overrides) / medium-large (far field) | the far field shows the intact city; memory (544k triangles for a whole location is small); streaming from disk | R2 (overrides), R2-R3 (far field) |
| **LOD** | the game has none. The far field uses simplified merged meshes (meshoptimizer, MIT, unverified) built at first run and cached; characters need none | medium | low | R3 |
| **PBR and the material pipeline** | per draw, the material comes from the `mat` key: the pack's maps (albedo, normal, roughness/metal/AO, emissive), else defaults derived per shader kind (`layeredReflect` -> glossy dielectric with its `REFL` map as the probe fallback, `environment` -> metal-like, `simple` on characters -> skin/cloth presets by texture key). **The world is baked**, so world lighting = the baked vertex colour (and `TTEX` layer) as irradiance x albedo, plus PBR specular from probes, SSR or ray tracing, plus the sun. Characters and props: full PBR with the game's directional lights (pddi slot 37) + image-based lighting. Normals: from the vertex stream where present, else **generated per prim buffer at upload** (70% of room groups have none) | large (renderer) + content | baked lighting double-counts with added sun and AO unless the albedo is "de-lit"; packs supply de-lit albedo, or the pipeline divides by a low-frequency estimate. Night locations need emissive light sources the data does not have (packs can add `lights` later) | R3 |
| **Shadows** | the sun direction per location from the level's directional light (or a pack value); cascaded shadow maps for characters, props and the world, with the game's stencil volumes and blob shadows dropped (2.5) | medium | the baked world already contains its own shadows; new shadows apply to dynamic objects onto the world, and to the world onto characters | R3 |
| **AO** | GTAO-style screen-space AO (depth + generated normals); ray-traced AO at R4 | small-medium | double darkening with the baked AO in vertex colours: weight it down on world surfaces | R3 |
| **SSR** | hierarchical-Z screen-space reflections on glossy materials (buildings, water, wet streets), falling back to the `REFL` / sphere map | medium | edge artefacts; the faithful sphere maps remain the fallback | R3 |
| **RT reflections** | inline ray queries from a compute pass at half resolution, hitting a TLAS of the world + characters; hit shading uses albedo x baked vertex colour (cheap, matches the world's look), with a denoiser (temporal + spatial) | large | Deck performance ("very slow" reports): plan reflections at quarter/half resolution, or SSR only on the Deck; M1/M2 have no hardware RT | R4 |
| **RT shadows** | one shadow ray per pixel to the sun (and to the few dynamic lights), replacing the cascades on capable GPUs | medium | low; the cheapest RT feature | R4 |
| **RT GI** | probe-based (DDGI-like) diffuse GI over the world, replacing the baked colour for dynamic objects first; full relighting of the world only with de-lit albedo packs | large | the baked look is the art direction; GI changes it. Make it a toggle | R4 (stretch) |
| **Model replacement** | `mdl` keys per prim buffer (2.7). Replacement glTF skinned to the original skeleton by joint name (the offline tool maps palette slot -> joint name from the `.p3d`'s MatrixPalette and Skeleton chunks). At run time the backend draws the replacement with the bone matrices of the original draws (the union of an instance's palettes), and suppresses the original groups. Collision, animation and the skeleton stay the game's | large (tooling + renderer) | instance grouping needs tags (2.6). A replacement's joints must be a subset of the joints the original skins. Shadows and RT use the replacement (it is what the TLAS holds). Never a file-level `.p3d` override: room and prop `.p3d`s also carry collision (`WorldCollisionObject` 0x7010025, `PhysicsObject` 0x7011000), so loose-file overrides would change physics | R5 |
| **HD textures** | the existing plan (texture-packs.md, `tex` keys), through the same override layer; also works in the normal build's bgfx backend | small | none beyond D9 | R2 (the normal build can ship it earlier) |

## 5. Build and code structure

### 5.1 Directories

```
src/platform/sdl/pddi/                 shared: the pddi front end (both builds)
    pddi_*.cpp                         the 23 classes, D3D-state model, combiner keys, constants, draw log (split from bgfx_*.cpp)
    draw_sink.h                        the sink interface: resources (texture, prim buffer, target), draws, views, copies, queries, present
    bgfx/                              the faithful sink (today's bgfx submission code): normal build; optional in the remaster
    shaders/                           faithful bgfx shaders (unchanged)
src/platform/sdl/remaster/             HULK_REMASTER only (host ABI, behind a C interface)
    rm_api.h                           extern "C": frame packets, resources, tags, config
    capture/                           the sink: frame packets, phase classification, world-space recovery, instance grouping
    rhi/  rhi.h  vk/  mtl/             our RHI: devices, swapchain, buffers, BC textures, pipelines, compute, AS + ray query
    graph/                             render graph: passes, transient targets, barriers, timing
    passes/                            faithful/ gbuffer/ lighting/ shadows/ ssao/ ssr/ rt_shadows/ rt_reflect/ rt_gi/ post/ upscale/ farfield/
    scene/                             scene mirror: meshes (BLAS), instances (TLAS), materials, lights
    assets/                            override layer: pack index, key hashing, loaders (PNG/DDS/KTX2, glTF via cgltf), GPU cache
    shaders/                           HLSL (one source -> SPIR-V via DXC, -> MSL via SPIRV-Cross)
    ui/                                debug overlay and options (Dear ImGui, MIT)
tools/remaster_*.py                    shader build, pack tools (dump index, key conversion), golden-image compare
tests/remaster/                        RHI smoke scenes (our own content), shader proofs, pass unit tests
```

### 5.2 The flag and the runtime toggles

- **`HULK_REMASTER`** (0/1) is set only by the native build scripts (`tools/native_mac.py` and the SteamOS
  counterpart) for the platform layer's remaster target.
  - The game tree (`build/tree/`) compiles **identically in both builds**: the same objects are reused, so the
    remaster costs no second game compile.
  - The only game-side difference is the override table's start-up writes, done by the platform layer.
- **Runtime toggles** (remaster build only):
  - `remaster.json` in the user configuration directory, with `HULK_RM_*` overrides in the environment, as the
    `HULK_GFX_*` knobs work today;
  - and the in-game debug overlay.
- **Per-feature switches:** `fog`, `mips`, `aniso`, `scale`, `msaa`, `upscale`, `draw_distance` (fade constants),
  `farfield`, `pbr`, `shadows`, `ao`, `ssr`, `rt_shadows`, `rt_reflections`, `rt_gi`, `packs` (`tex`/`mat`/`mdl`).
- **Presets:** `faithful` (all off: the remaster renderer reproduces the bgfx image), `enhanced` (R2), `remaster`
  (R3), `rt` (R4).
- **Hardware gating at start-up:** ray-query support (Vulkan extensions; on Metal, `supportsRaytracing` and GPU
  family 9 for the hardware path). Missing support falls back by feature (RT reflections -> SSR, RT shadows ->
  cascades).

### 5.3 The pass interface (extensibility)

```cpp
// src/platform/sdl/remaster/graph/pass.h (host ABI; sketch)
struct FrameView {                     // built by capture/ from one frame of pddi packets
    CameraInfo camera;                 // view, projection (the game's and the render-side one), previous frame's
    span<const DrawItem> draws;        // world-space draws: phase, instance, mesh key, material, transform, prev transform
    span<const LightInfo> lights;
    span<const FxRequest> gameFx;      // the game's effect requests (bloom, colour pass, motion trail, refraction copies)
    const Settings* settings;
};
class Pass {
  public:
    virtual const PassInfo& info() const = 0;                 // name, feature id, order hint, supported tiers
    virtual bool enabled(const Settings&, const DeviceCaps&) const = 0;
    virtual void setup(GraphBuilder&, const FrameView&) = 0;   // declare reads/writes of named resources ("depth", "hdr", ...)
    virtual void execute(PassContext&, const FrameView&) = 0;  // record RHI commands
};
#define HULK_RM_REGISTER_PASS(T) static PassRegistrar<T> s_reg_##T   // static registry, no central list to edit
```

- A new feature is a new `Pass` that reads and writes named resources. The graph orders the passes by their
  declared dependencies and inserts barriers. A missing producer disables the consumer and logs it.
- The **faithful pass** is the first pass. It draws the frame exactly as the bgfx sink would: the same combiner
  programs and vertex programs, ported to HLSL and proven against the same references.
- Remaster passes replace phases of it: G-buffer for the world and objects; lighting; the game's translucent and
  particle draws forward-shaded on top; the game's effects re-hosted in HDR; then the HUD and front end drawn
  faithfully, last, at native resolution.

### 5.4 How the two builds share the platform layer

| Layer | Normal build | Remaster build |
|---|---|---|
| game + engine tree, data TUs | same objects | same objects |
| SDL3 platform: window, input, audio, files, saves, movies, replay, host CRT | same | same |
| pddi front end (`src/platform/sdl/pddi/`) | yes | yes |
| sink | bgfx (faithful) | remaster capture -> renderer (bgfx sink optional, decision D4) |
| override table (render-only data items) | no | yes |
| asset packs | `tex` only (HD textures, bgfx sink) | `tex`, `mat`, `mdl` |

### 5.5 Test strategy

1. **The normal build stays proven.**
   - The front-end/sink split is accepted only if the bgfx sink produces identical draw logs (`tools/drawlog_diff.py`
     IDENTICAL on a replay), passes all 548 self-test probes (`tools/wine_gfx.py smoke`), and gives identical frames
     (`HULK_GFX_SHOT`) on the same machine.
   - `build_tree` and the MSVC checks never see the flag. Any guarded edit gets the per-source object-identity check
     (G3).
2. **Simulation equality (the gate for every remaster change).**
   - Run the same play3 replay through the normal and the remaster builds (`tools/wine_replay_job.py` style, as
     queue jobs, same `HULK_GFX_SIZE` and `HULK_VDT_US`). Every checkpoint hash must be equal. The hash covers RNG,
     boot step, camera position and the GameClock ([wine-replay.md](wine-replay.md) "Checkpoint hashing").
   - Extend it with a **wide simulation hash**: the `.data`/`.bss` pages minus a render-owned exclusion list built
     from `config/data.json` owners (`Render/`, the pure3d render objects, `DAT_004c546c`, the override table's
     items).
   - Run with each feature preset (`faithful`, `enhanced`, `remaster`, `rt`), because a remaster feature must not
     move a checkpoint even through timing: replays use the virtual clock.
3. **Image parity (R1).**
   - The remaster renderer at the `faithful` preset against the bgfx sink, at the same replay frames, on the same
     machine and API: per-pixel FLIP/SSIM with a near-zero threshold.
   - Because both consume the same front end, the packet streams are identical by construction. Log a hash of each
     frame's packets in both.
4. **Feature baselines.**
   - Golden screenshots per preset at fixed replay frames (title, menus, the junkyard tutorial, downtown day/dusk/
     night, a fight, an NIS, a glow effect), per GPU family (Metal M1, Metal M3+, Deck).
   - Stored under `build/` only: game output is game data and never committed.
   - Compared with a perceptual threshold; a changed baseline needs a human look.
5. **Unit and smoke.**
   - RHI smoke scenes with our own content (committable PNGs): every texture format, MSAA, compute, an acceleration
     structure build and a ray-query image.
   - Shader proofs for the faithful ports.
   - Pass tests on synthetic `FrameView`s.
6. **Performance budgets.**
   - Per-pass GPU timestamps in the overlay and in replay logs.
   - Budgets: Deck at 1280x800, 30 fps with `enhanced` and 60 fps with `faithful`; M1 at 1440p and 60 fps with
     `remaster`; M3+ with `rt`.

## 6. Staged plan

| Stage | Work | Exit criteria | Size |
|---|---|---|---|
| **R1 Skeleton** | Split the front end from the sink (bgfx sink proven identical). Write `rm_api.h` and the capture: frame packets, heuristic phase classification, world-space recovery (confirm where the view matrix is). RHI raster on Vulkan and Metal: swapchain, buffers, BC textures, pipelines, targets, blits, occlusion queries, timestamps. The faithful pass: combiner programs, vertex programs, fixed function, the fx pixel programs and the present, ported to HLSL and proven. The render graph. Native build wiring (macOS first, then SteamOS) and the C boundary. | `faithful` preset matches the bgfx image (near-zero FLIP) on Metal and on the Deck; replay checkpoints equal to the normal build | 5-8 weeks |
| **R2 Cheap wins** | Fog controls. Full mip chains + BC7 cache + anisotropic filtering. Render scale + MSAA. The draw-distance override table and the far plane. The asset override layer with `tex` packs (decision D9 settled). Far-field layer v1 (own `.p3d` reader, merged rooms, fade handover). | `enhanced` preset; replay equality with each option; the Deck at 30 fps | 2-4 weeks (+2-3 for the far field) |
| **R3 PBR and lighting** | G-buffer and deferred lighting for opaque world and objects; forward pass for translucents and particles; generated normals; `mat` packs and per-kind default materials; sun and cascaded shadows; GTAO; SSR; HDR, tone mapping, the game's bloom, colour pass and motion trail re-hosted in HDR; temporal upscaling (instance tags by interposition, motion vectors); far-field LOD. | `remaster` preset; golden baselines; replay equality | 6-10 weeks |
| **R4 Ray tracing** | Acceleration structures in the RHI (BLAS per static prim buffer at upload; compute pre-skinning + refit for skinned draws; TLAS per frame); ray-query shaders through DXC/SPIRV-Cross (first task: prove the toolchain); RT shadows, RT reflections with a denoiser, RT AO; optional DDGI. Hardware gating and fallbacks. | `rt` preset on M3+ and desktop RDNA2+/NVIDIA; the Deck with RT shadows (or documented off) | 6-10 weeks |
| **R5 Model packs** | `mdl` keys and dump mode with glTF export; the offline pack tool (joint names from the player's `.p3d`s); instance grouping; skinned replacement with the original bone matrices; replacement in shadows, RT and the far field; validation (joint subset, bounds). | a replacement Hulk and a replacement prop drawn in every pass; replay equality unchanged | 4-8 weeks |

Total: about 23 to 40 agent-assisted weeks. The critical path is R1's front-end split and RHI, then R3's G-buffer,
which R4 builds on.

What batches well:
- shader ports with their existing proofs as acceptance tests (as G2-G5 did);
- the Metal and Vulkan halves of each RHI feature in parallel;
- passes as self-contained modules with golden images.

Prerequisites outside this plan:
- the native 64-bit builds running the game on the SDL platform layer (native-mac.md milestones 2 and onwards);
- a SteamOS build;
- a Deck for measurements.

### 6.0 Remaster gameplay features (user's list, 2026-10-26)

These are new mechanics for "the game made today". Each sits behind its own flag, has its own tests, and never touches
the faithful port.

| Feature | Idea | Starts from |
|---|---|---|
| **Co-op** | A second player, locally and online (6.1). | The player/controller-agent singleton, plus the deterministic lockstep the replay work proved. |
| **Destructible buildings** | Buildings break up physically: fractured pieces, collapse driven by structural damage, debris that stays, and full persistence of the city's damage instead of the original's fixed break states. | The game's existing destruction (breakable props and building pieces, the physics in `src/engine/physics`), and the renderer's far-field and RT work for showing damaged geometry. |
| **Cleanup crews** | The city reacts over time. Crews arrive and clear rubble, repair and rebuild damaged buildings, reopen roads. That makes damage meaningful, and it's a cue for the next escalation. | A world-state layer that records damage per building and block and schedules repair actors. It builds on the persistence the destruction feature adds. |
| **Better enemy AI** | Modern behaviour: squads that coordinate (flanking, suppression, retreat, regrouping), use of cover and verticality, vehicles and aircraft that work together, units that react to the destruction around them. | The game's AI (the behaviour selectors such as `CGolem::vfunc_4`, the `CRangedAgent`/`CPathAgent` family and the fight system), reworked behind the flag. |
| **Better enemy spawning** | A director instead of fixed spawn rules: it paces encounters by player state, heat level and the destruction caused, spawns believably (off-screen, from roads and air), and scales difficulty in co-op. | The spawn logic and the Lua `om::Stream` / `cm_IsPointInCameraView` hooks found in R0 (section 3.2). |

The order is open. Co-op and the director work well together, as do destruction and cleanup crews. Each starts with a
feasibility pass (as C0 for co-op) that maps the game systems involved.

### 6.1 Co-op (requested 2026-10-26; gameplay, not rendering)

The user wants co-op on the roadmap. Unlike R1-R5 it changes the simulation: the game has one player character, one
camera and single-player mission logic. So it can't live under the render-only `HULK_REMASTER` rule. It gets its own
compile-time flag (`HULK_COOP`), and every co-op hook is inert unless a session actually has a second player. That way
the single-player game, in both builds, keeps its replay equality with the original.

| Stage | Work | Exit criteria |
|---|---|---|
| **C0 Feasibility** | Map how the game owns "the player": the Hulk singleton and the systems that assume one (camera, HUD, input agent `CControllerAgent`, targeting, mission scripts and Lua bindings, save data, AI aggro and the fight system's player references). Decide which second character fits: a second Hulk instance or a playable variant. List every place that reads the player and how each would generalise. | A written plan in this section with the touch-point list and a size estimate |
| **C1 Local co-op** | A second input device on the SDL layer. A second player character spawned and driven by its own controller agent. A shared camera that frames both (or a split screen, which the remaster renderer can draw as two views). The HUD for two. Mission logic that tolerates two players (fail, respawn, objectives). | Two players can finish a mission locally. With one player, replays are unchanged. |
| **C2 Online co-op** | Deterministic lockstep: exchange inputs only, building on what the replay work already proved (fixed dt, virtual clock, the lockstep handoff, RNG determinism, checkpoint hashes as desync detection). Rollback is an option if latency demands it. | Two machines stay in sync over a mission. Checkpoint hashes match, and a desync is detected and reported. |

Notes:
- Co-op touches game code (matches/ and equivalent/ sources). Each change sits behind `HULK_COOP` and keeps every
  proof valid with the flag off, the same way `__clang__` twins do.
- Online play relies on cross-platform float determinism between SteamOS (x86-64) and macOS (arm64). The x87/SSE
  work (docs/wine-float.md, soft-x87) and the native builds must give identical simulation results on both. That's a
  prerequisite to verify early, with cross-machine replays of play3.
- Co-op and the remaster are independent. Either can ship without the other.

## 7. Decisions for the user

| # | Decision | Options | Recommendation |
|---|---|---|---|
| D1 | Renderer foundation | own RHI (Vulkan + Metal) / The Forge / Vulkan-only via MoltenVK until R4 | own RHI |
| D2 | Shader language | HLSL + DXC + SPIRV-Cross / Slang | HLSL now; re-check Slang's Metal ray tracing at R4 |
| D3 | Split the faithful backend into front end + sink | split (shared state model, proven identical) / duplicate the state model in the remaster | split |
| D4 | Does the remaster build also carry the bgfx sink (runtime fallback and A/B)? | yes (two graphics stacks in one binary) / no (the `faithful` preset is the fallback) | yes during R1-R3, drop later if the faithful pass is proven |
| D5 | How tags above pddi are placed | interposition of virtual slots / guarded `HULK_REMASTER` source edits with object-identity proof / heuristics only | heuristics R1-R3, interposition R4-R5, guarded edits only where unavoidable |
| D6 | Draw distance beyond the game's resident rooms | the far-field layer (renderer-only rooms from the extracted data) / stop at what the game loads | far field, with the "intact city at distance" caveat |
| D7 | Aspect/FOV coupling | accept it (as the normal build does) / a logic-aspect pin for tests | accept for play; pin as a test-mode knob only |
| D8 | Minimum hardware for RT | M3+ and RDNA2+/NVIDIA only / also M1/M2 (Metal ray tracing without hardware acceleration) / the Deck | M3+ and desktop; the Deck gets RT shadows at most; M1/M2 get SSR and cascades |
| D9 | Texture key | (A) backend-side key, update `texpack_convert.py` / (B) the payload key with an image-loader tag | A (no game edit) |
| D10 | World look under PBR | keep the baked lighting (PBR specular, sun shadows, AO on top) / relight the world (needs de-lit albedo packs, GI) | keep baked by default; relighting as an `rt_gi` toggle |
| D11 | Who makes PBR and model content | community packs only / project-authored tools (dump, conversion) without content | tools only; content is user-installed |
| D12 | Upscalers | FSR 2/3 (MIT, licence unverified) on both / MetalFX on macOS / none | FSR on the Deck, MetalFX on macOS |

## 8. Open questions and things to verify

- Where the view matrix is: the bottom of the pddi matrix stack at frame start, or only the logic view object (R1,
  first task).
- `vulkaninfo` on a current SteamOS Deck (ray query, acceleration structures), and ray-query throughput there.
- SPIRV-Cross output for a ray-query compute shader on Metal (R4, first task); Slang's status at that time.
- The streaming resident set per location (how far the game's loaded rooms reach) and the anchor's identity.
- Whether `Render::Object`'s culled counter (`FUN_001c4b20`: `+0x80 = +0x84`, `+0x88 = 0`, `+0xac` incremented
  when outside the frustum) is read by simulation. The remaster does not change that frustum, but the far field must not need it.
- `om::Stream` 0x1e6390's two callees (0x1e5980, 0x1e2940), and `CEncounterGenerator`: the reading of their view use
  is unconfirmed.
- The blob/projected shadow in `FUN_001c84e0`, and whether `ShadowSkin` is stencil volumes.
- Whether the remaster's longer GPU frames could change real-time dt in normal play. That is the same as any slower
  machine, and replays use the virtual clock. Not a determinism issue, but a pacing one at 30 fps on the Deck.
