// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0003ec00 @ 0x0003ec00
#include "gen/owners.h"

float owners::Progress_3ec00::FUN_0003ec00(int k)
{
    float v = value;
    if (k != key) {
        value = 0.0f;
        return 0.0f;
    }
    if (v >= 0.0f && v <= 1.0f) {
        value = 0.0f;
        return v;
    }
    value = 0.0f;
    if (v > 1.0f)
        return 1.0f;
    return 0.0f;
}
