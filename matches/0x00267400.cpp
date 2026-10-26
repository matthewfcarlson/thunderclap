#include "decls/data/engine/unknown.h"
// data: initFlag = DAT_00528370

void FUN_00267400(void) {
    if (!(*(unsigned char*)&DAT_00528370)) {
        unsigned int i = 0;
        do {
            unsigned int v = i << 24;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            if (v & 0x80000000U)
                v = (v << 1) ^ 0x04c11db7;
            else
                v <<= 1;
            ((unsigned int*)&DAT_00527f70)[i] = v;
            ++i;
        } while (i < 256);
        (*(unsigned char*)&DAT_00528370) = 1;
    }
}