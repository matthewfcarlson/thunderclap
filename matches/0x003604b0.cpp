#include "decls/data/engine/audio.h"

extern "C" void* __cdecl FUN_002673a0(const char*, int);
void FUN_003604b0() {
    (*(void**)&DAT_004e6d28) = FUN_002673a0("ChannelVolumeFade", 0);
}