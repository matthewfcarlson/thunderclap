The goal is a **native port**: C++ source we build for the supported targets, x86-64 SteamOS, arm64 macOS and arm64 Android handhelds (Windows is not a target), with quality-of-life improvements. Every game function has verified source: byte-matched against the original compiler (MSVC 7.1, `cl` 13.10.3077) where that's cheap, since a match proves correctness for free, or proven *equivalent* to the original by differential execution.

**This repo contains no game code or assets. You need your own copy of the game.**

## Status

<!-- status -->
| | Functions | Bytes |
|---|---|---|
| Game code (`.text`, excluding XDK/CRT/Bink) | 27,437 | 2.73 MB |
| Byte-matched (`: matches` blocks) | 22,337 (81.4%) | 892 KB (32.7%) |
| Proven equivalent (`: equivalent` blocks) | 5,099 (18.6%) | 1836 KB (67.3%) |
| **Verified source, total** | 27,436 (100.0%) | 2727 KB (**100.0%**) |
<!-- /status -->

![Treemap of game code in address order, one box per function sized by its bytes: blue is byte-matched, green is proven equivalent, grey is not yet verified](docs/progress-map.svg)

Most matches are small functions, so byte coverage is the honest metric. Where things stand (2026-11-11):

- **Verified source for every game function.** All but one address are byte-matched or proven equivalent; the one left, 0x0035c5b0, is 304 bytes of data, not a function. XDK, CRT, D3D and Bink library code is reimplemented from its interfaces, never decompiled, and is not counted ([`docs/platform-boundary.md`](docs/platform-boundary.md)).
- **One merged source tree is the source of truth** (the merge-once flip, 2026-11-10, freeze point F = `e68debc9d`; [`docs/merge-once.md`](docs/merge-once.md)). `src/game/`, `src/engine/` and `src/platform/xbox/` hold one translation unit per recovered object file ([`docs/splits.md`](docs/splits.md)), in link order (`src/link-order.txt`). Each function is a block headed `// 0xADDR NAME (SIZE B): matches|equivalent` with its pinned symbol; `tools/tree_tu.py` checks a TU's functions, pins symbols and materializes the tree for builds. The per-function sources in `matches/` and `equivalent/` are frozen at F (still verified, read-only; removing them awaits the maintainer's OK).
- **The Wine build is the development and verification build.** The tree compiles under clang into a 32-bit (i686) Windows image that runs under Wine on the SDL3 platform layer and the pddi/bgfx graphics backend. A live session reaches the first mission with keyboard control, the game's own sound and movies ([`docs/wine-play.md`](docs/wine-play.md)). A change to shared code is proven by a control/proof pair of Wine builds that replay the recorded session `play3` to frame 60,000; `tools/ckpt_gate.py` requires the proof's state checkpoints to agree wherever the control's do ([`docs/wine-build.md`](docs/wine-build.md), [`docs/wine-replay.md`](docs/wine-replay.md), [`docs/compute.md`](docs/compute.md#wine-builds)). The renderer draws the scene but still differs from the original's frames ([`docs/graphics-backend.md`](docs/graphics-backend.md)).
- **Native 64-bit builds compile and link; start-up is being brought up.** The same tree builds for arm64 macOS (`tools/native_mac.py`) and x86-64 Linux / arm64 Android (`tools/native_elf.py`), keeping the MS C++ ABI ([`docs/native-mac.md`](docs/native-mac.md), [`docs/native-android.md`](docs/native-android.md), [`docs/native-build.md`](docs/native-build.md)). Every tree and data TU compiles (the link refuses a failed TU). The links still stub about 22,100 unresolved names per target (down from about 29,000 on 11-10); [`docs/native-unbound-plan.md`](docs/native-unbound-plan.md) sorts them by root cause and fixes them in source, by the thousand where renames suffice. Start-up batches move the macOS image along the start-up path (now past Pure3D's set-up). Each source edit for 64-bit keeps its 32-bit proof (`equiv.py --x64` checks the 64-bit object against the 32-bit one).
- **Equivalence checker** ([`docs/equivalence.md`](docs/equivalence.md)). It runs the original and our code side by side in an emulator and compares calls, memory writes and return values. It has been tightened over 29 rounds, each closing a gap without relaxing a comparison, with 400 regression cases (`tests/equiv/regress.py`). It also checks the clang objects the Wine build runs (`--wine`) and the 64-bit objects (`--x64`); `tools/x87_order.py` finds float arithmetic grouped differently from the original's. Promotions are checked at 3,000 inputs.
- **Trace replay against real game state.** Function-entry state recorded while the original plays in xemu is replayed through the original and our code ([`docs/equivalence.md`](docs/equivalence.md#trace-replay-toolstrace_capturepy-toolsequiv_replaypy)). The game replays deterministically after the new-game load, so a session recorded once (on the hook-only XBE, [`hybrid/`](hybrid/)) is replayed as often as needed, in xemu and by the Wine build.
- **Data as source.** Every byte of `.rdata`/`.data`/`.bss` is inventoried ([`config/data.json`](config/data.json): addresses, kinds, names, owners, no game bytes) and generated as per-object C++ data that byte-matches the XBE ([`docs/data.md`](docs/data.md)). Game data is never committed: the data TUs are generated locally from the player's own XBE (`tools/data_gen.py`), and builds refuse stale generated inputs (`tools/input_guard.py`).
- **Shared headers** recovered from RTTI, hand-maintained source since 2026-11-13: 4,244 classes, every vtable and base layout checked against the XBE ([`docs/headers.md`](docs/headers.md)).
- **Platform boundary mapped.** Game code reaches the Xbox through 182 XDK/kernel/D3D/DirectSound functions in four seams (pure3d's D3D backend, radcore's platform layer, audio, Bink) plus 8 small functions ([`docs/platform-boundary.md`](docs/platform-boundary.md)); `src/platform/sdl/` reimplements them over SDL3, bgfx and FFmpeg (loaded at runtime for Bink movies).
- **Lua scripts mapped.** Missions are Lua 5.1-era bytecode; a lister and an inventory of the 749 C++ bindings the scripts call are in [`docs/lua-scripts.md`](docs/lua-scripts.md).
- **Two versions, one tree.** The faithful port is the 2005 game, exact and replay-checked; a later *remaster* may change rendering and gameplay behind flags ([`docs/remaster.md`](docs/remaster.md)). Online co-op for the remaster is designed and prototyped on the Wine build (lockstep and rollback sessions, a signalling Worker in `net/worker/`; [`docs/multiplayer.md`](docs/multiplayer.md)), and **paused** while the native builds come up. Widescreen and 60 fps options exist in the Wine build's platform layer ([`docs/wine-widescreen-60fps.md`](docs/wine-widescreen-60fps.md)).
- **Shared compute queue.** Equivalence batches, regression suites, Wine builds and replays go through `tools/jobq.py`, which spreads jobs over the build hosts by free capacity; the laptop takes only graphics runs ([`docs/compute.md`](docs/compute.md)).
- **Retired:** the model farm (matching and equivalence by cheap models; [`farm/`](farm/) is kept for its pitfall recipes in `farm/src/prompt.ts`), patching our functions into the XBE for a hybrid build in xemu (`hybrid/` now only records), the CPU permuter, and `build_tree.py` as the build's source (`HULK_TREE_SOURCE=0` still selects it).
- **Terms.** The *Wine build* is the 32-bit clang image run under Wine (`tools/wine_*.py`, `docs/wine-*.md`, `HULK_WINE_*`; the old `native_*` names, `--native` and `HULK_NATIVE_*` remain as aliases). *Native* means the 64-bit builds for the supported targets.

## Layout

| Path | What |
|---|---|
| `src/game/`, `src/engine/`, `src/platform/xbox/` | the merged tree: one TU per recovered object, a block per function (edit functions here) |
| `src/platform/sdl/` | the SDL3 platform layer: XDK/CRT shims, audio, input, files, movies, the pddi/bgfx graphics backend |
| `include/` | `common.h`, `tree_prelude.h`, tree headers (`game/`, `engine/`, `platform/xbox/`), `gen/` (classes from RTTI), `decls/` (addresses, data declarations), `compat/` |
| `matches/`, `equivalent/` | per-function sources, frozen at F (read-only) |
| `config/` | `splits.json` (object ranges), `data.json` (data inventory, no game bytes) |
| `tools/` | every script: checkers (`compare.py`, `verify_relocs.py`, `equiv.py`), `tree_tu.py`, builds (`wine_*.py`, `native_mac.py`, `native_elf.py`), the queue (`jobq.py`) |
| `tests/` | checker regression cases and backend tests |
| `hybrid/` | hooks for recording sessions in xemu |
| `docs/` | design notes; [`docs/journal.md`](docs/journal.md) is the findings log, [`docs/roadmap.md`](docs/roadmap.md) the plan |
| `build/`, `isos/` | local only, never committed: compilers, Ghidra, venv, the extracted disc, generated data |

## Working on a function

Run from the repo root with `build/venv/bin/python`:

```sh
tools/packet.py show 0xADDR                                    # asm, Ghidra hint, referenced data
tools/compare.py src/.../TU.cpp 0xADDR                         # MATCH, or an aligned diff against the XBE
tools/verify_relocs.py src/.../TU.cpp --addr 0xADDR --json     # every reference hits the right symbol
tools/equiv.py src/.../TU.cpp 0xADDR --json [--wine | --x64]   # differential execution (promotion: --inputs 3000)
tools/tree_tu.py check src/.../TU.cpp --relocs                 # every function of a TU
tools/tree_tu.py pin .                                         # after an edit that changes a symbol
tools/progress.py --readme                                     # the status table above and the treemap
```

A `matches` block must still compile to the original's bytes with its references correct; an `equivalent` block needs a fresh passing `equiv.py` run. Heavy jobs go through the queue ([`docs/compute.md`](docs/compute.md)).

## How it got here

1. **Recon:** XBE parsing, XDK library IDs (XbSymbolDatabase), RTTI recovery (4,244 classes, 13k virtual functions named in Ghidra), and object boundaries from link order.
2. **Matching at scale:** each function got a context packet (symbolized asm, class, vtable, Ghidra's C). A farm of cheap models, with one tool that compiled a candidate under wibo and diffed it, matched most small functions; identical code shapes reused a verified match without a model (18k small functions collapse to 6.4k shapes). Near-misses that clustered on one symptom got one deep investigation, and the fix became a recipe (the vtable-store-order recipe turned 13 stuck functions into about 700 matches overnight).
3. **Equivalence:** large functions were written for readability and proven by `tools/equiv.py`, by models and Claude subagent batches; families of near-identical functions were proven in bulk by generators ([`tools/equiv_gen/`](tools/equiv_gen/)). Verified bytes went from 21% on 10-10 to ~100% by 10-19.
4. **The tree:** sources were moved onto shared headers and merged into per-object TUs, then committed as the source of truth (2026-11-10).

Details: [`docs/toolchain.md`](docs/toolchain.md), [`docs/farm.md`](docs/farm.md), [`docs/source-tree.md`](docs/source-tree.md), [`docs/journal.md`](docs/journal.md), [`docs/prior-art.md`](docs/prior-art.md).

## Roadmap

Full plan: [`docs/roadmap.md`](docs/roadmap.md).

- [x] Toolchain: matching compiler on macOS, Ghidra + RTTI, compare loop, reference verification
- [x] Asset tools: RCF unpack/repack, P3D → PNG/glTF
- [x] **1. Map the platform boundary**: XDK/kernel/D3D calls from game code; render/camera/HUD/game-loop subsystems
- [ ] **2. Shared headers and real types/names**: headers generated and verified; the tree is merged and committed. Open: the remaining stub classes, real types where the 64-bit build needs them, real names.
- [x] **3. Source for every game function**: byte-matched where cheap, proven equivalent for large ones (table above).
- [ ] **4. Data**: inventory and byte-verified data TUs done; sources are being wired onto the named items ([`docs/data.md`](docs/data.md)).
- [x] **5. Test harness in xemu**: deterministic recording and replay of real sessions, checkpoints against the original, trace replay. (Patching our functions into the XBE was retired at the flip; the Wine build's replays took its place.)
- [ ] **6. Wine build, then native builds**: the Wine build plays into the first mission and gates every change by replay; the 64-bit builds for x86-64 SteamOS, arm64 macOS and arm64 Android handhelds compile and link, with the unbound names and start-up in progress ([`docs/native-unbound-plan.md`](docs/native-unbound-plan.md)).
- [ ] **7. Make it better**: widescreen and 60 fps options in the Wine build; higher resolution, HD textures and models, and the remaster later.

## Setup

Needs macOS or Linux, Python 3.12+ and Node 22+. See [`docs/toolchain.md`](docs/toolchain.md).

```sh
xdvdfs unpack <your-iso> isos/extracted           # cargo install xdvdfs-cli
tools/pull_compiler.py win32/msvc7.1 build/compilers/msvc7.1
tools/setup_ghidra.sh                             # Ghidra + XBE loader + RTTI import
build/venv/bin/python tools/compare.py experiments/first-matches/refcount.cpp 0x18b40
```

Building the Wine image: [`docs/wine-build.md`](docs/wine-build.md) (`tools/wine_build_job.py` runs a whole build as one queue job). Native builds: [`docs/native-mac.md`](docs/native-mac.md), [`docs/native-build.md`](docs/native-build.md).

Clean-room: no leaked source (e.g. the Simpsons: Hit & Run leak, which shares this engine) or leaked XDK material is used or accepted.
