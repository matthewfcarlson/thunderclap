#include "gen/global.h"

class Base_e18d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
class FEDoAction_e18d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Inner_e18d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};

void FEDoParticleSystem::vfunc_5() {
    (*(Inner_e18d0 * *)&this->f_34)->d();
}
