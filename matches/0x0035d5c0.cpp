#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
struct Pair_35d5c0 {
    int a;
    int b;
};
Pair_35d5c0 __cdecl FUN_0027b020(int*);
extern int gFirst_35d5c0;
extern int gSecond_35d5c0;
void FUN_0035d5c0() {
    Pair_35d5c0 p = FUN_0027b020((int*)((hulk_intptr)hulk_at_0040048c));
    gFirst_35d5c0 = p.a;
    gSecond_35d5c0 = p.b;
}