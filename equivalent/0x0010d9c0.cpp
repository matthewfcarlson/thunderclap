// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 24/24)
// hulkfight::ai::OnBlockedTriangleCondition::vfunc_6 @ 0x0010d9c0
#include "decls/address.h"
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Vec3_10d9c0 {
    float x, y, z;
};

struct Body_10d9c0 {
    char pad00[0x40];
    Vec3_10d9c0 pos;
};

struct Locator {
    char FUN_00059a50(Vec3_10d9c0 *out);
};

struct Res_10d9c0 {
    char pad00[0x10];
    Locator *loc;
    char pad14[0x328 - 0x14];
    Body_10d9c0 *body;
};

struct Resolver_10d9c0 {
    Res_10d9c0 *FUN_00059a30();
};

struct Target_10d9c0 {
    Resolver_10d9c0 *FUN_000592a0();
};

struct Hit_10d9c0 {
    char pad00[0x16];
    unsigned short info;
};

struct Slot_10d9c0 {
    void FUN_00025260(int a, int b, int c);
};

struct Mgr_10d9c0 {
    void FUN_001dcf60(int a);
};

struct World {
    char pad00[0xc];
    Mgr_10d9c0 *mgr;
    char pad10[0x20 - 0x10];
    Slot_10d9c0 *slot;
};


extern char __cdecl FUN_00202560(Vec3_10d9c0 *from, float dist, int flag, Vec3_10d9c0 *outA, Vec3_10d9c0 *outB, int p6, int p7, Hit_10d9c0 **outHit);

class OnBlockedTriangleCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, void *obj, int c);
    char pad04[8];
    int op;
    char useBody;
    char pad11[3];
    unsigned short value;
};

char OnBlockedTriangleCondition::vfunc_6(int a, void *obj, int c)
{
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Res_10d9c0 *r = ((Target_10d9c0 *)obj)->FUN_000592a0()->FUN_00059a30();
    if (!r)
        return 0;
    Vec3_10d9c0 pos;
    if (!useBody) {
        r->loc->FUN_00059a50(&pos);
    } else {
        Body_10d9c0 *body = r->body;
        if (!body)
            return 0;
        pos = body->pos;
    }
    Hit_10d9c0 *hit = 0;
    DAT_004dd700->slot->FUN_00025260(0, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(0);
    pos.y = pos.y + 5.0f;
    Vec3_10d9c0 outB;
    Vec3_10d9c0 outA;
    char found = FUN_00202560(&pos, 20.0f, 1, &outA, &outB, 0, 0, &hit);
    DAT_004dd700->slot->FUN_00025260(1, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(1);
    if (!found || !hit)
        return 1;
    unsigned short got = (unsigned short)(hit->info >> 13);
    unsigned short want = value;
    switch (op) {
    case 0: return got < want;
    case 1: return got <= want;
    case 2: return got == want;
    case 3: return got != want;
    case 4: return got >= want;
    case 5: return got > want;
    }
    return 0;
}
