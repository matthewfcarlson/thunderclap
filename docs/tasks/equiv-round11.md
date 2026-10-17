# Equivalence checker round 11

Round 11 went after the last large unverified functions that fix batch fx10 traced to the checker: a stub that
popped a word the original had pushed for a later call, a long-code budget that early returns kept from firing, loop
bounds made of stub floats through `__ftol2`, an interpreter loop over fuzzed instruction words, and 137 list walks at
two compares. Two of the notes had the wrong cause. 0x002dbd90's `pow` results were never stub floats: `fld x; fld e;
call __CIpow` passes its arguments in x87 registers, the stub left them there, so `end = (int)(pow(...) * n)` was the
exponent times n on every row. And 0x00039c60 is not mainly slower-machine noise: round 10's `diffcount` (vector
counts of 1-4 from `(end - begin) >> 2`) took its coverage from 118 (round 9, and round 10 with `diffcount` off: 123)
to 96, on this machine as on mac1. A bigger time budget doesn't bring it back (`--time-budget 400`: 96; a smaller one
happens to give 107, its random phase handing over to the directed inputs after 2248 inputs).

Soundness rule (unchanged): a change may only steer inputs or make inputs inconclusive; it never relaxes the
comparison of a real difference. Changes 1 and 4 correct a stub's model of the stack (both sides alike: each side
still follows its own code), the rest choose inputs (memory, stack arguments, stub results), choose the step and time
budgets, or skip work; nothing is excluded and no edge is declared dead. Each change has a case in
`tests/equiv/cases/` that fails under the round-10 checker (`EQUIV_MODULE=equiv_r10 tests/equiv/regress.py`), and
`_wrong` cases show that the newly reached code catches a real difference. `EQUIV_OFF=name,name` switches each named
change off.

## Changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | 0x000e8790: `push 0; call [0x4de948]; ...; push ecx; call [esi+0x18]`. The global function pointer is fuzzed (not code), so the stub's arity came from the run's pushes: it popped the 0, which is owner->v6's second argument. The original's `mov [esp+0x10], eax` then hit its return address and every input past the early returns went wild. (`ptrpop`) | A call through a fixed pointer takes its stack use from the pointer's call sites across the image (`Program.ptr_call_pop`): a site with nothing pending on every path from its function's entry (`Program.pending_at`: pushes that aren't saves, minus pops, `add esp` and known callee pops) means the pointer takes no stack words, whatever its convention (pops none, pending words stay for the next call); a site with `add esp, N` right after the call means caller-cleaned. 0x4de948 has 22 call sites in listed functions, 14 with nothing pending. | `0x000e8790_ptr_noargs` (inconclusive 7/38 -> 38/38), `..._wrong` (a wrong second argument of the virtual call) |
| 2 | 0x003572b0: `if (start == 0) return;` then ~65k straight-line steps. The long budget (1M steps, 3x time) needed the first 4 inputs to time out; inputs 0 and 1 return in 6 steps. (`earlyret`) | While every input that ran out of steps did so in a loop over a constant count (each loop exit that ran at least half as often as the hottest compare has no input source), a random input whose original returns within 256 steps doesn't count: the budget is decided at the 4th other input (by input 16 at the latest), the revert check 4 inputs after that, the probe runs on the first input that ran out of steps (not input 0). Next to runaway loops over fuzzed counts an early return counts as before (0x002cb2b0: the long budget at input 5 cost 50 s and its coverage case dropped to 64%). | `0x003572b0_early_returns` (inconclusive, 20 early returns, 1/22 -> 21/22, 330 inputs), `..._wrong` (a wrong gradient offset in the tables) |
| 3 | 0x001e7470 (CSPManager's constructor, 4 KB, 10,700 stub calls an input): input 3 returns at 19k steps through a stub result of 0 that skips the slot loops, so the escalation never fired, and the step cut on the first runaway loop then made all 3002 others time out. (`constloop`, `longmore`) | When three of the first four ran out of steps, each in a loop that counts down from a constant (`mov ebx, 0x800; ...; dec ebx; jne`: the hot loop exits have no input source), the 8M-step probe runs; if it returns, the long budget applies. Long code gets up to 8x the time budget (not 3x) while fewer than 50 inputs completed and the original returns on four inputs in five. | (no case: one input takes 4-40 CPU s; work list: inconclusive 7/102, 1 input -> 102/102, 50 inputs, 742-1510 CPU s) |
| 4 | 0x002dbd90: `__CIpow` takes x87 register arguments (`fxch st(1); fstp [esp]; fst [esp+8]`); the stub treated values below st0 as kept across the call and pushed no result, so the "result" was the exponent. (`x87args`) | `Program.x87_args`: what a callee's first instructions read below the x87 stack it found (following a jmp thunk, at most 3). The stub pops those and pushes its float result (trampoline `fstp st(0)` x n, then the float load). | `0x002dbd90_ftol_unit` (with 5) |
| 5 | 0x002dbd90's 0x480 path: each of 256 rows has `end = (int)(pow((j + 0.5) / 256, 1 / d) * (count << 8))`; a stub float of 0..1000 makes `end` up to 65 million. (`ftolunit`) | A runaway loop whose exit compare has an operand `__ftol2` made from a stub's float result: that callee's float results are drawn in [0, 1] (0, 1, or a fraction) in three inputs in four, every call. A directed input's own float result for a call wins. | `0x002dbd90_ftol_unit` (48/80 -> 62/80), `..._wrong` (a wrong table value in the 0x480 path) |
| 6 | 0x0026bac0 (dlmalloc mallinfo): 10 null-terminated fastbins and 127 circular bins at one compare, sentinel = the bin; fuzzed nodes are shared between bins (and with the heap pointer null-ish, every link is 0 and every bin's walk goes through node 0), so a link planted with one bin's sentinel sent another bin's walk elsewhere, and the input with the plants ran away where the discovery run didn't. A node linked to itself and a sentinel in the zero page were not taken for walks at all. (`walkheads`, `walknolong`) | A discovery run never plants a link another walk loaded before, ends a walk at the link before one loaded before (the link offset learned from two rounds), and empties a walk at its top test (`cmp eax, edx; je` before the loop: the bin's own link gets the sentinel) when its first node's link was loaded before. A self-linked node and a sentinel below 0x10000 count as walks. When the first four inputs all ran out of steps in detected walks, the 1M-step budget is skipped (4 x 1M-step runs that only go round a cycle). | `0x0026bac0_walk_heads` (unsupported -> 14/14, 116 inputs, 44 s), `..._wrong` (a wrong chunk count) |
| 7 | 0x002142d0 (luaG_symbexec): fuzzed instruction words rarely pass `op < 0x24`, `a < maxstacksize` and the per-mode checks, and few inputs reach the loop at all (the bases word plants start from come from four inputs). (`opwords`) | `_word_models`: a word loaded from an array by index that three or more compares test through different field extractions (one a switch, or four in all) is an instruction stream; each extraction gets the values its compares name (every switch case, 0..bound+1, around a constant, below a memory value, 0-3). Directed inputs plant runs of 1-8 such words from the first word a completed input read there, in every epoch; a word another compare of that input read keeps the value that compare saw (the RETURN check of `code[sizecode - 1]`), a loop bound in a stack argument below the run is raised, half the runs have every stub return normally or 1. At most 30% of the time budget. | `0x002142d0_op_words` (45/120 -> 92/120), `..._wrong` (a wrong pc passed to FUN_00214250 in the newly reached case 25) |
| 8 | 0x00039c60: round 10's `diffcount` plants vector counts of 1-4; the tie-break network over the vector's elements reaches its later compares with more. (`diffwide`) | One difference plant in four is 5-12 elements. | (work list; 96 -> 113/152) |

Not changed:

- **0x00039c60's last edge.** 113/152 (74.3%) against 118 under round 9 and 123 with `diffcount` off: one edge
  short of the bar. Steering small-count observations out of the directed phase's six per compare (tried) changed
  nothing; the remaining gap is the directed inputs round 10's small vectors take from the tie-break compares.
- **0x001e7470's speed.** 4-5 CPU s an input, 37 s for dictionary-memory inputs (every one of 10,700 stub calls
  remaps the pages the constructor touches, and dictionary pages are planted in Python). Change 3 gives it the long
  budget and up to 8x the time. In a CPU profile of one dictionary input (input 14), `_close_segment` took 47 s and
  `compare_runs` 32 s: the per-stub snapshot and comparison are the next thing to make faster.

## Validation (2026-10-16)

- `tests/equiv/regress.py --jobs 2`: 145/145 (135 old + 10 new). Under the round-10 checker all 10 new cases fail
  (`EQUIV_MODULE=equiv_r10 ... --only`): `0x000e8790_ptr_noargs` inconclusive 18%, `0x002142d0_op_words` 38%,
  `0x0026bac0_walk_heads` unsupported, `0x002dbd90_ftol_unit` 60%, `0x003572b0_early_returns` inconclusive 5%, and
  round 10 catches none of the five `_wrong` guards (the same statuses), while round 11 fails all five. A first full
  run had `0x002cb2b0_loop_exit_order` at 41% (64% alone, 77% under round 10): change 2 gave a function whose early
  inputs return in 61 steps next to runaway loops over fuzzed counts the long budget; restricted to constant-count
  timeouts (above), it is back at 77%, and the second full run is 145/145. With
  `EQUIV_OFF=ptrpop,earlyret,constloop,longmore,x87args,ftolunit,walkheads,walknolong,opwords,diffwide` the round-11
  checker gives round 10's result input for input (0x000e8790 2992 inputs 7/38, 0x002142d0 3136 45/120, 0x00039c60
  3149 96/152). `tests/equiv/test_equiv.py`: 12/12.
- `tests/equiv/selftest.py` (300 matches): 297/300. The sample has changed with `matches/` since round 10 (the two
  known failures 0x00094540 and 0x00155090 are no longer drawn); the three failures, 0x00091030, 0x00153fd0 and
  0x001540b0, are the same kind (`call #1 went to 0x6fff0000`, an unresolved destructor in the current tree) and fail
  identically under round 10.
- `tests/equiv/mutate.py` on the pinned 120: 303 caught, 8 commutes pass, 2 equivalent mutants, 6 false passes, 0 false
  failures (37 don't compile, 63 compile to the same bytes): identical to round 10 mutant by mutant (all 419). No new
  false passes.
- The work list (sources snapshotted at the start: fx10's `work/fx10/` for 0x000e8790, 0x002142d0, 0x0026bac0,
  0x002dbd90, 0x003572b0; `pass/` for 0x001e7470 and 0x00039c60), `--inputs 3000`, default flags, round 10 and round 11
  on the same machine (load 6-9):

  | Address | Round 10 | Round 11 | Promotable now | Change |
  |---|---|---|---|---|
  | 0x000e8790 | inconclusive 7/38 (11 wild) | 38/38, 3044 inputs, 5 s | yes (new) | 1 |
  | 0x003572b0 | inconclusive 1/22, 20 inputs | 21/22, 330-468 inputs, 361 s | yes (new) | 2 |
  | 0x001e7470 | inconclusive 7/102, 1 input | 102/102, 50 inputs, 742-1510 CPU s | yes (new; exactly 50: `--time-budget 300` for margin) | 3 |
  | 0x002dbd90 | 48/80, 267 inputs | 62/80 (77.5%), 106 inputs | yes (new; borderline, `--time-budget 300` for margin) | 4, 5 |
  | 0x002142d0 | 45/120 | 92/120 (76.7%), 4477 inputs, 11 s | yes (new) | 7 |
  | 0x0026bac0 | unsupported (3165 timeouts) | fail: `returned 0x00000000, expected 0x4002...` (a real difference: mallinfo returns its struct by value) | with the by-value source: yes (14/14, 116 inputs) | 6 |
  | 0x00039c60 | 96/152 (round 9: 118) | 113/152 (74.3%) | no (one edge short) | 8 |

  All with the default flags (`--inputs 3000`). 0x0026bac0 needs a source fix (the round-11 case has it:
  `HeapStats FUN_0026bac0()` with `return stats;`).
- `equivalent/`, a random 300 (`random.Random(2035).sample` of the sorted list, 4658 files, snapshotted) at
  `--inputs 3000`: 296 promotable. No newly failing file: all four others get the same result under round 10.
  0x00122520 fails (`call #14 to 0x3a83126f: the local passed as argument 7 differs at +0x0 (0x1, expected 0x80000)` on
  262+patch; the committed `HEAD` copy fails the same way under round 10: a pre-existing failure to triage).
  0x00242da0 is inconclusive (17 completed inputs, 3169 timeouts; its header records 50 inputs, 30/30), 0x00094fb0
  has 8 completed inputs (a registration constructor like 0x001e7470 whose timeouts are not all constant-count
  loops), 0x000eca60 has 48 wild inputs (17/20), each identical under round 10.

## What's left, ranked

1. **0x00039c60** (113/152): round 10's vector counts of 1-4 starve the directed inputs of the tie-break network; one
   edge short. Next step: directed patches of an element's rank across a run that kept its fuzzed vector size.
2. **Per-stub cost** (0x001e7470: 10,700 stub calls an input; 0x00094fb0 the same shape, 8 inputs): `_close_segment` compares every mapped page after
   every call, and dictionary pages are regenerated in Python for every epoch.
3. **Interpreter words** (0x002142d0 92/120): the last 28 edges need consistent sizes (`sizecode` past the words
   planted, a RETURN at `code[sizecode - 1]`, CLOSURE's `p[b]->nups` upvalue words).
4. Unchanged from round 10: frame-array overruns behind a loop counter (0x00282d00's pre-fix shape), red-black fix-up
   sides (0x002639c0), x87 precision at fuzzed extremes.

## Recipes for batch agents

- **Re-run before rewriting.** Sources stuck on a call through a global function pointer followed by a virtual call
  (`fn() ... obj->v(x, 0)`, going wild), on `pow`/`sqrt`-style intrinsics feeding loop bounds (`__CIpow`), on
  long constructors that register thousands of entries, on interpreter loops over instruction words, and on many list
  walks at one compare (allocator statistics) are now steered: re-run them at `--inputs 3000` first.
- **Declare a function-pointer global with its real type** (`extern float (__cdecl *DAT_004de948)();`): the checker
  takes the original's stack use from the pointer's other call sites, and ours follows our declaration; a wrong
  declaration now shows as a stack difference.
- **`mallinfo`-style returns.** A function that returns a struct by value returns the hidden pointer in `eax`; a
  source that takes an out-pointer and returns `void` fails with `returned 0x0, expected 0x4002...` once the checker
  gets through (0x0026bac0: `HeapStats FUN_0026bac0()` passes, `void FUN_0026bac0(HeapStats *)` doesn't).
- **Long code** (thousands of stub calls an input) can take up to 8x the time budget by itself now; don't pass
  `--steps`. If it still reports fewer than 50 inputs, add `--time-budget 600`.
- **`N+words` inputs** are planted instruction streams: a failure on one is a real difference on a well-formed
  program.
