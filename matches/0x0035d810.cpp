#include "compat/ptr.h"
extern "C" char hulk_at_0040048c[];
struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(int);
extern Pair gPair;
void FUN_0035d810() {
    gPair = FUN_0027b020(((hulk_intptr)hulk_at_0040048c));
}