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
| Byte-matched (`matches/`) | 21,081 (76.7%) | 784 KB (28.5%) |
| Proven equivalent (`equivalent/`) | 4,564 (16.6%) | 1840 KB (66.9%) |
| **Verified source, total** | 25,645 (93.3%) | 2624 KB (**95.4%**) |
<!-- /status -->

![Treemap of game code in address order, one box per function sized by its bytes: blue is byte-matched, green is proven equivalent, grey is not yet verified](docs/progress-map.svg)

Most matches so far are small functions, so byte coverage is the honest metric. Where things stand (2026-10-14):

- **What's left.** About 3,500 functions (270 KB) are unverified: 3,400 are under 100 bytes and go to a local fine-tuned model (ulk-2 on a second Mac, about 100 matches an hour, $0), and only about 100 are 100 bytes or larger, the hardest functions in the game. Claude subagents work on those and on fixing the equivalence checker. Families of near-identical functions are proved in bulk (`tools/clone_equivalent.py`, generators in [`tools/equiv_gen/`](tools/equiv_gen/)). The port-priority list ([`docs/port-priority.txt`](docs/port-priority.txt), 2,011 functions) is **95% verified**.
- **First source tree.** Link order survives in the XBE, so functions are grouped into recovered object files ([`docs/splits.md`](docs/splits.md)) and generated into a merged tree (`tools/gen_tree.py`), in which every byte-matched function still matches and every equivalent still compiles ([`docs/source-tree.md`](docs/source-tree.md)). The tree is laid out to build both the Xbox game and the native ports from one source ([`docs/shipping.md`](docs/shipping.md)).
- **Lua scripts mapped.** Missions are Lua 5.1-era bytecode; a lister and an inventory of the 749 C++ bindings the scripts can call are in [`docs/lua-scripts.md`](docs/lua-scripts.md), the groundwork for adding missions and areas as plain files.
- **Hybrid build boots.** 14,614 of our functions patched into the original XBE run in xemu through boot, menus and the new-game load, with state checkpoints identical to the original's ([`docs/hybrid-build.md`](docs/hybrid-build.md)). A bisect tool finds the function behind any divergence.
- **Equivalence checker, rounds 3 and 4** ([`docs/equivalence.md`](docs/equivalence.md)). It runs the original and our code side by side in an emulator and compares calls, memory writes and return values. Round 4 fixed five checker bugs (deferred stack cleanups, register-argument callees, epilogue cleanup, pushed zeroed registers, second jump tables) and plants string literals into compared buffers. Every promotion is checked at 3,000 inputs on a second Mac, and a full pass at 12,000 inputs found 12 more wrong sources (now fixed or demoted).
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
- [ ] **2. Shared headers and real types/names**: headers generated and verified; migrating matches onto them is next. *ETA: ~1 week of agent time once started (estimate, no rate yet).*
- [ ] **3. Source for every game function**: byte-matched where cheap, behaviour-verified *equivalent* for large ones. 90% of bytes verified; about 3,500 functions (270 KB) to go, 3,400 of them under 100 bytes for the local matching lane. *ETA: about a week; the small pile finishes by 10-15, then a second pass on its misses.*
  - Port-priority functions (platform seams first): 95% verified.
- [ ] **4. Data**: globals, tables, vtables, strings. *ETA: 3–5 days, mostly tooling (estimate).*
- [ ] **5. Hybrid build in xemu**: boots with 14,614 functions patched in. Next: trace replay of real game state for every equivalent (in progress) so the build only includes equivalents that agree on it, then the full scenario suite ([`docs/tasks/10-hybrid-test-plan.md`](docs/tasks/10-hybrid-test-plan.md)). *ETA: 2–4 days after a replay recording (estimate).*
- [ ] **6. Native build**: x86-32 host first, then x86-64 (SteamOS) and arm64 (macOS). Needs milestones 3 and 4, plus the D3D/audio/input/movie backends. *ETA: 3–6 weeks after milestone 3 (estimate).*
- [ ] **7. Make it better**: widescreen/FOV/60 fps, higher resolution, HD textures and models. *ETA: 1–2 weeks after a native build (estimate).*

ETAs for milestone 3 come from the git history of `matches/` and `equivalent/` (verified bytes: 21% on 10-10 midday, 33% at 11:30 on 10-11, 48% at 09:30 on 10-12, 62% at 10:30 on 10-13, 90% on the evening of 10-14). The others are judgment calls and will be revised once each milestone has a measurable rate.

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
