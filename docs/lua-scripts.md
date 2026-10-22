# Lua scripts: format, bindings, load path

Groundwork for adding missions and areas. Everything here is derived from the shipped game data and
`default.xbe`; no script text is reproduced (the scripts are the game's content). Listings and
intermediate JSON live under `build/lua/` (gitignored); regenerate them with the commands below.

## Tools

| Tool | Purpose |
|---|---|
| `tools/luac_list.py` | Bytecode reader/lister for this game's format (`luac -l` style listing, `--check`, `--stats`, `--out`) |
| `tools/lua_bindings.py` | Call-target / global inventory over all scripts (bytecode, `.fig`-embedded bytecode, text) -> `build/lua/calls.json` |
| `tools/lua_regs.py` | Recovers the C++ binding table from the XBE (name -> C function) -> `build/lua/regs.json` (needs `build/venv/bin/python`, capstone) |
| `tools/lua_inventory.py` | Cross-references the two and `matches/`/`equivalent/`; writes `docs/lua-bindings.csv` |

```
python3 tools/luac_list.py --check build/rcf          # parse everything, verify no leftover bytes
python3 tools/luac_list.py build/rcf/misc/init.lua    # listing to stdout
python3 tools/luac_list.py --out build/lua/lst build/rcf   # listings for all (58 MB)
python3 tools/luac_list.py --stats build/rcf          # opcode histogram
python3 tools/lua_bindings.py                         # build/lua/calls.json
build/venv/bin/python tools/lua_regs.py               # build/lua/regs.json
python3 tools/lua_inventory.py --csv docs/lua-bindings.csv
```

## Bytecode format

The VM identifies itself as `Lua 5.1 (work)` (a string in `.rdata` at 0x42660c) but the chunk layout and
opcode set are Lua 5.0's, with a 4-byte `float` as `lua_Number`. Only the version byte (0x51) and the
missing `SIZE_OP/A/B/C` header bytes differ from stock 5.0. Header (14 bytes):

| Offset | Value | Meaning |
|---|---|---|
| 0 | `1B 4C 75 61` | signature `ESC Lua` |
| 4 | `51` | version byte (0x51, not the stock 0x50) |
| 5 | `01` | little endian |
| 6, 7, 8 | `04 04 04` | sizeof(int), sizeof(size_t), sizeof(Instruction) |
| 9 | `04` | sizeof(lua_Number): 4-byte float |
| 10..13 | `3B AF EF 4B` | test number 31415926.0 as a float |

There are no `SIZE_OP/A/B/C` bytes (stock 5.0 has four). Instruction layout is the 5.0 one: `op` 6 bits (low),
`C` 9, `B` 9, `A` 8 (high); `Bx` = bits 6..23 (18 bits), `sBx = Bx - 131071`; RK operands >= 250 index the constant
table (`x - 250`). Function layout is the 5.0 order: source name (size_t length incl. NUL, 0 = none),
linedefined (int), nups, numparams, is_vararg, maxstacksize (bytes), lineinfo[] (ints), locvars[]
(name, startpc, endpc), upvalue names[], constants[] (type byte 4 = string, 3 = number, 0 = nil),
protos[] (recursive), code[]. All shipped chunks are stripped of line info and local names.

Opcode numbering (36 opcodes; verified against jump directions and operand ranges over 1.7M instructions): MOVE 0, LOADK, LOADBOOL, LOADNIL,
GETUPVAL, GETGLOBAL, GETTABLE, SETGLOBAL, SETUPVAL, SETTABLE, NEWTABLE, SELF 11, ADD, SUB, MUL, DIV, POW, UNM,
NOT, CONCAT, JMP 20, EQ, LT, LE, TEST, CALL 25, TAILCALL, RETURN 27, FORLOOP 28, **FORPREP 29**, TFORLOOP 30,
TFORPREP 31, SETLIST 32, SETLISTO 33, CLOSE 34, CLOSURE 35. This is the stock 5.0 opcode set (FORLOOP/FORPREP and
TFORLOOP/TFORPREP pairs); `FORLOOP` vs `FORPREP` was confirmed from jump directions. SELF never occurs in the shipped scripts, so
its slot is the 5.0 default, unconfirmed by data.

Opcode statistics over all 16,347 chunks (1,698,465 instructions): LOADK 46.1%, GETGLOBAL 20.0%, CALL 15.0%,
GETTABLE 5.5%, SETTABLE 3.4%, RETURN 2.0%, MOVE 1.9%, NEWTABLE 1.1%, JMP 1.0%, LOADBOOL 1.0%, SETGLOBAL 0.6%,
CLOSURE 0.5%, EQ 0.5%, SETLIST 0.3%; the rest are under 0.3% each. SELF and CLOSE are absent. The
code is overwhelmingly flat sequences of `GETGLOBAL; LOADK...; CALL` (data-driven scripts).

### Corpus and parse results

`tools/luac_list.py --check build/rcf`: **0 failures, no leftover bytes**, every instruction in range.

| Source | Count | Notes |
|---|---:|---|
| Standalone bytecode `.lua` | 108 | `misc.rcf`: `init.lua`, `scripts/{config,damage,physics}.lua`, 103 subtitle map/timing files; `sound_misc.rcf`: `sound/objects.lua` |
| Standalone bytecode `.obj` | 93 | `sound_misc.rcf` `sound/scripts/<name>.obj` (compiled from the text `.lua` of the same stem) |
| Bytecode embedded in `.fig` | 16,146 chunks in 155 of 176 `.fig` files | fight/scenario script containers (`fig0` magic); chunks sit back to back, found by signature scan |
| Plain-text `.lua` | 287 | `art.rcf`: 187 (`global_init.lua`, 15 locations x 2 (`<stem>_init.lua`, `<stem>.lua`), 78 missions x 2); `sound_misc.rcf`: 100 (sources of the `.obj` files and sound tables) |

The "395 scripts" figure is the `.lua` file count (108 compiled + 287 text). The loader (below) reads a
file into memory and calls the `luaL_loadbuffer`-style function, which accepts text and bytecode alike,
so text replacements for compiled files should load; this has not been tested.

## How scripts are bound to C++

Bindings are not stock `lua_register`. A binding is a C++ object (`Method<n>`/`Closure<n>` templates: name,
argument/result type descriptors, function pointer at +0x1c, owner at +0x20). `Registry::Add`
(`FUN_001d3b70`, 907 xrefs) does `lua_pushlightuserdata(obj)`, `lua_pushcclosure(FUN_001d22a0, 1)`,
`lua_settable(GLOBALS, name)`; `FUN_001d22a0` (935 bytes) is the single C thunk that unpacks the Lua
arguments by the descriptors and calls the bound function. `FUN_001d4c90` returns the ScriptHandler
registry singleton. Managers register in their constructors, mostly with the `Method<n>` constructors
inlined (`tools/equiv_gen/inlined_regs.py`), or through ~179 small `Registry::Register*(name, owner, fn)`-style helpers
(`tools/equiv_gen/reg_helper.py`). When the Lua state is recreated (`FUN_001d3da0`, see below) the registry is
walked and every binding re-pushed.

`tools/lua_regs.py` finds every registration site in `.text` (name string + function pointer) and reports
**749 bound names** (746 through the registry + 3 created directly in `ScriptHandler::CreateState`:
`debug` = 0x001d2000, `cdebug` = 0x001d2020, and the `Vector` type setup 0x001d07b0). Cross-check:
CSPManager 0x001e7470 = 66, CUnlockablesManager 0x00094fb0 = 15, CCameraManager 0x0009dd20 = 62
(all match the numbers in `tools/equiv_gen/README.md`). Standard libraries are plain `luaL_reg`-style
`{name, cfunction}` arrays in `.data` (base 0x434d90, table 0x4348a0, math 0x434970, string 0x434af8,
coroutine 0x434e68, debug 0x434710, extra base functions 0x4cd3f8) opened from the 0x33xxxx range.

Status legend: *matches* = `matches/0x<addr>.cpp` exists; *equivalent* = `equivalent/0x<addr>.cpp` exists;
*unverified* = neither. "C function" is the function pointer stored in the binding (the real implementation, not
the registration glue). The full per-name table (749 rows: name, C address, registrar, call count, scripts,
statuses, top script groups) is `docs/lua-bindings.csv`.

### Headline numbers

| | Count |
|---|---:|
| Distinct bound names | 749 |
| Used by scripts AND bound | 479 |
| Bound but never called by any script | 270 |
| Called by scripts, not bound, not defined by scripts, not stdlib ("unresolved") | 15 (11 real, 4 lexer noise) |
| Called by scripts, defined by scripts themselves | 284 global functions + 71 module-table functions |
| Standard-library functions called | 26 (all bound; C addresses below) |
| Bound C functions verified (matches/ 257 + equivalent/ 154) | 411 of 749 (55%) |
| Of the used bindings: verified | 268 of 479 (56%) |
| Registration functions: verified | 683 of 749 rows in `matches/`/`equivalent/`; the other 66 are the CSPManager ctor 0x001e7470, proved but not yet promoted (`build/farm/bench/claude-equiv/pass/`) |

Call counts are static call sites weighted by occurrence in each script/chunk, not runtime counts.

### Top 60 bindings by static call count

| calls | scripts | name | C function | status |
|---:|---:|---|---|---|
| 73798 | 93 | `snd_CreateTrigger` | 0x001f1480 | equivalent |
| 43545 | 79 | `snd_AddCommand_PlayMissionDialogueEvent` | 0x001f17f0 | equivalent |
| 15770 | 94 | `snd_CreateObject` | 0x001f13b0 | equivalent |
| 12675 | 106 | `cdebug` | 0x001d2020 | equivalent |
| 11139 | 93 | `snd_AddCommand_PlaySequenceEvent` | 0x001f1540 | unverified |
| 7633 | 78 | `snd_AddCommand_PlayFightDialogueEvent` | 0x001f18b0 | equivalent |
| 5470 | 81 | `snd_AddCommand_PlayAmbienceEvent` | 0x001f1a20 | equivalent |
| 3491 | 79 | `snd_AddCommand_PlayMusicEvent` | 0x001f1970 | equivalent |
| 3362 | 78 | `snd_AddCommand_CueNISEvent` | 0x001f1b80 | equivalent |
| 3016 | 61 | `stm_MapSoundFileToStringKey` | 0x001be9f0 | equivalent |
| 2691 | 36 | `tvm_AddCharacterToEncounterGenerator` | 0x001fdc90 | equivalent |
| 2289 | 96 | `snd_PrepareSequence` | 0x001ea050 | matches |
| 1460 | 61 | `snd_AddCommand_StopTunableEvent` | 0x001f16e0 | unverified |
| 1255 | 29 | `am_SetDefendLocation` | 0x00029740 | equivalent |
| 1255 | 37 | `spm_SetSmartPropStateByName` | 0x001e3230 | equivalent |
| 1200 | 78 | `em_PostEventString` | 0x001cbd10 | matches |
| 1103 | 84 | `spm_SetSmartPropState` | 0x001df100 | unverified |
| 1039 | 79 | `am_GetActorPosition` | 0x00026c30 | equivalent |
| 956 | 98 | `hud_ClearMessages` | 0x000d5440 | equivalent |
| 919 | 105 | `hud_Message` | 0x000d5fa0 | unverified |
| 918 | 82 | `snd_AddCommand_InstallMixer` | 0x001efd60 | unverified |
| 863 | 99 | `Vector` | 0x001d07b0 | matches |
| 820 | 24 | `am_CreateActor` | 0x0002c050 | equivalent |
| 746 | 36 | `am_SetTarget` | 0x00029500 | equivalent |
| 719 | 54 | `am_SetActorPosition` | 0x00026b10 | unverified |
| 714 | 58 | `debug` | 0x001d2000 | unverified |
| 712 | 39 | `hud_triggerButtonHintEnd` | 0x000cad60 | matches |
| 701 | 89 | `tvm_GetLocatorPosition` | 0x001fd7d0 | unverified |
| 652 | 61 | `snd_AddCommand_PlayTunableEvent` | 0x001f1600 | equivalent |
| 566 | 34 | `stm_SetEvent` | 0x001bdf20 | unverified |
| 560 | 51 | `tvm_IsActorInTriggerVolume` | 0x001fcc00 | unverified |
| 555 | 40 | `am_UpdateKnownPlayerPos` | 0x000290a0 | unverified |
| 554 | 48 | `fe_fullscreenMessage` | 0x000b47b0 | equivalent |
| 525 | 41 | `hud_AddMovingHudIcon` | 0x000cb310 | unverified |
| 500 | 33 | `hud_triggerButtonHintBegin` | 0x000ce700 | unverified |
| 488 | 52 | `tvm_DisableTriggerVolume` | 0x001fcc40 | matches |
| 465 | 56 | `hud_AddMovingMapIcon` | 0x000cafd0 | unverified |
| 465 | 23 | `um_IsUnlockableLocked` | 0x00092dc0 | matches |
| 462 | 101 | `snd_TriggerAmbience` | 0x001eb6c0 | matches |
| 451 | 90 | `sm_SetMissionObjectiveState` | 0x001ccfc0 | unverified |
| 445 | 33 | `am_GetWayPointCount` | 0x00029010 | unverified |
| 440 | 64 | `spm_SetSmartPropMustBeActive` | 0x001dc100 | equivalent |
| 424 | 94 | `am_LoadFightScript` | 0x00024480 | unverified |
| 418 | 54 | `am_AdvanceWayPoint` | 0x00028fd0 | unverified |
| 389 | 64 | `sm_SetMissionState` | 0x001cc620 | equivalent |
| 364 | 100 | `sm_StartTimer` | 0x001cc9d0 | equivalent |
| 362 | 68 | `am_SetActorControllerIndex` | 0x00028130 | unverified |
| 360 | 91 | `sm_SetMissionObjective` | 0x001ccf70 | unverified |
| 355 | 32 | `am_SetPatrolParams` | 0x00029390 | unverified |
| 355 | 28 | `um_SetUnlockableLocked` | 0x00093db0 | unverified |
| 339 | 50 | `gfm_GetChapter` | 0x00023e50 | matches |
| 333 | 57 | `snd_AddCommand_PlayInterruptEvent` | 0x001f15a0 | unverified |
| 332 | 70 | `am_PlayFightNode` | 0x00027c90 | equivalent |
| 325 | 66 | `hud_AddStaticMapIcon` | 0x000caf60 | unverified |
| 321 | 47 | `gfm_GetMissionProgressSimple` | 0x0008a060 | matches |
| 315 | 100 | `hud_ShowOverlays` | 0x000d6fb0 | matches |
| 304 | 47 | `spm_GetSmartPropState` | 0x001dc350 | matches |
| 288 | 16 | `rm_EnableBloom` | 0x001b8780 | matches |
| 288 | 16 | `rm_SetBloomColour` | 0x001b87d0 | matches |
| 288 | 16 | `rm_SetBloomParameters` | 0x001b98e0 | equivalent |

### By registrar (manager constructor / registration function)

Each row is one function that registers a group of bindings; "prefix" is the script-visible name prefix.

| registrar | owner | prefix | bound | used | calls | matches | equivalent | unverified | registrar status |
|---|---|---|---:|---:|---:|---:|---:|---:|---|
| 0x00031310 | CActorManager | `am` | 217 | 112 | 10476 | 25 | 46 | 146 | equivalent |
| 0x001e7470 | CSPManager | `spm` | 66 | 49 | 4085 | 19 | 25 | 22 | proved-unpromoted |
| 0x0009dd20 | CCameraManager | `cm` | 62 | 45 | 3445 | 28 | 7 | 27 | equivalent |
| 0x000d1720 | HUDOverlay | `hud` | 44 | 33 | 3794 | 22 | 3 | 19 | equivalent |
| 0x00200c10 | CTriggerVolumeManager | `tvm` | 38 | 29 | 5441 | 7 | 5 | 26 | equivalent |
| 0x001cfb20 | CScenarioManager | `sm` | 34 | 17 | 1964 | 25 | 4 | 5 | equivalent |
| 0x0007f950 | CAmbientsManager | `amb` | 29 | 18 | 187 | 14 | 4 | 11 | equivalent |
| 0x001bb990 | CRenderManager | `rm` | 27 | 20 | 2873 | 13 | 5 | 9 | equivalent |
| 0x000c0e40 | CFEManager | `fe` | 23 | 16 | 1038 | 4 | 7 | 12 | equivalent |
| 0x0008bf80 | CGameFlowManager | `gfm` | 22 | 18 | 1600 | 16 | 3 | 3 | equivalent |
| 0x00208210 | CWorldStreamManager | `wsm` | 22 | 18 | 592 | 11 | 5 | 6 | equivalent |
| 0x001f2730 | CSoundSystem | `snd` | 20 | 18 | 168480 | 1 | 11 | 8 | equivalent |
| 0x00091630 | CStatsManager | `sta` | 16 | 9 | 231 | 9 | 5 | 2 | equivalent |
| 0x00094fb0 | CUnlockablesManager | `um` | 15 | 12 | 1136 | 6 | 5 | 4 | equivalent |
| 0x001ee820 | CSoundRealTimeManager | `snd` | 12 | 5 | 1312 | 11 | 1 | 0 | equivalent |
| 0x001c0cd0 | CSubtitleManager | `stm` | 11 | 4 | 3637 | 5 | 2 | 4 | equivalent |
| 0x001f81c0 | CEffectManager | `em` | 11 | 8 | 617 | 3 | 5 | 3 | equivalent |
| 0x000d6640 | MessageOverlay | `hud` | 9 | 7 | 2149 | 2 | 1 | 6 | equivalent |
| 0x000d75c0 | CSimOverlayManager | `hud` | 7 | 7 | 1133 | 7 | 0 | 0 | equivalent |
| 0x00087e80 | - | `util` | 7 | 5 | 313 | 1 | 1 | 5 | equivalent |
| 0x001d4830 | ScriptHandler | `sh` | 6 | 1 | 15 | 3 | 0 | 3 | equivalent |
| 0x001b84f0 | CFMVManager | `fmvm` | 5 | 4 | 148 | 2 | 0 | 3 | equivalent |
| 0x00203490 | CWorldCollisionManager | `wcm` | 5 | 5 | 78 | 4 | 0 | 1 | equivalent |
| 0x001ea8b0 | CSoundResourceManager | `snd` | 4 | 3 | 2506 | 1 | 2 | 1 | equivalent |
| 0x001b2e50 | - | `phy` | 4 | 0 | 0 | 3 | 0 | 1 | equivalent |
| 0x001d3c90 | ScriptHandler | `(debug, cdebug, Vector)` | 3 | 3 | 14252 | 1 | 1 | 1 | matches |
| 0x001cc360 | CEventManager | `em` | 3 | 2 | 1218 | 3 | 0 | 0 | equivalent |
| 0x001f6990 | CSoundVoiceManager | `snd` | 3 | 1 | 262 | 3 | 0 | 0 | equivalent |
| 0x000aef10 | CControllerManager | `ctrl` | 3 | 2 | 33 | 0 | 1 | 2 | equivalent |
| 0x001b3c50 | - | `exp` | 3 | 2 | 30 | 1 | 0 | 2 | equivalent |
| 0x000b0500 | CHapticControllerManager | `hcm` | 3 | 1 | 15 | 3 | 0 | 0 | equivalent |
| 0x000436f0 | - | `char` | 3 | 1 | 2 | 0 | 1 | 2 | equivalent |
| 0x0008e880 | CPlatformManager | `debug` | 3 | 0 | 0 | 3 | 0 | 0 | equivalent |
| 0x00106e90 | CPatrolPathManager | `path` | 3 | 0 | 0 | 0 | 2 | 1 | equivalent |
| 0x001eebc0 | CSoundSimManager | `snd` | 2 | 1 | 80 | 1 | 1 | 0 | equivalent |
| 0x001b6440 | - | `cm` | 2 | 2 | 7 | 0 | 0 | 2 | equivalent |
| 0x00087e30 | - | `time` | 1 | 1 | 11 | 0 | 0 | 1 | matches |
| 0x00047890 | CCharacterTemplateManager | `ctm` | 1 | 0 | 0 | 0 | 1 | 0 | equivalent |

### Called by scripts but not bound anywhere (unresolved)

Not found in the registry, not defined by any script, not a standard-library function. Most are dead references
(names that appear only in sound-source text, autotester hooks, or code that was never completed). The
`at_*` names are autotester hooks that are absent from the shipped scripts.

| name | calls | scripts |
|---|---:|---:|
| `snd_SetEffectProperty` | 134 | 1 |
| `at_print` | 105 | 15 |
| `at_testname` | 90 | 15 |
| `at_endtest` | 45 | 15 |
| `^up0` | 32 | 16 |
| `getRidOfOldRubble` | 16 | 16 |
| `snd_AddEffect` | 6 | 1 |
| `format` | 3 | 1 |
| `gsub` | 1 | 1 |
| `globals` | 1 | 1 |
| `snd_SetMinMaxDistances` | 1 | 1 |
| `snd_CreateRegion` | 1 | 1 |
| `hud_GetMapIconMaxCount` | 1 | 1 |
| `am_GroupSetMaxActive` | 1 | 1 |
| `SetSmartPropCharacterAlignmentDamageFactor` | 1 | 1 |

(`^up0` is a call through an upvalue, `format`/`gsub` are method calls on string values, `globals` a local; they
are artifacts of the static tracing, not missing bindings.) If one of these ran in the retail game it would be a
nil-call error, so they are either unreachable or in the sound sources that are shipped only as compiled `.obj`.

### Bound but never called by any script

270 names. By prefix: `am_` 105, `cm_` 17, `sm_` 17, `spm_` 17, `hud_` 13, `snd_` 13, `amb_` 11, `tvm_` 9, `fe_` 8, `rm_` 7, `sta_` 7, `stm_` 7, `gfm_` 4, `phy_` 4, `debug_` 3, `em_` 3, `path_` 3, `sh_` 3, `um_` 3, `wsm_` 3, `(none)_` 2, `char_` 2, `dbg_` 2, `hcm_` 2, `ctm_` 1, `ctrl_` 1, `exp_` 1, `fmvm_` 1, `wm_` 1. Mostly `am_` (actor manager) and camera/scenario/SP
helpers that the shipped content does not use; they are still available to new scripts. The full list is the
rows with `calls = 0` in `docs/lua-bindings.csv`.

### Standard-library functions the scripts use

| name | calls | C function | status |
|---|---:|---|---|
| `table.insert` | 7486 | 0x0033ae50 | matches |
| `table.getn` | 2461 | 0x0033adf0 | matches |
| `math.random` | 480 | 0x0033bb40 | equivalent |
| `tostring` | 477 | 0x0033e250 | equivalent |
| `tonumber` | 223 | 0x0033d7a0 | equivalent |
| `string.find` | 189 | 0x0033cc10 | equivalent |
| `coroutine.yield` | 185 | 0x0033e9e0 | matches |
| `math.deg` | 139 | 0x0033b970 | matches |
| `string.sub` | 117 | 0x0033bd40 | equivalent |
| `pairs` | 111 | 0x0033ddd0 | matches |
| `math.floor` | 103 | 0x0033b7d0 | matches |
| `math.mod` | 86 | 0x0033b800 | unverified |
| `math.atan2` | 70 | 0x0033b760 | unverified |
| `math.asin` | 69 | 0x0033b6d0 | unverified |
| `string.format` | 26 | 0x0033d400 | equivalent |
| `type` | 23 | 0x0033dd60 | matches |
| `table.foreach` | 20 | 0x0033ad60 | matches |
| `table.sort` | 17 | 0x0033b500 | matches |
| `ipairs` | 17 | 0x0033de10 | matches |
| `math.sqrt` | 15 | 0x0033b850 | matches |
| `math.max` | 3 | 0x0033bad0 | matches |
| `math.abs` | 2 | 0x0033b610 | unverified |
| `table.remove` | 2 | 0x0033aef0 | equivalent |
| `math.min` | 2 | 0x0033ba60 | matches |
| `math.randomseed` | 1 | 0x0033bc80 | matches |
| `math.ceil` | 1 | 0x0033b7a0 | matches |

Other script-callable pieces that are Lua code, not C++ (defined by `init.lua` and friends): helper functions
and module tables the scripts share (a general utility layer, per-mission modules for the side missions, and
building-destruction helpers). Their names are script content and are not listed here.

## Load path and script structure

Names are function addresses in `default.xbe`. Path strings are `.rdata` format strings. Files are read through
the engine file system (the RCF archives; see `docs/formats/rcf.md`) rooted at the archive directories.

| Step | Function | Detail |
|---|---|---|
| Script host object | `ScriptHandler` ctor `FUN_001d4830` (vftable 0x422684) | Owns the `lua_State*` (+8) and the registry (+0xc, count at +0x100c). Registers its own bindings inline: `sh_DoString` (0x001d3f00), `sh_GetNumber`, `sh_GetString`, `sh_ProcessFile` (0x001d36e0), `dbg_AddWatch`, `dbg_DeleteWatch`. Singleton accessor `FUN_001d4c90` |
| Create/open state | `FUN_001d3c90` | Creates the Lua state (`FUN_002150e0`), opens the standard libraries, creates `debug`/`cdebug` and the `Vector` type |
| Lazy init | `FUN_001d4530` | If not yet initialised: `FUN_001d3c90`, `FUN_001d3bc0` (push all registered bindings), then notifies the sound system |
| Reset for a level | `FUN_001d3da0` (not in functions.csv, unreferenced by direct call) | Closes the old state, `FUN_001d3c90`, re-pushes every binding, runs `init.lua` (via `FUN_001d36f0`), then tries four per-level files `art/levels/<lvl>/<lvl>_{sp,tv,eg,path}.lua` (none exist in the shipped archives) |
| Run one file | `FUN_001d3600(path, flag)` | Opens the file through the VFS, reads it whole, calls `FUN_001d2810` (compile+run, chunk name `=ScriptHandler::DoLuaBuffer`). 17 callers. Text or bytecode both accepted |
| Startup scripts | `FUN_001d3c50` | Runs, in order: `init.lua`, `scripts/physics.lua`, `scripts/damage.lua`, `scripts/config.lua`. Called from level-load code `FUN_000865d0` and `FUN_00086630` |
| Level load | `FUN_00086630` (called from `FUN_000873a0`) | Resets managers, `FUN_001d4530`, `FUN_001d3c50` (startup scripts), then `FUN_00206320`, then `FUN_00088940`, finally marks the level loaded |
| Fight scripts + init scripts | `FUN_00206320` (world stream) | `am_LoadFightScript`-equivalent `FUN_00024400` on `scripts/fight/hulk.fig` and `scripts/fight/common.fig`; then `FUN_001d3600` on `art/locations/<locdir>/<locstem>_init.lua`, then `art/missions/<id>/<id>_init.lua`; then streams `art/locations/<locdir>/<locstem>.p3d` and `art/missions/<id>/<id>.p3d` |
| Mission/location data | `FUN_00088940` | Loads `art/missions/<id>/<id>.dh` and `.rdl`, then (via `FUN_001cd3d0` -> `FUN_001cd220`) the main scripts below |
| Main scripts | `FUN_001cd220` (a CScenarioManager-region function) | `FUN_001d3600` on `art/locations/<locdir>/<locstem>.lua` then `art/missions/<id>/<id>.lua`. A second caller `FUN_001cd410` (from the front end, `FUN_000bf560`) also loads `art/missions/<id>/<id>.dh` |
| Scripts in other systems | sound: `FUN_001efa40` -> `sound\scripts\<name>.obj`; `FUN_001f6990` -> `sound\map.lua`; subtitles: `FUN_000c2990` -> `frontend/lang/subtitles/timings/<name>.lua`, `FUN_001c0ab0` -> `frontend/lang/subtitles/<m>/<m>_sub_map.lua`, `global_sub_map.lua`, `blonskyfiles_sub_map.lua`; `scripts/all_defs.dhd` via `FUN_001fb1e0` | Each is `FUN_001d3600` on a formatted path |

Naming: a mission id is `c%02dm%02d` (also `c%dm%d` in a few places): chapter and mission number, e.g. the 78
mission directories under `art/missions/` (chapter 0 = prologue/tutorial, chapter 10 = the side/bonus missions
`c10m01..c10m45`). A *location* has two names: the directory (long name, e.g. a district plus time of day;
15 directories) and a short file stem used for every file inside it (for example `dt_day` in the `downtown_day`
directory). The two are separate getters on the level descriptor (`FUN_000897f0`, `FUN_000897e0`/`FUN_0008a2d0`).

Per-mission files (all 78 have the same six): `<id>_init.lua`, `<id>.lua`, `<id>_scenario.fig`, `<id>.dh`
(data handler: locators and objects), `<id>.rdl` (INI-style character templates), `<id>.p3d`. Per-location:
`<stem>_init.lua`, `<stem>.lua`, `<stem>_scenario.fig`, `<stem>.dh`, `.rdl`, `.p3d`, plus `common.fig`,
`<x>_common_scenario.fig`, `common_autotester.fig`. `art/global_init.lua` has no string reference in the
executable (appears unused).

What each kind of script does (in terms of the calls it makes, not its content):

* **`<id>_init.lua` / `<stem>_init.lua`**: a list of `am_LoadFightScript(path, nil)` calls (about a dozen
  `scripts/fight/<character>.fig`/`_ai.fig` files plus the mission's own `_scenario.fig`). It selects which
  characters/AI definitions exist for that mission. Runs before the level geometry streams in.
* **`<id>.lua`, `<stem>.lua`**: tiny at present (a single call to a shared helper, defined in `init.lua`,
  that places the player at the spawn locator). The location file for a district in the shipped data
  also carries a block of shared damage-effect functions.
* **`<id>_scenario.fig`**: a `fig0` container of fight-system definitions (conditions, tracks, actions) with
  compiled Lua chunks embedded as the `LuaCondition`/`LuaTrack`/`LuaAction` parameters (C++ classes
  `hulkfight::scenario::LuaCondition/LuaTrack/LuaAction`, `ParamScript`). This is where the mission logic lives:
  16,146 chunks total, mostly small state checks and calls to `sm_*`, `snd_*`, `hud_*`, `am_*` bindings.
  A script-visible state-machine table (current state name + list of states) is stored in Lua globals, with
  per-sub-mission setup functions run by the chunks.
* **`misc/init.lua`** (bytecode): the shared library (helpers, math tables, enums such as prop states) and the
  **mission registry**: 77 `AddValidMission(a, b)` calls (two strings; binding 0x000b4b60, CFEManager, stores
  into a 128-entry string table at +0x26c, deduplicated by strcmp) and 92 `SetMissionInfo(id, s2, s3, s4, n5, n6)`
  calls (binding 0x000b4e30, CFEManager: 128-entry table of 0x28-byte records at +0x470, keyed by a 64-bit hash of
  the id; fields: three more hashed strings and two numbers). 45 nested functions.
* **`scripts/config.lua`** (debug-controller function table), **`scripts/damage.lua`**, **`scripts/physics.lua`**: global tuning/callback tables.
* **Subtitle scripts** (103 bytecode files under `misc/frontend/lang/subtitles/`): per-mission sound-file ->
  string-key maps and timing tables (`stm_MapSoundFileToStringKey` 3,016 calls).
* **Sound scripts** (`sound_misc/sound/scripts/<name>.obj`, one per mission/location/time of day, plus
  `common`, `frontend`): pure data scripts of `snd_CreateObject`, `snd_CreateTrigger`, `snd_AddCommand_*`
  (well over 100k calls), `snd_PrepareSequence`. The text sources of these are shipped too.

C++ -> Lua entry: `FUN_001d3b00` (ScriptHandler) takes a by-value 0x2b8-byte call descriptor (names held in 0x100-byte buffers)
and forwards to `FUN_001d2190`; `FUN_001db110` builds one for a script-side handler named `HandleLuaCalls`
(event `CollapseRoof`), and `stm_InitEvents` (CSubtitleManager) is an example of C++ code registering
its own script hook. Mission start/update callbacks are not C++-called by name: mission logic is the
`LuaCondition/LuaTrack/LuaAction` chunks in the scenario `.fig` plus whatever the `<id>.lua` file does at load time. The mission ids are also present in
static `.rdata` pointer tables (0x3ffdf0.. main missions, 0x4061e8.. and 0x406710.. richer per-mission records
with extra string pointers, the c10 side-mission names at 0x407474..0x407584), plus `TBS_C%dM%d_NAME` and
`TBS_MISSION_DESCRIPTION_C%02dM%02d` string-table keys.

## Adding a mission: what we would need

1. **Content files** under a new `art/missions/<id>/`: `<id>_init.lua`, `<id>.lua`, `<id>_scenario.fig`, `<id>.dh`,
   `<id>.rdl`, `<id>.p3d`. The `.lua` files can be authored as text (loader accepts text; untested). The
   `.dh` and `.rdl` are text. `.p3d` is the existing Pure3D format (`docs/formats/p3d.md`).
2. **The scenario `.fig`**: needs a writer. We can read the embedded bytecode but the `fig0` container framing
   (record headers, hashes, parameter blocks) is not documented yet. Alternative: reuse a shipped `.fig` and only
   change the Lua chunks (they are independently parseable, but chunk sizes and offsets in the container would need to be fixed up).
3. **Registration**: add `AddValidMission` + `SetMissionInfo` calls (in `init.lua`, or a new startup script) for the new id;
   note both tables hold at most 128 entries (92 / 77 used).
4. **Archive**: new files must be inside `art.rcf` (or the loader's VFS must be taught to read loose files); the
   RCF writer/rebuilder is a prerequisite (`tools/rcf.py`, `docs/formats/rcf.md`).
5. **Strings**: `TBS_C<n>M<n>_NAME` and mission-description keys in the localized string tables.
6. **Sound**: a `sound\scripts\<id>.obj` (or reuse one) and a subtitle map/timing file per language.
7. **For the native port**: all 749 bindings must exist natively; 338 of them (45%) are still unverified, 270 are unused by the
   shipped scripts (low priority), and the Lua VM itself is the stock 5.0-era VM linked into the XBE
   (it can be replaced by a stock Lua 5.0 build patched to read this 14-byte header with no op-size bytes).

Open questions:

* Do the hard-coded `.rdata` mission tables (0x3ffdf0.., 0x4061e8.., 0x406710..) need a new row for a new id, or is
  `SetMissionInfo` the only gate? Who reads them (not yet traced).
* `fig0` container format and the exact way `LuaCondition/Track/Action` chunks are extracted at load time.
* How a new mission is entered from the front end: which of `gfm_SetNextMission`/`FUN_000bf560` consume the ids, and whether a location needs a
  new district `.p3d` set (`art/locations/<loc>/<loc>_district_%d.p3d`, `_r%03d.p3d`) and `rooms.rcf` entries.
* Whether the loader accepts text for the files currently shipped compiled (should, per `FUN_001d2810`; test in xemu/Wine build).
* Whether `SELF` exists in this VM (never emitted by the shipped compiler output).
* Which of the 15 unresolved names are reachable (likely none).
