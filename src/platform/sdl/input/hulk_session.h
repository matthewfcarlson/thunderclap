// Live session mode (docs/multiplayer.md "M0" and "Control port"): lockstep input streaming between two instances
// over UDP, state-hash exchange, and the debug control port. Off unless the environment asks for it:
//   HULK_NET=send|recv|rb     the session role (rb: the rollback session, below). send (instance A): its pads are the session's; every pad read is
//                             streamed to the peer. recv (instance B): every pad read returns A's read of the same
//                             index (waiting for it); the local source is not read for state.
//   HULK_NET_BIND=PORT        the local UDP port (0.0.0.0)
//   HULK_NET_PEER=A.B.C.D:P   the peer's address (numeric IPv4; through tools/netshim.py for impaired links)
//   HULK_NET_LEAD=N           (send) frames A may run ahead of B's last report before it waits (default 8)
//   HULK_NET_REDUNDANCY=N     unacknowledged frame records re-sent in each packet (default 32)
//   HULK_NET_HASH_EVERY=N     state-hash interval in frames (default 30; 0 = none)
//   HULK_NET_TIMEOUT=S        seconds without the peer before the session gives up (default 600: the peer may start late)
//   HULK_NET_LOG=FILE         a log of the session (stats every 300 frames, every hash comparison) besides SDL_Log
//   HULK_CTL_PORT=PORT        the control port on 127.0.0.1 (debug builds only: not compiled with NDEBUG or
//                             HULK_RELEASE): text commands over UDP, see hulk_session.cpp
// The simulation never reads anything here: the session only decides which pad state a read returns and when a
// frame may start. Frame numbers are the checkpoint hook's (GameClock::Update calls).
#ifndef HULK_PLATFORM_SDL_SESSION_H
#define HULK_PLATFORM_SDL_SESSION_H

#include "hulk_input.h"

#ifdef __cplusplus
extern "C" {
#endif

int hulk_session_active(void);                          // 1 when HULK_NET, the control port or HULK_LAT_PROBE is set
unsigned hulk_session_hash_interval(void);              // frames between state hashes (0: none)
// once per GameClock::Update, at its entry: FRAME is the checkpoint frame number; HASH the session's state hash
// when HAVE_HASH (the frame is a multiple of the interval). May block (lockstep gate, control-port pause).
void hulk_session_frame(unsigned frame, int have_hash, unsigned hash);
// wraps the input source the game reads (hulk_input_init calls it; returns INNER when no session is configured)
const HulkInputSource* hulk_session_wrap(const HulkInputSource* inner);
// mp3, the latency probe (xdk/snapshot.cpp, HULK_LAT_PROBE, which also turns the wrapper on): S is ORed over every
// read of PORT (buttons and analog buttons ORed, a non-zero stick replaces) until called with S = 0; the count of
// reads it applied to so far
void hulk_session_pad_or(unsigned port, const HulkPadState* s);
unsigned hulk_session_pad_or_reads(void);

// mp3, the rollback session (HULK_NET=rb; docs/multiplayer.md section 16). Two players, one per instance; the game's
// one controller reads both pads merged (buttons ORed, the first non-zero stick), so either player's input changes
// the simulation. Each instance sends its own player's input per frame, predicts the other's (the last state it
// has), and when the real input differs from the prediction restores the snapshot of that frame and runs again.
//   HULK_NET_RB_PLAYER=0|1    this instance's player: 0 takes its input from the input source (a recording's polls,
//                             up to 61 reads a frame), 1 from a seeded random generator (HULK_NET_RB_SEED,
//                             from frame HULK_NET_RB_P1_FROM, default 12000)
//   HULK_NET_RB_WINDOW=N      frames of prediction before the instance waits for the peer (default 8)
//   HULK_NET_RB_DELAY=N       frames of input delay on the local player (default 0)
//   HULK_NET_BIND, HULK_NET_PEER, HULK_NET_LOG, HULK_NET_HASH_EVERY, HULK_NET_TIMEOUT as for M0
// The snapshot side (xdk/snapshot.cpp) calls hulk_session_rb_frame at every GameClock::Update entry with these:
typedef struct HulkSnapOps {
    int (*save)(unsigned slot, unsigned frame);         // 1: the current state is in ring slot SLOT as FRAME
    int (*restore)(unsigned slot, unsigned frame);      // 1: restored; the game's frame number is FRAME again
    unsigned (*hash_big)(void);                         // the shared state (arena and game data)
    unsigned (*hash_small)(unsigned frame);             // the M0 session hash (actors, mission state)
    unsigned (*fibers)(void);                           // fiber switches + drive posts so far (no restore across one)
    unsigned slots;                                     // ring slots available
} HulkSnapOps;
int hulk_session_rb_active(void);
// at frame FRAME's start; returns the frame the game now runs (FRAME, or an earlier one after a restore)
unsigned hulk_session_rb_frame(unsigned frame, const HulkSnapOps* ops);
int hulk_session_rb_resimulating(void);

#ifdef __cplusplus
}
#endif

#endif
