#include "decls/data/engine/audio.h"
// data: gData_24c3b0 = DAT_004cc258

extern "C" int FUN_0024c3b0(unsigned int* format, int count) {
    return ((*format >> 4) & 0x1f) * ((int*)&DAT_004cc258)[((int)(*format << 28) >> 28) * 6] * count;
}