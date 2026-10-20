#include "compat/ptr.h"
extern "C" char DAT_00427534[];
class Base_22aa20 {
  public:
    void Fn();
};
class LocomotionDriver {
  public:
    virtual void f0();
    virtual void f1();
    virtual LocomotionDriver* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
};
extern int g_count_22aa20;
extern void __cdecl thunk_FUN_00267090(LocomotionDriver*);
LocomotionDriver* LocomotionDriver::vfunc_2(int flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_00427534);
    g_count_22aa20--;
    ((Base_22aa20*)this)->Fn();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}