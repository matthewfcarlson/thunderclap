#include "decls/data/engine/pure3d/prop.h"
// data: gHolder_27f2a0 = DAT_0052c2ac

#include "compat/ptr.h"
struct Worker_27f2a0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void Run(int, int);
};
struct Manager_27f2a0 {
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
    virtual void f13();
    virtual void f14();
    virtual void Do0(int);
    virtual void Do2(int);
    virtual void Do1(int, int);
};
struct Holder_27f2a0 {
    Manager_27f2a0* mgr;
};
struct Obj_27f2a0 {
    char pad0[0x20];
    int field20;
    char pad24[0x3c];
    Manager_27f2a0* field60;
    void* field64;
    char pad68[8];
    unsigned field70;
    void target(int, int);
};
void Obj_27f2a0::target(int a, int b) {
    char* p = (char*)this + 0x70;
    for (int i = 100; i != 0; --i, p += 0x60) {
        Worker_27f2a0* w = *(Worker_27f2a0**)(p - 16);
        if (w) {
            (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do0(0);
            unsigned n = *(unsigned*)p;
            if (n != 0xffff)
                (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do1(0, n * 64 + *(unsigned*)((*(char**)(p - 12)) + 0x1c));
            (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do1(0, (hulk_intptr)(p - 0x50));
            w->Run(a, b);
            (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do2(0);
        }
    }
}