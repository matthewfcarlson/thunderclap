// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CEffectStopTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CEffectStopTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CEffectStopTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CEffectStopTrack>::**)(int))&this->f_10))(b);
}
