// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamBool<CGrappleAttachTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<CGrappleAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<CGrappleAttachTrack>*)a)->*(*(bool (fight::ParamBool<CGrappleAttachTrack>::**)(int))&this->f_10))(b);
}
