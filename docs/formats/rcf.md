# RCF ("ATG CORE CEMENT LIBRARY") format notes

Status: **fully verified.** `tools/rcf.py verify` rebuilds all 13 shipped archives byte-for-byte from these rules, and every one of the 8,359 names hashes to its directory entry. All values are little-endian.

## Layout
```
0x0000  header (0x3C)
0x003C  directory: count × {hash, offset, size}, sorted by hash
        zero pad to 0x800
names   name table
        zero pad to 0x800
data    files in name-table order, each zero-padded to 0x800 except the last
```

## Header (0x3C bytes)
| Off | Type | Meaning |
|---|---|---|
| 0x00 | char[0x20] | `"ATG CORE CEMENT LIBRARY"` + NUL padding |
| 0x20 | u8[4] | version `02 01 00 01`. The loader (`core::CementLibrary`, 0x277810) requires `[0]==2`, `[1]<=1`, `[2]==0`, `[3]!=0`. |
| 0x24 | u32 | directory offset (always 0x3C) |
| 0x28 | u32 | directory size (12 × count) |
| 0x2C | u32 | name table offset = `align(0x3C + 12*count, 0x800)` |
| 0x30 | u32 | name table size (unpadded) |
| 0x34 | u32 | 0 |
| 0x38 | u32 | file count |

## Directory
`count` × `{u32 hash, u32 offset, u32 size}`, sorted ascending by hash so the game can binary-search it. Offsets are absolute and 0x800-aligned.

## Name table
```
u32 0x800, u32 0                      # table header (alignment, reserved)
count × {
  u32 mtime                           # Unix time of the source file (2005-03 … 2005-06)
  u32 0x800                           # alignment
  u32 0
  u32 len                             # strlen(name) + 1
  char name[len]                      # NUL-terminated, backslash-separated, e.g. "frontend\feconfig.txt"
  u8  pad[3]                          # always zero, records are NOT 4-aligned
}
```
Records are in **data order**: the i-th name is the i-th file in the data area. Names join to directory entries by hash, not by position.

## Filename hash
`FUN_002673d0(const char *s, int seed)` with seed 0:
```c
for (; *s; s++) { int c = (signed char)*s; if (c < 'a') c += 0x20; h = h*31 + c; }
```
This folds `A–Z` onto `a–z`, but it also shifts every other char below `'a'` (`\` becomes `|`, `.` becomes `N`, and so on), so `/` and `\` hash differently. Shipped names all use `\`. `FUN_002673a0` next to it is the same hash without case folding. Found by scanning `.text` for `imul r, r, 0x1f`.

## Repacking
Everything above is determined by the ordered `(name, mtime, bytes)` list and the version word, so `rcf.py extract` saves those in `_rcf.json` and `rcf.py repack` rebuilds the original exactly. To add a file, append it to the manifest; to replace one, overwrite it on disk. The hash must stay unique within an archive (repack checks this).

## Open questions
- Which archive wins when two mounted archives (`rcfs.txt` order) contain the same hash, and whether loose files on disk override them.
- Meaning of version byte `[1]` (0 or 1 allowed; shipped files use 1).
