// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamVector<CGrabTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamVector<CGrabTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CGrabTrack>*)a)->*(*(bool (fight::ParamVector<CGrabTrack>::**)(int))&this->f_10))(b);
}
