// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::TargetDirectionCondition::vfunc_6 @ 0x001260a0
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Anchor {
    char FUN_00059a50(V3 *out);
};

struct Target {
    char pad0[0x40];
    V3 pos;
    char pad4c[4];
    V3 dir;
};

struct Fighter {
    char pad0[0x10];
    Anchor *anchor;
    char pad14[0x328 - 0x14];
    Target *target;
};

struct Owner;
struct Chain {
    Fighter *FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void v0();
    Chain *FUN_000592a0();
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
class TargetDirectionCondition {
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

bool hulkfight::ai::TargetDirectionCondition::vfunc_6(int a, fight::Params *params, int b)
{
    CFightParams *fp = dynamic_cast<CFightParams *>(params);
    if (fp == 0)
        return 0;
    Fighter *fighter = params->FUN_000592a0()->FUN_00059a30();
    Target *target = fighter->target;
    if (target == 0)
        return 0;
    V3 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    fighter->anchor->FUN_00059a50(&pos);
    V3 d;
    d.x = pos.x - target->pos.x;
    d.y = pos.y - target->pos.y;
    d.z = pos.z - target->pos.z;
    d.FUN_0022d110();
    V3 e = target->dir;
    e.FUN_0022d110();
    float dot = e.z * d.z + e.y * d.y + e.x * d.x;
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
