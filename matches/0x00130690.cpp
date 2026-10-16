// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamStringConstList<hulkfight::LocationCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamStringConstList<hulkfight::LocationCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamStringConstList<hulkfight::LocationCondition>*)a)->*(*(bool (fight::ParamStringConstList<hulkfight::LocationCondition>::**)(int))&this->f_10))(b);
}
