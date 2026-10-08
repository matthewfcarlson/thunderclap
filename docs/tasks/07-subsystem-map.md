# 07: Subsystem map for QoL (render, camera, HUD, game loop)

## Goal
Find and document the code behind the quality-of-life targets (widescreen and aspect ratio, FOV, frame rate and timestep, resolution, intro skipping), so these functions can be prioritized for decomp and patched in the hybrid build (task 06).

## Context
- RTTI already names many subsystems: `VCRenderManager`, `VCCameraManager`, `VHUDOverlay`, `VCGameFlowManager`, `VCWorldStreamManager`, `VCFEManager` (front end), `VCSubtitleManager`, plus `pure3d::pddiBaseContext` (the renderer interface, 111 virtual methods). Their vtables and virtual methods are labelled in Ghidra (`build/ghidra`) and listed in `build/rtti.json`.
- Useful anchors: D3D8 calls identified by XbSymbolDatabase (`D3DDevice_SetViewport`, `D3DDevice_SetTransform`, `D3DDevice_Present`/`Swap`, `SetRenderState`), XAPI timing (`KeQueryPerformanceCounter`, `QueryPerformanceFrequency`), float constants like `0.75`/`1.3333`/`4/3` aspect, `60.0`/`30.0`/`0.0333` timesteps, and FOV-ish radians around `0.7–1.2`.
- Strings: debug and menu strings, the `args.txt` command line (`-fmvvol 0.9`). Command-line parsing code may expose hidden switches.

## Deliverables
1. `docs/subsystems.md`, per target:
   - **Projection/aspect/FOV:** the function(s) building the projection matrix, where aspect and FOV come from, and the HUD layout code (2D overlay scaling).
   - **Frame timing:** the main loop, how `dt` is computed or clamped, and whether physics or animation assume 30 or 60 Hz.
   - **Resolution/back buffer:** D3D present parameters and render-target sizes.
   - **Boot flow:** intro movies and splash screens, and how to skip them.
   - Each entry gives addresses, Ghidra names, call chains, and a confidence level.
2. A prioritized list (`build/farm/priority.txt` format: one address per line) of functions to decompile first for these features. The farm can consume it.
3. Ghidra labels for what you find, applied via a script in `tools/ghidra_scripts/` that's re-runnable (not manual GUI edits, which aren't tracked).

## Done when
- Each QoL target above has an identified code location with evidence, or a documented dead end.
- The priority list exists and is referenced from `docs/roadmap.md`.
