// Same code shape as 0x00293c80 (propagated; names are from that function)
#include "compat/ptr.h"
struct V {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17(int, int);
};
struct G_293cc0 {
    void a();
    void b(int, int, int);
};
struct T_293cc0 {
    V* p;
    void f(int, int, int);
};
extern G_293cc0 glob_293cc0;
void T_293cc0::f(int a, int b, int c) {
    glob_293cc0.a();
    glob_293cc0.b(a, b, c);
    p->x17(0, (hulk_intptr)&glob_293cc0);
}