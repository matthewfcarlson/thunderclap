// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c96e0..0x001cc5e0 (kind game, layer game, confidence high), dominant class CEventManager
// (tree_prelude.h: not needed)


// 0x001cadb0 FUN_001cadb0 (59 B): matches/0x001cadb0.cpp [isolated: conflict: FUN_001d4c90; on include/gen/ and not mergeable]
// sym: ?FUN_001cadb0@Owner_1cadb0@owners@@QAE_NXZ
// Same code shape as 0x001ca090 (propagated; names are from that function)
#include "decls/data/game/global.h"
#include "gen/owners.h"

class Thing_1cadb0 {
  public:
    void finish();
};
Thing_1cadb0* FUN_001d4c90();
bool owners::Owner_1cadb0::FUN_001cadb0() {
    Thing_1cadb0* t = FUN_001d4c90();
    if (!t)
        return false;
    if (!((owners::Obj_1d2e80 *)t)->FUN_001d2e80())
        return false;
    ((owners::Obj_1d1dd0 *)t)->FUN_001d1dd0((hulk_intptr)DAT_00421ca8, value);
    t->finish();
    return true;
}

