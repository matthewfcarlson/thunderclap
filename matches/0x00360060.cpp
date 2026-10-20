#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" int __cdecl CreateThing(const char*, int);

void FUN_00360060() {
    *(int*)((hulk_intptr)DAT_004e69a8) = CreateThing("ChannelVolumeFade", 0);
}