// Same code shape as 0x00069920 (propagated; names are from that function)
#include "gen/global.h"
#include "compat/ptr.h"

float zero_69ae0 = 0.0f;

hulk_freg CMoveAddYTrack::vfunc_7() {
    hulk_freg d = this->timeEnd - this->timeBegin;
    if (d < zero_69ae0)
        d = zero_69ae0;
    return d;
}
