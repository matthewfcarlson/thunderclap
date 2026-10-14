// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 25/30, incomplete)
// hulkfight::motion::LocomotionSteerAction::vfunc_5 @ 0x0015e7d0
extern float DAT_003f32e0;  // 0.0
extern float DAT_003f32f4;  // 0.5

struct V3_15e7d0 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_15e7d0 *other, float eps);
};

struct Mgr10_15e7d0 {
    bool FUN_00059a50(V3_15e7d0 *out);
};

struct Player_15e7d0 {
    char pad0[0x10];
    Mgr10_15e7d0 *mgr10;
    char pad14[0x144 - 0x14];
    int flags144;
    char pad148[0x2064 - 0x148];
    V3_15e7d0 v2064;
    float f2070;
    char pad2074[0x20a8 - 0x2074];
    int i20a8;
    float FUN_000354c0();
    void FUN_00035550(V3_15e7d0 *out);
};

struct Mgr_15e7d0 {
    Player_15e7d0 *FUN_00059a30();
};

struct Holder_15e7d0 {
    Mgr_15e7d0 *FUN_000592a0();
};

struct CurObj {
    char pad0[0x8a8];
    float f8a8;
    float f8ac;
    float f8b0;
};

struct Cfg_15e7d0 {
    char pad0[0x14];
    float f14;
    float f18;
};

float __cdecl FUN_00224ea0(float x, float z);
float __cdecl FUN_00224fc0(float a, float b);

static inline float Abs(float v)
{
    union {
        float f;
        unsigned int u;
    } b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

union Arg1_15e7d0 {
    int skip;
    float f;
};

class LocomotionSteerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(Arg1_15e7d0 a, float dt);
    char pad04[0x1c - 4];
    Cfg_15e7d0 *cfg;
    Holder_15e7d0 *owner;
    CurObj *cur;
    float FUN_0015c590(float t);
};

bool LocomotionSteerAction::vfunc_5(Arg1_15e7d0 a, float dt)
{
    V3_15e7d0 vecA;
    V3_15e7d0 pos;
    V3_15e7d0 vecB;

    if (a.skip)
        return true;
    if (!cur)
        return false;

    Mgr_15e7d0 *mgr = owner->FUN_000592a0();
    Player_15e7d0 *pl = mgr->FUN_00059a30();
    float f = pl->FUN_000354c0();
    cur->f8a8 = f;
    cur->f8ac = f;

    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    pl->mgr10->FUN_00059a50(&pos);

    vecA = pl->v2064;
    vecB.x = 0.0f;
    vecB.y = 0.0f;
    vecB.z = 0.0f;
    if (vecA.FUN_0022d2b0(&vecB, 0.00001f))
        pl->FUN_00035550(&vecA);

    float ang = FUN_00224ea0(vecA.x, vecA.z);
    float q = cur->f8ac;
    a.f = cfg->f18;
    float r;
    if (a.f <= DAT_003f32e0) {
        r = ang;
    } else {
        float d = FUN_00224fc0(q, ang);
        float maxStep = a.f * dt;
        a.f = d;
        if (Abs(a.f) <= maxStep) {
            r = ang;
        } else if (d < DAT_003f32e0) {
            r = q - maxStep;
        } else {
            r = maxStep + q;
        }
    }
    cur->f8a8 = r;
    cur->f8ac = r;

    float v = pl->f2070;
    CurObj *c2 = cur;
    float w = c2->f8b0;
    if (pl->i20a8 >= 0) {
        if (v <= DAT_003f32e0) {
            v = 0.0f;
        } else {
            float vold = v;
            v = 0.5f;
            if (!(vold <= DAT_003f32f4))
                v = 1.0f;
        }
    }
    a.f = FUN_0015c590(v);
    if (pl->flags144 & 2) {
        float h = FUN_0015c590(0.5f);
        if (a.f > h)
            a.f = h;
    }
    float r2 = a.f;
    if (cfg->f14 <= DAT_003f32e0) {
        c2->f8b0 = r2;
        return true;
    }
    dt = cfg->f14 * dt;
    if (r2 - w > DAT_003f32e0) {
        if (dt > r2 - w)
            c2->f8b0 = r2;
        else
            c2->f8b0 = dt + w;
    } else {
        if (-dt < r2 - w)
            c2->f8b0 = r2;
        else
            c2->f8b0 = w - dt;
    }
    return true;
}
