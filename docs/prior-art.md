# Prior art & tooling survey (2026-10)

## LLM-assisted decomp projects (workflow references)

| Project | Target | What to steal |
|---|---|---|
| [freeqaz/dc3-decomp](https://github.com/freeqaz/dc3-decomp) | Xbox 360, MSVC-PPC C++ | **Closest analogue** (big MSVC C++ game, Claude Code). Orchestrator MCP that wraps objdiff/Ghidra/m2c/build. About 25 `.claude/skills`. Worktree pool for parallel agents. Unicorn side-by-side execution to sort logic bugs from regalloc noise. Reports ~91% of authorable functions. Separates XDK code from game code in its metrics. |
| [cdlewis/snowboardkids2-decomp](https://github.com/cdlewis/snowboardkids2-decomp) ([write-up](https://blog.chrislewis.au/the-long-tail-of-llm-assisted-decompilation/)) | N64 | Similarity-based scheduling (work next to already-matched functions) beat difficulty ranking. Hooks block tampering with the hash, tests, and generated files. Dropped decomp-permuter because of overfitting and doom loops. Caps retries (p85 ≈ 28 attempts). [nigel](https://github.com/cdlewis/nigel) task runner, [coddog](https://github.com/ethteck/coddog) opcode-similarity search. |
| [macabeus/mizuchi](https://github.com/macabeus/mizuchi) | GBA | Plugin pipeline: m2c → compile → objdiff → permuter first, then a sandboxed Claude retry loop. Claude can only submit C. Matched 74% of a 60-function benchmark ([post](https://gambiconf.substack.com/p/can-llms-really-do-matching-decompilation)). Also Kappa (VS Code agent mode). |
| [Simon Willison on one-shot decomp](https://simonwillison.net/2025/Dec/6/one-shot-decompilation/) | | Headless Claude Code loop that always picks the easiest remaining function. |
| [Starting a decomp from zero with Claude Code](https://gambiconf.substack.com/p/starting-a-decompilation-project) | GBA | Bootstrapping a project from nothing. |

| [hkmodd/ps2-recomp-Agent-SKILL](https://github.com/hkmodd/ps2-recomp-Agent-SKILL) | PS2 (recomp) | Claude skill used as a boot sequence: `SKILL.md`, then required reading in `resources/`. A persistent `PROJECT_STATE.md` that the human edits to correct the agent and that new chats resume from. Circuit breakers (same failure 3× → stop and read docs or ask). "Read first, detect second, ask third, act last." Ghidra driven over MCP (GhydraMCP), plus an emulator debug server over MCP for A/B runs (original vs. rebuilt). The ISA-specific parts don't transfer; the process layer does. |

## Original-Xbox matching decomps (most relevant)

decomp.dev tracks only **2** original Xbox projects (as of 2026-10):

- **[punpckhdq/halo](https://github.com/punpckhdq/halo)**: Halo CE build 2342. **Matching**, ~19% decompiled. **This is the template to copy.** Pipeline:
  - `configure.py` + `tools/project_x86.py` generate `build.ninja` and `objdiff.json` (derived from encounter's dtk-template).
  - **[csplit](https://github.com/punpckhdq/csplit)** ("simple i386 COFF object splitter") cuts the original binary into per-unit COFF objects using `config/splits.json`, `symbols.json`, `relocs.json` and `contribs.json`, so each unit can be diffed with objdiff.
  - The compiler is the XDK's own `cl.exe` (dropped into `xbox/bin`), run on Linux/macOS through **[wibo](https://github.com/punpckhdq/wibo)**, a minimal Win32 loader (macOS build is x86_64 via Rosetta). Wine is the fallback.
  - Flags: `/O2 /Oy- /MT` with a PCH. Each object is marked `Matching`/`NonMatching`/`MISSING`. CI builds in a private container that holds the originals and uploads `report.json` to decomp.dev.
  - **Difference from us**: they use a *debug build with symbols* (`contribs.json` carries PDB module indices; relocs are known). Our retail XBE has **no PDB and no relocation table**, so we have to work out splits, symbols and relocs ourselves (Ghidra analysis plus RTTI/vtables plus string xrefs). That's the main up-front cost.
- **Mortal Kombat: Deception**: ~4.5% (repo link from decomp.dev 404s).

## Recompilation (not decomp, but adjacent)

- **[XenonRecomp](https://github.com/hedge-dev/XenonRecomp)**: Xbox 360 PPC → C++ static recompiler (UnleashedRecomp). TOML config with function boundaries, jump tables, setjmp addresses and mid-asm hooks. Override functions with weak linking. Not applicable to x86 Xbox directly, but its "recomp first, swap in decompiled functions over time" model is the static counterpart to halo-re's XBE patching.
- **[Recompendium](https://nio03.github.io/unricopie/en/)**: curated catalog of ~120 recomps, ~125 decomps and tools across 22 platforms, synced from decomp.dev. It records which projects disclose AI assistance (Road Rash 64, Ridge Racer PS1, Wave Race 64, Fable II, …) and which ban it (Viva Piñata).
- **[decomp.dev](https://decomp.dev/projects)**: progress tracker (consumes objdiff `report.json` from CI). Goal: get listed here.

## x86 / MSVC matching tooling

- **[reccmp](https://github.com/isledecomp/reccmp)** (LEGO Island decomp): the standard tool for MSVC x86 matching. Uses source annotations (`// FUNCTION: TARGET 0xADDR`), compares the original binary with the recompiled one through the PDB, and checks vtables, data and stack layout. Includes a Ghidra importer. Targets old MSVC (4.20); newer MSVC support is "in progress". It expects PE input, so we'd need an XBE→PE conversion or a loader patch.
- **[objdiff](https://github.com/encounter/objdiff)**: per-object diffing. Supports x86 COFF, which is the format `cl /c` emits, so a per-function workflow is possible if we can split the target into COFF objects.
- **decomp.me**: has Win32 MSVC presets for sharing scratches. Need to check whether 7.1 / 13.10 is listed.
- **Compiler**: XDK 5849 shipped with a VS.NET 2003-era `cl.exe` (13.10.x). We'll need the matching compiler, which means getting it from an XDK and running it under Wine on macOS (or in a Windows VM / CI).

## Original Xbox tooling

- **[XboxDev/ghidra-xbe](https://github.com/XboxDev/ghidra-xbe)**: Ghidra XBE loader. Uses **XbSymbolDatabase** to auto-label XDK library functions, so D3D/DSOUND/XAPI/LIBCMT can be excluded right away.
- **[halo-re/halo](https://github.com/halo-re/halo)**: Halo CE decomp. **Non-matching**: the build patches the original XBE so calls go to reimplemented functions, and it builds with Clang on macOS. This is an incremental, playable-from-day-one model we could use as an alternative or complement to byte matching.
- **[xboxrecomp](https://github.com/sp00nznet/xboxrecomp)**: static recompiler from XBE to native C. Not a decomp, but useful for its XBE parsing and library identification.
- **xemu**: emulator for runtime testing (breakpoints and memory watch with its GDB stub).
- **xdvdfs** (`cargo install xdvdfs-cli`): ISO extraction (used here).

## Radical / Pure3D engine knowledge

- **Donut Team** ([forum](https://forum.donutteam.com/topic/4617-hulk-ultimate-destruction-p3d-editor)): Pure3D (`.p3d`) chunk documentation. Their P3D editor opens *some* Hulk UD files.
- **Luigi Auriemma's radcore/RCF notes** and Hampo's LuaP3DLib are cited by [hit-and-run-web](https://github.com/Vheissu/hit-and-run-web) as format references.
- **[plowteam/donut](https://github.com/plowteam/donut)**: clean-room Simpsons: Hit & Run reimplementation. A legal reference for how Pure3D works.
- **SHAR_ROM**: decomp of the SHAR GameCube build tools.
- ⚠️ **Leaked Simpsons: Hit & Run source (2003)** is public on GitHub and shares engine code (Pure3D, radcore, radsound, etc.) with this game. **Do not copy it, and don't feed it to agents as reference.** It would contaminate the project. Stick to clean-room info: format docs, RTTI, and our own analysis.

## Sources to avoid

- A TCRF "Developer Tools" page fetched during research returned prompt-injection content instead of real info. Treat it as unreliable.
