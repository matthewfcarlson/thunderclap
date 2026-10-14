# Equivalence checker round 6

Round 6 worked through "What's left" in [round 5](equiv-round5.md), plus the cases batch agents sent in
while it ran. Each logged failure was reproduced under one seed (`EQUIV_SEEDS=N`) and traced on both sides.
Several notes had the wrong cause. The "loop repair picks clamps" note was really about an inner loop over a
constant bound. Most "x87 stack depth at return" failures came from `float_ret_after` not knowing the x87
depth at the call.

Soundness rule (unchanged): a change may only steer inputs or make inputs inconclusive. It never relaxes the
comparison of a real difference. Each fix has a case in `tests/equiv/cases/` that fails under the round-5
checker (`tests/equiv/regress.py`, now 76 cases). `EQUIV_OFF=name,name` switches named round-6 changes off
for A/B runs (the names are in the code next to each change).

## Changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | P6 bug 2. A callee's static write extent (`Key(const char*)` through `ecx`, 8 bytes) covered a dead spill slot that the original had written inside the object. The fill skipped words the function wrote, so the original kept its spill and ours its `0x5a5a5a5a`. The copy constructor then got different bytes (0x00040550 call #5). | Every word of the extent is filled on both sides. Where a side had written the word itself, its old value is recorded (`fill_pre`). If the two sides' old values differ, either side reads the word back before rewriting it, **and** the input shows no difference, the input is inconclusive (`statuses`: `fill_readback`). The extent is a range, not a set of stores, so it can cover a word the real callee leaves alone, and then the fill could hide a read-back. A difference seen anyway still fails: the same fill on both sides can't create one. | `0x00040550_spill_in_extent` |
| 2 | `Cue *c = new (buf) Cue(...); f(c)`: ours passes the constructor's `eax`, while the original recomputes `lea ecx, [buf]`. The stub returned a fuzzed `eax` (0x00081b20 call #30, "argument 1 is 0x003ff508, expected stack"). | A direct callee that returns its incoming `ecx` on every path (`Program.returns_this`, found by the same dataflow as `callee_writes`) and writes through `ecx` (a constructor) returns `this` from its stub. Accessors that only `mov eax, ecx; ret` keep a stub result: a zero or fuzzed pointer is what lets 0x001b4d00 reach its empty-container paths. | `0x00081b20_ctor_returns_this` |
| 3 | A loop counter kept in a local (`mov eax, [esp+0x40]; dec eax; mov [esp+0x40], eax; jne`, 0x001d8fc0) was attributed to the memory epoch of its re-load, not of the original load. Repair patched a heap word nobody reads again, and 116 of 424 inputs timed out. | A value reloaded from a local keeps the epoch it was first loaded in. | (0x001d8fc0 now repairs its loop, but the source fails on paths it never reached before: see below) |
| 4 | `test eax, eax; je L; push x5; call [vt+0x48] (ret 4); push eax; call __RTDynamicCast; add esp, 0x14; L:` (0x000ea7c0). `pending_use` took the virtual for caller-cleaned (`__RTDynamicCast` has no `callee_stack_args`), so the stack drifted by a word. 46 of 207 inputs went wild at the final `ret` (`0x5a5a5a5a`). | `CodeView.join_balance`: when a branch taken before the pushes joins the code after the call, both paths reach the join at the same depth, which fixes how many words the call pops. It is tried before `pending_use`. The "reader" rule also checks the reader's own cleanup: if that releases only the words it reads, our callee popped the rest. | `0x000ea7c0_dyncast_vcall_pop` |
| 5 | `sub esp, 0x14; ...; push x6; call [esp+0x3c]; ...; add esp, 0x14; ret` (0x0009b560, a callback trampoline). The epilogue's `add esp` released 5 words, and that was read as cleanup of the 6 pending ones. Every input went wild. | In `pending_use`, an `add esp` that releases exactly the prologue's frame right before `ret`/`pop` means the pending words were popped by the callee. | `0x0009b560_epilogue_frame` |
| 6 | `float_ret_after` decided "the callee returns a float" from the instruction after the call. That is wrong when the caller keeps values on the x87 stack across the call: a running sum, `fld [k]; push eax; call f; fadd [m]` (0x00295270), or `fld [this+0x6c]; call f (void); fstp [this+0x6c]` (0x001050d0). The stub pushed a fuzz float, which gave "x87 stack depth at return 4" or a store of 0.25f. | The x87 depth at the call is passed in. Values already on the stack count as available, so a float return is consumed only by an instruction that needs more. | `0x00295270_x87_live_across_call`, `0x001050d0_fstp_after_void_call` (now reaches the source's reversed `FUN_00025260` arguments) |
| 7 | A float returned untouched across `__security_check_cookie` (0x000dfbf0): the scan stopped at the cookie call, and ours spills `st0` around it. | The cookie check is transparent to the scan. | `0x000dfbf0_float_ret_cookie` |
| 8 | `~Derived` ends in `jmp ~Base` (ours), where the original inlined `~Base`. (a) `pick_symbol` chose `~Base` as the target, because it looks more like the original. (b) The jump ran in place, but `~Base`'s `push esi` prologue was taken for an argument of its virtual call, so the stack drifted (0x0028c040, 0x0028bcd0). | (a) Each candidate is compared with the bytes of the functions it tail-jumps to appended. (b) A tail jump into our own object registers that function's prologue, as calls already did. | `0x0028bcd0_tail_jmp_local` |
| 9 | Loop repair: in the 7 KB vertex emitters the hottest back edge is an inner loop over a constant bound (`cmp edx, 8; jb`). It can't be patched, and the outer loop's bound wasn't among the 12 hottest compares (0x002cb2b0, 0x002cec10). | Candidate exit compares are every back edge or loop exit (a forward jcc past a back edge, unless its target jumps straight back into the loop) that ran at least max(16, hottest/64) times and has a patch, hottest first. They are followed by the hottest other compares. Top-tested loops (`cmp; jae out; ...; jmp top`) are handled now. Compared with round 5, 0x002fdf40 doesn't drop. | `0x002cb2b0_loop_exit_order` |
| 10 | Directed inputs that hit a fuzzed loop (a switch case's own loop over a count) were wasted: repair only ran in the random phase. | A directed input whose original runs away is repaired too, from a separate budget of 64 runs. | (vertex emitters) |
| 11 | With `--inputs 3000`, every random input ran before any directed one, and slow functions used up the time budget (0x000ea7c0: 0 directed inputs). | Past 256 random inputs, with 50 completed, the random phase hands over at half the time budget. The rest of the random inputs run after the directed phase, then directed inputs run again. | `0x000ea7c0_dyncast_vcall_pop` |
| 12 | `rep stosd` over `count*4` bytes with a fuzzed count read from memory (allocators and constructors: 0x0028c2a0 with 20 completed inputs, 0x001c7770 with 35). Each one timed out, and the 32-inconclusive cap stopped the search. | A `rep` with a count over 0x2000 records where `ecx` came from. The stuck input is repaired like a loop bound, with the count patched to about 8. | `0x0028c2a0_rep_count` (≥ 50 inputs) |
| 13 | The 32-inconclusive cap of the random phase cut functions short of 50 completed inputs, or stopped them although most inputs complete (0x0003c1d0: 34 of 363 time out on a plane count). | After the directed phase, more random inputs run (repaired as before) while fewer than 50 have completed. When at most 20% of the random inputs were inconclusive, the rest of the time goes to random inputs, then directed ones again. Letting the random phase itself ignore the cap was tried and reverted: it took the time the directed phase needs (0x002448b0 52 → 34, 0x002e30f0 89 → 59). | `0x0003c1d0_count_cap` |
| 14 | Iterator ranges `[first, last)` over fuzzed pointers are millions of elements (0x003037f0 `std::_Unguarded_partition`: 294 of 302 inputs timed out, 8 completed). | A new input mode (seed % 8 == 5, for functions with two pointer arguments) puts each later pointer argument a few elements past the first one. The step is one of the code's `add/sub reg, imm` constants (0x44 there). | `0x003037f0_iterator_range` |
| 15 | Directed budget order. `str_queue` plants ran first in every round and could take the whole budget (0x00044cb0: 116 of 116 directed inputs were plants). Each compare also had all six of its observations tried before the next compare got a turn. | Plants take at most half the remaining budget per pass. Compares are worked breadth-first, round robin over observations whose patches haven't been tried. A compare keeps its turn while its observations find new edges, and stays active until both sides were taken `RARE_HITS` times. | `0x000ffef0_compare_chain` (82 → 122/122) |
| 16 | A bound re-read after each call, ending only through the callee (`while (t->first != head) erase(t->first)`). Patching it in every epoch ends the loop before its first round. | A variant patches it only from the next epoch on (overlay key `("after", epoch)`), so the loop runs once. | (0x0025b7d0 still stalls: see below) |
| 17 | The 2^32 bias of an unsigned-to-float conversion: the original has it as a float, our build as a double. That gave a level-2 `missing_float_constant` warning (0x00084c40). | The pair is recognised as the same constant. | — |
| 18 | A float argument the original stores with `fstp [esp]` and ours pushes from a float local (`push ecx`). The float tolerance applied only when both sides were `fstp` stores. With change 1 the vectors a `Vec3` transform fills are no longer the source's (1, 0, 0), and the x87 rounding of one side showed: 0x002b9ac0, 1-2 ulp and -0 vs 0. | An argument stored by `fstp` on either side compares with the float tolerance, as documented for float arguments and memory words. | `0x002b9ac0_float_arg_copied` (passes under round 5 too: it guards changes 1 and 18 together) |
| 19 | `cmp eax, eax; je` after a loop (a compiler artefact, 0x000e4470): one side can never be taken, but it counted as uncovered (7/10). | A jcc right after `cmp r, r` / `sub r, r` / `xor r, r` that nothing else jumps to has fixed flags. Its dead side isn't counted, and directed inputs don't chase it. | `0x000e4470_self_compare` |
| 20 | `lea ecx, [ecx]` (alignment padding) counted as a write of `ecx` in `reg_writes`, so the stub of FUN_00204760 clobbered `ecx`. The original calls the next method with the leftover `this` (0x00205860, 3 of 51 inputs). | No-op moves don't count as register writes there either (round 5 did the same for the function under test). | `0x00205860_padding_keeps_ecx` |

Also from the batch reports, but not checker bugs:

- **0x00195a90** (ProjectileEffect ctor): ours reads `this->owner` before calling `FUN_0027f250()`, and the
  original after it (`FUN_0027f250()->FUN_00283a40(&owner->sub18, ...)`). Evaluation order is a real
  difference: memory is re-read after every call because a callee may change it. Hoist the
  `FUN_0027f250()` call into a local first.
- **0x001d8fc0**: once its loop repairs (change 3), the source differs from the original by 1-2 ulp in a
  local passed to FUN_00067c30 (`b0ec.w`, copied with `mov`, so it is compared exactly). It is an x87
  precision difference in the source.
- **0x001050d0**: with change 6 the float store is right, and the run reaches `FUN_00025260(0, 0, 1)`,
  which the original calls as `(1, 0, 0)`. The arguments are reversed in the source.
- **0x0029d2c0** (13 → 23-29/30 edges): random input 562 completes now, and the original makes 3 calls where
  ours makes none. The round-5 checker fails the same way on that seed: a source bug.
- **The vertex emitters** 0x002c96e0 (random input 80: "missing write to 0x4000000c before call #19") and
  0x002cb2b0 (input 164: "unexpected write to arg2+0x18 before call #3"): the round-5 checker fails these
  inputs too. They used to time out before completing. Both differ in a write through fuzzed pointers
  (not traced further), so agents should look at them before promoting. The regression cases stop before
  those seeds.

## Validation (2026-10-14)

- `tests/equiv/regress.py`: 76/76. The 16 new cases fail under the round-5 checker, except
  `0x002b9ac0_float_arg_copied` (see change 18). `0x002c96e0_loop_back_edge` now stops at random input 80 and
  asks for 75% instead of 60%.
- `tests/equiv/selftest.py` (300 matches): 300/300.
- `tests/equiv/mutate.py` on the same 120 functions with both checkers (the sample is drawn from
  `matches/`, which grows, so it was pinned with `--only`): identical outcomes. 362 caught, 8 commutes pass,
  0 false failures, 10 false passes (the same 10 mutants under round 5).
- `equivalent/` at `--inputs 3000` on mac1, in random order (seed 2027), 824 of 3,348 files so far:
  - The random 200 that ran first: 200/200 under the final build. Two failed under intermediate builds
    and were fixed: 0x002b9ac0 (change 18) and 0x00173ca0. In 0x00173ca0, `join_balance` had decided "the
    caller pops" for a virtual whose pushed words belong to the next call's `ret 8`; it now only decides
    when the callee pops some.
  - **Newly failing** (the files were left alone):
    - **0x0022f960**, **0x0001c430**: random inputs 190 and 397 show real differences, and the round-5
      checker fails the same seeds (`EQUIV_SEEDS=190` / `397`). Round 5 never ran them: its random phase
      stopped at 32 inconclusive inputs (192 and 8 completed). Change 13 keeps going.
    - **0x0028e160**: a false failure, newly reached (coverage 42 → 84/84). The original's unrolled loop keeps
      a loop-bound temporary in the dead `parent` argument slot (`mov [esp+0x30], ecx`). The source later
      reuses that slot as a read buffer for FUN_002647e0 (`pval = &parent`). The local passed is compared
      before the call, and the original's dead temporary differs from our stale argument. This is the known
      "compiler temporary inside a compared extent" class (round 5, "Not changed").
    - **0x00336dd0**: fails under the round-5 checker as well (input 83, after loop repair). It was committed
      by another lane today with 154 inputs.
  - The other 817 are equivalent.
- Logged failures and coordinator cases, 47 sources from `build/farm/bench/claude-equiv/work|pass/` at
  `--inputs 3000`, round 5 → round 6:
  - **Newly promotable** (equivalent, ≥ 75%, ≥ 50 inputs): 0x0003c1d0 (130 → 193/224), 0x00040550
    (fail → 57/60), 0x00081b20 (fail → 165/172), 0x0009b560 (unsupported → 2/2), 0x000dfbf0 (fail → 2/2),
    0x000e4330 and 0x000e4470 (7/10 → 7/9), 0x000ea7c0 (78 → 129/142), 0x000ffef0 (82 → 122/122),
    0x001c7770 (35 → 50 inputs), 0x002448b0 (45 → 51-56/64), 0x0028bcd0 and 0x0028c040 (fail → 6/8),
    0x0028c2a0 (20 → 52 inputs), 0x00295270 (fail → 12/12), 0x002cb2b0 (194 → 302-308/382),
    0x002cd130 (274 → 322/376), 0x002cec10 (207 → 302/376), 0x002fdf40 (36 → 48/50), 0x003037f0 (8 inputs
    28/62 → 50+ inputs 59-60/62), 0x00205860 (fail → 8/8).
  - Promotable before and still: 0x00084c40, 0x00107410, 0x00148b00, 0x001d8350, 0x0025f450, 0x0029d880
    (42 → 49/54).
  - More coverage, not yet at the bar: 0x00044cb0 (37 → 50/122), 0x002e30f0 (59 → 94/126).
  - Unchanged: 0x0004cbe0 9/18, 0x002de030 8/35, 0x002e3bd0 87/118, 0x00233990 22/30, 0x002639c0 36/52,
    0x0025b7d0 1/8, 0x0028a630 and 0x00282d00 (fuzzed stack indices, fail).
  - **Now failing on newly reached inputs** (source bugs; the round-5 checker fails the same seeds):
    0x001b4d00 (input 1404: a local passed to 0x2f1ce0 holds 2048.0 where the original has 32768.0),
    0x0029d2c0 (13 → 23/30; input 562: ours skips the calls), 0x002c96e0 (input 80), 0x002cb2b0 (input 164),
    0x001d8fc0 and 0x001050d0 (see "not checker bugs" above), 0x00195a90 (evaluation order).

## What's left, ranked

1. **Per-iteration observations.** A directed input patches a compare from its first execution in a run
   (`cmp_obs`). Compares in later loop rounds can't be targeted. Two cases: loop-exhaustion exits that need
   every round to pass its early exits (0x000e4330, 0x000e4470, 0x000e43c0: eight children, each non-null
   and each getter returning 0xffff), and element-match counts (0x002fdf40 reached 48/50 only through extra
   random inputs). Tried and dropped: one stub result for every later call to the same callee. It kept the
   reader loops of 0x002e30f0 going (94 → 48/126), and still didn't reach the FEContainer exits, whose
   children are fuzzed null.
2. **P4 structures** (0x002639c0 36/52, 0x0025b7d0 1/8). Fuzzed trees walk forever. The teardown loop of
   0x0025b7d0 also cycles on the null page (`[0] == 0`) and needs an erase stub that unlinks. A
   well-formed tree planted at the offsets the walk uses is still the plan.
3. **Infeasible edges beyond `cmp r, r`**: dead `k == -1` checks (0x0003c1d0), null/overrun checks after list
   walks (0x00233990, 8 of 30 edges), pointer-wraparound exits and `setcc` outcomes (0x0023c040, 15/22).
   These need value-range analysis. Promotion could also accept a hand-reviewed list of dead edges.
4. **Partial-register arguments** (0x002d0a50): a byte flag in `cl`/`dl` over leftover high bytes is compared
   as the whole register. Compare only the bytes the callee reads (`movzx`/`test cl`).
5. **Prologue pushes counted as pending arguments** (0x002adb10): ours saves `esi`/`edi` where the original
   doesn't. When the function takes them as register inputs, the saves become "3 argument words" of the
   first virtual call.
6. **Float ties after `fabs`** (0x000f1bd0): `and 0x7fffffff` on a stack slot, then an exact compare
   with pi/2 in `.rdata`. Exact ties are planted only against plain loaded values.
7. **x87 64- vs 80-bit intermediates** (the s32 question about 0x000692c0): such sources pass because
   floats compare with 1e-5 relative tolerance. A double spill differs from an 80-bit value by ~1e-16
   relative, far inside it. Only cancellation that amplifies the difference past 1e-5 would show, and the
   fuzzer doesn't engineer that. A directed mode for our own spill sites is possible, but by the tolerance
   rule these differences are accepted anyway.
8. **Extent growth over compiler temporaries**, now with a second shape: 0x0028e160 above, and 0x00173ca0's
   neighbour word if `pending_use` ever gets an arity wrong. Unchanged since round 5.
9. Unchanged from round 5: count×size buffer fills (0x002de030), combined directed constraints
   (0x0004cbe0), fuzzed stack-array indices (0x00282d00, 0x0028a630). The time budget is still the limit
   for the 7 KB vertex emitters under load: they pass the bar on a quiet machine. `--time-budget 300`
   helps under load.
