// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1840..0x000e1920 (kind game, layer game, confidence high), dominant class FEDoParticleSystem
// (tree_prelude.h: not needed)


// 0x000e18d0 FEDoParticleSystem::vfunc_5 (8 B): matches/0x000e18d0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?vfunc_5@FEDoParticleSystem@@UAEXXZ
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

