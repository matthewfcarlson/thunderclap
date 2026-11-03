// Same code shape as 0x001ca090 (propagated; names are from that function)
#include "decls/data/game/global.h"
#include "gen/owners.h"

class Thing_1caf40 {
  public:
    void finish();
};
Thing_1caf40* FUN_001d4c90();
bool owners::Owner_1caf40::FUN_001caf40() {
    Thing_1caf40* t = FUN_001d4c90();
    if (!t)
        return false;
    if (!((owners::Obj_1d2e80 *)t)->FUN_001d2e80())
        return false;
    ((owners::Obj_1d1d90 *)t)->FUN_001d1d90((hulk_intptr)DAT_00421cb0, value);
    t->finish();
    return true;
}