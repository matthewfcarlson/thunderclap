// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamIntConstRange<fight::OpportunityTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<fight::OpportunityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<fight::OpportunityTrack>*)a)->*(*(bool (fight::ParamIntConstRange<fight::OpportunityTrack>::**)(int))&this->f_10))(b);
}
