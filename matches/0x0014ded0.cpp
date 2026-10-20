#include "compat/ptr.h"
struct Base_14ded0 {
    Base_14ded0();
    virtual void vfn();
};

class Derived_14ded0 : public Base_14ded0 {
  public:
    char pad[8];
    int m0c;
    int m10;
    Derived_14ded0();
};

extern "C" void _ReadWriteBarrier();

extern int vftable[];

Derived_14ded0::Derived_14ded0() {
    m0c = 0;
    m10 = 0;
    *(hulk_intptr*)this = (hulk_intptr)vftable;
}
