# Data as source (`.rdata` / `.data` / `.bss`)

Roadmap step 4, data half: the game's globals, constant tables, float pools, strings and vtables as source.
Code half (the source tree): [source-tree.md](source-tree.md). Written 2026-10-16. Numbers are from that day's
run (they move a little as farm lanes add sources, see [Reproducing](#reproducing)).

```sh
build/venv/bin/python tools/data_inventory.py     # config/data.json + build/data/inventory-report.json  (~5 s)
build/venv/bin/python tools/data_gen.py           # data TUs, include/decls/data/, compile + byte-check  (~25 s warm)
build/venv/bin/python tools/data_gen.py --only global/CAction.cpp      # one object
build/venv/bin/python tools/build_tree.py --rounds 16 --data           # the tree build plus the data TUs and a link check
```

| Output | What | Tracked |
|---|---|---|
| `config/data.json` | the inventory: one line per item (address, size, kind, name, type, owner, xrefs) | yes (no game bytes, no string text) |
| `include/decls/data/<layer>/<dir>.h` | `extern "C"` declarations of every emitted item, per layer directory | yes (names, types, sizes only) |
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
   (capstone over all of `.text` and the library sections, ~8 s, cached), every `DAT_xxxxxxxx` name the
   `matches/` and `equivalent/` sources use, and every aligned data word whose value is an address in the range.
   Filters, because a value in the range isn't always an address: immediates used by `cmp`/`and`/`add`/... are
   constants, an unaligned immediate is an address only if a string starts there, a BSS "address" whose bytes are
   ASCII (`0x504c41` = "ALP") with no memory operand is a FourCC (2 sources even named such constants `DAT_`), and a
   data word whose bytes are text isn't a pointer.
3. **Extents.** A string swallows starts inside it (pointers to a suffix, `"xRET" + 1`); a source offset past an
   address name (`DAT_x + 8` in verified code, read from the relocation addends of the last tree build's objects)
   makes one item of the range. An item ends at the next start, or earlier where the evidence says so: the FPU
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

**Form, per item** (all `extern "C"`, so the C linkage name is the inventory name and types don't enter the
symbol): strings `const char s_x[N] = "...";` (octal escapes, no trigraphs), wide strings `unsigned short[]`,
floats and doubles as decimal literals that round-trip (`%.9g` / `%.17g`; NaN, infinities and denormals would fall
back to integer words: none occur), scalars and tables with the sources' primitive type when its size fits, else
`unsigned int[]` / `unsigned char[]`, pointers `const void* const p = (const void*)((const char*)&target + off);`,
mixed items as a `#pragma pack(1)` struct of byte runs and pointer words, BSS `extern "C" { T x[N]; }`. `const`
for `.rdata`, non-const for `.data`. A pointer names its target by inventory name (`FUN_<addr>` for code).

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
`extern "C" { ... }` free. Mixed items are declared through a forward-declared `DataLayout_<addr>` struct (sources
take its address). The headers carry names, types and sizes only, no contents.

## 3. Wiring plan (follow-up, not done here)

Today a verified source declares `extern "C" char DAT_0041dcac[];` and the tree's objects reference
`_DAT_0041dcac` (or a C++-mangled `?DAT_0041dcac@@3PADA`). The switch is a `migrate_gen.py`-style rewrite:

1. **Map every address name to an item.** `config/data.json` gives `DAT_<addr>` -> item + offset (`interior` lists
   the addresses sources and code use inside an item). Kinds: exact item start; inside an item (`DAT_x+4` style:
   rewrite to `((char*)&item + 4)` with the source's type); code-owned (a vftable or RTTI address: the rewrite
   is to the class, `include/gen/`, not to data); library (stays an address name, shimmed by the platform layer).
2. **Per source, token-level** (`tools/cxx_items.py`, as `rename_placeholders.py` / `migrate_gen.py` do): drop the
   source's own `extern ... DAT_x` declaration, `#include "decls/data/<layer>/<dir>.h"`, rename uses to the item
   name, and add a cast where the source's type differs from the declared one (`*(int*)&flt_x` when a source
   loads a float with integer moves). Logged (`build/migrate-data.log`), originals kept, list of changed files.
3. **Verify every rewrite** as migrate_gen does: matches/ must still `compare.py` MATCH (relocations are masked,
   so a renamed data symbol can't change the bytes; this catches type changes that change codegen), equivalent/
   must stay EQUIVALENT under `equiv.py --inputs 3000` (equiv.py binds address names by address today; it needs the
   inventory to bind item names to their addresses: one lookup in `config/data.json`).
4. **Then fold**: once an object's sources use the names, `gen_tree.py` puts its data definitions at the top of
   the object's code TU (or keeps the `.data.cpp` sibling; either way one object), and `build_tree.py --data`
   reports `by_name` for all of them.

`tools/build_tree.py --data` measures where this stands (link check of the tree's objects against the data TUs):

| reference from a tree object to `DAT_<addr>` | references |
|---|---|
| all (7,200; 5,676 of them C++-mangled, e.g. `?DAT_0048e058@fn_00014d40@@3MA`, need the declaration) | 7,200 |
| resolves by name today (a data TU defines the same C symbol: scalars and BSS keep `DAT_<addr>`) | 260 |
| an emitted item's start: resolves after the rename | 5,225 |
| inside an emitted item (`DAT_x` = item + offset) | 141 |
| a vftable or RTTI address (code-owned: the rewrite goes to the class, not to data) | 1,303 |
| library data (CRT/XDK globals, e.g. `DAT_004d9968`): stays an address name for the platform shim | 269 |
| outside the data sections (`$$XTIMAGE`) | 2 |

53 addresses are *defined* by tree objects (sources that define the global themselves, `unsigned __int64 DAT_x;`);
50 of them are also data TU items, so those definitions move out of the sources in the rewrite.

**Tree build with `--data`** (2026-10-16, 20 minutes): **2,502 / 2,502 TUs compile, 21,129 / 21,129 matches still
match, 4,564 / 4,564 equivalent/ functions compile, 4,517 with code identical to their standalone build, 47 wrapped
ones can't be told, 0 differ**; the data TUs (1,078) compile and every item verifies. The data TUs are separate
objects, so they can't change the code TUs; the option adds their check and the link check to
`build/tree/report.json` (`data`).

**What the native (clang) build needs from data:**

- **No absolute addresses.** Every `DAT_xxxxxxxx` becomes a named object defined in a data TU; every pointer
  word inside data becomes a pointer initializer (`&target + off`), which is what `data_gen.py` already emits.
  Pointer tables are real pointer arrays, relocated by the native linker.
- **32-bit first** (as the code): the tables keep their byte layout, and `#pragma pack(1)` structs keep pointers
  at 4-byte offsets. For 64-bit, pointer-containing items need their real types (a `const void*` grows to 8 bytes
  and shifts every later field), so mixed `DataLayout_` structs have to become typed structs first.
- **Names across linkage:** pointers to functions use `FUN_<addr>`; the native build needs the function's real
  symbol (a C++ member such as `CFoo::vfunc_3` can't be named by an `extern "C"` alias). The inventory knows the
  target address, so the generator can emit the real name once functions.csv names are spellable.
- **vftables and RTTI** come from the compiler (both MSVC and clang); the native build never needs the original
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
4. **Strings and floats that sources will write as literals** become dead items; the generator should skip items
   whose only references are from sources that no longer name them.
5. **Typed tables:** `table`, `struct` and `unknown` items are bytes and words; real element types come from
   the code that indexes them (field mining, as `gen_headers.py --mine` does for classes).
6. **`DAT_` names for constants:** a few sources declare FourCC/hash immediates as `DAT_` globals; the inventory
   ignores those names (`false_source_names`) and the migration must turn them back into constants.
7. **Library-owned data referenced by game code** (269 references, e.g. CRT globals): belongs to the platform shim.
8. `config/data.json` is about 9 MB (46k lines). RTTI items (21k) could move to a derived listing if the size
   matters.

## Reproducing

The inventory reads the matches/ + equivalent/ sources (their `DAT_` names and types) and the source offsets of the
last *complete* tree build (`build/data/source_offsets.json`; re-read only when nearly every TU of the current
`build/tree/manifest.json` has its object, because `build_tree.py` regenerates the tree as it runs). New farm
sources therefore shift a few items between runs; the per-kind totals move by a handful.
