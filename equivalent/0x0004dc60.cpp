// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 13/16, incomplete)
// CMotionClimbAngleCondition::vfunc_7 @ 0x0004dc60
struct Vec3 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3* other, float epsilon);
    float FUN_0022d110();
    void FUN_000111b0(const Vec3* a, const Vec3* b);
};

struct Stats {
    char pad0[0x1ae0];
    Vec3 aimB;
    char pad1aec[0x1af8 - 0x1aec];
    Vec3 aimA;
    bool FUN_000356c0(Vec3* out);
};

void* __fastcall FUN_000592a0(void* params);
Stats* __fastcall FUN_00059a30(void* owner);
extern "C" float FUN_00018a20(float v);
extern "C" float FUN_00224fc0(float a, float b);

union FloatBits {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits b;
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

bool CMotionClimbAngleCondition::vfunc_7(void* params)
{
    Stats* stats = FUN_00059a30(FUN_000592a0(params));

    Vec3 dir = stats->aimA;
    Vec3 zero;
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    if (dir.FUN_0022d2b0(&zero, 1e-5f)) {
        dir = stats->aimB;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        if (dir.FUN_0022d2b0(&zero, 1e-5f))
            return 0;
    }
    dir.y = 0.0f;
    dir.FUN_0022d110();

    Vec3 vel;
    if (!stats->FUN_000356c0(&vel))
        return 0;

    float d = vel.z * dir.z + vel.x * dir.x + vel.y * dir.y;
    if (d < 0.0f) {
        float nd = -d;
        Vec3 t;
        t.x = dir.x;
        t.y = dir.y;
        t.z = dir.z;
        t.y = t.y * nd;
        t.z = t.z * nd;
        t.x = t.x * nd;
        vel.x = vel.x + t.x;
        vel.y = vel.y + t.y;
        vel.z = vel.z + t.z;
    }
    if (vel.FUN_0022d110() < minLength)
        return 0;

    float a = FUN_00018a20(vel.y);
    float fz = AbsF(vel.y);
    float diff = fz - 1.0f;
    if (!(AbsF(diff) <= 1e-5f)) {
        Vec3 up;
        up.x = 0.0f;
        up.y = 1.0f;
        up.z = 0.0f;
        Vec3 cross;
        cross.FUN_000111b0(&vel, &up);
        float c = cross.z * dir.z + cross.y * dir.y + dir.x * cross.x;
        if (c < 0.0f)
            a = -a;
    }
    float r = FUN_00224fc0(a, angleTolerance);
    float limit = limitAngle * 0.5f;
    return limit > AbsF(r);
}
