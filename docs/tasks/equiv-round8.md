# Equivalence checker round 8

Round 8 worked through the batch cases of fx7a/fx7b, "What's left" in [round 7](equiv-round7.md), and the
coverage limits that older batch logs blamed on the checker. Each logged failure was reproduced under one seed
(`EQUIV_SEEDS=N`) and traced on both sides. Notes had the wrong cause again: 0x000dcae0 ("loop-repair patches
of spill slots S+0x10/0x14") is a stub-filled array index of -1 whose store lands on the original's loop
counter spill, and 0x00218350 ("ours takes luaC_barrier where the original calls luaV_lessequal") is an x87
precision difference in OP_FORLOOP. 0x00292f60's error was the same crash as 0x0028ff00.

Soundness rule (unchanged): a change may only steer inputs or make inputs inconclusive. It never relaxes the
comparison of a real difference. Each fix has a case in `tests/equiv/cases/` that fails under the round-7
checker (`tests/equiv/regress.py`), and `_wrong` cases show that a real difference is still caught.
`EQUIV_OFF=name,name` switches each named change off (the names are in the table and next to the code).

## Changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | `c->u.f(L)` through a fuzzed `lua_CFunction` (0x00215790, newly failing in round 7: "this (ecx) is 0x8, expected 0"). `ecx` is compared at an indirect call that looks virtual (`call [reg+d]` with reg == `[ecx]`). On the null page `[0] == 0`, so a closure pointer of 0 looked like a receiver on both sides. Lua's DumpFunction (0x0021a830) calls a cdecl writer callback 20 times, with `ecx` left over from instruction selection. (`ccall`) | The original's caller proves the callee cdecl: it releases every word pushed for the call right after it (`push esi; call [ecx+0xc]; add esp, 4`, with only plain instructions in between and no epilogue). Thiscall, stdcall and fastcall pop their own words, and a member function with `...` is cdecl with `this` pushed, so a cdecl callee doesn't take `ecx`. A later call through the same field (the same operand at the same non-stack address, `call [esi+4]` again) has the same pointer type, so the proof carries over to calls whose cleanup is shared with the next call's (`call [esi+4]; ...; push x4; call [esi+4]; add esp, 0x20`). Only the original's code counts as evidence. | `0x00215790_cdecl_ecx`, `0x0021a830_cdecl_field` |
| 2 | A void virtual (0x000da930): the original leaves `FUN_000fc3d0()`'s result in `eax` after `cmp [eax+0x221c], ebx`, and a read of a callee's result counted as evidence that the function returns it ("left 0x4001a8c4 in eax"). (`derefonly`) | A callee's result that was only dereferenced (used as a memory base or index, no implicit read) isn't evidence: `use(f()->x)` and `p = f(); use(p->x); return p` compile alike. A result tested or copied as a value still counts (`0x0026ce10_void_eax` still fails). | `0x000da930_deref_result` |
| 3 | `max()` of an empty sequence in loop repair (0x0028ff00, 0x00292f60 at 12k inputs): an input that timed out inside a CRT helper run for real (memset) had no jcc of the function counted. | `default=0`. | `0x0028ff00_helper_timeout` (seed 105; 0x00292f60 crashed on seed 420) |
| 4 | strncat with overlapping source and destination (0x003468c0, seeds 1101/1197/1205: `src == dest`, `src == dest + 12`). The original reads the source a word at a time, a byte loop sees its own writes. Undefined behaviour. (`overlap`) | For a CRT copy routine under test (`_strncat`, `_strcat`, `_strncpy`, `_strcpy` and the wide versions; not `_memcpy`, which is `_memmove`'s code in this XBE) an input that shows a difference is inconclusive when the bytes it certainly touches overlap: the source read and the destination string read and written, from the input's memory, with a string longer than 64 KB taken as 64 KB (a subset of what is read). A destination whose end isn't found proves nothing. 13 of 3037 inputs. | `0x003468c0_overlap_ub`, `..._wrong` (no terminator when the count runs out: fails) |
| 5 | `buf[len] = 0` with a fuzzed `len` (0x001f0090, "ebx not preserved"): the original's store lands on its saved `ebx`, ours elsewhere. Also arrays indexed past the return address (0x000a2800, 0x000a89c0: those went wild before). (`smash`) | An array-style store in the original (indexed, through a pointer, or a string instruction) over its return address or a live saved-register slot is a buffer overrun, undefined behaviour no real input causes: if the input shows a difference, or the original then goes wild, it is inconclusive (`statuses`: `stack_smash`; not counted against the 10% wild bar). An overrun input that agrees counts as before (0x00203a80's `buf[strlen(buf) - 4] = 0` overruns on a third of its inputs, identically on both sides). Plain `mov [esp+k]` stores don't count: an argument word pushed once and rewritten for the next call can look like a register save. | `0x001f0090_buf_overrun`, `..._wrong` (`count < 7`: fails) |
| 6 | `sete byte ptr [esp+0x1c]` (0x0023c040): a setcc into memory was never recorded, so both of its outcomes stayed uncovered. (`setmem`) | Its outcome is the byte it stores. | `0x0023c040_wrap_setmem` |
| 7 | `lea ecx, [ebp+3]; cmp ebp, ecx; jae` (reverse4 in 0x0023c040, 3 edges): taken only when `p + 3` wraps past 2^32. (`wrapcmp`) | That side is dead when one of the two registers is used as a memory base in the function (a pointer: no object straddles the top of the address space, and computing `p + 3` past it is undefined). Straight-line code, neither register rewritten between the lea and the cmp. | `0x0023c040_wrap_setmem` (15/22 -> 17/19) |
| 8 | `xor eax, eax` before a list walk, `test eax, eax; jne` after it (0x00233990): `eax` is 0 on every path, so the taken side is dead. (`constflags`) | A forward constant propagation over the registers (`xor r, r`, `mov r, imm`, `mov r, r2`; any other write, and every call, makes a register unknown; `test r, r; je L` makes r 0 at L). A jcc whose flag-setting `test`/`cmp`/`or` sees constants on every path has a dead side. A side any rule calls dead that a run takes anyway counts normally and is listed in `coverage.dead_taken` (a checker bug to report). | `0x00233990_const_flags` (22/30 -> 22/28) |
| 9 | The 32-inconclusive cap of the random phase stopped 0x00359a80 (a polygon clipper, 21% of its inputs run away) at 121 completed inputs and 46/72 edges, and the round-6 follow-ups only run while fewer than 50 completed or at most 20% were inconclusive. (`covcap`) | While branch coverage is under the 75% bar after the directed phase, the time left goes to more random inputs, then directed ones again. Only runs that couldn't be promoted anyway take longer. | `0x00359a80_cov_cap` (46/72 -> 66/72, ~100 s) |
| 10 | `EQUIV_SEEDS=N` with `--inputs <= N` reported unsupported (no seed in range). | The seeds set `--inputs` as `seeds=` does. | `tests/equiv/test_equiv.py` `test_env_seed_past_inputs` |

Not checker bugs, diagnosed:

- **0x000dcae0** (FETextInput::vfunc_5, `5+loop`/`5+patch`). The loop repair's patches are heap overlays of the
  loop count (`this+0x150`) and `this+0x178`, not stack words, and the spill slots are not register-allocated
  differently in a way that matters. The failure is a fuzzed index: `FUN_000f7fe0` (stubbed) builds the
  `Lay` object on the stack and its fill leaves `idx == -1`, so `mov [esp + idx*16 + 0x24], 1` writes 16 bytes
  below the cell array. In the original that is S+0x14, its spilled loop counter `i`, which it reloads after
  the highlight `FUN_000f80e0` calls (`mov edi, [esp+0x14]`): `i` becomes 1 and the original skips to the
  second iteration's part B, while ours (another frame layout) keeps `i`. A store outside a local array is
  undefined behaviour, but the checker can't prove the array's bounds, so the input isn't made inconclusive
  (a spill slot can't be told from an array element accessed at a fixed offset). It is the "fuzzed stack-array
  indices" class (0x00282d00, 0x0028a630). The other 2605 inputs agree.
- **0x00218350** (luaV_execute), input 5102 (`--inputs 20000`): a source difference. OP_FORLOOP compares the
  new index with the limit. The original rounds `idx = ra->value.n + step` to a float before the compare
  (`fstp [esp+0x1c]` ... `fld [esp+0x1c]; fcomp [esp+0x24]`); ours compares the unrounded 80-bit sum
  (`fadd; fst [esp+0x18]; ...; fcomp st(1)`). On input 5102 the rounded index equals the limit, so the
  original loops and ours falls through, and the next opcode differs (call #2 to 0x00217100 instead of
  0x00217d80). Fix in the source: make the compare use the stored float, e.g. `volatile float idx =
  ra[2].value.n + ra->value.n;` in `case 28` (with it, seed 5102 passes and `--inputs 3000` gives 893
  compared, 0 failed, 224/228). Reordering the statements as in Lua 5.1 (`step`, `idx`, `limit`, `0 < step`)
  doesn't change MSVC's code.

## Validation (2026-10-15)

- `tests/equiv/regress.py`: 110/110. All 11 new cases fail under the round-7 checker
  (`EQUIV_MODULE=equiv_r7`; `0x0028ff00_helper_timeout` crashes it). The two `_wrong` cases fail under both:
  they guard changes 4 and 5 against hiding a real difference.
- `tests/equiv/selftest.py` (300 matches): 300/300.
- `tests/equiv/mutate.py` on round 7's pinned 120 functions: 362 caught, 8 commutes pass, 0 false failures,
  11 false passes. The mutants aren't round 7's: the stub reconciliation is editing `matches/` in the working
  tree, and 38 mutants don't compile (round 7: 8; the `const` operator's `0 -> 1` on what are now pointer
  literals). The round-7 checker on the 11 functions with a false pass gives the same outcome mutant by
  mutant (11 false passes, the same ones). No new false passes.
- `equivalent/`, a random 300 (seed 2032 over the sorted file list) at `--inputs 3000`, locally: 299
  equivalent. **0x000fce60 fails**, and it fails the same way under round 7 (not a round-8 change; the file
  is unchanged since its promotion): "call #2 to 0x0022baf0 writes 0x2c bytes through ecx ... ours has only
  0x10 bytes there". The `fy <= 0.001` branch's local `Quat_fce60 q` (16 bytes) is the `this` of
  0x0022baf0, which is `Matrix::build` in `equivalent/0x0022baf0.cpp` (`float m[16]`): a source bug, the local
  must be the matrix. File left alone. Below the bar but equivalent, as under round 7: 0x001ae450 (55/80),
  0x001dec10 (12 inputs; 21 under round 7). No `dead_taken` anywhere. `stack_smash` set aside 129 inputs over
  3 functions (0x000e9af0, 0x00283110, 0x002aea70), all still equivalent and promotable.
- Logged failures and round 7's leftovers, 33 sources from `equivalent/`, `pass/` or `work/` (the files were
  unchanged between the two runs), at `--inputs 3000`, round 7 -> round 8:
  - **Newly promotable** (equivalent, no conflicts, >= 75%, >= 50 inputs; default flags unless given):
    0x0021a830 (work/; fail -> 7/7, 130 inputs), 0x003468c0 (pass/; fail -> 46/48, 3024, 13 `overlap_ub`),
    0x00233990 (work/; 22/30 -> 22/28), 0x0023c040 (work/; 15/22 -> 17/19), 0x00359a80 (work/; 46/72, 121 ->
    66/72, 1515: uses the 3x budget, ~2 min CPU), 0x001f0090 (work/; fail -> 10/10, 116),
    0x000a89c0 (work/; 60/82 -> 73/82, 1146: 410 `stack_smash` inputs; ~2 min), 0x0029dd30 (work/; 18/26, 57
    -> 25/26, 619; ~2 min), 0x000da930 (**work/** copy, the fx7a fix; fail -> 305/312, 3346. The pass/ copy
    still fails: "missing write to this+0x3ac before call #6 (expected 0x1d)", the 0x1b case fx7a fixed).
  - Already in `equivalent/`, now passing again: 0x00215790 (fail -> 22/22, 94), 0x0028ff00 and 0x00292f60
    (round 7 crashes -> 10/10, 50 inputs and 22/22, 2943).
  - Promotable before and still (round 7 already passed them; their log entries are stale, they only need a
    promotion run): 0x002ebef0 (74/90, 50 inputs: borderline, use `--time-budget 300`), 0x0023a6b0 (84/102),
    0x002a0050 (87/90), 0x002bb0b0 (37/48 -> 39/48), 0x001ad8c0 (79/80), 0x0029d880 (50/54), 0x002e3bd0
    (118/118), 0x0025f450 (55/56), 0x000a2800 (38/40, 92 inputs), 0x00218350 (pass/; 224/228, 763 inputs;
    input 5102 needs `--inputs 20000`, see the diagnosis above), and the equivalent/ files 0x000e4330,
    0x000e4470, 0x000e43c0 (7/9), 0x002fdf40 (48/50), 0x00203a80 (9/9).
  - Still failing, source bugs (same under round 7): 0x0021ab30 ("call #3 to 0x3e800000: the local passed as
    argument 2 differs at +0x1"), 0x0001df20 ("call #720 to 0x00059820 writes 0x94 bytes through ecx ... ours
    has only 0x90 bytes": the local is 4 bytes short), 0x000dcae0 (call #25, the fuzzed-index store diagnosed
    above).
  - Unchanged: 0x0024a800 44/56 at 42 inputs, 0x0026bac0 and 0x0024ad20 unsupported (every input times
    out), 0x0029d5d0 31/42 (74%).
- **0x002eea80** (reported by a batch agent as a possible round-8 regression: "call #8 went to 0x00000005
  instead of 0x00000000" on input `2+patch`, 1 failure in 50 completed). Not a checker change: the round-7
  checker fails the same input the same way (the only difference is 52 -> 51 edges, a dead side). It is a
  source bug the old checker never reached (it completed 19 inputs): `Target` declares `attach` as its 15th
  virtual, so ours calls `[vtbl+0x38]` where the original calls `[vtbl+0x3c]` (0x2eebf9). On `2+patch` the
  target is on the null page, where the two slots hold different words. With `virtual void v14();` added
  before `attach`, the pass/ source is equivalent: 51/51, 50 completed (borderline: `--time-budget 300`).

## What's left, ranked

1. **Fuzzed stack-array indices** (0x000dcae0; 0x00282d00, 0x0028a630 from round 6): a store through a
   stub-filled index lands on a spill slot the original reloads. Change 5 only covers overruns into the
   return address and saved registers; a spill slot can't be told from an array element at a fixed offset
   without the array's bounds. Next step: bound the array from the original's addressing (`[esp + idx*16 +
   0x24]` with the next fixed-offset access above it) and make inputs whose index falls outside it
   inconclusive when they differ.
2. **Walks the sentinels don't end** (unchanged): 0x0024a800 (42 inputs), 0x0026bac0 (per-bin sentinels),
   0x0024ad20 (needs an erase stub that unlinks).
3. **Just under the bar**: 0x0029d5d0 31/42 (74%), 0x001ae450 55/80, 0x001dec10 and 0x002eea80/0x002ebef0
   at ~50 inputs (most inputs time out in loops over fuzzed counts).
4. **Per-iteration observations** (unchanged; all pass the bar): 0x000e4330/0x000e4470/0x000e43c0 7/9,
   0x002fdf40 48/50.
5. **Compiler temporaries in compared extents** (round 7 item 4, unchanged): 0x00359510, 0x000c1b50,
   0x0028e160.
6. **Coverage limits in older logs** (work item 8): most of the "checker limit" entries checked here pass
   under round 7 already (list above): the log is stale, not the checker. The remaining clusters are
   count x size buffer fills (0x002de030), combined directed constraints (0x0004cbe0), float results that
   stubs can't steer (0x0029d090 negative clamps, 0x002e8f80 fabs tolerances, 0x000f3dc0 `__ftol2` ranges),
   and stub fills that never produce a valid iterator (0x001aedb0 `idx != -1`).
7. x87 64/80-bit intermediates (accepted by the tolerance rule), unchanged.

## Recipes for batch agents

- **Re-promote stale "checker limit" entries before rewriting anything.** Many log entries that blame the
  checker pass now (0x002ebef0, 0x0023a6b0, 0x002a0050, 0x002bb0b0, 0x001ad8c0, 0x0029d880, 0x002e3bd0,
  0x0025f450, 0x000a2800, and round 8's list above): re-run the existing source at `--inputs 3000` first.
- **Indirect calls through cdecl function pointers** (Lua's `lua_CFunction`, writer callbacks) no longer
  compare `ecx`: no `equiv-conv` or register juggling is needed for them.
- **`call #k went to X instead of Y` at a virtual call** usually means a wrong vtable slot: count the
  declared virtuals against the original's `call [reg+0xNN]` (0x002eea80 was one short). Inputs on the null
  page expose it only rarely, so a source that passed with few inputs can fail later.
- **`writes 0xN bytes through ecx/argument k ... make the local as big as the callee's object`**: the
  local's type is too small (0x000fce60, 0x0001df20); find the callee's real object type, don't pad blindly.
- **`stack_smash` and `overlap_ub` in `statuses`** are inputs that are undefined behaviour in the original
  (a fuzzed length overrunning a buffer into saved registers, overlapping strcpy/strcat arguments). They are
  set aside only when they differ; a wrong bound still fails on other inputs. Nothing to do in the source.
- **Coverage under 75% after the random phase stopped** now runs longer (up to the 3x time budget, ~2-6 min
  for loop-heavy functions). Don't kill such runs early; `--time-budget 300` helps borderline ones.
- **`coverage.dead_taken`** in a report is a checker bug (a side a rule called dead was taken): report the
  address, don't work around it.
- **`EQUIV_SEEDS=N`** now runs seed N whatever `--inputs` says: reproduce a failing input with
  `EQUIV_SEEDS=5102 tools/equiv.py SRC ADDR`.
- **x87 compares against a stored float** (`fstp [esp+k]; fld [esp+k]; fcomp`): when the original rounds a
  value to float before comparing and ours compares the 80-bit sum, make the variable `volatile float`
  (0x00218350's OP_FORLOOP).
