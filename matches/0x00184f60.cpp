#include "compat/ptr.h"
extern "C" char DAT_004197c8[];
extern "C" void _ReadWriteBarrier();
class Ref_184f60 {
  public:
    virtual void A();
    virtual void B();
};
class Base_184f60 {
  public:
    void Finish();
};
class BallAndChainReturnAction {
  public:
    volatile int vptr;
    char pad[0x18];
    void* mOne;
    Ref_184f60* mTwo;
    void Reset();
};
void BallAndChainReturnAction::Reset() {
    vptr = ((hulk_intptr)DAT_004197c8);
    _ReadWriteBarrier();
    if (mTwo) {
        mTwo->B();
        mTwo = 0;
    }
    if (mOne)
        mOne = 0;
    ((Base_184f60*)this)->Finish();
}