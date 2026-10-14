// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::AnimationChargeAction::vfunc_5 @ 0x0013b220
struct Mixer {
    char pad0[0x1e58];
    float blend;            // 0x1e58
};

struct Context {
    Mixer* FUN_00059a30();
};

struct Manager {
    Context* FUN_000592a0();
};

struct Dial {
    char pad0[0x22c];
    float from;             // 0x22c
    float to;               // 0x230
    void FUN_00225cf0(float value);
};

namespace hulkfight {
namespace motion {
class AnimationChargeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int skip, int unused);
    char pad04[0x20 - 4];
    Manager* manager;       // 0x20
    Dial* dial;             // 0x24
};
}
}

bool hulkfight::motion::AnimationChargeAction::vfunc_5(int skip, int unused)
{
    if (skip == 0) {
        float t = manager->FUN_000592a0()->FUN_00059a30()->blend;
        if (t >= 0.0f && t <= 1.0f) {
        } else if (t > 1.0f) {
            t = 1.0f;
        } else {
            t = 0.0f;
        }
        dial->FUN_00225cf0((dial->to - dial->from) * t + dial->from);
    }
    return true;
}
