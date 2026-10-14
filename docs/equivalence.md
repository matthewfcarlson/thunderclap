# Equivalence verifier (`tools/equiv.py`)

Proves that a function we wrote behaves like the original, without byte-identical codegen. It is the level
1–3 verifier of [task 09](tasks/09-equivalent-decomp.md).

```sh
build/venv/bin/python tools/equiv.py SRC 0xADDR                 # human-readable report
build/venv/bin/python tools/equiv.py SRC 0xADDR --json          # one-line JSON (for the farm)
build/venv/bin/python tools/equiv.py SRC 0xADDR --map map.json  # bind our symbols to original addresses
build/venv/bin/python tools/equiv.py SRC 0xADDR -- /Oy-         # extra cl flags
```

Library: `equiv.verify(src, addr, symbol=None, flags=(), n_inputs=64, mapping=None, use_names=True, ...)`
returns the report dict. `seeds=[...]` (or `EQUIV_SEEDS=1,2` in the environment) runs only those random
inputs: a regression case for the one input in thousands that showed a bug. The exit status is 0 only for `equivalent`. A typical function takes 1–5 s
(compile included); loops that run long on fuzzed inputs can take up to the 120 s level-3 budget. The
budget is CPU time, so a loaded machine takes longer but gets the same result. `--time-budget S` changes it (slow
functions need more to reach the 50 completed inputs `promotable` asks for). `--inputs N` raises the
input cap to at least N.

## Levels

| Level | Check | Fails on |
|---|---|---|
| 1 | compiles with MSVC 7.1 (`compare.py` flags; `--clang` adds a host-clang syntax check, warning only) | compile errors |
| 2 | same references: callees, globals, vftables, strings | a missing or extra callee or global, an unresolvable symbol |
| 3 | differential execution in Unicorn on fuzzed inputs | any difference in calls, memory writes, return value, callee-saved registers or stack balance |

`status` is `equivalent` (levels 1–3 pass), `fail`, `inconclusive` (no difference, but fewer than 8 inputs
ran to completion or branch coverage is under 25%; byte-identical code is exempt), `unsupported` (level 3
could not run any input to completion), `compile_error` or `no_function`. `level` is the highest level
passed.

`equivalent` says no difference was seen with *some* coverage. Promotion to `equivalent/` needs more, and
`promotable` says whether this run meets that bar: `equivalent`, no level-2 conflicts, at least 75% branch
coverage, at least 50 completed inputs (run with `--inputs 3000`), and at most 10% of the completed count set
aside as wild (below). When an `equivalent` run falls short, `promotable_note` says why and the text report
prints it (`not promotable (thin evidence): branch coverage 21/46 is under 75%`). `status` keeps its meaning,
so tools that parse it are unaffected.

Level 2 also lists **warnings**: differences that equivalent code can legitimately have. Examples are an
immediate that only looks like an address, a float constant loaded another way (`fld1`, or a double
instead of a float; the 2^32 bias of an unsigned-to-float conversion isn't even warned about), a string or global read in pieces, another element of a global the original
references too (a loop's induction base at a different field of the same object), and CRT calls the
original inlined. Level 3 still checks the behaviour behind them.

## Binding our symbols to original addresses

Our object names things; the original has addresses. Each symbol our code references is bound in this
order. The report's `level2.mapping` says which rule fired.

1. **explicit**: `--map` JSON, or a `// equiv-map: ?Foo@@YAXXZ = 0x00123456` comment in the source.
2. **content**: string literals (same bytes as a string the original references), `__real@` float
   constants (same bits, in read-only data: a writable global that holds 0.0 is a variable), vftables
   (`??_7Class@@6B@` by RTTI class name) and RTTI type descriptors (`??_R0?AVClass@@@8`, the operands of
   `dynamic_cast`, by class name: with two casts in one function, pairing by position could swap them).
   A string the original stores without its terminator (`L"()"` among packed pairs `"()[]{}"`) binds by
   its characters.
3. **name**:
   - an exact `build/functions.csv` name (`Class::vfunc_3`, `thunk_FUN_…`, or a mangled name it keeps
     as is, like the CRT's `?getBasicDataType@UnDecorator@@…`);
   - an address in the name (`FUN_00123456`, `DAT_004dd6e4`, `g_00491234`, …);
   - an XDK symbol;
   - a fixed CRT helper (`__ftol2`, `__chkstk`);
   - a CRT routine found in the XBE by behaviour (below).
4. **paired**: instruction alignment with the original; the operand at the same spot of the matching
   instruction. When the code is byte-identical, this is exact and overrides wrong name claims, which are
   reported in `level2.conflicts`. In other code the alignment can pair different statements of the same
   shape, so it only binds symbols that have no name, and never contradicts one. Float constants and
   strings bind by content only, never by position.
5. **ordered**: leftover symbols matched to leftover original targets of the same kind, in first-use order.

Rules 4 and 5 trust the original. With invented names, level 2 checks shape and consistency, and level 3
checks the resulting behaviour. Names that carry addresses make level 2 a real check.

A function from a merged source-tree object (`tools/build_tree.py`, `verify(..., obj_path=...)`) is wrapped in
`namespace fn_<addr>`, so its mangled names differ from its standalone source's. The `equiv-map`/`equiv-conv`
names of the source, the `sizeof` probes of callee parameter types and the vftable and RTTI lookups by class
name all see through that namespace.

Two kinds of symbol are never paired:

- **Functions defined in our own object.** These are code the original inlined, for example an inline
  constructor that this compile didn't inline. They run in place, as if inlined, and their references count
  at level 2. That includes a tail jump into one (`~Derived` ending in `jmp ~Base`, where the original
  inlined `~Base`); the function under test is picked by comparing each candidate with the original, with
  the bytes of the functions it tail-jumps to appended. MSVC's own helpers `vector constructor iterator` and its kin (`??_H`, `??_I`, `??_L`,
  `??_M`) are the exception: the original calls the XBE's copy (FUN_00011520), so ours pairs with it.
- **CRT routines** (`memcpy`, `strcmp`, `sin`, …). The XBE's own copies are found once by behaviour. Every
  function in the CRT region is probed against memcpy/strcmp/floor/… test vectors, and the results are
  cached in `build/equiv/crt.json`. The routines found run for real on both sides. A routine the XBE
  doesn't have out of line (e.g. `memset`, inlined everywhere) runs semantically in Python. Either way,
  inlining one side and calling on the other makes no difference.

## Calling conventions MSVC can't express

Some pure3d/d3d functions use link-time-generated conventions: arguments in `eax`, `edx` or `esi`, `this`
in `ecx` with the caller popping, and so on. Write ordinary C++ with the values as normal arguments, and
declare where the original passes them:

```cpp
// equiv-conv: FUN_00326dc0 eax ecx
int FUN_00326dc0(int primType, int count);               // a plain cdecl declaration

// equiv-conv: FUN_0026b380 stack stack stack ebx edx esi edi
extern int FUN_0026b380(void* a, int mode, void* c, int toMode, int g, int f, int e);
```

- The locations are listed in our parameter order: `eax ecx edx ebx esi edi ebp`, or `stack` for the next
  stack word.
- The name can be the original's name or address, or our symbol's name.
- At each call to that function, the original's values (taken from those registers and stack words) and
  ours (taken from wherever our declaration put them) are compared as one argument list, position by
  position. Swapped or wrong arguments still fail; only the location may differ.
- At such a call in our run, the callee's caller-saved register arguments are put where the annotation
  says before the stub returns, so a register the callee preserves holds that argument afterwards, as in
  the original.
- The same annotation on the function under test (`// equiv-conv: FUN_00325fd0 ecx edx eax stack`) feeds
  the original its inputs in those registers and ours through our declaration.

Stack effects: both sides pop what the callee's real `ret N` pops, as they would linked against the real
function. A declaration that pops something else leaves our stack off from then on; when that changes
behaviour (it usually crashes), the first mismatch explains it (`our declaration has the callee pop 4 bytes
of arguments, but it really pops 0`). Two wrong declarations can cancel out (a push folded around a call),
which byte-identical code sometimes does, so the declaration alone isn't a failure. `this` in `ecx` with
caller-popped stack arguments (a plain `ret`) can't be declared in C++: annotate it with `equiv-conv`, and
then our side pops per our declaration. When a callee reads a register that our code doesn't set, the mismatch message suggests the
annotation.

`__security_check_cookie` is `__fastcall`: the cookie must arrive in `ecx`
(`extern "C" void __fastcall __security_check_cookie(unsigned int)`).

## Level 3 design

Each input runs the original bytes and our linked object, each in a fresh 32-bit Unicorn instance.

**Memory**
- Memory is a pure function of `(seed, epoch, address)`, mapped lazily on first touch. Both runs see the
  same bytes wherever they read, and no address faults except a small poison range for unresolved symbols.
- XBE image pages hold the original sections, with `.bss` zero. Referenced `.data` globals get fuzzed
  values, except in input 0.
- Other memory (heap, wild pointers) comes from a pool of structured pages: zeros, small ints, `-1`,
  flags, floats, and pointers into a heap region. `0..0xFFFF` reads as zero, so null dereferences work.
- Our object is laid out at `0x60000000` and mapped in both runs. Bound symbols point at original
  addresses, so a call goes to the same address in both runs and a stored vftable pointer has the same value.

**Inputs**
- `this`, the arguments and the registers come from the mangled signature: pointers, ints, floats, doubles,
  and the hidden struct-return pointer. A struct passed by value gets as many words as the function's own
  `ret N` pops or its code reads (not just 4). 16 extra stack words follow, and callee-saved registers get
  unique values.
- Seeds rotate between several modes:
  - wide or near/ascending pointers;
  - iterator ranges: a later pointer argument a few elements past the first one, in a step the code
    advances pointers by (`add esi, 0x44`), so `[first, last)` isn't millions of elements;
  - "tame" small-number memory;
  - dictionary memory: planted copies of the input's pointers, `this+4/8/12` (object graphs) and the
    constants the original compares against;
  - narrow memory: every heap pointer folded into 512 bytes, so `end - begin` ranges stay short;
  - noise memory: random bytes on half the pages, so copies and byte loads see distinct values;
  - boundary constants as int arguments;
  - stubs that always return 0 or 1.
- 64 random inputs, then more (up to 256) while branch coverage of the original keeps growing.
- Seeds with `seed % 8 == 6` are "stable": callees change no memory, so a loop that calls something per
  element re-reads the same bound every round.
- **Loop repair.** An input on which the original runs out of steps in a loop (a count, a `begin`/`end`
  pair or a list walk read from fuzzed memory) is re-run with the loop's bound patched so that the loop
  ends after a round or two; the induction variable's step comes from the comparison's first two rounds.
  The compares tried first are those that can end a loop: back edges (`cmp esi, [count]; jb top`) and
  jumps out of one (a top-tested loop's `cmp; jae out`, but not a jump to a block that goes straight back
  in), that ran at least 1/64 as often as the hottest compare and have a patch, hottest first. An inner loop
  over a constant bound (`cmp edx, 8; jb`) has no patch, so the outer loop's bound is found even when it is
  far down the list. Then the hottest other compares (often clamps inside the body, whose patching never
  ends the loop). A bound re-read after each call is patched in every epoch, and also only from the next
  epoch on (the loop runs once: `while (t->first != head) erase(t->first)`).
  A run that then hangs in the next loop is repaired again (4 loops deep, 64 runs). A loop that ran away
  once is cut off after 256 rounds on later inputs (those count as timed out, and are repaired too).
  Directed inputs that run away are repaired the same way, from a budget of their own.
- **Walk sentinels.** An input whose original runs away in a list or tree walk (`while (n->left != nil)`,
  where `nil` is `&tree.nil`, a fixed pointer, and the links come from fuzzed memory) is run again with the
  pointers its hottest compares held fixed planted in half the words of every data page, in every epoch.
  Walks then end within a few links. A run that hangs in a walk toward another sentinel (a second tree)
  goes again with both. After 4 such runs without a completion the function stops getting them. A `rep` string
  instruction with a count over 0x2000 (`rep stosd` over a fuzzed `count*4` bytes) is repaired like a loop
  bound: the count's source is patched to about 8.
- With `--inputs` over 256, the random inputs hand over to the directed ones once half the time budget is
  gone (and 50 inputs completed); the rest of the random inputs run afterwards, then directed ones again.
  When the random phase stops at 32 inconclusive inputs, the directed phase runs, then more random inputs
  while fewer than 50 have completed, or while at most 20% of them were inconclusive.
- **Alphabet strings.** A char loop that compares each byte with constants (an atof-style parser: `'-'`,
  `'.'`, `'0'`..`'9'`) gets short strings made of those chars (and keywords spelled by compares at
  consecutive offsets, `p[0] == 'c' && p[1] == 'l' && ...`) planted where it read its first byte. A stack
  copy of a heap string (`do *d++ = c = *s++; while (c)`) is planted through its source.
- Then up to 96 **directed** inputs (input-to-state; each one that finds a new edge earns 4 more, up to 4x).
  Compares are worked breadth first: one observation per compare per pass, on to its next ones while they
  find new edges, until both sides were taken 4 times. String-literal plants take at most half the
  remaining budget per pass. A stub result can be planted for that call and every later call to the same
  callee (a loop that runs through only when each element's getter says so).
  Every comparison the original executes is recorded, with where each operand came from. When a branch side
  (or `setcc` outcome, or jump-table case) was never taken, or was taken by fewer than 4 inputs, the input
  that reached it is re-run with that memory, stack argument, stub result or out-parameter word patched to
  a value on the other side (alternating between the two operands). Followed through:
  - the high byte of a loaded word (`mov ax, [buf]; cmp al, 'B'; jne; cmp ah, 'M'`), and bytes of a stack
    argument word;
  - comparisons done by `sub`/`add`/`dec`/`inc`/`and`/`or r, r` (`dec ecx; sub ecx, 4; je`: a type switch);
  - arithmetic on the loaded value: `add`/`sub` of constants or other registers (`end - begin`), shifts,
    `and`, `neg`/`not`, magic-number divisions (`imul` by a constant, `idiv`), `movzx` of a low byte, a
    byte-table switch index (`movzx ecx, byte [eax + table]`), all inverted to find the value to plant;
  - a register stored to a stack local and compared there later (`movsx eax, byte [edx]; mov [esp+4], eax`);
  - x87 compares (`fcom`/`fcomp` + `fnstsw`/`test ah`, `fcomi`), against memory or a stubbed callee's
    float result, a float a stub filled in through a pointer, a loaded value plus, minus or times a
    constant (`fld [g]; fadd [k]; fcomp [0.95]`: inverted), or a masked argument word (`and eax,
    0x7fffffff`: fabs, ties planted). When the compared value is computed (`sqrt` of the difference of two stub-filled vectors,
    a scaled and clamped result) there is no single word to invert: the input is re-run with every stub
    float (float results and out-parameter fills) set alike, to 0, 1000 and 1 (equal vectors give distance
    0);
  - a loop's bound (patched for one or two more rounds, in every memory epoch when it is re-read after a
    call).

  - string compares against a literal in `.rdata`: `repe cmpsb/w/d` (one operand in `.rdata`, `ecx`
    elements), calls to the CRT `strcmp`/`_stricmp`/`strncmp` (executed for real), and inline byte-pair
    loops (`mov dl, [ecx]; cmp dl, [esi]`). Fuzzed bytes never spell `"Millimeters"`, so the original's
    run records (buffer, literal, memory epoch) and a directed input re-runs it with the literal written
    over the buffer: once with its terminator (an exact match) and once without (a longer string starting
    with it). A heap or global buffer is planted in the epoch it was read in; a stack buffer only when a
    stub filled it (the literal becomes that stub's fill). Each (site, literal) is queued from two inputs;
    the next bytes of the same pair of strings aren't queued again. Planted runs queue the compares they
    reach in turn (a chain of keywords, a tag then a name prefix). These run first in each round, while
    some edge is missing, and count in `inputs_directed` (and `inputs_planted`). Only inputs change; both
    sides see the same memory.

  Directed inputs never patch code (a switch's byte table: ours has its own), nor a float constant read
  at a fixed address in `.rdata` (ours may load it from its own constant, or as `fld1`), nor plant an
  address that wraps around (`lea ecx, [ebx + 0xb4]; test ecx, ecx` and `add eax, 0x58; je` are the null
  checks of a base-class conversion, not value tests). Exact float ties are planted only against a plain
  loaded value: against a computed one, the tie depends on the precision each side computes in.

**Callees**
- Callees are never executed, except `_ftol`/`_chkstk` and the CRT routines above. The `/GS` check
  `__security_check_cookie` is skipped on both sides, because its caller's `add esp` releases the frame
  and isn't argument cleanup; `ecx` must hold a value read from the cookie global. A call to the function
  under test itself (recursion) is stubbed on both sides, and `&self` (a stored function pointer) is the
  original's address in our run too. At every `call`, and at
  a `jmp` that leaves the function (a tail call), a stub:
  - records the target, the argument words, the registers, and every stack local passed by pointer;
  - returns a deterministic `eax`/`edx`, plus a float on the x87 stack if the code after the call consumes
    `st0` (the same value on both sides; directed inputs can steer it). Values the caller already keeps on
    the x87 stack across the call count (`fld [k]; call f; fadd [m]` adds to a running sum, it doesn't
    consume a result), and the `/GS` cookie check after the call is looked through;
  - returns `this` (its `ecx`) from a constructor: a callee that writes through `ecx` and returns its
    incoming `ecx` on every path (`Cue *c = new (buf) Cue(...); f(c)` uses the result where the original
    recomputes `lea ecx, [buf]`);
  - fills each local passed by pointer (an out-parameter), with the same values on both sides. A class
    parameter is filled over its whole `sizeof`. Any other parameter gets at least 16 bytes, skipping
    words the function has already written itself;
  - models how far the real callee writes through each pointer argument (x87 stores count: capstone marks
    `fstp [eax]`'s operand as read-only) (`ecx` or a stack argument). A
    static scan of the callee (`Program.callee_writes`) follows stores through the incoming pointer, copies
    and constant offsets of it, and callees it is passed on to (a base or member constructor). In the
    original's run that extent, capped at the room the original's frame has there, is filled; ours fills
    the same offsets, including words the function wrote itself before the call (a dead spill slot inside
    the object in one frame layout). Where a side had written such a word, its old value is kept aside: an
    input on which the two sides' old values differ, one of them reads the word back before rewriting it,
    and no difference shows, is inconclusive (`fill_readback`). The extent is a range, so it can cover a
    word the real callee leaves alone. Through a register that includes offset 0, and a partly written last word is filled
    whole: a by-value argument built in place by a copy constructor (`sub esp, 8; mov ecx, esp; push src;
    call ctor`) otherwise kept each side's own dead return address in it. A return address or saved
    register below `esp` is dead, so it no longer bounds the room either. If ours has less room before a saved register, the return address or the caller's
    frame, the call fails (`writes 0x40 bytes through ecx ... but ours has only 0x20 bytes there`): our
    local is smaller than the callee's object;
  - leaves `ecx`/`edx`/`eax` alone when the callee never writes them (callers may rely on that);
  - pops the callee's argument bytes. Pops over 252 bytes (a struct passed by value) are done directly.
- A `push` of an untouched callee-saved register counts as a save (not an argument) only if the function
  pops that register somewhere; otherwise it passes on a register argument (LTCG `esi`). A register the
  function wrote itself is never a save, even when it holds its entry value again (`xor edi, edi; push edi`
  with `edi` 0 on entry, as recorded game states often have it). Alignment padding (`mov edi, edi`,
  `lea esi, [esi]`) doesn't count as a write.
- The pop count comes from the callee's own `ret N` (following tail jumps) when the call site names a real
  function. For cdecl, it comes from the caller's `add esp, N` or `pop ecx` cleanup, including one
  deferred over several calls (looked for up to 48 instructions on: four writer-callback calls share one
  `add esp, 0x40` 31 instructions later). An `add esp, N` in an epilogue (followed by `ret` or a callee-saved `pop`)
  counts only beyond the frame the prologue reserved with `sub esp`. A caller-cleaned callee takes only the words it reads; pushes above them
  are pending for a later call.
- A call of unknown arity (virtual, a `jmp [vtable]` thunk) is decided first by a branch taken before its
  pushes that joins the code after it: both paths reach the join with the same stack depth (`je L; push x5;
  call [vt+0x48]; push eax; call __RTDynamicCast; add esp, 0x14; L:` pops one word). An epilogue `add
  esp, N` that releases exactly the prologue's frame doesn't release pending words: the callee popped them.
  Otherwise it is decided by what the caller does with the
  pushed words afterwards: released by a later `add esp` (the callee leaves its arguments:
  caller-cleaned), popped by a later call with a known `ret N` (pushed early for that call: `push 1; call
  thunk; push eax; push esi; call f(ret 4); push eax; call g(ret 12)`), or read by a later caller-cleaned
  call (`push &t; call [vt+0x40]; push eax; ...; call f; add esp, 0x10`). When a later `ret N` call pops some
  of them and a later `add esp` releases exactly the rest, the callee popped none (`push eax; push K; call
  thunk; mov ecx, eax; call f(ret 4); push ...; call g; add esp, 0x10`: f takes K, g's cleanup the `eax`;
  taking it for a `ret 4` thunk left the stack a word off, and callee-saved registers came back shifted). A deferred `add esp` after later
  calls that releases fewer than the pending words, with nothing after it taking the rest before the
  epilogue, means the callee popped the rest (`push 0; push 0x103; call [vt+0x164]` (ret 4)`; push eax;
  call __RTDynamicCast; push 8; call new; add esp, 0x18`). Otherwise the tracked pushes
  count, and the callee pops them. Each side's stack follows its own code (a virtual we declare as a
  thiscall member pops its arguments where the original's caller cleaned them up; the target is unknown
  either way); the number of words compared is the original's.
- The number of argument words compared is what the callee actually reads (a stack-depth scan of the
  callee, which follows indirect calls, `ebp` used as a general register and late register saves).
  Unused or dead arguments don't count. A callee our source declares with `...` is compared over the
  words each call site passes, also past an `equiv-conv`'s listed slots.
- At a call to an `equiv-conv` callee, the stack words our declaration passes are that call's, even when
  the real callee reads none of them (a register argument we pass on the stack, cleaned up later): they
  aren't counted as arguments of the next call.
- Functions of our own object run in place: the words pushed for them are their arguments, and their
  prologue's register saves aren't arguments of the calls they make.
- **Callees that never return** (`longjmp`, Lua's `luaD_throw`, error helpers: no `ret` reachable, every
  path ends in `int3`, a call followed by `int3`, another such callee, or an indirect jump after reloading
  `esp`) end the run on both sides; it is compared up to and including that call, without return value or
  registers.
- A jump through a pointer read from memory is a tail call (unless it lands in the function's own body),
  in both runs. A tail jump to a CRT helper (`jmp _ftol`) runs the helper for real, so its operand shows in
  the return value. A tail call out of an `equiv-conv` function compares as many words as the original
  passes on (each side passes on its own incoming stack words).
- Callee side effects: after each stub the memory epoch advances, and every non-code page is remapped with
  fresh deterministic contents. That models "the callee may change anything", and it catches code that
  caches a value across a call when the original re-reads it.

**Compared per input**
- The call trace: targets in order; the argument words; and the callee's register inputs, i.e.
  `ecx`/`edx`/`eax` when the callee reads them before writing (so `this`, and `ecx` for every virtual
  call).
- Locals passed by pointer, on the stack or in a register: exactly `sizeof(*param)` bytes for a class
  type, taken from our callee declaration (a `sizeof` probe compile). A scalar or unknown pointer may
  point at an array, so it is compared over the words the function filled in, up to the next local whose
  address the function takes (4 KB at most). Only bytes the original wrote count, so an uninitialised
  out-parameter is not compared, nor a copied uninitialised word. A word that points to another local on
  both sides (`desc.format = &fmt`) isn't compared as a value; the local it points to is compared in turn
  (two levels deep).
- Memory writes per call segment: the final byte values that differ from the segment's initial state.
  The stack is excluded.
- The return value by type: `al`, `ax`, `eax`, `edx:eax` or `st0`. A function we declare `void` that is
  reached only through a vtable or a pointer (no direct call sites) still has `eax` compared when the
  original leaves a meaningful value there: a callee's result nothing overwrote, or a write to `eax` the
  function never reads back (a `dec eax; jne` of a switch's dec chain is read, through the flags) (`left 0x7 in eax, expected 0xa8: ours is void, but the original returns a
  value there`).
- Bytes of `eax` that last came from `fnstsw ax` (a float branch's status word, `fnstsw ax; test ah, 0x41;
  ...; mov al, 1; ret`) aren't compared: no source produces them. What was written after them (`al`) is.
- The x87 stack depth, `ebx/esi/edi/ebp` and `esp` after return.
- An argument pushed from a register whose last write set only its low byte(s) (`setcc al; push eax`, a
  `bool`) compares on those bytes only. A register argument of an `equiv-conv` callee compares on the bits
  the real callee reads before overwriting it (a byte flag in `cl` over leftover high bytes: `test cl, cl`).
- An argument word that holds, on each side, the return address of the same earlier call (stale padding of
  a struct passed by value) is equal: each image has its own addresses.
- Values that point into the stack compare as "a stack address". Floats stored by `fst`/`fstp` (on either
  side) and float arguments (stored by `fstp` on either side, a word copied with `push` on the other)
  compare with relative tolerance 1e-5; a word that is the same normal float
  but for its last bit (rounded once more on one side, then copied through a register) is equal too.

An input on which either side stores into code (our object at `0x60000000`, or the original's `.text`,
through a fuzzed pointer) is inconclusive: the store rewrites one side's instructions only (`statuses`
counts them as `code_write`).

**Wild control flow** (`statuses`: `wild`). A run stops (`fault:wild_jump`) where control leaves the
function's own code: a return through a return address that a fuzzed pointer or an overflowed stack buffer
overwrote, or a call through a fuzzed function pointer into junk. Before, the junk ran on, with effects that
depended on each side's frame layout. An indirect call through a fuzzed pointer that lands *inside* the
function under test (`fault:wild_call`) is caught too: an unaligned read across a heap pointer and a small
int spells `0x0013400c`, and the original ran its own code from there while ours, whose code is elsewhere,
stubbed a call (or the other way round, for a pointer into our object). An input is inconclusive when the
original goes wild, or ours makes such a call; ours going wild where the original returns is still a
failure. An input on which both sides fault, with the same calls and writes up to there and only the fault
kinds differing (`statuses`: `both_fault`), is inconclusive too. When more than 10% of the completed count
is set aside this way, the run isn't `promotable`: a model of some call is probably off (a stack that
drifts until the final `ret`), and that hides the code. A call through `[0xffffffff]` reads its target
wrapping around to address 0, as the CPU does. An input on which the original doesn't return (step limit 50k, or the 1000-page limit) is inconclusive. If
the first 4 inputs all run out of steps, the rest get 1M steps (and 3x the time budget): long but
deterministic code such as string building. If 6 of the first 8 still run out, the budget goes back down and loop repair
takes over (rb-tree inserts on fuzzed, cyclic trees: 3 completed inputs became 84). One where the original faults is compared up to the fault, but
not counted as a pass, and its branches don't count as covered. While fewer than 8 inputs have completed,
faulting inputs don't stop the search (up to 192 of them). The step budget isn't raised when the early
timeouts come from a `rep` string instruction with an absurd (fuzzed) count or from a loop that a stubbed
callee keeps going (hundreds of calls). Then input 0 is run once with 8M steps: if it returns, the code is long but finite (100 objects with 66 stub calls each, a 2048-slot scan)
and the rest get twice the steps it took (at least 1M) and 3x the time budget; and an input where such a fill or copy got through in the original
but our semantic copy hit the page limit is inconclusive.

**Return type** comes from our mangled name. For a C name it is inferred from the original's call sites.
If ours returns `void` but the original's direct callers read `eax` (or `st0`) after the call, the return
value is compared anyway, and `return_note` says so.

**Coverage** counts taken/not-taken for every conditional branch (except dead sides: a jcc right
after `cmp r, r`/`sub r, r`/`xor r, r` that nothing else jumps to; the zero side of `lea ecx, [esi + 4]; ...;
test ecx, ecx` where esi is a pointer, the null check of `&this->member`; sides a source declares with
`// equiv-dead: +0x63 taken, +0x70 not taken: why` after hand review, listed in `coverage.declared_dead`;
and everything only a dead side reaches), 0/1 for every `setcc`, and every
jump-table case of the original (a table is read up to its first non-code word, and ends where the
next table of the function starts, so two back-to-back switches keep their own cases). It comes only from inputs that ran to completion (not from faults).
Directed inputs can also patch a word a stub filled through an out-parameter, when the original compares
it. `level3.coverage.complete` is false when some edge never ran, and the
uncovered edges are listed.

## Report (JSON)

```jsonc
{
  "addr": "0x001b77e0", "src": "...", "target": "FUN_001b77e0", "symbol": "?Run@Target@@QAEXXZ",
  "status": "equivalent", "level": 3, "byte_identical": true, "time": 6.0,
  "level1": {"ok": true},
  "level2": {"ok": true, "issues": [], "warnings": [],       // missing_call, extra_data_ref, ...
             "mapping": {"?Fn@Mgr@@QAEXXZ": {"addr": "0x002088a0", "how": "paired"}},
             "conflicts": []},
  "signature": {"cc": "thiscall", "this": true, "ret": "void", "params": [], "param_types": []},
  "level3": {"ok": true, "inputs_run": 68, "inputs_inconclusive": 0, "inputs_faulted": 0, "inputs_failed": 0,
             "inputs_directed": 4, "statuses": {"ret": 68},
             "coverage": {"edges_total": 16, "edges_covered": 16, "complete": true, "uncovered": []},
             "mismatches": [{"input": 4, "diffs": ["call #3 went to 0x00232660 instead of 0x0008d690"]}]}
}
```

Mismatch strings are written for a model to act on. Examples:

- `write to this+0x40 before call #2 was 0x3f000000 (0.5f), expected 0x3f800000 (1f)`
- `call #3 to 0x0008d690: argument 1 is 0x25, expected 0x24`
- `call #1 to 0x00337700: the local passed as argument 1 differs at +0x8`
- `missing call #2 to 0x00232660`
- `returned 0x0, expected 0x1`

## Validation

Latest run (2026-10-14, checker round 7; details in [tasks/equiv-round7.md](tasks/equiv-round7.md)):
`regress.py` 99/99; selftest 300/300; mutation suite identical to round 6 on the same 120 functions; merged
source tree, first 300 `equivalent/` functions on their tree objects: 300/300 (round 6: 281); `equivalent/`
random 200 at 3000 inputs: 199, the other (0x00215790) a newly reached seed round 6 fails too (`ecx` at an
indirect cdecl call). 20 logged sources newly promotable (21 with a one-line fix to 0x001d2190).

Previous run (2026-10-14, checker round 6; details in [tasks/equiv-round6.md](tasks/equiv-round6.md)):
`regress.py` 76/76; selftest 300/300; mutation suite identical to round 5 on the same 120 functions (362
caught, 10 false passes, 0 false failures). `equivalent/` in random order, 824 of 3,348 files: the first 200
are all equivalent. Four newly fail. Two show real differences on seeds round 5 never ran (0x0022f960,
0x0001c430). 0x0028e160 is a compiler temporary in a reused argument slot. 0x00336dd0 fails under round 5
too.

Previous run (2026-10-13, checker round 5; details in [tasks/equiv-round5.md](tasks/equiv-round5.md)):
`regress.py` 60/60; selftest 300/300 (both standing failures fixed); mutation suite 363 caught, 5 false passes
(also false under round 4), 0 false failures; `equivalent/` random 200 all equivalent, and of ~1,200 files the
changes could touch, one newly fails (0x00195560: its local is 4 bytes smaller than the callee's object).

Previous run (2026-10-12, checker round 3; samples drawn from the current `matches/`):

- Selftest: 298/300 equivalent; with `/O1` 296/300 and with `/Oy-` 297/300. Every failure (0x003388d0,
  0x00312db0, and under other flags 0x0029b3a0, 0x00327c70) fails the same way with the previous checker
  (the match sources changed or don't bind a string).
- Mutation suite (120 functions): 325 caught, 19 false passes, 1 false fail (a commute mutant). The
  previous checker on the same mutants: 321 caught, 23 false passes, the same false fail; the 4 differences
  are all newly caught mutants.
- `equivalent/` re-checked: 980 of 983 still equivalent. The 3 that fail now reach paths the previous
  checker never covered: a callee declared `ret 8` that really has a plain `ret` (0x00277810), and two
  argument values on directed inputs (0x00332310, 0x00355e2d).
- `build/farm/equiv-lowcov/` (functions that passed with thin coverage): 24 of the original 56 now pass
  with at least 75% branch coverage (7 before), 32 of the current 75.
- `tests/equiv/regress.py`: 36/36.

The harnesses:

- `tests/equiv/selftest.py`: a size-stratified sample of 300 matches must be `equivalent` against itself.
  `--flags /O1` or `--flags /Oy-` recompiles the same sources with other options: different bytes (other
  register allocation, frames, inlining and CRT calls), same behaviour. Those must pass too. Symbols are
  bound with the exact match's ground truth.
- `tests/equiv/mutate.py`: for each function, one mutant per operator must `fail`. The operators swap
  non-commutative operands, change a literal, drop a call, shift a field offset, and flip a comparison. A
  commutative swap must pass. Mutants that don't compile, or that give identical bytes, are excluded.
  Hand-checked semantically equivalent mutants are listed in `EQUIVALENT_MUTANTS`. Symbols are bound
  with the unmutated match's mapping.
- `tests/equiv/test_equiv.py`: quick unit and end-to-end tests.
- `tests/equiv/regress.py`: sources a checker bug once got wrong (`tests/equiv/cases/`), each with the
  status it must get and the mismatch that shows why.

## Trace replay (`tools/trace_capture.py`, `tools/equiv_replay.py`)

Fuzzing can't reach some paths, and its stubs return made-up values. Trace replay runs both sides on game
states recorded once from the real game, and replays them on every build.

```sh
PY=build/venv/bin/python
$PY tools/trace_capture.py --session s2 --minutes 30 --per-func 30    # record (one xemu, ~30 min)
$PY tools/equiv_replay.py --session build/traces/s2 --equivalent      # replay every captured equivalent/
$PY tools/equiv_replay.py --src OLD.cpp 0xADDR                        # any source against the recording
$PY tools/equiv_replay.py --matches all                               # control: matches must all agree
$PY tools/equiv_confidence.py                                         # -> build/equiv-confidence.json
$PY tools/patch_xbe.py --matches all --equivalent --classes identical,local,equivalent --tier-min 3 ...
$PY tools/bisect_hybrid.py ...      # orders candidates by tier, lowest first, when the file exists
```

Captures live in `build/traces/SESSION/trace.sqlite`. They hold game memory, so never commit them.

**Capture.**
- The game is the original XBE plus only the test hooks: fixed frame time, constant seed, `skip-intro`,
  `no-fmv`.
- Input comes from `tests/replays/capture-gameplay.json`, keyed by pad polls (hooks flag `pollkey`;
  after the new-game load the frame counter races, while polls stay at about one per frame). The script
  goes title → New Game → Normal, taps A through the opening, then loops run / turn / X combo / Y /
  jump / grab in the junkyard tutorial.
- xemu runs with `-S -gdb` and `-snapshot`, with the copied config.
- A breakpoint on a target's entry starts a **co-simulation**. The original bytes run in Unicorn with
  equiv.py's `Run`:
  - registers, the stack window and the game's stack contents come from the game;
  - every page touched in a memory epoch is read from the paused game and recorded. Code pages
    (`.text`, BINK) come from the XBE; `.rdata` comes from the game, because the kernel thunks are
    patched at load.
- At each call Unicorn would stub, the game runs the callee: a breakpoint on the return address, checked
  against esp and the callee-saved registers. Recorded per call:
  - eax/edx/ecx;
  - ST(0);
  - the game's frame afterwards, plus the bytes the callee changed in it, located relative to the
    pointer argument they lie behind;
  - the bytes the callee's static write extent covers.

  Pages touched later are re-read; that is the next epoch.
- Unicorn's entry esp gets the game's low 12 bits, so `and esp, -8` lays frames out alike.
- **Self-check:** at the end the game runs to the return address. Unicorn's esp, eax/edx, ST(0) and the
  memory written since the last call must equal the game's. A callee that changes frame bytes the
  function wrote itself, with no pointer reaching them, aborts the capture. Failed captures are kept but
  never replayed.
- QEMU slows down with every breakpoint set: 800 never-hit ones make it 6x slower. So at most 96
  functions are armed at a time (`--window`):
  - a queue rotates through the targets;
  - a function idle for 20 s, or captured 5 times in a row, makes room;
  - functions in `hybrid/exclude.txt` and `build/farm/equiv-demoted/` stay armed.
- A target hit inside a callee is captured too, nested up to depth 3 with its own Unicorn thread.
  Otherwise it is parked until the outer capture ends.

**Replay.**
- `equiv.verify(..., level3_fn=...)` does levels 1–2 and the binding as usual. The replay then runs the
  original and ours on each recorded call with `equiv_replay.TraceRun`, a `Run` whose stub results are the
  recorded ones, in order.
- Both sides start with `STACK_FILL` stacks.
- Callee frame writes are placed relative to the pointer the call passed. The original's run decides each
  placement:
  - a write into the incoming argument slots goes to the same slot in ours, unless the original passed a
    pointer into its argument slots (a dead parameter reused as a local) and ours a local of its own:
    then it goes behind ours;
  - a write the capture keyed to a register (`ecx` left over from `mov ecx, edi`) that the call also
    passes as a stack argument is placed through that argument (ours may not have it in the register);
  - a write the original can't place is skipped on both sides.
- A real callee write that starts inside our local and runs past its end fails, as equiv.py's
  undersized-local check does ("writes 0x40 bytes through ecx ... ours has only 0x20").
- The comparison is `compare_runs`, the level-3 rules.
- The original's replay must reproduce the recorded outcome: status, call targets, eax/edx and the final
  memory writes. Otherwise that call is counted `incomplete`, not compared.
- Statuses per function:
  - `agreed`;
  - `mismatch` (first diff given);
  - `no_replay` (captured, but nothing replayable);
  - `not_reached`;
  - `unsupported` (the function itself has `equiv-conv`).

**Confidence tiers** (`tools/equiv_confidence.py`):

| Tier | Meaning |
|---|---|
| 0 | replay mismatch, or listed in `hybrid/exclude.txt` |
| 1 | fuzz only (not reached, or nothing replayable) |
| 2 | replay agreed on 1–2 calls |
| 3 | replay agreed on 3 or more calls |

Fuzz evidence comes from `build/equiv/fuzz-cache.jsonl` (`--fuzz` fills it), or else from the source's
`// STATUS:` line. `patch_xbe.py`/`hybrid_test.py`/`bisect_hybrid.py` take `--confidence FILE` and
`--tier-min N`. The bisect orders candidates by tier, lowest first, so the first half it tries holds the
least-trusted functions.

**Validation (2026-10-12, session `s2`).**
- **Capture:** 31 min unattended, boot → title → New Game → opening → junkyard tutorial gameplay; 203 MB.
  Of 1,648 targets in equivalent/, 439 were reached and 429 captured, for 7,675 calls; 88 calls (1.1%)
  failed their self-check.
- **Replay** of every captured equivalent, at most 30 calls each, took about 75 min on 3 jobs:
  - 7,205 calls replayed, 137 incomplete;
  - 396 functions agree, 14 mismatch, 5 had nothing replayable, 14 are unsupported (`equiv-conv`).
- **`hybrid/exclude.txt`:** the five sources as they were when excluded (9429e0a5) replay as mismatches
  for 4 of 5, each with the cause the bisect found:
  - 0x241390: a ctor writes 0x40 bytes into a 0x20-byte local;
  - 0x324e00: QueryPerformanceFrequency writes 8 bytes into 4;
  - 0x26ce10: void, but the original returns the allocation in eax;
  - 0x259610: a local passed to 0x3c9ea7 differs. This one was previously unexplained.
  - 0x329f70 (the menu stall) agrees on 30 calls.

  The current, fixed sources of all five agree.
- **`build/farm/equiv-demoted/`:** the 7 captured ones agree. Their known faults are on paths the
  session never ran: 0x277810's bad callee 0x272bc0 and 0x332310's 0x329f20 were never called.
- **False failures:** 0 among 29 captured matches and 0 among the 20 byte-identical equivalents.
- **Bugs fuzzing missed:** among the 14 mismatches, 0x2a9920 (the real callee 0x28aa20 writes a 16-byte
  object into a 12-byte local), 0x2b8b30 (0x35 bytes into 0x30) and 0x293ef0 (a callee declared to pop
  4 bytes that pops 8).
- **Triage of the other 11 (round 4).** Checker/replay artefacts, now fixed: 0x13ab50, 0x25d7f0, 0x2952e0
  (`xor edi, edi; push edi` taken for a register save when `edi` was 0 on entry), 0x201f20 (a callee
  write into a reused parameter slot in the original, a local in ours), 0x256420, 0x321310, 0x324270 (a
  write keyed to a leftover `ecx` that ours doesn't hold). Source bugs: 0x2b9ce0 (two locals set before
  a call that the original sets after it; fixed), 0x228da0 (ours divides by the unrounded 80-bit sum,
  the original by the stored float: 1 ulp; not fixed). Not resolved: 0x308fe0 (compares uninitialised
  bytes of a local that the call-0 delta fills on one side only), 0x201850 (`ebp` at return; most of
  its calls are incomplete).

### Routine replay after promotion (`tools/equiv_replay_fn.py`)

Replaying a whole session costs 30-75 minutes, but replaying given functions only needs the captures already
on disk. Measured (20 random captured functions, 8 local sessions, 3 jobs, Mac): 11 s total, about 0.5 s per
function; 70% of that is setup (compiling our source and loading the original), the rest is the recorded calls
(about 20 ms each; a few heavy functions take 5-15 s, bounded by `--budget`). So it replays every session in
one pass per function: ours is compiled once, then each session's calls run through it, at most `--max-calls`
(default 30, spread evenly over the recording, so rare late mismatches are still sampled) per session.

Sessions: `build/traces/*/trace.sqlite` here (s1, s2, t1, t2, x-*) and on mac1 (m-combat, m-menus, m-roam;
`--remote mac1` syncs `tools/*.py` and the function sources there, replays in parallel and pulls the result
back as `build/traces/replay-fn-mac1.json`). `--index` lists what each session captured.

Not every function can be replayed: only those a session reached. About 43% of `equivalent/` was captured
in some session, but functions promoted since the last captures are 0% (the last two batches: 0 of 31). They print
`not-captured` and are appended to `build/traces/capture-wanted.txt`: those need to go into the target list of the
next capture; no replay can help.

After each promotion batch (commit):

```sh
PY=build/venv/bin/python
$PY tools/equiv_replay_fn.py --since HEAD~1 --changed --remote mac1   # ~10-30 s: the batch + anything stale
$PY tools/equiv_confidence.py                                         # merges the results into the tiers (~5 s)
```

- `--since REV` adds the functions `equivalent/` gained or changed in REV..HEAD (use the batch's parent commit
  if the batch was several commits); `--functions 0xA,0xB` or `@file` names them directly; `--sessions s2,x-menus`
  limits sessions.
- `--changed` adds every `equivalent/` source changed since its last replay: a per-function record with a
  different source hash, or a session result written before the source's last commit. Run it on its own
  (`--changed --remote mac1`) after fixes or re-promotions. `tools/equiv_confidence.py` drops the same stale results
  (`replay_stale` in `build/equiv-confidence.json`), so a function is never trusted on a replay of an older source.
- Exit status 1 and a `mismatch` line (with the session, call and first difference) mean the new equivalent
  disagrees with the real game: demote it as for a fuzz failure.
- `--src-dir DIR` replays sources from DIR first (demoted or experimental ones); `--out` redirects the result file.
- A full re-check of everything captured (`--functions @list` of all `equivalent/`) takes about 10 minutes for the local sessions and over 30 on a loaded mac1 (its sessions are big);
  a batch of 20 takes 10-30 s on either.
  Whole-session replays (`equiv_replay.py --session ... --equivalent`) are only needed after a new capture.
- mac1 is shared: the remote side runs niced with at most 3 jobs.

Evidence per (function, session) is merged newest-first by `tools/equiv_confidence.py`, so tiers stay current
without re-running whole sessions. Results live in `build/traces/` (never committed).

**Limits.**
- Coverage is what one scripted session reaches: boot, front end, the opening and the junkyard tutorial.
- Writes a callee makes into the caller's frame through a pointer stored earlier (not passed in that
  call) can't be placed in our frame. Such calls go `incomplete` when the original depends on them.
- Uninitialised stack is `STACK_FILL` on both sides in replay, but the game's own bytes at capture.
- Threads and DMA writing memory during a capture show up as failed self-checks (about 1%).
- `equiv-conv` functions aren't replayed.

## Limits

- **Loops kept going by callees.** A loop that ends only through a callee's side effect (a teardown
  `while (head) remove(head)` over a global) still runs out of steps: 0x0024ad20 stays unsupported. (A
  fixed 2048-slot loop with several calls per slot now gets the long step budget: 0x001dec10 completes.)

- **Coverage, not proof.** A pass means no difference on the inputs run, so check `coverage.complete`.
  Code behind conditions the fuzzer can't satisfy (deep pointer chains, specific global state, values
  computed from several loads) stays unverified. Branch coverage is also not path coverage: a difference
  that needs a combination of conditions can survive full branch coverage.
- **Callees are opaque.** A stub's out-parameter values are arbitrary, not what the real callee would
  write. How far a callee writes is a static under-approximation: loops that advance the pointer, string
  instructions and indirect calls inside the callee aren't followed.
- **Argument counts** for calls through fuzzed pointers come from tracked pushes in the original, and are
  reused by our run call by call. A rare mix of cdecl and thiscall indirect calls sharing one deferred
  cleanup can still be miscounted. That shows up as a false failure, not a pass.
- **Data-dependent loops:** a difference that only shows with particular data, such as a byte copy whose
  source and destination happen to hold equal bytes, can pass even with full branch coverage. Two of the
  final mutants are like this.
- **Inline-vs-call differences** of game functions fail. If the original calls `FUN_x`, our code must
  call it too: declare it `extern` rather than defining a body. Only CRT routines are exempt.
- **Unspecified evaluation order:** MSVC may evaluate call arguments in a different order under other
  flags (seen once with `/O1`). The call order differs, so it fails; arguably correctly, since the binary
  differs.
- **Not modelled:** exceptions (SEH frames work, but nothing throws), threads, timing, hardware/MMIO,
  self-modifying code, `in`/`out`. LTCG register-argument functions work when registers carry the
  arguments, because all registers start as valid pointers. Callee-saved registers are never compared as
  callee inputs.
- **x87:** float results compare with tolerance, and integer results of `fistp` compare exactly.
- **Function bounds** come from `build/functions.csv`. Code past the listed size is still followed, as a
  chunk, but some sizes are wrong: 0x001bb0b0 is listed at 320 bytes but returns at +0x47d, so its
  packet showed only part of the function.
