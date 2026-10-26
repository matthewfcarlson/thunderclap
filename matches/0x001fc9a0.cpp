#include "decls/data/game/global.h"
// data: fallback = DAT_003f335c

struct Item {
    char pad[64];
    Item* Get();
};
class Obj {
    char pad[0x20c];
    int count;
    Item* items;

  public:
    Item* Find(int index);
};
Item* Obj::Find(int index) {
    if (index < 0 || index > count)
        return (Item*)&(*(int*)&DAT_003f335c);
    Item* p = &items[index];
    return p->Get();
}