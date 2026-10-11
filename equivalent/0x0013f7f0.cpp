// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 17/18, incomplete)
// hulkfight::motion::WallVelocityCondition::vfunc_6 @ 0x0013f7f0
struct Vec3 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3 *other, float epsilon);
};

namespace fight {
class Params {
public:
    virtual void vfunc_0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void vfunc_0();
};

struct Stats {
    char pad0[0x1ae0];
    Vec3 aimB;
    char pad1aec[0x1af8 - 0x1aec];
    Vec3 aimA;
    void FUN_000356c0(Vec3 *out);
};

void *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(void *x);
extern "C" char FUN_00018960(float a, float b, float epsilon);

namespace hulkfight { namespace motion {

class WallVelocityCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a0, fight::Params *params, int a2);
    char pad04[8];
    unsigned int mode;
    float threshold;
};

char WallVelocityCondition::vfunc_6(int a0, fight::Params *params, int a2)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;

    Stats *stats = FUN_00059a30(FUN_000592a0(params));

    Vec3 dir = stats->aimA;
    Vec3 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (dir.FUN_0022d2b0(&zero, 1e-5f))
        dir = stats->aimB;

    Vec3 vel;
    vel.x = 0.0f;
    vel.y = 0.0f;
    vel.z = 0.0f;
    stats->FUN_000356c0(&vel);

    float v = -(vel.z * dir.z + vel.y * dir.y + vel.x * dir.x);

    switch (mode) {
    case 0:
        return v < threshold;
    case 1:
        return v <= threshold;
    case 2:
        return FUN_00018960(v, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(v, threshold, 1e-5f);
    case 4:
        return v >= threshold;
    case 5:
        return v > threshold;
    }
    return 0;
}

}}
