// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamBool<CJumpTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CJumpTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CJumpTrack>*)a)->*(*(bool (fight::ParamBool<CJumpTrack>::**)(int))&this->f_10))(b);
}
