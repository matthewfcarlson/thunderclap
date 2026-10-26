// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamBool<CGrappleTimerCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CGrappleTimerCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CGrappleTimerCondition>*)a)->*(*(bool (fight::ParamBool<CGrappleTimerCondition>::**)(int))&this->f_10))(b);
}
