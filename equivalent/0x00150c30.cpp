// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 21/22, incomplete)
// hulkfight::motion::CollisionChargeCondition::vfunc_6 @ 0x00150c30
struct Fighter_150c30 {
    char pad0[0x213c];
    float value;
};

struct Holder_150c30 {
    Fighter_150c30 *FUN_00059a30();
};

struct Target_150c30 {
    char pad0[0x7c];
    float value;
};

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Target_150c30 *v3();
    Holder_150c30 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
  public:
    virtual void v4();
};

char FUN_00018960(float a, float b, float eps);

namespace fight {
class Condition {
  public:
    virtual void c0();
};
}

namespace hulkfight {
namespace motion {

class CollisionChargeCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a1, fight::Params *params, int a3);
    char pad04[8];
    unsigned int mode;
    float threshold;
    unsigned char useFighter;
};

char CollisionChargeCondition::vfunc_6(int a1, fight::Params *params, int a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Target_150c30 *target = params->v3();
    if (target == 0)
        return false;

    Fighter_150c30 *fighter = params->FUN_000592a0()->FUN_00059a30();

    float a = target->value;
    float b = threshold;
    if (useFighter && fighter)
        b = fighter->value;

    switch (mode) {
    case 0:
        return a < b;
    case 1:
        return a <= b;
    case 2:
        return FUN_00018960(a, b, 1e-5f);
    case 3:
        return FUN_00018960(a, b, 1e-5f) == 0;
    case 4:
        return a >= b;
    case 5:
        return a > b;
    }
    return false;
}

}
}
