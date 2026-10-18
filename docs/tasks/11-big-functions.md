# 11: The functions over 4 KB

**Status (2026-10-18): done.** Every function this task lists is now in `matches/` or `equivalent/`; they were
proven by the big-function batches (big2–big5, bigq, bigr) before the scheduled start. Nothing below needs running.

**When:** after the weekly Claude usage window resets (Sunday 2026-10-18, 09:00 local). It needs Claude
agents, which are paused until then.

**Why:** 24 unproven functions are over 4 KB (131 KB, about 5% of game code). None of them are merged
functions: no return inside any of them is followed by int3 padding. But several are big only because MSVC
inlined small helpers many times, and for those a generator is cheaper than a proof by hand.

## Phase 1: generators for the repetitive ones (one agent)

| Function | Size | What repeats |
|---|---|---|
| `0x0009dd20` | 6.7 KB | ~60 inlined script-binding registrations: `FUN_001d04d0` (151 calls), `Registry::FUN_001d3b70` (63), `operator new` `FUN_0008d690` (62), type-name globals such as `DAT_0048e128`. The same `Closure0`/`Method0` pattern as `tools/equiv_gen/closure.py`, which proved 48 out-of-line registrations in one pass. |
| `0x001e7470` | 4.1 KB | The same pattern, ~43 registrations. |
| `0x00073700` | 4.2 KB | 83 pairs of calls to `0x002367c0` / `0x00236ac0`: a table built line by line. |
| `0x000464c0` | 4.8 KB | 85 calls to `0x0027aa20`: another table. |

Steps:
1. Extend `tools/equiv_gen/closure.py` (or add a sibling) to emit a body of N inlined registrations: read each
   registration's vftable, owner class, return type, method and name string from the disassembly, in order.
   Prove `0x001e7470` first (smaller), then `0x0009dd20`.
2. Write small generators for the two call tables (`0x00073700`, `0x000464c0`).
3. Each output must pass `tools/equiv.py --inputs 3000` (equivalent, no level-2 conflicts, ≥75% coverage, ≥50
   completed inputs). These functions are long and straight-line, so coverage should be easy and run time is the
   cost. Then `tools/equiv_replay_fn.py --remote mac1` where captured.
4. Look for more functions with the same inlined-registration shape below 4 KB (count calls to `FUN_001d3b70`
   and `FUN_001d04d0`) and run the generator on them too.

Expected: about 20 KB proven at low cost.

## Phase 2: one of each look-alike pair, then its sibling (one agent per pair, one at a time)

Same structure (return count, call count, x87 count), different lengths: probably one template instantiated for
different types. They're not the same shape, so `tools/clone_equivalent.py` can't clone them, but once one is
proven the other is mostly a diff.

| Pair | Sizes | Shape |
|---|---|---|
| `0x002c96e0` / `0x002cb2b0` | 7.0 / 7.7 KB | 29 calls, 29 returns, ~360 x87 |
| `0x002cd130` / `0x002cec10` | 6.8 / 7.1 KB | 72 calls, 29 returns, 264 x87 |
| `0x00317700` / `0x00316410` | 4.5 / 4.6 KB | 32 / 79 calls, 6 returns, ~700 x87 |

Do the smaller of each pair first, then hand the sibling to the same agent (or a follow-up) with the proven
source as the template.

## Phase 3: the rest, one Sonnet batch at a time (as usage allows)

Real game logic: `ProjectileMissile::vfunc_4` (9.1 KB), `CRangedAgent::vfunc_4`, `PathAction::vfunc_5`,
`TankLocomotionAction::vfunc_5`, `HeliLocomotionAction::vfunc_5`, `FUN_001d8fc0`, `FUN_000cc7e0`,
`FUN_00081b20`, `FUN_00280d90` (x87-heavy AI and physics, inlined vector maths); `FEMemCardControl::vfunc_4`
(48 returns, a UI state machine), `TextSelector::vfunc_5`, `FUN_000ba040` (25 `dynamic_cast`s). Split each
into helper functions with `__forceinline` where the original inlined them, and expect the x87 precision recipes
from the batch brief (`build/farm/bench/claude-equiv/brief.md`) to matter. Any that can't be expressed (80-bit
intermediates live across statements) become hand-written assembly or port exceptions.

## Rules

- Check `build/agent-tools/usage-gate.sh` before starting each agent: stop at 90% of the 5-hour or weekly window.
- Promote with `build/agent-tools/promote-remote.sh` (3,000 inputs on mac1), then replay the new functions
  (`tools/equiv_replay_fn.py --since HEAD~1 --remote mac1`) and refresh `tools/equiv_confidence.py`.
