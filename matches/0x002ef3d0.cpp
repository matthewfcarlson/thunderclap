#include "gen/physics.h"

class Obj_2ef3d0 {
  public:
    virtual void Run();
    virtual void Release();
};

void physics::SimState::vfunc_13(void* __p0) { void * p = (void *)__p0;

    if ((*(Obj_2ef3d0 * *)&this->f_70))
        (*(Obj_2ef3d0 * *)&this->f_70)->Release();
    (*(Obj_2ef3d0 * *)&this->f_70) = (Obj_2ef3d0*)p;
    (*(Obj_2ef3d0 * *)&this->f_70)->Run();
}
