# hulk-ultimate-recomp

A decompilation of **The Incredible Hulk: Ultimate Destruction** (Xbox, 2005, Radical Entertainment), built with LLM help.

The goal is a **native port**: C++ source we can build for SteamOS, arm64 macOS and Windows, with quality-of-life improvements. Functions are byte-matched against the original compiler (MSVC 7.1, `cl` 13.10.3077) where that's cheap, since a match proves correctness for free. Large functions only need to be proven *equivalent*, by differential execution against the original.

**This repo contains no game code or assets. You need your own copy of the game.**

## Status

<!-- status -->
| | Functions | Bytes |
|---|---|---|
| Game code (`.text`, excluding XDK/CRT/Bink) | 22,615 | 2.53 MB |
| Byte-matched (`matches/`) | 15,465 (68.4%) | 552 KB (21.8%) |
| Proven equivalent (`equivalent/`) | 280 (1.2%) | 81 KB (3.2%) |
| **Verified source, total** | 15,745 (69.6%) | 633 KB (**25.0%**) |
<!-- /status -->

Most matches so far are small functions, so byte coverage is the honest metric. Where things stand:

- **Platform boundary mapped.** Game code reaches the Xbox through 182 XDK/kernel/D3D/DirectSound functions. All of those calls sit in four seams (the pure3d D3D backend, the radcore platform layer, audio, Bink movies) plus 8 small functions ([`docs/platform-boundary.md`](docs/platform-boundary.md)). Everything else only uses the portable C runtime.
- **QoL hooks located** ([`docs/subsystems.md`](docs/subsystems.md)). 16:9 and 720p are already built in. The 30 fps cap is a single flag (two vblank waits per frame) and the game timestep is variable. Intros can be skipped by setting one counter.
- **Shared headers** generated from RTTI: 4,244 classes in 17 headers, with every vtable and base layout checked against the XBE ([`docs/headers.md`](docs/headers.md)).
- **Equivalence checker working** ([`docs/equivalence.md`](docs/equivalence.md)). It runs the original and our code side by side in an emulator and compares calls, memory writes and return values. It passes all 300 sampled matches and catches 334 of 338 deliberately broken copies.
- **First large functions proven equivalent.** Sonnet subagents got 30 of 40 port-priority functions of 200–700 bytes to pass. The 10 failures were checker limitations, now being fixed. Byte-matching got 0 of 51 over 400 bytes.
- **Port priority list** ([`docs/port-priority.txt`](docs/port-priority.txt)): 2,011 functions (228 KB), platform seams first, 25% verified by bytes.

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
- [ ] **2. Shared headers and real types/names**: headers generated and verified; migrating matches onto them is next
- [ ] **3. Source for every game function**: byte-matched where cheap, behaviour-verified *equivalent* for large functions (checker and farm mode done; scaling up)
- [ ] **4. Data**: globals, tables, vtables, strings
- [ ] **5. Hybrid build in xemu**: integration test, first QoL patches
- [ ] **6. Native build**: x86-32 host first, then x86-64 (SteamOS) and arm64 (macOS)
- [ ] **7. Make it better**: widescreen/FOV/60 fps, higher resolution, HD textures and models

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
