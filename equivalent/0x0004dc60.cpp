// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 16/16)
// CMotionClimbAngleCondition::vfunc_7 @ 0x0004dc60
#include "compat/ptr.h"
struct Vec3_4dc60 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_4dc60* other, float epsilon);
    float FUN_0022d110();
    void FUN_000111b0(const Vec3_4dc60* a, const Vec3_4dc60* b);
};

struct Stats_4dc60 {
    char pad0[0x1ae0];
    Vec3_4dc60 aimB;
    char pad1aec[0x1af8 - 0x1aec];
    Vec3_4dc60 aimA;
    bool FUN_000356c0(Vec3_4dc60* out);
};

void* __fastcall FUN_000592a0(void* params);
Stats_4dc60* __fastcall FUN_00059a30(void* owner);
extern "C" float FUN_00018a20(float v);
extern "C" float FUN_00224fc0(float a, float b);

union FloatBits_4dc60 {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits_4dc60 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class CMotionClimbAngleCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(void* params);
    char pad04[8];
    float angleTolerance;
    float limitAngle;
    float minLength;
};

struct Frame_4dc60 {
    float a;
    Vec3_4dc60 dir;
    Vec3_4dc60 vel;
    Vec3_4dc60 tmp; // zero / up / scaled-correction temp share one slot
    Vec3_4dc60 cross;
};

bool CMotionClimbAngleCondition::vfunc_7(void* params)
{
    Stats_4dc60* stats = FUN_00059a30(FUN_000592a0(params));
    Frame_4dc60 f;

    f.dir = stats->aimA;
    f.tmp.x = 0.0f;
    f.tmp.y = 0.0f;
    f.tmp.z = 0.0f;
    if (f.dir.FUN_0022d2b0(&f.tmp, 1e-5f)) {
        f.dir = stats->aimB;
        f.tmp.x = 0.0f;
        f.tmp.y = 0.0f;
        f.tmp.z = 0.0f;
        if (f.dir.FUN_0022d2b0(&f.tmp, 1e-5f))
            return 0;
    }
    f.dir.y = 0.0f;
    f.dir.FUN_0022d110();

    if (!stats->FUN_000356c0(&f.vel))
        return 0;

    double d = f.vel.z * f.dir.z + f.vel.x * f.dir.x + f.vel.y * f.dir.y;
    if (d < 0.0) {
        double nd = -d;
        f.tmp.x = f.dir.x;
        f.tmp.y = f.dir.y;
        f.tmp.z = f.dir.z;
        f.tmp.y = f.tmp.y * nd;
        f.tmp.z = f.tmp.z * nd;
        f.tmp.x = f.tmp.x * nd;
        f.vel.x = f.vel.x + f.tmp.x;
        f.vel.y = f.vel.y + f.tmp.y;
        f.vel.z = f.vel.z + f.tmp.z;
    }
    if (f.vel.FUN_0022d110() < minLength)
        return 0;

    f.a = FUN_00018a20(f.vel.y);
    hulk_freg fz = AbsF(f.vel.y);
    hulk_freg diff = fz - 1.0f;
    if (!(AbsF(diff) <= 1e-5f)) {
        f.tmp.x = 0.0f;
        f.tmp.y = 1.0f;
        f.tmp.z = 0.0f;
        f.cross.FUN_000111b0(&f.vel, &f.tmp);
        double c = f.cross.z * f.dir.z + f.cross.y * f.dir.y + f.dir.x * f.cross.x;
        if (c < 0.0)
            f.a = -f.a;
    }
    hulk_freg r = FUN_00224fc0(f.a, angleTolerance);
    hulk_freg limit = limitAngle * 0.5f;
    return limit > AbsF(r);
}
