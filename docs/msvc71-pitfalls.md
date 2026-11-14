# MSVC 7.1 pitfalls: reading the target and writing a byte match

The recipes the model farm gave its workers (farm/src/prompt.ts), kept as a reference for matching and proving
functions by hand. The farm is retired and archived (user decision D2, 2026-11-13): farm/ was removed from the tree;
the last commit that has it is named in [Where the farm went](#where-the-farm-went). The compiler is MSVC 7.1
(cl 13.10.3077), `/O2 /GR /GX-` (no C++ exceptions: no game function has an EH frame; gx1 made /GX- the tree's
default, 2026-11-13, and a TU still written for /GX says `// cl-flags: /GX`), x86-32, x87 floating point, frame pointers omitted unless a TU says otherwise.

Today a function is a block of its tree TU (`src/{game,engine,platform/xbox}`, [merge-once.md](merge-once.md)); the
checkers are `tools/compare.py` + `tools/verify_relocs.py` for a byte match and `tools/equiv.py` for equivalence
([equivalence.md](equivalence.md)). The farm's workers wrote one self-contained .cpp per function and read an aligned
instruction diff (`target | ours`; `!!` differs, `--` missing in ours, `++` extra in ours); the rules below are written
for that loop but hold for a block in a TU.

## Byte matching

**Workflow.** Fix the earliest difference first; later ones often follow from it. Bytes covered by relocations (call
targets, global addresses) are masked, so the names of called functions and globals don't change the bytes, only types,
calling conventions and code shape (verify_relocs then checks that the names hit the right addresses).

**Declarations and layout**
- Define the target and declare (don't define) what it calls, or a callee may be inlined.
- Class layout must make offsets agree: `[ecx+0x1c]` is a member at offset 0x1c; a class with virtual methods has its
  vftable pointer at offset 0. Pad with char arrays (zero-length or negative ones don't compile).
- `call dword ptr [eax+N]` calls slot N/4: declare that many virtual methods before it, in order.
- Member functions are `__thiscall` (this in ecx). `ret N` pops N bytes of stack arguments; plain `ret` with stack
  arguments means `__cdecl`. A call with no `add esp,N` after it goes to a `__stdcall` callee.
- `lea ecx,[reg+off]; push float; call` with no `add esp` is a thiscall member of a sub-object or array element:
  declare it `Elem::Fn(float)`.
- Rebuild real structs with real field offsets instead of Ghidra's `this+0x28` arithmetic; check `sizeof` when a size
  appears as an immediate (`push 0x2c`). Don't copy Ghidra's casts.
- MSVC 7.1 is pre-C++11: no `auto`, `nullptr`, `override`, `enum class`, range-for or brace-init. Members are private in
  a `class` unless under `public:`. Constructors and destructors have no return type; declare them in the class before
  defining them. MSVC 7.1 rejects `__thiscall` in function-pointer types: call through virtual methods of a declared
  class and use member fields, not `(void**)`/`(code**)` casts.
- Never hard-code image addresses (vftables, globals, functions) as integers and never store a vptr by hand: use real
  classes and declared globals. Pointer tricks and comma expressions that happen to match give the wrong structure.

**Flags**
- An ebp frame (`push ebp / mov ebp,esp ... leave`): the object was built with `/Oy-` (`// cl-flags: /Oy-`).
- Size-optimised code (`and dword ptr [m],0` for zero stores; `push 2 / pop eax`; `xor eax,eax / inc eax`;
  `push ecx / pop ecx` stack adjusts; `leave`): `/O1 /Oy-` (`// cl-flags: /Oy- /O1`). The CRT/XAPI region around
  0x34xxxx-0x35xxxx often is.

**Exceptions and destructors**
- Any destructor (including a virtual one on a stack temporary) adds an SEH frame (`fs:[0]`); if the target has none,
  use a plain virtual method as a placeholder, or declare the destructors `throw()`.
- `fs:[0]` set-up and `mov [esp+N], state` stores only in ours: EH unwind states; mark the callees `throw()` (check
  sibling functions for `fs:[0]`).

**Expressions and order**
- Float sums are reordered by the compiler: try permutations of the term order (`y*y + z*z + x*x`). Small inline
  helpers can change instruction selection compared with hand-written loops.
- Load order follows the source: copying a member into a local before a call (`Mgr* m = owner->mgr;`) can fix it.
  Declaring a local (`int n = 0;`) at the top, before the first load, can fix a register swap.
- Load order of a call's arguments against the object pointer: wrap the chain in an inline member of the intermediate
  class (`Mid::Get(int id) { return prov->Get(id); }`).
- Float parameters that are only copied or pushed must be declared `float`, not `int`. Float compares: write
  new-value > old-value (operand order flips the `fcom` test).
- A zero store to a member that is later overwritten is optimised away; write it through a local pointer
  (`int* q = &m; *q = 0;`). Reloading a member in its own block (`{ Obj* q = mObj; q->f(); }`) reproduces alternating
  eax/edx loads.
- Prefer early returns (`if (!p) return false;`) over wrapping the body in `if (p) { ... }` when the target tests
  before saving registers.
- `dec ecx; je A; dec ecx; jne B` on a small int is `switch (x) { case 1: ... case 2: ... }`, not an if-chain.
  Unsigned `n > 0` gives `jbe`; `n != 0` gives `je`.
- When the target reuses a parameter as its working variable, do the same (modify the parameter, not a copy).
- A guard-bit pattern (`mov dl,[g]; test al,dl; ... or edx,1; mov [g],edx`) is a function-local static with a runtime
  initializer: `static T* last = param;`.
- Constructing in place without a null check: call `q->T::T();` explicitly (placement new adds a null test). To keep a
  virtual call in a constructor from being devirtualised, call through `Base* b = this; b->Fn();`.
- A function starting `mov eax,ecx` that returns this is a constructor; one that doesn't return this is a void
  method. Members set before the vptr store come from an inline base-class constructor.

**Intrinsics**
- Inlined strlen: `const char* e = s + 1; do c = *s++; while (c); len = s - e;`, then `+1` gives
  `sub eax,edx / inc eax`. strcpy: `do { c = *src; src++; *dst = c; dst++; } while (c);`. Write them as small inline
  helpers.
- `sbb eax,eax / sbb eax,-1` inline: the strcmp intrinsic (`extern "C" int strcmp(const char*, const char*);`). A bare
  `sete al` result wants a `char` return type, not `bool` or `int`.
- `rep stosd` / `rep stosb` is `memset(p, 0, n)`; a call with arguments in st0/st1 is `fmod()`; `fpatan` is `atan2()`.
  Declare them `extern "C"` and call them. A call to FUN_0034483c with a float in st0 is `_ftol`: write `(int)x`.

## Reading the diff

- `[0]` against `[0x4dd9cc]`, or `call 0x3a` against `call 0x188480`: unresolved relocations, ignore them.
- The same instructions in another order: the expression shape differs, not the logic. Lines on one side only: a
  construct is missing or extra. Different registers everywhere: usually a side effect of another difference; fix that
  first. Change one thing at a time.
- This engine is pure3d/Radical: look for `p3d::find<T>(name)`, `new(allocator) T(...)`, `DynamicCaster<T>`; the names
  of referenced data often name the idiom.

## Symptom in the target -> probable source

Some are strong guesses, not confirmed rules.

- A `...::vftable` address stored into a stack slot or `[this]`: a real class with virtual functions and its inline
  constructor, or a destructor (a `DynamicCaster<T>` temporary).
- vptr store, member calls at falling offsets, then a `jmp` to a base function on this: an empty out-of-line destructor
  (`T::~T() {}`) whose members have destructors and whose base has a virtual destructor.
- The target stores the vptr right after `mov esi,ecx` but ours sinks that store below the first member load or test:
  (1) if the body is empty or starts with a loop, write a real `virtual ~T() throw()` and move the trailing frees and
  releases into inline destructors of small member types (reverse offset order, all callees `throw()`); (2) otherwise
  declare `extern "C" void _ReadWriteBarrier();` and call it right after the vptr store (an intrinsic, no code); (3) or
  make both the store and the first member load volatile. Compiler flags don't change it.
- Register-only differences (a temporary in ecx where ours uses eax, esi/edi swapped) usually mean the structure is
  wrong, not the allocator: a later call that never loads ecx is a thiscall on the tested value (declare it a member);
  eax may be busy because the function returns a value; a hand-written strlen/strcpy loop should be the intrinsic; a
  hand-stored vptr should be a real class with the stores moved into member types.
- A base function called on `this+4` where the target uses `this`: the base needs virtual functions, so its vptr sits
  at offset 0 of the base.
- Constant-size allocation, null test, a thiscall returning this, `xor eax,eax` on the null path, one shared store:
  `new(heap) T(...)` with an inline `operator new(size_t, Allocator)`.
- A null test that remains after the pointer was read: an inlined getter that can return 0. A constant loaded before
  a branch: a variable set before the `if`; if the target loads it in one branch only, drop the shared variable.
- `xor eax,eax` used as the stored zero (where ours has `mov [x],0`): both paths merge into one expression (new,
  ternary, inline return).
- A global loaded once before a call and reused after it: the source cached it in a local (`Loader* ld = gLoader;`).
  An extra `push ecx / pop ecx` in ours: a new stack local where the target reused a dead parameter slot; start the
  temporary's lifetime after the parameter's last use.

## MSVC 7.1 idioms seen in this binary

- `xor al,al` before a switch: `bool r = false; switch (x) { case 0: r = A(); break; case 1: r = B(); break; } return r;`
- `sub reg,0 / je / dec reg / jne`: a switch over 0..n.
- `mov eax,[ecx+N] ... call eax` instead of `call [eax+N]`: the member is copied to a local first
  (`Fn fn = mFn; (obj->*fn)()`).
- `fld dword ptr [addr]`: a float constant or global (a literal, or an `extern const float`).
- `test ecx,ecx / je / mov [ecx],eax` after a call: `if (out) *out = value;`

Example (matched):

```
mov eax,[ecx+4] / dec eax / cmp eax,1 / mov [ecx+4],eax / jge end / mov eax,[ecx] / push 1 / call [eax+8] / end: ret
```
```cpp
class RefCounted { public: virtual void AddRef(); virtual void Release(); virtual ~RefCounted(); int mRefCount; };
void RefCounted::Release() { if (--mRefCount < 1) delete this; }
```

## Writing an equivalent function

The equivalence bar is behaviour (`tools/equiv.py`): level 1 compiles, level 2 the same references (calls, globals,
vtables, strings, float constants), level 3 the same calls in the same order with the same arguments and `this`, the
same writes between calls and the same return value, on many generated inputs with every callee stubbed. A callee may
change any memory, so re-read values after a call where the original does.

- Names bind symbols to addresses: name every called function and used global after its address (`FUN_0022b980`,
  `DAT_004dd6e4`); a member keeps its address name inside its class (`struct Vec { void FUN_0022b980(); };`), or the
  `Class::method` name the function table gives. A name with the wrong address is an error.
- The target's own calling convention, parameter count and return type must match the original.
- Callee conventions decide which values are arguments: no `add esp,N` after a call with stack arguments means
  `__stdcall` or a thiscall member; `lea ecx,[...]` or `mov ecx,...` right before a call passes this.
- Callees taking arguments in registers no C++ convention uses (mostly the D3D backend, e.g. eax): declare them as
  ordinary functions and annotate where the original passes each parameter, in parameter order:
  `// equiv-conv: FUN_00326dc0 eax ecx`, `// equiv-conv: FUN_00325fd0 ecx edx eax stack`. The same annotation on the
  target describes its own register inputs. A callee with this in ecx plus caller-popped stack arguments is an ordinary
  member and needs none.
- Float constants as literals (0x3f800000 is `1.0f`), strings as literal text. No inline assembly, `_emit`, naked
  functions or `#pragma`.
- Write it the way a programmer would: real structs with named fields, loops instead of gotos, no Ghidra casts.

## Where the farm went

farm/ held the model farm: the TypeScript driver (`farm/src/farm.ts`), the worker prompts (`farm/src/prompt.ts`, whose
text is the substance of this page), the compile-error hints (`farm/src/hints.ts`), the tier configurations
(`farm/tiers*.json`) and the lane and night scripts. Its tracked files were removed on 2026-11-13; the last commit
that has them is **ac307cc62** (`git show ac307cc62:farm/src/prompt.ts`). The farm's local state
(build/farm/: the SQLite databases, packets, ledgers) and farm/'s untracked files (`farm/endpoints.json`, private tier
files) stay on the machines that have them; `farm/endpoints.json` must still never be committed.
