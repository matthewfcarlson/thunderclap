# Class headers (`include/gen/`)

`include/gen/` holds one definition per polymorphic class of the game: 4,244 RTTI classes in 17 namespace headers,
plus `owners.h` (classes RTTI never names). **The headers are source, edited by hand** (since gen1, 2026-11-13), like
`src/` since the merge-once flip ([merge-once.md](merge-once.md)). `tools/gen_headers.py` generated them from the
recovered RTTI until then; it is now only the **layout checker** (the probe below), and the files that fed the generator
(`include/gen/evidence*.json`) are gone. The path stays `include/gen/` so that no `#include` changes.

```sh
build/venv/bin/python tools/gen_headers.py --probe            # compile every header, check every class (~10 s)
build/venv/bin/python tools/gen_headers.py --probe pure3d     # one header's classes
build/venv/bin/python tools/gen_headers.py --probe --update-sizes   # record sizes after an intended layout change
build/venv/bin/python -m unittest tests.test_gen_headers      # name helpers, the model, the probe
```

## Editing a header

- Edit the class where it is. A layout change is a shared change: the TUs that include the header must still verify
  (`tree_tu.py verify . --relocs`, plus the code hashes and `--x64` gate for equivalents), and a Wine proof pair is
  needed when compiled code changes (CLAUDE.md "Builds and proofs").
- Run `--probe` (or `tree_tu.py verify`, which runs it when include/gen/ changed). It must pass; when an edit is meant to change a class's 32-bit `sizeof` (a field the code proves past
  the old end, a pad given its real type), record it with `--update-sizes` and commit `config/gen-sizes.json` with the
  header, so the diff shows the size change.
- Conventions the generator followed, which hand edits keep: slot N introduced by class X is `vfunc_N` until a real name
  is known; every class in a destructor slot family declares its own (pure where its vftable has `_purecall`); fields
  only where code proves the offset (`f_<offset>` until named, `_pad_<offset>` gaps); `hulk_intptr` / `hulk_uintptr`
  for 4-byte words that hold pointers; a comment naming the evidence (address, agent) on anything hand-added.
- New owner classes (non-polymorphic classes RTTI doesn't name) go into `owners.h` by hand; tools/legacy/owner_classes.py, which
  planned them, is retired.

## What's in a header (as generated; hand edits since keep the shape)

- **One header per top-level namespace** (`core.h`, `pure3d.h`, `fight.h`, …), `global.h` for the
  global namespace, `all.h` for everything and `_prelude.h` for one macro. 17 headers in all, covering
  4,244 RTTI classes as 1,611 emitted units (template families count once).
- Forward declarations, then definitions in dependency order. Headers include each other only for
  base classes and enclosing classes; there are no include cycles.
- **Nested classes** (`content::LoadInventory::DynamicCasterBase`, `pure3d::Skeleton::Limb`, … 24 of
  them) are declared inside their enclosing class and defined after it as `class Outer::Inner`.
  A qualifier counts as a class if it's an RTTI class, and as a namespace otherwise. Mangled names
  don't distinguish the two, so a wrong guess can't change codegen.
- **Bases** in RTTI declaration order. MSVC lays them out as in the game; the probe checks every offset.
- **Virtual methods in vtable order.** Slot N introduced by class X is `vfunc_N` (the same name
  `functions.csv` uses for the slot's owner). Overrides are redeclared in the overriding class,
  inherited slots aren't, `_purecall` slots are `= 0`, and each class's comment line gives its
  vftable address(es).
- **Destructors.** A slot is `virtual ~X()` when most of its bodies look like a scalar deleting
  destructor (`test byte ptr [esp+N], 1` and `ret 4`, following adjustor thunks); 85 slot
  families qualify. Every class in such a family declares its own destructor, pure where its vftable
  has `_purecall` (interfaces such as `core::IRefCount` declare pure virtual destructors).
- **Parameter counts are proven:** each slot gets as many parameters as its bodies pop (`ret N`).
  Types are `int` unless a match proves otherwise (below).
- **Fields only where proven:** `char _pad_XX[N]` plus `T f_XX` for offsets that matched code
  reads or writes through `this` (mined from `matches/`, or curated in the tool), and tail
  padding where a multiple-inheritance base offset proves a base's size.

## Verification: the layout probe

`--probe` builds a model of the game's classes from `build/rtti.json` and the XBE (bases, vftables, the class that
implements each slot, destructor slots; nothing from the headers), compiles each header on its own with `cl` 13.10
`/c /O2 /GR /GX-`, then one TU per header that includes `gen/all.h` and constructs every RTTI class placed in that
header (abstract ones through a derived probe class; constructors a class declares out of line, like
`fight::Track()`, are defined in the probe TU) with `/Od`, so every vftable and RTTI descriptor lands in the object,
and parses the COFF:

| Check | Result (gen1, 2026-11-13, HEAD 9bbef387f) |
|---|---|
| headers compiling cleanly (the 17 namespace headers and owners.h) | 18/18 |
| classes with vftable + base descriptors emitted | 4,238/4,238 (the other 6 have no vftable and are forward-declared: `math::Vector`, `audio::Mixer`, 4 CRT exception types) |
| vftables with the RTTI slot count | 4,266/4,266 |
| slots whose function is the one RTTI says (the class that last overrode it, or `_purecall`) | 27,439/27,439 |
| `??_R1` base class descriptors (mdisp/pdisp/vdisp) identical to the XBE's | 4,238/4,238 |
| `sizeof` equal to `config/gen-sizes.json` (concrete classes) | 4,039/4,039 |

The first four checks compare with RTTI and the XBE. RTTI carries no sizes, so the size check is a ratchet instead:
`config/gen-sizes.json` holds the 32-bit `sizeof` of every concrete class as the headers had it when last recorded
(first from the committed headers at the flip). Until the flip the probe compared with the generator's own layout;
hand edits since then (typ1's records, x64t5-x64t8's allocation sizes) had grown 15 classes past it, and the flip's
recording takes the headers as they are. Multiple-inheritance base sizes are covered by the base descriptors (a base of
the wrong size moves the next base's offset).

The probe checks the 32-bit MSVC layouts only; the 64-bit layouts are the native builds' and `equiv.py --x64`'s.

### The probe in verify (tool2, 2026-11-13)

`tools/tree_tu.py verify` runs the probe whenever a header under include/gen/ changed (since `--changed-since REF`,
else uncommitted; in a queue job, shipped) and fails when it does (summary `gen_probe`: counts, the problems' first
lines, seconds); `check TU` runs it when the TU can `#include` such a header; `--gen-probe` forces it. In a queue job
it needs nothing extra: include/gen/ and config/gen-sizes.json are in the base tree (ship your edits of both; the
submit guard refuses a job whose probe would read an unshipped gen-sizes.json), build/rtti.json, functions.csv, the
XBE and wibo come through the workspace's `build/` and `isos/` links.

**The probe writes nothing into the checkout.** Its probe TUs and objects go to a fresh directory under build/tmp/
(removed afterwards; `--keep DIR` must be under build/ or outside the checkout); only `--update-sizes` writes a tracked
file. An agent's `--probe` run in the shared checkout was once refused by the auto-mode permission check as a
destructive action: that agent had read the tool when it still regenerated include/gen/ (deleting the headers it did
not write). Running it through `tree_tu.py verify` / `check`, or after reading the current tool, avoids that.

## Multiple and virtual inheritance

No class in the game uses virtual inheritance. 21 classes have more than one polymorphic base, all
in `core`, `movie`, `pure3d::TextBible` and `CSPListener`. They're mostly a primary interface plus
`core::Object`/`RefCount`/`SafeRefCount`/`IMutable` at a non-zero offset:

`CSPListener`, `core::{TimerList, ControllerSystemXBox, MemoryDlAllocator, MemoryTwoWayAllocator,
ConsoleClient, DebugConsole, Drive, XboxDrive, MemoryPool, ControllerBuffer, DriveThread, File,
InstanceDrive, CementLibrary, XboxSaveDrive}`, `pure3d::TextBible`,
`movie::{PlayerBink, RenderStrategyBink, BinkCallback}`.

- `core::CementLibrary` has `core::IRefCount` twice (non-virtually, through `ICementLibrary` and
  `IFileCompletionCallback`). That's legal C++ and reproduced as is.
- **Base sizes proven by offsets.** `core::Drive` has `Object` at +4 and `SafeRefCount` at +0xc, so
  `sizeof(core::Object) == 8`. The generator pads such bases so MSVC puts later bases where the
  game has them. `XboxSaveDrive` puts `SignedReader` at +0xbc, so `Drive`'s size is proven too.
- **Slot-name collisions.** One declaration `vfunc_N` in a class overrides every inherited
  `vfunc_N` with the same parameters. Where the vftables disagree with that (one inherited and one
  overridden, different arities, or different final functions), the less-used family is renamed
  `vfunc_N_<Introducer>`: `IMutable` slots 0/1, `SignedReader` 0–2, `SignedWriter` 0/1,
  `ICementLibrary` 3, `ILanguageChangeCallback` 3, `StatePropListener` 0 and `BinkCallback` 1
  (11 renames).

## Templates

2,688 of the 4,244 classes are template instantiations in 55 families. Each family is emitted
once as a primary template with all its instantiations (and their vftables) listed in a comment.
Bases are written in terms of the parameters, e.g. `Closure1<T0,T1,T2> : Method1<T0,T1,T2>`,
`om::MetaTypeAttribScalar<T0> : om::MetaTypeAttrib<T0>`. If some instantiations had a different
base list or slot pattern, the generator would emit explicit specializations for them; none do.
No family has non-type parameters.

| Family | Instantiations |
|---|---|
| `fight::ParamFloatConstRange` | 308 |
| `fight::TrackFactoryTemplate` / `TrackFactoryCasterTemplate` | 245 / 245 |
| `fight::ConditionFactoryTemplate` / `ConditionFactoryCasterTemplate` | 221 / 221 |
| `fight::ParamEnumConstList`, `ParamBool`, `ParamIntConstRange`, `ParamName`, `ParamVector`, … | 168, 146, 141, 77, 63, … |
| `Method0`–`Method7`, `Closure0`–`Closure7` (script bindings) | 324 each |
| `content::LoadInventory::DynamicCaster` | 49 |
| `Function0`–`Function7`, `pure3d::pddiStack`, `om::TypeT`, … | small |

Template arguments that aren't RTTI classes (`CActorManager`, `hulkfight::DialogueTrack`, …, 22 of
them) are forward-declared in their namespace's header. Two enums named only in template
arguments get empty definitions (enumerators unknown), and so does the nested one
(`ScriptHandler::script_state`): an opaque `enum X;` is an MSVC extension that every non-MSVC clang target
rejects (692 TUs, [wine-build.md](wine-build.md) fix 1), and MSVC 7.1 rejects the C++11 `enum X : int;`.
An empty enum has `int` as its underlying type, as MSVC gives the opaque one.
**Member-pointer model.** `Method1<T,…>` stores a 4-byte member-function pointer (`f_1c`, proven by
`method.cpp`). For an incomplete `T`, MSVC would pick the 16-byte general representation, so the
forward declarations carry `HULK_SINGLE_INHERITANCE` (`__single_inheritance` under MSVC/clang,
empty elsewhere). Without it, 104 `Method*`/`Closure*` sizes come out wrong.

## Not expressible yet / known gaps

- **Destructor-slot matches** (a third of vfunc matches) are hand-written scalar deleting
  destructors (`void* X::scalar_dtor(unsigned char)`). With real headers they become
  `X::~X() {}` plus member/base destructors, and the compiler generates the deleting wrapper.
  That's a rewrite, not a swap. Only the empty case works so far: MSVC 7.1 never inlines a
  non-empty destructor into its scalar deleting destructor (`??_G` calls `??1` out of line, tried
  with out-of-line, in-class, `inline`, `__forceinline`, explicit specializations, nothrow callees
  and member destructors; x64-4, 2026-10-24), while the game's `??_G` bodies contain the vptr store
  and the level's clean-up inline (e.g. 0x00051fb0, 468 `ConditionFactoryTemplate<T>` /
  `TrackFactoryTemplate<T>` slots of that shape).
- **Parameter and return types** are only proven by count. Mined types come from stub guesses.
  Return types default to `void` for slots no match has defined.
- **Non-virtual member functions**: RTTI doesn't list them. The ones a source *defines* as its own
  function are declared in their class from that source (`R FUN_<addr>(P...); // non-virtual`,
  first by `tools/legacy/rn_members.py`, batch b9, now by hand; types: scalars kept,
  a pointer to the class itself as `X*`, other pointers `void*`). Callers keep declaring the members
  they call on a local helper struct (`((X_nv_<addr>*)this)->f()`), which compiles to the same code.
- **Constructors**: a class declares the ones a source defines out of line (`X(P...);`, e.g. unb5's
  `fight::Track()` for 0x00236d40, which the derived classes' constructors call; the probe defines them in its own
  TU so the vftable is emitted there). Bodies that make calls get an EH frame on the headers
  (because of the base's virtual destructor) that the game lacks. Call-free ones byte-match, but defining them makes
  the header vftables appear in the tree with unbound slot symbols (docs/consolidation-plan.md section 9, round 3).
- **Pointers in integer fields**: a 4-byte field that sources read as a pointer
  (`*(T**)&p->f_20`, `tools/ptr_fields.py`) is `hulk_intptr` / `hulk_uintptr`: `int` / `unsigned int` on the
  32-bit builds, pointer-sized on the 64-bit ones. Where the 64-bit work needs real pointers the field is a pointer
  (x64t2-x64t8). `_pad_` arrays after such a field still assume 32-bit offsets.
- **Field names**: a field is `f_<offset>` until a name is proven (clean1 named 218 from evidence; new names are
  edits of the header and its users). The retired `tools/legacy/param_fields.py` named the fields of the fight Track/Condition classes from their
  parameter registrations: the string literal passed to a `fight::ParamValue*` constructor and the setter
  registered with it, whose one store through `this` gives the offset (CClimbableCondition +0x10 `arc`).
  The retired `tools/legacy/rename_fields.py` rewrote the sources' references (libclang-resolved, so `f_10` of another class is
  never touched). See docs/consolidation-plan.md section 12.
- **Function names** (clean2): the retired `tools/legacy/fn_names.py` named functions by address, with evidence
  (`evidence-fnames.json`, removed at gen1); `tools/name_unify.py rename --names FILE` applies such a list to the definition and every `FUN_<addr>`
  reference. Each name keeps its address as a suffix (`SetArc_000480a0`, tools/addr_names.py), which every tool
  that reads an address from a name understands. Members of include/gen/ headers (owners.h) are not renamed yet.
  See docs/consolidation-plan.md section 13.
- **Fields of embedded objects**, arrays, and fields reached through raw `(char*)this + N`
  arithmetic aren't mined. Fields of non-RTTI classes (anything the game doesn't `dynamic_cast`
  or `typeid`) have no home yet.
- **rtti.py over-counts** a vftable that is directly followed by a code-looking pointer.
  `om::DynBehaviour` had 3 slots where every derived class has 2. The generator truncates a base
  vftable that is longer than all of its derived classes' (and so does the probe's model). The bogus third "slot" `0xa5d0a` is
  also a bogus function in `functions.csv` (`om::DynBehaviour::vfunc_2`, 1,449 bytes).
- Two destructor-shaped slots in one primary chain: `pure3d::pddiRenderContext` 87/88,
  `pddiBaseContext` 102 and `movie::BinkCallback` 1. Only the first one in the chain becomes the
  destructor; the others stay `vfunc_N`.
- **64-bit:** the headers are 32-bit layouts (`char _pad` sizes assume 4-byte pointers). A port
  build needs real member types before the pads can go.

## History: the generator (until 2026-11-13)

`tools/gen_headers.py` emitted the headers from RTTI: bases in RTTI order, virtual methods in vftable order (`vfunc_N`,
destructors where most slot bodies have the scalar deleting destructor's shape, parameter counts from `ret N`), template
families once, and fields from evidence: signatures and `this->field` offsets mined from `matches/` with clang
(`--mine`, `include/gen/evidence.json`: 9,909 signatures, 1,795 fields), the consolidation batches' sources
(`evidence-rn.json`: fields, signatures, non-virtual members, constructors, pointer-sized fields), field names from the
fight parameter registrations (`evidence-names.json`, tools/legacy/param_fields.py), owner classes (`evidence-owners.json`,
tools/legacy/owner_classes.py) and function names (`evidence-fnames.json`, tools/legacy/fn_names.py, applied by `name_unify.py
rename`). From x64t2 on, agents edited the headers by hand where the generator had no input for what they needed
(records' pointer fields, allocation sizes, base-class words moved up), so the committed headers and the generator's
output drifted apart.

**The loss check (gen1).** Regenerating from HEAD 9bbef387f's inputs in a private export and diffing with the committed
headers gave 219 differing lines in 7 headers (audio, content, fight, global, owners, physics, pure3d). Every one is a
hand edit the generator lacked (typ1, x64t2-x64t8, unb5): typed records where the generator has pads or `int`, fields
moved into a base, `HULK_REFCOUNT_PACK`, `fight::Track()`, comments. Nothing in the inputs was missing from the headers:
every field the generator emits is in the committed headers at the same offset, in the same class or (where a hand
edit moved the words up) its base, with the generator's type or one a hand edit chose on evidence (e.g. x64t6 keeps
`physics::CollisionVolume`'s +0x20 an `int` where a stub vote had said `void*`). Its 19 dropped evidence items (signatures whose arity contradicts `ret N`) were
rightly never emitted. The function names of `evidence-fnames.json` are applied in `src/` except seven that were left
out on purpose (consolidation-plan.md section 13); they are listed in native-build.md "gen1".

Retired with the generator: `--mine`, `--swap-test` and the regeneration; tools/legacy/migrate_gen.py, rn_members.py,
rn_sigs.py, rn_ptrfields.py, rn_fields.py, ptr_slots.py, param_fields.py, rename_fields.py, fn_names.py and
owner_classes.py (they wrote the evidence files or rewrote matches/ onto the generated headers; they now refuse to run).
The clang helpers rn_transform.py used moved into it. Git history keeps the generator (`git show 9bbef387f:tools/gen_headers.py`).

## Hand matches on the headers

`experiments/first-matches/*_gen.cpp` are the original experiments rewritten on `#include <gen/…>`.
They define `X::vfunc_N` against the generated declarations and use `f_XX` fields, and all 5
functions still MATCH:

| File | Function | Result |
|---|---|---|
| `refcount_gen.cpp` | `pure3d::NonCopyable::vfunc_1` (Release; `delete this` goes through the generated virtual dtor) | MATCH |
| `action_gen.cpp` | `CAction::vfunc_5` (calls slots 7/8) | MATCH |
| `action_gen.cpp` | `CHitAnimationAction::vfunc_9` (`f_1c` from the header, a local stub for the object it points at) | MATCH |
| `method_gen.cpp` | `Method0<CActorManager,int>::vfunc_2` (explicit specialization of the generated template's member) | MATCH |
| `method_gen.cpp` | `Method1<CActorManager,void,const char*>::vfunc_2` | MATCH |

## Sources on the headers (2026-10-16)

`tools/legacy/migrate_gen.py` rewrites `matches/` and `equivalent/` sources onto these headers (rules and numbers in
[source-tree.md](source-tree.md#includegen-migration-2026-10-16)): about 8,100 sources now `#include "gen/<ns>.h"`
and define the real member, e.g. `template <> bool fight::ParamFloatConstRange<CFoo>::vfunc_6(int a, int b)` or
`CCollisionAction::~CCollisionAction() {}` (MSVC generates the matched scalar deleting destructor from it). The
headers themselves did not change: every rewrite that needed a missing field or slot type was rejected rather than
the header widened (926 sources, 230 of them in matches/, wait on fields the headers lack; see the next steps there).

`include/decls/address.h` is a separate, hand-maintained header: pinned prototypes of a few address names many
sources declare (`extern World* DAT_004dd700;`, `unsigned __int64 FUN_0027b020(const char*);`, ...). It declares
the pointed-to classes only; sources keep defining the members they use. `tools/rename_placeholders.py` never
renames its class names.
