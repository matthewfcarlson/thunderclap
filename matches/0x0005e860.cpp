// Same code shape as 0x0004df70 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamEnumConstList<CStunAnimationTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<CStunAnimationTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<CStunAnimationTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<CStunAnimationTrack>::**)(int))&this->f_18))(b);
}
