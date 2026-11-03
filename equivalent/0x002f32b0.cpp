// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f32b0 @ 0x002f32b0
// FUN_002f32b0 @ 0x002f32b0: snaps a direction vector to the dominant axis when one component is near +-1
#include "gen/owners.h"
union FloatBits_2f32b0 {
    float f;
    unsigned int u;
};


void owners::Axis_2f32b0::FUN_002f32b0()
{
    FloatBits_2f32b0 a;
    a.f = x;
    a.u &= 0x7fffffff;
    dominant = 0;
    if (a.f > 0.9999f) {
        dominant = 2;
        x = 1.0f;
        z = 0.0f;
        y = 0.0f;
        return;
    }
    FloatBits_2f32b0 b;
    b.f = y;
    b.u &= 0x7fffffff;
    if (b.f > 0.9999f) {
        dominant = 3;
        x = 0.0f;
        y = 1.0f;
        z = 0.0f;
        return;
    }
    FloatBits_2f32b0 c;
    c.f = z;
    c.u &= 0x7fffffff;
    if (c.f > 0.9999f) {
        dominant = 4;
        x = 0.0f;
        z = 1.0f;
        y = 0.0f;
    }
}
