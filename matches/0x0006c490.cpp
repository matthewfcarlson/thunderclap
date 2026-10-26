// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CMoveAddTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CMoveAddTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CMoveAddTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CMoveAddTrack>::**)(int))&this->f_10))(b);
}
