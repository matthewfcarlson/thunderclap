#include "compat/ptr.h"
extern "C" char DAT_00415b00[];
extern "C" void _ReadWriteBarrier();
class Base_15f680 {
  public:
    virtual void f0();
    virtual void f1();
};
class HeliLocomotionAction_15f680 {
  public:
    virtual void slot0();
    void tail();
    char pad[0x1c];
    Base_15f680* p20;
    Base_15f680* p24;
};
void HeliLocomotionAction_15f680::slot0() {
    *(void**)this = (void*)((hulk_intptr)DAT_00415b00);
    _ReadWriteBarrier();
    if (p24) {
        p24->f1();
        p24 = 0;
    }
    p20->f1();
    tail();
}
