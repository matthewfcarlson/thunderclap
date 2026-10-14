// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::TargetDirectionXZCondition::vfunc_6 @ 0x00126270
extern "C" double sqrt(double);

struct V3_126270 {
    float x, y, z;
    float FUN_0022d110();
};

struct Anchor_126270 {
    char FUN_00059a50(V3_126270 *out);
};

struct Target_126270 {
    char pad0[0x40];
    V3_126270 pos;
    char pad4c[4];
    V3_126270 dir;
};

struct Fighter_126270 {
    char pad0[0x10];
    Anchor_126270 *anchor;
    char pad14[0x328 - 0x14];
    Target_126270 *target;
};

struct Owner;
struct Chain_126270 {
    Fighter_126270 *FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void v0();
    Chain_126270 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v0();
};

bool FUN_00018960(float a, float b, float eps);

namespace fight {
class Condition {
public:
    virtual void c0();
};
}

namespace hulkfight {
namespace ai {
class TargetDirectionXZCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int b);
    char pad04[8];
    int op;
    float threshold;
};
}
}

bool hulkfight::ai::TargetDirectionXZCondition::vfunc_6(int a, fight::Params *params, int b)
{
    CFightParams *fp = dynamic_cast<CFightParams *>(params);
    if (fp == 0)
        return 0;
    Fighter_126270 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Target_126270 *target = fighter->target;
    if (target == 0)
        return 0;
    V3_126270 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    fighter->anchor->FUN_00059a50(&pos);
    V3_126270 d;
    d.x = pos.x - target->pos.x;
    d.y = 0.0f;
    d.z = pos.z - target->pos.z;
    d.FUN_0022d110();
    V3_126270 e = target->dir;
    e.y = 0.0f;
    e.FUN_0022d110();
    float dot = e.z * d.z + d.x * e.x + e.y * d.y;
    switch (op) {
    case 0:
        return dot < threshold;
    case 1:
        return dot <= threshold;
    case 2:
        return FUN_00018960(dot, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(dot, threshold, 1e-5f);
    case 4:
        return dot >= threshold;
    case 5:
        return dot > threshold;
    }
    return 0;
}
