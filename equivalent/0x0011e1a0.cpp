// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 27/30, incomplete)
// hulkfight::ai::StrafeLateralHBAction::vfunc_5 @ 0x0011e1a0
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

class RefCounted {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Mount {
    char pad0[0x18];
    bool FUN_00059a50(Vec3 *out);
};

struct Target : RefCounted {
    char pad04[0x3c];
    Vec3 pos;
};

struct Stats {
    char pad0[0x10];
    Mount *mount;
    char pad14[0x328 - 0x14];
    Target *target;
    char pad32c[0x2064 - 0x32c];
    Vec3 aim;
    float f2070;
    Vec3 dir;
    bool FUN_00035660(Vec3 *out);
};

void *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(void *x);
extern "C" float FUN_00224f10(Vec3 *v);
extern "C" float FUN_00224fc0(float from, float to);
extern "C" float FUN_00083d90(float *v);
extern "C" void FUN_00224d70(float angle, Vec3 *v);

extern Vec3 DAT_004a6ac0;

struct Tuning {
    char pad0[0x1c];
    float low;
    float high;
    float f24;
};

namespace hulkfight {
namespace ai {
class StrafeLateralHBAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2);
    char pad04[0x18];
    Tuning *tuning;     // 0x1c
    void *owner;        // 0x20
    RefCounted *held;   // 0x24
};

bool StrafeLateralHBAction::vfunc_5(int a1, int a2)
{
    if (a1 != 0)
        return true;
    if (owner == 0)
        return false;

    Stats *stats = FUN_00059a30(FUN_000592a0(owner));
    Target *target = stats->target;
    if (target == 0) {
        target = (Target *)held;
        if (target == 0)
            return true;
    }
    target->AddRef();
    if (held != 0)
        held->Release();
    held = target;

    // The original keeps all of these in one contiguous stack frame; the stubs fill through
    // the pointers handed to callees, so the layout matters.
    struct {
        float side;
        float height;
        Vec3 d;
        Vec3 q;
        Vec3 r;
        Vec3 p;
    } fr;
    fr.p = target->pos;
    fr.q.x = 0.0f;
    fr.q.y = 0.0f;
    fr.q.z = 0.0f;
    stats->mount->FUN_00059a50(&fr.q);

    fr.d.x = fr.p.x - fr.q.x;
    fr.d.y = 0.0f;
    fr.d.z = fr.p.z - fr.q.z;
    fr.height = -(fr.p.y - fr.q.y);
    float dist = fr.d.FUN_0022d110();

    fr.r.x = 0.0f;
    fr.r.y = 0.0f;
    fr.r.z = 0.0f;
    stats->FUN_00035660(&fr.r);
    fr.r.y = 0.0f;
    fr.r.FUN_0022d110();

    float angleD = FUN_00224f10(&fr.d);
    float angleR = FUN_00224f10(&fr.r);
    fr.side = FUN_00224fc0(angleD, angleR);
    float side = FUN_00083d90(&fr.side);
    fr.side = side;

    float theta;
    if (side < 0.0f)
        theta = angleD - 1.5707964f;
    else
        theta = angleD + 1.5707964f;

    if (dist < 7.0f) {
        double w = (double)dist * 0.14285715f * 1.5707964f;
        if (side < 0.0f)
            theta = theta - w;
        else
            theta = w + theta;
    } else if (dist > 20.0f) {
        double x;
        if (dist < 40.0f)
            x = ((double)dist - 20.0f) * 0.05f * 1.5707964f;
        else
            x = 1.5707964f;
        if (side < 0.0f)
            theta = x + theta;
        else
            theta = theta - x;
    }

    stats->aim = DAT_004a6ac0;
    FUN_00224d70(theta, &stats->aim);

    if (fr.height < tuning->low) {
        if (dist > 20.0f)
            stats->aim.y = 1.0f;
        else
            stats->aim.y = dist * 0.05f;
        stats->aim.FUN_0022d110();
    } else if (fr.height > tuning->high) {
        if (dist > 20.0f)
            stats->aim.y = -1.0f;
        else
            stats->aim.y = dist * -0.05f;
        stats->aim.FUN_0022d110();
    }

    stats->dir = fr.d;
    stats->f2070 = tuning->f24;
    return true;
}
}
}
