#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0042e764[];

struct Alloc_2b9660 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    void init(pure3d::BillboardObject*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::BillboardObject::vfunc_4() {
    Alloc_2b9660* p = (Alloc_2b9660*)thunk_FUN_0008d690(0x60);
    if (p) {
        p->init(this);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_0042e764);
        *(unsigned long*)((char*)p + 0x58) = 0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}
