// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<COrientTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<COrientTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<COrientTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<COrientTrack>::**)(int))&this->f_10))(b);
}
