// STATUS: equivalent (tools/equiv.py level 3: 20028 inputs, branch coverage 30/30)
// FUN_001958c0 @ 0x001958c0
// FUN_001958c0 @ 0x001958c0
#include "decls/address.h"
struct V3_1958c0 {
    float x, y, z;
};

struct Tag_1958c0 {
    char pad00[0x1b0];
    int kind;
};

struct Ref12c {
    char pad00[0x12c];
    int id;
};

struct Entity {
    char pad00[0x114];
    int f114;
    char pad118[0x148 - 0x118];
    Ref12c *f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    float f19c;
    bool FUN_001d6980();
    void FUN_001d82d0();
    bool FUN_001d7300();
    void FUN_001d6ec0(int a, int b, int c);
    void FUN_001d86d0(V3_1958c0 *v, int a);
};

struct Info_1958c0 {
    char pad00[0x11c];
    Tag_1958c0 *tag;
    char pad120[0x128 - 0x120];
    Entity *f128;
    int f12c;
    Entity *FUN_00035ef0(int i);
};

struct Scale_1958c0 {
    float FUN_001dddf0();
};

struct Mgr_1958c0 {
    Info_1958c0 *FUN_00059c10(int id);
};

struct World {
    char pad00[0xc];
    Scale_1958c0 *scale;
    char pad10[0x44 - 0x10];
    Mgr_1958c0 *mgr;
};

struct Holder_1958c0 {
    char pad00[8];
    Entity *entity;
    char pad0c[0x70 - 0xc];
    int f70;
};


// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
extern bool FUN_00195560(V3_1958c0 *a6, int a0, int a4, int id, int a2, int a3, int a5, float a7, float a8, int a9, int a10, int z0, float one, int z1);

// equiv-conv: FUN_001958c0 eax stack stack stack stack stack stack stack stack stack stack
bool FUN_001958c0(int id, Holder_1958c0 *h, int a2, int a3, int a4, int a5, V3_1958c0 *a6, float a7, float a8, int a9, int a10)
{
    Entity *e = h->entity;
    if (!e)
        return false;
    if (e->f148)
        return FUN_00195560(a6, e->f148->id, a4, id, a2, a3, a5, a7, a8, a9, a10, 0, 1.0f, 0);

    Info_1958c0 *p = DAT_004dd700->mgr->FUN_00059c10(id);
    if (p) {
        if (e == p->f128)
            return false;
        for (int i = 0; i < 8; i++) {
            if (e == p->FUN_00035ef0(i))
                return false;
        }
        int kind = p->tag->kind;
        if (e->f198 == kind)
            a8 = a8 * e->f19c;
        if (kind == 2)
            a8 = DAT_004dd700->scale->FUN_001dddf0() * a8;
    }
    if (e->FUN_001d6980())
        return false;
    e->FUN_001d82d0();
    if (a8 > 0.0f) {
        Info_1958c0 *q = DAT_004dd700->mgr->FUN_00059c10(id);
        int v = q ? q->f12c : 0;
        e->FUN_001d6ec0((int)a8, v, 0);
    }
    if (e->FUN_001d7300() && e->f114 == 0 && h->f70 != 0 && a7 != 0.0f) {
        V3_1958c0 v = *a6;
        v.x = v.x * a7;
        v.y = v.y * a7;
        v.z = v.z * a7;
        e->FUN_001d86d0(&v, a4);
    }
    return true;
}
