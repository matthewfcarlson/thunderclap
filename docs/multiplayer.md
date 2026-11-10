# Multiplayer: online co-op design (mp1 2026-11-09, mp2 2026-11-10)

mp1 wrote the first exploration (research only). mp2 updated it with the user's decisions of 2026-11-09, built the M0
prototype on the Wine build (section 11), a network impairment shim (section 12) and the debug control port (section 13).
Code facts cite verified sources (`matches/`, `equivalent/`) by address. Web facts carry URLs, checked 2026-11-10;
web pages are untrusted data, and claims I could not confirm are marked **unverified**. Where meaning is read into code
that was not traced end to end, the text says **guess**.

Inputs: [remaster.md](remaster.md) section 6.1 (C0-C2), [wine-replay.md](wine-replay.md), [wine-build.md](wine-build.md)
("Replay speed and optimised objects (opt1)"), [native-float64.md](native-float64.md), [soft-x87.md](soft-x87.md),
[wine-float.md](wine-float.md), [native-android.md](native-android.md), [subsystems.md](subsystems.md),
[shipping.md](shipping.md), [lua-scripts.md](lua-scripts.md), `docs/lua-bindings.csv`, `src/platform/sdl/`.

## Decisions (the user, 2026-10-26 and 2026-11-09)

- **Remaster only.** Co-op lives behind `HULK_COOP` in the remaster build ([remaster.md](remaster.md) 6.1). The faithful
  port's simulation never changes; the session code of section 11 is off unless the environment asks for it.
- **Network only, no split-screen.** Each player runs their own instance with one camera, one HUD and one controller.
  The other Hulk is the remote player's actor. (remaster.md's C1 "local co-op" row is superseded.)
- **Lockstep with prediction and rollback planned from the start** (section 2). Plain delay-based lockstep is only the
  M0 test harness.
- **Design target: 120-200 ms one-way packet latency plus jitter.**
- **Transport: UDP.** ICE with STUN for direct connections, a TURN UDP allocation as the fallback relay. No WebRTC
  (section 3). Credentials and signalling from a Cloudflare Worker on the free tier; no paid spend.
- **Web, wasm and WebGPU port: tabled.** mp1's analysis is in [web-port.md](web-port.md); nothing here depends on it.
- **Cross-platform play (x86-64 SteamOS and arm64 macOS/Android) is required on day 1** (section 4).
- **Respawn as if Ultimate Destruction had shipped with co-op**, Halo-style: a dead player respawns once no enemies are
  around (section 8). **Co-op works in free roam** as well as in missions.
- **Player 2 is a second Hulk with a different skin**; the two characters must differ (section 6.5).
- **The host's save drives the session** and is transferred to the guest (section 6.6).
- **Mission scripts stay untouched.** The single-player script API gets a co-op meaning in our C++ bindings, plus engine
  events; our own original Lua add-ons only as a last resort (section 9). Game scripts are game content: never
  committed, shipped or quoted.
- **Prerequisite:** the maintainer checks with their employer before any public repository, public binary,
  notarization, or public network endpoint (the Worker, a TURN key in a shipped binary). Builds from source used by
  the maintainer's own machines avoid most of this.

## Summary

Each instance simulates the whole game; peers exchange only pad states (18 bytes per player per frame, 30 Hz). At the
target latency (4-6 frames one way, 8-12 round trip) plain lockstep needs about 8-12 frames of input delay per player
(270-400 ms), which M0 measured (section 11.3), so the design is **rollback with a small input delay**: 2 frames of input delay, up
to 8 frames of prediction, frame-advantage throttling, and resimulation of the mispredicted frames inside one 33 ms
tick (section 2). The pieces that exist: a Wine build that replays play3 bit-identically across hosts for 60,000
frames; and now (mp2) a live session mode in which a second instance takes every pad read from the first over UDP,
with a wider state hash (actors, health, life state, mission state; no camera) compared every 30 frames. The pieces
that do not exist: whole-state snapshot and restore (section 2.5), the 64-bit builds running the game (cross-platform
determinism, section 4), the transport (section 3) and the co-op gameplay layer (sections 6-9).

## 1. The engine and the models

### 1.1 What the engine is

- **One thread runs the simulation.** `CGame::MainLoop` 0x87940 → `CGame::Tick` 0x87630 → `GameClock::Update` 0x86450
  → in GS_GAME, `UpdateSimulation` 0x88c30 (about 25 subsystem updates with one dt, physics 0x1e6f10). Then
  `CGame::Render` 0x86cb0 ([subsystems.md](subsystems.md) section 3). Gameplay is paced to 30 fps. The timestep is
  measured (clamped at 66,666 µs) in the original; the replay pins make it fixed.
- **Other threads exist but do not compute game state:** the drive thread (`core::DriveThread`), the audio mixer, and
  a loader fiber (radcore, 0x26d990-0x26dd10).
- **Heaps:** the game's XAPI heaps are host `calloc` blocks in the port (`src/platform/sdl/xdk/memory.cpp`), not one
  arena. The world streams continuously (rooms, `wsm_*`).
- **About 4,244 classes and no serialization** of game objects outside saves.

### 1.2 Models

| Model | Fit |
|---|---|
| **Deterministic lockstep with rollback** (chosen) | Each peer simulates everything; only inputs travel. Needs bit-identical simulation on every target, a whole-state snapshot/restore and resimulation of several frames inside one. The simulation is single-threaded and already deterministic under the replay pins. |
| Delay-based lockstep without rollback | The same determinism without snapshots, but at 120-200 ms one way the input delay is 8-10 frames (sections 2.1, 11.3). Kept as the M0 harness and as a "LAN mode". |
| Host-authoritative state sync | Replication for a codebase with no serialization and thousands of classes. Rejected. |
| Video streaming, split-screen | Rejected (each player runs their own instance; no split-screen). |

### 1.3 What makes the simulation deterministic today

From the replay work ([wine-replay.md](wine-replay.md), pins 1-12). Each pin is also a session requirement:

| Source of nondeterminism | Pin today | Session needs |
|---|---|---|
| Frame time (QPC) | `HULK_VCLOCK=1`: 33,333 µs per Update (`xdk/timing.cpp`) | the same fixed dt on every peer; real-time pacing (`HULK_FPS_CAP`, `pddi/sdl_platform.cpp`) stays outside the sim |
| Pad poll rate limited by real time (the `jb` at 0x26918b) | poll on every call (`hulk_hook_pad_poll`) | same; inputs keyed by **pad read index**, which equals a per-frame key once the frame is known (section 11.1) |
| New-game seed `Seed(GetMicroseconds())` at 0x8668e | the recording's seed | the session seed chosen by the host |
| Sound code drawing from the gameplay RNG (0x964d0 call sites, `rand()` at 0x260ae2, sequencer 0x113e0) | private generators per call site | same (voice timing is host-dependent) |
| Voice-end timing (scripts wait on dialogue) | `HULK_AUDIO_CLOCK=frame` | same; the live mixer follows sim frames and handles device drift (resample or drop) |
| Which frame a file read completes in | `HULK_SYNCIO=5`, lockstep drive I/O | same; a slow disk makes everyone wait |
| `GetLocalTime` | `vdate` | the session date |
| Uninitialised memory | case by case; heap blocks are zeroed (`memory.cpp`) | zeroed heaps and stacks on every build |
| Floats | the Wine build: SSE2 with `-ffp-eval-method=double -ffp-contract=off`, x87-keep functions, retfix/castfix ([wine-float.md](wine-float.md) 13) | section 4 |
| Pointer values (ASLR, 32 vs 64 bit) | not pinned | **risk**: any hash, sort or ordering by address differs between machines and between 32- and 64-bit heaps; found by cross-machine runs |
| Allocation size and exhaustion | not pinned | 64-bit objects are larger: cap pools by count, give all builds the same headroom |

The Wine build replays play3 with checkpoints matching the original to the end of the recording (56,550) and is
identical across three runs on two hosts at all 60,001 frames ([wine-replay.md](wine-replay.md)). M0 (section 11)
adds the live case: two instances, one fed over the network.

## 2. Latency budget, prediction and rollback

### 2.1 The numbers at 30 fps

One frame is 33.3 ms. At the design target:

| | one way | round trip |
|---|---|---|
| base latency 120-200 ms | 3.6-6.0 frames | 7.2-12 frames |
| plus jitter (p99 +30-60 ms on Wi-Fi/cellular, **unverified** typical figure; the shim's default pareto tail) | 4.5-7.8 frames | |
| plus send cadence (an input leaves at the end of its frame: up to 1 frame) | 5.5-8.8 frames | |

**Plain lockstep** can simulate frame F only when every peer's input for F has arrived. With an input delay of D frames
(an input pressed at F is applied at F+D and sent at once) a peer waits unless D ≥ one-way latency + jitter + cadence,
so **D ≈ 6-9 frames (200-300 ms) before anything the game itself adds**; M0 measured 8-12 frames per side for smooth
play with the shim's jitter and loss (section 11.3). That is
unplayable for a brawler (a punch 0.3 s after the button), which is why rollback is planned from the start.

**Rollback** applies local input after a small delay D (hides part of the latency and reduces resimulation) and
**predicts** the remote input for frames whose input has not arrived (repeat the last known pad state). When the real
input arrives and differs, the instance restores the snapshot of the first mispredicted frame and resimulates up to the
present inside the current tick.

| parameter | proposal | why |
|---|---|---|
| input delay D | **2 frames** (67 ms), user-tunable 0-3 | removes 2 frames of every rollback; 67 ms is below what most players notice in a brawler (**guess**; to be playtested) |
| prediction window (max rollback) | **8 frames** (267 ms) | covers one-way 200 ms + jitter + cadence - D ≈ 4-7 frames with margin. Beyond it the instance stalls instead of predicting further |
| typical rollback depth | 4-6 frames at 160 ms one way | (latency + cadence)/33 - D |
| snapshot cadence | every frame inside the window (ring of 9) | a rollback restores the frame before the first misprediction |

**How often a rollback happens.** play3's recording has an input change on **4.2% of frames** (2,445 of about 58,500
frames; 17,915 pad-state entries over 1,231,391 polls, `tools/replay_pack.py` load of `build/rp1/play3.hrp`). So
"repeat the last pad state" mispredicts on about 1 frame in 24 per remote player. Analog sticks of a live pad change
more often than the recording's quantized ones (**unverified**): quantize sticks to the recording's precision before
sending (the hybrid `quant` flag already does this for recordings), and treat stick changes inside a dead band as no
change.

### 2.2 Resimulation cost (measured on the Wine build)

A rollback of R frames costs R extra simulation steps inside one tick, with rendering, audio mixing and file I/O
suppressed. The Wine build's headless replay is exactly that kind of loop (noop renderer, `HULK_AUDIO_NOMIX=1`, the
frame audio clock, lockstep drive I/O). From opt1's measurements (play3 to frame 60,000, [wine-build.md](wine-build.md)
"Replay speed"):

| image | mac2 | studio | mac1 | per frame (mac2) |
|---|---|---|---|---|
| `--opt o0` | 122.7 s | 137.6 s | 186.1 s | 2.0 ms |
| `--opt hot` | 106.0 s | 116.5 s | 164.4 s | 1.8 ms |
| `--opt all` | 91.2 s | 105.1 s | 141.1 s | 1.5 ms (658 fps) |

Gameplay frames are slower than the average (loads and menus are cheap): `HULK_FPS_LOG` gave 2.4-5.6 ms per gameplay
frame on the -O0 image before opt1. MP2's own measurement of the worst frames is in section 11.4.

**Budget.** With a rollback of R frames in a tick, the tick needs (R + 1) simulation steps plus one render inside
33.3 ms. Taking render and present at 10-15 ms (**guess** for the remaster renderer on a handheld), the simulation gets
18-23 ms:

| R | sim budget per step | the Wine build's gameplay frame (2.4-5.6 ms, -O0, Rosetta x87) |
|---|---|---|
| 4 | 3.6-4.6 ms | fits on average, not at the worst frames |
| 6 | 2.6-3.3 ms | does not fit at the worst frames |
| 8 | 2.0-2.6 ms | does not fit |

The Wine build spends a large share outside game code (Rosetta's x87 emulation: one instruction after `fsqrt` had 9.7%
of the samples; the audio mixer 13-15% before nomix). A native arm64 or x86-64 build at -O2 without Rosetta should be
several times faster (**unmeasured**: the 64-bit builds do not run the game yet). **Native needs about 2.5 ms per
gameplay step at the worst frames on the slowest target (Steam Deck, Android handhelds)** for 8-frame rollbacks; 4 ms
is enough for the typical 4-6. Mitigations: rollbacks are rare (1 frame in 24 mispredicts), so an occasional deep
rollback can spread over two ticks by slowing the local clock one frame (time sync, 2.3); and the resimulated frames
skip particle and effect updates that do not feed the simulation (to be proven per subsystem, **risk**).

### 2.3 Input redundancy and time sync

- **Redundancy.** Every packet re-sends all inputs the peer has not acknowledged (M0: up to `HULK_NET_REDUNDANCY`=32
  frame records, about 16 bytes per frame without changes). A lost packet then costs nothing as long as the next
  one arrives; with 30 packets per second, a 3% random loss is invisible. Bursty loss longer than the prediction
  window stalls.
- **Acks** carry the highest frame received contiguously, so the sender trims its resend list.
- **Frame advantage and throttling** (GGPO-style). Each peer estimates the remote frame as `remote_frame_in_last_packet
  + RTT/2 / 33.3 ms`. If the local frame is ahead of that by more than one frame on average over a second, it waits one
  frame (a 33 ms hitch spread out as one duplicated frame every few seconds) so that neither side runs ahead and
  forces the other into deeper rollbacks. M0's `HULK_NET_LEAD` is the crude version (a hard cap on the lead).
- **Session start** is a barrier: both peers start frame 0 when both have the session settings and the host's save.

### 2.4 What the player feels

- **Own Hulk**: responsive (input delay D = 2 frames, plus the game's own one to two frames).
- **Partner's Hulk**: predicted; when the partner presses a button the local view of the partner snaps by up to the
  rollback depth (a punch starts 4-6 frames "late" and the animation skips its first frames). Smoothing the partner's
  rendered transform for a few frames after a correction hides the snap (presentation only, never fed back to the sim).
- **Enemies** react to the partner's real inputs after a rollback: an enemy that was predicted to keep walking may snap
  into a hit reaction. This is the usual rollback artefact.
- **Sound and effects** of resimulated frames are not replayed: sounds started in a mispredicted frame keep playing
  unless the corrected timeline cancels them (GGPO games accept this; a voice-id ledger can stop the orphans).

### 2.5 Snapshot and restore

What must be saved for a rollback is everything the simulation reads:

| state | size | in the snapshot |
|---|---|---|
| the game's heaps (actors, AI, physics, scripts' Lua states, scene graph) | the Xbox title budget is 64 MB including textures and audio; the simulation's share is **unmeasured** (estimate 20-40 MB) | yes |
| `.data`/`.bss` of the image (globals, RNGs, singletons) | about 1-2 MB in the original's layout (**unverified**) | yes |
| main thread and loader fiber stacks | KB | not needed if snapshots are taken at the frame boundary, where the main stack is at `CGame::Tick` and the loader fiber is idle (**to verify**: the fiber can be mid-load) |
| render state (bgfx resources, pddi caches), audio voices and mixer, file handles, drive requests in flight | — | **excluded**: render reads the sim; audio voices are re-derived (the frame audio clock makes voice state a function of the sim, but the device side is not); lockstep I/O completes every request inside its frame, so none are in flight at the boundary |

**Implementation route:** route every game allocation into one arena (a reserved virtual range, our allocator; also
needed for pointer determinism across builds), then snapshot by **copy-on-write dirty pages**: `mprotect` the arena
read-only at each snapshot and copy a page on its first write (macOS, Linux, Android all support it; Windows is not a
target). A frame touches far fewer pages than the arena holds (**unmeasured**: the control port's `snapshot` command is
where this gets measured). A full copy of 32 MB at 10-20 GB/s is 1.6-3.2 ms, too slow for every frame but fine as a
fallback every N frames with resimulation from the last full copy. **Rolling back across a streaming load** (a room
loaded in a mispredicted frame) is the hard case: lockstep I/O makes loads frame-exact, so the rule is to never predict
across a frame whose simulation posted a drive request (stall instead).

## 3. Transport

**What travels:** per frame each player's pad state (18 bytes, quantized), its frame number, acks, and every 30 frames
a state hash. M0's packets are 32-byte headers plus 16 bytes per frame record and 24 bytes per pad change; at 30
packets per second that is about 2-4 KB/s each way plus UDP/IP overhead (about 1 KB/s), roughly 15 MB per hour per
direction. Unreliable, unordered datagrams.

**Path:** plain UDP. **ICE** (RFC 8445) gathers host, server-reflexive (STUN) and relayed (TURN) candidates and picks
the best pair that works; most home NAT pairs connect directly once STUN gives each peer its public address.
Symmetric NATs and CGNAT need the **TURN UDP allocation** (RFC 8656), which forwards bytes and adds about one extra hop
of latency (the relay is at the nearest Cloudflare location of each peer, **unverified** placement). No WebRTC: no DTLS
or SCTP, no libdatachannel (the web client is tabled).

**Library: libjuice** ([repository](https://github.com/paullouisageneau/libjuice), read 2026-11-10): "licensed under
MPL 2.0" (file-level copyleft: our own files stay ours; changes to libjuice's own files would be published). A "simplified
full ICE agent (RFC5245 then RFC8445)", STUN (RFC 5389 then 8489) and "TURN relaying (RFC5766 then RFC8656)", **UDP
only** ("Only UDP is supported as transport protocol and other protocols are ignored": matches Cloudflare, which relays
UDP only). No required dependencies (Nettle optional). Builds on Linux, Android, macOS, iOS and Windows (MinGW and MSVC).
It is the ICE layer libdatachannel uses. One stream of datagrams per agent (one component) is all we need. Not
checked: whether it can send before ICE completes (we don't need to), and its behaviour under Wine (the Wine build
would use it only for tests; plain sockets suffice there, as in M0).

**Credentials and signalling: a Cloudflare Worker** (design only; nothing deployed):

- **TURN credentials.** Cloudflare Realtime TURN issues short-lived credentials: `POST
  https://rtc.live.cloudflare.com/v1/turn/keys/$TURN_KEY_ID/credentials/generate-ice-servers` with `Authorization:
  Bearer $TURN_KEY_API_TOKEN` and `{"ttl": 86400}` returns `201` and an `iceServers` list:
  `stun:stun.cloudflare.com:3478`, `turn:turn.cloudflare.com:3478?transport=udp`, `turn:turn.cloudflare.com:443?transport=udp`
  (plus TCP/TLS URLs we ignore) with a `username` and `credential`; revocation is `POST .../credentials/$USERNAME/revoke`
  ([generate credentials](https://developers.cloudflare.com/realtime/turn/generate-credentials/)). Credentials can be set
  to expire "up to 48 hours in the future"; there is "no maximum duration limit for a TURN allocation"; relay addresses
  are IPv4 only; "TCP relaying" is not supported ([FAQ](https://developers.cloudflare.com/realtime/turn/faq/)). The Worker
  holds the API token as a secret, so no key ships in a binary; it mints a credential with a TTL of a few hours per
  session.
- **Cost.** STUN at `stun.cloudflare.com` is "free and unlimited". TURN is $0.05/GB of egress; "The first 1,000 GB each
  month is free" and "SFU and TURN share this allowance" ([pricing](https://developers.cloudflare.com/realtime/pricing/)).
  At about 15-20 MB per relayed session-hour (both directions), 1,000 GB is tens of thousands of session-hours, and
  only sessions that fail to connect directly use it. **Unverified:** whether enabling TURN needs a payment method on the
  account; the user decides before anything is created. A Worker can cap usage (refuse credentials past a daily count).
- **Signalling and lobby.** A room code; the host's and guest's ICE candidates and session settings pass through the
  Worker (HTTP polling, or a WebSocket to one Durable Object per room). Workers Free: "100,000 requests per day", 10 ms
  CPU per request ([limits](https://developers.cloudflare.com/workers/platform/limits/)); Durable Objects with the SQLite
  backend are on the free plan (mp1, [DO pricing](https://developers.cloudflare.com/durable-objects/platform/pricing/)).
  A connection is a few dozen requests: far below the limits.
- **Zero-infrastructure fallback:** paste a connection code (candidates as text) or LAN play (host candidates only). No
  Worker needed for the first tests.

## 4. Cross-platform bit-exact determinism (x86-64 and arm64)

Day-1 cross-play means a SteamOS x86-64 build and an arm64 macOS/Android build must compute bit-identical game state.
What is in place and what is left:

| hazard | status | rule for the session builds |
|---|---|---|
| float expression evaluation | the 64-bit front end uses `-ffp-eval-method=double -ffp-contract=off` ([native-float64.md](native-float64.md) table); arm64 contracts to `fmadd` by default, x86-64 can with FMA3 | `-ffp-contract=off` on every target and every TU that feeds the sim (also platform code that writes sim state); no `-ffast-math`, no `-Ofast`; `-fno-builtin` for libm calls so the optimiser does not fold them with host libm semantics |
| host libm (`sin cos atan2 pow exp log sqrt acos ...`) | **softx87**: integer-only implementations of the x87 transcendentals, the same results on both targets (native-float64.md); `sqrt` is correctly rounded everywhere (IEEE) | the session builds call only softx87 for every transcendental the game uses; host libm is banned from sim code (a link-time check: no `sin`/`cos`/... imports from game objects) |
| x87 80-bit intermediates | the Wine build keeps 268 x87 functions; the 64-bit builds reproduce them with **x87ext** (consumers computed from the 80-bit value at 53 bits), checked to 0 mismatches in 2,000,000 per operation | as now |
| float → int conversion | **fpcvt**: the Wine build's results (0x80000000 for out of range) on both targets; x86-64 `cvttsd2si` and arm64 `fcvtzs` differ on NaN and out-of-range (arm64 saturates) | fpcvt on every conversion in sim code (384 sites today) |
| `(float)i` inside an expression, float returns | castfix, retfix64 | as now |
| denormals, FTZ/DAZ | SSE default MXCSR (no FTZ/DAZ); arm64 FPCR cleared by `entry_posix` (FZ/DN/AH off) | assert the modes at session start and after every third-party call that might change them (audio, graphics drivers on Android) |
| NaN payloads and sign | comparisons are identical on all targets; 35 functions depend on a NaN's bits (wine-build.md sweep); x86 produces the "default NaN" with the sign bit set, arm64 with it clear (`0x7fc00000` vs `0xffc00000` for float) | any NaN created by arithmetic must not reach the sim's bits: the 35 sites get an explicit canonical NaN, and the state hash includes them so a difference shows |
| integer behaviour | 32- vs 64-bit `long` in LP64 (macOS/Linux/Android): the gen headers already pin widths; signed overflow is UB that clang exploits | `-fwrapv` on session builds (**to measure** that it changes nothing on play3) |
| pointer order, allocation layout | not pinned (1.3) | one arena per build with the same allocation sequence; no hashing/sorting by address (to be found by cross-build replays) |
| compiler | one clang version for all targets (the toolchain pins it); same optimisation flags per TU | the build identity in the session handshake (section 5) names the compiler, flags and source commit |

**x87 versus SSE/NEON.** The Wine build is the verification build: SSE2 code with x87-keep functions under Rosetta. The
native builds are SSE2 (x86-64) and NEON (arm64) with x87ext and softx87 replacing the x87. The 64-bit builds are
checked against the Wine build's results function by function (`equiv.py --x64`), so if both match the Wine build they
match each other. **Cross-play is between native builds only** (x86-64 ↔ arm64); the Wine build is never a session
peer, it is the reference both are gated against.

**The gate.** A determinism class is a set of builds that produce identical play3 checkpoint and session hashes:

1. each native build replays play3 to 60,000 frames and must print the same per-frame checkpoint hashes as the Wine
   build (`tools/ckpt_gate.py WINE NATIVE`, the existing replay machinery, with `HULK_CKPT_ALL=1`);
2. the M0 pair (section 11) runs across builds: x86-64 SteamOS instance A, arm64 macOS instance B, through the shim;
   every session hash must match (the session hash covers actors, health and mission state, so it is stricter than
   the checkpoint's RNG/camera/clock);
3. the session handshake refuses peers whose build identity is not in the same class.

Because the 64-bit builds do not reach the game loop yet, steps 1-2 are open (M2, section 14).

## 5. Session handshake

Lockstep refuses to start unless all of these match: (1) **build identity** (source commit, compiler, flags, a hash of
the simulation objects, the determinism class); (2) **data identity**: the XBE hash and the RCF hashes, including the
language's `sound_<lang>.rcf` (voice lengths reach scripts); only hashes cross the wire, never data; (3) **settings that
reach the sim**: tick rate, difficulty, logic aspect and FOV (remaster D7), remaster gameplay flags, tweaks; (4) **start
state**: session seed and date, the host's save (6.6).

During play: the session hash every 30 frames. On a mismatch both sides stop, write a desync report (frame, the hash
regions, the `HULK_PRNG_EVERY`/`HULK_CKPT_EVERY` per-frame dumps that `tools/ckpt_gate.py` reads) and return to the menu.

## 6. A second (remote) Hulk

### 6.1 Where the engine assumes one player

| Assumption | Where | Notes |
|---|---|---|
| **The main actor** | `CActorManager` +0x124. `am_SetMainActor` 0x25fc0 → 0x25e50 swaps it, sets the new one's controller index (+0x20a8) to **0** and hands it to a ref-holding singleton (0x1b6580 → 0x1b4c40). `am_GetMainCharacterName` 0x243d0 reads it. | The world global `DAT_004dd700` (the Sim object built by 0x88670) holds the actor manager at +0x20 and `CScenarioManager` at +0x2c. **About 76 functions read the main actor directly** (heuristic grep), mostly hulkfight AI conditions and actions, the HUD overlay, the hypnotic camera, front-end code. |
| **The actor's controller slot** | Actor +0x20a8: −1 = AI, 0-3 = pad port. `am_SetActorControllerIndex` 0x28130. `CControllerAgent::vfunc_4` 0xfd0f0 copies that pad's state into the fighter's input block at +0x1f58 (0xb3d20 → 0xb3660). | The engine separates actor from pad. But the controller list holds **one** entry (`FUN_000b3d20` returns entry `i` only for `0 <= i < 1`; `ctrl_IsButtonPressed` 0xae9f0 loops `i < 1`): co-op raises it to 2. |
| **Pads** | `HULK_INPUT_PORTS 4`, `HulkInputSource` (`src/platform/sdl/input/hulk_input.h`) | The session wrapper (section 11) already sits there; co-op gives port 1 the remote player's pad. |
| **One camera** | `FUN_001c3d90`, a lazily created singleton with **80 callers**, including 0xfd0f0 (camera-relative sticks) | see 6.3 |
| **HUD** | `COverlayManager` (`CGame`+0x2c); `hud_*` 60 bindings | local player; a teammate marker and health bar are new remaster UI |
| **AI's notion of "the player"** | section 7 | |
| **Mission flow** | `CScenarioManager` (`sm_*`), `gfm_*`; section 9 | |
| **World streaming** | `wsm_*`, rooms; focus probably the main actor or camera (**guess**) | 6.4 |

### 6.2 Players versus the local view

- **Player actors** are simulation state, identical on every instance. `P[0]` is the host's Hulk and stays the main
  actor (+0x124), so single-player code and scripts keep working. `P[1]` is created at session start with controller
  slot 1.
- **The local player index** is presentation only: which camera is drawn, which player the HUD shows, which pad rumbles,
  where the audio listener sits. It must never be read by simulation code. The session hash (which excludes the
  camera) and a test that swaps local indices between two instances catch leaks.
- **Input:** each instance reads its local pad, sends it with the frame number, and feeds every player's pad to their
  slot. The remote Hulk is driven by network inputs, not network state.

### 6.3 Cameras

Sticks are camera-relative (0xfd0f0 builds headings from the camera transform), so **every player's camera is simulated
on every instance** and only the local one is drawn: the `FUN_001c3d90` singleton becomes one camera per player, with a
current-player context set around each player's update. **Risk:** any simulation read of the *render* view (culling
counters, LOD by distance; remaster.md section 8 lists `Render::Object`'s culled counter and `CEncounterGenerator`'s view
use as unconfirmed) diverges, because each instance renders from a different camera. M0's session hash leaves the camera
out for that reason, so such a read shows up as a session-hash mismatch once two views differ.

### 6.4 Streaming and distance

A **leash**: both players stay inside the active streaming area. Past it, warn, then teleport the straggler to the
leader. Heaps get headroom for two focus points; every peer uses the same sizes.

### 6.5 The second Hulk's skin

**How skins work (read in code).** A skin is a name, not an actor property:

- The level/world loader object (`DAT_004dd700`+0x54 → `FUN_000862a0()`) keeps the selected skin as a 32-byte string at
  +0xaa4 (`FUN_00203870` writes it, `FUN_00203860` reads it) and the skin whose assets are loaded at +0xac4.
- `FUN_00203890(id)` (equivalent) maps unlockable ids 0-12 to skin names: 0 `hulk_australia`, 1 `grey_hulk`, 2
  `joefixit`, 3 `abomination_ashulk`, 4 `banner_savage`, 5-12 the national Hulks (`hulk_canada`, `hulk_us`, `hulk_uk`,
  `hulk_france`, `hulk_german`, `hulk_italy`, `hulk_spain`, `hulk_japan`). The default is `hulk`.
- At level start 0x203a10 sets `hulk`, then takes the first of ids 0-12 that is unlocked and "on" in
  `CUnlockablesManager` (`um_IsUnlockableLocked` 0x92dc0, `um_IsUnlockableOn` 0x92de0) and applies it. The save holds no
  skin field: the skin is derived from the unlockables' "on" bits.
- The front end: the `unlocked_cheats` selector under `TBS_CHEAT_CHARACTER` (built by 0xb64f0; 0xb5ca0 applies a
  choice: clear the on bits of 0-12, `FUN_00203870(name)`, set the chosen id on).
- Assets: the level load 0x206320 loads `art/global_nonchar.p3d`, then `art/global_<skin>.p3d` into **one**
  `LoadInventory` (+0xaa0), then `scripts/fight/hulk.fig` and `common.fig`; it skips the load when +0xac4 equals +0xaa4. It
  also overrides the skin for some story missions (it forces `joefixit` or a national Hulk for certain mission ids when the
  skin is `hulk`).
- Actors come from `am_CreateActor` 0x2c050 → 0x2b970, which looks up a definition by hashed name (0x44ad0). How the Hulk
  definition finds its model in the loaded inventory is **not traced** (**guess**: by fixed names inside the skin's
  `global_<skin>.p3d`, which would make two skins' resources collide).

**Co-op rule.** P1's skin is chosen by the guest from the skins the **host's save** has unlocked; if it equals P0's (or
the host has unlocked none), P1 gets a fixed alternative so the two always differ: `grey_hulk` when P0 is `hulk`, else
`hulk`. The pair is part of the session settings (section 5). The engine work (M5): load the second skin's
`art/global_<skin>.p3d` into a second inventory (a second +0xaa0-style slot owned by our co-op code), resolve P1's model
from it, and keep the story-mission override applying to P0 only. **First check (open):** whether two `global_*.p3d`
files can be resident together or their resource names collide; if they collide, the fallback is a tint of P0's model
(a material parameter in the remaster renderer), which still makes the characters differ but is not a real skin.

### 6.6 The host's save drives the session

The game side of saves is `CGameFlowManager` (`gfm_*`): five slot records of 0xbe8 bytes at +0xac8. A record holds a
magic/version word (checked against `DAT_0049c294`), the chapter and mission block, three floats and flags, the camera
inversion options, the unlockables' "locked" and "on" bit sets (0x2fe bits each, at +0x38 and +0xb8: unlocks, purchased
moves, cheats and therefore the skin), a 100 × 24-byte table, a 50-entry table and the slot name. Functions:
`FUN_000890a0` loads a slot into memory and checks the magic, `FUN_0008b560` captures the live game into a slot,
`FUN_0008a8f0(idx, world)` applies a slot to the live game (the front-end load screen 0xda930 calls it), `FUN_00089d30`
is the new-game reset. The file layer is `core::XboxSaveDrive` over `src/platform/sdl/xdk/saves.cpp`.

**Transfer:** the host captures its slot (0x8b560's record, 3,048 bytes), sends it in the session start message with a
hash, and the guest writes it into a slot of its own `CGameFlowManager` and calls `FUN_0008a8f0` as the load screen does.
The guest's own saves are never touched (the record lives in memory; the guest's save drive is read-only for the
session). Both instances then start from the same state; the session hash's first window checks it. Not in the record
and sent separately: the skins (6.5), the session seed and date, and options that reach the sim. **Open (user):** whether
the guest earns anything (smash points, unlocks) for its own save; the simplest rule is no.

### 6.7 Keeping it in the remaster build

- Everything behind `HULK_COOP`; with one player every hook is inert, so single-player replays stay equal.
- Prefer link-level wrappers and interposition (as the replay hooks wrap 0x86450) over editing verified sources.
- Where a source must change, the `#if defined(HULK_COOP)` goes **inside the function body** (a top-level `#if` makes
  gen_tree wrap the source), and the MSVC object must stay unchanged with the flag off.

## 7. Enemies with more than one Hulk

### 7.1 How targeting works today

| Mechanism | Where | Single-player assumption |
|---|---|---|
| Default target | `hulkfight::ai::AcquireTargetCondition::vfunc_6` 0x1245b0: an AI actor with no target (+0x328), on another team, takes the main actor (handle at +0x12c). `AcquireTargetAction::vfunc_5` 0x124a80 special-cases the main actor. | the main actor is the only player candidate |
| Script-forced awareness | `am_UpdateKnownPlayerPos` 0x290a0, `...NoAttack` 0x290f0, `am_ForgetKnownPlayerPos` 0x29340 pass the main actor's handle to the AI controller (+0x1ca0); 0xfe4d0 raises the AI state to at least 3 | "the player" |
| Explicit targets | `am_SetTarget` 0x29500, `am_GetTarget` 0x295a0, forced targets, `SetDefendActor` | name-based |
| Alert levels | `SetAlertStatus` 0x29910, `GetHighestAlertStatus` 0x29990 | per enemy |
| Attack tokens, engaged set | static tracker `DAT_004dc678` (accessor 0x678d0, 33 users), up to **40 engaged actors**; 0x66390 picks the attacker for a position; `TokenCondition::vfunc_6` 0x10dcf0 asks about the main actor's position | one pool around one player |
| Spawning and caps | `CEncounterGenerator` (vftable 0x424fa4), `am_SetMaxActorCountForPerformance` (+0x32c), group caps | global |

### 7.2 What co-op changes

- **Target selection:** a choose-player function where the code reads the main actor as *the* enemy: nearest living
  player in line of sight, weighted by threat, with hysteresis. All inputs are sim state.
- **Per-player engaged sets:** the 40-slot tracker split into one budget per player under a global cap; a downed
  player's attackers return to the pool.
- **Known-position calls from scripts:** apply to the player nearest the enemy.
- **Scaling:** performance caps and group counts ×1.5, enemy health by a co-op factor (session settings).
- The remaster's planned AI revamp takes "a set of players" as input from the start.

## 8. Death and respawn "as if Ultimate Destruction had shipped with co-op"

### 8.1 What the game does today (traced, mp2)

| step | where | what |
|---|---|---|
| damage | 0x43350 → `FUN_0003b1c0` (SetHealth: health float +0x1b0c, clamped to the max at +0x1b10) | on a crossing from > 0 to <= 0 it posts an event (0x1c9a40, type 3; **guess**: `Actor_Zero_HP`) to the event queue (`World`+0x30, 0x1cbc20). It does **not** change the life state |
| life state | `FUN_0003ea10` (matches) sets actor +0x20b0: 0 alive, 1 dying/dead, 2 removed | 0 → 1 zeroes the health, posts a type-1 event (**guess**: `Actor_Death`) and clears enemies' target flags. Callers: `am_SetCharacterHealth` 0x28840, 0x25470, `RemoveActor` 0x2a4b0 |
| script kill | `am_SetCharacterHealth` 0x28840 | value <= 0 on **the main actor** calls `CScenarioManager::SetMissionState(2)` (0x1cc620) directly; any other actor gets life state 1 |
| per frame | `CActorManager` tick 0x2ae80 | an actor in state 1 times out after 1.5 s and is removed (0x2a4b0; removing the main actor nulls +0x124). **The main actor below y = -50** (-200 on two levels) sets mission state 2 unless it is already 2 or 5: the engine's fall-out-of-the-world rule |
| failure | 0x1cc620 state 2 | fade (`DAT_004dd6ec`'s panel fader) and the HUD's `story_mission_fail` or `side_mission_fail` screen; 9 and 12 also end in 2 |

There is **no C++ respawn path**: nothing in the engine revives, refills or teleports the Hulk. The event names
(`Actor_Zero_HP`, `Actor_Death`, `Game_Checkpoint`, ...) have no C++ users, so the reaction to the Hulk's death, in free
roam as in missions, is the scripts' (through the event queue) plus the fail screen's retry (**guess**: the retry handler
behind 0xbc1e0's screen was not found). Free roam and missions share the same C++ path; the only fork is the screen
choice by the chapter counter.

### 8.2 The co-op rule

A Hulk whose health reaches zero is **down**, not dead to the world:

- **Hooks:** wrap SetHealth 0x3b1c0 (a player crossing to <= 0) and SetLifeState 0x3ea10 (0 → 1 on a player). The
  downed player gets our own "down" state: the life state stays 0 for the engine (so 0x2ae80 never removes the actor and
  +0x124 never goes null), the actor plays the knockdown, becomes intangible and is removed from target candidates and
  engaged sets (7.2). The single-player fail calls are filtered while the partner is up: 0x1cc620's states 2/9/12 when
  they come from the death paths (0x28840 on the main actor, 0x2ae80's fall rule), not when a script fails a mission
  for another reason (time out, objective lost).
- **Respawn condition** (checked every frame in our C++, deterministic on every instance):
  1. the partner is up and not in an NIS, scripted camera or grab;
  2. **no enemy is engaged with the partner**: no actor in the partner's engaged set (7.2) and no actor with alert state
     >= engaged (the 0x29990-style scan) within 30 m;
  3. the partner has taken no damage for 5 s;
  4. at least 5 s since going down (the death animation and a beat of tension).
- **Where:** a valid ground point 4-8 m behind the partner, out of the partner's line of fire (the ground query
  `am_GetActorStaticGroundPoint` 0x26d50's data; not inside a building or water), with 3 s of invulnerability
  (`am_SetActorInvulnerable`'s mechanism). Health: full (0x401a0, the health initializer). Rage/meter: empty.
- **Fallback timer:** if the partner never gets out of combat, respawn anyway after **30 s** at the partner's last safe
  point (Halo's rule waits forever; a brawler with endless free-roam military escalation needs a ceiling). **User
  choice.**
- **Partner assist (remaster mechanic):** the partner can stand over the downed Hulk for 2 s (hold a button) to revive
  him at half health on the spot, even in combat. It makes co-op feel like co-op and costs one input.
- **Penalty:** free roam: lose a share of the smash points earned since the last respawn (mirrors the original's
  feel of loss without ending play); missions: none beyond the time lost.
- **Both down:** the normal single-player failure. Only then does the script world see the Hulk die (the main actor's
  health goes to zero through the original path), so the mission's own fail and checkpoint logic runs unchanged; in free
  roam, whatever the game does for a single player then happens to both (the host's main actor drives it; P1 respawns
  beside P0 when P0 comes back).

### 8.3 Edge cases

| case | rule |
|---|---|
| an objective only the downed player can satisfy (carrying an object, a "Hulk must reach X" trigger) | position triggers and "the Hulk" queries already accept any living player (9.1), so the partner can satisfy it; a carried object drops where the carrier went down and the partner can pick it up. Missions where this is not enough get a per-mission add-on (9.2 c) |
| an NIS or scripted sequence starts while one is down | respawn him at once, before the NIS (scripts take control through `am_SetActorControllerIndex(-1)` / `nism_*`, which our binding layer sees first) |
| grabbed or held when going down (`GetCharacterGrapplee`) | the grab ends on down; the respawn timer starts at release |
| falls out of the world (0x2ae80's y limit) or into a null room (`SetAlwaysKillInNullRoom`) | counts as down; respawn by the normal rule, never at the fall point. For P0, 0x2ae80's direct `SetMissionState(2)` is filtered while P1 is up |
| the partner is far away or streaming another area | respawn at the partner regardless of distance (the leash, 6.4, keeps this rare) |
| a mission fails for a reason other than death (timer, escort lost) | unchanged: both see the fail screen and retry together |
| one player disconnects | a "leave" input at a frame number removes the remote Hulk on both instances at that frame; the game continues single-player. Rejoining mid-mission is not supported: the guest rejoins at the next checkpoint by restarting the session from the host's save |
| the downed player's camera and HUD | local presentation only: an orbit or spectator view of the partner and a countdown |

## 9. Mission scripts

**Constraint:** the Lua scripts are game content from the player's disc. We never commit, ship or distribute them, or
diffs or patches derived from them, and this document does not describe their logic. Counts come from
`docs/lua-bindings.csv` (749 bindings, 479 used by scripts) and aggregate scans; no script text is reproduced.

### 9.1 How much of the API refers to "the player"

| Category | Bindings (calls / scripts) | Co-op meaning |
|---|---|---|
| Main actor identity | `am_SetMainActor` (2/1), `am_GetMainCharacterName` | P0 stays the main actor |
| Control hand-off | `am_SetActorControllerIndex` (362/68), `am_GetActorControllerIndex` (21/17), `am_SetAllActorControllerIndex`, `am_ResetAllActorControllerIndex`, `ctrl_SetButtonLock`/`LockAll`, `ctrl_IsButtonPressed` (30) | −1 on the Hulk (cutscene) applies to **all** players; a non-negative index restores each player's own slot; "any button pressed" means any player's |
| AI awareness of the player | `am_UpdateKnownPlayerPos` (555/40), `...NoAttack`, `am_ForgetKnownPlayerPos` | the player nearest that enemy |
| Actor queries on the Hulk's name | `am_GetActorPosition` (1,039/79), `am_SetActorPosition` (719/54), `am_GetActorLocatorDistance` (103/40), `am_GetActorActorDistance` (47/31), `am_GetCharacterHealth` (227/41), `am_SetActorInvulnerable` (66/38), `am_SetTarget` (746/36) | position and distance queries: the player **nearest the queried point** ("any player satisfies"); teleports move **all** players (the second offset by a small radius); health and life state report the **party** (alive while any player is up; the healthiest living player's health) |
| Camera, letterbox, NIS | `cm_*` 64 (3,452 calls), `nism_*` 7 (774) | each instance's local view; an NIS pulls both players into the shot |
| HUD, mission state, objectives, timers | `hud_*` 60 (7,076), `sm_*` 34 (1,964), `gfm_*` 22 (1,600) | shared, unchanged |
| Rumble | `hcm_EnableRumble` (15), `fmvm_SetRumbleEvent` (143) | local pad |

About 15 bindings take a co-op meaning when their argument names the Hulk, plus about 10 about control, rumble and the
main actor. Most `am_*` bindings resolve actors by name (0x2672f0 hash → 0x24280), so "is this the main actor's name?"
can be intercepted in one place, the binding layer (the registrar `equivalent/0x00031310.cpp` and its thunks).

### 9.2 Options, in order of preference

| Option | How | For |
|---|---|---|
| **(a) Co-op meaning in the C++ bindings** | In `HULK_COOP` builds, wrap the bindings of 9.1 (per-binding link wrappers or a hook in the script call dispatcher `FUN_001d22a0`) to apply the co-op meaning when the actor is the main actor | every mission and free roam, by default |
| **(b) Engine events** | Our C++ at fixed points: session start (spawn P1 near P0), mission start and checkpoint (gather both players), NIS start and end, player downed and respawned (8), all-down, mission fail and success (`CScenarioManager` 0x1cc620), objective changes (0x1ccfc0) | respawn, leash, gathering |
| **(c) Our own Lua add-ons (last resort)** | Original files written from scratch, loaded beside the game's from `mods/`; they use only the API and react to (b)'s events; never copy game script text | missions where (a) gives the wrong result |

## 10. Distribution and packaging

Unchanged from mp1's study except that the browser build is tabled. **Prerequisite:** the employer check (top).

- **macOS (arm64):** a locally built binary has no quarantine attribute and needs only the linker's ad-hoc signature. A
  downloaded one needs Developer ID signing, hardened runtime and notarization; an unsigned downloaded app needs System
  Settings › Privacy & Security › "Open Anyway" since macOS 15 ([9to5Mac](https://9to5mac.com/2024/08/13/security-bite-apple-finally-making-it-harder-to-override-gatekeeper-is-a-telling-move/)).
  Library validation blocks `dlopen` of an FFmpeg not signed by the same team (bundle it signed, or
  `com.apple.security.cs.disable-library-validation`). Talking to **LAN** peers triggers the Local Network privacy prompt
  ([TN3179](https://developer.apple.com/documentation/technotes/tn3179-understanding-local-network-privacy));
  Internet peers do not. Add `NSLocalNetworkUsageDescription`.
- **Steam Deck (SteamOS, x86-64):** the native ELF against Steam Runtime 3 "sniper" (`tools/linux_sysroot.py`);
  AppImage or Flatpak (`--share=network`), "Add a non-Steam game". Steam networking and Steam Datagram Relay are not
  available to a non-Steam game, so the lobby is ours.
- **Android handhelds (arm64):** sideloaded APK with `INTERNET`; LAN discovery needs a `MulticastLock`; Google's
  developer verification for certified devices starts 2026-09-30 in four countries
  ([Google](https://support.google.com/android-developer-console/answer/16561738)); opt out of tagged pointers.

## 11. M0: a live lockstep session on the Wine build (mp2)

### 11.1 What was built

Behind runtime flags that are off by default (nothing changes unless `HULK_NET` or `HULK_CTL_PORT` is set):

- **`src/platform/sdl/input/hulk_session.{h,cpp}`** (in `hulk_sdl.lib`, included by `input/hulk_input.cpp`): a wrapper
  around the input source the game reads. `HULK_NET=send` (instance A) passes reads through and streams them;
  `HULK_NET=recv` (instance B) answers every pad read with A's read of the same index, waiting for it. Reads are
  numbered per instance (both run the same simulation, so read *k* is the same poll on both); A groups them into
  **frame records** (the reads between two `GameClock::Update` calls, plus the reads whose state changed) and every
  packet re-sends the records B has not acknowledged. Plain UDP sockets (Winsock through `SDL_LoadObject` under Wine,
  BSD sockets elsewhere; numeric IPv4 only). Wire format at the top of `hulk_session.cpp`. A **lockstep gate**: A may not
  start frame F before B has reported frame F − `HULK_NET_LEAD`. Stats every 300 frames: stall time, frames that
  waited, wall-clock gaps between frames ("hitches" over 50 ms), RTT, lead, packets, hash results.
- **The session state hash** (`src/platform/sdl/xdk/replay_hooks.cpp`, `hulk_session_state_hash`), every 30 frames at
  `GameClock::Update`'s entry: the checkpoint hash **without the camera** (frame, gameplay RNG, boot step, GameClock),
  the particle RNGs, then every actor of the actor manager (its inline handle list at +0x10, resolved through 0x59c10 /
  0x59ba0's table) with life state (+0x20b0), controller slot (+0x20a8), health (+0x1b0c), static ground point (+0x1a84)
  and position (0x59a50's source), then the scenario manager's mission state (+0xc), checkpoint (+0x1194) and clocks
  (+0x1198, +0x119c). Plain memory reads at the offsets the bindings use; pointer values are never hashed. Both sides
  exchange their last four hashes in every packet and log each comparison.
- **The session settings** come from the recording's header: A opens play3 (`build/rp1/play3.hrp`, inputs and
  checkpoints); B opens a **header-only copy** (`tools/lockstep_test.py strip`: flags, seed, tweaks, pad count; zero
  inputs, zero checkpoints), so the replay pins (vclock, syncio 5, frame audio clock, sound/sequencer RNG isolation,
  seed) are on, and B's inputs can only come from the network. M1 replaces the header with a session mode.
- **`tools/lockstep_test.py`**: `pair` runs A, B and the shim on one host (A 90 frames past B's stop, so B's last
  inputs arrive even with loss); `peer` runs one side for cross-host pairs (with a one-way shim in front of its peer);
  `submit` sends a pair to the queue; `summary` reads the logs.

**Why read indexes and not frames.** play3 is poll-keyed: about 21 pad reads per frame, and the recording's state can
change between polls of one frame. Keying by read index reproduces it exactly; a frame record says which reads belong to
which frame, so the gate and the stats are per frame. The co-op build keys inputs by frame (one sampled state per
player per frame), which is what the rollback design assumes.

**Default build.** With neither variable set, the wrapper is not installed (`hulk_session_wrap` returns the source) and
`hulk_native_frame` calls `hulk_session_active()` once and caches 0. The Wine proof in 11.5 checks that play3 replays
identically.

### 11.2 Runs (2026-11-10)

Image: the Wine build at `--opt o0` with the session code (test lineage `mp2-test`, job 70988; the proof image of 11.5 has
the same sources). `HULK_AUDIO_NOMIX=1`, the noop renderer, play3 (`build/rp1/play3.hrp`) on A, its header on B.

| run | hosts | link | pacing, lead | frames | session hashes (A / B) | checkpoints B vs A |
|---|---|---|---|---|---|---|
| 70997 | studio, one host | loopback, no shim | unpaced, 8 | 60,000 | 2,005 / 2,005 ok, **0 diverged** | 2,005 common, 0 differ |
| 70998 | studio | shim: 120-200 ms (drew 191 and 138 ms), pareto jitter 20 ms, 5% loss with bursts (P 0.3), 2% reorder, 1% dup, seed 5; 20,257 packets dropped, 2,750 duplicated, 5,666 reordered | unpaced, 64 | 60,000 | 2,001 / 2,001 ok, **0 diverged** | 2,001 / 0 |
| 71000 + 71001 | **A on mac2, B on studio** | the LAN (Wi-Fi; ping 10-225 ms), no shim | unpaced, 64 | 60,000 | 2,007 / 2,008 ok, **0 diverged** | 2,008 / 0 |
| 71002 + 71003 | A on mac2, B on studio | the LAN | 30 fps, 16 | 9,000 | 301 / 301 ok, 0 diverged | |
| 70991-70996 | studio | 11.3 | 30 fps, 4-24 | 9,000 each | 301 / 301 ok each, 0 diverged | 301 / 0 each |

A matched the recording's own checkpoints in every run as a plain replay does (70997: 2,000 ok, the 5 known transients
5880, 5910, 34260, 52620, 52650). Both sides made exactly the same 1,234,827 pad reads over 60,000 frames (71000/71001).
The session hash resolves the actor manager's actors (1-9 of them on play3's path, logged every 900 frames) and reads
the mission state.

**Result: no divergence** in any run: same host, impaired link, or across two machines.

**Bug found on the way:** a loading screen polls the pad hundreds of thousands of times inside one frame (frames
8743-8752 of play3: 558,000 reads), and the replay's auto-START rule changes the pad every 8 polls, so one frame's
record held ~70,000 changes and never fit a datagram: both sides waited forever at frame 8743. Records now close early at
40 changes and a send emits as many datagrams as the unacknowledged records need. The co-op build sends one sampled
state per player per frame, so this volume is an artefact of replaying a poll-keyed recording, but the transport must
still never assume one frame fits one packet.

### 11.3 Plain lockstep at 120-200 ms

Paced at 30 fps (`HULK_FPS_CAP=30`, the front end at 60 as the game's flag says), play3's first 9,000 frames, the shim
at 120-200 ms one way (this seed drew 156 and 185 ms), pareto jitter 15 ms, 2% loss (seed 11); measured RTT 385-452 ms
average (base 341 ms plus jitter, FIFO queueing and the 10 ms resend cadence), about **12-13 frames**. A may run at most
`lead` frames ahead of the last frame B reported. Stalls are summed over frames 300-9000 (the start-up barrier
excluded); a hitch is a wall-clock gap over 50 ms between two frames.

| setting | A waited (frames that waited) | B waited | hitches A / B | wall time for 9,000 frames |
|---|---|---|---|---|
| no shim (0 ms), lead 8 | 5.4 s (62) | 9.5 s (137) | 13 / 8 (loads) | 926 s |
| shim, lead 4 | 512 s (3,642) | 512 s (3,668) | 3,333 / 2,661 | 1,461 s |
| shim, lead 8 | 179 s (2,544) | 180 s (2,533) | 1,697 / 1,254 | 1,094 s |
| shim, lead 12 | 71 s (2,829) | 74 s (2,949) | 824 / 397 | 955 s |
| shim, lead 16 | 17 s (531) | 17 s (498) | 167 / 78 | 930 s |
| shim, lead 24 | 5.3 s (31) | 5.2 s (3) | 24 / 7 | 926 s |
| mac2 ↔ studio LAN (RTT 107-126 ms avg), lead 16 | 5.6 s (70) | 5.2 s (2) | 30 / 7 | |

The baseline's 926 s include the loads and three real-time movies. **How to read the lead:** in M0 all of the delay
budget sits on one side (A sends its reads as it makes them; B never delays its own), so `lead` is the sum of both
sides' input delays: A at frame F needs B at F − lead, and B needs A's frame F, which arrives one way later. Smooth play
needs lead ≥ RTT in frames plus a jitter margin: at 12-13 frames of RTT, lead 16 still stalls 6% of frames, lead 24 is
smooth. **A symmetric delay-based lockstep therefore needs an input delay of about 8-12 frames (270-400 ms) per player
at the design target**, which is the case for rollback (section 2): with rollback, the same budget becomes prediction
instead of delay.

### 11.4 Resimulation speed (measured)

A plain play3 replay of the same image on studio with `HULK_FPS_LOG=1` (job 71005; frame-time windows of 120 presents
between frames 600 and 58,500, 483 windows): average frame **2.1 ms** (median window), 3.5 ms (p90 window); the worst
frame of a window **5.7 ms** (median), 9.2 ms (p90); loads reach 300 ms-2.4 s. So on the Wine build (o0, Rosetta) an
8-frame rollback of ordinary frames costs about 17 ms, and of worst-case frames 45-75 ms: rollback does not fit in a
33 ms tick on the Wine build at the worst frames. opt1's `--opt all` is 1.3-1.4× faster; native builds without Rosetta's
x87 emulation should be several times faster (**unmeasured**). The target for native stays about 2.5 ms per worst
gameplay frame on the slowest handheld (section 2.2).

### 11.5 The default build is unchanged (Wine proof)

Control 70999 (studio, lineage `mp2`, `--state fresh --map full --opt o0`, the shared `hulk_sdl.lib`) and proof 71008
(the same host, `--state seed:70999`, these sources, `--sdl-src` with the session code), play3 to frame 60,000 with no
session variables set. `tools/ckpt_gate.py 70999 71008`: 2,010 common checkpoints, control-ok/proof-diverged 0, the
same five known transients on both sides (5880, 5910, 34260, 52620, 52650), particle-RNG hashes identical at all 2,010,
**GATE ok**; `wine_build_job.py compare`: the images differ (the new code), 0 of 2,010 checkpoint hashes differ. Both
ran from `git archive` of 0c41c92ee plus the session files (build5's later renames of 16 matched sources are
byte-identical rebuilds).

### 11.6 What M0 does not do yet

- The session settings come from a recording's header (M1: a session mode).
- B's own pad is not used (there is no second player yet); the gate uses B's frame reports as its "input".
- No prediction or rollback (M3); no NAT traversal (M4: plain IPv4 addresses).
- The state hash covers the actor manager's list, not every live object (bullets, props, particles beyond their RNGs);
  a desync outside it shows up later through the RNG or an actor.

## 12. Network impairment shim (`tools/netshim.py`)

A UDP proxy that applies seeded, reproducible impairments. Every lockstep test goes through it (`lockstep_test.py pair
--shim "..."` starts one shim with two one-way links; `peer --shim-out "..."` puts one in front of a remote peer).

```sh
build/venv/bin/python tools/netshim.py run --link 42001:127.0.0.1:41002 --link 42002:127.0.0.1:41001 \
      --delay 120-200 --jitter 15 --dist pareto --loss 2 --burst 0.3 --reorder 1 --dup 0.5 --seed 7 --log shim.jsonl
build/venv/bin/python tools/netshim.py selftest
```

- **Model per link** (each direction is a link with its own generator, seeded from `--seed` and the link index): a base
  delay drawn once from `--delay LO-HI` (default 120-200 ms); per-packet jitter `normal` (|N(0,J)|), `pareto` (heavy tail,
  capped at 10 J; the default) or `uniform` (0..2J); FIFO delivery unless `--reorder` % lets a packet overtake; `--loss` %
  with optional burstiness (`--burst` = P(loss | previous lost)); `--dup` % second copies 1-20 ms later.
- **Reproducible:** decisions are drawn per packet in arrival order, so the same seed and packet sequence give the same
  drops, delays and duplicates; `--log` writes them (JSON lines) with the final counters. Wall-clock delivery is as exact
  as the host's timers (about 1 ms).
- **Self-test** (laptop, 2026-11-10): a clean link delivers 1,500 of 1,500 in order; 120-200 ms + pareto 15 ms + 5% loss
  drew a 127 ms base, minimum latency 128 ms, median 159 ms (FIFO queueing behind tail packets at a 2 ms send gap),
  4.67% loss, no inversions; 10% reorder + 5% dup gave 170 inversions and 78 duplicates; the same seed reproduced all
  1,500 decisions. `SELFTEST ok`.

## 13. Control port (debug builds)

A localhost-only UDP port for tests and start-up debugging (`src/platform/sdl/input/hulk_session.cpp`):

- **Never in release builds:** compiled only when neither `NDEBUG` nor `HULK_RELEASE` is defined (the release packaging
  must define one of them; the Wine build's `hulk_sdl.lib` is a development build). **Bound to 127.0.0.1 only.** Off
  unless `HULK_CTL_PORT=<port>` is set; `HULK_CTL_PAUSED=1` starts paused before frame 0.
- **Protocol:** one text command per datagram, one reply datagram (`printf 'hash' | nc -u -w1 127.0.0.1 PORT`):

| command | reply | what |
|---|---|---|
| `frame` | `frame F` | the current session frame |
| `hash` | `hash F H` | the last session state hash and its frame (section 11.1) |
| `pause` / `resume` | `ok` | stop before the next frame starts / run free |
| `step N` | `ok` | run N frames, then pause |
| `pad P BUTTONS LX LY RX RY [A B X Y BLACK WHITE LT RT] [for N]` | `ok` | port P reads this state (buttons in hex, the rest decimal) for N frames or until `pad P off`; on a session's send side the injected state is streamed like a real one |
| `net` | counters | role, frame, peer frame, reads, hashes ok/bad, stall time |
| `snapshot` / `restore` | `ERR unsupported` | reserved for M3 (2.5): the rollback test hook and where snapshot size and cost get measured |

- **Hooks:** the input wrapper (injection), the per-frame session call at `GameClock::Update`'s entry (pause, step, hash).
  It shares the session's per-frame hook, so it costs nothing when off (one cached flag). Native builds get it when
  `replay_native.cpp` calls the same hook (64-bit follow-up; the Wine build's `replay_hooks.cpp` calls it now).
- **Uses:** lockstep tests (query hashes from a driver instead of parsing logs, pause both sides at a frame, inject a
  divergent input to prove the hash catches it), native start-up debugging (step the first frames, read the frame
  number while a probe runs).

## 14. Phased plan

| Phase | Work | Exit criterion |
|---|---|---|
| **M0: lockstep harness on the Wine build** (done, section 11) | session mode (`HULK_NET`), state hash, shim, control port | two instances agree at every hash across hosts and under impairment |
| **M1: session mode without a recording** | the pins as `HULK_SESSION=lockstep` (vclock, syncio 5, frame audio clock, sound/sequencer RNG isolation, session seed and date) instead of a recording's flags; live SDL pad on A | a live-played session agrees across two hosts |
| **M2: cross-build determinism** (needs the 64-bit builds to run the game) | play3 on x86-64 and arm64 gated against the Wine build; the M0 pair across x86-64 ↔ arm64; arena allocator; pointer-order audit | determinism class A = {x86-64 SteamOS, arm64 macOS, arm64 Android} |
| **M3: snapshot and rollback** | arena + dirty-page snapshots, restore, resimulation with render/audio/I/O suppressed, prediction, frame-advantage throttling; the control port's `snapshot`/`restore` as the test hook | 8-frame rollbacks inside a 33 ms tick on the slowest target; a rollback test (restore N frames back, resimulate, same hash) passes every frame of play3 |
| **M4: transport** | libjuice ICE (STUN, TURN UDP), connection codes, then the Worker (credentials, rooms) after the employer check | two machines on different networks at 120-200 ms play with no desync |
| **M5: co-op gameplay (`HULK_COOP`)** | controller list of 2, P1 spawn with the second skin, per-player sim cameras, local-player index, choose-player AI and engaged sets, binding meanings (9a), events (9b), respawn (8), leash, host save transfer | two players finish a story mission and roam free; with one player, play3 is unchanged |
| **M6: polish** | teammate HUD, spectating while down, rejoin at checkpoint, co-op scaling, per-mission add-ons (9c) | |

**Main risks:** cross-build float or NaN differences seen only as rare desyncs; simulation reading render or local
state; pointer-ordered iteration; snapshot size and the fiber/streaming state at the frame boundary; resimulation cost on
handhelds; script missions built around one Hulk.

## 15. Open questions for the user

1. **Rollback parameters:** input delay 2 frames (67 ms) and an 8-frame prediction window, as proposed? Or a larger
   input delay (3) to halve rollback cost on handhelds?
2. **TURN:** may a Cloudflare Realtime TURN key be created on the free allowance (1,000 GB/month shared with the SFU)?
   Whether it needs a payment method on file is unverified; nothing has been created or deployed. And the employer
   check before any public endpoint.
3. **Respawn tuning (8.2):** 30 m / 5 s out-of-combat rule, 30 s fallback timer, partner revive (2 s hold, half health),
   a smash-point penalty in free roam: keep, change, or drop any of them?
4. **Second skin (6.5):** if two `global_<skin>.p3d` packs cannot be resident together, is a tinted P0 model acceptable
   as the fallback, or should P2's skin be restricted to skins whose resources do not collide?
5. **Progression:** does the guest earn anything for its own save (smash points, unlocks), or is a co-op session the
   host's progress only (proposed)?
6. **Story-mission skin overrides:** the game forces a skin in some missions (6.5). Apply the override to P0 only (P1
   keeps their skin), or to both?
7. **Hosts for M2:** which machines run the first x86-64 ↔ arm64 cross-build session once the 64-bit builds run the game
   (a SteamOS/Linux x86-64 box is not among the queue hosts today)?
