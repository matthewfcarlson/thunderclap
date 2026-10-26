// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamBool<CSnapToWallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CSnapToWallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CSnapToWallTrack>*)a)->*(*(bool (fight::ParamBool<CSnapToWallTrack>::**)(int))&this->f_10))(b);
}
