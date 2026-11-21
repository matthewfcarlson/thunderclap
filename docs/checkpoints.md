# Checkpoints against the original game (ckpt1, D155/D158)

Goal (D155): for code the reference recordings reach, a refactor is validated by matching **reference checkpoints
recorded from the original game** instead of per-function re-proofs. The 32-bit Wine build is the first build checked
against them (D158); the native 64-bit builds consume the same references once they reach gameplay. The rule that
uses them is the lead's to enact: a function the reference recordings reach (block mode, below) needs no re-proof for a
refactor if every reference checkpoint still matches; unreached functions keep their proofs.

Nothing derived from the game is committed: recordings, reference checkpoints, coverage lists and field dumps stay
under `build/` on the player's machines. Only the formats, the probe source and the tools are tracked.

## Where this starts from

- **The narrow hash** (`src/platform/sdl/replay/hulk_replay.h`, `hybrid/hooks.cpp checkpoint()`): FNV-1a over the frame
  number, the gameplay RNG (8 bytes), `g_BootSequenceStep`, the camera position and 48 bytes of the GameClock, every 30
  frames. The recordings carry the original's values (xemu), and the Wine build compares with them on every replay
  (`ckpt frame N hash H recording R ok|DIVERGED`); play3 matches the original at every checkpoint to 56,550 except
  5880, 5910 and 34260. The 64-bit replay driver (`src/platform/sdl/host/replay_native.cpp`) lays the same fields out
  as the 32-bit bytes, so the hash is comparable across builds. It is narrow: a divergence shows only once it reaches
  the RNG, the camera or the clock (div8/div9 in [wine-float.md](wine-float.md) took thousands of frames to surface),
  and it does not say which subsystem moved.
- **ckpt_gate** (`tools/ckpt_gate.py`) compares a proof run with its control, both Wine builds; it is a regression gate,
  not a check against the original.
- **Particle RNG checkpoints** (div10): a second hash over 40 bytes of pure3d's particle generators.

## Coverage (what the reference recordings reach)

`HULK_COVER=<list>` (Wine build, `src/platform/sdl/xdk/startup.cpp`, off when unset) arms a one-shot `int3` on every
address of the list before the initializers run; the first execution of one restores the byte, notes the frame and
resumes, so each address costs one exception per run and the game's code and state are unchanged (play3 with coverage
on: `ckpt_gate` against a plain control GATE ok, prng 0 of 2,001 frames differ). Hits go to `<trace>.cov`.

```sh
P=build/venv/bin/python
$P tools/cover.py list IMAGE/hulk-strict.map --bb --exe IMAGE/hulk-strict.exe --out build/ckpt/cover.lst  # leaders
#   replay with HULK_COVER=<cover.lst> (wine_replay_job.py run --env, the list shipped beside the image)
$P tools/cover.py report trace.txt.cov IMAGE/hulk-strict.map --blocks build/ckpt/cover.lst.blocks.json --json OUT.json
```

`list` takes every function symbol of the game's objects in the link's map; `--bb` adds every basic-block leader
(direct branch targets inside the function and the first instruction after a branch or return, from `llvm-objdump`).
`report` maps the image's functions to tree blocks by their `// sym:` pin (with the Wine build's float-to-double return
mangling, and the binding map as a fallback) and reports functions, original bytes and an estimate of the bytes run
(each function's original size times the fraction of its clang blocks hit), by area, TU and first-hit frame.

**Caveats.** The Wine link folds identical functions (lld ICF): a hit at a folded address cannot say which of the
folded functions ran, so the validation rule counts folded functions as **unreached**. Coverage is of the clang image
built `--opt o0` (no inlining); `--gfx` replaces the original's D3D layer (`src/platform/xbox/pure3d`), which therefore
shows as unreached and can only be validated by the original's own drawlog.

### play3 to frame 60,000 (ckpt1, HEAD 24306b8f6)

| area | functions | reached | % | bytes (by function) | bytes (by block, est.) |
|---|---:|---:|---:|---:|---:|
| src/game | 19,399 | 11,527 | 59.4% | 73.6% | 65.5% |
| src/engine | 7,269 | 3,685 | 50.7% | 58.7% | 48.8% |
| src/platform/xbox | 818 | 167 | 20.4% | 22.7% | 18.1% |
| total | 27,486 | 15,379 | 56.0% | 66.9% (1.83 of 2.73 MB) | 58.3% |

83,620 of 158,414 basic blocks ran; 10,335 of the reached functions ran every block; 1,032 reached functions sit on
ICF-folded addresses. 12,849 functions are first entered before frame 1,000 (boot, front end, first load), 425 in
1,000-2,000, then a thin tail (94 around 33,000, 6 after 49,000): play3's later half adds almost no new code. Never
reached: 631 whole TUs (209 KB), 1,012 whole classes (214 KB), among them the D3D layer (above), physics joints and
articulated bodies, SpotLight, the "Old*" loaders, shadow meshes, about 40 Hulk and enemy moves (FireBeam, Surf,
BallAndChain, HeliDeathSpiral, GroundShockwave, several grapple throws, air-to-ground targeting), half the front end
(345 of 673 FE functions), the memory card (53 of 119), movies (the recordings run `no-fmv`), HUD overlays (105 of 174)
and cheats/unlocks (58 of 102).

## The semantic state hash

### One probe, three compilers

The probe (`src/platform/sdl/ckpt/ckpt_probe.{h,cpp}`, probe version 3) walks the game's state from the globals each
build hands it (`HulkProbeInputs`) and hashes it per subsystem tag. The same source is compiled:

1. with MSVC 7.1 into the hook-only XBE: `hybrid/hooks.cpp` includes it and calls it from `hybrid_clock_tick` (inside
   `GameClock::Update`) when the build has the `probe` flag (HF_PROBE), with the original's addresses;
2. with clang i686 into the Wine build: `src/platform/sdl/xdk/replay_hooks.cpp` includes it and calls it at
   `GameClock::Update`'s entry when `HULK_CKREF=1`, with the data TUs' `DAT_<addr>` items;
3. with the native front ends into the 64-bit builds (the native replay driver, once native reaches gameplay).

Field access: a field `include/gen` spells is read through gen (`offsetof` on the build's layout, checked against the
original's 32-bit offset at compile time on 32-bit builds) when `HULK_PROBE_GEN` is defined; the words gen does not
spell yet (the actor's life state and controller slot, the scene-node chain to its position, the actor and scenario
managers' pointers, which gen only forward-declares) are read at their 32-bit offsets, on 32-bit builds only. A 64-bit
build reports the tags that need them as **unavailable** (never hashed at a guessed offset) until gen spells those
words; each read in the probe names the function that shows its offset (the same reads as the session hash of
multiplayer.md). The Wine build reads the original's offsets directly (identical on 32-bit; gen's include path is not
on the platform layer's compile line).

### Canonical encoding

- Little-endian 32-bit values: integers and enums as they are, floats as their IEEE bit patterns.
- **Floats are exact.** The port's float work (wine-float.md, native-float64.md, soft-x87.md) aims at bit-exact
  results on every build; quantising would hide exactly the 1-ULP divergences the div8/div9 hunts found. A quantised
  copy of each float (rounded to 10 fraction bits; NaN, infinities and zeros unchanged) is hashed into a second stream
  for diagnosis only: when the exact hash differs and the quantised one does not, `ckpt_ref` says "float drift";
  when both differ, "logic".
- **Pointers are never hashed**: only present / absent; lists are walked in the game's own order.
- Each tag's hash is FNV-1a 32 over (frame, tag, probe version) and its values, in exact and quantised versions.

### Tags (probe v3)

| id | tag | tier | contents |
|---:|---|---|---|
| 0 | `legacy` | every frame | the narrow hash of hulk_replay.h (Wine records only; the recordings carry the original's) |
| 1 | `flow` | every frame | boot step, world / actor manager present, the scenario manager's mission state |
| 2 | `clock` | every frame | the GameClock block +0x10..+0x40 (step and scaled step as zeros, as the legacy hash) |
| 3 | `rng` | every frame | the gameplay MWC (0x4e5ad0) |
| 4 | `hulk` | every frame | the main actor (CActorManager +0x124): life state, controller slot, health, static ground point, position |
| 5 | `camera` | every frame | the logic view's position (+0x4c) |
| 6 | `actors` | every 30 frames | count, then every actor of the actor manager's list as for `hulk` |
| 7 | `mission` | every 30 frames | mission state, checkpoint, elapsed and end times |
| 8 | `sound` | every frame | the sound code's own generators (sound-rng): an **observable**, outside the verdict unless `--strict` (the audio backends are not the original's, and the two original runs themselves disagree) |
| 9 | `particle` | every frame | pure3d's particle generators (40 bytes at 0x554be4) |

Planned next (each a new tag id and probe version): Hulk's orientation, velocity, rage and action / animation state;
the camera's target and kind; per-actor type and AI state; the front-end screen stack; a save-buffer hash when the
game writes one; a draw digest.

In xemu the hook writes one 23-word record per frame into a 512-entry ring in `g_hybrid` (46 KB) that the host drains
with the checkpoint ring every few seconds; the per-actor values are hashed in the guest and only the hashes leave it.

## Reference checkpoints from the original

```sh
# a from-boot replay of the recording in xemu with the probe (an xemu queue job; -snapshot as always)
build/venv/bin/python tools/hybrid_test.py replay build/replays/play3.json --syncio --ckref OUT.ckref [--ckref-dump F]
# three times (two hosts or more), then the reference: per frame, each tag all runs agree on
build/venv/bin/python tools/ckpt_ref.py make A.ckref B.ckref C.ckref --name play3 --out build/ckpt/play3.ckref
```

A recording's VM snapshots hold the hooks they were recorded with, so references come from replays from boot (play3:
about 50 minutes per run). `make` keeps a (frame, tag) only where all runs agree and drops the disagreeing tags of a
frame, never the whole frame (three runs: two runs can agree by chance where the original is not deterministic,
"The particle tag" below); the sidecar `play3.ckref.json` counts what was dropped. References are derived game
data: they stay in `build/ckpt/`, never committed. A probe change bumps the probe version; `ckpt_ref` refuses a run
and a reference of different versions, so new references are recorded with it.

**play3 (probe v2, two runs on two hosts).** The two original runs agree on flow, clock, Hulk, camera, actors and
mission at every one of 56,595 frames. They do not agree on the particle generators after about frame 12,920 (the
recording's own prng checkpoints stop at 12,900 for the same reason) nor on the sound generators: the original is not
deterministic there, which is why v3 keeps the particle generators apart from the gameplay RNG.

## Comparing a build (`ckpt_ref`)

```sh
# a Wine replay with the probe: HULK_CKREF=1 writes trace.txt.ckref beside the trace
build/venv/bin/python tools/ckpt_ref.py check RUN.ckref --ref build/ckpt/play3.ckref [--cover COVER.json] \
    [--control CONTROL.ckref] [--strict] [--json OUT]
build/venv/bin/python tools/ckpt_ref.py diff TRACE_OR_DUMP_A TRACE_OR_DUMP_B --frame F
```

**In the proof flow (D161).** Replays write the records by default (`HULK_CKREF=1` in `wine_replay_job.DEFAULT_ENV`;
`--env HULK_CKREF=0` turns it off) and `wine_build_run.py` brings `trace.txt.ckref` back beside the trace.
`tools/ckpt_gate.py CONTROL PROOF` adds the `ref` gate to the checkpoint and prng gates: with the reference on the
machine (`--ref`, default `build/ckpt/play3.ckref`) and records from both runs, it fails on any (frame, tag) the
control matched against the original and the proof does not, and on reference frames the proof lacks. The GATE line
carries its status (`GATE ok (ref: ok)`, `(ref: not checked: ...)`), and `--require-ref` fails whenever it cannot run
(no reference, a control or proof without records, other probe versions); controls from before D161 stay "not
checked" until they age out. The references travel to the queue hosts one way with the other local inputs
(`build/ckpt` is in `wine_build_run.INPUT_DIRS`), and a build job with a replay checks its own run against the
recording's reference (`nb-out/ckref-check.json`, `summary.json` `ckref`).

`check` reports per tag the frames compared and diverged, the first divergence, whether it is float drift or logic,
and the last matching frame before it. With `--control` the verdict is the gate: no (frame, tag) that the control run
matched may diverge in the run (the control's own divergences are the known ones). Localisation:

- **which subsystem**: the first tag to diverge;
- **which fields**: `HULK_CKREF_DUMP=<from>-<to>` makes the Wine build log every hashed value of those frames
  (`ckdump` lines in the trace); `hybrid_test.py replay --ckref-dump F` dumps the original's at frame F (OUT.dump.txt,
  the same format); `ckpt_ref.py diff` names the fields that differ, floats shown as values;
- **which code**: with `--cover` the functions the coverage report first saw in the window between the last
  matching and the first diverging frame. A drift in code that was already running needs a coverage run started in
  that window (or the field dump and the trace probes of wine-replay.md).

**The Wine build against play3's reference (v2):** flow, clock and mission match at every frame. The known
ckpt_gate transients are float drift (the quantised hashes agree): the camera from frame 5,875 (the 5880/5910
checkpoints) and Hulk and the actors from 34,240 (34260).

## Proposal: when a refactor needs no re-proof (D155; not implemented, the user decides)

A change to an `equivalent` or `matches` block today needs a fresh proof (`equiv.py` at 3,000 inputs, `--wine`,
`--x64`) or a byte match. The proposal: a block whose changed code the reference recordings demonstrably run may
instead be validated by the reference checkpoints.

**R1. Which references.** The reference set is every recording with a three-run reference in `build/ckpt/` of the
current probe version (today play3). The set, its probe version and each reference's content hash are named in a
tracked manifest (`config/ckpt-refs.json`: names and hashes only, no game data), so a validation states exactly what it
was checked against. A reference is re-recorded (two runs) when the probe version changes.

**R2. Reached means the changed blocks ran.** A refactor qualifies only if every basic block of the changed
function(s) that the change touches is hit by some reference recording, measured by block-mode coverage
(`tools/cover.py list --bb`, one replay per reference with `HULK_COVER`) on the change's own image: the changed
function's blocks in the proof image, matched to the hit list. Function-entry coverage is not enough (a reached
function can still have its changed branch unrun: in play3 a third of the reached functions do not run every block).
A function on an ICF-folded address counts as **unreached** (a hit cannot say which folded function ran) unless the
coverage build is linked without folding (`/opt:noicf`, a coverage-only link option to add).

**R3. The gate.** A control (HEAD) and a proof (with the change) on one host and the same inputs, every reference
replayed: `ckpt_gate` GATE ok, including the reference gate (no (frame, tag) the control matched against the original
diverges in the proof) on **every** reference, and no reference frame lacking. Observable tags (`sound`) and tags the
originals disagree on are outside the gate by construction.

**R4. What stays.** A block that fails R2 keeps today's rule (a proof or a byte match). So do: blocks whose effect
the probe cannot see (rendering, audio mixing, file and save I/O, until the `obs` and `save` tags exist; R2 alone does
not show that a block's outputs reach a hashed tag), blocks that only a 64-bit build runs, and `matches` blocks whose
bytes the change alters (a byte match is a different claim from behaviour). The ledger records a checkpoint
validation as its own kind (`ckpt`, naming the references, the coverage run and the pair), never as an `equiv` proof,
so a later re-proof requirement can find every block validated this way.

**R5. After the 32-bit builds are gone.** The rule then runs on the native build: the native replay with the probe
(the same tags; the actor and mission tags need the records of "Follow-ups" before they are available natively),
coverage from a native instrumented build (`-fsanitize-coverage=trace-pc-guard` or the same one-shot breakpoints), and
the same reference files: they come from the original in xemu, so they outlive the Wine build. Until a native replay
matches the references as far as the Wine build does today, R1-R3 run on the Wine build.

**Coverage today (play3).** 15,379 of 27,486 functions reached, about 58% of the bytes by block: under R2 most of
the front end, the memory card, movies and ~40 move families stay on proofs until recordings reach them (the
recording checklist below).

## Follow-ups

**(A) Shared records for the probe's pointer chain (native correctness; owner: the records lane, when native
reaches gameplay).** The actors and mission tags walk world (0x4dd700) +0x20 (the actor manager) and +0x2c (the
scenario manager), the actor manager's count (+0xc), handle list (+0x10), main actor (+0x124) and handle table
(`*(+0)` +0x44: count +4, items +8 of 0x24 bytes, flags +0xc), and the actor's scene node (+0x10) and its drawable
(+0x18, position +0x40). gen spells only the CCharacter and CScenarioManager fields; the rest are read at 32-bit
offsets, so natively those tags are unavailable. The game's own code reads the same objects through TU-local
stand-ins (`Obj_59a50`/`Data_59a50` in CFightParamsCollision.cpp, the local views of the world in 277 TUs that name
`DAT_004dd700`, 21 TUs that call the handle-table functions 0x59ba0/0x59c10), so natively the layout that matters is
whatever those stand-ins say. The task: records `Sim` (the world), `CActorManager` (a gen class body; it has no RTTI
class of its own), the handle table and its item, and the scene node and drawable, in records.h or gen; convert the
stand-ins in those TUs to them; whole-tree verify (no code_changed), `gen_headers.py --probe`, the x64 gate, a Wine
pair, re-pin the D139 movers `--from-ledger`. Estimate: the world record alone reaches 277 TUs (the D74/D77 risk of a
header most TUs include), so a lane-week class of work in two or three landings (world first, then the actor
manager and table, then the scene node), each with its own whole-tree verify and Wine pair. The probe then reads
through the records and the native tags become available.

**(B) The probe calls the game's read-only getters (D161).** Where a getter exists, the probe calls it instead of
reading offsets, so its reads follow the game code's own layout on every build: 0x59c10 (handle to actor, through
0x59ba0) and 0x59a50 (the scene node's position). Each was checked side-effect free from its listing (reads only;
0x59a50 writes only its output). In xemu they are called at the probe point (inside GameClock::Update, on the game
thread), in the Wine build as `FUN_00059c10` / `FUN_00059a50` (thiscall, bound by address). Implemented (D161.2):
the hashes are the same as with the offset reads (the getters read the same words), so the references stay valid;
the actor's scene node is read through gen (`CCharacter::_pad_10`, the word after pure3d::Entity) and the scenario
manager's end time through gen's new `CScenarioManager::f_119c`. What still needs (A): the world and actor-manager
words and the handle table pointer.

**(C) Particle frames.** See "The particle tag" below.

### The particle tag (phase 4a)

Against the two-run play3 reference the Wine build differed in the particle tag at 143 frames after 12,923, all at
frames where the two original runs agreed. The original is the cause, not the Wine build: a third original run
(xemu dump 105756) disagrees with the A = B agreement at 12,923 and 13,542 too, and at 13,542 the field dumps show
which generators: the first sprite updater's MWC and guard (words 0-2) and the unset second one (3-5) are equal in all
runs, while the point/plane/sphere generator (6-7) and the sprite emitter (8-9) differ between the Wine build and the
third original run as much as between original runs. After about frame 12,918 the original's particle streams follow
audio-driven event timing (wine-replay.md), and two runs can coincide at single frames by chance. So references are
made from **three** runs (`ckpt_ref.py make A B C`): a (frame, tag) is kept only where all agree, which removes those
chance agreements; the particle and sound tags stay frame by frame as before.

## Recordings needed for broad coverage

play3 reaches 56% of the functions. The user records these with `tools/hybrid_test.py record` (record-replay.md
"Recording a session"); after each, `cover.py` measures what it added and picks the next. Checklist for the player:

1. **Front-end tour** (about 6 min, fresh game): open every screen, scroll every list, change every option, enter a
   cheat code on the cheat screen, open Stats and Unlockables, accept and dismiss pop-ups.
2. **Memory card** (about 6 min): save a new game, overwrite it, load it, delete a save; pick "continue without
   saving" and "retry" if offered.
3. **Movies**: one session recorded **with** movies (without `no-fmv`), from boot through the intro and the first
   mission's cutscenes.
4. **Varied combat** (10-15 min, in missions with props and enemies): every move family (beam / clap attacks,
   surfing on a car, ball-and-chain, every grapple and throw), helicopters, tanks, aircraft, using held props as
   weapons.
5. **Later missions and the second city area**: at least one mission of each kind past the first area (race,
   destruction, escort, boss).
6. **play4**: continue play3 from its last snapshot (`record play4 --continue play3`), so play3's references extend.

Tips (as for play3): run on AC power, nothing else heavy on the Mac, press START at the loading screens yourself,
Ctrl-C in the terminal when done.

## Status

- Coverage: landed (ckpt1 phase 3 step 1; control 104695, proof 104986, GATE ok).
- Probe (v3), `HULK_CKREF` in the Wine build, HF_PROBE in the hook-only XBE, `hybrid_test.py replay --ckref`, and
  `tools/ckpt_ref.py`: landed (ckpt1 phase 3 steps 2-3 and 5; control 105130, proof 105140, GATE ok).
- References: play3 v3 from two xemu runs (step 4, local `build/ckpt/play3.ckref`).
- Native: the probe compiles for the 64-bit builds with the actor / mission tags unavailable until gen spells their
  words; the native replay driver calls it once native reaches gameplay.
