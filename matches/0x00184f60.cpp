#include "compat/ptr.h"
#include "gen/fight.h"
extern "C" char DAT_004197c8[];
extern "C" void _ReadWriteBarrier();
class Ref_184f60 {
  public:
    virtual void A();
    virtual void B();
};
class PropThrowAction_184f60 {
  public:
};
class BallAndChainReturnAction {
  public:
    volatile hulk_intptr vptr;
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
    ((fight::Action *)(((PropThrowAction_184f60*)this)))->FUN_002326a0();
}