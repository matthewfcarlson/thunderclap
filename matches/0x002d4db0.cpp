#include "gen/pure3d.h"

class Obj_2d4db0 {
  public:
    virtual void f();
    virtual void g();
};

void pure3d::ParticleEmitter::vfunc_27(void* __p0) { Obj_2d4db0 * p = (Obj_2d4db0 *)__p0;

    if (p)
        p->f();
    if ((*(Obj_2d4db0 * *)&this->f_88))
        (*(Obj_2d4db0 * *)&this->f_88)->g();
    (*(Obj_2d4db0 * *)&this->f_88) = p;
}
