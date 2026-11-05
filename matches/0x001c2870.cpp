#include "compat/ptr.h"
#include "gen/owners.h"
class Item_1c2870 {
  public:
    char pad[16];
};
class Container_1c2870 {
  public:
    int count;
    Item_1c2870 items[1];
    bool Find(hulk_intptr x);
};
bool Container_1c2870::Find(hulk_intptr x) {
    int i = count;
    while (--i >= 0) {
        if (!((owners::Plane_22e080 *)&(items[i]))->FUN_0022e080((const float *)(hulk_uintptr)(int)x))
            return false;
    }
    return true;
}