// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CEffectTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CEffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CEffectTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CEffectTrack>::**)(int))&this->f_10))(b);
}
