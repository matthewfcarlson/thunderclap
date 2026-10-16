// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::JointTrackerTrack>::**)(int))&this->f_10))(b);
}
