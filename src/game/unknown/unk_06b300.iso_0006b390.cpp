// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006b300..0x0006bd20 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x0006b390 FUN_0006b390 (12 B): matches/0x0006b390.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?FUN_0006b390@C_6b390@owners@@QAEDH@Z
#include "gen/owners.h"

char owners::C_6b390::FUN_0006b390(int v) {
    *(int*)((char*)this + 0x28) = v;
    return 1;
}

