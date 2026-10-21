// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 18/18)
// hulkfight::ai::HasGroundPointExtendedCondition::vfunc_6 @ 0x00118050
#include "decls/address.h"
#include "compat/ptr.h"
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct V3_118050 {
    float x, y, z;
};

struct Body_118050 {
    char pad00[0x40];
    V3_118050 pos;
};

struct Locator {
    char FUN_00059a50(V3_118050 *out);
};

struct Res_118050 {
    char pad00[0x10];
    Locator *loc;
    char pad14[0x328 - 0x14];
    Body_118050 *body;
    char pad32c[0x2064 - 0x32c];
    V3_118050 vel;
};

struct Resolver_118050 {
    Res_118050 *FUN_00059a30();
};

struct Target_118050 {
    Resolver_118050 *FUN_000592a0();
};

struct Hit_118050 {
    char pad00[0x16];
    unsigned short info;
};

struct Slot_118050 {
    void FUN_00025260(int a, int b, int c);
};

struct Mgr_118050 {
    void FUN_001dcf60(int a);
};

struct World {
    char pad00[0xc];
    Mgr_118050 *mgr;
    char pad10[0x20 - 0x10];
    Slot_118050 *slot;
};


extern char __cdecl FUN_00202560(V3_118050 *from, float dist, int flag, V3_118050 *outA, V3_118050 *outB, int p6, int p7, Hit_118050 **outHit);
extern V3_118050 *__cdecl FUN_00083e00(V3_118050 *out, V3_118050 *in, float s);

struct Frame_118050 {
    V3_118050 pos;
    V3_118050 w;
    V3_118050 tmp;
    V3_118050 outA;
    V3_118050 ret;
    V3_118050 outB;
};

class HasGroundPointExtendedCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, void *obj, int c);
    char pad04[9];
    char useVel;
    char pad0e;
    char useBody;
    char useScaled;
    char useAbs;
    char pad12[2];
    float scale;
    float limit;
    V3_118050 dir;
};

char HasGroundPointExtendedCondition::vfunc_6(int a, void *obj, int c)
{
    Frame_118050 f;
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Res_118050 *r = ((Target_118050 *)obj)->FUN_000592a0()->FUN_00059a30();
    if (!r)
        return 0;
    if (!useBody) {
        r->loc->FUN_00059a50(&f.pos);
    } else {
        Body_118050 *body = r->body;
        if (!body)
            return 0;
        f.pos = body->pos;
    }
    Hit_118050 *hit = 0;
    if (useVel) {
        hulk_freg s = scale;
        f.tmp.x = s * r->vel.x;
        f.tmp.y = s * r->vel.y;
        f.tmp.z = s * r->vel.z + f.pos.z;
        f.w.z = f.tmp.z;
        f.w.x = f.tmp.x + f.pos.x;
        f.w.y = f.tmp.y + f.pos.y;
    } else if (useScaled) {
        f.tmp = dir;
        V3_118050 *p = FUN_00083e00(&f.ret, &f.tmp, scale);
        f.tmp.z = f.pos.z + p->z;
        f.w.z = f.tmp.z;
        f.w.x = f.pos.x + p->x;
        f.w.y = f.pos.y + p->y;
    }
    DAT_004dd700->slot->FUN_00025260(0, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(0);
    char found = FUN_00202560(&f.w, 20.0f, 1, &f.outA, &f.outB, 0, 0, &hit);
    DAT_004dd700->slot->FUN_00025260(1, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(1);
    if (found) {
        hulk_freg v = f.outA.y - f.w.y;
        if (useAbs) {
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = v;
            bits.u &= 0x7fffffff;
            v = bits.f;
        }
        if (!(v < limit))
            return 0;
    }
    return 1;
}
