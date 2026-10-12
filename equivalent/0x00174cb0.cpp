// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 20/20)
// hulkfight::motion::FootPivotAction::vfunc_5 @ 0x00174cb0
struct Vec3 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3 *other, float eps);
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const Vec3 *in, Vec3 *out);
};

struct Transform {
    void FUN_00221d20(float v);
};

struct JointObject {
    char pad0[0x18];
    Transform transform;
};

struct Target {
    char pad0[0x40];
    Vec3 pos;
};

struct Stats {
    char pad0[0x328];
    Target *target;
    char pad32c[0x2064 - 0x32c];
    Vec3 aim;
    float FUN_000354c0();
    void FUN_00035720(Vec3 *v);
};

struct Skeleton2 {
    char pad0[0x1c];
    Matrix *matrices;
};

struct Skeleton1 {
    char pad0[0x64];
    Skeleton2 *inner;
};

struct Body {
    Stats *FUN_00059a30();
    Skeleton1 *FUN_00059a40();
    void FUN_00059a50(Vec3 *out);
};

struct Pivot {
    char pad0[0x20];
    Vec3 local;
    float angleOffset;      // 0x2c
    float turnRate;         // 0x30
    char useTarget;         // 0x34
};

Body *__fastcall FUN_000592a0(void *owner);
extern "C" float FUN_00224f10(Vec3 *v);
extern "C" float FUN_00224fc0(float from, float to);
extern "C" void FUN_00224d70(float angle, Vec3 *v);

namespace hulkfight {
namespace motion {
class FootPivotAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, float dt);
    char pad04[0x18];
    Pivot *pivot;           // 0x1c
    void *owner;            // 0x20
    unsigned int index;     // 0x24
    JointObject *joint;     // 0x28
};

bool FootPivotAction::vfunc_5(int a1, float dt)
{
    // One contiguous frame: the stubs fill through the pointers handed to callees.
    struct {
        float out;
        float rate;
        Vec3 t;
        float angleNow;
        float target;
        Vec3 d;
        Vec3 m;
        Vec3 f;
        Vec3 r;
        Vec3 a;
        Vec3 z;
        Matrix mtx;
    } fr;

    if (a1 != 0)
        return true;

    Body *body = FUN_000592a0(owner);
    if (body == 0)
        return false;
    Stats *stats = body->FUN_00059a30();
    if (stats == 0)
        return false;
    Skeleton1 *skel = body->FUN_00059a40();
    if (skel == 0)
        return false;

    Matrix *mats = skel->inner->matrices;
    fr.a.x = 0.0f;
    fr.a.y = 0.0f;
    fr.a.z = 0.0f;
    fr.mtx = mats[index];
    fr.t = pivot->local;
    fr.mtx.FUN_0022c2b0(&fr.t, &fr.a);

    fr.m.x = 0.0f;
    fr.m.y = 0.0f;
    fr.m.z = 0.0f;
    body->FUN_00059a50(&fr.m);

    fr.d.x = fr.a.x - fr.m.x;
    fr.d.y = fr.a.y - fr.m.y;
    fr.d.z = fr.a.z - fr.m.z;
    fr.angleNow = stats->FUN_000354c0();

    float ang;
    if (pivot->useTarget) {
        Target *tgt = stats->target;
        if (tgt != 0) {
            fr.t.x = tgt->pos.x - fr.m.x;
            fr.t.y = tgt->pos.y - fr.m.y;
            fr.t.z = tgt->pos.z - fr.m.z;
            ang = FUN_00224f10(&fr.t);
        } else {
            ang = 0.0f;
        }
    } else {
        fr.t = stats->aim;
        fr.z.x = 0.0f;
        fr.z.y = 0.0f;
        fr.z.z = 0.0f;
        if (!fr.t.FUN_0022d2b0(&fr.z, 1e-5f))
            ang = FUN_00224f10(&fr.t);
        else
            ang = fr.angleNow;
    }

    fr.target = ang + pivot->angleOffset;
    fr.rate = pivot->turnRate;
    if (!(fr.rate < 0.0f)) {
        float diff = FUN_00224fc0(fr.angleNow, fr.target);
        float step = fr.rate * dt;
        union {
            float f;
            unsigned int u;
        } a;
        a.f = diff;
        a.u &= 0x7fffffff;
        if (a.f <= step)
            fr.out = fr.target;
        else if (!(diff < 0.0f))
            fr.out = step + fr.angleNow;
        else
            fr.out = fr.angleNow - step;
    } else {
        fr.out = fr.target;
    }

    joint->transform.FUN_00221d20(fr.out);

    float delta = fr.out - fr.angleNow;
    fr.r = fr.d;
    FUN_00224d70(delta, &fr.r);
    fr.f.x = fr.d.x - fr.r.x;
    fr.f.y = fr.d.y - fr.r.y;
    fr.f.z = fr.d.z - fr.r.z;
    stats->FUN_00035720(&fr.f);
    return true;
}
}
}
