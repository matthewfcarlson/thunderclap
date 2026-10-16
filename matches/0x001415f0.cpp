// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::WallVelocityCondition>::**)(int))&this->f_10))(b);
}
