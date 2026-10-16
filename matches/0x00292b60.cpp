#include "gen/pure3d.h"

class Manager_292b60 {
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
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28(int, int, int, int);
};
extern Manager_292b60* gManager_292b60;

void pure3d::Camera::vfunc_22() {
    vfunc_5((*(int *)&this->f_10), (*(int *)&this->f_14));
    if (!this->f_cc)
        vfunc_26();
    gManager_292b60->f28((*(int *)&this->f_1c), (*(int *)&this->f_20), (*(int *)&this->f_10), this->f_18);
}
