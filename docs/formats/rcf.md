# RCF ("ATG CORE CEMENT LIBRARY") format notes

Status: header and directory layout inferred from the first 0x48 bytes of `misc.rcf` (internally consistent: `dir_size == 12 * count`, `dir_off == header size`, offsets 0x800-aligned). **The name-table record layout is unverified**; `tools/rcf.py` extracts path-like strings heuristically and joins them to directory entries by `(offset,size)` found in the 16 bytes before each string, else by order. Verify against real archives and tighten.

## Header (0x3C bytes, little-endian)
| Off | Type | Meaning |
|---|---|---|
| 0x00 | char[0x20] | `"ATG CORE CEMENT LIBRARY"` + NUL padding |
| 0x20 | u32 | version/flags (`02 01 00 01` in misc.rcf) |
| 0x24 | u32 | directory offset (0x3C) |
| 0x28 | u32 | directory size in bytes (= 12 × count) |
| 0x2C | u32 | name table offset (0x2000 in misc.rcf) |
| 0x30 | u32 | name table size |
| 0x34 | u32 | reserved (0) |
| 0x38 | u32 | file count |

## Directory
`count` × `{u32 hash, u32 offset, u32 size}`. Offsets are absolute and 0x800-aligned. Hash is presumably a name hash; algorithm unknown (check game code for the cement file-open path).

## Name table
At `names_off`, `names_size` bytes. Expected: one record per file with a path string (likely backslash-separated); exact record header unknown.

## Open questions (resolve with real data)
1. Name-table record layout and ordering vs. directory order.
2. Hash function (needed to repack/add files).
3. Meaning of version word; padding rules between files for byte-identical repack.
