// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamVector<hulkfight::ai::ThreatBallTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::ThreatBallTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::ThreatBallTrack>::**)(int))&this->f_10))(b);
}
