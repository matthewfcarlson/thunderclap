#include "decls/data/engine/audio.h"

extern "C" int FUN_0024c480(unsigned int* format, unsigned int bytes) {
    unsigned int x = *format;
    int index = (int)(x << 28) >> 28;
    unsigned int m = (x >> 4);
    m &= 31;
    unsigned int d = *(unsigned int*)(((unsigned char*)&DAT_004cc254) + index * 24);
    unsigned int s = m * *(unsigned int*)(((unsigned char*)&DAT_004cc258) + index * 24);
    unsigned int q = bytes / d;
    unsigned int r = bytes % d;
    return (r * s) / d + q * s;
}
