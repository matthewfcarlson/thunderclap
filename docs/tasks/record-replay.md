# Record/replay: why play2 didn't replay, and the fix

`build/replays/play2.json` (tutorial, saves, loads: 8,514 frames, 10,705 pad changes, 284 checkpoints) left its
recorded checkpoints at frame 90 on every replay. Every trace capture of it recorded a different game from the one
the user played. Two causes were found, plus a third (host clock) that was pinned without being needed.

## 1. Two pads, interleaved by poll

`hybrid_test.py record` binds the keyboard to port 1 (the user's xemu.toml has no bindings). xemu also auto-binds
any gamepad it sees to the next free port. The user played on a gamepad, so the game saw **two pads**: the idle
keyboard in port 1 and the gamepad in port 2. `ControllerSystemXBox::vfunc_12` polls every connected pad once per
round, and `g_hybrid.polls`, which recordings are keyed by, counted both.

Evidence in the file: every non-zero entry has an even poll number and every zero entry an odd one (10,705 of
10,705). Port 1 was always idle. A replay has only the keyboard (no gamepad is connected here), so it reads one pad
per round and runs the stream at twice the speed, onto the wrong pad.

The suspected cause in the task (failed `XInputGetState` calls not recorded) can't be seen in play2. The parity
would show a pad that went missing, and it never does. The keyboard pad returned no errors in 24,000 polls (the new
`poll_errors` counter). The virtual pad (below) rules it out for future recordings anyway: every read the game
makes succeeds, in both record and replay.

**Fix (vpad).** With `HF_VPAD` the game sees one virtual pad in port 1 on every host. It is inserted at the first
device check, whatever xemu has bound and whenever USB enumerates. The device calls are redirected to
`hybrid/hooks.cpp` (`patch_xbe.py VPAD_CALLS`): `XGetDeviceChanges`, `XInputOpen/Close/SetState`, and the pad-init
`XInputGetState`. When recording, the hooks open every real pad themselves and give the game their merged state, so
any pad plays (keyboard or gamepad, any port). Rumble is forwarded to the real pads and completes at once for the
game, so the rumble status no longer depends on hardware timing. When replaying, no real pad is touched.

**Salvage.** `hybrid_test.py salvage IN OUT` finds the pad that played and rewrites the stream as that pad's, keyed
by poll round. Because the idle pad was all zero and an entry is only written on a change, the stream is exact.

## 2. The audio sequencer drew from the gameplay RNG

The collapsed play2 then replayed to frame 330, deterministically: four replays (fast, render scale 6, two
virtual pads) gave the same wrong hash at 360. A dump at frame 360 matched the recorded hash once the gameplay RNG
(`0x4e5ad0`) was stepped **2 more times**. The camera and GameClock were already identical. So the recording drew the
gameplay RNG twice more than the replay did, and nothing else differed.

One replay throttled to ~6.5 fps (SIGSTOP/SIGCONT, 70% of the time stopped) matched the recording through frame
720. play2 itself was recorded at about that speed. Two other throttled replays didn't match: the extra draws
depend on timing, not simply on speed.

`sound-rng` had already moved the sound code's draws (`0x964d0` callers in the voice manager) and audio
sequencing's `rand()` off the gameplay generator. The audio *sequencer* (`audio::Seq*`) still used it, through two
other paths:

| Site | What | How it read the game's RNG |
|---|---|---|
| `0x2526cc` | `audio::SeqActionVarVolumeRand::vfunc_1` | `mov ecx, [0x4e5acc]`, inline MWC step |
| `0x25369c` | `audio::SeqActionVarPitchRand::vfunc_1` | same |
| `0x254ed0` | `audio::SeqEventLogicOr::vfunc_3` | same |
| `0x25527f` | `audio::SeqCommandLogicOr::vfunc_0` | same |
| `0x2548f8`, `0x2549c9` | `audio::SeqEventSilence::vfunc_1/2` (silence length) | `call 0x113e0` (RandInt) |
| `0x254ca8` | `0x254c80`, `audio::SeqEventLogicRepeat`'s state (repeat count) | `call 0x113e0` |

These run when the emulated audio hardware finishes a sound, in real time. How many draws fell into a frame depended
on how fast xemu ran.

How they were found:
- A fresh recording made while throttled (`slow2-v2`, ~5 fps) and replayed at full speed parted at frame 600.
- A replay at full speed and a throttled one of the same recording, halted at frame 601 (`halt_frame`), differed
  by one RNG step.
- The `rng-log` diagnostic build logged every call into the RNG accessors (`0x964d0`, `0x964e0`) and every entry
  of the functions that step the RNG inline (`RNGLOG_FUNCS`), with caller and frame. The diff between the two runs
  was one extra `RandInt` call, from `0x254c80` at frame 579.
- The first four sites read `[0x4e5acc]` directly. They were found by listing every reference to it.

(GDB write watchpoints on `0x4e5ad0` wedge xemu's stub, so the logging is done in the guest.)

**Fix (seq-rng).** These sites now read the sound code's generator. The `mov`s are pointed at
`g_hybrid.seq_rng_ptr` (= `&snd_rng`), and the RandInt calls go to `hybrid_seq_randint`.

After the fix, a full-speed and a throttled replay of the same recording give identical checkpoints through the
end (1,547 frames). Before, they parted at frame 600.

## 3. The host's date (pinned, wasn't the cause)

xemu's RTC follows the host. The game's only `GetLocalTime` (`0x355364`) caller is core `0x267ad0`, used by:
- the save-slot metadata (`0x8b560` via `0x89a60`, next to the `TBS_C%dM%d_NAME` save names);
- the audio sequencer's 64-bit event ids (`0x263c90`: date bits | `GetMicroseconds`, used as keys in `0x4cd4cc`).

Replays run on different days already agreed with each other, so this wasn't a cause. It is still a host input:
`HF_VDATE` makes the date 2006-01-02 12:00 plus the virtual clock.

Other `KeQuerySystemTime` readers are XAPI internals: file times, the utility drive, and `XboxSaveDrive::vfunc_9`
→ `0x35618d`. A game-visible save timestamp could still come from FATX file times. Nothing in the paths checked
reads them back.

## Saves and the HDD

- The HDD image (`build/xemu/.../xbox_hdd.qcow2`, unchanged since Oct 10) holds **no Hulk data**. TDATA/UDATA
  contain only title `55530008`. There is no `56550039` (Hulk) directory.
- Every run uses `-snapshot`, so record and replay both start from that disk, with no saves and the same cache
  partitions. The game mounts its utility drive at start (`XapiInitProcess` → `XMountUtilityDrive`).
- Saves made during a session go to the run's temporary overlay. A later load in the same session reads them back,
  so a replay re-creates them itself. The one save field that came from the host clock (the slot timestamp) is
  pinned by `vdate`.
- How long a save or load takes still follows host I/O. The poll-keyed input stream absorbs this where the game
  waits for a button (the load screen's `PRESSSTART` loop exits on the recorded press). The trace replays of play2
  reached the same poll count at the end of the first load (47,8xx) as the recording.

## Recording format

`hybrid_test.py record` writes:

```
{"version": 2, "key": "polls", "flags": [... "vpad", "vdate", "seq-rng", "syncio", "record", "quant"],
 "seed", "tweaks", "inputs": [[poll, buttons, [8 analog], [4 thumbs]], ...], "checkpoints": [[frame, hash]],
 "frames", "polls", "timeline": [[wall s, frame, polls], ...], "pads": {...diagnostics}}
```

- **Version 1** (no `version` field) is what play1/play2 are. They replay as before, with neither the virtual pad
  nor the new pins.
- Replay and the trace tools (`hooks_cfg`) turn on whatever the recording's flags say.
- Optional keys:
  - `vpad_count`: several virtual pads, for replaying an interleaved version-1 recording unchanged;
  - `salvaged`: where a salvaged file came from.
- `timeline` records how polls ran ahead of frames (load screens), which play2 lacked when it was being
  diagnosed.

## Results

All runs are on this Mac (M3), one xemu at a time. "Throttled" means xemu was SIGSTOPped 70 ms of every 100 ms,
which gives about 3–7 fps instead of ~26. The stand-in player is play2's own input (collapsed to one pad, with the
first load shortened), fed through `record --script`.

| Recording | Made at | Replays | Checkpoints |
|---|---|---|---|
| play2 (version 1), as is | user, ~5–7 fps | full speed | diverges at **frame 90** (3 of 17 match) |
| play2 salvaged (`salvage`) | — | full speed ×4, render scale 6, 2 virtual pads, throttled ×3 | diverges at **frame 360** in 6 of 7 runs; one throttled run matched through 720 |
| `slow2-v1` (old flags) | throttled, ~5 fps | full speed ×2 | diverge at 600 (both) |
| `slow2-v2` (vpad, vdate, seq-rng without the RandInt sites) | throttled | full speed ×2 | diverge at 600 (RNG +1 step: `0x254c80`) |
| `slow3-v2` (all fixes) | throttled, ~3 fps, 2,239 frames | full speed ×2, then once more on the final build | **75 of 75, identical to the end** (all three) |
| `final1` (final code) | ~6 fps (host under load), 2,779 frames | full speed, then throttled (~7.5 fps) | **93 of 93, identical to the end** (both) |
| `final2` (final code) | ~23 fps, 10 min, 14,053 frames | full speed ×2 | **469 of 469, identical to the end** (both) |

Also checked:
- builds with every function around the new sites replaced, equivalents included, link and redirect them
  correctly;
- trace builds (`trace_gate.py`) build from both version-1 and version-2 recordings;
- without the new flags, a build differs from the previous code only inside `.hybrid` and in the rel32 of the
  existing hook calls (the hooks moved inside the section).

What wasn't tested: the real-pad half of the virtual pad, with a person on a gamepad. It opens the bound pad
(`real_pad0` set) and reads it without errors, but no key or pad input could be injected here. QMP has no key
handler in xemu, and CGEvents posted to xemu's pid don't reach SDL. The stand-in runs go through the same record
path from the pad state on.

play2 can't be salvaged past frame 330. Two attempts were made:
- Its audio sequencer drew the gameplay RNG at host-timed moments, and nothing in the recording says when.
- A replay with `seq-rng` plus fitted RNG offsets got further only to frame 210. The draws can be fitted at the
  checkpoints only while no gameplay draw falls between them. By frame 120 the recording had already made 23
  more audio draws than the replay. That tool was dropped.
- A replay without `seq-rng` reproduces most of the draws by chance and gets further (330), but not reliably.

`build/replays/play2-salvaged.json` (collapsed, frames 0–330: the title, the menus, the new-game load and the first
150 frames of the tutorial) is what is left.

### Speed of the recording build (stand-in input, 150 s each, gameplay from 60 s)

| Build | fps | host drain per 2 s |
|---|---|---|
| record (version 2, new incremental drain) | 25.5 | 4.9 ms |
| record + the old full-ring drain (230 KB memsave) | 26.6 | 10.6 ms |
| record with sound on (`HULK_XEMU_SOUND=1`) | 26.2 | 4.9 ms |
| replay | 27.2 | 4.1 ms |
| real-time game (no fixed dt or virtual clock: closest to plain xemu with a frame counter) | 25.7 | 4.2 ms |

The hooks, the drain, sound, and the checkpoints don't slow the game: about 26 fps is what xemu gives on this Mac
in the tutorial, with or without them. play2 was recorded much slower. 8,514 frames took about 15 minutes, against
about 6 for its replays, and only a ~6.5 fps replay ever reproduced its audio timing. The likely reason is the
host: other jobs running, battery or Low Power Mode, or a second xemu. A ~6 fps recording now replays exactly too,
but the game runs in slow motion for the player (game time is frames × 33 ms), which is what makes slow sessions
painful.

## What to do for the next recording

```sh
build/venv/bin/python tools/hybrid_test.py record play3 --out build/replays/play3.json
#   play; Ctrl-C in the terminal when done
build/venv/bin/python tools/hybrid_test.py replay build/replays/play3.json      # check it: "identical": true
```

- Use any pad: the gamepad (xemu binds it to whatever port) or the keyboard. The game sees one virtual pad.
- Make the Mac fast:
  - run on AC power, with Low Power Mode off;
  - run no other xemu, trace capture, compile or lane job;
  - keep the xemu window on screen.
  The recording replays at any speed, but at under ~25 fps the game is in slow motion while you play.
- Press START at the loading screens yourself.
- The terminal prints the frame and fps every 30 s (0 fps on a loading screen is normal). If gameplay shows well
  under 25 fps, the host is busy.

## VM snapshots: start a replay or a trace part-way through a recording

```sh
build/venv/bin/python tools/hybrid_test.py record play3 --out build/replays/play3.json [--snap-every 5]
#   a snapshot every 5 min; type s + Enter in the terminal (or kill -USR1 PID) for one now
build/venv/bin/python tools/hybrid_test.py replay build/replays/play3.json --from-snapshot 3     # or --from-frame F
HULK_XEMU_INSTANCE=0 build/venv/bin/python tools/trace_gate.py --session g3a --script build/replays/play3.json \
    --from-frame 9000 --shard 0/2 &
HULK_XEMU_INSTANCE=1 build/venv/bin/python tools/trace_gate.py --session g3b --script build/replays/play3.json \
    --from-frame 9000 --shard 1/2 &
build/venv/bin/python tools/trace_gate.py --session g3 --merge g3a g3b
build/venv/bin/python tools/equiv_replay.py --session build/traces/g3 --equivalent
```

### Design

**The disk is an overlay.** Each recording gets its own qcow2 file, `NAME.disk.qcow2`, with the read-only base
image as its backing file. `hybrid_run.make_overlay` writes it: qcow2 version 3, 64 KB clusters, a backing-format
extension. There is no qemu-img on this Mac.
- The recording runs xemu on the overlay **without `-snapshot`**. `Xemu(snapshot=False)` refuses any disk that is
  not an overlay of the base (`assert_overlay`).
- QEMU only ever opens a backing file read-only, so the base is never written.
- `hybrid_run.check_base` checks the base's size and sha256 before every xemu start, and stops if either changed.
  The base itself is `chmod a-w`.

**Snapshots are `savevm` into the overlay.** HMP `savevm sK` is run while the VM is stopped. It stores the
machine state (~60 MB) as an internal snapshot of the overlay, and the disk state at that moment is included.
- Each snapshot is tagged in the recording's `snapshots`:

  ```
  {tag, frame, polls, inputs (record entries so far), ckpt: [frame, hash] (the last checkpoint),
   t, pause_s, disk_bytes, why ("every" or "request"), usb (xemu's pads)}
  ```

- When the recording ends, the overlay is made read-only.
- Not used, and never to be used:
  - `drive-backup`. On a `-snapshot` drive it deleted the base image (2026-10-17): the overlay's "temporary"
    open flag is passed on to the new image's backing file;
  - migrate-to-file. It works (61 MB, 0.4 s), but it leaves the disk state to be saved some other way.

**Resuming** (`hybrid_test.resume_snapshot`):
1. `install` the recording's own XBE (`NAME.rec.xbe`), so any section the game reads from the disc later is the
   same.
2. Clone the overlay to a throwaway copy (`cp -c`, an APFS clone: instant; deleted afterwards).
3. Start xemu on the copy, paused (`-S`), without `-snapshot`.
4. Wait for xemu to attach its pad, then `loadvm`.

   `-loadvm` at startup fails ("Unknown section … usb-hub"), because xemu adds its pads and their hubs only after
   QEMU starts. If the snapshot had pads that this host doesn't bind, they are `device_add`ed at their recorded
   ports first. This was tested with a second pad (hub `1.4`, `gamepad_1`) added while recording, standing in
   for an auto-bound gamepad. The resume added it back, and all 45 later checkpoints matched.
5. Attach GDB and turn the recording build into a replay:
   - the flags `replay` would use;
   - the replay ring from the snapshot's poll on (`replay_pos`, `replay_avail`, `replay_count`);
   - longer recordings are then fed as usual (`ReplayFeeder`, or trace_gate's `feed_ring`).

**One build for record, replay and trace.** The recording build carries the trace_gate trampolines for the default
target set (`trace_gate.default_targets()`: `equivalent/`, the demoted ones, 300 matches), but **every entry is
left alone** (`trace={"patch_entries": False}`).
- With the entries left alone, the build behaves like the plain recording build. A replay from boot of a
  recording made with it was identical (514 of 514 checkpoints).
- `trace_gate.py --from-snapshot/--from-frame` arms only its own targets: it writes their table entries (`next`)
  and the 5-byte entry `jmp`s over GDB. QEMU drops the stale translations of written code.
- Targets added to `equivalent/` after the recording aren't in its build, so they can't be armed from its
  snapshots. A trace from boot, or a new recording, covers them.

### Results (`build/replays/snaprec.json`)

The recording is a stand-in run: 10 min, 15,408 frames, a snapshot every 1.5 min plus one on request (SIGUSR1),
7 in all.

| | |
|---|---|
| a snapshot | 0.06–0.08 s paused, about 60 MB in the overlay (423 MB for 7) |
| recording speed | 15,408 frames in 600 s, against 14,053 for the same stand-in without snapshots (`final2`): no measurable cost |
| build with the trampolines | 7 s (cached objects) |
| resume (copy, boot, loadvm, convert) | 1.2–1.3 s after xemu starts |

| Replay | Checkpoints after the snapshot |
|---|---|
| from boot | 514 of 514, identical |
| from s0 (frame 2,058) | 445 of 445 |
| from s2 (frame 5,398) | 334 of 334 |
| from s3 (frame 7,990) | 247 of 247 |
| from s6 (frame 14,837, the last) | 19 of 19 |

**Two trace_gate shards in parallel from s4 (frame 10,308), 6 min each.** `HULK_XEMU_INSTANCE` was 0 and 1, and
the shards used `--shard 0/2` and `1/2`.
- Both stayed on the recorded path: 126 of 126 and 145 of 145 checkpoints matched.
- Shard 0 captured 891 good calls of 471 equivalent functions (11 failed); shard 1 captured 1,177 good calls of
  466 functions (23 failed).
- `--merge` gave one session: 2,148 calls, 974 functions.
- `equiv_replay.py --equivalent --max-calls 5` on it: 860 agreed, 1 mismatch, 22 no_replay, 55 unsupported,
  14 not_reached. The mismatch is `0x1f9710` ("argument 4 is an address in ours"), which was already a known one.

### Costs and caveats
- **Disk:** ~60 MB per snapshot, so about 1.4 GB for a 2-hour recording at the default 5 minutes. The overlay
  and the `.rec.xbe` stay in `build/replays/` (untracked).
- **Old recordings:** recordings made before this have no snapshots. `--snap-every 0` records without them, on
  `-snapshot` as before.
- **Host:** snapshots are tied to this xemu (0.8.136) and to the machine setup (64 MB, the pad topology).
- **Trace targets:** a recording's trampolines cover the trace targets as of recording time.

## Snapshot resumes that diverged at frame 51570 (play3)

Resumes of `build/replays/play3.json` from s4, s5, s6 and s8 left the recorded checkpoints at frame 51570, and
resumes from s7 and s9 didn't. Some re-joined the recording around the load at frame 52069 and some didn't. The
cause is not the snapshots. The game's streaming reads finish on the drive threads, and which frame a result lands
in follows the host. One AI decision at frame 51565 went either way. Replays from boot are exposed in the same way.

### What differs

- **At 51570 only the gameplay RNG differs.** The camera, GameClock and boot step hash the same. Between 51540 and
  51570 the recording drew the RNG 50 times; the s5 resumes drew 51, the s4/s6/s8 ones 52. Both bad hashes are the
  recorded state stepped once or twice more.
- **The extra draw is one more frame of avoidance.** A guest-side log of every RNG accessor call
  (`build/snapdiv/rnglog2.py`: logger code written over GDB into the build's unused `rnglog` area, no breakpoints)
  matched call for call, with the same RNG states, from the snapshot to 51565. At 51565, the bad runs call
  `CPathAgent::vfunc_4` (0x1050d0) → `CAvoidBehaviour::vfunc_4` (0x109c00) → `vfunc_3` (0x10a040) once more, and
  its sweep draws at 0x10a4aa. In good runs that behaviour's last update is at 51564.
- **The two objects involved are the same up to then.** Copies of the character and the behaviour, taken at every
  update from 51555 to 51564 (`snaplog.py`), were byte-identical between a good and a bad run.
- **The drive threads were busy right then.** A log of the `core::DriveThread` request handler (`call [edx+0xc]`
  at 0x273210) shows dozens of request steps per frame from 51554 to 51565, and a new request at 51562 that was
  still running at 51594.

### It was never per-snapshot

The same snapshot gives either result, depending on how the host runs:

| Resume of s8, to 51600 | 51570 |
|---|---|
| plain: the original run, and one with the rain generator moved | bad, bad (52 draws) |
| plain, idle host, 4 runs (two of them with `iosync` or a pre-read disk clone, which did nothing) | good ×4 |
| throttled (xemu SIGSTOPped 70 ms of every 100 ms), 4 runs with various other options | bad ×4 |
| VM stopped over GDB at some frames (breakpoints, memory dumps) | good in 7 of 9 |
| guest-side RNG logging (a few instructions per RNG call) | bad ×4 |

The s7 resume matched in one run and missed in another (a halt that spins the game thread at 51540).
- A VM stop lets the host finish outstanding reads while the guest stands still, so they complete "early".
- Throttling stops xemu while QEMU's virtual clock runs on, so every frame takes more emulated time.

Neither changes any input the hooks pin. Which way the race goes depends on the host.

### Ruled out

- **A savevm/loadvm gap.** Nothing was found missing after `loadvm`. Every checkpoint before 51570 matches in
  every run, good or bad. Runs from one snapshot differ from each other only in timing.
- **The sound generator** (`snd_rng`) is not reproduced from run to run. A resume of s8 reaches s9's frame with
  28,042 calls against s9's 28,070. That is the audio hardware's real time, and it doesn't reach the gameplay RNG.
- **`iosync`.** It waits at `PumpPlatformServices`, and never waited (`io_waits` = 0). No request is pending
  there: requests are posted during the frame and completed before the next pump. The game reads their results
  in between.
- **The rain effect (0x1f7320).** It is not sound, but sound-rng puts it on the sound generator
  (`patch_xbe.SOUND_RNG` sites 0x1f7362 and 0x1f74b7, labelled "voices"). Every ~0.05 s of game time it raycasts
  from a random point near the player and sends the object hit a `Damage_<kind>_<material>` event (0x1f6cd0).
  - Its draws are host-timed, because they share a stream with the sound code's.
  - Moving it to a private generator over GDB changed every rain hit from s8 to 51570 and changed no checkpoint.
  - Then it still parted at 51570, both plain and throttled.
  - It is left as is, but it remains a host-timed input in principle.
- **A cold page cache for the disk clone.** Reading the clone before starting changed nothing.

### Fix: `syncio` on resumes

`tools/hybrid_test.py` `install_syncio`, which `resume_snapshot` runs by default:
- After every request the main thread posts to a drive thread (`core::DriveThread` 0x272fc0, its tail at
  0x27303f), the main thread sleeps 1 ms at a time until that drive has nothing queued or running (`+0x8c` = 0).
- Every request then completes inside the frame that made it, as on a fast host.
- The code is written over GDB into the recording build's unused `rnglog` area, so existing recordings
  (play3.rec.xbe) get it without a rebuild.
- `io_waits` counts the sleeps, `io_timeouts` the waits given up after 2 s.
- The replay result reports both as `"syncio"`.
- `--no-syncio` turns it off.
- `trace_gate.py --from-snapshot` resumes through the same function, so it is on there too.

| Resume (`replay --from-snapshot K --until-frame 52120`) | Checkpoints | Sleeps | Timeouts |
|---|---|---|---|
| s4 (frame 25,705) | 881 of 881, identical (to 52,110) | 9,565 | 2 |
| s5 (30,841) | 709 of 709 (to 52,110) | 8,616 | 2 |
| s6 (37,310) | 495 of 495 (to 52,140) | 2,804 | 0 |
| s7 (40,923) | 374 of 374 (to 52,140) | 2,435 | 0 |
| s8 (44,699) | 250 of 250 (to 52,170) | 1,618 | 0 |
| s9 (48,226) | 132 of 132 (to 52,170) | 1,117 | 0 |

s8 with syncio, throttled as above, also matched to 51600: 1,295 sleeps, no timeouts. Without syncio, throttling
had given bad ×4.

### Built in: the `syncio` flag (recordings made from now on)

The wait is now a build-time hook, so recordings and replays from boot are timing-proof as well.
- `hooks.cpp` `HF_SYNCIO` (8192, flag name `syncio`) and `hybrid_syncio_tail`: `patch_xbe.py` (`SYNCIO_SITE`) turns
  the tail of the drive post routine at 0x27303f into a `jmp` to it. With the flag, the main thread sleeps 1 ms at a
  time (the game's own `Sleep`) until that drive's `+0x8c` is 0, up to 2,000 sleeps. Other threads fall through.
  `io_waits` counts the sleeps and `io_timeouts` the waits given up (the same fields `iosync` uses; recordings don't
  set `iosync`).
- `RECORDING_PINS` has `syncio`, so new recordings carry it in their `flags`, and replays (from boot or from a
  snapshot) turn on what the recording says. `replay` now reports `"syncio": {io_waits, io_timeouts}`.
- A recording whose flags lack it (play3, play1, play2) is unchanged: it replays without the hook, and
  `--from-snapshot` still installs the GDB version (`install_syncio`). `--no-syncio` drops either.
- Proof (`record --script` with a stand-in pad script, 4,904 frames, 164 checkpoints): replay from boot identical
  twice, and identical throttled as above (18,936 sleeps, 9 timeouts).

**Re-record?** Not needed for play3, whose synced resumes match. Anything recorded from here on includes the
flag. A recording made earlier on a slow host could still contain a late completion that no synced replay
reproduces; re-record those if they diverge.

### Left open

- **Recordings made before the flag** replay from boot without syncio (only resumes have the GDB wait).
- **Cost.** Resumes run slower with the waits: 1,100–9,600 sleeps of 1 ms over 4,000–26,000 frames here. The s8
  resume to 51,600 took about 10 min against 6 without.
- **The timeouts.** The 2 in s4 and s5 (a drive still busy after 2 s, probably in a load) didn't cost a checkpoint.
  A drive that never goes idle would make every post wait 2 s.

## Trace sessions of play3 on two hosts (2026-10-20)

Every `equivalent/` function below tier 3 in `build/equiv-confidence.json` (4,072 of 5,228 at HEAD 95cc2154) was armed in
`trace_gate.py` runs over play3, sharded **by time** across mac1 (M1 Max) and mac2 (M3 Max), then replayed.

| Segment | From | To (`--until-polls`) | Frames | Host |
|---|---|---|---|---|
| A | boot | s3 (1158542) | 0–20.9k | mac2 |
| B | `--from-snapshot 3` | s6 (1209924) | 20.5k–37.3k | mac2 |
| C | `--from-snapshot 6` | stopped by hand | 37.3k–41.3k | mac1 |
| C2 | `--from-snapshot 7` | s9 (1222003) | 40.9k–48.4k | mac2 |
| D | `--from-snapshot 9` | stopped by hand | 48.2k–52.0k | mac1 |
| D2 | `--from-snapshot 10` | end | 52.3k–56.6k | mac2 |

All six used `--only` (the target list), `--burst 3 --per-func 10`. The checkpoints matched the recording the whole way
(for example 243 of 243 in A at frame 7,267), so every segment stayed on the recorded path. The segments merge with
`trace_gate.py --merge` (23,783 calls, 1,768 functions with a good capture).

Notes from running it:
- A segment is slow where first calls bunch up (boot: 435 frames in the first 160 s; one 126,000-stop capture took 190 s)
  and fast elsewhere (D2: 4,300 frames in 470 s on mac2). mac1 stalled for minutes at a time with two instances running
  (single captures of 500 s and more); one instance per host was steadier.
- **A function that runs only at start-up is lost when its caller is armed too.** `gates_skipped` counts a gate hit that
  is deeper than `MAX_DEPTH` (3) or on another stack: the call runs uncaptured and the function is parked, but a
  start-up function never runs again. 604 targets were reached but not captured after the first pass, 566 of them at
  poll 0 (CRT and static initialisers). A second pass of **24 disjoint shards** (`--shard K/24`, `--until-polls 30`, about
  1 min each, 3 xemu at a time on mac2) captured 515 of the 543 start-up functions and cut reached-not-captured from 604
  to 47. Use `--shard` on any boot-time target set.
- `--jobs` in `equiv_replay.py` is capped at 3 (`Pool(min(jobs, 3))`), and on mac2's Python 3.9 that fork pool hung with
  idle workers. The replays ran as 6–14 separate `equiv_replay.py --only A,B,C --jobs 1 --out FILE` processes and the
  result files were concatenated into `SESSION/replay-equivalent.json` (the format `equiv_confidence.py` reads).
- A background job started over ssh ignores SIGINT; stop a `trace_gate.py` with SIGTERM. The sqlite file keeps what was
  committed (WAL), so a partial session still merges, but it has no `session.json` and no census.

### Result

| | before | after |
|---|---|---|
| tier 3 (replay verified, 3 or more calls agreed) | 1,156 | 2,646 |
| tier 2 (replay agreed on fewer than 3) | 1,114 | 640 |
| tier 1 (fuzz only) | 2,952 | 1,932 |
| tier 0 (mismatch or excluded) | 6 | 9 (see below) |

The 4,072 targets: 2,120 agreed on at least one call, 6 mismatched, 164 `unsupported` and 35 `no_replay` (the replayer
can't run them; see the replay summaries), 47 reached but not captured (capture failed: frame differs, other path,
timeout), **1,700 never ran in play3**. Those 1,700 are the real gap: nothing short of new gameplay (other levels,
modes, menus) reaches them. `build/traces/capture-wanted.txt` is the older list of the same kind.

Disagreements at HEAD (not fixed here; `equivalent/` was not edited):

| Function | Calls | What differs |
|---|---|---|
| 0x0001b280 | 0 of 10 | the original makes a call to the 6-byte thunk at 0x002fb600 as its call #2 and ours makes one call fewer, on all ten recorded calls. Fuzzing passed 3,007 inputs, so the path is one the fuzzer's callee stubs don't reach |
| 0x000aa680 | 6 of 7 | write to `this+0x28c` before call #19: ours 0x3e18f7f6 (0.149), original 0x4059d51b (3.40), 12 bytes differ |
| 0x0015f6b0 | 0 of 7 | the local passed as argument 2 of 0x0022b170 is 0x5a5a5a5a in ours and 1.0f in the original: an uninitialised local |
| 0x000ef030 | 4 of 10 | call #5 to 0x000f7d30 declared with 0 stack bytes; it takes 4 (`ret 4`): chained-call words on the wrong call |
| 0x0024d840 | 0 of 6 | call #4 to 0x0025fb00, same: takes 4 stack bytes, declared 0 |
| 0x0028faa0 | 0 of 10 | call #2 to 0x0022ca90, same: takes 8, declared 4 |

The last three had uncommitted edits in the working tree while this ran (another agent), so the committed versions are what
disagree; replay them again after that lands. 0x000f6530 and 0x002a4b00 were already tier 0 from earlier sessions.

Where the results live: `tr1` (merged A–D2), `tr1-E` (a boot-only pass, 39 functions), `tr1-F` (the 24 start-up
shards, merged), `tr1-G` (the 61 later one-shot targets, boot to s3) under `build/traces/`, each with
`replay-equivalent.json`. `equiv_confidence.py` reads them like any session. The `// STATUS:` line in `equivalent/` stays
the fuzz result: nothing in this repo writes trace results into the headers; the tier file carries them.

#### Follow-up (fx23, 2026-10-20): the disagreements fixed, stale results refreshed

All three real disagreements came from the **layout of our locals**, not from the logic. The replay places what a callee
wrote into the caller's frame relative to the pointer it was given, so ours must lay the objects out as the original does
(a callee's write to one local must not land on a neighbour, and a write placed relative to another pointer must hit the
same local):
- 0x0001b280: the callee 0x0001b170 fills `limit, axis, target` through three pointers; the original has them in that
  order at consecutive addresses and ours had `limit, target, axis`, so `target` stayed 0 and ours returned early (one call
  fewer). A `struct { float limit; int axis; Object *target; }` local gives the original's layout. 10/10 agree.
- 0x0015f6b0: a recorded write into `ex` (the first `Vec3::FUN_0022d290` result) is keyed to `&axis + 40`; the original
  has a 4-byte slot between `v90` and `ex`, ours had none, so the write missed `ex` and `qA.FUN_0022b170` read 0x5a5a5a5a.
  Making `adz` addressable (`(*(volatile float*)&adz);`) adds the slot (the frame grows from 0x10c to 0x110 bytes, a
  difference from the original). 7/7 agree; branch coverage is now 122/122.
- 0x000aa680: the 8-byte write by 0x000a04c0 through `&a` (`a` and `b` adjacent in the original) overran into our `dist`
  because `b` lay 8 bytes away from `a`; `dist` became 27.5 instead of 118 and key 5 got the wrong time. `struct { float a, b; }`
  with reference aliases makes them adjacent. 7/7 agree.
- 0x000ef030, 0x0024d840, 0x0028faa0 (the chained-call fixes of 7553f51f) agree on every session at HEAD (15/15, 6/6,
  26/26 on `tr1` plus the segments); 0x000f6530 and 0x002a4b00 agree on all `tr1*` sessions at HEAD (the old tier 0 came
  from before round 12).

Sources for the first three are in `build/farm/bench/claude-equiv/pass/` for the 20000-input promotion.

Refresh of the stale results: the equivalents whose source changed since a session result was made were replayed at HEAD
on mac2, one in-process process per shard (no fork pool): 672 functions captured in the `tr1*` sessions (610 agreed, 12
`no_replay`, 50 `unsupported`, no mismatch) and 605 captured in the older sessions (`g-play2`, `p*`, `s2`, `x-*`, ...,
copied to mac2 for this; 532 agreed, 23 `no_replay`, 50 `unsupported`, no mismatch; 14 more were not captured in any session
on that host). The results are in `build/traces/replay-fn-mac2.json` and `replay-fn-mac2old.json`; with them
`equiv_confidence.py` gives tier 3 on 2,729 of the 5,201 sources (was 2,646), tier 0 only on the three still-unpromoted fixes
plus the four excluded ones.

### A second host for xemu (mac2)

Set up like mac1, in `~/hulk-tr1`, without touching the existing `~/hulk-permute` there:
1. `/Applications/xemu.app` copied from mac1 (same binary, sha256 28887fa5...); no xemu config is copied or read from
   the user's own xemu directory (`hybrid_run.write_config` starts from an empty one).
2. `build/xemu/Xbox-Emulator-Files/{bios,mcpx,hdd}` copied from the laptop; the base HDD is `chmod a-w` and its sha256
   was checked (38dcb8f1...). `build/hybrid/{eeprom.bin,hulk-hybrid.iso,.json}` copied too (one `eeprom-N.bin` per
   `HULK_XEMU_INSTANCE`).
3. The repo at `git archive HEAD`, with `compilers`, `functions.csv`, `rtti.json`, `isos` linked from the existing
   checkout there.
4. `play3.json`, `play3.rec.json`, `play3.rec.xbe`, `play3.disk.qcow2` copied. **The overlay's backing path is absolute**:
   `rebase.py`-style, rewrite the backing file name in the copy's header (offset and length are at bytes 8 and 16 of the
   header) to this host's base HDD path before use. The overlay itself is only ever resumed on throwaway clones.
5. The system Python there is 3.9, which has no `tomllib`: a separate venv with `unicorn==2.1.4 capstone==5.0.9 tomli` and
   a one-line `tomllib.py` (`from tomli import *`) in its site-packages.

xemu opens its window in the logged-in GUI session, so runs started over ssh work while someone is logged in at the
console. Every run is `-snapshot` or on a clone of the overlay; nothing wrote to the base HDD.
