# 10: Test plan for the hybrid build (and later the Wine build)

## Goal
Once [task 06](06-hybrid-patch-build.md) can patch our functions into the original XBE, prove that the patched game behaves like the original. When it doesn't, find the responsible function automatically. The same harness later checks the native builds ([roadmap](../roadmap.md) step 6) and QoL changes (step 7).

## Why
- `tools/equiv.py` checks one function at a time on fuzzed inputs, with stubbed callees ([equivalence.md](../equivalence.md)). It can't see:
  - initialization order;
  - state that builds up over many frames;
  - timing;
  - real data shapes the fuzzer never produces;
  - interactions between functions that are each "equivalent" alone.
- Branch coverage isn't path coverage. Code behind conditions the fuzzer can't reach stays unverified until real gameplay runs it.

## Approach: deterministic replay, compared against the original

### 1. Make runs repeatable
- **Input replay.** We own the controller seam (`core::ControllerXBox`; see [platform-boundary.md](../platform-boundary.md)). A test build replaces the pad read with a reader that plays inputs from a file on the HDD image. "Record" mode, the same hook on the original game, writes those files while someone plays.
- **Fixed timestep and seed.** Game dt is variable and clamped at 66.7 ms ([subsystems.md](../subsystems.md)). A test build pins dt to 1/30 s and seeds the RNG with a constant.
- **Determinism check first.** Before any comparison means anything, two runs of the same replay on the *unmodified* game (with only the replay, dt and seed hooks patched in) must produce identical checkpoints. Anything that still varies, such as audio streaming timing or loading order, gets pinned or excluded from the hash.
- **State checkpoints.** A small hook (our code, called once per frame) hashes key state every N frames and writes it to a ring buffer:
  - player position, velocity, health and rage;
  - camera matrix;
  - RNG state;
  - live object and entity counts;
  - mission and objective flags;
  - the current level.

  The ring buffer is read through xemu's GDB stub, or flushed to a file on the HDD image. Screenshots at fixed frames come from xemu's monitor (QMP).

### 2. Test ladder for every hybrid build
1. **Load:** the patched XBE passes `tools/xbeinfo.py` and xemu starts it.
2. **Boot:** it reaches the title menu, with a screenshot compared against the original.
3. **Scenario replays:** each a few minutes, compared checkpoint by checkpoint against the same replay on the original:
   - boot → menu → new game;
   - the first mission;
   - a fight with several enemies;
   - heavy destruction and physics: buildings, thrown objects;
   - vehicles: grab, throw, smash;
   - a Bink cutscene, plus the pause and options menus;
   - save, quit, load: the save data must be byte-identical to the original's;
   - every level load (a scripted warp replay).
4. **Soak:** a long replay or idle loop, an hour or more, for crashes, leaks and slow drift.

A build **passes** when every scenario's checkpoints match the original exactly, its screenshots match within a small tolerance, and the soak finishes without a crash.

### 3. When a scenario diverges: bisect, then shrink to a unit test
- **Bisect.** A hybrid build is just a set of patched functions, so `tools/bisect_hybrid.py` bisects that set.
  - It patches half, re-runs the failing scenario up to its first divergent checkpoint, and keeps the half that diverges.
  - That's about log2(N) runs: roughly 10 for 1,000 patched functions.
  - Subsystem boundaries from [subsystems.md](../subsystems.md) make good first splits.
- **Capture real inputs.** For the culprit, a GDB breakpoint at its entry dumps the registers and the pages it touches on the failing frame.
- **Feed them to the checker.** Those snapshots become directed inputs for `tools/equiv.py` (`--inputs-from`, to be added). The bug then reproduces in seconds without xemu, and the fix is checked the same way.
- **Close the loop.** Every captured snapshot is kept in a corpus that `equiv.py` replays on later checks of that function. Real data then raises level-3 coverage for every function the scenarios reach, beyond what fuzzing alone gets.

### 4. Integration coverage
- A counter hook records which patched functions actually ran in each scenario.
- Patched functions that no scenario reaches are listed in the report. They need a new scenario before we call them tested.
- The report also gives, per subsystem, the share of patched bytes executed.

### 5. QoL changes on the same harness
- **Widescreen, FOV and HUD:** screenshot diffs against expected layouts. Check that HUD elements anchor to screen edges.
- **60 fps:** the same replay at 30 and 60 fps.
  - Checkpoints will differ, so compare trajectories instead: jump heights, throw distances, timer durations, animation lengths.
  - Gameplay constants of 1/30 and 1/60 are the first suspects for frame-rate dependence.
- **Intro skip and faster loading:** the boot scenario must reach the same menu state.

### 6. The Wine build and later native builds reuse all of it
- The replay files, checkpoint hashes and scenarios are platform-independent. The native x86-32 build, then x86-64 (SteamOS) and arm64 (macOS), run the same suite against the original's checkpoints.
- Exact matching is expected on x86-32 with x87 math.
- On SSE/NEON, float results drift. Compare positions and other floats within a tolerance that tightens over time, and treat discrete state (flags, counts, level, RNG) as exact. A divergence then shows *where* drift starts, usually in physics or animation, instead of just "the replay desynced".

### 7. Automation
- `tools/hybrid_test.py SCENARIO...`: builds the hybrid XBE from `matches/` plus `equivalent/`, boots xemu with the user's own files, runs each scenario, and writes a JSON report: pass/fail, first divergent checkpoint, coverage.
- Nightly on a Linux box: headless xemu under Xvfb, all scenarios, with the report committed to `build/` and summarized in the README status table.

## Inputs the user provides
- Their own Xbox BIOS, MCPX ROM and HDD image for xemu. Never downloaded or committed.
- One recording session per scenario, played on the original game in record mode. Replays are input files, not game data, so they can live in `tests/replays/`.

## Deliverables
1. Replay, fixed-dt, seed and checkpoint hooks as hybrid-build patches, plus a passing determinism check on the unmodified game.
2. `tools/hybrid_test.py` with the scenario suite and JSON report.
3. `tools/bisect_hybrid.py`.
4. Snapshot capture over the GDB stub, plus `equiv.py --inputs-from` and the snapshot corpus.
5. The coverage report.
6. [`docs/hybrid-build.md`](../hybrid-build.md) and [`record-replay.md`](record-replay.md): how to record, run and read the reports.

## Done when
- Two runs of every scenario on the original produce identical checkpoints.
- A hybrid build with all of `matches/` and `equivalent/` patched in passes every scenario, or each failure has been bisected to a function and fixed with a captured-input unit test.
- The same suite runs against the first native x86-32 build.

## Depends on
[Task 06](06-hybrid-patch-build.md) (the patcher and a booting hybrid build), [task 07](07-subsystem-map.md) (the controller, game loop and timestep locations, which are done), and [task 09](09-equivalent-decomp.md) (`equiv.py`).
