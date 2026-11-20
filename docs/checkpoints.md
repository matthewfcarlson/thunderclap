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

The probe (`src/platform/sdl/replay/ckpt_probe.{h,cpp}`) reads named game state **through the tree's own types**
(`include/gen` classes, `include/decls` records) and writes a canonical byte stream. It is compiled:

1. with MSVC 7.1 into the hook-only XBE (`hybrid/`, linked into `.hybrid`): on the original, gen's 32-bit layout is the
   original's layout (checked class by class by `gen_headers.py --probe`);
2. with clang i686 into the Wine build;
3. with the native front ends into the 64-bit builds, where the same field names follow the native layout.

So no offset is written twice, and a record the game code itself reads correctly natively is read correctly by the
probe. A field the probe needs that gen still spells as a pad or an untyped `f_XX` gets a proper name and type in gen
(or a records.h record), through the usual header process (`gen_headers.py --probe`, whole-tree verify).

### Canonical encoding

- Little-endian fixed-width values: integers as u8/u16/u32 by their declared width, floats as their IEEE bit patterns,
  booleans as one byte.
- **Floats are exact.** The port's float work (wine-float.md, native-float64.md, soft-x87.md) aims at bit-exact
  results on every build; quantising would hide exactly the 1-ULP divergences the div8/div9 hunts found. A quantised
  copy of each float field (2^-10 relative, sign-preserving) is hashed into a separate diagnostic stream only: when
  the exact hash differs and the quantised one does not, the report says "float drift"; when both differ, "logic".
- **Pointers are never hashed.** A pointer field is encoded as null / non-null, or as the ordinal of its target in a
  list the game owns (actor index in the actor manager's order); names as the game's 32-bit tUID hashes; strings by
  content.
- Lists are walked in the game's own order (its arrays and linked lists), never in memory order.
- Each sub-hash is FNV-1a 32 over (frame, tag, stream); the frame record is the list of (tag, hash) pairs.

### Sub-hashes (tags)

| tag | tier | contents |
|---|---|---|
| `flow` | cheap | boot step, game state, current level and mission ids, pause / loading flags |
| `clock` | cheap | the GameClock (game and scaled time, dt, rate), the virtual clock |
| `rng` | cheap | gameplay MWC (0x4e5ad0), particle MWCs (0x554be4..), the sound generator, Lua's `rand` state |
| `hulk` | cheap | position, orientation, velocity, health, rage, current action / state machine id, animation id and time, held prop (ordinal) |
| `camera` | cheap | position, target, field of view, active camera kind |
| `actors` | full | count by type; per actor in the actor manager's order: type tUID, position, orientation, health, AI state id |
| `mission` | full | mission and objective state, timers and counters through the game's mission objects (not the Lua VM: its tables and GC counters depend on pointers and on 32/64-bit sizes) |
| `fe` | full | the front-end screen stack and selection, HUD state |
| `save` | event | hash of the save buffer each time the game writes it |
| `obs` | optional | observables beyond game state: a digest of the frame's draws (the drawlog record, graphics-backend.md) and of the sound events started |

The legacy narrow hash stays in the frame record (tag `legacy`) so existing recordings, ckpt_gate and the native
replay keep working.

**Rate.** The cheap tier every frame, the full tier every 30 frames (the current interval). In xemu the hook writes
the records into a ring the host drains as it does today (QMP memsave every 2 s); the hook's code and ring stay small
(a 1.2 MB ring once starved the game of memory: record-replay.md), so the full tier's per-actor streams are hashed in
the guest and only (tag, hash) pairs leave it.

## Reference checkpoints from the original

1. Build the hook-only XBE with the probe (`tools/patch_xbe.py --hooks`, the probe compiled with MSVC 7.1 like
   `hooks.cpp`; no game function is patched).
2. Replay each recording in xemu through the queue (`--needs xemu`, always `-snapshot`; play3's VM snapshots let
   shards run in parallel, `--from-snapshot K`), **twice**, ideally on two hosts.
3. A frame's (tag, hash) is a reference when both runs agree; a frame where the original disagrees with itself is
   dropped for that tag (this is where the known transients go).
4. Store `build/ckpt/<recording>.ckref` locally (header: format version, recording name and content hash, XBE hash,
   probe version, tag list; then per frame the (tag, hash) pairs, plus the quantised hashes). Never committed.

A probe change bumps the probe version and needs new references; the tool refuses a reference of another version.

## Comparing a build (`ckpt_ref`)

`tools/ckpt_ref.py check RUN --ref build/ckpt/play3.ckref` reads the run's frame records (the Wine build writes them
with `HULK_CKREF=1` beside the trace) and reports, per tag, the first diverging frame, whether it is drift or logic,
and the overall verdict (every reference frame matched). Localisation:

- **which subsystem**: the first tag to diverge (tags are independent, so `hulk` diverging before `rng` says where);
- **which fields**: `HULK_CKREF_DUMP=<frame>` makes the Wine or native build write the canonical field stream of that
  frame by name; the original's is taken from a third xemu run halted at that frame (`halt_frame`) with the same dump;
  `ckpt_ref.py diff` names the fields that differ;
- **which code**: the coverage report's first-hit frames give the functions first entered between the last matching
  and the first diverging frame (the window's suspects), and block coverage of that window (a coverage run started from
  the last matching frame) narrows it to the functions that ran there.

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
- Probe, hook-only XBE with the probe, references and `ckpt_ref`: phase 3, steps 2-5.
