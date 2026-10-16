// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CMotionHitGroundHeightTrack>::**)(int))&this->f_10))(b);
}
