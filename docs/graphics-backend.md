# Graphics backend: design and plan

Planning document, written 2026-10-18. Stage G0 (the harness) is built: see [section 7](#7-g0-the-harness-built-2026-10-18).
Stage G1 (the backend in the native image, first frames and draws) is [section 8](#8-g1-the-backend-in-the-native-image-2026-10-19).
G3's draw path (prim buffers, vertex programs, render state) is [section 9](#9-g3-the-draw-path-prim-buffers-vertex-programs-render-state-2026-10-19).
G2's shader-class combiners, 2D mode, linear textures and movie strategy are [section 10](#10-g2-the-shader-classes-combiners-2d-textures-and-movies-2026-10-19).
The window and the event pump moved to SDL3 in [section 11](#11-sdlwin-the-window-and-the-event-pump-on-sdl3-2026-10-19).
G4's frame-buffer copy, refraction, framebuffer effects and the other extensions are [section 12](#12-g4-effects-the-frame-buffer-copy-refraction-and-the-extensions-2026-10-19).
G5's clean-up (shader proofs, window scaling, copies without blits, two-sided lighting) is [section 13](#13-g5-clean-up-shader-proofs-window-scaling-portability-two-sided-lighting-2026-10-19).
The small prototypes and the scripts that produced the planning numbers were under `build/gfx-proto/` (not tracked). Inputs: [platform-boundary.md](platform-boundary.md),
[seams.md](seams.md), [web-port.md](web-port.md), [native-build.md](native-build.md), [subsystems.md](subsystems.md),
[formats/p3d.md](formats/p3d.md), [texture-packs.md](texture-packs.md), `src/platform/sdl/xdk/`,
`build/native/shim-inventory.json`, `build/rtti.json`, `build/port/platform_calls.json`, `build/port/seams.json`,
`config/splits.json`, the generated tree (`build/tree/src/platform/xbox/pure3d/`) and the player's own data
(`isos/extracted/default.xbe`, `build/rcf/`; only counts are reported here).

## Recommendations in one table

| Question | Recommendation |
|---|---|
| 1. Where to cut | **At the pddi seam.** A new `src/platform/sdl/pddi/` reimplements the `d3d*` classes (display, device, context, texture, prim buffer/stream, the shader classes the data uses, the extensions) on bgfx, using the verified `platform/xbox/pure3d` sources as the specification. No D3D8 call, D3D state word, NV2A method number or XGraphics function survives into the shipped port. |
| 2. What to reproduce | Fixed-function T&L for the default (no-program) path; **17 NV2A vertex programs** (661 instructions total) of which the data needs about 10; D3D-style texture-stage combiners (up to 4 stages) through a state-keyed uber shader; **17 run-time-assembled `xps.1.1` pixel shaders** in the framebuffer effects; render targets, copies, occlusion queries, gamma. No swizzling: every texture on disc is linear DDS or PNG. |
| 2b. Shader semantics, clean-room | Hand-write bgfx shaders for each program from the **game's own** program bytes (in the player's XBE) and the game's own `xps` text (already in our verified C sources), checked per vertex against **our own CPU interpreter of NV2A vertex programs**, written from public descriptions. A run-time translator is the fallback if hand-writing stalls. |
| 3. Library | **bgfx** (BSD-2): D3D11/12, Metal, Vulkan, GL/GLES and WebGL2 from one API, so native and web share the backend. SDL_gpu has no web backend (Vulkan / D3D12 / Metal only). sokol_gfx is the credible runner-up. bgfx builds here with the installed toolchain (prototype below). |
| 4. Testing | Per-draw **pddi state records** from the hybrid build (xemu) and the native build, compared draw by draw at the same frame of the same replay; plus scan-out screenshots vs native frames at replay checkpoints with a perceptual threshold; plus per-program vertex tests against the NV2A interpreter. |
| 5. HD textures | In the new `pddiTexture` implementation, at the first upload of mip 0 (no engine edits); proposed key change for texture-packs.md below, or a two-line hook in the engine's image loader if the existing payload key must stay. |
| 6. Plan | G0 harness → G1 first triangle → G2 front end → G3 a level → G4 effects → G5 web; about 10 to 16 weeks of agent-assisted work, with shaders, combiners and the effects extension as parallel batches. |

## 1. Where to cut: pddi, not D3D8

### What the game reaches

Pure3D's render path is three layers: portable engine code (`src/engine/pure3d/`: scene graph, loaders,
`pddiBaseContext` with its state stacks) calls **pddi** virtual interfaces, whose only implementation is the D3D8
backend (`src/platform/xbox/pure3d/`, 22 objects, 555 functions: 416 matched, 94 equivalent, 45 not yet), which calls
the XDK. Measured with `build/gfx-proto/inventory.py`:

- **Every graphics XDK call is inside `platform/xbox`.** Of the 86 D3D8/XGraphics functions (622 call sites) and the
  93 D3D state words (434 references), none is reached from a `game` or `engine` object. The two XDK calls in the
  engine's `pddiBaseContext.cpp` are `QueryPerformanceCounter` (timing, not graphics).
- **Portable code reaches the backend through 46 virtual slots (425 typed call sites, a lower bound) and 22 direct
  entry points (34 sites)** ([seams.md](seams.md#render)): `d3dCreateDevice` (0x31ba60) from `pure3d::InitPlatform`,
  two device helpers (0x31bae0 8 sites, 0x31bac0 4), the shader factories and a few framebuffer-effect entry points.
- The **shader factory table** (`FUN_00328130`, 16 names: `error`, `simple`, `lightweight`, `lightmap`,
  `environment`, `projtex`, `pointsprite`, `layered`, `layeredlmap`, `toon2`, `toon`, `refract`, `spheremap`,
  `bumpmap`, `layeredReflect`, `fbeffectsshader`) sits in the engine object `pddiBaseShader.cpp` but constructs `d3d*`
  classes. It is a registration point the new backend replaces with its own table (the one place an engine-layer
  file names backend classes; move it to the platform layer when `include/seams/` is written).

The interface per class (vtable slots from `build/rtti.json`; "overridden" = slots the `d3d*` class defines instead
of inheriting the portable base; bytes are the overriding functions' sizes):

| pddi class | d3d class | slots | overridden | bytes | direct XDK call sites in the overrides |
|---|---|---|---|---|---|
| `pddiDisplay` | `d3dDisplay` | 18 | 15 | 1,129 | 20 (device creation, reset, swap, vblank, gamma) |
| `pddiDevice` | `d3dDevice` | 14 | 10 | 539 | 0 (factory methods: new texture, prim buffer, shader, context) |
| `pddiBaseContext` | `d3dContext` | 111 | **33** | 3,392 | 34 |
| `pddiTexture` | `d3dTexture` | 21 | 16 | 635 | 8 (lock, palette lock, swizzle-on-unlock) |
| `pddiPrimBuffer` | `d3dPrimBuffer` | 15 | 11 | 373 | 4 |
| `pddiPrimBufferStream` | `d3dPrimBufferStream` | 18 | 18 | 783 | 6 |
| `pddiBaseShader` | `d3dShader` | 25 | 7 | 315 | 0 |
| `d3dShader` | 15 shader subclasses | 25 each | 4 to 14 each, **163 in total** | | most of the 112 `SetVertexShaderConstant1` and 55 `SetTexture` sites |
| 9 `pddiExt*` | 9 `d3dExt*` | 48 | 48 | 6,975 | 42; `d3dExtFramebufferEffects` alone is 5,800 B in its overrides (114 functions, 22 KB in its object) |

`d3dContext` keeps 78 of `pddiBaseContext`'s 111 slots: the portable base does the matrix/state stacks, 2D mode and
primitive batching, and calls down into the 33 overrides. The overrides the portable layer calls most are slot 30 and
31 (59 sites each), 58 (35), 54 (31, cull mode), 62 (22), 60 (18), 91 (16), 89 (14), 12 (12, clear). Each render-state
override is a few dozen bytes that maps one pddi enum to one D3D state (slot 54 cull mode, 58 z-enable, 64 stencil
enable, 74 stencil ops, 76 fill mode, 80 fog colour, 35/78 state words written inline; 56, 60, 62 and 66-72 set one
state each through an NV2A method immediate), i.e. **the pddi enums are Radical's own, platform-neutral, and already
decoded by our verified sources**. Which state each of 56-72 is gets read off the method number while porting.

### The D3D8 call level, for comparison

Cutting below the backend means keeping the 555 `platform/xbox` render functions and implementing, behind them:
86 D3D8/XGraphics functions; the 93 D3D state words and `D3D__DirtyFlags` with the XDK's lazy-flush semantics (the
game's own code writes them inline in 51 functions); a table from **NV2A push-buffer method numbers back to render
states** (`D3DDevice_SetRenderState_Simple(method, value)`, 56 sites); `FUN_00328bf0`'s direct writes into D3D's
texture-stage register block (`0x0039db1c`); `XGAssembleShader` (an `xps.1.1` assembler); `CreatePixelShader` from
register-combiner structures; `CreateVertexShader` from NV2A microcode with Xbox vertex declarations; swizzled
surfaces; palettes; and the push-buffer, vblank and visibility-test machinery. That is a D3D8-for-Xbox emulator
(OpenCE's route for Halo, which calls D3D8 directly), it keeps absolute XDK addresses (`0x39db00`) in code that must
also build for wasm32 and Itanium targets, and it ships exactly the XDK-shaped API that rule 4 of
[platform-boundary.md](platform-boundary.md#rules-for-library-and-platform-code-decided-2026-10-18) says to minimise.

| | pddi cut | D3D8 cut |
|---|---|---|
| Surface to implement | ~160 virtual methods for the shader set the data uses (~230 for all 15 shader classes) + 22 entry points | 86 functions + 93 state words + NV2A method table + shader assembler/translators |
| Semantics to learn | Radical's pddi enums (visible in our verified sources) | XDK internals: dirty-flag flushing, state-word layout, NV2A methods, PSDEF combiner encoding |
| XDK-shaped API in the shipped port | none | all of it |
| Reuse of verified `platform/xbox` code | as the specification; code ported, not linked | linked unchanged |
| Web / 64-bit | clean | absolute addresses and XDK layouts to carry |
| Risk | behaviour drift in a reimplemented class | a large emulator for a small API |

**Decision: cut at pddi.** Write `src/platform/sdl/pddi/` as one class per `d3d*` class (`bgfxDisplay`,
`bgfxDevice`, `bgfxContext`, `bgfxTexture`, `bgfxPrimBuffer`/`Stream`, one class per data-used shader kind, the
extensions), each written by reading the verified `platform/xbox/pure3d` source of its counterpart and replacing the
D3D call with the backend call. The verified sources stay the specification and stay in the Xbox/hybrid build. The
MS-ABI vtable slot order is kept for the 32-bit Windows build because portable code still calls by slot until fix 5b
gives it real class declarations ([native-build.md](native-build.md)); after 5b the classes simply derive from the
`include/gen` pddi bases.

What the current `src/platform/sdl/xdk/graphics_d3d8.cpp` (73 stand-ins) and `graphics_xgraphics.cpp` (6) become:
nothing. They keep the native image starting until the pddi backend links in its place, then the native link drops
the `platform/xbox/pure3d` objects and these files together.

## 2. What the renderer has to reproduce

### What the data actually uses

From `build/gfx-proto/shader_census.py` over all 1,436 `.p3d` files (8,787 Shader chunks):

| pddi shader name | d3d class | Shader chunks | where |
|---|---|---|---|
| `simple` (and `lightweight`) | `d3dSimpleShader` | 5,889 | everywhere: characters, props, front end, NIS |
| `layered` | `d3dLayeredShader` | 1,383 | world, rooms, NIS |
| `layeredReflect` | `d3dBuildingShader` | 1,376 | buildings |
| `environment` | `d3dReflShader` | 92 | world |
| `refract` | `d3dRefractVertexShader` | 41 | `art` (effects) |
| `fbeffectsshader` | `d3dFBEffectsShader` | 6 | `art` |
| `error` | `d3dErrorShader` | fallback | missing shader |

**`lightmap`, `projtex`, `pointsprite`, `layeredlmap`, `toon`, `toon2`, `spheremap` and `bumpmap` appear in no
`.p3d` and in no other non-movie file of the 13 RCFs, and their name strings are referenced only by the factory
table and by the shader classes themselves.** They look like Pure3D features this game does not use. Build them
last (or never), after a hybrid-build run that logs every factory call confirms they are never constructed.

Textures (ImageData payloads): 25,894 DDS (DXT1 17,917, DXT3 4,045, DXT5 3,932; all power-of-two) and 1,156 PNG.
**Nothing on disc is swizzled or uncompressed DDS.** `d3dTexture::vfunc_14` (unlock) calls `XGSwizzleRect/Box`
because the NV2A wants linear formats swizzled in memory; a modern backend uploads the same bytes linear, so there is
no swizzle or unswizzle code in the port at all. PNG textures are decoded by engine code (`ImageConverter`) into
locked texture memory, possibly palettised (`SetPalette`: 44 sites, `D3DPalette_Lock2`): the backend expands P8 to
RGBA8 on unlock.

Display: the game asks for 1280x720 and picks from its mode table, with a **16-bit back buffer above 720 pixels wide**
and D24S8 depth ([subsystems.md](subsystems.md)). The port renders at window size into RGBA8 + D24S8 and reports that
size through `pddiDisplay` slots 6/7/16. `d3dRefractVertexShader` uses literal 640.0/480.0 (screen-space scale) and
needs the real size passed in.

### Vertex side

- **Fixed function.** The default vertex program (registered with data = 0) is D3D's fixed-function T&L:
  `SetTransform` (world/view/projection from `d3dContext` slots 108/109), `SetLight`/`LightEnable` (8 lights max in
  D3D8), `SetMaterial`, two-sided lighting, normalize normals, vertex colour, fog (`SetRenderState_FogColor`, slot
  80). Public Direct3D 8 documentation describes this pipeline fully; one hand-written bgfx vertex shader with a few
  compile-time variants (lit/unlit, fog, texgen) covers it.
- **17 NV2A vertex programs**, registered by name in `FUN_00329430` (`d3dSimpleShader.cpp` in the tree) with
  pointers to precompiled microcode in the XBE's data section, and bound through the vertex-declaration builder
  `FUN_003290e0` (the declaration is built from a flags word: positions, normals, colours, up to 15 UV sets, skin
  weights/indices, tangents). Measured in the player's XBE by `build/gfx-proto/vsh_blobs.py`: every blob starts with
  a 4-byte header (type `0x78`, version `0x20`, u16 instruction count) followed by 16-byte instructions whose last one
  carries the end flag, as public projects describe the format:

  | program | instr. | program | instr. | program | instr. |
  |---|---|---|---|---|---|
  | `skin` | 68 | `skin_refract` | 72 | `simple_multicbv` | 34 |
  | `skin_onebone` | 43 | `spheremap` | 58 | `simple_proximity` | 30 |
  | `point_sprite` | 9 | `environmap` | 48 | `layered_multicbv` | 34 |
  | `toon` | 21 | `bumpmap` | 22 | `layered_proximity` | 30 |
  | `toon2` | 29 | `refract` | 54 | `layered_lightmap_multicbv` | 34 |
  | `skin_toon` | 45 | | | `layered_lightmap_proximity` | 30 |

  661 instructions in all. The data-used shader classes need `skin`, `skin_onebone`, the four `simple_*`/`layered_*`
  programs, `refract`, `skin_refract`, `environmap` and probably the `layered_lightmap_*` pair: about 10 programs,
  ~430 instructions. Constants come from `SetVertexShaderConstant1/4` (136 sites), most of them in each shader
  class's slot 24 (per-draw constants: matrices read back with `GetTransform`, lights with `GetLight`) and the
  hardware-skinning extension (`d3dExtHardwareSkinning`, bone matrices). The backend keeps a 192-register
  constant file (NV2A's size) per draw and maps it to one uniform array.

### Pixel side

- **Texture-stage combiners.** Most shaders express their pixel pipeline as D3D8 texture-stage operations through a
  state cache in `d3dVertexProgram.cpp` (`0x329bb0`-`0x329f70`: set colour op / alpha op / args per stage, texture
  factor; e.g. `d3dSimpleShader::vfunc_14` builds 1 to 3 stages for its blend modes) and `FUN_00328bf0` (texture
  addressing, filtering, bump-env). The game touches stages 0 to 3 (`D3D__TextureState[0..3][…]`). Public D3D8
  documentation defines each `D3DTOP_*` op and argument; the backend packs the active stages into a **state key**
  and compiles or selects a fragment shader per key (the uber-shader-with-cache every D3D8 reimplementation uses).
  Render states (blend, depth, cull, stencil, fill, alpha test, fog) come in as pddi calls on the context and map to
  bgfx's 64-bit state and stencil words, except **alpha test** and **fog**, which go into the fragment shader key.
- **Programmable pixel shaders: few, and their source is ours.** `d3dExtFramebufferEffects`'s set-up
  (`FUN_00320540`, verified) **assembles 17 pixel shaders at run time from `xps.1.1` text built in game code** (8 glow
  levels x 2 passes + 1), via `XGAssembleShader` and `CreatePixelShader`; `FUN_003202b0` assembles one more from a
  caller-supplied string; `d3dBumpMapVertexShader` (unused by the data) creates one from a structure. The text is in
  our own verified C, so these are translated by hand to bgfx shaders with no vendor material at all. They use
  `tex`, `dp3`, `mad`, `mul_x2`, `_bx2`, `+` co-issue and constants c0-c7: a dozen instructions each.
- **Bump-env** (`SetTextureState_BumpEnv`, 4 sites in `FUN_00328bf0`), **texture factor** (6), **palettes**,
  **two UV sets** (rooms carry UV0 and UV1 for lightmaps).

### Framebuffer, targets and the rest

| Feature | Where | bgfx mapping |
|---|---|---|
| Render targets, back-buffer reads | `d3dContext` slot 92 (`SetRenderTarget`, `GetBackBuffer`), `d3dExtFrameBufferTexture`, `d3dExtFramebufferEffects` (glow/blur/colour passes, `DrawVerticesUP` quads) | frame buffers + views; full-screen passes as views with an orthographic quad |
| `CopyRects` (3 sites: screenshot/pause background and effects) | `0x31b1e0`, `0x31b230`, `0x320aa0` | `bgfx::blit` where `BGFX_CAPS_TEXTURE_BLIT`, else a textured quad (WebGL2) |
| Occlusion queries | `d3dExtVisibilityTest` (Begin/End/GetResult) | `bgfx::createOcclusionQuery` (WebGL2 has them) |
| Antialias control | `d3dExtAntialiasControl` (MSAA on/off, mask) | back-buffer MSAA flag at reset |
| Gamma ramp | `d3dExtGammaControl`, `D3DDevice_SetGammaRamp` | a final full-screen pass with a 256x1 LUT |
| Read pixels | `d3dExtReadPixels` | `bgfx::readTexture` (asynchronous; check the caller tolerates a one-frame delay) |
| Point sprites | `d3dPointSpriteShader` (unused by data) | expand to quads if ever needed |
| Swap / vblank pacing | `d3dDisplay` slot 14, `SetVerticalBlankCallback(0x31acc0)` | `bgfx::frame()`; the vblank counter driven by the platform frame clock |
| Immediate primitives | `d3dPrimStream` (`DrawVertices` from `pddiBaseContext` batching), `DrawVerticesUP` | transient vertex buffers |
| Static meshes | `d3dPrimBuffer` (vertex buffer lock, `DrawIndexedVertices`, `SetIndices`) | static vertex/index buffers created on unlock |

Push buffers, the NV2A method immediates, `D3D_SetPushBufferSize`, `KickOffAndWaitForIdle`, `XGIsSwizzledFormat`,
`D3D_CheckDeviceFormat` and `GetDeviceCaps` have no counterpart: they disappear with the D3D layer.

### Getting the shader semantics without vendor code

The rule ([platform-boundary.md](platform-boundary.md#rules-for-library-and-platform-code-decided-2026-10-18)): no
leaked XDK material, no vendor code; the game's own code and public documentation are fine. The vertex programs are
**the game's code** (Radical's, in the player's XBE), in the same position as the x86 code we decompile. Approach:

1. **An NV2A vertex-program decoder and CPU interpreter of our own** (`tools/nv2a_vsh.py`, plus a C++ twin for the
   test harness), written from public descriptions of the NV20-family vertex program format (nouveau/envytools
   documentation, xboxdevwiki); xemu and Cxbx-Reloaded may be *read* as references, as the rules allow, but no code
   is copied (both are GPL/LGPL). It reads the 17 programs from the player's XBE at the addresses
   `FUN_00329430` gives. Dev-time only: it prints a listing on the developer's machine; nothing derived from the
   bytes is committed except the hand-written shaders.
2. **Hand-write each program** as a bgfx `.sc` vertex shader (the same status as a hand-written `equivalent/`
   source: our code, written against the game's behaviour). About 430 instructions for the data-used set.
3. **Check each one per vertex**: random vertex inputs and constant files through the CPU interpreter and through
   the compiled shader (render one point per vertex into an RGBA32F target and read it back); tolerance per output
   register, like `tools/equiv.py`. This is the vertex-shader version of the repo's existing equivalence gate.
4. **Fallback, run-time translation**: if hand-writing stalls, the same decoder emits shader source at first run on
   the player's machine (the way the first-run flow already extracts RCFs), compiled with bgfx's `shaderc` shipped as
   a tool. Heavier (shaderc pulls glslang, SPIRV-Cross, SPIRV-Tools and Tint; see the prototype) and a second code
   path to test, so it is the fallback, not the plan.
5. **Pixel shaders**: from the `xps.1.1` text in our verified sources (translation by hand; no decoder needed), and
   from public D3D8 documentation of texture-stage operations for the combiner key. Register-combiner structures
   (`PSDEF`) are only needed for the unused bump-map shader.

## 3. Library choice

| | bgfx | SDL_gpu (SDL3) | sokol_gfx | own WebGPU (Dawn / wgpu-native) |
|---|---|---|---|---|
| Native backends | D3D11, D3D12, Metal, Vulkan, OpenGL 2.1/3.1+, GLES 2/3.1 | Vulkan, D3D12, Metal | GL 3.3, GLES3, Metal, D3D11, WebGPU, Vulkan (experimental) | Vulkan, Metal, D3D12 via the implementation |
| Web | **WebGL 1/2 via Emscripten**; WebGPU "Dawn Native only", i.e. not in the browser | **none** documented | WebGL2 and WebGPU | WebGPU in the browser |
| Shaders | own `.sc` dialect, offline `shaderc` to every backend | SPIR-V / DXIL / DXBC / MSL; SDL_shadercross to convert | annotated GLSL, offline `sokol-shdc` | WGSL |
| Licence | BSD-2-Clause | zlib | zlib | BSD-3 (Dawn) / MIT-Apache (wgpu) |
| Fit | one backend for native + web; mature; heavy build (genie, three repos) | already our SDL3 dependency; no web, no GL fallback | small, header-only, has browser WebGPU; Vulkan still experimental | one API everywhere but WebGPU on old GPUs / Deck is via Vulkan only |

Sources (checked 2026-10-18): bgfx backends, platforms, licence:
[bgfx overview](https://bkaradzic.github.io/bgfx/overview.html), [bgfx LICENSE](https://github.com/bkaradzic/bgfx/blob/master/LICENSE)
("Copyright 2010-2026 Branimir Karadzic", BSD-2). SDL_gpu drivers and shader formats:
[SDL_gpu.h](https://raw.githubusercontent.com/libsdl-org/SDL/main/include/SDL3/SDL_gpu.h) (Vulkan, Direct3D 12,
Metal; SPIRV, DXBC, DXIL, MSL, METALLIB); SDL's
[Emscripten README](https://raw.githubusercontent.com/libsdl-org/SDL/main/docs/README-emscripten.md) mentions only
GLES/WebGL and the 2D renderer, not the GPU API; a forum report agrees
([SDL discourse](https://discourse.libsdl.org/t/can-sdl3-gpu-functions-shader-be-compiled-to-wasm/59691)). sokol:
[floooh/sokol](https://github.com/floooh/sokol) ("GL/GLES3/WebGL2 + Metal + D3D11 + WebGPU + Vulkan (experimental)",
zlib). Emscripten's browser WebGPU path: [Emscripten WebGPU](https://emscripten.org/docs/porting/multimedia_and_graphics/WebGPU-support.html).

**Recommendation: bgfx.** It is the only option with mature native backends on all three desktop targets
(Metal on macOS, Vulkan/GL on the Deck, D3D11/12 on Windows, D3D11 also covering Wine) *and* a documented browser
target, so [web-port.md](web-port.md) stage W4 becomes "shared". Its state model (64-bit render state + stencil
words, views, transient buffers, occlusion queries, BC1-3 textures) matches what pddi asks for. The costs: bgfx's own
shader dialect and offline `shaderc` step, and its build system (GENie) next to our clang-cl/lld-link build; the
backend library is built once per target and linked. If the web is dropped, SDL_gpu becomes the simpler choice (one
fewer dependency), and the pddi cut keeps that switch cheap: only `src/platform/sdl/pddi/` changes.

Licences to ship: bgfx, bx, bimg (BSD-2, notices in the binary's licence file); bimg's bundled decoders and shaderc's
third-party parts (glslang, SPIRV-Cross, SPIRV-Tools, Tint) only if shaderc ships (fallback route of section 2).

### Prototype (`build/gfx-proto/`)

Question: does bgfx build here with the installed toolchain (Apple clang 21, make, no installs), and can one shader
source reach every backend we need?

- Shallow clones of upstream `bx`, `bimg`, `bgfx` (heads of 2026-10-16/17) in `build/gfx-proto/ext/`; bx's bundled
  GENie generated `gmake-osx-arm64` projects; `make -j2 config=release bgfx shaderc` built cleanly (9 warnings) in
  6 min 42 s wall time: `libbgfxRelease.a` (10 MB) and `shadercRelease` (18 MB; its static dependencies glslang,
  SPIRV-Cross, SPIRV-Tools and Tint are about 1.2 GB of `.a` files, which is why shipping shaderc is the fallback).
- `build/gfx-proto/shaders/`: a fixed-function vertex shader (`vs_ff.sc`: transform, one directional light +
  ambient, linear fog) and a texture-stage fragment shader (`fs_tss.sc`: one stage with select / modulate /
  modulate2x / add, alpha test by `discard`, fog blend), compiled by `build.sh` for **Metal, SPIR-V (Vulkan),
  GLSL 330 and 440, ESSL 300 (WebGL2) and WGSL**: all 12 compile (0.9 to 3 KB each).
- **Not possible on macOS: the D3D11/12 profiles** (`s_5_0`): "HLSL compiler is not supported on this platform";
  shaderc needs Microsoft's shader compiler DLL, so D3D shader binaries are built on Windows (or under Wine with the
  compiler DLL from a Windows install, not shipped by us). On Windows the Vulkan or GL backend avoids that step.
- One trap found: uniform names starting with `u_alphaRef` collide with a bgfx predefined (`u_alphaRef4`); use our
  own prefix for backend uniforms.
- Not tried: a window/run test (needs the examples' glue, not built), an Emscripten build, the i686 Windows build.

## 4. Test strategy

Ground truth is the original game in xemu, run through the hybrid build's deterministic replays
([hybrid-build.md](hybrid-build.md): fixed dt, virtual clock, seeded RNG, pad replay keyed by polls, checkpoints).

1. **Per-draw pddi records (the main oracle).** Add a hybrid-build hook flag `drawlog` at the pddi level: in our
   verified `d3dContext`/`d3dPrimBuffer`/`d3dPrimStream` draw entry points (they are already our objects in the
   hybrid image), append one record per draw to a ring like the checkpoint ring: frame, draw index, shader name and
   class, vertex program name + declaration flags, primitive type and count, the pddi render state (blend, z, cull,
   stencil, fog, alpha test, fill), the bound textures by **content key** (the HD key, section 5), a hash of the
   vertex constant file, the viewport and render target. Read the ring over QMP `memsave` as the checkpoints are. The
   native backend writes the same record at the same pddi calls. A diff tool aligns the two streams by frame and draw
   index and names the first mismatch: wrong state is found without looking at a pixel, independent of the GPU.
2. **Screenshots at replay checkpoints.** The harness already saves xemu's scan-out (640x480 X8R8G8B8 from
   `NV_PCRTC_START`, `tools/hybrid_run.py`). The native build runs the same recording with the same hooks, renders
   at 640x480 in test mode, and dumps the back buffer at the same frame numbers. Compare with a perceptual metric
   (SSIM / FLIP) and a per-scene threshold, plus a diff heat map in the report; exact equality is impossible (NV2A
   rasterisation, 16-bit back buffer at 720p, DXT decoders differ). Frames: one per scene type (title, menus, each
   level's first frame, a fight, an NIS, a glow effect). Keep the reference PNGs under `build/` (game output is game
   data; never committed).
3. **Shader unit tests**: the NV2A interpreter against each hand-written vertex shader (section 2); a CPU reference
   of each texture-stage key against the generated fragment shader on small textures; the `xps` effects shaders
   against a CPU reference of their 8-10 instructions.
4. **Backend smoke scenes without the game**: a small `pddi` test program (first triangle, each blend mode, each
   combiner op, render-to-texture, occlusion query) rendered on Metal, Vulkan, D3D11 and WebGL2; their PNGs are ours
   and can be committed as regression references.
5. **Debugging tools**: RenderDoc (Vulkan/D3D) and Xcode's Metal capture on native builds; `bgfx::setDebug` stats.

## 5. HD textures

The key scheme in [texture-packs.md](texture-packs.md) is XXH64 of the mip-0 ImageData **payload** (the DDS or PNG file
bytes). The texture path is: `TextureLoader`/`ImageLoader` (engine) read the chunk, an `ImageHandler` decodes it,
`pddiDevice` slot 9 (`d3dDevice::vfunc_9`, called from `pure3d/Texture.cpp`) creates the `pddiTexture`, and
`ImageConverter`/`TextureBuilder` (engine) fill it through `pddiTexture` slots 13/14 (lock/unlock) and 11 (palette).
The backend never sees the DDS file itself, only the locked surface it receives.

Two ways to hook it:

- **(A, recommended) In the backend, no engine edit.** `bgfxTexture::Unlock(mip 0)` hashes what it received: for DXT
  textures the mip-0 block data (on NV2A compressed formats are not swizzled, so these are the payload's mip-0 bytes
  minus the 128-byte DDS header; verify on the hybrid build with the draw log), for PNG-derived textures the decoded
  pixels in the locked format. Key = XXH64 over `(format, width, height, bytes)`. Look up `mods/textures/<key>.png`;
  on a hit, upload the PNG (any size, RGBA8, generate mips) in place of the locked data and keep the original's
  sampler state. This needs texture-packs.md's key redefined and `tools/texpack_convert.py convert` to compute the new
  key; it has every Xbox texture's bytes in hand, so that is a small change (not made here).
- **(B) Keep the payload key** with a two-line hook in the engine image loader that passes the payload hash to the
  next texture created. It touches portable engine code for a platform feature, which the layer rules discourage.

Dump mode (`HULK_TEXDUMP=1`) writes every uploaded texture as `<key>.png` in upload order, so modders can make packs
against the Xbox data directly. Memory: 4x packs multiply texture memory by 16; keep DXT originals on GPU and
compress PNG replacements to BC3/BC7 at load (bimg can encode) or cache the converted result on disk.

## 6. Staged plan

Sizes assume one person directing agent batches, after the native 32-bit build runs the game loop with stubbed
graphics (today's state: it links and starts, [native-build.md](native-build.md)).

| Stage | Work | Size | Parallel batches |
|---|---|---|---|
| G0 Harness | bgfx (bx, bimg) built by `tools/native_gfx.py` for i686-pc-windows-msvc (D3D11) and macOS (Metal); `src/platform/sdl/pddi/` skeleton; the native link swaps `platform/xbox/pure3d` + `graphics_*.cpp` for it; SDL3 window; hybrid `drawlog` hook + record reader + diff tool. **Built 2026-10-18 except the link swap (section 7)** | 1 to 2 weeks | the drawlog hook and the bgfx build are independent |
| G1 First triangle | `bgfxDisplay` (init, reset, swap, sizes, aspect), `bgfxDevice` (factories), `bgfxContext` clear + transforms + fixed-function vertex shader + one texture stage, `bgfxPrimStream` immediate draws, `bgfxTexture` for DXT1/3/5 and RGBA, `error` shader. **Linked and drawing in the native image 2026-10-19 (section 8): Vulkan under Wine; the game's own first frame waits for the native build** | 1 to 2 weeks | display/device vs texture vs prim stream |
| G2 Menus and front end | the `simple` shader with its 1-3 stage combiners, texture-stage state key + shader cache, blend/z/cull/alpha test, 2D mode (`pddiBaseContext`), PNG/P8 textures, fonts, the copyright and title screens, movies' render strategy (frames as textures). Compare draw logs and screenshots for title → main menu → options. **Combiners done 2026-10-19 (section 10): every data-used class's pass set-up ported onto a D3D device-state model, 100 combiner keys with a generated program each (+ a generic combiner), the fade, blend table fixed, four stage samplers, texgen + texture matrices, linear textures (texel coordinates), 2D modes, the movie tile path; P8 is unreachable in this game. Self-test 464 probes on Metal and under Wine/Vulkan. The front end's own frames wait for the native build** | 2 to 3 weeks | combiner ops, state mapping, P8/palette, screenshot tooling |
| G3 A level | `bgfxPrimBuffer` static meshes, vertex declarations from the flags word, `skin`/`skin_onebone`/`simple_*` programs (NV2A interpreter first), hardware-skinning extension, `layered` (+ lightmap pair) and `layeredReflect`, fog, stencil (shadows/decals), `environment`, lights from `pddiLightingState`. Target: the junkyard tutorial replay with matching draw logs. **Draw path done 2026-10-19 (section 9): prim buffers, the skin programs through the skinning extension, the fixed-function program with lights, render-state slots 54-80, views; self-test 19/19 probes on Metal and on Vulkan under Wine. The level waits for the native build; the shader classes' combiners are G2's** | 3 to 5 weeks | one batch per shader class; one per vertex program (interpreter-checked); state/fog/stencil |
| G4 Effects | `d3dExtFramebufferEffects` (114 functions: glow levels, blur, colour passes, the 17 `xps` shaders), render targets, `CopyRects`, `refract` (+`skin_refract`), visibility tests, gamma, read pixels, antialias | 2 to 3 weeks | the 17 `xps` translations as one batch; targets/copies; queries/gamma |
| | **Done 2026-10-19 (section 12): the frame drawn into a scene target with a present pass; the display's frame-buffer copy (blits ordered between views) and the refraction shader's constants and stage; the vertex program extension that gives meshes their program; the framebuffer effects (colour correction, the fbeffects shaders' average, bloom, the motion-trail overlay) with the xps programs translated; visibility tests as occlusion queries; antialias answers. Self-test 502 probes on Metal; 498 on Vulkan under Wine (page 5's four vertex-program-extension probes came after the last Wine run). Not done: two-sided lighting; the unused extensions (gamma, read pixels, framebuffer texture, render targets, projected texture)** | | |
| G5 Web and polish | WebGL2 via the same backend (Emscripten bgfx build, `BGFX_CONFIG_MULTITHREADED=0`, blit fallback), HD textures + dump mode, resolution independence (640/480 literal), MSAA/anisotropy options; the unused shader classes only if a factory log shows them | 1 to 3 weeks | HD textures independent of everything after G1 |
| | **G5 clean-up done 2026-10-19 (section 13): every shader the backend draws with proven against an independent reference (the framebuffer effects' 20 pixel programs against an interpreter of the game's text, the fixed-function vertex path against Direct3D 8's pipeline as the game sets it up, the 100 combiner keys against the texture-stage reference); three fixed-function corrections from the game's state; the frame scaled into any window with its aspect kept (HULK_GFX_SCALE); quad copies where a renderer can't blit; the OpenGL origin for render-target copies; two-sided lighting on the fixed-function path; deferred texture uploads (the boot movies' crash). Self-test 548 probes on Metal. Not done: an OpenGL/WebGL2 run, the web build** | | |

Total about **10 to 16 weeks**. The critical path is G0 → G1 → G3 (vertex programs and the level shaders). What
batches well: each shader class is a self-contained port of one verified `platform/xbox` object (12 to 40 functions,
1 to 3 KB) with a draw-log diff as its acceptance test; each vertex program is a 22 to 72 instruction translation with
the interpreter as oracle; combiner ops are table rows. Keep Claude-side agents on the shader classes and effects
(they need reading the verified C), and small mechanical items (state enum tables) on the cheaper lanes.

Prerequisites outside this plan: the native build's game loop running past start-up with graphics stubbed; the radcore
file shim reading extracted data; input replay in the native build (needed for the frame-matched comparisons).

## 7. G0: the harness (built 2026-10-18)

```sh
PY=build/venv/bin/python
$PY tools/native_gfx.py fetch            # pinned tarballs -> build/third_party/{dl,src} (sha256-checked), notices
$PY tools/native_gfx.py build            # bx/bimg/bgfx static libs: host (macOS arm64, Metal) and win32 (i686): ~10 s
$PY tools/native_gfx.py shaderc          # bgfx's shaderc for the host (GENie + make -j2): ~5.5 min, once
$PY tools/native_gfx.py pddi             # the skeleton: host lib + smoke test; win32 hulk_pddi.lib
$PY tools/native_gfx.py smoke            # a window, clear + one triangle through the skeleton's context API
$PY tools/native_gfx.py slots            # MS-ABI vtable layout of every skeleton class vs build/rtti.json
$PY tools/native_gfx.py status
$PY tools/hybrid_test.py replay build/replays/final1.json --until-frame 900 --drawlog 30:300:900 \
    --drawlog-out build/g0/drawlog-a.jsonl  # xemu: the replay with a per-draw log (checkpoints still compared)
$PY tools/drawlog_diff.py build/g0/drawlog-a.jsonl build/g0/drawlog-b.jsonl   # IDENTICAL / first mismatches
```

**bgfx as a dependency** (`tools/native_gfx.py`; everything under `build/third_party/`, nothing installed system-wide).
Pinned upstream commits as GitHub tarballs with their sha256 in `PINS`: bx `dd261e27`, bimg `6d60464e`, bgfx `4410cdfc`
(2026-10-16/18 heads; BSD-2-Clause, notices collected into `build/third_party/out/LICENSES.txt`), and the mingw-w64
v14.0.0 **headers** (public domain / ZPL notices; compile-time only, nothing of mingw-w64 is linked). No build system of
theirs is used for the libraries: each library is its amalgamated source (`bx/src/amalgamated.cpp`, `bimg/src/image.cpp`
with ASTC decoding off, `bgfx/src/amalgamated.cpp`), compiled directly, so the two targets share one recipe:

| target | compiler | renderers | output |
|---|---|---|---|
| `host` (macOS arm64) | Apple clang, `-x objective-c++ -std=c++20` | Metal (+ noop) | `out/host/lib/{bx,bimg,bgfx}.a` (0.3 / 0.2 / 1.3 MB) |
| `win32` (i686) | Homebrew LLVM clang `--target=i686-pc-windows-msvc` (native_link.py's toolchain): MS C++ ABI, `-msse4.2`, no exceptions/RTTI/`/GS`/thread-safe statics | Direct3D 11, OpenGL, Vulkan (all loaded at run time) | `out/win32/lib/{bx,bimg,bgfx}.lib` (0.4 / 0.3 / 1.8 MB) |

Both use `BGFX_CONFIG_MULTITHREADED=0` (pddi drives bgfx from the game's render thread; no render thread, no TLS; the web
build needs the same). The Windows build has no MSVC or Windows SDK headers here, so it compiles against mingw-w64's
headers (Windows API, msvcrt-flavoured C runtime) with the MSVC triple plus `-fgnuc-version=4.2.1` (the headers expect a
GNU front end), a small generated compat header (one UCRT-only declaration bx uses, and `#pragma init_seg(".CRT$XHU")`,
see below), and bgfx's bundled DirectX headers. One local fix to the pinned sources (`PATCHES`): bx's `macros.h` defines
`__stdcall` away for clang with the MSVC CRT, which on i686 turns every WINAPI and COM call into cdecl (found by the
undecorated `__imp__CloseHandle`); it is kept on `_M_IX86` (worth reporting upstream). shaderc is built with upstream's
GENie projects (`--with-tools`, `gmake-osx-arm64`, `make -j2 shaderc`) and copied to `build/third_party/tools/shaderc`;
`native_gfx.py shaders` compiles `src/platform/sdl/pddi/shaders/*.sc` for Metal, SPIR-V, GLSL 430, ESSL 300 and WGSL
(10/10). D3D bytecode still needs Windows (section 3).

What the native link has to do with these libraries is in `build/g0/LINK.md` (not done here: `native_link.py` belongs
to the native-build work): add `hulk_pddi.lib` + the three libraries, bind the skeleton's 95 `FUN_<address>`
references to the tree's pddi base functions, bind `d3dCreateDevice` (0x31ba60) to `hulk_pddi_create_device`, and
import libraries for the plain kernel32/user32/gdi32/msvcrt/ntdll names bgfx uses (listed there). The image skips
clang's `.CRT$XCU` initializers on purpose, so the Windows libraries put theirs in `.CRT$XHU` and
`src/platform/sdl/pddi/win32_glue.cpp` runs them (with stand-ins for five UCRT-only functions msvcrt.dll lacks).
Checked by a stand-alone PE linked with the image's flags (`/nodefaultlib /safeseh:no /machine:x86`, import libraries
generated from Wine's own export tables; `build/g0/probe/`, not tracked): **Direct3D 11 under Whisky's Wine renders and
reads back the clear colour.** OpenGL crashes under Wine on macOS (macOS GL is 4.1, bgfx asks for 4.3) and Vulkan has no
ICD there; on Windows / the Deck both are available.

**The pddi skeleton** (`src/platform/sdl/pddi/`): one class per D3D-side pddi class, keeping the MS-ABI vtable slot
order of the game class it stands in for: `bgfxDevice`, `bgfxDisplay`, `bgfxContext` (111 slots), `bgfxTexture`,
`bgfxPrimBuffer`, `bgfxPrimBufferStream`, `bgfxPrimStream`, `bgfxShader` (d3dShader's 25 slots) with the six data-used
kinds `bgfxSimpleShader`, `bgfxLayeredShader`, `bgfxBuildingShader`, `bgfxReflShader`, `bgfxRefractShader`,
`bgfxFBEffectsShader` plus `bgfxErrorShader`, and the nine extensions. Slot lists come from `build/rtti.json`, signatures
from `include/gen/pure3d.h` with each slot's stack shape checked against the game function's `ret N` (two headers were
short: `d3dDisplay` slot 4 takes a config pointer, `d3dExtFramebufferEffects` slot 8 takes 8 words) and returns
corrected where the verified source shows one (display slots 9/13/17 return 0; device slots 7 and 9 return the new object). Each
slot is either *ours* (the D3D backend's overrides and the slots the game leaves pure: a logged stub, counted per
slot, or a minimal bgfx implementation) or *base* (inherited from a portable pddi base, i.e. engine code in the tree: in
the native image it calls the tree's function by XBE address through `game_base.h`; on the host it is a logged stub).
The context keeps the portable base's 0x148 bytes of data where the base's functions expect them and runs the base
constructor (0x31f410) in the native image. Implemented: device factories, display init on a native window (SDL3 on
the host), sizes, aspect, swap (`bgfx::frame`), context begin/end frame, clear (pddi flags 1/2/4 from the base's clear
block), immediate prims (slot 30 returns a prim stream with d3dPrimStream's field layout for the engine's inline vertex
writes, slot 31 draws it through a transient buffer and a stand-in fixed-function program), cull mode. The prim kinds
come from the game's table at 0x4d3650 (0 tri list, 1 tri strip, 2 line list, 3 line strip, 4 points). Everything
else is G1+. `native_gfx.py slots` compiles the skeleton for i686 with clang's vtable dump: **all 23 classes have the
game's slot count and every `vfunc_N` sits at index N.**

**Smoke test** (`smoke/smoke_main.cpp`, host): SDL3 window, `hulk_pddi_create_device` -> display (slot 7) ->
`hostInit` (bgfx on Metal) -> context (slot 8); per frame begin (4), clear (12), begin prims (30), three vertices written
through the stream's pointers as the engine's inline code does, end prims (31), end frame (5), swap (display 14); a
screenshot four frames from the end is checked at two pixels. Result: `renderer Metal ... corner 32,48,64 centre
255,128,0 -> PASS` (the clear colour and the triangle's), and the native draw log of the run (`smoke.pdl`, 120 draws).

**drawlog** (hybrid build; `hybrid/hooks.cpp` `HYBRID_DRAWLOG`, `tools/patch_xbe.py --drawlog` / `hooks["drawlog"]`,
`tools/hybrid_test.py replay --drawlog`, `hybrid_run.read_drawlog`, `tools/drawlog_diff.py`; details in
[hybrid-build.md](hybrid-build.md#drawlog-per-draw-pddi-state-graphics-backend-g0)): the 11 call sites of the D3D draw
functions in the pure3d backend go through a logger that records, in selected frames, 24 words per draw: frame, draw
index and site, primitive type and count, the active shader's class (vftable) and id, the four stage textures as
first-seen ordinals, the context's render-state and stencil blocks, the fog flag, and a hash of the top matrices. The
native backend writes the same record (`pddi.h` `DrawRecord`, `drawlogDump`), so `drawlog_diff.py` compares hybrid with
native as well as two hybrid runs. Proof on `build/replays/final1.json` to frame 900, logging every 30th frame from 300:
two runs logged **5,357 draws each in 21 frames (of 234,574 draws executed), all fields identical**, and both runs'
checkpoints matched the recording's (31 of 31, no divergence). The hooks-only build without the flag is unchanged
(hooks.cpp compiles to the same code and data). What the log shows already: in those frames the data uses
`d3dSimpleShader` (4,467 draws), `d3dLayeredShader` (759) and `d3dBuildingShader` (131); 85% of draws are prim-buffer
`DrawIndexedVertices` tri strips; 164 distinct textures.

**Open after G0**: the link integration (LINK.md); D3D11 shader bytecode (Windows or the compiler under Wine); the
prim stream's pending-vertex carry-over, mid-frame clears (a new view), the clear-by-quad path; `bgfx::reset` with the
2026 swap-chain API for mode changes; whether portable code reads d3d-side fields beyond the base data of the context,
display or texture (the skeleton keeps only the base's layout); include/gen returns that are `void` where the game's
caller reads eax (only the ones above were corrected).

## 8. G1: the backend in the native image (2026-10-19)

```sh
PY=build/venv/bin/python
$PY tools/native_gfx.py build --target win32 && $PY tools/native_gfx.py pddi   # libraries + hulk_pddi (host + win32)
$PY tools/native_link.py --reuse-map --gfx          # the image with the pddi/bgfx backend (or HULK_NATIVE_GFX=1)
HULK_GFX_SELFTEST=30 HULK_GFX_SHOT=10 HULK_GFX_SHOT_DIR='Z:/abs/dir' $PY tools/native_run.py
HULK_GFX_DRAWLOG=0:1:9 HULK_GFX_DRAWLOG_OUT='Z:/abs/x.pdl' $PY tools/native_run.py   # the native draw log (PDL1)
$PY tools/drawlog_diff.py build/g1/drawlog-boot-hybrid.jsonl x.pdl --ignore shader_id   # hybrid vs native
$PY tools/native_gfx.py d3d4linux && $PY tools/native_gfx.py shaderc   # HLSL route (HULK_GFX_DXBC=1 shaders): see below
```

Run-time options (environment, `src/platform/sdl/pddi/sdl_platform.cpp`): `HULK_GFX_RENDERER` (d3d11, the default
on Windows; `tools/native_run.py` sets vulkan under Wine), `HULK_GFX_SIZE` (640x480), `HULK_GFX_SHOT` /
`HULK_GFX_SHOT_DIR` (TGA screenshots of given frames), `HULK_GFX_DRAWLOG` / `HULK_GFX_DRAWLOG_OUT`,
`HULK_GFX_FRAMES` (exit after N presents), `HULK_GFX_HIDDEN`, `HULK_GFX_SELFTEST`. Backend log lines go to the
image's trace as `gfx ...` (`hulk_native_log` in `src/platform/sdl/xdk/startup.cpp`).

**Link** (`tools/native_link.py --gfx`, `graphics_backend`; build/g0/LINK.md done): the pddi objects are linked as
objects, bgfx/bimg/bx as libraries. Every host function those reference is renamed `hulk_gfx_<name>` in copies of
the objects and libraries (`build/native/link/gfx/`) and comes from import libraries of our own (`hulk_gfx_X == X`,
kernel32/user32/gdi32/msvcrt/ntdll, a fixed name table in native_link.py). The renaming matters: the tree binds
plain names to other things (`_free` and `??3@YAXPAX@Z` to the game's heap 0x267090, `_memcpy` to the host CRT,
`_CloseHandle@4` to the XDK shim; `??2@YAPAXI@Z` is still a stub), and a real `_free` from an msvcrt import library
would silently take over those references. The pddi objects' `GameBase::FUN_<address>` references are bound by
address like the tree's (89 now, all bound: G0's 95 less the six base shader table getters, which are ours since
G1; 116 host imports renamed), `d3dCreateDevice` 0x31ba60 is bound to `hulk_pddi_create_device` (the caller
in `pure3d::InitPlatform` 0x292560 is aliased to it), and `hulk_pddi_create_device` runs bx/bgfx's `.CRT$XHU`
initializers. **Strict lld-link: 0 errors** (8.81 MB; 1,722 symbols still stubbed, as without --gfx, which also
links with 0 errors: 7.49 MB). The MSVC 7.1
verification build can't be affected: no generator or source file changed (only native_link.py and
`src/platform/sdl/`, which `gen_tree.py`/`build_tree.py` never read). The same change fixed `source_slots`'s symbol
pattern (a namespace between the stub class and the TU's `fn_` namespace, `?acquire@Lock_2756e0@core@fn_f0fe475a@@`):
10 more virtual-dispatch stubs (1,262 -> 1,272), for the --gfx and the plain link alike.

**Binding: which objects are ours.** Everything the engine reaches comes from the device it gets from
`d3dCreateDevice`, so binding that one function is enough for the device, display (device slot 7), context (slot 8),
textures (9), prim buffers (10) and shaders (11): the engine only ever calls them by slot. The one engine-layer
registration point is the shader factory: `FUN_00328130` (in `pddiBaseShader.cpp`, engine layer) fills the
name -> creator table at 0x5555c8 with 16 creators that construct `d3d*` shader classes, and `d3dDevice::vfunc_11`
looks a name up in it (`FUN_00327c70`). `FUN_00328130`'s only caller is `d3dDevice`'s constructor (0x31ba00), which
our device replaces, so in the native image the game's table stays empty and nothing reaches a `d3d*` shader
constructor; `bgfxDevice::vfunc_11` is the same lookup over our classes (`bgfxDevice::newShader`: simple/lightweight,
layered, layeredReflect, environment, refract, fbeffectsshader; every other name, and unknown ones, the error shader,
logged once, as the game falls back to entry 0). Considered and not done: binding the 15 creator functions
(0x327e60..0x328100) to ours (15 aliases into engine-layer code instead of one platform function), or registering our
creators in the game's table (keeps the engine-layer table and its 64-byte name slots for no gain). When
`include/seams/` is written, the factory table and its lookup move to the platform layer next to the device. The rest
of `platform/xbox/pure3d` stays linked (the Xbox layer is still in the tree), unreachable except for the two
`pddiObject` constructors 0x31bac0/0x31bae0 (engine helpers, harmless) and a few portable helpers that happen to live in
d3d objects (the text drawer 0x328270, `FUN_00328250`/`60`, `FUN_0031c180`): they only call pddi slots.

**What the backend does now** (on top of G0's skeleton):

| piece | what | specification |
|---|---|---|
| device | layout `+8` error, `+0xc` current context (slots 5/6), slot 4 version block (18, 11, 56, "bgfx ..."), slot 8 runs the base's state reset (slot 99) as 0x320d30 does, slot 9 textures, slot 11 the factory | 0x31b7d0..0x31b9f0 |
| display | slot 4: an SDL3 window (section 11) + `bgfx::init` (size from `HULK_GFX_SIZE`; the game asks 1280x720), slot 14: `bgfx::frame` + message pump + screenshots/draw log | 0x31ae70, 0x31b190 |
| context | slot 89 (GetExtension) returns our nine extensions by id (0x101 gamma, 0x500001 antialias, 0x500004 projected texture, 0x500005 read pixels, 0x102 skinning, 0x500002 visibility, 0x106 vertex program, 0x103 framebuffer effects, 0x104 framebuffer texture); prim streams drawn with the stage-0 texture, alpha test and BLMD blend | 0x321ea0, 0x324e00 |
| shaders | slot 4 the name; slots 15-20 return key -> setter tables for the base's Set* slots 5-10 (the base, tree code, calls our `__thiscall` setters): TEX/TTEX/REFL, UVMD FIMD SHMD LIT BLMD ATST ACMP 2SID, SHIN ACTH FADE, AMBI DIFF EMIS SPEC and each kind's own keys (accepted, kept for G2) | the keys from the game's tables (0x4d7988.., filled by 0x361a90 & co.), the fields from d3dShader's setters 0x3333a0.. |
| textures | create (power-of-two check for format 0), lock returns the game's level description (size, bpp, type, ARGB masks/starts/shifts, stride, bits: bottom-up with a negative stride for the uncompressed formats, as the Xbox lock), unlock uploads; uncompressed formats stored A8R8G8B8 (the engine converts into the masks it is handed), DXT1/3/5 as BC1/2/3 | 0x326330, 0x326900, 0x31c570, 0x31c290, 0x325fd0 |
| slot returns | corrected where the game's function returns a value and include/gen says void: context 7, 36, 82, 89; texture 12, 13; prim buffer 4, 7; visibility 4; shader 4, 5, 8, 15-20 | the verified sources |

**Renderers under Whisky's Wine 7.7 on this Mac:**

- **Direct3D 11 (wined3d): presents.** Clear + present + screenshot work in the game image. No draws: there is no
  D3D shader bytecode. The route to it is built and runs: `native_gfx.py shaderc` now builds upstream shaderc with
  its d3d4linux bridge on macOS (`SHADERC_CONFIG_HAS_D3DCOMPILER=1`; upstream enables it for Linux only; bgfx's copy of
  the DirectX-Headers WSL stubs needs `sal.h`, taken from mingw-w64's headers into a directory of its own), and
  `native_gfx.py d3d4linux` builds upstream's `3rdparty/d3d4linux` server as an x86_64 PE with our toolchain (a
  60-line std::string/vector stand-in of ours for the two STL types it uses; x86_64 because it calls D3DCompile
  through plain function pointers) next to a link to **Wine's own d3dcompiler_47** (Wine's implementation, no
  Microsoft code). shaderc -> d3d4linux -> D3DCompile works end to end, but Wine 7.7's HLSL compiler rejects bgfx's
  shader library: no `asfloat`/`asuint`/`f32tof16`, `SamplerComparisonState`, `SampleBias`/`SampleLevel`, `rcp`,
  `lerp`, `transpose`, the ternary operator, and finally "call to user-defined function: not yet implemented". So
  `HULK_GFX_DXBC=1` stays opt-in for a newer Wine (or Linux); D3D bytecode for Windows builds comes from a Windows
  machine.
- **Vulkan (MoltenVK): draws.** Whisky ships `libMoltenVK.dylib` next to Wine; Wine's winevulkan finds it when
  `DYLD_FALLBACK_LIBRARY_PATH` includes Whisky's lib directory (G0's "no ICD"). bgfx's Vulkan renderer then starts in
  the i686 image after one local fix (`PATCHES`: GPU timer queries off with `HULK_VK_NO_TIMER_QUERY`;
  `TimerQueryVK::begin` divided by zero). SPIR-V shaders come from the macOS shaderc as before.
  `tools/native_run.py` sets both. Caveat: a second screenshot readback in one run hits an assertion in Wine 7.7's
  32-bit winevulkan thunks (`loader_thunks.c:5445`); one screenshot per run works.
- OpenGL: not retried (G0: bgfx asks for 4.3, macOS has 4.1).

**First frame and first draws.** `HULK_GFX_SELFTEST=N` drives N frames through the engine's own slots at context
creation (begin frame 4, clear colour through the base's slot 6 (tree code), clear 12, a triangle through prim
stream slots 30/31 with the inline vertex writes, a textured strip with the "simple" shader, end frame 5, swap 14),
then the game goes on. In the game image under Wine: **D3D11: 30 frames presented, screenshot centre 32,48,64 = the
clear colour. Vulkan: 60 frames; screenshot: clear 32,48,64 in the corner and centre, the triangle 255,128,0, the
textured strip showing its checker (255,255,255 / 0,64,192)** - the texture created through device slot 9, filled
through lock/unlock, and bound by setting the shader's `TEX` through the tree's `pddiBaseShader::vfunc_5`, which
walked our key table and called our setter.

**How far the game gets** (the native7 tree + G1, Wine): device, display and context are ours and no D3D import is
called any more; `pure3d::InitPlatform` completes (shader loaders, `tContext`), then physics init, the platform
start-up (streams, drive thread) up to mounting the RCF archives from `rcfs.txt` in `CPlatformManager::FUN_0008e880`.
Four native-only source bugs on the way were confirmed and probed with fixes in the scratch copy of the tree only
(the repo's sources are untouched; see docs/native-build.md "Graphics boundary crossed"), and the run now stops in
the RCF mount (`CementLibrary` 0x277a70 -> `FileCompletionRequest` 0x274d20 releases a `CementLibrary` through a bad
`this`): native-build work. **The game's own first BeginFrame/EndFrame is not reached yet**, so there are no game
draws to compare.

**Draw log.** The native record now reads what the hybrid hook reads, from the same places: the portable base keeps
its render-state (+0x4c), stencil (+0x58) and fog (+0x54) blocks and matrix stacks (+0x20..) in our context, so
those fields are comparable word for word; textures are first-seen ordinals given out at the first logged draw (as
`dl_tex`), the shader is `0x8000 | kind` and `drawlog_diff.py` translates the hybrid side's vftable to the kind when
one log is native. Reference for the comparison: `build/g1/drawlog-boot-hybrid.jsonl`, the hybrid replay of
`build/replays/final1.json` to frame 300 logging every 10th frame from 10: 8,070 draws in 29 frames (frame 10: 28
draws; from frame 100 about 300 per frame), all checkpoints identical (11/11). The native self-test log
(`HULK_GFX_DRAWLOG`) loads and aligns against it (no common frames: DIFFERENT, as expected). Two things to settle when
game frames exist: the native frame number is the display's present count, the hybrid's `g_hybrid.frame` (align the
definitions), and the native record's `seq` has no draw site.

**Open after G1:** the native-build blockers above (then the front end's real draws and the drawlog diff); prim
buffers (device slot 10, context slot 32: G3), vertex programs, the context's render-state slots 56-80 (stubs: depth,
stencil, fill, fog reach bgfx state only through the base's blocks, which the draw log reads), clear-by-quad and
mid-frame clears, the combiner modes of the simple shader beyond stage 0 modulate, D3D bytecode (Windows or a newer
Wine), the second-screenshot assertion under winevulkan, bgfx::reset for mode changes.

## 9. G3: the draw path: prim buffers, vertex programs, render state (2026-10-19)

```sh
PY=build/venv/bin/python
$PY tools/native_gfx.py shaders && $PY tools/native_gfx.py pddi    # shaders/ and shaders/vp/, host lib + win32
$PY tools/native_gfx.py smoke     # Metal: the self-test scene, 19 probes checked on a screenshot
$PY tools/native_gfx.py slots     # 23 classes, every vfunc_N at index N (still ok)
HULK_GFX_SELFTEST=30 HULK_GFX_SHOT=10 HULK_GFX_SHOT_DIR='Z:/abs/dir' $PY tools/native_run.py   # the same in the game
$PY tools/drawlog_diff.py HYBRID.jsonl NATIVE.pdl --align auto   # present-count native logs: the offset is found
```

Specification throughout: the verified `platform/xbox/pure3d` sources (the d3dContext overrides live in the tree's
`d3dExtFramebufferEffects.cpp`, the prim buffer and its stream in `d3dPrimBufferStream.cpp`), the game's own data
tables read from the XBE by address (only their values are used), and public Direct3D 8 documentation for what
the D3D states mean. New files: `bgfx_draw.cpp` (the draw path), `selftest_scene.cpp` (the scene), `shaders/vp/
vs_vp_ff.sc` and the stage fragment shaders `fs_vp_stage{,5,3}.sc` + `fs_vp_stage.sh`.

**One draw path.** Prim streams (context slots 30/31) and prim buffers (slot 32, the skinning extension) end in
`bgfxContext::draw`: the drawlog record, the program, the constants, the stage-0 texture, the fragment uniforms,
the bgfx state and stencil words, submit. Every draw uses one backend vertex (80 bytes: position, normal, blend
weights, bone indices, two colours, four uv sets) converted from what the game wrote, with Direct3D's defaults for
what the vertex lacks, so one bgfx layout serves every program (a per-format layout is a later memory saving).

**Prim buffers** (`bgfxPrimBuffer`, `bgfxPrimBufferStream`):

| piece | what | from |
|---|---|---|
| creation (device slot 10) | parameter block words 0 kind, 1 vertex flags, 4 vertex count, 5 index count, 7 program name; the D3D primitive type from 0x4d3ea8; the program: the name, else `skin` (flags 0x180) / `skin_onebone` (0x80) | 0x31b960, FUN_00327860 |
| the vertex | the game's *packed* layout (FUN_003290e0 with its packed flag, as FUN_00327860 asks): position; 0x100 blend weights and 0x10 normal as 11:11:10 (NORMPACKED3); 0x80 three bone indices x3 as D3DCOLOR bytes; 0x20 a colour or 0x4000 colour sets; 0x40 a second colour; uv sets; 0x200/0x400/0x800/0x1000 extras (kept, not read). The CPU copy holds exactly what the Xbox vertex buffer would | FUN_00326e90 (offsets), FUN_003290e0 (stride) |
| the stream (slot 4/5) | the record keeps the game's field offsets (+0x24 position .. +0x50 weights); slots 0-17: position, normal (packed with the game's 1/(length x 1.001) scale), the vectors, colour sets, uv sets, the second colour, bone indices, packed weights, whole vertices; FUN_00326f90's advance | 0x327450..0x3277a0 |
| indices | slot 7/8 lock/unlock (count in use), slot 9 copy, 16-bit | 0x327200..0x3272b0 |
| raw access | slot 11/12 lock/unlock the packed vertices | 0x327250, 0x327280 |
| draw count | slot 14: an override count; whole primitives only (FUN_00326dc0 + the table at 0x3f3260) | 0x3270a0, 0x3272f0 |
| bgfx buffers | converted at the first draw after a change: a static vertex/index buffer the first time, a dynamic one once the buffer is written again (animated geometry) | ours |

**Prim streams** now keep d3dPrimStream's whole header: `+0x18` the batch limit (a multiple of 6 vertices),
`+0x1c` vertices written, `+0x20` what a full batch carries over (0x4d3664: 2 for strips, 1 for line strips) and
the carry area at `+0x24`. That matters because the engine advances with **its own** FUN_0008ef00 (tree code):
at the limit it copies the carried vertices to +0x24, calls slot 1 (draw) and slot 0 with carry. G1's stream left
the limit 0, so a long batch would have run past the buffer. Slot 30 now does what 0x31bd30 does besides: the
shader's program constants (slots 22/24), the skin constants for skinned flags, and the pass (0x327d20).

**Vertex programs.** The six proven shaders of `shaders/vp/` are compiled and embedded with the others
(`native_gfx.py` compiles `shaders/vp/` with its own varying file). A draw's program is the prim buffer's (prim
streams: fixed function); the constant file is `bgfxContext::m_vc` (192 registers, hardware numbering), uploaded as
`u_vc` = c96..c191, which is what the shaders' annotations already said. Where the constants come from:

| program | constants | state |
|---|---|---|
| `skin`, `skin_onebone` | `d3dExtHardwareSkinning` slot 5: bone x the modelview (the base's matrix stack 0), transposed, three rows to c113 + 3i (25 bones, slot 1); slot 6: FUN_00324270 (c96 fixed, c98-c101 the projection's columns, c102 diffuse, c103 specular + power, c104 emissive + ambient light x ambient, with the game's alpha swap; up to four enabled directional lights at c105..c112), the shader marked skinned, every pass | **wired; drawn in the self-test (bones blended 50/50, lit)** |
| `refract`, `skin_refract` | d3dRefractVertexShader slot 24 (0x32f3b0): the refraction shader's own parameters; the stage samples the frame-buffer copy | **wired in G4 (section 12)** |
| `simple_proximity`, `*_multicbv` | d3dSimpleShader/d3dLayeredShader slot 24 | CBVP/MCBV are 0 in all data (docs/shaders.md): fixed function |
| fixed function | `vs_vp_ff.sc`: D3D8 T&L from the backend's D3D-side state, through the same uniform (layout in the shader: modelview and projection columns, the material, the ambient light, four lights) | **done**: directional and point lights (a spot is lit as a point, no cone), local-viewer Blinn specular, vertex colour as the diffuse/ambient material, fog depth |

Depth: Direct3D's [0, w] clip depth is remapped on the CPU (the projection's z column: 2z - w) where bgfx reports
`homogeneousDepth` (OpenGL), so the proven shaders stay untouched. **bgfx pairs a vertex and a fragment shader
only when the fragment shader's inputs are exactly the vertex shader's outputs** (`createProgram` compares the two
interface hashes and returns an invalid handle otherwise, silently in a release build), so the stage fragment
shader exists once per output set of the vertex programs: seven outputs (ff, skin, skin_onebone), five (refract,
skin_refract), three (simple_proximity).

**The D3D-side state** (`bgfxContext`): every override calls the base's setter first, as the game's do, so the
portable blocks the draw log compares stay identical, then keeps the D3D meaning:

| slots | state | bgfx |
|---|---|---|
| 54 | cull: 0 none, 1 counter-clockwise (D3D's default), 2 clockwise (0x4d3a48) | `BGFX_STATE_CULL_*` |
| 56 | colour write mask r, g, b, a | `BGFX_STATE_WRITE_R/G/B/A` |
| 58, 60, 62 | z enable, compare (pddi compare: 0 never 1 always 2 less 3 lequal 4 greater 5 gequal 6 equal 7 notequal; 0x4d3a6c), z write | depth test / `WRITE_Z` (z disabled: neither) |
| 64-74 | stencil enable, compare, reference, read mask, write mask, ops fail / z fail / pass (0 keep 1 zero 2 replace 3 incr (wrap) 4 decr (wrap) 5 invert; 0x4d3a54) | the stencil word; **bgfx has no stencil write mask** (anything but 0xff is logged) |
| 76 | fill 0 solid 1 wireframe 2 points (0x4d3a8c) | solid only (logged) |
| 78, 80 | fog enable; colour, start, end (the game sets linear table fog: 0x39de84 = 3) | the stage shader: k = (end - d) / (end - start) on the vertex output's fog depth |
| 35 | the ambient light | the programs' constants |
| 96 | the viewport's depth range | not per view in bgfx (logged unless 0..1) |
| 108 | stack n top -> D3DTS_WORLD (n = 0: the modelview; D3D's VIEW stays the identity), TEXTURE0..2 (0x4d3a34) | the programs' constants |
| 109 | the projection and viewport from the base's view block: mode 0 perspective, 1 orthographic, 2 pixels | `m_proj`, the viewport |
| 110 | light n changed (+ the modelview it is placed with); FUN_00321310 moves the marked lights to camera space from the base's light set (+0x50, 8 x 0x7c bytes) at the next draw | the lights |
| 84, 90, 91 | 0x800; the extensions it supports; nothing (as the game) | |
| 4, 12 | begin frame (+ the base's 0x31d470); clear | views (below) |

Blend (BLMD), alpha test (ATST/ACMP/ACTH) and the material stay the shader's, read at the draw. **Views:** each
frame's draws go to bgfx view 0 in sequential mode; a clear or a viewport change after draws opens the next view
(bgfx clears a view at its start and has one rectangle per view), so mid-frame clears and viewports work.

**Self-test** (`selftest_scene.cpp`, the same scene for the host smoke test and `HULK_GFX_SELFTEST`): a 4 x 3 grid,
each cell one test, 19 probes checked on the screenshot: a fixed-function triangle; the texture through device slot
9 (TEX through the base's slot 5 in the game image); z LEQUAL and z ALWAYS; alpha and additive blend; stencil (write
1 with colour writes off, draw where 1); cull; a 12-vertex strip through a 6-vertex batch (the FUN_0008ef00 carry,
two seams probed; the seam probe fails with the carry disabled); a lit indexed prim buffer (packed normal, one
directional light, fixed function); a **skinned prim buffer through `d3dExtHardwareSkinning` slots 5/6: the `skin`
program with three bones blended 50/50 + 50/50 + 0 moving the quad half a screen into its cell, lit by the skin
program's light** (the probe where the unskinned quad would be shows the cell underneath); linear fog; the colour
write mask. **Metal (host): 19 of 19. Vulkan under Whisky's Wine, in the game image (native7 tree + G3, linked
--gfx, strict 0 errors): 19 of 19** (`build/g3/selftest-vulkan-shot10.tga`; one screenshot per run, the winevulkan
assertion still applies). After the self-test the game image stops where its tree does (the native7 snapshot:
physics init, `CollisionVolume`; the same without the self-test), so there are still no game frames to diff.

**Draw-log frame numbering.** The hybrid build numbers frames by GameClock updates; the native backend now does too
once the image calls `hulk_pddi_clock_tick()` (requested from native9: `build/g3/for-native9.md`), and says which
numbering a log has (`PDL2`: magic, count, flags bit 0 = game-clock frames; PDL1 still reads). For present-count
logs `drawlog_diff.py --align auto` finds the offset that gives the most frames the same draw signature (primitive,
count, shader kind per draw) and reports how many frames it explains; `--offset N` sets it. Checked on the hybrid
boot log against a copy of itself shifted by 37 frames as a native PDL2: offset +37 found, 29 of 29 frames,
IDENTICAL. Log the native side every frame over the range (`HULK_GFX_DRAWLOG=first:1:last`) so the offset can land
on the hybrid's every-10th frames.

**Stubbed or open after G3:** the shader classes' texture-stage combiners beyond stage 0 modulate (+ specular, alpha
test, fog), i.e. layered/lightmap/reflection stages and the fade modes (G2's state key); `refract`/`skin_refract`
constants and the frame-buffer texture (G4); `simple_proximity`/`*_multicbv` constants (unused by the data); spot
cones; texture matrices (stacks 1-3 are kept, not applied); stencil write masks, wireframe, depth range (bgfx);
render targets and the clear-by-quad path (G4); the frame timer slots 106/107; the extensions other than skinning;
D3D bytecode (unchanged: Windows or a newer Wine); a proof of `vs_vp_ff.sc` in the shader_equiv style (the plan in
docs/shaders.md: the fixed-function equations as a `.vp` of ours; branches on light type make that a set of
variants).

## 10. G2: the shader classes' combiners, 2D, textures and movies (2026-10-19)

```sh
PY=build/venv/bin/python
$PY tools/native_gfx.py pddi && $PY tools/native_gfx.py smoke   # Metal: 5 self-test pages, 464 probes
$PY tools/native_gfx.py combiners    # regenerate shaders/vp/combiners.txt from the shader classes (then pddi again)
HULK_GFX_SELFTEST=30 HULK_GFX_SELFTEST_PAGE=N HULK_GFX_SHOT=10 HULK_GFX_SHOT_DIR='Z:/abs/dir' $PY tools/native_run.py
```

Specification: the verified sources of each shader class's slots 12-14 (`d3dSimpleShader::vfunc_14` 0x32aa70,
`d3dLayeredShader::vfunc_14` 0x32dc40, `d3dBuildingShader` 0x332310/0x332620/0x3326d0, `d3dReflShader`
0x32c520/0x32c300/0x32c3b0, `d3dRefractVertexShader` 0x32efa0/0x32f280, `d3dErrorShader` 0x32b120, `d3dShader`
0x333420/0x3334a0), of the state-cache helpers they call (0x329bb0-0x32a320, 0x32b530, 0x32a920, 0x32a0c0,
0x32a190, 0x32a260), of `d3dShader`'s setters and constructor (0x3333a0.., 0x333770.., 0x333520) and its fade
(0x3335e0); the game's tables they index, read from the XBE by address (only the values are used: blend modes
0x4d4e50, blend factors 0x4d4ed0, compares 0x4d4f04, UVMD 0x4d4efc, FIMD 0x4d4e10, SHMD 0x4d4f24); public
Direct3D 8 documentation for what the texture-stage operations compute. New files: `bgfx_combiner.cpp`,
`shaders/vp/fs_vp_stage.sh` (the combiner) and `shaders/vp/combiners.txt`.

**What the shaders write, and where it goes.** On the Xbox each class's pass set-up writes D3D's texture-stage
registers (`D3D__TextureState[stage][n]` at 0x39db10, 32 words a stage: n = 0-2 addressing, 3-5 filtering, 12-15
colour op and arguments, 16-19 alpha op and arguments, 20 the result register, 21 the texture transform flags;
read off the helpers' stores), the texture factor, alpha blending and test, the shade mode and the lighting
material. Our classes are ports of those slots writing the same values (Xbox D3D numbering) into
`bgfxContext::m_d3d` through the same helpers; the draw turns that into a fragment program, sampler flags, bgfx
blend state and uniforms. Activation (slots 12/13, called by the pass loop when the shader changes) is ported
too: the reflective kinds push the sphere map (scale 0.5, offset 0.5) on texture matrix stack 2 or 3 through the
context's slots 15/14 and pop it on deactivation; the base `d3dShader` turns fog to black while an additive shader
is active and puts the colour back after; refract swaps its mode and alpha test for its pass.

| class (pddi name) | stages (Xbox D3DTOP: 2 selectarg1, 3 selectarg2, 4 modulate, 12 blenddiffusealpha, 14 blendtexturealpha, 15 blendfactoralpha, 18 modulatealpha_addcolor, 20 modulateinvalpha_addcolor) |
|---|---|
| `simple` / `lightweight` | TEX x diffuse (colour and alpha) when there is a TEX; the fade stage; the rest off. No TEX, no fade: the diffuse colour |
| `layered` CLYR 0 (all data) | TEX; TTEX (uv set 1) over it by TBLM (0x32da40: 0 selectarg1, 1 blendtexturealpha keeping the current alpha, 2 add, 3 subtract, 5 modulate2x, 6 modulatealpha_addcolor, else modulate); x diffuse; fade |
| `layered` CLYR 1 / other | diffuse x TEX, the layer / TTEX, TEX blended by the diffuse alpha, x diffuse (colour only) |
| `layered` TBLM 7 | the layer stage subtracts, its alpha is TTEX's, blending src x src alpha + 0 (and the shader's own blend and alpha test are skipped, as the game's early return) |
| `layeredReflect` | TEX x diffuse (TEX's alpha); TTEX added where that is not opaque (20; LRSA leaves it out); REFL through the camera-space reflection vector and the sphere map in D3DTS_TEXTURE2, clamped, added the same way; fade (alpha modes: the factor's alpha) |
| `environment` | TEX x diffuse into temp; REFL (reflection vector, sphere map in D3DTS_TEXTURE1, clamped) x the factor (ENVB, alpha faded); temp + temp alpha x that (18), the factor's alpha |
| `refract` | the frame-buffer copy x the factor (REFC, REFB) into temp (the copy: G4, section 12); TEX (x diffuse when lit); temp over it by the factor's alpha (15), the diffuse alpha; alpha blend, no alpha test |
| `error` | no textures, stage 0 off (the diffuse colour); blend and alpha test stay as they were |
| `fbeffectsshader` | nothing (its slots 12-14 are empty; a draw with it only adds its settings to the colour correction: G4, section 12) |

The fade (`FADE`, 0..1 -> 0..255 faded out; set at run time by game code, in no `.p3d`): FUN_003335e0 makes the
mode the blend uses (alpha when BLMD is none and the shader fades), scales the alpha test reference by what is
left, and for lit shaders fades the material (alpha modes: the diffuse alpha; add/subtract: every colour to black;
modulate: the emissive to white); unlit shaders get a fade stage instead (alpha modes: alpha x factor (255 - fade);
add/subtract: colour x (255 - fade); modulate: colour x fade). FUN_0032a260 then sets blending from the mode
through 0x4d4e50 and the alpha test (ATST, ACMP, the faded ACTH x 255).

**Blend modes fixed.** G1's blend table guessed four of the eight pddi blend modes wrong. From 0x4d4e50 (enable,
operation, source, destination): 0 off; 1 src alpha, inv src alpha; **2 one, one** (G1: src alpha, one); **3 one,
one, reverse subtract** (G1: src alpha); 4 dst colour, zero; 5 dst colour, src colour; **6 dst colour, src alpha**
(G1: one, src alpha); **7 src alpha, src alpha, reverse subtract** (G1: zero, inv src alpha). The data uses 0, 1
and 2 (census below).

**Defaults fixed.** The `d3dShader` constructor's: DIFF, SPEC, EMIS opaque black, AMBI white, ACMP 5 (gequal), ACTH
0.5, UVMD 1 (clamp), FIMD 1 (linear), SHMD 1 (gouraud), SHIN 0 (G1 had a white diffuse, a black ambient, wrap).

**The combiner key and its programs.** The draw writes the active stages (up to the first disabled colour op) as a
canonical key, `c<op>.<arg1>.<arg2>a<op>.<arg1>.<arg2>r<result>` per stage, arguments an op doesn't read as 0
(`-`: no stage). One fragment program per key: `tools/native_gfx.py combiners` runs every class's slots 12/14/13
in the host build over the parameters that change its stages (the textures present, LIT, BLMD, a fade, TBLM, CLYR,
LRSA: `enumerateCombinerKeys`) and lists the keys, **100**, in `shaders/vp/combiners.txt` (tracked); the build
writes `fs_cmb_<FNV-1a of the key>.sc` for each (the stages as constants for `fs_vp_stage.sh`), compiles it for
every profile (multi-threaded, skipped when up to date: ~17 s for the host build from scratch) and embeds it. At
run time the program for (vertex program, key) is cached; a key with no generated program (or a vertex program
with fewer outputs: bgfx pairs a vertex and fragment shader only when the inputs equal the outputs, so the
refract programs' five and simple_proximity's three outputs have their own) is drawn by the **generic combiner**,
the same code with the stages as uniforms (logged once per key). After the stages: the specular colour when
SPECULARENABLE (lit with a power above 0, as FUN_00329f70 sets it), the alpha test on the 8-bit alpha (ALPHAREF
0..255), linear table fog.

**Texture stages.** Four samplers; each stage's addressing (UVMD: wrap/clamp; mirror/border mapped too) and
filtering (FIMD: point/linear, mip none/point/linear) become bgfx sampler flags. The fixed-function program now
generates each stage's coordinates as D3D does: TEXCOORDINDEX picks a uv set or a camera-space vector (normal,
position, reflection vector: the reflective shaders' `0x30000`), and with D3DTTFF a count the coordinates go
through D3DTS_TEXTUREn (a uv set as (u, v, 1, 0), D3D's rule for 2D coordinates; a vector as (x, y, z, 1)), the
matrices the base's stacks 1-3 hand to slot 108. Drawn by a vertex program (skin), stage n reads its oTn.

**Two-sided** (2SID): FUN_00329f70's cache turns D3D's culling off while a two-sided shader draws and gives back
the context's cull mode when one that isn't comes (so the draw's cull is D3D's, `m_d3d.cull`, not slot 54's).
Two-sided *lighting* (back faces lit with the flipped normal) is not done: the fixed-function program has no back
colour outputs (adding them changes every program's interface).

**The draw log** now records the four stage textures (what the hybrid hook records: the state cache's bound
textures), not the shader's TEX/TTEX/REFL.

**2D mode.** `pddiBaseContext` has no separate 2D path: the engine's 2D (text, HUD, front end, movies) selects the
projection with slot 24 (mode into the view block, then slot 109: 0 perspective, 1 orthographic of the aspect,
2 pixel coordinates, y down) and draws prim streams through the simple shader, fonts as textured quads. G3 ported
slot 109's three modes; the host build now keeps the base's view block and matrix stacks itself (slots 14-16, 24
are the base's in the game image), so the self-test drives the same slots in both.

**Textures: linear formats, and no palettes.** pddi formats 11 and 12 (12 is made as 11) are D3D's `LIN_` formats
(0x325fd0's table: LIN_R5G6B5 .. LIN_A8R8G8B8): any size, unswizzled, and the NV2A samples them with **texel
coordinates**. The movie player's tiles are format 11 and draw with texel coordinates (u from 0.5 to width + 0.5),
so the backend scales a stage's coordinates by 1/size when its texture is linear. **P8 is never made**: the format
table's palettised entry (D3DFMT_P8, index 6) belongs to pddi format 1, which `0x326330` folds into format 0
before the lookup, so no texture gets a palette (slots 11/12 act only on one) and the engine's 8-bit images
(`ImageConverter::vfunc_2`, `Image8`) arrive converted into the 32-bit layout the lock describes. All uncompressed
locks are bottom-up, linear ones included (FUN_0031c570 flips every format but DXT), as G1 had it.

**Movies: the render strategy.** `movie::RenderStrategyBink` (the game's, unchanged) makes linear 32-bit pddi
textures of at most 1024 x 1024 per tile (vfunc_6), hands each tile's lock to the player (vfunc_4: bits, stride),
and draws the tiles with the pixel projection, the simple shader (BLMD 0, UVMD 1, FIMD 0 at 1:1 else 1) and texel
coordinates (vfunc_7). So the backend needs nothing movie-specific beyond linear textures: the decoder (Bink's
replacement, a separate FFmpeg/transcode task) writes each frame's rows, top row first, at the lock's bits, bits +
stride, ... (the stride is negative: the engine's bottom-up layout; PlayerBink 0x333de0 does the same with Bink's
copy). `bgfxTexture::writeFrame` is that seam for our own callers; the self-test draws a tile exactly as vfunc_7
does and checks it is upright.

**What the data uses** (all 8,787 Shader chunks of the `.p3d` files, `$S/g2/census.py`): simple BLMD 0/1/2, LIT 0/1,
ATST 0/1 with ACMP 4 (greater) or 3/0, UVMD 0/1, FIMD 0/1/4, 2SID 0/1; layered always CLYR 0, TBLM 1 (1,381) or 0
(2); layeredReflect TEX + TTEX + REFL (LRSA 0 in 45); environment TEX + REFL with BLMD 0/2; refract (41) and
fbeffects (6) in `art`; no FADE (run time only). The boot replay's draw log (`build/g1/drawlog-boot-hybrid.jsonl`)
has simple (6,871 draws), layered (935) and layeredReflect (264) draws.

**Self-test** (`selftest_scene.cpp`, pages; `HULK_GFX_SELFTEST_PAGE` in the game image, one screenshot per run):

| page | what | probes | Metal (host) | Vulkan (Wine, game image) |
|---|---|---|---|---|
| 0 | G3's draw path (unchanged scene; lit shaders now set DIFF/AMBI as data does) | 19 | 19 | 19 |
| 1 | combiners: simple TEX, FADE alpha, FADE add, LIT FADE (faded material); layered TBLM 1/2/3, CLYR 2, TBLM 7; layeredReflect; environment; alpha test | 13 | 13 | 13 |
| 2 | page 1 through the generic combiner | 13 | 13 | 13 |
| 3 | 2D (mode 2), orthographic (mode 1), a linear texture with texel coordinates, a movie tile as RenderStrategyBink draws it, UVMD wrap/clamp, FIMD point/linear, 2SID, additive + fog (to black and back), the environment reflection through texgen + the sphere matrix, FADE scaling the alpha reference | 19 | 19 | 19 |
| 4 | the sweep: all 100 keys of combiners.txt, generated and generic, colour and alpha, against a CPU reference of the stage operations (written separately from the shader) | 400 | 400 | 400 |

Vulkan: the native7 tree + G2 linked `--gfx` (strict, 0 errors), one page per run (`build/g2/selftest-vulkan-page*`:
screenshots and probe lines; Metal's: `build/g2/metal-*.png`), every key drawn by its generated program (no
"no generated program" line). A deliberate error in one operation (modulateinvalpha_addcolor) fails 24 of the
sweep's probes. Shader proofs: `tests/shaders` 42/42; `native_gfx.py slots` ok.

**Open after G2:** two-sided lighting; flat shading (SHMD 0, logged; no data uses it); the frame-buffer copy
refract samples (G4); projected texture coordinates (D3DTTFF_PROJECTED; unused); the bump-mapping operations
(unused by the data's classes); a proof of `vs_vp_ff.sc` in the shader_equiv style (it would need the
fixed-function equations as `.vp` programs of ours, one per light-type and texgen mix: not done); the front end's
real draws and their draw-log diff, which wait for the native build to reach the game's first frame.

## 11. sdlwin: the window and the event pump on SDL3 (2026-10-19)

```sh
PY=build/venv/bin/python
$PY tools/native_gfx.py pddi && $PY tools/native_gfx.py smoke          # host (Metal): the window is SDL3's; 464 probes
$PY tools/native_gfx.py window-test [--target win32]                   # window + event pump + sa1's pad backend (host / Wine)
$PY tools/native_sdl.py build --target win32                           # SDL3.dll (one local patch, below)
$PY tools/native_link.py --reuse-map --gfx && HULK_GFX_SELFTEST=30 HULK_GFX_SELFTEST_PAGE=N ... $PY tools/native_run.py
```

The Win32 window class, `WM_CLOSE` handler and `PeekMessage` loop of `win32_platform.cpp` are gone (the file is retired,
not kept as a fallback: nothing needs it); `pddi/sdl_platform.cpp` has the same run-time options and per-frame hooks and
no Win32 window code. `HULK_GFX_RENDERER`, `HULK_GFX_SIZE`, `HULK_GFX_SHOT*`, `HULK_GFX_DRAWLOG*`, `HULK_GFX_FRAMES`,
`HULK_GFX_HIDDEN`, `HULK_GFX_SELFTEST*` behave as before; new: `HULK_GFX_FULLSCREEN=1` starts in desktop-size
fullscreen.

| piece | what |
|---|---|
| `src/platform/sdl/platform_events.{h,cpp}` | the program's **one** SDL event pump, a small C API without SDL types: `hulk_platform_video_init` (reference counted), `create_window`, `native_handles` (HWND on Windows, `NSWindow` on macOS, X11 display + window number or Wayland display + surface elsewhere, as bgfx's `swapChain.nwh/ndt` and `platformData.type` want them), `pump`, `quit_requested`, `has_focus`, `toggle_fullscreen` (F11 and Alt+Enter do it from the pump), a resize handler, and listeners. Every event goes to the listeners first, then the hub handles close/quit, focus, the window's pixel-size changes and the fullscreen keys; the rest is dropped. |
| `src/platform/sdl/hulk_sdl_api.h` | the ~15 SDL entry points the window code uses as a table: direct on the host, resolved from `SDL3.dll` with `LoadLibrary`/`GetProcAddress` in the i686 image. A direct `_SDL_CreateWindow` reference from the pddi objects would be renamed by `native_link`'s graphics step (every host import of the graphics objects becomes `hulk_gfx_<name>` bound to msvcrt/kernel32/user32/gdi32) to a name no DLL exports. `SDL3.dll` is one module in the process, so the table and sa1's audio/input backends (direct imports of `SDL3.lib`) share one SDL: one video subsystem, one event queue. |
| `pddi/sdl_platform.cpp` | slot 4 of the display on SDL: video init, a resizable window (`HULK_GFX_SIZE`, hidden with `HULK_GFX_HIDDEN`), the native handle to `bgfxDisplay::hostInit`; `platformPump` is the hub's pump and ends the process when the window is closed (as `WM_CLOSE` did). Called once per present (display slot 14). |
| `bgfxDisplay::hostResize` | the hub reports the window's pixel size changing (resize, fullscreen); the main swap chain is reset to it (`bgfx::reset` with a `SwapChain` carrying only the size) and the display's size slots follow. The probes run at a fixed size and see no resize. |

**Coordination with sa1's gamepad backend.** `hulk_input.cpp` reads pads with `SDL_UpdateGamepads` and
`SDL_GetGamepadAxis` (state, not events) and flushes only the joystick/gamepad event range
(`SDL_EVENT_JOYSTICK_AXIS_MOTION` .. +0xff) itself. The hub never leaves window events for it to find: the window code
polls the queue (and drops what nobody listens to, joystick events included), the pad code never polls it. Rule for new
code: **no `SDL_PollEvent` anywhere else**; register a listener. `window-test` proves it in one process, host and i686
under Wine: a window, `hulk_input_init`, a virtual gamepad plugged in while the window pumps (appears in port 0, buttons
and axes arrive), a pushed close request (hub and listener see it), a joystick event ahead of a focus-lost event (the
focus event still arrives), fullscreen on and off (Wine: 0 -> 1 -> 0 with one resize callback; on the host the request
is accepted but macOS completes it only for a foreground app, which a command-line run is not), and the pad state still
updating after all of it.

**One local fix to SDL (tools/native_sdl.py `PATCHES`).** `WIN_UpdateDarkModeForHWND` runs on every window creation
and calls uxtheme's undocumented ordinals 104/132/133/135 (their Windows 10 meanings). Wine's uxtheme has other
functions there: ordinal 104 is `IsThemePartDefined` (stdcall, 3 arguments) called with none, so `SDL_CreateWindow`
returned to garbage (eip 0x0000000a) under Wine. It now returns early when SDL's own `WIN_IsWine()` is true; Wine has no
dark mode to switch on. Real Windows is untouched.

**Results (2026-10-19).**

- Host, Metal, `tools/native_gfx.py smoke`: 5 pages, **464 of 464 probes**, through the hub's window and pump.
- i686 game image under Wine (Whisky 7.7) + Vulkan (MoltenVK), SDL3 window, `HULK_GFX_SELFTEST=30`, one page per run:
  page 0 19/19, page 1 13/13, page 2 13/13, page 3 19/19, page 4 400/400 = **464 of 464**. Direct3D 11 on the SDL
  window presents (clear colour correct) and draws nothing, as before (no DXBC under Wine 7.7).
- sa1: `native_sdl.py test` host native_audio 34, native_input 73; `wine-test` i686 native_audio 58, native_input 75, all
  passing; `window-test`: 13 checks on the host and under Wine.
- After the self-test the game runs on and stops later in physics code (`Node::run` 0x306510), the native build's own
  state, not the window's.

**Open.** Resizing and fullscreen change the back buffer, but the game's viewports and 2D layouts are in the pixel
sizes it asked for at start-up; scaling the 4:3/16:9 game frame into a larger window (a blit with letterboxing) is a
display-layer feature for later, as is a mode list/option screen. Linux (X11/Wayland) handles are written and
compile-checked but not run. The pump runs once per present: a long load without presents leaves the window
unserviced (Wine marks it not responding after several seconds); if loads show that, call `platformPump` from the
loading loop's yield.

## 12. G4 effects: the frame-buffer copy, refraction and the extensions (2026-10-19)

```sh
PY=build/venv/bin/python
$PY tools/native_gfx.py fetch && $PY tools/native_gfx.py build --target win32   # bgfx with the two new PATCHES
$PY tools/native_gfx.py pddi && $PY tools/native_gfx.py smoke     # Metal: 9 self-test pages, 502 probes
HULK_GFX_SELFTEST=30 HULK_GFX_SELFTEST_PAGE=N HULK_GFX_SHOT=10 HULK_GFX_SHOT_DIR='Z:/abs/dir' $PY tools/native_run.py
HULK_GFX_DIRECT=1 ...   # no scene target: draws straight to the back buffer (G3's path; no copies, no effects)
```

Specification: the verified sources of `d3dRefractVertexShader` (0x32efa0 the pass, 0x32f3b0 the constants,
0x32f2e0 the constructor, 0x32f240/0x32f250), the display (0x31ae70 its copy texture, 0x31b1e0 the copy, slots
0x31ad30/0x31ad40), the context's slot 32 (0x3218c0) and the skinning extension's slot 6 (0x3245d0), the
`d3dExtFramebufferEffects` object and its helpers (0x3224b0, 0x3225c0..0x3226b0, 0x3226d0, 0x322990, 0x320330,
0x320540, 0x320aa0, 0x322cd0, 0x323130, 0x323910, 0x3239e0, 0x324660, 0x324a00, 0x325110), `d3dFBEffectsShader`
(0x328720, setters 0x328560..0x3285c0, 0x3285d0) and FUN_003287a0, the visibility and antialias extensions
(0x3222c0..0x3222f0, 0x322000..0x322030), `d3dExtVertexProgram` (0x322360..0x322440); the game's callers
(CRenderManager FUN_001b93a0 / FUN_001b98e0 / FUN_001b8780, the HUD's FUN_001c16e0 / FUN_001c22f0,
BillboardQuadGroup FUN_002ba220, the prim group loaders FUN_002e1960 / FUN_002e22c0 / FUN_002e30f0 / FUN_002e3bd0 and
PrimGroupStreamed::vfunc_6) found by an xref of the extension ids in the XBE; data read by address (the contrast
table 0x432a10, the level thresholds, the threshold program's text 0x432da0, the fbeffects key tables): values only.
New: `bgfx_effects.cpp`, `shaders/fx/` (`vs_fx`, `fs_fx_filter`, `fs_fx_blur`, own varyings),
`shaders/vs_pddi_present.sc` + `fs_pddi_present.sc`; self-test pages 5-8.

**The scene target and the present pass.** bgfx can neither read nor blit the back buffer, and the game reads its
render target (the refraction's copy, every framebuffer effect, the overlay's front buffer). So the frame is drawn
into a frame buffer of ours, BGRA8 + depth/stencil (D24S8, or D32FS8 where the renderer can't render to D24S8:
MoltenVK, Apple GPUs), and display slot 14 draws it onto the back buffer in the last view (255) before
`bgfx::frame`; screenshots still read the back buffer. Every context view targets it. Without a present program
(no shader build for the renderer: D3D11 under Wine 7.7) or with `HULK_GFX_DIRECT=1` the frame goes to the back
buffer as before and there are no copies (the refraction stage samples white, the effects skip). The OpenGL origin
(bottom left) is handled by the present and fx quads; the refraction stage's sampling of the copy is not flipped
there yet (G5, with WebGL2).

**The frame-buffer copy.** The game's display makes a texture of the back buffer's size and format at init when
DisplayConfig +0x2e asks (the game does: logged as "frame-buffer texture asked for"), and FUN_0031b1e0 copies the
render target into it (CopyRects) each time a refraction pass begins. Ours: `bgfxContext::copyFrameBuffer` puts a
`bgfx::blit` (scene colour -> the copy) at the start of a new view, and bgfx runs a view's blits before its clear
and draws: everything drawn (and cleared) so far is in the copy, what follows samples it. Views: a frame has at
most 250; a copy needs one (two refractions in a row: two views). A view that only clears now keeps the rectangle it
cleared when a viewport change follows (Direct3D clears the viewport of the time; G3 moved the pending clear to
the new rectangle).

**Refraction** (`refract`, `skin_refract`; 41 shader chunks in `art`). The pass (0x32efa0) binds the copy on stage 0
as a linear texture (texel coordinates: the program's oT0 is the screen position x the viewport plus the projected
normal x the scale). Slot 22 now answers true (the game's), so context slot 32 and the skinning extension's slot 6
call slot 24 before the passes, as the game does; slot 24 (0x32f3b0) is ported: `bgfxContext::refractConstants` for
the unskinned constants, c188-c191 for skinned (the table in docs/shaders.md). The constructor's defaults are the
game's: REFI 10 (+0x88), REFB 1 (+0x8c), REFC opaque white (+0x90); slot 24 stores the faded intensity back into
REFB as the game does. **How a mesh gets the program:** not from the prim buffer's creation block but from the vertex
program extension (0x106), which G3 left as stubs: the prim group loaders ask slot 4 (the shader's slot 22, with
+0x7d set for a skinned palette), take slot 2's handle (the shader's slot 23 name: `refract` / `skin_refract`) and
give it to the buffer with slot 5 (+0x3c); streamed prim groups keep it and bind it with slot 6 around their prim
stream draws. Our handles are 1 + an index into the names (the game's are D3D vertex shader handles from
FUN_003290e0). Without this the data's refraction meshes would have drawn with the fixed-function program.
**Display slots 6/7 fixed:** 6 is the height (+0x478), 7 the width (+0x47c) (G1 had them swapped; 0x31ae70 gives
+0x47c to BackBufferWidth, and the refraction's scale divides the back buffer's width by slot 7).

**The framebuffer effects extension** (0x103). What the game runs each in-game frame after the scene:

| slots | what | ours |
|---|---|---|
| 3, 4 | colour correction on/off; settings: saturation, brightness, contrast (linear below 0, the table above), its midpoint, a tint | ported (the table copied by value) |
| 5 | FUN_003287a0: the frame's fbeffects shaders averaged into slots 3/4 (none: off); their settings come from a draw of one through context slot 32 (no draw: FUN_003285d0 adds SAT, BRIT, MDPT, CONT, TINT when CLRE) or its UPDT parameter | ported; the data's six fbeffects shaders (`global_nonchar.p3d`) are all neutral (contrast 0: the pass is the identity but for 8-bit rounding) |
| 6 | the colour pass (FUN_00324660): the frame copied, then the level's program over it with luminance weights (0.25, 0.625, 0.125) | ported |
| 7, 8 | bloom on/off; settings: amount, the quarter copy's tint, blend, the gaussian's width (taps exp(-i^2/s^2), at most 20, the run cut at 1/255), the bright pass's colour weights, brightness, contrast, midpoint | ported |
| 9 | the bloom: copy; bright pass into a half-size target; tinted copy into a quarter target; the separable gaussian (1-4 taps a draw, additive, both sides, both directions); the composite 2 x blur x amount + frame x blend | ported |
| 1, 2 | the HUD's motion trail: the front buffer (the last presented frame, kept by a blit at the present while asked for) over the frame through the context's own 2D path and a "simple" shader: alpha-blended, or additive and zoomed (split: three passes, one channel each, scales 4 apart) | ported |
| 10 | nothing | as the game |

The passes are views of the context (`fxView`: a view drawing into the scene target or one of the extension's
targets, `fxCopy`: the copy, `fxDone`: back to the scene) drawing pre-transformed quads (the game's
`DrawVerticesUP` with XYZRHW + TEX1..4, its -0.5 pixel-centre offsets becoming pixel edges) with `shaders/fx/`:
`fs_fx_filter` is FUN_00320540's 14 colour-pass programs as one (each level's co-issued `mov_x2/x4` and add chain
as uniforms) plus the threshold program, `fs_fx_blur` the five FUN_00320330 sums and the composite. Arithmetic as
the register combiners do it: each instruction clamped to [-1, 1], the output to [0, 1], constants quantised to 8
bits in [0, 1] on the CPU (the combiner constants are packed colours). Brightness is at most 100/255, so the
programs' second side (brightness >= 0.5) is never chosen by the game.

**Visibility tests** (0x500002; BillboardQuadGroup: a flare quad drawn with colour writes off, the passed samples
over its area). Begin/end make the draws between them a bgfx occlusion query; the result is the query's latest
answer: bgfx answers a frame or two late, so each test of a frame has its own query (the k-th test the k-th query)
and gets last frame's count for the same flare. **Antialias** (0x500001): slot 4 answers the multisample type, 0
(the scene target is not multisampled); slot 2 (the context's clear-by-quad flag) has no caller in the game: kept
and logged. Slot 3 jumps into the XDK and has no caller.

**Two bgfx fixes for Wine's 32-bit Vulkan** (`tools/native_gfx.py` PATCHES, defines in the win32 build only):
`HULK_VK_MAP_WRAP`: Wine 7.7's 32-bit winevulkan writes a 64-bit pointer through vkMapMemory's ppData, zeroing the
word after a 4-byte pointer member; in OcclusionQueryVK that word is its ring's size, so the first occlusion query
divided by zero (TimerQueryVK has the same layout: the earlier timer-query patch avoided the same fault). bgfx's
vkMapMemory now goes through a wrapper that maps into an 8-byte slot. `HULK_VK_PRECISE_OCCLUSION`: the precise
occlusion feature and `VK_QUERY_CONTROL_PRECISE_BIT` where the device has it (MoltenVK answered 1 for 8,192
passed pixels without it).

**Layout rule found the hard way:** `bgfxContext`'s data members must all come after `m_base` (the portable base's
+8..+0x14c block, written by the game image's base functions); new members declared earlier shifted the block and
the base constructor overwrote them. Static asserts in `bgfx_context.cpp` now check +8 and +0x14c in the i686 build.

**Self-test** (pages 5-8 new; the host smoke test runs every page, the game image one per run):

| page | what | probes | Metal (host) | Vulkan (Wine, game image) |
|---|---|---|---|---|
| 0-4 | G3 / G2 (unchanged; now through the scene target and the present pass) | 464 | 464 | 464 |
| 5 | refraction over a known pattern: a 20-pixel offset from the normal and REFI, REFC's tint, two refractions in a row (the second's copy holds the first's output), skin_refract through the skinning extension, the program's alpha k, the copy after a mid-frame clear, the program given through the vertex program extension's slots 4/2/5 and through slot 6 on a prim stream | 18 | 18 | 14 of the first 14 (the last four not run: see below) |
| 6 | colour correction of eight colours and the clear colour from two fbeffects shaders' average (slot 32 + UPDT, slot 5, slot 6) against a CPU reference written from the xps text; a visibility test (half a quad behind an occluder: 8,192 of 16,384 pixels) | 13 | 13 | 13 |
| 7 | the bloom of five uniform regions (sigma 2: three taps; brightness -20, contrast 30, midpoint 0.6, a tinted quarter copy) against the CPU reference of every pass with 8-bit targets | 5 | 5 | 5 |
| 8 | the overlay, additive and split, converging on colour / (1 - a) | 2 | 2 | 2 |

The Vulkan column is from the game image linked before the vertex program extension was implemented (pages 0-8,
498 probes, all passing); after it, every x86 process on this Mac (Wine and wibo alike, Rosetta-translated) hung in
uninterruptible state from 18:14 on 2026-10-19, so page 5's four extension probes are verified on Metal only.
Without the copy, page 5 fails 11 of its first 14 probes; a missing doubling in one level's add chain fails 8 of
page 6's 13. Screenshots and probe lines: `build/g4/` (`selftest-vulkan-page*.png`, `-probes.txt`). Direct3D 11
under Wine: the present program has no DXBC build, so the frame goes to the back buffer as before (the clear colour;
no draws). `tests/shaders` 42/42 (no vertex program changed); `native_gfx.py slots` ok.

**Not done / open after G4:**

- **Two-sided lighting** (D3DRS_TWOSIDEDLIGHTING: 263 lit two-sided `simple` shader chunks and 11 `refract`): the
  fixed-function program would need back-colour outputs, which changes the interface of every program in the
  seven-output set (the proven `skin`/`skin_onebone` included) and of all 100 generated combiners; and what the
  NV2A does for vertex programs that write no oB0/oB1 under two-sided lighting is unverified. Not cheap: left.
- Unused by the game's code (no caller found by an xref of the ids and of context slot 92): render targets (context
  slot 92 SetRenderTarget, the framebuffer texture extension 0x104), read pixels (0x500005), gamma (0x101: the
  display's ramp 0x31b390 is reached only through it), the global projected texture (0x500004), clear-by-quad
  (+0x44c), the vertex program extension's slots 1/3/7/8, the display's capture (slot 15, still a stub). They stay
  logged stubs.
- ~~The OpenGL/WebGL2 origin for the refraction stage's copy; a quad copy where a renderer can't blit~~: G5,
  section 13 (no OpenGL run yet).
- ~~An `xps.1.1` interpreter proof of `fs_fx_filter`/`fs_fx_blur`~~: G5 (`tools/xps.py`); the NV2A combiners'
  internal precision and `def` rounding are still taken as float.
- The game's own effects frames: the native image still stops in physics init after the self-test (native-build
  work), so no in-game refraction, colour correction or bloom has been drawn yet.
- Game code `dynamic_cast`s the effects extension (HulkShaderCallback FUN_001c1a40 keeps it in DAT_004e2318 for
  the HUD's motion trail). Our extension objects carry no game RTTI, so in the native image that cast needs a
  rebind (or a locator naming the game's types); noted for the native build (build/g4/for-native10.md).

## 13. G5 clean-up: shader proofs, window scaling, portability, two-sided lighting (2026-10-19)

```sh
PY=build/venv/bin/python
$PY tools/xps.py prove                      # the 20 framebuffer-effects pixel programs vs shaders/fx (3000 px each)
$PY tools/d3d_ff.py prove                   # vs_vp_ff.sc vs the Direct3D 8 fixed-function reference (10 configs)
$PY tools/d3d_ff.py prove --src src/platform/sdl/pddi/shaders/vp/vs_vp_ff2s.sc   # + the back colours
$PY tools/d3d_combiner.py prove --all-profiles   # the 100 combiner keys, generated and generic programs
$PY tools/native_gfx.py pddi && $PY tools/native_gfx.py smoke      # Metal: 11 pages, 14 shots, 548 probes
HULK_GFX_QUAD_COPY=1 $PY tools/native_gfx.py smoke                # the same with quad copies instead of blits
HULK_GFX_WINDOW=960x540 HULK_GFX_SCALE=integer ... tools/native_run.py   # the game image in a larger window
```

**Shader proofs** (docs/shaders.md has the details and tolerances). Everything the backend draws with is now proven
against an independent reference on fuzzed inputs through the compiled SPIR-V (`shader_equiv.py`'s machine, which
gained texture sampling: sampler n answers only at its own coordinate set, so a swapped set fails), each with a
deliberately broken fixture that fails:

| what | reference | result | broken fixture |
|---|---|---|---|
| `shaders/fx/` (15 `xps.1.1` programs of FUN_00320540 incl. the threshold text at 0x432da0, 5 `ps.1.1` of FUN_00320330) | `tools/xps.py`: an interpreter of the game's own program text (combiner clamps, co-issue, 8-bit constants); the filter program's uniforms come from the C++ (`pddi_smoke --fx-params`) | 20 equivalent, 3,006 pixels each, max difference 4e-6 (tolerance 2^-16) | `fixtures/fx/`: a dropped clamp fails the 8 programs of levels 1-8 (above them the result saturates either way); a swapped coordinate set fails `blur4` only |
| `vs_vp_ff.sc` (fixed function) | `tools/d3d_ff.py`: Direct3D 8's pipeline with the state the game sets (below) | 10 configurations equivalent, 3,000 vertices each, worst 5% of the tolerance | `fixtures/vs_wrong_ff.sc` (no linear attenuation) fails exactly the 4 point-light configurations |
| the 100 combiner keys | `tools/d3d_combiner.py`: Direct3D 8's texture stages, specular, alpha test, fog | 200 programs equivalent (generated + generic), 600 pixels each, all profiles compile | `fixtures/fs_wrong_vp_stage.sh` (op 20) fails exactly the 12 keys using it, both programs |

**Fixed function: three corrections found by the reference** (from the verified sources, not guesses):
FUN_00320c60, the context's device set-up, writes the deferred render states after LIGHTING (0x39dea8) and
SPECULARENABLE (0x39deac): COLORVERTEX on and every material source **D3DMCS_MATERIAL** (the ordering is confirmed by
AMBIENT = 0x39dedc, the word slot 35 writes, and by the point-sprite shader's POINTSIZE..POINTSIZE_MAX at
0x39dee0..0x39defc). So a lit draw takes its colours from the material and never from the vertex; G3 used the vertex
colour. LOCALVIEWER and NORMALIZENORMALS are never set (Direct3D's defaults: on, off), so normals now go through the
inverse transpose of the modelview (`u_vc[52..54]`, computed in `ffConstants`) and are not renormalised (a flag,
`u_vc[13].w`, if a hybrid capture shows otherwise); directional lights' directions are normalised (FUN_00321310 moves
them by a matrix: not unit). The self-test pages still pass unchanged (their lit quads have unit normals, identity
transforms and white material).

**Window scaling.** The game's frame (the mode: what slots 6/7/11/12 report and the scene target's size) is now
independent of the window: `bgfxDisplay::present` draws it into `presentRect()`, the largest rectangle of the frame's
aspect that fits, centred, with black bars (pillarbox / letterbox). `HULK_GFX_SCALE`: `linear` (default; 1:1 stays
point sampled), `nearest`, `integer` (whole multiples, point sampled; a smaller window falls back to fitting).
`HULK_GFX_WINDOW=WxH` opens the window at another size than `HULK_GFX_SIZE` (the frame). Resizing and fullscreen (F11 /
Alt+Enter from the event hub, no mouse needed) reset only the swap chain; without a scene target (`HULK_GFX_DIRECT`,
no present program) the back buffer is the frame and follows the window as before. Self-test page 9: four quadrants;
probes at each quadrant mapped through the present rectangle, the frame's first/last row and column in the window,
and the bars just outside (black); the smoke test runs it at 640x480 and in 960x540 (linear, pillarbox), 900x600
(integer, bars on four sides) and 800x800 (nearest, letterbox) windows.

**Portability prep.** *Copies without blits:* `bgfxContext::sceneCopy` is the one place render-target copies happen
(the refraction's frame-buffer copy, the effects' full copy, the overlay's front buffer at the present); where the
renderer can't blit it draws a full-screen quad into the destination's frame buffer in a view of its own and the
scene goes on in the next view. On by default for OpenGL (bgfx's desktop GL renderer blits only through
glCopyImageSubData, GL 4.3; its GLES/WebGL2 path blits through framebuffer blits), `HULK_GFX_QUAD_COPY=1/0` forces it.
Checked on Metal: the smoke test with quad copies forced passes all 548 probes (pages 5-8 depend on the copies), and
page 5 under Wine/Vulkan likewise. *GL origin:* a copy of a render target (`bgfxTexture::m_fromTarget`: the frame-buffer
copy, the overlay's front buffer) is stored bottom-up where targets have the origin at the bottom left; the stage's
coordinates now take an offset after the scale (`u_pddiFrag[14..15]`), so the draw samples it with v -> 1 - v there
(the present and fx quads already flipped). Checked at unit level only: the pinned bgfx has no macOS OpenGL context
(no `glcontext_nsgl`; the host build is Metal-only), so there is no OpenGL run on this host; `d3d_combiner.py`'s fuzzed
offsets/negative scales prove the shaders apply it.

**Two-sided lighting.** A separate program, used only while a lit two-sided shader draws on the fixed-function path
(FUN_00329f70: TWOSIDEDLIGHTING with LIGHTING; 263 lit two-sided `simple` chunks): `vs_vp_ff2s.sc` (the same
`vs_vp_ff.sh` with FF_TWO_SIDED: also the back face's colours, the lights on the reversed normal with the back
material, which FUN_00329f70 sets to the front one) and `fs_vp_stage2s.sc` (the generic combiner picking the colours
by `gl_FrontFacing`). `vs_vp_ff.sc`, the six proven programs and the 100 generated combiners are unchanged; the
variant is proven with its back colours by `d3d_ff.py`. Self-test page 10: front and back faces with the normal toward
and away from the light (two-sided), and the same back faces through a one-sided lit shader. Not done: `refract` /
`skin_refract` with two-sided lighting (11 `refract` chunks): what the NV2A does for a vertex program that writes no
oB0/oB1 is unverified, so they keep the front colours.

**Texture uploads deferred** (the native image's stop 27, `build/g5/for-native10.md`): an unlock queues the texture;
its data goes to bgfx when a draw binds it or at the next present, so a game that unlocks more often than it presents
(the boot movies while it loads) keeps one copy per level instead of one per unlock.

**Results.** Host Metal: 11 pages, 14 shots, **548 of 548** (also with quad copies forced). Wine + Vulkan, the game
image (wsg1, linked `--gfx`, strict 0 errors): pages 0-10 one per run, **512 of 512** (19 + 13 + 13 + 19 + 400 + 18 + 13 + 5 + 2 + 4 + 6), page 9 in a 960x540 window 11/11 and in a 900x600 window with `HULK_GFX_SCALE=integer` 14/14, page 5 with quad copies forced 18/18 (`build/g5/wine-vulkan-results.txt`, screenshots `build/g5/selftest-vulkan-*`). `tests/shaders` 65 tests OK; `native_gfx.py slots` ok.

**Open after G5:** an OpenGL/WebGL2 run (needs a bgfx with a GL context on some host, or the web build); the NV2A's
combiner precision and `def` constant rounding (the fx proofs take float and exact constants); NORMALIZENORMALS'
real default on the Xbox (a hybrid capture of a scaled lit mesh would settle it); two-sided lighting for vertex
programs; spot-light cones (no data light is a spot).

## Open questions

- Confirm on the hybrid build that the eight shader classes the data never names are never constructed (log the
  factory table's calls through a full replay).
- ~~Which code reaches `FUN_003202b0`~~: only FUN_00320330, the framebuffer effects' five blur/composite programs
  (section 12).
- The exact meaning of `d3dContext` slots 30/31 (59 sites each), 89 and 91 (one-byte override, 16 sites); read
  `pddiBaseContext`'s callers before G1.
- Does `d3dExtReadPixels` need a synchronous result (bgfx reads back a frame or two later)? (G4: no game code asks
  for the extension, 0x500005; the display's capture, slot 15, is still a stub.)
- Is the DXT mip-0 data the backend receives byte-identical to the payload's mip 0 (key option A)?
- bgfx on the 32-bit Windows target: bgfx supports Windows x86, but the first native image is built with clang-cl +
  lld-link; build bgfx with the same toolchain (GENie can emit a vs2022 or ninja project) rather than mixing CRTs.
- Web: bgfx's WebGL2 path and `bgfx::blit` availability there; fall back to quad copies.
