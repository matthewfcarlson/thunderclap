// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CComboMessageTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CComboMessageTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CComboMessageTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CComboMessageTrack>::**)(int))&this->f_10))(b);
}
