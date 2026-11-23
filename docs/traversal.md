# Traversal: how Hulk moves, and how to make the city faster to cross (wtrav0)

Research and design for the remaster's traversal wishlist ([remaster.md](remaster.md) §6.0, "Hulk's move set and
traversal") and the user's request of 2026-11-23: "it should be easier to get around the city ... unlockable moves such
as charging running (holding down sprint makes you charge going faster and faster and doing more damage when you
collide)". Nothing here changes the faithful port. Destruction itself (breaking walls, craters) is lane wdest0's
subject (docs/destruction.md); this doc only says where a charged sprint would hand off to it.

Sources: the tree (`src/engine/fight/`, `src/game/global/`, `src/game/hulkfight/motion/`), and the player's own
`build/rcf/misc/scripts/fight/hulk.fig` decoded with throw-away scripts in `build/wtrav0/scripts/` (not committed:
`figdict2.py` builds a name dictionary, `figtree.py`/`figfind.py`/`figann.py` list nodes and track parameters). Numbers
quoted from the data are tuning values, read once; no script text or game data is reproduced. "(I)" marks an inference;
everything else was read in code or data.

## Summary

- **Hulk's moves are data.** Every speed, jump height, wall-run speed and contact damage is a parameter of a *track* in
  the fight script `scripts/fight/hulk.fig` (1,389 nodes, 625 banks). The C++ code holds the track classes and the
  physics formulas, no tuning (one exception: the fall speed cap of 200).
- **Sprint is constant speed.** Hold the right trigger (the game's "Free Look" button, index 5) with the stick
  deflected: `LocomotionSprintTrack` moves Hulk at a flat 20 units/s (run: 10). There is no ramp.
- **Charge already exists** as a per-character float (Char+0x1e58, 0..1) that tracks fill over time, and **contact
  damage already scales with it**: a collision track does `damage + (damageMax − damage) × charge`. The jump consumes
  charge to interpolate its flight time, height and distance. The user's charging sprint is therefore mostly a new use
  of existing machinery: fill charge while sprinting, let collision damage read it. Only the speed ramp needs code.
- **New moves can be pure data**: a `.fig` is a patch grafted into the fight tree at a path, track and condition
  classes are looked up by name hash, and a node can be gated by the existing `unlockable` condition. What is missing
  for that is tooling (a `fig0` writer) and a way to load an extra file in the app.
- **Unlocks**: 100 `CUnlockableMove` slots (unlockable indices 0x266–0x2c9); the shipped `init.lua` sets up 63 of
  them, so about 37 slots are free. Purchase state is one bit per unlockable in the save record, so a remaster move in
  a spare slot is saved by the original format with no new fields (old saves read it as "not bought").
- **Recommended first prototype:** the charging sprint, as two entry hooks in the wasm app (sprint speed ramp, charge
  fill) behind a remastered-only settings row, tuned in free play, then turned into data (a fig chunk gated by a spare
  unlockable move slot, bought in the moves store) once the feel is right (§8).

## 1. The fight system in brief

The fight system (namespace `fight`, `src/engine/fight/`) runs every character's moves, AI and mission scenario logic.
Three *contexts* exist: Motion, AI and Scenario (`FUN_0010b2c0`).

| Piece | What it is | Where |
|---|---|---|
| **Bank** | a list of child banks and nodes with its own conditions. Selection (`fight::Bank::vfunc_8` 0x23c670): if the bank's conditions pass, walk the children; the first passing child of weight ≤ 0 wins, otherwise a weighted random pick (`FUN_00238350`, the game RNG) among passing children | `Bank.cpp` |
| **Node** | one move: conditions, a list of tracks, optional children | `Node.cpp`, `Node::vfunc_9` 0x231c50 reads it |
| **Track / Action** | a timed piece of behaviour (`timeBegin`, `timeEnd`; −1 = until the node ends). Each track makes an Action when the node starts; `Action::vfunc_5(event, dt)` runs each frame | `Track.cpp`, `Action.cpp` |
| **Condition** | a test (button, stick, velocity, charge, unlockable, ...); lists combine by AND, with OR and NOT entries (`FUN_00236f40`) | `Condition.cpp` |
| **Opportunity / Execute / Sequence** | the transitions: in a time window, if a condition group passes, queue a branch (by index in the chunk) at a priority; `OpportunityAction::vfunc_5` 0x237590 | `OpportunityTrack.cpp` |
| **Chunk** (`fightChunk`) | one `.fig` file: a version, a context, a `path` into the existing tree and the branches to insert there. A `.fig` is a patch | `Chunk.cpp`, loader `FUN_00232870` |

Per frame (`FUN_0003b7d0`, the motion runner at `CCharacter`+0xb4): with no node running, the root bank selects one;
the running node's actions start when their begin time passes and stop when `vfunc_5` returns false; opportunity
windows queue the next node, which replaces the current one if its priority allows (`FUN_00232060`). Hit reactions run
on a second runner (+0xdc).

**Loading.** `am_LoadFightScript` (0x24480 → `FUN_00024400`) reads a file; `FUN_00232870` accepts the binary `fig0`
format (`BinReader`) or a text format that starts with `\r\nfightChunk` (`ScriptReader`). The level loader always
loads `scripts/fight/hulk.fig` and `common.fig` (`FUN_00206320`); mission and location `_init.lua` scripts load the
rest (docs/lua-scripts.md "Load path").

**`fig0` binary layout** (from `BinReader.cpp`; enough to read and, with care, to write):
- header: `fig0`, a flags word (bit 0: enums as ints, bit 2: names as 8-byte hashes; hulk.fig has both);
- records: an 8-byte tag hash, a 4-byte payload size, the payload (scalar fields), then child records; a zero tag ends
  a list;
- names are 64-bit hashes `v = v * 0x1003f ^ c` over the characters (`FUN_002672f0`), with a case-folding variant
  (`FUN_00267340`) for branch names;
- **parameters are positional**: the binary reader ignores the parameter-name hash and reads the class's parameters in
  their registration order (floats, ints and bools 4 bytes, vectors 12, names 8, strings length-prefixed). The text
  reader goes by name;
- transitions name their target by **index within the chunk**, so a chunk can be appended to but not reordered.

## 2. How the original moves Hulk

### 2.1 Character state

`Char` is the per-character motion state (`FUN_000592a0()->FUN_00059a30()`):

| Field | Meaning |
|---|---|
| +0x80 | velocity (vec3) |
| +0x1a8 / +0x1b4 | per-frame velocity add / displacement add (momentum and drift tracks) |
| +0x140 | motion state: None, Standing, Prone, Air, Climbing |
| locomotion state | Walking, Running, Climbing, WallRunning, Jumping, Falling, GetHit, Surfing (`LocomotionStateTrack`, enum 0x48f590) |
| +0x1e58 / +0x1e5c | **charge** (float) and charge type (0 Jump, 1 Attack, 2 Throw) |
| +0x1f58 | input block (buttons and sticks, copied in by the controller agent) |
| +0x2064 / +0x2070 | intention: camera-relative stick direction and its magnitude |

### 2.2 Input

`InputTracker::FUN_000af170` (`CGameController.cpp`) keeps 11 logical buttons and 2 sticks, each button with a state
(up, pressed, held, released), a held time and a value. The logical buttons (0x49ee30) are Punch (X), Gamma (Y), Action
(B), Jump (A), Taunt, **Free Look (index 5, right trigger)**, Target (left trigger), ... `CControllerAgent::vfunc_4`
0xfd0f0 copies the pad into Char+0x1f58 and computes the stick heading relative to the camera. Fight conditions
(`buttonDown`, `buttonPress`, `axisDown`, `intentionSpeed`, ...) read that block. The hold time is counted in frames of
pad state, not wall-clock time.

### 2.3 Run and sprint

| Move | Trigger (hulk.fig) | Track and values |
|---|---|---|
| Walk / run | stick | `locoSteer` (`LocomotionSteerTrack`): acceleration 60, turning 840°/s, walk 3, run 10 units/s. Speed by stick magnitude: ≤ 0.5 walk-scaled, 0.5–1 blends to run (`FUN_0015c590`) |
| Dash (sprint start) | bank SPRINT: stick deflected + Free Look held + a script variable | node DASH: a short animation, a body collision volume (damage 15, see 3.1), shield arc, threat ball, then an opportunity into SPRINT |
| Sprint | continuing | `locoSprint` (`LocomotionSprintTrack`): velocity **20**, turn velocity 360°/s, turn acceleration 2400, lean threshold 0.99, lean rate 20; three body collision volumes at Motion_Root (front and both shoulders, damage 10 each) |

Code: `LocomotionSprintAction::vfunc_3` 0x163ed0 builds a `choreo2::LocomotionSteerDriver` whose speed starts at the
current forward speed; `vfunc_5` 0x15e250 holds it at `velocity` (a parameter read by `FUN_0015c4f0`; a negative value
means the animation's own speed) and turns toward the stick with a damped angular integrator. The driver scales the run
cycle's playback rate to match the speed (root motion), so a faster sprint plays the legs faster.

Units: the template's world capsule is 3 high and 1 in radius (`global.rdl`), so a unit is about a metre (I). Sprint is
about 72 km/h.

### 2.4 Jump, charged jump and falling

Charge: `ChargeTrack` (type, clearOnBegin, finalCharge) fills Char+0x1e58 linearly over the track's duration
(`ChargeAction` 0x171860 / 0x1718f0, `+= dt × rate`). Holding Jump runs a charge track; `ChargeCondition` reads it.

`CJumpAction::vfunc_6` 0x13b90 consumes the jump charge t (0..1, `FUN_0003ec00`) and builds a closed-form arc:
T = lerp(minFlightTime, maxFlightTime, t) to the apex, H = lerp(upDistance), D = lerp(forwardDistance); launch speed
2H/T, forward speed D/T, the jump's own gravity 2H/T² (not the world's −3000 of `CCollisionManager` 0x1b6440).

From sprint (bank Jump under SPRINT, on Jump released):
- charge ≤ 0.2: a fixed hop (apex 0.5 s, up 6, forward 7);
- otherwise the charged jump: apex 0.32–1.27 s, up **4–30**, forward **2.5–35**.

Other jump tracks in hulk.fig go up to apex 1.67 s and 48 units straight up (I: the full super jump). A "StartChargedJump"
event fires at full charge.

Air control (`CJumpAction::vfunc_7` 0x18d40, `FallAction::vfunc_5` 0x134ee0): steering only. Hulk turns toward the
stick at a rate interpolated by forward speed (300°/s at the low end in the sprint jump), skipped when the stick is more
than 135° off at speed; `drift` (7) adds stick-along-facing displacement. Falling uses the track's gravity (50 to 300)
up to `maxVelocity`, clamped at 200 in code.

### 2.5 Wall run, climb and exits

- **Entry**: `CClimbableCondition::vfunc_7` 0x4d130 probes along the facing (or the stick) for 3 × radius plus this
  frame's movement (capped at 5), retrying at ±arc/2, and accepts a wall whose normal is within `arc`.
- **Wall run** (`WallRunAction` 0x142990 begin, 0x13fa80 per frame): without `useCharge` the start velocity is the
  current velocity minus its into-wall part, raised to at least `velocityInit` (20–40) and `velocityInitY` (0–30):
  **sprint momentum already carries onto the wall.** With `useCharge` it is the stick direction, at least 45° up, at
  lerp(velocityMin, velocityMax, charge). Each frame: gravity 10, friction 1, speed kept in [20, 30–40], turning toward
  the stick at 60°/s; the run ends when the wall turns flat (|n.y| > 0.6), the normal jumps by more than
  `maxAngleChange` (40°) or turns more than 135°.
- **Exits**: `WallExitTrack` and `WallJumpTrack` (velocityMin/Max, gravity, up angles, drift); a climb uses
  `climbLocomotion4` (velocity 6 in every direction). Other movement tracks: `surf` (riding a car or slab, velocities
  20–35), `groundSlide`, `flyingDash` (a mid-air dash, velocity 25–50), `bounce`, `momentumXZAdd` (blend horizontal
  speed to a final value over the track).

## 3. Contact damage and knock-back

### 3.1 Collision tracks

`CCollisionTrack` (`CCollisionTrack.cpp`) is a sphere on a joint with an offset and radius, active for the track's
window, with hit counts per target size, flags (`bumper`, `devastator`, `steelFists`, `crusher`, ...), hit types, a
sound, `damage`/`damageMax`, `force`/`forceMax`, a direction mode, and small/large-target reaction parameters
(interrupt, reaction time, push-back distance and time, height, stun). The sprint's three volumes deal 10 damage each,
the dash 15.

Hit resolution `FUN_00019470` (`CCollisionAction_2.cpp`) builds a `CFightParamsCollision` (+0x78 damage, +0x7c the
attacker's charge, +0x80 the force factor) and sends it to the target's `receiver` branch or applies it
(`CCharacter::FUN_000437a0`). The damage formula `FUN_00013f20`:

1. charge c = the attacker's charge, clamped to 0..1;
2. damage = `damage + (damageMax − damage) × c` when `damageMax > 0`;
3. × caller factor, × 2 for a held-prop match, × the character's damage scale (rage 1.2), × 2 against a `crusher`
   target kind; a cheat sets 100000.

So **damage is a parameter scaled by charge, not mass × speed.** Push-back distance, time and height come from the
small- or large-target set, scaled by 50/weight or 1000/weight of the target's class; the direction is the attacker's
facing or attacker→target.

### 3.2 Props, cars and the world

- **Props and vehicles** are state props (`CSPHulkPropInstance`): `FUN_001d6ec0(amount, attacker, forced)` scales by
  the prop's meter and kind, subtracts from health only above a per-prop threshold (+0x10c), and reports the killing
  hit. Physics contacts between props and characters (`AICollisionSolverAgent` 0x1b1270, 0x1b1710) need a relative
  speed above 5 and use a mass-class table.
- **Static world** damage (`WorldDamageTrack` 0x143b20) is decals and effects only (fire, crack, footprint ...
  per surface kind). Breaking buildings is wdest0's subject.

## 4. Unlocks, smash points and saves

- **Definition**: `CUnlockablesManager` (ctor 0x94fb0) holds 766 unlockables; indices 0x266–0x2c9 are 100
  `CUnlockableMove`s. `init.lua` fills them with `um_SetupUnlockableMove(index, nameKey, comboKey, descKey, image,
  cost)` (0x92ef0; cost 0 = gifted), orders the store with `um_SetupUnlockableMoveFEOrder` (position < 100) and chains
  prerequisites with `um_SetUnlockableDependency` (move+0x28). The shipped script sets up 63 moves (static count).
  A move object: +0x20 purchased, +0x24 cost, +0x28 prerequisite, +0x2c tutorial flag, +0x38/+0x40 combo and
  description string keys, +0x48 image name.
- **Gating**: the fight condition `unlockable` (`hulkfight::UnlockableCondition`, registered 0x132620, evaluated
  0x12f110) takes an index and a `locked` flag. hulk.fig uses it 93 times, all with move indices 614–759. A cheat
  (0x1d) makes every move count as bought. A few C++ paths read moves directly (health upgrades in `CCharacter`
  0x401a0, missile deflection).
- **Smash points** are the `xp` stat in `CStatsManager` (`sta_AddXP` 0x900a0); the store spends them.
- **Store**: `CFEManager` 0xc21b0 builds the list (skips locked moves; shows GIFTED / ENABLED / cost), 0xc2c20 fills
  the detail pane, 0xc31e0 buys (prerequisite, cost, then `AddXP(−cost)`, purchased, optional tutorial).
- **Save**: one 0xbe8-byte record per slot (`CGameFlowManager`+0xac8; capture 0x8b560, apply 0x8a8f0, load 0x890a0),
  checked only by a magic word (and the XDK signature). Unlock state is two bitsets of 32 words at +0x38 (locked) and
  +0xb8 (on/purchased), one bit per unlockable index; bits 0x2fe–0x3ff are never written and read as zero.

### 4.1 Plugging in a new move

| Option | How | Old saves | Cost |
|---|---|---|---|
| **A. a spare move slot (recommended)** | one of the ~37 indices in 0x266–0x2c9 that `init.lua` never sets up: a remaster-only startup step calls `um_SetupUnlockableMove` / `FEOrder` / dependency for it (strings from our own string table); the fight chunk gates the move with `unlockable(index, locked=false)` | the bit is 0: locked, not bought | small; save, store, pricing, prerequisite and the fight condition all work unchanged |
| B. the spare bits 0x2fe–0x3ff | grow the tables past 766 | read as 0 | large: `items[0x2fe]`, the 766-name enum, range checks and the manager layout all change |
| C. a sidecar file | our own record beside the save | untouched | medium; only needed if the store must hold more than the free slots |

The free slot list must be confirmed by a run-time dump of the manager (which slots have no name key) before choosing
indices. With option A the original executable reading a remaster save sees a set bit for a move it never set up and
ignores it (its store skips moves without data) (I).

## 5. Designs for faster city traversal

Each design names its hook, its size and what it changes. "Data" means a fight-chunk change (§6.1); "hook" means an
entry hook in the app (as `draw_distance.c` does) or a remaster-only track class.

### 5.1 Charging sprint (the user's request)

**Feel.** Hold sprint: Hulk starts at today's 20 u/s and builds over ~3 s to a top speed (first tuning guess 34 u/s,
1.7×), leaning further forward; a charge stage change gives a camera shake and a ground decal at stage 2 and 3.
Anything he hits at speed takes damage and knock-back scaled by the charge: soldiers fly, cars are punted (a high-charge
hit on a car passes its damage threshold and sends it tumbling), light props shatter. Turning is slower at top speed
(turn velocity falls from 360 to ~180°/s), so the move rewards straight lines through traffic; releasing sprint or a
hard turn bleeds the charge. A charged sprint into a jump keeps the extra speed (5.2), and into a wall gives a faster,
higher wall run (the wall run already keeps sprint momentum).

**Hooks.**
1. *Charge fill*: a charge track on the SPRINT node (type Attack, finalCharge 1, duration ~3 s), or a hook that
   writes Char+0x1e58 while `LocomotionSprintAction` runs. Charge type matters: the jump reads only Jump-type charge,
   so an Attack-type sprint charge is ignored by the jump unless 5.2 adds a carry.
2. *Speed ramp*: code. `LocomotionSprintAction::vfunc_5` 0x15e250 holds a constant `velocity`. Either an entry hook
   that scales the driver's speed field (+0x8b0) by lerp(1, 1.7, charge) and the turn velocity down, or a new
   remaster-only track class `chargeSprint` (registered in the Motion context like the others) that the data uses
   instead of `locoSprint`. Data-only alternative: three chained sprint nodes (velocity 20 / 26 / 34) joined by
   opportunity windows on `fightNodeTime`; coarse steps, no code.
3. *Contact damage*: data. Give the sprint's collision volumes `damageMax` (e.g. 10 → 80) and `forceMax`; the existing
   formula scales by charge. A `CollisionChargeCondition` on reaction branches can pick a bigger reaction (ragdoll
   launch) above a charge.
4. *Smash through*: state props already break above their threshold. Weak walls and building damage belong to wdest0's
   destruction layer; the hand-off is a contact event (joint, velocity, charge) that the destruction system consumes.
5. *Animation*: the run cycle already rate-scales with speed; above ~1.5× it looks like a sprint at double tempo. Use
   the lean animations (`animLeanEast/West`) and a stronger forward pitch on the root, or cap visible tempo and add
   motion trail (`motionTrail` track) above stage 2.

**Size.** Prototype as hooks: 2–3 days. Data version with a fig writer: 1–2 weeks including the writer (§6.1).

### 5.2 Landing jump (momentum chain)

Jump within ~0.15 s of landing and keep (part of) the horizontal speed you landed with, plus a boost; chain three and
the third leap is the long one. Today a jump's forward speed is D/T from parameters only: incoming velocity is dropped.
Hook: `CJumpAction::vfunc_6` (begin): if the Land node started less than the window ago, add `k ×` landing XZ speed
(k ~0.6) to the computed forward speed and bump H by a chain step; reset after the window. Data side: an opportunity on
the Land node into the Jump bank with a `fightNodeTime` window. Size: 2–3 days with tuning.

### 5.3 Wall-run carry-over

Entering already keeps sprint speed (`velocityInit` is a floor). The missing half is the exit: `WallExitTrack` /
`WallJumpTrack` launch at their own velocity range. Hook or data: use the wall run's current speed (or the sprint charge)
as the exit's lerp factor, so a fast wall run flings Hulk off the top or across the street. Data-only first: raise the
wall jump's maxima and use `useCharge`. Size: 1–3 days.

### 5.4 Better air control

`drift` and the turning rates are parameters of the jump and fall tracks: raising `drift` (7 → ~15) and the
low-speed turning rate is data only and immediate. A mid-air redirect (the existing `flyingDash` used as an air dash
on Jump while airborne, once per jump) is data plus one new node. Size: 1 day (parameters), 3–4 days (air dash).

### 5.5 Other ideas, ranked by fun versus cost

| # | Idea | Hook | Fun | Cost |
|---|---|---|---|---|
| 1 | **Charging sprint** (5.1) | hooks, then data | high: the user's ask; fast travel that is also a weapon | medium |
| 2 | **Longer charged leaps** as an upgrade (forward max 35 → 60, apex time scaled) | data: the charged jump's maxima in a gated variant | high for traversal, nearly free | small |
| 3 | **Landing jump chain** (5.2) | hook in `CJumpAction` begin | high for skilled play | small-medium |
| 4 | **Wall-run fling** (5.3) | data, then hook | medium-high | small |
| 5 | **Air control + air dash** (5.4) | data | medium | small |
| 6 | **Rooftop vault**: a charged jump aimed at a ledge in front snaps the arc to land on it (`CJumpAttackTrack` already aims a leap at a target with speed/distance/arc) | new target finder (ledge probe) + data | medium-high: removes the "short by a metre" frustration | medium |
| 7 | **Thunderclap glide**: clap at the apex to slow the fall and steer (low gravity, high drift for 2 s) | data: a node with `fall` (low gravity, low maxVelocity) and drift, gated, one per jump | medium; in the character's spirit | small-medium |
| 8 | **Car surf boost**: `surf` exists; a charged surf goes faster | data | low-medium | small |

Not recommended: anything that raises the world's gravity or the 200 fall cap (props share the physics), or that
changes jump physics globally (missions with jump puzzles are tuned to it).

## 6. Hooking it in

### 6.1 Two routes for a new move

- **Hooks (prototype).** Entry hooks in the wasm app, like the settings already shipped (`draw_distance.c`,
  `tutorial_skip.c`): inert unless the setting is on; state in Char fields or `hulk_game_state`. Fast to tune; ties
  the move to the app.
- **Data (shipping).** A remaster `.fig` chunk loaded after hulk.fig. Needs:
  1. a `fig0` writer (or the text format's reader reversed: `ScriptReader` takes names, which avoids positional
     mistakes); the reader-side layout is in §1 and the parameter order of each track class is in its registration
     function (`FUN_001633f0` for `locoSprint`, `FUN_00146190` for `worldDamage`, ...);
  2. a way for the app to read a file that is not in the RCF archives (a remaster overlay in `run/disc.c`'s hdisc
     layer) and a remaster startup step that calls `am_LoadFightScript` on it;
  3. the chunk's `path` naming the SPRINT bank (or its parent) so the new nodes are siblings selected before the
     original, gated by `unlockable(index, locked=false)`; weight ≤ 0 keeps the bank's selection first-match and
     leaves the RNG untouched.
  A remaster-only track class (`chargeSprint`) is code registered beside the originals; the data then only names it.

### 6.2 Gating: remastered edition, unlock and setting

- A remastered-only settings row "Traversal moves" (port_settings.c; faithful value off). With it off the app neither
  loads the remaster chunk nor arms the hooks, and the setup of the new unlockable slots is skipped, so the game is
  the faithful one: same heap layout, same RNG draws, identical play3 checkpoint records. Loading the chunk even with
  every move locked would allocate fight objects and move the game hash, so the gate must be "not loaded", not
  "loaded but locked".
- With it on, each move is an unlockable move in a spare slot, bought with smash points in the original store. A
  remaster "all traversal moves" toggle can set the bits for players who want them at once.
- The row is per session (like Aspect Ratio and Draw Distance): it changes the simulation, so replays, `HULK_INPUT`
  tests and rollback runs pin it, and netplay peers must share it (the session handshake carries it).
- Purchases live in the host's save; old saves load with the new moves locked; the original executable ignores the
  extra bits (§4.1).

## 7. Determinism, co-op and the rest of the game

- **Rollback.** Every input to these designs is simulation state: the pad block (frame-counted hold times), Char
  fields, the fight runner's node time, the game's dt. New state (a landing-window timer, a chain count) goes in the
  character's own words or in `hulk_game_state`, never in host statics or wall-clock time. Hooks must not draw from
  the game RNG (or must do it identically on every peer). With these rules the moves are rollback-safe like the
  original moves; the per-session setting keeps both peers on the same rules.
- **Co-op.** Both Hulks run the same fight tree; the host's save decides what is bought (multiplayer.md §6.6), so the
  guest gets the host's moves. A charged sprint into the partner should not damage them (the collision track's hit
  types / team check, to be verified with two Hulks).
- **Camera.** The game camera follows with lag tuned for 20 u/s; the sprint node already sends a camera hint (6).
  At 1.7× expect the camera to trail; add a remaster camera hint that pulls back and widens with charge (render-side
  FOV only: the logic view's FOV feeds simulation, remaster.md §3.3).
- **Streaming.** Rooms stream around the player (`CWorldStreamManager`); the game draws to ~390 units. At 34 u/s
  Hulk crosses that in about 11 s, twice as fast as today, and a long charged leap (60 forward) adds more. Measure
  room-load stalls with `HULK_SYNCIO` off in free play before raising top speeds further; the far field (far-field.md)
  hides pop-in at distance but not missing collision.
- **AI.** Enemies attack through the token tracker around the player and aim at his position; faster movement means
  more missed shots and lost targets (AI reads Hulk's velocity in `TargetVelocity*` conditions, so some lead their
  shots). Heat and military response come from destruction and missions, not speed, so a faster Hulk does not change
  them by itself; a charged sprint through traffic does, through the props it breaks. The wishlist's "counter-Hulk
  tactics" (dodging charges) would read the charge value.
- **Missions.** Races, chases and timed missions are tuned to the original speeds. Option: the remaster chunk's moves
  carry a condition that disables them in listed missions (the fight scripts can test the chapter and mission:
  `chapterMission` condition), or accept easier missions.

## 8. Recommended first prototype (one lane)

**Charging sprint as app hooks, in build/ only until the feel is approved.**

1. Hooks: `LocomotionSprintAction::vfunc_3` 0x163ed0 (begin: reset the sprint's charge to 0) and `vfunc_5` 0x15e250
   (per frame: charge += dt / 3 up to 1 while the trigger is held and the stick is near the facing; scale the driver's
   speed by lerp(1, 1.7, charge); scale turn velocity by lerp(1, 0.5, charge)). Charge kept in Char+0x1e58 as type
   Attack so the existing collision formula sees it.
2. Damage: a hook in the hit resolution (`FUN_00013f20`) that, for Hulk's sprint collision volumes only, treats
   `damageMax` as `damage × 8` and `forceMax` likewise while the setting is on (the data route later writes those
   values instead).
3. A remastered-only settings row, default off in replays and tests; a debug overlay of charge and speed
   (`HULK_GFX_STATS`-style log line).
4. Checks: play3 records byte-identical with the row off (wasm_build_job `--test play3:N --control`); a free run with
   `HULK_INPUT` (trigger held 5 s down a downtown street) twice with the same hashes; a `HULK_ROLLTEST` across a
   charged sprint; feel review by the user in the app.
5. Then the data route: a `fig0` writer in tools/, the overlay file path, the spare unlockable slot with store text,
   and the charge tiers as data.

Size: 3–5 days for steps 1–4.

## 9. Open decisions for the user

| # | Decision | Options | Recommendation |
|---|---|---|---|
| T1 | How traversal moves are gated | a remastered-only setting only / unlockable moves in the store only / both | both: a per-session "Traversal moves" row turns the set on; each move is bought in the store |
| T2 | Implementation route | app hooks / data chunks (needs a fig writer and an overlay loader) / new remaster track classes | hooks to prototype, then data + one `chargeSprint` track class |
| T3 | Charging sprint top speed and damage | 1.5× / 1.7× / 2× speed; damage ×4 / ×8 at full charge | 1.7× and ×8 to start, tuned in play |
| T4 | Missions tuned to original speeds | disable remaster moves in listed missions / accept easier missions | disable in timed and chase missions only |
| T5 | Which ideas follow the charging sprint | §5.5 ranking | longer leaps and landing chain next, then the wall-run fling |

## 10. Open questions

- The free move slots: dump `CUnlockablesManager` after `init.lua` to list slots with no name key.
- The exact parameter order of `CCollisionTrack` against the data (the sprint record's force words read as
  2000/1000; which of `force`/`forceMax` they are).
- Whether `forceMax` scales by charge like `damageMax` (I: the packet carries a force factor at +0x80).
- The text `fightChunk` syntax (`ScriptReader`): if it is easy to write, it is the better authoring format.
- Room streaming headroom at 1.7× sprint and 60-unit leaps (free-run measurement).
- Whether a charged sprint into the co-op partner registers as a hit.

## 11. What was built (wtrav1, D242)

The user's answers (D242, 2026-11-23): T1 both a settings row and store unlocks; T2 app hooks first, data later once
the feel is right; T3 the charge builds gradually only while the trigger is held, up to a level-set maximum, and a
release keeps the speed until a hit or another move; T4 the moves stay on in every mission; T5 a few +10% leap
unlocks and a stronger bounce for a jump right at landing. Built as entry hooks in the wasm app
(`src/platform/wasm/gfx/traversal.c`, `tools/wasm_port.py` GFX_APP_HOOKS), behind **Gameplay Options > Traversal
Moves** (`remaster_moves`, remastered-only: faithful Off, remastered default On; per session).

### 11.1 What the player gets

| Move (store) | Cost | Effect |
|---|---|---|
| Charge Sprint I | 20,000 | sprint top speed ×1.3, charged hits up to ×3 damage, ×1.5 push-back |
| Charge Sprint II (needs I) | 50,000 | ×1.5 speed, ×5 damage, ×2.0 push-back |
| Charge Sprint III (needs II) | 100,000 | ×1.7 speed (34 u/s), ×8 damage, ×2.5 push-back |
| Mega Leap I | 10,000 | every jump 10% higher and 10% longer (same air time); up to 2 chained bounces |
| Mega Leap II (needs I) | 25,000 | 20%; up to 3 bounces |
| Mega Leap III (needs II) | 60,000 | 30%; up to 4 bounces |
| Landing bounce | free with the setting | 1 bounce without Mega Leap |

Costs follow the shipped upgrade lines (Air Dash 12,000, Super Air Dash 25,000, Double Air Dash 60,000, Double Super
Air Dash 150,000; Critical Pain 75,000): the third charge level is among the dearest moves. Smash points are the game's
own (`xp`); the store, the "Acquired" state, the prerequisite dimming and the "Move purchased." dialog are the
original's.

**Charging sprint.** Sprint as before (stick + right trigger). While the trigger stays held the charge fills from 0 to
1 over 3 s of game time; the sprint's target speed is `velocity × lerp(1, top, charge)` (top by level). Turning gets
heavier with speed: the track's turn velocity and turn acceleration are scaled by `1 − 0.55 × (speed factor − 1) /
0.7` (half the turn rate at 1.7×). Any of Hulk's collision hits while charged (the sprint's body volumes, or anything
else he hits mid-sprint) deal `damage × lerp(1, damage top, charge)`, take at least `charge` as the force factor
(forceMax side of the force lerp), and push small and large targets `lerp(1, push top, charge)` further (height by the
square root). Releasing the trigger with charge ≥ 0.10 keeps the sprint at its speed and heading (a *coast*): the input
block shows the trigger held and, with the stick centred, the last stick sample with the intention along his velocity.
The coast ends on a hit (character or prop), on a wall (speed below 35% of the target for 4 sprint frames), when
another move takes over the node (jump, attack, a wall run: sprint momentum carries onto the wall as in the original),
or when the trigger is pressed again (charging resumes). Then the original rules apply.

**Higher leaps.** `CJumpAction::vfunc_6` 0x13b90 computes a jump's launch speed `v`, gravity `g` and forward speed
from the track and the jump charge; the hook scales all three by `k = 1 + 0.1 × level`: apex height ×k at the same
air time, distance ×k.

**Landing bounce.** What the original does: hulk.fig's landing bank has a branch (buttonUp+charge or buttonRelease,
not in c10m24 / c10m27) that re-jumps straight out of the landing, and such a re-jump keeps some jump charge: in a
measured chain of taps the launch speed went 21.6 → 26.8 → 31.7 → 33.0 (about +50%, capped). The remaster multiplies on
top: a jump that starts within 0.25 s of touching down (the main actor's motion state leaving Air) is bounce n of a
chain, ×(1 + 0.12 n) on height and forward speed (and at least 0.8 × the landing's horizontal speed); the chain grows
to 1 + leap level and breaks on any later jump. Measured with Mega Leap III and taps at each landing: launch speed
31.5, 43.2, 56.1, 63.5 (base 21.6 → 33.0), forward 26.7 → 38.1 u/s. Off in the two precision-landing challenges (c10m24, c10m27), as the
original's own re-jump is.

### 11.2 How it is wired

| Hook | Address | Does |
|---|---|---|
| sprint begin | 0x00163ed0 | the controlled character's sprint: charge 0 |
| sprint frame | 0x0015e250 | charge += dt / 3 while the trigger is down; turn fields scaled during the call; driver target speed (+0x8b0) scaled after |
| sprint end | 0x0015c540 | coast and charge cleared |
| controller input | 0x000fd0f0 | after the pad copy: the real trigger state; while coasting, trigger (button 5) held, stick 0 and intention replayed |
| damage formula | 0x00013f20 | charged hits: damage, force factor, push-back params (+0xf8/+0x100/+0x110/+0x118 of the track, put back at the end of UpdateSimulation); ends a coast |
| jump begin | 0x00013b90 | leap and bounce scaling of +0x28 (v), +0x2c (forward), +0x30 (g) |
| store list | 0x000c21b0 | the moves set up before the computer interface's Buy Menu refresh (front end too) |
| UpdateSimulation | 0x00088c30 (tutorial_skip.c's hook) | game clock, landings (motion state +0x140: 3 = Air), store upkeep, scaled tracks restored |

**Store.** Slots 0x2c4–0x2c9 (constants.unlockables move_95..100; the shipped init.lua sets up 63 moves, none there).
`um_SetupUnlockableMove`'s C side 0x92ef0 is called with our keys (`TBS_PORT_MV_*`, injected into str_*.txt by
fe_options.c), the cost and a copy of a shipped move's picture name read from that move (Dashing Straight for the
sprint levels, Air Dash for the leaps), so no game text is in the source. The store's rows are its order positions
read as a dense prefix (the detail screen 0x000c2c20 takes row n as `ids[n]`), and init.lua assigns positions only
as the story unlocks moves (`unlockable_move_fe_order_counter`), so ours are placed right after the shipped prefix
every update and move along when a new shipped move takes their place. A move's `locked` byte (+8) also disables it
in the fight script (`UnlockableCondition` 0x12f110 wants unlocked and bought), so ours are kept unlocked while the
setting is on. Purchase state is the original's on-bit (save record +0xb8), so an old save reads ours as not bought
and the original game ignores them. With the setting off nothing is set up and the store is the original's.

**Determinism.** State in `hulk_game_state` (charge, coast, stick sample, landing clock, chain, scaled-track list,
the set-up manager); all inputs are game state and the game's dt. Checks below.

### 11.3 Challenges and the move set (T4)

- No mission or challenge script locks a move: `um_SetUnlockableLocked` appears in 28 scripts (355 calls), all on
  smart hints, jump markers, comic-book galleries, movies and cheats (location `common.fig` scenarios, c00m01, c01m01,
  c02m04, c07m03, c08m00); init.lua unlocks moves as the story reaches them (and a debug "unlock all"). Bought moves
  are never taken away; a *locked* move would be off in the fight script (the condition wants unlocked and bought).
- Restrictions live in hulk.fig as conditions: `chapterMission` gates (parameters read as (2, chapter, 2, mission),
  (I)): c10m24 and c10m27 (jump off a building and land in a target) turn off the landing re-jump, smash, throw and 2-handed prop attacks; the
  other gates enable mission-specific prop moves (c01m02/04, c02m02, c03m02/03, c04m01/02, c06m01, c07m03, challenges
  c10m01/02/30/35/38); and `varCompare stealth_truck` turns off the sprint and attacks while Hulk carries the stealth
  truck.
- Air dash levels: Air Dash, Super Air Dash, Double Air Dash, Double Super Air Dash are separate moves
  (move_10/54/61/62) chained by dependencies; the fight nodes test them with `unlockable` conditions and count dashes
  per jump in a fight variable (`air_dash`). No mission restricts them.
- So the remaster moves stay on everywhere, except the landing bounce follows the original into the two precision-landing
  challenges. The charging sprint is off wherever the original sprint is (stealth truck), since it rides on it.

### 11.4 Checks

- play3 to 60,000 frames, null renderer, candidate (setting off) vs control on one host: checkpoint records
  byte-identical (prefix; the reference gate: no new divergence).
- Two identical `HULK_INPUT` free runs with the moves on (sprint 4 s, release and coast, a chain of landing taps):
  game hashes equal every 50 frames to 4,300; `HULK_ROLLTEST=2800:3700` across the charged sprint, coast and bounces:
  identical.
- Store: a Metal free run (new game, exit to the menu, Continue, Buy Menu) shows the six moves with prices and
  prerequisites; Charge Sprint I bought ("Move purchased.", points −20,000), saved; a new run loading that save shows it
  "Acquired" and plays it as level 1 (26 u/s coast); with the setting off the same save shows the original store.
- Not done: a fight chunk (data route), the camera pull-back at speed, a co-op partner check.

### 11.5 Developer forces (wdev1)

For testing without buying: developer mode (`developer=1` in port_settings.txt or `HULK_DEV=1`) lists Force Charge
Sprint, Force Mega Leap (Off / I-III) and Force Original Moves (Off / All Bought) at the end of Gameplay Options;
docs/wasm-port.md "Developer options". Hooks answer the purchase reads (0x12f110, 0x92940, 0x19e910); the save's
capture 0x8b560 sees the real bits.
