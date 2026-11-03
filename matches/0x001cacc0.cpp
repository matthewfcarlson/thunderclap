#include "gen/owners.h"
class Item_1cacc0 {
  public:
    void Finish();
};
Item_1cacc0* GetItem();
bool owners::Owner_1cacc0::FUN_001cacc0() {
    Item_1cacc0* item = GetItem();
    if (!item)
        return false;
    if (!((owners::Obj_1d2e80 *)item)->FUN_001d2e80())
        return false;
    ((owners::Obj_1d1dd0 *)item)->FUN_001d1dd0((hulk_intptr)"old", oldValue);
    ((owners::Obj_1d1dd0 *)item)->FUN_001d1dd0((hulk_intptr)"new", newValue);
    item->Finish();
    return true;
}