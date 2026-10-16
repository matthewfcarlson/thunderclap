#include "gen/pure3d.h"

class Obj_2d4d70 {
  public:
    virtual void Release();
    virtual void AddRef();
};

void pure3d::ParticleEmitter::vfunc_25(void* __p0) { Obj_2d4d70 * param = (Obj_2d4d70 *)__p0;

    if (param != (*(Obj_2d4d70 * *)&this->f_84)) {
        if (param)
            param->Release();
        if ((*(Obj_2d4d70 * *)&this->f_84))
            (*(Obj_2d4d70 * *)&this->f_84)->AddRef();
        (*(Obj_2d4d70 * *)&this->f_84) = param;
    }
}
