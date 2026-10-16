#include "gen/physics.h"

class Context_2f7c30 {
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
    virtual int Check(int, int);
};
class Param_2f7c30 {
  public:
    virtual void f0();
    char pad[12];
    int value;
    char pad2[0x4c - 0x14];
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
    virtual void Apply(int, int, int);
};

void physics::ImpulseBasedCollisionSolver::vfunc_3(void* __p0, int a, int b, int c) { Param_2f7c30 * p = (Param_2f7c30 *)__p0;

    if (p && !(this->f_34 & 1)) {
        int val = p->value;
        if ((*(Context_2f7c30 * *)&this->f_04)->Check(val, a) != 1)
            p->Apply(c, a, b);
    }
}
