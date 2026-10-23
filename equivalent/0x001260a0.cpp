// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::TargetDirectionCondition::vfunc_6 @ 0x001260a0
#include "gen/hulkfight.h"

extern "C" double sqrt(double);

struct V3_1260a0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Anchor_1260a0 {
    char FUN_00059a50(V3_1260a0 *out);
};

struct Target_1260a0 {
    char pad0[0x40];
    V3_1260a0 pos;
    char pad4c[4];
    V3_1260a0 dir;
};

struct Fighter_1260a0 {
    char pad0[0x10];
    Anchor_1260a0 *anchor;
    char pad14[0x328 - 0x14];
    Target_1260a0 *target;
};

struct Owner;
struct Chain_1260a0 {
    Fighter_1260a0 *FUN_00059a30();
};

namespace fight {
class Params_1260a0 {
public:
    virtual void v0();
    Chain_1260a0 *FUN_000592a0();
};
}

class CFightParams_1260a0 : public fight::Params_1260a0 {
public:
    virtual void v0();
};

bool FUN_00018960(float a, float b, float eps);

namespace fight {
class Condition_1260a0 {
public:
    virtual void c0();
};
}

namespace hulkfight {
namespace ai {
}
}
bool hulkfight::ai::TargetDirectionCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_1260a0 * params = (fight::Params_1260a0 *)__p1; int b = (int)__p2;

    CFightParams_1260a0 *fp = dynamic_cast<CFightParams_1260a0 *>(params);
    if (fp == 0)
        return 0;
    Fighter_1260a0 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Target_1260a0 *target = fighter->target;
    if (target == 0)
        return 0;
    V3_1260a0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    fighter->anchor->FUN_00059a50(&pos);
    V3_1260a0 d;
    d.x = pos.x - target->pos.x;
    d.y = pos.y - target->pos.y;
    d.z = pos.z - target->pos.z;
    d.FUN_0022d110();
    V3_1260a0 e = target->dir;
    e.FUN_0022d110();
    float dot = e.z * d.z + e.y * d.y + e.x * d.x;
    switch (this->f_0c) {
    case 0:
        return dot < this->f_10;
    case 1:
        return dot <= this->f_10;
    case 2:
        return FUN_00018960(dot, this->f_10, 1e-5f);
    case 3:
        return !FUN_00018960(dot, this->f_10, 1e-5f);
    case 4:
        return dot >= this->f_10;
    case 5:
        return dot > this->f_10;
    }
    return 0;
}
