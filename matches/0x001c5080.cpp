// FUN_001c5080 @ 0x001c5080
#include "gen/owners.h"

void owners::Blend_1c5080::FUN_001c5080(float input, float duration)
{
    float v;
    if (input >= 0.0f && input <= 1.0f)
        v = input;
    else if (input > 1.0f)
        v = 1.0f;
    else
        v = 0.0f;
    value = v;
    if (duration <= 0.0f)
        held = v;
    if (held == v) {
        rate = 0.0f;
    } else {
        float inv = 1.0f / duration;
        rate = inv;
        if (v < held)
            rate = -inv;
    }
}
