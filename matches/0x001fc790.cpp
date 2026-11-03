#include "gen/owners.h"
class Item_1fc790 {
  public:
};
class Thing_1fc790 {
  public:
    char pad[8];
    int count;
    Item_1fc790* items[1];
    void ClearAll();
};
void Thing_1fc790::ClearAll() {
    for (int i = 0; i < count; ++i)
        ((owners::Obj_1fb940 *)(items[i]))->FUN_001fb940();
}