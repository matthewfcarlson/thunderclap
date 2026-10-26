#include "decls/data/game/global.h"
// data: gPair = DAT_004de628, hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(hulk_intptr);
void FUN_0035d810() {
    (*(Pair*)&DAT_004de628) = FUN_0027b020(((hulk_intptr)((char*)&DAT_0040048c)));
}