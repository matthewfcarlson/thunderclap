// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<CGrappleAttachTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<CGrappleAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<CGrappleAttachTrack>*)a)->*(*(bool (fight::ParamIntConstRange<CGrappleAttachTrack>::**)(int))&this->f_10))(b);
}
