#include "gen/pure3d.h"

class Obj_2d5e00 {
  public:
    virtual void a();
    virtual void b();
    char pad[0x14];
    int kind;
};

void pure3d::SpriteParticleEmitter::vfunc_8(void* __p0) { Obj_2d5e00 * p = (Obj_2d5e00 *)__p0;

    if (p)
        p->a();
    if ((*(Obj_2d5e00 * *)&this->f_a8))
        (*(Obj_2d5e00 * *)&this->f_a8)->b();
    (*(Obj_2d5e00 * *)&this->f_a8) = p;
    if (p && (p->kind == 1 || p->kind == 3 || p->kind == 7 || p->kind == 2 || p->kind == 4 || p->kind == 5 ||
              p->kind == 6))
        this->f_10 = 1;
    else
        this->f_10 = 0;
}
