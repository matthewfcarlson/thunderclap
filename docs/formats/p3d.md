# Pure3D (.p3d) format notes

Status: **verified against all 1,436 `.p3d` files** in the 13 RCFs (0 unparsable, 0 bad chunks). Top-level chunk IDs come from the constructors of the XBE's `*Loader` classes; sub-chunk layouts were worked out from the data and checked by exporting Hulk and a downtown room and rendering them (textures, UVs and skin weights all land correctly). All values are little-endian.

## File and chunks
- 12-byte header: magic `P3D\xFF`, `u32` header size (12), `u32` file length.
- Then chunks: `{u32 id, u32 data_size, u32 total_size}`. Both sizes include the 12-byte chunk header; the chunk's own data is `data_size - 12` bytes, and child chunks fill the rest of `total_size`.
- Strings are **pstrings**: `u8 len` + `len` bytes, NUL-padded to a 4-byte multiple in most chunks (shader `TEX` params are an exception: they aren't padded).

## Chunk IDs
Loader-confirmed (ID is a constant in the named loader's constructor):

| ID | Name | Loader |
|---|---|---|
| 0x7000 | History | `IgnoreLoader` |
| 0x2200 | Camera | `CameraLoader` |
| 0x2380 | LightGroup | `LightGroupLoader` |
| 0x10000 | Geometry | `GeometryLoader` |
| 0x10001 | PolySkin | `PolySkinLoader` |
| 0x10019 | ShadowSkin | `ShadowSkinLoader` |
| 0x10023 | ShadowMeshBuffer | `ShadowMeshBufferLoader` |
| 0x11000 | Shader | `ShaderLoader` |
| 0x13000 | Light | `LightLoader` |
| 0x14000 | Locator | `LocatorLoader` |
| 0x1580C | ParticleSystem | `ParticleSystemLoader` |
| 0x17006 | BillboardQuadGroup | `BillboardQuadGroupLoader` |
| 0x19000 | Texture | `TextureLoader` |
| 0x19001 | Image | `ImageLoader` |
| 0x19005 | Sprite | `SpriteLoader` |
| 0x22000 | TextureFont | `TextureFontLoader` |
| 0x23000 | Skeleton | `SkeletonLoader` |
| 0x120100 | Scenegraph | `ScenegraphLoader` |
| 0x121000 | Animation | `AnimationLoader` |
| 0x121201 | FrameController | `FrameControllerLoader` |
| 0x123000 | CompositeDrawable | `CompositeDrawableLoader` |
| 0x7010000 | CollisionObject | `physics::CollisionObjectLoader` |
| 0x7010025 | WorldCollisionObject | `physics::WorldCollisionObjectLoader` |
| 0x7011000 | PhysicsObject | `physics::PhysicsObjectLoader` |
| 0x802000A | StatePropData | `StatePropDataLoader`, `CSPHulkPropLoader` |
| 0x60000700 | Level | `Render::LevelLoader` |
| 0x60000701 | Room | `Render::RoomLoader` |
| 0x60000722 | Transitions | `TransitionsLoader` |
| 0x60000A00 | DataHandlerRaw | `DataHandlerRawLoader` |

The old spec-first guesses were wrong for some of these (Skeleton is 0x23000, not 0x4500; every PrimGroup is 0x10020, never 0x10002).

## Textures
- **Texture 0x19000**: name, `u32 version (14000)`, width, height, bpp, alpha depth, mip count, then three more `u32`s (texture type / usage / priority by analogy; unchecked). Width, height and mip count match the children: one Image per mip level, largest first.
- **Image 0x19001**: name, version, width, height, bpp, palettized, has-alpha, format. Child: ImageData.
- **ImageData 0x19002**: `u32 size` + a complete file: a **DDS** (DXT1 17,917×, DXT3 4,045×, DXT5 3,932×; no uncompressed or swizzled formats) or a **PNG** (1,156×, fonts and some UI).
- DDS rows are stored **bottom-up** relative to how the art was authored: the controller diagram reads correctly only after a vertical flip. Mesh UVs index the rows as stored, so `p3d.py` flips the PNG and uses `v' = 1 - v` in glTF.

## Shaders
**Shader 0x11000**: name, pddi shader name (e.g. `simple`), `u32` flags…, then parameter children, each `char[4] key` + value:
- 0x11002 texture: `TEX\0` (base), `TTEX` (detail/grime), `REFL` (reflection map), then a pstring texture name.
- 0x11003 int: `LIT\0`, `2SID`, `SHMD`, … + `u32`.
- 0x11004 float and 0x11005 colour: key + 4 bytes.

Textures are found **by name across everything loaded**, not just the same file. World rooms (`rooms.rcf`) reference shaders and textures defined in `districts.rcf` (`<area>_district_N.p3d`), so export rooms with `--lib`.

## Meshes
- **Geometry 0x10000**: name, `u32 prim group count` (no version field).
- **PolySkin 0x10001**: name, `u32 version`, skeleton name, `u32 prim group count`.
- **PrimGroup 0x10020**: `u32 version`, shader name, `u32 prim type` (0 tri list, 1 tri strip), `u32 vertex format` (e.g. 0x2191), `u32 vertex count`, `u32 index count`, `u32 matrix count`, …
  Children (all start with `u32 count`):

| ID | Name | Element |
|---|---|---|
| 0x10011 | ? | 1 byte, always 0 so far |
| 0x10005 | PositionList | `float[3]` |
| 0x10006 | NormalList | `float[3]` |
| 0x10007 | UVList | **`u32 channel`** then `float[2]`; rooms carry channels 0 and 1 |
| 0x10008 | ColourList | `u8[4]` D3DCOLOR (B, G, R, A): baked vertex lighting |
| 0x10010 | ? | `u8` per vertex |
| 0x1000A | IndexList | `u32` |
| 0x1000B | MatrixList | `u8[4]` palette slots, **first weight's slot in the top byte** (checked: the top-byte joint is nearest the vertex for 847 / 1015 Hulk vertices, against 10 for the low byte) |
| 0x1000C | WeightList | `float[3]`; the 4th weight is `1 - sum` |
| 0x1000D | MatrixPalette | `u32` skeleton joint index |
| 0x10003 | BoundingBox | `float[6]` (no count) |
| 0x10004 | BoundingSphere | `float[4]` (no count) |

## Skeletons
- **Skeleton 0x23000**: name, `u32` ?, `u32 joint count`, …
- **SkeletonJoint 0x23001**: name, `u32 parent index` (root points at itself), `float[16]` rest matrix relative to the parent, row-major with row vectors (translation in the last row, D3D style). Hulk has 38 joints (`Motion_Root`, `Balance_Root`, `Character_Root`, `Pelvis`, …).
- 0x23003: limb records (`left_leg`, `right_leg`, … + joint indices), probably for IK.

## Animations
Verified on all 14,856 animations: every channel of the decoded types below fills its chunk exactly (283,400 channels), and key frames are strictly increasing.

- **Animation 0x121000**: `u32 version`, name, `char[4] kind`, `f32 frame count`, `f32 frame rate`, `u32 cyclic`. Kinds: `PTRN` (skeletal pose, 5,406), `SPAR`/`SPEM` (particles), `PPTG`/`PPLG`, `BQG`, `CAM`, `VRTX`, `STRN`, `PVIS`, `TEX`, `SHAD`, `PSPG`, `LITE`.
  - 0x121006: per-channel-type key statistics (children 0x121007: `u32 0, u32 channel id, u32 count, u16[]…`). Not needed for playback.
  - **GroupList 0x121002**: `u32 version`, `u32 group count`.
  - **Group 0x121001**: `u32 version`, name, `u32 id`, `u32 channel count`; children are channels. Groups bind to skeleton joints **by name**. The ids are not joint indices (`Wealded_Weap_*` differ between animations). Cutscene (`nis/`) animations name the root group after the character (`hulk`) with id 0; it drives joint 0 (`Motion_Root`).
- **Channels**: `u32 version`, `char[4] param`, [1/2-DOF only: `u16 axis`, `f32[3] constant`], `u32 key count n`, `u16 frame[n]`, then n values. Time = frame / frame rate. Each channel has one child 0x121110 (`u32 version`, `u32` interpolation mode?, often 0xFFFFFFFF).

| ID | Values | Params seen |
|---|---|---|
| 0x121100 | `f32` | many material/particle params (`FOV`, `DIST`, `SPD`, …) |
| 0x121102 Vector1DOF | `f32`: replaces component `axis` of `constant` | `TRAN` |
| 0x121103 Vector2DOF | `f32[2]`: the two components other than `axis`, which keeps `constant` | `TRAN`, `LOOK`, `UP` |
| 0x121104 Vector3DOF | `f32[3]` | `TRAN` (local translation; matches the rest pose exactly), `LOOK`, `UP`, `TRA` |
| 0x121105 Quaternion | `f32[4]` x, y, z, w | `ROT` |
| 0x121111 | `s16[4]` x, y, z, w / 32767 | `ROT` |
| 0x121112 | `s16[3]` x, y, z / 32767; w = √(1−x²−y²−z²) | `ROT` (cutscenes) |
| 0x121114 | `s8[3]` x, y, z / 127; w derived | `ROT` (gameplay; the most common channel) |
| 0x121107 / 0x121108 / 0x121109 / 0x12110E | not decoded (guessing from params: texture name / bool / colour / int) | `TEX`, `VIS`, `CLR`, `ALP`, … |

Quaternions use the column-vector convention, so their matrix is the *transpose* of the joint's row-vector rest matrix. Checked by scoring layouts against Hulk's rest pose: x, y, z, w with the transposed matrix wins for every rotation type. Hulk's gameplay animations (`hlk_*`, 178 in `global_nonchar.p3d`; more in mission files) and cutscenes (`nis/*.p3d`, `PTRN_hulk*`) render correctly when skinned.

## Locations
A location (e.g. `downtown_day`) is split into rooms, one file per room in `rooms.rcf` `art/locations/<loc>/<prefix>_rNNN.p3d`, in world space. Each room carries its own lightmap textures and shaders. Base textures come from `districts.rcf` `art/locations/<loc>/<prefix>_district_N.p3d`. `p3d.py city <loc|prefix>` merges all rooms with the districts as libraries: 4,121 of 4,126 materials across all 15 locations resolve a texture.

## glTF export conventions (`p3d.py gltf`)
Pure3D is left-handed, glTF right-handed: Z is negated on positions and normals, `S·M·S` (S = diag(1,1,-1)) on matrices, and triangle winding is reversed. Row-major row-vector matrices already have glTF's column-major layout. Joints are written as translation + rotation (animation targets can't use `matrix`); a quaternion (x, y, z, w) becomes (−x, −y, z, w).

## Unknown chunks (by frequency, from `p3d.py stats build/rcf`)
Animation channels are now named in the table above. Of the rest: 0x10011 (30k, in every PrimGroup), 0x60000724 / 0x60000725 (Hulk world data), 0x8020002 / 0x802000B / 0x8020008 / 0x8020003 (state props), 0x7010007 / 0x7010001 / 0x7010004 (collision volumes), 0x122000 and 0x123001.

## Open questions
1. Non-skeletal animation channels (bool/colour/texture/int) and the 0x121110 interpolation field.
2. Meanings of the PrimGroup vertex-format bits and of 0x10010 / 0x10011.
3. Collision (0x701xxxx) and state-prop (0x802xxxx) layouts.
