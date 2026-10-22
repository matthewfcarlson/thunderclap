// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 17/18, incomplete)
// FUN_000c8f50 @ 0x000c8f50
#include "compat/ptr.h"
class Obj {
public:
    void run(float target);
    char p0[0x210];
    float f210;
    char p1[4];
    float f218;
    char p2[0x224 - 0x21c];
    char c224;
    char p3[0x2959 - 0x225];
    char c2959;
};

void Obj::run(float target)
{
    hulk_freg d = target - f218;
    hulk_freg s;
    if (d < 0.0f)
        s = -1.0f;
    else if (d > 0.0f)
        s = 1.0f;
    else
        s = 0.0f;

    hulk_freg v = f218 * f218 * 0.0125f;
    hulk_freg c;
    if (!(v >= 0.0f))
        c = 0.0f;
    else if (v > 0.02f)
        c = 0.02f;
    else
        c = v;

    hulk_freg pos = c * s + f218; // the stored f218 is rounded; the uses below take the register
    f218 = pos;
    f210 = 0.12f * pos;
    float a = pos - 0.6f;
    if (a < 0.0f) a = -a;
    if (a <= 0.02f && s == -1.0f) {
        c224 = 1;
        c2959 = 0;
        return;
    }
    float b = pos - 1.25f;
    if (b < 0.0f) b = -b;
    if (b <= 0.02f && s == 1.0f) {
        c224 = 1;
        c2959 = 0;
    }
}
