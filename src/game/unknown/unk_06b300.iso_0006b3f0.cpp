// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006b300..0x0006bd20 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x0006b3f0 FUN_0006b3f0 (12 B): matches/0x0006b3f0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?FUN_0006b3f0@A_6b3f0@owners@@QAE_NH@Z
#include "gen/owners.h"

bool owners::A_6b3f0::FUN_0006b3f0(int x) {
    *(int*)((char*)this + 0x34) = x;
    return true;
}

