#include "decls/data/game/global.h"
// data: zero_35cf0 = DAT_003f32e0

class Item_35cf0 {
    char pad[0x190];

  public:
    int value;
};
class Helper_35cf0 {
  public:
    int Method();
};
class Obj_35cf0 {
  public:
    char pad0[0x11c];
    Item_35cf0* item;
    char pad120[8];
    Helper_35cf0* thing;
    char pad12c[0x324 - 0x12c];
    int add;
    char pad328[0x1b0c - 0x328];
    float f;
    int FUN();
};
int Obj_35cf0::FUN() {
    int x = 100;
    if (item)
        x = item->value + 100;
    x += add;
    if (thing)
        x += thing->Method();
    if (f <= DAT_003f32e0 && x > 0)
        return 0;
    return x;
}