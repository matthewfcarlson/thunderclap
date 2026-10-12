// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 22/22)
// hulkfight::motion::WallExitAction::vfunc_5 @ 0x001401c0
struct Vec3 {
    float x, y, z;
    bool FUN_0022d2b0(const Vec3* other, float eps);
    float FUN_0022d110();
};

union FloatBits {
    float f;
    unsigned int u;
};

float __cdecl FUN_00224f10(Vec3* v);
float __cdecl FUN_00224fc0(float from, float to);
void __cdecl FUN_00224d70(float angle, Vec3* v);

struct Xform {
    void FUN_0022be40(Vec3* pos);
    void FUN_00221d20(float v);
};

struct Target {
    char pad00[0x18];
    Xform xform;
};

struct Limits {
    char pad00[0x30];
    float halfHeight;
    float limit;
};

struct Fighter {
    char pad00[0x11c];
    Limits* limits;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1ad4 - 0x144];
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    char pad1b04[0x2064 - 0x1b04];
    Vec3 vel;
    void FUN_000359c0(int v);
    void FUN_000357a0(Vec3* v);
};

struct Anchor {
    Fighter* FUN_00059a30();
    void FUN_00059a50(Vec3* out);
};

struct Owner {
    Anchor* FUN_000592a0();
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
    Owner* owner;
    Target* target;
    Vec3 g;
    Vec3 n;
    Vec3 vel;
};

bool WallExitAction::vfunc_5(int skip, float dt)
{
    if (skip != 0) {
        return true;
    }
    if (target == 0) {
        return false;
    }
    Anchor* anchor = owner->FUN_000592a0();
    Fighter* fighter = anchor->FUN_00059a30();
    fighter->FUN_000359c0(3);

    float s1 = FUN_00224f10(&vel);
    Vec3 fv = fighter->vel;
    float s2 = FUN_00224f10(&fv);
    float held = s1;
    float diff = FUN_00224fc0(s1, s2);
    float v;
    if (!(diff < 2.3561945f)) {
        v = held;
    } else {
        held = params->rate;
        if (!(held < 0.0f)) {
            float diff2 = FUN_00224fc0(s1, s2);
            float step = held * dt;
            FloatBits ab;
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
    Vec3 push;
    push.x = vel.x * dt;
    push.y = vel.y * dt;
    push.z = vel.z * dt;

    Vec3 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    anchor->FUN_00059a50(&pos);

    if (fighter->mode == 4) {
        Vec3 f = fighter->d;
        Vec3 gg = fighter->c;
        Vec3 zero;
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
    Limits* lim = fighter->limits;
    if (lim->halfHeight * 0.5f > push.y - g.y) {
        float t = n.z * g.z + n.y * g.y + n.x * g.x;
        float depth = n.x * push.x + n.y * push.y + n.z * push.z - t;
        if (depth < lim->limit) {
            Vec3 h;
            float d = lim->limit - depth;
            h.x = n.x * d;
            h.y = n.y * d;
            h.z = n.z * d;
            fighter->FUN_000357a0(&h);
        }
    }
    target->xform.FUN_0022be40(&push);
    target->xform.FUN_00221d20(FUN_00224f10(&vel));
    return true;
}
