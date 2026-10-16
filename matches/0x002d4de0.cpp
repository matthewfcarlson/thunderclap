#include "gen/pure3d.h"

namespace pure3d {
struct Ref_2d4de0 {
    virtual void Release();
    virtual void AddRef();
};

} // namespace pure3d
void pure3d::ParticleEmitter::vfunc_29(void* __p0) { Ref_2d4de0 * p = (Ref_2d4de0 *)__p0;

    if (p != (*(Ref_2d4de0 * *)&this->f_8c)) {
        if (p)
            p->Release();
        if ((*(Ref_2d4de0 * *)&this->f_8c))
            (*(Ref_2d4de0 * *)&this->f_8c)->AddRef();
        (*(Ref_2d4de0 * *)&this->f_8c) = p;
    }
}
