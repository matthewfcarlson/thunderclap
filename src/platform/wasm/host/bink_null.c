/* Bink by address (the shapes: src/platform/sdl/xdk/movies_bink.cpp's notes): no decoder here, so BinkOpen fails and
 * the game goes on without the movie. */
#include "hulk_host.h"
#include "sim.h"

FFG(00364da0) { UNUSED; RET(0); }               /* BinkSetIO */
FFG(00364dc0) { UNUSED; RET(0); }               /* BinkSetSoundTrack */
FFG(00364fe0) { UNUSED; RET(0); }               /* BinkOpen: failed */
FFG(00367610) { UNUSED; RET(0); }               /* BinkSetVolume */
FFG(00367660) { UNUSED; RET(0); }               /* BinkSetMixBins */
FFG(00366b40) { UNUSED; RET(0); }               /* BinkPause */
FFG(00366940) { UNUSED; RET(0); }               /* BinkWait */
FFG(00367bc0) { UNUSED; RET(0); }               /* BinkDoFrame */
FFG(00365f30) { UNUSED; RET(0); }               /* BinkCopyToBufferRect */
FFG(003681d0) { UNUSED; RET(0); }               /* BinkNextFrame */
FFG(00368530) { UNUSED; RET(0); }               /* BinkClose */
FFG(00368660) { UNUSED; RET((uint32_t)(SIM->clock / (HULK_TSC_HZ / 1000))); }   /* the millisecond tick */
FFG(0033eb70) { UNUSED; }                       /* BinkSetMemory */
