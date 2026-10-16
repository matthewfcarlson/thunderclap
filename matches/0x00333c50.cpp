#include "gen/movie.h"

class Ref_333c50 {
  public:
    virtual void Release();
    virtual void AddRef();
};

void movie::PlayerBink::vfunc_3(void* __p0, void* __p1) { Ref_333c50 * x = (Ref_333c50 *)__p0; Ref_333c50 * y = (Ref_333c50 *)__p1;

    if ((*(Ref_333c50 * *)&this->f_10) != x) {
        Ref_333c50* old = (*(Ref_333c50 * *)&this->f_10);
        (*(Ref_333c50 * *)&this->f_10) = x;
        if (x)
            x->Release();
        if (old)
            old->AddRef();
    }
    if ((*(Ref_333c50 * *)&this->f_14) != y) {
        Ref_333c50* old = (*(Ref_333c50 * *)&this->f_14);
        (*(Ref_333c50 * *)&this->f_14) = y;
        if (y)
            y->Release();
        if (old)
            old->AddRef();
    }
}
