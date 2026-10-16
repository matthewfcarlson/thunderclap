// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::AnimationChargeAction::vfunc_5 @ 0x0013b220
#include "gen/hulkfight.h"

struct Mixer_13b220 {
    char pad0[0x1e58];
    float blend;            // 0x1e58
};

struct Context_13b220 {
    Mixer_13b220* FUN_00059a30();
};

struct Manager_13b220 {
    Context_13b220* FUN_000592a0();
};

struct Dial {
    char pad0[0x22c];
    float from;             // 0x22c
    float to;               // 0x230
    void FUN_00225cf0(float value);
};

namespace hulkfight {
namespace motion {
}
}
bool hulkfight::motion::AnimationChargeAction::vfunc_5(int skip, int unused) {
    if (skip == 0) {
        float t = (*(Manager_13b220 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30()->blend;
        if (t >= 0.0f && t <= 1.0f) {
        } else if (t > 1.0f) {
            t = 1.0f;
        } else {
            t = 0.0f;
        }
        (*(Dial * *)&this->f_24)->FUN_00225cf0(((*(Dial * *)&this->f_24)->to - (*(Dial * *)&this->f_24)->from) * t + (*(Dial * *)&this->f_24)->from);
    }
    return true;
}
