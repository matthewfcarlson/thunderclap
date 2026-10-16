#include "gen/pure3d.h"

class Obj_2830e0 {
  public:
    virtual void f();
    virtual void g();
};

void pure3d::prop::CMotionTrail::vfunc_8(void* __p0) { Obj_2830e0 * p = (Obj_2830e0 *)__p0;

    if (p)
        p->f();
    if ((*(Obj_2830e0 * *)&this->f_40))
        (*(Obj_2830e0 * *)&this->f_40)->g();
    (*(Obj_2830e0 * *)&this->f_40) = p;
}
