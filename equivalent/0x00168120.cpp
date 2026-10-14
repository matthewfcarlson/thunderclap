// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::VelocityAnimatedCondition::vfunc_6 @ 0x00168120
extern "C" double sqrt(double);

struct Vec3_168120 {
    float x, y, z;
};

struct Fighter_168120 {
    void FUN_000356c0(Vec3_168120 *out);
};

struct Holder_168120 {
    Fighter_168120 *FUN_00059a30();
};

bool FUN_00018960(float a, float b, float eps);

namespace fight {
class Params {
public:
    virtual void v0();
    virtual void v1();
    Holder_168120 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v2();
};

class VelocityAnimatedCondition {
public:
    char pad0[0xc];
    unsigned mode;
    float speed;

    bool FUN_00168120(int a1, fight::Params *params, int a3);
};

bool VelocityAnimatedCondition::FUN_00168120(int a1, fight::Params *params, int a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Fighter_168120 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Vec3_168120 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    fighter->FUN_000356c0(&v);
    float s = (float)sqrt((double)(v.z * v.z + v.x * v.x + v.y * v.y));

    switch (mode) {
    case 0:
        return s < speed;
    case 1:
        return s <= speed;
    case 2:
        return FUN_00018960(s, speed, 1e-05f);
    case 3:
        return !FUN_00018960(s, speed, 1e-05f);
    case 4:
        return s >= speed;
    case 5:
        return s > speed;
    }
    return false;
}
