// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000e7560 FUN_000e7560 (59 B): matches/0x000e7560.cpp [isolated: conflict: DAT_0049dba4; on include/gen/ and not mergeable]
// sym: ?FUN_000e7560@ThisWrap_000e7560@owners@@QAEHH@Z
#include "gen/owners.h"
extern char DAT_0049dba4[], DAT_0049f4f0[], DAT_0049f454[];
extern "C" int __cdecl FUN_00344e74(int, int, char*, char*, int);
int owners::ThisWrap_000e7560::FUN_000e7560(int x) {
    return FUN_00344e74(FUN_00344e74(this->helper(x), 0, DAT_0049dba4, DAT_0049f4f0, 0), 0, DAT_0049f4f0, DAT_0049f454, 0);
}

