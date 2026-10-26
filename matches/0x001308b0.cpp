// Same code shape as 0x0004dfd0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

template <> bool fight::ParamString<hulkfight::NISSoundTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::NISSoundTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::NISSoundTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::NISSoundTrack>::**)(int))&this->f_10))(b);
}
