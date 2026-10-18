# Equivalence checker round 12

Round 12 went after what the replay-fix batches fx11 and fx12 traced to the checkers rather than to the sources.
Most of it is in trace replay (`tools/equiv_replay.py`): of the 23 functions those batches fixed, 15 mismatched on
replay only because of how the capture records and the replay places a callee's frame writes. The capture diffs
the game's frame after a call against Unicorn's before it, keys each changed run to the nearest pointer below it
and the replay re-places it relative to that pointer on both sides. Four kinds of bytes came out wrong:

- **scratch-register keys.** A run keyed to `eax` after `fnstsw ax` (`(&R & 0xffff0000) | fpsw`), after `mov al,
  [edx+0x24]` over a pointer, or to a loop's end pointer: the same absolute address on both sides, which is an
  outgoing argument in the original and a saved register in ours (fx12 0x00122520, 0x000202f0, 0x00017a80,
  0x000f5fa0).
- **stack addresses.** Most of those runs were not callee writes at all: the upper half of a pushed `&local`, 0xd004
  in the game and 0x7eff in Unicorn.
- **dead-frame garbage.** Interrupt frames (EIP, CS 8, EFLAGS 0x2xx), the gate trampoline's words and the caller's
  `ebp` left in stack bytes the function hadn't used yet, merged into runs behind the nearest pointer (fx12
  0x000c7c60, 0x002a81c0, 0x002c1770, 0x002340b0/0x00234a10, 0x00201850; fx11 0x00308fe0's call 0, 0x00080820).
- **partial words.** A 3-byte run that left the top byte of a stale return address alone, 0x00 in the original
  and 0x60 in ours (fx12 0x001f9710, which compare.py matches).

Plus three plain replay gaps (x87-argument callees, writes into our dead argument slots, a step budget too small
for 0x00201850) and the three sessions captured before the ST(0) fix (s1, t1, t2), whose callee float results are
the physical x87 register.

On the fuzzing side (`tools/equiv.py`) fx11/fx12 found three gaps: x87 register arguments were never compared (the
old 0x0033b6d0 called `__CIasin` on an empty x87 stack and passed 3000 inputs), a virtual callee's out-object had
no size (0x002a4b00's 8-byte id in a 4-byte local, 0x002251d0's 16-byte vector in a 12-byte one), and ties never
happen with random values.

Soundness rule (unchanged): `equiv.py` changes only steer inputs or add comparisons; `equiv_replay.py` changes only
remove artifacts of the recording/replay machinery. Where replay can't tell an artifact from a callee write (bytes
below the stack pointer since the last call that the original never reads), the call becomes `incomplete`, never
`agreed`, and only after re-running both sides without those bytes, with the original still reproducing the
recording. Every change has a case (`tests/equiv/regress.py` for `equiv.py`, the new
`tests/equiv/replay_regress.py` for replay) that fails under round 11 and passes now, and `_wrong` cases show real
differences are still caught. `EQUIV_OFF=name` and the new `REPLAY_OFF=name` switch each change off.

## equiv.py changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | 0x0033b6d0 (Lua `math.asin`): `fld x; call __CIasin` passes x in st(0). Round 11's `x87args` popped it, but nothing compared it, so a source that dropped `luaL_checknumber`'s result and called `FUN_003442bc(L, 1)` passed. (`x87cmp`) | Each call records the x87 registers the callee takes (`Program.x87_args`) as values (`None` for an empty slot); `compare_runs` compares them with the float tolerance: `call #2 to 0x003442bc: x87 argument st(0) is empty, expected 2`. `float_ret_after` also counts a following call that takes an x87 argument as using the float result (ours: `call luaL_checknumber; call __CIasin`, no `fst` in between). | `0x0033b6d0_x87_arg` (equivalent under both), `..._wrong` (round 11: equivalent; now fails) |
| 2 | A virtual call has no static write extent, so its stub fills only what our declaration says: 0x002a4b00's `create` writes a 64-bit id (ours: `unsigned`, under the return address); 0x002251d0's `sample` writes a 16-byte vector (ours: 12 bytes, `q.x` after it). (`vext`) | `Program.vslot_writes(disp, pop)`: what the functions in that vtable slot (every RTTI vtable) with the same stack use write through each argument. The original's run takes, per frame local passed, the biggest extent at least three implementations share (`VEXT_SHARED`) that fits the original's free room there (up to the next word it wrote, another address-taken local, a saved register or the return address); ours must have that room before a saved register, its return address or a local it set before the call (`writes 0x8 bytes through argument 2 ... ours has only 0x4 bytes there before the return address`). The stub fills that far on both sides. A real target (trace replay) uses its own static extent instead. | `0x002a4b00_vslot_room` / `..._wrong`, `0x002251d0_vslot_room` / `..._wrong` (round 11: both wrong ones equivalent); guard `0x000a75d0_vslot_unrelated` (slot 0x54: only two other-hierarchy implementations write 0x14 bytes; with "two share" it failed fuzzing and replay) |
| 3 | Random values never tie, and directed inputs only target sides not yet taken: `fabs(m[0][0]) > eps` against `>=` differs only at equality, with both sides taken thousands of times. Directed float ties were also limited to two plain loads. (`ties`, `ftie`) | After the first directed phase, one input per compare (at most 48) plants a tie: an operand from an input made equal to the other operand, through its transforms when the planted value comes back exactly (`_fxf_exact_tie`: fabs, fchs, or checked forward in the loaded precision); integer compares likewise (`cmp eax, [ebx+0xc]`, `cmp eax, 5`). The regular float patches also try the tie for a transformed operand when it is exact. | `0x002fbf20_fabs_tie` (equivalent), `..._wrong` (`>=`; round 11: equivalent, 3000 inputs; now fails) |

Not changed: B4, deep edges reached only at 12k-20k inputs (fx12's 0x001b05a0): analysed, see "What's left".

## equiv_replay.py changes

| # | Root cause | Fix | Case (`tests/equiv/replay_regress.py`) |
|---|---|---|---|
| 1 | `_apply_regs` substituted the recorded ST(0) only for stubs returning through TRAMP+0x800..0xC00; a callee with x87 arguments returns through TRAMP+0xC00 (pop them, then `jmp [FSLOT+0x10]`), so the original took a fuzz float (10.0) instead of the recorded asin result. (`x87arg`) | Point `[FSLOT+0x10]` at the qword variant and put the recorded ST(0) in FSLOT (fx12's patch). | `0x0033b6d0_x87_arg` g-play2 (mismatch -> agreed 1/1), `..._wrong` (mismatch, now on the x87 argument) |
| 2 | Runs keyed to a register the callee doesn't take (eax after `fnstsw ax`, after `mov al, ..`, a loop's end pointer). (`scratchkey`) | A run keyed to a register that isn't one of the callee's register inputs (`Program.reg_inputs`; ecx/edx for an unknown target) goes behind the nearest stack-argument pointer below it, else nowhere (both sides). | `0x00122520_fnstsw_key`, `0x00017a80_al_key` g-play2, `0x000202f0_fnstsw_key` p4-1 (fx12's pre-fix sources: mismatch -> agreed) |
| 3 | A word that holds a game stack address where Unicorn holds its own for the same word (a pushed `&local`, 0xd004.. vs 0x7eff..) differs only in the address space: no callee wrote it. (`xlate`) | A recorded word of the function's own frame (a game address below the entry esp) that translates to exactly the word the original holds there is dropped (both sides). Other stack-looking words stay the game's on both sides, as before: translating them was tried and broke data that only looks like an address (0x00217640: `sprintf` into `char buf[32]`, the word `"1\0" + 0xd004` became 0x7eff0031). | with 2 |
| 4 | A run that changes part of a word assumed both sides held the game's other bytes (0x001f9710: a stale return address, 0x0060.. in ours). (`widen`) | Widen to whole words with the game's bytes where the original's code never wrote them; ours keeps bytes its own code wrote. | `0x001f9710_partial_word` g-play2 (the committed source: mismatch -> agreed 2/2) |
| 5 | Interrupt frames, the gate trampoline's words and leftovers in stack bytes the function hadn't used yet, recorded as callee writes. The capture can't tell them from a callee's out-parameter. (`unknown`) | The original's run tracks the highest esp since the last call (since entry for the first) and marks recorded bytes below it, and which of those its own code reads. A call that mismatches is re-run on both sides without the marked bytes the original never read; if the original still reproduces the recording and ours then agrees, the call is `incomplete` ("differs only through recorded stack bytes ... the original never read"), not a mismatch. Bytes the original reads (the rounding bug of fx11's 0x00308fe0 sits on a vector the original reads) and bytes above the stack pointer (0x002a4b00's id) are never left out. | `0x000c7c60_pad_garbage` g-try3 (mismatch -> no_replay), `0x00080820_merged_garbage` g-try2 (mismatch -> agreed 2, 3 incomplete); guards `0x00308fe0_rounding_wrong` s2, `0x002a4b00_real_overflow_wrong` par0, `0x002251d0_vec4_wrong` ringfeed2 (still mismatches) |
| 6 | Ours keeps an out-parameter in a dead incoming-argument slot; the replay refused every frame-keyed write into our argument area (fx11 0x001af650, fx12 0x000f6530). (`deadarg`) | Allowed when it stays inside our incoming arguments and the original's own slots there are dead after the call (its next access to each byte is a write, or none: a read hook on the original's argument area). | `0x000f6530_dead_arg_slot` p4-1 (fx12's pre-fix source: mismatch 0/5 -> agreed 5/5) |
| 7 | s1, t1 and t2 were captured before b566e0d3 (ST(0) read as the physical register): s1's 0x00042680 recorded cos(angle) where the game returned the angle. (`st0fix`) | `TraceStore.pre_st0_fix` (by name, else the session's files older than the fix): a call whose original took a recorded x87 result is `incomplete` ("captured before the ST(0) fix"); calls without one replay as before. Results carry `st0fix`; `equiv_confidence.py` drops pre-fix sessions' results without it. | `0x00042680_pre_st0_fix` s1 (fx12's pre-fix source: mismatch 0/15 -> 15 incomplete), guard `0x00241390_pre_st0_fix_wrong` s1 (still a mismatch) |
| 8 | 0x00201850's original replay ran out of the 2M steps on most calls ("status timeout, recorded ret"). (`steps`) | When the original times out where the recording returned, once more with 16M steps (while under half the time budget). | `0x00201850_long_call` s2 (no_replay -> agreed 6/6) |

Also: replay results record `st0fix`, `pre_st0_fix`, `unknown_bytes`, `long_steps`; `equiv_confidence.py` takes
`--replays GLOB` (whole-session results written elsewhere with `--out`) and `--out FILE`.

## Validation (2026-10-17)

Machines: `regress.py`, `test_equiv.py`, `replay_regress.py`, selftest, mutate and the random 300 ran locally
(load 12-30 on 8 cores: other agents); the replay sweeps ran on mac1 (`~/hulk-r12`, the local sessions copied
there, the sources from one snapshot of `equivalent/`, 5,646 files).

- `tests/equiv/regress.py --jobs 2`: 157/157 (145 old + 12 new). A first run at `--jobs 1` under load had three
  load-sensitive coverage cases short (`0x002c96e0_loop_back_edge` 68%, `0x002cb2b0_loop_exit_order` 74%,
  `0x003037f0_iterator_range` 65%); alone, round 11 gets the same (72%, 77%, 65%), and the final full run passes
  all three. Under round 11 (`EQUIV_MODULE=equiv_r11 ... --only`) all new `_wrong` cases come out `equivalent`
  (x87_arg, both vslot_room, fabs_tie, float_tie), the others pass. `tests/equiv/test_equiv.py`: 12/12.
- `tests/equiv/replay_regress.py` (new; local sessions): 16/16. Under round 11
  (`EQUIV_REPLAY_MODULE=build/agent-tools/equiv_replay_r11.py EQUIV_MODULE=equiv_r11`) the 11 non-guard cases
  all fail (mismatch, or no_replay for 0x00201850) and the five guards pass (still mismatches).
- `tests/equiv/selftest.py` (300 matches): 290/300. The ten failures are scalar deleting destructors of templates
  (`??_G...Closure1<...>`, `ParamEnumConstList<...>`, ...: `call #1 went to 0x6fff0000`, the destructor
  unresolved in the current tree) and fail identically under round 11: the sample and `matches/` changed, not the
  checker (round 11's 0x00091030/0x00153fd0/0x001540b0 are the same kind).
- `tests/equiv/mutate.py` on the pinned 120 (`build/equiv/mutants.jsonl`'s addresses): 303 caught, 8 commutes pass,
  2 equivalent mutants, 6 false passes, 0 false failures (37 don't compile, 63 compile to the same bytes):
  identical to round 11 mutant by mutant (all 419). No new false passes.
- `equivalent/`, a random 300 (`random.Random(2036).sample` of the sorted snapshot) at `--inputs 3000`: 298
  equivalent, 297 promotable (929 tie inputs in all). Newly failing: **0x0030e0a0**, a real bug the tie inputs
  found: `time + k <= cutoff` where the original's `fcomp [esi+0xc]; test ah, 5; jp` is `<` (input `3+tie`: `extra
  call #2 to 0x00319ef0`); with `<` it passes (case `0x0030e0a0_float_tie`). A first version of the ties also
  failed 0x0033cff0 (Lua gsub) by planting the original's own stack address (its buffer end) into a stub fill;
  ties no longer plant stack or our-code addresses (case `0x0033cff0_tie_stack_addr`). 0x001f4f00 (19 inputs,
  code_write) and 0x002a4e40 (inconclusive) get the same result under round 11.
- Work list: 0x00039c60 110/152 locally (113 on mac1 in round 11: still short; ties gave it 14 inputs);
  0x001b05a0 (fx12's 12k-20k failure): see "What's left".

**Replay, every local session** (`equiv_replay.py --equivalent`, round 11 = `build/agent-tools/equiv_replay_r11.py`
with `equiv_r11`, round 12 = this round's both; functions agreed/mismatch/no_replay/unsupported, then calls
agreed/mismatched/incomplete; g-play2b is a snapshot taken at 12:52, the capture was still running):

| Session | Round 11 | Round 12 |
|---|---|---|
| g-hot | 4/0/0/0; calls 4/0/0 | 4/0/0/0; calls 4/0/0 |
| g-play2 | 1984/2/43/91; calls 11952/3/390 | 1996/0/33/91; calls 12006/0/339 |
| g-play2b | 939/3/26/47; calls 969/3/28 | 952/0/16/47; calls 982/0/18 |
| g-prof | 328/0/5/21; calls 759/0/13 | 330/0/3/21; calls 764/0/8 |
| g-try1 | 600/0/8/32; calls 1799/0/44 | 603/0/5/32; calls 1810/0/33 |
| g-try2 | 856/1/12/37; calls 3050/1/69 | 860/0/9/37; calls 3062/0/58 |
| g-try3 | 1904/2/55/83; calls 1944/2/55 | 1915/0/46/83; calls 1955/0/46 |
| gd-cmp | 652/0/12/35; calls 2882/0/57 | 656/0/8/35; calls 2890/0/49 |
| p2-1 | 591/0/13/30; calls 5062/0/155 | 594/0/10/30; calls 5076/0/139 |
| p2-w | 691/1/20/32; calls 2974/2/126 | 695/0/17/32; calls 2994/0/106 |
| p3-0 | 593/0/13/23; calls 5147/0/210 | 596/0/10/23; calls 5177/0/180 |
| p3-1 | 417/0/7/22; calls 2785/0/78 | 418/0/6/22; calls 2790/0/72 |
| p4-0 | 521/0/12/23; calls 4379/0/170 | 523/0/10/23; calls 4394/0/155 |
| p4-1 | 546/1/9/36; calls 4557/5/141 | 548/0/8/36; calls 4567/0/134 |
| par0 | 142/0/5/5; calls 766/0/24 | 143/1/3/5; calls 769/2/19 |
| par1 | 183/0/3/6; calls 1281/0/32 | 183/0/3/6; calls 1283/0/30 |
| ringctl | 4/0/0/0; calls 4/0/0 | 4/0/0/0; calls 4/0/0 |
| ringctl2 | 4/0/0/0; calls 4/0/0 | 4/0/0/0; calls 4/0/0 |
| ringfeed | 4/0/0/0; calls 4/0/0 | 4/0/0/0; calls 4/0/0 |
| ringfeed2 | 360/0/8/13; calls 2057/0/49 | 364/0/4/13; calls 2069/0/37 |
| s1 | 388/0/6/15; calls 5087/0/146 | 355/0/39/15; calls 4598/0/636 |
| s2 | 415/0/7/14; calls 7335/0/153 | 420/0/2/14; calls 7352/0/138 |
| smoke-0 | 186/0/5/4; calls 2058/0/72 | 186/0/5/4; calls 2058/0/72 |
| smoke2-0 | 129/0/4/2; calls 913/0/24 | 130/0/3/2; calls 918/0/19 |
| t1 | 159/0/5/3; calls 440/0/10 | 159/0/5/3; calls 437/0/13 |
| t2 | 277/0/6/11; calls 1132/0/31 | 259/0/24/11; calls 1072/0/91 |
| x-menus | 253/0/5/12; calls 1626/0/32 | 254/0/4/12; calls 1632/0/26 |
| x-tut1 | 320/0/6/11; calls 1852/0/39 | 321/0/5/11; calls 1858/0/33 |
| x-tut2 | 409/0/7/14; calls 3633/0/89 | 412/0/4/14; calls 3642/0/80 |
| x-tut3 | 368/0/8/17; calls 2995/0/86 | 370/0/6/17; calls 3006/0/75 |

All sessions: 10 mismatching functions -> 1; 14,227 -> 14,258 agreed, 310 -> 288 no_replay. Mismatches gone:

- 0x001f9710 (g-play2, g-try3, p2-w, p4-1): `argument 4 is 0x60000008, expected 0x00000008` -> agreed (`widen`).
- 0x0033b6d0 (g-play2): the asin result -> agreed (`x87arg`).
- 0x000dd350 (g-play2b): `call #48 to 0x0008d6d0: argument 1 is 0x81, expected 0x85` -> agreed (`widen`: with it off
  the mismatch is back).
- 0x00217640 (g-try2): `call #2 to 0x00219430: argument 3 is 0x20, expected 0x24` -> agreed (`widen`).
- 0x001f4c50 (g-play2b, 0xb bytes into an 8-byte local), 0x00278b50 (g-try3, 0x26 into 0x24), 0x00234cf0
  (g-play2b, `ebp not preserved`: 0x002340b0's sibling) -> `no_replay`: they differ only through bytes below the
  stack pointer the original never reads (`unknown`). Likely the fx12 frame-layout pattern (pad/alignment
  garbage): replay can't tell, fuzzing still checks them.

Appeared: **0x002e22c0** (par0, calls 1 and 2): `call #21 to 0x002647e0: argument 1 is 0x00000000, expected
0x0139bdf0`. Round 11 counted every par0 call incomplete ("call targets differ from the recording"); with
`widen` the original reproduces the recording (a 3-byte count read by `Stream::Read` gets its top byte), so ours is
compared for the first time: at the `0x10005` chunk ours passes `D->f18` = 0 where the original passes a heap
pointer. Not triaged further: a candidate for the next fix batch.

s1 and t2 lose agreed functions (388 -> 355, 277 -> 259) and t1 calls (440 -> 437): `st0fix` makes their calls that
take a recorded x87 result incomplete, as intended.

**Confidence** (`tools/equiv_confidence.py --replays` on the two sweeps' results, file times equalised so neither
side has stale results; the `replay-fn*.json` files as on disk): tiers 0/1/2/3 = 12/2711/1002/1945 under round 11's
rules -> 6/2687/1014/1963. Tier 0 is now the five `hybrid/exclude.txt` entries and 0x002e22c0. 80 pre-fix session
records from `replay-fn*.json` are dropped (no `st0fix` mark). Moves: 14 functions 1 -> 3, 11 1 -> 2, 4 0 -> 3,
2 0 -> 2, 1 0 -> 1, 1 2 -> 3, 1 3 -> 1 (an s1/t-only function), 1 1 -> 0 (0x002e22c0).


## What's left, ranked

1. **0x002e22c0** (par0): newly comparable, mismatches at the `0x10005` chunk (above).
2. **Deep conjunctions** (B4, fx12's 0x001b05a0). At 3000 inputs (local, round 12) both the old and the fixed
   source cover 127/134 and pass; the edges missing are +0x462/+0x46c/+0x4f9/+0x545, the path behind 0x3be. In 400
   inputs no input reaches +0x443. The way there is a conjunction after `FUN_001d72e0()`: |v|^2 of a vector in the
   object the stub returned against a local (`fcomp st(1)` at +0x3ec), |w|^2 of a local vector against a constant
   (+0x417), `FUN_002f8e10` returning true, then `edi = [[out]+0x44]+0x18] + idx*24` nonzero (two out-parameters
   the original zeroes before the call, so only stub fills reach them), a flag bit, and `FUN_001d5e80() == 3`. Each
   is steerable alone; the sums of squares have no single source (only the all-alike stub/memory float modes move
   them) and directed inputs chain one condition per input. What would reach it at 3000: directed inputs that keep a
   chained input's whole overlay (memory floats included) while adding the next compare's plant, and
   sum-of-squares steering (plant one component to sqrt(target)). The 20,000-input run reached it 3 times.
3. **Merged runs over adjacent out-parameters** (fx11's 0x00080820): splitting a run at the call's other pointer
   arguments was tried and dropped: in the local sessions every merged run found is a first call, where the
   `unknown` rule already decides, so no case changes outcome.
4. **Stack pointers a callee stores** stay the game's addresses on both sides (`xlate` only drops pure
   translation artifacts): translating them broke string data. A capture-side fix (record which words the callee
   wrote as pointers) would be exact.
5. **0x00039c60** 110-113/152 (one-three edges short), unchanged; **0x0035c5b0** is not a function: 304 bytes of
   `.text$x` EH code, `mov eax, funcinfo; jmp 0x35aa68` frame-handler thunks and `lea ecx, [ebp-N]; jmp dtor` /
   `push [ebp-x]; call delete; pop ecx; ret` unwind funclets for library parents. It should be listed like the 204
   `__ehhandler_*`/`__unwindfunclet_*` entries `tools/fix_function_list.py --pass2` added (split into its units),
   so progress counts leave it out; no source to write.
6. Unchanged from round 11: per-stub cost on long constructors, interpreter words (0x002142d0), frame-array
   overruns, red-black fix-up sides.

## Recipes for batch agents

- **Re-run the sweep before rewriting a replay mismatch.** Round 12's replay drops the capture artifacts behind
  most of fx11/fx12's frame-layout fixes: a "register not preserved" diff with only the upper half wrong
  (0xd004xxxx), partial-word stale bytes (`argument 4 is 0x60000008, expected 0x00000008`), runs over pads and
  alignment slots. What's left after `tools/equiv_replay_fn.py --changed` is far more likely a real difference.
- **`no_replay` with "differs only through recorded stack bytes ... the original never read"** is inconclusive,
  not a pass: the original has unused stack there (a pad, a dead slot) and ours a live value. Matching the
  original's frame (as fx12 did) turns it into `agreed`; it's never needed for promotion.
- **`incomplete` "captured before the ST(0) fix"** (s1, t1, t2): ignore; those calls carry wrong float results.
- **x87 arguments** are compared now: a `__CI*` intrinsic (`__CIasin`, `__CIpow`, ...) written as a plain call
  with stack arguments fails with `x87 argument st(0) is empty`. Write the libm call with `// equiv-map: __CIasin =
  0x...`.
- **Virtual out-objects**: `writes 0x8 bytes through argument 2 ... ours has only 0x4` at a `call [eax+N]` comes
  from the slot's implementations (at least three write that much): make the local as big (`struct { unsigned
  lo, hi; }`, a `Vec4`).
- **Ties**: an input labelled `N+tie` made two compared values equal; a failure there is a `<` vs `<=` (or `>` vs
  `>=`) difference. Read the original's `test ah, 5/0x41/1` to pick the operator (0x0030e0a0).
