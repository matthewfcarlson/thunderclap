// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamVector<CCameraDramaticTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamVector<CCameraDramaticTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CCameraDramaticTrack>*)a)->*(*(bool (fight::ParamVector<CCameraDramaticTrack>::**)(int))&this->f_10))(b);
}
