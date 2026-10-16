#include "gen/pure3d.h"

class Ref_2b6f30 {
  public:
    virtual void f0();
    virtual void f1();
};
class Provider_2b6f30 {
  public:
    char pad[0x70];
    Ref_2b6f30* getObj();
};
struct ShadowSkinImpl_nv_2b6f30 {
    void helper(Ref_2b6f30*);
};

void pure3d::ShadowSkinImpl::vfunc_6() {
    if (!(*(Ref_2b6f30 * *)&this->f_7c)) {
        Ref_2b6f30* r = (*(Provider_2b6f30 * *)&this->f_70)->getObj();
        if (r)
            r->f0();
        if ((*(Ref_2b6f30 * *)&this->f_7c))
            (*(Ref_2b6f30 * *)&this->f_7c)->f1();
        (*(Ref_2b6f30 * *)&this->f_7c) = r;
    }
    ((ShadowSkinImpl_nv_2b6f30*)this)->helper((*(Ref_2b6f30 * *)&this->f_7c));
}
