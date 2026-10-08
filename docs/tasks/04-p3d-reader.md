# 04: Pure3D `.p3d` reader

## Goal
Parse the game's Pure3D files (meshes, textures, skeletons, animations) into an inspectable form, with export to standard formats. This is the path to HD texture packs and model swaps.

## Context
- Pure3D is Radical's engine (RTTI namespace `pure3d`, 251 classes, e.g. `pure3d::Shader`, `pure3d::Animation`, `pure3d::pddiBaseContext`). `.p3d` files are a **chunk tree** (chunk ID, data size, total size incl. children), documented publicly for *Simpsons: Hit & Run* by Donut Team (LuaP3DLib, P3D editor). Donut Team's editor opens *some* Hulk UD files, so expect version differences and Hulk-specific chunks.
- Input comes from task 03 (`tools/rcf.py extract`).
- Loader classes in the XBE (`content::LoadInventory`, `DynamicCaster<pure3d::*>`, `*Loader` classes) map chunk IDs to types. Their constants are good ground truth for unknown chunk IDs.

## Deliverables
1. `tools/p3d.py dump <file.p3d>`: indented chunk tree (ID, name when known, sizes, key fields), tolerant of unknown chunks.
2. Decoders for the high-value chunks: textures/images to PNG (identify Xbox swizzle and DXT formats), meshes to glTF or OBJ, skeletons.
3. `docs/formats/p3d.md`: chunk ID table with "Hulk-specific / differs from SHAR" notes and evidence (file offsets, loader addresses).
4. A stats summary across all `.p3d` files in the RCFs: chunk ID histogram, and unknown chunks ranked by frequency.

## Done when
- `dump` handles every `.p3d` in the extracted RCFs without crashing (unknown chunks are reported, not fatal).
- At least textures export to viewable PNGs, and one character mesh (Hulk) exports to glTF that opens in Blender.
- No extracted or converted game assets are committed.
