#include "decls/data/engine/fight.h"
// data: gGlobal = DAT_004ca27c

extern "C" unsigned long long __cdecl FUN_002672f0(int, int, int);
int gLow;
int gHigh;
void __cdecl FUN_0035f150() {
    unsigned long long v = FUN_002672f0((*(int*)&DAT_004ca27c), 0, 0);
    gLow = (int)v;
    gHigh = (int)(v >> 32);
}
