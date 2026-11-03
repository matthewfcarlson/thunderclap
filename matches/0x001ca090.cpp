#include "decls/data/game/global.h"
// data: checkpoint = DAT_00421ba0
#include "gen/owners.h"

class Thing_1ca090 {
  public:
    void finish();
};
Thing_1ca090* GetThing();
bool owners::Owner_1ca090::FUN_001ca090() {
    Thing_1ca090* t = GetThing();
    if (!t)
        return false;
    if (!((owners::Obj_1d2e80 *)t)->FUN_001d2e80())
        return false;
    ((owners::Obj_1d1dd0 *)t)->FUN_001d1dd0((hulk_intptr)DAT_00421ba0, value);
    t->finish();
    return true;
}