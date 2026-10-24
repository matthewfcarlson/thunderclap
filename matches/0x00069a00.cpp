// Same code shape as 0x00069920 (propagated; names are from that function)
#include "gen/global.h"
#include "compat/ptr.h"

float zero_69a00 = 0.0f;

hulk_freg CMoveAddTrack::vfunc_7() {
    hulk_freg d = this->f_10 - this->f_0c;
    if (d < zero_69a00)
        d = zero_69a00;
    return d;
}
