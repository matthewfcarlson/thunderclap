// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamString<hulkfight::DebugPrintCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::DebugPrintCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::DebugPrintCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::DebugPrintCondition>::**)(int))&this->f_10))(b);
}
