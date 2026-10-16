// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamString<CCollisionTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamString<CCollisionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<CCollisionTrack>*)a)->*(*(bool (fight::ParamString<CCollisionTrack>::**)(int))&this->f_10))(b);
}
