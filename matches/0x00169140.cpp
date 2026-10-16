// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::RayCastTargetCondition>::**)(int))&this->f_10))(b);
}
