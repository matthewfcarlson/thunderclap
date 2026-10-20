#include "compat/ptr.h"
#include "gen/global.h"

class FELayout_e27b0 {
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
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
};
class FEControl_e27b0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void o();
};
extern char typeA_e27b0;
extern char typeB_e27b0;
void* cast(void*, int, void*, void*, int);

void VScroll::vfunc_11() {
    int i = 0;
    if (this->f_240 > 0) {
        char* p = (char*)this + 0x40;
        do {
            int* q = (int*)cast((void*)*(hulk_intptr*)p, 0, &typeB_e27b0, &typeA_e27b0, 0);
            if (q)
                ((FEControl_e27b0*)q)->o();
            ++i;
            p += 0x10;
        } while (i < this->f_240);
    }
}
