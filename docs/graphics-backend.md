# Graphics backend: design and plan

Planning document, written 2026-10-18. Stage G0 (the harness) is built: see [section 7](#7-g0-the-harness-built-2026-10-18).
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
| G1 First triangle | `bgfxDisplay` (init, reset, swap, sizes, aspect), `bgfxDevice` (factories), `bgfxContext` clear + transforms + fixed-function vertex shader + one texture stage, `bgfxPrimStream` immediate draws, `bgfxTexture` for DXT1/3/5 and RGBA, `error` shader | 1 to 2 weeks | display/device vs texture vs prim stream |
| G2 Menus and front end | the `simple` shader with its 1-3 stage combiners, texture-stage state key + shader cache, blend/z/cull/alpha test, 2D mode (`pddiBaseContext`), PNG/P8 textures, fonts, the copyright and title screens, movies' render strategy (frames as textures). Compare draw logs and screenshots for title → main menu → options | 2 to 3 weeks | combiner ops, state mapping, P8/palette, screenshot tooling |
| G3 A level | `bgfxPrimBuffer` static meshes, vertex declarations from the flags word, `skin`/`skin_onebone`/`simple_*` programs (NV2A interpreter first), hardware-skinning extension, `layered` (+ lightmap pair) and `layeredReflect`, fog, stencil (shadows/decals), `environment`, lights from `pddiLightingState`. Target: the junkyard tutorial replay with matching draw logs | 3 to 5 weeks | one batch per shader class; one per vertex program (interpreter-checked); state/fog/stencil |
| G4 Effects | `d3dExtFramebufferEffects` (114 functions: glow levels, blur, colour passes, the 17 `xps` shaders), render targets, `CopyRects`, `refract` (+`skin_refract`), visibility tests, gamma, read pixels, antialias | 2 to 3 weeks | the 17 `xps` translations as one batch; targets/copies; queries/gamma |
| G5 Web and polish | WebGL2 via the same backend (Emscripten bgfx build, `BGFX_CONFIG_MULTITHREADED=0`, blit fallback), HD textures + dump mode, resolution independence (640/480 literal), MSAA/anisotropy options; the unused shader classes only if a factory log shows them | 1 to 3 weeks | HD textures independent of everything after G1 |

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

## Open questions

- Confirm on the hybrid build that the eight shader classes the data never names are never constructed (log the
  factory table's calls through a full replay).
- Which code reaches `FUN_003202b0` (the pixel shader assembled from a caller-supplied string), and with what text.
- The exact meaning of `d3dContext` slots 30/31 (59 sites each), 89 and 91 (one-byte override, 16 sites); read
  `pddiBaseContext`'s callers before G1.
- Does `d3dExtReadPixels` need a synchronous result (bgfx reads back a frame or two later)?
- Is the DXT mip-0 data the backend receives byte-identical to the payload's mip 0 (key option A)?
- bgfx on the 32-bit Windows target: bgfx supports Windows x86, but the first native image is built with clang-cl +
  lld-link; build bgfx with the same toolchain (GENie can emit a vs2022 or ninja project) rather than mixing CRTs.
- Web: bgfx's WebGL2 path and `bgfx::blit` availability there; fall back to quad copies.
