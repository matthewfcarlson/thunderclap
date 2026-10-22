#include "compat/ptr.h"
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3c90[];
extern "C" void _ReadWriteBarrier();
struct Ref_20a90 {
    virtual void f0();
    virtual void Release();
};
struct CHapticEventAction_20a90;
void __fastcall BaseDtor(CHapticEventAction_20a90* p);
struct CHapticEventAction_20a90 {
    virtual void a0();
    virtual void a1();
    char pad[0x18];
    Ref_20a90* mRef;
    int mUnknown;
    void Dtor();
};
void CHapticEventAction_20a90::a0() {}
void CHapticEventAction_20a90::a1() {}
void CHapticEventAction_20a90::Dtor() {
    *(void**)this = (void*)((hulk_intptr)DAT_003f3c90);
    _ReadWriteBarrier();
    if (mUnknown)
        mUnknown = 0;
    *(void**)this = (void*)((hulk_intptr)DAT_003f3390);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    BaseDtor(this);
}
