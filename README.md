# hulk-ultimate-recomp

A matching decompilation of **The Incredible Hulk: Ultimate Destruction** (Xbox, 2005, Radical Entertainment), built with LLM help.

The goal is C++ source that compiles with the original compiler (MSVC 7.1, `cl` 13.10.3077) to byte-identical machine code, function by function, and eventually relinks into the original `default.xbe`.

**This repo contains no game code or assets. You need your own copy of the game.**

## Status

<!-- status -->
| | Functions | Bytes |
|---|---|---|
| Game code (`.text`, excluding XDK/CRT/Bink) | 23,049 | 2.60 MB |
| Byte-matched (`matches/`) | 14,331 (62.2%) | 457 KB (**17.5%**) |
<!-- /status -->

Most matches so far are small functions. Byte coverage is the honest metric.

## How it works

1. **Recon:** XBE parsing, XDK library IDs (XbSymbolDatabase), and RTTI recovery: 4,244 classes, 13k virtual functions named in Ghidra.
2. **Packets:** each function gets a precomputed context file with symbolized asm, its class and vtable, and Ghidra's C as a hint.
3. **Farm:** cheap models (GPT-6 Luna first) run on [pi-durable](https://github.com/earendil-works/pi/tree/main/packages/durable). There are many parallel, crash-resumable conversations, each with one tool that compiles a candidate under wibo and diffs it against the original. Spend is hard-capped.
4. **Propagation:** functions with identical code shape reuse a verified match without calling a model. 18k small functions collapse to 6.4k shapes.

Details: [`docs/toolchain.md`](docs/toolchain.md), [`docs/farm.md`](docs/farm.md), [`docs/journal.md`](docs/journal.md) (findings log), [`docs/prior-art.md`](docs/prior-art.md).

## Roadmap

Full plan: [`docs/roadmap.md`](docs/roadmap.md).

- [x] Toolchain: matching compiler on macOS, Ghidra + RTTI, compare loop
- [x] Matching farm with cost controls; model benchmark (GPT-6 Luna: 65% on 32–96-byte functions at ~$0.002/match)
- [ ] **1. Match every function**: sweep ≤96-byte shapes, then large functions
- [ ] **2. Verify references**: relocations must hit the right symbols
- [ ] **3. Shared headers and real types/names**
- [ ] **4. Original source files**: splits, data, csplit + objdiff, decomp.dev
- [ ] **5. Relink** to a SHA-1-identical `default.xbe`
- [ ] **6. Make it better**: widescreen/FOV/60 fps, higher resolution, RCF/P3D asset tools, HD textures and models, native PC port. Much of this can start early via xemu, a hybrid patch build, and standalone asset tools.

## Setup

Needs macOS or Linux, Python 3 and Node 22+. See [`docs/toolchain.md`](docs/toolchain.md).

```sh
xdvdfs unpack <your-iso> isos/extracted           # cargo install xdvdfs-cli
tools/pull_compiler.py win32/msvc7.1 build/compilers/msvc7.1
tools/setup_ghidra.sh                             # Ghidra + XBE loader + RTTI import
build/venv/bin/python tools/compare.py experiments/first-matches/refcount.cpp 0x18b40
```

Clean-room: no leaked source (e.g. the Simpsons: Hit & Run leak, which shares this engine) is used or accepted.
