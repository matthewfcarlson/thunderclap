// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<CGrabTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrabTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrabTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CGrabTrack>::**)(int))&this->f_10))(b);
}
