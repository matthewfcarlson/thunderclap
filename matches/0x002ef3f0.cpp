#include "gen/physics.h"

class Obj_2ef3f0 {
  public:
    virtual void f();
};
class Old_2ef3f0 {
  public:
    void cleanup();
};

void physics::SimState::vfunc_14(void* __p0) { Obj_2ef3f0 * p = (Obj_2ef3f0 *)__p0;

    if (p)
        p->f();
    if ((*(Obj_2ef3f0 * *)&this->f_74))
        ((Old_2ef3f0*)(*(Obj_2ef3f0 * *)&this->f_74))->cleanup();
    (*(Obj_2ef3f0 * *)&this->f_74) = p;
}
