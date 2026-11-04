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

## 10. Members through include/gen/ (x64-9, name unification batch 4, 2026-11-02)

The 64-bit link needs every reference to name its definition's own symbol. A member call on a source's own stub
(`p->Init("hasHitPushback")` on `Hit_155500`) is a TU-namespace symbol the Wine link only reaches through an alias.
`tools/name_unify.py member` plans, from a Wine build's link outputs (tools/name_audit.py), every member -> member
alias whose definition is a non-virtual member of an include/gen/ class; `member-apply` rewrites the callers to
call through the header class: `((fight::ParamValueBool *)p)->FUN_00234860("hasHitPushback")`, the source
including `gen/<ns>.h` (casts to the caller's declared types first, then the header's; the stub's declaration
goes; a stub named like an include/gen/ name takes the source's address as a suffix, `ParamBool_54300`).

Definitions placed by hand first (b9 shape, `include/gen/evidence-rn.json` "members"): `fight::Action::FUN_002326a0`
(fight::Action's destructor body, which 431 call sites of the derived actions' destructors call), the
`fight::ParamValue{Float,Name,NameList,Branch}` constructors-as-members `FUN_00234960/a90/ba0/00235170`, and
`ParamValueBool::FUN_00234860` now takes `const char*` (the callers pass the parameter's name; `int` was too narrow
for 64 bits). All six byte-match.

gen_tree.py: a stub item holding a cast to an include/gen/ class (`ParamBoolBase(const char* name) {
((fight::ParamValueBool *)this)->FUN_00234860(name); }`) stays in its TU (`names_gen`, off-switch
`HULK_GEN_TREE_OFF=genref`): hoisted to common.h it broke 804 TUs that don't include the header. The rule changes
nothing in a tree of HEAD's sources. Two more lessons: a source that goes on include/gen/ and can't merge is isolated
without a TU namespace, so its own stubs named like *any* include/gen/ class (not only the headers it includes) define
global symbols other such sources define too (lld duplicates: `CSmartPropUpdateAttachmentAction::Shutdown`); such
sources are left alone. The replay-pin functions (docs/wine-replay.md) are left alone too.

| | control 39098 (HEAD c8bfc4ae7) | batch 39753 |
|---|---|---|
| sources | - | 399 matches/ + 284 equivalent/ callers, 6 definitions, fight.h + evidence-rn.json |
| TUs / matches still matching | 2,570 / 22,340 | 2,610 / 22,340 (40 more `.iso_` TUs: on-gen sources that don't merge) |
| equivalents identical to standalone (merged / wrapped / isolated) | 2,740 / 2,214 / 180 | 2,831 / 2,100 / 203 |
| strict link rc / unbound | 0 / 1,328 | 0 / 1,328 |
| play3 checkpoints | 2,003 to 60,060 | identical at all 2,003 common frames (batch to 60,240) |
| name audit, game (symbols / references) | 50,375 / 52,193 | 49,401 / 51,271 |
| native arm64 link, unbound | 50,407 | 49,429 |

What it does not reach: of 16,108 member -> member aliases, 15,849 have a definition on a TU stub. The rename map
names an RTTI class for 517 of those definitions (1,995 aliases; tools/rn_members.py plans only 50 of them
automatically now). The other 4,989 definitions (13,673 aliases) belong to non-polymorphic classes RTTI never names
(`Target_27b040`, the 8-byte hash holder 584 callers use): no include/gen/ class exists for them. 2,732 of those
owner stubs have only builtin fields (7,423 aliases), 450 more only builtin fields but members taking other stubs
(793), 1,118 pointer fields to other stubs (3,487). Proposal: an include/gen/ header of such owner classes (b12
"pinned types" with layouts, one class per definition, canonical member prototypes with pointers where callers pass
pointers: the `Target_27b040` callers pass `const char*` to its `unsigned int`), after which `member-apply` handles
their callers unchanged.

## 11. Owner classes: include/gen/owners.h (x64-10, name unification batch 5, 2026-11-02)

Section 10's remainder: definitions that are members of the defining source's own stub, of classes RTTI never names.
Design:

- **One header, one namespace.** `include/gen/owners.h` declares `namespace owners { ... }`, one class per such
  definition: `owners::<Stub>_<addr>` (the stub's name, with the definition's address appended unless it already
  ends in it: `owners::Target_27b040`, `owners::Object_592a0`). Keyed by definition, not by real class: without RTTI
  nothing proves that two sources' stubs are one class, so each class is the definition's own view of it; merging
  views of one real class is later work. The namespace keeps the generated names out of the sources' top-level names
  (a caller's own stub `Target_27b040` does not collide with `owners::Target_27b040`, so `member-apply` renames
  nothing, and gen_tree sees one new top-level name, `owners`).
- **Generated, not written.** `tools/owner_classes.py plan` reads a Wine build's link outputs (the same input as
  `name_unify.py member`) and writes `include/gen/evidence-owners.json`; `tools/gen_headers.py` emits owners.h from it
  (`emit_owners`; all.h includes it). Each class holds its stub's members in source order (layout preserved), typedef
  names said as the builtin types they name, the defined member named `FUN_<addr>` (b9's convention), the stub's other
  member declarations kept as they are (the definition's body may call them). Each field carries its 32-bit offset
  and, where it differs, its 64-bit one (`// +0x04 (+0x08)`), from clang's record layouts for i686 and x86_64
  windows-msvc; the class comment gives the defining source and the sizes.
- **First scope: self-contained stubs.** Fields and member signatures of builtin types, pointers to them or to the
  stub itself; no bases, virtual or static members, nested types, inline bodies, constructors or destructors;
  member types `type_info` understands (no references). Not: definitions whose stub the rename map names as an RTTI
  class (they belong on include/gen/'s real class), the replay pins, sources in other agents' hands.
- **Signatures: pointer beats integer.** A 4-byte integer parameter (or return) of the definition that some caller
  declares as a pointer becomes `hulk_uintptr` / `hulk_intptr` (`hulk_ulongptr` / `hulk_longptr` for `long`), in the
  header and in the definition: the same type on the 32-bit builds, so the code and the mangled name do not change,
  and pointer-sized on the 64-bit ones (include/compat/ptr.h). `Target_27b040::FUN_0027b040(hulk_uintptr)`: its 584
  callers pass `const char*`. A real pointer type would need the body's uses cast and the callees' prototypes
  settled first; the pointer-sized integer is the step that is exact on both builds. Pointer fields stay as the
  stub declares them (copied, so the 32-bit layout is the stub's; the 64-bit offsets are what a real pointer gives).
- **The definition source** loses its stub, includes `gen/owners.h` and defines `R owners::X::FUN_<addr>(P...)`
  (other uses of the stub's name say `owners::X`). **Callers**: `name_unify.py member --moved` (the plan's
  `moved.txt`) and `member-apply`, unchanged but for two fixes: `header_member` reads a `hulk_*` spelling from the
  header text (cxx_items' tokenizer says those types as the 32-bit ones, so a header's `hulk_uintptr` parameter
  never reached `member_arg_cast`'s pointer bridge), and `member_ret_cast` casts a `hulk_*` return to a caller's
  pointer type.
- **gen_tree.** A wrapped source on include/gen/ goes to its own TU because its definition (`void ns::X::f()`) can't
  sit in a `fn_<addr>` namespace. A caller whose only include/gen/ header is owners.h and whose own definition is not
  a member of an include/gen/ name has no such definition: it stays wrapped, owners.h included at the top of the TU
  (`gen_isolates`; off-switch `HULK_GEN_TREE_OFF=ownwrap`). Without the rule the first dry run isolated 707 sources
  (HEAD 244), with it 297; on HEAD's sources the rule changes nothing.
- **Uses of a reconciled parameter** keep the old type: each use in the body becomes `((unsigned int)value)`
  (`name_unify.param_use_casts`), so the 32-bit code is unchanged and no call in the body narrows or turns
  ambiguous on 64 bits (the first native compile of the batch lost 4 TUs: a body that took `&index`, an `f1(member,
  arg)` that matched two overloads once `arg` was 64-bit). A parameter the body assigns or takes the address of keeps
  its integer type (its pointer-passing callers then stay on their stubs).

Batch 5 (applied, x64-10). Planned from control 39773's link (HEAD 80bc25b2a), proven on HEAD 44d83331c (control 42322
vs batch 42344, mac2, both fresh, `--map full`, play3 to 60,000):

| | control 42322 | batch 42344 |
|---|---|---|
| owner classes (include/gen/owners.h) | - | 2,666 (7,150 aliases planned; 237 with pointer-sized integer signatures, 248 whose 64-bit layout differs) |
| sources | - | 4,836: 2,666 definitions (2,501 matches/, 165 equivalent/) + callers (3,130 calls: 1,207 matches/, 1,013 equivalent/) |
| strict link rc / unbound | 0 / 1,328 | 0 / 1,324 |
| play3 checkpoints | 2,013 to 60,360 | identical at all 2,002 common frames (0..60,030) |
| name audit, game (symbols / references) | 49,401 / 51,271 | 46,339 / 48,222 |
| native arm64 link, unbound (front-end failures) | 49,429 (3) | 46,370 (3) |

Verification: every touched match MATCH + verify_relocs ok, every touched equivalent promotable at 3,000 inputs and at
600 with `--wine`. Left out (not promotable after the rewrite): 3 definitions (0x001acfa0 `--wine` fail and 0x00320540
unsupported, both failing the same way at HEAD; 0x002f9bc0 `--wine` inconclusive, promotable at HEAD), ~130 callers (most: a stub renamed for colliding with an include/gen/
name whose vftable or RTTI symbol the checker then can't resolve, `Method0_306e0`; 7 `SeqEvent*Type` constructors
whose `Temp().Init(...)` temporaries the cast changes), 0x0012ebc0 / 0x0012f030 (merged, they flip GameStateCondition's
canonical `FUN_0008d6d0` to `extern "C" (hulk_uintptr)`, which conflicts on 64 bits with a wrapped source's
`unsigned int` declaration), the replay pins and sources other agents held. A caller that build_tree isolates
(`lost its match in the tree`) now keeps a TU namespace (owners.h before it): isolated plain, `Obj::run` of 0x0030f4c0
collided with HEAD's plain-isolated 0x000aa680 in the strict link of a preview build.

Not yet reached: definitions whose stub's members name other stubs (2,091 / 5,736 aliases: next, with those stubs as
classes of their own or `void *`), stubs with virtual members, bases or nested types, reference-typed members
(`Pair_27af70::Assign`), and the callers member-apply refuses (arity 620 calls, return size or bool 177, float/int 100).
Classes are per definition: merging the views of one real class is later work.

## 12. Names: locals, parameters and include/gen/ fields (clean1, 2026-11-03)

Naming and cleanup of matches/ and equivalent/, in batches that keep every byte and every proof. Two kinds so far:

- **Locals and parameters** (batch 1): Ghidra placeholders (`param_N`, `local_x`, `uVarN`, `piVarN`, ...) in 709
  sources (707 matches/, 2 equivalent/) named from their use. `tools/rename_ids.py MAP.json` renames tokens outside
  comments and literals and refuses a file where a new name is already an identifier (a local can't capture another
  name). 531 sources are scalar deleting destructors whose flag parameter (`if (param_2 & 1) delete(this)`) is now
  `flags`; the other 178 (154 code shapes) were named by hand and propagated to sources of the same shape: Lua C
  functions' state `L` (the first argument of the Lua API calls, as in the sources that already say `lua_State *L`),
  red-black tree rotations `tree`/`node`/`child`/`parent`, `first`/`last` of insertion sorts, `alignment` of the
  round-up helpers, `inserted`/`removed` masks of `XGetDeviceChanges`, `length`/`spacing`/`maxCount`/`out` of the
  sample-spacing helper 0x000a0010. No placeholder of those kinds is left in either tree.
- **include/gen/ fields** (batch 2): `include/gen/evidence-names.json` names a unit's field with its evidence;
  `tools/gen_headers.py` emits that name instead of `f_<offset>` (`field_name`). The first evidence tool is
  `tools/param_fields.py`: a fight parameter registration passes a string literal to a `fight::ParamValue*`
  constructor and registers a setter; the setter (disassembled from the XBE) stores its argument once through `ecx`
  (or returns `&this->x`, `lea eax,[ecx+X]; ret`), which gives the offset, and gen_headers' model gives the unit
  that declares a field there (the class or a non-virtual base). Refused: setters with no or several stores, classes
  RTTI doesn't name, offsets no unit declares (25: the field isn't in the header yet), a store size other than the
  field's, two names for a field, one name for two fields, a name another member of the hierarchy has.
  `tools/rename_fields.py` then rewrites the references: each candidate source (on include/gen/, naming a renamed
  unit's class or a class derived from one, and spelling an old name) is parsed by libclang as tools/equiv64.py
  prepares it, against the headers before the rename; a member reference whose field is a renamed include/gen/
  field is rewritten in place (`this->f_0c` -> `this->compare`; an implicit reference becomes `this->name` when
  the source uses the name for anything else). A token spelled like an old name that the parse doesn't account
  for refuses the source. 211 fields of 86 classes (CClimbableCondition +0x10 `arc`, +0x14 `useIntentionMotion`;
  CAxisCondition +0x0c `axis`; hulkfight::motion::PropDamageTrack +0x0c `timeBegin`, +0x10 `attachmentIndex`,
  +0x14 `damage`); 481 candidate sources, 83 rewritten (137 references; 74 matches/, 9 equivalent/), none refused.
- **Fields the header lacked** (batch 3): when no unit declares the offset, `param_fields.py` adds the field
  ("added" in evidence-names.json, with its type: the store's width, float for an x87 store or a
  `fight::ParamValueFloat` parameter) if it lies in the class's own part, inside its size and clear of every
  declared field, so no layout changes. 7 fields: CClimbableCondition +0x0c `angle`, CAxisTimeCondition +0x14
  `time`, fight::PlatformCondition +0x0c/+0x0e/+0x0f `pS2`/`gameCube`/`win32` (+0x0d `xBox` was renamed),
  CSmartPropEventTrack +0x0c `event`, fight::SequenceTrack +0x18 `priority`.

Gates: batch 1, 707/707 matches MATCH + verify_relocs ok, 2/2 equivalents promotable (3,000; `--wine` 600);
batch 2, 74/74 and 9/9. `--x64` as at HEAD for all 11 equivalents (equivalent, except 0x002151e0 unsupported/tool,
0x00183510 crash64 and 0x0012f400 int, which fail the same way at HEAD).

| | control 42501 (HEAD ccfd11419, mac2) | batches 1-3, 42504 (mac1) |
|---|---|---|
| TUs / matches still matching | 2,658 / 22,340 | 2,658 / 22,340 |
| equivalents identical to standalone (merged / wrapped / isolated) | 2,864 / 2,020 / 250 | same |
| strict link rc / unbound | 0 / 1,324 | 0 / 1,324 |
| image (PE time stamp zeroed) | - | identical to the control's |
| play3 checkpoints | 2,005 to 60,120 | identical at all 2,005 common frames (batch to 60,150) |
| name audit, game (symbols / references) | 46,339 / 48,222 (x64-10) | 46,339 / 48,222 |
| native arm64 link, unbound | 46,370 (x64-10) | 46,370 (same groups, same 3 front-end failures) |

Not reached yet: registrations whose setter stores more than once or calls (18), whose class the source names
only by a template parameter or a stub (23), 18 offsets outside the class's own part or without a store type;
the fields of the other include/gen/ classes (no string evidence; usage across sources is the next source of
names); function and member names (they need a name-to-address convention the checkers understand: equiv.py's
`name_address` reads the address from `FUN_<addr>`-style names only, so a renamed callee must keep that form or
the checker must learn a new one, with a regress run).

## 13. Function names: the address-suffix convention (clean2, 2026-11-03)

Section 12 stopped short of function names: the checkers and the link read a callee's address from `FUN_<addr>`-style
names only. The convention that lifts this is one many sources already followed by hand (`Init_001d43b0`,
`Check_000dfa60`, `ReadTrack_002530b0`, `Func_00367610`: all thirteen such callees checked bind to the address their
names say):

- **A meaningful function name keeps the address as a suffix**: `SetArc_000480a0` = the name, `_`, and eight lowercase
  hex digits starting `00`. It is read from the *leaf* identifier only (the function's own name, not its class or
  namespace: `Obj_480a0::SetArc_000480a0` says 0x000480a0, a constructor `Ctor_001d0480::Ctor_001d0480` mangles as
  `??0` and says nothing). At least two characters come before the suffix (`v_001d0480`, a placeholder virtual named
  after its class's constructor, sits unbound in clang's stub vftables and must stay so), and not a placeholder or data
  prefix (`FUN_`, `DAT_`, `tbl_`, `zero_`, ... keep their own rules). A reader uses the address only where it is in the
  XBE's `.text` (or, in clang_probe's grouping, a verified function). One module says this: `tools/addr_names.py`
  (`suffix_address`, `symbol_suffix_address` for object-file symbols, `ident_address` for either form).
- **Readers taught it** (each with an off-switch `sufname` for A/B):
  - `equiv.py name_address` (rule 3 of docs/equivalence.md's binding order; `EQUIV_OFF=sufname`);
  - `verify_relocs.py`: a new hard issue `name_address_mismatch` when a suffix-named reference's relocation targets
    another `.text` address (the byte match masks the relocation, so nothing else would tell; `RELOC_OFF=sufname`).
    Not applied to `FUN_` names (it would be a new check on 22,000 matches; left for a separate sweep);
  - `wine_link.py name_address` (fallback after the relocation binding; `HULK_WINE_LINK_OFF=sufname`) and its gfx
    game-reference test;
  - `gen_tree.py addr_named`: linkage and spelling differences of an address-named function bind by the address, as
    for `FUN_` (`HULK_GEN_TREE_OFF=sufname`). On HEAD's sources the generated tree is byte-identical with and without
    it (both runs `PYTHONHASHSEED=0`: gen_tree's output order depends on the hash seed, 137 files differ in line
    order between two unseeded runs of one input);
  - `name_unify.py` (`ADDR_NAME`: callers spelling an address name are bound by it), `clang_probe.py` (the x87-keep
    callee key and the undefined-symbol groups), `x87_order.py` (name binds of equivalents, the `equiv-conv` line),
    `wine_shim.py`, `data_gen.py` (data relocations to functions), `native_mac.py` (report groups);
  - `param_fields.py` reads a setter in either form and reports it as `FUN_<addr>`, so evidence-names.json
    regenerates identically after the rename.
  Not changed: `equiv_next.py` (a stale fork nothing imports), `name_audit.py` (report categories only).
- **Regress** (tests/equiv/regress.py): `0x000139b0_suffix_names` (equivalent/0x000139b0 with its four callees renamed:
  equivalent), `..._swapped` (two callees of one shape whose names carry each other's addresses: fail, "call #1 went to
  0x00059a30 instead of 0x000592a0"), `..._swapped_off` (the same with `sufname` off: equivalent, pairing by position
  binds each name to the original's call there: what the rule catches); verify_relocs `0x001d47c0_suffix_name` (ok)
  and `..._wrong` (`Init_001d4320` for the original's 0x001d43b0: bad, name_address_mismatch; ok before).

**Applying names.** `tools/fn_names.py` writes `include/gen/evidence-fnames.json` ({address: name, kind, evidence});
`tools/name_unify.py rename --names ... --bindings B.json` applies it: the definition's own name (from the binding map's
`definitions`: `Obj_480a0::Set` or `FUN_000480a0`) and every `FUN_<addr>` token in matches/ and equivalent/ (code,
comments, `// equiv-*` lines) take the name. All users or none: refused when a user is excluded, outside matches/ and
equivalent/ (include/gen/ headers are generated: owners.h members are named through evidence-owners.json, later work),
when the definition's invented name is used for anything else in its source, or when the name is already in use.
Callers that name the function by an invented stub name (bound by relocation) keep it for now.

First evidence: **fight parameter callbacks**. The registrations clean1 used (section 12) pass each parameter's
callback; each of the 278 callbacks is registered under exactly one parameter name. `Get<Name>` when its body is
`lea eax,[ecx+X]; ret` (it hands the parameter the field's address), `Set<Name>` otherwise.

Batch 1 (applied): 273 of the 278 callbacks (`include/gen/evidence-fnames.json`; e.g. 0x000480a0 `SetArc_000480a0`,
`Obj_480a0::Set` before, registered by 0x00054160 for CClimbableCondition's "arc"; 0x000481a0 `GetFightNode_000481a0`,
`lea eax,[ecx+0x10]; ret`, CFightNodePrevCondition's "fightNode"; 0x0010c8d0 `SetText_0010c8d0`, AIHistoryNameCondition's
"text", frees the old string and copies the new one). 364 sources: 273 definitions and their registration callers
(278 matches/, 86 equivalent/), 1,090 tokens. Left out: 0x00047b00/10/20 (definitions in include/gen/owners.h) and
0x0012e4d0/0x0012edf0. Renaming those two lets 0x0012ea40, a match outside the batch, merge into GameStateCondition.cpp
(its stub's `Obj::Set` stops colliding with theirs). Its `extern "C" FUN_0008d6d0(hulk_uintptr)` then becomes the TU's
declaration and conflicts on 64 bits with wrapped 0x0012e710's `unsigned int` (the first proof build lost that TU in
the native compile: 4 front-end failures instead of 3). This is section 11's 0x0012ebc0/0x0012f030 hazard, reached
indirectly: **a rename can change which sources merge**. Fewer name collisions mean more merging; check a batch's
gen_tree modes against HEAD (`PYTHONHASHSEED=0 gen_tree.py --fresh` in both workspaces, manifest `blocks[].mode`) and
the native front end before the proof. In batch 1 the only mode left changed is 0x0010ce60, wrapped as "same
definition as 0x0010cc40" before (the two setters had the same text), merged now.

Gates: 278/278 matches MATCH + verify_relocs ok (with the new name_address_mismatch rule); 86/86 equivalents promotable
at 3,000 inputs and at 600 with `--wine`; `--x64` 64 equivalent, 22 fail exactly as at HEAD (the registration
functions' 64-bit layout and int findings, e.g. 0x00075b50 "allocation of 0x18 bytes holds a fight::ParamValueName").
tests/equiv/regress.py --jobq: 415/415 (0x001fe380_tiny_counts needed a rerun: coverage 70% < 80% on a loaded host,
83% alone).

| | control 42586 (HEAD fa3ef1de7, mac1) | batch 1 + tools, 42746 (mac1) |
|---|---|---|
| sources | - | 364 (278 matches/, 86 equivalent/), evidence-fnames.json, the tools above |
| TU modes | - | one source changes mode: 0x0010ce60 merged (was wrapped as the same definition as 0x0010cc40) |
| strict link rc / unbound | 0 / 1,324 | 0 / 1,324 (same symbols) |
| image (PE time stamp zeroed) | - | identical to the control's |
| play3 checkpoints | 2,003 to 60,060 | identical at all 2,003 common frames (batch to 60,090) |
| x87-keep list | - | identical |
| name audit, game (symbols / references) | 46,339 / 48,222 | 46,339 / 48,222 |
| native arm64 link, unbound (front-end failures) | 46,370 (3) | 46,370 (3; same groups) |

(The first proof, 42738, with 0x0012e4d0/0x0012edf0 renamed: checkpoints identical at all 2,001 common frames, but the
image differed and the native compile lost GameStateCondition.cpp, as above. Native groups moved slightly against
section 12's numbers because native_mac.py now counts the old suffix names, `Init_001d43b0` and the rest, as
"function by address"; the total is the same.)

Not reached yet: owners.h members (the 3 callbacks there and the 2,666 `owners::X::FUN_<addr>` definitions: gen_headers
should take their names from evidence-fnames.json), callers that name a renamed function by an invented stub name
(bound by relocation: `name_unify.py member/free` can carry the name over), the Lua API wrappers and RTTI vftable slots
as further evidence sources, and a sweep of `name_address_mismatch` over `FUN_` names in matches/.
