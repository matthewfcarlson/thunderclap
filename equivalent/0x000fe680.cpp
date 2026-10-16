// STATUS: equivalent (tools/equiv.py level 3: 112 inputs, branch coverage 47/48, incomplete)
// CCharacterGolem::vfunc_3 @ 0x000fe680
#include "decls/address.h"
extern float DAT_0040d0f4;
extern float DAT_0040d0e8;
extern bool DAT_004e0a98;

extern "C" double sqrt(double);

struct V3_fe680 {
    float x, y, z;
};

struct Rng_fe680 {
    float FUN_00078780();
};
Rng_fe680 *FUN_000964d0();

struct Slot_fe680 {
    char pad0[8];
    int f08;
    int f0c;
    char pad10[0x30];
    V3_fe680 pos;
};

struct Link_fe680 {
    char pad0[0x12c];
    Slot_fe680 *slot;
};

struct Part54_fe680 {
    void FUN_00086310();
};

struct Target_fe680;

struct Sub20_fe680 {
    bool FUN_00025d30(Target_fe680 *t);
    bool FUN_00024300(Target_fe680 *t);
    Link_fe680 *FUN_00024280(unsigned __int64 id);
};

struct Entity {
    char pad0[0x20];
    Sub20_fe680 *sub20;
    char pad24[0x30];
    Part54_fe680 *part54;
};

struct Skel_fe680 {
    void FUN_00059a50(V3_fe680 *out);
};

struct Target_fe680 {
    char pad0[0x10];
    Skel_fe680 *skel;
    char pad14[0x1ccc];
    int f1ce0;
    int f1ce4;
    bool FUN_00042990(Entity *e, Slot_fe680 *q, float range, char *outB, char *outA);
};

struct PState {
    char pad0[8];
    Slot_fe680 *slot;         // 8
    char padc[6];
    char b12;
    char b13;
    float f14;
    float f18;
    char pad1c[0x18];
    float f34;
    V3_fe680 qpos;            // 0x38
    char b44;
    char b45;
    char b46;
    char pad47[0x9c - 0x47];
    void FUN_000fe300(V3_fe680 *p, int found, int a, int b, float dt);
    void FUN_000fdf20();
};

class CCharacterGolem {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Entity *a1, float dt);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual Target_fe680 *vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int v);
    virtual int vfunc_9();
    char pad4[0x54];
    PState p;           // 0x58
    char flagF4;
    char padf5[0x2f];
    float f124;
    char pad128[4];
    float f12c;
};

void CCharacterGolem::vfunc_3(Entity *a1, float dt)
{
    Target_fe680 *t = vfunc_6();
    a1->part54->FUN_00086310();
    if (!a1->sub20->FUN_00025d30(t)) {
        float x = dt + f12c;
        f12c = x;
        if (x < DAT_0040d0f4)
            return;
        dt = x;
        f12c = 0;
    }
    if (flagF4 != 0)
        return;
    struct Frame {
        char pad10[2];
        char b12;
        char b13;
        char found;
        char pad15[3];
        float dist;
        Rng_fe680 *rng;
        V3_fe680 qpos;
        V3_fe680 pos0;
    } fr;
    PState *ps = &p;
    fr.rng = FUN_000964d0();
    if (DAT_004e0a98 && t != 0) {
        Sub20_fe680 *s20 = a1->sub20;
        unsigned __int64 id = FUN_002672f0("hulk", 0, 0);
        ps->slot = s20->FUN_00024280(id)->slot;
    }
    Slot_fe680 *q = ps->slot;
    if (q != 0 && t != 0) {
        t->skel->FUN_00059a50(&fr.pos0);
        fr.qpos = q->pos;
        float dx = fr.qpos.x - fr.pos0.x;
        float dy = fr.qpos.y - fr.pos0.y;
        float dz = fr.qpos.z - fr.pos0.z;
        fr.dist = (float)sqrt((double)(dz * dz + dy * dy + dx * dx));
        bool near = false;
        if (t->FUN_00042990(a1, q, 100.0f, &fr.b12, &fr.b13)) {
            if (vfunc_9() != 0 || fr.dist < 3.0f)
                near = true;
        }
        fr.found = 0;
        if (near) {
            if (fr.dist <= 100.0f) {
                fr.found = 1;
                if (ps->b12 == 0 && ps->f14 > 3.0f)
                    f124 = 0;
            }
        }
        float rem = f124 - dt;
        f124 = rem;
        if (rem <= 0.0f && !a1->sub20->FUN_00024300(t))
            f124 = (fr.rng->FUN_00078780() + 1.0f) * DAT_0040d0e8;
        if (q->f0c == 1 && q->f08 != 0) {
            ps->b44 = 1;
            if (fr.found) {
                ps->b45 = 1;
                if (vfunc_9() < 3)
                    vfunc_8(3);
            }
        } else {
            ps->b44 = 0;
        }
        ps->FUN_000fe300(&fr.qpos, *(int *)&fr.found, t->f1ce0, t->f1ce4, dt);
        if (fr.found)
            ps->b45 = 1;
        if (ps->b13 != fr.b12) {
            ps->f18 = 0;
            ps->b13 = fr.b12;
        }
        ps->qpos = fr.qpos;
        ps->f34 = 0;
        if (vfunc_9() < 2)
            vfunc_8(2);
        if (ps->b46)
            ps->FUN_000fdf20();
    }
    ps->f14 = dt + ps->f14;
    ps->f34 = dt + ps->f34;
}
