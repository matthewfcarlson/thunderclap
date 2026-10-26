// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamString<CWeaponCollisionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<CWeaponCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CWeaponCollisionTrack>*)a)->*(*(bool (fight::ParamString<CWeaponCollisionTrack>::**)(int))&this->f_10))(b);
}
