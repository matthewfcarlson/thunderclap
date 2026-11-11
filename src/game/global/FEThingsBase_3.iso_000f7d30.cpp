// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f1570..0x000f8690 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000f7d30 FUN_000f7d30 (36 B): matches/0x000f7d30.cpp [isolated: conflict: FUN_0027b020; on include/gen/ and not mergeable]
// sym: ?FUN_000f7d30@A_f7d30@owners@@QAEHH@Z
#include "gen/owners.h"
extern unsigned long long __cdecl FUN_0027b020(int);
hulk_intptr owners::A_f7d30::FUN_000f7d30(hulk_intptr p) {
    int r = f(FUN_0027b020(((int)p)));
    if (r != -1)
        return r;
    return r | r;
}

