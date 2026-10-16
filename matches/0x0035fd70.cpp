#include "decls/data/engine/audio.h"

extern int __cdecl FUN_002673a0(const char*, int);
void __cdecl FUN_0035fd70(void) {
    (*(int*)&DAT_004e6748) = FUN_002673a0("ChannelSendVolumeFade", 0);
}