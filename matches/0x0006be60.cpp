// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloat<CScrubberTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloat<CScrubberTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloat<CScrubberTrack>*)a)->*(*(bool (fight::ParamFloat<CScrubberTrack>::**)(int))&this->f_10))(b);
}
