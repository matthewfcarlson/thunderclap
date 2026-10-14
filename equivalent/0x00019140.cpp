// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 22/22)
// CDropAction::vfunc_7 @ 0x00019140
struct Vec3_19140 {
    float x, y, z;
};

union FloatBits_19140 {
    float f;
    unsigned int u;
};

float __cdecl FUN_00224ea0(float x, float z);
float __cdecl FUN_00224fc0(float from, float to);

static inline float AbsBits(float v)
{
    FloatBits_19140 bits;
    bits.f = v;
    bits.u &= 0x7fffffff;
    return bits.f;
}

struct Fighter_19140 {
    char pad00[0x2064];
    float velX;
    char pad2068[4];
    float velZ;
    float timer;
    void FUN_000359c0(int mode);
};

struct Anchor_19140 {
    Fighter_19140 *FUN_00059a30();
    void FUN_00059a50(Vec3_19140 *out);
};

struct Owner_19140 {
    Anchor_19140 *FUN_000592a0();
};

struct DropParams {
    char pad00[0x14];
    float angleOffset;
    float followRate;
    float turnRate;
    char pad20[0x28 - 0x20];
    float fallRate;
    float maxFall;
};

struct Transform_19140 {
    float FUN_002220d0();
    void FUN_00221d20(float angle);
    void FUN_0022be40(Vec3_19140 *pos);
};

struct DropTarget {
    char pad00[0x18];
    Transform_19140 xform;
};

class CDropAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float dt);
    virtual void vfunc_8();
    char pad04[0x1c - 4];
    Owner_19140 *owner;
    DropParams *params;
    DropTarget *target;
    float angle;
    float fall;
};

bool CDropAction::vfunc_7(float dt)
{
    if (target == 0) {
        return false;
    }
    Anchor_19140 *anchor = owner->FUN_000592a0();
    Fighter_19140 *fighter = anchor->FUN_00059a30();
    fighter->FUN_000359c0(3);

    if (fighter->timer > 0.0f) {
        float cur = angle;
        float ang = FUN_00224ea0(fighter->velX, fighter->velZ);
        if (params->turnRate < 0.0f) {
            angle = ang;
        } else {
            float diff = FUN_00224fc0(cur, ang);
            float step = dt * params->turnRate;
            if (AbsBits(diff) <= step) {
                angle = ang;
            } else if (diff < 0.0f) {
                angle = cur - step;
            } else {
                angle = step + cur;
            }
        }
    }

    float r = target->xform.FUN_002220d0();
    float want = params->angleOffset + angle;
    if (params->followRate < 0.0f) {
        r = want;
    } else {
        float diff = FUN_00224fc0(r, want);
        float step = dt * params->followRate;
        if (AbsBits(diff) <= step) {
            r = want;
        } else if (diff < 0.0f) {
            r = r - step;
        } else {
            r = step + r;
        }
    }
    target->xform.FUN_00221d20(r);

    double fallNow = fall - dt * params->fallRate;
    fall = (float)fallNow;
    float limit = params->maxFall;
    if (limit <= 0.0f || limit > 200.0f) {
        limit = 200.0f;
    }
    limit = -limit;
    if (fallNow < limit) {
        fall = limit;
    }

    Vec3_19140 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    anchor->FUN_00059a50(&pos);
    pos.y = dt * fall + pos.y;
    target->xform.FUN_0022be40(&pos);
    return true;
}
