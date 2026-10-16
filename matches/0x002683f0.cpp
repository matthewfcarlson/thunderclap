#include "gen/core.h"

int helper();
class Pad_2683f0 {
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
    virtual void f18(int);
};

void core::ControllerSystemXBox::vfunc_7(int a, int b) {
    this->f_14 = b - a;
    char* p = (*(char (*)[4736])&this->f_20);
    int i = 4;
    do {
        if (p[0x49e]) {
            Pad_2683f0* q = (Pad_2683f0*)p;
            q->f18(helper() + this->f_14);
        }
        p += 0x4a0;
        --i;
    } while (i);
}
