#include "compat/ptr.h"
#include "decls/data/game/global.h"
// data: gBases = DAT_004ddb14, gCounts = DAT_004ddb10

extern "C" {
void* FUN_000b08a0(int index, int item) {
    if (index >= 0 && index < 11 && item >= 0 && item < ((int*)&DAT_004ddb10)[index * 2])
        return (char*)((int*)((char*)&DAT_004ddb10 + 4))[index * 2] + item * 32;
    return (void*)((hulk_intptr)((char*)&DAT_003f335c));
}
}