#include "decls/address.h"
extern unsigned int g_lo_35c760;
extern unsigned int g_hi_35c760;

void FUN_0035c760() {
    unsigned long long r = FUN_0027b020("missilesoldier");
    g_lo_35c760 = (unsigned int)r;
    g_hi_35c760 = (unsigned int)(r >> 32);
}
