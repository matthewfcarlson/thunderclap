#include "gen/global.h"

#include "compat/ptr.h"
extern "C" char DAT_0040c3d0[];
class Ref_e89e0 {
  public:
    virtual void f();
    virtual void g();
};
class FEPoseAnimation_e89e0 {
  public:
    void Done();
};

void FEParticleAnimation::FUN_000e89e0() {
    *(int* volatile*)this = (int*)((hulk_intptr)DAT_0040c3d0);
    Ref_e89e0* r = (*(Ref_e89e0 *volatile *)&this->f_64);
    if (r) {
        r->g();
        (*(Ref_e89e0 *volatile *)&this->f_64) = 0;
    }
    ((FEPoseAnimation_e89e0*)this)->Done();
}
