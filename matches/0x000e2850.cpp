#include "compat/ptr.h"
class Outer_e2850;
class Inner_e2850 {
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
    virtual float f17(Outer_e2850*);
};
class Outer_e2850 {
  public:
    char pad[0x14];
    Inner_e2850* p;
    hulk_freg call();
};
hulk_freg Outer_e2850::call() {
    return p->f17(this);
}