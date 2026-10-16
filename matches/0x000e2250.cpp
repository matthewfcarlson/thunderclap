#include "gen/global.h"

class Item_e2250 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

void VScroll::vfunc_1() {
    for (int i = 0; i < this->f_240; ++i)
        ((Item_e2250**)((char*)this + 0x40))[i * 4]->f4();
}
