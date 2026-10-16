// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// hulkfight::ai::StrafeCircleHBAction::vfunc_5 @ 0x0011ddb0
#include "decls/data/game/hulkfight/ai.h"

struct Vec3_11ddb0 {
    float x, y, z;
    float FUN_0022d110();
};

class RefCounted_11ddb0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Mount_11ddb0 {
    char pad0[0x18];
    bool FUN_00059a50(Vec3_11ddb0 *out);
};

struct Target_11ddb0 : RefCounted_11ddb0 {
    char pad04[0x3c];
    Vec3_11ddb0 pos;
};

struct Stats_11ddb0 {
    char pad0[0x10];
    Mount_11ddb0 *mount;
    char pad14[0x328 - 0x14];
    Target_11ddb0 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_11ddb0 aim;
    float f2070;
    Vec3_11ddb0 dir;
    bool FUN_00035660(Vec3_11ddb0 *out);
};

void *__fastcall FUN_000592a0(void *owner);
Stats_11ddb0 *__fastcall FUN_00059a30(void *x);
extern "C" float FUN_00224f10(Vec3_11ddb0 *v);
extern "C" float FUN_00224fc0(float from, float to);
extern "C" float FUN_00083d90(float *v);
extern "C" void FUN_00224d70(float angle, Vec3_11ddb0 *v);


struct Tuning_11ddb0 {
    char pad0[0x14];
    float inner;
    float outer;
    float low;
    float high;
    float f24;
};

namespace hulkfight {
namespace ai {
class StrafeCircleHBAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2);
    char pad04[0x18];
    Tuning_11ddb0 *tuning;     // 0x1c
    void *owner;        // 0x20
    RefCounted_11ddb0 *held;   // 0x24
};

bool StrafeCircleHBAction::vfunc_5(int a1, int a2)
{
    if (a1 != 0)
        return true;
    if (owner == 0)
        return false;

    Stats_11ddb0 *stats = FUN_00059a30(FUN_000592a0(owner));
    Target_11ddb0 *target = stats->target;
    if (target == 0) {
        target = (Target_11ddb0 *)held;
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
        Vec3_11ddb0 d;
        Vec3_11ddb0 q;
        Vec3_11ddb0 r;
        Vec3_11ddb0 p;
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

    float inner = tuning->inner;
    float outer = tuning->outer;
    if (inner > 0.0f && dist < inner) {
        double w = dist / inner * 1.5707964f;
        if (side < 0.0f)
            theta = theta - w;
        else
            theta = w + theta;
    } else if (outer > 0.0f && dist > outer) {
        double x;
        if (outer + outer > dist)
            x = (dist - outer) / outer * 1.5707964f;
        else
            x = 1.5707964f;
        if (side < 0.0f)
            theta = x + theta;
        else
            theta = theta - x;
    }

    stats->aim = (*(Vec3_11ddb0*)&DAT_004a6ac0);
    FUN_00224d70(theta, &stats->aim);

    if (fr.height < tuning->low) {
        if (dist > outer || !(outer > 0.0f))
            stats->aim.y = 1.0f;
        else
            stats->aim.y = dist / outer;
        stats->aim.FUN_0022d110();
    } else if (fr.height > tuning->high) {
        if (dist > outer || !(outer > 0.0f))
            stats->aim.y = -1.0f;
        else
            stats->aim.y = -(dist / outer);
        stats->aim.FUN_0022d110();
    }

    stats->dir = fr.d;
    stats->f2070 = tuning->f24;
    return true;
}
}
}
