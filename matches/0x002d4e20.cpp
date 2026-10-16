#include "gen/pure3d.h"

namespace pure3d {
class Ref_2d4e20 {
  public:
    virtual void AddRef();
    virtual void Release();
};

} // namespace pure3d
void pure3d::ParticleEmitter::vfunc_31(void* __p0) { Ref_2d4e20 * p = (Ref_2d4e20 *)__p0;

    if (p != (*(Ref_2d4e20 * *)&this->f_90)) {
        if (p)
            p->AddRef();
        if ((*(Ref_2d4e20 * *)&this->f_90))
            (*(Ref_2d4e20 * *)&this->f_90)->Release();
        (*(Ref_2d4e20 * *)&this->f_90) = p;
    }
}
