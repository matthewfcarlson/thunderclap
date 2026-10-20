#include "compat/ptr.h"
extern "C" char DAT_00415c50[];
extern "C" void _ReadWriteBarrier();
class LocomotingAction {
  public:
    volatile int vptr;
    char pad[0x1c - 4];
    class Obj_161800* mObj;
    void Base();
    LocomotingAction* V2(int);
};
class Obj_161800 {
  public:
    virtual void V0();
    virtual void V1();
};
extern void thunk(LocomotingAction*);
LocomotingAction* LocomotingAction::V2(int flags) {
    vptr = ((hulk_intptr)DAT_00415c50);
    _ReadWriteBarrier();
    if (mObj) {
        mObj->V1();
        mObj = 0;
    }
    Base();
    if (flags & 1)
        thunk(this);
    return this;
}