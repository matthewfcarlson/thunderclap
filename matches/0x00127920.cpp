// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::AcquireTargetTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::AcquireTargetTrack>::**)(int))&this->f_10))(b);
}
