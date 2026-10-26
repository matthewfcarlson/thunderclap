#include "decls/data/engine/core.h"
// data: gData_274af0 = DAT_0052a1c8

struct Obj_274af0 {
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
    virtual void f14(void*, void*, void*);
};
void init(void*);
void target() {
    char a[4], b[4], c[4];
    init(((char*)&DAT_0052a1c8));
    (*(Obj_274af0**)&DAT_0052a1e4)->f14(a, b, c);
    (*(Obj_274af0**)&DAT_0052a1e4)->f1();
    (*(Obj_274af0**)&DAT_0052a1e4) = 0;
}