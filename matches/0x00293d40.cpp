#include "decls/data/engine/global.h"

typedef unsigned int U_293d40;
struct Obj_293d40 {
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
    virtual void f15();
    virtual void f16();
    virtual void f17(int, void*);
};
struct Holder_293d40 {
    Obj_293d40* p;
};
struct Sub_293d40 {
    void init();
};
struct C_293d40 {
    Holder_293d40 h;
    void run(U_293d40, U_293d40, U_293d40);
};
void C_293d40::run(U_293d40 a, U_293d40 b, U_293d40 c) {
    (*(U_293d40*)&DAT_0052c2c8) = a;
    (*(U_293d40*)&DAT_0052c2cc) = b;
    (*(U_293d40*)&DAT_0052c2d0) = c;
    (*(Sub_293d40*)&DAT_0052c2d8).init();
    (*(U_293d40*)&DAT_0052c308) = (*(U_293d40*)&DAT_0052c2c8);
    (*(U_293d40*)&DAT_0052c30c) = (*(U_293d40*)&DAT_0052c2cc);
    (*(U_293d40*)&DAT_0052c310) = (*(U_293d40*)&DAT_0052c2d0);
    h.p->f17(0, (void*)&(*(Sub_293d40*)&DAT_0052c2d8));
}
