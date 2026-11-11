// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000e75a0 FUN_000e75a0 (59 B): matches/0x000e75a0.cpp [isolated: compile error in a shared declaration (C2371); on include/gen/ and not mergeable]
// sym: ?FUN_000e75a0@ThisWrap_000e75a0@owners@@QAEHH@Z
#include "gen/owners.h"
extern int DAT_0049dbbc, DAT_0049f4f0, DAT_0049dba4;
extern "C" int __cdecl FUN_00344e74(int, int, int*, int*, int);
int owners::ThisWrap_000e75a0::FUN_000e75a0(int x) {
    return FUN_00344e74(FUN_00344e74(this->inner(x), 0, &DAT_0049dba4, &DAT_0049f4f0, 0), 0, &DAT_0049f4f0, &DAT_0049dbbc, 0);
}

