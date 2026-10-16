// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::SmartPropIsCargoCondition>::**)(int))&this->f_10))(b);
}
