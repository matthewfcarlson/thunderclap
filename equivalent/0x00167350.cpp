// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 12/12)
// hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_6 @ 0x00167350
#include "gen/hulkfight.h"

struct MotionState_167350 {
    int FUN_00035910();
};

struct Locomotion_167350 {
    char pad00[8];
    MotionState_167350* state;   // 0x08
    int kind;             // 0x0c
};

struct Fighter_167350 {
    char pad00[0x328];
    Locomotion_167350* locomotion;   // 0x328
};

struct Body_167350 {
    Fighter_167350* FUN_00059a30();
};

class Target_167350 {
public:
    Body_167350* FUN_000592a0();
};

namespace hulkfight {
namespace motion {

}
}
bool hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * a1 = (void *)__p0; Target_167350 * target = (Target_167350 *)__p1; void * a3 = (void *)__p2;

    Locomotion_167350* loco = target->FUN_000592a0()->FUN_00059a30()->locomotion;
    if (loco == 0 || loco->state == 0 || loco->kind != 1)
        return false;
    int want = this->f_10;
    switch (this->f_0c) {
    case 0:
        return loco->state->FUN_00035910() == want;
    case 1:
        return loco->state->FUN_00035910() != want;
    }
    return false;
}
