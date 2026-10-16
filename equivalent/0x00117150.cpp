// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 29/30, incomplete)
// hulkfight::ai::MotionBoostAction::vfunc_5 @ 0x00117150
#include "decls/address.h"
struct V3_117150 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(V3_117150 *p, float eps);
};

class RefCounted_117150 {
public:
    virtual void addRef();
    virtual void release();
};

struct ActionParams_117150 {
    char pad00[0x14];
    float limit;             // 0x14
    char pad18[0x24 - 0x18];
    unsigned int extra;      // 0x24
};

struct Camera {
    void FUN_00059a50(V3_117150 *out);
};

struct Other_117150 {
    char pad[0x1b0];
    int id;
};

struct Reg124_117150 {
    char pad00[0x11c];
    Other_117150 *other;            // 0x11c
    char pad120[0x12c - 0x120];
    RefCounted_117150 *target;      // 0x12c
};

struct Reg20_117150 {
    char pad[0x124];
    Reg124_117150 *p124;
};

struct World {
    char pad[0x20];
    Reg20_117150 *p20;
};

extern unsigned int DAT_004e0ca4;
extern V3_117150 DAT_004e0c98;

struct Pad_117150 {
    char pad00[0x10];
    Camera *camera;          // 0x10
    char pad14[0x11c - 0x14];
    Other_117150 *other;            // 0x11c
    char pad120[0x328 - 0x120];
    RefCounted_117150 *lock;        // 0x328
    char pad32c[0x2064 - 0x32c];
    float push[3];           // 0x2064
    unsigned int pushExtra;  // 0x2070
    char pad2074[0x20a8 - 0x2074];
    int f20a8;
    void FUN_0003ffa0(RefCounted_117150 *t, int flag);
    void FUN_000353d0(V3_117150 *from);
};

struct Fighter_117150 {
    Pad_117150 *FUN_00059a30();
};

struct Owner20_117150 {
    Fighter_117150 *FUN_000592a0();
};

class MotionBoostAction {
public:
    virtual void v0();
    char pad04[0x1c - 4];
    ActionParams_117150 *params;    // 0x1c
    Owner20_117150 *owner;          // 0x20
    RefCounted_117150 *held;        // 0x24
    V3_117150 pos;                  // 0x28

    char FUN_00117150(int a, int b);
};


char MotionBoostAction::FUN_00117150(int a, int b)
{
    if (a != 0)
        return 1;
    if (owner == 0)
        return 0;

    if (!(DAT_004e0ca4 & 1))
        DAT_004e0ca4 |= 1;
    DAT_004e0c98.z = 0.0f;
    DAT_004e0c98.y = 0.0f;
    DAT_004e0c98.x = 0.0f;
    if (pos.FUN_0022d2b0(&DAT_004e0c98, 1e-5f))
        return 0;

    Pad_117150 *pad = owner->FUN_000592a0()->FUN_00059a30();
    RefCounted_117150 *target = pad->lock;
    if (target == 0) {
        target = held;
        if (target == 0) {
            if (pad->f20a8 >= 0)
                return 1;
            if (pad->other == 0)
                return 1;
            Reg124_117150 *r = DAT_004dd700->p20->p124;
            if (r == 0)
                return 1;
            target = r->target;
            if (target == 0)
                return 1;
            if (r->other == 0)
                return 1;
            if (pad->other->id == r->other->id)
                return 1;
            pad->FUN_0003ffa0(target, 0);
        }
    }
    if (target != 0)
        target->addRef();
    if (held != 0)
        held->release();
    held = target;

    V3_117150 camPos;
    camPos.x = 0.0f;
    camPos.y = 0.0f;
    camPos.z = 0.0f;
    pad->camera->FUN_00059a50(&camPos);

    V3_117150 d;
    d.x = pos.x - camPos.x;
    d.y = pos.y - camPos.y;
    d.z = pos.z - camPos.z;
    float len = d.FUN_0022d110();
    float ex = d.x * -1.0f;
    ActionParams_117150 *pr = params;
    unsigned int extra = pr->extra;
    float ey = d.y * -1.0f;
    float ez = d.z * -1.0f;
    if (len < pr->limit)
        return 0;
    pad->push[0] = ex;
    pad->push[1] = ey;
    pad->push[2] = ez;
    pad->pushExtra = extra;
    pad->FUN_000353d0(&pos);
    return 1;
}
