// Same code shape as 0x001353c0 (propagated; names are from that function)
#include "compat/ptr.h"
class Thing_151f20 {
  public:
    virtual void A();
    virtual void B();
};
class Base_151f20 {
  public:
    Base_151f20();
    virtual void X();
    virtual void Y();
};
class HitThrowAction_151f20 : public Base_151f20 {
  public:
    HitThrowAction_151f20(void* p, Thing_151f20* t);
    char pad[0x1c - 4];
    int mF[9];
};
HitThrowAction_151f20::HitThrowAction_151f20(void* p, Thing_151f20* t) : Base_151f20() {
    int i;
    for (i = 0; i < 9; i++)
        mF[i] = 0;
    mF[0] = (hulk_intptr)p;
    if (t)
        t->A();
    if (mF[1])
        ((Thing_151f20*)mF[1])->B();
    mF[1] = (hulk_intptr)t;
}
