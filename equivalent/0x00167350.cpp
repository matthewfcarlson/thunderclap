// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 12/12)
// hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_6 @ 0x00167350
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

class TargetLocomotionMotionStateCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void* a1, Target_167350* target, void* a3);

    char pad04[8];
    int mode;             // 0x0c
    int expected;         // 0x10
};

}
}

bool hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_6(void* a1, Target_167350* target, void* a3)
{
    Locomotion_167350* loco = target->FUN_000592a0()->FUN_00059a30()->locomotion;
    if (loco == 0 || loco->state == 0 || loco->kind != 1)
        return false;
    int want = expected;
    switch (mode) {
    case 0:
        return loco->state->FUN_00035910() == want;
    case 1:
        return loco->state->FUN_00035910() != want;
    }
    return false;
}
