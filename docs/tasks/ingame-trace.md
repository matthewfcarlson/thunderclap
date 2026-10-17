# In-guest trace gate: arm every function at once

## Goal
One playthrough at near full speed should record the first N calls of every `equivalent/` function it reaches,
in the format `tools/equiv_replay.py` already replays, with its comparison rules unchanged.

## Why coverage was low
`tools/trace_capture.py` arms a GDB breakpoint on each target's entry. QEMU slows down with every breakpoint set
(about 6x with 800, even never hit), so at most `--window` 96 are armed at a time, in rotation. A function that
runs only briefly, such as during a level load, is recorded only if it happens to be armed then. Each 2-hour
`play2` shard targeted about 2,300 functions and recorded about 600. Only 1,168 of 5,072 equivalent functions
had ever been replayed.

## Options weighed

**Full in-guest capture** means logging entry registers, the stack window and the memory a call reads into a
guest ring. Registers and the stack are easy. Memory is the hard part, and the existing sessions show why
(`s2`, 8,285 good calls):

- the median call reads 3 distinct pages (p95 11, max 78);
- the median call has 5 (page, epoch) pairs (p95 58, max 12,158), because each callee return starts a new
  memory epoch and pages are re-read then;
- 75% of the pages are heap, reached through pointer chains (`this->member->field`). Neither the entry state
  nor static analysis can name them.

So copying "the pages the function reads" at entry needs either a page-fault tracer in the guest or a
re-snapshot after every callee. The tracer would mark pages not-present at ring 0 and log each first touch,
re-arm at every callee return, and catch every call site, indirect ones included. The re-snapshot would need a
hook on each call site (2–7-byte indirect calls can't take a 5-byte jump). Either one also needs the self-check
redone offline. That is a small hypervisor inside a running game, with a real risk of hanging it, and most of
its value is already in `trace_capture.py`'s co-simulation.

**What the 96-breakpoint window actually costs** is the arming, not the co-simulation. In `s2`, capture took
36 ms per call and guest time during captures 14 ms per call. Most of the 31 minutes was the game running
slowed down by breakpoints, or running unarmed functions while the window waited for them.

**Chosen: the in-guest trigger plus the existing host co-simulation (a gate).** The build arms every target
itself, so no window is needed. The host still records each call exactly as `trace_capture.py` does, so the
session format, the self-check and the replay rules are all unchanged. This is the prompt's third option taken
further: the guest doesn't just log which functions run, it stops them, one call at a time, at the moment the
host wants them.

## How it works

### Build (`tools/patch_xbe.py`)
`build(..., trace={"targets": [...], "next": 0})` adds `trace_stubs` to the `.hybrid` section, after the hooks.

- **Header** (5 words): `busy`, `gate_fn`, `gate_cont`, `gates`, `busy_skips`.
- **Common routine** (110 bytes), entered as `push entry_f; call common` with the stack
  `[ret into tramp_f][entry_f][caller's return address]`:
  - saves flags, eax and edx;
  - on the first call, stores `g_hybrid.polls` and `frame` in the entry;
  - increments `count`;
  - if `count >= next`, takes `busy` (an `xchg`; if the gate is already taken, the call runs uncaptured and
    `busy_skips` counts it), stores the entry and the continuation in `gate_fn`/`gate_cont`, restores
    everything, drops its two words with `lea esp, [esp+8]` (which leaves the flags alone), and reaches the
    gate: one `nop`, with every register as at the function's entry. Without a host attached it clears `busy`
    and jumps to `gate_cont`;
  - otherwise it restores the registers and does `ret 4` into the trampoline's displaced code.
- **Entry table**, 16 bytes per target: `count`, `next`, poll of the first call, frame of the first call.
  `next` = 0 means "gate the next call", 0xffffffff means never.
- **Trampolines**: `push entry_f; call common`, then the instructions the 5-byte `jmp` displaced, relocated,
  then `jmp f+len`:
  - `jcc`: rewritten to its rel32 form;
  - `jmp rel`: re-targeted;
  - a `call rel32`, which is always the last displaced instruction: becomes `push f+len; jmp target`, so the
    callee returns into the original code where the co-simulation waits for it.
- **Refused**:
  - functions under 5 bytes;
  - entries whose first bytes a hook or tweak already patched;
  - a direct branch or jump-table target inside the displaced bytes (CodeView over the function);
  - an indirect call, `loop`/`jecxz`, or a `ret`/`jmp` before the end of the displaced bytes.

  Of 8,179 sources tried, 153 were refused for size and 2 for the other reasons. About 5,500 targets add about
  200 KB to `.hybrid`, which is 431 KB without them.
- The original entry keeps its other displaced bytes, as the hybrid build does. Unicorn reads code from the
  XBE, so co-simulation sees the unpatched function.

### Host (`tools/trace_gate.py`, a `trace_capture.Capture` subclass)
- **The gate is the only permanent breakpoint.** On a stop there the host reads `gate_fn`/`gate_cont`, sets
  `eip = gate_cont` (GDB `P8=`) and clears `busy`, so another thread can never redirect the continuation. It
  then runs `CallCapture` from those entry registers, unchanged: Unicorn plus the paused game, callee
  breakpoints, epochs, the self-check and `TraceStore`.
- **Nested captures**: a gate stop while waiting inside a capture is a target hit in a callee, captured
  nested as before (up to depth 3, judged by esp). A hit from another thread, or one too deep, runs uncaptured.
  That function's `next` is set to never until the outer capture ends.
- **Which calls**, per function, up to `--per-func` (30):
  - the first `--burst` (5) calls back to back (`next` = 0 again after each capture);
  - then one more each time the game has advanced `--spread-polls` (1,800, about a minute) since the last
    capture.
- **`--max-stops`** (3,000 guest stops per call): a function whose single call runs much of the game, such as
  the new-game load (0x86630: 141 s and 128,851 stops in one capture), CGame::Tick or the PRESSSTART loop, is
  given up for the session and listed as `heavy`. Its callees are still captured, nested or on their own. The
  gdb recorder pays this cost too, whenever one of them is in its window.
- **Census**: every 10 s the host reads the whole table, so `session.json` and the store's `census` meta give,
  for every target, its call count and the poll and frame of its first call, captured or not. A
  `--census-only` run takes no captures at all.
- **Checkpoints**: with a recording as `--script`, the checkpoint ring is read along the way and compared with
  the recorded hashes (`checkpoints` in `session.json`).
- **No QMP screenshots.** They are what wedged xemu (see below).

## Results (2026-10-16/17, this Mac, script `build/replays/play2.json`)

**Same wall time, both recorders** (fresh sessions, current `equivalent/`):

| | gdb recorder (`gd-cmp`, 9 min) | gate (`g-try3`, 10 min) |
|---|---|---|
| game reached | poll 50,840, frame 3,210 | poll 51,000, frame 3,370 |
| equivalent functions captured | 699 | 2,044 |
| equivalent functions reached (census) | (unknown) | 3,147 |
| calls recorded | 3,097 | 2,086 (mostly 1 per function: spread re-arms only start once the game is 1,800 polls past the load) |
| replay (`--max-calls 10`) | 652 agreed, 0 mismatch | 1,899 agreed, 7 mismatch |
| incomplete calls | 2.0% | 2.7% (p2-0 4.0%, p2-1 3.0%, s2 1.9%) |

- **Agreement:** of the 616 functions both sessions replayed, every status is the same. The gate session
  replayed 1,290 functions the gdb run didn't; 696 of them were never replayed by any earlier local session.
- **Mismatches:** 0x122520 (`edi` not preserved) is already known (p2-0, fx11). Five were never replayed
  before: 0x17a80 (`edi` not preserved), 0xc7c60 (0xb bytes into an 8-byte local), 0x1f9710 (an argument is
  an address in ours), 0x278b50 (0x26 into 0x24) and 0x2a81c0 (an extra call). 0x2c1770 (0x128 into 0x121)
  agreed in m-menus, but its source changed after that replay.
- **Matches** (`--matches 200`, 70 captured): 65 agree, 2 no_replay, 1 not_reached, 2 mismatch: 0x2c3040 and
  0x35d7a0. `tools/equiv.py` fails both the same way on fuzz inputs with no trace involved (its binding links
  ours to its own helper copy: "argument 1 is 0x60000000"), so these are checker false failures in any session,
  not recorder errors.
- **Speed:** census only (no captures), the game runs about 13% slower than hooks-only: frame 2,685 at 151 s
  vs 3,077 at 145 s. With captures, about 65% of wall time goes to captures in the first 10 minutes (the boot
  and the new-game load, where every function is new), then the `--duty` budget.
- **Per-call cost is unchanged** (profile, 3 min): about half Python co-simulation (equiv.py's Run hooks), a
  quarter stop round trips (~0.65 ms each), 15% memory-read packets (2 per page).
- **Determinism:** the gate run's checkpoints equal a hooks-only replay's through frame 570, and differ from
  frame 600 on (the residual leak `docs/hybrid-build.md` describes, or the gate stops). **Neither stays on the
  recording:** a hooks-only `hybrid_test.py replay` of play2 leaves the recorded checkpoints at frame 90.
  Suspect: in record mode `hybrid_xinput_get_state` returns the real `XInputGetState` result, and polls where
  the pad wasn't ready returned an error to the game and were not recorded; replay returns success on every
  poll. The p2-0/p2-1 gdb shards ran off the recording the same way.

**Full play2** (`g-play2`, 150 min limit; the Mac slept for part of it on battery):
- reached poll 118,311 of 126,024 and frame 70,674. Off-path, the tutorial loops, so frames ran far past the
  recording's 8,514;
- census: 3,221 equivalent functions reached, against 592/634 per gdb shard;
- captured: 2,120 equivalent functions, 12,998 good calls, 91 failed self-checks; 60 matches with 277 calls;
- `heavy`: only 0x3078a0;
- replay of this session not run yet (battery).

**Reached but never captured:** 1,061 equivalents (555 called once, 428 called 4+ times), almost all first
called at poll 0 (boot). Their gates were skipped: another thread, or depth 3, while the boot's capture storm
ran. A 3-minute `--only` run of six of them captured the hot ones at depth 0 within 4 s of boot, so the
trampolines are fine. The fix is in the schedule (below).

## The gdb `TimeoutError`
Every session that ended with `gdb connection lost: TimeoutError('timed out')` logged `screenshot failed
(TimeoutError)` 30 s before it: ringctl, ringctl2, ringfeed and x-menus here, and the p2 shards.

Reproduced with `build/wip-ingame/wedge_test.py` (hooks-only play2 build, no GDB, one QMP action every 2 s):

| QMP action every 2 s | Result |
|---|---|
| `memsave` of g_hybrid + `xp 0xfd600800` (NV_PCRTC_START) | fine for 240 s, through the load |
| + `pmemsave` of the 1.2 MB scan-out buffer | wedged at 34.7 s, poll 47,814 (the new-game load) |
| `pmemsave` alone | wedged at 36.7 s, poll 47,816 |

The framebuffer `pmemsave` during a load hangs xemu's main loop, and the GDB stub runs on that loop. **Fix:**
`trace_capture.py --shot-every` now defaults to 0 (no screenshots); `trace_gate.py` takes none. The 9-minute
gdb run through the same load survived.

## Recording a session
```sh
build/venv/bin/python tools/trace_gate.py --session g-play3 --script build/replays/play2.json --minutes 150
build/venv/bin/python tools/equiv_replay.py --session build/traces/g-play3 --equivalent --max-calls 10
```
Options:
- `--per-func 30 --burst 1 --spread-polls 1800 --duty 0.5 --max-stops 3000`;
- `--only FILE` records just the listed targets (e.g. a session's `reached_not_captured`, or
  `build/traces/capture-wanted.txt`);
- `--census-only` gives reach without captures;
- `--log-gates` writes every gate stop to `capture.log`.

## Left
- **Lost first calls at boot.** Run a second pass with `--only` over the first session's
  `reached_not_captured` (cheap: the census lists them). Or, better, re-arm a skipped function at once instead
  of parking it, and allow more nesting depth for gates (trace_capture's `MAX_DEPTH` 3).
- **Replay `g-play2`** (13k calls) and merge it through `equiv_confidence.py`.
- **play2 doesn't replay** past frame 90 even hooks-only (above). Every capture of it records the off-path
  game. Found (docs/tasks/record-replay.md): it was recorded with two pads bound, interleaved by poll, and the
  audio sequencer drew from the gameplay RNG in real time. Version-2 recordings (virtual pad, `seq-rng`) replay
  exactly. play2 is salvageable only to frame 330 (`build/replays/play2-salvaged.json`); re-record it.
- Functions under 5 bytes (153) aren't trampolined. The gdb recorder could take them as permanent
  breakpoints.
- Cheaper captures: page reads cost 2 GDB packets each (QEMU caps `m` at 2 KB), and decode/Unicorn hooks in
  equiv.py dominate. Neither is touched here.
