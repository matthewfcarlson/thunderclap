# The native links' unbound names: a plan for the last 29,000 (plan1, 2026-11-10)

The arm64 macOS, x86-64 Linux and arm64 Android links still stub **29,010 / 28,995 / 29,002** names (x64t1's batch 5,
proof 71460). Each batch along the start-up path fixes about 25. This document sorts the macOS names by root cause and
proposes source-side fixes that clear them by the thousand. The rule is the user's: fix in source, with no link-time
redirect of local vftables to the game's. Every number here is measured on one snapshot, unless the text says it is an
estimate.

Status of the numbers:
- **measured**: the classification (sections 2 and 3) and the rename prototype (section 5.1);
- **simulated** from the objects and the Wine map: the slot-naming prototype (section 5.2);
- **estimated**: the other buckets' gains (section 4).

## 1. Summary

- **The unit is a (TU, callee) pair, not a callee.** gen_tree puts every TU's declarations in a TU namespace
  (`fn_f<7 hex>`), so each TU's declaration of a callee is its own symbol. 29,010 unbound names come from 30,872
  object references; almost every name is one TU's view of one callee. So a fix at the callee's definition or in a
  shared header reaches all of that callee's TUs at once. The hot callees are few: 101 addresses carry all 2,448
  invented names whose address has no 64-bit definition, and the top 10 carry 93% of them.
- **Close to half of the names (13,295, 46%) need no new semantics, only names.** Four buckets are pure renames or
  declarations. The 32-bit code stays the same, and they are mechanical:
  - B2 / B2b: invented callee and data names that the Wine map already binds to one address, 8,621 names;
  - B3: stub virtual members named after their game vftable slot, 2,226;
  - B1: jmp-thunk and CRT names, 1,278;
  - B0: the two TUs the 64-bit front end rejects, 1,170.
- **The prototype rewriter for B2 / B2b** (`build/plan1/scripts/rename.py`, libclang) was measured end to end on a
  private workspace. It renamed 9,150 (TU, name) pairs in 1,482 TUs. In the Wine build of that tree (job 71502):
  - all 22,339 matches still match and all 5,099 equivalents compile;
  - the Wine image is **byte-identical** to the control's (2e8232cd).

  The native links go from 29,010 to **22,880** (macOS) and from 28,995 to **22,860** (Linux), **-6,130** in one
  mechanical pass. The rewriter needs three fixes before it is a tool: operators, `#if` branches, and an MSVC gate
  per TU (section 5.1).
- **Two blockers hold back more names (one tool fix, one source fix):**
  - The 64-bit objects have no scalar deleting destructors. Clang emits `??_G` only where it emits the class's
    vftable, so 1,871 tree definitions have no 64-bit symbol. This blocks 1,650 stub vftable slots and 1,871 of the
    link's 3,614 `hulk_x_` game-vftable slots.
  - `src/engine/fight/Track.cpp` fails the 64-bit front end, on an ambiguous call created by a `hulk_uintptr`
    argument. Its 15 definitions are missing, which blocks 1,170 names and 656 game-vftable slots.
- **The rest is real 64-bit typing, about 10,000 names.** Callers whose declarations pass differently (B6 / B6b,
  7,047) and setters taken by address with a `void f()` declaration (B5, 2,882). These need the definitions' types
  at the callers. The plan does it per callee family, through shared headers (owners.h / include/gen classes)
  rather than per TU.

## 2. Data and method

- **Snapshot.** The clang-probe snapshot and binding map of x64t1's proof 71460 (studio lineage `x64t1-p5`, the tree
  at 6fbb78f17; HEAD has changed only tools since).
- **Build.** Recompiled on studio through the queue (jobs 71464 macOS and 71465 Linux, about 80 s each from the
  caches) and linked locally with `--bindings`. The counts reproduce x64t1's: macOS 29,010 (bound by address
  14,717), Linux 28,995.
- **The metric** is native_mac's: the `unbound:` groups of `link-report.json`, one per distinct undefined symbol,
  after the address bindings and less the CRT and XDK table rows. Those rows are 1,007 names more and are counted
  apart. The link's 3,614 `hulk_x_` game-vftable slots are not in the metric (section 3.4).

Scripts (build/plan1/scripts/, kept):

| script | what it does |
|---|---|
| `natfetch.sh` / `natbuild.sh` | x64t1's, retargeted to build/plan1; `NORUN=1` skips the macOS run |
| `classify2.py` | every unbound name with its link group, why the address binding refused it (`plan_link`'s class and IR detail), the referencing TUs and, for names without an address, the Wine map's address and whether the tree's 64-bit definition there has the same IR signature as the reference |
| `relocscan.py` | how each name is used, from the Mach-O relocations: called (`BRANCH26`), address taken in code (`PAGE21`), or data (a vftable slot or a table) |
| `slotsim.py` | for each stub virtual member: the local vftable and slot that hold it (`llvm-readobj --section-relocations`), the game vftable the Wine map pairs with that local vftable, the XBE word in the same slot, and the tree's 64-bit definition there, with an IR-signature check |
| `buckets.py` | one fix bucket per name (below) |
| `samples.py` | file:line samples (the first line of the referencing TU that spells the name) |
| `rename.py` | prototype rewriter 1 (section 5.1) |
| `msvc_errs.py` | the first MSVC error of each TU in a list (tree_tu's compile, in build/plan1/ws) |

## 3. The 29,010 names by root cause

### 3.1 By what the name is

| what | names | how it is used | why the link refuses it |
|---|---|---|---|
| **virtual member of a stub class** | 7,443 | 7,037 only as a vftable slot of a local vftable; 406 called | no address in the name; the Wine build aliases these slots, and its map has none of them |
| **address name, IR signature differs** | 7,049 | 4,167 called; 2,861 address taken only (`&Track::FUN_x` in parameter tables); 21 data | argument count 3,443; pointer / int 1,230; float / int 513; byte widths (i1 / i8 / i32 results and arguments) 920; pointer / int64 and int / int64 433; the rest small |
| **member of a stub class** (non-virtual) | 6,426 | called | no address in the name: 3,334 have the definition's IR signature at the Wine map's address, 2,287 do not, 787 have no 64-bit definition there, 18 unmapped |
| **free function** (C++ or C linkage) | 2,475 | called | 565 same signature; 1,378 have no 64-bit definition at the address (jmp thunks to free / alloc, the CRT's `__RTDynamicCast`, Track.cpp's functions); 407 differ; 99 unmapped or ambiguous |
| **vftable variable** (`Foo_vftable`, `g_vftable_12afe0`) | 2,119 | address | no address in the name; 2,110 mapped by the Wine map to a game vftable |
| **variable** | 1,863 | address | no address in the name; 1,789 mapped to a data item |
| **constructor / destructor of a stub class** | 1,166 | called | 737 same signature; 232 have no definition (Track.cpp); 186 differ; 11 unmapped |
| **address name, no unique 64-bit definition** | 257 | called | Track.cpp 87; definitions named `target` / `Target` in several wrapped namespaces 167 |
| RTTI descriptor variable | 60 | address | no address in the name |
| other address names | 152 | | data address inside an item 58, not verified by the map 41, outside .text 28, bound in some objects only 16, no tree definition 9 |

### 3.2 By fix bucket

Every name is in exactly one bucket (`buckets.py`). "Refs" counts the objects that reference the name.

| bucket | root cause | names | refs | fix (section 4) | 32-bit risk |
|---|---|---|---|---|---|
| **B0** | the defining TU fails the 64-bit front end (Track.cpp 15 definitions; CSoundSequence.GS.cpp) | 1,170 | 1,196 | two front-end fixes, then B2 for the invented callers | none (a cast) |
| **B1** | invented names of `jmp` thunks (0x00263f30, 0x0008d330 / 0x0008d340 to free 0x00267090; 0x00263ea0 to alloc 0x0008d690) and CRT routines (0x00344e74 `__RTDynamicCast`, 0x00345804 ...) | 1,278 | 1,359 | rename to `thunk_FUN_` / `FUN_` of the thunk, or to the CRT name the native CRT table has | none (names) |
| **B2** | invented function names the Wine map binds to one address, with the definition's IR signature | 4,636 | 4,837 | **rename to the suffix convention** (`Helper_0027af50`) | none (names; verify_relocs then checks them) |
| **B2b** | invented data names (vftable variables, variables, RTTI descriptors) the map binds | 3,985 | 3,991 | **rename to `hulk_at_<addr>`** (the link binds it to `DAT_<addr>`) | none (names) |
| **B3** | stub virtual members whose game slot's definition has the same IR signature | 2,226 | 2,227 | **name the virtual after its slot's address** | none (names) |
| **B3b** | the same, signature differs (2,120 argument count: `virtual void A()` for a slot that takes arguments) | 2,171 | 2,173 | slot name + the definition's declaration (only referenced through the vftable) | low (vftable-only members) |
| **B4** | the slot's definition has no 64-bit symbol: 1,650 scalar deleting destructors, 124 `_purecall` (0x00344f51) | 1,677 | 1,677 | tool: emit `??_G` on 64-bit; declare pure slots `= 0` | none (64-bit only / names) |
| **B5** | address names taken by address only, declared `void f()` | 2,882 | 2,884 | the setters typed end to end (sh2's member-function-pointer method) | low (sh2: complete single-inheritance member pointers are the address) |
| **B6** | address names called with a declaration that passes differently | 4,167 | 4,201 | callee-family declarations in shared headers, plus definition-side retyping (unb2's method) | medium: per-TU MSVC gate |
| **B6b** | invented names with a different IR signature | 2,880 | 2,989 | B2's rename, then as B6 | medium |
| **B7** | stub virtuals in a local vftable the Wine map does not pair with a game vftable | 831 | 831 | vftable by address where the constructor is known (x64t1's method), or pair by RTTI name | low |
| **B8** | address names: `target` definitions not unique on 64-bit (167), data inside items, not verified, outside .text | 319 | 412 | rename the definitions to address names; data inventory | none / low |
| **B9** | the rest: names the map binds ambiguously or not at all (167), called stub virtuals (531), ... | 788 | 2,095 | by hand, as found | - |
| | **total** | **29,010** | **30,872** | | |

### 3.3 Samples (file:line, demangled name, [address the name or the map gives])

B2, member of a stub class, same IR signature (3,334):
- src/engine/pure3d/prop/CMotionTrail.cpp:896 `fn_f4890d4c::EffectQueue_2834f0::Cleanup2()` [0x0027afd0]
- src/game/hulkfight/motion/CollisionTargetTypeCondition_2.cpp:36 `ConditionFactoryTemplate_159a30::base2_dtor()` [0x002343d0]
- src/engine/pure3d/TextBible.cpp:256 `Item_2c3a20::Fini()` [0x00263e90]
- src/game/hulkfight/motion/LocomotingCondition.cpp:348 `A_15c460::f592()` [0x000592a0]

B2, constructor of a stub class, same IR signature (737; a constructor binds when its class is named by the address:
`FUN_001d0480`, sh2's rule):
- src/game/hulkfight/motion/PropThrowAction.cpp:560 `Action_184110::Action_184110()` [0x00232660, fight::Action]
- src/game/global/CFEManager.cpp:1681 `CtorV_001d0480::CtorV_001d0480(const char*, int)` [0x001d0480, Function]
- src/game/global/CUnlockableJumpMarker.cpp:30 `Part_934d0::Part_934d0()` [0x0027af00]

B2b, vftable variables and variables (3,985):
- src/game/hulkfight/ai/AcquireTargetTrack_3.cpp:31 `int g_vftable_12afe0` [0x00410b64]
- src/game/global/CAxisTimeCondition.cpp:23 `void** CAxisCondition_4b2e0_vftable` [0x003f6d50]
- src/game/global/CTimeManager.cpp:113 `Root_863e0* g_863e0` [0x004dd700]
- src/game/hulkfight/motion/FireBeamTrack.cpp:22 `int rttiB` [0x00494b60]

B1, jmp thunks and CRT (1,278):
- src/game/hulkfight/ai/TargetDistanceCondition_3.cpp:91 `thunk_delete(void*)` [0x00263f30, `jmp` to 0x00267090]
- src/game/global/CClimbableCondition.cpp:140 `SweepTrack_DeleteThis(void*)` [0x0008d330, `jmp` to 0x00267090]
- src/game/hulkfight/motion/FireProjectileAction.cpp:837 `Check(void*, int, Params_19b3c0*, ...)` [0x00344e74, `__RTDynamicCast`]
- src/game/hulkfight/motion/JointRelativeTrack_3.cpp:27 `do_cast` [0x00344e74]

B3 / B3b, stub virtual members (vftable slots):
- src/game/global/AICollisionSolverAgent.cpp:223 `Function_1b1660::f()`
- src/game/hulkfight/motion/TeleportRelativeTrack_4.cpp:35 `TeleportRelativeTrack_17ea80::v4()`
- src/engine/pure3d/TextureFontLoader.cpp:88 `TextureFont::_m_vf19()`
- src/game/hulkfight/motion/TeleportRelativeAction.cpp: `TeleportRelativeAction_175920::A0()` (slot 0 of the local
  vftable that the map pairs with the game's 0x00417f2c)

B5, address taken only (the parameter tables' setters):
- src/game/hulkfight/motion/PropSpawnTrack_reg.cpp:292 / :874: `void FUN_00180050();` is stored as
  `&BallAndChainShootTrack_18abd0::FUN_00180050` through `ParamFloatConstRange_18abd0(const char*, void (T::*)())`.
  The definition is `bool (float)`: IR `void(ptr)` / `i1(ptr, float)`.
- src/game/hulkfight/motion/PropAddToCollisionTrack_3.iso_00187e00.cpp:21 `void __cdecl SetTimeBegin_0017f6b0();`
  stored as a `FloatParam` callback (definition `i8(ptr, i32)`)
- src/game/global/CActorManager.cpp:5873 `CActorManager::FUN_0002a200(const char*)` [ptr(ptr, ptr) / ptr(ptr, i32)]

B6, called with a declaration that passes differently:
- src/game/global/COccupationAgent.GS.cpp:67 `Locator::FUN_00059a50(Vec3_103c30*)` returns `int`; the definition
  returns `bool` (i32 / i1)
- src/engine/physics/CollisionObjectLoader.cpp:45 `Stream_3088d0::FUN_002669f0()` returns `bool`; the definition
  returns `unsigned` (i1 / i32)
- src/game/unknown/unk_1f9530.GS.cpp:192 `Actor::FUN_00037180(V3)` passes a vector by value; the definition takes
  three `int`s
- src/engine/pure3d/TextureFontLoader.cpp: `Reader::FUN_002647e0(void*, int, int, int)`; the definition is
  `i8(ptr, i64, i64, i32, i64)`, which looks like unb2's pointer-width retyping over-applied

B4 / the deleting destructors:
- src/game/global/CCameraManager.cpp:3127 the block 0x0009a760 is `??_G?$Method6@VCCameraManager@@XMMMMMM@@...`.
  Its source is `~Method6() {}`; MSVC emits the deleting destructor beside it, but clang emits only `??1`.

B0:
- src/engine/fight/Track.cpp:269 / :272 `FUN_002672f0((*(hulk_uintptr*)&DAT_004ca290), 0, 0)`: the call is
  ambiguous on 64-bit between the TU's two declarations (lines 18 and 76).
- src/game/global/CSoundSequence.GS.cpp:63: an `int*` parameter given a `hulk_intptr*`.

### 3.4 Where the names concentrate

Callee addresses that carry the most names (all buckets with an address). The fight-engine bases and a few core
helpers dominate:

| address | definition | TU | names | buckets |
|---|---|---|---|---|
| 0x00263f30 | `jmp` thunk to free 0x00267090 | - | 485 | B1 |
| 0x0027af50 | `FUN_0027af50` (string / hash helper) | engine/unknown/unk_27aec0.cpp | 428 | B6b 335, B6 93 (argument count) |
| 0x002345b0 | `fight::Condition::~Condition` | engine/fight/Condition.cpp | 282 | B2 |
| 0x00236d40 / 0x00236d60 / 0x00236ab0 / 0x00236a90 / 0x00236ac0 | Track's constructor, destructor, factory | engine/fight/Track.cpp | 1,077 | B0 |
| 0x0008d330 / 0x0008d340 | `jmp` thunks to free | - | 459 | B1 |
| 0x002343d0 / 0x002343b0 / 0x00234590 | ConditionFactory, Condition(void*) | engine/fight/Condition.cpp | 597 | B2, B6b |
| 0x00344e74 | `__RTDynamicCast` (CRT) | - | 232 | B1 |
| 0x00232660 / 0x002326a0 | `fight::Action` constructor, member | engine/fight/Action.cpp | 277 | B2 |
| 0x001d0480 / 0x001d04d0 | `Function`'s constructor, a lookup | game/global/Function.cpp | 333 | B2, B6b |
| 0x00059a30, 0x0027af00, 0x0027afd0 | fastcall helpers | | 355 | B2 |
| 0x0008d690 | the allocator | game/unknown/unk_08ceb0.cpp | 164 | B2, B6b |

- Stub vftable slots concentrate even more. Four game functions (content::LoadObject's slots 0 and 1, 0x00038290 /
  0x000382a0; pure3d::NonCopyable's slot 0, 0x00018b30; core::IRefCount::Release, 0x00018b40) are 1,690 of B3's
  2,226.
- Four parameter-class virtuals (0x001d04c0 Function, 0x00234270 / 0x002342b0 / 0x00234350 fight::Param) are 371 of
  B3b.

**Not in the metric: the game vftables' slots.** native_mac emits the game's 4,268 vftables (`code_owned64`) for
sources that store a vftable by address. Of their slots, 3,614 have no 64-bit definition and become `hulk_x_` stubs:
- 1,871 scalar deleting destructors (the B4 tool fix);
- 656 Track.cpp's (B0);
- about 1,066 library or not in the tree (`_purecall` included).

A constructor that stores a game vftable by address (x64t1's method) is only as good as these slots. Fixing B0 and B4
makes that method safe in bulk.

## 4. Fixes per bucket

Every fix below is in source or in the native tools. None redirects a local vftable to the game's at link time.

### B0: the two front-end failures (1,170 names; one batch, a few hours)

- **Track.cpp.** Line 269 / 272 pass `*(hulk_uintptr*)&DAT_...` to `FUN_002672f0`, which the TU declares twice
  (`extern "C" Key_236ac0 FUN_002672f0(int, int, int)` and `unsigned __int64 FUN_002672f0(unsigned int, int, int)`).
  On 64-bit `hulk_uintptr` converts equally well to both, so the call is ambiguous. The fix is one declaration, or
  an `(unsigned int)` cast. MSVC: a no-op (MATCH and verify_relocs on the TU's blocks).
- **CSoundSequence.GS.cpp:63.** An `int*` parameter takes a `hulk_intptr*`; retype the parameter.
- **Effect.**
  - 90 address names bind at once.
  - The 1,080 invented callers move into B2 (same IR signature: rename), and 656 game-vftable slots get
    definitions.
  - Proof: `tree_tu.py check --relocs` on both TUs, equiv on their equivalents (`--wine`), one Wine proof.
- Add a gate: **the native compile must have no front-end failure** (native_mac's `by_stage`). Each failure silently
  removes every definition of a TU.

### B1: thunks and the CRT (1,278 names; part of the B2 batches)

- **The rename.** The invented names of the four `jmp` thunks become `thunk_FUN_<target>` (`thunk_FUN_00267090_a`
  / `_b` where one source calls two thunks: sh2's spelling). Alternatively `FUN_<thunk>`, which plan_link already
  binds through `jmp_target`.
- **The CRT.** `__RTDynamicCast` (0x00344e74, 232 names) and the other CRT routines get the name the native CRT
  table has. Their references then fall into the CRT table group, which binds them to the host's.
- **Prerequisite for 0x00344e74.** The rewriter needs the native CRT table's rows by address
  (`native_mac.crt_bindings()`).

### B2 / B2b: rename invented names to the address the Wine map proves (8,621 names; rewriter 1, prototyped)

- **The rename.** For a name without an address that the Wine binding map binds to one address A by relocation
  position, rename the declaration and every reference in the TU:
  - functions get `<leaf>_<A>` (the suffix convention; `Fn<leaf>_<A>` for a one-letter leaf);
  - data gets `hulk_at_<A>`;
  - constructors and destructors: the class takes the `FUN_<A>` name, as sh2's 80 `FUN_001d0480` constructors did.
    The prototype does not do classes yet.
- **Effect on the native link.** It binds where the IR signatures agree (B2) or the data fits (B2b).
- **Effect on 32-bit.** Code bytes do not change. verify_relocs gains a check, because suffix names are verified
  against the relocation's target.
- **Prerequisite for the B6b names.** The rename is also the first step for B6b, whose next step is the
  declaration.
- **Header-declared names.** 932 names are declared in a header (owners.h, include/gen), and the rewriter leaves
  them. They are owners.h's stub members without an address (`owners::Obj_240b0::set`). They are better fixed in
  `evidence-owners.json` as one batch, which conflicts with x64t2 (below).
- **Proof.**
  - The Wine build's MSVC verification of the whole tree: build_tree's report, every block `match` / `compiled` as
    before.
  - verify_relocs on the renamed matches (tree_tu `--relocs`).
  - Equivalents: their objects must be unchanged except for symbol names. A block whose callee name changed needs
    `equiv.py` again only if its `equiv-map` lines name the old symbol.
  - One Wine proof with the play3 replay (image hash and `ckpt_gate`) per batch. The image should be byte-identical
    to the control's (only names changed). x64t1's batches showed this for vftables named by address: the image
    stayed 2e8232cd.

### B3 / B3b: name stub virtuals after their game slot (4,397 names; rewriter 2, simulated)

- **The problem.** A local stub class's `virtual void A();` sits in clang's local vftable. No checker binds a name
  without an address.
- **What gives the address.** The Wine map pairs the local vftable with a game vftable (4,316 local vftables:
  position 2,162, equiv:vftable 1,188, equiv:paired 743, equiv:ordered 223). The game vftable's slot k holds the address of the function that slot means.
- **The rename.** `A` becomes `A_<slot address>`. The native link then binds the slot to the tree's definition, so
  the local vftable behaves as the game's without being redirected. Its RTTI stays the local class's; see the risks.
- **B3b** also needs the definition's parameter list, for the 2,120 slots declared `()` that take arguments. It is
  32-bit-safe when the member is only referenced through the vftable (`relocscan`: 7,037 of 7,443 stub virtuals are
  data-only).
- **The header form clears the most.** 1,690 of B3's names are four base-class virtuals (LoadObject's slots 0 and 1,
  NonCopyable's 0, IRefCount::Release). The stubs inherit them from local copies of those bases. Deriving the local
  copies from include/gen's `content::LoadObject` / `core::IRefCount` / `pure3d::NonCopyable` makes the slots name
  the gen virtuals, which the tree defines under those exact names. Done per base class, that is one batch of about
  1,700 names. It is the "consolidation" unb1 named. The renaming is the fallback for classes whose layout
  disagrees with gen's.
- **Verification has a gap.** The renamed slot names are not in the Wine map: the Wine link aliases stub-vftable
  slots and never records them. native_unbound has to accept a name that verify_relocs verified on 32-bit, or the
  Wine link has to record the slot pairing it already makes in `bindings.json`. This is a tool change (below).

### B4: deleting destructors and pure slots (1,677 names + 1,871 game-vftable slots; tool batch)

- **Why the symbol is missing.** 1,871 tree blocks are scalar deleting destructors (`??_G`). Their source is the
  class's destructor body; MSVC emits `??_G` beside it, but clang (MS ABI) emits `??_G` only in a TU that emits the
  class's vftable. So the tree's definition at that address has no 64-bit symbol (native_unbound.Defs: "116 64-bit
  symbols of that form", because the fallback's qualified name ends in `dtor'`).
- **Source fix.** Force the vftable's emission in that TU on native builds only. A constructor or `new` of the
  class in a `#if HULK_NATIVE` function does it; a key function cannot. Clang then emits `??_G` as a weak definition.
- **Tool alternative.** native_mac emits `??_G` for each such block from the class's `??1`: call `??1`, then
  `operator delete(this)` if bit 0 of the flag is set, then return `this`. That is the MS ABI's definition of the
  function, so this is compiler-generated code emitted where the compiler did not, not a redirect. The decision is
  the user's (section 7).
- **Pure slots.** `_purecall` slots (0x00344f51, 124): declare the stub's virtual `= 0` where the game slot is
  `_purecall`, and the slot then binds to the CRT row.
- **Fix the Defs fallback too.** `shape()` names a special member `dtor'`, so 116 unrelated deleting destructors
  collide.

### B5: setters taken by address (2,882 names; family generator)

- **The pattern.** Nearly all are the fight parameter tables (`ParamFloatConstRange_xxx<T>("name", &T::FUN_x)`)
  and the `FloatParam` / `IntParam` callbacks. The member is declared `void FUN_x()` and stored through
  `void (T::*)()`. The definition is `bool (float)`, `bool (int)` or `char (const char*)`.
- **The fix is sh2's member-function-pointer method.** Declare the member with the definition's types, and type the
  template's member pointer (`bool (T::*)(float)`). For a complete single-inheritance class MSVC stores the
  function's address in both cases (sh2: every helper still matched), so the 32-bit bytes do not change.
- **The generator.** Like build/sh2/scripts/conv_helpers.py: read the definition's 64-bit IR signature and its
  source declaration, then rewrite the member declaration and the template parameter.
- **Families.** The `ParamXxx_<addr>` templates are a family of about 40 near-identical sources
  (tools/equiv_gen/'s territory).
- **Proof.** Compare plus relocs for matches; equiv `--wine` for equivalents (the setter types change in their
  callers' IR).
- **Tool alternative.** native_unbound could accept a different signature for references that are only
  address-taken, because the stored value is the address whatever the declaration says. That clears all 2,882 at
  once, but the indirect call stays typed wrongly in source. It is listed as a decision; this plan recommends the
  source fix.

### B6 / B6b: declarations that pass differently (7,047 names; per callee family, MSVC-gated)

- **What these are.** The real 64-bit bugs. By kind (B6, called address names):
  - pointer / int arguments 1,065;
  - argument count 905: a member called as a free function, a free function called as a member, missing or extra
    arguments;
  - float / int arguments 446;
  - byte widths 900 (`bool` / `char` / `int` results and arguments);
  - int64 / pointer 432;
  - result read where the definition returns none, 123.
- **They concentrate on a few callees.**

  | top callees | share of B6 | share of B6b |
  |---|---|---|
  | 10 | 13% | 29% |
  | 50 | 29% | 40% |
  | 200 | 50% | 53% |

  0x0027af50 alone has 428 names: callers declare it with no arguments, and the definition takes `this`.
- **A. Callee declarations in a shared header.**
  - For the top callees, the definition's declaration goes in one place: an owners:: class (owners.h already
    exists for "a member known by its address"), or an include/gen class when the callee is a member of a known
    class.
  - Callers use it instead of their local stub's member.
  - The rewrite at a call site: `((owners::X_27af50*)p)->FUN_0027af50(...)`, or the stub class deriving from the
    owners class. The arguments are cast to the declared types.
  - MSVC bytes stay the same when the old and new types pass alike on 32-bit (int / pointer, `char` / `bool` in a
    register the caller already truncates). Otherwise they change, so **every TU goes through the MSVC gate** and
    the rewriter keeps the callee's old declaration in the TUs whose blocks stop matching.
  - Expect most of the int / pointer and argument-count cases to stay byte-identical. The byte-width and float
    cases need case-by-case review (a float passed as `int` is the same stack word on 32-bit, but a caller that
    computes it differs).
- **B. Definition-side retyping (unb2's plan.py / rw.py).** This is for callees whose callers mostly agree with each
  other and disagree with the definition. Two examples:
  - `FUN_002647e0` is declared `i8(ptr, i64, i64, i32, i64)` while 50 callers pass pointer / int / int / int;
  - `FUN_0022d2b0` returns `int` where 51 callers read a `bool`.

  unb2 measured 2,321 net names for its first pass; rerun its planner on today's objects.
- **C. hulk_freg float results.** unb2 counted 676 names. This is its own batch, with the float review unb2
  described: the Wine build's code changes.
- **Effect.** Pass A on the top 200 callees reaches about 3,600 of the 7,047. Assume 60-70% survive the MSVC gate
  (an estimate; the int / pointer share is the largest): about 2,300 names. Pass B adds unb2's kind of gain.

### B7, B8, B9

- **B7 (831).** Local vftables the map does not pair. Pair them by the RTTI name, or store the game's vftable by
  address in the constructor (x64t1's method) once B0 and B4 have given the game vftables real slots.
- **B8 (319).** Rename the 167 `target` / `Target` definitions in wrapped namespaces to their address names (their
  64-bit forms collide). Add the data items for the 58 interior addresses (data_gen), and handle the rest by hand.
- **B9 (788).** Ambiguous in the map, or called stub virtuals: by hand, as the start-up reaches them.

### Tool changes the source fixes need

1. **A gate for front-end failures** in native_mac / native_elf compile, so that a TU never drops out silently (B0).
2. **The slot names' verification (B3).** Either native_unbound accepts a suffix name that verify_relocs verified
   in the 32-bit tree, or wine_link writes the slot aliases it makes (unb1: 6,208) into `bindings.json` under
   the slot functions' names.
3. **`??_G` on 64-bit (B4)**, in source (`HULK_NATIVE` emission) or the link (decision 2).
4. **`native_unbound.Defs` / `native_mac.TreeDefs`**: give special members (`dtor'`) a qualified-name key that does
   not collide.
5. **Rewriter infrastructure** (tools/, from the prototypes):
   - `rename.py`: classes by address (constructors), header-declared names through the owners evidence, the
     CRT table;
   - `slotname.py`;
   - `setters.py` (B5);
   - `decls.py` (B6 pass A).

   Each writes a per-TU change list and takes `--only` / `--exclude` (for x64t2's files).

## 5. Prototypes

### 5.1 Rewriter 1: renames (B2 / B2b), measured

- **Run.** `build/plan1/scripts/rename.py build/plan1/cls-p5.json build/plan1/nat-p5/cp/snap build/plan1/rw1
  --jobs 2`. It uses libclang on the native front end's target (`aarch64-pc-windows-msvc`, the snapshot's include
  paths), matches cursors by their 64-bit mangled name, finds references by canonical declaration, and edits only
  where every site spells the name.
- **First run.** 1,561 candidate TUs, 10,881 (TU, name) pairs:
  - renamed 9,223;
  - skipped 932 declared in a header (914 in the final run), 626 whose new name was already declared in the same scope, 6 not found,
    5 at macro sites.
- **First version's bugs.** Its first version renamed two variables of different types to one `hulk_at_` name in
  one TU (MSVC C2040 in EffectAction.cpp). Data renames are now unique per TU, and EffectAction.cpp compiles.
- **Spot check.** `tree_tu.py check --relocs` on the renamed src/game/unknown/unk_0240b0.cpp (131 renames): 210 / 210
  matches MATCH with relocations ok, 72 / 72 equivalents compile.
- **Whole-tree proof (private workspace).** build/plan1/ws = HEAD + the renamed TUs; Wine builds 71491, then 71502 on
  studio, lineage `plan1-rw1`, stages build, probe and link (no replay):

  - First run (job 71491): 54 TUs failed MSVC, all of them rewriter bugs.
    - 51 renamed `operator delete[]`: the name token at the cursor is `operator`.
    - Two (Clip_2.cpp, unk_23fa40.cpp) missed a call in a platform `#if` branch that libclang's aarch64 parse
      does not see (Clip_2.cpp: `#if defined(HULK_PTR64)` / `#else`).
    - One missed a call inside `#if defined(__clang__)` / `#else`.

    Fixes: operators are skipped; every edited TU is parsed again on aarch64 and i686, and a rename named in an
    error is dropped. Three TUs went back to HEAD for this run (Clip_2.cpp and unk_23fa40.cpp, whose redo hung
    libclang, and ProjectileGroundShockwave.cpp, whose `__clang__` branch only MSVC sees). **The production
    rewriter must end with the MSVC compile of each TU (tree_tu) and drop what fails.**
  - Final: **9,150 renames in 1,482 TUs.** Skipped: 914 declared in a header, 626 whose new name already exists in
    that scope, 67 operators, 11 other.

  | | baseline (71460's snapshot and map) | renamed (71502, lineage plan1-rw1) |
  |---|---|---|
  | MSVC verification of the tree (build_tree) | 22,339 matches match, 5,099 equivalents compiled | **22,339 matches match, 5,099 equivalents compiled** |
  | Wine image `hulk-strict.exe` | 2e8232cd | **2e8232cd** (byte-identical) |
  | Wine strict link unbound / x87 keep list | 1,251 / 266 | 1,251 / 266 |
  | arm64 macOS unbound (bound by address) | 29,010 (14,717) | **22,880 (20,786)**: -6,130 |
  | x86-64 Linux unbound (bound by address) | 28,995 (14,731) | **22,860 (20,805)**: -6,135 |
  | native front-end failures | 2 | 2 (the same: B0) |

  - The Wine image is byte-identical, so the replay proof is implied: same image, same checkpoints. A real batch
    still runs the play3 replay, because its control may differ.
  - The renamed equivalents compiled under MSVC. Their object code is unchanged, because the image is. A real batch
    reruns `equiv.py` only for blocks whose `equiv-map` lines name a renamed symbol.
  - Android was not linked. Its count tracks the other two within 10.

  **Of the 8,621 B2 / B2b names, 6,130 bound.** The rest:
  - left out on purpose: 914 header-declared, 626 same-scope collisions, 3 TUs;
  - data declared wider than its item: 434 `hulk_at_` names, `int` over a 2-byte item and the like. Those need the
    item's type, a data batch;
  - the renamed B6b names, which now carry an address but still pass differently. They join B6: the macOS link now
    shows 9,977 address names with an IR mismatch.

  Constructors and destructors (737 B2 names) were not attempted.
  - The renaming is class-level: the class takes the constructor's `FUN_` name (sh2's rule).
  - A class can carry one address, so a stub class whose constructor *and* destructor are referenced needs the
    destructor called through a second stub class, or the base-class consolidation of batch 4.

  After the prototype, the leftovers by kind (macOS, 22,880):
  - stub virtuals 7,443 (B3 / B3b / B4 / B7, untouched);
  - address names with an IR mismatch 9,977 (B5 / B6 / B6b);
  - invented free functions 1,414 (mostly B1, thunks and CRT);
  - invented members 1,249;
  - constructors / destructors 1,166;
  - vftable variables and variables 1,017;
  - the rest 614.

### 5.2 Rewriter 2: slot names (B3 / B3b), simulated

`slotsim.py` reads, for every object, the local vftables and their slot relocations, the Wine map's game vftable for
each, and the XBE slot. Per stub virtual member (7,443):

| outcome | names |
|---|---|
| the slot's definition has the same IR signature: binds when named by its slot's address | **2,232** |
| signature differs: argument count (declared `()`) | 2,120 |
| signature differs: other (pointer / int 22, result read 15, ...) | 38 |
| the slot's target has no unique 64-bit definition (deleting destructors 1,650, `_purecall` 124, Track.cpp 64, other) | 1,677 |
| the Wine map does not pair the local vftable | 834 |
| different slots / objects disagree | 158 |
| not in a local vftable (called) | 381 |

After B0 and B4, the 1,677 move to "same" or "differs". With B3b's declarations, slot naming reaches about 6,000 of
the 7,443.

## 6. Batches

Each batch is one agent:
- one rewriter run over its TU set;
- the 32-bit gates on the changed TUs (tree_tu `check --relocs`; `equiv.py` where a block's IR changed, `--wine`);
- one Wine proof (`--gfx --replay play3 --frames 60000`, `ckpt_gate.py` against a control);
- the native measurement (natbuild on the proof's snapshot and map).

Batches 1 to 6 are mechanical. Their 32-bit risk is names only, so a batch can be the whole tree minus the excluded
files.

| # | batch | buckets | names (est.) | depends on | parallel with x64t2? |
|---|---|---|---|---|---|
| 1 | front-end fixes (Track.cpp, CSoundSequence.GS.cpp) + the compile gate | B0 | 90 now, 1,080 + 656 slots unlocked | - | yes (fight / audio TUs) |
| 2 | rename invented names to addresses (rename.py, tree-wide) | B2, B2b, B1 | 6,130 measured (prototype); 7,000-8,500 with constructors, B1 and the skipped names | 1 for Track.cpp's callers | yes, excluding src/platform/xbox/pure3d/, src/engine/pure3d/pddi*.cpp, the d3d* TUs and owners.h |
| 3 | `??_G` on 64-bit + the Defs key fix | B4 | 1,650 slot names + 1,871 game slots | decision 2 | yes (tools; the source variant touches 1,871 blocks' TUs: after 2) |
| 4 | base-class consolidation: LoadObject, IRefCount, NonCopyable, fight::Param / Condition / Action / Track bases from include/gen | B3 (the header part) | about 1,700 + 371 | 2 (renames in the same TUs) | yes |
| 5 | slot naming for the rest + the slot verification (tool change 2) | B3, B3b | 2,500-4,000 | 3, 4 | yes, excluding the pddi TUs |
| 6 | setters typed end to end (the parameter-table families) | B5 | 2,882 | - | yes (game/hulkfight, game/global) |
| 7a-7d | callee-family declarations, top callees in fours of 50 (0x0027af50 first), MSVC-gated | B6, B6b | 2,000-3,000 | 2 | 7a-7d serialize on owners.h / evidence-owners.json; **after x64t2** releases owners.h |
| 8 | definition-side retyping (unb2's planner, rerun) | B6 | 1,000-2,000 | 2 | yes (definitions), except pddi |
| 9 | hulk_freg float callers (float review) | B6 | 676 | - | yes |
| 10 | B7 / B8 / B9 clean-up | | 1,000-1,900 | 3, 5 | after x64t2 |

**What can run concurrently with x64t2.**
- x64t2 holds:
  - the pddi start-up path: the state-stack constructors 0x0031ed40, 0x0031ee00, 0x0031efd0 and 0x0031f0a0, and the
    pddi record layouts (src/engine/pure3d/pddiBaseContext.cpp, src/platform/xbox/pure3d/);
  - the 12 `extern char FUN_` declarations;
  - include/gen/owners.h with evidence-owners.json. The checkout shows them modified now.
- Batches 1, 2, 3 (tool variant), 4, 6, 8 and 9 do not need those files and can run beside x64t2:
  - batch 2 with `--exclude` for x64t2's TUs, and the 914 header-declared names left out;
  - batch 4's include/gen classes are not x64t2's (content.h, core.h, fight.h).
- Batches 7 and 10 edit owners.h, so they wait for x64t2.
- Two rewriter batches must not take the same TUs at the same time. Batches 2 and 4 touch the same fight-system TUs,
  so run 4 after 2 lands, or give them disjoint TU lists.

**The function-as-data declarations** (`extern char FUN_x;`: 74 in 43 sources) are x64t2's 12 plus 62 more. A
declaration as a function (x64t1's batch 2 method) is part of batch 10 after x64t2 lands. Most are the element
constructors handed to the vector-constructor helper 0x00011520.

**Order of value.**
1. Batches 1 + 2 take the count from 29,010 to about 20,000 with names only. Batch 2's prototype alone reached
   22,880.
2. Batches 3 to 6 take it to about 10,000.
3. Batches 7 to 10 are the typing work: the bugs the start-up would otherwise hit one at a time.

The start-up batches (x64t1's kind) continue in parallel. They should take their fixes from these rewriters' output
for the TUs they touch, instead of renaming by hand.

## 7. Decisions for the user

1. **The tool rules the source fixes need.** Accepting slot names that verify_relocs verified (B3), and an
   address-only reference rule (B5's alternative). Neither redirects anything; both change what the native link
   accepts as proof.
2. **`??_G` on 64-bit.** Either native-only source that forces the vftable's emission (1,871 blocks' TUs touched), or
   the link emits the MS ABI deleting destructor from the class's destructor. The second is smaller and keeps the
   tree clean. The first is pure source.
3. **The batch size of renames.** Batch 2 is tree-wide (1,482 TUs). The 32-bit risk is names only and its proof is
   one Wine build, but the diff is large for a shared checkout. Alternatively, run it per directory (game/global,
   game/hulkfight, engine/...) in 4-6 commits.

## 8. Reproduce

```sh
PY=build/venv/bin/python
sh build/plan1/scripts/natfetch.sh p5 x64t1-p5                    # snapshot + map of proof 71460 (studio)
NORUN=1 TARGETS="mac linux" sh build/plan1/scripts/natbuild.sh p5   # queue compile, local link -> build/plan1/nat-p5
HULK_CLANG_PROBE_DIR=build/plan1/nat-p5/cp $PY build/plan1/scripts/classify2.py --dir build/plan1/nat-p5/mac/nm \
    --bindings build/plan1/maps/p5/bindings.json --out build/plan1/cls-p5.json --cache build/plan1/cls-p5.pkl
$PY build/plan1/scripts/relocscan.py build/plan1/cls-p5.json build/plan1/nat-p5/mac/nm build/plan1/use-p5.json
HULK_CLANG_PROBE_DIR=build/plan1/nat-p5/cp $PY build/plan1/scripts/slotsim.py build/plan1/cls-p5.json \
    build/plan1/nat-p5/mac/nm build/plan1/cls-p5.pkl build/plan1/maps/p5/bindings.json build/plan1/slotsim-p5.json
HULK_CLANG_PROBE_DIR=build/plan1/nat-p5/cp $PY build/plan1/scripts/buckets.py build/plan1/cls-p5.json \
    build/plan1/use-p5.json build/plan1/slotsim-p5.json build/plan1/nat-p5/cp/snap/report.json build/plan1/buckets-p5.json
$PY build/plan1/scripts/rename.py build/plan1/cls-p5.json build/plan1/nat-p5/cp/snap build/plan1/rw1 --jobs 2
# workspace = git archive HEAD + rw1/src-root/src overlaid (dynamic_initializers.cpp patched onto HEAD's $L pins), then
$PY tools/wine_build_job.py submit --name plan1 --workspace build/plan1/ws --lineage plan1-rw1 --host studio --gfx \
    --stages build,probe,link --sdl-src build/x64t1/tp-out/sdl-backends/win32 --state auto
sh build/plan1/scripts/natfetch.sh rw1 plan1-rw1 && NORUN=1 TARGETS="mac linux" sh build/plan1/scripts/natbuild.sh rw1
```
