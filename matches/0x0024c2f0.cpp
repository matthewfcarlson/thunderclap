#include "decls/data/engine/audio.h"
// data: gTable_24c2f0 = DAT_004cc258

int FUN_0024c2f0(unsigned int* p) {
    unsigned int v = *p;
    int index = (int)(v << 28) >> 28;
    return (int)((v >> 4) & 31) * *(int*)((char*)((int*)&DAT_004cc258) + index * 24);
}