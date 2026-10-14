# Equivalence checker round 5

Round 5 worked through the open items of [round 4](equiv-round4.md) (P3–P7) and the "suspected checker
bug" notes in `build/farm/bench/claude-equiv/log.jsonl`. It reproduced each logged failure under one seed
(`EQUIV_SEEDS=N` or `verify(..., seeds=[...])`) and traced both runs instruction by instruction. Several notes
had the wrong diagnosis. Most "fuzzed pointer aliases the stack" failures were really a fuzzed *function
pointer* landing inside the function under test.

Soundness rule: a change may only make inputs inconclusive or steer inputs. It never relaxes the comparison
of a real difference. Each fix has a case in `tests/equiv/cases/` that fails under the round-4 checker and
passes now (`tests/equiv/regress.py`, 57 cases).

## Changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | An unaligned read across a heap pointer and a small int spells a code address (`0x0013400c`). A vtable read through a fuzzed pointer then hands the original an address inside its own body: it ran its own code from there, while ours (code elsewhere) stubbed a call. The same happens in our run with `0x60000001`. | An indirect call into the function's own body stops the run (`fault:wild_call`). The input is inconclusive. | `0x000f3f00_wild_call`, `0x001b7f40_wild_call_ours` |
| 2 | Returns through smashed return addresses (unbounded `strcpy` into a stack buffer) ran junk whose effects depended on frame layout. Both sides crashed, with different fault kinds. | The run stops where control leaves the function's code (`fault:wild_jump`). An input is inconclusive if the original goes wild, or if both sides fault with only the fault kind differing (`both_fault`). Ours going wild where the original returns still fails. | `0x0026f290_both_fault` |
| 3 | `call [0xffffffff]`: the stub read the target with Unicorn's `mem_read`, which doesn't wrap at 4 GB the way the CPU does. | Reads that wrap go through `_mem`. | `0x00272df0_wrapped_read` |
| 4 | A by-value argument built in place by a stubbed copy constructor (`sub esp, 8; mov ecx, esp; push src; call ctor`). The callee-extent fill started at offset 4 (offset 0 was assumed to be a stack argument), and dead return-address slots stayed in `save_slots` and capped the room. Word 0 kept each side's own return address. | Fill offset 0 through a register pointer. Fill a partly written last word whole. Drop save slots below `esp`. The undersized-local check then sees the real room, so it catches more: 0x001d8350's `Event` local was 0x1c bytes and the callee writes 0x28. | `0x001db230_copy_ctor_temp`, `0x001d8350_dead_ret_slot` (fail) |
| 5 | `mov edi, edi` (alignment padding) marked `edi` as written, so a later lazy `push edi` save looked like an argument word. | No-op moves (`mov r, r`, `lea r, [r]`) don't count as writes. | `0x00087630_nop_move` |
| 6 | `??_R0` RTTI type descriptors (the operands of `dynamic_cast`) bound only by pairing. With two casts, one was left unresolved or swapped. | Bind by class name from `build/rtti.json`. | `0x002867b0_rtti_by_name` (level 2) |
| 7 | `push eax; push K; call <jmp [vtable] thunk>; mov ecx, eax; call f (ret 4); push x3; call g; add esp, 0x10`. `pending_use` stopped at `f` and decided the thunk popped one word, but `f` takes K and `g`'s cleanup takes `eax`. The stack drifted by a word, so callee-saved registers came back shifted. 0x000c2c20's note blamed fuzzed pointers. | Keep scanning after a `ret N` call takes some pending words. If a later `add esp` releases exactly the rest, the callee pops none. | `0x000c2c20_thunk_shared_push` |
| 8 | P5: a float compare on a value computed from stub results (`sqrt` of the difference of two stub-filled vectors, a dot product) had no single word to invert. | Directed inputs set every stub float alike: 0, +1/−1 by turns per filled object, and 1000. 0x00107410 went from 11/52 to 51/52 edges and exposed a real source bug: the 64-bit id was loaded after the call. | `0x00107410_stub_floats` |
| 9 | `test eax, eax; jge` on a word behind a stubbed pointer. Directed inputs only planted 0, 1 and `x ^ 1`, so the sign never flipped (0x00117150: 17/30). | -1 is planted too (29/30). | `0x00117150_sign_test` |
| 10 | Byte out-parameters at odd frame offsets (`char found, flagA, flagB`) were never filled or steered, because fills required `v % 4 == 0`. | Fill (and steer) the byte (0x000bfa10: 6/12 → 12/12). | `0x000bfa10_byte_outparams` |
| 11 | Selftest's two standing failures: `L"()"` stored without its terminator in the original (packed `"()[]{}"`), and MSVC's `vector constructor iterator` (`??_H`), which our object defines as a COMDAT and ran in place while the original calls FUN_00011520. | Bind a string by its characters when the terminated form is absent. `??_H/??_I/??_L/??_M` pair like any callee. | `0x003388d0_unterminated_literal`, `0x00312db0_vector_ctor_iterator` |
| 12 | When the first 4 inputs timed out, every input got 1M steps, unless all 8 first inputs then timed out too. rb-tree inserts on cyclic fuzzed trees (0x002639c0) completed 3 inputs in 440 s. | Go back to 50k steps plus loop repair when 6 of the first 8 time out (84 inputs, 9/52 → 19/52 edges). | — |
| 13 | Loop repair patched the *hottest* compares of a timed-out run: in 7 KB vertex emitters (0x002c96e0, 0x002cb2b0, 0x002cd130, 0x002cec10) those are colour clamps inside the loop, whose patching never ends it. | Back-edge compares (`cmp; jb top`) are tried first (0x002c96e0: 182 → 326/382 edges). | `0x002c96e0_loop_back_edge` |
| 14 | A float branch leaves the x87 status word in `ax` and then sets only `al` (`fnstsw ax; test ah, 0x41; ...; mov al, 1; ret`). The return compare flagged the status bytes (0x4000 vs 0): 0x000452e0. | `eax` bytes that last came from `fnstsw` aren't compared. `al` still is. | `0x000452e0_status_word`, `..._wrong_al` (fail) |
| 15 | The level-3 time budget wasn't on the CLI, so slow functions fell short of 50 completed inputs depending on load. | `--time-budget S`. `promotable_note` says when the budget ran out. Promotion scripts can pass a bigger one for slow functions (0x002c7a50 ~900 s, 0x00227a10/0x002299c0 ~1500 s). | — |
| 16 | `status: equivalent` is reported at thin coverage (agents kept noting it). | A new `promotable` field: `equivalent`, ≥75% branch coverage, ≥50 completed inputs, no level-2 conflicts, ≤10% of inputs set aside as wild. Plus `promotable_note` and a text line. `status` is unchanged for its consumers. | — |

## Not changed, with reasons

- **Extent growth over compiler temporaries** (0x00359510, 0x000c1b50). The compared extent of a scalar or
  unknown out-parameter grows over neighbouring words the function wrote. That can pull in a spill slot that
  no source reproduces. The checker can't tell such a slot from an array element the source forgot to
  write, so not comparing it would hide real dropped stores. Workaround: declare the callee's parameter as a
  pointer to an exact-size struct (`struct Max { float v; }`). Class pointees are compared over exactly their
  `sizeof`.
- **0x00223870 "regression"**: not a regression. The round-3 checker (feff2ce6) and the batch-bq promotion
  check on mac1 (`rp-bq.jsonl`) both give 8 completed inputs and 33/106 edges. The 95/106 in the log never
  came from a 3000-input run.
- P6 bug 2 (fill words the function wrote when the callee's static extent covers them, 0x00148b00).
  Overwriting a value the function wrote could hide its later read-back. Not done.
- Tried and reverted: letting random inputs continue past 32 inconclusive ones while repairs still find
  edges (the extra timeouts ate the time budget: 0x002c96e0 fell back), and planting one fuzzed string over
  another for inline byte compares (0x00044cb0's name loop: most fuzzed names are empty, no gain).
- Loop repair order is a trade-off: back edge first lifts the vertex emitters (0x002c96e0 182 → 291–326
  edges) but 0x002fdf40 reaches 36/50 instead of 48/50 (HEAD: 37/50). Trying both orders per input (every
  other stuck input, or back edge last) did worse on both. A better rule needs to tell a top-tested loop's
  exit compare from a clamp.
- Count×size buffer fills (FUN_002647e0(dst, 0x1f, 4) fills only 16 of 124 bytes; 0x002de030 DDS
  fourCC) and combined constraints (stub result == field and a range check, 0x0004cbe0). These are open.

## Validation (2026-10-13)

- `tests/equiv/regress.py`: 60/60. The 17 new cases fail under the round-4 checker.
- `tests/equiv/selftest.py` (300 matches): 300/300. The two standing failures (0x00312db0, 0x003388d0) are
  fixed (change 11) and have regression cases.
- `tests/equiv/mutate.py` (120 functions): 363 caught, 6 commutes pass, 0 false failures. The 5 false
  passes (0x000200f0, 0x000c87a0, 0x000e5f70, 0x0011c840, 0x003303e0 mutants) are false passes under the
  round-4 checker too.
- `equivalent/` at `--inputs 3000`:
  - seeded random 200 (seed 2026): 200/200 equivalent;
  - every file the changes plausibly touch (x87 compares, sign tests, odd-offset `lea`, `mov ecx, esp`,
    no-op moves, thunk calls, `dynamic_cast`, `new[]`/`L""`), checked on mac1 in two parts: 800 under the
    build before change 13, all equivalent but **0x00195560**, plus most of the other 395 under change 13.
  - 0x00195560 newly fails: `Request` is 0x90 bytes in the source, and FUN_00059820 → FUN_00059510
    writes bytes 0x90 and 0x91. The dead return-address slot used to hide this (change 4). It is a real
    source bug. The file was not deleted.
- Logged failures re-run (95 sources from work/ and equiv-demoted/):
  - **21 now pass the bar** (≥75%, ≥50 inputs, no conflicts) and failed it under the round-4 checker:
    0x000452e0, 0x0007c5b0, 0x0007f690, 0x00087630, 0x000bfa10, 0x000c2c20, 0x000f8280, 0x00107410,
    0x00117150, 0x0012f750 (demoted copy), 0x001a9f10, 0x001b7f40, 0x001c6fe0, 0x001d2ee0, 0x001d8350,
    0x001db230, 0x001ecda0, 0x00258530, 0x00272df0, 0x002e2a70, 0x00334620.
  - 18 more already passed under the round-4 checker at 3000 inputs (stale log entries, or sources
    fixed since).
