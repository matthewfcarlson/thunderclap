// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 51/52, incomplete)
// hulkfight::ai::StrafeCircleAction::vfunc_5 @ 0x0011d900
extern "C" double pow(double, double);

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

class Waypoint {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual Vec3 *GetPos(Vec3 *scratch);
};

struct Special {
    char pad00[0x9e];
    char active;
    char pad9f;
    int key0;
    int key1;
};

struct Registry {
    Waypoint *FUN_001fc8c0(int a, int b);
};


struct Player {
    char pad0[0x10];
    Mount *mount;
};


struct Hub20 {
    char pad0[0x124];
    Player *player;
};

struct World {
    char pad0[0x20];
    Hub20 *hub;
    char pad24[4];
    Registry *registry;
};

struct Stats {
    char pad0[0x10];
    Mount *mount;
    char pad14[0x328 - 0x14];
    Target *target;
    char pad32c[0x1ca0 - 0x32c];
    Special *special;
    char pad1ca4[0x2064 - 0x1ca4];
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
extern World *DAT_004dd700;

struct Tuning {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    char f2c;
    char pad2d[3];
    float f30;
};

namespace hulkfight {
namespace ai {
class StrafeCircleAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2);
    char pad04[0x18];
    Tuning *tuning;
    void *owner;
    RefCounted *held;
};

bool StrafeCircleAction::vfunc_5(int a1, int a2)
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

    struct Frame {
        float theta;
        float dist;
        float lo;
        float side;
        float height;
        float f20;
        Vec3 p;
        Vec3 d;
        Vec3 q;
        Vec3 r;
        Vec3 scratch;
    } fr;

    Special *sp = stats->special;
    Waypoint *wp = 0;
    if (sp != 0 && sp->active != 0)
        wp = DAT_004dd700->registry->FUN_001fc8c0(sp->key0, sp->key1);
    if (wp != 0) {
        Vec3 *pp = wp->GetPos(&fr.scratch);
        fr.p = *pp;
    } else {
        fr.p = target->pos;
    }
    fr.q.x = 0.0f;
    fr.q.y = 0.0f;
    fr.q.z = 0.0f;
    stats->mount->FUN_00059a50(&fr.q);

    fr.d.x = fr.p.x - fr.q.x;
    fr.d.y = 0.0f;
    fr.d.z = fr.p.z - fr.q.z;
    fr.height = -(fr.p.y - fr.q.y);
    fr.dist = fr.d.FUN_0022d110();

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

    Tuning *tn = tuning;
    float f14 = tn->f14;
    float f18 = tn->f18;
    if (f14 > 0.0f && fr.dist < f14) {
        double w = fr.dist / f14 * 1.5707964f;
        if (side < 0.0f)
            theta = theta - w;
        else
            theta = w + theta;
    } else if (f18 > 0.0f && fr.dist > f18) {
        double x;
        if (!((double)f18 + f18 > fr.dist))
            x = 1.5707964f;
        else
            x = (fr.dist - f18) / f18 * 1.5707964f;
        if (side < 0.0f)
            theta = x + theta;
        else
            theta = theta - x;
    }

    stats->aim = DAT_004a6ac0;
    FUN_00224d70(theta, &stats->aim);

    tn = tuning;
    fr.lo = tn->f1c;
    fr.f20 = tn->f20;
    Hub20 *hub = DAT_004dd700->hub;
    Player *pl = hub->player;
    if (pl != 0) {
        pl->mount->FUN_00059a50(&fr.p);
        Tuning *t3 = tuning;
        float f24 = t3->f24;
        float f28 = t3->f28;
        if (t3->f2c != 0) {
            if (fr.p.y > f24) {
                double k = 1.0f / pow(fr.p.y / f24, f28);
                fr.lo = k * t3->f1c;
                fr.f20 = k * t3->f20;
            }
        }
    }
    if (fr.height < fr.lo) {
        if (fr.dist > f18 || !(f18 > 0.0f))
            stats->aim.y = 1.0f;
        else
            stats->aim.y = fr.dist / f18;
        stats->aim.FUN_0022d110();
    } else if (fr.height > fr.f20) {
        if (fr.dist > f18 || !(f18 > 0.0f))
            stats->aim.y = -1.0f;
        else
            stats->aim.y = -(fr.dist / f18);
        stats->aim.FUN_0022d110();
    }
    stats->dir = fr.d;
    stats->f2070 = tuning->f30;
    return true;
}
}
}
