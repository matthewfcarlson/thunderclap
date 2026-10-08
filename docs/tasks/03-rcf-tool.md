# 03: RCF archive tool

## Goal
A standalone tool to list, extract and (later) repack the game's `.rcf` archives. It's the foundation for texture, model, audio and movie work, and needs no code decomp.

## Context
- Files in `isos/extracted/`: `art.rcf` (366 MB), `districts.rcf`, `rooms.rcf`, `misc.rcf`, `nis.rcf`, `sound*.rcf`, `movies*.rcf`, `mog_mov*.rcf`. Mount order is in `rcfs.txt`.
- Header magic: `"ATG CORE CEMENT LIBRARY"` (Radical's radcore "Cement" format, also used by *Simpsons: Hit & Run*). First bytes of `misc.rcf`:
  ```
  00: "ATG CORE CEMENT LIBRARY" + NUL padding to 0x20
  20: 02 01 00 01  3c 00 00 00  b0 1f 00 00  00 20 00 00
  30: b4 ac 00 00  00 00 00 00  a4 02 00 00  d7 4f 00 00
  40: 00 28 a8 00  5e 00 00 00  df fa 25 00  00 a8 9b 00 ...
  ```
  This looks like a version, then offsets/sizes of a directory and a name table, followed by (hash, offset, size) entries.
- Public references: Luigi Auriemma's radcore/RCF notes and QuickBMS scripts, and Donut Team docs for SHAR (cited by github.com/Vheissu/hit-and-run-web). Use format docs only, never the leaked SHAR source.
- The game code that reads these lives in the XBE. Search RTTI/strings for `radcore`/cement/file classes to confirm field meanings if docs are unclear.

## Deliverables
1. `tools/rcf.py` with `list <file.rcf>` (name, offset, size, hash) and `extract <file.rcf> <outdir>`, keeping directory structure from the name table.
2. Format notes in `docs/formats/rcf.md` (header fields, directory entry layout, name table, alignment, hashing if any).
3. A summary of contents per archive (file counts and extensions) appended to `docs/journal.md`.
4. Stretch: `repack` that reproduces an archive **byte-identically** from its extracted files (round-trip test). That's the prerequisite for mods.

## Done when
- `list` and `extract` work on all 13 archives; extracted file counts match the directory counts.
- Round-trip tests skip cleanly when `isos/extracted/` is missing.
- No extracted data is committed (outputs go under `build/` or a user-given path).
