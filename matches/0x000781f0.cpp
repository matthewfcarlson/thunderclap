// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<CExplosionTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<CExplosionTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<CExplosionTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<CExplosionTrack>::**)(int))&this->f_10))(b);
}
