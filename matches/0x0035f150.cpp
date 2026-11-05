#include "decls/data/engine/fight.h"
// data: gGlobal = DAT_004ca27c

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
int gLow;
int gHigh;
void __cdecl FUN_0035f150() {
    unsigned long long v = FUN_002672f0((*(const char**)&DAT_004ca27c), 0, 0);
    gLow = (int)v;
    gHigh = (int)(v >> 32);
}
