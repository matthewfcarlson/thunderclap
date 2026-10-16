// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamVector<hulkfight::ai::MotionTargetTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::MotionTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::MotionTargetTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::MotionTargetTrack>::**)(int))&this->f_10))(b);
}
