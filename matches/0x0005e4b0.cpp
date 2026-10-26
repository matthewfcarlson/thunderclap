#include "compat/ptr.h"
#include "gen/fight.h"

class ParamValue_5e4b0 {
  public:
    char pad[12];
};
class ParamValueBool_5e4b0 : public ParamValue_5e4b0 {};
class CCollisionTrack_5e4b0;

template <> bool fight::ParamBoolPtr<CCollisionTrack>::vfunc_6(hulk_intptr __p0, int __p1) { unsigned char * p = (unsigned char *)__p0; unsigned char v = (unsigned char)__p1;

    p[this->f_10] = v;
    return true;
}
