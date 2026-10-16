#include "gen/pure3d.h"

struct Ref_2dfd70 {
    virtual void AddRef();
    virtual void Release();
    int pad[5];
    int kind;
};

void pure3d::PrimGroup::vfunc_8(void* __p0) { Ref_2dfd70 * r = (Ref_2dfd70 *)__p0;

    if (r)
        r->AddRef();
    if ((*(Ref_2dfd70 * *)&this->f_40))
        (*(Ref_2dfd70 * *)&this->f_40)->Release();
    (*(Ref_2dfd70 * *)&this->f_40) = r;
    if (r && (r->kind == 1 || r->kind == 3 || r->kind == 7 || r->kind == 2 || r->kind == 4 || r->kind == 5 ||
              r->kind == 6)) {
        this->f_10 = 1;
        return;
    }
    this->f_10 = 0;
}
