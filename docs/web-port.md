# Web port: what it would take to run Thunderclap in a browser

Research and planning only, written 2026-10-17. Nothing here is built. Measurements come from a probe run on the
2026-10-17 clang-probe snapshot (`build/clang-probe/snap/`, 2,557 TUs) with the installed Emscripten (emcc 6.0.2-git,
clang 23.0.0git); the probe script and its JSON are in `build/web-research/`. Facts about OpenCE and the web platform
carry URLs; claims I could not confirm are marked **unverified**.

## Headline

**Feasible, and cheaper than it looks once the native ports exist, because a web build is "just" a fourth platform
layer plus a wasm32 toolchain.** Our tree is already 32-bit-pointer code behind four seams, which is exactly the shape
that works on wasm32. The blockers are not web-specific:

1. **The MS C++ ABI.** The verified code stores vptrs by hand, calls vftable slots by number and assumes `__thiscall`
   and MS mangling. wasm32 is Itanium-ABI (and has no `__thiscall`). A web build therefore **depends on fixes 5b
   (canonical prototypes) and 6b (constructors / non-trivial destructors in `include/gen`)**, the same work the Linux,
   macOS and 64-bit builds need. Fix 5b is also needed for a second, wasm-only reason: WebAssembly traps on calls whose
   signature differs. This is the long pole and it is shared, not web-specific.
2. **Graphics.** Our planned backend (SDL_gpu or bgfx) can reach the web only through bgfx (WebGL2 and WebGPU backends
   exist); SDL_gpu has no confirmed web backend. The ~15 NV2A-era shader classes need hand-written shaders either way.
3. **Game data and size.** About 2.3 GB of RCFs (1.1 GB without movies), supplied by the player. Fine for OPFS, but
   the first-run extraction and the 4 GB wasm32 ceiling shape the design.
4. **Floating point.** x87 to IEEE f32/f64. Same exposure as SSE native builds; the replay tooling is the answer, and
   wasm is at least deterministic where x87 code was not.
5. **Threads and fibers.** radcore uses fibers and a drive thread. Web needs either pthreads (COOP/COEP) or Asyncify;
   OpenCE picked pthreads.

Rough size: **web-only work is about 4 to 8 weeks of agent-assisted effort after the native Windows x86 build runs
and fix 5b/6b are done**; the shared prerequisites are many times larger and are already on the roadmap. A **cheap
probe already shows 97.0% of the tree (2,481 of 2,557 TUs) compiles for wasm32** with the same flags as the
`gnu` probe (section 7).

## 1. Prior art: OpenCE

[OpenCE](https://github.com/OpenCommunityEdition/OpenCE) (read from a shallow clone in
`build/web-research/OpenCE/`; read only, nothing run) is a port of the *Halo: Combat Evolved* Xbox decompilation
(build 2342) to Linux, Windows, Android and the web, playable at halocombatevolved.com
([README](https://github.com/OpenCommunityEdition/OpenCE/blob/main/README.md),
[port/web/README.md](https://github.com/OpenCommunityEdition/OpenCE/blob/main/port/web/README.md)).

**Architecture (the ideas worth knowing):**

| Topic | What OpenCE does |
|---|---|
| Layering | One game source tree (`source/`, C, 785 dirs/files) plus a platform layer in `port/linux/src` shared by Linux, Windows, Android and web; `port/web/src` holds only web-specific files (entry point, WebGL host, sockets over WebRTC, memory watch, JS halves). Web code paths are `HALO_WEB` / `HALO_GLES` guards; game-source edits are marked `port:` and listed in the README. |
| Graphics | It does *not* replace the engine's renderer interface. It re-implements the **Xbox D3D8 API itself** (`d3d8_gl.c`) on OpenGL, and translates NV2A vertex programs and register-combiner pixel shaders (`nv2a_vsh.c`, `nv2a_psh.c`) to GLSL at run time. Web uses the Android OpenGL ES renderer through WebGL 2. Their list of WebGL 2 gaps is a useful checklist (no texture swizzle, S3TC only for multiple-of-4 2D textures, vertex stride max 255 bytes, no feedback loops, no `glCopyImageSubData`, buffer-write stalls on ANGLE/Metal). |
| Toolchain | Emscripten 6.0.10 (pinned), `wasm32`, `-O2 -pthread -msimd128 -mbulk-memory -mnontrapping-fptoint`, `-ffp-contract=off`, `-fno-strict-aliasing`, no LTO (LTO turns width-mismatched calls into traps). Built by a ninja graph (`tools/web_build.py`). The decompilation is C, so the C++ ABI issue never came up for them. |
| Memory | Xbox memory window kept at a fixed virtual address by making the wasm memory exactly `0x88000000` bytes with `ALLOW_MEMORY_GROWTH=0` and the window as its top 128 MB; the C heap is kept below it. Needs a browser that grants ~2.1 GB. WebAssembly cannot protect pages, so write-watch of texture memory is done by hashing once a frame. |
| Threads / main loop | Emscripten pthreads with `PROXY_TO_PTHREAD`: game `main` runs on a Web Worker, canvas moved to the worker (`OFFSCREENCANVASES_TO_PTHREAD`), one game-loop iteration per browser frame via `emscripten_set_main_loop`. Needs cross-origin isolation. |
| Hosting | Static site on GitHub Pages. Pages cannot send COOP/COEP, so a **service worker adds the headers** (first visit reloads once); a header rule on Cloudflare is the alternative. About 10 MB first download. |
| Game data | **Player-supplied.** The page reads the player's own `.iso`/`.xiso` in place (a worker, `xiso-worker.js`, treats the image as untrusted: every offset is checked), validates each map, and copies only `maps/` into the browser's **Origin Private File System** (WasmFS mounted at `/data`). "Nothing is uploaded." Asks the browser for persistent storage. |
| Audio / input | SDL 3.4.16 built as an Emscripten port: audio via an AudioWorklet, gamepad (appears only after a button press), keyboard/mouse with pointer lock, touch overlay. |
| Video | **No Bink on any OpenCE port**; the game skips movies (README "Limits"). |
| Other | Multiplayer over WebRTC with public MQTT brokers for signalling; mods as folders in OPFS; tests in Node/Playwright. |

**License.** The repository is **CC0 1.0** (LICENSE.md; `docs/custom_edition_caches.md` notes it deliberately avoids
GPL code). It bundles third-party code under other licenses (expat, zlib, Opus, KCP, Monocypher, tomlc17, musl math,
stb_vorbis, extract-xiso, mbedtls, SDL3 zlib-licensed, SMAA MIT, Overpass/Newtown fonts OFL), whose notices a web
release must carry (`port/web/licenses.py`). Its Xbox SDK headers were written from the game's PDB and public
documentation, never the SDK.

**Rules for us (ideas, not code):**

- Copy: the *shape*. Static site, player-supplied disc image read in a worker and extracted to OPFS, service-worker
  COOP/COEP, pinned Emscripten, one game-loop step per animation frame, a "This browser" capability check page, and
  the WebGL 2 gap list as a checklist.
- Do not copy: their code, their D3D8-on-GL abstraction (it fits a game that calls D3D8 directly; ours has the `pddi`
  seam, so the abstraction is wrong for us), their fixed-address memory window, `HALO_WEB` ifdefs in game code.
- Separation: nothing from OpenCE goes in `game/` or `engine/`. Even though CC0 would permit it, we do not import it:
  keep it as reading material, so there is no provenance question and the repo's own license choice is unconstrained.
  If we ever do reuse a small piece, CC0 needs no attribution, but its bundled third-party files each carry their own
  terms (above); take them from upstream, not through OpenCE. Everything web-specific lives in `src/platform/web/`
  (and `site/` for the page), selected at build time like `platform/sdl`.

## 2. Toolchain and ABI (question 1)

**Choice: Emscripten, wasm32.** (Alternatives: wasi-sdk lacks browser APIs; Rust/Zig are irrelevant; a wasm64 build
gives 64-bit pointers, which breaks the `.p3d`/Lua assumptions below and has uncertain browser support: **unverified**,
WebAssembly 3.0 standardizes Memory64 per [this summary](https://byteiota.com/webassembly-30-spec-release/) but I found
no authoritative per-browser status.)

What the MS ABI dependence means on wasm32 (counts from [wine-build.md](wine-build.md), scans of the tree):

| Dependence | Count | wasm32 effect |
|---|---|---|
| Hand-written vptr stores `*(void**)this = &g_vftable_x` | 2,115 sites, 1,845 sources | breaks: Itanium vtable layout has offset-to-top and RTTI words before the table, and the vftable symbols we alias by address do not exist |
| Virtual calls through a hand-written vftable (`vptr[5]`) | 753 sites | slot numbers are MS-ABI numbers; Itanium gives virtual destructors two slots, so every class with one shifts |
| Virtual members of TU-local stub classes | 82,632 declarations | stubs that call by slot only work under the MS ABI |
| `__RTDynamicCast` by descriptor address | 792 sites | MS RTTI descriptors; need `dynamic_cast` on real classes |
| `__thiscall`/`__stdcall`/`__fastcall` annotations | ~2,689 sources | clang ignores them on wasm (1,893 TUs warned `ignored-calling-convention` in the probe); harmless, but see signatures below |
| MS name mangling aliases (`wine_link.py` fix 5a) | the link strategy of the current x86 build | not applicable: fix 5a's alias map only holds for MS ABI and 4-byte pointers |
| Absolute-address casts (NV2A methods, D3D state words, fiber starts) | ~75 + 19 | all inside `platform/xbox` and seam code that the web layer replaces |

**Does web depend on fix 5b / 6b? Yes.** 6b (constructors and non-trivial destructors defined once in `include/gen`
so sources stop storing vptrs) is required for any Itanium target, which wasm32 is. 5b (one canonical prototype per
verified function in `include/decls/`) is required for Itanium and 64-bit (an `int` parameter declared for a pointer
differs), and wasm adds a third reason: **WebAssembly calls a function only as its own type**; OpenCE had to fix every
mismatched declaration, and its link fails on a direct call with a mismatched signature
([port/web/README.md "Calls"](https://github.com/OpenCommunityEdition/OpenCE/blob/main/port/web/README.md)). Our tree
has ~11,700 callees referenced under another symbol and 1,199 free functions whose signature differs from the
definition's (wine-build.md), so 5b must be done properly (run the web link with fatal signature warnings as a gate).
There is no "compat shim" route for web equivalent to fix 5a. Wasm has no equivalent of the `/alternatename` alias trick
for signature-mismatched calls.

So web is not a way around these fixes; it is the strictest consumer of them. That is a useful property: if the web
link passes with signature checking on, the tree is genuinely canonical.

**What wasm32 buys us.** `sizeof(void*)==4`, `int` and `long` 32-bit: `.p3d` chunk layouts, Lua 5.1 bytecode
(compiled for 4-byte `size_t` and pointers), save structures and the 24,747 explicit `char pad[N]` layouts, and the
4,779 pointer/int casts all stay valid, so **the 64-bit cleanup (roadmap 6.2) is not needed for web**, and loaders of
32-bit file formats work unchanged. Two wasm32 differences from i386 that the probe found: `size_t` is `unsigned long`
(not `unsigned int`), and `long` is 4 bytes like MSVC. `double`/`long long` alignment in structs is 8 on wasm32 and MSVC but 4 on
i386 Linux, so wasm32 should match MSVC layouts better than the Linux x86 build (run the `sizeof`/`offsetof` checks
that the tree verifies against the XBE under wasm32 to confirm). Also: wchar_t is 4 bytes on wasm32 by default, and
the code assumes 16-bit (`-Xclang -fno-wchar` / `-fshort-wchar` as OpenCE does).

## 3. Floating point (question 2)

The game is x87: 80-bit intermediates, `_ftol` (367 sites), x87 control-word juggling, and `volatile` pins used to
force 64/32-bit rounding in lifted code (2,288 pins in 531 sources). WebAssembly has only IEEE f32/f64 with
round-to-nearest-even, no directed rounding, no observable exceptions, and NaN payload/sign nondeterminism
([Wasm spec numerics](https://webassembly.github.io/spec/core/exec/numerics.html)). Emscripten SIMD and `fma` are
opt-in; `-ffp-contract=off` is what OpenCE uses to avoid fused results.

Behaviours that can diverge from the Xbox:

1. **Excess precision.** Chained float expressions that on x87 stay in 80-bit registers round at every step on wasm.
   Physics (`fight`, `physics` namespaces), animation blending, camera filters, `pow`/`asin`-family helpers
   (`__CIpow`, `__CIasin` take x87 stack arguments) and trig. Differences are in the last 1 to 3 ulp but accumulate over
   frames.
2. **Float-to-int.** `_ftol` truncates via `fistp` with a control word; wasm's `i32.trunc_f32_s` traps out of range
   unless `-mnontrapping-fptoint` (saturating). Out-of-range inputs diverge (x87 returns `0x80000000`).
3. **Transcendentals.** Emscripten's libc (musl) `sin/cos/pow/atan2` differ from the Xbox CRT's x87 `fsin`/`fpatan`-based
   code in the last bits. OpenCE ships musl math for determinism across its platforms.
4. **Comparison and NaN behaviour.** `fcom`/`fnstsw` sequences with unordered operands; NaN sign propagation.
5. **Denormals** are handled natively in wasm (no flush-to-zero), unlike a program with FTZ set.

Positive side: wasm float semantics are deterministic across browsers for non-NaN ops, which is better than SSE-vs-x87
mixed hosts, so replays are repeatable between machines.

**Testing with our tools.** Same strategy as roadmap 6.3, and no new tooling is required:
- Run the existing deterministic input replays (`tools/hybrid_test.py`, [hybrid-build.md](hybrid-build.md)) against the
  web build with the original's checkpoints; the bisect tool names the guilty function.
- Re-run `tools/equiv.py`-style differential checks with a **float tolerance** per function class, using wasm
  compiled objects run under a wasm runtime (node or wasmtime) in place of the x86 emulator; `equiv.py` already
  carries x87 tolerance logic ([equivalence.md](equivalence.md)).
- Build a three-way matrix: x87 (i686 Windows build), SSE (arm64/x86-64), wasm. Record trace checkpoints from the
  x87 build and diff float fields at each. Only functions that diverge beyond tolerance need a software double-double
  or `long double` emulation, which is expensive; wasm has no 80-bit type, so any needed 80-bit behaviour would use
  `__float128`/soft-float (slow) or manual compensation.

## 4. Graphics (question 3)

Our plan is a `pddi` backend (`pure3d::pddiDevice`, `pddiDisplay`, `pddiRenderContext` with 111 virtuals, etc.) on
SDL_gpu or bgfx over Metal/Vulkan/D3D12 ([shipping.md](shipping.md), [platform-boundary.md](platform-boundary.md)).

| Option | Web story |
|---|---|
| **SDL_gpu** | SDL3's Emscripten README ([docs/README-emscripten.md](https://raw.githubusercontent.com/libsdl-org/SDL/main/docs/README-emscripten.md)) covers windows, input, audio, GLES2/3 via WebGL and does not mention SDL_gpu. A forum thread ([SDL3 GPU in browser](https://discourse.libsdl.org/t/can-sdl3-gpu-functions-shader-be-compiled-to-wasm/59691)) reported no WebGPU/WebGL backend. **Unverified for 2026**: check SDL's current tree before deciding. Treat SDL_gpu as native-only. |
| **bgfx** | Lists WebGL 1/2 and Emscripten, and WebGPU "Dawn Native only" ([overview](https://bkaradzic.github.io/bgfx/overview.html)); BSD-2 license. The only one of the two with a documented web target, so **the same backend can serve native and web if we pick bgfx**. Shaders compile offline with `shaderc` to GLSL ES / SPIR-V / MSL / HLSL from one source. |
| Own WebGL2 path under `pddi` | The OpenCE route. The `pddi` seam is thin enough (46 virtual methods called from portable code, 22 direct entry points: [seams.md](seams.md)) that a small second backend is plausible. Costs a second shader set. |
| WebGPU | Limited availability per [MDN](https://developer.mozilla.org/en-US/docs/Web/API/WebGPU_API); secure context only. A reasonable second target, not the first. |

**Recommendation:** make the backend choice for *native* first, with web as a tiebreaker in bgfx's favour. If SDL_gpu
wins natively, write a separate small WebGL2 `pddi` backend in `src/platform/web/` instead of bending SDL_gpu.

Specifics:

- **Fixed-function D3D8-style state.** The game's state goes through `pddiRenderContext` virtuals (blend, z, cull,
  fog, lights, texture stage ops) plus 93 D3D state words and 56 NV2A-method immediates, all inside the render seam
  that the new backend replaces anyway. No web-specific work beyond the shared backend; there is no fixed function in
  WebGL2 or WebGPU, so the backend emulates it with a generated-shader uber pass (cache keyed by state), as every D3D8
  port does.
- **Shaders.** About 15 `d3dShader` classes with NV2A vertex microcode and register-combiner pixel programs; each needs
  hand-written GLSL ES 3.00 (or bgfx shader source). This is the biggest single task and is shared with native. GLSL ES
  3.00 has what's needed; avoid features OpenCE lists as missing.
- **Texture formats.** The Xbox's DXT1/3/5 are swizzled. WebGL's S3TC extension requires 2D, dimensions that are
  multiples of 4, and DXT1 RGB is discouraged for portability
  ([WEBGL_compressed_texture_s3tc](https://registry.khronos.org/webgl/extensions/WEBGL_compressed_texture_s3tc/)); the
  extension is unavailable on some mobile GPUs, where decoding on upload (CPU, or a small wasm decoder) is the
  fallback. WebGPU exposes BC as the optional `texture-compression-bc` feature. Plan: unswizzle at load (the
  `XGSwizzleRect` replacement is shared), upload DXT where supported, otherwise decode to RGBA8; HD texture packs
  ([texture-packs.md](texture-packs.md)) are PNG so they take the RGBA8 path (4x textures raise memory, see section 6).
- **Other constraints** worth carrying over from OpenCE's list: no texture swizzle, no render-to-self feedback, no
  `glCopyImageSubData`, and buffer-update stalls on ANGLE/Metal (use per-frame buffer rings). Render targets and the
  `d3dExtFramebufferEffects` object (114 functions) are the riskiest consumers.
- **Draw-call cost.** Every GL call crosses wasm-to-JS; batch state changes and cache VAOs.

## 5. Audio, input, files, saves, threads, memory, video (question 4)

**Audio.** SDL3 on Emscripten gives an AudioWorklet output; sound is discarded until the first user click, so a "click
to start" gate is needed ([SDL Emscripten README](https://raw.githubusercontent.com/libsdl-org/SDL/main/docs/README-emscripten.md)).
The radsound HAL replacement (24 DirectSound functions; sample decode and Radical ADPCM are already game code) is
shared with native; the I3DL2 reverb and 3D mixing must be done in our code (no DSP chip), at fixed 48 kHz mix size to
avoid underruns (OpenCE found SDL's own buffer size necessary). Custom soundtracks (WMA) are stubbed. Music/voice in
`.rsd` files (574 MB across `sound.rcf`/`sound_en.rcf`) stream from OPFS.

**Input.** The Gamepad API through SDL3's gamepad layer; browsers expose a pad to a page only after a button press;
rumble varies by browser (SDL's haptics; **unverified** per browser). Keyboard/mouse map through SDL. The 7 XInput
functions are shared with native.

**Files.** Browser file APIs: player picks the `.iso`/`.xiso` (file input or `showOpenFilePicker`) or an
already-extracted folder (`showDirectoryPicker` in Chromium-class browsers). A worker extracts to the **Origin Private
File System** (secure-context only; synchronous access handles work in workers; subject to the origin's storage quota;
clearing site data deletes it: [MDN OPFS](https://developer.mozilla.org/en-US/docs/Web/API/File_System_API/Origin_private_file_system)).
Mount with Emscripten WasmFS's OPFS backend (OpenCE does) so the radcore file shim keeps using `fopen`/`pread`.
Sizes from the RCF inventory in [journal.md](journal.md): art 348 MB, districts 45, misc 13, nis 15, rooms 127, sound 354,
sound_en 220 (about **1.12 GB without movies**), movies 1,170 MB (`mog_mov*`, `movies*`), total about 2.3 GB, from a
2.4 GB disc. Per shipping.md the native port extracts RCFs to loose files; on the web consider keeping each RCF
as one OPFS file and reading ranges (`tools/rcf.py` shows the directory is a sorted hash table; the real loader is
`core::CementLibrary`), which avoids creating ~8,400 small files and skips movies unless wanted. Optionally skip the
extraction of movie RCFs entirely. Request persistence (`navigator.storage.persist()`) so the browser does not evict
1 to 3 GB.

**Saves.** Files under the OPFS `/data/save/`; drop signatures (HMAC over title key is skipped natively too). Offer export/
import as a zip so players can move saves between browsers (OpenCE does this).

**Threads and the main loop.** The game has a drive thread, semaphores, critical sections and **fibers** (radcore thread
layer: `ConvertThreadToFiber`/`CreateFiber`/`SwitchToFiber`). Options:

| Approach | Pros | Cons |
|---|---|---|
| **pthreads + `PROXY_TO_PTHREAD` + OffscreenCanvas** (OpenCE) | blocking calls just work; drive thread maps to a real worker | needs SharedArrayBuffer, so COOP `same-origin` + COEP `require-corp` ([web.dev](https://web.dev/articles/coop-coep)); static hosts without header control need a service worker; a threaded wasm cannot fall back to a single-threaded one, so two builds ([Emscripten pthreads](https://emscripten.org/docs/porting/pthreads.html)) |
| Single-threaded + `emscripten_set_main_loop` + **Asyncify** | works on any static host | Asyncify code-size/speed cost; the game's frame loop must be restructured into per-frame steps either way; blocking file reads need async I/O or preloaded buffers |

Fibers on Emscripten need Asyncify ("you must link your program with ASYNCIFY",
[fiber API](https://emscripten.org/docs/api_reference/fiber.h.html)); under pthreads the simplest port is
**thread-per-fiber with a handoff semaphore** (the same plan as the native `platform/sdl` layer), so the web build can
share that code. Recommendation: pthreads, as OpenCE did, accept the COOP/COEP requirement, and ship the service-worker
trick for hosts that cannot set headers. One iteration of the game loop per `requestAnimationFrame`; the game
runs 30 fps in gameplay (platform-boundary.md), so frame pacing can follow the vblank callback.

**Memory.** wasm32 caps linear memory at 4 GB; 2 to 3 GB is realistic in current desktop browsers (OpenCE requires a
browser that grants 2.1 GB and says phones may not: [port/web/README.md](https://github.com/OpenCommunityEdition/OpenCE/blob/main/port/web/README.md)).
The Xbox had a fixed budget (64 MB of RAM on retail hardware; the game reports a fixed `GlobalMemoryStatus` per
platform-boundary.md), so the game's own footprint is small. The pressure is on the host side: decoded textures
(especially HD packs), streamed audio, and OPFS data are not in linear memory except what is read. Plan a fixed
memory size (no growth, so pointers and shared-memory views stay valid), 256 MB initial as a first guess **(measure
under the Wine build)**, and a memory watch only if the game depends on write-protect semantics (OpenCE needed it
for a Halo texture-cache trick; our `pddi` backend does not have that constraint since we own the texture upload
path).

**Bink video.** No web decoder is shipped by us. Options: (1) skip movies as OpenCE does; (2) RAD's Bink 2 SDK lists
"the web (WebAssembly via Emscripten)" ([RAD Bink](https://www.radgametools.com/bnkmain.htm)), but it is a commercial
license and the game's movies are Bink 1 (verified by mv1: all 28 `.rmv` files are `BIKi`): not an option for an open
repo; (3) transcode at asset-prep time on the player's machine to a format the browser decodes (WebCodecs / `<video>`
with VP9 or H.264), which fits the "player supplies data" rule and needs an ffmpeg-class transcoder in the page
(heavy) or a desktop helper; (4) a clean-room Bink 1 decoder (patent/license status **unverified**, legal review needed);
(5) FFmpeg's LGPL Bink decoder, which the desktop build now uses ([wine-movies.md](wine-movies.md)): a wasm build of
the same minimal configuration links to a 549 KB module (linked, not yet run in a browser).
Recommendation: ship v1 with movies skipped and a seam hook so a transcoded `.webm` can play through `RenderStrategy`
later. Movies are about half of the disc, so skipping also halves the storage ask.

## 6. Legal and distribution (question 5)

- **What a web build may contain:** our source-built `.wasm`, JS glue, page, shaders written by us, third-party
  libraries with their notices (a `licenses.txt` like OpenCE's). No game data, no XBE, no XDK, no Bink, no assets from
  the disc, not even derived tables. Same rule as every other platform ([shipping.md](shipping.md) "The legal line").
- **How players supply the game:** open the page, pick their own ISO/XISO (or extracted folder); the page checks the
  XBE hash against the supported release, extracts in a worker into the browser's OPFS; nothing leaves the machine.
  OpenCE does exactly this and states "nothing is uploaded"
  ([README "Game data"](https://github.com/OpenCommunityEdition/OpenCE/blob/main/README.md)). Read the disc image in
  place with range reads (File.slice) so a 2.4 GB image is not loaded into memory; treat it as hostile input.
- **Hosting:** the site can be static (GitHub Pages / Cloudflare Pages) because it holds only our code. Do not host
  texture packs (user-installed only per [texture-packs.md](texture-packs.md)).
- **Risks:** a *hosted playable site* is more visible than a source release, and the repo has no license yet. Public hosting
  gives the rights-holders a clear takedown target; OpenCE's choice to host a site is its own risk judgment, not
  precedent for us. Decide separately from the engineering. Not legal advice.

## 7. Cheap probe: emcc on the merged tree (question 6)

`build/web-research/emcc_probe.py` compiles each TU of the clang-probe snapshot with `/opt/homebrew/bin/emcc` (wasm32,
1 process), with the `gnu` configuration's flags minus `--target`, `-mno-sse` and `-mfpmath=387`, and adds
`-Xclang -fno-wchar -fno-operator-names` and the native dialect flags that `clang_probe.py` uses. Diagnostics are
classified with `clang_probe.py`'s own rules, so categories are comparable. Results in
`build/web-research/emcc-probe/result_*.json`.

| run | TUs | compile OK | fail |
|---|---|---|---|
| emcc wasm32, syntax only, whole snapshot (6 minutes, 1 process) | 2,557 | **2,481 (97.0%)** | 76 |
| emcc wasm32, `-c -O1` objects, random 200 | 200 | 193 (96.5%) | 7 |
| clang `gnu` (i686 Linux), same snapshot | 2,557 | 2,487 (97.3%) | 70 |
| clang `gnu64` poc (for scale, from wine-build.md) | 2,557 | about 92.4% (earlier snapshot) | |

Object generation succeeds wherever syntax does, so there are no wasm backend errors in the sample.

Failures by category, TUs (emcc / gnu where gnu failing is from the cached report):

| category | emcc TUs | meaning |
|---|---|---|
| `dependent-base-lookup` | 24 | `Closure0` stubs using `Fn` from a dependent base: MS two-phase lookup (same on gnu) |
| `msvc-template-spec-syntax` | 17 | `template <>` missing on clone specializations (same on gnu) |
| `extern-c-redeclared` | 14 | 5 shared with gnu, **9 new**: `strlen`/`memcpy`/`strncpy`/`memset` redeclared with `unsigned int` where the builtin takes wasm32's `unsigned long` |
| `other-error` | 13 | per-source (same on gnu) |
| `exception-spec-mismatch` | 5 | `operator new`/`memset` without `throw()` (same on gnu) |
| `goto-over-initialization` | 5 | asm-shaped control flow (same on gnu) |
| `msvc-for-scope`, `type-defined-in-return-type`, `placement-new-undeclared`, `register-keyword` | 2 each | same kinds as gnu; `placement-new-undeclared` is the `size_t` width again |

Reading:

1. **No wasm-specific blocker at the syntax or codegen level.** 65 of the 76 failures are the same TUs and causes as
   the Linux `gnu` configuration, and fixing those (fix 4's per-source edits) is shared work. 11 are new, all one
   cause: a hand-declared libc function or `operator new(unsigned int)` whose `size_t` is `unsigned int`. wasm32's
   `size_t` is `unsigned long`; the `size_t` canonicalisation in `tree_prelude.h`/`compat/native.h` (fix 1) should
   cover the rest if the sources stop spelling their own prototypes for libc functions. 5 TUs compile under emcc but
   not under the cached `gnu` run; I did not investigate why (the cached `gnu` report may predate later tree edits).
2. **The compile check cannot see the real problems.** Everything above is syntax. The ABI breakage (vptr stores,
   slot numbers) and signature mismatches only appear at link and run time. The honest second probe is a wasm **link**
   with `-Wl,--fatal-warnings` of a small closed subset (e.g. one engine namespace plus data TUs); expect many
   signature-mismatch errors, which is the count 5b will drive to zero. I did not run a link: it needs stubs for the
   unresolved symbols (30,000 before fixes).
3. Warnings: `ignored-calling-convention` in 1,893 TUs and `ignored-declspec` in 1,872 are noise; null-`this` and
   array-bounds UB warnings (9 and 5 TUs) are the per-source review items already in wine-build.md.

Rerun any time with `python3 build/web-research/emcc_probe.py <N> <seed> [obj]` (6 minutes for the whole tree, 1 process).

## 8. Staged plan

Rows marked **shared** are required by the native ports too and should be done first; **web** is new work for this
document. Sizes are estimates for one person with agents.

| Stage | Work | Shared / web | Size | Slots after (roadmap) |
|---|---|---|---|---|
| W0 | Re-run the emcc probe after each `build_tree.py` run as a regression gate (the script exists). Add `-Wl,--fatal-warnings` link probe of a closed subset. | shared tooling | 1 to 2 days | now |
| W1 | Fix 4 (per-source MS-isms), `size_t` canonical, libc prototypes in a compat header | shared | 1 to 2 weeks | native-build fix 1/4 |
| W2 | Fix 5b canonical prototypes and fix 6b constructors/destructors in `include/gen`, so sources stop storing vptrs. Web link gate: zero signature mismatches. | shared (the long pole) | 4 to 10 weeks | roadmap 2 and 6.1 |
| W3 | Seam implementations that are not graphics: file shim, input, audio HAL, timers, threads incl. thread-per-fiber, saves, CRT. Written against SDL3 so they build on Emscripten. | shared with `platform/sdl` | already planned | roadmap 6.1 |
| W4 | `pddi` backend and shaders (the 15 shader classes). Decide bgfx vs SDL_gpu with web as a tiebreaker. | shared if bgfx; else native + web separate | the biggest item | roadmap 6.1 / 7 |
| W5 | wasm32 float validation: replays with tolerances, three-way matrix (x87 / SSE / wasm), fix divergent functions | shared replay tooling, web-run | 1 to 3 weeks after the build runs | roadmap 5 and 6.3 |
| W6 | `src/platform/web/`: Emscripten build graph (pinned emcc), entry point (`main` loop stepping, no blocking on the page thread), OPFS mount, canvas in worker, capability check | web only | 1 to 2 weeks | after W2 to W4 and a running Windows x86 build |
| W7 | The page: ISO picker, worker extractor with XBE hash check, progress, storage persistence, saves export/import, service-worker COOP/COEP, licenses.txt | web only | 1 to 2 weeks | after W6 |
| W8 | Movies: skip (default), later transcoded-video path | web only | 0 / 1 to 3 weeks | optional |
| W9 | Performance: GL call batching, buffer rings, wasm SIMD flags, memory sizing, loading-time streaming from OPFS; test in Chrome, Firefox, Safari | web only | 2 to 4 weeks | after W7 |

Milestones: web slots **after roadmap step 6.1** (a native 32-bit build that runs), because it needs the same fix 5b/6b,
seam shims and renderer; it does **not** need 6.2 (64-bit cleanup) and can share the 32-bit pointer assumptions, so it
may reach players before arm64/x86-64 do. It shares step 5 (hybrid build/replays) as its correctness oracle. Step 7
QoL items (widescreen, HD textures) work unchanged on the web.

## 9. Directory layout and boundary rules

```
src/platform/web/      emscripten entry (main loop, OPFS mount), WebGL2/bgfx glue, JS libraries, wasm-only stubs
site/                  index.html, app.js, workers (iso extractor), service worker, manifest
build/web/             output only (ignored)
```
- `game/` and `engine/` get no `#ifdef __EMSCRIPTEN__`. A web difference is a seam implementation.
- The build selects `platform/web` the way it selects `platform/sdl`; the Emscripten toolchain file is the only
  place that mentions `emcc`.
- No code or abstractions from OpenCE; third-party dependencies (SDL3, bgfx, stb) are pulled as upstream
  dependencies with their own licenses.
- Pin the Emscripten version (OpenCE pins 6.0.10); the probe above ran on the locally installed 6.0.2-git.

## Open questions

- bgfx or SDL_gpu natively? (web favours bgfx; check SDL_gpu's current web status first.)
- ~~Do `.rmv` movies use Bink 1?~~ Yes (mv1). A transcode would add about 1.2 GB ([wine-movies.md](wine-movies.md) section 3).
- Does the game keep any state in the first 64 KB / absolute XBE addresses that wasm's flat memory must reproduce (the
  75 absolute-address casts)? They are in platform code today.
- Browser memory in practice: can Safari and mobile browsers give the footprint (unverified; desktop Chrome, Edge and
  Firefox are the realistic first targets, as for OpenCE).
- Whether to ship the web build at all before the repo's license question is settled.
