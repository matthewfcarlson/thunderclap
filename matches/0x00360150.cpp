#include "decls/data/engine/audio.h"

extern "C" int __cdecl FUN_002673a0(const char*, int);
void FUN_00360150() {
    (*(int*)&DAT_004e6a60) = FUN_002673a0("ChannelVolumeFade", 0);
}