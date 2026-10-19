# Shaders: NV2A vertex programs, their bgfx counterparts, and how one is proven

Written 2026-10-18. The shader part of the graphics plan ([graphics-backend.md](graphics-backend.md), section 2,
"Getting the shader semantics without vendor code"): the game's 17 NV2A vertex programs are hand-written as bgfx
vertex shaders, and each one is checked per vertex against our own CPU interpreter of the NV2A program, the way
[`tools/equiv.py`](equivalence.md) checks a C++ function against the original.

```sh
PY=build/venv/bin/python
$PY tools/nv2a_vp.py list                       # the 17 programs in the player's XBE: shapes, registers, ops
$PY tools/nv2a_vp.py census                     # the census table below
$PY tools/nv2a_vp.py dis skin                   # a listing, on this machine only (never commit one)
$PY tools/nv2a_vp.py asm prog.vp -o prog.bin    # our own text form back into microcode
$PY tools/shader_equiv.py src/platform/sdl/pddi/shaders/vp/vs_vp_skin_onebone.sc            # prove a shader
$PY tools/shader_equiv.py SRC.sc PROGRAM --inputs 3000 --json                              # for a batch
$PY -m unittest discover -s tests/shaders -v    # 42 tests (verdict tests need shaderc; game ones the XBE)
```

Prerequisites: bgfx's sources and shaderc (`tools/native_gfx.py fetch`, `tools/native_gfx.py shaderc`) and the
player's XBE at `isos/extracted/default.xbe`. Pure Python; nothing to install.

## Clean room

- The format notes below are in our own words, from public descriptions of the NV20-family vertex program engine
  (community documentation of the 128-bit instruction word, such as the xboxdevwiki and envytools/nouveau notes)
  and Microsoft's public Direct3D 8 `vs.1.1` documentation for what each operation computes, and **checked against
  our own observation of the game's programs** (listed under each item). xemu and Cxbx-Reloaded may be read for
  understanding; nothing is copied from them (GPL/LGPL). No XDK or NVIDIA material.
- The programs are game data. `nv2a_vp.py` reads them from the player's XBE at run time; their bytes and listings
  stay on the developer's machine (`build/`). Tracked files hold only summaries and statistics (the census) and
  our hand-written shaders, which have the status of an `equivalent/` source: our code, written against the
  game's behaviour.
- The addresses of the 17 programs come from our verified source of the registry that names them
  (`FUN_00329430`, [equivalent/0x00329430.cpp](../equivalent/0x00329430.cpp)).

## Format notes

**Blob.** A 4-byte header, then 16 bytes per instruction. Header: low byte `0x78` (the type), next byte `0x20`,
high 16 bits the instruction count (observed: all 17). The last instruction, and only it, has the end flag
(observed: all 17).

**Instruction.** Four little-endian dwords; dword 0 is zero in every game instruction. Two units execute side by
side: the **MAC** (vector: `mov mul add mad dp3 dph dp4 dst min max slt sge arl`) and the **ILU** (scalar and
special functions: `mov rcp rcc rsq exp log lit`). Fields (`nv2a_vp.FIELDS` is the full table):

| dword | bits | field |
|---|---|---|
| 1 | 25-27 / 21-24 | ILU operation / MAC operation |
| 1 | 13-20 | the constant register this instruction reads (0..191) |
| 1 | 9-12 | the input register this instruction reads (v0..v15) |
| 1, 2 | | operand A: negate, 4 x 2-bit swizzle, temp register, mux |
| 2 | | operand B: the same |
| 2, 3 | | operand C: the same, its temp register split across dwords 2 and 3 |
| 3 | 24-27 / 20-23 / 16-19 | MAC temp write mask / temp register / ILU temp write mask (bit 3 = x .. bit 0 = w) |
| 3 | 12-15, 11, 3-10, 2 | output write mask; output (1) or constant (0) write; output register; result from MAC (0) or ILU (1) |
| 3 | 1 / 0 | constant index relative to `a0.x` / end flag |

- **Operands** select a temporary (mux 1), *the* input register of the instruction (2) or *the* constant register
  (3): one input and one constant per instruction, shared by every operand that names one. Unused operands read
  the input with swizzle `xyzw` in the game's encoding (observed).
- **Which operands each operation reads:** `mov`/`arl` A; `mul dp3 dph dp4 dst min max slt sge` A and B; `add`
  **A and C** (observed: every game `add` has C set and B idle); `mad` A, B, C. The ILU reads **C** (observed:
  every ILU-only instruction has A and B idle). So `add`/`mad` and a paired ILU operation share operand C; the
  assembler rejects a pair that needs two different C values.
- **Paired ILU results go to r1.** When both units are busy, the ILU's temporary write goes to r1, not to the
  instruction's temp register (observed: game pairs write the MAC and ILU masks to the same temp field with
  overlapping masks, e.g. 15 and 8, and the code that follows reads the ILU result from r1).
- **Registers.** r0-r11 temporaries; reading r12 returns the position written so far (`oPos`); outputs `oPos` (0),
  `oD0` (3), `oD1` (4), `oFog` (5), `oPts` (6), `oB0`/`oB1` (7, 8), `oT0`-`oT3` (9-12). One output write per
  instruction. No game program writes a constant register (observed). Constants are numbered 0..191 in the
  hardware; Direct3D's `c0` is hardware `c96`. **The game's `SetVertexShaderConstant` call sites pass hardware
  numbers** (lights at `0x7e + 3i` = c126.., read by `simple_proximity` as c126..).
- **Address register.** `arl a0.x, src` sets a0 = floor(src.x); `c[a0.x + n]` reads constant n + a0. The game
  scales a normalised byte holding 3 x bone by 256, not 255: floor(b/255 x 256) = b for every b < 255, so the
  conversion survives rounding (and 255 x would also be exact in float32 for every byte, checked).
- **Screen-space epilogue.** Every game program ends with `mul oPos.xyz, r12, c58` / `mad oPos.xyz, r12, r1.x,
  c59` with `r1.x = rcc(r12.w)` computed somewhere before (observed: all 17): oPos.xyz = clip.xyz x c58 / clip.w +
  c59, with c58/c59 the viewport scale and offset (set by the graphics runtime, not by the game). A bgfx shader
  returns the clip-space position in `gl_Position` and the viewport transform is fixed function, so the comparison
  uses oPos as it is just before the first instruction that rewrites an already-written oPos component
  (`nv2a_vp.screen_epilogue`, `run(position="clip")`).

**Semantics** (vs.1.1 definitions; scalar ILU results are replicated to all components; all sources are read
before either unit writes): `dp3`/`dp4` dot products; `dph` = a.xyz . b.xyz + b.w; `dst` = (1, a.y b.y, a.z, b.w);
`slt`/`sge` 1.0 or 0.0 per component; `rcp` 1/x (`rcp(1) = 1` exactly); `rcc` 1/x with the magnitude clamped to
[5.42101e-20, 1.884467e+19], sign kept; `rsq` 1/sqrt(|x|); `exp` (2^floor(x), x - floor(x), 2^x, 1) at partial
precision; `log` (floor(log2|x|), |x| / 2^floor(log2|x|), log2|x|, 1) at partial precision; `lit` (1, max(x, 0),
x > 0 and y > 0 ? y^clamp(w, -128, 128) : 0, 1). The game uses `rcp rsq rcc lit` and never `exp`, `log`, `dph`,
`dst` or `slt` (census below).

**Precision we do not know.** The NV2A's own accuracy for `rcp`/`rsq`/`rcc`/`lit` and its rounding mode are not
publicly documented; the interpreter computes the correctly rounded float32 result and the tolerance (below)
allows any implementation within a few ulps of it. Also open: whether the NV2A computes `0 x inf = 0` (the fuzzer
avoids infinities; a vertex whose reference output is not finite is skipped), whether `arl` adds a bias before
flooring (every game use floors a value at least 1/255 away from an integer), and the exact `rcc` bounds (no game
vertex gets near them).

## Census

From `tools/nv2a_vp.py census` (registers and counts only; "selected by" and "constants from" are from our
verified sources; "data needs it" from a scan of all 1,436 `.p3d` files' Shader and PrimGroup chunks in
`build/rcf/`):

| program | instr. | paired | inputs | outputs | constants read (before the epilogue) | relative | selected by | constants from | data needs it |
|---|---|---|---|---|---|---|---|---|---|
| `skin` | 68 | 8 | v0-2, v9-12, v15 | oPos oD0 oD1 oFog.x oT0 oT1 oT2 oT3 | c96, c98-105 | c113-115 | FUN_00327860 (prim buffer stream): vertex flags bit 7 and bit 8 | FUN_00324270; bones d3dExtHardwareSkinning::vfunc_5 | yes: all 387 skinned prim groups (format 0x2191) |
| `skin_onebone` | 43 | 7 | v0, v2, v9-12, v15 | oPos oD0 oD1 oFog.x oT0 oT1 oT2 oT3 | c96, c98-112 | c113-115 | FUN_00327860: bit 7 without bit 8 | FUN_00324270; bones d3dExtHardwareSkinning::vfunc_5 | no prim group in the data (every skinned one has weights); keep |
| `point_sprite` | 9 | 2 | v0, v3, v14 | oPos oD0 oPts.x | c98-101 | - | nothing (d3dPointSpriteShader slot 23 returns "") | d3dPointSpriteShader | no |
| `toon2` | 29 | 5 | v0, v2, v9 | oPos oD0 oFog.x oT0 oT1.x oT2.x | c97-104, c106-110, c112-115 | - | d3dToon2VertexShader slots 4/23 | d3dToon2VertexShader | no (class unused) |
| `toon` | 21 | 4 | v0, v2, v9 | oPos oD0 oFog.x oT0 oT1.x | c98-104, c106-111, c119 | - | d3dToonVertexShader slot 23 | d3dToonVertexShader | no (class unused) |
| `skin_toon` | 45 | 5 | v0-2, v9, v15 | oPos oD0 oFog.x oT0 oT1.x | c96, c98-101, c105, c107, c109, c188-190 | c113-115 | d3dToonVertexShader slot 23 (skinned) | d3dToonVertexShader | no (class unused) |
| `refract` | 54 | 6 | v0, v2, v9 | oPos oD0 oD1 oFog.x oT0 oT1 | c96, c98-104, c107, c109-118, c121 | - | d3dRefractVertexShader slots 4/23 | d3dRefractVertexShader | yes: 43 prim groups |
| `skin_refract` | 72 | 8 | v0-2, v9, v15 | oPos oD0 oD1 oFog.x oT0 oT1 | c96, c98-101, c103-105, c188-191 | c113-115 | d3dRefractVertexShader slot 23 (flag +0x7d) | d3dRefractVertexShader | only if refract meets a skinned mesh at run time; keep |
| `spheremap` | 58 | 9 | v0, v2, v9 | oPos oD0 oD1 oFog.x oT0 oT1 | c96-104, c110-121, c123-125 | - | d3dSpheremapVertexShader slots 4/23 | d3dSpheremapVertexShader | no (class unused) |
| `environmap` | 48 | 7 | v0, v2-3, v9 | oPos oD0 oD1 oFog.x oT0 oT1 | c96, c98-101, c110-121, c123 | - | nothing (registered only) | - | no |
| `bumpmap` | 22 | 8 | v0, v2, v6, v9-10, v15 | oPos oFog.x oT0 oT1 oT2 oT3 | c96, c98-101, c117, c119-120 | - | d3dBumpMapVertexShader slots 4/23 | d3dBumpMapVertexShader | no (class unused) |
| `simple_multicbv` | 34 | 6 | v0, v3-4, v9 | oPos oD0 oFog.x oT0 | c96, c99, c106-108, c110-113, c126-137 | - | d3dSimpleShader slot 23 (param MCBV) | d3dSimpleShader::vfunc_24, FUN_0032a5a0 | unlikely: MCBV = 0 in all data |
| `simple_proximity` | 30 | 7 | v0, v3, v9 | oPos oD0 oFog.x oT0 | c96, c106-108, c110-113, c126-137 | - | d3dSimpleShader slot 23 (param CBVP) | d3dSimpleShader::vfunc_24, FUN_0032a5a0, FUN_0032a600 | unlikely: CBVP = 0 in all data |
| `layered_multicbv` | 34 | 7 | v0, v3-4, v9-10 | oPos oD0 oFog.x oT0 oT1 | c96, c99, c106-108, c110-113, c126-137 | - | d3dLayeredShader / d3dLightMapShader slot 23 (MCBV) | d3dLayeredShader | unlikely: MCBV = 0 in all data |
| `layered_proximity` | 30 | 8 | v0, v3, v9-10 | oPos oD0 oFog.x oT0 oT1 | c96, c106-108, c110-113, c126-137 | - | d3dLayeredShader / d3dLightMapShader slot 23 (CBVP) | d3dLayeredShader | unlikely: CBVP = 0 in all data |
| `layered_lightmap_multicbv` | 34 | 8 | v0, v3-4, v9-11 | oPos oD0 oFog.x oT0 oT1 oT2 | c96, c99, c106-108, c110-113, c126-137 | - | d3dLayeredLMapShader slot 23 | d3dLayeredLMapShader | no (class unused) |
| `layered_lightmap_proximity` | 30 | 9 | v0, v3, v9-11 | oPos oD0 oFog.x oT0 oT1 oT2 | c96, c106-108, c110-113, c126-137 | - | d3dLayeredLMapShader slot 23 | d3dLayeredLMapShader | no (class unused) |

17 programs, 661 instructions; every one ends with the screen-space epilogue (c58/c59): True
operations: mul 142, dp3 134, dp4 128, mov 94, add 78, mad 70, max 28, rcp 28, rsq 20, rcc 17, min 16, arl 10, lit 6, sge 4

How the program is chosen: a shader class's slot 23 returns a program name (`""` for fixed function), and
`FUN_00327860` (the prim buffer stream) passes it to the registry lookup (`FUN_00321da0`), using `skin` /
`skin_onebone` when the shader gives none and the prim buffer's vertex flags have bit 7 (skinned) set; bit 8
(several bones per vertex) picks `skin`. Evidence for the last column:

- **Skinned meshes all use `skin`.** All 387 skinned PrimGroups (on `simple` shaders) have both a matrix list and a
  weight list (vertex format 0x2191: bits 7 and 8 set). No PrimGroup has format 0x2091, which would select
  `skin_onebone`, assuming the flags word FUN_00327860 receives is the PrimGroup's vertex format (to confirm).
- **`refract`**: 43 PrimGroups use the `refract` shader, none skinned, so `skin_refract` needs a run-time case
  (the class sets its flag at +0x7d).
- **The `*_multicbv` / `*_proximity` programs are probably never selected.** `d3dSimpleShader` and
  `d3dLayeredShader` choose them from two parameters whose names say what they are, `MCBV` (multiple
  colour-by-vertex sets) and `CBVP` (colour-by-vertex proximity). They are **0 in all 7,196 `simple` and `layered`
  Shader chunks that carry them** (the other 76 of the 7,272 do not set them), and the only game code that sets them at run time (`FUN_002821d0`, the
  `CLightQueue` constructor) sets them to 0. No script or other data file names them. (The 4CC-to-flag binding
  is filled at start-up, so "MCBV sets +0x84, CBVP sets +0x8c" is by name and order, not yet by a run-time check.)
- **Unused classes**: `toon`, `toon2`, `spheremap`, `bumpmap`, `layeredlmap`, `pointsprite` appear in no data
  ([graphics-backend.md](graphics-backend.md#what-the-data-actually-uses)); `environmap` and `point_sprite` are
  selected by nothing at all (`d3dReflShader`, the data's `environment`, uses fixed function).

**So the data needs 2 programs for certain (`skin`, `refract`), 2 more if run-time cases reach them
(`skin_onebone`, `skin_refract`), and probably none of the other 13.** That replaces the plan's "about 10". Before
writing the rest, log the registry lookups (`FUN_00321da0`'s name argument) through a full hybrid replay, as the
plan already proposes for the factory table.

## The pipeline

### `tools/nv2a_vp.py`: decoder, assembler, interpreter

- `parse_blob`, `decode`/`encode` (exact round trip of all 661 game instructions), `disasm` (vs.1.1-style text;
  a pair is written `mac ... + ilu ...`, a temp-and-output write `r3.xy|oT0.xy`), `assemble` (our text back into
  microcode, with the hardware's constraints: one input and one constant per instruction, a paired ILU writes r1
  only, add/mad share operand C with the ILU, one output write), `info` (registers read and written, relative
  bases, uninitialised reads, the epilogue), `census`.
- `run(prog, v, c, position="screen" | "clip")`: one vertex, float32 arithmetic (Python doubles rounded to float32
  after every operation; a double result rounded once is the correctly rounded float32 result for + - x / and
  sqrt). Next to every value runs an **absolute error bound**, the largest distance between this result and the
  result of any other correct float32 evaluation of the same mathematics (see Tolerance). A vertex whose relative
  constant index leaves 0..191, whose `arl` operand is within its bound of an integer, or whose outputs are not
  finite, is reported `bad` and skipped by the comparison.
- No numpy: the venv has none, and one vertex of a 72-instruction program takes about 0.2 ms.

### `tools/shader_equiv.py`: a bgfx shader against a program

Levels, as in equiv.py:

| level | check | fails on |
|---|---|---|
| 1 | the `.sc` compiles with bgfx's shaderc for SPIR-V, Metal, GLSL 430, ESSL 300 and WGSL (`--quick`: SPIR-V only) | `compile_error` |
| 2 | interface: every input register the program reads is fed by a shader input, every output it writes is produced, every uniform maps onto constant registers; warns on constants the program reads that no uniform covers | `interface_error` |
| 3 | differential execution on directed, structured and fuzzed vertices; every output component the program writes is compared | `fail` (first differing output register and vertex), `inconclusive` (fewer than 50 vertices ran, or a written component was never compared), `equivalent` |

**Why execute SPIR-V on the CPU.** shaderc turns the `.sc` into SPIR-V with glslang and runs spirv-opt's
performance passes; the Vulkan binary is that SPIR-V and the Metal and WGSL outputs are cross-compiled from it
(SPIRV-Cross, Tint: `tools/shaderc/shaderc_metal.cpp`, `shaderc_wgsl.cpp`). Interpreting it therefore tests the
program the backends are built from, after the compiler's optimisations, which a reference evaluator of our own
`.sc` text would not (it would test our reading of the source, not what shaderc made of it). It needs no GPU,
window or driver, runs headless on any machine a batch agent uses, and is deterministic. The alternative, drawing
one point per vertex through bgfx's Metal backend into a float target, tests the real GPU arithmetic but needs a
window session, gives answers that vary with the GPU and driver, and is not available on Linux batch machines; it
remains a useful later spot check. The SPIR-V interpreter (about 60 opcodes and the GLSL.std.450 functions bgfx
shaders use) reads opcode names from Khronos's published grammar files in bgfx's bundled SPIRV-Headers.
What it cannot see: the GPU's own arithmetic (fused multiply-adds, fast-math reciprocals) and the GLSL/ESSL
outputs, which come from glslang's GLSL front end and are only compile-checked.

**Annotations** in the `.sc` (comments; shaderc ignores them) tie the shader to the program:

```glsl
// nv2a-program: skin_onebone                      a game program name, or a .vp/.bin path relative to the .sc
// nv2a-input: a_position = v0 position            input kinds: position normal color uv weight index:<stride>:<n> any
// nv2a-input: a_color0 = v3 color bgra            "bgra": a D3DCOLOR the bgfx attribute delivers as B, G, R, A
// nv2a-uniform: u_vc = c96                        u_vc[i] is hardware constant c[96 + i]
// nv2a-output: v_fog = oFog                       only where the default names do not apply
// nv2a-const: c96 = fixed 0 1 256 0.5             what the game puts there (kept in every vertex set)
// nv2a-const: c98..c101 = projection              hints for the structured set: matrix projection bones
//                                                 direction position color "range lo hi"
```

Default outputs: `gl_Position` = oPos (clip space), `v_color0/1` = oD0/oD1, `v_fog` = oFog.x, `v_texcoord0-3` =
oT0-oT3. Each input gets the components the shader's attribute declares and the rest as (0, 0, 0, 1), on both
sides (what a vertex buffer with that declaration gives the NV2A and a bgfx backend).

**Vertex sets** (default 600 + 2 directed; `--inputs`, `--seed`): half *structured* (game-like: affine and
perspective matrices, unit light directions, colours in [0, 1], byte-valued colours and bone indices, positions to
+-100), half *fuzzed* (every input and constant uniform in [-8, 8] with 5% exact 0, +-1, 0.5, except constants the
game sets to literals and index inputs, which stay valid so relative addressing lands in range).

**Report.** Text by default (the first differing output component, its value and expected value with bit
patterns, the allowed difference, the vertex's inputs, how many vertices differ); `--json` gives the full dict
(`status`, `level`, `level1.profiles`, `level2.{issues,warnings,inputs,uniforms,outputs}`, `level3.{vertices_run,
vertices_skipped, skip_reasons, by_kind, components_compared, exact_components, ambiguous, never_compared,
colour_unclamped, max_ratio, mismatches, spirv_ops, tolerance}`). Exit status 0 only for `equivalent`.

### Tolerance

A component passes when |shader - reference| <= 4 x bound + 2^-100, with the bound tracked through the program:

- **Exact where the hardware is exact.** `mov`, swizzles, negation, masks, `min`, `max`, `sge`/`slt` away from the
  threshold and `arl` carry no error: a bound of 0 demands the same float bit for bit (+0 and -0 compare equal).
  Texture coordinate pass-throughs are reported as `bit-exact` components.
- **Arithmetic** (`mul add mad dp3 dp4 dph dst`): the first-order bound |a| eb + |b| ea + ea eb plus one ulp of every
  rounded product and partial sum (2n ulps of the sum of magnitudes for an n-term dot product). This covers a
  fused multiply-add, another association or another order of the terms, and cancellation (the bound is relative
  to the magnitudes summed, not to the result).
- **`rcp rsq rcc`**: the input's bound through the derivative plus 4 ulps. Vulkan, GLSL and WGSL allow 2.5 ulps or
  less for 1/x, division and inversesqrt, and the NV2A's own accuracy is undocumented.
- **`exp`/`log`** (partial precision, "at least 10 bits" in vs.1.1): 2^-10 relative on the approximated component;
  **`lit`'s power**: 2^-8 relative. (The game uses no `exp`/`log`; `lit` 6 times.)
- **Discontinuities** (`sge`/`slt` with operands within their bound of each other, `lit`'s branches likewise, the
  floor in `exp`/`log`): the component's bound becomes infinite and it is not compared on that vertex (counted as
  `ambiguous`); for `arl` and out-of-range relative constants the vertex is skipped. Exact operands are never
  ambiguous, so `u >= 0.5` against an exact 0.5 is checked.
- **Factor 4**: the reference and the shader each carry their own rounding, each within one bound of the exact
  value, so 2 is the minimum; 4 leaves room for GPU-side approximations. Measured headroom: correct but
  differently written shaders (division instead of `rcp` x, other summation orders, matrices built with
  `mtxFromRows` and `mul`, `normalize()`, a loop over lights) use 5% to 14% of the allowance over 3,000 vertices,
  and the wrong variants miss by orders of magnitude.
- **Colour outputs are compared after a [0, 1] clamp** of the reference (Direct3D 8 clamps vertex shader colour
  outputs; a bgfx varying is not clamped, so the shader must `saturate`). `--no-color-clamp` turns it off. The
  report counts how many compared colour components were strictly inside (0, 1), so a test where everything
  saturates is visible.
- **Undefined behaviour is NaN.** SPIR-V leaves `pow(x < 0)`, `pow(0, y <= 0)`, `inversesqrt(x <= 0)`, `log(x <= 0)`,
  `sqrt(x < 0)` and `min`/`max`/`clamp` of a NaN undefined; the interpreter returns NaN for them and records them.
  A shader that lets one reach an output fails (with the undefined operations listed); one whose compiled code
  computes an undefined value only to discard it passes, which matters because spirv-opt turns
  `ndl > 0.0 && ndh > 0.0 ? pow(ndh, p) : 0.0` into a select that evaluates `pow` on every vertex.

## Five proofs

All under [`src/platform/sdl/pddi/shaders/vp/`](../src/platform/sdl/pddi/shaders/vp/) (own `varying.def.sc`: the
vertex-program shaders need normals, blend indices, two colours, fog and four texture sets). 3,000 vertices,
all five profiles:

| shader | program | result | compared | notes |
|---|---|---|---|---|
| `vs_vp_simple_proximity.sc` | `simple_proximity` (30 instr.) | **equivalent**, 1.4 s | 39,026 components on 3,002 vertices; oT0 bit-exact; every colour component inside (0, 1) on about 1,500 vertices | transform, world position, four inverse-square point lights added to the vertex colour (D3DCOLOR swizzle), fog from world z |
| `vs_vp_skin_onebone.sc` | `skin_onebone` (43 instr.) | **equivalent**, 2.1 s | 87,058 components; oT0-oT3 bit-exact; oD1 inside (0, 1) on about 420 vertices | bone from a relative constant index, four directional lights, Blinn specular with the `lit` rule, fog from view z |
| `vs_vp_skin.sc` | `skin` (68 instr.; the one the data needs) | **equivalent**, 3.4 s | 87,058 components on 3,002 vertices; oT0-oT3 and both alphas bit-exact; oD0 inside (0, 1) on about 1,150 vertices, oD1 on about 470 | three-bone blended position (third weight 1 - w0 - w1), normal from bones 0 and 1 only, renormalised (zero normal stays zero), four lights as `skin_onebone`, fog from view z |
| `vs_vp_refract.sc` | `refract` (54 instr.; 43 prim groups) | **equivalent**, about 1 s | 63,042 components on 3,002 vertices; worst 1.6% of the allowance; oFog, oT1 bit-exact; oD0 inside (0, 1) on about 1,150 vertices, oD1 on about 310 | view-dependent factor k from the transformed normal and screen position scales every light term (the program's "n.l" is k times the sum of -direction); oT0 = projected normal times scale plus screen position times viewport; alpha is k |
| `vs_vp_skin_refract.sc` | `skin_refract` (72 instr.; run-time case) | **equivalent**, about 3 s | 63,021 components on 3,001 vertices (1 skipped: a zero normal makes oT0 infinite); oD0 inside (0, 1) on about 1,150 vertices | `skin`'s blend and lighting, `refract`'s oT0 built from the blended normal; alpha is c191.w |

All follow the program's order of operations, so in practice every component is bit-identical (worst 0% of the
allowance). Deliberately wrong variants in `tests/shaders/fixtures/` fail:

- `vs_wrong_simple_proximity.sc` (the D3DCOLOR byte order not undone): `fail` at the first structured vertex,
  `oD0.x = 1, expected 0.540772736`.
- `vs_wrong_skin_onebone.sc` (`lit`'s n.h > 0 test dropped, so a power <= 0 evaluates pow(0, p)): `fail` on the
  fuzzed vertices that reach it (4 of 600 vertices, 12 of 3,000), `oD1.x = nan, expected 0`, with `pow(0.0, -1.67)` listed as
  the undefined operation. The structured set alone (powers 0..16) does not see it: the fuzzed half earns its keep.
- `vs_wrong_skin.sc` (the normal blended by 1 - w1 instead of 1 - w0): `fail` at the first structured vertex.
- `vs_wrong_refract.sc` and `vs_wrong_skin_refract.sc` (oT0's v not flipped): `fail` on `oT0.y` at the first directed/structured vertex.
- `vs_synth_wrong.sc` (`>` for `sge`'s `>=`): fails only on fuzzed vertices whose u is exactly 0.5.

Writing the first proof also caught a slip of ours (a constant offset of 11 instead of 10) at the first
structured vertex.

## How a batch agent writes and proves a shader

1. `tools/nv2a_vp.py info <program>` and `dis <program>` (on the machine; the listing stays in the agent's
   context or `build/`, never in a tracked file). Read the shader class's constant upload in the verified tree
   (`build/tree/src/platform/xbox/pure3d/`, the census's "constants from" column) to name what each register holds.
2. Write `src/platform/sdl/pddi/shaders/vp/vs_vp_<program>.sc`: readable GLSL in bgfx's dialect, one `u_vc`
   array mapped to c96.. (the game's constant uploads all start at c96 or above; c58/c59 belong to the runtime), `#define`s naming the
   registers, comments saying what the program computes and where its constants come from (our words, as in the
   two proofs). Follow the program's order of operations where it costs nothing (bit-identical results make
   reviews trivial) but write it as shader code, not a transliteration of the listing.
3. Annotate inputs (with their kinds), the uniform, the fixed constants the game uploads (`nv2a-const: c96 = fixed
   ...`) and structured hints for the rest.
4. `tools/shader_equiv.py <src> --inputs 3000`. On `fail`, the report names the first output component and the
   vertex; rerun with `--seed` or more inputs after fixing. `interface_error` lists what is not mapped.
   `inconclusive` means some written component was never compared: add structured hints so the vertices reach it.
5. Done when `equivalent` at 3,000 inputs and the report shows the colour components exercised inside (0, 1).
   Record the result in the shader's header comment.

## Plan

**Vertex programs.** Order by need: `skin`, `refract`, `skin_refract` and `skin_onebone` are done (see above); then, only if the hybrid lookup log shows them,
`simple_multicbv`, `layered_multicbv`, `layered_proximity` (`simple_proximity` is done). The other nine are for
classes no data uses. Each is a single batch item with this tool as its acceptance test. Backend work that goes
with them (not done here): add `shaders/vp/` to `tools/native_gfx.py shaders` (it compiles only the top-level
directory with the top-level varying file), a 192-register constant file per draw uploaded as `u_vc`, the vertex
layouts from the declaration builder (`FUN_003290e0`'s flags word: which attributes, how many components,
normalised bytes for colours and indices), and the D3D-style clip depth (z in [0, w]) on the GL backends
(`bgfx::getCaps()->homogeneousDepth`).

**Fixed function.** The default path (no program) is D3D8 fixed-function T&L; it is specified by public
documentation, not by game microcode. The same harness can prove it: write the fixed-function equations once as
a `.vp` program of ours per variant (`nv2a_vp.assemble`), check the interpreter against hand-computed cases, then
prove `vs_pddi_ff.sc`'s variants against those programs.

**Pixel side.** Two parts, both without vendor material:

- *Combiner states.* The texture-stage state the shaders set (`d3dVertexProgram.cpp`'s cache, `FUN_00328bf0`) is
  D3D8 texture-stage operations, defined in public documentation. Plan: a state key (ops and arguments for stages
  0-3, alpha test, fog) recorded per draw by the drawlog; a CPU reference of each `D3DTOP_*` and argument in
  Python; and a fragment-shader counterpart of this tool, `fs` mode: interpret the fragment SPIR-V on fuzzed
  interpolants and texel values (texture fetches replaced by given values), compare per output channel with the
  same bound tracking (combiner math is mostly mul/add/lerp at 8-bit inputs).
- *The 17 `xps.1.1` effect shaders* (`d3dExtFramebufferEffects` set-up, 8 glow levels x 2 passes + 1), whose text
  is in our verified C: translate each by hand to a bgfx fragment shader and prove it against a small `xps.1.1`
  interpreter of ours (`tex`, `dp3`, `mad`, `mul_x2`, `_bx2`, co-issue, c0-c7; the semantics are in the public D3D8
  pixel shader documentation). `FUN_003202b0` (a caller-supplied string) first needs its callers found.

## Open questions

- Which programs run: log `FUN_00321da0`'s name argument (and the prim buffer flags) through a full hybrid
  replay. The census's conclusions for `skin_onebone`, `skin_refract` and the four `*_multicbv`/`*_proximity`
  programs rest on the data scan and on the MCBV/CBVP binding by name.
- Whether the flags word FUN_00327860 receives is the PrimGroup's vertex format.
- The NV2A's accuracy for `rcp`/`rsq`/`rcc`/`lit`, `0 x inf`, an `arl` bias, the exact `rcc` limits (none matters
  for the game's inputs as far as we can see; a hybrid-build capture of real vertex outputs would settle it).
- Whether D3D8's colour-output clamp holds on the NV2A for oD0/oD1 exactly as `saturate` (the comparison
  assumes so).
- A GPU spot check (bgfx Metal, one point per vertex into an RGBA32F target) to bound the real backends' error
  against the SPIR-V interpreter.
