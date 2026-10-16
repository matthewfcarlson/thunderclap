#include "gen/global.h"

extern "C" char DAT_0049dba4[];
extern "C" char DAT_0049f4f0[];
class FEObject_e2760 {
  public:
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
};
class FELayout_e2760 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
extern FEObject_e2760* castFE(void*, int, int, int, int);

void VScroll::vfunc_12() {
    for (int i = 0; i < this->f_240; ++i) {
        FEObject_e2760* p = castFE(*(void**)((char*)this + 0x40 + i * 16), 0, ((int)DAT_0049dba4), ((int)DAT_0049f4f0), 0);
        if (p)
            p->f16();
    }
}
