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
returns the report dict. `seeds=[...]` (or `EQUIV_SEEDS=1,2` in the environment, whatever `--inputs` says) runs only those random
inputs: a regression case for the one input in thousands that showed a bug. The exit status is 0 only for `equivalent`. A typical function takes 1–5 s
(compile included); loops that run long on fuzzed inputs can take up to the 120 s level-3 budget. The
budget is CPU time, so a loaded machine takes longer but gets the same result. `--time-budget S` changes it (slow
functions need more to reach the 50 completed inputs `promotable` asks for). `--inputs N` raises the
input cap to at least N.

## Levels

| Level | Check | Fails on |
|---|---|---|
| 1 | compiles with MSVC 7.1 (`compare.py` flags; `--clang` adds a host-clang syntax check, warning only) | compile errors |
| 2 | same references: callees, globals, vftables, strings, float constants (in memory and in immediates), the initializers of globals the source defines | a missing or extra callee or global, an unresolvable symbol, a float constant a few ulps off the original's, a defined global whose initial bytes aren't the original's |
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

(round 13, `fconst`) A float constant of ours that the original doesn't have is a level-2 **failure**
(`float_constant_differs`), not a warning, when the original reads a constant we don't share that is within
1e-4 of it (relative) without being the same value as the loads read it (`0.0174533f` = 0x3c8efa39 where the
original has pi/180 = 0x3c8efa35; `57.2958f` for 0x42652ee0; `0.00392157f * 255.0f` folded to 1.0000003 where
the original has 1.0). Level 3's float tolerance passes such a source on every input, and a byte match masks the
constant's bits; the native build would carry the wrong value. A double constant of exactly the float's value is
not a difference. Write the original's value with 9 significant digits (`0.0174532924f`).

`tools/lint_floats.py` is the static companion (all of `matches/` and `equivalent/`, no inputs needed): it takes the
constants each original function loads (float/double memory operands in the data sections, immediates that are float
bit patterns) and lists every float literal in the source that is within 1e-3 of one without being bit-exact, with the
spelling that is (`build/cl2/floats.json`). `fconst` only sees a function when its checker run happens; `matches/`
sources are never re-run, and a byte match masks the constant (the compare is on code). It never rewrites a source.

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
(`extern "C" void __fastcall __security_check_cookie(unsigned int)`). Better (round 13): `// cl-flags: /GS` (the
game was built with it) and a plain `char buf[N]` local; MSVC 7.1 then emits the cookie load and check itself
(0x000c6d90 matches 33/34 that way). `compare.py` passes `/GS` and `/GS-` on; `tools/gen_tree.py` keeps its own
copy of the allowed flags.

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
  while fewer than 50 have completed, or while at most 20% of them were inconclusive, or while branch
  coverage is under the 75% promotion bar (then directed ones again).
- **Small loop counts.** The loads that fed a runaway loop's bound (`mov ecx, [eax-4]` ... `dec ebx; jne`, also
  through a stack copy) are remembered. A later input that runs away gets a discovery run of the original in
  which those loads read small counts (1-4, where the word was larger), then runs again with those counts in
  its memory on both sides; a run that hangs in the next loop learns that one too (56 copy loops in a row).
  Once small counts get inputs through and most inputs run away, three in four inputs (seven in eight when
  nine in ten run away) start that way; the 8M-step probe is skipped when small counts already got input 0
  through. It stops when it costs a quarter of the time budget without a completed input. Directed inputs
  that run away behind the side they opened get small counts first too. Bounds that are a difference
  (`(v->end - v->begin) >> 2`, `nfixargs - (L->top - base) / 8`) are planted at the `sub`: the end word (a
  plain load, or a stack argument) becomes the begin word plus what the transforms after the sub turn into a
  count of 1-4, in every memory epoch it is read in, relative to that epoch's begin (a vector a stub returned,
  re-read after every call in the loop); otherwise the begin word moves. Runaway list and tree walks (`cmp eax,
  ecx` with `ecx = &tree.nil`, `test ebp, ebp` on a link) get the sentinel planted into the link they just
  loaded after one to three links, in every epoch. A loop that still runs away behind counted loops whose
  bound no load feeds (a pair loop over the points 80 counted lists collected) gets one more round with counts
  of 0 or 1 at every count load, and once that has got two inputs through, small counts start that way. (Round 11.)
  One difference plant in four is 5-12 elements rather than 1-4. A stub's float result that bounds a runaway loop
  through `__ftol2` (`end = (int)(pow(x, e) * n)`, a new call in each outer round) is drawn in [0, 1] for that callee
  in three inputs in four. Many walks at one compare (127 circular bins, each with its own sentinel, over nodes the
  bins share; heads in the zero page when the object pointer is null-ish) plant no link some other walk already loaded,
  end a walk at the link before one loaded before, and empty a walk at its top test (the same compare before the loop,
  `cmp eax, edx; je out`) when its first node's link was loaded before; a node linked to itself counts as a walk. A
  run that writes as it runs away (`do { top->tt = 0; top++; } while (--n)`, out of pages rather than steps)
  counts as running away here. A discovery run that returned while the input with its plants didn't (fuzzed
  nodes alias, so a planted link was also read as a key) gets up to two more discovery runs from its plants.
- **Stack-array indices from stub fills.** A word a stub filled (an out-parameter) that the original then uses
  as the index of an indexed access to its own frame (`mov eax, [esp+0xa0]; shl eax, 4; fstp [esp+eax+0x20]`)
  is drawn as 0 or 1 in every later input (a directed input's own value for it wins). A fuzzed -1 stores below
  the array, onto whatever each frame layout keeps there, so no frame layout other than the original's could
  agree on it.
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
  - a char minus a constant (`movsx eax, sig[i]; add eax, -0x56; cmp eax, 0x20`) and a switch through a byte
    table on a loaded char (one char per case) join the alphabet of planted strings; strings are planted in
    the epoch the char was read and every later one (a loop that calls something per char), and string
    plants go round robin over the buffers and literal sites queued;
  - a register set to a constant right at the start of a branch side (`cmp eax, [g]; jne L; mov bl, 1; ...;
    L: xor bl, bl`) or by a setcc, tested later with no source of its own (`test bl, bl; je`): steered
    through the compare that decided it, after the direct patches are used up (a few tries per deciding
    compare unless one helps). A directed input that reaches a compare with a missing side in a new way
    (another source, another deciding compare) keeps its observation even past the first six, so a flag two
    conditions feed (`eax == [g]` then `edx == [g+4]`) is steered one condition after the other;
  - two inputs a run found equal (`cmp eax, [ebx+0xc]; jne` on a stub result) are moved together when a later
    compare of one of them is patched (`add eax, -8; cmp eax, 4; ja`: a switch on the same value);
  - a byte out-parameter the function set itself (`char hit = 0; vt->query(&hit)`), which random inputs
    leave alone, and a word nobody wrote behind a local passed by pointer past the 16 bytes filled by default
    (`read(&hdr, 0x1f, 4, 1)`; the fourCC at +0x48): a directed input has the stub write it, on both sides;
  - the first round of a compare that compared constants (a default, `mov al, 0x76` past a string's end) is
    replaced by a later round that compared input data;
  - x87 compares (`fcom`/`fcomp` + `fnstsw`/`test ah`, `fcomi`), against memory or a stubbed callee's
    float result, a float a stub filled in through a pointer, a loaded value plus, minus or times a
    constant (`fld [g]; fadd [k]; fcomp [0.95]`: inverted), or a masked argument word (`and eax,
    0x7fffffff`: fabs, ties planted). When the compared value is computed (`sqrt` of the difference of two stub-filled vectors,
    a scaled and clamped result) there is no single word to invert: the input is re-run with every stub
    float (float results and out-parameter fills) set alike, to 0, 1000 and 1 (equal vectors give distance
    0); when it is computed from floats in memory only (`|sqrt(x*x + y*y + z*z) - 1| < eps` on a matrix's
    rows), with those floats planted as an identity matrix, all 1 and all 0. A computed operand's value is
    read from the x87 registers, so the other side can still be steered past it (a stub's float against
    `fld [k]; fmul [4.0]`);
  - a float's source survives `fst`/`fstp` to memory and the reload, register-form arithmetic with a value
    known at that point (`fld [pi/2]; fsubr st(1)`; decided by opcode bytes), `fabs`, a fabs mask applied in
    memory (`and dword [esp+4], 0x7fffffff`, also with the mask in a register), a computed value plus or
    times a float in memory (`fmul st(1); fadd [ecx+0x218]`: steered through the memory word) and `fld st(i)`.
    The transforms are inverted, with halfway and one-and-a-half-times targets for `|x - c| < eps`. A float
    converted by `__ftol2` gives the integer compares after it (`cmp eax, 8; jge`) that float's source, and a
    stub whose result goes straight into `__ftol2` returns a float (it converted an empty x87 stack);
  - a fixed-address word in the image is planted only when our code reads it too (a float constant the
    original keeps in `.data` is a literal in ours: planting it changed the original alone);
  - a loop's bound (patched for one or two more rounds, in every memory epoch when it is re-read after a
    call).

  - (round 11) instruction words: a word loaded from an array by index (`mov eax, [edx + eax*4]`) that at least three
    compares test through different field extractions (`and 0x3f`, `shr 24`, `shr 6; and 0x3ffff`), one of them a
    switch or four in all, is an interpreter's instruction stream. Directed inputs plant runs of 1-8 words from the
    first word a completed input read there, in every memory epoch, each made of field values the compares name
    (every case of the switch, up to a small bound, around a constant, below a value from memory). A word another
    compare of that input read before the loop keeps the field value it had (`code[sizecode - 1] & 0x3f == RETURN`), a
    loop bound in a stack argument below the number of words is raised to it, and half of them have every stub return
    a normal value or 1 (a checker callee that returns 0 ends the loop at the first word). At most 30% of the time
    budget;
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
  checks of a base-class conversion, not value tests). Exact float ties are planted only where the planted
  value comes back as exactly the other side's: against a plain loaded value, or through `fabs`/`fchs` and
  constant arithmetic checked forward in the loaded precision (round 12); against a value computed in 80 bits
  that no loaded float equals, never.
- (round 12, ties) Ties. Random values never tie, and directed inputs only go after sides not yet taken, so
  `fabs(m[0][0]) > eps` against `>=` (or `cmp eax, [ebx+0xc]; jl` against `jle`) differed only on inputs that never
  ran. After the first directed phase, one input per compare (at most 48 a function) makes an input operand
  equal to the other one (`inputs_tie`).
- (round 13, objptr) Objects behind loaded pointers. A field read `[reg + d]` through a pointer the code loaded as
  is from an input (memory, a stub's result or fill, a stack argument), where the word read equals a neighbouring
  word (the null page, a run of zeros), can't show a wrong field offset: fx15's 0x002e22c0 read `D->f18` at +0x1c,
  D a constructor stub's field in the null page on every input that got there. Up to two directed inputs per such
  pointer (keyed by where it was loaded; at most 24 a function, after the tie inputs) plants the address of an object whose
  words all differ (word i = 0x101 * (i + 1) + 0x10000 * depth: small, so counts stay small, and the bytes of a
  word's low half differ too) into the pointer's source; a pointer loaded from that object in turn gets the next
  of four such objects (`inputs_objptr`, labels `N+obj`). Only inputs change; both sides read the same object.
- (round 14) Four small changes found on the full re-check's three leftovers, each switchable with `EQUIV_OFF=name`.
  `rmwundo`: Unicorn can deliver the code hook of a read-modify-write instruction a second time after its store went
  through (0x0025b970's `inc dword [3 + 0x24]`, an unaligned dword, in our code only), applying it twice; the old
  bytes of such a store are put back when the same address is delivered again. `staticcount`: a `sub r, x; sar/shr r,
  k` (a pointer difference scaled to an element count) is a loop bound read from the input; the sites are known from
  the code, so once two inputs have run away the small-count rounds start every input (three in four) with a small
  count there, without waiting for a runaway loop to point at it (0x002a4e40: 8 -> 163 inputs, 1 -> 22 of 24 edges).
  `walkaddr`: a walk waiting for `&tree.nil` computed by `lea` from a fuzzed pointer is a walk although the address is
  not in the heap range. `addrcount`: an address computed by `lea` from a pointer is never a "count" to plant small
  (planting 2 into the owner pointer made every walk start in the zero page; 0x00242da0: 17 -> 50 inputs, 2 -> 30 of
  30 edges).
- (round 15, cl3) Five gaps native10 and fx20 found, each switchable with `EQUIV_OFF=name`:
  - `caseidx`: a jump table's cases are its indices, not its targets. Coverage counts every index the bounds check
    before the `jmp [r*4 + tab]` lets through (`cmp esi, 0x14; ja`: 21), each index an edge `(jmp, ("idx", k))`, and
    directed inputs plant the missing indices (through the switch value's source and transforms, as before). Two
    indices that share a target in the original are two cases: native10's stop 20 was 0x0028aea0 mapping 0x12110e to
    the default and 0x121111 to another group, `equivalent` at 19,784 inputs with "12/12" coverage (now 21 index
    edges, and the old source fails).
  - `argcall`: chained calls. `X(a)->M()` and `X()->M(a)` compile to the same bytes when X pops nothing and M pops a
    word (`v44(t)->setFont()` for `v44()->setFont(t)`); every word was compared, but not which call it belongs to. At a
    direct call to a callee that pops its words (`ret N`, N > 0), our declaration must pop N too; otherwise every
    input fails (`call #3 to 0x0027af90: our declaration passes it 8 bytes of stack arguments, but it takes 4 (ret 4):
    the other 4 bytes belong to another call`). Natively the other call gets them. A callee with a plain `ret` (caller
    pops) keeps the old rule (a declaration mismatch only explains a difference): `this` in ecx with caller-popped
    words can't be declared in C++. Not covered: two chained virtual calls (no declaration is visible at either).
  - `initbytes` (level 2): a global our source *defines* (`const float rads = 0.0174533f;`, `float g = -1.0f;`) that
    binds to an original address is read at the original's address in level 3, and a byte match masks the
    relocation, so its initializer was never compared. Its bytes (relocations inside it masked, `.bss` as zeros)
    must be the original's there: `initializer_differs` (`ours`/`original` hex, and floats for a 4-byte item).
    `tools/verify_relocs.py` reports the same for matches (`initializer_mismatch`, a hard issue), and
    `verify_relocs.py --initializers OUT` sweeps all of `matches/` and `equivalent/` (`build/cl3/initializers.json`).
  - `immfloat` (level 2): float bit patterns in `mov`/`push` immediates (`mov dword [esi+0x38], 0x3e32b8c3`) compare
    like float constants in memory: one of ours the original doesn't have, within 1e-4 (relative) and with the same
    exponent as one of its unshared ones, is `float_immediate_differs` (fx20's 0x00180f00: `0.17453292f` and
    `1.7453292f`, 1 ulp off each, passed 3000 inputs). An immediate counts as a float when it is above 0xffff, has a
    normal exponent and isn't an image address; an integer that only looks like a float is flagged only next to a
    near-equal original constant.
  - `treespecial`: equiv-map and equiv-conv lines naming a constructor, destructor, operator or template function
    (`??0DrawableBase@pure3d@@QAE@XZ`) are translated into a merged tree object's `fn_<addr>` namespace too (they
    fell back to instruction pairing, which bound the allocator: native10's stop 17).
- (round 16, cl4) Three gaps native13 found, each switchable (`EQUIV_OFF=name`; `RELOC_OFF=literal` for verify_relocs):
  - `literal` (verify_relocs) / `literalfull` (equiv level 2 string binding): a string literal is compared over its
    whole extent (its COMDAT section from the symbol to the end: a wide literal's terminator, embedded NULs), not up
    to its first NUL byte, which cut every wide string after its first character. native13's stop 34:
    `matches/0x003388d0` passed with `L"()"` where the original's item at 0x434634 is `L"()[]{}=;"`; now
    `string_mismatch`. `verify_relocs.py --literals OUT` sweeps every `matches/` and `equivalent/` source that has a
    wide literal or an escape `\0`/`\x0` (the only literals a NUL cut can hide a difference in; matches/ through the
    relocation map, equivalents/ by finding the full bytes in the image): `build/cl4/literals.json`.
  - `rwfix`: `reg_writes` (which of eax/ecx/edx a callee may change, so a register it never writes keeps its value
    across the stub) assumed a self-recursive callee clobbers all three. It is now a least fixpoint over the call
    graph reached from the callee (to depth 3; indirect or unreadable callees still write all three), so a
    self- or mutually recursive function gets the registers it really writes. 0x0030ecb0 calls itself and never
    writes edx; the original of 0x0030ed60 keeps the node in edx across that call, and the rewrite with an ordinary
    local (native13's pending source) could not be proven: now EQUIVALENT at 3000 inputs.
  - `vcall`: at an indirect (virtual) call our stack words are decided by our own code around the call, and the
    original's by its code. If the original's k-th call takes words (a pop count above 0, learned from its code) and
    our k-th call on the same input takes more, the extra words belong to another call: a virtual declared with extra
    arguments that the next call passes again compiles to the same bytes (0x002f2fc0: slot 4 declared with 3 words,
    the real callee pops 1 and the transform call takes the other two). Natively the callee pops its own word only.
    Message: `call #N (indirect): our code passes it 12 bytes of stack arguments, but the original's call takes 4:
    the other 8 bytes belong to another call`. This extends `argcall` (direct callee-popped calls) to indirect calls,
    whose arity is learned from the original's run. Not covered: an original call that takes none (pop 0 is also what
    the code looks like when its words are "the next call's"; 0x0024da50 / 0x0024db50 pass `effect` to a slot that
    takes none and again to the next call, and 0x0013d7b0's original keeps the next call's words in preset frame
    slots: the two look the same from the original alone, and a rule that flags the first flags the second, the
    only committed equivalent it flags). The real callee's pop count is what decides: a rewrite that declares an
    indirect call with arguments should be checked against the callee's own source.
- (round 17, cl5) Three gaps native14 found, each switchable (`EQUIV_OFF=name`; `RELOC_OFF=thisdecl` / `COMPARE_OFF=thisdecl`
  for compare.py and verify_relocs). Old behaviour = `EQUIV_OFF=ftolexact,ptrext,thisdecl`.
  - `ptrext`: the bytes a callee reads through a pointer into the caller's frame. The extent of a scalar or unknown
    pointee grew over the words the function itself wrote, starting at the pointer: a local whose first words a callee
    fills (`ev.id.FUN_0027af00()`, a constructor stub) and whose later words the function stores (`ev.type = -1;
    ev.value = 0`) stopped at word 0 and only that word was compared. Now a leading run of callee-written words (up to
    ARRAY_WINDOW) is stepped over when the function's own stores follow it. native14's stop 38: `equivalent/0x0027dca0`
    passed its listeners `{id}` instead of `{id, type -1, 0}` and the listener switched on garbage (pre-fix source =
    `tests/equiv/cases/0x0027dca0_event_words_wrong.cpp`: EQUIVALENT at 3000 inputs before, `the local passed as
    argument 1 differs at +0x8 (0x0, expected 0xffffffff)` now).
  - `ftolexact`: float comparison is exact by default. The original runs the x87 at 53-bit precision (control word
    0x027F; docs/native-float.md) and both emulated runs write that word, so equal arithmetic gives equal bits and a
    1-ULP difference is a real one: the native build reproduces the original's rounding bit for bit or it drifts
    (native14's camera y). `_feq` is `==` (+0 and -0 are different); a returned `st(0)` is compared over its full
    64-bit mantissa (`st0raw`), the control word at return must match, and the "same float but for the last bit" rule
    for stack words is off. An explicit tolerance in a directed-input search is unchanged. Unicorn honours the
    precision bits (`build/cl5/pctest.py`). This changes verdicts; the flips are listed in `build/cl5/flips.txt`.
    `tools/equiv_replay.py` compares through `equiv.compare_runs`, so recorded-state replays are exact too.
  - `thisdecl`: a callee our source declares as a free `__cdecl`/`__stdcall` function (not a member, not
    `__fastcall`) that the original's callee takes `this` in ecx (its body reads ecx before writing it, found by
    `Program.reg_inputs`, or it is in a vtable). Byte-identical code can't show it (the caller's ecx happened to hold the
    right value), the native build passes the first argument there. `compare.py` reports status `thiscall_decl` for such
    an exact match (so farm promotion, which wants `match`, drops it), `verify_relocs.check` the issue
    `free_decl_of_thiscall`, equiv.py a level-2 issue of that kind. A callee with an `// equiv-conv` line and CRT
    helpers (`__aullshr`) are left out. native14's stop 37: `matches/0x00042930` (`void __stdcall helper(int, float)` for
    the member 0x00042890); the pre-fix sources of 0x00042930, 0x00042960, 0x00336f10 and 0x00337330 all report it.
    `build/cl5/thiscall.json` has the sweep over `equivalent/` and `matches/`.

- (round 18, cl6) **Native mode**: `equiv.py SRC 0xADDR --native` (`verify(native=True)`, `tools/equiv_native_sample.py` for
  lists) compiles the source the way the native build does (`tools/clang_probe.py`'s `msvc` configuration: clang i686
  `-O0` x87, `compat/native.h`, `hulk_freg` = `double`) and runs that COFF object against the original in the same
  harness, calls included. Before, only leaf functions could be run (calls hit wild jumps and argument-count errors).
  What the harness had to learn about clang's object:
  - the MSVC object of the same source names the function under test (`pick_symbol` by byte similarity could pick a
    constructor the function calls) and its symbol bindings are reused (`natmap`: clang's code pairs badly with the
    original's, so type descriptors, vftables, literals bind as the proven MSVC object has them; section symbols such as
    `.rdata` stay local data; functions the object defines run in place). Level 2 is not applied to clang's object.
  - clang reserves the outgoing-argument area in the prologue and stores arguments with `mov [esp+k], x`; a callee that
    pops its arguments is followed by `sub esp, N` (or, before the epilogue, a smaller `add esp`). `CodeView.clang_pop_after`
    reads that for indirect calls, direct calls take the words of our declaration (or the original's count for C names and
    `...` calls), `sub esp, N` is not a frame allocation to track, and an `add esp` far on is the epilogue, not cleanup
    (`clangpop`). A declaration that pops differently from the real callee is still reported (`abi_mismatch`, `vcall`).
  - bool results: clang tests bit 0 only, the original the byte; a callee declared `bool`, or a call followed by `test al, 1`,
    returns 0/1 (same branch; `boolret`), and a function returning `bool` compares by truthiness (`natbool`). `eax` of a void
    function reached through a vtable is not compared (`natvoid`): native callers are compiled from sources that declare it void.
  - destructors: clang omits the last vptr store of a trivial `~Base() {}`; a final `[this]` difference between two vftable
    addresses in a destructor is not reported (`dtorvptr`). Words only a stub's speculative window fill wrote and scalar
    pointee windows behind the declared size are compared where both runs wrote them (`natwin`: clang orders locals
    differently). An original that fills thousands of elements with one `rep stos` where clang's loop outruns the step
    budget is inconclusive (`ours_slow_rep`).
  - a float return mismatch where ours is the original's `st(0)` rounded to 24 bits is labelled "unrounded-return class"
    (the by-design native15 difference); the verdict stays `fail`.
  - triage aids: `EQUIV_TRACE=1` (instruction trace and stub lines of our run), `EQUIV_DUMP=1` (calls of both runs on a
    failing input), `EQUIV_MAXFAIL=N` (do not stop at three failing inputs), `X87DBG=1`.
  - more of clang's object: `frame_of` (the prologue of the function holding the call, `push eax` frames included) so
    `add esp, X` before the epilogue is read against the right frame; a callee whose pop is unknown follows our declaration;
    the original's word count is reused for C-named callees, `...` calls and indirect cdecl calls; a library routine the
    original calls as `__CI<name>` with st(0) arguments (`__CIasin`) is the same call as clang's `asin(double)`
    (`natci`, the stack doubles become the x87 arguments); `testb $1` over a byte that is neither 0 nor 1 makes an input
    that differs inconclusive (`boolub`: a bool field of fuzzed memory is undefined natively).
  - **`_strcmp` was bound to the XBE's `_wcscmp`** (0x346e5a): the CRT probes (`abc`/`abd` shaped strings) cannot tell a
    wide compare. A fourth probe (equal one-byte strings with different bytes behind the NUL) fixes it
    (`crtprobe`); the table is cached in `build/equiv/crt2.json` (`_strcmp` 0x3473c6, `_strcpy` 0x346f3e now found).
    MSVC mode never reached it (MSVC inlines strcmp).
  - **x87 math** (`x87math`): `exp`, `sin`, `cos`, `tan`, `atan`, `atan2`, `sqrt` called by our code run the instruction
    sequences MSVC 7.1 inlines (and native15's `crt_glue.cpp` uses) in a scratch Unicorn machine at control word 0x027F;
    the result comes back as the full 80-bit st(0). Unicorn 2.1.4 (QEMU 5) implements fsin/fcos/fptan/fpatan/f2xm1 with the
    host's double libm and rounds their results to 53 bits whatever the control word (real x87: 64-bit results), so
    for sin/cos/tan/atan/atan2/sqrt this is the same value Python's `math` gave; `exp` is a sequence of 53-bit steps and
    differs from `math.exp` in the last bit for roughly one input in three (`matches/0x0009f760` native: EQUIVALENT with
    the sequence, `returned 1.0136074813942127e+23, expected ...107e+23` with Python). Residual: the missing 11 mantissa
    bits of the transcendental results (a real CPU's st(0) feeds the next 53-bit operation with them; a double rounding at
    one operation in ~2000) and `fsin` of |x| >= 2^63; not measurable here (no x86 hardware; Rosetta computes fpatan with
    the host's atan2). `pow`, `log` & co. are library routines (a callee in the original, stubbed) and stay Python.
  - **Sum order**: MSVC 7.1 reassociates float sums, so an MSVC-mode pass cannot show the order clang computes is right;
    native mode can. native15's parked `0x0022ff50` (hulk_freg) is EQUIVALENT natively at 3000 inputs (its MSVC-mode run
    differs: `hulk_freg` is `float` there); summing the endpoint distance in the other order fails natively. The parked
    `0x0009fb20` fails in MSVC mode on the order of its final sum (MSVC inlines exp itself, so the Python model was not
    the cause), and natively on two things only: the by-design 24-bit rounding of the float return and the x87 register's
    larger exponent range (a `double` local holds inf where the original's st(0) holds 1e434; 35 of 3003 inputs, all
    `exp` of a huge argument; with a `double` return the other 2968 agree).
  Findings that are real native differences (not harness gaps) fall in a few classes: explicit `(float)` casts of register
  values that MSVC 7.1 drops (0x0033ed90, 0x00150a10), float locals the original keeps unrounded (needs `hulk_freg`),
  unrounded float returns, an operand read before a call where the original reads it after (evaluation order: 0x001247d0,
  0x00207580), and a tail `jmp` whose callee reads the caller's stack words (0x0024b0c0). `build/cl6/native-sample.json`
  has the sample, `build/cl6/native-recheck.txt` the sources to re-check.

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
  - (round 12, vext) for a virtual call (`call [eax+0x14]`, eax = ecx's vptr, target fuzzed) takes that extent from
    the functions in that vtable slot (all RTTI vtables) that pop the same bytes: per frame local passed, the
    biggest extent three implementations share that fits the original's free room there (up to
    the next word it wrote, another address-taken local, a saved register or the return address). Ours must
    have that room before a saved register, its return address or a local it set before the call (pure3d's
    loaders' `create` write a 64-bit id: a 4-byte local fails), and the stub fills that far on both sides. A
    real target (trace replay) uses its own extent;
  - leaves `ecx`/`edx`/`eax` alone when the callee never writes them (callers may rely on that);
  - pops the callee's argument bytes. Pops over 252 bytes (a struct passed by value) are done directly. A call through
  a fixed function pointer (`call [0x4de948]`, a global whose value is fuzzed) takes its stack use from the pointer's
  call sites across the image: when some site passes it no words (nothing pending on any path from its function's
  entry) it takes none and pops none, so `push 0; call [g]; push ecx; call [esi+0x18]` passes both words to the
  virtual call; when some site releases the words right after it (`add esp, N`), it is caller-cleaned;
- a callee that takes x87 register arguments (`fld x; fld e; call __CIpow`: its first instructions read st0 and st1
  below the stack it found) has them replaced by its float result, as the real one does: they are not values the
  caller keeps across the call;
- A `push` of an untouched callee-saved register counts as a save (not an argument) only if the function
  pops that register somewhere; otherwise it passes on a register argument (LTCG `esi`). A register the
  function wrote itself is never a save, even when it holds its entry value again (`xor edi, edi; push edi`
  with `edi` 0 on entry, as recorded game states often have it). Alignment padding (`mov edi, edi`,
  `lea esi, [esi]`) doesn't count as a write.
- The pop count comes from the callee's own `ret N` (following tail jumps) when the call site names a real
  function. For cdecl, it comes from the caller's `add esp, N` or `pop ecx` cleanup, including one
  deferred over several calls (looked for up to 48 instructions on: four writer-callback calls share one
  `add esp, 0x40` 31 instructions later). An `add esp, N` in an epilogue (followed by `ret` or a callee-saved `pop`)
  counts only beyond the frame the prologue reserved with `sub esp`. (round 13, `popret`) `pop ecx` (once or
  twice) right before a `ret` is the call's cleanup when, with the call's words left on the stack, the pops end
  exactly at the run's return-address slot (`push [eax+4]; call [eax]; pop ecx; ret 4`, fx14's 0x0026dc20); with a
  `push ecx` frame (`push ecx; ...; push x; call [edx+0x1c]; pop ecx; ret`, 15 such functions) they end one word
  short, so the call popped its word and the `pop ecx` releases the frame, as before. A caller-cleaned callee takes only the words it reads; pushes above them
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
  call). `ecx` isn't compared at a call through a pointer that the original proves cdecl: its caller
  releases every word pushed for the call right after it (`push esi; call [ecx+0xc]; add esp, 4`), which
  only a cdecl callee allows (thiscall, stdcall and fastcall pop their own words), or a later call through the
  same field (the same operand at the same non-stack address, `call [esi+4]`) whose cleanup is shared with
  the next call's.
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
  original leaves a meaningful value there: a callee's result nothing overwrote and that the function used
  as a value (only dereferencing it, `cmp [eax+0x221c], ebx`, isn't evidence: `use(f()->x)` and `p = f();
  use(p->x); return p` compile alike), or a write to `eax` the function never reads back (a `dec eax; jne` of a switch's dec chain is read, through the flags) (`left 0x7 in eax, expected 0xa8: ours is void, but the original returns a
  value there`).
- Bytes of `eax` that last came from `fnstsw ax` (a float branch's status word, `fnstsw ax; test ah, 0x41;
  ...; mov al, 1; ret`) aren't compared: no source produces them. What was written after them (`al`) is.
- The x87 stack depth, `ebx/esi/edi/ebp` and `esp` after return.
- (round 12, x87cmp) The x87 registers a callee takes as arguments (`fld x; call __CIasin`; `Program.x87_args`),
  with the float tolerance; an empty slot is `empty` (`call #2 to 0x003442bc: x87 argument st(0) is empty,
  expected 2`). A call that takes an x87 argument right after another call counts as using that call's float
  result.
- An argument pushed from a register whose last write set only its low byte(s) (`setcc al; push eax`, a
  `bool`) compares on those bytes only. A register argument of an `equiv-conv` callee compares on the bits
  the real callee reads before overwriting it (a byte flag in `cl` over leftover high bytes: `test cl, cl`).
- An argument word that holds, on each side, the return address of the same earlier call (stale padding of
  a struct passed by value) is equal: each image has its own addresses.
- Values that point into the stack compare as "a stack address". Floats stored by `fst`/`fstp` (on either
  side) and float arguments (stored by `fstp` on either side, a word copied with `push` on the other)
  compare exactly (round 17, `ftolexact`: the same bits, +0 and -0 apart; `EQUIV_OFF=ftolexact` restores the old
  relative tolerance 1e-5 and the rule that a word that is the same normal float but for its last bit, rounded once
  more on one side and copied through a register, is equal).

An input on which either side stores into code (our object at `0x60000000`, or the original's `.text`,
through a fuzzed pointer) is inconclusive: the store rewrites one side's instructions only (`statuses`
counts them as `code_write`).

Inputs that are undefined behaviour in the original are inconclusive too when they show a difference (one
that agrees counts as usual), when the input proves the undefined behaviour:
- the original overruns a buffer into its return address or a live saved-register slot with an array-style
  store (indexed, through a pointer, or a string instruction: `buf[len] = 0` with a fuzzed `len`)
  (`stack_smash`; one that then goes wild is set aside as `stack_smash`, not `wild`). Plain `mov [esp+k]` stores don't count (an argument word rewritten for the next call
  can look like a register save);
- a CRT copy routine under test (`strncat`, `strcat`, `strncpy`, `strcpy` and the wide versions; not
  `memcpy`, which is `memmove` in this XBE) gets a source that overlaps the destination over the bytes it
  certainly touches (`overlap_ub`).

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
but our semantic copy hit the page limit is inconclusive. (Round 11.) While every input that ran out of steps did so in
a loop over a constant count, inputs whose original returns within 256 steps (`if (start == 0) return`) don't count
toward those first 4: the budget is decided at the 4th other input. When three of
the first four ran out of steps, each in a loop that counts down from a constant (`mov ebx, 0x800; ... dec ebx; jne`),
and the fourth returned through a stub result that skips the loops, the 8M-step probe runs too. Long code the probe
proved finite gets up to 8x the time budget (not 3x) while fewer than 50 inputs have completed and the original
returns on at least four in five. When the first four ran out of steps in walks over fuzzed links (below), the long
budget is skipped: they are runaway walks.

**Return type** comes from our mangled name. For a C name it is inferred from the original's call sites.
If ours returns `void` but the original's direct callers read `eax` (or `st0`) after the call, the return
value is compared anyway, and `return_note` says so.

**Coverage** counts taken/not-taken for every conditional branch (except dead sides: a jcc right
after `cmp r, r`/`sub r, r`/`xor r, r` that nothing else jumps to; the zero side of `lea ecx, [esi + 4]; ...;
test ecx, ecx` where esi is a pointer, the null check of `&this->member`, also when the lea's result is kept in
a register across calls and branches (`lea edi, [esi+0x1f58]; call f; ...; test edi, edi; je`: a forward data
flow; a call ends it for eax/ecx/edx only, since the original keeping it in ebx/esi/edi/ebp relies on the callee
preserving it); the wraparound side of `lea ecx,
[ebp + 3]; cmp ebp, ecx; jae` when either register is used as a pointer; a jcc whose flags come from
registers that hold the same constant on every path (`xor eax, eax` before a loop, `test eax, eax; jne`
after it); sides a source declares with
`// equiv-dead: +0x63 taken, +0x70 not taken: why` after hand review, listed in `coverage.declared_dead`;
and everything only a dead side reaches; a side a rule calls dead that a run takes anyway counts normally
and is listed in `coverage.dead_taken`, a checker bug to report), 0/1 for every `setcc` (also one that
stores to memory, `sete byte ptr [esp+0x1c]`), and every
jump-table case index of the original (round 15: every index the bounds check lets through, not every distinct target) (a table is read up to its first non-code word, and ends where the
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

`level` is the highest level passed. A `fail` also has `failed_levels` (`[3]` for a level-3 mismatch, `[2]` or
`[2, 3]` with level-2 issues), and the text header says `fails level 3 (passes level 2)`.

Mismatch strings are written for a model to act on. Examples:

- `write to this+0x40 before call #2 was 0x3f000000 (0.5f), expected 0x3f800000 (1f)`
- `call #3 to 0x0008d690: argument 1 is 0x25, expected 0x24`
- `call #1 to 0x00337700: the local passed as argument 1 differs at +0x8`
- `missing call #2 to 0x00232660`
- `returned 0x0, expected 0x1`

## Validation

Latest run (2026-10-20, checker round 17, cl5): `regress.py` 195/195 (8 new cases: 0x0027dca0 event words, 0x0009faa0 and
0x00097320 exact floats, 0x00042930 and 0x00336f10 thiscall declarations, each `_wrong` is `equivalent`/`match` under
round 16; a case can run with `"equiv_off"` switches: six older float-sensitive cases keep the tolerance, 0x001b4d00's
free declaration of FUN_00080cd0 keeps `thisdecl` off); `test_equiv.py` 14/14; `replay_regress.py` 16/16.
60-function sample of `equivalent/` at 3000 inputs (25 x87 functions the scanner lists with extra rounding, 15 with a
frame object passed by pointer, 20 random; `build/cl5/sample60.txt`), round 16 vs 17: 56 identical, 4 `equivalent` ->
`fail` (0x0003d350, 0x00134330, 0x0015f6b0, 0x0022ff50: a float differing in the last bit(s), exact comparison), none
the other way; time 3514.8 s vs 3560.8 s of summed per-function time (+1.3%). All 288 `equivalent/` sources among
`build/x87/scan-o0.json`'s candidates at 3000 inputs and the 2,113 sources with x87 code or a pointer-to-frame-store shape
at 300 inputs (`build/cl5/static.json`): 99 newly fail (`build/cl5/flips.txt`): 90 exact floats, 7 `ptrext`, 2 both
(attributed by re-running each with one switch off); 12 of the float ones are +0/-0 differences. `thiscall.json`: all
5,138 `equivalent/` sources and the 4,790 `matches/` sources that can hit: one finding (0x00321ea0, a vtable function
declared free `__stdcall`), none in `matches/`. `build/cl5/recheck.txt`: 2,114 sources (the 99 observed flips first).

Previous run (2026-10-20, checker round 16, cl4): `regress.py` 187/187 (6 new cases: 0x003388d0 literal, 0x0030ed60
recursive edx, 0x002f2fc0 vcall, each with a `_wrong` that the previous round passes); `test_equiv.py` 14/14.
60-function sample of `equivalent/` at 3000 inputs (9 whose callees changed register writes, 31 with indirect calls,
20 random; `build/cl4/sample60.txt`), round 15 vs 16: 60 equivalent under both, no verdict change; time +2.9% (a
shared machine; the runs are time-budgeted). All 1,691 `equivalent/` sources with an indirect call at 200 inputs: no
`vcall` hit (the rule without its "original takes words" condition flags 0x0013d7b0 and 0x002b2040 only).
`literals.json`: no violations (39 sources with a wide or escaped-NUL literal). `build/cl4/recheck.txt`: 11 sources
(9 whose callees' register writes shrank, 2 for the pop-0 `vcall` shape). Pending 0x0030ed60 (native13): EQUIVALENT.

Previous run (2026-10-19, checker round 15, cl3): `regress.py` 181/181 (12 new cases; every new `_wrong` case is
`equivalent` under round 14, and `0x0029a190_tree_ctor_map` fails there; `0x000991b0_chained_vcalls` now fails, as it
should: its source declares FUN_000fd8a0 (`ret 0x10`) with 2 of its 4 words, see `argcall`); `test_equiv.py` 12/12.
60-function sample of `equivalent/` at 3000 inputs (20 with jump tables of more indices than targets, 20 with chained
callee-popped calls, 20 random; `build/cl3/sample60.txt`), round 14 vs 15: 59 equivalent under both, with 21 gaining
index edges, all covered (0x0028aea0 12/12 -> 23/23); 0x000991b0 newly fails (the declaration above; a real bug for the
native build); time 1358.6 s vs 1360.7 s (+0.2%). Level 2 over the 939 committed equivalents with float immediates:
no `float_immediate_differs` (fx20 fixed the known ones). Initializers (`verify_relocs.py --initializers`): 119
violations in 116 `matches/` sources (89 a `gNegOne = -1.0f` propagated to functions whose original reads another
constant, 15 placeholder vftables defined as zeros), none in `equivalent/` (`build/cl3/initializers.json`).

Previous run (2026-10-18, checker round 13; details in [tasks/equiv-round13.md](tasks/equiv-round13.md)):
`regress.py` 164/164 (the library-span cases 0x00212641 and 0x003468c0 replaced or dropped; every new `_wrong` case
is `equivalent` under round 12); `replay_regress.py` 16/16; selftest 292/300 (all 8 fail the same under round 12);
mutation suite identical to round 12 mutant by mutant; `equivalent/` random 300 (seed 2041, library excluded) at
3000 inputs: 298 promotable, no newly failing file. `fconst` fails 43 `equivalent/` sources at level 2 (a float
literal a few ulps off: `build/equiv/fconst-failing.tsv`). 0x0026dc20 newly promotable (`popret`).

**Recipes for batch agents (round 13).** `float_constant_differs`: write the original's value (`original=`) with 9
significant digits, not one derived from the math (the game's 180/pi is 0x42652ee0). Use `// cl-flags: /GS` and a
plain buffer instead of a hand-written cookie (candidates: `build/equiv/gs-candidates.tsv`). An `N+obj` failure
(`argument 1 is 0x00000808, expected 0x00000707`) is a wrong field offset behind a pointer: 0x707 is word 7 (+0x18),
0x808 word 8 (+0x1c).

Previous run (2026-10-17, checker round 12; details in [tasks/equiv-round12.md](tasks/equiv-round12.md)):
`regress.py` 157/157 (every new `_wrong` case is `equivalent` under round 11); the new `replay_regress.py` 16/16
(the 11 non-guard cases all fail under round 11); selftest 290/300 (ten template scalar deleting destructors with
an unresolved destructor, identical under round 11); mutation suite identical to round 11 mutant by mutant;
`equivalent/` random 300 (seed 2036) at 3000 inputs: 297 promotable, one newly failing file, 0x0030e0a0, a real
`<=`/`<` bug found by the tie inputs. Replay over every local session (on mac1): 10 mismatching functions -> 1
(0x002e22c0, newly comparable), 14,227 -> 14,258 agreed; confidence tier 0 12 -> 6, tier 3 1,945 -> 1,963.

**Recipes for batch agents (round 12).** Re-run the replay (`tools/equiv_replay_fn.py --changed`) before
rewriting a source for a replay mismatch: upper-half register diffs (0xd004xxxx), stale partial words and pad
garbage are no longer reported. `no_replay` "differs only through recorded stack bytes ... the original never
read" is inconclusive (a pad in the original, a live value in ours): matching the original's frame turns it into
`agreed`, but promotion doesn't need it. Ignore `incomplete` "captured before the ST(0) fix" (s1, t1, t2). A
`__CI*` intrinsic written as a plain call fails with `x87 argument st(0) is empty`: write the libm call with an
`equiv-map`. `writes 0x8 bytes through argument 2 ... ours has only 0x4` at a virtual call: make the local as big as
the slot's implementations' object. A failure on an `N+tie` input is a `<`/`<=` difference: read the original's
`test ah, ...` to choose.

Previous run (2026-10-16, checker round 11; details in [tasks/equiv-round11.md](tasks/equiv-round11.md)):
`regress.py` 145/145 (the 10 new cases all fail under round 10); selftest 297/300 (three unresolved-destructor
failures, identical under round 10); mutation suite identical to round 10 mutant by mutant on the pinned 120;
`equivalent/` random 300 (seed 2035) at 3000 inputs: 296 promotable, no newly failing file. 6 of 7 work-list
sources newly promotable (0x0026bac0 with a by-value return).

Previous run (2026-10-15, checker round 9; details in [tasks/equiv-round9.md](tasks/equiv-round9.md)):
`regress.py` 125/125; selftest 298/300 (the 2 fail identically under round 8); mutation suite identical to
round 8 on the pinned 120; `equivalent/` random 300 at 3000 inputs: 299 (0x0028e160 as under round 8). 12 of
26 work-list sources newly promotable.

Previous run (2026-10-14, checker round 7; details in [tasks/equiv-round7.md](tasks/equiv-round7.md)):
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
- `tests/equiv/replay_regress.py` (round 12): sources a replay artifact once got wrong
  (`tests/equiv/replay_cases/`), each replayed on a local capture session (skipped when that session is absent)
  with the status it must get; `EQUIV_REPLAY_MODULE=path` and `EQUIV_MODULE=name` pick the versions.

## Trace replay (`tools/trace_capture.py`, `tools/equiv_replay.py`)

Fuzzing can't reach some paths, and its stubs return made-up values. Trace replay runs both sides on game
states recorded once from the real game, and replays them on every build.

```sh
PY=build/venv/bin/python
$PY tools/trace_gate.py --session g2 --script build/replays/play2.json --minutes 150   # record: every target armed
$PY tools/trace_capture.py --session s2 --minutes 30 --per-func 30    # record, the older way (96 breakpoints)
$PY tools/equiv_replay.py --session build/traces/s2 --equivalent      # replay every captured equivalent/
$PY tools/equiv_replay.py --src OLD.cpp 0xADDR                        # any source against the recording
$PY tools/equiv_replay.py --matches all                               # control: matches must all agree
$PY tools/equiv_confidence.py                                         # -> build/equiv-confidence.json
$PY tools/patch_xbe.py --matches all --equivalent --classes identical,local,equivalent --tier-min 3 ...
$PY tools/bisect_hybrid.py ...      # orders candidates by tier, lowest first, when the file exists
```

Captures live in `build/traces/SESSION/trace.sqlite`. They hold game memory, so never commit them.

**Two recorders, one format.**
- `tools/trace_gate.py` (preferred): the build arms every target itself. Each target's entry jumps to a
  trampoline that counts the call in a per-function table in the guest. When the host has asked for that
  call, the trampoline stops at a single shared gate address, the only permanent breakpoint, with the
  function's entry registers. The host then records the call exactly as below.
  - Which calls: the first call of every target is always recorded. After that the default is one call
    (`--burst`), then one more each time the game has moved `--spread-polls` 1,800 polls on, within a `--duty`
    share of wall time, up to `--per-func`.
  - The table also gives a census of every target: call count, and the poll and frame of its first call.
  - Design and numbers: [tasks/ingame-trace.md](tasks/ingame-trace.md).
- `tools/trace_capture.py`: a GDB breakpoint per target, at most `--window` at a time (below).

Both write the same `trace.sqlite`, and `equiv_replay.py` reads either.

Play3 sharded over two hosts (2026-10-20): 1,368 more functions reached tier 3, 6 disagreements, and 1,700 targets that
play3 never runs. See [tasks/record-replay.md](tasks/record-replay.md), "Trace sessions of play3 on two hosts".

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
- No screenshots by default (`--shot-every 0`): the QMP `pmemsave` of the framebuffer wedges xemu's main loop
  during level loads. The GDB stub runs on that loop too, so the session ended with `gdb connection lost:
  TimeoutError`. Reproduced at play2's new-game load, poll ~47,815, every time.
- (trace_capture.py) QEMU slows down with every breakpoint set: 800 never-hit ones make it 6x slower. So at
  most 96 functions are armed at a time (`--window`):
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
- Round 12 (details in [tasks/equiv-round12.md](tasks/equiv-round12.md); `REPLAY_OFF=name` switches each off):
  - `x87arg`: a callee with x87 register arguments gets the recorded ST(0) too.
  - `scratchkey`: a write keyed to a register the callee doesn't take (eax after `fnstsw ax`, after `mov al, ..`,
    a loop's end pointer) goes behind the nearest stack-argument pointer below it, else nowhere.
  - `xlate`: a recorded word of the function's own frame holding a game stack address that translates to
    exactly what the original holds there (a pushed `&local`, 0xd004.. vs 0x7eff..) is no write at all. Other
    stack-looking words stay the game's (bytes of a string can spell 0xd004....).
  - `widen`: a run that changes part of a word gets the game's other bytes where the original's code never
    wrote them (stale return-address bytes in padding).
  - `unknown`: bytes that were below the stack pointer since the last call (interrupt frames, the gate
    trampoline's words) may not be callee writes. A mismatching call is re-run on both sides without those of
    them the original's code never read; if the original still reproduces the recording and ours agrees, the
    call is `incomplete` ("differs only through recorded stack bytes ..."), never agreed.
  - `deadarg`: a frame-keyed write into our incoming-argument slots (ours keeps a local in a dead
    parameter) is placed when the original's own slots there are dead after the call.
  - `st0fix`: sessions captured before b566e0d3 (s1, t1, t2): a call whose original takes a recorded x87
    result is `incomplete`; `equiv_confidence.py` drops their results made by older replays (no `st0fix` mark).
  - `steps`: an original that runs out of the 2M steps where the recording returned gets 16M once.
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
- **x87:** float results, stores and float arguments compare exactly (round 17; a returned `st(0)` over its full
  64-bit mantissa, and the control word at return must be the same). Both emulated runs start with the original's
  control word 0x027F (round to nearest, 53-bit precision; Unicorn honours the precision bits:
  `build/cl5/pctest.py` stores 1/3 with 53, 64 and 24 mantissa bits for 0x027F, 0x037F and 0x007F). MSVC-compiled
  code that is not byte-identical can still differ in the last bit (a `float` local stored and reloaded where the
  original keeps the register); that is a real difference for the native build (docs/native-float.md).
- **Function bounds** come from `build/functions.csv`. Code past the listed size is still followed, as a
  chunk, but some sizes are wrong: 0x001bb0b0 is listed at 320 bytes but returns at +0x47d, so its
  packet showed only part of the function.
