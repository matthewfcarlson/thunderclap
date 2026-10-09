# Pure3D (.p3d) format notes

Status: **spec-first, unverified against Hulk UD files.** Written from memory of the public Donut Team / SHAR format docs (no leaked source). Every claim below needs checking against extracted files and the XBE loader classes.

## File
- 12-byte header: magic `50 33 44 FF` ("P3D\xFF"; byte-swapped `FF 44 33 50` treated as big-endian), `u32` header size (12), `u32` file length.
- Then a sequence of chunks to end of file.

## Chunk
`{u32 id, u32 data_off, u32 total_size}` then `data_off - 12` bytes of chunk-specific data, then child chunks up to `total_size`. `tools/p3d.py` treats `size < 12`, `data_off > size` or overrun as a bad chunk: it reports it and stops that level.

## Chunk IDs (names UNVERIFIED)
| ID | Name |
|---|---|
| 0x7000 | History |
| 0x10000 | Geometry |
| 0x10002 | PrimitiveGroup |
| 0x10005 / 6 / 7 | PositionList / NormalList / UVList |
| 0x1000A | IndexList |
| 0x11000 | Shader |
| 0x19000 / 1 / 2 | Texture / Image / ImageData |
| 0x4500 / 0x4501 | Skeleton / SkeletonJoint |
| 0x121000 | Animation |

## Open questions
1. Do Hulk files use this header, or compression/different magic?
2. Hulk-specific chunk IDs: rank with `p3d.py stats` and match to `*Loader` classes in the XBE.
3. Xbox texture formats (swizzle, DXT) for PNG export, not yet implemented.
4. Mesh primitive and vertex layouts for glTF export, not yet implemented.
