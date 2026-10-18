# Equivalence checker round 13

Round 13 took the checker gaps that fix batches fx14 and fx15 found, plus three sources that byte-match but load a
float constant with the wrong value:

- **cleanup before `ret`** (fx14, 0x0026dc20). `push [eax+4]; call [eax]; pop ecx; ret 4` with no frame:
  `cleanup_after` treats `pop ecx` before a `ret` as an epilogue. The unknown-arity call was then assumed to pop its
  own word, so the `pop ecx` took the return address and every input ran wild.
- **`/GS` in `// cl-flags:`** (fx14). compare.py dropped the token, so sources wrote the cookie check out by hand.
- **pointers that are never real objects** (fx15, 0x002e22c0). `D = B->f5c`, where B is the allocator stub's
  result and a constructor stub fills B. On every input that reached them, D's fields were in the null page, and
  `[D+0x18]` and `[D+0x1c]` both read 0. A source that read every field of D 4 bytes too high passed 3,000 inputs.
- **float constants a few ulps off** (equivalent/0x000d6b20, 0x001c52f0, 0x001fbd00; `tools/verify_relocs.py`
  reports `float_mismatch`). Level 2 only warned about them (`float_constant_not_in_original` plus
  `missing_float_constant`). Level 3 compares floats with a relative tolerance of 1e-5, and these differ by 2e-7 to
  4e-7, so every input passed. The constant is reached; the tolerance hid it. (0x001c52f0 already failed under
  round 12, through a tie input, not through the constant itself.)

Soundness rule (unchanged): `equiv.py` changes may only steer inputs, add comparisons or make inputs inconclusive,
and `compare.py` may never let different bytes MATCH. `popret` is the exception, and the user asked for it (work
item 1). It is a stub-arity fix, the same kind as rounds 7 and 8's cleanup fixes. Each side applies it only when
its own run's stack proves the shape, so it never turns a callee-popped call into a caller-cleaned one (see #1).
Every change has a case that fails under round 12 and passes now, and a `_wrong` case shows real differences are
still caught. `EQUIV_OFF=popret|objptr|fconst` turns each change off.

## equiv.py changes

| # | Root cause | Fix | Case |
|---|---|---|---|
| 1 | `pop ecx` (once or twice) right before `ret` is never argument cleanup in `cleanup_after`. After `call [eax]` (unknown arity), the stub popped the pushed word, so the `pop ecx` popped the return address: 0x0026dc20 was `unsupported` (256/256 wild). (`popret`) | `CodeView.pop_ret_cleanup` reads the pops; `_stub` takes them as the call's cleanup only when `esp + n == ENTRY_ESP`, that is, when the pops end exactly on this run's return-address slot with the call's words still on the stack. fx14's static form (`n > frame_alloc()`) was not used. A static scan of game code found 18 functions with this shape, and 15 of them are `push ecx` frames (`push ecx; ...; push x; call [edx+0x1c]; pop ecx; ret`) where `frame_alloc()` is 0 and the pop releases the frame. There the runtime check ends one word short and keeps round 12's behaviour. | `0x0026dc20_pop_ret_cleanup` (round 12: unsupported; now equivalent, 1/1), `..._wrong` (`o->fn(t->arg)`: `call #2 to ...: argument 1 is`). Also newly supported: matches/0x000be4c0 and 0x001df680 (`Function1<...>::vfunc_2`, unsupported under round 12, now equivalent). The other 15 are unchanged. |
| 2 | A field read through a pointer that the fuzz never makes real: D in the null page, so neighbouring fields read the same 0. (`objptr`) | `Run._note_deref` records each `[reg + d]` access (0 <= d < 0x3f8) where reg was loaded unchanged from an input (memory, a stub result or fill, or a stack argument) and the word it reads equals a neighbouring word. Each pointer is keyed by the instruction that loaded it, else by its stub result or fill. After the tie inputs, `objptr_phase` plants the address of an object into the pointer's source, using up to 2 inputs per pointer and 24 per function. In the object, word i is `0x101 * (i + 1) + 0x10000 * depth`, so every word differs, the bytes of each word's low half differ, and counts stay small. A pointer loaded from that object gets the next of 4 objects (`inputs_objptr`, input labels `N+obj`). | `0x002e22c0_objptr` (fx15's fixed source: equivalent, 114/115), `..._wrong` (fx15's pre-fix source; round 12: equivalent at 3000 inputs, 114/115; now `input 80+obj: call #20 to 0x002647e0: argument 1 is 0x00000808, expected 0x00000707`) |
| 3 | A float constant of ours that the original doesn't have was only a level-2 warning. (`fconst`) | `_float_const_diffs` in `level2` turns it into an issue, `float_constant_differs` (a level-2 failure, not a warning). It applies when the original reads a constant it doesn't share with us that is within 1e-4 relative but not the same value, read at the original's load size (4 or 8 bytes). A double with exactly the float's value is not a difference. | `0x000d6b20_float_const_wrong` (equivalent/0x000d6b20.cpp as is; round 12: equivalent; now `L2 float_constant_differs __real@3c8efa39`), `0x000d6b20_float_const` (with `0.0174532924f`: equivalent; also MATCH, and verify_relocs reports no issues) |

`tests/equiv/regress.py` now also matches its expected text against level-2 issues (`"L2 kind symbol"`).

## compare.py change

`file_flags` accepts `/GS` and `/GS-` in a source's `// cl-flags:` line. This changes only what is compiled, never
how bytes are compared. 0x000c6d90 written with `// cl-flags: /GS` and a plain `char name[0x20]` (fx14's
`0x000c6d90_gs.cpp`) gives `MATCH ... bytes target=86 ours=86, target instructions matched 33/34`, equiv.py
`equivalent` (2998 inputs), and `verify_relocs.py` reports no issues. Without the flag: `DIFF ... ours=68` and level
2 `missing_call __security_check_cookie`. Cases: `0x000c6d90_gs_flag` (equivalent), `..._wrong` (`argument 2 is`).
**gen_tree.py needs the same change** (outside this round's files): add `"/GS", "/GS-"` to `ALLOWED_FLAGS` in
`tools/gen_tree.py` (l.98-99). Otherwise a `/GS` source's TU in the tree is built without `/GS`. `flags_tag` then
groups such sources under a `GS` tag.

**The /GS opportunity:** `build/equiv/gs-candidates.tsv` lists 329 sources (325 in `equivalent/`, 3 in `matches/`,
1 in `hybrid/`) with 486 cookie checks written out by hand (`__security_check_cookie(cookie)` with `cookie =
DAT_004d9968`). Its columns are address, file, number of checks, and whether the source names a cookie variable.
A later batch can rewrite them as `// cl-flags: /GS` with plain buffers; no source was changed this round.

## Library-span cases replaced (docs/platform-boundary.md, rule 1)

- `0x00212641_import_pop` (XAPILIB) is replaced by `0x0026dad0_import_pop`, radcore's job teardown (game code,
  matches/0x0026dad0.cpp). It calls `RtlEnterCriticalSection` and `RtlLeaveCriticalSection` through their kernel
  slots after other calls, the same shape as 0x00212641's NtClose. With instrumentation, `pending_use`'s
  import-slot branch is taken at 0x26dae3 -> 0x26db0b, as it is at 0x212674 -> 0x2126a2. Neither source changes
  outcome with that branch off, and no `EQUIV_OFF` name flips 0x00212641. The rule is now redundant with later ones
  (round 11's `ptrpop`, the kernel-slot pops), so the case is a guard. Added `..._wrong`: the wrong critical
  section gives `call #5 to 0x80000126: argument 1 is 0x0052a18c, expected 0x0052a188`.
- `0x003468c0_overlap_ub` / `_wrong` (LIBCMT strncat) are removed with no game-code replacement. The `overlap_ub`
  rule only ever applies to a CRT copy routine under test (`UB_COPY`, by the name of the function under test), and
  library functions are never checked, so no game function can reach it. The existing unit test
  `test_equiv.py::test_copy_overlap` covers the predicate and now also asserts that the rule is still registered.
  The rule stays (removing it would only be stricter, on code that is never checked).

Six regress cases had the same kind of off-by-ulps constant as #3 (`0x0002b970_tree_explicit_map` and its
`.tree.cpp`, `0x0004cbe0_eq_range`, `0x00083e60_fabs_fret`, `0x000ea7c0_dyncast_vcall_pop`,
`0x0010b5b0_flag_via`). Their copies in `tests/` now use the original's value with 9 significant digits; what
each case tests is unchanged. `0x0004cbe0_eq_range_wrong` keeps its `1.5708f` and fails at both levels.

## Validation (2026-10-18)

Machines: regress, test_equiv, replay_regress and selftest ran locally. The random 300 and the mutation suite ran
on mac1 (`~/hulk-r13`, 2 processes, sources copied from the local tree).

- `tests/equiv/regress.py --jobs 2`: **164/164** (157 - 3 library cases + 10 new). Under round 12
  (`EQUIV_MODULE=equiv_r12 ... --only`): both pop_ret cases are `unsupported`, and `float_const_wrong` and
  `objptr_wrong` come out `equivalent`. The guards and fixed sources pass. `gs_flag` passes under round 12's
  equiv.py because the flag lives in compare.py; with the old compare.py it fails at level 2 (above).
- `tests/equiv/test_equiv.py`: 12/12.
- `tests/equiv/replay_regress.py` (local sessions, `EQUIV_MODULE=equiv_wip`, unchanged equiv_replay.py): 16/16.
- `tests/equiv/selftest.py` (300 matches): **292/300**; round 12 got 290. The 8 failures fail the same way under
  round 12: 7 template scalar deleting destructors (`call #1 went to 0x6fff0000`) and 0x003576d0 (`call #1 to
  0x0034511c: argument 1 is 0x60000070, expected 0x00364830`, the same under round 12).
- `tests/equiv/mutate.py` on the pinned 120: 303 caught, 8 commutes pass, 2 equivalent mutants, 6 false passes,
  0 false failures (37 don't compile, 63 compile to the same bytes). This matches round 12 mutant by mutant (all
  419; round 12 rerun on mac1 the same day). No new false passes.
- `equivalent/`, a random 300 (`random.Random(2041).sample`, library spans excluded, 5,659 files) at `--inputs
  3000`: 299 equivalent, 298 promotable; 909 tie inputs and 2,418 objptr inputs in all. **No file newly fails:**
  0x00080900 fails under round 12 too (`5+tie: call #2 went to 0x00080cd0 instead of 0x00080c10`, a tie input:
  probably a real `<` vs `<=`, untriaged), and 0x00044cb0 is short on coverage under both (81/120). None of the 300
  is in the fconst list.
- **fconst over the tree** (level 2 only, `max_level=2`, local): all of `equivalent/` (the first full scan) and the
  867 sources in `equivalent/` and `matches/` with a float literal of 3 or more significant digits. 43
  `equivalent/` sources newly fail, and no `matches/` source does. They are listed in `build/equiv/fconst-failing.tsv`,
  each with our constant and the original's. All 43 look like mistyped constants: pi/180 as `0.0174533f` (12
  sources), 180/pi as `57.2958f` (the original has 0x42652ee0 = 57.2957764, 9), `0.00392157f` for 1/255 (4),
  pi/2, pi, 2pi, 1/15, 1/600, 1/sqrt2, and two folded ones (`0.00392157f * 255.0f` = 1.0000003 where the original
  has 1.0, 0x001c82c0; `1.52593e-05f` for 1/65535, 0x00268d30). The 3 named in the work list are among them.

Newly promotable: **0x0026dc20** (fx14's `work/fx14/0x0026dc20.cpp`, no extra flags): equivalent, promotable, 3001
inputs, 1/1 (+0x7 not-taken declared dead). 0x000c6d90 with `// cl-flags: /GS` is a MATCH (33/34). It can replace
equivalent/0x000c6d90.cpp once gen_tree.py takes the flag.

## What's left, ranked

1. **43 fconst sources** (`build/equiv/fconst-failing.tsv`): a one-literal fix each (the original's value, 9
   digits). Until then they fail level 2.
2. **/GS rewrite** of 329 sources (`build/equiv/gs-candidates.tsv`), after the gen_tree.py `ALLOWED_FLAGS` change.
3. **0x00080900**: tie input 5+tie diverges at call #2 (fails under round 12 too). Read the original's float test.
4. **0x00039c60**: unchanged at 110/152 (3,179 inputs, 24 objptr inputs). **B4 deep conjunctions** (0x001b05a0):
   not attempted; round 12's analysis stands.
5. Unchanged from round 12: merged runs over adjacent out-parameters, stack pointers a callee stores, per-stub
   cost on long constructors, interpreter words.

## Recipes for batch agents

**`float_constant_differs`** at level 2 means a literal is a few ulps off the original's constant. Write the
`original=` value with 9 significant digits (`0.0174532924f`, `57.2957764f`, `0.00392156886f`, `1.57079637f`). Don't
derive it from the math: 180/pi rounds to 0x42652ee1, but the game holds 0x42652ee0. **`/GS` sources**: write `//
cl-flags: /GS` and a plain `char buf[N]`; don't write the cookie load or `__security_check_cookie` by hand. **An
`N+obj` failure** (`argument 1 is 0x00000808, expected 0x00000707`) means a field offset is wrong in a struct
reached through a pointer. The values are word indexes: 0x707 is word 7, at +0x18, and 0x808 is +0x1c. Look for a
vftable pointer the hand-written struct gained or lost (fx15). **`call [reg]; pop ecx; ret N`** functions are no
longer `unsupported` for wild jumps. Re-run any logged as such.
