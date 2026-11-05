#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" int __cdecl FUN_002673a0(const char*, int);

void FUN_00360060() {
    *(int*)((hulk_intptr)DAT_004e69a8) = FUN_002673a0("ChannelVolumeFade", 0);
}