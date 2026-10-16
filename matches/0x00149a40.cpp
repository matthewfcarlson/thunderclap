// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "gen/fight.h"

template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::vfunc_6(int a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleExecuteTrack>::**)(int))&this->f_10))(b);
}
