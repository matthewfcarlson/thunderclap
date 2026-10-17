# Thunderclap

> **Disclaimer.** This is an unofficial, non-commercial fan project. It is not affiliated with, endorsed by or
> sponsored by Marvel, The Walt Disney Company, Radical Entertainment, Vivendi Universal Games, Activision or
> Microsoft. "The Incredible Hulk", "Hulk", "Marvel" and all related names, characters and marks are trademarks
> of their respective owners and are used here only to identify the game this project is compatible with. The
> repository contains no executables, data or assets from the original release; to use it you need your own
> legally obtained copy of the game. Nothing here is offered for sale.

A decompilation of **The Incredible Hulk: Ultimate Destruction** (Xbox, 2005, Radical Entertainment), built with LLM help.

The goal is a **native port**: C++ source we can build for SteamOS, arm64 macOS and Windows, with quality-of-life improvements. Functions are byte-matched against the original compiler (MSVC 7.1, `cl` 13.10.3077) where that's cheap, since a match proves correctness for free. Large functions only need to be proven *equivalent*, by differential execution against the original.

**This repo contains no game code or assets. You need your own copy of the game.**

## Status

<!-- status -->
| | Functions | Bytes |
|---|---|---|
| Game code (`.text`, excluding XDK/CRT/Bink) | 27,477 | 2.75 MB |
| Byte-matched (`matches/`) | 21,795 (79.3%) | 803 KB (29.2%) |
| Proven equivalent (`equivalent/`) | 5,238 (19.1%) | 1921 KB (69.9%) |
| **Verified source, total** | 27,033 (98.4%) | 2724 KB (**99.1%**) |
<!-- /status -->

![Treemap of game code in address order, one box per function sized by its bytes: blue is byte-matched, green is proven equivalent, grey is not yet verified](docs/progress-map.svg)

Most matches so far are small functions, so byte coverage is the honest metric. Where things stand (2026-10-16):

- **What's left.** About 1,100 functions (79 KB) are unverified. 1,099 are under 100 bytes; every one has had a matching attempt from the cheap-model lane, so the next pass is equivalence mode or the next local fine-tuned model. Only 7 are 100 bytes or larger: checker limits, one that waits for trace replay, and one that isn't a function. Families of near-identical functions are proved in bulk (`tools/clone_equivalent.py`, generators in [`tools/equiv_gen/`](tools/equiv_gen/)).
- **Source tree on shared headers.** Link order survives in the XBE, so functions are grouped into recovered object files ([`docs/splits.md`](docs/splits.md)) and generated into a merged tree (`tools/gen_tree.py`) laid out by layer (game, engine, platform/xbox) to build both the Xbox game and the native ports ([`docs/shipping.md`](docs/shipping.md)). 9,159 sources now use the shared headers instead of private stubs, and 77% of functions sit in merged files; every byte-matched function still matches and every equivalent still compiles to the same code ([`docs/source-tree.md`](docs/source-tree.md)).
- **Data as source.** Every byte of `.rdata`/`.data`/`.bss` is inventoried ([`config/data.json`](config/data.json): addresses, kinds, names, owners, no game bytes), and 18,832 items are generated as per-object C++ data that byte-matches the XBE, with pointers checked as references to the right targets ([`docs/data.md`](docs/data.md)). Game data is never committed: the data files are generated locally from the player's own XBE.
- **Lua scripts mapped.** Missions are Lua 5.1-era bytecode; a lister and an inventory of the 749 C++ bindings the scripts can call are in [`docs/lua-scripts.md`](docs/lua-scripts.md), the groundwork for adding missions and areas as plain files.
- **Hybrid build boots.** 14,614 of our functions patched into the original XBE run in xemu through boot, menus and the new-game load, with state checkpoints identical to the original's ([`docs/hybrid-build.md`](docs/hybrid-build.md)). A bisect tool finds the function behind any divergence.
- **Equivalence checker, round 10** ([`docs/equivalence.md`](docs/equivalence.md)). It runs the original and our code side by side in an emulator and compares calls, memory writes and return values. Recent rounds steer inputs through float compares, `__ftol2`, byte-table switches and flags, and keep runaway loops, list walks and vector-bound loops short, without ever relaxing a comparison; each change has regression cases (135) and must catch every known-bad mutant the previous round caught. Every promotion is checked at 3,000 inputs on a second Mac (20,000 for fixes). A full re-check of all 4,593 equivalents under round 8, plus the paths rounds 9 and 10 newly reach, found 10 wrong sources; all are fixed and re-checked.
- **Trace replay: equivalence checked against real game state.** Function-entry state is recorded while the original game plays in xemu, then replayed through the original and our code, with each callee returning what it really returned ([`docs/equivalence.md`](docs/equivalence.md#trace-replay)). 706 equivalents have been replayed against real calls and agree; replay has caught about 20 bugs that 3,000 fuzzed inputs passed (mostly callees writing more than our locals hold). Each equivalent gets a confidence tier, and the hybrid build and bisect can be limited to replay-verified functions. A new promotion is replayed in seconds.
- **Record once, replay forever.** The game replays deterministically after the new-game load (the opening movie made the game loop run away; timers and the sound code's random numbers are now pinned). A person can record a session at full speed (`tools/hybrid_test.py record`, analog inputs quantized so recordings stay small) and captures replay it as often as needed, several xemu instances side by side.
- **Recipes beat retries.** Near-misses that cluster on one symptom get one deep investigation; the fix goes into the agent brief and farm prompt and is applied by cheaper models and scripts. The vtable-store-order recipe turned 13 stuck functions into about 700 matches overnight ([`docs/journal.md`](docs/journal.md)).
- **A second Mac (mac1)** runs the promotion checks, full re-checks of `equivalent/` (`tools/equiv_batch.py`), trace captures and replays. The permuter found nothing in 70 near-misses there, so it's retired.
- **Platform boundary mapped.** Game code reaches the Xbox through 182 XDK/kernel/D3D/DirectSound functions, all in four seams (pure3d D3D backend, radcore platform layer, audio, Bink) plus 8 small functions ([`docs/platform-boundary.md`](docs/platform-boundary.md)). 16:9 and 720p are built in, the 30 fps cap is one flag, and intros can be skipped ([`docs/subsystems.md`](docs/subsystems.md)).
- **Shared headers** generated from RTTI: 4,244 classes in 17 headers, with every vtable and base layout checked against the XBE ([`docs/headers.md`](docs/headers.md)).

## How it works

1. **Recon:** XBE parsing, XDK library IDs (XbSymbolDatabase), and RTTI recovery: 4,244 classes, 13k virtual functions named in Ghidra.
2. **Packets:** each function gets a precomputed context file with symbolized asm, its class and vtable, and Ghidra's C as a hint.
3. **Farm:** cheap models (GPT-6 Luna first) run on [pi-durable](https://github.com/earendil-works/pi/tree/main/packages/durable). There are many parallel, crash-resumable conversations, each with one tool that compiles a candidate under wibo and diffs it against the original. Spend is hard-capped.
4. **Propagation:** functions with identical code shape reuse a verified match without calling a model. 18k small functions collapse to 6.4k shapes.

5. **Equivalence:** a large function passes when `tools/equiv.py` finds no behavioural difference from the original across fuzzed and directed inputs. It runs in the farm (`--mode equiv`) and in Claude subagent batches ([`docs/agents/equiv-brief.md`](docs/agents/equiv-brief.md)), and results go to `equivalent/`.

Details: [`docs/toolchain.md`](docs/toolchain.md), [`docs/farm.md`](docs/farm.md), [`docs/journal.md`](docs/journal.md) (findings log), [`docs/prior-art.md`](docs/prior-art.md).

## Roadmap

Full plan: [`docs/roadmap.md`](docs/roadmap.md).

- [x] Toolchain: matching compiler on macOS, Ghidra + RTTI, compare loop
- [x] Matching farm with cost controls; model benchmark (GPT-6 Luna: 65% on 32–96-byte functions at ~$0.002/match)
- [x] Reference verification: relocations must hit the right symbols
- [x] Asset tools: RCF unpack/repack, P3D → PNG/glTF
- [x] **1. Map the platform boundary**: XDK/kernel/D3D calls from game code; render/camera/HUD/game-loop subsystems
- [ ] **2. Shared headers and real types/names**: headers generated and verified; 9,159 sources migrated onto them (tree 77% merged). Next: constructors in the headers, the remaining stub classes, real names.
- [ ] **3. Source for every game function**: byte-matched where cheap, behaviour-verified *equivalent* for large ones. 97% of bytes verified; about 1,100 functions (79 KB) to go, all but 7 under 100 bytes.
  - Port-priority functions (platform seams first): 95% verified.
- [ ] **4. Data**: globals, tables, vtables, strings. Inventory and byte-verified data files done; wiring sources onto the named items is in progress.
- [ ] **5. Hybrid build in xemu**: boots with 14,614 functions patched in. Next: trace replay of real game state for every equivalent (in progress) so the build only includes equivalents that agree on it, then the full scenario suite ([`docs/tasks/10-hybrid-test-plan.md`](docs/tasks/10-hybrid-test-plan.md)). *ETA: 2–4 days after a replay recording (estimate).*
- [ ] **6. Native build**: x86-32 host first, then x86-64 (SteamOS) and arm64 (macOS). Needs milestones 3 and 4, plus the D3D/audio/input/movie backends. *ETA: 3–6 weeks after milestone 3 (estimate).*
- [ ] **7. Make it better**: widescreen/FOV/60 fps, higher resolution, HD textures and models. *ETA: 1–2 weeks after a native build (estimate).*

ETAs for milestone 3 come from the git history of `matches/` and `equivalent/` (verified bytes: 21% on 10-10 midday, 33% at 11:30 on 10-11, 48% at 09:30 on 10-12, 62% at 10:30 on 10-13, 90% on the evening of 10-14, 97% on 10-16). The others are judgment calls and will be revised once each milestone has a measurable rate.

## Setup

Needs macOS or Linux, Python 3 and Node 22+. See [`docs/toolchain.md`](docs/toolchain.md).

```sh
xdvdfs unpack <your-iso> isos/extracted           # cargo install xdvdfs-cli
tools/pull_compiler.py win32/msvc7.1 build/compilers/msvc7.1
tools/setup_ghidra.sh                             # Ghidra + XBE loader + RTTI import
build/venv/bin/python tools/compare.py experiments/first-matches/refcount.cpp 0x18b40
```

**Match by hand:** `build/venv/bin/python tools/workbench/server.py`, then open http://127.0.0.1:8765. Pick a function (near-misses first). It shows the best earlier model attempt in an editor next to the aligned target/ours assembly diff, plus a C++ diff, Ghidra's decompilation and data context, and a CPU permuter button. A byte-identical, reference-checked result is installed into `matches/`, committed and pushed automatically.

Clean-room: no leaked source (e.g. the Simpsons: Hit & Run leak, which shares this engine) is used or accepted.
