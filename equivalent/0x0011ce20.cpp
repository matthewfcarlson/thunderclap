// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 74/74)
// hulkfight::ai::StrafeRunAction::vfunc_5 @ 0x0011ce20
#include "decls/address.h"
extern "C" double pow(double, double);

struct Vec3_11ce20 {
    float x, y, z;
    float FUN_0022d110();
};

union Slot_11ce20 {
    int i;
    float f;
    unsigned int u;
};

class RefCounted_11ce20 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Mount_11ce20 {
    char pad0[0x18];
    bool FUN_00059a50(Vec3_11ce20 *out);
};

struct Target_11ce20 : RefCounted_11ce20 {
    char pad04[0x3c];
    Vec3_11ce20 pos;
};

struct Player_11ce20 {
    char pad0[0x10];
    Mount_11ce20 *mount;
};

struct Hub20_11ce20 {
    char pad0[0x124];
    Player_11ce20 *player;
};

struct World {
    char pad0[0x20];
    Hub20_11ce20 *hub;
};

struct Stats_11ce20 {
    char pad0[0x10];
    Mount_11ce20 *mount;
    char pad14[0x328 - 0x14];
    Target_11ce20 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_11ce20 aim;
    float f2070;
    Vec3_11ce20 dir;
    bool FUN_00035660(Vec3_11ce20 *out);
};

void *__fastcall FUN_000592a0(void *owner);
Stats_11ce20 *__fastcall FUN_00059a30(void *x);
extern "C" float FUN_00224f10(Vec3_11ce20 *v);
extern "C" float FUN_00224fc0(float from, float to);
extern "C" void FUN_00224d70(float angle, Vec3_11ce20 *v);

extern Vec3_11ce20 DAT_004a6ac0;

struct Tuning_11ce20 {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    char b2c;
    char b2d;
    char pad2e[2];
    float f30;
    float f34;
};

namespace hulkfight {
namespace ai {
class StrafeRunAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(Slot_11ce20 a0, Slot_11ce20 a1);
    char pad04[0x18];
    Tuning_11ce20 *tuning;
    void *owner;
    RefCounted_11ce20 *held;
    int f28;
    int mode;
};

bool StrafeRunAction::vfunc_5(Slot_11ce20 a0, Slot_11ce20 a1)
{
    if (a0.i != 0)
        return true;
    if (owner == 0)
        return false;

    Stats_11ce20 *stats = FUN_00059a30(FUN_000592a0(owner));
    Target_11ce20 *target = stats->target;
    if (target == 0) {
        target = (Target_11ce20 *)held;
        if (target == 0)
            return true;
    }
    target->AddRef();
    if (held != 0)
        held->Release();
    held = target;

    struct Frame {
        float angle;
        float dist;
        float step;
        float t18;
        float t1c;
        float dy;
        Vec3_11ce20 w;
        Vec3_11ce20 d;
        Vec3_11ce20 fwd;
        Vec3_11ce20 pos;
        Vec3_11ce20 q;
    } fr;

    fr.pos = target->pos;
    Tuning_11ce20 *tn = tuning;
    if (tn->b2d) {
        int m = mode;
        if (m == 1 || m == 2 || m == 8)
            fr.pos.x = fr.pos.x + tn->f30;
        if (m == 6 || m == 5 || m == 4)
            fr.pos.x = fr.pos.x - tn->f30;
        if (m == 2 || m == 3 || m == 4)
            fr.pos.z = fr.pos.z + tn->f30;
        if (m == 8 || m == 7 || m == 6)
            fr.pos.z = fr.pos.z - tn->f30;
    }
    fr.q.x = 0.0f;
    fr.q.y = 0.0f;
    fr.q.z = 0.0f;
    stats->mount->FUN_00059a50(&fr.q);

    fr.d.x = fr.pos.x - fr.q.x;
    fr.d.y = 0.0f;
    fr.d.z = fr.pos.z - fr.q.z;
    fr.dy = -(fr.pos.y - fr.q.y);
    fr.dist = fr.d.FUN_0022d110();

    fr.fwd.x = 0.0f;
    fr.fwd.y = 0.0f;
    fr.fwd.z = 0.0f;
    stats->FUN_00035660(&fr.fwd);
    fr.fwd.y = 0.0f;
    fr.fwd.FUN_0022d110();

    tn = tuning;
    a0.f = tn->f14;
    fr.t1c = fr.fwd.z * fr.d.z + fr.fwd.x * fr.d.x + fr.fwd.y * fr.d.y;
    if (fr.t1c < 0.0f) {
        if (f28 > 0)
            f28 = -f28;
        if (fr.dist > a0.f) {
            f28 = 1;
            fr.w = fr.d;
        } else {
            fr.w = fr.fwd;
        }
    } else {
        if (f28 >= 0) {
            fr.w = fr.d;
        } else if (fr.dist > a0.f) {
            f28 = 1;
            fr.w = fr.d;
        } else {
            fr.w = fr.fwd;
        }
    }

    fr.step = tn->f18;
    if (fr.step <= 0.0f) {
        stats->aim = fr.w;
    } else {
        fr.angle = FUN_00224f10(&fr.fwd);
        fr.t18 = FUN_00224f10(&fr.w);
        double diff = FUN_00224fc0(fr.angle, fr.t18);
        fr.step = fr.step * a1.f;
        a1.f = (float)diff;
        a1.u &= 0x7fffffff;
        if (a1.f <= fr.step) {
            fr.angle = fr.t18;
        } else if (diff < 0.0f) {
            fr.angle = fr.angle - fr.step;
        } else {
            fr.angle = fr.step + fr.angle;
        }
        fr.w = DAT_004a6ac0;
        FUN_00224d70(fr.angle, &fr.w);
        stats->aim = fr.w;
    }
    stats->dir = stats->aim;

    if (f28 > 0 && fr.t1c > 0.0f) {
        tn = tuning;
        fr.t1c = tn->f1c;
        fr.t18 = tn->f20;
        Hub20_11ce20 *hub = DAT_004dd700->hub;
        Player_11ce20 *pl = hub->player;
        if (pl != 0) {
            pl->mount->FUN_00059a50(&fr.pos);
            Tuning_11ce20 *t3 = tuning;
            fr.step = t3->f28;
            a1.f = t3->f24;
            if (t3->b2c) {
                if (fr.pos.y > a1.f) {
                    double k = 1.0f / pow(fr.pos.y / a1.f, fr.step);
                    fr.t1c = k * t3->f1c;
                    fr.t18 = k * t3->f20;
                }
            }
        }
        if (fr.dy < fr.t1c) {
            if (fr.dist > a0.f || !(a0.f > 0.0f))
                stats->aim.y = 1.0f;
            else
                stats->aim.y = fr.dist / a0.f;
            stats->aim.FUN_0022d110();
        } else if (fr.dy > fr.t18) {
            if (fr.dist > a0.f || !(a0.f > 0.0f))
                stats->aim.y = -1.0f;
            else
                stats->aim.y = -(fr.dist / a0.f);
            stats->aim.FUN_0022d110();
        }
    }
    stats->f2070 = tuning->f34;
    return true;
}
}
}
