#include "decls/data/game/global.h"
// data: zero_222a00 = DAT_003f32e0

class EntryOwner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int f13();
};
struct Item_222a00 {
    char pad[4];
    float value;
    unsigned char enabled;
};
class Container_222a00 {
  public:
    char pad[0x68];
    unsigned count;
    Item_222a00 entries[1];
    unsigned char Check(EntryOwner* item);
};
unsigned char Container_222a00::Check(EntryOwner* item) {
    unsigned i = 0;
    while (i < count) {
        Item_222a00* e = (Item_222a00*)((char*)this + 0x6c + i * 0x28);
        if (*(EntryOwner**)e == item) {
            if (!(e->value < DAT_003f32e0) || e->enabled)
                return (unsigned char)item->f13();
            break;
        }
        ++i;
    }
    return 1;
}
