#include "compat/ptr.h"
extern "C" char hulk_at_00400488[];
struct Hash_35dfe0 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Hash_35dfe0 __cdecl FUN_0027b020(const char*);
extern unsigned int g_lo_35dfe0, g_hi;

void __cdecl FUN_0035dfe0() {
    Hash_35dfe0 h = FUN_0027b020((const char*)((hulk_intptr)hulk_at_00400488));
    g_lo_35dfe0 = h.lo;
    g_hi = h.hi;
}
