#include "compat/ptr.h"
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3c90[];
extern "C" void _ReadWriteBarrier();
class Obj_225c0 {
  public:
    virtual void a();
    virtual void b();
};
class Haptic {
  public:
    virtual void f0();
    virtual void f1();
    virtual Haptic* f2(unsigned char flags);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    void cleanup();
    char pad[0x18];
    Obj_225c0* mObj;
    int mHandle;
};
extern void thunk(Haptic*);
Haptic* Haptic::f2(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_003f3c90);
    _ReadWriteBarrier();
    if (mHandle)
        mHandle = 0;
    *(void**)this = (void*)((hulk_intptr)DAT_003f3390);
    _ReadWriteBarrier();
    if (mObj) {
        mObj->b();
        mObj = 0;
    }
    cleanup();
    if (flags & 1)
        thunk(this);
    return this;
}
