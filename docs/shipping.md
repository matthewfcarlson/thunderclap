# From verified functions to a shipped port

How the per-function sources become a source tree, how the port reaches players on macOS, the Steam
Deck and Windows, and how modding works. Each section names the roadmap step it belongs to ([roadmap.md](roadmap.md)).
Written 2026-10-12; nothing here is built yet unless it says so.

## 1. The source tree (roadmap steps 2 and 4)

Today every file in `matches/` and `equivalent/` is its own translation unit. It declares just enough
for one function: stub structs, `extern "C" FUN_xxx` callees and `DAT_xxx` globals. A real tree needs
three things.

**Which file each function lives in.** The XBE has no `__FILE__` paths or `.cpp` names (checked), but
link order survives. MSVC emits an object file's functions contiguously and the linker places objects
in link order. Measured on the 12,919 game functions that RTTI names, the 4,185 owning classes form
only **1.74 contiguous runs per class** in address order. The unnamed functions between those runs
almost certainly belong to the surrounding file. [Task 05](tasks/05-split-recovery.md) turns this into
`config/splits.json`: estimated object ranges with evidence. Files are named after their dominant class
(`CChaseCamera.cpp`), with a directory per namespace (`pure3d/`, `core/`, `fight/`, `hulkfight/`,
`physics/`, `audio/`, …) as in `include/gen/`. A wrong cut is cheap, because codegen doesn't depend on
the file a function sits in.

**Shared declarations.** Merging translation units surfaces conflicts: the same callee declared with
different signatures, or the same struct with different padding. Each conflict is a real type to pin
down or a mistake in one of the two files. `include/gen/` already defines the 4,244 RTTI classes with
layouts checked against the XBE. Migrating matches onto it is roadmap step 2.

**Two builds over one tree.**
- *Verification build:* MSVC 7.1 under wibo, one object per recovered file. Every function is
  re-checked: byte-match for `matches/` (objdiff/`compare.py`), behaviour for `equivalent/` (`equiv.py`,
  trace replay). This keeps the merged tree honest as it's refactored.
- *Native build:* the same tree under clang. Unverified functions are holes. The hybrid build covers them
  with the original code; a native build can't, so it needs step 3 finished.

**Platform layers (decided 2026-10-14).** One tree builds the Xbox game and the native ports. Pure3D/radcore
was a multi-platform engine and every platform call goes through four seams ([platform-boundary.md](platform-boundary.md)),
so the tree is split by layer, not only by namespace:

```
src/game/…            portable game code (global C* classes, hulkfight, game-side sound logic, Lua bindings, front end, …)
src/engine/…          portable Pure3D / radcore / radsound / Lua / choreo2 / fight / physics (sim) code
src/platform/xbox/    our decomp of the Xbox seam implementations: pddi D3D8, radcore Xbox layer, radsound HAL, Bink player
src/platform/sdl/     native backends: SDL3 input, audio and files; pddi on Metal / Vulkan / D3D12 (SDL_gpu or bgfx)
src/platform/sdl/xdk/ the first of them: stand-ins for the 167 XDK/XAPI/Bink imports, so the native build can run
                      platform/xbox before the seams have SDL3 backends (started 2026-10-18, native-build.md), the
                      library code/data the game reaches by address (library.h) and the entry point (startup.cpp)
src/platform/sdl/crt/ the host C runtime of the first (Windows / Wine) image: msvcrt.dll through our own import
                      tables (host_crt_table.h) and our glue (/GS cookie, atexit, stdio, game paths)
include/seams/        the seam interfaces both platform directories implement
```

- **Xbox:** `game` + `engine` + `platform/xbox` under MSVC 7.1. The working-game route is the hybrid build:
  our objects patched into the player's own XBE, so Microsoft's XDK libraries and Bink come from their disc
  and are never shipped. A full relink would need the XDK, which isn't ours to distribute. Running
  identically on Xbox is the test that `game` and `engine` are right before any native backend exists.
- **macOS, Windows, Linux:** `game` + `engine` + `platform/sdl` under clang (MSVC also works on Windows).
- **Pointer size:** the first native build is 32-bit x86 (roadmap step 4), because `.p3d` chunks, Lua
  bytecode and saves bake in 32-bit pointers and sizes. 64-bit (Apple Silicon, modern Windows) comes later
  with widening loaders.
- **First native target (decided 2026-10-17): `i686-pc-windows-msvc`, built with clang-cl and linked with
  lld-link**, run on Windows x86 or under Wine. The verified code is MS-ABI code (stub classes whose vftable
  slots assume one slot per virtual destructor, hand-written vptr stores and slot calls, `__thiscall`), and the
  link binds calls by MS-mangled name aliases ([native-build.md](native-build.md) fixes 0 and 5a). Linux and
  macOS (Itanium ABI) follow once callers use the real include/gen classes (fix 5b). Native flags:
  `-fms-extensions -fno-strict-aliasing -fwrapv -fno-delete-null-pointer-checks`, x87 math on 32-bit
  (`-mno-sse -mfpmath=387`), `include/compat/native.h` force-included (it brings `compat/crt.h`, the one
  declaration of each CRT function), and MSVC 7.1's dialect where clang has a switch: `-Xclang -fno-wchar`
  (`/Zc:wchar_t-`), `-fno-operator-names`, `-Wno-c++11-narrowing`, `-Wno-address-of-temporary`
  ([native-build.md](native-build.md#after-fix-4-and-the-binding-fixes-2026-10-18)).
- Each recovered object in `config/splits.json` carries a `layer` (`game`, `engine`, `platform/xbox`,
  `library`); `tools/gen_tree.py` places files by layer. Done 2026-10-15: link order splits game from engine
  cleanly (`fight` and `physics` are linked with Radical's libraries, so they are `engine`), and
  `platform/xbox` is 32 objects, 824 functions ([splits.md](splits.md#layers)). What the portable layers call
  in it, per seam: [seams.md](seams.md).

**First scaffold** (a good one-agent task):
1. `tools/infer_splits.py` → function-to-file map, committed.
2. Generate `src/<namespace>/<File>.cpp`: verified functions in address order, with a placeholder comment
   for each unverified one.
3. Hoist shared declarations into per-namespace headers, preferring `include/gen/`.
4. Build script for the verification build. Report which files compile and which declaration conflicts
   remain.

## 2. Shipping on macOS (roadmap step 8)

- **Ship code only, never game data.** `Thunderclap.app` contains our arm64 executable and renderer.
- **Bring your own game.** On first launch the app asks for an ISO or extracted folder and checks the
  XBE hash against the supported release. It then extracts the data, with every RCF unpacked into
  folders (see §5), to `~/Library/Application Support/Thunderclap/`. The pieces exist: xISO extraction, and `tools/rcf.py`, which
  reads and rebuilds all 13 RCF archives byte-for-byte.
- **Gatekeeper.** Opening without warnings needs a Developer ID signature and notarization (Apple
  Developer Program). Unsigned builds work with right-click → Open the first time.

## 3. Steam Deck (roadmap step 8)

Only the native port ships to the Deck. Players can already run the original game in xemu without us,
so an xemu-based release adds nothing. The hybrid ISO stays an internal test vehicle (step 5).

- **Native port:** a Linux x86-64 build packaged as an AppImage or Flatpak. Copy the ISO over in Desktop
  Mode, run the app once and point it at the ISO (same first-run flow as macOS), then use "Add to Steam"
  for Game Mode. Input goes through SDL, so Steam Input works with no extra setup. If the repo goes
  public, a Decky/Flathub listing can make it one click, still with bring-your-own ISO.

## 4. Windows (roadmap step 8)

- **Same native port, same first-run flow.** `game` + `engine` + `platform/sdl`, built with clang-cl or MSVC.
  On first launch it asks for the ISO or extracted folder, checks the XBE hash and extracts the data,
  with RCFs unpacked into folders (§5), to `%LOCALAPPDATA%\Thunderclap\`.
- **Packaging:** a zip with the executable and SDL3 DLL; an installer is optional. Renderer backend is D3D12
  (or Vulkan) through the same pddi layer as macOS and Linux.
- **SmartScreen.** Unsigned executables get an "unknown publisher" warning on first run ("More info" →
  "Run anyway"). Removing it needs an Authenticode code-signing certificate; not needed for testing.
- **32-bit first.** The first native build is x86-32 (§1, pointer size), which Windows runs natively; the
  x86-64 build follows with the widening loaders.

## 5. Modding: textures, models, levels (roadmap steps 6 and 7)

Both data formats are mapped already: RCF archives are fully verified ([rcf.md](formats/rcf.md)), and
all 1,436 `.p3d` files parse, with Hulk and a downtown room exported correctly ([p3d.md](formats/p3d.md)).

| Mechanism | What it replaces | Needs | Step |
|---|---|---|---|
| **Repacked RCFs** | any file, in the game's own format | `tools/rcf.py` (done) | tooling for testing mods against the original in xemu; not a shipped path |
| **Loose-file overrides** | any file: drop a replacement at the same path under `mods/` and the file layer reads it before the RCF | a check in the port's radcore file shim | 6: part of the OS shim |
| **Texture replacement by hash** | textures at any resolution, as PNGs, without touching `.p3d` | the renderer hashes each texture on upload and looks for `mods/textures/<hash>.png` (as in Dolphin and PCSX2 texture packs) | 7: in the new `pddi` backend |
| **Model import** | meshes, skins, levels | a `.p3d` writer (the exporter in reverse) and a Blender export path | 7: tooling |

The hash scheme is the best route for HD texture packs: modders never need to understand `.p3d`, and
it keeps working as the renderer changes.
Existing Dolphin (GameCube) packs map onto the Xbox textures by p3d path and name (2,325 of 2,334 for the one tested); key scheme, Dolphin hash and converter in [texture-packs.md](texture-packs.md).

**Extracted data, not RCFs (decided 2026-10-14).** The native port's first run unpacks every RCF into a
plain folder tree (`data/art/…`, `data/misc/…`), and the radcore file shim reads files from that folder;
RCFs aren't read at runtime. Adding content is then adding files: a new mission is
`art/missions/<id>/<id>_init.lua` and `<id>.lua` (plain-text Lua loads, since `DoFile` 0x001d3600 compiles
text and bytecode alike), and a new area is a new `art/locations/<dir>/`. `mods/` stays as an overlay on top
of `data/`, so mods never edit the player's extracted copy. Open points from [lua-scripts.md](lua-scripts.md):
missions are registered in `misc/init.lua` (`AddValidMission`/`SetMissionInfo`, 128-entry tables), which a mod
shouldn't have to replace, so the port should run each `mods/*/init.lua` after the game's own; whether the
hard-coded mission tables in `.rdata` also gate a new id; and the `.fig` container format, which scenario
logic lives in.

## The legal line

We distribute our source and binaries only. Game data always comes from the player's own copy, checked
by hash and extracted locally. No assets are committed or bundled (the repo's standing rule), and the
leaked SHAR source is never used (clean-room).
