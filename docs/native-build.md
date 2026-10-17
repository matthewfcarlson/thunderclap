# Native build: how far the tree is from clang

Roadmap step 6.1 ([roadmap.md](roadmap.md#6-native-build), [shipping.md §1](shipping.md#1-the-source-tree-roadmap-steps-2-and-4)):
the first native build is 32-bit x86 under clang. This page measures how far the merged source tree
([source-tree.md](source-tree.md)) is from that, sorts what's in the way into categories, and turns them into a
prioritized fix list. Measured 2026-10-17.

```sh
build/venv/bin/python tools/clang_probe.py              # snapshot (if missing), compile 6 configurations, classify, link probe
build/venv/bin/python tools/clang_probe.py --snapshot   # refresh the snapshot after a complete tools/build_tree.py run
build/venv/bin/python tools/clang_probe.py --only src/game/global/CAction.cpp   # one TU's diagnostics, every configuration
```

Cold, the first run takes 10-15 minutes (4 compiler processes); a warm run takes 30 s. Everything goes to `build/clang-probe/`:
`report.json` (counts, categories with example sites, scans, link probe), `undefined.txt` (every undefined symbol with
its group and demangled name), `cache/` (per-TU results and objects) and `snap/` (the tree being probed).

## What was measured

- **Input:** a copy of the tree from the last complete build (2026-10-16 18:44, `build/tree/`: 2,498 TUs, 26,395
  verified functions, 19,952 merged / 5,805 wrapped / 638 isolated), `include/` as committed (HEAD `7b9f6642`), and the
  1,078 data TUs (`build/data/src/`). It's a copy because `migrate_data.py` and `build_tree.py` were rewriting the
  live tree during the run. Nothing in `build/tree/` or `include/` was changed.
- **Compiler:** Homebrew clang 22.1.8. No system headers are needed: the tree includes nothing from the CRT.
- **Configurations** (all compile every TU; `-ferror-limit=0`; the warnings in `COMMON` in the tool):

| config | flags | answers |
|---|---|---|
| `msvc` | `--target=i686-pc-windows-msvc -fms-extensions -fms-compatibility -fms-compatibility-version=13.10 -std=c++14 -c` | what a clang build that keeps MSVC's ABI (mangling, vftable layout, `__thiscall`) needs. Its objects feed the link probe |
| `gnu` | `--target=i686-unknown-linux-gnu -fms-extensions -std=gnu++17 -fsyntax-only` | the MSVC-only constructs that `-fms-compatibility` was hiding (two-phase lookup, predeclared `size_t`, ...) |
| `gnu64` | the same for `x86_64-unknown-linux-gnu` | what else breaks with 8-byte pointers |
| `*-poc` | the three above on a patched copy (`build/clang-probe/poc/`) | the effect of the cheap fixes (fix 1 below) |

## Headline numbers

| config | TUs compiling | engine | game | platform/xbox |
|---|---|---|---|---|
| `msvc` | **2,378 / 2,498 (95.2%)** | 471 / 495 | 1,889 / 1,965 | 18 / 38 |
| `gnu` | 1,676 (67.1%) | 461 | 1,197 | 18 |
| `gnu64` | 797 (31.9%) | 332 | 450 | 15 |
| `msvc-poc` | 2,382 | 471 | 1,893 | 18 |
| `gnu-poc` | **2,316 (92.7%)** | 462 | 1,836 | 18 |
| `gnu64-poc` | **2,307 (92.4%)** | 458 | 1,832 | 17 |

- With MSVC's dialect and ABI, clang already compiles 95% of the tree. The 120 failing TUs come down to a few
  causes, and **one cause is 66% of them**: wrapped sources that redeclare an `extern "C"` name with a different type.
- One line in `include/gen/global.h` (`enum script_state;` has no underlying type) breaks 692 TUs on every non-MSVC
  target. Together with a 15-line compatibility header and spelling `operator new`'s parameter as `size_t`, the
  Linux targets go from 67% / 32% to 93% / 92%.
- **No inline assembly, SEH or `__declspec(naked)` anywhere in the tree.** x87 code survives only as `volatile`
  rounding pins (2,288 in 531 sources).
- **Linking is the real distance, not compiling.** The 2,378 compiling TUs plus the data TUs leave **30,130
  undefined symbols** (39,855 references). 79% of them (23,721) are calls under a name, class or signature other than
  the one the callee's definition has, or under a stub name that only the relocation resolves. The verification build never sees this, because `compare.py`
  masks relocations and `equiv.py` binds callees by address. Only 299 symbols are CRT or platform imports.

## Categories

Cells are *sites / failing TUs / sources* (a site is a distinct file:line; a header line counts once however many
TUs include it). "Producer" is what wrote the line: a source verbatim in a `fn_<addr>` namespace (wrapped), a
merged definition, the TU's merged declarations, a hoisted tree header, or `include/gen`.

**Errors**

| category | `msvc` | `gnu` | `gnu64` | `gnu-poc` | producer | what it is |
|---|---|---|---|---|---|---|
| `extern-c-redeclared` | 579 / 79 / 420 | 578 / 78 / 419 | 582 / 79 / 422 | 578 / 78 / 419 | wrapped sources (356 matches, 222 equivalent) | the same `extern "C"` function or global declared with another type in another `fn_` namespace (MSVC 7.1 accepts it, clang doesn't). 369 are `FUN_` names (`FUN_00344e74` = `__RTDynamicCast` 53, `FUN_0027b020` 45, `FUN_002672f0` 22), 191 invented names for one address (`Find`, `Lookup`, `Check`, `fetch`), 22 `DAT_` |
| `calling-convention-redeclared` | 4 / 4 / 4 | same | – | same | wrapped | the same, differing only in calling convention |
| `duplicate-definition` | 68 / 22 / 68 | same | same | same | wrapped matches | clones that still define their donor's name: 61 `pure3d::d3d*Shader::vfunc_N` clones each define `extern "C" FUN_0008ceb0` (namespaced targets, which `reconcile_stubs.py` skips) |
| `enum-forward-declaration` | (warning) | 1 / **692** / 0 | 1 / 692 / 0 | fixed | `include/gen/global.h:4181` | `enum script_state;` (an MS extension: no underlying type) |
| `placement-new-undeclared` | – | 70 / 4 / 4 | **4,313 / 1,179 / 1,259** | fixed (9 left on 64-bit) | everywhere | 1,311 sources declare `operator new(unsigned int, ...)`; on 64-bit, `size_t` isn't `unsigned int`. 156 sources also `typedef unsigned int size_t;` (hoisted into `common.h`) |
| `size_t-not-predeclared` | – | 4 / 4 / 4 | 4 / 4 / 4 | fixed | wrapped equivalent | MSVC predeclares `size_t` |
| `exception-spec-mismatch` | (warning) | 64 / 64 / 40 | 7 / 7 / 6 | 64 / 64 / 40 | merged declarations, wrapped | `void* operator new(size_t) throw();` against the implicit declaration |
| `typeid-needs-typeinfo` | 18 / 4 / 4 | same | same | other-error | isolated matches | `typeid` with the source's own `class type_info` (MS ABI's global `type_info`; Itanium wants `std::type_info`) |
| `msvc-template-spec-syntax` | 38 / 16 / 38 | same | same | same | wrapped matches | `int fight::ConditionFactoryCasterTemplate<X>::vfunc_0(void*)` without `template <>` (clone sources) |
| `dependent-base-lookup` | 9 / 4 / 9 | 69 / 24 / 49 | 47 / 22 / 43 | 69 / 24 / 49 | wrapped equivalent | `Closure0` stubs use `Fn` from their dependent base `Method0<T,R>` (two-phase lookup) |
| `case-narrowing` | 38 / 2 / 7 | same | same | same | wrapped equivalent | `switch (int) { case 0xce85a963: }` (C++11 narrowing) |
| `goto-over-initialization` | (warning) | 8 / 5 / 5 | same | same | asm-shaped sources | `goto` past an initialized local |
| `msvc-for-scope` | 2 / 2 / 2 | same | same | same | 2 equivalent sources | a `for` variable used after its loop (`/Zc:forScope-`) |
| `address-of-temporary`, `type-defined-in-return-type`, `register-keyword` | 6 / 3 / 5, 5 / 2 / 4, – | +2 / 2 / 2 `register` | same | same | sources | `&T()`, `struct W {...} *f();`, `register` (gone in C++17) |
| `other-error` | 8 / 7 / 7 | 9 / 8 / 8 | 18 / 11 / 12 | 28 / 13 / 13 | sources | `short wchar_t`, a call with mismatched argument types, an unnamed typedef, a `DAT_` used but never definable (`fn_000d4b60`) |

**Warnings that matter** (they don't stop compilation)

| category | sites / sources (`msvc` unless noted) | why it matters |
|---|---|---|
| `64bit-pointer-int-cast` (`gnu64`) | **4,779 / 2,981** (in 1,103 TUs) | pointers through `int` and back: the bulk of the 64-bit gap (an error without `-fms-extensions`) |
| `ub-null-this-or-reference-check` | 19 / 16 | `if (this)`, `&p->field != 0`: clang folds them to true. `-fno-delete-null-pointer-checks` |
| `ub-array-bounds` | 5 / 5 | `pad[77]` in `char pad[77]`: a field read through the stub's pad |
| `ub-missing-return`, `ub-uninitialized`, `ub-unsequenced`, `ub-vptr-memaccess`, `ub-pure-virtual-in-ctor`, `calling-convention-cast` | 2, 1, 2, 3, 1, 1 | each a real behaviour difference under clang's optimizer; per-source review |
| MS extensions tolerated by `-fms-extensions` | explicit constructor calls 126 / 86, exception specs 121 / 39, dependent-base lookup 41 / 40 (`msvc` only), `goto` 8 / 5 | build with `-fms-extensions` (all clang targets accept it), or fix per source |

**Source scans** (constructs no diagnostic reports; `report.json` → `scans`)

| scan | occurrences / TUs / sources | for |
|---|---|---|
| hand-written vptr stores (`*(void**)this = &g_vftable_x`, `vptr = ...`) | 2,115 / 891 / 1,845 | link (vftable by address), any non-MSVC ABI |
| vftables named as symbols (`g_vftable_*`) | 2,005 / 585 / 985 | same |
| virtual calls through a hand-written vftable (`vptr[5]`) | 753 / 292 / 390 | same: slot numbers are the MS ABI's |
| virtual members of TU-local stub classes | 82,632 / 1,983 / 3,893 | Itanium puts two slots per virtual destructor, so stubs that call by slot only work under the MS ABI |
| `__RTDynamicCast` called by address with RTTI descriptor addresses | 792 / 163 / 379 | needs the descriptors by symbol (or `dynamic_cast`) |
| integers in the XBE's ranges cast to pointers / function pointers from integers | 75 / 27 / 54, 19 / 4 / 13 | absolute addresses (NV2A methods written as pointers, `(void*)0x26dc20` fiber starts, D3D state words) |
| `*(T*)&x` type punning | 2,854 / 350 / 835 | strict aliasing: `-fno-strict-aliasing` (2,443 of them cast a `DAT_` global: the `data-cast` rewrites of [data.md](data.md#the-rewrite)) |
| explicit `char pad[N]` layouts | 24,747 / 1,355 / 3,572 | 64-bit; include/gen adds 889 `_pad_` gaps and 589 pointer-typed `f_XX` fields at 32-bit offsets |
| `__int64` / explicit calling conventions / `__declspec` | 2,715 / 1,000, 2,689 / 1,640, 521 / 297 sources | fine on 32-bit (clang accepts all three with `-fms-extensions`); conventions are ignored on 64-bit |
| `/GS` cookie calls written out | 714 / 317 sources | drop at the shim (`__security_check_cookie` → no-op) |
| inline asm, SEH | 0, 0 | |

## Link probe

`llvm-nm` over the 2,378 compiling `msvc` objects plus the 1,078 data TU objects (all of which compile under clang):
every referenced symbol that no object defines, grouped. ("in `fn_`" = the reference comes from inside a wrapped
source's namespace, so even a correct C++ declaration gets the namespace in its mangled name.)

| group | symbols | references | in `fn_` | addresses |
|---|---|---|---|---|
| function under an invented/stub name, no address in the symbol (`Base_135f40::Fin`, `Obj_150480::f1`, `helper`) | **13,221** | 17,427 | 4,114 | (known only from the relocation) |
| function verified and compiled, but referenced under another symbol | **10,500** | 11,873 | 5,242 | 4,253 |
| function verified, but its TU fails under clang | 2,689 | 2,779 | 1,215 | 1,513 |
| vftable / RTTI by address (`g_vftable_*`, `DAT_` of a `??_7`/`??_R0` item) | 1,954 | 2,426 | 502 | 576 |
| function not yet verified (incl. vfuncs of include/gen classes nobody defined) | 1,068 | 1,266 | 601 | 280 |
| data: emitted item referenced under a C++ name | 288 | 315 | 237 | 84 |
| CRT / C++ runtime (`type_info` vftable 1,060 refs, `operator new`/`delete`, `terminate`, `__RTDynamicCast`) | 168 | 3,477 | 63 | 9 |
| platform imports (D3D, DSound, XAPI, kernel, XPP, Bink; by name or by library address) | 131 | 134 | 62 | 15 |
| data: library (CRT/XDK) data | 81 | 128 | 41 | 39 |
| data: not an emitted item (interior / outside the inventory) | 27 | 27 | 24 | 21 |
| library code by address, unnamed | 3 | 3 | 0 | 3 |

Of the 10,500 "referenced under another symbol": 5,242 are declared inside a `fn_` namespace, 3,898 as a member of
the caller's own stub class (`Object::FUN_000b4c10`), 1,199 as free functions whose signature or linkage differs
from the definition's (`?FUN_00011070@@YAHM@Z` against a definition returning `void`), and 161 with C linkage against a C++
definition. The platform shim surface agrees with [platform-boundary.md](platform-boundary.md): 131 import symbols
plus 81 library data symbols (D3D state words, CRT globals), to be implemented in `platform/sdl`.

## Prioritized fix list

The order is set by what unblocks a linkable 32-bit image soonest. Sizes are estimates.

**0. Choose the first native target: `i686-pc-windows-msvc` (clang-cl + lld-link).** The verified code is
MS-ABI code: 82k virtual declarations in stub classes, 753 hand-written vftable calls and 2,115 vptr stores rely on
MSVC's vftable layout (one slot per virtual destructor, no offset-to-top), on `__thiscall`, and on MS mangling (which
fixes 5 and 6 below use to alias by name). Compiling for Itanium (Linux, macOS) works after fix 1, but it silently
changes the slot numbers of every stub with a virtual destructor. So the first link should be Windows x86, run
natively or under Wine. Linux and macOS come after fix 5b, once calls go through the real include/gen classes. This
narrows the "Linux or Windows" choice in roadmap step 6.1 rather than reversing it.

**1. Compatibility header + three generator one-liners** (half a day; proven in `build/clang-probe/poc/`):
- `include/compat/native.h` (force-included by the native build only): `typedef __SIZE_TYPE__ size_t;` off MSVC,
  `type_info` / `std::type_info`, later the CRT bits the shim provides.
- `gen_headers.py`: emit `enum script_state : int;` (or an empty definition) for enums named only in declarations
  (692 TUs on every non-MSVC target).
- `gen_tree.py`: global `operator new`/`delete` declarations and `typedef unsigned int size_t;` stop coming from
  sources. Emit one canonical set (`size_t`, the `throw()` form each TU's codegen needs) from a gen_tree prelude, so
  `common.h` loses its 32-bit `size_t`. MSVC output doesn't change (`size_t` is `unsigned int` there), so
  `build_tree.py` should show 0 changes. This also covers the 64 `exception-spec-mismatch` TUs on gnu (not in the
  PoC).
- Flags for every native build: `-fms-extensions -fno-strict-aliasing -fwrapv -fno-delete-null-pointer-checks`, and
  on 32-bit `-mfpmath=387` for the first replays: x87 is what the `volatile` pins and the replay checkpoints assume.

Measured: gnu 1,676 → 2,316 TUs, gnu64 797 → 2,307, msvc 2,378 → 2,382.

**2. `extern "C"` redeclarations in wrapped namespaces** (gen_tree, about 150 lines plus a tree build; 79 TUs, 60 of
them fail on nothing else). For a wrapped source whose declaration of a C-linkage function or global differs from the
TU's canonical one, gen_tree emits a namespace-local forwarder instead of the declaration:
`static inline R name(A a) { return ((R (__cdecl*)(A))&::name)(a); }`, or for data `static T& DAT_x = *(T*)&::DAT_x;`.
MSVC should turn a call through a cast function address into the same direct `call`; the regression rounds of
`build_tree.py` would catch any change. Do it under a `--native` switch first if a tree-wide MSVC re-verification can't be
afforded. Invented names for one address (`Find`/`Lookup`/`Check` = `__RTDynamicCast`, 191 sites) collapse into
`FUN_<addr>` once fix 5a gives every relocation its address.

**3. Clones defining their donor's name** (68 sources, 22 TUs). Extend `reconcile_stubs.py`'s `clone-free` rule to
namespaced vfunc targets (`pure3d::d3dLightMapShader::vfunc_16` defining `FUN_0008ceb0`), or route them through
`migrate_gen.py` gen-swap. Check with `compare.py`.

**4. Per-source edits** (about 130 sources, a day for one agent plus re-verification): `template <>` on 38 clone
specializations (mechanical; extend migrate_gen's `clone-template`), `typename Method0<T,R>::Fn` in the Closure stubs
(49 sources on gnu, mechanical), `case (int)0x...` (7), for-scope (2), `goto` past initialization (5), `register` (2),
`&T()` (5), types defined in return types (4), `type_info` (4), the ~13 others. Each changed source is re-checked with
`compare.py` or `equiv.py`. Most of them are wrapped or isolated today, so the edits also help the MSVC tree merge.

**5. Callee binding: the link gap** (23,721 of 30,130 undefined symbols).
- **5a. A binding map from the verification build** (a new tool, about 500 lines, 2-3 days). `build_tree.py`
  already compiles every TU with MSVC and checks it against the XBE. Record each relocation's symbol and the XBE
  address it must resolve to (`verify_relocs.py` does this for matches; for equivalent/ use the address `equiv.py`
  binds), map each address to the symbol of its definition in the tree (`build_tree.mangle_prefixes`), and emit a
  linker alias file (`/alternatename:<referenced>=<defined>` for lld-link). Every stub name, wrapped-namespace name
  and signature variant is the same machine-level call that the byte match or behaviour check proved, so on 32-bit
  MS ABI the alias is exact. This turns 10,500 + 13,221 + 1,954 (vftables, below) symbols into resolved references
  without touching a source. It's the fastest way to a linked image, but it only holds for the MS ABI and 4-byte
  pointers.
- **5b. Canonical prototypes** (the long-term fix, and the same work as header reconciliation). Declare every
  verified function once, from its definition, in `include/decls/` (generalising `decls/address.h`), and rewrite
  callers onto it with a `migrate_*` family like `pin-decl`. Needed for Itanium and 64-bit, where an `int`
  parameter declared for a pointer really differs. The link probe's "referenced under another symbol" and "stub name"
  counts are the progress measure.

**6. vftables and RTTI by address** (1,954 symbols, 576 addresses; 1,845 sources store vptrs by hand).
- 6a (MS ABI, about 1 day): `config/data.json` names every vftable and RTTI item by its MSVC symbol (`??_7X@@6B@`,
  `??_R0...`), and clang emits identical structures from include/gen (the `gen_headers.py --probe` TU constructs every
  class). So alias `g_vftable_<addr>` / `DAT_<vftable addr>` to the clang symbol. The 792 `__RTDynamicCast` calls by
  descriptor address then resolve against the host CRT's own `__RTDynamicCast` with clang's descriptors.
- 6b: constructors and non-trivial destructors in include/gen, so sources stop storing vptrs (next steps 1-2 of
  [source-tree.md](source-tree.md#next-steps-ranked)). Required for Itanium.

**7. Platform shim and CRT** (roadmap step 6.1 proper): 131 platform symbols and 81 library-data symbols behind the
four seams, plus the CRT. On `i686-pc-windows-msvc` the CRT is the host's (`operator new`, `type_info`, `terminate`
and `__RTDynamicCast` exist with the same names). The 75 absolute-address casts (NV2A methods written as pointers,
D3D state words at `0x39de20`, fiber starts by address) are all in platform/xbox and seam code, which the SDL layer
replaces anyway.

**8. Unverified functions** (1,068 symbols: 280 by address, the rest include/gen vfuncs nobody defined). The holes of
roadmap step 3; the link probe lists exactly the ones a linked image needs (`undefined.txt`, group "not yet verified").

**9. 64-bit (sized, not first):** 4,779 pointer↔int casts in 2,981 sources, 24,747 explicit pads in 3,572 sources,
889 pads and 589 pointer fields in include/gen, mixed `DataLayout_` data structs ([data.md](data.md#what-the-native-clang-build-needs-from-data)),
loaders of 32-bit file formats. After fix 1, 64-bit *compiles* as well as 32-bit (2,307 TUs). The gap is silent layout,
which only real types close (5b, 6b, typed globals).

## How this feeds header reconciliation and typed globals

The native gaps and the MSVC tree's merge failures are the same disagreements seen from two sides:

- **Wrapped blocks** (5,805 functions; `gen_tree --stats`: 4,035 refused class merges, 365 blocks wrapped by the
  merged-layout check, 466 include/gen sources isolated) are where a source's declarations disagree with its TU's.
  For clang, every such disagreement on a *callee* is also a link mismatch: 12,101 of the 30,130 undefined symbols come from inside
  `fn_` namespaces. Fixes 2 and 5b remove wrap reasons and link mismatches together. A source whose declarations
  become the canonical ones merges in the MSVC tree and links natively.
- **Refused class merges** are stub classes of one object that disagree. On the native side the same stubs are the
  13,221 stub-member symbols (members declared by callers and defined nowhere under that name) and the 82k
  slot-order-dependent virtual declarations. Moving them onto include/gen classes (migrate_gen gen-swap for
  non-owner stubs, next step 4 of source-tree.md) is what makes the code ABI-portable.
- **Typed globals and tables:** 288 data symbols are referenced under C++ names (237 from `fn_` namespaces: the
  pinned `DAT_004dd700` & co. while `decls/address.h` declares them with C++ linkage; the `extern "C"` change in the
  working tree fixes those). The 2,854 `*(T*)&x` casts are mostly `data-cast` rewrites. Typed declarations in
  `include/decls/data/` (stub classes per BSS object) remove them and the strict-aliasing exposure; until then
  `-fno-strict-aliasing`.
- **Suggested gate:** run `tools/clang_probe.py` after each `build_tree.py` run (`--snapshot`). The numbers to watch:
  `msvc` TUs compiling (target 100%), undefined "referenced under another symbol" + "stub name" (target 0 after 5b),
  and `gnu-poc` TUs compiling (Itanium readiness).

## Caveats

- `-O0` objects. Optimization changes nothing in the undefined-symbol set except inline functions that are never
  emitted, so the probe slightly *over*-counts references from inline helpers.
- The 120 failing `msvc` TUs contribute no references, and their definitions count as missing ("its TU fails").
- Groups come from symbol names: `FUN_`/`DAT_` addresses, `build/functions.csv` names, `build/port/platform_calls.json`
  and a CRT list. A stub name that happens to equal a functions.csv name is classified by that name.
- The snapshot predates the working-tree `extern "C"` change to `include/decls/address.h` (deliberately reverted to
  HEAD in the snapshot, so that it matches the tree it was built with).
