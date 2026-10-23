# Byte-matching MSVC 7.1 (XDK-era) code

How to get C++ that compiles with the original compiler to the original's bytes, for an original-Xbox game built
with Visual C++ 7.1 (VS.NET 2003, `cl` 13.10.3077, the compiler the final XDKs shipped). Most of it applies to any
MSVC 6-8 era x86 target.

Confidence markers: **[seen]** was confirmed on real functions in a full-game project; **[hedged]** is general
MSVC knowledge we didn't verify there, so check it with a probe compile before relying on it. When a recipe here
disagrees with what your compiler does, the compiler wins: write the correction into your brief.

## Contents

1. When to match, and when to stop and prove equivalence
2. Identifying the compiler and flags from the binary
3. Objects, splits and link order
4. The match loop
5. Reading the target (quick reference)
6. Mismatch catalogue: symptom -> source change
7. References: a MATCH that hits the wrong symbol
8. Permuters
9. Scaling: shapes, clones, generators, recipes
10. Matching with LLMs
11. Prioritising the work
12. Ruled-out levers and known-unsolved shapes

---

## 1. When to match, and when to stop

- Matching is the gold standard: identical bytes plus correct references means identical behaviour, with no
  test-coverage caveat. It is also the cheapest proof **for small functions**.
- Cost rises steeply with size. In one project, cheap models matched about two thirds of 32-96-byte functions,
  about one in twelve at 97-192 bytes, and none above 192 bytes in five attempts each; a fine-tuned small local
  model matched most functions under 64 bytes and essentially nothing over 128. Strong models with a good brief
  did better on mid-size functions (30-70% per batch), but the curve has the same shape.
- **Stop matching and prove equivalence instead when**: the function is large (hundreds of bytes and up); the score
  plateaus (typically by attempt 4-8); only register-choice or operand-order differences remain after the structure
  is right; it takes arguments in registers no C++ convention uses (link-time code generation, see 2.6); it uses
  the CRT's `__SEH_prolog` (`__try`/`__except`, usually library code); or it is an SEH/EH funclet.
- Always save the best attempt and its first mismatch. A recipe found later (section 9) often unblocks a whole
  group of parked near-misses in one pass.

## 2. Identifying the compiler and flags from the binary

### 2.1 Compiler version

- XDK library version strings in the XBE name the XDK build. The final XDKs pair with VC 7.1, `cl` 13.10.3077 /
  `link` 7.10.3077, the same build as VS.NET 2003 RTM and the free Visual C++ Toolkit 2003; decomp.me hosts it as
  `msvc7.1`. Earlier XDKs used VC 7.0 or VC 6-based compilers **[hedged]**: confirm by matching a handful of small
  functions before building anything big.
- Prove the version by hand-matching five small, different functions (a refcount release, a small switch, an x87
  getter, a template method). If all five match with `/O2`, the compiler and base flags are right **[seen]**.

### 2.2 Byte-count fingerprints

Scan `.text` before choosing flags (heuristic counts, not a disassembly):

| Signal | Suggests |
| --- | --- |
| Few `push ebp; mov ebp,esp` | frame pointer omission (`/Oy`, implied by `/O1`, `/O2`, `/Ox`) |
| Many `ebp` frames with `leave` | `/Oy-` objects (some projects build all code that way) |
| No `movss`/`addss` etc. | x87 only (no `/arch:SSE`, which 7.1 does offer **[hedged]**) |
| Many `ret N` | thiscall/stdcall-heavy C++ |
| `int3` (0xCC) runs between functions | normal MSVC alignment padding |
| `.?AV...@@` strings and locators before vtables | `/GR` (RTTI on) |
| `fs:[0]` setup, `__ehhandler` thunks, a `.text$x`-style tail of funclets | `/GX` (`/EHsc`) C++ exceptions |
| Calls to a cookie check before `ret` in functions with char buffers | `/GS` |

### 2.3 Per-function flag fingerprints

Different objects can use different flags. In one game there were at least three regimes **[seen]**: game code
`/O2` with frame pointers omitted, a few game objects with `/Oy-`, and the CRT/XAPI region `/O1 /Oy-`. Allow a
per-file flag comment in sources (e.g. `// cl-flags: /Oy- /O1`), whitelist the accepted flags, and record the
flags per object in the split config.

| In the target | Try |
| --- | --- |
| `push ebp; mov ebp,esp ... leave` | `/Oy-` **[seen]** |
| `push 2; pop eax`, `xor eax,eax; inc eax`, `and dword ptr [m],0` for zero stores, `push ecx`/`pop ecx` as stack adjusts, `pop ecx; pop ecx` to clean two args | `/O1` (often with `/Oy-`) **[seen]** |
| a call to `memcpy`/`strcmp`/`sin` where game code inlines them | `/O1` or no `/Oi` **[seen]** |
| inline `rep movsd`, `repe cmpsb`, `fsin`, `fsqrt` | `/O2` (`/Oi` intrinsics) **[seen]** |
| `mov eax,[cookie]` stored near the frame top, then the cookie passed in `ecx` to a check before `ret` | `/GS` **[seen]**; a plain `char buf[N]` local makes 7.1 emit the cookie itself **[seen]** (its exact trigger rules are **[hedged]**); never hand-write the cookie |
| `fs:[0]` frame and state stores in a function with local objects that have destructors | `/GX`; if the target has none, the callees were `throw()` or the objects had no dtors |

What the umbrella switches imply (VC 7.1 documentation, **[hedged]**: verify with `cl /?` or a probe):
`/O2` = `/Og /Oi /Ot /Oy /Ob2 /Gs /GF /Gy`; `/O1` = `/Og /Os /Oy /Ob2 /Gs /GF /Gy`; `/Ox` = `/Og /Oi /Ot /Oy /Ob2`
(no `/GF /Gy`). Other 7.1 switches worth a probe when a function resists: `/Ob1` (inline only `inline`-marked),
`/Ob0`; `/G6` vs `/G7` (scheduling tuning; 7.1's default blend **[hedged]**); `/Op` (float consistency: stores at
every assignment); `/QIfist` (`fistp` instead of the `_ftol` call); `/J` (`char` unsigned: `movzx` loads of chars);
`/Zp` (struct packing). In the project behind this file, `/O1`/`/Os`/`/Ob1`/`/Ox` did **not** fix a vptr-store
ordering problem that turned out to be a source-shape issue **[seen]**: try flags after structure, not before.

Make the permuter (section 8) and the batch tooling try a few flag sets automatically (`""`, `/Oy-`, `/Oy- /O1`,
`/O1`, `/Os`, `/GX-`), but promote a non-default flag only when it is consistent with the object's other functions.

### 2.4 Function-level linking, COMDATs and folding

- `/Gy` puts each function in its own COMDAT, so the linker can order and drop functions. Inline functions and
  template instantiations are COMDATs emitted into every object that uses them; the linker keeps one copy, often in
  the first object that used it, far from the class's other functions ("COMDAT strays").
- **Dead copies**: one game had ~14,000 unreferenced bodies (small inline methods like vector dot products) left in
  `.text` **[seen]**. Don't list them as functions to match unless something references them; keep them out of the
  progress denominator.
- `/OPT:ICF`-style folding makes several source functions share one body **[hedged]**. If a body is reached under
  two class names, match it once and expect the relocation verifier to see one target for two names.
- `/GF` pools identical string literals across the image, so many functions point at one string address.

### 2.5 RTTI and EH tables

- With `/GR`, each vtable is preceded by a pointer to a complete object locator, which leads to the type descriptor
  (mangled name) and class hierarchy. That gives class names, inheritance, vtable sizes and which functions are
  virtual slots of which class. Generate headers from it, and prove them: compile a probe TU that instantiates every
  class and compare emitted vftables, slot counts and `sizeof` with the binary **[seen]**.
- With `/GX`, each function with unwind work has a FuncInfo table in read-only data, a small `__ehhandler` thunk
  (`mov eax, offset FuncInfo; jmp __CxxFrameHandler`), and unwind funclets. They are compiler output: they match
  automatically once the function body matches, so exclude them from the work list **[seen]**.

### 2.6 Link-time code generation

Functions taking arguments in `eax`/`edx`/`esi`/`edi` with a plain `ret`, or thiscall with caller pop, point at
`/GL` + `/LTCG`, which invents calling conventions for internal functions **[seen]**. Per-file C++ can't reproduce
them: prove such functions equivalent and annotate where each parameter travels (codegen-pitfalls.md).

## 3. Objects, splits and link order

A retail XBE has no PDB and no relocation table, so object boundaries must be inferred. Codegen does not depend on
which file a function sits in (beyond inlining and literal pooling), so a wrong cut is cheap; start with one TU
per function and merge later.

- **Link order follows the build's object list**: game objects first, then middleware and engine libraries, then
  the XDK/CRT spans. XDK symbol databases label the library spans.
- **Signals for cuts** **[seen]**: RTTI-named functions cluster by owning class (the largest cluster is the home;
  small far-away clusters are COMDAT strays); classes that interleave in address order came from one file; vtables
  of adjacent objects appear in the same order in `.rdata` (true for most adjacent pairs in one game); unnamed
  functions between two cores are cut by call-graph affinity; long runs with no affinity become their own objects.
- Template instantiations and inline methods are placed by the linker; don't let them pull a cut.
- Dynamic initializers and atexit thunks live in their own subsections (`.CRT$XC*`/`.text$yc`-style); EH funclets
  in another; treat them as separate "objects".
- Record per object: range, inferred name (dominant class), confidence, layer (game / engine / platform / library)
  and compiler flags. Write only addresses and names to the repo, never bytes.
- When merging matched one-function TUs into real files later, re-verify every function: same-TU definitions can
  be inlined and shared literals re-pooled.

## 4. The match loop

1. **Packet** (precomputed, no tokens): symbolized asm with call targets named, referenced data annotated (string
   text, float values, vftable names), owning class and vtable with the target slot marked, a decompiler hint,
   callers and callees. Fix the function list first (SKILL.md section 3) or some packets are unmatchable.
2. **First attempt**: a self-contained TU. No `#include`; declare every class, global and callee minimally;
   define exactly one function; real structs with padding arrays at the right offsets (check `sizeof` against
   immediates like `push 0x2c` before a `new`); a virtual call `call [eax+N]` is slot N/4, so declare that many
   virtuals first. Pre-C++11 only (no `auto`, `nullptr`, `override`, brace-init). Don't copy the decompiler's
   casts; rebuild the types.
3. **Compare**: compile with the original compiler, extract the function from the COFF, mask relocated bytes and
   diff against the executable. Use an **aligned (LCS) diff** over normalised instructions with tags for differs /
   missing / extra; a naive k-th-to-k-th diff made large functions look hopeless when one early instruction was
   extra **[seen]**.
4. **Iterate**: fix the earliest difference, one change per attempt. Read the diff for its kind: same
   instructions reordered = expression or statement shape; lines on one side only = a construct missing or extra;
   registers different everywhere = a side effect of an earlier difference.
5. **Verify references** on MATCH (section 7). Then install and run the formatter (which should keep a
   reformatted file only if it still compiles to the same object).
6. **Budget**: cap attempts (8 is plenty for most); record status, attempts and best score.

**Score** for ranking near-misses: aligned-equal instructions / target instructions, where aligned pairs need equal
bytes (relocations masked), jumps must land on aligned instructions, and extra instructions count against you.
Mnemonic-only pairing gave false 1.00 scores **[seen]**.

## 5. Reading the target (quick reference)

| Pattern | Meaning |
| --- | --- |
| `ecx` loaded right before a call, no stack cleanup after | thiscall member call; `ecx` is `this` |
| `ret N`, no `add esp` after calls to it | callee-pop: `__stdcall` or thiscall |
| plain `ret`, caller does `add esp,N` | `__cdecl` |
| args in `ecx`, `edx`, then stack, `ret N` | `__fastcall` (the `/GS` cookie check is one) |
| `mov eax,ecx` at entry and `this` returned | constructor |
| `test byte ptr [esp+4],1` then a call to `operator delete`, `ret 4` | scalar deleting destructor |
| `eax` left holding junk at `ret` | `void` return |
| `and esp,-8` prologue | a `double`/`__int64` local, an 8-aligned struct or a big array |
| `fs:[0]` setup | EH frame (a local with a destructor, or `try`) |
| `call _ftol` (or `_ftol2`) with a float in `st0` | `(int)f` |
| `call` with args in `st0`/`st1` | `fmod`; `fpatan` is `atan2` |
| `rep stosd` / `rep movsd` / `repe cmpsb` | `memset` / `memcpy` or struct copy / `memcmp` with a literal |
| `sbb eax,eax; sbb eax,-1` after a byte compare loop | the `strcmp` intrinsic |
| a guard word tested with a bit mask, then `or` of that bit and a store | function-local static with a runtime initializer |

Pushes a callee doesn't pop belong to a later call: the first call ran inside the next call's argument list
(MSVC pushes right to left and evaluates arguments before the object). Follow `jmp` thunks to find real callees.

## 6. Mismatch catalogue: symptom -> source change

Each entry: what you see in the diff, then what to change. Fix the earliest one first.

### 6.1 Signatures and structure (check these before blaming the allocator)

- **Temp lands in `ecx`/`edx` where the target uses `eax`**: a later call that never loads `ecx` is a thiscall on
  that value, so the value stays in `ecx` to become `this`: declare the callee as a member of the tested object
  **[seen]**. Or `eax` is busy because the function returns an earlier call's result the decompiler dropped **[seen]**.
- **`this`/argument swapped between `esi` and `edi`**: often a hand-written `strlen`/`strcpy` loop that should be
  the intrinsic; or a missing declaration that made a callee look like it clobbers something it doesn't **[seen]**.
- **Extra or missing pushes around a call**: callee arity wrong. Count the callee's real `ret N` (follow thunks),
  not the pushes before the call.
- **Wrong return type**: `sete al` alone wants a `char` return, not `bool`/`int` **[seen]**; a function whose
  `eax` is junk is `void`.
- **A base call on `this+4` where the target passes `this`**: the base needs virtuals so its vptr is at offset 0
  **[seen]**.
- **Float parameters that are only copied or pushed** must be declared `float`, not `int` **[seen]**.

### 6.2 Register allocation and declaration order

- **Base/index order in `[a+b+N]`** follows the order in which the two values were defined; pure copies don't count
  (they are propagated away). `p[i]`, `i[p]`, `*(p+i)` and casts don't change it. Make the pointer a real computed
  local and declare it before or after the index **[seen]**.
- **Load order** follows source: copying a member into a local before a call (`Mgr* m = owner->mgr;`) can fix it;
  reloading a member in its own block reproduces alternating `eax`/`edx` loads **[seen]**.
- **vtable loaded into a different register**: copy the member pointer into a local first (`Node* q = m; q->c->f()`)
  rather than chaining or caching the inner pointer **[seen]**.
- **A zero kept in a register vs immediate zero stores** (`xor edi,edi` ... `mov [m],edi` vs `mov [m],0`): in one
  project's experiments the register appeared only when a compare against 0 shared the region with the stores, and
  the choice then depended on how many zero stores followed (one compare: 1 store imm, 2 reg, 3 imm, 4+ reg).
  Change the count by moving stores into or out of an inline helper, or by adding/dropping a re-test **[seen]**.
- **Declaring a local at the top** (`int n = 0;`) before the first load can fix a register swap **[seen]**.
- **Reuse parameters**: when the target modifies a parameter as its working variable, do the same rather than
  copying it **[seen]**.
- Hacks with odd side effects (`*(volatile*)`, casting a count to a pointer) perturb allocation everywhere;
  rewriting the plain natural loop fixed such cases **[seen]**.

### 6.3 Locals and stack layout

- **Extra `push ecx`/`pop ecx` or a larger `sub esp`**: you introduced a stack local where the target reused a dead
  parameter slot. Start the temporary's lifetime after the parameter's last use, or reuse the parameter **[seen]**.
- Scalars mostly live in registers; arrays, structs and anything whose address is taken get slots. Slot order is
  not simply declaration order **[hedged]**: try reordering the declarations of address-taken locals, narrowing
  their scopes into blocks, or merging two locals whose lifetimes don't overlap into one.
- `and esp,-8` appears with `double`/`__int64` locals; a plain `float` local doesn't cause it.
- A zero store to a member that is later overwritten gets optimised away; keep it by writing through a local
  pointer (`int* q = &m; *q = 0;`) **[seen]**.

### 6.4 Temporaries and expression shape

- Same instructions in a different order: the expression tree differs, not the logic. Split or merge statements;
  move a subexpression into a named local or inline it **[seen]**.
- **Ternaries and shared exits**: `xor eax,eax` used as the stored zero where you get `mov [x],0` means both paths
  merge into one expression (a ternary, an inline function's return, a `new` result) **[seen]**.
- **A constant loaded before a branch**: a variable set before the `if`; if the target loads it in one branch only,
  drop the shared variable **[seen]**.
- `add ecx,-3` vs `sub ecx,3`, `lea` vs `add`, `inc` vs `add 1`: usually a signedness or type difference in the
  operand, or which value is considered the base; try the operand's type and expression order.
- `x/W` becomes `x*(1/W)` with the reciprocal as a constant **[seen]**; write it as a division.
- One-expression virtual calls (`g->Set(g->Get() == 0)`) load the vptr once; splitting into statements reloads it.

### 6.5 Loops

- **for vs while vs do-while**: MSVC rotates loops so the test sits at the bottom; a `for`/`while` whose entry
  test can't be proven true gets an extra guard test before the loop, a `do-while` doesn't **[hedged]**. If the
  target has no guard, write `do { } while`; if it has the guard duplicated at the top, write `while`/`for`.
- **Pointer vs index**: `mov eax,[x]; lea edi,[eax+8]` then `add edi,4` per iteration is strength reduction of an
  indexed loop: cache the struct pointer in a local and index (`D* d = data; d->c[i] = 0;`). A hand-written
  walking pointer gives a different prologue **[seen]**.
- **Counting down** (`dec ecx; jne`) usually comes from a counter that is only used as a trip count; write the
  loop with an index used inside only if the target uses it **[hedged]**.
- **A run of stores that the target emits in a different position** relative to an immediate store: writing the run
  as a loop (`for (j = 0; j < 8; j++) f[j] = 1.0f;`) or as inline setter calls moved it **[seen]**.
- `unsigned n > 0` compiles to `jbe` exit, `n != 0` to `je` **[seen]**: pick the comparison the target tests.

### 6.6 Switch

- **Small switches** become decrement chains: `sub reg,0 / je / dec reg / je / dec reg / jne` is `switch (x)` over
  0..n, not an if-chain **[seen]**.
- **Dense switches** become a bounds check (`cmp reg,N; ja default`) and `jmp [reg*4+table]`. **Read the table from
  the executable** to map case values to blocks; off-by-one case numbering is a common error **[seen]**. A
  subtracted bias before the compare is the lowest case value.
- Many case values sharing few targets become a **byte index table plus a jump table** (two loads) **[hedged]**.
- Sparse values become a **binary tree** of compares (`cmp; jg/jl`) **[hedged]**; the tree shape is fixed by the
  case values, not their order in the source.
- **Case bodies are laid out roughly in source order** **[hedged]**: reorder the `case` blocks to change block
  layout; the table stays the same.
- `xor al,al` before a switch: `bool r = false; switch (x) { case 0: r = A(); break; ... } return r;` instead of
  returning from each case **[seen]**.
- Jump tables are often placed inline right after the function's code, which truncates naive function sizes.

### 6.7 Branch layout and condition inversion

- **Early return vs wrapped body**: when the target tests before saving registers, use early returns
  (`if (!p) return false;`) rather than wrapping the body in `if (p) { }` **[seen]**.
- **Inverted condition / swapped then-else blocks**: flip the `if`/`else` and negate the condition; MSVC tends to
  place the `then` block as the fall-through **[hedged]**. This is a cheap permuter mutation.
- `if (a && b)` vs nested `if`s vs early returns made no difference in tested cases **[seen]**.
- The duplicate-return-block tail-merge choice is hard to steer (see section 12).

### 6.8 Inlining and intrinsics

- **Declare, don't define, callees** or `/Ob2` inlines them. Conversely, when the target inlined a helper, define
  it `inline` (or in the class body). Small inline helpers also change instruction selection vs the same code
  written out **[seen]**.
- An **inlined getter that can return 0** leaves a null test after the pointer was read **[seen]**.
- `__forceinline` forces what `/Ob2` declined; MSVC refuses to inline some functions regardless (ones with
  `try`/EH states of their own, varargs, `alloca`, recursion beyond a depth limit) **[hedged]**.
- **Intrinsics under `/Oi`**: declare them `extern "C"` and call them rather than writing loops **[seen]**:
  `memset` (`rep stosd`/`stosb`), `memcpy` (`rep movsd` + byte tail), `memcmp` with a literal (`repe cmpsb`),
  `strcmp` (byte loop ending `sbb eax,eax; sbb eax,-1`), `strlen` (`lea edx,[eax+1]` loop, `sub eax,edx`),
  `strcpy`, `fabs` (`fabs`), `sqrt` (`fsqrt`), `sin`/`cos` (`fsin`/`fcos`), `atan2` (`fpatan`). `abs`/`labs`
  become `cdq; xor; sub` **[hedged]**. A hand-written `strlen` loop gives a different register set.
- **Base ctor calls and devirtualisation**: inside a ctor, a virtual call on `this` is devirtualised; call through
  `Base* b = this; b->Fn()` to keep it virtual. Members set before the vptr store come from an inline base ctor
  **[seen]**.
- **Call order around a chained getter**: wrap the chain in an inline member of the intermediate class
  (`Mid::Get(int id) { return prov->Get(id); }`) to change argument vs object load order **[seen]**.

### 6.9 Struct copies vs memcpy

- A struct assignment of a few dwords becomes paired `mov`s; larger ones become `rep movsd` with a count in `ecx`
  plus a byte/word tail. `memcpy` with a constant size compiles the same way under `/Oi`. Pick the spelling that
  gives the target's register choice (`esi`/`edi` setup order differs) **[hedged]**.
- By-value struct arguments are copied onto the stack (`sub esp,N` then `rep movsd`, or a copy constructor called
  with `ecx = esp`); the callee's `ret N` counts the whole struct **[seen]**.
- Overlapping copies the original did with forward `rep movsd` are not `memcpy` semantics; for a port, keep a
  forward loop (byte-match source may use the intrinsic if it matches).

### 6.10 Signed/unsigned and narrow types

- `movsx` vs `movzx`: the signedness of the narrow type being loaded (or `/J`).
- `sar` vs `shr`, `idiv` vs `div`, `jl`/`jg` vs `jb`/`ja`: signedness of the operands. Signed division by a power
  of two becomes `cdq; and edx,mask; add eax,edx; sar eax,k` (or `sub eax,edx; sar` for 2) **[hedged]**.
- `char`/`short`/`bool` parameters are pushed as full stack words; the callee reads only the low part. Upper bytes
  can be stale **[seen]**.
- **bool returns**: `setcc al` without zero-extension; `mov al,1` / `xor al,al` paths; a returned stored flag byte
  is `char`, not `bool` **[seen]**. Signedness of temporaries made no difference where tested (section 12).

### 6.11 Calling conventions

| Convention | Shape |
| --- | --- |
| `__thiscall` (member) | `this` in `ecx`, args on stack, callee pops (`ret N`) |
| `__cdecl` | args on stack, caller pops (`add esp,N`, or `pop ecx` for 4 under `/O1`) |
| `__stdcall` | args on stack, callee pops, no `ecx` setup |
| `__fastcall` | first two dword args in `ecx`, `edx`, rest on stack, callee pops |
| varargs member | `this` pushed on the stack, caller pops (cdecl) |

- MSVC 7.1 rejects `__thiscall` in function-pointer types: call through virtual methods of a declared class or
  member function pointers instead of casts **[seen]**.
- `lea ecx,[reg+off]; push x; call` with no cleanup is a thiscall member of a sub-object or array element: declare
  it on the element type **[seen]**.
- `mov eax,[ecx+N] ... call eax` (instead of `call [eax+N]`) is a member function pointer or function pointer field
  copied to a local first (`Fn fn = mFn; (obj->*fn)()`) **[seen]**.

### 6.12 Virtual calls and thunks

- `mov eax,[ecx]; call [eax+N]` is slot N/4. Declare the slots in order (generated RTTI headers make this free).
- Adjustor thunks (`sub ecx,N; jmp target` / `add ecx,N; jmp`) implement multiple-inheritance overrides; vcall
  thunks (`mov eax,[ecx]; jmp [eax+N]`) implement pointers to virtual members **[hedged]**. Both are compiler output:
  match the real function and let the class layout produce the thunk.
- A function ending `jmp Base::~Base` is a destructor whose base dtor was tail-called **[seen]**.

### 6.13 Constructors and destructors

- **vptr store sinks below the first member load/test in a dtor** (target: `mov esi,ecx; mov [esi],vftable; mov
  r,[esi+N]`). Fixes in order **[seen]** (one investigation fixed a cluster of hundreds of functions):
  1. a real `virtual ~T() throw()` with the trailing frees/releases moved into inline destructors of small member
     types (reverse offset order; all callees `throw()`), so the compiler emits the vptr store first;
  2. `extern "C" void _ReadWriteBarrier();` called right after the store (an intrinsic that emits no code but
     blocks the reordering);
  3. both the store and the first member load made `volatile` (either alone does nothing).
  Hand-storing the vptr as an integer is never acceptable; it hides the class and breaks relocation checks.
- **Ctor zero-inits emitted after the vptr store** go in a member type with an inline ctor (`Vec v; ... :
  v(0,0,0)`); plain `a(0), b(0)` initialisers sink the vptr **[seen]**.
- **Dtor body stores** belong in an inline method of a member struct (`sb.Reset()`) **[seen]**.
- **Two vptrs** (multiple inheritance): a second base with an inline virtual dtor reproduces the second store
  **[seen]**.
- **EH frames**: any destructor on a local, even a temporary, adds an `fs:[0]` frame and state stores
  (`mov dword ptr [esp+N],k`). If the target has none, the callees must be `throw()` or the temporary must not have
  a destructor **[seen]**. If the target has one and you don't, a local object with a dtor is missing.
- **Scalar deleting destructor**: `if (flags & 1) operator delete(this)` after the dtor body; vector deleting
  destructors also walk a count stored before the array **[hedged]**.

### 6.14 new and delete

- `new T(args)`: a call to `operator new`, a null test, the ctor called on the non-null path, and a shared
  `xor eax,eax` on the null path. Constant-size allocation + null test + thiscall returning `this` is
  `new (alloc) T(...)` with an inline `operator new(size_t, Allocator&)` **[seen]**.
- Placement new adds a null test too; call `p->T::T()` explicitly to construct without it **[seen]**.
- With `/GX`, a `new` whose ctor can throw gets an EH state that frees the block on unwind; `throw()` ctors avoid it
  **[hedged]**.
- `operator delete` and `operator delete[]` are different symbols even when one forwards to the other; packets that
  label both with one name produce byte matches that fail relocation checks **[seen]**.

### 6.15 Static locals

- A function-local static with a runtime initializer compiles to a guard word: load the guard, test a bit, on first
  use set the bit (`or edx,1; mov [guard],edx`) and run the initializer. Several statics in one function share the
  guard with one bit each **[seen]** for the pattern, **[hedged]** for sharing. Write `static T* last = param;`.
- Statics with constant initializers have no guard; they are plain data.

### 6.16 String and float constants, `.rdata` order

- A string literal becomes a `??_C@` COMDAT and a float literal a `__real@<hex>` COMDAT in your object. With
  relocations masked, any string or float "matches" the bytes; only the relocation verifier checks content **[seen]**.
- Float constants must be bit-exact: write 9 significant digits from the executable's bits (`0.0174533f` is not the
  float the game uses for pi/180) **[seen]**.
- `fld1`/`fldz` load 1.0 and 0.0 without a constant; any other value is a memory operand. A literal vs an
  `extern const float` global can change codegen (constant folding), so match the target's access **[seen]**.
- `.rdata` order of literals within an object follows first use in the TU **[hedged]**; it matters only when you
  match whole objects (data layout), not single functions.
- A global's address hard-coded as an integer (`p->vt = 0x4xxxxx`) can byte-match and still be unportable: declare
  the global and reference it **[seen]**.

### 6.17 x87 floating point

- **Operand order**: `fsub`/`fsubr`, `fdiv`/`fdivr` and which operand is on the stack follow the source order of
  operands and which side was computed first. Float sums and products are reassociated: try permutations of the term
  order (`y*y + z*z + x*x`) and full parenthesisation **[seen]**.
- **`fxch` count and `fld`/`fstp` order** follow evaluation order and when results are stored; storing a result to a
  named `float` local vs keeping it in an expression changes spills.
- **Compares** use `fcom`/`fcomp`/`fcompp` (or `fucom*`), `fnstsw ax`, `test ah,mask`, `jp`/`jne`/`je`. The mask
  encodes the relation and NaN behaviour; `a > b` and `b < a` compile to different operand orders and masks. Write
  the comparison with operands in the target's order (in one project, "new value > old value" was the common form)
  **[seen]**. `sahf` forms and `fcomi` are uncommon in 7.1 game code **[hedged]**; if you see `fcomi`, suspect
  hand-written or library code, or other flags.
- **Float to int**: `(int)f` calls `_ftol` (`_ftol2` in some CRTs) **[seen]**; `/QIfist` would give `fistp`
  **[hedged]**.
- **No SSE**: x87 only, so `float` math is done at the FPU's precision (53-bit on Xbox, set by the CRT) and rounded at
  stores **[seen]**.
- Float arguments are pushed as `push dword [mem]` when copied straight from memory, or `sub esp,4` / `push ecx` then
  `fstp dword ptr [esp]` when computed; doubles use `sub esp,8; fstp qword ptr [esp]`.

### 6.18 Tail calls, thunks and linker artifacts

- `/O2` turns `return f(args)` into `jmp f` when the frame allows it (no locals left to clean, compatible stack
  arguments) **[hedged]**; a thiscall forwarder often ends in `jmp` **[seen]**.
- Calls through `jmp` thunks (import thunks, `[thunk]` stubs, incremental-link tables) must be followed to the real
  target when counting `ret N` and naming callees. An incremental-link table (a block of `jmp rel32` stubs every
  callee goes through) means `/INCREMENTAL`; retail builds normally don't have one **[hedged]**.
- Kernel imports are calls through the XBE's kernel thunk table, not functions to match.
- Noreturn tails (a call followed by `int3` padding) end the function; a decompiler that assumes a call is noreturn
  when it isn't truncates the body **[seen]**.

## 7. References: a MATCH that hits the wrong symbol

After compare reports MATCH, offsets line up, so every relocation in your object pairs with the original's 4 bytes
at the same offset. Check each target **[seen]**:

- string literals byte-equal with what the original points at; float constants bit-equal;
- vftable references are real vftables of the right class; calls land on function starts; data references land in
  data, not mid-code;
- one declared symbol maps to one target (two different call targets under one name is an error, and so is a
  declared function standing in for two);
- a constant 0 in the original where yours has a relocation (or the reverse) is a mismatch the masking hid;
- names that carry an address (`FUN_xxxxxxxx`) agree with the address they resolve to;
- global initializers compared with the original's bytes.

In one project's first full verification ~2% of byte matches were wrong, mostly **shape-propagated copies** that
kept the template function's strings or callees **[seen]**. Run the verifier inside every tool that installs a
match (the model tool, propagation, cloning), and feed failures back as diffs.

## 8. Permuters

A permuter randomly rewrites a close attempt, recompiles, and keeps candidates that score better.

- **Mutations** that worked as a starting set: swap nearby statements in a block; commute operands of commutative
  operators (including `&&`/`||`, which changes evaluation order); flip a comparison (`a < b` to `b > a`); retype
  `int`/`unsigned`; truthiness (`p` vs `p != 0`); `++`/`--` forms; flip `if`/`else` with negated condition; split
  an initialised declaration; inline a single-use local; convert `if` to a ternary; add or remove `throw()`; try a
  few flag sets.
- **Mutations need not preserve meaning**: only a byte-identical result that also passes the relocation verifier
  counts, and identical bytes plus identical references mean identical behaviour. Reject candidates that hard-code
  image addresses.
- Search: hill-climb on the aligned score with plateau walks (accept equal scores), many workers in parallel.
- **What to expect**: it moved a register-allocation near-miss from 0.44 to 0.59 in minutes early on, but on a pile
  of 70 near-misses that agents had given up on (register choice and operand order) it found nothing at ~2,000
  tries a minute **[seen]**. Other projects dropped permuters for overfitting and doom loops. Use it as a cheap
  pass on near-misses (score >= ~0.75) between model rounds, not as the main engine, and don't spend a box on it
  that could run equivalence checks.

## 9. Scaling: shapes, clones, generators, recipes

- **Shape dedup**: mask call targets and absolute addresses and hash the rest. In one game, 18,000 small functions
  collapsed to ~6,400 shapes, and ~80 model matches propagated to ~2,200 verified functions **[seen]**. Propagated
  copies must pass the relocation verifier individually (strings and callees differ).
- **Cloning**: compile a matched source against an unmatched same-shaped function, rename every symbol whose target
  moved (names carrying the old address get the new one), install only when compare and the verifier both pass.
- **Generators** for families of near-identical but not same-shaped functions (registration tables, property
  readers, script bindings): a script reads the function's asm or packet in order and emits the source, sometimes
  into a hand-written template. A clone or generator is only as good as its template: one wrong template spread the
  same bug to a dozen functions in one project **[seen]**.
- **Research once, apply many**: when many near-misses fail on one symptom, give the whole cluster to one strong
  investigation; it found three recipes for the vptr-store problem, matched the 13 study cases, and the recipe then
  matched ~575 more through cheap batches and ~120 more through scripts with no model at all **[seen]**. Write each
  recipe into the matching brief and the model prompt so the next batch doesn't rediscover it.
- **RTTI-derived headers** shared by every source stop each file from inventing placeholder classes; regenerate
  matched sources onto them and re-verify (all early hand matches still matched) **[seen]**.
- **A hand-matching workbench** (editor preloaded with the best attempt, live aligned diff, packet beside it, a
  permute button, install on verified match) speeds up the human loop.

## 10. Matching with LLMs

What worked in a farm of cheap and local models plus subagent batches **[seen]**:

- **One tool, no exploration.** The worker gets the packet and a single `submit_cpp` tool that compiles, diffs and
  verifies; no file or shell access, so tokens go to code. A match ends the run.
- **A static system prompt** (cacheable prefix) holding: the compiler and flags; TU rules (no includes, declare
  everything, one body, layout and slot rules, pre-C++11); how to read the diff; a symptom -> source table (section
  6); idioms seen in this binary; one worked example. Grow it from batch reports ("any NEW pitfall, max 2 bullets").
- **Compact diffs**: mismatches with a line of context, aligned, not whole listings.
- **Escalation**: cheap tier first, then stronger; a higher tier starts fresh with the packet, the best attempt and
  its diff, and a one-line summary per earlier attempt (score, first mismatch). Different model families rescue
  each other's misses.
- **Caps and restarts**: a few attempts per tier; fresh restarts beat long chains (matches level off by attempt
  4-5). Clamp output tokens (one runaway reply was 480 KB). Low or no "thinking" was as good and much faster for
  matching.
- **Batches of subagents**: ~8-30 functions each with the brief and tools; one function per family per batch, or
  interleaved shapes, so a stubborn family doesn't eat the batch. Accumulated brief tips raised one round from 38%
  to 72%.
- **Benchmark before forecasting**: a fixed held-out set sampled across sizes. A sample sorted by size once showed
  "100%" because it was all 1-8-byte functions.
- **Fine-tuning a small local model** on verified matches (with the teacher's reasoning) worked well under ~64
  bytes and not above ~128; more varied data helped more than more of the same.
- **Anti-cheat**: reject inline asm, `_emit`, `naked`, `#pragma`, hard-coded image addresses and hand-stored vptrs.
- Treat model output as untrusted code: compile it, never run it outside an emulator/sandbox.

## 11. Prioritising the work

1. Exclude library spans, funclets, thunks and dead code from the list.
2. Small leaf functions first (no callees, or only declared callees); they teach the brief and feed shape
   propagation. Count progress in bytes alongside functions.
3. Families next: clone and generate (section 9).
4. Work **near** what's already matched (same class, same object): similarity scheduling beat difficulty ranking
   in other projects, and shared declarations carry over.
5. Mid-size functions to strong models with the full brief; park near-misses with their best attempt for recipe
   sweeps and permuter passes.
6. Large functions, LTCG conventions and plateaued near-misses go to equivalence proofs.

## 12. Ruled-out levers and known-unsolved shapes

Ruled out in tested cases **[seen]**: the `register` keyword; `const`; signedness or pointer-vs-int type of a temp;
`a+b` vs `b+a` for integers; `p[i]`/`i[p]`/`*(p+i)`; `if (a&&b)` vs nested or early-return forms; statement order
inside a run of independent stores (the scheduler keeps them in order); compiler flags for the vptr-store problem.

Unsolved in one project **[seen]**: `ebx` vs `ebp` for a local (rare in the binary); a redundant re-test of a
register parameter kept after a call; which duplicate return block the tail-merger keeps; `cmp reg,[param]` vs
`cmp [field],reg` operand roles; caller-cleaned `this` calls. Expect a residue like this and prove those functions
equivalent instead.
