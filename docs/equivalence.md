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
returns the report dict. The exit status is 0 only for `equivalent`. A typical function takes 1–5 s
(compile included); loops that run long on fuzzed inputs can take up to the 120 s level-3 budget. The
budget is CPU time, so a loaded machine takes longer but gets the same result. `--inputs N` raises the
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

Level 2 also lists **warnings**: differences that equivalent code can legitimately have. Examples are an
immediate that only looks like an address, a float constant loaded another way (`fld1`, or a double
instead of a float), a string or global read in pieces, another element of a global the original
references too (a loop's induction base at a different field of the same object), and CRT calls the
original inlined. Level 3 still checks the behaviour behind them.

## Binding our symbols to original addresses

Our object names things; the original has addresses. Each symbol our code references is bound in this
order. The report's `level2.mapping` says which rule fired.

1. **explicit**: `--map` JSON, or a `// equiv-map: ?Foo@@YAXXZ = 0x00123456` comment in the source.
2. **content**: string literals (same bytes as a string the original references), `__real@` float
   constants (same bits, in read-only data: a writable global that holds 0.0 is a variable), and vftables
   (`??_7Class@@6B@` by RTTI class name).
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

Two kinds of symbol are never paired:

- **Functions defined in our own object.** These are code the original inlined, for example an inline
  constructor that this compile didn't inline. They run in place, as if inlined, and their references count
  at level 2.
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
  and the hidden struct-return pointer. 16 extra stack words follow, and callee-saved registers get unique
  values.
- Seeds rotate between several modes:
  - wide or near/ascending pointers;
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
  A run that then hangs in the next loop is repaired again (4 loops deep, 64 runs). A loop that ran away
  once is cut off after 256 rounds on later inputs (those count as timed out, and are repaired too).
- Then up to 96 **directed** inputs (input-to-state; each one that finds a new edge earns 4 more, up to 4x).
  Every comparison the original executes is recorded, with where each operand came from. When a branch side
  (or `setcc` outcome, or jump-table case) was never taken, or was taken by fewer than 4 inputs, the input
  that reached it is re-run with that memory, stack argument, stub result or out-parameter word patched to
  a value on the other side (alternating between the two operands). Followed through:
  - comparisons done by `sub`/`add`/`dec`/`inc`/`and`/`or r, r` (`dec ecx; sub ecx, 4; je`: a type switch);
  - arithmetic on the loaded value: `add`/`sub` of constants or other registers (`end - begin`), shifts,
    `and`, `neg`/`not`, magic-number divisions (`imul` by a constant, `idiv`), `movzx` of a low byte, a
    byte-table switch index (`movzx ecx, byte [eax + table]`), all inverted to find the value to plant;
  - a register stored to a stack local and compared there later (`movsx eax, byte [edx]; mov [esp+4], eax`);
  - x87 compares (`fcom`/`fcomp` + `fnstsw`/`test ah`, `fcomi`), against memory or a stubbed callee's
    float result;
  - a loop's bound (patched for one or two more rounds, in every memory epoch when it is re-read after a
    call).

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
    `st0` (the same value on both sides; directed inputs can steer it);
  - fills each local passed by pointer (an out-parameter), with the same values on both sides. A class
    parameter is filled over its whole `sizeof`. Any other parameter gets at least 16 bytes, skipping
    words the function has already written itself;
  - models how far the real callee writes through each pointer argument (`ecx` or a stack argument). A
    static scan of the callee (`Program.callee_writes`) follows stores through the incoming pointer, copies
    and constant offsets of it, and callees it is passed on to (a base or member constructor). In the
    original's run that extent, capped at the room the original's frame has there, is filled; ours fills
    the same offsets. If ours has less room before a saved register, the return address or the caller's
    frame, the call fails (`writes 0x40 bytes through ecx ... but ours has only 0x20 bytes there`): our
    local is smaller than the callee's object;
  - leaves `ecx`/`edx`/`eax` alone when the callee never writes them (callers may rely on that);
  - pops the callee's argument bytes. Pops over 252 bytes (a struct passed by value) are done directly.
- A `push` of an untouched callee-saved register counts as a save (not an argument) only if the function
  pops that register somewhere; otherwise it passes on a register argument (LTCG `esi`).
- The pop count comes from the callee's own `ret N` (following tail jumps) when the call site names a real
  function. For cdecl, it comes from the caller's `add esp, N` or `pop ecx` cleanup, including one
  deferred over several calls. A caller-cleaned callee takes only the words it reads; pushes above them
  are pending for a later call.
- A call of unknown arity (virtual, a `jmp [vtable]` thunk) is decided by what the caller does with the
  pushed words afterwards: released by a later `add esp` (the callee leaves its arguments:
  caller-cleaned), popped by a later call with a known `ret N` (pushed early for that call: `push 1; call
  thunk; push eax; push esi; call f(ret 4); push eax; call g(ret 12)`), or read by a later caller-cleaned
  call (`push &t; call [vt+0x40]; push eax; ...; call f; add esp, 0x10`). Otherwise the tracked pushes
  count, and the callee pops them. Each side's stack follows its own code (a virtual we declare as a
  thiscall member pops its arguments where the original's caller cleaned them up; the target is unknown
  either way); the number of words compared is the original's.
- The number of argument words compared is what the callee actually reads (a stack-depth scan of the
  callee, which follows indirect calls, `ebp` used as a general register and late register saves).
  Unused or dead arguments don't count. A callee our source declares with `...` is compared over the
  words each call site passes, also past an `equiv-conv`'s listed slots.
- Functions of our own object run in place: the words pushed for them are their arguments, and their
  prologue's register saves aren't arguments of the calls they make.
- **Callees that never return** (`longjmp`, Lua's `luaD_throw`, error helpers: no `ret` reachable, every
  path ends in `int3`, a call followed by `int3`, another such callee, or an indirect jump after reloading
  `esp`) end the run on both sides; it is compared up to and including that call, without return value or
  registers.
- A jump through a pointer read from memory is a tail call (unless it lands in the function's own body),
  in both runs.
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
  function never reads back (`left 0x7 in eax, expected 0xa8: ours is void, but the original returns a
  value there`).
- The x87 stack depth, `ebx/esi/edi/ebp` and `esp` after return.
- An argument pushed from a register whose last write set only its low byte(s) (`setcc al; push eax`, a
  `bool`) compares on those bytes only.
- Values that point into the stack compare as "a stack address". Floats stored by `fst`/`fstp` (on either
  side) and float arguments compare with relative tolerance 1e-5; a word that is the same normal float
  but for its last bit (rounded once more on one side, then copied through a register) is equal too.

An input on which the original doesn't return (step limit 50k, or the 1000-page limit) is inconclusive. If
the first 4 inputs all run out of steps, the rest get 1M steps (and 3x the time budget): long but
deterministic code such as string building. One where the original faults is compared up to the fault, but
not counted as a pass, and its branches don't count as covered. While fewer than 8 inputs have completed,
faulting inputs don't stop the search (up to 192 of them). The step budget isn't raised when the early
timeouts come from a `rep` string instruction with an absurd (fuzzed) count or from a loop that a stubbed
callee keeps going (hundreds of calls); and an input where such a fill or copy got through in the original
but our semantic copy hit the page limit is inconclusive.

**Return type** comes from our mangled name. For a C name it is inferred from the original's call sites.
If ours returns `void` but the original's direct callers read `eax` (or `st0`) after the call, the return
value is compared anyway, and `return_note` says so.

**Coverage** counts taken/not-taken for every conditional branch, 0/1 for every `setcc`, and every
jump-table case of the original. It comes only from inputs that ran to completion (not from faults).
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

Latest run (2026-10-12, checker round 3; samples drawn from the current `matches/`):

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
  - a write into the incoming argument slots goes to the same slot in ours;
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
  4 bytes that pops 8). The rest are not triaged yet.

**Limits.**
- Coverage is what one scripted session reaches: boot, front end, the opening and the junkyard tutorial.
- Writes a callee makes into the caller's frame through a pointer stored earlier (not passed in that
  call) can't be placed in our frame. Such calls go `incomplete` when the original depends on them.
- Uninitialised stack is `STACK_FILL` on both sides in replay, but the game's own bytes at capture.
- Threads and DMA writing memory during a capture show up as failed self-checks (about 1%).
- `equiv-conv` functions aren't replayed.

## Limits

- **Loops kept going by callees.** A loop that ends only through a callee's side effect (a teardown
  `while (head) remove(head)` over a global, a fixed 2048-slot loop with several calls per slot) still
  runs out of steps: 0x0024ad20 and 0x001dec10 stay unsupported.

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
