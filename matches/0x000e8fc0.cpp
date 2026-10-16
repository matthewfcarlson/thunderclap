#include "gen/global.h"

class Child_e8fc0 {
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
    virtual void f13(int);
};
class FELayout_e8fc0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
};
struct VScroll_nv_e8fc0 {
    void helper(int, int);
};

void VScroll::vfunc_8(int p) {
    switch (p) {
    case 1: {
        int x = this->f_268;
        if (this->f_248 != x)
            ((VScroll_nv_e8fc0*)this)->helper(x, 1);
        break;
    }
    case 2:
        if (this->f_248 != 0)
            ((VScroll_nv_e8fc0*)this)->helper(0, 2);
        break;
    }
    if ((*(Child_e8fc0 * *)&this->f_244))
        (*(Child_e8fc0 * *)&this->f_244)->f13(p);
}
