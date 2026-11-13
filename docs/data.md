# Data as source (`.rdata` / `.data` / `.bss`)

Roadmap step 4, data half: the game's globals, constant tables, float pools, strings and vtables as source.
Code half (the source tree): [source-tree.md](source-tree.md). Written 2026-10-16. Numbers are from that day's
run (they move a little as farm lanes add sources, see [Reproducing](#reproducing)).

```sh
build/venv/bin/python tools/data_inventory.py     # config/data.json + build/data/inventory-report.json  (~5 s)
build/venv/bin/python tools/data_inventory.py --check   # exit 1 unless config/data.json is what its inputs give
build/venv/bin/python tools/data_gen.py           # data TUs, include/decls/data/, compile + byte-check  (~25 s warm)
build/venv/bin/python tools/data_gen.py --only global/CAction.cpp      # one object
build/venv/bin/python tools/build_tree.py --rounds 16 --data           # the tree build plus the data TUs and a link check
build/venv/bin/python tools/migrate_data.py --apply --equivalent       # sources onto include/decls/data/ (verified, logged)
```

| Output | What | Tracked |
|---|---|---|
| `config/data.json` | the inventory: one line per item (address, size, kind, name, type, owner, xrefs) | yes (no game bytes, no string text) |
| `config/data-items.json` | item decisions reviewed by hand that the evidence alone doesn't give (spans, kinds, owners; each with its `why`): an input of the inventory | yes |
| `config/data-source-offsets.json` | the offsets verified code uses past an address name (`DAT_x + k`): an input of the inventory (`--refresh-offsets`) | yes |
| `include/decls/data/<layer>/<dir>.h` | `extern "C"` declarations of every emitted item (`DAT_<addr>`, inventory name as a comment), per layer directory; sources include them | yes (names, types, sizes only) |
| `build/data/src/<layer>/<dir>/<File>.data.cpp` | one data TU per owning object, with the game's bytes | **no** (game data) |
| `build/data/report.json` | per-item verification results and per-kind totals | no |
| `build/data/inventory-report.json`, `code_xrefs.json`, `source_offsets.json` | coverage, disassembly cache, source offsets of the last complete tree | no |

## 1. The inventory (`tools/data_inventory.py`)

Every byte of `.rdata` (`0x3f2be0`, 0x99e88 B), `.data` (`0x48ca80`, 0x4f56c B initialized) and its BSS tail
(to `0x56f8e0`) belongs to exactly one item; the tool asserts the items tile the range. `BINKDATA`, `DOLBY` and the
two `$$X*IMAGE` sections are listed as one opaque `library_section` item each.

**Evidence, in order:**

1. **Known structures first.** The kernel thunk table at the start of `.rdata`; from `build/rtti.json` every type
   descriptor (`??_R0`), complete object locator (`??_R4`), class hierarchy descriptor (`??_R3`), base class array
   (`??_R2`) and base class descriptor (`??_R1`), and every vftable as one item `[locator pointer][slots]` (the MSVC
   COMDAT; the `??_7` symbol is 4 bytes in). A vftable never runs into the next structure (rtti.py can over-count
   slots). `type_info`'s own vftable (`0x439de8`, no locator) is placed by hand.
2. **Start points:** every absolute operand of every function in `build/functions.csv` that lands in the range
   (capstone over all of `.text` and the library sections, ~8 s, cached): immediates and memory displacements, also
   with a base or index register (`movzx eax, byte [eax + 0x426830]`; data3, below), every `DAT_xxxxxxxx` name the
   sources use (the merged tree's function blocks; before the flip `matches/` and `equivalent/`), and every aligned
   data word whose value is an address in the range.
   Filters, because a value in the range isn't always an address: immediates used by `cmp`/`and`/`add`/... are
   constants, an unaligned immediate is an address only if a string starts there, a BSS "address" whose bytes are
   ASCII (`0x504c41` = "ALP") with no memory operand is a FourCC (2 sources even named such constants `DAT_`), and a
   data word whose bytes are text isn't a pointer. That last rule also drops real pointers whose bytes happen to
   read as text (the word `7c 77 42 00` at `0x4ca298` points at a string at `0x42777c`, "|wB"): such words are
   listed by hand in `config/data-pointers.json` (item, byte offsets, why; the mirror of
   `config/data-not-pointers.json`), and the inventory and `data_gen.py` take them as pointers (dec1,
   2026-11-05: `0x4ca298` and `0x4ca29c`, name pointers hashed by `FUN_002672f0`, were `int` scalars; then the
   other 6 words that sources use as pointers and the rule dropped: `0x49ed3c`, `0x49f3c4`, `0x4a06a4`,
   `0x4c5cf8`, `0x4ca248` (native start-up initializer 260 crashed hashing it), `0x4ca254`). All 8 now have
   source evidence; `0x4ca248` points at a 4-byte item the inventory carved as `unknown`, so it is declared
   `const void*` (its users read it through `(*(const char**)&DAT_x)`).
3. **Extents.** Typed records (`include/decls/data/records.h`) and the spans of `config/data-items.json` are placed
   first, like the RTTI structures: one item each, whatever references fall inside. A string swallows starts inside
   it (pointers to a suffix, `"xRET" + 1`); a source offset past an address name (`DAT_x + 8` in verified code,
   `config/data-source-offsets.json`, the relocation addends of the tree's objects) makes one item of the range. An item ends at the next start, or earlier where the evidence says so: the FPU
   access width (`fld dword` -> float, `qword` -> double, `fild` -> integer), the access width of non-indexed
   loads, or the type sources declare (`extern float DAT_x;`, `char DAT_x[16]`).
4. **Classification** of each referenced item: string / wide string (printable text, NUL-terminated), float /
   double (or a table of them when indexed), pointer or pointer table (every word an address or 0), struct (some
   words addresses), scalar (one access width), table (indexed, or larger than its access), bss.
5. **Unreferenced bytes** (after an item, before the next start) are carved greedily: strict-ASCII strings,
   runs of plausible floats, runs of pointers, zero runs (`padding` when shorter than a word, else `zeros`), and
   what's left as `unknown`. Most unreferenced floats are header-defined `static const float`s that every
   including object emits and none uses (the same 28-byte run, `2π, 1e12, 1e-5, 32767, 1023, 511, 127`, sits in
   dozens of objects).

**Item format** (`config/data.json`, one JSON object per line):

| key | meaning |
|---|---|
| `addr`, `size`, `pad` | item start, size, and alignment padding after it (folded in; zero bytes up to the next item) |
| `kind` | see the table below |
| `name` | proposed name (below) |
| `type` | known type: from the access (`float`, `double[4]`, `void*[3]`) or from the sources' declarations; `source_type` when the sources disagree with the access |
| `cls`, `slots`, `vfptr_offset` | vftables: the class, slot count, offset of the vfptr in the object (multiple inheritance) |
| `object` | owning object (`config/splits.json` file) |
| `owner_by` | how the owner was found (below) |
| `xrefs` | functions that reference the item (code operands) |
| `data_refs` (`data_refs_n`) | items whose words point at it (first 8, and the count) |
| `interior` | referenced addresses inside the item (`DAT_x+4` names, string suffixes, field addresses) |
| `referenced` | `false` when nothing references the item's first byte |
| `source_names` | number of sources using `DAT_<addr>` |
| `flags` | `out_of_order` (owner breaks link order), `init_only` (only `.text$yc` initializers reference it), `truncated` |
| `layer`, `section` | only where they don't follow from `object` / the address (`load_inventory()` fills them in) |

**Names.** vftables `??_7Class@@6B@` (`+<offset>` for secondary vftables), RTTI structures their MSVC names
(`??_R0.?AVX@@@8`, `??_R4X@@6B@`, `??_R3X@@8`, `??_R2X@@8`, `??_R1<base>`), strings
`s_<up to 20 identifier characters>_<addr>`, wide strings `ws_..._<addr>`, `flt_` / `dbl_` / `fltTbl_`, `PTR_` /
`ptrTbl_`, `tbl_`, `struct_`, `zero_`, `unk_`, and `DAT_<addr>` for scalars and BSS (the name sources already use).
Every name ends in the 8-digit address, so it is unique and maps back. Data TUs use a C identifier per item
(`cname`): the name itself, or `vtbl_<addr>` / `rttiTD_<addr>`... for the mangled ones.

**Owners.** `.data`, `.rdata` and `.bss` contributions are laid out in link order, like `.text`: of 8,340 `.rdata`
addresses referenced by exactly one object, only 204 are out of order (COMDATs), and `.data`/`.bss` are as clean.
So:

| `owner_by` | rule | items | bytes (game/engine/platform) |
|---|---|---|---|
| `refs` | one object references it | 9,671 | 354,160 |
| `shared` | several objects: the one inside the window of its neighbouring single-owner items, first in link order (a pooled string or float COMDAT is placed with the first object that contributes it) | 2,016 | 34,282 |
| `data`, `data-shared` | only data references it: the referencing item's owner (strings in pointer tables, 2 rounds) | 8,007 + 1,570 | 237,027 + 33,814 |
| `class` | vftables and RTTI structures: the object whose dominant class it is | 4,358 | 107,196 |
| `between` | unreferenced, both neighbouring owners agree | 12,377 | 313,754 |
| `guess` | unreferenced, neighbours disagree: the previous one | 6,152 | 394,175 |

References from the `.text$yc` dynamic initializers (`game-init`) are ignored when choosing an owner: they
construct every object's globals. An item only they reference is flagged `init_only` and placed by its neighbours.

### Coverage

(2026-10-16; game + engine + platform/xbox = 1,483,900 B, library = 182,276 B; padding includes the `pad` bytes.)

| kind | items (port layers) | bytes | items (library) | bytes |
|---|---|---|---|---|
| `bss` | 2,281 | 579,912 | 221 | 24,472 |
| `rtti_td` | 4,210 | 257,908 | 34 | 1,304 |
| `vtable` | 4,233 | 125,964 | 35 | 868 |
| `string` | 6,394 | 106,041 | 559 | 9,018 |
| `library_section` | 0 | 0 | 4 | 106,368 |
| `rtti_bcd` | 4,229 | 101,496 | 30 | 720 |
| `rtti_col` | 4,233 | 84,660 | 33 | 660 |
| `rtti_chd` | 4,206 | 67,296 | 32 | 512 |
| `rtti_bca` | 4,208 | 54,116 | 30 | 236 |
| `zeros` | 5,913 | 24,686 | 189 | 2,485 |
| `table` | 257 | 20,924 | 116 | 6,209 |
| `unknown` | 1,065 | 13,509 | 293 | 13,407 |
| `float_table` | 784 | 18,388 | 30 | 476 |
| `struct` | 54 | 7,532 | 180 | 9,360 |
| `padding` | 0 | 9,492 | 0 | 843 |
| `pointer_table` | 233 | 4,440 | 80 | 2,780 |
| `float` | 1,098 | 4,392 | 145 | 580 |
| `scalar` | 427 | 1,628 | 49 | 274 |
| `pointer` | 288 | 1,152 | 128 | 512 |
| `kernel_thunks` | 0 | 0 | 1 | 640 |
| `double` | 32 | 256 | 33 | 264 |
| `wstring` | 5 | 88 | 15 | 288 |
| `unknown_bss` | 1 | 20 | 0 | 0 |

**Unknown: 13,529 bytes in the port layers (0.9%)**, 26,936 with the library (1.6% of 1,666,176). They are unreferenced, non-zero runs
that are neither text, floats nor addresses: small int tables (`2, 2, 2, 1, 2, ...`), packed `short`s and bit
patterns, most likely reached through a struct field offset or a header static that no instruction names
directly. `table` (21 KB) and `struct` (8 KB) are referenced but untyped.

What carries the bytes: BSS (580 KB) and the compiler-generated class data (vftables and RTTI, 691 KB, 47% of the
port layers' bytes) dominate; strings are 106 KB, float constants and tables 23 KB. 1,888 port-layer items are `out_of_order` (mostly pooled strings and floats shared by several objects) and 902 are `init_only`.

## 2. Data as source (`tools/data_gen.py`)

**One data TU per owning object**, `build/data/src/<layer>/<dir>/<File>.data.cpp`, beside the object's code TU in
`build/tree/src/` rather than inside it. Reasons: the code TUs are a merge of 25k sources whose own
`extern` declarations of the same addresses disagree in type and linkage (`extern "C" char DAT_x[]`,
`extern int DAT_x`, `extern World* DAT_x`); a definition in the same TU would turn each disagreement into a
compile error and move functions from merged to wrapped. The separate TU proves the data on its own now, and folds
into the object's TU when the sources use the declared names (section 3). Codegen doesn't depend on where data is
defined, so the split costs nothing in the verification build.

**What is emitted:** every item owned by a `game`, `engine` or `platform/xbox` object except:

- **vftables and RTTI structures** (code-owned): MSVC generates them from the class definitions in `include/gen/`,
  whose probe already checks every vftable slot and every base class descriptor against the XBE
  ([headers.md](headers.md#verification-the-layout-probe)). Writing them by hand would duplicate them.
- **jump tables**: none are in the data sections; MSVC 7.1 puts switch tables in `.text` after the function
  (no `jmp [reg*4 + disp]` operand in the binary points into `.rdata`). They come with the function's code.
- **library data** (XDK, CRT, Bink): opaque, like library code.
- alignment padding.

Strings and float constants *are* emitted. In the original they were code-owned (`??_C@` literal pools and
`__real@` constants), but the sources reference them as `extern "C" char DAT_x[]` / `extern float DAT_x`
(1,317 + 575 declarations), so for this tree they are data with names. Code that is later rewritten with
literals (`"movies"`, `0.5f`) makes the item dead; `tools/data_gen.py` will simply stop emitting items no source
references (open problem 4).

**Form, per item** (all `extern "C"`, so types don't enter the symbol; the C name was the inventory name and is
`DAT_<addr>` since the wiring, section 3; examples below use the inventory names): strings `const char s_x[N] = "...";` (octal escapes, no trigraphs), wide strings `unsigned short[]`,
floats and doubles as decimal literals that round-trip (`%.9g` / `%.17g`; NaN, infinities and denormals would fall
back to integer words: none occur), scalars and tables with the sources' primitive type when its size fits, else
`unsigned int[]` / `unsigned char[]`, pointers `const void* const p = (const void*)((const char*)&target + off);`,
mixed items as a `#pragma pack(1)` struct of byte runs and pointer words, BSS `extern "C" { T x[N]; }`. `const`
for `.rdata`, non-const for `.data`. A pointer names its target by its C name (`FUN_<addr>` for code). The three variables pinned in
`include/decls/address.h` are defined with that declaration (`extern "C" { World* DAT_004dd700; }`, C linkage).

**Verification**, per item: compile the TU with `compare.py`'s MSVC 7.1 under wibo, flags `/O2 /GR /GX /Gy`; find
the item's symbol; compare its bytes with the XBE outside relocations; each relocation must be `DIR32` and resolve
through the inventory's names (or the TU's own section symbols) to exactly the address the XBE word holds; BSS
items must have their size. The section the compiler chose is recorded too (`section_ok`).

| kind | emitted | byte-verified | pointers checked | section as in the XBE |
|---|---|---|---|---|
| `bss` | 2,281 | 2,281 | 0 | 2,281 |
| `double` | 32 | 32 | 0 | 32 |
| `float` | 1,098 | 1,098 | 0 | 1,097 |
| `float_table` | 784 | 784 | 0 | 784 |
| `pointer` | 288 | 288 | 288 | 288 |
| `pointer_table` | 233 | 233 | 1,020 | 233 |
| `scalar` | 427 | 427 | 0 | 234 |
| `string` | 6,394 | 6,394 | 1 | 6,381 |
| `struct` | 54 | 54 | 1,065 | 54 |
| `table` | 257 | 257 | 0 | 218 |
| `unknown` | 1,065 | 1,065 | 0 | 1,065 |
| `unknown_bss` | 1 | 1 | 0 | 1 |
| `wstring` | 5 | 5 | 0 | 5 |
| `zeros` | 5,913 | 5,913 | 0 | 4,357 |
| **total** | **18,832** (782,968 B, 1,078 TUs) | **18,832** | **2,374** | 17,030 |

Failures: none. Every data TU compiles (1,078 / 1,078) and every emitted item byte-matches with its pointers resolving to the right targets. One `string` item (`0x406a54`) holds a pointer word and is emitted as a struct; it is a mis-carved string run (open problem 2). Negative checks: a changed string byte, a float off by one ulp and a pointer to `target + 4`
instead of `target` are each reported as a diff.

**Section placement** is the one thing not reproduced: the 1,802 items in the last column's gap are all-zero `.data` items (`zeros` 1,556, `scalar` 193, `table` 39, empty strings 13, a `0.0f`) that MSVC 7.1 puts in `.bss` when the initializer is all zeros; the original has them in `.data`, so its sources initialized them some other way (a dynamic initializer that the optimizer folded, or a non-zero-looking expression). This matters only for a byte-identical relink,
not for the port.

**Declarations:** `include/decls/data/<layer>/<dir>.h` (31 headers) declares every emitted item with the type its
definition has, e.g. `extern "C" const char s_movies_0041dcac[7];`, `extern "C" float fltTbl_004c3bc8[4];`,
`extern "C" { ... }` free. (Since the wiring, section 3, the C symbol of every data item is `DAT_<addr>`:
`extern "C" const char DAT_0041dcac[7];  // s_movies_0041dcac`.) Mixed items are declared through a forward-declared `DataLayout_<addr>` struct (sources
take its address). The headers carry names, types and sizes only, no contents.

## 3. Wiring the sources onto the data (`tools/migrate_data.py`, 2026-10-16)

Sources used to declare their own `extern ... DAT_xxxxxxxx` for every global they touch, in whatever type and
linkage suited them (`extern char DAT_x;`, `extern "C" char DAT_x[];`, `extern AnimKey DAT_x;`), and 50 of them
defined the global themselves. Now a verified source includes the owner's `include/decls/data/<layer>/<dir>.h`
and declares nothing, so the tree has one declaration and one definition (the data TU's) per global.

### Names in sources: the address name stays the symbol

Every emitted data item's C symbol is now `DAT_<addr>` (`data_gen.cname`); the inventory name
(`s_movies_0041dcac`, `flt_00421a90`, `fltTbl_...`) is the description written next to its declaration:

```c
extern "C" const char DAT_00421a94[15];  // s_Compute_Lights_00421a94
extern "C" const float DAT_00421aa4;  // flt_00421aa4
```

This is the "per-address alias" option, chosen over renaming sources to the inventory names because:

1. **equiv.py binds data by the spelling of the name** (`HEX_NAME`: `DAT_`/`PTR_`/`s_`... followed by the 8
   digits). `flt_`, `fltTbl_`, `tbl_`, `zero_`, `unk_`, `struct_` and most `s_<text>_` names don't match it, and
   equiv.py can't be changed under the running promotions. A renamed equivalent/ source would fall back to
   positional pairing for its globals, which binds whatever the original reads at that spot: a wrong-global
   bug would pass. With `DAT_<addr>` every reference is still checked against its address.
2. **The rewrite stays minimal**: a declaration goes, an `#include` comes, and only where the types differ is
   there a cast. Uses keep their spelling, `// equiv-*` lines and mangled names in them stay valid.
3. **Renaming later is mechanical**: one pass over the headers and sources once equiv.py reads
   `config/data.json` (or the port no longer needs it). The address is in every name either way, so nothing
   is lost.

The three variables pinned in `include/decls/address.h` (`DAT_004dd700` World, `DAT_0052c2a8` Gfx,
`DAT_004dd6ec`) keep that declaration (C linkage, typed): their data TU definition is `extern "C" { World* DAT_004dd700; }`
and `include/decls/data/` leaves them out, so a source can include both headers.

### The rewrite

Per source, token-level (`tools/cxx_items.py`), for every top-level declaration of `DAT_<addr>` whose address
is an emitted, declared item (not code-owned, library, pinned or a FourCC constant):

| rule | what | matches/ | equivalent/ |
|---|---|---|---|
| `data-decl` | the source's type is the header's (`canon`: `unsigned` = `unsigned int`, `T x[]` = `T x[N]`): the declaration just goes, uses don't change | 265 (314 names) | 742 (1,292) |
| `data-cast` | the types differ: each use becomes `(*(T*)&DAT_x)`, `&DAT_x` becomes `((T*)&DAT_x)`, an array `T DAT_x[]` becomes `((T*)&DAT_x)` (multi-dim: `(*(T(*)[A][B])&DAT_x)`), T being the source's own type | 607 (1,220) | 1,350 (2,750) |
| `data-interior` | `DAT_y` inside item x (y = x + k): `(*(T*)((char*)&DAT_x + k))` | 15 (20) | 76 (116) |
| `data-def` | the source defined the global: the definition goes (owners, below) | 1 (1) | 11 (48) |
| **sources rewritten** | | **861** | **1,556** |

Counts are sources, a source can use several rules (names in parentheses; the log has the rule per name). Several declarators in one
declaration (`extern int DAT_a, DAT_b, FOO;`) lose only the migrated names. Refused: a declaration inside a
namespace or with an initializer, function-pointer declarators, `sizeof` or a member access on a name that needs
a cast, a cast that would land in a global's initializer (it could make it dynamic), names used in a
preprocessor line or on an `// equiv-*` line, a source that keeps another declaration of a name its headers
declare, and the addresses on `build/farm/bench/claude-equiv/batch-{r9p,fx9p,fx9r,r10p,bigq}.txt`.

Why casts and not typed headers: the header type is the definition's (the data TU byte-checks it), and the
sources disagree among themselves (the same 144-byte BSS buffer is `char`, `Stream`, `unsigned char[144]`).
Casts keep each function's own access type, so codegen can't change; `tools/compare.py` / `equiv.py` prove it
per source. The most common pairs: `char` vs `unsigned char[N]` (BSS objects declared by their first byte),
a source stub class vs `unsigned char[N]` (`ParamRegistry`, `AnimKey`), `const char*` vs `const void*`,
non-const vs `const` `.rdata`. Typing the headers better (stub classes for BSS objects) shrinks the casts; it
doesn't need the sources to change again (a cast to the header's own type is harmless).

**Verification** (as migrate_gen): matches/ must `MATCH` under `compare.py`, equivalent/ must be `EQUIVALENT`
under `equiv.py --inputs 3000` (600 s per run; a timeout rejects). The source is re-read before the write and
skipped if a farm lane or promotion changed it meanwhile. Log `build/migrate-data.log` (one JSON line per source:
rule, headers, per-name rule, the verification line), originals `build/data-orig/`, list `build/data-migrated.txt`.
Re-running plans nothing for a migrated source.

**Run (2026-10-16, 07:45-17:55; equiv.py is most of it):** 2,417 sources rewritten and verified (861 matches/,
1,556 equivalent/; 6 of the equivalent/ ones are new, still-untracked promotions), 4,019 names in matches/ and
equivalent/ off private declarations onto 28 shared headers.

| | matches/ | equivalent/ |
|---|---|---|
| sources with a `DAT_` name (not on a batch list, not shadowed) | 1,582 | 2,110 |
| nothing inventory-owned to move (code-owned, library, pinned, FourCC names only) | 721 | 527 |
| planned (rewritten in the scratch dir) | 861 | 1,562 |
| kept (verified) | **861** | **1,556** |
| rejected by verification | 1 (DIFF: the first `&DAT_x[i]` form, fixed and re-run: kept) | 6: 2 regressions caught (`0x000d4b60` compile error, a declaration the parser missed; `0x001b3c50` FAIL level 2, an interior `DAT_x + 64` that equiv.py's reference check doesn't accept), 3 that fail the same way unchanged (`0x00242da0` INCONCLUSIVE, `0x0029d880`, `0x00122520` FAIL), 1 timeout (`0x00088020`, >600 s) |
| refused by the tool | 0 | 21: 10 names used in a `#define`, 10 declarators it doesn't parse (function pointers, `union {...} DAT_x`), 1 declared in a namespace |
| on a batch list (scheduled promotions) | - | 7 |
| shadowed by a matches/ source | - | 28 |

No source changed under the tool between read and write ("changed meanwhile": 0).

### Owners of a global (step 2)

**Rule: the data TU defines every inventory item; a source never defines a `DAT_<addr>` global.** The data TU
is the object that owns the address in link order, has the verified bytes, size and section, and is the only
candidate that exists for every item. A source definition was a stand-in from before the data had a home
(`unsigned __int64 DAT_004e2448;` in the hash initializers, `AnimKey DAT_004dd270;`, `char DAT_004e7b08;`); the
rewrite (`data-def`) deletes it and the source uses the header like any other. Of the 50 globals sources defined: **49 moved to the data TUs** (12 sources: the hash/registry initializers
`0x0035e860`, `0x0035e9a0`, `0x0035ebb0`, `0x0035cec0`, the shader tables `0x00361a90` ... `0x00363290`,
`0x0014fad0`, `0x002be720`, `0x00262e60`). One is left: `equivalent/0x00088600.cpp` defines
`CSimDb *DAT_004dd700;`, the pinned World pointer; it needs the pin family's rename (`CSimDb` -> `World`) as well,
which migrate_gen's `pin-decl` doesn't do for definitions. The tree now has 4 addresses defined by code objects
(was 53), 1 of them also by a data TU (was 50).

### Strings and floats (step 3)

Sources reference strings and float constants as `DAT_<addr>` like any global, so they go through the same
rewrite onto the named item (the header's `const char DAT_x[N]` / `const float DAT_x`), not onto literals: a
literal becomes a `??_C@`/`__real@` COMDAT in the function's object and changes codegen (string pooling, constant
folding). No literal replacement was attempted; where a cast was needed (`char DAT_x[]` against
`const char DAT_x[15]`) it is a cast to the source's type. Literals stay open problem 4.

### Generator and tools

- `tools/data_gen.py`: C names `DAT_<addr>`, the inventory name as a comment in the header, pinned variables
  defined with their `address.h` declaration; `link_check` counts `by_name` against the symbols the data TU
  objects really define (C and C++ names).
- `tools/gen_tree.py`: `#include "decls/data/<layer>/<dir>.h"` is a hoisted include like gen/ and decls/; the
  headers of a TU's merged *and* wrapped sources go at the top of the TU (only `extern "C"` declarations, so a
  wrapped source sees them from its namespace; an include inside one namespace would hide them from the next),
  and their declarations are forced variants, so an unmigrated neighbour that declares a name differently is
  wrapped. `build_tree.py`: the object cache key covers include/decls/data/.
- `tools/data_inventory.py`: a migrated source no longer declares its names, so its type vote is the type the
  last inventory recorded (`previous_types`). Re-running the inventory after the migration gives the same items
  (checked: 0 differences in size, kind, type, source_type, object over 46,388 items).

### Tree build with `--data`

`build_tree.py --rounds 16 --data` (log `build/data-wire-build.log`; then `--resume --regression-rounds 3`, log
`build/data-wire-build2.log`, because one equivalent/ function still differed after the default two regression
rounds): **2,498 / 2,498 TUs compile; 21,776 / 21,776 matches still match; 4,619 / 4,619 equivalent/ functions
compile, 4,569 with code identical to their standalone build, 49 wrapped ones can't be told (symbol not found
standalone), 1 whose source doesn't compile standalone (`equivalent/0x0010b5b0.cpp`, committed today by a promotion:
`fabs` undeclared; not touched here, on the fx9p list), 0 differ.** Data TUs: 1,078 / 1,078 compile, 18,832 / 18,832
items verified.

The one regression the rounds handled: `equivalent/0x002e9c60.cpp` (not migrated; its TU's neighbours were), whose
code changed when merged and again when wrapped; it is isolated now.

| | before (same corpus and fallback state, original sources from build/data-orig/) | after |
|---|---|---|
| merged / wrapped / isolated | 19,851 / 5,895 / 649 (75.8%) | **19,952 / 5,805 / 638 (76.2%)** |
| matches merged / wrapped / isolated | 17,444 / 3,814 / 518 | 17,467 / 3,801 / 508 |
| equivalent/ merged / wrapped / isolated | 2,407 / 2,081 / 131 | 2,485 / 2,004 / 130 |
| TU files | 2,509 | 2,498 |

(The morning build, 1196ae7a: 19,623 / 5,427 / 643 of 25,693; farm lanes added 702 functions since.) The gain is
small because the `DAT_` declarations were mostly spellings of one declaration already (`canonical_variant` treats
C/C++ linkage of address names as one); what it removes are the type disagreements (`char` vs `int` for one
global) and the source-defined globals. Wraps by conflict on a `DAT_` name: the remaining ones are sources not
migrated (above) whose declaration differs from the header their neighbours now bring in.

### Link check

| reference from a tree object to `DAT_<addr>` | before (2026-10-16 04:00) | after |
|---|---|---|
| all references (C++-mangled ones need a declaration) | 7,200 (5,676 C++) | 6,177 (1,277 C++) |
| **resolves by name** (a data TU defines exactly this symbol) | **260** | **4,028** |
| an emitted item's start, by address only | 5,279 | 563 (406 of them the pinned `DAT_004dd700` & co. declared inside wrapped sources' `fn_<addr>` namespaces) |
| inside an emitted item | 87 | 12 |
| vftable / RTTI (code-owned) | 1,303 | 1,306 |
| library data (platform shim) | 269 | 266 |
| outside the data sections | 2 | 2 |

Fewer references overall because a merged TU now references one `_DAT_x` where its functions' private
declarations gave several (C and C++ names). The rename alone (C names `DAT_<addr>`, before any source changed)
took `by_name` from 260 to 634; the source rewrite does the rest. (The 2026-10-16 morning text said 5,225 / 141 for
the two by-address rows; the numbers above are from that build's report file.)

### What is left

Re-run of 2026-10-17 (mop-up): the three pinned names are `extern "C"` in `include/decls/address.h` and in their data
TU definitions (`tools/data_gen.py`); `equivalent/0x00088600.cpp` includes the header and names its class `World`
instead of defining `DAT_004dd700` itself; `tools/migrate_data.py --apply --equivalent` moved 145 more sources
(of 149 candidates; 4 rejected and left unchanged: 2 FAIL, 1 compile error, 1 inconclusive). Tree
(`build_tree.py --rounds 16 --data`): 2,557 / 2,557 TUs compile, 21,817 / 21,817 matches byte-match, no equivalent
differs from its standalone build; link check 6,477 references, **4,238 by name** (was 4,028), 620 by address
(was 563; 354 of them pinned names, was 406), 10 interior.

- **The pinned names in wrapped sources: done 2026-10-17 (night).** Were 354 references by address: gen_tree's
  `CLinkage` turned a wrapped source's `extern "C" World* DAT_004dd700` into `fn_<addr>::DAT_004dd700` (its
  `World` is the source's own stub). Now a wrapped or isolated source's declaration of a pinned name becomes a
  typed view of the TU's one C declaration, `#define DAT_004dd700 (*(World* *)&::DAT_004dd700)` inside its
  namespace, and a merged C++ declaration of one gets C linkage (`gen_tree.PINNED`, `pin_views`;
  [wine-build.md](wine-build.md#after-the-next-fixes-1-3-2026-10-17) says why this and not an exemption or
  an alias). Same code under MSVC 7.1 (`build_tree.py`: 21,817 / 21,817, no equivalent differs). Link check
  (`build_tree.py --resume --data` on the live tree: 6,171 references, **4,283 by name**, 917 C++ linkage, 1,342
  code-owned, 267 library, **266 by address**, 11 interior): pinned by address **0** (was 354); all references to the three names are
  `_DAT_004dd700` / `_DAT_0052c2a8` / `_DAT_004dd6ec` (references count once per object and symbol, so the
  views of one TU now count once: hence 6,171 references, not 6,477).
- **Other by-address references** (266 on 2026-10-17 night; were 256 + the pinned ones): sources refused or rejected by the migration (25 declarator is not
  `T NAME[...]`, 10 used in a preprocessor line, 1 in a namespace, 21 on batch lists, the 4 rejected) and farm
  sources committed since. Re-run `tools/migrate_data.py --apply --equivalent` after promotions land.
- Typed headers: BSS objects are `unsigned char[N]` in the headers, so most casts are `(*(Stub*)&DAT_x)`; a typed
  declaration (a stub class per global in include/decls/, like `World`) would remove them.
- Interior references fail equiv.py's level 2 in one case (`0x001b3c50`): equiv.py reads `DAT_x + 64` as a
  reference to x. Rare (116 interior names migrated fine).

### Rules for new sources

- Don't declare `DAT_<addr>` data yourself: `#include "decls/data/<layer>/<dir>.h"` for the item's owner (the
  header that declares the name: `grep -rl 'DAT_004c53bc\b' include/decls/data`) after the `// STATUS` comment
  block, next to any `gen/` / `decls/` includes. Use the name as declared there.
- If your code needs another type, cast at the use: `(*(int*)&DAT_x)`, `((char*)&DAT_x)`, `(*(Foo_1b77e0*)&DAT_x)`.
  An address inside an item is `(*(T*)((char*)&DAT_item + k))` (the header comment marks items; an address
  without its own declaration is inside the one before it).
- Never define a `DAT_` global in a source; the data TU owns it. Strings and floats: use the `DAT_` item, not a
  literal.
- `DAT_004dd700`, `DAT_0052c2a8`, `DAT_004dd6ec` still come from `decls/address.h`. Code-owned addresses
  (vftables, RTTI) and library data (CRT/XDK) are not in these headers; keep your own declaration for those.
- `tools/migrate_data.py --apply --equivalent` moves sources that didn't follow this (farm output) and verifies them.

### What the native (clang) build needs from data

- **No absolute addresses.** Every `DAT_xxxxxxxx` becomes a named object defined in a data TU; every pointer
  word inside data becomes a pointer initializer (`&target + off`), which is what `data_gen.py` already emits.
  Pointer tables are real pointer arrays, relocated by the native linker.
- **The XBE's layout** (done 2026-10-18, [wine-build.md](wine-build.md#start-up-continued-2026-10-18-evening)):
  the Wine link doesn't link the data TU objects as they are; it copies each item (bytes and relocations) into
  one block per XBE section at the XBE's distances, so items the inventory split out of one structure stay
  adjacent (open problem 2 no longer breaks the Wine image; the item boundaries still matter for typed data).
- **Pointer-holding items have pointer types** (x64-5, 2026-10-25; [native-mac.md](native-mac.md) section 10): a
  word that holds a pointer is a pointer, 4 bytes on the 32-bit builds and 8 on 64-bit. Which words: the XBE's
  initialized pointers, and the ones the sources use as pointers at run time (zero in the XBE, or BSS), from
  `config/data-ptrs.json` (`tools/data_ptrs.py evidence`). Types by what they point at: `const char*` (strings),
  `hulk_code_ptr` (code), `hulk_vftable_ptr` (vftables), `const void*` (other data), `void*` (set at run time).
  Mixed `DataLayout_` structs have the pointers as pointer members and the other words as `unsigned int`; they
  are packed on the 32-bit builds (`HULK_DATA_PACKED`: the XBE's layout, byte-identical) and naturally aligned
  on 64-bit. Code that still addresses such an item by 32-bit byte offsets, or reads a pointer word as an
  integer, is listed by `tools/data_ptrs.py lint`.
- **Typed records** (reg1, 2026-11-05). A `.bss` item that several sources index as one record takes its type from
  `include/decls/data/records.h`, hand-written: the record (pointer fields as pointers) and `extern "C" T
  DAT_<addr>[N];`. The inventory makes each declaration one item of its 32-bit size (libclang,
  `i686-pc-windows-msvc`; drift1: dg1's `data_gen.py --merge-records`, which edited config/data.json's lines, is
  gone). Initialized (`.data`) records whose fields are simple types get their initializer from the XBE's bytes
  (dg1: `ShaderParamEntry`, `ControllerNameList`, `StringRecord_23fc40`). `data_gen.py` reads those declarations: the item's data TU includes the header and defines the
  item with it (form `typed record`, the 32-bit size asserted against the item), and the generated headers leave it
  out (a comment points at records.h); a generated header that leaves items out includes records.h itself (reg4), so
  a source naming them needs no include of its own. First user: the memory allocator registry
  (`MemoryHeapSlot DAT_00527c60[46]` and its root `DAT_00527f40`). The static om types (reg4: 84 objects, `OmType`,
  `OmEntityType`, `SeqEventTypeHead`) are declared as arrays of one (`extern "C" OmType DAT_004e5db0[1];`), so the
  sources that pass the item as a pointer keep compiling; an item that held several objects is one item per object.
  The header declares no namespace or other
  top-level name besides its records and items: gen_tree keeps every top-level name of include/ global, so a
  `namespace core { ... }` there moved the core classes of 20 TUs out of their TU namespaces (a duplicate symbol in
  the native link).
- **Names across linkage:** pointers to functions use `FUN_<addr>`; the Wine build needs the function's real
  symbol (a C++ member such as `CFoo::vfunc_3` can't be named by an `extern "C"` alias). The inventory knows the
  target address, so the generator can emit the real name once functions.csv names are spellable.
- **vftables and RTTI** come from the compiler (both MSVC and clang); the Wine build never needs the original
  addresses. Pointers *to* vftables in data (rare) must become references to the class (e.g. a placement-new'd
  object), not to `??_7` symbols, which clang names differently.
- **Float bits:** constants are emitted as decimal literals that MSVC 7.1 parses to the exact bits; clang does the
  same for `%.9g`/`%.17g` literals, so no hex floats are needed.
- **BSS** is plain zero-initialized globals. The XDK-only buffers (`platform/xbox` owners) go with that layer.

## 4. Open problems

1. **Owners of unreferenced items** are guesses where neighbours disagree (`guess`, 394 KB, mostly large BSS
   buffers next to an object boundary). A wrong owner moves an item to the neighbouring TU, which is harmless for
   the build but wrong for the tree's file layout. `.data` link order could be checked against `.text` order per
   object to pin the boundaries.
2. **Item boundaries without evidence:** a struct-typed global whose fields code addresses separately is several
   items (`DAT_x`, `DAT_x+4`, ...) unless a verified source uses an offset past the first one. Merging needs types
   (the sources' stub structs) or the tree's relocations of all objects, not just the last build's.
3. **Section placement** of explicitly zero-initialized `.data` items (above).
4. **Strings and floats that sources will write as literals** (none yet: the wiring keeps the `DAT_` items) become dead items; the generator should skip items
   whose only references are from sources that no longer name them.
5. **Typed tables:** `table`, `struct` and `unknown` items are bytes and words; real element types come from
   the code that indexes them (field mining, as `gen_headers.py --mine` does for classes).
6. **`DAT_` names for constants:** a few sources declare FourCC/hash immediates as `DAT_` globals; the inventory
   ignores those names (`false_source_names`), migrate_data.py leaves them alone; they should become constants.
7. **Library-owned data referenced by game code** (269 references, e.g. CRT globals): belongs to the platform shim.
8. `config/data.json` is about 9 MB (46k lines). RTTI items (21k) could move to a derived listing if the size
   matters.

## Reproducing

`config/data.json` is generated, never edited: `tools/data_inventory.py` rewrites it from its inputs, and
`tools/data_inventory.py --check` (also `tests/test_data_inventory.py`) exits 1, naming the items that differ, when the
committed file is not what they give in a field `tools/data_gen.py` reads: the item set, `size`, `pad`, `kind`,
`name`, `type`, `object`, `layer`, `section`, `source_type` where it changes data_gen's scalar type (its fallback
when `type` gives none), and `interior` on vftables and RTTI structures (tools/wine_link.py makes a label of each). The
data TUs, include/decls/data/ and those labels follow from them. Differences in the informational
fields (`source_names`, `source_type` otherwise, `owner_by`, `shared_objects`, `flags`, `xrefs`, `data_refs`,
`interior`, `referenced`, `pointers`, `cls`/`slots`/`vfptr_offset`, the coverage line) are printed as warnings
and exit 0: they move whenever a source adds a name or functions.csv moves an xref, and nothing generated depends on
them (`interior` elsewhere and `xrefs` are hints for addr_literal and equiv; regenerate to refresh them).
`--check --exact` fails on any difference (data2, 2026-11-12). The inputs:

| input | what it decides | committed |
|---|---|---|
| the XBE, `build/functions.csv`, `build/rtti.json` | the bytes, code references (`build/data/code_xrefs.json` caches them per function list), RTTI structures | no (local, from the player's XBE) |
| `config/splits.json` | owners (objects by address, link order) | yes |
| the merged tree (`src/game`, `src/engine`, `src/platform/xbox`) | start points and type votes: per function block the `DAT_` names it uses and the types the TU's shared part and the block declare; a hoisted declaration no block uses counts on its own | yes |
| `config/data.json` itself | the type a source on `include/decls/data/` votes (it no longer declares the name), and the type of an item no source names any more (kept while the span is the same) | yes |
| `include/decls/data/records.h` | typed records: one item per declaration | yes |
| `config/data-items.json` | item decisions reviewed by hand (below) | yes |
| `config/data-pointers.json` | pointer words whose bytes read as text | yes |
| `config/data-source-offsets.json` | offsets past an address name (extents) | yes |

The inventory reads config/data.json for those type votes, so the check holds it to a fixed point: regenerating
gives the same file.

**How to change data items.** A record type: declare it in records.h and regenerate (the items inside fold into it,
an item that runs into it is cut). A pointer word the text rule drops: config/data-pointers.json. Anything else (an
item's span, kind, type, name or owner): an entry in `config/data-items.json` with its `why` (`size` + `kind` place a
span before carving, `pad` folds the bytes after it as padding; `kind`, `type` (null: none), `name`, `object` override
the carved item at that address). Then `tools/data_inventory.py`, `tools/data_gen.py` (the data TUs and
include/decls/data/), and the gates of a data change (data_gen verifies every item; the Wine image or a proof).

**What drifted, and the fix (drift1, 2026-11-11).** The inventory was last run as a whole on 2026-10-16. The 14
commits that changed config/data.json since (reg1-reg4, dec1, boot1, the Lua VM, bink1, F's Lua split and renames,
dg1 B2-B4) edited its lines by hand or by script, and its inputs moved under it:

- *hand edits* that no input recorded: the typed records' spans (reg1, reg3, reg4, dg1), reg4's split words, F's
  owners for the Lua objects' items, the luaL_reg tables' kinds (8310fb004);
- *the sources*: matches/ grew after 10-16, then froze at F, and the code now lives in the merged tree (2,467 items'
  `source_names` and 534 `source_type`s were 10-16's);
- *config/data-pointers.json* (dec1, 697da9944) added pointer words without a re-run: the strings they point at would
  change owner and extent;
- *the source offsets* were `build/data/source_offsets.json`, a local cache of 10-16's tree build (385 offsets); a
  re-read after the data wiring would have found almost none (the regex missed `_DAT_x`, the `extern "C"` symbols);
- *build/functions.csv* (2026-10-17 size fixes) moved some xrefs and owners;
- *a type spelling bug*: `unsigned char` became `unsigned int char`; and `source_type` was written even when it
  equals `type` (kept: it is cheap and nothing reads the difference).

Now: the tree is the source input, records.h spans are placed by the inventory, the other hand edits are entries of
`config/data-items.json` (67: 52 that record the commits' decisions, each naming its commit, and 15 marked `review`:
F's carve kept where the evidence since then says otherwise, mostly dec1's pointer targets; removing one changes the
data TUs, so it goes with a Wine proof), and the 10-16 offsets are `config/data-source-offsets.json`. Regenerating
gave the same items, spans, kinds, names, owners and pads as the committed file; 2,574 items' other fields moved
(`source_names` 2,467, `source_type` 534, `owner_by` 73, `flags` 70, `xrefs` 40, `data_refs` 33, `shared_objects` 31,
`interior` 30 (none on a vftable or RTTI item), `referenced` 23, `type` 8, `pointers` 1). data_gen's output from it:
include/decls/data/ byte-identical, the data TUs differ in 7 comment lines.

**Refreshing the offsets** (`--refresh-offsets`; `--compile` compiles tree TUs without a cached object, MSVC: run it
as a queue job). From the tree at 8205c9508 it reads 446 offsets (259 the same, 8 changed, 179 new, 118 gone): about
250 items would change span, mostly two words used as one (`DAT_x + 4`).

**Applied (data2, 2026-11-12).** config/data-source-offsets.json is the tree's (446 offsets from 2,675 objects, queue
job 72277). With it 99 items change span and 107 are folded into their neighbours: mostly 8-byte `.bss` pairs that
code reads as one 64-bit value (the name hashes the dynamic initializers write, `(u64)hi << 32 | lo` keys, the
performance-counter frequency DAT_00528380), small index-pair and pointer tables, a vector. An offset is how *our*
source spells an address, not only how the original laid it out, so four were reviewed and pinned in
config/data-items.json instead: a loop's end pointer (`DAT_00528388 + 16`), a source overlaying separate statics with
one struct (`DAT_0056b7c0 + 14392`), neighbouring arrays spelled as offsets of the first (`DAT_004e3768 + 48`), and the
audio codec table at 0x004cc254 (one 120-byte struct; neither carve had it). A source that named a folded word now
spells it `(*(T*)((char*)&DAT_x + 4))` (9 TUs: 13 matches blocks still MATCH, 8 equivalents re-proved). drift1's 15
`review` entries were decided in the same change: 7 removed (the evidence accepted: CDramaticCamera's and Branch.cpp's
strings, `int[4]` / `unsigned int` from the sources, the 2-byte string 0x004ca248 points at, now `const char*`), 3
kept with their reasons (an IMA ADPCM index table, a luaL_reg list, a header-static float run), 4 corrected (Lua's
log_2 byte table in lobject.cpp, the opcode table's kind, a string's owner, libpng's 8-byte signature) and 0x004d4143
replaced by one 2,480-byte stroke-font table at 0x004d4120. config/data-items.json: 64 entries (52 + 8 + the 4 pins
above), and `reviewed` keeps the reasoning of the ones removed.

**Limits seen on the way.** The code operands missed a base register plus displacement (`movzx eax, byte [eax +
0x426830]`, luaO_log2's table): such an item had no code reference unless a source named it (fixed by data3, below).
And the type votes read the previous config/data.json: regenerate from the committed file, not from an intermediate
run, or a folded item's neighbour loses the type only that run dropped.

**Base-register operands and the type spelling (data3, 2026-11-12).** `operand_ref` now takes a memory operand's
displacement whatever its registers (only a segment override is skipped); a base register makes the access indexed,
like an index register (the register picks an element or a field, so the access width says nothing of the item's
extent). Three rules keep the new references from carving on their own evidence what they cannot know:

- *GPU registers.* The D3D library writes NV2A's PGRAPH registers through a register holding the MMIO base
  (`mov [esi + 0x400750], eax`, 0xfd400750): base-register displacements into `NV2A_PGRAPH` (0x400000-0x401fff) from
  a library object are dropped (110 operands, all D3D's; game code's `[eax + 0x400524]` into the heap table stays).
- *Fields.* A base-register displacement less than `FIELD_GAP` (16) bytes after another of the same function is a
  field of the element the first starts (`[eax + 0x4399a0]` .. `[eax + 0x4399a7]`, one 8-byte element; ModeEntry's
  `+0`, `+4`, `+8`, `+9`): it counts for the item that holds it (xrefs, owner, `interior`), it does not start one.
- *Source types.* Where only base-register accesses index an item, the extent the sources declare (`float DAT_x[5]`)
  wins over "indexed, up to the next start", and an item read only through base registers keeps the sources' type
  (a field's width is not the element's: `Entry_32a260[]` stays, not `unsigned char[128]`).

An item pinned to another object in config/data-items.json now takes the items only it references along (its
strings follow the pinned owner, not the carve's), without becoming an anchor of the link-order pass.
The result: 390 new operands, 280 after the PGRAPH filter, on 116 addresses (60 of them fields); 17 port items gain their first code
reference and 16 more references, 27 library items gain one. Port items that change in a field data_gen reads:
3 spans (`TblEntry[]` 0x004061e8 8 -> 1,360 B, 68 entries to 0x00406738; HUDOverlay's `Lookup_d3f10[]` 0x004a0560
8 -> 248 B; d3dDisplay's `ModeEntry[]` 0x004d3508 12 -> 112 B; the unreferenced carve inside each is folded in),
0x00427620 `float[5]` table -> float_table, 16 owners moved by the new references (0x0041d7f8 to hulkfight/unk_1acb90.cpp,
0x004a0d38's string to FETextInput.cpp, 0x004d3508 and its RTTI neighbour to d3dDisplay.cpp, 0x004d4e50 and the
4 tables after it to d3dSimpleShader.cpp, 0x004d10bc to physics/unk_2e6780.cpp, 0x004dc360 to CCharacter.cpp, a zero word to its other neighbour),
and 3 regions now Bink's (library, so no longer emitted): its error strings 0x0043529c / 0x004352ac (lua/lbaselib.cpp
by guess) and the byte tables 0x004399a0..0x00439de8 (pure3d/Image32.cpp by guess). One decision was pinned:
0x004061e8 stays with global/unk_0b4cf0.cpp (data-items.json's `why`: it sits in unk_0b4cf0's mission-table run and
shares its strings; unk_0bc1e0 reads it as an extern); the rest is the evidence, recorded under `reviewed`.

The misspelled `unsigned int char` was fixed in decl_type on 2026-11-11, but the type votes read config/data.json, so
the 26 items (and 49 more spelled `unsigned int __int64`, `unsigned int short`, `unsigned int long long`) carried it
on. `canon_type` is now the one spelling, applied to every type the sources declare and every type read back from
config/data.json, so the old spelling cannot come back from either side; tests check both and that config/data.json
holds none. data_gen reads the corrected types: the 33 eight-byte `.bss` keys are `unsigned __int64` (were
`unsigned char[8]`), 0x004de9b0 `unsigned short[2856]`, 0x004dd8e4 and 0x0052a228 `unsigned char` scalars; every
source reaches them through `*(T*)&DAT_x`.

**Accesses past an item (scan1, 2026-11-13).** The inventory turns a source offset into one item of the range (`DAT_x
+ k`, above), but it never checked that an access *ends* inside its item, and an item boundary the evidence or a pin
put inside a structure stays invisible on the 32-bit builds, where the items are adjacent at the XBE's distances.
Natively each item is placed on its own, so such an access reads or writes another object: linux1's FUN_00277190
read the terminator of the 2-byte "D:" as `DAT_0042b50c + 2` and took another start-up path on Linux (8025b0aae).
`tools/data_overreach.py scan [--compile] [--all]` checks the tree's MSVC objects: every DIR32 relocation that names
a data item carries the constant offset as its addend, the instruction holding it gives the access width (an
address only formed by lea / an immediate is width 0; MSVC's inline `rep movs` / `stos` block copies count their
extent), and `[x + k, x + k + width)` must lie inside the item config/data.json starts at x (`size`; the `pad` after
it is not emitted). Reported: `over` (ends past the item), `pad` (ends in its padding), `addr` (an address formed
farther past the end than a loop bound), `before`, `indexed` (a register-indexed access whose constant part starts
past the end); informational (`--all`): `end` (one past the end, plus less than min(32, size): MSVC's loop bounds at
a field of one past the end) and `negidx` (an index's negative constant, `token2string[token - 257]`).
tests/test_data_overreach.py; a whole-tree run is one queue job (`--compile --jobs 8`, ~40 s on mac2 with its
object cache).

First run (HEAD ffb68ff69, job 77960; classes as the tool now has them): 25 reported, 15 informational, in 8 places.
All reported ones were real: one read of the next item (the IMA step table read as `DAT_0042ac18 + 64 + 4i`,
fixed in source, 9bbef387f) and five mis-sized items (fixed by data-items pins / a record, with the sources that
spelled the old boundaries): the audio formats (records.h `AudioFormatEntry DAT_004cc248[6]`; carved as a 1-byte
string, a pointer pair and data2's 120-byte struct at field `a` of entry 0), the 2-short word 0x004cdca8, the three
voice count arrays 0x004e3768 (80 bytes; data2's 28-byte span), Perlin's four noise tables from 0x0056b7c0 (2056,
2056, 6168 and 4112 bytes; data2's 1,024-byte span and a carve that made the permutation table 4 bytes), and the
three joint-name pointers 0x0048f6d0 (a 4-byte "string" and an unknown; config/data-pointers.json). After them the
scan reports nothing (job 78132); the informational ones are loop bounds and negative index constants.
data_gen: an initialized typed record's pointer field is now cast to the field's records.h type (was `void*`, which
only `void*` fields accept).
