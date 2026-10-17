# HD texture packs (Dolphin packs on the Xbox data)

Community HD texture packs for this game exist only for the GameCube version, as Dolphin custom-texture
packs. This page records how such a pack is mapped onto the Xbox textures the port loads, so the native
renderer can use it (hash-keyed texture replacement, [shipping.md §5](shipping.md)).

Tools: `tools/gc_disc.py` (reads the GameCube disc and its RCFs in place) and `tools/texpack_convert.py`
(Dolphin names, the mapping, and the converter). Both run only on the user's own files: their GameCube
disc, the pack they downloaded, and their Xbox data. Nothing derived from any of them is committed;
`map.json` and the output stay under `build/texpack/`.

**Licensing.** The pack tested here (*The Incredible Hulk: Ultimate Destruction RE*, "6. Hulk Final
Remaster", 2,334 PNGs) ships with no license file. The port treats packs like this as a user-installed
mod only: never bundled, mirrored, or linked from a release or the repo without the author's permission.

## Usage

```
python3 -I tools/texpack_convert.py map  <gc.ciso> <pack dir> isos/extracted     # -> build/texpack/map.json
python3 -I tools/texpack_convert.py convert <gc.ciso> <pack dir> isos/extracted  # -> build/texpack/out/<key>.png
python3 -I tools/texpack_convert.py names <gc.ciso>                              # Dolphin name of every GC texture
python3 tools/gc_disc.py list <gc.ciso>
```

Run with `-I`: the pack is untrusted input and is only ever opened as PNG data by Pillow. Needs numpy
and Pillow; uses the `xxhash` module when installed (a pure-Python XXH64 fallback is built in but slow).
Unzip a pack into its own new directory first. A full `map` run takes about 20 s.

## The GameCube disc

- **CISO container**: `"CISO"`, u32 block size (LE, 0x200000 here) at +4, then a 0x7ff8-byte map, one byte
  per disc block (1 = present); present blocks follow the 0x8000-byte header in order.
- **Disc**: standard GameCube layout, game id `GHUE7D`; FST at 0x424/0x428 of `boot.bin`. Ten files:
  `art.rcf`, `misc.rcf`, `movies.rcf`, `nis.rcf`, `sound_en.rcf`, `rcfs.txt`
  (`art.rcf,misc.rcf,movies.rcf,nis.rcf`), `args.txt`, banner/icon files.
- **RCF**: the same format as on Xbox ([rcf.md](formats/rcf.md)) with version bytes `02 01 01 01`:
  byte [2] = 1 marks a **big-endian header and directory**; the name table stays little-endian and the
  filename hash is unchanged. There are no `districts.rcf`/`rooms.rcf`: the GC `art.rcf` holds the
  location districts and rooms under the same `art\locations\…` paths that the Xbox splits into
  `districts.rcf` and `rooms.rcf`. Paths are otherwise identical, which is what makes the path match work.

## GameCube `.p3d` textures

The GC `.p3d` files are the Xbox format ([p3d.md](formats/p3d.md)), still little-endian, with the same
Texture 0x19000 / Image 0x19001 / ImageData 0x19002 chunks (one Image per mip level, largest first).
Differences:

- ImageData holds the same kind of payload, a **DDS or PNG file**, not GX data. The GameCube build converts
  at load time. GC DDS files are **DXT1 only**; where Xbox uses DXT3/DXT5 the GC file is a palettized PNG.
- Many GC textures are half the Xbox size (of 2,369 mapped Xbox texture instances, 1,312 have the same width as the GC one, 1,056 twice it).
- 356 Texture chunks (mostly `bonus\…` and some `nischars_*`) store their Texture/Image header fields
  big-endian (version reads 0x36b0 byte-swapped) while the chunk headers stay little-endian.

What the GC build uploads to GX, verified by reproducing Dolphin hashes (below):

| ImageData payload | GX format | Conversion |
|---|---|---|
| DDS DXT1 | CMPR (14) | DXT1 blocks regrouped into 8x8 tiles (2x2 blocks: TL, TR, BL, BR), the two RGB565 colours byte-swapped to big-endian, and the four 2-bit indices in each byte reversed. Rows as stored. |
| PNG, palettized | C8 (9) | 8-bit indices in 8x4 tiles; TLUT in **RGB5A3**, big-endian: opaque form `1rrrrrgggggbbbbb` when alpha >= 0xE0, else `0aaarrrrggggbbbb`. **Image flipped vertically.** |
| PNG, RGB / RGBA | RGBA8 (6) | 4x4 tiles, 32 bytes of A,R pairs then 32 bytes of G,B pairs. **Image flipped vertically.** |

The flip puts PNG textures in the same bottom-row-first order the DDS files already use (see the
DDS orientation note in [p3d.md](formats/p3d.md)), so on GX every texture is bottom row first.

## The Dolphin texture hash (verified)

From Dolphin's source (custom texture naming in the texture cache / `HiresTexture`):

```
tex1_<W>x<H>[_m]_<XXH64(base level)>[_<XXH64(tlut range)>]_<GX format>.png
```

- `W`x`H`: the base level's size. `_m` when the texture has mip levels (here: the Texture has more than one Image).
- Texture hash: XXH64, seed 0, over the **base level only**, in GX memory layout (the encoded size for the
  format, dimensions padded to whole blocks), printed as 16 lowercase hex digits.
- TLUT hash (paletted formats; only C8 occurs here, C4/C14X2 follow the same rule per Dolphin's source): XXH64, seed 0, over the palette entries **from the smallest to the largest
  index the base level actually uses**, i.e. bytes `[2*min, 2*(max+1))` of the big-endian TLUT.
- Format: the GX texture format number in decimal (CMPR 14, C8 9, RGBA8 6, IA8 3, ...).

**Match rate: 2,333 of the pack's 2,334 names reproduced exactly** (texture hash, TLUT hash, size, `_m`
and format), from 8,773 GC textures (2,727 distinct names). The pack is 1,649 CMPR, 589 C8, 95 RGBA8 and
1 IA8. The one miss is `tex1_4x4_…_3` (IA8, 4x4): no `.p3d` texture is IA8, so it is a texture the engine
builds at run time, not one that ships on the disc.

## Mapping to the Xbox textures

For each reproduced pack name, the GC texture(s) with that name give `(p3d path, texture name)`; the Xbox
texture with the same texture name in the `.p3d` at the same path is its counterpart. Results for this pack:

| | Pack files |
|---|---|
| matched by p3d path + texture name | **2,325** (2,361 pack→Xbox pairs; 2,308 distinct Xbox keys, of 2,732 distinct Xbox textures) |
| matched by texture name only (any `.p3d`) | 0 (not needed) |
| matched by image similarity | 0 |
| no Xbox counterpart | 8: the GameCube controller glyphs in `frontend\art\feglobal.p3d` (`GC_A/B/X/Y/L/R.TGA`, `GC_LEFTJOYSTICK`, `GC_RIGHTJOYSTICK`); the Xbox has no such textures, and the image search (same aspect ratio, all Xbox textures) correctly finds nothing close |
| no GC texture | 1: the run-time IA8 texture above |

Image similarity (16x16 premultiplied RGBA thumbnails, mean absolute difference over 0..255) is the
fallback for names that don't match, and is also stored per pair in `map.json` as a check: median 6.8,
90th percentile 12.9; the high outliers are particle and flare textures the pack author restyled. The
orientation check (comparing both flips) never disagreed with the rule below by more than noise.

The Xbox formats behind the matches (per texture instance): DXT1 → CMPR 1,674; DXT5/DXT3 → C8 530;
DXT5 → CMPR 3; RGB PNG → RGBA8 72; RGBA PNG → C8 64 / RGBA8 24; palettized PNG → C8 2. 52 Xbox textures are claimed by two pack files (the same art at two
sizes or formats in different GC files); the converter keeps the larger image.

## Key scheme for the port

`mods/textures/<key>.png`, where **key = XXH64 (seed 0) of the Xbox texture's mip-0 ImageData payload**
(the DDS/PNG file bytes after ImageData's u32 size), as 16 lowercase hex digits.

Why a content hash and not `p3d path + texture name`:
- Texture names are not unique (`waterOS.bmp.0`, the same name with different contents in different
  districts), and the same texture is repeated across many files (2,361 matched pairs collapse to 2,308
  keys), so the path scheme would need duplicates and still be ambiguous.
- It works for any load path (loose-file overrides, new levels, `mods/` overlays) without the renderer
  knowing which file a texture came from, the same model Dolphin and PCSX2 packs use.
- The bytes are already in hand in the Image loader; hashing them is cheap and stable across renderer
  changes (unlike hashing decoded or GPU-converted pixels).
- If a mod replaces the texture data itself, the key changes, so an HD replacement never lands on art it
  wasn't made for.

**Orientation**: replacement PNGs are in **upload order, bottom row first**, as the DDS payloads store
them and as Dolphin dumps them, so the converter copies pack PNGs unchanged. For Xbox textures whose
payload is a PNG this assumes the Xbox loader flips PNGs as the GC one does (proven on GC by the hashes;
the thumbnail check agrees, but the Xbox image loader's PNG path has not been read yet).

`map.json` keeps, per pack file: status, the GC texture(s) (rcf, p3d, texture, size, format, mips) and
the Xbox target(s) (key, rcf, p3d, texture, payload type, match kind, similarity).

## Loading packs in the native renderer

1. At startup, index `mods/textures/*.png` (and subfolders) by the 16-hex-digit file name; ignore other files.
2. When the Image loader creates a texture, hash mip 0's ImageData payload with XXH64 and look it up.
3. On a hit, decode the PNG (upload order, any size, RGBA) and use it in place of the original, generating
   mips if the original had them; UVs are normalized, so a 4x upscale needs no other change. Keep the
   original's sampler state (wrap, filter) and treat alpha as the original format's alpha usage.
4. Optionally a `dump` mode writing `<key>.png` for every texture loaded, so modders can make new packs
   directly against the Xbox data.

For a Dolphin pack, players run `texpack_convert.py convert` once against their own disc and pack and
copy `build/texpack/out/` into `mods/textures/`.
