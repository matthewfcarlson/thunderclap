#include "decls/address.h"
extern int g_a;
extern int g_b;
extern const char m[];

void __cdecl FUN_0035e1a0() {
    unsigned long long r = FUN_0027b020(m);
    g_a = (int)r;
    g_b = (int)(r >> 32);
}
