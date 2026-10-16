# Equivalence checker round 10

Round 10 went after the largest functions still unverified that the checker, not their sources, held back:
loops whose bound is re-read after every call, a Lua loop over a difference of a stack argument, a load and a
register, walks over fuzzed links that never reach their sentinel, and stack-array indices a stub filled. Each
was traced on a snapshot of its source with a per-run log of the original (status, steps, hottest compares, what
each discovery run planted). Two notes had the wrong cause: 0x001fe380's "O(n^2) pair loops" are cheap once the
80 counted lists collect few points, but counts of 1-4 still collect the 160-point maximum; 0x002639c0's descent
got its plants and ran away anyway, because fuzzed nodes alias (one node's link is another's key, read before
the plant). The three 64-300 B "equivalent under 75%" entries of the log are stale: their `equivalent/` sources
pass the bar under round 9 already.

Soundness rule (unchanged): a change may only steer inputs or make inputs inconclusive. It never relaxes the
comparison of a real difference. Every change below only chooses inputs (memory words, stack arguments, stub
fills), which both sides see alike; nothing is excluded and no edge is declared dead. Each change has a case in
`tests/equiv/cases/` that fails under the round-9 checker (`EQUIV_MODULE=equiv_r9 tests/equiv/regress.py`), and
`_wrong` cases show that the newly reached code catches a real difference. `EQUIV_OFF=name,name` switches each
named change off.

## Changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | `v = FUN_002ed700(); for (i = 0; i < (v->end - v->begin) >> 2; i++) { ...calls... }` (0x001b4d00, 0x0019e910's +0x2362 loop, the same vector in both): `mov eax, [ecx]; mov edx, [ecx+4]; sub edx, eax; sar edx, 2; cmp ebx, edx; jb`, re-read in a new memory epoch after every call. Round 9's small counts planted the `end` word as 1-4, which made `end - begin` negative (a huge unsigned count), and loop repair patches one epoch. (`diffcount`) | A tracked register that a `sub` of another register or memory word turns into a difference keeps that `sub` (`dpc`). When a runaway loop's exit compare has such a bound, the discovery run plants at the `sub`: the end word (a plain load in this epoch, or a stack argument) becomes `begin + d`, where `d` is what the transforms after the `sub` (`sar 2`, magic divisions, `add -nfixargs`) turn into a count of 1-4; the register follows. Each epoch gets its own plant, relative to that epoch's begin. When the end word can't be planted, the begin word moves instead (`sub eax, [esi+8]`, or a register loaded plainly). | `0x001b4d00_vector_bound` (81/122 -> 120/122), `..._wrong` (a sign error in the newly reached knockback code: round 9 passes it, round 10 fails it) |
| 2 | Lua `adjust_varargs` (0x002155f0, "unsupported"): `missing = nfixargs - (L->top - base) / 8` with `nfixargs` a stack argument, `base` in `edx` (equiv-conv) and `top` a load; the nil fill `do { top->tt = 0; top++; } while (--missing)` writes as it runs away and ends in `too_many_pages`, not a timeout, so small counts never started. (`diffcount`, `smallpages`) | Change 1 plants the stack argument (`missing` becomes 1-4) or, on the other path, `top = base + 8 * (nfixargs + k)`; stack-argument plants go into the input's patch. A run that runs out of pages counts as running away for small counts (`smallpages`). | `0x002155f0_diff_bound` (unsupported -> 12/12, 50 inputs), `..._wrong` (a wrong nil tag in the fill loop: round 9 can't run it, round 10 fails it) |
| 3 | Tree and list walks over fuzzed links (0x0024a800: `while (n->left != &scene->childNil)`, `Successor()` walks, and `while (e) { f(e); e = e->next; }` with a call per entry, so each link is read in a new epoch): the walk sentinels of round 7 (the fixed pointer planted in half of every data page) gave up after 4 runs, and small counts planted 1-4 into the links (null-page pointers that link to themselves). (`walkend`) | A runaway loop's exit compare whose one side held a pointer fixed over two rounds while the other, a plain load, moved (`cmp eax, ecx` with `ecx = &tree.nil`), or `test r, r` on a moving heap link, is a walk. The discovery run plants, after 1-3 rounds, the sentinel (or 0) into the link the compare just loaded, in whatever epoch it was read in, and the register follows; its link loads are no longer planted as counts. A discovery run that returned while the input with its plants ran away (a planted link was also read before the plant, as a key of an aliasing node: 0x002639c0) gets up to two more discovery runs from its plants. | `0x0024a800_walk_end` (44/56, 42 inputs -> 52/56, 59-90), `..._wrong` (`e->state != 1` for `== 0`: round 9 passes it, round 10 fails it) |
| 4 | 0x001fe380: 4 classes x 20 lists, each with a fuzzed count, collect up to 160 points (one virtual call each), then an O(n^2) pair loop with a call per pair. Counts of 1-4 (only where the word was over 16) still give 160 points, 12720 pairs, and the run hits the cumulative 256-round cut of the pair loop or the step budget; the pair loop's bound is a stack local, nothing to plant. (`tinycount`) | When a small-count round still runs away and learned no new count load, one more round plants 0 (three in four) or 1 at every count load whose word is over 1, and at every difference bound. Once two inputs got through that way, small counts start with it. | `0x001fe380_tiny_counts` (26/46, 29-34 inputs -> 39/46, 79), `..._wrong` (a swapped coordinate in the pair loop's result; round 9 catches it too, on 4 inputs) |
| 5 | `mov eax, [esp+0xa0]; shl eax, 4; fstp [esp+eax+0x20]` (0x000dcae0, round 8-9's "fuzzed stack-array index"): the index is a count FUN_000f7fe0 fills into the `Lay` object on the stack; a fuzzed -1 stores 16 bytes below the cells, onto the original's spilled loop counter, which no other frame layout can agree on (input 734+small). (`idxfill`) | A stub-filled word (call, argument, offset) that the original uses as the index of an indexed access to its own frame is drawn as 0 or 1 in every later input (a directed input's own value for that fill wins, so a compare on it is still steered both ways). Steering, not exclusion: no input is set aside, and inputs before the fill was seen keep their values. | `0x000dcae0_fill_index` (fail -> 38/38), `..._wrong` (a wrong constant stored into the indexed cell; caught by round 9 too) |

Not changed:

- **Work item 3, 0x0028e160 (compiler temporary in the dead `parent` argument slot).** Left failing: the pre-call
  contents are observable. FUN_002647e0 (29 bytes at 0x2647e0) is `if (!stream->open) return 0; else jmp
  read...`: `mov al, [ecx+0xc]; test al, al; jne; xor al, al; ret 0x10`, so on a closed stream it returns without
  touching the buffer, and 0x0028e160 never tests `al` after the call. The buffer then still holds what was there
  before: 4 (the unrolled loop's bound the original stored at +0x112, `mov [esp+0x30], ecx`) in the original, the
  stale `parent` pointer in ours, and the next `obj->f4 = *pval` stores it. The callee writes before reading only
  when the stream is open, so no byte of the buffer can be excluded. Source fix for a batch agent: store the
  bound into that slot as the original does (`*pval = <bound>` where the unrolled loop starts; the source already
  uses `pval = (int *)&parent`).
- **Work item 4, 0x00282d00 (CMotionTrail::vfunc_6).** Not a stub fill: the index of `f.r1.uv[i].v = t` is the
  loop counter, bounded by `this->segs`, a heap word read once; `segs` in 7..~20 writes past `uv[6]` into the
  other locals of the frame (input 54: "missing write to 0x00000008 before call #8"; 29+small). Steering it would
  take a discovery run per input to find the bound behind the counter (the small-count machinery only starts on
  inputs that run away); not done. Unchanged: fail, 16/16.
- **Work item 5, 0x002142d0 (luaG_symbexec).** Not attempted: the fuzzed bytecode needs per-opcode operand fields
  that pass the checks before the switch (`op < 0x24`, `a < maxstacksize`, `b < sizek` for constants, jump targets
  inside the code, a final RETURN). Unchanged: 45/120.
- **0x002dbd90 (png gamma tables, 48/80).** Not the vector class: its loops are long but finite. `count = 1 <<
  (8 - bits)` (up to 256) arrays of 256 `pow` results each, and an inner `do { ...; edi++; } while (edi <= end)`
  whose `end` is a stub's `pow` result through `__ftol2` (up to `count << 8`). A random input with small `bits`
  needs millions of steps; the 1M-step budget made it slower, not better (35/80). Unchanged.
- **Work item 6 (64-300 B, "equivalent" under 75% in the log).** Only three entries: 0x00268970 (9/14 logged),
  0x0008ed60 (3/16), 0x00334b00 (9/16). Their `equivalent/` sources pass the bar under round 9 and round 10 alike
  (14/14, 13/16, 16/16, about 3000 inputs each): stale log entries, no cluster to fix. (The `pass/` copies of
  0x0008ed60 and 0x00334b00 are older drafts that fail under both: "call #2 to 0x0008f880: argument 1 is
  0x00000006, expected 0x00000002", "call #3 to 0x4007d390: argument 1 ...".)

## Validation (2026-10-15)

- `tests/equiv/regress.py`: 135/135 (125 old + 10 new cases). In the full run (`--jobs 2`, loaded machine)
  `0x002c96e0_loop_back_edge` reached 68%; alone it gets 82% under round 10 and round 9 alike (a load-sensitive
  coverage case, not a regression). Under the round-9 checker every new case except two `_wrong` guards fails:
  `0x002155f0_diff_bound` unsupported, `0x0024a800_walk_end` 42 inputs, `0x000dcae0_fill_index` fails on
  734+small, `0x001b4d00_vector_bound` 68%, `0x001fe380_tiny_counts` 57% (34 inputs); round 9 passes
  `0x001b4d00_vector_bound_wrong` and `0x0024a800_walk_end_wrong` and can't run `0x002155f0_diff_bound_wrong`
  (unsupported), all three fail under round 10; `0x000dcae0_fill_index_wrong` and `0x001fe380_tiny_counts_wrong`
  fail under both. With `EQUIV_OFF=diffcount,smallpages,walkend,tinycount,idxfill` the round-10 checker gives
  round 9's result input for input (0x0024a800, 16 seeds: identical counts). `tests/equiv/test_equiv.py`: 12/12.
- `tests/equiv/selftest.py` (300 matches): 298/300, the same two known failures as round 9 (0x00094540,
  0x00155090: `call #1 went to 0x6fff0000`, an unresolved destructor in the current tree).
- `tests/equiv/mutate.py` on the pinned 120: 303 caught, 8 commutes pass, 2 equivalent mutants, 6 false passes,
  0 false failures (37 mutants don't compile, 63 compile to the same bytes): identical to round 9 mutant by
  mutant (all 419 mutant files compared). No new false passes.
- The work list (sources snapshotted at the start: round 9's snapshots, `work/` for the rest, `equivalent/` for
  0x002155f0, 0x0028e160 and the item-6 three), `--inputs 3000`, round 9 and round 10 run side by side under the
  same load:

  | Address | Round 9 | Round 10 | Promotable now | Change |
  |---|---|---|---|---|
  | 0x001b4d00 | 81/122, 1441 inputs | 120/122, 2134 | yes (new) | 1 |
  | 0x001fe380 | 26/46, 29 inputs | 39/46, 79 | yes (new) | 4 |
  | 0x002639c0 | 36/52 | 39/52 (75.0%), 703 | yes (new; borderline, use `--time-budget 300`) | 3 |
  | 0x0024a800 | 44/56, 42 inputs | 52/56, 59 | yes (new; few inputs, use `--time-budget 300`) | 3 |
  | 0x002155f0 | unsupported (482 s) | 12/12, 50 inputs (29 s) | yes (new; exactly 50, `--time-budget 300` for margin) | 1, 2 |
  | 0x000dcae0 | fail (734+small, the fuzzed index) | 38/38, 1805 | yes (new) | 5 |
  | 0x0019e910 | 369/432 | 386/432 | yes (both; `pass/` and `equivalent/` copies alike) | 1 |
  | 0x002dbd90 | 48/80 | 48/80 | no | |
  | 0x0028e160 | fail (call #12 to 0x002647e0) | fail, the same | no (see "Not changed") | |
  | 0x00282d00 | fail (inputs 54, 29+small) | fail, the same | no | |
  | 0x002142d0 | 45/120 | 45/120 | no | |
  | 0x00268970 | 14/14 | 14/14 | yes (both; the log's 9/14 is stale) | |
  | 0x0008ed60 | 13/16 | 13/16 | yes (both) | |
  | 0x00334b00 | 16/16 | 16/16 | yes (both) | |

  All need only the default flags with `--inputs 3000`.
- `equivalent/`, a random 300 (`random.Random(2034).sample` of the sorted list, 4603 files, snapshotted) at
  `--inputs 3000`: 300 equivalent, 299 promotable, no failures. 0x000fd0f0 is below the bar (23/32) under round 9
  identically (its header records 32/32 at 19928 inputs: it needs `--inputs 20000`). No newly failing file.

## What's left, ranked

1. **Long finite loops sized by stub floats and fuzzed shifts** (0x002dbd90 48/80): `end = (int)(pow(x, e) * n)`
   through `__ftol2` and `count = 1 << (8 - bits)`. Next step: steer a stub float that feeds a loop bound through
   `__ftol2` into [0, 1] (the ftolsrc source already exists) and treat `1 << x` bounds like counts.
2. **Frame-array overruns behind a loop counter** (0x00282d00): the counter's bound (`this->segs`) is a heap word,
   so steering needs the bound found statically (the compare that guards the indexed store) and planted by a
   discovery run on every input, not only on runaway ones.
3. **Bytecode-shaped inputs** (0x002142d0, 45/120): a per-opcode template from the operand checks the run passed.
4. **0x0028e160**: a source fix (the bound stored into the reused argument slot, above), not a checker change.
5. **Red-black fix-up sides** (0x002639c0 39/52: colour compares on aliasing fuzzed nodes) and 0x0019e910's last
   46 edges (386/432): directed steering of chained field compares through the nodes a walk reached.
6. Unchanged from round 9: per-iteration observations (0x00039c60), boundary values on covered compares, x87
   precision at fuzzed extremes.

## Recipes for batch agents

- **Re-run before rewriting.** Sources stuck on loops over `(end - begin) >> 2` of a vector a stub returned (the
  FUN_002ed700 family: 0x001b4d00, 0x0019e910), `nfixargs - (top - base) / 8`-style
  differences with a stack argument, tree and list walks (`while (n->left != &tree.nil)`, `while (e) { f(e); e =
  e->next; }`), pair loops over points collected from counted lists, and stub-filled indices into a stack array
  (`cells[lay.idx]`) now get steered: re-run them at `--inputs 3000` first. On the work list, 6 sources became
  promotable this way (0x001b4d00, 0x001fe380, 0x002639c0, 0x0024a800, 0x002155f0, 0x000dcae0).
- **`N+small` inputs are normal inputs.** Small counts now also plant vector ends relative to their begin, the
  sentinel into a walk's link, and counts of 0/1; both sides see the same memory. A failure on such an input is a
  real difference on a short loop, not a checker artefact.
- **Stack-array indices.** A fuzzed index into a frame array that a stub filled is drawn 0 or 1 once seen; a
  failure that names a spill slot behind such an array is now a real difference on an in-range index. An index
  that is a loop counter bounded by a heap field (0x00282d00's `segs` over `uv[6]`) is still fuzzed: such inputs
  still fail when they overrun into other locals.
- **Compiler temporaries in reused argument slots** (0x0028e160): the checker keeps comparing a buffer whose callee
  may return without writing it (FUN_002647e0 on a closed stream). Store into the slot what the original stores
  there (`*pval = bound` before the tail loop), don't wait for a checker change.
- **Stale log entries.** 0x00268970, 0x0008ed60 and 0x00334b00 (logged 9/14, 3/16, 9/16) pass the bar from
  `equivalent/` as they are; check the `equivalent/` copy, not an older `pass/` draft.
- **Long but finite loops** (0x002dbd90: `1 << shift` tables of `pow` results) stay under the bar at the default
  budget; a bigger `--steps`-style budget makes them slower, not better.
