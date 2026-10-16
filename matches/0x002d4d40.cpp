#include "gen/pure3d.h"

namespace pure3d {
struct Obj_2d4d40 {
    virtual void f0();
    virtual void f1();
};

} // namespace pure3d
void pure3d::ParticleEmitter::vfunc_23(void* __p0) { void * p = (void *)__p0;

    if (p)
        ((Obj_2d4d40*)p)->f0();
    if ((*(Obj_2d4d40 * *)&this->f_80))
        (*(Obj_2d4d40 * *)&this->f_80)->f1();
    (*(Obj_2d4d40 * *)&this->f_80) = (Obj_2d4d40*)p;
}
