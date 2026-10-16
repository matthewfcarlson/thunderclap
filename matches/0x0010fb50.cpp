// Same code shape as 0x0004df70 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition>::**)(int))&this->f_18))(b);
}
