// Same code shape as 0x0005e4b0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

class ParamValue_63300 {
  public:
    char pad[12];
};
class ParamValueBool_63300 : public ParamValue_63300 {};
class CCollisionTrack_63300;

template <> bool fight::ParamBoolPtr<CWeaponCollisionTrack>::vfunc_6(hulk_intptr __p0, int __p1) { unsigned char * p = (unsigned char *)__p0; unsigned char v = (unsigned char)__p1;

    p[this->f_10] = v;
    return true;
}
