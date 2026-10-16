// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamBool<hulkfight::motion::RayCastConeCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::RayCastConeCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::RayCastConeCondition>::**)(int))&this->f_10))(b);
}
