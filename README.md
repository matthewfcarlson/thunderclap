# The Incredible Hulk: Ultimate Destruction, decompiled

A decompilation of *The Incredible Hulk: Ultimate Destruction* (Xbox, 2005), aimed at a **native port**: C++ source
built for **x86-64 SteamOS**, **arm64 macOS** and **arm64 Android handhelds** (Windows is not a target). Every game
function has verified source, either byte-matched against the original compiler (MSVC 7.1, `cl` 13.10.3077) or proven
*equivalent* to the original by differential execution.

**This repository contains no game code, data or assets.** You need your own copy of the game disc: every build step
reads the game's files from your extracted disc, and the generated data never leaves your machine.

## Status

<!-- status -->
| | Functions | Bytes |
|---|---|---|
| Game code (`.text`, excluding XDK/CRT/Bink) | 27,437 | 2.73 MB |
| Byte-matched (`: matches` blocks) | 22,701 (82.7%) | 1014 KB (37.2%) |
| Proven equivalent (`: equivalent` blocks) | 4,735 (17.3%) | 1714 KB (62.8%) |
| **Verified source, total** | 27,436 (100.0%) | 2727 KB (**100.0%**) |
<!-- /status -->

![Treemap of game code in address order, one box per function sized by its bytes: blue is byte-matched, green is proven equivalent, grey is not yet verified](docs/progress-map.svg)

Bytes are the honest metric (most matches are small functions). The one address without a block, 0x0035c5b0, is 304
bytes of data, not a function. XDK, CRT, D3D and Bink library code is not counted.

- **Source:** one merged tree (`src/`) holds every game function, one translation unit per recovered object file
  ([`docs/merge-once.md`](docs/merge-once.md)). Data is inventoried and regenerated from your XBE
  ([`docs/data.md`](docs/data.md)); class headers come from RTTI ([`docs/headers.md`](docs/headers.md)).
- **Wine build** (development and verification): the tree compiled as a 32-bit image, run under Wine on our SDL3
  platform layer, plays into the first mission with sound and movies, and every change to shared code is gated by
  replaying a recorded session ([`docs/wine-build.md`](docs/wine-build.md), [`docs/wine-play.md`](docs/wine-play.md)).
- **Native 64-bit builds:** every TU compiles and links for all three targets; start-up is being brought up and the
  remaining unresolved names are being fixed in source ([`docs/native-build.md`](docs/native-build.md),
  [`docs/native-unbound-plan.md`](docs/native-unbound-plan.md)).
- **Later:** a remaster with modern rendering and online co-op is designed and paused
  ([`docs/remaster.md`](docs/remaster.md), [`docs/multiplayer.md`](docs/multiplayer.md)).

The plan and what is left: [`docs/roadmap.md`](docs/roadmap.md).

## Getting started

Needs macOS or Linux, Python 3.12+ (a venv at `build/venv`) and Node 22+. Details: [`docs/toolchain.md`](docs/toolchain.md).

```sh
xdvdfs unpack <your-iso> isos/extracted                     # your own disc (cargo install xdvdfs-cli)
tools/pull_compiler.py win32/msvc7.1 build/compilers/msvc7.1  # MSVC 7.1, run through wibo
tools/setup_ghidra.sh                                       # Ghidra, the XBE loader, RTTI import
build/venv/bin/python tools/data_inventory.py && build/venv/bin/python tools/data_gen.py   # data TUs from your XBE
build/venv/bin/python tools/compare.py src/game/hulkfight/unk_0185f0.cpp 0x18b40         # smoke test: prints MATCH
```

## Building and running

| What | How | Docs |
|---|---|---|
| Play the Wine build | `tools/play.py --check`, then `tools/play.py --build` | [`docs/wine-play.md`](docs/wine-play.md) |
| A full Wine build as one queue job | `tools/wine_build_job.py submit` / `wait` | [`docs/wine-build.md`](docs/wine-build.md) |
| arm64 macOS | `tools/native_mac.py compile`, then `link` | [`docs/native-mac.md`](docs/native-mac.md) |
| x86-64 SteamOS / arm64 Android | `tools/native_elf.py compile\|link --target linux-x64\|android-arm64` | [`docs/native-linux.md`](docs/native-linux.md), [`docs/native-android.md`](docs/native-android.md) |
| Unpack RCF archives, read P3D files | `tools/rcf.py`, `tools/p3d.py` | [`docs/formats/`](docs/formats/) |

Run Python tools with `build/venv/bin/python` from the repo root. Heavy jobs go through a shared queue
(`tools/jobq.py`, [`docs/compute.md`](docs/compute.md)).

## Working on a function

```sh
tools/packet.py show 0xADDR                                    # asm, Ghidra hint, referenced data
tools/compare.py src/.../TU.cpp 0xADDR                         # MATCH, or an aligned diff against the XBE
tools/verify_relocs.py src/.../TU.cpp --addr 0xADDR --json     # every reference hits the right symbol
tools/equiv.py src/.../TU.cpp 0xADDR --json [--wine | --x64]   # differential execution (proofs: --inputs 3000)
tools/tree_tu.py check src/.../TU.cpp --relocs                 # every function of a TU
tools/progress.py --readme                                     # regenerate the status table above
```

A function is a block `// 0xADDR NAME (SIZE B): matches|equivalent` in its TU. A `matches` block must still compile to
the original's bytes with correct references; an edited `equivalent` block needs a fresh proof
([`docs/equivalence.md`](docs/equivalence.md)). Contributor and agent rules are in [`CLAUDE.md`](CLAUDE.md).

## Layout

| Path | What |
|---|---|
| `src/game/`, `src/engine/`, `src/platform/xbox/` | the game: one TU per recovered object, a block per function |
| `src/platform/sdl/` | the SDL3 platform layer: XDK/CRT shims, audio, input, files, movies, the bgfx graphics backend |
| `include/` | shared headers: `gen/` (classes from RTTI), `decls/` (addresses, data), tree headers |
| `config/` | object splits and the data inventory (addresses and names only, no game bytes) |
| `tools/` | checkers, builds, the job queue, asset tools |
| `tests/` | checker regression cases and platform-layer tests |
| `hybrid/` | hooks for recording sessions in xemu |
| `net/worker/` | the co-op signalling Worker (paused) |
| `docs/` | design notes; [`docs/journal.md`](docs/journal.md) is the findings log |
| `build/`, `isos/` | local only, never committed: compilers, venv, your extracted disc, generated data |

## More

- How it was done: recon from RTTI and link order, matching small functions at scale, proving the large ones
  equivalent, then merging everything into one tree ([`docs/journal.md`](docs/journal.md),
  [`docs/toolchain.md`](docs/toolchain.md), [`docs/farm.md`](docs/farm.md), [`docs/prior-art.md`](docs/prior-art.md)).
- Platform boundary: what the game calls in the Xbox and how the port replaces it
  ([`docs/platform-boundary.md`](docs/platform-boundary.md), [`docs/graphics-backend.md`](docs/graphics-backend.md)).
- MSVC 7.1 matching recipes: [`docs/msvc71-pitfalls.md`](docs/msvc71-pitfalls.md).

## Clean room

No leaked source (e.g. the *Simpsons: Hit & Run* leak, which shares this engine) or leaked XDK material is used or
accepted. Microsoft and RAD library code (XDK, CRT, D3D, Bink) is reimplemented from its interfaces and the game's call
sites, never decompiled; Bink movies play through FFmpeg loaded at runtime.
