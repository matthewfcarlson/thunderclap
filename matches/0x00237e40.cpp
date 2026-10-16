// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<fight::SequenceTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<fight::SequenceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<fight::SequenceTrack>*)a)->*(*(bool (fight::ParamIntConstRange<fight::SequenceTrack>::**)(int))&this->f_10))(b);
}
