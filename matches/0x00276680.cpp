// Same code shape as 0x00273560 (propagated; names are from that function)
#include "decls/data/engine/core.h"
// data: gObjStorage = DAT_0052a208

typedef unsigned int u32_276680;
struct Obj_276680 {
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
    virtual u32_276680 f13();
};
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
u32_276680 target() {
    FUN_0026d850(((char*)&DAT_0052a208));
    u32_276680 r = (*(Obj_276680**)&DAT_0052a224)->f13();
    FUN_0026d840(((char*)&DAT_0052a208));
    return r;
}