// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000e74e0 FUN_000e74e0 (59 B): matches/0x000e74e0.cpp [isolated: compile error C3861: 'DAT_0049dba4': identifier not found, even with argument-dependent lookup; on include/gen/ and not mergeable]
// sym: ?FUN_000e74e0@ThisWrap_000e74e0@owners@@QAEHH@Z
#include "gen/owners.h"
extern int __cdecl FUN_00344e74(int, int, void*, void*, int);
extern char DAT_0049dba4, DAT_0049f4f0, DAT_0049f470;
int owners::ThisWrap_000e74e0::FUN_000e74e0(int x) {
    return FUN_00344e74(FUN_00344e74(this->Inner(x), 0, &DAT_0049dba4, &DAT_0049f4f0, 0), 0, &DAT_0049f4f0, &DAT_0049f470, 0);
}

