// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamString<CSmartPropSpawnTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamString<CSmartPropSpawnTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CSmartPropSpawnTrack>*)a)->*(*(bool (fight::ParamString<CSmartPropSpawnTrack>::**)(int))&this->f_10))(b);
}
