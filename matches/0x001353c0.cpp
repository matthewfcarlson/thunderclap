#include "compat/ptr.h"
class Thing_1353c0 {
  public:
    virtual void A();
    virtual void B();
};
class Base_1353c0 {
  public:
    Base_1353c0();
    virtual void X();
    virtual void Y();
};
class FlyingBrakeAction : public Base_1353c0 {
  public:
    FlyingBrakeAction(void* p, Thing_1353c0* t);
    char pad[0x1c - 4];
    int mF[9];
};
FlyingBrakeAction::FlyingBrakeAction(void* p, Thing_1353c0* t) : Base_1353c0() {
    int i;
    for (i = 0; i < 9; i++)
        mF[i] = 0;
    mF[0] = (hulk_intptr)p;
    if (t)
        t->A();
    if (mF[1])
        ((Thing_1353c0*)mF[1])->B();
    mF[1] = (hulk_intptr)t;
}
