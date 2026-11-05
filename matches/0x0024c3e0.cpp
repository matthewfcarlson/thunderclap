#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

typedef unsigned int uint_24c3e0;
extern "C" hulk_uintptr __cdecl FUN_0024c3e0(uint_24c3e0* format, uint_24c3e0 bytes) {
    return bytes / (((*format >> 4) & 0x1f) * ((int*)&DAT_004cc258)[((int)(*format << 0x1c) >> 0x1c) * 6]);
}