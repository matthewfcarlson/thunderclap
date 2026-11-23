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
python3 -I tools/texpack_convert.py pack <pack dir> isos/extracted --name NAME   # -> <mods>/NAME/ (the app's pack)
python3 -I tools/texpack_convert.py keys isos/extracted <dump>/keys.txt           # sink keys vs a HULK_PACK_DUMP list
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

The app (and any renderer of the port) keys a texture by **what its draw sink receives at upload**
([remaster.md 2.7](remaster.md), option A of D9; wpack1):

`tex-<key>`, **key = XXH64 (seed 0) of le32 format, le32 width, le32 height and the level-0 bytes**, 16 lowercase hex
digits. Format is the sink's (draw_sink.h `SinkTextureFormat`): 0 BGRA8 (A8R8G8B8 in memory), 1 BC1, 2 BC2, 3 BC3.

- A **DDS** payload reaches the sink as its blocks as stored (DXT1 -> BC1, DXT3 -> BC2, DXT5 -> BC3): the key is
  computed from the ImageData payload directly (`texpack_convert.py` `sink_upload`).
- A **PNG** payload is decoded by the game into the 32-bit layout the lock describes, **rows flipped** (bottom row
  first), exactly as the GameCube loader does. Settled by experiment (wpack1): of the textures a session uploaded
  (624 keys over 8,000 frames of start-up, menus and the first mission), 574 DDS payloads match as stored, 42 PNG
  payloads match with rows flipped and none as stored; the other 8 are run-time textures. So on both consoles every
  texture is uploaded bottom row first.
- The `map.json` / `out/<payload key>.png` files of `map` / `convert` keep the older payload key (the mip-0 ImageData
  bytes): it is what links a pack file to an Xbox texture; `pack` turns it into the sink key.

Why a content hash and not `p3d path + texture name`:
- Texture names are not unique (`waterOS.bmp.0`, the same name with different contents in different
  districts), and the same texture is repeated across many files (2,361 matched pairs collapse to 2,308
  keys), so the path scheme would need duplicates and still be ambiguous.
- It works for any load path (loose-file overrides, new levels, `mods/` overlays) without the renderer
  knowing which file a texture came from, the same model Dolphin and PCSX2 packs use.
- Hashing at the sink needs no hook in the game: the renderer sees every upload (and the game never sees the
  replacement).
- If a mod replaces the texture data itself, the key changes, so an HD replacement never lands on art it
  wasn't made for.

**Orientation**: replacement PNGs are in **upload order** (the first row of the file is the first row uploaded, i.e.
the bottom of the art as authored), as the DDS payloads store them and as Dolphin dumps them, so `pack` hard-links
the Dolphin pack's PNGs unchanged. `HULK_PACK_DUMP` writes the same order.

`map.json` keeps, per pack file: status, the GC texture(s) (rcf, p3d, texture, size, format, mips) and
the Xbox target(s) (key, rcf, p3d, texture, payload type, match kind, similarity).

## Override packs in the app (wpack1)

```
<mods>/<pack>/pack.json                  name, kinds, count (informative)
<mods>/<pack>/textures/tex-<key>.png     any size, RGBA/RGB/palettized PNG, upload order
<mods>/<pack>/textures/index.txt         optional: "tex-<key> <file>" lines (read instead of listing the folder)
<mods>/<pack>/models/mdl-<key>.obj       model overrides (below)
```

`<mods>` is `HULK_MODS_DIR`, else `<app dir>/mods` (`~/Library/Application Support/HulkUD/mods`). Every folder of
`<mods>` with textures or models is a pack (at most 11). **Video Options > Texture Pack: Off / <pack folder names>**
(port_settings.c `texture_pack`, remastered-only; the remastered default is the first pack in name order, Off when
none is installed). The value saved is the FNV-1a hash of the folder name, so the choice survives packs being added.
`HULK_TEXPACK=0` ignores packs; replays and tests start with it Off like every remastered setting (pin it with
`HULK_SETTINGS=remastered=1,texture_pack=<hash>`).

How it works (run/app/texpack.cpp, all in the runner):
- At start the packs are indexed by file name (no image opened): 0.7 ms for the 2,308-file pack.
- At each level-0 upload the runner hashes the level and looks the key up. On a hit the replacement is made in the
  sink beside the original and put in the vid's place; the original stays alive and keeps receiving the module's
  levels, so a pack switched off or changed in the menu goes back at once, and a draw that counts for an occlusion
  query samples the original (the pixel counts the game reads never depend on a pack).
- Decoding is lazy and off the runner's thread: the first upload of a key queues a job (stb_image, bimg's copy), the
  original is drawn until it is done (usually the next frame), then it is swapped in between frames. The replacement
  takes the original's format family with a full mip chain made by the runner (box filter): DXT1 -> BC1 (opaque when
  the original never uses 3-colour transparent texels, else 1-bit alpha), DXT3/DXT5 -> BC3, 32-bit -> BGRA8; a size
  that is not a multiple of 4 stays BGRA8. The sampler state comes from the draw, so wrap / clamp / filtering and
  alpha test and blend are the original's. Never replaced: linear textures (pddi formats 11/12: movie frames) and
  render targets.
- Encoded replacements stay in a CPU cache (`HULK_TEXPACK_CACHE_MB`, default 384, least recently used dropped), so a
  rollback restore or a reload of the same level swaps them in without decoding.
- Encoded replacements are also kept on disk (wr2): `<app dir>/cache/textures/tex-<key>-<hash>.bin`, the hash over the
  image's path, size and modification time, the original's format and alpha use and the encoder's knobs (an edited
  image is built again). The disk cache is capped at `HULK_TEXPACK_DISK_MB` (default 2048; 0 turns it off; least
  recently used files go first, down to 90%); `HULK_TEXPACK_DISK_DIR` moves it. With the Dolphin pack the scripted
  run's decode + encode went from 3.1 s (first launch: 324 files, 68 MB written) to 0.14 s of reading (the next).
- Knobs: `HULK_TEXPACK_LOG=1` (index, each decode, a summary every 5 s with the disk cache's reads and writes),
  `HULK_TEXPACK_THREADS`, `HULK_TEXPACK_MAX` (largest side kept, default 4096: larger images skip their top levels),
  `HULK_TEXPACK_RAW=1` (BGRA8, no BC encoding).

Measured with the converted Dolphin pack (laptop, Metal, the 8,000-frame scripted run: start-up, menus, the first
mission's start): 381 swaps of 363 distinct replacements, 2.6 s of decode + encode spread over the worker threads
(about 7 ms a texture, none on the runner's thread), 68 MB of encoded replacements in the CPU cache and 41.5 MB on the
GPU; frame rate unchanged (56 vs 52 frames/s unpaced). Checks: checkpoint records (`HULK_CKREF`) byte-identical to the
same run without a pack; `HULK_ROLLTEST` identical with the pack on at 6500:7600 (gameplay) and 1200:2500 (front end).

### Making a pack

1. `HULK_PACK_DUMP=<folder>` (any run of the app) writes `<folder>/keys.txt` (one line per key the session uploaded
   or drew: `tex-<key> format width height mips pddi_format ordinal replaced`, and `mdl-<key> flags prim vertices
   indices draw_count`), `<folder>/textures/tex-<key>.png` (level 0 decoded, upload order) and
   `<folder>/models/mdl-<key>.obj`. `HULK_PACK_DUMP=<file>.txt` writes only the list. Everything dumped is the
   player's own game data: keep it on their machine, never share or commit it.
2. Paint over a dumped PNG at any size (keep the row order: open, edit, save) and save it as
   `<mods>/<pack>/textures/tex-<key>.png`. Pick the pack in Video Options > Texture Pack.
3. From a Dolphin pack: `map`, then `texpack_convert.py pack <pack dir> isos/extracted --name NAME` writes
   `<mods>/NAME/textures/` (hard links to the pack's files, index.txt, pack.json); `keys <xbox dir> keys.txt` checks
   the converter's keys against a dump.

### One-file packs (wpkg1)

`texpack_convert.py bundle <mods>/NAME <xbox dir> OUT.hulkpack [--payload baked|png|both]` writes a pack folder as
one file: a disc pack (tools/disc_pack.py; read through run/disc.h) of its textures/ tree. Put it in `<mods>` (or in
the app bundle with `wasm_app.py bundle --with-texpack`): Video Options > Texture Pack lists it by its file name
without `.hulkpack`, beside the loose folders, which work as before. With `--payload baked` (the default) the file
holds `textures/baked/tex-<key>-<format>-<alpha>.bin` for every key: the replacement the app itself would make (the
disk cache's layout), made offline by tools/texbake.cpp, which compiles run/app/texpack.cpp's own encoder (`build()`),
for the original's format and alpha use, which the tool reads off the Xbox texture the key comes from (DXT1: opaque
or 1-bit, as texpack.cpp decides). The app uses a baked replacement as it is, so the pixels are the same as from the
PNG and there is no decode or encode at run time; a key without one (or `HULK_TEXPACK_MAX` / `HULK_TEXPACK_RAW` set)
falls back to the PNG if the file has it. `--payload png` stores the PNGs only (the app decodes and encodes as for a
folder, with the disk cache keyed by the pack file).

Formats compared (the converted "Hulk Final Remaster" pack, 2,308 textures):

| | size | load (per texture, CPU) | quality |
|---|---|---|---|
| PNG folder (today) | 605 MB | decode + BC encode: 2,291 ms for 352 textures (6.5 ms each) | the app's BC1/BC3/BGRA8 encode |
| PNG, one file | ~605 MB (PNG does not compress) | the same | the same |
| baked BC1/BC3/BGRA8 + mips, zstd, one file | 280 MB (579 MB raw) | read + zstd: 110 ms for the same 352 (0.3 ms each) | identical to today (same encoder, same bytes) |
| BC7 + mips | 519 MB raw (before zstd) | read | better than BC1 at 2x its size; Apple silicon Macs only (Metal BC); most Android GPUs lack BC |
| ASTC 4x4 / 6x6 / 8x8 + mips | 519 / 234 / 130 MB raw | read | 4x4 ~ BC7; 6x6 smaller, softer; Apple silicon (Metal) and Android GPUs both |

(Load: the 8,000-frame scripted run, noop renderer, no disk cache; the same 361 swaps and 41.5 MB of replacements
either way. BC7/ASTC sizes are computed from the baked chains' level sizes: no encoder was run.)

Recommendation: the baked one-file pack. It is the smallest file that needs no new code path in the sink (BC1 / BC3 /
BGRA8 are what the sink already takes), it shows exactly the pixels the PNG folder shows, and a texture costs a read
instead of an encode. BC7 brings nothing here: 1,621 of the 2,308 replacements are BC1 (0.5 byte a pixel), so BC7 (1
byte) would be about as big as the baked set, and many Android GPUs lack BC. ASTC is the one format both Apple
silicon (Metal) and the Android handhelds sample natively, and 6x6 would make the raw set ~40% of the baked one; it
needs a new sink format (src/platform/sdl/pddi: a shared-layer change) and an encoder (ARM's astcenc, Apache 2.0),
so it is a decision for later, worth taking if BC textures turn out unsupported or slow on the handhelds' GPUs
(not checked here: the emulator test ran without a pack).

### Models (the minimal version)

`<mods>/<pack>/models/mdl-<key>.obj` replaces one prim buffer's geometry at its draws (run/app/meshpack.cpp).
Key: XXH64 of le32 vertex flags, le32 prim kind, le32 vertex count and the vertices in the game's packed layout
(`SinkVertexData::packed`), remaster.md 2.7's `mdl`. The draw keeps its transform, shader, textures, render state
and (skinned groups) bone matrices; only the vertex and index buffers are the replacement's. Not replaced: prim
streams (particles, billboards) and draws an occlusion query counts.

- **Format**: Wavefront OBJ (`v`, `vt`, `vn`, `f`; polygons are fanned; at most 65,535 vertices), in the original's
  model space as the dump writes it: z negated and the winding reversed (so it reads right-handed in a modelling
  tool), `vt` v = 1 - the game's v (the dumped PNG then lies the right way up). Position, the first UV set and the
  normal come from the OBJ; every other attribute (vertex colours, which carry the world's baked lighting; the second
  UV set of `layered` shaders; skin weights and palette indices) is taken from the original vertex nearest each new
  vertex.
- **Static meshes** (props, rooms, HUD models) work as they are: keep the replacement over the original's surface
  and its baked lighting follows.
- **Skinned meshes** work within one prim group: each new vertex follows the bones of its nearest original vertex,
  with the draw's own palette (at most 25 bones), so a replacement must stay inside the volume its group covers. The
  full plan (remaster.md 4, R5: glTF skinned by joint name from the `.p3d` Skeleton/MatrixPalette, a manifest
  replacing a whole character's groups, suppressing groups) needs the offline joint-name map and the instance tags.
- Checked: a test pack scaling every skinned group of the first mission by 1.3 and dropping half the HUD models'
  triangles drew as expected; checkpoint records byte-identical to the run without it. Collision, animation and the
  shadow volumes stay the game's (shadows are separate meshes: replace their keys too).

For a Dolphin pack, players run `texpack_convert.py map`, then `pack`, against their own disc and pack; nothing is
bundled.
