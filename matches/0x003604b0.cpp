#include "decls/data/engine/audio.h"

// the name's hash (0x002673a0, an int)
extern "C" int __cdecl FUN_002673a0(const char*, int);
void FUN_003604b0() {
    (*(int*)&DAT_004e6d28) = FUN_002673a0("ChannelVolumeFade", 0);
}