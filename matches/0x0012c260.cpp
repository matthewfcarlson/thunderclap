// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ThreatDistanceCondition>::**)(int))&this->f_10))(b);
}
