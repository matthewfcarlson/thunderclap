// Same code shape as 0x00069920 (propagated; names are from that function)
#include "gen/global.h"

float zero_69a00 = 0.0f;

float CMoveAddTrack::vfunc_7() {
    float d = this->f_10 - this->f_0c;
    if (d < zero_69a00)
        d = zero_69a00;
    return d;
}
