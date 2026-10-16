# Generated class headers (`include/gen/`)

`tools/gen_headers.py` turns the recovered RTTI (`build/rtti.json`) into shared C++ headers, one
definition per class. Matched functions can include them in place of per-file stub classes
(roadmap stage 2). The headers are generated: change the tool or its inputs, never the headers.

```sh
build/venv/bin/python tools/gen_headers.py            # regenerate include/gen/ (≈2 s)
build/venv/bin/python tools/gen_headers.py --report   # plus every renamed slot, vote split, etc.
build/venv/bin/python tools/gen_headers.py --probe    # compile + layout-check every header (≈25 s)
build/venv/bin/python tools/gen_headers.py --mine     # re-mine matches/ -> include/gen/evidence.json (≈20 min, cached)
build/venv/bin/python tools/gen_headers.py --swap-test 200   # recompile 200 matches on the headers
build/venv/bin/python -m unittest tests.test_gen_headers     # also checks include/gen is current
```

## What's in a header

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

`--probe` compiles each header on its own with `cl` 13.10 `/c /O2 /GR /GX`. It then compiles a TU
that constructs every class (abstract ones through a derived probe class) with `/Od`, so every
vftable and RTTI descriptor lands in the object, and parses the COFF:

| Check | Result |
|---|---|
| headers compiling cleanly | 17/17 |
| classes with vftable + base descriptors emitted | 4,238/4,238 (the other 6 have no vftable and are forward-declared: `math::Vector`, `audio::Mixer`, 4 CRT exception types) |
| vftables with the RTTI slot count | 4,266/4,266 |
| slots whose function is the one RTTI says (the class that last overrode it, or `_purecall`) | 27,439/27,439 |
| `??_R1` base class descriptors (mdisp/pdisp/vdisp) identical to the XBE's | 4,238/4,238 |
| `sizeof` equal to the generator's layout (concrete classes) | 4,039/4,039 |

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
arguments get empty definitions (enumerators unknown).
**Member-pointer model.** `Method1<T,…>` stores a 4-byte member-function pointer (`f_1c`, proven by
`method.cpp`). For an incomplete `T`, MSVC would pick the 16-byte general representation, so the
forward declarations carry `HULK_SINGLE_INHERITANCE` (`__single_inheritance` under MSVC/clang,
empty elsewhere). Without it, 104 `Method*`/`Closure*` sizes come out wrong.

## Field and signature evidence from `matches/` (first pass)

`--mine` parses every match whose target is a `Class::vfunc_N` (10,519 files) with clang (MS ABI,
i686), finds the matched definition, and records:

- its **signature** (primitive types kept, pointers/references as `void*`), which applies to the
  slot and to every override;
- every **`this->field`** it touches, at the offset clang's MS-ABI record layout gives for the stub.
  The bytes matched, so the offset (and the access width) is proven for the slot's owner class.

Results: 9,909 signatures and 3,635 files with `this`-relative field accesses (373 files had no
recognizable member definition, and clang couldn't parse 15). After voting, **1,012 of the 1,535
slot families** have a mined or curated signature. **1,795 proven fields in 781 classes** are emitted
(the probe still passes with all of them). The evidence lives in `include/gen/evidence.json`, so
regeneration doesn't need clang; the raw per-file cache is `build/gen_mine_cache.json`.

Evidence is kept only where it's consistent with the binary: a signature must have the parameter
count the slot's `ret N` proves, and fields that overlap or are misaligned are dropped. The
remaining disagreements are votes, and the majority wins. `--report` lists every split: these are
stub-type guesses that differ between matches (`int` vs `void*` vs `unsigned int`, `bool` vs
`unsigned char`), not layout conflicts. A field that falls inside a base class's proven extent is
left to the base. Types are only as good as the stubs: a 4-byte field's offset is proven, but whether it's
`int` or a pointer isn't.

## Swap-in measurement

`--swap-test N` takes N random `vfunc_N` matches and rewrites each one mechanically onto
`#include <gen/all.h>`, then runs `compare.py`. The rewrite:

- replaces the stub for the owner class with `typedef <real class> __Self`;
- redefines the target as `__Self::<header slot name>(<header parameter types>)`, casting
  parameters back to the stub's types in a prologue;
- maps stub fields to `f_XX` by clang's layout offset, with a cast when the stub type differs;
- maps calls to stub virtuals to the header's slot names by stub vtable index;
- routes stub non-virtual helpers through a local `__Self_nv` declaration struct;
- renames other stubs whose names collide with generated classes.

Two samples of 200 (seeds 1 and 2):

| Outcome | seed 1 | seed 2 | total |
|---|---|---|---|
| **MATCH** | 108 | 112 | **220** |
| DIFF (compiles, bytes differ) | 0 | 0 | **0** |
| compile error | 6 | 4 | 10 |
| target is a destructor slot (not attempted) | 66 | 64 | 130 |
| stub has multiple bases | 7 | 7 | 14 |
| ambiguous: several definitions, can't tell which matched | 9 | 6 | 15 |
| field the match uses isn't in the header | 3 | 4 | 7 |
| other rewrite limits (slot returns `void` in the header, float/int parameter clash, nested stub base, calls a destructor slot by name) | 1 | 3 | 4 |

Excluding destructor slots, **220 of 270 (81%)** matches survive the swap. Every rewrite that
compiled still matched: the generated layouts never changed codegen. The failure modes:

- **Destructor slots (a third of the sample):** the matches are hand-written scalar deleting
  destructors, which a header can't absorb (see gaps).
- **Signature disagreements** (C2664/C2440): a match calls a slot with arguments or a return type
  that differ from the voted signature (`int` vs pointer, a `void` return the header didn't learn).
  These need real parameter types, which means human naming.
- **Qualified non-virtual calls to a base's implementation** (`Base::vfunc_62()`, C2352) and stubs
  with several bases: the mechanical rewrite doesn't handle these.
- **Fields not in the header:** the access is in a base's range, lost a type vote, or (for
  `Method2+` before they were curated) was a member-function pointer the miner doesn't type.

## Not expressible yet / known gaps

- **Destructor-slot matches** (a third of vfunc matches) are hand-written scalar deleting
  destructors (`void* X::scalar_dtor(unsigned char)`). With real headers they become
  `X::~X() {}` plus member/base destructors, and the compiler generates the deleting wrapper.
  That's a rewrite, not a swap.
- **Parameter and return types** are only proven by count. Mined types come from stub guesses.
  Return types default to `void` for slots no match has defined.
- **Non-virtual member functions** aren't in the headers: RTTI doesn't list them. Matches keep
  declaring them on a local helper struct (`((Helper*)this)->f()`), which compiles to the same code.
- **Fields of embedded objects**, arrays, and fields reached through raw `(char*)this + N`
  arithmetic aren't mined. Fields of non-RTTI classes (anything the game doesn't `dynamic_cast`
  or `typeid`) have no home yet.
- **rtti.py over-counts** a vftable that is directly followed by a code-looking pointer.
  `om::DynBehaviour` had 3 slots where every derived class has 2. The generator truncates a base
  vftable that is longer than all of its derived classes'. The bogus third "slot" `0xa5d0a` is
  also a bogus function in `functions.csv` (`om::DynBehaviour::vfunc_2`, 1,449 bytes).
- Two destructor-shaped slots in one primary chain: `pure3d::pddiRenderContext` 87/88,
  `pddiBaseContext` 102 and `movie::BinkCallback` 1. Only the first one in the chain becomes the
  destructor; the others stay `vfunc_N`.
- **64-bit:** the headers are 32-bit layouts (`char _pad` sizes assume 4-byte pointers). A port
  build needs real member types before the pads can go.

## Sources on the headers (2026-10-16)

`tools/migrate_gen.py` rewrites `matches/` and `equivalent/` sources onto these headers (rules and numbers in
[source-tree.md](source-tree.md#includegen-migration-2026-10-16)): about 8,100 sources now `#include "gen/<ns>.h"`
and define the real member, e.g. `template <> bool fight::ParamFloatConstRange<CFoo>::vfunc_6(int a, int b)` or
`CCollisionAction::~CCollisionAction() {}` (MSVC generates the matched scalar deleting destructor from it). The
headers themselves did not change: every rewrite that needed a missing field or slot type was rejected rather than
the header widened (926 sources, 230 of them in matches/, wait on fields the headers lack; see the next steps there).

`include/decls/address.h` is a separate, hand-maintained header: pinned prototypes of a few address names many
sources declare (`extern World* DAT_004dd700;`, `unsigned __int64 FUN_0027b020(const char*);`, ...). It declares
the pointed-to classes only; sources keep defining the members they use. `tools/rename_placeholders.py` never
renames its class names.
