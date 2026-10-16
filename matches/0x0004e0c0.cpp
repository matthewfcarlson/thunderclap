// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CButtonCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CButtonCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CButtonCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CButtonCondition>::**)(int))&this->f_10))(b);
}
