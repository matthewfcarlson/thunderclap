// Same code shape as 0x00085cd0 (propagated; names are from that function)
// Returns the gameplay RNG's pointer (DAT_004e5acc): a pointer, so it stays whole on 64-bit
#include "decls/data/game/unknown.h"

extern "C" void* FUN_000964d0(void) {
    return (*(void**)&DAT_004e5acc);
}
