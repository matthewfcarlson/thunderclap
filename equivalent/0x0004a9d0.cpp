// STATUS: equivalent (tools/equiv.py level 3: 3051 inputs, branch coverage 42/42)
// CClimbEdgeCondition::vfunc_7 @ 0x0004a9d0
#include "decls/address.h"
struct Vec3_4a9d0 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_00011160(float scale, Vec3_4a9d0 *dir);
    void FUN_000111b0(Vec3_4a9d0 *a, Vec3_4a9d0 *b);
};

struct HitExtra_4a9d0 {
    int b;
    int c;
    int d;
    int e;
};

struct HitInfo_4a9d0 {
    char pad00[0x16];
    unsigned char flags16;
};

struct Limits_4a9d0 {
    char pad00[0x30];
    float half;
    float full;
};

struct Fighter_4a9d0 {
    char pad00[0x11c];
    Limits_4a9d0 *limits;
    char pad120[0x334 - 0x120];
    void *attach334;
    void *attach338;
    char pad33c[0x1af8 - 0x33c];
    Vec3_4a9d0 facing;
    unsigned int contact;
    char FUN_00038de0(Vec3_4a9d0 *from, Vec3_4a9d0 *to, int a, int foreign, HitExtra_4a9d0 *outB, Vec3_4a9d0 *outN, int c, HitInfo_4a9d0 **hit);
};

struct Owner_4a9d0 {
    Fighter_4a9d0 *FUN_00059a30();
    char FUN_00059a50(Vec3_4a9d0 *out);
};

struct Params {
    Owner_4a9d0 *FUN_000592a0();
};

struct Holder_4a9d0 {
    char pad00[0x124];
    void *current;
};

struct World {
    char pad00[0x20];
    Holder_4a9d0 *holder;
};


class CClimbEdgeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Params *params);
    char pad04[8];
    int type;
    char checkSweep;
};

bool CClimbEdgeCondition::vfunc_7(Params *params)
{
    if (type < 0 || type >= 6) {
        return false;
    }
    Owner_4a9d0 *owner = params->FUN_000592a0();
    Fighter_4a9d0 *f = owner->FUN_00059a30();
    unsigned int contact = f->contact;
    if (type == 4) {
        return (contact & 0xf) == 0xf;
    }
    if (type == 5) {
        return contact == 0;
    }
    if (!(contact & (1 << type))) {
        return false;
    }
    if (!checkSweep) {
        return true;
    }
    Limits_4a9d0 *lim = f->limits;
    if (lim == 0) {
        return false;
    }
    float h = lim->half;
    float m = lim->full;
    Vec3_4a9d0 v = f->facing;
    v.y = 0.0f;
    v.FUN_0022d110();

    Vec3_4a9d0 d;
    Vec3_4a9d0 w;
    switch (type) {
    case 0:
        d.y = 1.0f;
        d.x = 0.0f;
        d.z = 0.0f;
        h = h * 0.5f;
        break;
    case 3:
        d.y = -1.0f;
        d.x = 0.0f;
        d.z = 0.0f;
        h = h * 0.5f;
        break;
    case 1:
        w.y = 1.0f;
        w.x = 0.0f;
        w.z = 0.0f;
        d.FUN_000111b0(&w, &v);
        h = m;
        break;
    case 2:
        w.y = -1.0f;
        w.x = 0.0f;
        w.z = 0.0f;
        d.FUN_000111b0(&w, &v);
        h = m;
        break;
    default:
        return false;
    }

    Vec3_4a9d0 nv;
    nv.x = v.x * -1.0f;
    nv.y = v.y * -1.0f;
    nv.z = v.z * -1.0f;
    Vec3_4a9d0 pos;
    if (!owner->FUN_00059a50(&pos)) {
        return false;
    }
    pos.FUN_00011160(m, &v);

    float twoH = h + h;
    Vec3_4a9d0 e;
    e.x = pos.x + d.x * twoH;
    e.y = pos.y + d.y * twoH;
    e.z = pos.z + d.z * twoH;

    int foreign = 0;
    void *cur = DAT_004dd700->holder->current;
    if (f != cur && f->attach338 != cur && f->attach334 != cur) {
        foreign = 1;
    }
    Vec3_4a9d0 hitN;
    HitExtra_4a9d0 hitB;
    HitInfo_4a9d0 *hit;
    if (f->FUN_00038de0(&pos, &e, 0, foreign, &hitB, &hitN, 0, 0)) {
        return false;
    }
    float twoM = m + m;
    Vec3_4a9d0 p;
    p.x = nv.x * twoM + e.x;
    p.y = nv.y * twoM + e.y;
    p.z = nv.z * twoM + e.z;
    if (f->FUN_00038de0(&e, &p, 0, foreign, &hitB, &hitN, 0, 0)) {
        return false;
    }
    float back = h * -2.0f;
    e = p;
    p.x = d.x * back + e.x;
    p.y = d.y * back + e.y;
    p.z = d.z * back + e.z;
    hit = 0;
    if (!f->FUN_00038de0(&e, &p, 0, foreign, &hitB, &hitN, 0, &hit)) {
        return false;
    }
    if (hit != 0 && (hit->flags16 & 0x10)) {
        return false;
    }
    return !(hitN.x * d.x + (hitN.y * d.y + hitN.z * d.z) < 0.8f);
}
