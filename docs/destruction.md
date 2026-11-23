# Destruction and deformable terrain (wdest0: research and design)

The user's remaster wishlist ([remaster.md](remaster.md) 6.0, "Destruction and the living city") asks for real-time
building fracture instead of fixed break states, damage from wall running and climbing, persistent rubble with
clean-up and repair crews, and (11-23) **deformable terrain**: craters from big landings scaled by fall height, and
ground and roads that deform. This page covers two things. First, how the original game makes the world breakable,
with addresses and data counts from the player's own disc. Second, what each wish would take in the wasm app's
remastered edition, ending with a first prototype sized for one lane.

Research only: no game or tool code was changed. Counts come from scripts over `build/rcf` (the player's extracted
archives, `tools/p3d.py` parser; the scratch scripts are in build/wdest0/, uncommitted). Script content is
paraphrased, never quoted. "Guess" marks what was inferred rather than read.

## How the original does it (no code needed)

- **Only smart props break.** A smart prop is a pre-made breakable object: a lamp post, car, billboard, water tower
  or one of about 30 special buildings. Each prop type is authored as a small state machine, for example clean,
  damaged_1, damaged_2, destroyed, gone. Every state names which pre-modelled pieces are visible, which collision
  pieces are on, which pieces fly off as rigid bodies, and which effects, sounds and child props fire. Nothing is cut
  at run time. Every break you see was modelled by an artist.
- **The city itself never breaks.** Ordinary buildings, streets and terrain are baked room geometry with a separate,
  simplified collision mesh. Punching a wall, stomping or landing on the ground runs a ray against that mesh. The hit
  surface's material (concrete wall, dirt floor, glass ...) selects a Lua function, which adds a **decal** (a crack
  or crater texture laid over the surface), particles (dust, sparks) and a sound. The geometry and the collision stay
  exactly as they were. The "craters" of big landings are decals.
- **Health is a number on the prop.** Every hit, whether a punch, a charge, a thrown car, an explosion or a
  shockwave, subtracts from it. When it reaches zero the prop takes its "out of hit points" transition to the next
  state, gets fresh hit points from that state, and the visuals and collision change.
- **Whole buildings fall by script.** When a destructible building reaches its destroyed state, a Lua helper shakes
  the camera, plays dust, damages everything inside the building's trigger volume for about six seconds, and spawns
  one to three rubble props (concrete chunks, girders), but only where the camera is not looking.
- **Nothing is remembered for long.** A broken prop stays broken while its room is loaded. When the room streams out,
  the prop's record is deleted, and the next load builds it again in its initial state. The save stores progress,
  stats, scores and "collected" flags for collectables, but no world damage.
- **Landings change nothing but decals.** No code uses fall height or impact speed to scale damage, shake or decals.
  The fight graph picks a landing move, and that move's tracks have fixed parameters.

## 1. Findings

### 1.1 What can break: smart props versus room geometry

**Census** (all 1,436 `.p3d` files):

- 1,206 `StatePropData` chunks (0x802000A) with 252 distinct names: 769 in mission files, 437 in location files.
- State counts per prop: 1 (128), 2 (265), 3 (348), 4 (94), 5 (131), 6 (119), 7 (53), 8 (22), and up to 19 (cars:
  colour variants times damage).
- The most common state names are `destroyed` (826), `clean` (798), `damaged_1` (184), `pickedUp` (141), `gone` (139)
  and `damaged_2` (69).
- About 30 prop types are buildings or large structures. Examples: `divisionABuilding` (8 states),
  `armory` (7), `bioRBuilding` (6), `intelBuilding` (6), `churchTower` / `churchCore` (5), `warehouse1` (5),
  `buildA/B/CBlock` (4), `damGenBuilding*` (4), `waterTower` / `waterTower3` (3), `electricalTower` (3),
  `pedOverpass` (3), `tollBooth` (3), `canyonBridge` (2), and the rock `hoodoo*` (3). Most are mission props
  (`art/missions/c0Nm0M.p3d`).

**Where props are placed.**

- Each room file carries two `DataHandlerRaw` chunks (0x60000A00). One lists that room's smart-prop placements
  (instance name, type, prop file, transform, `StateProp`). The other lists locators.
- `downtown_night` has 128 rooms holding 4,515 prop placements. The top types are streetLight 711,
  stopLightDouble 602, treeCrabtree 541, streetLampPost 267, dumpster1 243, carPT 210, airCon 182, waterTower3 173 and
  busshelter 147.
- `outskirts_day` has 181 rooms holding 1,808 placements: boulderT, treeOutskirt, streetLight, hoodooA, dumpster1,
  airCon, concDivider, oilBarrel ...
- Larger and scripted props are placed by the location's data-handler text file (`<loc>.dh`, e.g. 514 objects in
  dt_night.dh). Its attributes include `InitialState`, `Persistent`, `Rooms`, `IsStreamed`, `CollisionPropIndex` and
  `UnlockableIndex`. Example: the 13 `divisionABuilding` instances in downtown.

**Room geometry is one mesh per room.** A room file (`rooms.rcf art/locations/<loc>/<prefix>_rNNN.p3d`) is one
`Geometry` (`<room>Scene`) split into prim groups by material, plus one `WorldCollisionObject` (`<room>WorldCollision`).

- Buildings inside a room are not separate objects: there is no per-building mesh, collision, health or name.
- Collision is a separate, simplified mesh:

| location | rooms | collision triangles | median / max per room | render triangles (approx.) |
|---|---|---|---|---|
| downtown_night | 128 | 67,518 | 527 / 1,692 | ~155k |
| outskirts_day | 181 | 201,164 | 1,239 / 2,122 | ~180k |

**Samples** (where mesh, collision and health live):

| thing | location | mesh | collision | health |
|---|---|---|---|---|
| a downtown office block (e.g. in `dt_night_r512`) | room geometry | prim groups of `dt_night_r512Scene` | triangles of `dt_night_r512WorldCollision` (kd-tree, material bits) | none: decals only |
| `divisionABuilding` (13 in downtown) | `dt_night.p3d` (location file) | CompositeDrawable `divABuildCleanShape1/2`, `divARemainsShape`, `divABDebrisPileShape`, skeleton `divisionABuilding`, animation `PTRN_divisionABuilding` | per-state world collision `divABCollisionMeshAShape` (chunk 0x802000C) plus joint volumes | `CSPHulkPropInstance` +0x108, refilled per state |
| `armory` | room file `dt_night_r106.p3d` (in-room prop) | composite in the room file | `armoryCleanCollisionShape` in clean / damaged states, `armoryRubbleCollisionShape` in destroyed / gone | +0x108 |
| `waterTower3` (173 in downtown) | location file | composite, states clean / destroyed / gone | joint volumes | +0x108 |
| an outskirts hillside | room geometry (`os_day_r202`: 2,122 collision triangles) | prim groups (dirt, grass) | the room's collision mesh (Dirtfloor / Grassfloor materials) | none |
| `hoodooA` rock (125 in outskirts) | location file `os_day.p3d` | composite: clean / destroyed / gone | joint volumes | +0x108 |
| `canyonBridge` | location file | composite | world collision `cBridgeCollisionShape` | +0x108 |

### 1.2 The damage path

All damage to anything breakable ends in **`FUN_001d6ec0(amount, attacker, forced)`**
(src/game/global/CSPHulkPropInstance.cpp:1248), on a `CSPHulkPropInstance`. That class derives from
`pure3d::prop::StateProp`; it is 0x278 bytes, its constructor is 0x1d7890, and its layout is in include/gen/global.h.

**Instance fields:**
- +0x40: state index; +0x44: time in state.
- +0x98: StatePropData; +0x9c: drawable; +0xa0: `physics::PhysicsInstance`.
- +0xec: the type (`CSPHulkProp`).
- +0x108: **health** (int); +0x10c: minimum damage that counts; +0x110: has-hit-points flag.
- +0x148: carried-by (no damage while carried).
- +0x194: **indestructible**.
- +0x198 / +0x19c: alignment and its damage factor.

**What `FUN_001d6ec0` does:**
1. A held prop takes `held_damage_factor`.
2. An attacker of the matching alignment multiplies the damage by +0x19c.
3. If the damage exceeds +0x10c, health drops, the prop flashes red for 0.4 s, and the attacker is recorded at
   +0x24c.
4. It returns whether the prop was alive. It never changes state itself.

**Sources:**

| source | function | damage |
|---|---|---|
| Melee, including charges (`CCollisionTrack`: damage, damageMax, force, devastator) | 0x1a710 (CCollisionAction_2.iso_0001a710.cpp) | lerp(damage, damageMax, charge) × character scale (`FUN_00013f20`), doubled with a held weapon; then an impulse (`FUN_001d86d0`, guess) |
| Held prop (fight track `PropDamageTrack`: timeBegin, attachmentIndex, damage) | `PropDamageAction` 0x182310 | fixed |
| Grappled prop (`GrapplePropDamageTrack`) | 0x182380 | lerp by grapple blend |
| Thrown prop hits a prop (speed² > 25) | 0x1b1710 → 0x1da540 (CSPListener.cpp:3003) | the thrown prop's +0x230; the thrown prop damages itself by a fraction |
| Explosions (4 slots in `CCollisionManager`) | 0x1b4d00 | by distance band: small 4/9/12/15 m → 1300/1000/600/300, large 3/8/14/20 m → 7000/6000/4000/2000 (`exp_DefineProfileDamage`, damage.lua) |
| Ground shockwave (`FireGroundShockwaveTrack`, 26 params) | `ProjectileGroundShockwave` hit 0x199060 | lerp(damage, damageMax, charge) × alignment |
| Script | `tvm_DamagePropsInTriggerVolume` 0x1fd920, `spm_SetSmartPropHitPoints` 0x1dc9a0 | given |

**World hits (decals only, no health):**
- `WorldDamageTrack` (0x143b20: joint, direction, distance, damageType, scale) casts one ray.
- `WorldConeDamageTrack` (0x143df0: cone angles, startDistance, length, min/maxDecals, min/maxDecalScale,
  damageType) casts N random rays in a cone.
- Each hit goes to the dispatcher **`FUN_001f6cd0`** (src/game/hulkfight/unk_1f6bc0.GS.cpp:52). It reads the
  triangle's material and calls the location script's `Damage_<type>_<material>` (falling back to `_Generic`).
  - Damage types (enum `DAT_004c8070`): Fire, Bullet, Crush, Crack, Treadmark, Footprint, Rain, Debris, PropImpact.
  - The scripts call `CDQ_AddDecal` (0x1f6f30), `CDQ_Nearest` and `CPS_AddPS` (0x1f6e60, particles).
- A prop hitting the world (speed² > 15, 0x1b05a0) uses the same dispatcher with type PropImpact.

**Climbing and wall running do no damage.** The climb probe `FUN_0003f7b0` (CCharacter.cpp:5577) rejects smart
props unless their current state has `climbable` = true. Triangles flagged `unclimbable` are excluded (the mask bit;
the reader is a guess).

`TargetBreakTrack` (0x1725e0) only clears lock-on; despite its name it is not destruction.

### 1.3 Break states, collision, debris and effects

**From health to a new state**, each frame:
1. The `CSPManager` update (0x1e6f10) calls `FUN_001d8fc0`, which calls `StateProp::vfunc_6` (0x27e920) and then
   `FUN_001d7d50`.
2. `FUN_001d7d50` (CSPListener.cpp:375) checks health. At health ≤ 0 it fires transition type 13 ("out of hit points"
   by reading) via `FUN_0027d4f0`.
3. It reloads health from the new state's `hitpoints` attribute (0x1d5c70).
4. Callers fire event 1 when a hit leaves the prop alive. `PropDestroyTrack` (`FUN_001d6770`) walks the 13-chain to
   its end.

**The state change** is `StateProp::vfunc_16` (0x27e4c0), which calls `FUN_0027d780` (StateProp_2.cpp:1164). It:
- sets each frame controller's range and loop;
- shows or hides each drawable piece;
- enables or disables the matching joint collision volumes in the articulated sim state (`FUN_002fd4b0` →
  `FUN_00310460`).

Collision therefore changes per state by switching **pre-made joint volumes**. A state can also name a **world
collision object** (sub-chunk 0x802000C, 179 uses). Examples: armory clean → rubble collision, `buildABlock` building
→ remains, `bioRBuilding` clean → remains. That object is loaded into the state at +0x4c; the reader that registers it
with the world was not traced (guess: on entering the state).

**Debris.** A state lists sub-bodies (0x30 bytes: joint, spawn time, offset, rotation). At the spawn time,
`FUN_0027db30` calls `FUN_002fdf40`, which turns that joint's collision volumes (and a rigid body, if it has mass)
into a body attached to the prop's `PhysicsInstance`. From then on the joint follows the body. So **chunks are
pre-modelled pieces of the same prop**, simulated by the game's own impulse solver.

**Events and effects.**
- State timelines fire events (`FUN_0027cc60`) and "Effect" particles at bones (`FUN_0027dd30` → 0x27cd10).
- Element keys "StateProp" spawn a child prop (`Attached%d`, 0x1e47e0) and "Explosion" fires an explosion of size
  0-5 (`FUN_001b4620`).
- The listener `CSPListener::vfunc_0` (0x1db230) maps events to explosions, sounds (`State_%d`, "Broken"), Lua calls
  (`HandleLuaCalls`) and the scenario's "destroyed" event at the last state.
- Camera shake and dust for buildings come from Lua (`cm_CameraShake`, `em_AddWorldEffect "explosionDust01"`).
- `em_EnableDebris` (0x1f7110) only clears a flag.

**StatePropData layout** (decoded from the loader `fn_00290bf0` in
src/engine/pure3d/prop/StatePropDataLoader.new_throw.cpp; not previously in [formats/p3d.md](formats/p3d.md)):
- Header: version, name, composite drawable name, state count, and (from version 3) one more word. The drawable's
  `CollisionObject` and `PhysicsObject` are found by the same name.
- State chunks 0x8020001 / 0x8020007 / 0x8020009: name, auto-transition, out state, then the counts of drawables,
  frame controllers, events and callbacks, then the out-frame. Their children:

| id | count | record |
|---|---|---|
| 0x8020002 | 17,967 | visibility: piece name, visible |
| 0x8020003 | 7,039 | frame controller: name, cyclic, cycles, hold, min/max frame, speed |
| 0x8020004 | 3,167 | event: name, target state, event id |
| 0x8020005 | 822 | callback: name, event, frame |
| 0x8020006 | (rare) | 0x30-byte record with a hashed name and 7 words (the sub-body spawns, guess) |
| 0x8020008 | 7,688 | name pair (per state) |
| 0x802000B | 11,926 | 0x58-byte effect / child-prop element (names, offsets, a `StateProp` extension in version 5) |
| 0x802000C | 179 | world collision object by name |

### 1.4 Whole-building collapse (`killBuild`, Lua)

The building-destroyed handler lives in misc/scripts/fight/common.fig, with copies in each location's common.fig
(script content, paraphrased). On a building prop's destroyed event it:
1. makes the building's props indestructible and posts `building_destruct`;
2. generates casualties;
3. for `TimeToFall` (6 s), every 0.1 s, damages props and actors in the building's trigger volume `<prop>_tv`
   (`tvm_DamagePropsInTriggerVolume`, `am_ApplyCharacterDamage`; 500 to Hulk by default);
4. spawns 1-3 rubble props (concrete bowler, girder, concrete rubble) at random points in the central ±30% of the
   footprint, using `math.random`. A piece is skipped when its point is in the camera's view
   (`cm_IsPointInCameraView`): this is the simulation coupling noted in remaster.md 3.2;
5. drops small pieces on Hulk if he is inside;
6. adds camera shake and dust, posts `building_down`, and makes the props destructible again.

A FIFO rubble cap (`maxRubble` 25, `getRidOfOldRubble`) exists in the script but is dead code: the function is never
defined and nothing calls the spawner. The real cap is in C++: `FUN_001dcd30` marks runtime-spawned props (0x2000).
Once 64 exist, each new spawn deletes up to 5 older spawned props that are not instantiated.

### 1.5 Persistence and the save

- **`CSPManager`** holds 2,048 item slots (+0x608, 0x28 bytes each) and 2,048 records (+0x14608, 0x14 bytes:
  position and flags). Record flags: bit 0 instantiated, bit 3 persistent, 0x2000 spawned at run time.
- **Distance streaming keeps damage.** `om::Stream` (0x1e6390) de-instantiates distant props. `FUN_001e5980` saves the
  state index, the hit points (×100, capped at 65,000) and the pose into the slot.
- **Room unload forgets damage.** `FUN_00206a40` calls `FUN_001e73b0` (om/Stream.cpp:788). That de-instantiates the
  room's props and deletes every record without the persistent bit (`FUN_001e5bc0`).
- **Room load rebuilds.** `CSPManager::vfunc_1` (0x1e5f10) rebuilds the props from the room's data in their
  `InitialState`. A name that still exists (a persistent prop) is skipped, so a persistent prop keeps its state.
- **Reset.** `FUN_001e11d0` clears the whole manager. It is called from the world resets 0x86630 and 0x88b80 (guess:
  location load and mission restart).
- **The save** (`SaveMgr::FUN_0008b560`, 0xbe8 bytes per slot) holds:
  - progress, options and 100 score records;
  - two 766-bit unlockable arrays (collected comics, hints and smash collectables, whose `UnlockableIndex` then stops
    the prop from spawning again);
  - up to 50 stats and XP.
  - It holds **no world damage**. A `prop_destroy_building` stat (TBS_STATS_BUILDINGS_DESTROYED) is prepared but
    nothing found tallies it.
- **Heat** ("ers") is Lua only and not saved. Prop events carry `ers_increase` (minor 1, medium 3, major 7;
  destroying a type-4 prop adds 40); soldier and vehicle kills add 5. Level thresholds are 0/5/17/48/68, and the level
  decays over time.

### 1.6 The ground

**Representation: a static triangle mesh per room, not a heightfield.**
- Loading: `CWorldStreamManager` `FUN_002067d0` loads `<room>WorldCollision` and registers it in one of
  **19 fixed room slots** (`CCollisionManager` `FUN_001b5ec0`, CCollisionManager.cpp:2012) of the global collision
  world `DAT_00554c14`.
- A triangle's id is `(slot << 16) | face`.
- Mesh layout (`CollisionMesh` loader `FUN_003078a0`, CollisionObjectLoader.cpp:696):

| chunk | content |
|---|---|
| 0x7000003 | vertices (float3, room space) |
| 0x7000006 | faces: 3 u16 indices + u16 flags, stored as 24-byte faces with three edge neighbours |
| 0x7000748 | adjacency, plus per-edge values (guess: convexity) |
| 0x7000008 | a u16 **kd-tree** stream over 16-bit quantised coordinates (inv = 65535/extent; box query `FUN_00307060`, segment `FUN_00307240`; at most 1,024 hits a query, `DAT_00555440`) |
| 0x7000800 | unknown floats + bytes (no reader found) |
| 0x7016000 | load-time property edits: 0x7016012 `material` and 0x7016010 `unclimbable` face lists (`FUN_00201850`) |

- The face flag word holds `ignoredByNPCs`, `unclimbable`, a 5-bit `material` and `maxsize`/`propindex`.
- There are 19 materials (`DAT_004c8098`): Concrete/Brick/Glass/Metal/Ice/Wood/Dirt/Tile × wall/floor, Grassfloor,
  Hybridwall, Energywall.

**Ground queries.**
- `CollisionMesh::vfunc_17` (0x2f36c0) is the point-down query.
- `CWorldCollisionManager` (World+0x24):
  - `FUN_00201e00`: rays, with the flag mask;
  - `FUN_00201f20`: the ground below a point; this is `wcm_IntersectGround`;
  - **`FUN_00202560`**: the main ground height, mesh plus dynamic objects with normal.y > 0.5.
- Characters cache three ground results at +0x1EA8 (`FUN_00038660`; reused within 0.4 units, 0.01 for the player).
  The per-frame ground update `FUN_000418f0` (CCharacter.cpp:6446) snaps within a step height and writes the grounded
  flag and the point and normal at +0x1A39..+0x1A78.

**Landings.**
- No C++ landing handler exists. The fight graphs (.fig) choose landing moves through VelocityY, GroundDistance and
  RayCast conditions.
- `FallAction` (0x134ee0) integrates gravity with a terminal velocity of at most 200 and does no ground test.
- Effects are fixed per track: `WorldDamageTrack` decals; `FireGroundShockwaveTrack` → `ProjectileGroundShockwave`
  (0x198b30), which follows the ground with `FUN_00201f20` each step, stamps decals and damages props;
  `CCameraShakeAction` (0x16d30) shakes with fixed amplitude and no falloff.
- **No code uses fall height or impact speed.**

**Decals** (`CDecalQueue`, constructor 0x280690, in src/engine/pure3d/prop/CMotionTrail.cpp):
1. Flood-fill the collision triangles around the hit over edge adjacency: same material, normal dot > 0.5
   (`FUN_002809b0`).
2. Clip and subdivide to the decal's square (`FUN_00280be0`, `FUN_00281e60`, `FUN_00280d90`).
3. Copy the vertices 0.03 units along the normal (`FUN_0027f5f0`).
4. Draw from a 100-slot ring (`FUN_0027f4a0`).

The decal is drawn on the *collision* mesh's shape, which is why it can float over render geometry that differs.

**Navigation.**
- There is no navmesh. `CPathAgent` / `CPathGraphAgent` (0x104d00, 0x1050d0) steer in XZ toward script-set patrol
  points (`path_*`, `amb_AddPatrolPath`).
- Avoidance is ray-based (`CAvoidBehaviour` 0x109df0).
- Height always comes from the ground update, so actors follow changed ground automatically within the step height
  and the 0.5 slope limit, once their ground caches are invalidated.
- Tanks cast 100 units down at sample points, one per frame round-robin with a cache (`TankLocomotionAction`
  0x18f6d0).
- Ambient spawns use `FUN_00202560`.
- `OnBlockedTriangleCondition` (0x10d9c0) reads `propindex` under foot.

**The only run-time change to world collision is flag bits:** `FUN_001b5d20`, from `CSPManager` `FUN_001deda0`,
clears `propindex` on tagged triangles. Vertices, the kd-tree and the quantisation never change after load.

## 2. What any new system must satisfy

1. **Faithful is untouched.** Every addition is a remastered-only setting whose off state is the original
   (D232/D233). With it off, play3's checkpoint records stay byte-identical (`native_replay.py` against
   build/ckpt/play3.ckref), and the macOS and Android null records stay identical (CLAUDE.md, wand1). No game
   function's source changes. Hooks are wasm entry or site hooks (`wasm_port.GFX_APP_HOOKS`, native_hooks.h rows), as
   for tutorial_skip and draw_distance.
2. **It is a gameplay change, so it is per session** (like Aspect Ratio and Tutorial Skip). Replays, `HULK_INPUT` runs
   and `HULK_ROLLTEST` pin it off unless the test pins it on with `HULK_SETTINGS=remastered=1,<key>=1`. Netplay peers
   must share it.
3. **State that affects the simulation lives in snapshotted memory.** That means the module's arena (game heap) or a
   host section `hulk_game_state` (`__attribute__((section("hulk_game_state")))`), computed only from game state and
   frame-indexed input. Never from wall time, the renderer or host history. Then HULK_ROLLTEST round-trips across it
   and co-op rollback carries it.
   - A crater's collision patch, a fractured chunk's rigid body and the rubble list are simulation state.
   - Purely visual state (decal meshes, the debris of a visual-only fracture, dust) is runner state. It must be
     re-derivable after a restore, as `ff_gfx_restored` re-makes stale sink objects.
4. **Bit-identical floats across macOS arm64, x86-64 and Android arm64.** The sim runs in the wasm module, whose
   float semantics are IEEE and the same on every host. So the safest place for new simulation code is **inside the
   module** (a C file compiled by wasm_port like host-extra code), not the native runner.
   - Runner-side code that feeds the simulation would need the native rules of multiplayer.md 4: no FMA contraction,
     softx87 transcendentals, no host libm.
   - Visual-only fracture may run in the runner with any maths.
5. **Random numbers** come from a generator seeded from game state and kept in `hulk_game_state`. Never from
   `math.random` or the game's RNG: drawing from those shifts everything after it (cf. killBuild's view-gated spawns).
6. **Rollback depth.** Anything in the sim step costs (R + 1) times per tick under rollback. Keep the simulation-side
   work to a fraction of a millisecond a frame and put the heavy parts (mesh cutting, remeshing, GPU upload) in
   visual-only code that runs once per confirmed frame.

## 3. Performance budget on the targets

Measured today (wprof1): a gameplay update is 1-2 ms in the module on an M-series laptop. The remastered defaults cost
about 3 ms an update with two presents, and the GPU 1.5-1.8 ms at 1080p. Guesses for the slower targets: Deck-class
x86-64 roughly 1.5-2× the laptop's CPU time; Mali/Adreno handhelds 3-4× CPU and much less GPU.

| work | budget a frame (30 Hz sim) | notes |
|---|---|---|
| Crater collision patch (sim) | < 0.1 ms per landing | one patch of ≤ 256 triangles plus a small BVH, built in the module |
| Crater render mesh / decal (visual) | < 0.3 ms per landing on the CPU; once | a displaced grid of ≤ 1-2k vertices in the runner |
| Voronoi fracture of a prop (visual) | 1-5 ms per prop, spread over frames or **precomputed at load** | precompute cell sets per prop type on a worker thread, as the far-field index does |
| Plane slicing of a building section | 0.5-2 ms per cut (≤ 5k triangles) | worker thread; cap concurrent cuts |
| Rigid debris bodies (sim) | ≤ 64 active bodies; ~0.5 ms on the laptop, ~2 ms on Mali | the game's own solver caps itself; rubble is already capped at 64 |
| Debris draws | ≤ 200 extra draws, instanced | far field shows 2,900 draws cost ~1.8 ms; instance by material |
| Memory | ≤ 8 MB of sim state for patches and rubble; ≤ 64 MB visual | snapshot size is 19-37 MB today; dirty pages matter more than size |

Android sets the floor. Every new option needs a "Low" level that keeps the gameplay effect (collision patch, rubble
bodies) and drops visual extras (fine fracture, dense craters).

## 4. Options for buildings

### B1. Visual-only fracture of existing break states (runner)

At the moment a smart prop enters a `destroyed` / `gone` state, the runner replaces the authored destroyed pieces
with a Voronoi-fractured copy of the clean mesh, which flies apart and settles as visual debris.

- **Hook:** observe state changes through an entry hook on `StateProp::vfunc_16` (0x27e4c0). Get the prop's
  transform and drawable, and know its clean mesh by its prim-buffer `mdl` keys (meshpack's keys).
- **Faithful:** the game's states, collision, health and debris bodies are unchanged. The game's own debris stays
  invisible under the fractured copy (an rm pass hides the destroyed-state pieces' draws).
- **Determinism:** none needed. It is runner state; a rollback just re-plays it (or not).
- **Cost:** about 2-3 weeks for one lane. Fracture is precomputed per prop type at load: cells, cap triangulation
  (earcut.hpp, ISC), and inside faces textured with a concrete or brick material.
- **Limits:** debris cannot hit the Hulk or cars. Collision is the authored state's.

### B2. Simulated fracture for prop types (module + game physics)

The same as B1, but the chunks are real rigid bodies in the game's physics world, so the Hulk can pick them up and
throw them, and they block cars.

- **Hook:** spawn chunks as runtime smart props (`spm_SpawnSmartProp` path `FUN_001e5860`), using the game's own
  bodies, with generated `StatePropData` + `CollisionObject` + `PhysicsObject` built in the arena from the fractured
  cells.
- **Determinism:** fracture runs in the module, seeded from the prop's name and state change, so every peer cuts the
  same cells.
- **Cost:** 4-6 weeks. The risk is building pure3d objects at run time (the loaders' layouts are decoded in 1.3) and
  their memory under the 2,048-slot and 64-spawn caps.

### B3. Real-time building slicing (room geometry)

What the user asked for: cutting the city's own buildings. The obstacle is in 1.1: a room's buildings are not
objects. To make an ordinary building breakable, the remaster must:
1. **Segment** room meshes into buildings: connected components of render and collision triangles, grouped by
   footprint. Do it offline per location, into a derived "building index" kept in build/ (never committed), like the
   far-field index.
2. Give each building **health, damage and state in the module** (`hulk_game_state`), fed by the world hits the game
   already makes. An entry hook on `FUN_001f6cd0` (the decal dispatcher) receives every world hit with its damage
   type and triangle id: `(slot << 16) | face` maps to room and building.
3. **Hide** the cut part of the room mesh. Render side: an rm pass draws the room's buffers with the removed
   triangles clipped, or a replacement mesh by `mdl` key. Collision side: the room's collision faces for the building
   get a mask bit, or are swapped for a patch mesh (T2's mechanism).
4. **Fracture and collapse**: plane cuts or Voronoi at the damaged region, with structural support (a building falls
   when its supports at ground level are gone), dust, and rubble bodies (B2).
5. **Persistence** per building, beyond room unload (section 4.4).

- **Cost:** 3-6 months; the largest item on the wishlist. It needs T2's collision patching first.

### B4. Climbing and wall-run damage

- **Hook:** an entry hook on the climb update or the climb probe `FUN_0003f7b0` (each grab and each wall-run step
  gives a contact point), turned into world hits through `FUN_001f6cd0` with type Crack. That reuses the game's own
  decal and particle choice per material.
- A sim-side "wall integrity" grid per building (B3) decides when a ledge crumbles: the grab fails, Hulk drops, and
  rubble spawns.
- **Faithful:** off = no extra hits. **Cost:** 1-2 weeks for cracks (decals + particles only); crumbling needs B3.

### 4.4 Persistent rubble, clean-up and repair crews

- **Rubble that outlives its room.** A module-side table in `hulk_game_state` keyed by (location, room, building or
  prop name): damage state, rubble pieces, and a repair timer.
- **Restoring on load.** A hook after `CSPManager::vfunc_1` (0x1e5f10) puts props back into their damaged state
  (`spm_SetSmartPropState`'s path 0x1df100) when a room reloads.
- **Not on disc save.** The game's save has no room for it (1.5). Keep it in a port-side file next to the save,
  written with the save (`HULK_SAVE_DIR`), and in session snapshots for co-op.
- **Clean-up crews and repair actors** are new characters. They can be the game's own ambient types driven by patrol
  paths (`path_*`, `amb_AddPatrolPath`) to the rubble, removing pieces (`spm_RemovePropInstance`) or stepping repair
  states back (`spm_SetSmartPropState`) over time. Attacking them feeds the ers heat, which is Lua. Run them through
  our own Lua via `sh_DoString` (0x1d3f00), as tutorial_skip does. Scripting the game's own systems keeps the AI
  faithful to the game's feel.
- **Cost:** a persistence table alone, 1-2 weeks; crews, 3-4 weeks after it.

## 5. Options for terrain

### T1. Crater decals scaled by fall height (visual, plus the game's own decal)

At a landing, record the Hulk's fall height (the y at the jump's apex or last grounded point, minus the y at landing)
and his vertical speed.

- Through the game's decal path: call the game's `CDQ_AddDecal` / `FUN_001f6cd0` with a larger scale. This changes
  the game's decal ring, which is game state, so it is per session.
- Visual only: draw a crater as a displaced, textured disc in the runner, conformed to the ground by ray samples taken
  in the module.
- **Hooks:** the ground update `FUN_000418f0` gives the grounded transitions per character; the Hulk is world +0x20
  (tutorial_skip's path).
- **Cost:** 1 week.

### T2. Crater decal + local collision dip (the recommended first prototype; section 7)

A crater also changes the ground: the Hulk and enemies stand lower in it, cars dip in, thrown objects roll into it.

- **Representation:** per crater, a small patch mesh (a radial grid of ~150-250 triangles) over a disc of radius r,
  displaced by a crater profile (bowl plus rim), conforming to the original ground at its edge. It is stored in
  `hulk_game_state` (centre, radius, depth, seed; the mesh is rebuilt from those).
- **Collision:** the ground queries are wrapped. An entry hook on **`FUN_00202560`** (main ground height) and on
  **`FUN_00201f20`** (`wcm_IntersectGround`) checks the point against the active craters first (a 2D grid of crater
  discs): inside one, it returns the patch's height and normal under the point, and its material (Dirtfloor or
  Concretefloor).
  - Downward rays (`FUN_00201e00`) get the same treatment.
  - The mesh-level `CollisionMesh::vfunc_17` (0x2f36c0) is the deeper hook if objects query it directly.
- **Cache invalidation:** a new crater clears the character ground caches (+0x1EA8, 3 slots) within its radius, and
  tank caches.
- **Physics bodies** (thrown cars, debris) collide through the solver's contact generation against the room mesh, not
  `FUN_00202560`. The first prototype leaves them on the original surface (they float over the bowl). A later stage
  registers the patch as a `CollisionMesh` in a spare collision slot (19 slots, at most ~10 used: to be measured) with
  the original faces under it masked out. The kd-tree is built offline, so the patch needs a tiny tree of its own
  (one leaf for ≤ 256 faces works within the 1,024-hit buffer).
- **Rendering:** an rm pass draws the crater mesh with the ground's texture (the triangle's material and the room's
  prim group under it: the far field's position index finds the room buffer) plus a crack decal. A bowl lies below
  the original surface, so drawing it over the ground is not enough: a stencil pass marks the crater's disc as a hole
  in the ground's depth, then the bowl is drawn into it.
- **Roads:** the same patch with Concretefloor and an asphalt-crack decal set.

### T3. Deformable ground everywhere (height patches per room)

Every room's ground faces (Dirt/Grass/Concrete/Tile floors with normal.y > 0.7) get an adaptive height layer: a
height grid per room tile (e.g. 0.5 unit cells, deltas only, sparse), in `hulk_game_state`.

- Craters, footprints, tank tracks and shockwave furrows write into it. Collision and render read it.
- Rebuilding a room's collision tile means a new patch mesh per dirty tile (≤ 32×32 cells) and its tree.
- AI follows automatically (1.6), but deep trenches would trap patrol paths. The path agents need ray checks for
  slope > 0.5.
- **Cost:** 2-3 months. Memory: 4 bytes a cell with deltas only, sparse; a busy downtown fight might write a few
  hundred tiles (< 4 MB).

### T4. Voxel terrain

Outskirts terrain as voxels (dig, tunnels). It replaces the original collision and look wholesale, so it is out of
scope for a faithful-based remaster. Not recommended.

## 6. Staged plan

| stage | content | size (one lane) | depends on |
|---|---|---|---|
| D0 | this research | done | |
| **D1** | **crater prototype (T2 without physics bodies)**: fall-height tracking, crater record, ground-query wrap, render pass, setting row | **2-3 weeks** | |
| D2 | B1 visual fracture of 3-5 prop types (streetLight, busshelter, waterTower3, billboard, phoneBooth) | 2-3 weeks | |
| D3 | climb / wall-run cracks (B4 decal part); shockwave furrows on T2's patches | 1-2 weeks | D1 |
| D4 | T2 stage 2: patches in the physics world (bodies roll into craters); roads | 3-4 weeks | D1 |
| D5 | persistence table for props, rubble and craters across room reloads and saves | 2 weeks | D1, D2 |
| D6 | B2 simulated chunks | 4-6 weeks | D2 |
| D7 | building index (segmentation) + B3 slicing of one building class | 2-3 months | D4, D6 |
| D8 | clean-up and repair crews | 3-4 weeks | D5 |
| D9 | T3 height layer | 2-3 months | D4 |

## 7. Recommended first prototype (D1): craters from big landings

Small enough for one lane, visible, and it builds the hook and state pattern every later stage needs.

1. **Setting:** `craters` (Gameplay Options > Landing Craters: Off / On), remastered-only, off in replays and tests
   (port_settings.c row).
2. **Detection, in the module** (src/platform/wasm, a C file in `hulk_game_state`):
   - An entry hook on UpdateSimulation 0x88c30 (tutorial_skip's hook) reads the Hulk (world +0x20) each update: the
     grounded flag +0x1A39, the position, and the vertical velocity.
   - It tracks the apex since the last grounded frame.
   - On an airborne → grounded transition with fall height h ≥ h0 (e.g. 15 units; tune by observing the game's big
     leaps), it makes a crater with radius = clamp(k_r · √h, r_min, r_max) and depth = clamp(k_d · √h, 0,
     0.35 · radius). The root: impact energy grows with h, and crater size like a root of the energy.
   - Only on floor materials (Dirt/Grass/Concrete/Tile floor, normal.y > 0.8), read through the ground query.
   - At most 32 craters live, oldest first out, and new craters merge into nearby ones.
3. **Collision:** entry hooks on `FUN_00202560` and `FUN_00201f20` return the crater's height and normal inside the
   disc. Invalidate the ground caches of characters within the radius. Actors walk into the bowl and out.
4. **Render:** an rm pass draws each crater's bowl mesh after the room draws. The mesh is built in the runner from the
   crater record and the ground samples the module wrote, textured from the room draw under it plus a crack decal.
   A stencil cut hides the flat ground inside. Dust and shake come from the game's own effects
   (`em_AddWorldEffect` / `cm_CameraShake` through `sh_DoString`), only on the landing frame.
5. **Tests:**
   - play3 with the setting off: records byte-identical.
   - A `HULK_INPUT` free run with `HULK_SETTINGS=remastered=1,craters=1` from a save at a big leap: the same game
     hash on macOS and Android.
   - `HULK_ROLLTEST` across a crater's creation.
   - A screenshot of the bowl.
6. **Out of scope for D1:** physics bodies and cars against the bowl, persistence beyond the room's residence (a
   crater lives until its room unloads, as the game's own damage does), and AI path changes.

## 8. Decisions for the user

1. **Gameplay or looks first?** D1 (craters that change where you stand, so per session and shared in co-op) or D2
   (visual-only fracture, no simulation change, so it can be on in any session).
2. **Generic buildings.** Breaking the city's ordinary buildings (B3) is a large project: the game never had it, and
   it needs a derived per-location building index plus new structural collapse. Go, or limit fracture to the
   ~250 smart-prop types and the ~30 building props the game already breaks?
3. **Persistence scope.** Within the session only, or written beside the save (a port-side file, not the game's
   save)? Rubble kept across room unloads changes the game's streaming budget assumptions (64 spawned props).
4. **Physics library.** Keep the game's impulse solver for new bodies (faithful feel, same determinism as now), or add
   Jolt (MIT; cross-platform determinism behind `JPH_CROSS_PLATFORM_DETERMINISTIC`, ~8% slower, wasm supported)
   for debris and rubble only? Two solvers in one world means debris cannot push game objects unless bridged.
5. **Fall-height scaling also of damage?** Should a big landing's shockwave damage scale with height too, like the
   crater? (The original never scales it.)

## 9. Open questions and what was not verified

- The reader of a state's world collision object (0x802000C, state +0x4c): when it is registered with the world.
- The meaning of transition types 5, 9, 10 and 13 (13 = out of hit points, by reading) and of `PhysicsInstance`
  state 2.
- Which room id runtime-spawned rubble gets (it decides when rubble disappears).
- How many of the 19 collision room slots are used at once (sets the headroom for crater patches).
- Whether physics bodies ever query `FUN_00202560`, or only contact generation against the mesh.
- Chunk 0x7000800 in collision meshes; the per-edge values in 0x7000748.
- The game's big-leap fall heights (to set h0): measure in a free run (`HULK_TRACE_WATCH` on the Hulk's y, or the
  module hook's log).

## Libraries (general technique only; licences checked on the projects' pages)

| need | library | licence |
|---|---|---|
| polygon capping after a cut | earcut.hpp (mapbox) | ISC |
| Voronoi cells for fracture | voro++ (LBNL) | modified BSD |
| deterministic rigid bodies (optional) | Jolt Physics | MIT |
| navmesh, if path agents ever need one | Recast/Detour | zlib |
| noise for crater rims and cracks | FastNoiseLite | MIT |

No NVIDIA material (CLAUDE.md clean-room rules). GPL projects are not used.
