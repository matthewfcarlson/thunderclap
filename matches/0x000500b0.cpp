// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CCharacterFloatCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CCharacterFloatCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CCharacterFloatCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CCharacterFloatCondition>::**)(int))&this->f_10))(b);
}
