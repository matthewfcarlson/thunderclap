# Playthroughs: play on from play3 and record (wplay4, D244)

A *playthrough* is play3 followed by your own sessions, recorded so the whole thing replays as one recording. You
play in the macOS app as usual (Metal, your controller, sound); the app starts where the last session ended, records
your pad, and when you quit it saves the session and the game's state so the next session starts there at once.

Everything lives in `build/playthrough/NAME/` (game-derived local data: never committed, never in the player's folder
~/Library/Application Support/HulkUD). The first playthrough is **play4**.

## Commands

```sh
P=build/venv/bin/python
# play (and record) from the end of play4 so far, or from the end of play3 for a new playthrough
$P tools/playthrough.py record --name play4                     # the app: build/Hulk.app (--app PATH / --exe PATH)
#   end the session with the menu's Quit Game, Cmd+Q or the window's close button: the app saves and exits
$P tools/playthrough.py list                                    # playthroughs, their segments and frame counts
$P tools/playthrough.py replay --name play4                     # replay it all headless and check (a few minutes)
$P tools/native_replay.py run --exe build/wasm/hulk-aot --rec play4 --out build/ME/run --frames N -- $PWD/isos/extracted/default.xbe
$P tools/playthrough.py check --name play4 RUN.ckref            # a run's records against play4's
$P tools/wasm_build_job.py submit --name ME --target aot --test play4:N [--control JOB]   # on the queue
```

Starting from a game save (v2):

```sh
cp -R "$HOME/Library/Application Support/HulkUD/save" build/playthrough/mysave     # a copy of your save folder
$P tools/playthrough.py record --name day1 --from-save build/playthrough/mysave [--parent play4]
#   the game boots with that save (load it from the main menu: Load Game); the session records from boot
$P tools/playthrough.py record --name day1                      # later sessions continue day1 as above
```

A save-start playthrough is its own recording: it keeps a copy of the save (`seed/save`: the game's T, U and Z
drives; port_settings.txt is not taken) and the inputs from boot, so it replays from that save on any build
(`native_replay.py run --rec day1` seeds the run's save folder from it; `wasm_build_job --test day1:N` ships it).
Its recording (`boot.hrp`) has play3's header (the virtual clock and generators, skip-intro, no-fmv) and no inputs of
its own: the player has the pad from the first frame end. `--parent` only notes where the save came from. `--from-save`
copies the folder you name and never writes to it.

`record` options: `--settings remastered=1,frame_rate=60,...` sets renderer-only settings for every session of the
playthrough (given at the first session; the rows that change the game, aspect / HUD frame / draw distance / tutorial
skip / traversal moves / developer, are refused). Renderer options you change in the game's own Video Options menu
during a session are fine too: the presses are recorded and replay the same.

## What happens

1. **Reaching the start.** For the first session with a given app build, the app replays the playthrough so far
   (play3, then your earlier sessions) in a hidden window as fast as it runs (play3 to its end, GameClock frame 56,564
   where its last input takes effect: ~70 s headless on mac2, a few minutes with Metal), keeps
   the game's state there (`snapshots/<build>/<frame>.snap`, with the save folders as they were), and exits. Then it
   starts again in a window from that state. While it catches up, `record` prints `frame X of Y (N%, ~M s left)`
   every 5 seconds (Y: play3's end plus the earlier sessions; X from the replay's trace). Later sessions of the same build start from the last session's own
   snapshot within a second. Another build (a new app) makes its own snapshot the first time.
2. **Playing.** The window is the normal app: paced, sound on, your controller and the keyboard as pad 0. The game
   still runs under replay rules: the recording's virtual clock, the sound code's own generators, lockstep loading, the
   simulation's settings pinned to the original's. Nothing real-time reaches the game.
3. **Quitting** (menu Quit Game, Cmd+Q, close button) writes the session's state at the next frame end and exits; the
   tool appends the segment, rebuilds `play4.hrp` and the references, and keeps the state for the next session. If the
   app crashes, the segment ends at its last mark (written every second) and the next session replays to it.

## Determinism: what is and isn't the same

- **The same in every replay:** everything the game simulates. A session's checkpoint records are identical when the
  playthrough is replayed headless (null renderer or `hulk-aot`), and identical again when a session starts from a
  snapshot instead of replaying from frame 0 (tested: below).
- **Movies (FMV) are skipped**, as in play3 (its no-fmv rule: the game never queues an FMV). In-engine cutscenes play.
- **Sound** is the deterministic model (D222). Replays advance the voices 800 output frames a DoWork, which is ~1.5x
  the console's rate (the Wine mixer's clock play3 was checked with); from the first session on, a playthrough
  advances them 533 a DoWork (the game calls DoWork 3.01 times an update: 1,600 frames, real time at 30 updates a
  second), recorded in the recording's SEG1 trailer so replays do the same. Sounds a session hears follow the
  model; the mixer only listens.
- **The clock in waits:** the recording's virtual clock moves only at GameClock updates. In a playthrough's own
  segments (never in play3's part), the main thread reading the clock more than 20,000 times without an update (the
  game's minimum-time wait while it loads a save) sees it move on 1 ms a read; the next update goes on from there.
  Without it, Load Game froze the game at GS_PREGAME (sessions on build 0908293 must not load a save). It applies only
  where a session would otherwise hang, so segments recorded before it replay the same.
- **Saves** go to the session's own save folder, seeded from the snapshot's (play3's run-local saves to start with);
  the save files are part of each snapshot. Your own saves in the player's folder are never touched or read.
- **Settings:** every session and replay of a playthrough uses the same `--settings`; the menus refuse the rows that
  change the game during a recording's run.
- The Wine build and the native builds do not read the SEG1 trailer: play4 replays on the wasm builds only.

## Files

- `playthrough.json`: base (play3), settings, every segment's start and end as (present, GameClock frame, poll),
  entries, the build and executable it was recorded with, whether it started from a snapshot.
- `play4.hrp`: play3's header and inputs to the first segment's start, then each segment's (entries keyed by poll, as
  play3's), its checkpoints and particle checkpoints to the first segment, and a trailer:
  `"SEG1", u32 1, u32 n, u32 ds_live_work, n x {u32 start_present, start_frame, start_polls, end_present, end_frame,
  end_polls}`. A segment boundary is the first frame end at or after (frame, poll): the number of presents differs
  between renderers (the pddi front end's and d3d_null's during loads), updates and polls don't.
- `play4.ckref` (+ `.json`): the reference: the Xbox's play3 records up to the first session's start (frame 56,563;
  they end at 56,575, but from 56,564 the player's input replaces play3's), our own after them (the sessions'); the
  `.json` says where the Xbox's end
  (`xbox_to_frame`, `self_recorded_from_frame`). `play4.self.ckref`: our own records only, every frame: a replay of the
  playthrough must give exactly these (`playthrough.py check` / `replay` require it, every tag).
- `segments/NNN/`: `seg.inputs` (24-byte .hrp entries), `seg.seg` (start / end, DoWorks per update), the session's
  `trace.txt` / `trace.txt.ckref` / `stdout.txt`, its save folders.
- `snapshots/<sha256 of the hulk-app, 16 hex>/<frame>.snap` and `<frame>/{save,tdata,udata}`.

The app side (src/platform/wasm/host/replay.cpp "Playthroughs", sched.c `ff_snap_write` / `ff_snap_read`):
`HULK_RECORD_BASE=FILE.hrp` (the base, under replay rules), `HULK_RECORD=PREFIX` (a session), `HULK_SNAP_AT_HANDOFF=F`
(replay to the base's end, write the state, exit), `HULK_RESTORE=F`, tests' `HULK_RECORD_FROM=FRAME` /
`HULK_RECORD_UNTIL=FRAME` / `HULK_INPUT` (a scripted stand-in for the player), `HULK_DS_LIVE_WORK`. A snapshot is
rolltest's state (the image's data, the main stack and sim block, the arena to its top, the pddi front end's section,
the tree's `hulk_game_state`) plus the next fiber and the host state the game reads that lives elsewhere in module
data: the replay's position, virtual clock, generators and checkpoint counters (`ff_replay_blob`) and lockstep I/O's
drives (`ff_io_blob`). A restore checks the ranges against the build's own; the tool keys snapshots by executable.

## Reaching the daytime city

Which city you get is the mission's, not the time played: each mission has one location, and the location's name
carries the time of day (`downtown_day`, `downtown_dusk`, `downtown_night`, `outskirts_day`, `outskirts_dusk`, and
one-variant places such as `church_night`). The table pairing missions with locations is game data, `misc/init.lua`'s
`AddValidMission(mission, location)` calls (registered by FUN_000b4b60, looked up by FUN_000b4cf0); every way into a
mission (new game, the next / acquired mission, mission select) looks the location up there and loads it
(FUN_000895e0 -> CWorldStreamManager 0x00206320, `art/locations/<location>/`). Mission scripts name the next mission
(`gfm_SetNextMission`), so the order is the story's.

play3 covers the desert tutorial (c00m01, `desert_tutorial_dusk`, lit like day), then the night city (downtown_night,
frames ~15,000-28,000) and a third mission from ~33,600 to its end (56,575). The first story missions and the Church hub
are all night. The day and dusk city come with later story missions (and the c10 side missions); which mission first
uses `downtown_day` is in init.lua's table, not in the repo, so: **play on through the story**, taking the next story
mission each time; the city's look changes with the mission. If you have a save further on in the story, a playthrough
from that save (`--from-save`, above) is the fastest way there.

## Tests (wplay4)

- Full length, headless (`hulk-aot`, queue job 111817 on mac2): play3 replayed to its end and its state kept (frame
  56,564, poll 1,231,391; 46 MB), a scripted session (HULK_INPUT: stick held, A tapped) of 900 frames from that
  snapshot, a second session of 600 from the first one's snapshot, then the whole playthrough (58,064 frames) replayed
  from frame 0: records identical to the sessions', every tag (`playthrough.py replay`). DoWorks per update: 3.000.
- Metal (the app, hidden window, laptop): two scripted sessions recorded under Metal (the first from a Metal snapshot
  handed off inside play3, the second from the first's snapshot), replayed headless on `hulk-aot`: identical.
- From a save, headless (queue job 111863): a save made by play3 to frame 20,000, a scripted session from boot that
  loads it (GS_PREGAME -> GS_GAME), a second session from its snapshot, the replay from boot with the save: identical.
- play3 itself: candidate vs control to 60,000, records identical: hulk-aot (wasm_build_job test 111814) and the app
  with the null renderer (111815).
