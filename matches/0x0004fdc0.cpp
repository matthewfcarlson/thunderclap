// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamBool<CRageModeCondition>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamBool<CRageModeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CRageModeCondition>*)a)->*(*(bool (fight::ParamBool<CRageModeCondition>::**)(int))&this->f_10))(b);
}
