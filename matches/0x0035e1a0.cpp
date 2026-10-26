#include "decls/address.h"
#include "decls/data/game/global.h"
extern int g_a;
extern int g_b;

void __cdecl FUN_0035e1a0() {
    unsigned long long r = FUN_0027b020(DAT_00400490);
    g_a = (int)r;
    g_b = (int)(r >> 32);
}
