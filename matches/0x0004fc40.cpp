// Same code shape as 0x0004df70 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamEnumConstList<CMotionHitCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CMotionHitCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CMotionHitCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CMotionHitCondition>::**)(int))&this->f_18))(b);
}
