// Live session mode (docs/multiplayer.md "M0" and "Control port"): lockstep input streaming between two instances
// over UDP, state-hash exchange, and the debug control port. Off unless the environment asks for it:
//   HULK_NET=send|recv        the session role. send (instance A): its pads are the session's; every pad read is
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

int hulk_session_active(void);                          // 1 when HULK_NET or the control port is configured
unsigned hulk_session_hash_interval(void);              // frames between state hashes (0: none)
// once per GameClock::Update, at its entry: FRAME is the checkpoint frame number; HASH the session's state hash
// when HAVE_HASH (the frame is a multiple of the interval). May block (lockstep gate, control-port pause).
void hulk_session_frame(unsigned frame, int have_hash, unsigned hash);
// wraps the input source the game reads (hulk_input_init calls it; returns INNER when no session is configured)
const HulkInputSource* hulk_session_wrap(const HulkInputSource* inner);

#ifdef __cplusplus
}
#endif

#endif
