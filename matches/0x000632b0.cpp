// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamVector<CWeaponCollisionTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamVector<CWeaponCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CWeaponCollisionTrack>*)a)->*(*(bool (fight::ParamVector<CWeaponCollisionTrack>::**)(int))&this->f_10))(b);
}
