// Same code shape as 0x00273560 (propagated; names are from that function)
#include "decls/data/engine/core.h"
// data: gObjStorage = DAT_0052a1e8

struct Obj_275d50 {
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
    virtual void* f13();
};
extern "C" void FUN_0026d850(void*);
extern "C" void FUN_0026d840(void*);
// pops an item of the core memory pool (slot 13) under the lock; the item is a pointer on every target; the callers
// pass the item's size, which the pool's item size already is
extern "C" void* FUN_00275d50(unsigned int size) {
    FUN_0026d850(((char*)&DAT_0052a1e8));
    void* r = (*(Obj_275d50**)&DAT_0052a204)->f13();
    FUN_0026d840(((char*)&DAT_0052a1e8));
    return r;
}