#include "decls/data/engine/core.h"
// data: gObjStorage = DAT_0052a1c8

typedef unsigned int u32_273560;
struct Obj_273560 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
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
    virtual u32_273560 f13();
};
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
u32_273560 target() {
    FUN_0026d850(((char*)&DAT_0052a1c8));
    u32_273560 r = (*(Obj_273560**)&DAT_0052a1e4)->f13();
    FUN_0026d840(((char*)&DAT_0052a1c8));
    return r;
}