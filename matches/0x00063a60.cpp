// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<CSmartPropDropTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CSmartPropDropTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CSmartPropDropTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CSmartPropDropTrack>::**)(int))&this->f_10))(b);
}
