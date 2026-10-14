# Equivalence checker round 7

Round 7 worked through the batch cases of fx5, s38 and s39, "What's left" in [round 6](equiv-round6.md)
items 1-6, and equiv.py on merged source-tree objects ([source-tree.md](../source-tree.md)). Each logged
failure was reproduced under one seed (`EQUIV_SEEDS=N`) and traced on both sides. Several notes had the wrong
cause again: 0x0021acc0 ("stub writes through `&byte` smash the return address") was a cdecl callback whose
shared `add esp, 0x40` lay past the cleanup scan's window; 0x002adb10 ("prologue pushes counted as
arguments") was a tail call out of an `equiv-conv` function; 0x001d2190 ("a type byte the directed phase
can't reach") had only 4 words of its 0x2c0-byte by-value argument in the input, and once it has all of them
the source turns out to read `lua_State*` 4 bytes early.

Soundness rule (unchanged): a change may only steer inputs or make inputs inconclusive. It never relaxes the
comparison of a real difference. Each fix has a case in `tests/equiv/cases/` that fails under the round-6
checker (`tests/equiv/regress.py`). `EQUIV_OFF=name,name` switches each named change off (the names are in
the table and next to the code).

## Changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | Merged source-tree objects (`tools/build_tree.py`) wrap a function in `namespace fn_<addr>`. Its mangled names then differ from the standalone source's: the `sizeof` probe of `fn_00040550::Link` failed to compile against the standalone source (no pointee sizes: "local passed as argument 1 differs"), `equiv-map` lines naming `?thunk_FUN_0008d690@@YAPAXI@Z` bound nothing (0x0002b970: "call #8 went to 0x0008d690"), and vftables of classes inside the namespace had no RTTI match (0x000306e0: our object's own address stored). 17 of the first 300 tree functions failed. (`treens`) | Probes strip the namespace when the source isn't wrapped. Explicit and convention names are matched by qualified name and signature with the namespace removed (back-references make a textual cut wrong). vftables and `??_R0` descriptors fall back to an RTTI lookup by demangled name without it. | `0x00040550_tree_probe_sizes`, `0x0002b970_tree_explicit_map`, `0x000306e0_tree_vftable` (each with a `.tree.cpp` wrapped copy; `regress.py` compiles it and checks it against the unwrapped source) |
| 2 | `OverflowError: float too large to pack` in `_patches`: a float compare against a huge value asks for `yv * 1.5`, which has no 4-byte form (0x0004c1f0, 0x0004c320 crashed standalone too). | Such patch values are skipped. | `0x0004c1f0_float_range` |
| 3 | `return (int)f` as `jmp _ftol` from an `equiv-conv` function (0x002208e0). The tail jump was stubbed: its argument words were each side's incoming stack words (3 cdecl words in ours, 1 in the original), and the float in `st0` was never compared at all. (`tailhelper`) | A tail jump to a CRT helper runs the helper for real, as a call to it does; its result is the return value. | `0x002208e0_tail_ftol`, `..._wrong` (`(int)(f + 100)` fails) |
| 4 | `lea ecx, [esi + 4]; add esp, 0xc; test ecx, ecx; ...; je` (a source `if (&tag)`): zero only when `this == -4` (0x00203bb0 7/20, 0x00203a80 9/22). (`leanull`, `unreach`) | The zero side is dead when the base register is used as a memory base in the function (straight-line code between `lea` and `jcc`, nothing jumps in). Code reachable only through dead sides is dead too (branches, `setcc`s, switch cases), for this rule and round 6's `cmp r, r`. Directed inputs don't chase dead sides. | `0x00203bb0_lea_null` (7/20 → 7/7) |
| 5 | Hand-reviewed dead edges (round 6 item 3) had no way to be declared. (`declared`) | `// equiv-dead: +0x63 taken, +0x70 not taken: why` in the source leaves those sides (and code only they reach) out of the count; the report lists them (`coverage.declared_dead`, a text line). | `0x00203a80_declared_dead` |
| 6 | 0x0009d1b0 (void virtual): the original leaves `eax == 0` from a switch's `dec eax; dec eax; jne` chain on one path; that write was taken for a result "the function never reads back". (`voidflags`) | An arithmetic write of `eax` whose flags the next instruction tests (jcc, setcc, cmov, adc/sbb) is a read: the value was used, and a return value doesn't explain it. `left X in eax` still fails for real dead writes (`0x0026ce10_void_eax`). | `0x0009d1b0_void_dec_chain` |
| 7 | Lua's DumpHeader (0x0021acc0): four calls through a cdecl writer callback share one `add esp, 0x40` 31 instructions after the first call. `cleanup_after` looked 24 instructions ahead, so the first call was taken to pop its 4 words, the stack drifted, and every input went wild at the final `ret`. The log blamed stub writes through `&byte`. (`cleanwin`) | The scan looks 48 instructions ahead (it still subtracts later pushes and known pops, so a too-early guess comes out negative and is dropped). | `0x0021acc0_shared_cleanup`, `..._wrong` (a wrong version byte fails) |
| 8 | Long but finite code that makes thousands of stub calls (0x00280690: 100 objects × 66 calls; 0x001e7290: a 2048-slot scan) never got the 1M-step budget: that rule excludes runs with ≥ 500 calls (loops a stubbed callee keeps going), or reverted when 1M wasn't enough. Agents had to pass `--steps 3000000`. (`probe`) (Also probing after a failed 1M budget was tried and dropped: on runaway tree walks, 0x002639c0 and 0x0025b7d0, the 8M-step run used the whole time budget.) | When the first 4 inputs all time out and the 1M rule doesn't apply, input 0 is run once with 8M steps. If it returns, later inputs get twice the steps it took (at least 1M) and 3x the time budget. Not with `EQUIV_SEEDS`. | `0x00280690_step_probe` |
| 9 | rb-tree and list walks over fuzzed links never reach `&tree.nil` (0x0024a280 1/42, 0x00242da0 2/30 with 8-13 inputs; round 6 item 2). Links that are 0 cycle on the null page. (`sentinel`) | A timed-out original's hottest compares that held one operand fixed (a heap, stack or image pointer) while the other came from memory give the walk's sentinels. The input is run again with them in half the words of every data page (same positions per page, all epochs). A run that hangs toward a new sentinel (a second tree) goes again with both, 3 deep. After 4 runs without a completion the function stops getting them (the vertex emitters time out at full cost). | (0x0024a280 → 41/42, 0x00242da0 → 30/30: slow, not in regress) |
| 10 | `mov ax, [buf]; cmp al, 'B'; jne; cmp ah, 'M'` on a magic a stubbed read filled (0x002afa60 3/20): `ah` had no source. (`ahbyte`) | The high byte of a loaded word is its source shifted right by 8 (the low byte kept from the raw value when inverted). | `0x002afa60_ah_magic` (3/20 → 20/20) |
| 11 | `v.z == 0` after FUN_0022d240 filled the vector (0x00292cc0 1/2). FUN_0022d240 passes its `ecx` on to FUN_0022c2b0, which writes it with `fstp`. Capstone marks the memory operand of x87 stores read-only, so `callee_writes` missed every float store: the vector was never filled (it held STACK_FILL on both sides). (`x87st`, `ffill`) | x87 stores count as writes in `callee_writes`. A float compared after a stub filled it can be patched like any filled word (exact ties allowed against a constant). | `0x00292cc0_fstp_extent` (1/2 → 2/2) |
| 12 | `fld [g]; fadd [k]; fst [g]; fcomp [0.95]` on a `.data` float (0x000fee10 1/2): computed, so no source. (`fxf`) | `fadd/fsub/fsubr/fmul` by a memory constant and `fchs` are followed and inverted (no exact ties: the value is computed). | `0x000fee10_fadd_global` (1/2 → 2/2) |
| 13 | `fabs` as `and eax, 0x7fffffff` on an argument, stored to a slot, then `fucompp` against pi/2 (0x000f1bd0 1/2, round 6 item 6): the float load had no source. (`fabs`) | A float loaded from a slot that holds a masked argument word is steered through the argument, mask inverted; the tie is exact, so it is planted. | `0x000f1bd0_fabs_tie` (1/2 → 2/2) |
| 14 | An atof-style parser (0x00260d00 16/22): fuzzed bytes never spell `.` then digits. A keyword compare on a stack copy of a stub-returned string (0x0028fbc0 18/36): stack bytes that aren't a stub fill can't be planted. (`alpha`) | Byte compares against constants record the buffer and the constants (immediates, `mov al, 's'; cmp cl, al`). Strings made of those chars, with runs and keywords (compares at consecutive offsets of one pointer: `cla`, and letter runs the compares went through) are planted where the loop read its first byte; a stack copy (`mov [stack], cl` of a loaded byte) is planted through its source. Queued like literal plants, again whenever the alphabet grows. | `0x00260d00_alpha_digits` (16 → 20/22), `0x0028fbc0_copied_keyword` (18 → 29/36) |
| 15 | A 0x2c0-byte struct passed by value (0x001d2190) got 4 input words; the rest of the argument area was STACK_FILL, the same on both sides, and its type bytes at +0x2b0 couldn't be patched. (`bigstruct`, `sbyte`) | A by-value struct gets as many words as the function's own `ret N` pops or its code reads. Bytes and halves of stack argument words can be patched. With the whole argument fuzzed the source fails: it reads `call.L` at +0x2b8, the original at +0x2bc (`types` is 12 bytes, not 8 + pad). | `0x001d2190_bigstruct_arg` (fail; passed under round 6 at 14/20) |
| 16 | A tail call (`jmp [edx+0x28]`) out of an `equiv-conv` function (0x002adb10, eax/esi/edi): each side passes on its own incoming stack words, 3 cdecl words in ours and none in the original ("3 argument words, expected 0"). Round 6 blamed prologue pushes (item 5). (`tailconv`) | At a tail call of an `equiv-conv` function, ours compares as many words as the original's call passes (learned per call, as for unknown arities). | `0x002adb10_conv_tail_vcall` |
| 17 | A byte flag passed in `cl`/`dl` (equiv-conv) over whatever the caller left in the high bytes (0x002d0a50, round 6 item 4): compared as the whole register. (`partreg`) | `Program.reg_read_width`: the bits of an incoming register the real callee reads before overwriting it, on every path (a call or a tail jump counts as reading all of it). A register argument compares on those bits. | `0x002d0a50_byte_flag_reg`, `..._wrong` (flag 2 instead of 0 fails) |
| 18 | A by-value struct whose padding holds a stale return address (0x001f9710: 0x001f977a in the original, 0x600000aa in ours, "argument 4 differs"). (`retaddr`) | An argument word that holds, on each side, the return address of the same earlier call (the latest call returning there) is equal. | (0x001f9710: work/ source fails differently now, see below) |

## Validation (2026-10-14)

- `tests/equiv/regress.py`: 99/99. 22 of the 23 new cases fail under the round-6 checker
  (`EQUIV_MODULE=equiv_r6`; `0x0004c1f0_float_range` crashes it). The 23rd, `0x002d0a50_byte_flag_reg_wrong`,
  fails under both: it guards change 17 against hiding a wrong flag.
- `tests/equiv/selftest.py` (300 matches): 300/300.
- `tests/equiv/mutate.py` on round 6's pinned 120 functions (`--only`, the list from round 6's run):
  identical outcomes mutant by mutant. 362 caught, 8 commutes pass, 0 false failures, the same 10 false passes.
- Merged source tree: the first 300 `equivalent/` functions of `build/tree/report.json`, run on their tree
  objects (`verify(..., symbol=..., obj_path=...)`): 300/300 equivalent (round 6: 281, 17 fail, 2 crash).
- `equivalent/`, a random 200 (seed 2031) at `--inputs 3000`, locally: 199 equivalent. **Newly failing:
  0x00215790** (file left alone). Directed input `79+patch`: "call #3 to 0x00000008: this (ecx) is 0x8,
  expected 0". The call is `c->u.f(L)` through a fuzzed `lua_CFunction` (cdecl); the original happens to
  hold the closure in `ecx`, ours the target pointer. The round-6 checker fails the same seed
  (`EQUIV_SEEDS=79`); it never ran it at 3000 inputs because it stopped at the 32-inconclusive cap after 84
  inputs. Round 7's walk-sentinel retries complete some of the timed-out inputs, so the random phase goes
  on. Not a source bug: `ecx` is compared at every indirect call, and a cdecl function pointer doesn't
  read it (see "What's left" 3).
- Logged failures and round 6's leftovers, 38 sources from `build/farm/bench/claude-equiv/pass/` (when
  present) or `work/`, at `--inputs 3000`, round 6 → round 7:
  - **Newly promotable** (equivalent, ≥ 75%, ≥ 50 inputs, no conflicts):
    0x0024a280 (1/42, 8 inputs → 41/42, 129), 0x00242da0 (2/30, 16 → 30/30, 50: borderline, 24-39 inputs
    in other runs: use `--time-budget 300`), 0x0025b7d0 (1/8, 38 → 8/8, 66),
    0x001e7290 and 0x00280690 (unsupported → 22/22, 92 and 4/4, 78 inputs, default `--steps`; both use the
    whole 3x budget, ~360 s), 0x002afa60 (3/20 → 20/20), 0x00292cc0, 0x000fee10 and 0x000f1bd0 (1/2 → 2/2),
    0x00260d00 (16 → 20/22), 0x0028fbc0 (24 → 29/36), 0x002e30f0 (94 → 116/126),
    0x00203bb0 (7/20 → 7/7), 0x00203a80 (9/22 → 9/9), 0x002208e0 (fail → 14/14), 0x0009d1b0 (pass/ copy:
    fail → 32/34), 0x0021acc0 (unsupported → 3000 inputs, no branches), 0x001f9710 (fail → 8/8),
    0x002adb10 (fail → 4/4, 151 inputs), 0x002d0a50 (fail → 18/18).
  - Promotable before and still: 0x0007f690 (pass/), 0x000e4330, 0x000e4470, 0x000e43c0 (7/9),
    0x002fdf40 (48/50), 0x0003c1d0 (193 → 196/224).
  - **Now failing on newly reached inputs** (source bugs): 0x001d2190 (the whole by-value argument is
    fuzzed now; `call.L` is read at +0x2b8 where the original reads +0x2bc. With `char types[12]` and no
    `pad2bc` it is 20/20 at 3000 inputs, promotable), 0x001dec10 (unsupported → completes with the step
    probe; ours calls through a null pointer where the original calls 0x0027b040, call #2; the work/ source
    was never verified).
  - Unchanged: 0x0024a800 44/56 at 42 inputs (both trees' walks now end, but the per-node entry lists read
    misaligned planted words), 0x0026bac0 and 0x0024ad20 unsupported, 0x00359a80 46/72, 0x00233990 22/30,
    0x0023c040 15/22, 0x002639c0 36/52 (100 → 809 inputs), and the compiler-temporary failures 0x00359510,
    0x000c1b50, 0x0028e160.

## What's left, ranked

1. **Per-iteration observations** (unchanged from round 6 item 1): 0x000e4330/0x000e4470/0x000e43c0 stay at
   7/9 (they pass the bar), 0x002fdf40 48/50. Compares in later loop rounds still can't be targeted.
2. **Walks the sentinels don't end**: 0x0024a800 (per-node entry lists hang on misaligned reads of planted
   words; a run needs both trees' sentinels and the lists' 0), 0x0026bac0 (127 circular bins, each with its own
   head as sentinel: the sentinel moves with the outer loop), 0x0024ad20 (teardown loops end only through a
   callee that unlinks). A sentinel per bin (`head + 8k`) and an erase stub that unlinks are the next steps.
3. **`ecx` at indirect calls through cdecl function pointers** (0x00215790 above): compared because the
   target is unknown and may be a thiscall. Our object knows the pointer's type only through the source; a
   per-call-site declaration (`equiv-conv`-like, for call sites) would let the check skip `ecx` soundly.
4. **Compiler temporaries in compared extents** (round 6 item 8, task B7): 0x00359510 (the strength-reduced
   pointer difference at S+0x24), 0x000c1b50 (a spill next to the caster), 0x0028e160 (a loop bound in a
   dead argument slot). Not changed: the checker can't tell such a word from an array element the source
   forgot, so skipping it would hide real dropped stores. 0x001f9710's stale return address was a different
   case (fixed, change 18).
5. **Infeasible edges by value range** (round 6 item 3): 0x00233990 22/30, 0x0023c040 15/22. `equiv-dead`
   (change 5) now lets a reviewer declare them; no automatic range analysis yet.
6. **Just under the bar**: 0x00359a80 46/72 (121 inputs: loop re-entry arms need ≥ 52 polygon vertices),
   0x0024a800 (above). 0x00242da0 reaches 50 inputs only sometimes.
7. Unchanged from round 6: count×size buffer fills (0x002de030), combined directed constraints (0x0004cbe0),
   fuzzed stack-array indices (0x00282d00, 0x0028a630), x87 64/80-bit intermediates (accepted by the
   tolerance rule).

## Recipes for batch agents

- **Don't pass `--steps 3000000` any more.** Long but finite code (thousands of stub calls) gets its step
  budget from a probe run. It still uses the 3x time budget: expect ~6 minutes for 0x00280690-like
  constructors.
- **Byte flags in registers** (`equiv-conv` with a `char` in `cl`/`dl`): declare the parameter `char`; only
  the bits the real callee reads are compared, so leftover high bytes no longer need matching.
- **Dead branches** a reviewer has checked (a `this == -4` style test the rules don't cover, a value-range
  dead edge): add `// equiv-dead: +0x63 taken, +0x70 not taken: why` with the labels the report prints. The
  report lists them under `declared_dead`; say why in the comment, since a reviewer of the promotion reads it.
  `lea ecx, [esi + 4]; test ecx, ecx` null checks need nothing: they are dead automatically.
- **Structs passed by value** are fuzzed over their full size now (the function's `ret N`): get every field
  offset right, padding included. Sources that passed with a wrong tail layout fail now (0x001d2190).
- Sources in a merged tree object can be checked with `verify(src, addr, symbol=..., obj_path=...)`; no
  source change is needed for `namespace fn_<addr>`.
