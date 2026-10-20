# What to play next: the equivalent/ functions no recording has run

The trace sessions (`tr1*`, the play3 runs) ran 2,372 of the `equivalent/` functions at least once and replayed
3,300 of them. **1,867 never ran in any session** (`replay_status: not_reached` in `build/equiv-confidence.json`,
565,087 bytes). This page says why, which of them a player can reach, and what to play to reach them.

Regenerate everything with `build/venv/bin/python tools/reach.py` (needs `build/equiv-confidence.json`,
`build/rtti.json`, `build/tree/manifest.json`, `docs/lua-bindings.csv`, the local XBE, and the gate's census exported
to `build/reach1/census.json`). Per-function results (class, evidence, referrer chain, trigger group) land in
`build/reach1/classes.json` and `build/reach1/triggers.json`; nothing there is committed.

## Method

A call graph over the whole `.text` (direct calls and jumps, any immediate or displacement operand that names a
function, fall-through into a split body) plus the data side: every vtable (from RTTI) and every cluster of pointers
in `.rdata`/`.data` (function-pointer tables, registration tables) is a node. Roots are the entry point and every
function the trace census saw run. A vtable is live when some live function mentions its address (a constructor), and
then all of its slots are. Each unreached function is classed by what reaches it:

| Class | Meaning | Functions | Bytes |
|---|---|---:|---:|
| R | The census saw it run, but the gate captured no call (not a play question; a capture problem) | 194 | 76,000 |
| a | Dead: nothing in the image refers to it | 317 | 57,711 |
| b | Dead: referred to only by dead code or data (176), only by Lua bindings no shipped script calls (55), or only through debug code (7) | 238 | 64,401 |
| c | Failure path: reachable only through functions whose strings are error messages | 44 | 12,902 |
| d | Gameplay or content gated, with a named trigger (class, Lua binding or registry name) | 843 | 280,579 |
| e | Live-reachable but no identifiable trigger (mostly unnamed library and engine internals) | 231 | 74,494 |

So **551 functions (a+b, 122 KB) are unreachable in the retail game** and 44 more are failure paths; **1,074 (d+e)
are reachable**. Of those, about 720 map to something a player does; the rest (about 355) are library internals
(Lua VM and libraries, libpng, printf, allocator), image-format loaders, or shader and render variants that only
matter if the shipped content uses them. 194 of the 1,867 (class R) will not move by playing; they need a different
capture fix.

Caveats. Virtual dispatch is over-approximated (a live vtable makes every slot live), so class a/b is a lower
bound on dead code. Class c is string-based (a function counts as an error handler when most of its strings read as
errors), so treat it as indicative. A Lua binding counts as unused only when no shipped script names it; a name built
at run time would be missed. Trigger groups come from the class or translation unit a function belongs to, not from a
traced path, so "play X" below means "X exercises the code this group names", not a guarantee.

## What the dead code is

* **a (317)**: Bink callbacks and a few sound/camera/HUD helper methods nothing calls (`CCameraManager` 18, Bink
  callbacks 18, a path-planning unit 16, `SpotLight` 9, `ScriptHandler` 7, `HUDOverlay` 7, ...). Compiled in, never
  referenced.
* **b (238)**: 55 are Lua bindings that exist but that no shipped script calls (27 of them in the actor-manager
  binding unit, `am_*`), 176 are helpers below dead code (the `DebugConsole`, spare physics-joint and particle
  loader variants, sequencer events no sound data uses), 7 are under debug code.
* **DebugConsole** is covered in its own section below.

## Checklist

Ordered by functions covered per minute of play (minutes are my estimates for a careful run; counts are from
`build/reach1/triggers.json`). "?" marks an item whose trigger is a guess.

| # | Do this | Functions | Est. min | Per min | Needs |
|---|---|---:|---:|---:|---|
| 1 | Front end tour: open every screen, scroll lists, change every option, open the cheat entry screen and type a code, open Stats/Unlockables, accept and dismiss pop-up dialogs | ~115 (widgets 71, cheats/unlocks 31, HUD 12) | 6 | 19 | fresh game |
| 2 | Memory card: save a new game, overwrite it, load it, delete a save, choose "continue without save", "retry" and "free more blocks" if offered | 42 | 6 | 7 | fresh game, ends with a save |
| 3 | Throw many different props in a fight (car, barrel, rock, building chunk), pick up and drop, throw while holding a weapon-type prop | 68 | 5 | 14 | a mission with props |
| 4 | Take a long beating and deal a lot of hits: heavy hits, wall slams, knockback into walls, objects thrown at enemies, hits while enemies are airborne, enemy block | 53 | 4 | 13 | any combat |
| 5 | Grapple moves: grab, throw, swap, drain-health grab, "opportunity" (ball) grabs, drop | 40 | 4 | 10 | any combat, ideally late-game moves |
| 6 | Turn subtitles on and watch two or three cutscenes/dialogues | 13 | 2 | 6 | options menu |
| 7 | Ragdolls and big physics: knock many enemies/civilians flying, destroy vehicles and walls | 59 | 6 | 10 | destruction-heavy mission |
| 8 | Camera: watch every cutscene (NIS), trigger scripted cameras and the hypnotic cam, change zoom/chase cam | 23 | 4 | 6 | mission-dependent |
| 9 | Special moves: charge, jump attack, ground slide; enemies firing missiles, projectiles or beams; shockwaves; ball-and-chain; teleporting and surf enemies ? | 32 | 8 | 4 | later missions |
| 10 | Flying and helicopter enemies: shoot down helicopters (death spiral), fight enemies that dash and strafe in the air | 28 | 6 | 5 | missions with helicopters |
| 11 | Enemy and civilian variety: melee enemies that evade (hand-to-hand agent), patrol paths, formations, civilians in crowds, enemies fleeing or chasing | 129 | 15 | 9 | several missions |
| 12 | Trigger volumes, scripted events, mission start/end, level transitions (world streaming), mission timers | 48 | 8 | 6 | several missions |
| 13 | Different locations and times of day: particles, motion trails, billboards, light types, toon/lightmap/bump shaders | up to 172 ? | 20 | 8 | many locations |
| 14 | Music and dialogue variety: fade, mute and stop events, streaming-buffer pressure (quick mission restarts) | 70 | 8 | 9 | many missions |

Missions the shipped scripts tie to bindings that never ran (from the Lua listings, IDs only; check against your
own play log, since I cannot tell from here which ones play3 visited):

* civilians (`amb_CreateCivilian`, 19 scripts): `c03m04`, `c05m01`, `c10m20`, `c10m30`
* smart-prop spawning (`spm_SpawnSmartProp`, 16 scripts): `c00m01`, `c01m02`, `c01m04`, `c01m05`, `c02m02`, `c03m02`,
  `c03m04`, `c04m01`, `c04m02`, `c06m01`, `c06m03`, `c10m05`, `c10m23`, `c10m32`, `c10m34`
* trigger-volume damage (`tvm_DamageAllActorsInTriggerVolume`): `c02m04`
* the field-goal minigame (`hack_IsFieldGoal`): `c10m39`, `c10m45`
* chase-cam distance changes (`cm_SetChaseCamBaseDist`): `c10m37`, `c10m41`, `c10m42`
* `c01m05` and `c10m39`/`c10m45` call the most unrun bindings of any mission.

The front end and gameplay groups that matter most, with the evidence behind each:

* **Memory card (42)**: `FEMemCardControl` (23) shows load, delete, "free more blocks", "continue without save" and
  "retry" menu strings; the other 19 are the save-drive and file-request layer (`XboxSaveDrive`, `InstanceDrive`,
  `XboxDrive`, `Drive`). The drive layer includes failure handling; whether xemu's virtual disk can produce a full or
  unreadable save drive is untested ?.
* **Cheats and unlocks (31)**: `unk_0b4cf0` has strings for unlocked cheats, `TBS_CHEAT_CHARACTER`, `TBS_CHEAT_HULK`
  and the story and side mission selectors; `CFEManager` has "Moves unlocked" and generic dialogs;
  `CGameFlowManager` has the mission score/complete strings; `CStatsManager` and `CUnlockablesManager` are the
  experience and unlock screens. `FETextInput` (3 functions) has an `enter_code_text` string, so a code-entry screen exists.
* **Subtitles (13)**: all in `CSubtitleManager`, so one subtitle-on playthrough of dialogue covers the group.
* **Moves**: the grapple group is dominated by `GrappleThrowAction` (7) and `CGrappleOpportunityTrack` (5); the
  special-move group by `WorldConeDamageAction`, `GroundSlideAction`, `MissileThrowAction`,
  `ProjectileGroundShockwave`, `CJumpAttackAction`, `TeleportAction`, `SurfAction`, `BallAndChain*Action`,
  `FireBeamAction`. These are fight-system actions registered by name (`ballAndChainShoot`, `fireBeam`, `groundSlide`, ...);
  the `.fig` files hash those names, so which character or mission uses each is not recoverable from the data here.
  I do not know which enemy uses surf, teleport or the beam ?.
* **Flying (28)**: the helicopter death spiral (`CHeliDeathSpiralAction`), `Flying{Brake,Dash,AutoTarget}Action`, and
  the strafe/steer drivers.
* **Camera (23)**: 14 in `CCameraManager` (script cameras, `cm_*` bindings), plus the chase, NIS and animated
  cameras.

### Not worth play time

* **Failure paths, class c (44)**: Lua error and format-checking paths (`invalid format`, `bad argument`, resume
  errors), libpng error text, an "unknown error code" screen (`0x001bb0b0`) and a `TBS_STOP_PIRATING` screen
  (`0x001b8b60`) that only the error screen reaches. Not reachable by normal play; a corrupt save or read error
  might hit a few of them ?.
* **Library internals, class e (231)**: Lua VM and libraries (`unk_212bb0`, `unk_338d90`), `unk_2699f0` (allocator
  paths, probably), libpng row/IDAT code, printf and math. They run only if scripts or data exercise rare library
  options. Cheaper to cover by fuzz or by a unit test than by play.
* **Image loaders (70)**: BMP, Targa, PNG, 32-bit image handlers run only if the data holds those formats. The
  shipped files likely do not ?.

## DebugConsole (task lead)

`core::DebugConsole` (`src/engine/core/DebugConsole.cpp`, 9 functions here, 8 in class b) is a socket-based remote
console server (a state machine over a stream/socket helper layer; I did not trace the transport further), not an
in-game cheat or debug menu:

* A singleton client (`core::ConsoleClient`, pointer at `0x5283b0`) is created by `FUN_0026e9e0`, which allocates
  `0x1d8` bytes, and a per-frame tick (`FUN_0026ed70`, called every frame through `FUN_0008db00` from `FUN_00087630`) runs its
  state machine (setup with the constant `0x100b`, then states 1 to 3: connect/accept, read a framed message,
  dispatch it by type). `DebugConsole`
  is a thin printer/command object that links itself into that client's list.
* The only caller of `FUN_0026e9e0` is the `DebugConsole` constructor (`FUN_0026ed80`), and **nothing in the image
  calls that constructor or refers to its address** (no direct call, no data pointer). `0x5283b0` is zero from boot,
  so the per-frame tick returns at once. The 8 unreached functions are the constructor, destructor path and the
  message/command handlers behind it.
* No flag, global or button combination in the retail code turns it on; it would need a code change to construct
  one. Its message types (9, 10, 11) route to text output and the registered client callbacks; there is no table
  of game commands behind it and nothing that spawns enemies or vehicles.
* The Lua global `cdebug` (bound at `0x001d2020`, called by 106 scripts) is unrelated: it is an ordinary script-side
  call wrapper. Its 19 attributed functions in the reach data are Lua library internals, not debug features.

## Splitting into recordings

Each recording keeps its saves on its own qcow2 overlay. A later recording that needs an earlier save must start from
an overlay that already contains it; a save made in recording 1 is invisible to recording 2 unless 2 is started from
1's overlay.

1. **Recording A, 25 min, fresh game, no prior save**: items 1, 6 and 2, then a short opening mission for 3-5.
   Ends with a save. Covers about 250 functions; the memory-card items must happen here or from an overlay copy of
   this one.
2. **Recording B, 30 min, starting from A's overlay (it has the A save)**: load that save (this also exercises the
   load path with a pre-existing file), then missions covering items 3-5, 7, 8 and the civilians/props missions
   (`c03m04`, `c05m01`; `c01m05`). If the cheats/mission-selector screen offers a jump to arbitrary missions
   (`mission_selector`, `story_mission_selector`), use it here instead of grinding to a later save ?.
3. **Recording C, 30 min, needs a later save (or the mission selector)**: items 9, 10, 11, 12, 14: a helicopter
   mission, a late mission with special-move enemies, and the field-goal minigame (`c10m39`/`c10m45`). If no later
   save exists, build one in B and carry B's overlay forward.

Item 13 (location and time-of-day variety) is cheap to add to any of them by choosing different missions.

## What this will not fix

* Class R (194): the gate saw these run but captured no replayable call; replaying more play will not change that.
* Classes a and b (551): unreachable in retail; they can only be proven by fuzz, so they stay tier 1.
* Class e library internals (231): see above.

Realistically about 700 of the 1,867 are worth chasing by play, and a fair share of those need specific enemies or
missions whose names I could not tie to a function from static analysis alone.
