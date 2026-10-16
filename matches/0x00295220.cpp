#include "gen/pure3d.h"

class Obj_295220 {
  public:
    virtual void First();
    virtual void Release();
};

void pure3d::TextureFont::vfunc_17(void* __p0) { Obj_295220 * p = (Obj_295220 *)__p0;

    if (p)
        p->First();
    if ((*(Obj_295220 * *)&this->f_28))
        (*(Obj_295220 * *)&this->f_28)->Release();
    (*(Obj_295220 * *)&this->f_28) = p;
}
