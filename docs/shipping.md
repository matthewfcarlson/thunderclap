# From verified functions to a shipped port

How the per-function sources become a source tree, how the port reaches players on macOS and the Steam
Deck, and how modding works. Each section names the roadmap step it belongs to ([roadmap.md](roadmap.md)).
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

**First scaffold** (a good one-agent task):
1. `tools/infer_splits.py` → function-to-file map, committed.
2. Generate `src/<namespace>/<File>.cpp`: verified functions in address order, with a placeholder comment
   for each unverified one.
3. Hoist shared declarations into per-namespace headers, preferring `include/gen/`.
4. Build script for the verification build. Report which files compile and which declaration conflicts
   remain.

## 2. Shipping on macOS (roadmap step 8)

- **Ship code only, never game data.** `Hulk.app` contains our arm64 executable and renderer.
- **Bring your own game.** On first launch the app asks for an ISO or extracted folder and checks the
  XBE hash against the supported release. It then extracts the data to
  `~/Library/Application Support/<app>/`. The pieces exist: xISO extraction, and `tools/rcf.py`, which
  reads and rebuilds all 13 RCF archives byte-for-byte.
- **Gatekeeper.** Opening without warnings needs a Developer ID signature and notarization (Apple
  Developer Program). Unsigned builds work with right-click → Open the first time.

## 3. Steam Deck (roadmap steps 5 and 8)

- **Today, no port needed:** xemu on the Deck (e.g. via EmuDeck), with your own dump plus BIOS, MCPX and
  HDD files. Copy them by SD card, USB or `scp` in Desktop Mode, then add xemu as a non-Steam game. The
  hybrid ISO (our code patched into the original XBE) runs there the same way it does on the Mac.
- **Native port:** a Linux x86-64 build packaged as an AppImage or Flatpak. Copy the ISO over in Desktop
  Mode, run the app once and point it at the ISO (same first-run flow as macOS), then use "Add to Steam"
  for Game Mode. Input goes through SDL, so Steam Input works with no extra setup. If the repo goes
  public, a Decky/Flathub listing can make it one click, still with bring-your-own ISO.

## 4. Modding: textures, models, levels (roadmap steps 5, 6 and 7)

Both data formats are mapped already: RCF archives are fully verified ([rcf.md](formats/rcf.md)), and
all 1,436 `.p3d` files parse, with Hulk and a downtown room exported correctly ([p3d.md](formats/p3d.md)).

| Mechanism | What it replaces | Needs | Step |
|---|---|---|---|
| **Repacked RCFs** | any file, in the game's own format | `tools/rcf.py` (done) | 5: works on the original game and in xemu today |
| **Loose-file overrides** | any file: drop a replacement at the same path under `mods/` and the file layer reads it before the RCF | a check in the port's radcore file shim | 6: part of the OS shim |
| **Texture replacement by hash** | textures at any resolution, as PNGs, without touching `.p3d` | the renderer hashes each texture on upload and looks for `mods/textures/<hash>.png` (as in Dolphin and PCSX2 texture packs) | 7: in the new `pddi` backend |
| **Model import** | meshes, skins, levels | a `.p3d` writer (the exporter in reverse) and a Blender export path | 7: tooling |

The hash scheme is the best route for HD texture packs: modders never need to understand `.p3d`, and
it keeps working as the renderer changes.

## The legal line

We distribute our source and binaries only. Game data always comes from the player's own copy, checked
by hash and extracted locally. No assets are committed or bundled (the repo's standing rule), and the
leaked SHAR source is never used (clean-room).
