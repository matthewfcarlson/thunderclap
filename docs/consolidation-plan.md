# Class consolidation and renames (rn1)

Plan for moving the sources' stub classes onto the game's real classes: which stub is which class (a rename map
with evidence), how each stub fits its include/gen/ class, why the tree's functions are still wrapped, and the
rewrite batches that remove those reasons, in order of risk and size. Background: [source-tree.md](source-tree.md)
(stub reconciliation, include/gen migration), [wine-build.md](wine-build.md) ("How this feeds header
reconciliation and typed globals", "Bridges to remove"), [headers.md](headers.md). Measured 2026-10-19 on a
snapshot of the working tree (27,474 verified functions in the tree).

```sh
build/venv/bin/python tools/rn_map.py                 # rename map: build/rn1/rename-map.{json,tsv} (~10 s)
build/venv/bin/python tools/rn_layout.py --rebuild-db # include/gen layouts (clang) + stub fit: header-db, layout-fit,
                                                      #   header-additions (build/rn1/, ~5 s)
build/venv/bin/python tools/rn_plan.py --state S      # why functions are wrapped, per name: build/rn1/plan.json (~70 s)
build/venv/bin/python tools/rn_plan.py --batches      # build/rn1/batches/b1..b3.json
build/venv/bin/python tools/rn_plan.py --refine build/rn1/batches/b1-unclash-matches.json --state S \
    --bindings build/native/bindings.json --refine-out build/rn1/batches/c1-unclash-matches-refined.json
                                                      # generator in the loop: drop what costs merges or links (~5 min)
build/venv/bin/python tools/migrate_gen.py --family rn --batch build/rn1/batches/c1-unclash-matches-refined.json --apply
build/venv/bin/python tools/migrate_gen.py --family rn --batch build/rn1/batches/c3-equivalent-refined.json --apply --equivalent
build/venv/bin/python tools/rn_plan.py --metrics BEFORE_ROOT AFTER_ROOT list.txt   # pads / stub virtuals / casts
```

`S` is a fallback state (`build/tree/state.json` of the last full build). All outputs under `build/rn1/` are
regenerated. `tools/rn_map.py` and `--refine --bindings` need the binding map of a strict Wine link of the tree in
question (`build/native/bindings.json`, `tools/wine_link.py`): for a batch on top of another, the link of the tree
with the earlier batch applied.

## 1. The rename map (`tools/rn_map.py`)

A *stub* is a class a source defines itself: placeholder-suffixed names (`Obj_2d5ec0`), invented names (`Action`,
`Node`), global stubs of RTTI names (`NonCopyable` for `pure3d::NonCopyable`, kind `rtti-short`) and stubs that use
the RTTI name itself (`rtti-named`). One entry per (stub name, source): 54,210.

**Evidence** (strongest first). `=` means "the stub is X", `<=` "X or derived from X", `>=` "X or one of its bases".

| evidence | relation | how |
|---|---|---|
| `self-vfunc` | `=` | the source's own function is a member of the stub and `build/functions.csv` names its address `X::vfunc_N` |
| `self-vptr` | `=` | the source's own function is a member of the stub and the original stores vftable pointers through `this` at offset 0 (ecx, followed through register moves): the most derived of the stored classes (one inheritance chain). A factory that builds a `new X` inline stores through another register and doesn't count |
| `vftable` | `=` | the stub's `??_7S@...` symbol is bound by the strict Wine link (relocation position) to the game's vftable of X (`config/data.json`) |
| `base` | `=` | the stub is the source's base class of a stub known to be X (high or medium): X's primary base (RTTI, offset 0) |
| `call` | `<=` | a member function the source calls on the stub is bound to address A whose owner is X (one of the above for A's own source, or A is `X::vfunc_N`) |
| `called-as` | `>=` | the stub defines A, and a stub known to be X (high) calls A |

Owners of addresses propagate to a fixed point (10 rounds; evidence is only added, never withdrawn). Confidence:
**high** = only direct evidence on the class itself (`self-vfunc`, `self-vptr`, `vftable`) and nothing against it;
**medium** = one step from it (the base of a high stub; every call bound to a class without derived classes; two
callers that agree; or, among the classes that fit, the one its object file is named after); **low** = a bound or
conflicting evidence. Where two kinds of direct evidence exist for one stub they agree 775 of 831 times; the 56 that
differ are mostly a source whose stub carries a base class's name (`CAction`) for a derived class's destructor
(`CAutoTargetAction`, stored first): the most derived class wins at medium, different chains go to low.

| kind | high | medium | low | none | entries |
|---|---|---|---|---|---|
| suffixed (`Obj_2d5ec0`) | 668 | 1,878 | 799 | 26,871 | 30,216 |
| invented (`Action`, `Node`) | 285 | 672 | 1,064 | 7,894 | 9,915 |
| rtti-short (global `NonCopyable`) | 2,430 | 684 | 118 | 5,407 | 8,639 |
| rtti-named (the RTTI name itself) | 2,561 | 669 | 93 | 2,117 | 5,440 |
| **all** | **5,944** | **3,903** | **2,074** | **42,289** | **54,210** |

High + medium: 9,847 entries (4,681 distinct stub names) name 2,568 real classes; 8,631 of them are include/gen/
classes, 1,216 template instantiations (include/gen/ has the families, not the instantiations); the renames touch
6,652 sources (`touches` in the map: a suffixed stub copied into other sources goes with them). The "none" bulk is
helper structs of non-polymorphic classes (no RTTI, no vftable: `Vec3_2d53d0`, `Holder44_835a0`) and stubs that only
call `FUN_` functions nobody has placed in a class yet; they keep their placeholder names.

Examples: `Obj_1d1e0` = `CAction` (high, self-vptr: the function stores CAction's vftable and tail-calls
`fight::Action`'s destructor); `CTrack` in `matches/0x0023d3d0.cpp` = `fight::ConditionFactory` (medium, base of
`CSweepTrack_23d3d0` = `fight::ConditionFactoryTemplate<fight::FalseCondition>`, high, self-vptr);
`Obj_2d5ec0` = `pure3d::SpriteParticleEmitter` (medium: called from that class, the object is
`pure3d/SpriteParticleEmitter.cpp`); `Emitter_2d53d0`, `Holder44_835a0`: no evidence (non-polymorphic).

**Field names**: none renamed. The evidence a field name needs (an accessor or setter name, a debug string, a script
binding name) isn't in the tree: build/functions.csv has RTTI-derived names only, config/data.json carries no string
text, and the stubs' own field names are invented per source. Fields keep `f_XX` (include/gen/) or the source's
names; the Lua binding table (`docs/lua-bindings.csv`) is the place to look for accessor names later.

Files: `build/rn1/rename-map.json` (entries with evidence, notes, touched sources), `rename-map.tsv` (high/medium/low
rows: stub, source, real class, confidence, on include/gen, evidence, note, touched sources),
`rename-map-summary.txt`.

## 2. How the stubs fit their include/gen/ class (`tools/rn_layout.py`)

The header side is what clang makes of the real headers (one probe TU: `sizeof` and `delete` of each of the 1,550
non-template include/gen/ classes, `-fdump-record-layouts -fdump-vtable-layouts`; the committed headers carry
hand-corrected signatures, so they are read, not regenerated). The stub side is `tools/stub_layout.py`'s model
(MSVC x86 /Zp8) of the source's class. Only members whose names the source uses outside the class definition count.

| stub (high/medium, real class on include/gen/) | same | cast | ptr-int | arity | lacks | conflict | unsupported | all |
|---|---|---|---|---|---|---|---|---|
| used by the source (no member defined there) | 2,602 | 14 | 9 | 226 | 436 | 131 | 27 | 3,445 |
| the source's own class (defines the function) | 556 | 411 | 197 | 170 | 2,166 | 675 | 1,011 | 5,186 |

`same`: every used field is a header field at that offset with that type, every used virtual has the header slot's
arity. `cast`: same size, other type (`(*(T*)&p->f_XX)`). `ptr-int`: pointer on one side, integer on the other (a
64-bit gap the cast keeps). `arity`: a used virtual's parameter count differs from the header's slot (a header
signature to fix, `gen_headers.CURATED_SIGS`). `lacks`: a used field sits in a header `_pad_` gap. `conflict`: other
size, float vs integer, straddling fields, or a virtual past the header's vftable. `unsupported`: stub_layout can't
model the class (templates, multiple bases, ...).

**Header additions** (`build/rn1/header-additions.json`): over all stubs of a class, 6,374 field offsets in 1,102
classes where every stub that touches the offset agrees on size and kind (int / float / pointer) are proposals for
include/gen/ (gen_headers.py field evidence); 1,256 offsets disagree. Top: `CCharacter` 268 (61 disagree),
`CCharacterTemplate` 127, `CChaseCamera` 107, `CSPHulkPropInstance` 78, `CScriptCamera` 61, `HUDOverlay` 54 (0).

## 3. Why functions are wrapped (`tools/rn_plan.py`)

Generator run on the snapshot with native11's fallback state: **merged 20,567 / wrapped 6,045 / isolated 862
(74.9%)**; 3,858 class merges refused. 4,847 functions are wrapped for conflicting declarations; per conflicting name
(a function can have several):

| category | functions | what removes it |
|---|---|---|
| header-stub: the name is declared by an include/gen/ header the TU includes, the source has its own stub | 2,672 | onto the header (gen-ref, gen-swap), or the real name with a placeholder suffix when the stub is another class (unclash) |
| function/data: a function or variable declared differently | 1,681 | prototype pins (`decls/`), not class work |
| layout: one class (or unknown), layouts disagree | 1,256 | header fields / casts |
| split: variants are different real classes | 184 | renames to the real classes |

Top names: `fight::TrackFactoryCaster` 199, `fight::ConditionFactoryCaster` 164, `World` 158 (pinned type),
`fight::TrackFactoryCasterTemplate` 155, `Obj` 138, `Node` 136, `Function` 133, `CTrack` 118, `Object` 110,
`pure3d::NonCopyable` 102, `CSweepTrack` 100, `Closure2` 88, `fight::ParamFloatConstRange` 88, `Method1` 82,
`FUN_0027b020` 75. Among the header-stub conflicts with a known real class, 1,145 functions are wrapped on a private
stub of the header's class itself and 383 on a stub of another class that carries a header class's name (clone
donors: `CSweepTrack` in a `CCharacterTemplateManager` destructor, `CTrack` for `fight::ConditionFactory`).

## 4. Batches

Every batch: `tools/rn_plan.py --batches` writes it; `--refine` runs the generator with the rewrites and drops,
until nothing more is dropped, (1) a source whose own function or whose TU's other functions get a worse mode,
(2) with `--bindings` (the strict Wine link's binding map of the tree the batch applies to), a source whose merge
would make one invented name of the TU namespace stand for two addresses (`extern void* vftableD[]` declared by two
sources for two vftables: the Wine link can bind neither), and (3) a source whose function would share its
definition's name with another merged function of the TU (overloads `Target(PhysicsJoint_30cbb0*)` /
`Target(PhysicsJoint_30cd60*)`: build_tree.py and wine_link.py find functions by mangled-name prefix and would take
one for the other). Then `tools/migrate_gen.py --family rn` rewrites and verifies (compare.py MATCH / equiv.py
--inputs 3000 EQUIVALENT) and keeps what verifies, `tools/build_tree.py` proves the tree and the strict Wine link
proves the image. Ordered by risk (a rename < onto the header < header changes) and size.

| batch | rule | scope | candidates -> refined -> verified | risk | status |
|---|---|---|---|---|---|
| **b1** | `unclash` | matches/ | 1,760 stubs in 1,528 sources -> refined (`c1`) 1,691 stubs in 1,475 sources -> **1,475 MATCH** | lowest: names only | **applied** (x64-1, 2026-10-20: re-planned on HEAD 441f5270b, 1,526 -> 1,473 MATCH; section 8) |
| **b2** | `gen-ref` | matches/ | 428 stubs in 406 sources -> 201 rewritable -> refined (`c2`) 169 -> **168 MATCH** (1 compile error) | low | **applied** (x64-1: 459 -> 239 rewritable -> 198 -> 197 MATCH; section 8) |
| **b3** | `unclash` + `gen-ref` | equivalent/ | 384 stubs in 317 sources -> 172 rewritable -> refined (`c3`) 141 -> **130 EQUIVALENT** at 3,000 inputs (8 compile errors, 3 FAIL, one of which fails unchanged too) | medium (equiv.py) | **applied** (x64-1: 341 -> 165 rewritable -> 138 -> 129 EQUIVALENT at 3,000 inputs; the 20,000-input re-check of the 129 is pending, `build/x64/equivalents-b3.txt`; section 8) |
| b4 | relabel | both | 2,861 suffixed/invented stubs with a known real class in 2,296 sources: `Obj_2d5ec0` -> `SpriteParticleEmitter_2d5ec0` | low | planned: readability only, no merge effect (the names don't collide today) |
| b5 | `gen-swap` re-run | both | 712 rewritable today (`migrate_gen.py --no-verify --equivalent`), plus up to 3,030 sources the gen family skips for "preprocessor lines": the `#include "decls/data/..."` lines the data migration added | low | **applied** (x64-1, commit ac5792eb: 756 candidates, 402 verified, 246 kept after dropping the newly isolated and the TUs that gained unbound names, 240 applied; section 8) |
| b6 | header signatures | include/gen/ + rewrites | 198 used stubs whose called slot has another arity (189 sources), 118 gen-swap "header slot returns void", 16 float/int parameters, 170 owner stubs | medium: a header change reaches every TU that includes it | planned (`gen_headers.CURATED_SIGS`, then b2/gen-swap again) |
| b7 | header fields | include/gen/ + rewrites | 6,374 agreeing field offsets in 1,102 classes (`header-additions.json`); unblocks 409 used stubs (351 sources) and the 748 gen-swap "field not in header" skips | medium-high | **first part applied** (x64-1, commit 78683b3c: 815 fields inside the classes' own `_pad_` gaps, layout-neutral by construction, + 61 gen-swap rewrites; section 8). Left: offsets in a base's region (4,465), non-scalars (744), non-unique class heads (441) |
| b8 | base stubs | rewrites | 1,894 used stubs that fit but are a base of the source's own stub, used by value or with `new`: the derived stub derives from the header class (`class CSweepTrack_23d3d0 : public fight::ConditionFactory`) | medium | planned |
| b9 | owner non-virtual members | include/gen/ + rewrites | 1,752 stubs whose own function is a non-virtual member (`Obj_2d5ec0::target` = `SpriteParticleEmitter::FUN_002d5ec0`) | high | **first part done** (x64-4, section 9): 2,090 sources -> 1,282 are constructors / non-virtual destructors (not b9), 511 wait on header fields; 211 planned -> 188 verified -> refine 132 |
| b10 | destructor slots, owner vfuncs | migrate_gen gen family | 2,490 owner stubs; 1,692 gen-swap skips "destructor slot (body is not base-dtor + delete)" | medium-high | **blocked for byte matches** (x64-4, section 9): MSVC 7.1 as we run it never inlines a non-empty destructor into `??_G`; the game's `??_G` bodies have it inline |
| b11 | template families | include/gen/ constructors | 930 stubs of instantiations (`Closure1<CActorManager,...>`, `fight::ParamBool<...>`, `fight::ConditionFactoryTemplate<...>`); the top conflict names (`fight::TrackFactoryCaster` 199, `fight::ConditionFactoryCaster` 164, `...CasterTemplate` 155 + 126, `Closure*`/`Method*` 300+) | high | planned (source-tree.md next step 2) |
| b12 | pinned types | include/decls/ | `World` 158, `Gfx` 34, `Singleton_4dd6ec` 27 wraps | medium | planned (source-tree.md next step 3) |
| b13 | multiple inheritance | include/gen/ base order | 357 gen-swap "stub class has multiple/virtual bases", 133 gen-ref "stub has bases" | high | planned; it is what removes the `jump_shapes` bridge |
| - | function/data prototypes | include/decls/ pins | 1,678 functions wrapped only or also on a prototype (`FUN_0027b020` 75, `Find` 68, `a` 98) | - | not class work: pin-decl-style families |

**unclash** (b1, b3): a stub carrying an include/gen/ class's short name that the rename map says is another class
takes `<real short name>_<addr>`: `CSweepTrack` -> `CCharacterTemplateManager_46110` (the source's own class, a
clone of a donor's destructor), `CTrack` -> `ConditionFactory_23d3d0` (its base). In a TU on include/gen/ the stub no
longer collides with the header's class, so the function merges; outside it, two clones of one donor no longer
define the same function ("same definition as ..." wraps 597 -> 444). The name says which real class it is; the suffix says
it is still a private view of it.

**gen-ref** (b2, b3): a stub the source only uses (pointers, field reads, virtual and non-virtual calls) goes onto
its include/gen/ class. clang's AST gives every member access; fields become the header's `f_XX` (a cast where the
stub's type differs), virtual calls the header's slot names (arguments cast to the header's parameter types, the
result to the stub's return type), non-virtual calls go through a declaration struct `<Class>_nv_<addr>` (the
gen-swap pattern), other stubs whose names collide with the header's take the placeholder suffix, and the source
includes the header. Refused: stubs with bases, used by value / `new` / `sizeof` / as a base, a used field the
header lacks, a destructor slot or a slot past the header's vftable, an arity difference, a float meeting an
integer, a collision rename of a name that is correct (the rename map says so).

```cpp
// matches/0x001c5a70.cpp, b2
#include "gen/Render.h"
struct Object_nv_1c5a70 { ...  void Update(int); };
...
    Render::Object* n = c->Find(key);            // was: Node* n = c->Find(key);
    if (n)
        ((Object_nv_1c5a70*)(n))->Update(value);   // was: n->Update(value);
```

The refine step matters for gen-ref: unrefined (all 332 rewritable stubs of both directories), the tree loses 3
merged functions and isolates 31 more, because a source newly on include/gen/ that can't merge is isolated, and a TU
that newly includes a header wraps its other sources' private stubs of that header's classes.

## 5. Dry runs (b1-b3)

A snapshot of the working tree (2026-10-19 21:25) copied to mac2 (`~/hulk-tree/{base,c1,c2,c3}`; the MSVC 7.1
compiler and wibo from `~/hulk-permute`, linked, not changed). Each refined batch (`c1` = b1, `c2` = b2, `c3` = b3,
each refined on the tree with the previous one applied and that tree's binding map) was rewritten and verified there
with `migrate_gen.py --family rn --apply`, then `build_tree.py --resume --rounds 16 --regression-rounds 4 --jobs 8`
from the same fallback state (native11's last full build); the strict Wine link ran locally on each tree
(`clang_probe.py --snapshot --configs msvc`, `wine_link.py`, plain, without `--gfx`). The scripts and every report
are in `build/rn1/proof/` (`pipeline.sh`, `native_proof.sh`, `cmp_reports.py`; `*-report.json` of build_tree,
`*-native-report.json` and `*-unbound.txt` of wine_link, `*-probe.log` of clang_probe).

**MSVC 7.1 tree build** (`build_tree.py`; each row against the row above it, compared per function: `status` and
`vs_standalone` of every one of the 27,474 functions):

| tree | TUs | matches still matching | equivalent/ identical to standalone | verdict differences | new shared lookups | merged / wrapped / isolated | merged % | class merges refused | conflict wraps | "same definition" wraps |
|---|---|---|---|---|---|---|---|---|---|---|
| snapshot | 2,810 / 2,810 | 22,248 / 22,248 | 5,226 / 5,226 | - | - | 20,565 / 6,047 / 862 | 74.85 | 3,858 | 5,048 | 597 |
| + c1 (1,475 matches/) | 2,811 / 2,811 | 22,248 / 22,248 | 5,226 / 5,226 | 0 | 0 | 21,052 / 5,559 / 863 | 76.63 | 3,246 | 4,713 | 444 |
| + c2 (168 matches/) | 2,811 / 2,811 | 22,248 / 22,248 | 5,226 / 5,226 | 0 | 0 | 21,057 / 5,554 / 863 | 76.64 | 3,241 | 4,708 | 444 |
| + c3 (130 equivalent/) | 2,811 / 2,811 | 22,248 / 22,248 | 5,226 / 5,226 | 0 | 0 | 21,081 / 5,530 / 863 | 76.73 | 3,180 | 4,684 | 444 |

"New shared lookups": functions that build_tree.py would find under another function's symbol (below). c1: 466 of
its own functions and 21 others wrapped -> merged, and one other function (`equivalent/0x000b86b0.cpp`, wrapped) was
isolated by the build's own regression round because its code in the changed TU differed from standalone (the extra
TU); c2: 4 + 1 wrapped -> merged; c3: 18 + 6. Every c3 source compiles in the tree to the same code as standalone (97
merged, 27 wrapped, 6 isolated), and each was EQUIVALENT at 3,000 inputs before it was kept; the 130 need the
20,000-input re-check (`build/rn1/c3-equivalents.txt`). Textual counts of the changed sources (`rn_plan.py
--metrics`): c1 none (a rename); c2 169 stub classes -> 170 `_nv_` declaration structs, stub virtual declarations
254 -> 170, pads 49 -> 48, 76 sources newly include a gen header; c3 71 stub classes -> 71 `_nv_` structs, stub
virtuals 2,211 -> 2,125, pads 552 -> 542, 48 new gen includes.

**Strict Wine link** (`wine_link.py`, plain; every tree links with 0 errors, `rc` 0 under `lld-link` strict):

| tree | image | symbols stubbed | stub-class virtual members | ambiguous invented names | vftable / RTTI by address | dispatch stubs | probe: undefined symbols | declared in a wrapped `fn_<addr>` | stub-virtual / explicit-padding sites |
|---|---|---|---|---|---|---|---|---|---|
| snapshot | 7,539,200 | 1,594 | 1,339 | 70 | 15 | 1,233 | 57,533 | 13,595 | 85,010 / 25,727 |
| + c1 | 7,540,224 | 1,588 | 1,346 | 66 | 6 | 1,240 | 57,449 | 13,504 | 84,864 / 25,777 |
| + c2 | 7,540,224 | 1,588 | 1,346 | 66 | 6 | 1,240 | 57,445 | 13,504 | 84,780 / 25,779 |
| + c3 | 7,540,736 | 1,588 | 1,346 | 66 | 6 | 1,240 | 57,416 | 13,322 | 84,706 / 25,763 |

c1's changes to the stubbed set: 9 hand-written vftable variables and 4 ambiguous names are bound now (the
separated clones' `CTrack_vftable` & co.), and the renamed stubs' unbound dummy virtuals (`virtual void B();`, only
named by clang's stub vftables) are 34 symbols where they were 27: sources that shared one merged invented stub now
each have their own. c2 changes nothing in the link; c3 renames 7 dummy slots. The explicit-padding sites rise by 50 in
c1 although no source's pads change: the probe counts sites in the generated TUs, where merged stubs are emitted
differently from wrapped ones.

**First tries** (kept as findings, `build/rn1/RESUME.md`). Refined with the generator only, b1 (1,519 sources, +514
merged, all MATCH, 0 verdict differences) linked with 40 more symbols stubbed than the snapshot: 25
`extern void* CTrack_vftable[]` and 8 other invented names (`vftableD` x4, `rawVtable` x2, `gWaypoint`, `vt_name`)
that two merged sources declare identically for two different addresses become one TU-namespace symbol the link
can't bind. The MSVC build can't see this (relocations are masked; the bytes match). Fixes: unclash renames a
stub's companion variables with it (`CTrack_vftable` -> `ConditionFactory_23d3d0_vftable`), and `--refine --bindings`
refuses merges that create such an ambiguity. b2's first version renamed `PhysicsJoint` apart in 0x30cbb0 and three
clones, making `Target(PhysicsJoint_30cbb0*)` and `Target(PhysicsJoint_30cd60*)` overloads in one TU: build_tree.py
checked all four against 0x30cbb0's symbol (all "match": they are clones) and the Wine link left their calls
unbound; refine now refuses merges that make two functions share a definition name.

## 6. Estimates

**Merge rate.** Measured: 74.85% -> 76.73% after b1-b3 (section 5; +516 functions merged). For the planned batches, the generator's
classification after b2 bounds what class work can still unblock: 1,132 functions wrapped only on header-stub names
whose classes the map knows, 666 on header-stub names it doesn't, 863 only on layout disagreements (330 mapped), 70
only on split names, 82 on header-stub plus layout; 848 only on function/data prototypes; the rest mix these with
compile errors (453), helper definitions (216), macros (73) and include/gen/ isolation (460). If the class batches
(b5-b13) cleared every class-only conflict the tree would merge about 2,800 more functions (about 87%); the dry runs
kept 41-97% of their planned sources through refine and verification (b1 97%, b2 41%, b3 41%), so
a realistic expectation is half of that: about 81-82%, plus up to 3 points from prototype pins.

**Sources touched, removals, 64-bit** (stub entries from the rename map with high/medium confidence, outside
b1-b3; pads and virtuals counted inside the stub classes the batch takes away):

| batch | stubs | sources | explicit pads in those stubs | stub virtual declarations | other effect |
|---|---|---|---|---|---|
| b4 relabel | 2,861 | 2,296 | - (renamed, not removed) | - | readability |
| b6 signatures (used stubs) | 198 | 189 | 84 | 692 | + gen-swap's 118 "returns void" skips |
| b7 header fields (used stubs) | 409 | 351 | 548 | 722 | + 748 gen-swap "field not in header" skips; 6,374 fields into include/gen/ |
| b8 base / by-value stubs | 1,894 | ~1,800 | 411 | 3,576 | |
| b9 owner non-virtual members | 1,752 | 1,734 | 1,989 | 1,352 | the `ctor-virt` stand-ins (12) |
| b10 destructor slots, owner vfuncs | 2,490 | 2,486 | 2,545 | 16,950 | most clang-emitted stub vftables |
| b11 template families | 930 | 759 | 543 | 492 | the largest conflict names |
| b13 multiple inheritance | ~490 (skips) | ~490 | | | `jump_shapes` |
| total | 11,024 | | 6,120 | 23,784 | |

For scale, the clang probe of the snapshot counts 25,727 explicit-padding sites in 3,957 sources and 85,010
stub-virtual declarations in 4,182 sources (`clang_probe.py` scans, msvc configuration): the class batches reach about
a quarter of each; the rest belong to stubs without a known class (non-polymorphic helpers). Pointer<->integer casts
(4,779 in the 2026-10-17 gnu64 probe) follow the fields: b7 turns `ptr-int` fits (9 used, 197 owner) into typed
header fields; gen-ref keeps a `(*(int*)&p->f_XX)` cast where the stub read a pointer as an int.
The casts and the locals / signatures that carry pointers were typed separately (ptr1, `hulk_intptr` etc., docs/wine-build.md
"64-bit" item 9): msvc64 pointer<->integer casts 4,936 -> 1,163; what is left sits behind virtual and header-declared signatures.

**Link stubs and bridges.** Strict link of the snapshot: 0 errors, 1,594 symbols stubbed (1,339 of them virtual
members of stub classes that only clang's emitted stub vftables name), 1,233 virtual dispatch stubs, 70 ambiguous
invented names. Per bridge of [wine-build.md](wine-build.md#bridges-to-remove):

| bridge | count | removed by |
|---|---|---|
| `jump_shapes` (adjustor thunks, forwarders) | 207 + 120 + 48 | b13 (base order in include/gen/), then the thunk sources as overrides |
| RTTI TD redirection | 2,731 | b9, b10, b11: the owner stubs (whose constructors/destructors make clang emit RTTI) onto include/gen/; gen-ref (b2, b3) moves only users, which emit none |
| stand-in bodies (`local_code`) | 940 | not class work (declare, don't define) |
| stub vftables pointed at the game's | all stub classes | b10 first (16,950 stub virtual declarations), b9, b11; the 1,339 stubbed stub-vftable members go with them |
| `hulk_at_` / `DAT_` by address | 54 | not class work (data) |
| `ctor-virt` stand-ins | 12 | b9 (the real class declaration) |
| `SITE_REBIND`, `ENTRY_HOOKS` | 6, 1 | ENTRY_HOOKS: b7 (ControllerSystemXBox +0x12a0/+0x12a4 as named members) |
| empty stubs for the 0x002777c0 class | 14 | b13 |

## 7. Findings and caveats

- **The binding map makes the rename map.** Most of the evidence is the strict Wine link's relocation-position
  bindings: a stub's member call bound to an address whose owner is known, a stub's vftable symbol bound to the
  game's vftable. The map is as fresh as `build/native/bindings.json` (2026-10-17 here); re-run `tools/rn_map.py`
  after a full Wine link.
- **Non-polymorphic classes stay unnamed.** RTTI is the only source of class names; 42,289 stub entries have no
  evidence, mostly helper structs. They can still be consolidated by layout (stubs of one address's `this`), not
  named.
- **Medium is one inference step.** `base` assumes the stub's base is the real class's primary base (a stub that
  flattens two levels would be named after the nearer one); `call` with a class that has no derived classes assumes
  RTTI lists every derived class (it does for polymorphic classes). Low entries are recorded, not used.
- **Readability.** gen-ref trades an invented stub for the real class, and `p->Release()` for `p->vfunc_1()` (the
  header's slot names are still placeholders) and `((X_nv_<addr>*)p)->f()` for non-virtual calls. Real member names
  come with b9 (non-virtual members in include/gen/) and slot names from the Lua binding table.
- **migrate_gen gen family and data includes.** `skip_reason` refuses any source with a preprocessor line, so the
  data-migrated sources (`#include "decls/data/..."`) are out of gen-swap's reach since 2026-10-16 (b5). (Fixed by x64-1, section 8.)
- **build_tree.py finds functions by mangled-name prefix.** Two functions of one TU defined under one name (overloads)
  are both checked against the first symbol; the snapshot has 643 such groups (2,387 functions), all copies of one
  template instantiation emitted in several objects (identical code, so harmless), but an overload pair would be
  checked against the wrong function and bound to it by the Wine link (b2's first try). A uniqueness check in
  build_tree.py (a symbol may stand for several addresses only when their sources define the same function) would
  catch it at the source; refine guards the batches meanwhile. (Done by x64-1, section 8.)
- **equiv.py and renames.** One b3 unclash rename (`equivalent/0x001065b0.cpp`) turned EQUIVALENT into FAIL: equiv.py
  keys some bindings by mangled name. Every rename of an equivalent/ source has to be re-checked, as here.

Files: `tools/rn_map.py`, `tools/rn_layout.py`, `tools/rn_plan.py`, `tools/rn_transform.py` (new),
`tools/migrate_gen.py` (`--family rn`, `--batch`; the existing families unchanged, same output on the same
inputs). Outputs: `build/rn1/` (rename map, header DB, layout fit, header additions, plan, batches and refined
batches `c1-unclash-matches-refined.json`, `c2-genref-matches-refined.json`, `c3-equivalent-refined.json`, the dry
runs' source lists `c1-sources.txt` (1,475) / `c2-sources.txt` (168) / `c3-equivalents.txt` (130) and their patch
`dryrun-c1-c3.patch` against the 21:25 snapshot (1,762 files), `proof/`). To apply a batch to the live tree, re-run `rn_plan.py
--refine` (with the live tree's state and binding map) and `migrate_gen.py --family rn --apply` there rather than
apply the patch: sources and the tree move under other sessions, and both steps check the tree as it is.

## 8. Applied to the tree (x64-1, 2026-10-20)

b1-b3 re-planned and applied to the live tree rather than from the dry-run patch: a snapshot of HEAD 441f5270b
(base), its strict Wine link's binding map for `rn_map.py` and `--refine --bindings`, each refined batch applied
with `migrate_gen.py --family rn` on mac2 and proven there with `build_tree.py --resume --rounds 16
--regression-rounds 4` (same fallback state as section 5), the strict link locally, `verify_relocs.py` on every
changed match. Sources with uncommitted changes or another agent's open work were excluded (none of the batches'
sources were). Each batch was copied into the tree only where the file was unchanged since the snapshot (all were).

| tree | sources | matches still matching | verdict differences | equivalents differing from standalone | merged / wrapped / isolated | strict link: rc / stubbed / ambiguous names | verify_relocs |
|---|---|---|---|---|---|---|---|
| base (441f5270b) | - | 22,255 / 22,255 | - | 0 | 20,551 / 6,042 / 862 | 0 / 1,600 / 65 | - |
| + b1 (commit 36784eba) | 1,473 matches/ | 22,255 / 22,255 | 0 | 0 | 21,037 / 5,555 / 863 | 0 / 1,594 / 61 | 1,473 / 1,473 ok |
| + b2 (755eb3f7) | 197 matches/ | 22,255 / 22,255 | 0 | 0 | 21,049 / 5,542 / 864 | 0 / 1,594 / 61 | 197 / 197 ok |
| + b3 (0ac939aa) | 129 equivalent/ | 22,255 / 22,255 | 0 | 0 | 21,073 / 5,518 / 864 | 0 / 1,594 / 61 | - (equiv.py 3,000: all EQUIVALENT) |
| + b5 (ac5792eb) | 118 matches/ + 122 equivalent/ (+ 6 changed in the tree since: not applied) | 22,255 / 22,255 | 0 | 0 | 21,242 / 5,342 / 871 | 0 / 1,594 / 61 (unbound set identical) | ok |
| + b7 headers (78683b3c) | 12 include/gen/ headers, 815 fields | 22,255 / 22,255 | 0 | 0 | identical to b5 | - | - |
| + b7 sources (78683b3c) | 34 matches/ + 27 equivalent/ | 22,255 / 22,255 | 0 | 0 | 21,266 / 5,319 / 870 | 0 / 1,590 / 61 | 34 / 34 ok |

Merged 74.85% -> 76.75% after b1-b3 (+522 functions), 77.46% after b5 and b7 (+715). The 129 b3 equivalents need the 20,000-input re-check
(`build/x64/equivalents-b3.txt`; b5: `equivalents-b5.txt`, 122; b7: `equivalents-b7.txt`, 27). Refine kept 97% / 43% / 40% of the candidate sources (b1 1,526 -> 1,473; b2 459
sources, 239 rewritable -> 198; b3 341, 165 rewritable -> 138).

Findings of section 7 addressed: **build_tree.py** checks that a symbol stands for one function of a TU (commit
5b0eab47, [wine-build.md](wine-build.md#64-bit-the-probe-the-gap-by-class-and-what-replaces-each-bridge-x64-1-2026-10-20)
item 7: 832 functions re-checked under their own symbol, 3 fell back; strict link 1,600 -> 1,392 stubbed); the
**migrate_gen gen family** accepts `#include "decls/..."` sources (commit 03de06ed: 711 -> 757 rewritable, the
newly reachable ones mostly wait on header fields, b7). The batches' proofs used the tools of 441f5270b
(the old lookup) for base and batches alike.

**b5** (gen family re-run, `migrate_gen.py --apply --equivalent` on the b3 tree): 756 candidates, 402 verified
(326 clone-template, 76 gen-swap; 271 compile errors, 77 DIFF, 6 FAIL). Unrefined, the tree build isolated 114
of them (wrapped -> isolated) and the strict link gained 37 unbound symbols: invented names two merged sources
declare for two addresses (`TryCast`, `performCast`, `castThing` cast helpers, `gOne`/`typeA` globals, `TrackBase`
stub slots), rn1's b1 first-try finding again. Dropping the 114 and every b5 source of the 30 TUs those names live
in (42) gave a tree with the b3 tree's exact unbound set. The gen family has no `--refine --bindings` step yet;
it needs one (rn_plan's refine works on rn batches only).

**b7, first part** (`tools/rn_fields.py`): see the table row above. The base-region offsets (4,465) are the bulk:
a derived class's stubs agree on a field that belongs to a base; putting it into the base is layout-neutral the
same way (inside the base's pad) but every class derived from that base sees it, so it needs agreement over all
derived classes' stubs; next.

## 9. b9, caster pins, pointer fields (x64-4, 2026-10-24)

On HEAD b76e68ad1, proven against a same-host HEAD control (mac2, `tools/wine_build_job.py --gfx`, play3 to frame 1000).

- **b9** (`tools/rn_members.py`, migrate_gen rule `gen-nv`): a source whose own function (`FUN_<addr>`) is the only
  out-of-line member of a private stub that the rename map names as a plain include/gen/ class X: X gets
  `R FUN_<addr>(P...); // non-virtual` (include/gen/evidence-rn.json "members"; the source's signature in header
  types: scalars kept, `X*` for a pointer to the stub itself, `void*` for other pointers and references) and the
  source becomes `R X::FUN_<addr>(P...)` through the gen-swap rewrite (`gen_headers.swap_transform(nv=...)`). Of
  2,090 own-stub `FUN_` sources, 1,282 define a constructor (~900) or a non-virtual destructor (~360) out of line
  (they need modelled constructors and destructors, not declarations) and 511 use fields the headers lack; 211
  members planned, 188 sources verified, 132 kept by refine. The header keeps only the kept sources' members.
- **Casters** (b11/b12 follow-up): 288 `fight::*FactoryCasterTemplate<...>` / `DynamicCaster<...>` sources off
  include/gen/; 282 gen-family rewrites, then `rn_transform.canon_data_transform` (an `extern T DAT_x;` used only as
  `&DAT_x`, an RTTI descriptor, becomes `extern char DAT_x;`) and `canon_decl_transform` (one
  `extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);`, kept only where the call compiles). Without
  the two canonicalizations 127 of them went isolated on `DAT_0049850c` / `DAT_00491ca8` / `FUN_00344e74`
  declaration conflicts. swap_transform no longer casts a comparison to `bool` (`(bool)(x != 0)` compiles to
  `setne` where the game has `neg/sbb/neg`). The casters' invented data and helper names (`extern void* a, b;`,
  `check`, `Check`, `gB`, ...: 40 sources) take their address names from their verify_relocs maps
  (`rn_transform.pin_data_transform`): unpinned, the first tree build left `fight::a` / `fight::b` / `gB` bound to two
  addresses (unbound +3) and broke 7 on-gen sources that use `a` / `b` in the same TU namespaces. 270 verified ->
  refine 217.
- **Pointer fields** (`tools/rn_ptrfields.py`, evidence-rn.json "ptr_fields"): the 61 include/gen/ fields (55 units)
  that x64-3's `tools/ptr_fields.py` found read as pointers through `*(T**)&p->f_XX` are `hulk_intptr` /
  `hulk_uintptr`: the same types on the 32-bit builds, pointer-sized on the 64-bit ones.
- **b10**: the game's scalar deleting destructors contain the destructor chain inline although the same classes have
  out-of-line `??1` functions (0x00019420, 0x0001d1e0); cl 13.10.3077 /O2 never inlines a non-empty destructor into
  `??_G` (tried out-of-line, in-class, `inline`, `__forceinline`, explicit specializations, nothrow callees, member
  destructors). Likely link-time code generation in the original build. The hand-written `??_G` bodies stay.

| tree (mac2, same host) | sources | TUs compiled / total (build_tree; the clang probe agrees) | matches still matching | merged / wrapped / isolated (generator, per build state) | per function | strict link rc / unbound | play3 checkpoints |
|---|---|---|---|---|---|---|---|
| HEAD b76e68ad1 control (job 17126) | - | 2,627 / 2,627 | 22,340 / 22,340 | 21,771 / 5,027 / 676 | - | 0 / 1,330 | 0-1020 |
| + x64-4 batch (job 17245) | 333 matches/ + 16 equivalent/ (132 b9, 217 casters) | 2,626 / 2,626 (one `.iso_` TU fewer) | 22,340 / 22,340 | 21,984 / 4,815 / 675 | 214 better, 1 worse | 0 / 1,330 (`_check` 19 -> 17 refs) | identical 0-1020 |

The one worse function, `equivalent/0x002e9c60` (merged -> wrapped, "code differs from its standalone build", TU
`src/engine/physics/unk_2e6780.cpp`, no batch source in it), is the fallback-order effect of section 8 (0x2ea3c0):
generated locally from the batch's final state its merged code equals the standalone build byte for byte; with
`0x2e9880` (wrapped in both trees) still merged, as in an early round, it differs in the batch tree and not in the
control's. build_tree.py re-checks wrapped -> isolated escalations, not first fallbacks.


**Round 2 (x64-4).** build_tree.py now re-checks first fallbacks too (above): HEAD d3c76cfa8 merges 0x2e5410, 0x2e9c60
and 0x30f490 again (3 better, 0 worse; same final state and image on 8 and 4 slots). Then 118 agreeing header fields
(`tools/rn_fields.py`; b9 gains only 3 candidates from them, 508 own-stub members still wait on fields), 7 more b9
members, 10 gen-family rewrites the fields allow and 1 own-stub pointer field (`hulk_intptr`): 18 sources, 8 better,
0 worse against the fixed HEAD build, strict link and play3 checkpoints identical.

**Round 3 (x64-4): constructors.** About 900 own-stub `FUN_` sources define a constructor out of line. Their header
form is `X::X(P...) { body }` against a declaration in the header class (`include/gen/evidence-rn.json` "ctors",
`tools/rn_members.py --ctors`, migrate_gen rule `gen-ctor`), with the direct base's default constructor declared
out of line (evidence "base_ctors": the source's stub base declares it without a body, so the game calls it). A
class that gets declared constructors also gets a declared default constructor, so classes derived from it keep
their implicit ones; the layout probe defines the declared constructors in its own TU (else the vftables are not
emitted there) and reads sizes from `sizeof`.
- Planned 238 (refused: 1,043 "can't tell" (not one out-of-line constructor), 234 member initializers, 160 base
  arguments, 198 header fields missing, 43 a stub base whose constructor is inline or implicit). Verified 105/206
  matches and 19/32 equivalents; refine 118. **Not applied**: the tree build (job 18697 against 17346, mac2) kept
  22,340/22,340 matches and identical play3 checkpoints, but the strict link's unbound symbols rose 1,330 -> 1,438.
  A constructor defined on the header class makes its TU emit the header class's vftable, and that vftable names
  the header's `~X` and `vfunc_N` symbols, which no tree source defines under those names: the hand-written `??_G`
  slots stay on their stubs (b10). These constructors can move once the vftable slots bind by address (wine_link)
  or the destructor slots are on the headers. The tooling stays: gen_headers "ctors" / "base_ctors", migrate_gen
  `gen-ctor`, `rn_members.py --ctors`, and the probe fixes.
- **The other half is blocked like b10**: every DIFF (101 of 206) is an EH frame (`push -1; push $ehhandler; mov
  eax, fs:[0]`) the game doesn't have. With the header's base class, which has a virtual destructor, MSVC 7.1 /GX
  protects the constructor body against a throw from any call that may throw, including virtual calls declared
  `throw()`; only nothrow free functions (`extern "C"`, `throw()`) avoid it (toys in x64-4's scratch). The stubs
  match because they give the base no destructor. So a constructor body that calls a member or virtual function
  cannot move onto the headers as a byte match; call-free bodies can.
