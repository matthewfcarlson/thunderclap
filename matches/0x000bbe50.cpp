#include "decls/data/game/unknown.h"
// data: metalanim = DAT_00407b08

class Item {
  public:
    void Use(const char*, void*);
};
class Asset {
  public:
    char pad[0x3c];
    Item* item;
};
class X {
  public:
    void* v;
    Asset* a;
    int Fn(int type, void** p);
};
int X::Fn(int type, void** p) {
    Asset* q = a;
    if (!q)
        return -1;
    if (type != 1)
        return -1;
    void* v = *p;
    if (v)
        q->item->Use(((char*)&DAT_00407b08), v);
    return 0;
}