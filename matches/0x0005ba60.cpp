// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamVector<CGrappleAttachTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamVector<CGrappleAttachTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<CGrappleAttachTrack>*)a)->*(*(bool (fight::ParamVector<CGrappleAttachTrack>::**)(int))&this->f_10))(b);
}
