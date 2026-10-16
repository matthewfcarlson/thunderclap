// Same code shape as 0x0004df70 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamEnumConstList<CSmartPropCSMableCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CSmartPropCSMableCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CSmartPropCSMableCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CSmartPropCSMableCondition>::**)(int))&this->f_18))(b);
}
