// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000e75e0 FUN_000e75e0 (59 B): matches/0x000e75e0.cpp [isolated: conflict: DAT_0049dba4; on include/gen/ and not mergeable]
// sym: ?FUN_000e75e0@ThisWrap_000e75e0@owners@@QAEHH@Z
#include "gen/owners.h"
extern int FUN_00344e74(int, int, int*, int*, int);
extern int DAT_0049dba4, DAT_0049f4f0, DAT_0049f4c0;
hulk_intptr owners::ThisWrap_000e75e0::FUN_000e75e0(int x) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(x), 0, &DAT_0049dba4, &DAT_0049f4f0, 0), 0, &DAT_0049f4f0, &DAT_0049f4c0, 0);
}

