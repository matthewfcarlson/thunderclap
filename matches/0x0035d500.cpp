#include "decls/data/game/global.h"
// data: hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(hulk_intptr);
extern Pair g;
void FUN_0035d500() {
    g = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}