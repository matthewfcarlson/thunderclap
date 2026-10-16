#include "decls/address.h"
extern int g_lo;
extern int g_hi;
void FUN_0035f2e0() {
    unsigned __int64 v = FUN_002672f0("Runtime_Hal", 0, 0);
    g_lo = (int)v;
    g_hi = (int)(v >> 32);
}
