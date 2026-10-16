# Equivalence checker round 9

Round 9 went after the functions of 100 bytes or more whose sources never disagree with the original but miss
the promotion bar (75% branch coverage, 50 completed inputs). Each cluster of the work list was reproduced on
a snapshot of its source, and the compare the fuzzer or the directed phase failed to satisfy was traced in
the original (the observation the directed phase had for it, and what its patches did). Several log notes had
the wrong cause: 0x0010b5b0's `F == 0.0f` was a stub float stored and reloaded (its source was lost at the
`fstp`), but the branch also needed `bl`, a flag set from a u64 compare two blocks earlier; 0x0015d920's byte
out-parameter is one the function sets to 0 itself, which the stub model deliberately leaves alone;
0x002de030's fourCC sits at +0x48 of a 124-byte read whose stub fills 16 bytes; 0x000e36c0 spent 100 of its
120 s in the 8M-step probe.

Soundness rule (unchanged): a change may only steer inputs or make inputs inconclusive. It never relaxes the
comparison of a real difference. Every change below only chooses inputs (memory, stub results, stub fills):
both sides always see the same input. Each has a case in `tests/equiv/cases/` that fails under the round-8
checker (`EQUIV_MODULE=equiv_r8 tests/equiv/regress.py`), and `_wrong` cases show that the newly reached code
catches a real difference. `EQUIV_OFF=name,name` switches each named change off.

## Changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | A float's source was lost at every step but a load: `call f; fstp [esp+0x40]` ... `fld [esp+0x40]; fucompp` (0x0010b5b0 `F == 0.0f`); `fst [esi+0xb4]; fld [pi/2]; fsubr st(1); fstp [esp+8]; and [esp+8], 0x7fffffff; fld; fcomp [eps]` (0x00083e60); the mask in a register (`and [esp+4], edx`, 0x000c8f50); a clamp times a step plus a field (`fmul st(1); fadd [ecx+0x218]`); the cHRM `fabs(x - c) >= tol` chain (0x002e8f80). A computed operand had no value, so a stub float compared with `fld [k]; fmul [4.0]` couldn't be steered either. An x87 store into a stack word left the word's earlier integer source in place (a stale source, planted in vain). (`fprov`) | A steerable float keeps its source through `fst`/`fstp` to memory and the reload (dropped when anything else writes the word, at a stub fill, and for non-stack memory at each new epoch), register-form arithmetic with a value known at that point (decided by opcode bytes: D8/DC/DE, sub vs subr), `fabs`, a fabs mask in memory (immediate or register), a computed value plus/times a steerable memory float, and `fld st(i)`. The transforms are inverted (`fdiv`, `fdivr`, `fabs` added); targets halfway and one and a half times the other value come first after a fabs (`|x - c| < eps` with eps < 1: +-1 lands on the far side). A computed operand's value is read from the x87 registers. x87 stores end a stack word's integer source. | `0x00083e60_fabs_fret` (7/10 -> 10/10), `0x000c8f50_fabs_reg_mask` (11/18 -> 17/18), `0x002e8f80_chrm_chain` (22/38 -> 38/38) |
| 2 | `call f; call __ftol2; test eax, eax; jle; cmp eax, 8; jge` (0x000f3dc0): `float_ret_after` stopped at the helper call, so the stub returned no float and `__ftol2` converted an empty x87 stack (0x80000000, always `<= 0`). (`ftolret`, `ftolsrc`) | A call to `__ftol2` with nothing of the caller's on the x87 stack consumes the previous callee's float result (`ftolret`). The integer `__ftol2` returns keeps the float's source and transforms; an integer target w plants w + 0.5 (w - 0.5 below 0) through them (`ftolsrc`). | `0x000f3dc0_ftol_range` (14/20 -> 20/20), `..._wrong` (`n >= 0` for `n > 0`: fails) |
| 3 | `|sqrt(x*x + y*y + z*z) - 1| < eps` and `|dot| < eps` on a matrix's rows (0x0022cf90): computed from nine fields, no single word to invert, and the stub-float fallback had no stubs to set. (`memfloats`) | The floats the x87 read from memory (outside the stack, patchable) are listed in the compare's observation; when it is computed and no patch inverts it, they are planted as an identity matrix (1 every fifth word from the lowest of a 64-byte cluster), all 1 and all 0. After the stub-float plants when the run made calls. | `0x0022cf90_matrix_rows` (5/12 -> 11/12) |
| 4 | 0x000c8f50 under change 1: the directed phase planted the 0.02 the original keeps in `.data` (`fcom [0x49fbc4]`), a literal in ours: the original alone changed, 3 false failures. Round 8 could plant it too (it just never got there first). (`ourglobal`) | A fixed-address word in the image is planted only within 0x100 bytes past a data symbol our object references (bound by level 2). | `0x000c8f50_fabs_reg_mask` |
| 5 | `cmp eax, [g]; jne L; cmp edx, [g+4]; jne L; mov bl, 1; jmp M; L: xor bl, bl` ... calls ... `test bl, bl; je` (0x0010b5b0): `bl` has no source, so nothing steered it, and both inner compares were already covered (by runs that returned early). (`via`, `chain`) | A register set to a constant within 3 instructions of a jcc (the start of a branch side) or by a setcc carries the compare that decided it; a compare on it with no source of its own is steered through that compare (`via`). Only after the direct patches are used up, at most 3 tries per (compare, deciding compare) unless one finds an edge, and never in loop repair (an inner loop over a constant bound must stay unpatchable there: 0x002c96e0 lost 13% with it). A directed input that reaches a compare with a side still missing in a new way (another source kind, transform or deciding compare) keeps its observation past the first six (`chain`), so the next condition (`edx == [g+4]`) is steered from the run that satisfied the first. | `0x0010b5b0_flag_via` (27/43 -> 40/43) |
| 6 | `lea edi, [esi+0x1f58]; call f; call g; ...; jne; ...; test edi, edi; je` (0x0010b5b0 +0x194, declared dead by hand): the round-7 rule only looked at straight-line code. (`leaflow`) | A forward data flow keeps, per register, the lea that set it on every path (copies follow); a call ends it for eax/ecx/edx only: keeping the value in ebx/esi/edi/ebp across a call is the original's compiler relying on the callee preserving it. | `0x0010b5b0_flag_via` (no `equiv-dead` line) |
| 7 | A Lua binding's signature loop (0x001d22a0): `movsx eax, sig[i]; add eax, -0x56; cmp eax, 0x20; ja; movzx edx, byte [eax + map]; jmp [edx*4 + tab]`. Alphabet strings needed a plain byte compare; the char is read after a call (`lua_type(L, i)`), in a new epoch each round; the result loop's buffers used up the plants first. (`alphaxf`, `alphaep`, `alphasite`, `strrr`) | A char minus a constant joins the alphabet as the char it means (`alphaxf`), and so does one char per case of a byte-table switch on a loaded char, whose buffer becomes a planting site. Alphabet strings are planted in that epoch and every later one (`alphaep`), the "twice per alphabet" limit is per compare site (`alphasite`), and string plants go round robin over the sites queued (`strrr`). | `0x001d22a0_sig_switch` (28/51 -> 48/51), `..._wrong` (Lua type 4 for `'f'`: fails) |
| 8 | The first execution of a compare is its observation; when that compared constants (a loop's default, `mov al, 0x76` past the string's end) and a later round compared input data, the compare stayed unsteerable. (`obslater`) | A later round with an input source replaces a first one without (jcc and jump tables; not when the compare's second round is already recorded, which loop repair pairs with the first). | `0x001d22a0_sig_switch` |
| 9 | `k = node->f(); if (k != wantType) return; switch (k) { case 8..12 }` (0x0004cbe0): a patch to make `k` fall in the switch broke the equality, and the other way round. (`eqlink`) | Two input sources a run found equal (`cmp` of two plain loads, equal values) are linked; a patch to one adds a variant that moves the other to the same value. | `0x0004cbe0_eq_range` (9/18 -> 18/18), `..._wrong` (the source's `1.5708f` for pi/2: fails on the newly reached case 10) |
| 10 | `char hit = 0; this->v8(&a, &b, &hit); if (hit)` (0x0015d920): the stub fills a byte out-parameter only when the function hasn't written it (an initialised neighbour must survive); `hit` was always 0. (`pfill`) | Random inputs keep that rule. A directed input can have the callee write such a byte: the compare's source is (call, argument), and both sides get the byte written through that argument, whatever its alignment on each side. | `0x0015d920_byte_outparam_set` (45/70 -> 70/70), `..._wrong` (swapped `atan2` arguments in the newly reached half: fails) |
| 11 | `read(&hdr, 0x1f, 4, 1)` fills 124 bytes; the DXTn fourCC at +0x48 decides a switch (0x002de030), but a stub fills 16 bytes behind an unknown pointer (`ARRAY_WINDOW`), so the word held `STACK_FILL` on both sides. (`xfill`) | A stack word nobody wrote, within 4 KB past a local passed to a callee by pointer (the nearest one below it), read after that call, gets the source (call, argument, offset); a directed input has the stub write it on both sides, where each side's frame has room. | `0x002de030_fourcc_fill` (inconclusive 8/35 -> 35/35) |
| 12 | Loops over fuzzed counts: 0x000e36c0 (128 groups, each an array-new'd array whose count is the word before it), 0x000b1db0 (56 copy loops): every input ran away; loop repair fixes one loop per run, 4 deep, 64 runs per function, and the 8M-step probe took 100 s. (`smallcount`) | The loads that fed a runaway loop's bound (a register's last load, through stack copies and `lea`/`dec` derivations) are remembered. A timed-out input gets a discovery run of the original in which those loads read 1-4 where the word was larger, then runs again with those values in its memory, on both sides; a run that hangs in another loop learns its load too (8 rounds, 64 once it works). Once two inputs got through this way and at least half the rounds succeed while most inputs run away, 3 in 4 inputs (7 in 8 when 90% run away) start this way. The step probe is skipped when it already got input 0 through. Directed inputs that run away get it before loop repair. It stops after a quarter of the time budget without a completion, or a tenth with fewer than 1 in 4 rounds completing. | `0x000e36c0_small_counts` (unsupported -> 8/8, 63 inputs) |
| 13 | `--inputs 12000` covered less than 3000 on slow functions (0x001b4d00): after the first directed phase the random inputs ran until the time budget, and the directed inputs after them never ran. (`morein`) | Past 3000 random inputs, they stop at 80% of the budget; the directed inputs run, then more random inputs if time is left. | (A/B below; no case: needs minutes) |
| 14 | The text header said `FAIL ... level 2` for a level-3 mismatch (`level` is the highest level passed). | `failed_levels` in the report; the header says `fails level 3 (passes level 2)`. | `tests/equiv/test_equiv.py` `test_fail_header_names_level` |

Not changed:

- **Work item 5, stale high bytes of byte locals passed to a register-convention writer (0x0021ab30).** The
  callee is reached through a function pointer (Lua's writer callback); how many bytes it reads isn't known
  statically, so the bytes stay compared. fx8a fixed the source instead (one `union { int; uchar }` scratch
  slot, as the original reuses the dead argument slot; the callees declared `__stdcall`): 8/8, 3000 inputs.
- **Work item 9, fuzzed stack-array indices (0x000dcae0).** An indexed store below the array's lowest
  element can't be told from a valid access when MSVC folds a constant into the displacement (`cells[i + 1]`
  is `[esp + i*16 + base + 16]`, so `i == -1` is element 0), so the input can't be proven undefined
  behaviour. Unchanged (0x0028a630 was a source bug, fixed by fx8b; 0x00282d00 unchanged).
- **0x002142d0 (luaG_symbexec).** Only one random seed enters the bytecode loop at all, and the patched
  opcodes die in the per-op argument checks before the switch; needs a bytecode-aware plant. Unchanged
  (45/120).
- **0x00039c60 (tie-break network).** 86 -> 95/152 from changes 1 and 5; the rest needs two ranks equal in a
  later loop round (per-iteration observations, round 7 item 1).

## Validation (2026-10-15)

- `tests/equiv/regress.py`: 125/125 (110 old + 15 new cases). Every new case fails under the round-8 checker
  (`EQUIV_MODULE=equiv_r8`) except `0x000f3dc0_ftol_range_wrong`, which round 8 catches too (it guards change
  2). Three old cases changed because newly reached code showed real differences in their sources:
  `0x001ff770_strcmp_chain` (the source has `curBucket` at +0x234, the original reads +0x230; fixed in the case
  with `buckets[7]`), `0x002cb2b0_loop_exit_order` (seed 128 with small counts shows a write the source misses:
  the case stops at seed 128) and `0x0003c1d0_count_cap` (input 2551+small: -inf where the original stores
  -5.3e33; the case stops at seed 2500). `tests/equiv/test_equiv.py`: 12/12.
- `tests/equiv/selftest.py` (300 matches): 298/300. 0x00094540 and 0x00155090 (scalar deleting destructors:
  `??1Function@@UAE@XZ` / `??1ParamValueFloat@fight@@UAE@XZ` unresolved, call #1 goes to our object) fail
  identically under round 8: a ground-truth change in the current tree, not this round.
- `tests/equiv/mutate.py` on the pinned 120 (round 6-8's list, from `build/equiv/mutants.jsonl`): identical to
  round 8 mutant by mutant: 303 caught, 8 commutes pass, 2 equivalent mutants, 6 false passes, 0 false failures
  (37 mutants don't compile, 63 compile to the same bytes). No new false passes.
- `equivalent/`, a random 300 (`random.Random(2033).sample` of the sorted list, 4603 files) at `--inputs
  3000`, locally: 299 equivalent, 294 promotable. 0x0028e160 fails, identically under round 8 (the round-6
  compiler-temporary case: "call #12 to 0x002647e0: the local passed as argument 1 differs at +0x0"). Below
  the bar under both checkers alike: 0x0025a610 (25/40), 0x002ee570 (9 inputs), 0x000becd0 (21/32),
  0x001e4490 (8 inputs). **0x002cb2b0 is borderline**: 281-296/382 under round 9 vs 296-307 under round 8
  (73.6-77%; small counts take some of the budget of this 7 KB emitter); use `--time-budget 300` when
  re-promoting it. Outside the sample, **equivalent/0x001ff770 now fails** (the `curBucket` offset above)
  and equivalent/0x0003c1d0 can (input 2551+small).
- The work list (sources snapshotted at the start; the 5 already fixed by fx8 included), `--inputs 3000`,
  round 8 -> round 9, both run side by side under the same load. Newly promotable (default flags, `--inputs
  3000`):

  | Address | Round 8 | Round 9 | Change |
  |---|---|---|---|
  | 0x002e8f80 | 22/38 | 38/38 | 1 |
  | 0x0010b5b0 | 27/43 | 40/43 (remove its `equiv-dead` line or keep it) | 1, 5, 6 |
  | 0x00083e60 | 7/10 | 10/10 | 1 |
  | 0x000f3dc0 | 14/20 | 20/20 | 2 |
  | 0x000c8f50 | 11/18 | 17/18 | 1, 4 |
  | 0x0022cf90 | 5/12 | 11/12 | 3 |
  | 0x001d22a0 | 28/51 | 48/51 | 7, 8 |
  | 0x002de030 | inconclusive 8/35 | 35/35 | 11 |
  | 0x00039c60 | 86/152 | 118-119/152 | 1, 5, 9 |
  | 0x0015d920 | 45/70 | 69-70/70 | 10 |
  | 0x000e36c0 | unsupported | 8/8, 50-63 inputs | 12 |
  | 0x000b1db0 | unsupported | 52/56, 114-224 inputs (~90 s) | 12 |

  Reached code that fails (source bugs): **0x0004cbe0** 9/18 -> 17/18 but fails on case 10: `1.5708f` must be
  `1.5707964f` (pi/2 as the original's constant at 0x3f6b1c; with it, 18/18 equivalent). **0x0010b5b0**: on
  some runs `call #9 to 0x00035550: the local passed as argument 1 differs at +0x8`: the original passes the
  reused `tp` slot (stale `aim.z` at +8) for `vf`; give `vf` the original's storage.
  Already promotable under both (fx8 fixed the sources): 0x000a5a90 55/56, 0x000c21b0 128/136, 0x0021ab30 8/8,
  0x0028a630 6/6, 0x0019e910 369-378/432 (the +0x1d62 gate: see "What's left" 1).
  Not promotable, unchanged: 0x001b4d00 64 -> 80-81/122 (66%), 0x002dbd90 48/80, 0x001fe380 26/46 (19
  inputs), 0x002639c0 36/52, 0x0024a800 44/56 (42 inputs), 0x002142d0 45/120; failing as before: 0x000dcae0
  (now on `734+small`, the same fuzzed-index class), 0x00282d00 (input 54 and two small-count inputs, the
  fuzzed-segs wrap).
- **`--inputs 12000` vs 3000** (0x001b4d00): 63/122 at both under heavy load (it was 73 vs 87 in the log);
  coverage of this function swings 63-87 with CPU contention under every checker version.

## What's left, ranked

1. **Loops whose bound is re-read after every call** (`for (i = 0; i < (v.end - v.begin) / 4; i++) call()`:
   each round sees fresh memory). Small counts plant raw words, not a difference of two loads; loop repair
   patches one epoch. 0x0019e910's gate at +0x1d62 is now steerable (a stub's float against `ffc * ffc *
   4`, read from the x87 registers; a stale stack source cleared), and the directed input that opens it
   exists (fret -1.0), but the run behind it hits the 256-round cut of the vector loop at +0x2362 and the
   loop at +0x1b08. Next step: plant `end = begin + 4k` in every epoch from the observation's `add` transform.
   Same class: 0x002dbd90, 0x001fe380 (O(n^2) pair loops, 16 inputs), 0x002639c0, 0x0024a800 (42 inputs).
2. **Fuzzed stack-array indices** (0x000dcae0, 0x00282d00; unchanged): not provable undefined behaviour (see
   "Not changed"). 0x00282d00 now reaches its known failure (input 54) and two small-count inputs like it.
3. **Bytecode-shaped inputs** (0x002142d0, 45/120): an opcode plant needs the operand fields valid for that
   opcode's checks; a per-opcode template from the checks the run passed is the next step.
4. **Per-iteration observations** (unchanged): 0x00039c60 119/152 is now promotable, the tie-break network
   still needs two equal ranks in different rounds.
5. **Boundary values on covered compares**: a compare whose two sides were both taken 4 times is never
   steered to the tie (`n < 8` vs `n < 9` differ only at 8). The rare-hit pass runs only once every edge is
   covered.
6. **x87 precision at fuzzed extremes**: 0x0003c1d0 (input 2551+small, -inf against -5.3e33) is the
   80-bit-intermediate class; a source fix (`volatile float`) or accepting overflow to inf as a tolerance
   case would need a rule that can't hide a real difference.
7. Unchanged from round 8: compiler temporaries in compared extents (0x00359510, 0x000c1b50, 0x0028e160).

## Recipes for batch agents

- **Re-run before rewriting.** Sources stuck on float compares (`fabs(x - c) < eps`, stub floats stored and
  reloaded, `__ftol2` ranges), flags set from earlier compares (`bool ok = a == b; ... if (ok && ...)`),
  byte-table switches on string chars, byte out-parameters the function initialises (`char hit = 0;
  f(&hit)`), header fields past 16 bytes of a `read(&buf, count, size)`, `k == field && k in 8..12`, and loops
  over fuzzed counts (array-new destructors, copy loops) now get steered: re-run them at `--inputs 3000`
  first. On the work list, 12 sources became promotable this way (17 of 26 now pass the bar).
- **Newly reached code fails more.** Expect real differences on paths no input reached before: 0x0004cbe0
  adds `1.5708f` where the original adds pi/2 (`1.5707964f`, read the constant from the original),
  equivalent/0x001ff770 has `curBucket` at +0x234 (the original reads +0x230), 0x0010b5b0's `V3 vf` slot
  (the original passes the reused `tp` slot to FUN_00035550: a stale-word compare, give the local the
  original's storage). A failing input labelled `N+small` ran with small loop counts in its memory; it is a
  normal input (both sides saw the same memory), not a checker artefact.
- **`equiv-dead` for `lea reg, [esi+N]` ... `test reg, reg`** across calls and branches is no longer needed
  (0x0010b5b0 +0x194 is dead automatically); keep such lines only for value-range dead edges.
- **`inputs_small`, `probe_skipped`** in a report: the small-count steering ran. Loop-heavy functions can
  now complete 50 inputs at the default budget (0x000e36c0: 63, 0x000b1db0: 224); don't add `--steps`.
- **`--inputs 12000`** no longer covers less than 3000 for lack of time for the directed inputs, but
  coverage still depends on CPU contention: compare runs made under the same load.
- **`FAIL ... fails level 3 (passes level 2)`**: the header now names the failing level; `failed_levels` in
  the JSON.
