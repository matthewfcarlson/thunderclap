/* libjuice (ICE, STUN, TURN over UDP; MPL-2.0: ../net/libjuice/LICENSE) for the app's co-op transport (netplay.cpp; wnet1).
 * Pinned upstream: paullouisageneau/libjuice v1.7.4, archive sha256
 * 95c088862aa1b88b73d62aa99577135010eb768fcafb252d13aa85a8515ef798, src/ and include/juice/juice.h unchanged (juice.h
 * moved into src/ so these wrappers need no include path). The build tools compile every .c of run/app, so the library
 * comes as a few translation units: the mux back end. */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#ifndef _DARWIN_C_SOURCE
#define _DARWIN_C_SOURCE 1
#endif
#define JUICE_STATIC 1
#define JUICE_EXPORTS 1
#define USE_NETTLE 0
#define RELEASE 1
#include "../net/libjuice/src/conn_mux.c"
