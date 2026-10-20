# Quality-of-life ideas: research notes

Brainstorm plus read-only research for four areas: skipping missions, faster city travel, new moves, new
weaponizables. Nothing here has been run or implemented. Addresses are from `matches/` and `equivalent/`;
names like `f28` and `FUN_*` are decompiler stand-ins, and where a meaning is inferred the text says so.
These are changes for the native port (see [`roadmap.md`](roadmap.md)), not the byte-matched Xbox build.

## Summary

| Area | Feasibility | Why |
|---|---|---|
| Landing-jump momentum | **Good**: first to try | Jump physics is two readable functions; hook points are identified |
| Skip FMVs / fast retry | **Good** | Existing flags and entry points, little new logic |
| Skip a mission | **Medium** | Story state is clear, but where rewards are granted is not yet traced |
| More weaponizable props | **Blocked on `.fig` writer** | Mostly data, but the data container can't be written yet |
| New moves | **Blocked on `.fig` writer**, plus new C++ for new primitives | Moves are `.fig` graphs composed from compiled action/track classes |

The common blocker for the last two rows: `.fig` framing (record headers, hashes, parameter blocks) has no
writer ([`lua-scripts.md`](lua-scripts.md) around line 366). Reading and reusing existing nodes works; authoring
new ones needs that container reverse-engineered.

---

## 1. Travel: landing-jump momentum (bunny hop)

### How jumping works today

Movement is data-driven. Tunables live as floats and curves inside "track" objects loaded from script/XML;
"actions" run them. The track registry (`matches/0x00073700.cpp`) names `jump`, `jumpAttack`, `wallJump`,
`wallRun`, `fall`, `bounce`, `groundSlide`, `locoSprint`, `locoSteer`, `airToGroundTarget`, `locomotionState`.

- **Takeoff**: `CJumpAction::vfunc_6` (`equivalent/0x00013b90`). Creates a joint driver "jump", plays the
  animation, reads `speed = stats->FUN_0003ec00(0)` (a 0..1 one-shot value at stats+0x1e58, probably a charge
  or run-speed fraction), then reads three curves from `CJumpTrack` via `FUN_0006b540`, `FUN_00069210`,
  `FUN_000692c0`. Each interpolates min..max by `speed`. Their arithmetic suggests launch speed `2h/T`,
  horizontal speed `distance/T` and gravity `2h/T²` (inferred). The results go to `FUN_00099d20`. If
  `speed >= 1.0` and the mount's `out.y > 100`, it fires the `StartChargedJump` event.
- **Airborne tick**: `CJumpAction::vfunc_7` (`equivalent/0x00018d40`). Vertical velocity `f28 -= dt*f30`, heading
  steered toward the stick with a turn limit, root moved by `(f2c*dt, f28*dt)`. Meanings of `f28/f2c/f30` are
  inferred.
- **Landing**: the end of `vfunc_7`: `if (f28 < 0 && chara->v30()) return false;` (line 202). `v30()` is
  presumably "is grounded". Returning false ends the jump action; that is the landing transition.
- **No input buffering exists.** Searches for jump/input buffer, coyote time, queue time found nothing. A
  press just before touchdown is probably lost, so a hop window needs adding rather than tuning.
- Wall jump (`WallJumpAction::vfunc_3`, `equivalent/0x00140650`) uses the same `speed` scaling, so it can share
  a bonus.
- No glide found. Fall damage/landing stun has no dedicated named function (`stunTime`, `stunAnimation`,
  `airToGroundTarget` strings exist, untraced).

### Proposed design

1. In `vfunc_7` at the landing return, record the landing time and horizontal speed `f2c`.
2. In `vfunc_6`, if the previous landing was within a short window (start around 6 to 10 frames), boost either
   the `speed` fed to the three curves, or `f2c` directly, by a bonus that decays with the chain.
3. Make the window and bonus new tunables near the jump code rather than editing `CJumpTrack` data.
4. Optional: a small cue (dust ring or flash) on a well-timed hop; a chain multiplier with a cap that resets on a
   normal landing or hit.
5. Optional, after the above works: also hook wall-jump takeoff.

### Open questions

- What `FUN_00099d20` (where launch velocity enters physics), `FUN_000357a0` (stick-aligned input velocity) and
  `v30` actually do. Read these before writing the change.
- Whether a boost on `speed` is clamped downstream, and whether charged-jump effects (`StartChargedJump`,
  camera, sound) should fire on a hop.
- Whether landing resets velocity elsewhere (the landing stun path) before the next jump can read it.
- Verify the inferred variable meanings with a trace in the hybrid build before relying on them.

### Other travel ideas (not researched)

- Fast travel to unlocked jump markers. Jump markers exist (`gfm_AddJumpMarker` 0x89920,
  `gfm_GetNextJumpMarkerLocatorName` 0x89a00, `um_SetupUnlockableJumpMarker` 0x92fd0,
  `um_GetJumpMarkerLocatorName` 0x93260, `CUnlockableJumpMarker`) but they look like collectible and select
  UI, not movement; teleport would need a trace of the selection flow (`JumpMarkerSelected`).
- Landing roll or slide that converts fall speed into run speed (touches the stun path above).
- Sprint boost on wall runs (`LocomotionSprintAction::vfunc_3` 0x163ed0, `WallRunAction::vfunc_3` 0x142990).
- Better objective arrows and distance readout (`hud_*ObjectiveArrow*` bindings exist).

---

## 2. Skipping missions

### How mission flow works

- 78 missions, ids `cNNmNN` (chapter 10 holds the side missions). Each has `_init.lua`, `<id>.lua` (just
  spawns the player), `_scenario.fig`, `.dh`, `.rdl`, `.p3d`. The logic is in the `.fig` as compiled
  Lua condition/track/action chunks calling `sm_*`, `hud_*`, `snd_*`, `am_*`. **There is no per-mission "win"
  function to call.** A skip has to drive the same state transitions from C++.
- `sm_SetMissionState` (0x1cc620) takes a screen/state code. 2 is failure (shows `story_mission_fail` or
  `side_mission_fail`), 3 is success (calls `FUN_001cc600(0)` then shows `story_mission_success` or
  `side_mission_success`), 6 `mission_accept`, 7 `jump_marker_select`, 12 `fe_StartNextMission` (0xbc750).
- Objectives (`sm_SetMissionObjectiveState` 0x1ccfc0, `sm_SetMissionObjective` 0x1ccf70) are plain data with
  no side effects.
- Progress lives in `CGameFlowManager`: 100 entries of 0x18 bytes (8-byte hash of the id plus a state
  string: "locked", "complete", "info") at +0x158/+0x160. `gfm_SetMissionProgressSimple` (0x89f00) sets one;
  `gfm_GetNextChapterMissionToComplete` (0x8abc0) walks the 35 story ids at 0x3ffde0 and returns the first not
  complete or locked.
- Unlocks: `CUnlockablesManager` holds 32 mission-unlockable slots at +0xd90, each with a "cNmN" key and up to
  16 unlockable indexes (valid range under 0x2fe). `um_AddMissionUnlockable` (0x92c80),
  `um_SetUnlockableOn` (0x92e00), `um_SetUnlockableLocked` (0x93db0).
- `-level <name>` reaches `CGame::ApplyStateChange` (0x873a0) case 1 and starts a "oneshot" mission, bypassing
  story state. It is a debug jump, not a skip.

### Proposed design

Skip = call `sm_SetMissionState(3)` first and see what the success path already grants; if rewards come from
that screen or `FUN_001cc600`, a skip is nearly free. Fallback: mark the mission complete with
`gfm_SetMissionProgressSimple(id, "complete")`, grant the matching `um_AddMissionUnlockable` slot's
unlockables, then set the next mission with `gfm_GetNextChapterMissionToComplete`.

Frontends for it, cheapest first: a "Skip mission" entry on the failure screen (after N deaths, no medal), a
pause menu entry, a mission-select screen from the world map.

### Open questions (do these before building)

- Trace the callers of `sm_SetMissionState(3)` and the `story_mission_success` screen to find where stat
  tallies and rewards are applied. This decides how big the feature is.
- How "complete" propagates to chapter and location unlocks and to saves ([`native-files-saves.md`](native-files-saves.md)).
- `gfm_UnlockAllStoryMissions` (0x89ab0) and `gfm_IsStoryModeComplete` (0x893c0) appear to touch the same byte
  at +0xabf; likely a misread, check before using either.
- Whether skipped missions should be marked distinctly so medals and completion stats stay honest.

### Cutscenes, dialogue, retry

- FMVs: `CFMVManager::QueueMovie` (0x1b7310) takes a skippable flag (1 for all boot movies).
  `fmvm_GetUserSkippedLastTime` (0x1b6f00) returns a byte at +9; the code that sets it is not found yet.
  Likely a button hookup once the writer is found.
- In-engine cutscenes (`nism_*` 0x1bb990, `cm_SetScriptCam*` 0x9dd20) are script-driven; skipping needs a hook
  in the NIS manager, untraced.
- Dialogue: `snd_PlayDialogue` (0x1eb740), `snd_AddCommand_PlayMissionDialogueEvent` (0x1f17f0). No skip path
  investigated.
- Retry: `sm_SetCheckpoint` (0x1cc910) and `sm_GetCheckpoint` (0x1cc900) look like the checkpoint hook;
  `fe_restart` (0x861f0), `fe_exitSim` (0xbf450). The restore path is untraced.

---

## 3. New moves

### How moves are defined

- A "move" is a node graph in `.fig` (`scripts/fight/hulk.fig`, `common.fig`, per-character `_ai.fig`),
  loaded through `am_LoadFightScript` (0x24480), composed from compiled action and track classes. About 98
  `fight::` action/condition classes exist (`CGrabAction`, `CGrapple*`, `CSmartProp*Action`, `CRageModeAction`,
  `CComboTimerTrack`, ...), declared in `include/gen/global.h` and `fight.h`.
- Hulk's move tree has not been decoded here, and it is unknown whether nodes are keyed by name or hash.
- Charge-move strings: `jump_stomp_charge` (0x40d294), `jump_punch_charge` (0x40d2a8), `jump_gamma_charge`
  (0x40d6b0). Consumer untraced.
- Unlocking: `um_SetupUnlockableMove` (0x92ef0) fills table slots for ids 0x266..0x2c9 (about 100), and
  `um_SetupUnlockableMoveFEOrder` (0x92f70) orders them in the front end. The list is Lua-driven but capped by
  that id range. `fe_GetSelectedMove` (0xb43e0) feeds the move menu.
- Combo counting (`sm_Combo*`, binding block 0x1cfb20): the counter logic was not located.

### Paths to a new move

1. **Recombine existing actions** in `.fig`: no new C++, needs the `.fig` writer.
2. **Lua hooks**: `LuaCondition`, `LuaTrack`, `LuaAction` chunks can call bindings, so a Lua-driven behaviour
   may be possible without the writer if a node can be pointed at one. Unverified.
3. **New primitive** (a new Action/Track class): C++ plus factory registration
   (`ConditionFactoryTemplate`, `CasterTemplate`), and still a `.fig` node to use it.

### Ideas, ordered by likely cost

- Air dash, built as a variant of the jump code in section 1 (no `.fig` needed if it lives in `CJumpAction`).
- Slam-jump: a landing slam that launches upward, chaining with the hop window.
- Perfect dodge / counter, sprint tackle, charged clap shockwave: new primitives plus `.fig` nodes.

---

## 4. New weaponizables

### How weaponizing works

- Props carry `weaponizable_type` (0x422c04) and `weapon_type` (0x422c18) keys in smart-prop data, plus
  `target_priority`, `hitpoints`, `electrified`.
- `.fig` conditions gate moves on the held prop: `CSmartPropWeaponizableTypeCondition` (vftable 0x3f7130),
  registered as `smartPropWeaponizableType`; related keys `matchWeaponizableType`, `weaponType`, `isCargo`,
  `objectClass`, `isThrown`, `atRest`, `collided`, `missiles`. The enum list is
  `fight::ParamEnumConstList<CSmartPropWeaponizableTypeCondition>` (vftable 0x3f7b28), backed by a table
  (`gTable_49250`, `matches/0x00049250`). Enum names and values are not decoded.
- Lua: `spm_GetSmartPropWeaponizableType` (0x1e32b0), `spm_GetSmartPropWeaponType` (0x1e3360),
  `am_GetPropAttachedWeaponizableType` (0x2a2b0). Grab, throw and attach logic is probably in `CGrabAction` and
  `CSmartProp{Attach,Detach,Drop,Throw,Throwing}Action`; untraced.
- Damage tuning is `scripts/damage.lua` (runs at startup after init and physics); contents undocumented.

### Paths to a new weaponizable

- **Data only** (cheapest): give a new prop an existing `weaponizable_type` value so existing `.fig` grab,
  swing and throw nodes already apply. This depends on how props are authored and loaded; the prop data is in
  `.p3d` files the repo can already read ([`tools/p3d.py`](../tools/p3d.py)).
- **New enum value**: extend the table behind `gTable_49250` and the `ParamEnumConstList` array (code and data
  patch), plus new `.fig` nodes (needs the writer).

### Ideas

More props that reuse existing types (lamps, mailboxes, hydrants, containers), tuned in `damage.lua`; then
environmental combos (explosive props), dual wield, and durability, which need new actions.

---

## Suggested order

1. **Landing-jump momentum.** Read `FUN_00099d20`, `FUN_000357a0` and `v30`, prototype in the hybrid build,
   tune the window.
2. **FMV skip.** Find the writer of `CFMVManager+9`.
3. **Mission skip.** Trace `sm_SetMissionState(3)` and the success screen, then prototype the skip on one
   mission and check the unlocks.
4. **Decode `.fig`** write support. This unblocks new moves and weaponizables and is worth its own task brief
   in [`tasks/`](tasks/README.md).
5. **Reuse-only weaponizables** by re-skinning props to existing types.

## Caveats

- Research was reading decompiled code only; no game run, no trace. Confidence is medium for the movement
  section, moderate for missions, and medium-low for the moves and weaponizables data/code split.
- Many names above are reconstructions (`FUN_*`, inferred field meanings); check against traces before
  committing to a design.
