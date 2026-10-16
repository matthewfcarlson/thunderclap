// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamString<hulkfight::ai::FormationReadyCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::FormationReadyCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::FormationReadyCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::FormationReadyCondition>::**)(int))&this->f_10))(b);
}
