// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamString<hulkfight::ai::PathTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::PathTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::PathTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::PathTrack>::**)(int))&this->f_10))(b);
}
