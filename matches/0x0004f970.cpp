// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CLuaNumberCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CLuaNumberCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CLuaNumberCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<CLuaNumberCondition>::**)(int))&this->f_10))(b);
}
