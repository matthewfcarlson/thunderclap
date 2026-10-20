#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
struct Pair_35d180 {
    unsigned int lo;
    unsigned int hi;
};
extern Pair_35d180 __cdecl FUN_0027b020(void*);
extern unsigned int g_LO;
extern unsigned int g_HI;

void __cdecl FUN_0035d180() {
    Pair_35d180 p = FUN_0027b020((void*)((hulk_intptr)hulk_at_0040048c));
    g_LO = p.lo;
    g_HI = p.hi;
}
