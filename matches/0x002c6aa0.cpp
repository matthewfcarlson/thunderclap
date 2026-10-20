#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042ef74[];
extern "C" void _ReadWriteBarrier();
class IRefCount {
  public:
    virtual void A();
    virtual void Release();
};
class DisplayTraversal {
  public:
    volatile int* vptr;
    char pad[16];
    IRefCount* mRef;
    void Fn();
};
void DisplayTraversal::Fn() {
    vptr = (volatile int*)((hulk_intptr)DAT_0042ef74);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    vptr = (volatile int*)((hulk_intptr)DAT_003f6098);
}