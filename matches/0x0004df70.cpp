#include "gen/fight.h"

template <> bool fight::ParamEnumConstList<CStageCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CStageCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CStageCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<CStageCondition>::**)(int))&this->f_18))(b);
}
