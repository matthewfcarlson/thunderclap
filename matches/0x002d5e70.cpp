#include "gen/pure3d.h"

class Obj_2d5e70 {
  public:
    virtual void a();
    virtual void b();
};

void pure3d::SpriteParticleEmitter::vfunc_25(void* __p0) { Obj_2d5e70 * p = (Obj_2d5e70 *)__p0;

    if (p != (*(Obj_2d5e70 * *)&this->f_84)) {
        vfunc_15();
        if (p != (*(Obj_2d5e70 * *)&this->f_84)) {
            if (p)
                p->a();
            if ((*(Obj_2d5e70 * *)&this->f_84))
                (*(Obj_2d5e70 * *)&this->f_84)->b();
            (*(Obj_2d5e70 * *)&this->f_84) = p;
        }
    }
}
