// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CCameraShakeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCameraShakeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCameraShakeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CCameraShakeTrack>::**)(int))&this->f_10))(b);
}
