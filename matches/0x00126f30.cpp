// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_10))(b);
}
