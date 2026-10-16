// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HitThrowTrack>::**)(int))&this->f_10))(b);
}
