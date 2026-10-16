#include "decls/address.h"
extern unsigned int g_hash_lo;
extern unsigned int g_hash_hi;
void __cdecl FUN_0035d540(const char* s) {
    (void)s;
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    g_hash_lo = (unsigned int)v;
    g_hash_hi = (unsigned int)(v >> 32);
}
