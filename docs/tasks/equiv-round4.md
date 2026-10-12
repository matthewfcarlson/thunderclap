# Equivalence checker round 4: proposals from the hard pile

In October 2026, 127 log lines (about 105 functions) failed or were skipped by Sonnet equivalence batches, or were demoted
from `equivalent/` by the `--inputs 3000` re-check. These came from `build/farm/bench/claude-equiv/hard.jsonl`. One Opus pass
re-ran each best attempt under checker round 3 (`--inputs 3000`) and clustered them by root cause. It found that
**most "checker bug" notes written before round 3 were source bugs**. Fourteen functions now pass; their recipes are in the
batch brief (`build/farm/bench/claude-equiv/brief.md`, "Recipes from the hard pile").

The other clusters need checker work. They are ranked below by how many functions each one would unblock. "Outside"
counts unproven, non-dead, non-library functions (no `matches/` or `equivalent/` file) with the same code shape. That
count is an upper bound on the payoff, not a promise. Repro sources are in `build/farm/bench/claude-equiv/work/ADDR.cpp`
or `build/farm/equiv-demoted/ADDR.cpp`.

## Clusters

| Cluster | Pile | Verdict |
|---|---|---|
| Source bugs blamed on the checker (args around a call, swapped params, switch tables, NaN polarity, cookie convention, byte loop vs `rep movs`, field offsets) | 11 | source: fixed, passing |
| Unchanged source that now passes (round 3 fixed the limit) | 3 | passing (0x00227a10, 0x002299c0, 0x002eea80; few inputs completed) |
| Thin coverage: string or fourcc compares against literals | 6 | checker P1 |
| Thin coverage: floats from stubs through math (`sqrt`, tolerance, `ftol` clamps) | 7 | checker P5 |
| Thin coverage: rb-trees, pointer ranges, loop counts behind pointer chains | 7 | checker P4 |
| Thin coverage: other (dead code in the original 0x00285ac0, stub-filled flags, A* neighbours) | 7 | trace replay |
| A fuzzed pointer lands on code (our object or `.text`): 1 failing input in 3000 | 7 | checker P2 |
| Wild control flow or frame overflow: both sides fault, or UB on fuzzed indices | 10 | checker P3 |
| Stale stack words in by-value args or callee-initialised locals | 5 | checker P6 |
| Loops ended only by callee side effects (teardown, event pumps) | 4 + 5 unattempted | trace replay |
| x87 80-bit intermediates (0x001c2940, 0x002fd0c0, 0x0030c110) | 3 | source in principle (MSVC keeps natural `float` locals on the FPU stack); not proven in 3 tries; low payoff (one function, 0x001c2940, has the shape) |
| Address of the function under test (0x000e7770, 0x000f3940) | 2 | checker (known) |
| MSVC CRT, XAPI, EH funclets, caller-frame fragments, wrong function bounds (0x001bb0b0) | 28 | out of scope: port exceptions or library code |
| Not retried (float st0 returns, register conventions, 0x002c50c0 ebx out pointer) | ~14 | retry under round 3 with the brief's recipes |

## Proposals (ranked)

**P1. Plant literals for string compares (pile 6, outside about 50).** `repe cmpsb` against an image string
(0x00206320 +0xcc: `mov edi, 0x3f3f3c; lea esi, [ebp+0xaa4]; mov ecx, 5; repe cmpsb`) and CRT
`strcmp`/`stricmp`/`strncmp` (0x346e5a / 0x346fc5 / 0x345840) called with a `.rdata` argument. On an uncovered
branch after such a compare, re-run the input with the literal's bytes, terminator included, written over the
other operand's buffer. Use the pointer the original passed at that point, in the epoch where it is read. The fourcc
`cmp eax, imm` cases are already steerable; DDS headers (0x002de030) need the same treatment for `cmp [mem], imm` read
through a stub-filled buffer. Repros: 0x00206320 (31/42 edges, needs 32), 0x001ff770, 0x002f4eb0, 0x002de030, and the
byte-table switch 0x001d22a0. 0x00206320 would pass with this change alone.

**P2. Keep fuzzed pointers off code (pile 7; each fails on exactly 1 of about 3000 inputs).** The pointer pool and the
dictionary can produce addresses inside our object (`0x60000000+`) or the original `.text`. A store through such a
pointer self-modifies one side only. 0x0032a320 and 0x0032b530 on seed 1023: `st + 0x28 + 4*stage` = ours + 0x8c. The
same thing happens on reads: 0x001d2ee0, 0x00272df0, 0x001b7f40 (`this` aliases the "movies" string), 0x00285fc0,
0x002c7690. Fix: exclude both code ranges from heap pointers (map our object outside every range `fuzz_value`
can produce), or treat a write into either code range as ending the input inconclusively. Five of the seven
(0x0032a320, 0x0032b530, 0x001d2ee0, 0x00272df0, 0x001b7f40) pass every other input with full coverage.

**P3. Both sides fault after wild control flow (pile about 10).** Count an input as inconclusive, not failed, when
the original faults and ours faults too (or ours times out) with identical calls and writes up to that point, after an
indirect transfer to a non-function address or after the run overwrote its own return address, saved registers or
cookie. Repros: 0x000f8280 (`call [DAT_004de948]` runs junk: int3 vs invalid opcode), 0x0012f750, 0x0026f290 and
0x001a9f10 (unbounded `strcpy` into a stack buffer), 0x0021ab30, 0x001c1a40, and 0x000c21b0 (all 3 failing inputs are
original faults). 0x00282d00 and 0x0028a630 index stack arrays with fuzzed counts (UB). For those, detect an indexed
store or load that crosses into another address-taken local, and drop the input.

**P4. Valid data structures for loops (pile 7, plus the timeouts).** rb-tree insert/rebalance (0x002448b0,
0x00258530, 0x0025f450, 0x002639c0) reaches 13–32 of 52–64 edges, because fuzzed trees are cyclic. Plant a small
well-formed tree (nil sentinel, parent/left/right at the offsets the walk uses) as a dictionary mode. Loop counts behind
a pointer chain (`pool->list->count`, 0x0029d2c0) and down-counting loops (0x0029d5d0) still hit the inconclusive cap
before the directed phase runs. Let directed inputs run even after `inconclusive_cap_hit`, and repair bounds read
through two or more loads.

**P5. Steer floats through math on stub results (pile 7, outside: many of the 596 functions with x87 branches).**
Directed inputs can't invert `sqrt`, `fabs` or `x*k+0.5`, or a difference of two stub-filled vectors (0x00107410
`dist < 15`, 0x0010b5b0, 0x0029d090 `ftol` clamps, 0x002e8f80, 0x0022cf90 needs unit rows). Cheap version: for a
compare whose operand comes from x87 arithmetic over stub results, retry with each contributing stub float set to 0,
±1, the compared constant and small/large magnitudes, and keep what flips the branch.

**P6. Callee-written words in stack temporaries (pile 5, outside about 47).** Two precise bugs in
`_callee_extent`/out-parameter filling:
1. Offsets start at 4 (`range(4, cap, 4)`), assuming offset 0 was already filled as a stack argument. For a
   **register** pointer (a constructor's `ecx`), nothing fills offset 0. MSVC builds by-value arguments as
   `sub esp,8; mov ecx,esp; push src; call copy_ctor`. The temporary then still holds the previous call's return
   address, which differs between the two sides: 0x001ecda0 call #14 (`0x001ed035` vs ours), 0x001d8350,
   0x001fa1c0. Also, `save_slots` are never discarded when the stack is released, so a dead return-address slot
   bounds later fills.
2. Words the function wrote earlier are skipped (`func_stack_written`) even when the callee's static extent says the
   real callee overwrites them. 0x00148b00: the `desc` ctor (0x59820 → 0x59510) zeroes `desc+0x28`, but the original's
   frame held a dead spill there and ours held `-1`. Fill every word inside a statically known extent, and keep the
   skip for words beyond it.

Repro shape count: 47 unproven functions contain `mov ecx, esp`.

**P7. Trace replay as a coverage source.** For the thin-coverage and callee-driven-loop clusters (about 25 functions:
teardown loops 0x0024ad20, 0x001dec10, 0x000b1db0 and 0x0024a800; A* 0x001aedb0; Lua 0x002142d0), recorded game states
(`tools/equiv_replay.py`) would give real trees, strings and loop exits. Accept "fuzz equivalent + replay
equivalent with combined coverage ≥75%".

Smaller: the checker should warn when a source declares `__security_check_cookie` as anything but `__fastcall`.
`equivalent/0x001efa40.cpp` still declares it `__cdecl`. It passes at 3000 inputs because the cookie happens to be in `ecx` too, but the declaration should be fixed for the port.
