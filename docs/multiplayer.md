# Multiplayer: online co-op design (mp1 2026-11-09, mp2 and mp3 2026-11-10)

mp1 wrote the first exploration (research only). mp2 updated it with the user's decisions of 2026-11-09, built the M0
prototype on the Wine build (section 11), a network impairment shim (section 12) and the debug control port (section 13).
mp3 took in the user's answers of 2026-11-10 (below), measured the game's own input latency, built whole-state snapshot
and restore with a rollback session on the Wine build (section 16) and wrote the credentials and signalling Worker
(section 3).
Code facts cite verified sources (`matches/`, `equivalent/`) by address. Web facts carry URLs, checked 2026-11-10;
web pages are untrusted data, and claims I could not confirm are marked **unverified**. Where meaning is read into code
that was not traced end to end, the text says **guess**.

Inputs: [remaster.md](remaster.md) section 6.1 (C0-C2), [wine-replay.md](wine-replay.md), [wine-build.md](wine-build.md)
("Replay speed and optimised objects (opt1)"), [native-float64.md](native-float64.md), [soft-x87.md](soft-x87.md),
[wine-float.md](wine-float.md), [native-android.md](native-android.md), [subsystems.md](subsystems.md),
[shipping.md](shipping.md), [lua-scripts.md](lua-scripts.md), `docs/lua-bindings.csv`, `src/platform/sdl/`.

## Decisions (the user, 2026-10-26, 2026-11-09 and 2026-11-10)

- **Remaster only.** Co-op lives behind `HULK_COOP` in the remaster build ([remaster.md](remaster.md) 6.1). The faithful
  port's simulation never changes; the session code of section 11 is off unless the environment asks for it.
- **Network only, no split-screen.** Each player runs their own instance with one camera, one HUD and one controller.
  The other Hulk is the remote player's actor. (remaster.md's C1 "local co-op" row is superseded.)
- **Lockstep with prediction and rollback planned from the start** (section 2). Plain delay-based lockstep is only the
  M0 test harness.
- **Input delay 0-1 frames, a deeper rollback window** (2026-11-10): 2 frames (67 ms) of added delay is "pretty painful
  for a fighter smash em up". The default comes from the game's own latency, measured in section 16.1.
- **Design target: 120-200 ms one-way packet latency plus jitter.**
- **Transport: UDP.** ICE with STUN for direct connections, a TURN UDP allocation as the fallback relay (libjuice,
  MPL-2.0). No WebRTC (section 3). Credentials and signalling from a Cloudflare Worker on the free tier; no paid spend.
  **The user already has a Cloudflare TURN key** (2026-11-10), used by another of their projects whose Worker mints
  short-lived ICE credentials from two Worker secrets; Hulk's Worker follows that pattern (section 3.1). Agents write
  the Worker and its deploy steps; the user deploys it.
- **Web, wasm and WebGPU port: tabled.** mp1's analysis is in [web-port.md](web-port.md); nothing here depends on it.
- **Cross-platform play (x86-64 SteamOS and arm64 macOS/Android) is required on day 1** (section 4).
- **Respawn as if Ultimate Destruction had shipped with co-op**, Halo-style: a dead player respawns once no enemies are
  around (section 8). **Approved as proposed** (2026-11-10): no engaged enemy within 30 m and no damage to the partner
  for 5 s, a 30 s fallback, partner revive, a smash-point penalty in free roam. **Co-op works in free roam** as well as
  in missions.
- **Player 2 is a second Hulk with a different skin**; the two characters must differ. **Co-op always offers at least
  two skins**, even when the host has unlocked none. **A story mission that forces a skin applies it to the host's Hulk
  (P0; "P1" in the user's words), and the second Hulk (P1) gets a tinted version of the same skin** (2026-11-10;
  section 6.5).
- **One save, the host's** (2026-11-10): the session runs from the host's save and writes only to it. There is one
  store: both players share the movesets and upgrades the host has. The guest earns nothing of its own (section 6.6).
- **First cross-platform test machine (M2):** a Steam Deck or ROG Ally X, not available yet.
- **Mission scripts stay untouched.** The single-player script API gets a co-op meaning in our C++ bindings, plus engine
  events; our own original Lua add-ons only as a last resort (section 9). Game scripts are game content: never
  committed, shipped or quoted.
- **Prerequisite:** the maintainer checks with their employer before any public repository, public binary,
  notarization, or public network endpoint (the Worker, a TURN key in a shipped binary). Builds from source used by
  the maintainer's own machines avoid most of this.

## Summary

Each instance simulates the whole game; peers exchange only pad states (18 bytes per player per frame, 30 Hz). At the
target latency (4-6 frames one way, 8-12 round trip) plain lockstep needs about 8-12 frames of input delay per player
(270-400 ms), which M0 measured (section 11.3), so the design is **rollback with no input delay**: 0 frames of input
delay (the game itself moves the body 1 frame after a press, measured in 16.1), up to 10 frames of prediction,
frame-advantage throttling, and resimulation of the mispredicted frames inside one 33 ms tick (section 2). mp3 built
whole-state snapshot and restore and a two-instance rollback session on the Wine build (section 16). The pieces that exist: a Wine build that replays play3 bit-identically across hosts for 60,000
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
| input delay D | **0 frames** (the user, 2026-11-10: 2 frames is "pretty painful"); 1 as an option | the game already shows a move 1 frame after the press (measured, 16.1); every frame of delay adds 33 ms on top |
| prediction window (max rollback) | **10 frames** (333 ms) | covers one-way 200 ms + jitter + cadence ≈ 8-9 frames at D = 0. Beyond it the instance stalls instead of predicting further |
| typical rollback depth | 5-7 frames at 160 ms one way | (latency + cadence)/33 - D, with D = 0 |
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

- **Own Hulk**: as responsive as single player at D = 0. The game itself moves the body 1 frame after the press
  (measured, 16.1), then the display pipeline adds its refreshes.
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

### 3.1 The netplay Worker (`net/worker/`, mp3)

Written, tested offline, **not deployed** (the user deploys it). It lives in a new top-level `net/worker/` and not in
`tools/`. `tools/` holds development scripts that run in the checkout; the Worker is a deployable service with its own
package, wrangler config and tests, and the game's client side is under `src/platform/sdl/net/`. It follows the pattern of the user's
other project (a Worker that mints short-lived ICE credentials from the secrets `TURN_KEY_ID` and
`TURN_KEY_API_TOKEN`), written fresh for Hulk. Like that one it is a single ES module with no runtime dependencies.

Since wnet1 (D246, 2026-11-24) a room is a lobby of up to three players (`ROOM_MAX_PLAYERS`, 2..4): the host
(slot 0) and two guests (slots 1, 2) in a star, each guest connected to the host only. The host runs one libjuice
agent per guest and signals per slot; a slot a guest left can be taken again, and each join gives it a new
generation (`gen`) so the host's posts for an earlier guest never reach the new one.

| route | request | response |
|---|---|---|
| `GET /` | none, unsigned | `{service, ok, auth, disc}` (a health check: whether the app key and the spot table are set) |
| `POST /challenge` | none | `{disc:true, challenge, file, offset, length, expiresAt}` (one spot at random, a one-time token valid 2 min), or `{disc:false}` without `DISC_SPOTS` (wnet2, 18.1) |
| `POST /rooms` | `{settings?, proof?}` (settings: opaque JSON up to 4 KB, section 5; proof: `{challenge, answer}`) | 201 `{code, token, roomKey, role:"host", slot:0, maxPlayers, expiresAt}`; the code is 8 digits |
| `POST /rooms/<code>/join` | `{proof?}` | `{token, peerKey, role:"guest", slot, gen, maxPlayers, settings, expiresAt}`: the lowest free slot; 409 when full, 404 when missing or expired |
| `POST /rooms/<code>/ice` | a member's bearer token | `{iceServers:[{urls, username?, credential?}], ttl, turn, note?}`: only `stun:` and UDP `turn:` URLs on the ports in `ICE_UDP_PORTS` (3478, 443); `turns:`, `transport=tcp` and port 53 are dropped. Without the TURN secrets: STUN only (`turn:false`). If the API fails: 502 with the STUN list. Past the daily cap: 429 with the STUN list and no API call. `ICE_PER_ROOM` (8) a room. The old `POST /ice` answers 410 |
| `POST /rooms/<code>/settings` | `{settings}` | host only |
| `POST /rooms/<code>/signal` | host: `{to:<slot>, gen?, description?, candidates?, gatheringDone?}`; guest: the same without `to`/`gen` (it signals the host only) | `{ok:true}`; 409 for a slot with no guest or a stale `gen` |
| `GET /rooms/<code>` | none | host: `{role, slot:0, settings, guests:[{slot, gen, description, candidates, gatheringDone}], free, expiresAt}`; guest: `{role, slot, gen, settings, peer:{description, candidates, gatheringDone}, expiresAt}` (the host's agent for that guest) |
| `POST /rooms/<code>/leave` | none | a guest leaves; its slot is free again |
| `DELETE /rooms/<code>` | none | the host ends the room; a guest's DELETE leaves |

- **Rooms:** one Durable Object per room (SQLite backend, free plan). An alarm expires a room 10 minutes after creation
  if no guest joins, and 2 h after creation in any case. Calls after create or join carry a bearer token, compared in
  constant time.
- **Limits:**
  - Request size: 16 KB per request, 4 KB per description, 256 bytes per candidate, 32 candidates per side.
  - Per room: 1,500 requests in its lifetime (all players; the host polls every 6 s while it waits for guests, every
    0.7 s while one connects; a guest polls only until it is connected).
  - Per UTC day: 2,000 credentials and 5,000 rooms, counted by a global `Quota` Durable Object.
  - Credential TTL: `ICE_TTL_S` = 4 h, clamped at 48 h.
  - All of these are `vars` in `net/worker/wrangler.jsonc`.
- **Native client stub:** `src/platform/sdl/net/hulk_ice_config.{h,cpp}`.
  - `hulk_ice_fetch(base, out, err, len)` POSTs to `<base>/ice` through libcurl, loaded at run time with
    `SDL_LoadObject`. SteamOS and macOS ship libcurl. Android needs a JNI `HttpURLConnection` path, which is not
    written yet.
  - `hulk_ice_parse` turns the JSON into up to 8 servers (host, port, TURN or not, username, credential), ready for
    libjuice's `juice_config_t`.
  - `HULK_NET_WORKER` names the Worker.
- **Tests:**
  - `node net/worker/test/worker_test.mjs` uses an in-memory Durable Object stub and a mocked Cloudflare API: 142
    checks pass (wnet1: three-player rooms, slots, generations, leaving and rejoining; wnet2: the handshake).
  - `node net/worker/test/local_server.mjs --port P [--turn URL --user U --pass P]` serves the Worker on a local port
    with the same stubs (no wrangler): the game's co-op tests use it as their lobby.
  - `tests/net/ice_config_test.cpp` is built with `-DHULK_ICE_NO_FETCH` and needs no SDL: 37 checks pass. It also
    passes under ASan and UBSan.
  - An end-to-end fetch against a local mock server worked on the laptop.
- **Who may use it** (wnet2): every request but `GET /` is signed with the app key; rooms are made and joined only
  with a proof of disc ownership; per-IP limits; ICE credentials only for a room's members; peers authenticate each
  other (section 18.1).

**Deploy (the user):** the current steps, with the handshake's secrets, are section 18.1's. The first version's:

1. Install and log in: `cd net/worker && npm install`, then `npx wrangler login`. The only dependency is wrangler, a
   dev dependency.
2. TURN secrets (optional): `npx wrangler secret put TURN_KEY_ID`, then
   `npx wrangler secret put TURN_KEY_API_TOKEN`. Paste the values when asked; never put them in a file in the
   repository. Without them the Worker hands out STUN only.
3. Check the limits in `wrangler.jsonc` (`vars`), then run `npx wrangler deploy`. It prints the Worker's URL,
   `https://hulk-netplay.<your-subdomain>.workers.dev`.
4. Smoke test: `curl -X POST https://hulk-netplay.<your-subdomain>.workers.dev/ice` shows `"turn":true` once the
   secrets are set.
5. Point the game at it: `HULK_NET_WORKER=https://hulk-netplay.<your-subdomain>.workers.dev`. For local testing, run
   `npx wrangler dev` and set `HULK_NET_WORKER=http://localhost:8787`.

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

**Co-op rule (the user, 2026-11-10).**

- **Two skins at least, always.** The guest picks P1's skin from the skins the host's save has unlocked plus the co-op
  pair: `hulk` and `grey_hulk` are always offered in a co-op session, whatever the save holds (co-op's own grant; the
  save is not changed). If the guest's choice equals P0's, P1 gets the other one of the pair (`grey_hulk` when P0 is
  `hulk`, else `hulk`). The pair is part of the session settings (section 5).
- **Forced skins.** When the level load forces a skin for a story mission (0x206320 forces `joefixit` or a national Hulk
  for certain mission ids), **P0 wears the forced skin and P1 wears a tinted version of the same skin**: one skin's
  resources, P1's model drawn with a tint (a material parameter in the remaster renderer). The mission's look stays as
  designed and the two players still differ.
- **Engine work (M5):** load the second skin's `art/global_<skin>.p3d` into a second inventory (a second +0xaa0-style
  slot owned by our co-op code) and resolve P1's model from it; the tint path for forced skins. **First check (open):**
  whether two `global_*.p3d` files can be resident together or their resource names collide (answered in
  section 20: they collide in one inventory, so each extra skin gets an inventory and a render template of its own). If they collide, the
  tint is also the fallback for the free choice (P1 = P0's skin, tinted), which still makes the characters differ.

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
and sent separately: the skins (6.5), the session seed and date, and options that reach the sim.

**One save (the user, 2026-11-10).** The session writes only the host's save. There is a single store: smash points,
purchased moves and upgrades are the host's and both Hulks use them (the moveset and upgrade checks read the one
unlockables record, so P1 has whatever P0 has). The guest earns nothing for its own save; its saves are never read or
written during a session. Progress made in co-op (missions, smash points, purchases) is saved by the host's normal
save points.

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

### 8.2 The co-op rule (approved by the user, 2026-11-10)

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
  point (Halo's rule waits forever; a brawler with endless free-roam military escalation needs a ceiling).
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
| **M1: session mode without a recording** (mp3: built, not met; 16.3) | the rollback session `HULK_NET=rb` (inputs from each instance, prediction, restore, resimulation); the pins still come from a recording's header; next: rollback-safe drive I/O (16.4) | a session through the shim agrees across two hosts |
| **M2: cross-build determinism** (needs the 64-bit builds to run the game) | play3 on x86-64 and arm64 gated against the Wine build; the M0 pair across x86-64 ↔ arm64; arena allocator; pointer-order audit | determinism class A = {x86-64 SteamOS, arm64 macOS, arm64 Android} |
| **M3: snapshot and rollback** | arena + dirty-page snapshots, restore, resimulation with render/audio/I/O suppressed, prediction, frame-advantage throttling; the control port's `snapshot`/`restore` as the test hook | 8-frame rollbacks inside a 33 ms tick on the slowest target; a rollback test (restore N frames back, resimulate, same hash) passes every frame of play3 |
| **M4: transport** | libjuice ICE (STUN, TURN UDP), connection codes, then the Worker (credentials, rooms) after the employer check | two machines on different networks at 120-200 ms play with no desync |
| **M5: co-op gameplay (`HULK_COOP`)** | controller list of 2, P1 spawn with the second skin, per-player sim cameras, local-player index, choose-player AI and engaged sets, binding meanings (9a), events (9b), respawn (8), leash, host save transfer | two players finish a story mission and roam free; with one player, play3 is unchanged |
| **M6: polish** | teammate HUD, spectating while down, rejoin at checkpoint, co-op scaling, per-mission add-ons (9c) | |

**Main risks:** cross-build float or NaN differences seen only as rare desyncs; simulation reading render or local
state; pointer-ordered iteration; snapshot size and the fiber/streaming state at the frame boundary; resimulation cost on
handhelds; script missions built around one Hulk.

## 15. Open questions for the user

The questions of 2026-11-10 are answered (Decisions, top). New ones:

1. **Worker: ownership gating.** Should the netplay Worker require proof of game ownership before it mints TURN
   credentials? The other project's Worker uses a disc pass. Without gating, anyone with the URL can mint
   credentials up to the daily cap (3.1).
2. **Worker: per-IP rate limits.** Should it add per-IP limits as well as the global daily caps? Whether Workers
   rate-limit bindings are on the free plan is unverified.
3. **Worker: caps.** Are the defaults right: 2,000 credentials and 5,000 rooms a day, 4 h credential TTL, 200
   requests per room? Should TURN on port 443/udp stay in the list?
4. **Co-op load timing.** One way to make drive I/O rollback-safe completes a co-op session's file requests W frames
   after they are posted (16.4). Loads would take about 0.3 s longer in co-op only. Acceptable, or should the drive
   thread be snapshotted instead (more work, no timing change)?
5. **Steam Deck latency test.** When the Deck or Ally X arrives, measure the display pipeline on it (a camera at
   240 fps, or a latency tester). This is the part of input latency the Wine build cannot measure (16.1).

## 16. Snapshots, rollback and the game's own latency (mp3, Wine build)

### 16.1 The game's own input latency

Measured on the Wine build with play3 (jobs 71409 and 71417, studio).

- **Method:** `HULK_LAT_PROBE=150:15:9000`.
  1. Every 150 frames from 9,000, take a snapshot at frame F.
  2. Run 15 frames once for each test input, holding the input from F on and ORing it over the recording's pad.
     A button is held 4 frames (a tap); a stick stays held.
  3. Run the same 15 frames once with nothing added (the baseline). The run then goes on as recorded.
  4. Compare each input's run with the baseline, frame by frame, on four signals:
     - the main actor's input block (+0x1f58, the 0x43 words 0xb3660 copies from the pad);
     - the rest of the actor object;
     - its position;
     - the camera position.
- **What the counts mean:** each number is the first frame whose result differs, counted from the frame in which the
  changed pad was first read. That read is always the frame where the input begins. 0 means the frame's own update
  shows it.
- **Samples:** 180 probes (30 per input), excluding 91 windows skipped at a barrier (16.2). A probe where an input
  changed nothing in 15 frames (a cutscene, a menu, or the recording already pressing the button) is not counted.

| input | input block | actor state | position | camera | n |
|---|---|---|---|---|---|
| A (jump) | 0 | 0 (22 of 25) | **5** (22 of 23: the jump's wind-up) | 5 | 23-25 |
| B | 0 | 0 | 1 | 1 | 20-23 |
| X (attack) | 0 | 0 (20 of 21) | 1 (16 of 21; 4 at 4 frames) | 1 | 21-23 |
| Y | 0 | 0 | 1 (16 of 20; 4 at 4 frames) | 1 | 20-23 |
| left stick right | 0 | 0 | 1 (20 of 22) | 1 | 22-23 |
| left stick up | 0 | 0 | 1 (20 of 22) | 1 | 22-23 |

- **Measured:**
  - The game reacts to a pad read in the frame that reads it: the fighter's input block and its state change in that
    frame's update.
  - Movement and attacks move the body and the camera **one frame later (33 ms)**.
  - A jump leaves the ground 5 frames (167 ms) after the press. That is the animation's wind-up, the same in single
    player, not input lag.
- **How the frame is shown (from the code, not measured):** the frame's update runs, then `CGame::Render` draws it in
  the same main-loop iteration, then the present. So the game's own latency, from the press to the first frame drawn
  with the body moving, is **1 frame (33 ms)** of simulation.
- **Not measured: the display pipeline after the present.** That is the swap chain, the compositor and the display:
  typically one or two refreshes, host-dependent. The headless Wine run has no display (the probe's draw signal
  needed the prebuilt pddi library to change and was dropped). It is to be measured with a camera or a latency
  tester on the Steam Deck. mp2's "one to two frames" covers the simulation's 1 frame plus about one refresh.
- **Recommendation:**
  - **Input delay 0** by default. A 1-frame delay makes the body's first move 2 frames after the press, plus the
    display: 67 ms or more before anything a player sees. Offer 1 as an option for links that roll back too deeply.
  - **A prediction window of 10 frames (333 ms)**: 200 ms one way, plus the jitter tail, plus up to one frame of send
    cadence, comes to 8-9 frames.
  - **The cost:** with mp2's measured resimulation cost (job 71005: 2.1 ms average gameplay frame, 5.7 ms median
    worst frame of a window, 9.2 ms p90), a 10-frame rollback is about 21 ms of average frames. That fits a 33 ms tick
    on the Wine build at average frames but not at the worst ones (57-92 ms). A native build needs **about 2 ms per
    worst gameplay frame** on the slowest handheld for 10-frame rollbacks inside one tick. 4-6-frame rollbacks, the
    typical depth at 160 ms one way, need half that.

### 16.2 Snapshot and restore

Built in `src/platform/sdl/xdk/snapshot.cpp`. Everything is off unless `HULK_SNAP=1`.

- **The arena.** With the switch on, every game allocation comes from one reserved range. That covers malloc,
  calloc, realloc and free (0x3479aa, 0x347aa0, 0x347d7a, 0x3479bc) and the XAPI heaps.
  - The allocator's own state (size-class free lists, the top, counters) lives inside the range. A copy of the range
    is therefore a copy of the heap, and a restored heap hands out exactly the addresses it handed out the first time.
  - Blocks are zeroed, as the host blocks are.
  - Freed blocks wait in an 8,192-entry quarantine, also inside the range, before they can be reused. This is closer
    to the host heap's behaviour.
  - Every pointer the game holds into its heap is therefore the same on both peers, whatever happened before.
- **The image's data.** `tools/rollback_test.py ranges` reads the link map and lists what to copy besides the arena:
  - the game's `.data` and `.bss`;
  - the platform state the simulation reads: the virtual clock, the frame number, the sound code's private
    generators, the main thread's `rand()` state (Lua's `math.random`), XInput handles, and the replay cursor.

  Render, audio-device, file, thread and log state stay out.
- **`rand()`.** The main thread's state moved from msvcrt's thread data into the image (`crt_glue.cpp`). The sequence
  is the same, and the switch does not change it.
- **Where.** Snapshot and restore happen at `GameClock::Update`'s entry, on the main loop's call path only: a restore
  needs the same stack depth as the save. The frames above that call, `CGame::Tick` and the main loop, keep nothing
  across it.
- **The restore test** (`HULK_RB_TEST=E:D`) runs on play3:
  1. Snapshot at frame F, run D frames, and hash the whole snapshot.
  2. Restore F and run the same D frames again (the replay cursor is restored with the state).
  3. Compare the two hashes. On a difference it logs the differing words, with the arena chunk each belongs to.

  Each window also lists the platform calls made inside it, such as file opens and render-resource creation.

Results on play3, the Wine build at e72df1f82 (lineage mp3-dev, image 71415):

| run | windows | exact | different | skipped (barrier) | notes |
|---|---|---|---|---|---|
| 71416: restore test, every 200 frames, depth 8, fiber and drive-post barriers | 115 to frame 23,220 | **68** | **0** | 47 (44 drive posts, 3 fibers) | the run stopped at frame ~23,250 (crash; see the open problem below) |
| 71418: the same without the drive-post barrier | 75 to frame 15,240 | 71 | 2 (6 words of one 28 KB buffer) | 2 (fibers) | the crash came earlier (frame ~15,250) |
| 71413: arena on, no restores | none | | | | **play3 to frame 60,360: every checkpoint matches** except the five known transients, as without the arena (71414) |

- **The arena is faithful.** play3 replays to the end with every game allocation in the arena.
- **Size and time per snapshot** (71416, 68 windows):
  - Size: state 19-37 MB (median 32.7 MB), of which 1.9 MB is image data and the rest the arena.
  - Time: save 1.2 ms (median; p90 1.7 ms) and restore 1.2 ms (p90 1.4 ms), both memcpy on studio under Rosetta.
- **Dirty pages after one frame:** a median of 298 4 KB pages (1.2 MB; at most 521, or 2.1 MB) out of about 8,000. An
  incremental snapshot of dirty pages would copy about 4% of the state per frame.
- **Barriers found:**
  - **The loader fiber** (radcore) keeps its stack in host memory. A restore across a fiber switch crashed a level
    unload (play3's frame 2600). Fiber switches are now a barrier.
  - **The drive thread** runs game code with state on its own stack between lockstep steps. Restores across drive
    posts compared equal at the window's end (71418), but led to a crash later. Drive posts are now a barrier too
    (`HULK_SNAP_IO_BARRIER=0` turns it off).
  - In gameplay, drive posts are frequent: 44 of 115 windows of 8 frames had one, because the world streams.
- **Platform state that had to join the snapshot:**
  - **The sound voices.** A voice is the game's sound-buffer handle; voices and their stream rings are now allocated
    from the arena, and the mixer's voice list and clock are copied with the snapshot.
  - **The pddi front end's static data.**
  - **The main thread's `rand()` state.**
- **Open problem:** a crash after about 70 exact restores (71416, frame ~23,250, in pure3d geometry code). It is not
  caused by any single window. Something host-side still drifts across restores, and it is not yet found. The
  windows' platform calls are now only sound-buffer calls.

M3's exit criterion (a restore test on every frame of play3) is not met yet.

### 16.3 M1: the rollback session (`HULK_NET=rb`)

`input/hulk_session.cpp`, wire format "HRB1".

- **Two players, one instance each.** The game has one controller, so it reads both pads merged: buttons ORed, the
  first non-zero stick. Either player's input therefore changes the simulation.
  - Player 0's input is the recording's polls: up to 61 reads a frame, as a list of changes.
  - Player 1's input is a seeded random walk: holds of 2-20 frames of idle, a face button, a stick direction, or a
    jump while moving. It starts at frame 12,000.
  - Reads past 61 in one frame (a loading screen) return the recording's auto-START taps, which are the same on both
    instances.
- **Inputs are keyed by frame.** Each instance sends its player's frames until the peer acknowledges them.
- **Prediction and rollback.**
  - A frame without the remote input is predicted as the last state known.
  - When the real input arrives and differs from the prediction for any read the simulation made, the instance
    restores that frame's snapshot (a ring of 10, one per frame) and runs forward again.
  - While resimulating, frame pacing is off.
  - An instance waits when the remote input is more than `HULK_NET_RB_WINDOW` frames behind.
  - Frame-advantage throttling: an instance sleeps a quarter frame while it is more than one frame ahead on average.
- **Hashes.** Every 30 frames, once a frame is final (every input before it known), both instances compare two hashes:
  - the M0 session hash (actors, health, mission state);
  - a whole-state hash of the arena and the game data.
- **Running it:**
  - `tools/rollback_test.py pair` starts both instances and the shim on one host.
  - `submit --pair` sends the same as a queue job.

Run 71422: one host (studio), both instances paced at 30 fps by the session. The shim was set to 120-200 ms one way
(this seed drew about 170 ms; RTT averaged 348 ms), pareto jitter 15 ms, 2% loss in bursts, 1% reorder, 0.5%
duplicates. Window 10, input delay 0, player 1's random input from frame 10,000.

| | A (player 0, play3's polls) | B (player 1) |
|---|---|---|
| frames run together | 526 (until B stopped sending) | 515 |
| small hashes (actors, mission) | 10 ok to frame 300, then DIVERGED | the same |
| big hash (arena + game data) | differs at every compare, even while the small hash agrees | |
| snapshot per frame | 3.4 ms average (ring of 12) | 3.5 ms |
| barrier waits (fiber or drive post) | 12 in 300 frames, 3.6 s | 12, 1.8 s |
| rollbacks | 0 (no misprediction found before the parting) | 0; 3 mispredictions found after a barrier: not repairable |

- **What happened:**
  - Prediction ran: 300 of 301 frames were predicted on each side. Both instances agreed at every hash to frame 300.
  - At frame 302, B predicted A's front-end input wrongly in a frame that also posted drive requests. The barrier of
    16.2 forbids that rollback, so the instances parted.
  - In the front end the game posts drive requests almost every few frames (menus stream). With drive posts as a
    barrier, almost any misprediction lands before one.
- **The big hash** differs between the two processes from frame 30 on. The arena holds per-process bytes: host
  pointers in game memory and uninitialised stack bytes copied into buffers (16.2). It needs the per-process ranges
  found and excluded before it can be a desync check. The small hash is the reliable one today.
- **Result: M1 is not met.** The session machinery works up to the first misprediction that a barrier blocks. No
  divergence came from prediction or restore themselves before that point, but the run ends there.

### 16.5 The default build is unchanged (Wine proof)

Both builds are at the merge-once freeze point F (e68debc9d), with data TUs regenerated at F, on studio.

- **Control:** 71423, fresh, `--gfx`, a private `hulk_sdl.lib` built from F's own sources. The shared prebuilt
  library predates mp2's session code: the image could not resolve `hulk_session_active`.
- **Proof:** 71424, `--state seed:71423`, the mp3 sources, the mp3 `hulk_sdl.lib`.
- Both replayed play3 to frame 60,000 with no session or snapshot variables set.
- **`tools/ckpt_gate.py 71423 71424`: GATE ok.** 2,029 common checkpoints, 0 diverged on either side; particle-RNG
  hashes identical at all 2,029.
- **The one change that does not depend on a switch:** the CRT rows for rand/srand/free/realloc/calloc now bind to
  `hulk_crt_*` glue. The glue keeps msvcrt's behaviour; rand's main-thread state lives in the image.

### 16.4 What is left (plan)

1. **Make drive I/O rollback-safe**, since it cannot stay a barrier. Two options:
   - **Snapshot the drive thread's state**, in one of two ways:
     - give the drive its own small fiber whose stack is arena memory, so the snapshot covers it;
     - or prove the drive routine (0x2731d0) keeps nothing across steps and fix what it does keep.
   - **Delay completion deterministically:** a request posted in frame F completes at frame F + W on both peers,
     once F is confirmed. That changes load timing in co-op only; single player keeps lockstep I/O.
2. **The loader fiber.** Loads are rare, so stalling until every input is confirmed is acceptable. It is built (the
   fiber barrier) and costs one RTT per load frame.
3. **Find the remaining host state** behind the crash after about 70 restores.
   - **Method:** dump the host-side objects a window touches, sound and pddi first, and compare their state after
     each pass.
4. **Make the big hash comparable across processes:** find and exclude the per-process words (the restore test's
   diff dump finds them).
5. **Then run M1 again:** a session to 20,000+ frames through the shim, the restore test on every frame of play3,
   and the depth histogram and resimulation time, which this run could not reach.
6. **Then M3 proper:**
   - incremental snapshots (about 4% of pages per frame);
   - render and audio suppressed while resimulating;
   - the 64-bit builds' timing.

## 17. Co-op Hulks in one instance (wcoop1, D246, 2026-11-24)

The user's request (D246): up to three Hulks in a lobby, one player hosting from their current game, guests playing
the host's story with no saves of their own. wcoop1 builds the game side in one instance, without networking
(src/platform/wasm/gfx/coop.c; lane wnet1 owns the transport, join and input exchange). Gated behind the developer row
`dev_coop_local` (Gameplay Options, developer mode: 1 off, 2 or 3 Hulks); faithful runs, replays and play3 never see it.

**What works (first landing).**

- **Spawning.** In play (the main actor holds controller slot 0, the game camera is up, no letterbox) for 30 updates,
  each extra Hulk is made beside the main actor by the game's actor spawner 0x0002b970 (am_CreateActorAtPosition's
  path: the `hulk` template, team `player`, names `coop_p1` / `coop_p2`, ground snap) and given controller slot k. The
  Hulk template takes a second and third instance with no new resources: same model, same fight script. Checked in the
  tutorial c00m01 (a story mission); free roam not yet run (needs a save past chapter 1, see "Next").
- **Input.** The game reads all four pad ports through one `CController` (0x000ae4b0 makes a `CPhysicalController` per
  port, 0x000ae130 sums them: in single player any pad drives the Hulk), one `CSimController` (0x000b3b80; its update
  0x000b3bc0 runs from UpdateSimulation through 0x000b3d80) and a sim-controller list of one (0x000b3d20, `i < 1`) that
  `CControllerAgent::vfunc_4` 0x000fd0f0 indexes with the character's slot (+0x20a8). In co-op three entry hooks give
  each extra player his own chain built from the game's own objects: the main `CController` sums port 0 only, a
  `CController` of ours per player (game-state memory, the game's vftable) sums only port k (ports 1..3 carry the flag
  that sums them into the C/D blocks, moved to A/B for a player's own controller), a `CSimController` constructed by the
  game over ours is updated beside the original's, and the list answers index k with it. `SIM->pads_in` gains ports
  1..N-1, so XInput serves `SIM->pads[k]`.
- **Per-player cameras.** Sticks are camera-relative (0x000fd0f0 reads the logic view's matrix, 0x004e231c +0x1c). Each
  extra player has a simulated camera (a yaw in game state: the right stick turns it at 2.6 rad/s, and it eases behind
  him while he runs); while his controller agent runs, the logic view's matrix is that camera's (the game camera's
  orientation turned about the vertical), and put back right after.
- **Local view (picture only).** `hulk_wasm_coop_set_local_view(k)` / `HULK_COOP_VIEW=k`: after UpdateSimulation the
  logic view becomes player k's camera (the game camera's framing of the main actor, turned to k's yaw and moved to k);
  its 0x7c bytes are put back exactly when World::Render returns (before GameClock::Update's checkpoint), at the frame's
  end and before the next update. **Two runs with local views 0 and 1 gave byte-identical checkpoint records** (6,000
  frames, 9,712 checkpoints, the second Hulk running and leashed back three times); the game hash differs from the
  first frame of view 1 on (render bookkeeping, as with Draw Distance). A first version put the view back only before
  the next update: the records' camera tag then differed (GameClock::Update runs between the render and the update).
- **Enemies.** An AI actor choosing a target (AcquireTargetCondition::vfunc_6 0x001245b0) takes the nearest living Hulk:
  the actor manager's main-actor word holds that Hulk while the original runs. Built, not yet seen working (the tutorial
  has no enemies).
- **Leash and falls.** A player more than 300 units (horizontally; 80 at first, the user found it too short, 11-24; 200,
  then 300 with streaming, section 19) from the main actor, or below y = -45, is put back 5
  units behind him. Streaming then never has to hold rooms far from the main actor (the game loads rooms to ~390 units
  around the camera); no second focus point is needed while the leash holds.
- **Down and respawn (first version of 8.2).** An extra Hulk whose life state leaves 0 is down (the engine removes him
  1.5 s later); he is made again 5 units behind the main actor once down 5 s with no damage to the main actor for 5 s,
  or after 30 s whatever happens. A cutscene's slot -1 on the main actor also takes the extras' control, and gives it
  back. The main actor's death is still single player's (mission fail). Not yet exercised by a test.
- **Tests (HULK_INPUT `pK:FROM-TO:...` items drive pad K, host/frame.c).** play3 to 30,000 with the feature off: records
  identical to HEAD's (112027 against control 112025). HULK_ROLLTEST 3000:4600 with three Hulks: identical (112028).
  Metal free runs on the queue with 2 Hulks, view 0 and 1 (112023, 112024) and 3 Hulks, view 2 (112029): the shots show
  the extra Hulks running and the camera following the local player.

**Interface for wnet1.** A remote player's pad goes in `SIM->pads[k]` (XINPUT_GAMEPAD, 18 bytes) before each frame's
poll, k = 1 or 2, the same on every instance; the session sets `dev_coop_local` (2 or 3) on every peer (it is per
session, like every setting that changes the game); `hulk_wasm_coop_set_local_view(k)` picks the instance's own Hulk
(host state, never sent); `hulk_wasm_coop_player(k)` gives player k's character (0 while down). The spawn happens on the
same update on every instance because it depends only on game state.

**What the engine fights / what is left.**

- **Skins and tints (6.5):** per-player skins done in section 20 (wskin1); the tint of a forced skin's extra copies
  too (wskin2: the runner draws an extra Hulk who wears player 0's skin with a tint of his own, knowing his draws by
  their bone matrices).
- **One-player notions left:** the HUD, minimap, rumble and audio listener follow the main actor (P0) on every instance;
  attack tokens and the scripts' known-player positions mean the main actor; traversal.c's charge sprint follows one
  character (two players sprinting at once share its state).
- **Heap:** each extra Hulk is a full CCharacter and its components on the game heap; the cost on a full city level is
  not measured yet (the heap has little margin: watch for the out-of-memory spin 0x0008d320).
- **Free roam and enemies** need a scripted run from a save past chapter 1.

## 18. Online co-op: lobby, transport and joining a game (wnet1, D246, 2026-11-24)

The network side of D246 (wcoop1's section 17 is the game side). Remaster-only; replays, playthroughs and every faithful
run never start it (the module's hooks return at once under a recording, and nothing runs without a lobby).

**Pieces.**

- **Lobby: the netplay Worker** (`net/worker/`, section 3.1): rooms of up to three players, the host and two guests in a
  star. Codes are 8 digits (a guest enters them with a gamepad, a digit a menu row). Not deployed: the user deploys
  (below). `net/worker/test/local_server.mjs` runs the same Worker on a local port for tests.
- **Transport: libjuice 1.7.4** (MPL-2.0, vendored unchanged in `src/platform/wasm/run/net/libjuice/`, pinned by the
  release archive's sha256 in `run/app/netplay_juice_core.c`; compiled as four units of run/app, which every app build
  tool already compiles: no tool change for macOS, Linux or Android). Why libjuice and not a TURN client of our own:
  it is a whole ICE agent (a direct UDP path when the NATs allow, else the TURN relay), consent freshness and TURN
  allocation refresh included, and is what libdatachannel users run against Cloudflare's TURN every day; our own
  client would need long-term-credential TURN (MD5/HMAC-SHA1, nonces, refreshes, permissions, channels) plus
  connectivity checks, about 1,500 lines nobody here can test against Cloudflare before the Worker is deployed. Its
  server half doubles as the tests' local relay (`HULK_COOP_RELAY=PORT`). Size: ~10,000 lines of C, ~240 KB of
  objects.
- **The runner's session** (`run/app/netplay.cpp`, helpers `netplay_util.cpp`: HTTP by plain sockets for `http://`,
  libcurl loaded at run time for `https://` on macOS and Linux, `HttpURLConnection` through JNI on Android
  (`GameActivity.hulkHttp`; the manifest gains INTERNET); zlib loaded at run time). libjuice calls back on its own
  thread with its lock held, so a callback only queues the event; the session's lock is never held by a callback.
- **The module's side** (`src/platform/wasm/gfx/netplay.c`): hooks at GameClock::Update (replay.cpp), at every frame
  end and at the scheduler's switch (sched.c), weak, so the headless module is unchanged.

**Lockstep (delay-based; rollback stays the plan, section 2).** Keyed by presented frames (`SIM->frame`): at the end of
frame F each peer publishes its own pad (the frame end's sample: the runner's controller, or HULK_INPUT) for frame
F+1+D; the host gathers its own and each guest's pad for F+1 into the set for F+1 and sends it to every guest; every
peer then plays frame F+1 with the set: slot k's pad goes in `SIM->pads[k]` (section 17: Hulk k), the host's in 0.
A first version keyed the sets by GameClock updates: the pause menu and the front end read the pad with no update
running, so their pads froze. Presents are counted alike by every peer with the same renderer class (the pddi front
end of every real renderer, or every peer null), which the hello checks. D = round trip / 16.7 ms + 2 (2..12;
`HULK_COOP_DELAY`), from the round trip measured before the first join. Pads and sets are sent redundantly until
acknowledged (18 sets or 32 pads a datagram).

**Joining a game in progress.** A connected guest says hello (protocol, the app's build id, a hash of the XBE); the host
refuses another build or another game. At its next frame end (every fiber suspended) the host zeroes its free arena
blocks (`ff_arena_scrub`: nothing reads a free block, the arena zeroes what it hands out; the snapshot compresses
better and host and guest hold the same bytes), writes the playthrough snapshot (sched.c `ff_snap_write`), and the
runner packs it with the host's save folder (T, U, Z; not port_settings.txt) and its settings, compresses it (zlib
level 1) and streams it: paced by rate, 1.1 KB chunks, selective acknowledgements, the rate up 25% a round trip under
3% loss and down 25% past 10% (random loss on a relay is not congestion). The guest writes the saves into a throwaway
folder under its temp directory (removed when it quits), takes the host's settings for the session (never saved:
the menus are game state too, and follow the host's presses), and puts the state back at one of its own frame ends
(`ff_snap_read`; `ff_gfx_foreign_restore` first: another process's stamps say nothing about this runner's GPU
objects). Both continue from the frame after the snapshot; the guest's own pads count from D frames later. Its
local view becomes its own Hulk (`hulk_wasm_coop_set_local_view`).

Two host-path leaks had to go for a state to move between machines: file records kept the host's path (an open
archive restored on another machine pointed at the first machine's disc folder), so xapi.c now keeps the game's own
path (`D:\art\...`) in the record and resolves it when it opens the host stream. Free-run game hashes no longer
depend on the run's folders either.

**Desync check.** Every `HULK_COOP_HASH_EVERY` frames (60) each guest sends a digest of the simulation and the host
compares it with its own for that frame: the replay probe's tags (replay.cpp `ff_probe_digest`: flow, clock, RNG, the
main actor, the logic view, every actor, the mission; taken at the last GameClock update). Not the whole state: peers
whose pictures follow different Hulks differ in render bookkeeping (section 17), and a whole-state hash reported a
false DESYNC within 60 frames of the extra Hulks' spawn. `HULK_COOP_HASH=state` compares the whole state (ff_game_hash's
ranges, word-wise) for runs whose peers share a view. A difference ends that guest's session (it plays on alone) and
is logged as `DESYNC`.

**Leaving.** A guest silent for 10 s leaves the set from the next frame; when the last guest leaves the host plays on
alone without delay, and a later guest starts a new session. When the host leaves, a guest plays on alone (nothing it
saves is kept).

**Menu (remastered only, never saved).** Gameplay Options' "Online Co-op" row: Off, Host a Game, Join a Game. The
join code is typed on the game's own code keyboard (wjoin1): Extras' "Join Online Game" (or Join a Game on the row, in
the front end) opens the Code Input screen in join mode, the screen the game types cheat codes on (an FETextInput of
7 boxes: A starts typing, left/right moves between boxes, up/down steps a box through A-Z and 0-9, A enters). In join
mode the screen's prompt shows the co-op status and the entered text goes to the join instead of the cheat check
(fe_options.c answers the front-end function "DoFECodeInput" with a handler that forwards to the game's own outside join
mode); Code Input itself stays the cheat screen. The pause menu has no keyboard: Join a Game there says to join from the
main menu. The menus show a room's code as those 7 characters (src/platform/wasm/host/room_code.h): 6 base-32 symbols of
the Worker's 8-digit number (no I, L, O, U; a typed O reads as 0, I and L as 1) and a check symbol that catches any one
wrong character; the Worker and the runner's requests keep the digits. While co-op is on, the Online Co-op row's label
shows the status: "Co-op: room 0BRRAEW, waiting for players" / "..., 2 players" / "joining ..." / why it failed. In a
session the label is set at the same update on every peer from what they all know (the code, how many play), so the
menus stay equal. Launch options do the same: `--host`, `--join 0BRRAEW` or `--join 12345678` (HULK_COOP_HOST=1, HULK_COOP_JOIN=CODE). The lobby server's URL and
the app key are compiled into the app (18.1); `HULK_NET_WORKER` / `HULK_NET_KEY`, or `coop.txt` in the app folder (the
URL on its first line, `key=HEX` on another), override them.

**Hosting turns the extra Hulks on itself (wnet2, the user 11-24).** Hulk k exists while slot k is in the session's
set: coop.c reads netplay.c's `hulk_net_mask()` (game state, equal on every peer at every update), so a guest's Hulk is
made (after the usual 30 settled updates in play) once he is in the lockstep, and removed by the game's own
`KillActorByName` (0x0002b830, what a script's `am_KillActorByName` calls) at the first update without him; a host
alone has none, and when the last guest leaves the extras go. A joining guest's pad port is marked present
(`SIM->pads_in`) at the same frame end on every peer. `dev_coop_local` stays the developer knob (it adds Hulks whatever
the session).

**Knobs (tests).** `HULK_NET_KEY=HEX`, `HULK_NET_SKEW=S` (seconds added to the signed time),
`HULK_NET_TEST=replay|baddisc|badpeer` (the challenge request sent twice; a wrong disc answer; a hello under a wrong peer
key), `HULK_COOP_CODE_FILE=F` (the host writes its code there), `HULK_COOP_JOIN=@F` (a guest reads it,
waiting), `HULK_COOP_SHIM=seed=S,delay=MS,jitter=MS,loss=PCT` (a seeded impairment on every datagram this peer sends),
`HULK_COOP_RELAY=PORT` + `HULK_COOP_RELAY_ONLY=1` (a local TURN relay in this process; only relayed candidates),
`HULK_COOP_LOG=1|2|3`, `HULK_COOP_TMP=DIR`, `HULK_COOP_HASH_EVERY=N`, `HULK_COOP_DELAY=N`.

**Tests.**

- `tests/net/coop_loop.sh OUT [PEERS] [FRAMES] [SHIM] [RELAY]`: the runner's session without the game (a toy game
  calling the same imports: updates on most frames, a 4 MB state, hashes), a local lobby, a host and one or two guests
  joining mid-run; every peer's final state must agree. Passed on the laptop: 3 peers direct; 3 peers with 60 ms +
  0-30 ms jitter and 3% loss each way (round trip ~160 ms, D = 7, the 1.7 MB join at ~1 MB/s); 3 peers through the
  local TURN relay with 20 ms + 10 ms jitter and 1% loss. Since wnet2 the lobby runs with the handshake (a test app
  key and spot table over a made-up disc folder), and `NEG=1` adds peers that must be refused with their status
  (wrong app key, clock 10 min off, replayed request, wrong disc answer; with PEERS=2 also a wrong peer key).
- `tests/net/disc_spot_test.sh OUT SRC...`: the spot table read through run/disc.c from each disc source must hash as
  recorded (wnet2).
- `wasm_build_job.py ... --test coop:FRAMES[:PEERS[:SECOND_JOIN_S]]`: the app (null renderer) as a host (into the game
  with HULK_INPUT; no developer setting since wnet2) and one or two guests with scripted pads of their own joining it
  on loopback, through the local lobby with the handshake on (the candidate's compiled-in app key, or a fresh one; a
  spot table sampled from the host's disc); every guest's game hashes from its join on must equal the host's at the
  same frames, no DESYNC, each guest's Hulk spawned. With 3 peers the second guest leaves 3,000 frames before the end
  (his Hulk must be removed) and refused peers run beside them (wrong app key, clock off, replayed request, wrong disc
  answer, wrong peer key), each showing its status in the Online Co-op row. Results below.

### 18.1 The handshake (wnet2, 2026-11-24)

The user's ask: keep strangers off the Worker and its TURN key. Layers, each refused with a status the Online Co-op row
shows ("Co-op: the lobby refused this app (app key)", "... this device's clock is wrong: set the time", "... the lobby
refused a repeated request", "... the lobby could not confirm the game disc", "... too many tries from this network",
"... the host refused: not a player of this room"):

- **App key.** A random 32-byte key (tools/netplay_keys.py) compiled into the app and set on the Worker as the secret
  `APP_KEY`. Every request but `GET /` carries `X-Hulk-Time` (unix seconds), `X-Hulk-Nonce` (32 hex) and `X-Hulk-Sig` =
  HMAC-SHA256(key, `hulk-v1\n` METHOD `\n` PATH `\n` TIME `\n` NONCE `\n` hex SHA-256(body)). The Worker refuses a bad
  MAC, a time more than 300 s from its own, and a nonce it has seen (kept 12 minutes: a room's in its Durable Object,
  the others in the global one). Without `APP_KEY` the Worker answers 503 to everything (`ALLOW_UNSIGNED=1` only for
  a local development server).
- **Disc ownership** (the user's decision, section 15). The secret `DISC_SPOTS` holds 15 spots, each (file, offset,
  length 4-64 KiB, SHA-256 of those bytes), sampled by tools/netplay_keys.py from the player's own disc: hashes only,
  never disc bytes, and never committed. `POST /challenge` names one spot with a one-time token (its own MAC under a
  key derived from the table, valid 2 minutes); room create and join carry `{proof:{challenge, answer}}`, answer =
  HMAC-SHA256(key = the spot's hash, `hulk-disc-v1|` + challenge): the hash never travels, and a token answers once.
  Spots are files read through `hdisc_*` (run/disc.c), never image offsets, and only from `default.xbe` and the .rcf
  archives holding no Bink movie (an AV1 pack zeroes movies past 64 KiB; packs add only `.hulk/` files): the
  extracted folder, a trimmed .iso and the user's AV1 + texture-pack .hulkdisc gave the same 15/15 (and 400/400)
  hashes and answers (tests/net/disc_spot_test.sh, netplay_keys.py check).
- **Per-IP limits** (CF-Connecting-IP; vars): 40 challenges and 30 joins per 10 minutes (a code guesser gets 30 tries
  in 10^8), 12 rooms and 30 ICE requests an hour.
- **ICE credentials for members only:** `POST /rooms/<code>/ice` with the room's token, 8 a room, on top of the daily cap.
- **Peers authenticate each other.** Create returns the host a 32-byte room key; join returns a guest its peer key
  HMAC-SHA256(room key, `peer|SLOT|GEN`), which the host derives too. The game's hello carries a nonce and a MAC under
  it (protocol 2), so the host talks only to the guest the Worker gave that slot and generation; the welcome that
  accepts carries a MAC over the guest's nonce, so a guest plays only with the room's host. ICE itself already keys
  connectivity checks by the ice-pwd only room members see, and the TURN relay forwards only to peers it has
  permissions for.

**What it does not stop.** The app key and the address are in every copy of the app (masked, not encrypted): anyone
who has the app can pull them out and script the Worker; the disc check then still needs the disc's bytes (or the 15
hashes, which one owner could publish), and the per-IP and daily caps bound what a scripted client takes. It is a
fence against strangers and casual reuse of the TURN key, not DRM. Rotating the key (`netplay_keys.py init
--new-key`, rebuild, `wrangler secret put APP_KEY`) shuts out every older build.

**Where the values live.** One untracked, gitignored file at the checkout's root, `netplay.local.json` (mode 0600):
`worker_url` (the lead's), `app_key` and `disc_spots` (netplay_keys.py, merged in). `HULK_NETPLAY_CONFIG` names
another (tests). tools/wasm_app.py writes worker_url and app_key into `app-gen/hulk_netplay_config.h` (masked; runner
only, never module memory) for the macOS app, and wasm_android.py and wasm_linux.py through the same call;
wasm_build_job.py ships a copy of just those two as the job file `wbrun/netplay.json` (`--netplay FILE|none`), never
the spot table.

**Deploying the Worker (the user; after the employer check).** From the checkout's root:

1. `cd net/worker && npm install && npx wrangler login && cd ../..` (once).
2. `build/venv/bin/python tools/netplay_keys.py init` (adds app_key and disc_spots to netplay.local.json; `--disc`
   names another disc source than isos/extracted), then `netplay_keys.py check isos/extracted build/hulk-hd.hulkdisc`.
3. `build/venv/bin/python tools/netplay_keys.py secret APP_KEY | (cd net/worker && npx wrangler secret put APP_KEY)`
   and the same for `DISC_SPOTS` (the values go through the pipe, never onto the screen); TURN as before:
   `(cd net/worker && npx wrangler secret put TURN_KEY_ID)`, `... TURN_KEY_API_TOKEN` (pasted when asked).
4. `(cd net/worker && npx wrangler deploy)`; `curl https://hulk-netplay.<subdomain>.workers.dev/` says
   `"auth":true,"disc":true`.
5. Rebuild the apps (the key and address are compiled in); players need no coop.txt.

## 19. Memory and streaming for co-op (wstream1, 2026-11-25)

**The game heaps.** The "game heap" behind 0x00266e00 is a set of core::MemoryDlAllocator heaps carved at start-up
(0x0008d480 -> 0x0008d3a0, ids 3..18) out of the default heap (malloc; on this port the arena). Their sizes are
constants in the XBE's table 0x00400520 (`{name, size, 0}` by id), not a share of the console's memory:
GlobalMemoryStatus (0x00209f01; 64 MB here, as on a retail console) is only stored. Heaps 19..40 are carved later
from the Room Heap (7): two district heaps of 200 KiB and twenty room-data heaps of 0x25800 bytes (0x00204e40), which
fill it (3,023 of 3,050 KiB). A heap that cannot serve a request calls 0x0008d320, which spins forever.

With the remastered edition on (or the developer's `dev_coop_local` > 1) the app doubles every table size but the
Debug Heap's before any game code runs (`ff_boot_image_loaded`, called by boot.c after the image is loaded;
gfx/stream.c): 14,772 KiB -> 29,534 KiB of arena. Replays, `HULK_INPUT`/`HULK_ROLLTEST` runs and every faithful run
keep the original sizes (their settings start faithful). An online guest restores the host's memory, heaps included,
so every peer runs the host's sizes. `HULK_HEAP_SCALE=P` (100..400) overrides the scale where it applies;
`HULK_HEAP_LOG=N` / `HULK_HEAP_LOG_FROM=F` print every heap's live bytes, most live and highest break since F.

Measured (KiB, most live / highest break, play3's night city from frame 38,000 to ~52,000; the original's sizes in
the last column):

| heap | one Hulk | 3 Hulks, 400 units apart | size |
|---|---|---|---|
| 3 Script | 422 / 427 | 427 / 431 | 600 |
| 5 Effect | 268 / 275 | 259 / 269 | 400 |
| 6 Sound | 962 / 969 | 957 / 967 | 1,212 |
| 10 Prop | 416 / 428 | 409 / 410 | 850 |
| 11 Stream | 3,098 / 3,101 | 2,903 / 2,905 | 3,640 |
| 12 Game Object | 85 / 85 | 177 / 199 | 300 |
| 13 Fight | 136 / 171 | 172 / 181 | 300 |
| 14 Game FE | 452 / 465 | 452 / 463 | 500 |
| 15 Rendering | 198 / 202 | 228 / 240 | 400 |
| 17 Persistent | 3,230 / 3,236 | 3,230 / 3,238 | 3,260 |

Three Hulks cost ~115 KiB of Game Object heap, ~35 of Fight and ~40 of Rendering; nothing came near a size, and the
same runs at the original sizes (`HULK_HEAP_SCALE=100`) finished too. The heaps with the least margin are not co-op's:
Persistent (22 KiB left over the whole of play3) and Game FE (35 KiB; the menu screens of wquit1). Doubling gives
co-op's heaps 2-3x headroom for fights the replay never had, and the remaster's menus room to grow.

**Streaming.** CWorldStreamManager (pump 0x002089f0) keeps a state per room id (+0x5a4: 0 out, 1 resident and
wanted, 2 wanted, 3 resident and unwanted) and follows the main actor's room (+0x59c): a change applies the transition
table's entry (from, to) (+0x58c, 0x56-byte entries: two lists of up to 20 room ids; entry (0, R) lists R's whole set)
through 0x00207a00 and sets the request (+0x590); while a request is set the pump loads the nearest wanted room (one at
a time, asynchronously, +0xaec), then unloads the farthest unwanted ones. Rooms live in 20 fixed slots (+0x48) and two
district slots (+0x570); a load with no free slot writes through a null slot. Downtown night has 128 rooms and sets of
5..19 rooms (mean 13): the main actor alone holds 16..19 of the 20 slots in the city. More slots would need a larger
manager object and Room Heap and new room-data heaps; this lane keeps the 20.

gfx/stream.c makes each living extra Hulk's room and then his set (nearest first) wanted as well, while the rooms
that are or will be resident stay within 20 and two districts; rooms only an extra wants are recorded in game state
and go back to unwanted when no Hulk wants them. It runs before each pump and after each of the main actor's
transitions (entry hooks on 0x002089f0 and 0x00207a00; the latter is called from another TU than the pump's own). When
the main actor's new set needs a slot the game's unwanted rooms go first, then ours (the game's 0x00207080 unloads a
resident one at once). An extra whose room stays out for 45 updates is put back beside the main actor ("stream").
Everything is computed from game state (the session's Hulks, their positions, the manager's tables), so peers stay in
lockstep.

**The 238-unit cull.** Each update 0x0002a960 removes any actor but the main one whose room is not resident (or who is
in no room) and who is more than sqrt(56700) = 238 units from the main actor, unless the actor is never expendable
(+0x1d78, am_SetNeverExpendable 0x00026ab0's byte), frozen (+0x1cf4) or +0x119. Extra Hulks were removed the update
after they crossed it (56 removals in a test that put them 250 units out every 10 s); coop.c now makes them never
expendable at every spawn (4 removals, all scripted events of the replay, as at 200 units).

**The leash: 300 units.** From the location's own tables (room centres and sets): with a Hulk within 250 units of the
main actor his room is in the main actor's set 98.8% of the time and his room plus its neighbours fit beside it
99.9%; at 300, 84.8% and 95.3%; at 400, 21% and 69% (the slots run out). Test runs put the extras 250, 300, 400 and 600
units out every 10 s for ~14,000 frames: at 250 and 300 every target room was already resident; at 400, 16 of 70
placements landed in rooms that were not, and 6 Hulks had to be put back; at 600, 27 and 14.

**Tests.** play3 to 60,000 frames with co-op off, against HEAD's app: identical records (job 112134). Measurements:
jobs 112105-112111, 112126-112131 (`HULK_COOP_FROM=38000`, `HULK_COOP_SPREAD`, `HULK_COOP_LEASH=3000`,
`HULK_COOP_STREAM=0`).

## 20. Skins: each player's own, and comic skins (wskin1, D248 / D250, 2026-11-27)

Code: src/platform/wasm/gfx/skins.c (with hooks in coop.c, netplay.c and tutorial_skip.c's update hook; rows in
port_settings.c; menu strings in fe_options.c).

**How a Hulk gets his model (traced).** Section 6.5's open question is answered: every `art/global_<skin>.p3d` names
its objects alike (CompositeDrawable `hulk`, PolySkin `hulk_skin`, Skeleton `hulk_skeleton`, ShadowSkin
`hulk_shadow`, shaders `lambert1` and `TheIncredibleHulk_*` or `Hulk_*`), so two skins collide in one inventory. But a
character does not find his model by name at draw time: CCharacter's set-up (0x00042b40's `Setup`) asks the render
engine (`FUN_001c3d90()`) for a CRenderableCharacter through 0x001c3b20 (character name id, drawable name id) ->
0x001c60f0 -> 0x001c5900, which copies an **ObjectTemplate** found by the drawable's name id in the object manager's
template store (engine +0xc; templates are made by 0x001c4190 from the level loader's inventory when the character
template manager sets up a definition, 0x00045da0's tail). So a second skin needs only (1) its own inventory, loaded
by the game's own loader (0x00203e90, asynchronously: request polled with 0x00266750, taken into the inventory with
0x00266220), and (2) a template under a name id of ours (`port_skin_<name>`: ObjectTemplate 0x001c5cf0 over the
inventory's `hulk` DrawableHierarchy, added with 0x001c5ae0), and (3) the drawable id of the one model request made
while the spawner builds that Hulk swapped for ours (entry hook 0x001c3b20). The pose still comes from the main
definition's skeleton; every skin's `hulk_skeleton` has the same joints (3,724-byte chunk in all 14 files).

**Choosing (D248).** Gameplay Options gets "Co-op Skin" (remastered only; choices are the game's own cheat names, so no
new strings): the skin this player wears in someone else's co-op game. It is each peer's own (left out of the settings
the host hands a guest) and rides in bits 8..11 of the peer's pad wButtons in every lockstep set (netplay.c; the game
never reads those bits), so every peer learns slot k's choice at the same frame. The skin Hulk k is made with: a comic's
skin he picked up (below), else his choice, else the co-op pair's other one; a choice the host's save has not unlocked
falls back to the pair (`hulk`, `grey_hulk`: always offered); a skin another Hulk already wears gives way to the pair's
other one (section 6.5's rule). The developer's local Hulks (`dev_coop_local`) take the row for P1 and the pair for P2.
In a mission that forces a skin (0x00206320: joefixit or a national Hulk) every extra Hulk wears the forced one,
tinted (below).
Skins no Hulk wears are never loaded; at most two extra skins are resident (Persistent heap 0x11, ~200 KB each, which
the doubled co-op heaps of section 19 hold). Hulk k waits for his skin's load before he is made (a few updates; a
failed load makes him with the main actor's skin).

**Comic skins (D250, D250c).** Gameplay Options "Auto-Apply Comic Skins" (remastered only, faithful off, remastered
default on). A comic book whose reward is a skin's cheat (comic -> reward is the game's Lua table
`jk_comic_to_unlockable`; its pick-up handler in scripts/fight/common.fig only shows the code) is now unlocked the way a
typed code unlocks it (`um_SetUnlockableLocked` -> 0x00093db0 -> 0x00093600) and worn: the pick-up (0x001d8350, a
ComicBook prop, kind 8) marks the Hulk that took it; the next updates ask the game's Lua which skins' comics are
collected (our one line over the game's table and bindings, as kmcIsCheatComicCollected does); a skin that has just
joined the set is unlocked and worn. Player 0 wears it through the cheats screen's own path (every skin's "on" bit off,
this one on, `um_SetUnlockableOn`), which the game applies at the next level load (0x00203a10; the mission, a retry or
the next area), as a choice in the cheats screen does, and at once (wskin2, below). An extra co-op Hulk wears it at
once (he is made again beside the main actor with it). When a save
is loaded (0x0008a8f0) and at every level start, every skin whose comic the save holds is unlocked, and nothing is
switched (the user, 11-25). The save gains only the locked and on bits a typed code and the cheats screen would have
written.

**Menus.** A text selector's choice list is one line of the front end's script: the Co-op Skin row's fourteen
`TBS_CHEAT_*` ids made a line the parser crashed on at start-up (every run, faithful or not). fe_options.c parses such
a row (ids longer than 160 characters in all) with its first choice and relabels it in full when its screen is set up,
as a scrolled place is.

Extra skins load only where the game heaps were scaled for co-op (the Persistent heap's row of the image's heap table
at least 4 MiB: section 19); with the original sizes every Hulk wears the main actor's skin. The table is image data,
so an online guest, who takes the host's memory, decides as the host does.

**Tests** (app 112272, HEAD control 112253): play3 to 60,000 with the rows faithful: records identical to HEAD's (112273).
`HULK_COMIC_TEST=4000:0:2` (comic 2 as if player 0 picked it up): unlocked by its comic 0x0020 (Canadian flag shorts),
worn (on bits 0x0020) (112274); `4000:-1:2` (swept as a loaded save is): unlocked, not worn (112275). A real save that
holds skin comics (a copy of whang1's test saves, loaded by the front end's auto-load and Continue): with the row on the
load unlocked the skins of its collected comics (0x0420: Canadian and Italian flag shorts) and switched nothing; with
it off nothing changed (job 112294, build/wskin1/retro/run.sh). Online co-op (`coop:12000:2`, remastered, the guest's
Co-op Skin Joe Fixit, app 112292): host and guest load `global_joefixit.p3d` at the same frame (4,531 -> 4,534), make
the template and spawn player 1 with it at frame 4,535, no desync, every game hash agrees. Three local Hulks
(`dev_coop_local=3`, Co-op Skin Joe Fixit; P2 takes the pair's grey_hulk), Metal: the tutorial shows Joe Fixit, the green
Hulk and the grey Hulk side by side, each with his own textures and animating (112286, shots 4,500 and 5,500). A
rolltest 4000:6500 over the same set-up (both skins loaded at ~1,560): identical game hash after the restore (112300). A comic
for player 1 (`HULK_COMIC_TEST=4000:1:2`, two local Hulks, Metal): the Canadian flag shorts unlocked, player 0's "on"
bits untouched, Hulk 1 made again with them at frame 4,007 (112307). Landing checks on the rebased build (app 112302,
HEAD control 112301): play3 to 60,000 records identical (112303); the comic test (112304); `coop:12000:2` with skins
(112305) and without (112306) ok.

**Player 0's comic skin at once (wskin2).** With the comic row on (remastered) and the heaps scaled, player 0's new
skin is loaded into a slot of ours (as an extra Hulk's) and his model is made again in play the way CCharacter's
`Setup` (0x00042b40) makes it: the CRenderableCharacter under the character's name is let go (render engine
0x001c3b30), a new one is asked for with our template's name id (0x001c3b20), given the character's pose (+0x120,
0x001c5e20) and the rig's flag (rig +0xc: 0x001c5050 on the model's object and its +0x20). The pose, the skeleton, the
collision and the animation are the character's and do not change: the swap is between two updates and the Hulk goes
on in the same pose (play3's checkpoint records are unchanged by it). The on bits are still set as the cheats screen
sets them, so the next level load wears the skin by the game's own path, and the slot is not needed after it. Not in a
level that forces a skin (the mission's look stays; the skin comes with the next level load), and with the original
heap sizes only from the next level load. Skin slots are three now (one a player at most); an extra co-op Hulk in the
skin player 0 just took is made again with another (section 6.5's rule). Whether the level forces player 0's skin is
found once a level (by its main actor), before a comic's skin turns the on bits over.

**Tinted copies of a forced skin (wskin2, the user's rule in 6.5).** An extra Hulk who wears player 0's skin (a
mission's forced skin; also every extra Hulk where the heaps keep only the main actor's skin) is drawn with a tint of
his own (player 1 red, player 2 blue, luminance kept, 60%): picture only, game state unchanged. Every Hulk's model has
PolySkins of its own (the template's copied by 0x002b7e50), each with its pose (+0x60) and a BoneMatrixList of its own
(+0x58), which its display (PolySkin::vfunc_8 0x002b7900, entry hook) fills from the pose. The skinned primitives are
sorted into pure3d's display lists and drawn when the lists are flushed (so a hook around a character's display sees
none of his draws), each handing its bone matrices to the pddi front end's skinning extension
(bgfxExtHardwareSkinning::vfunc_5, the game's 0x00322200) just before its draw. skins.c records the bone lists of the
tinted Hulks' PolySkins; the extension (under HULK_PDDI_WASM) asks skins.c whose list a matrix is in, and gfx.c tags
the skinned draws that follow (`DrawPacket::instance` = "HULK" << 32 | k). The runner's lighting pass draws a tagged
skin draw with `fs_px_chartint` (fs_px_char's program with fs_px_stage.sh `PX_TINT`: the tint at the combiner's output,
`u_rmTint`), whatever Character Lighting is. `HULK_SKIN_TINT=r,g,b,s;r,g,b,s` tunes the two tints; `HULK_SKIN_SAME=1`
(tests) dresses every extra Hulk in player 0's skin, as a forced mission does.

wskin2 tests (app 112482, HEAD control 112483): play3 to 60,000 with the rows faithful, records identical (112484);
`HULK_COMIC_TEST=4000:0:2` on Metal: the Canadian flag shorts from frame 4,064, same pose (112486); rolltests across
the swap (3,950:4,400, 112482) and after it (4,100:4,400, 112485) identical; three local Hulks with
`HULK_SKIN_SAME=1 HULK_COOP_SPREAD=5:30` on Metal: players 1 and 2 tinted (112498). The game's cheats screen calls the
default skin "Savage Hulk" (TBS_CHEAT_HULK), so the Co-op Skin row's first choice (value 0, the plain Hulk) reads so.
