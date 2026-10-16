// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamBool<fight::PlatformCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamBool<fight::PlatformCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<fight::PlatformCondition>*)a)->*(*(bool (fight::ParamBool<fight::PlatformCondition>::**)(int))&this->f_10))(b);
}
