#include "gen/global.h"
#include "compat/ptr.h"

float zero_69920 = 0.0f;

hulk_freg CMoveTrack::vfunc_7() {
    hulk_freg d = this->f_10 - this->f_0c;
    if (d < zero_69920)
        d = zero_69920;
    return d;
}
