#include "decls/data/game/global.h"

extern "C" {
extern int gCounts[22];
extern int gBases[22];
void* FUN_000b08a0(int index, int item) {
    if (index >= 0 && index < 11 && item >= 0 && item < gCounts[index * 2])
        return (char*)gBases[index * 2] + item * 32;
    return (void*)((int)((char*)&DAT_003f335c));
}
}