# hulk-ultimate-recomp

A decompilation of **The Incredible Hulk: Ultimate Destruction** (Xbox, 2005, Radical Entertainment), built with LLM help.

The goal is a **native port**: C++ source we can build for SteamOS, arm64 macOS and Windows, with quality-of-life improvements. Functions are byte-matched against the original compiler (MSVC 7.1, `cl` 13.10.3077) where that's cheap, since a match proves correctness for free. Large functions only need to be proven *equivalent*, by differential execution against the original.

**This repo contains no game code or assets. You need your own copy of the game.**

## Status

<!-- status -->
| | Functions | Bytes |
|---|---|---|
| Game code (`.text`, excluding XDK/CRT/Bink) | 27,450 | 2.69 MB |
| Byte-matched (`matches/`) | 16,181 (58.9%) | 615 KB (22.8%) |
| Proven equivalent (`equivalent/`) | 1,520 (5.5%) | 681 KB (25.3%) |
| **Verified source, total** | 17,701 (64.5%) | 1297 KB (**48.1%**) |
<!-- /status -->

Most matches so far are small functions, so byte coverage is the honest metric. Where things stand (2026-10-11):

- **Progress rate.** Verified source went from 21% to 33% of game-code bytes in the last 24 hours (about 300 KB/day), mostly from Claude Sonnet subagents proving large functions *equivalent* (about 17 of every 20 attempted pass). The port-priority list ([`docs/port-priority.txt`](docs/port-priority.txt), 2,011 functions) is **84% verified**.
- **Hybrid build boots.** 14,614 of our functions patched into the original XBE run in xemu through boot, menus and the new-game load, with state checkpoints identical to the original's ([`docs/hybrid-build.md`](docs/hybrid-build.md)). A bisect tool finds the function behind any divergence.
- **Equivalence checker, round 2** ([`docs/equivalence.md`](docs/equivalence.md)). It runs the original and our code side by side in an emulator and compares calls, memory writes and return values. It now also catches what the hybrid build found: callees writing past an undersized local, hidden return values, wrong calling conventions and dropped arguments. Every file in `equivalent/` passes it.
- **Recipes beat retries.** Near-misses that cluster on one symptom get one deep investigation; the fix goes into the agent brief and farm prompt and is applied by cheaper models and scripts. The vtable-store-order recipe turned 13 stuck functions into about 700 matches overnight ([`docs/journal.md`](docs/journal.md)).
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
- [ ] **3. Source for every game function**: byte-matched where cheap, behaviour-verified *equivalent* for large ones. 33% of bytes verified; 5,718 functions (1.68 MB) to go. *ETA: about 1 week at the current ~300 KB/day if the agents keep running; 2–3 weeks more realistically, since the remaining functions are larger (321 over 1 KB) and ~10% hit checker limits or are library code.*
  - Port-priority functions (platform seams first): 84% verified. *ETA: 1–2 days.*
- [ ] **4. Data**: globals, tables, vtables, strings. *ETA: 3–5 days, mostly tooling (estimate).*
- [ ] **5. Hybrid build in xemu**: boots with 14,614 functions patched in. Next: a recorded gameplay replay to make post-load scenarios deterministic, then the full scenario suite ([`docs/tasks/10-hybrid-test-plan.md`](docs/tasks/10-hybrid-test-plan.md)). *ETA: 2–4 days after a replay recording (estimate).*
- [ ] **6. Native build**: x86-32 host first, then x86-64 (SteamOS) and arm64 (macOS). Needs milestones 3 and 4, plus the D3D/audio/input/movie backends. *ETA: 3–6 weeks after milestone 3 (estimate).*
- [ ] **7. Make it better**: widescreen/FOV/60 fps, higher resolution, HD textures and models. *ETA: 1–2 weeks after a native build (estimate).*

ETAs for milestone 3 come from the git history of `matches/` and `equivalent/` (verified bytes: 21% on 10-10 midday, 26% at midnight, 30% at 06:00, 33% at 11:30 on 10-11). The others are judgment calls and will be revised once each milestone has a measurable rate.

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
