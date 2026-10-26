// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamBool<CCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CCollisionTrack>*)a)->*(*(bool (fight::ParamBool<CCollisionTrack>::**)(int))&this->f_10))(b);
}
