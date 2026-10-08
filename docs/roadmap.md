# Roadmap

From "every function matches" to a rebuildable, moddable, portable game. Stages are roughly in dependency order. The quality-of-life and asset tracks (stage 6) can start much earlier; see the notes there.

## Stage 1: Match every game function *(in progress)*
- Farm plus propagation produce one standalone `.cpp` per function in `matches/`, with invented names and stub classes.
- Small and mid functions (≤96 B): GPT-6 Luna, ~$0.002/match. Large functions: aligned diffs, staged matching, similar-function examples, local models, then stronger models (Sonnet before Astra).
- **Caveat:** compare masks relocated bytes, so a match proves code *shape*, not that calls and globals point at the right symbols. Stage 2 closes that gap.

## Stage 2: Verify references (codegen match → full match)
- Export every reference from Ghidra (calls, globals, vtables, string and float pools). The XBE has no relocation table.
- `compare.py` checks that each relocation in our object resolves to the same target symbol as the original. Expect some current matches to fail and need fixing.

## Stage 3: Shared headers and real types
- One definition per class, replacing per-function stubs. RTTI gives names, inheritance and vtables. Field layouts come from usage across functions.
- Recompile every function against shared headers; it must still match. This catches matches that disagree on a field offset.
- Consistent naming (`vfunc_7` → `Update`) from strings, asserts and behaviour.

## Stage 4: Original translation units
- Recover `.obj` boundaries from link order in `.text`, string-pool and vtable/RTTI placement, and assert file names.
- `config/splits.json` (Halo-style). Functions move into source files in original order.
- Decompile data: globals, constant tables, float pools, vtables, strings (`.rdata`/`.data`/`.bss`).
- **csplit** cuts the original into per-file objects; **objdiff** tracks per-object progress; progress goes on **decomp.dev**.

## Stage 5: Relink to the original
- Link our objects with the XDK/CRT/Bink code: either XDK 5849 libraries, or those regions carved out of the original XBE as binary objects.
- Rebuild the XBE (header, sections, kernel thunks, certificate). Target: **SHA-1-identical `default.xbe`**, which then boots in xemu.

## Stage 6: Make it better
Most of this does **not** need stage 5. Three things unlock it early:
- **xemu**, available today: internal render-resolution scaling (higher "rendering size") with no game changes.
- **Hybrid build** (Halo-re style): patch our decompiled functions into the original XBE. Once the relevant subsystem is decompiled, this allows QoL changes playable in xemu, long before a full relink. So decompile the subsystems below *first*, not in size order.
- **Asset tooling** is independent of code decomp and can start any time.

### Quality of life
- Widescreen 16:9 (projection and HUD layout), FOV slider, camera tweaks.
- Higher or unlocked frame rate (60 fps). Needs the game loop and timestep code, since physics and animation are usually tied to frame time.
- Skip intro movies and splash screens; faster loading; save/checkpoint conveniences.
- Controller remapping, inverted-axis options, rumble settings.

### Rendering
- Native higher resolution and correct widescreen in the engine (beyond xemu's upscaling); MSAA, anisotropic filtering.
- Draw distance and LOD bias for districts and crowds; shadow resolution.
- Pure3D/pddi renderer (`pure3d::pddiBaseContext`, 111 virtual methods): the natural seam for a modern backend.

### Assets and models
- `.rcf` ("ATG CORE CEMENT LIBRARY") unpack/repack tool; asset browser.
- `.p3d` (Pure3D chunk format) reader/writer, building on public Donut Team format docs and the clean-room SHAR reimplementations (no leaked code).
- Texture dump and replacement packs (HD textures), model import/export (Blender), audio and Bink movie replacement.
- Modding hooks for new moves, characters and districts once the relevant systems are decompiled.

### Native port ("recomp")
- With matched source, replace Direct3D 8, DirectSound, XInput and the Xbox kernel with modern backends (e.g. a pddi implementation on Vulkan/Metal/WebGPU, SDL for input and audio). dc3-decomp did this for an Xbox 360 game.
- Then high-res rendering, widescreen, high frame rate and modding become ordinary code changes.

## Suggested ordering for the QoL track
1. Asset tools (RCF, then P3D): no code decomp needed; lets texture and model work start.
2. Prioritize decomp of the render-setup, camera, HUD and game-loop/timestep subsystems. RTTI already names many of them (`VCRenderManager`, `VCCameraManager`, `VHUDOverlay`, `VCGameFlowManager`).
3. Hybrid patch build in xemu: ship widescreen, FOV and 60 fps as patches.
4. Full decomp plus relink, then the native port.
