# Roadmap

**Goal: a native port.** Source we can build for SteamOS (x86-64 Linux), arm64 macOS and Windows, with quality-of-life improvements. Byte-matching is a tool for proving correctness cheaply, not the destination. A SHA-1-identical `default.xbe` is optional and off the critical path.

Concrete task briefs are in [`docs/tasks/`](tasks/README.md).

## Why a source port, not a static recompiler

A recompiler (XBE x86 → C, e.g. `xboxrecomp`) boots sooner. But it leaves machine-translated code running in an emulated 32-bit address space with x87 quirks, and every QoL change is a hook into translated code. This engine makes a source port unusually cheap: Pure3D/radcore was a multi-platform engine, and the Xbox-specific code sits behind a few seams the RTTI already shows:

| Seam | Classes (RTTI) | Port replacement |
|---|---|---|
| Rendering | `pure3d::pddiDevice`, `pddiDisplay`, `pddiRenderContext`, `pddiBaseContext` (111 virtuals), `pddiExt*` | a `pddi` backend on Vulkan/Metal (SDL_gpu or similar) |
| Input | `core::ControllerXBox`, `ControllerInputPointXBox`, `ControllerOutputPointXBox` | SDL3 gamepad |
| Audio | `audio::Hal*`, `audio::ListenerEffectXBox` | SDL3 audio / miniaudio |
| Movies | `movie::PlayerBink`, `RenderStrategyBink` | Bink transcoded at asset-prep time, or a modern decoder |
| OS | XAPI/kernel calls (files, threads, timers, memory) | a thin shim over SDL3 / the C++ standard library |

XDK, CRT and Bink library code is **replaced, never decompiled**. Everything else needs source.

## The plan

### 1. Map the platform boundary *(done)*
- Every call from game code into XDK/kernel/D3D8/DirectSound (XbSymbolDatabase already identifies these): that list is the port's shim surface.
- Subsystem map for render setup, camera, HUD, game loop and timestep ([task 07](tasks/07-subsystem-map.md)). It sets the farm's priority order.
- *Done:* [`platform-boundary.md`](platform-boundary.md) (182 platform functions; four seams plus 8 leak functions contain every platform call), [`subsystems.md`](subsystems.md) (QoL locations), and [`port-priority.txt`](port-priority.txt) (2,011 functions, seams first; `build/farm/priority.txt` for the farm).

### 2. Shared headers and real types *(highest leverage)*
- One definition per class, replacing per-function stubs ([task 02](tasks/02-rtti-headers.md)). RTTI gives names, inheritance and vtables; field layouts come from usage across functions.
- Recompile every match against the shared headers; it must still match. This catches field-offset disagreements.
- This is a prerequisite for both the port (64-bit layouts depend on real types) and for large functions (they fail on layout far more than on logic).

### 3. Complete source coverage
Every game function gets compilable C++ at one of three levels:

| Level | Meaning | How it's proven | Where it goes |
|---|---|---|---|
| **matched** | byte-identical codegen, references verified | `compare.py` + `verify_relocs.py` | `matches/` |
| **equivalent** | different bytes, same behaviour | differential execution against the original (see [task 09](tasks/09-equivalent-decomp.md)) | `equivalent/` |
| **draft** | compiles against shared headers, not yet proven | — | `equivalent/` with `// STATUS: draft` |

- Small functions: keep matching. It's cheap (under a cent each) and the proof is free.
- Large functions: stop paying for byte-matches. The farm writes equivalent code and checks behaviour instead ([task 09](tasks/09-equivalent-decomp.md)). A later pass can still upgrade them to matched.
- Order by subsystem, not size: the seams in the table above, then the step-1 priority list, then everything else.

### 4. Data
- Globals, constant tables, float pools, vtables and strings (`.rdata`/`.data`/`.bss`) as source.
- Translation-unit recovery ([task 05](tasks/05-split-recovery.md)) is useful for organizing source but not required for the port.

### 5. Hybrid build in xemu: the integration test
- Patch our compiled functions into the original XBE and run it in xemu ([task 06](tasks/06-hybrid-patch-build.md)).
- It's the end-to-end check for equivalent code (play, or replay recorded input, and compare against the original) and the first place QoL patches ship: widescreen, FOV, 60 fps.
- Test plan ([task 10](tasks/10-hybrid-test-plan.md)): deterministic input replays compared checkpoint by checkpoint against the original, automatic bisection to the guilty function, and real captured inputs fed back to `tools/equiv.py`. The same suite later checks the native builds.

### 6. Native build
1. **x86-32 host build first** (Linux or Windows, clang): same pointer size and calling conventions as the Xbox, so the only new variable is the platform layer. Shim XAPI/kernel, implement the `pddi`, input, audio and movie backends.
2. **64-bit clean-up**: pointer-size assumptions in structs, especially anything loaded from disk (`.p3d` chunk loaders, save data) and any code that stores pointers in `int`s.
3. **x86-64 (SteamOS) and arm64 (macOS)** builds. Watch x87 → SSE/NEON float differences in physics and animation; replays from step 5 catch drift.

### 7. Make it better
Mostly ordinary code changes once step 6 lands; many can ship earlier as hybrid-build patches.
- Widescreen (projection and HUD layout), FOV slider, camera options.
- Unlocked frame rate: needs the game loop and timestep code (physics and animation are usually tied to frame time).
- Native high resolution, MSAA, anisotropic filtering, draw distance and LOD bias.
- Skip intros, faster loading, controller remapping, rumble options.
- Assets: `.rcf` and `.p3d` tools are done ([task 03](tasks/03-rcf-tool.md), [task 04](tasks/04-p3d-reader.md)); HD texture and model packs build on them.

## Status of the old plan
The previous roadmap ended in a SHA-1-identical relink before any port work. That's now optional: matching continues where it's cheap, reference verification ([task 01](tasks/01-reference-verification.md)) is done, and the relink can happen later if anyone wants it.
