#include "gen/owners.h"
struct Item {
    char pad[8];
    int kind;
};
struct Manager {
    char pad[0x44];
    int count;
};
class Obj {
  public:
    char pad[4];
    Manager* mgr;
    int* values;
    bool Fetch(int index, int* out);
};
bool Obj::Fetch(int index, int* out) {
    if (index < 0)
        return false;
    if (index >= mgr->count)
        return false;
    if (((Item *)((owners::Thing_337090 *)mgr)->FUN_00337090(index))->kind != 3)
        return false;
    *out = values[index];
    return true;
}