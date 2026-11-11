// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006b300..0x0006bd20 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0006b6f0 FUN_0006b6f0 (41 B): matches/0x0006b6f0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?FUN_0006b6f0@C_6b6f0@owners@@QAE_NM@Z
#include "gen/owners.h"
extern hulk_freg __cdecl FUN_0004af40(float, float, float);
bool owners::C_6b6f0::FUN_0006b6f0(float x) {
    angle = FUN_0004af40(-180.0f, 180.0f, x) * 0.017453292f;
    return true;
}

