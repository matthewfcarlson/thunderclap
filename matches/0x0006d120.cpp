// Same code shape as 0x0004df70 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamEnumConstList<CAlertStatusTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CAlertStatusTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CAlertStatusTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CAlertStatusTrack>::**)(int))&this->f_18))(b);
}
