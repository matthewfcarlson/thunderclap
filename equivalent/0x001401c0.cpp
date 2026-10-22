// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 22/22)
// hulkfight::motion::WallExitAction::vfunc_5 @ 0x001401c0
#include "compat/ptr.h"
struct Vec3_1401c0 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3_1401c0* other, float eps);
    float FUN_0022d110();
};

union FloatBits_1401c0 {
    float f;
    unsigned int u;
};

float __cdecl FUN_00224f10(Vec3_1401c0* v);
float __cdecl FUN_00224fc0(float from, float to);
void __cdecl FUN_00224d70(float angle, Vec3_1401c0* v);

struct Xform_1401c0 {
    void FUN_0022be40(Vec3_1401c0* pos);
    void FUN_00221d20(float v);
};

struct Target_1401c0 {
    char pad00[0x18];
    Xform_1401c0 xform;
};

struct Limits_1401c0 {
    char pad00[0x30];
    float halfHeight;
    float limit;
};

struct Fighter_1401c0 {
    char pad00[0x11c];
    Limits_1401c0* limits;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1ad4 - 0x144];
    Vec3_1401c0 a;
    Vec3_1401c0 b;
    Vec3_1401c0 c;
    Vec3_1401c0 d;
    char pad1b04[0x2064 - 0x1b04];
    Vec3_1401c0 vel;
    void FUN_000359c0(int v);
    void FUN_000357a0(Vec3_1401c0* v);
};

struct Anchor_1401c0 {
    Fighter_1401c0* FUN_00059a30();
    void FUN_00059a50(Vec3_1401c0* out);
};

struct Owner_1401c0 {
    Anchor_1401c0* FUN_000592a0();
};

struct Params {
    char pad00[0x1c];
    float drag;
    char pad20[0x28 - 0x20];
    float rate;
};

class WallExitAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int skip, float dt);
    char pad04[0x1c - 4];
    Params* params;
    Owner_1401c0* owner;
    Target_1401c0* target;
    Vec3_1401c0 g;
    Vec3_1401c0 n;
    Vec3_1401c0 vel;
};

bool WallExitAction::vfunc_5(int skip, float dt)
{
    if (skip != 0) {
        return true;
    }
    if (target == 0) {
        return false;
    }
    Anchor_1401c0* anchor = owner->FUN_000592a0();
    Fighter_1401c0* fighter = anchor->FUN_00059a30();
    fighter->FUN_000359c0(3);

    hulk_freg s1 = FUN_00224f10(&vel);
    Vec3_1401c0 fv = fighter->vel;
    hulk_freg s2 = FUN_00224f10(&fv);
    hulk_freg held = s1;
    hulk_freg diff = FUN_00224fc0(s1, s2);
    hulk_freg v;
    if (!(diff < 2.3561945f)) {
        v = held;
    } else {
        held = params->rate;
        if (!(held < 0.0f)) {
            hulk_freg diff2 = FUN_00224fc0(s1, s2);
            hulk_freg step = held * dt;
            FloatBits_1401c0 ab;
            ab.f = diff2;
            ab.u &= 0x7fffffff;
            if (!(ab.f <= step)) {
                if (!(diff2 < 0.0f)) {
                    v = step + s1;
                } else {
                    v = s1 - step;
                }
            } else {
                v = s2;
            }
        } else {
            v = s2;
        }
    }
    FUN_00224d70(v - s1, &vel);

    vel.y = vel.y - dt * params->drag;
    Vec3_1401c0 push;
    push.x = vel.x * dt;
    push.y = vel.y * dt;
    push.z = vel.z * dt;

    Vec3_1401c0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    anchor->FUN_00059a50(&pos);

    if (fighter->mode == 4) {
        Vec3_1401c0 f = fighter->d;
        Vec3_1401c0 gg = fighter->c;
        Vec3_1401c0 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        bool update = true;
        if (f.FUN_0022d2b0(&zero, 1e-05f)) {
            f = fighter->b;
            gg = fighter->a;
            zero.x = 0.0f;
            zero.y = 0.0f;
            zero.z = 0.0f;
            if (f.FUN_0022d2b0(&zero, 1e-05f)) {
                update = false;
            }
        }
        if (update) {
            f.y = 0.0f;
            f.FUN_0022d110();
            n = f;
            g = gg;
        }
    }

    push.x = pos.x + push.x;
    push.y = pos.y + push.y;
    push.z = pos.z + push.z;
    Limits_1401c0* lim = fighter->limits;
    if (lim->halfHeight * 0.5f > push.y - g.y) {
        hulk_freg t = n.z * g.z + n.y * g.y + n.x * g.x;
        hulk_freg depth = n.x * push.x + n.y * push.y + n.z * push.z - t;
        if (depth < lim->limit) {
            Vec3_1401c0 h;
            hulk_freg d = lim->limit - depth;
            h.x = n.x * d;
            h.y = n.y * d;
            h.z = n.z * d;
            fighter->FUN_000357a0(&h);
        }
    }
    target->xform.FUN_0022be40(&push);
    float arg1 = FUN_00224f10(&vel);
    target->xform.FUN_00221d20(arg1);
    return true;
}
