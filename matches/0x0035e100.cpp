#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
struct Pair_35e100 {
    int a, b;
};
extern "C" Pair_35e100 __cdecl FUN_0027b020(hulk_intptr);
extern int g1_35e100;
extern int g2_35e100;
void __cdecl FUN_0035e100() {
    Pair_35e100 r = FUN_0027b020(((hulk_intptr)hulk_at_0040048c));
    g1_35e100 = r.a;
    g2_35e100 = r.b;
}
