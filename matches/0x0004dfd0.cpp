#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<CStageCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CStageCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CStageCondition>*)a)->*(*(bool (fight::ParamIntConstRange<CStageCondition>::**)(int))&this->f_10))(b);
}
