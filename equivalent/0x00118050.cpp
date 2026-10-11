// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// hulkfight::ai::HasGroundPointExtendedCondition::vfunc_6 @ 0x00118050
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct V3 {
    float x, y, z;
};

struct Body {
    char pad00[0x40];
    V3 pos;
};

struct Locator {
    char FUN_00059a50(V3 *out);
};

struct Res {
    char pad00[0x10];
    Locator *loc;
    char pad14[0x328 - 0x14];
    Body *body;
    char pad32c[0x2064 - 0x32c];
    V3 vel;
};

struct Resolver {
    Res *FUN_00059a30();
};

struct Target {
    Resolver *FUN_000592a0();
};

struct Hit {
    char pad00[0x16];
    unsigned short info;
};

struct Slot {
    void FUN_00025260(int a, int b, int c);
};

struct Mgr {
    void FUN_001dcf60(int a);
};

struct Game {
    char pad00[0xc];
    Mgr *mgr;
    char pad10[0x20 - 0x10];
    Slot *slot;
};

extern Game *DAT_004dd700;

extern char __cdecl FUN_00202560(V3 *from, float dist, int flag, V3 *outA, V3 *outB, int p6, int p7, Hit **outHit);
extern V3 *__cdecl FUN_00083e00(V3 *out, V3 *in, float s);

struct Frame {
    V3 pos;
    V3 w;
    V3 tmp;
    V3 outA;
    V3 ret;
    V3 outB;
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
    V3 dir;
};

char HasGroundPointExtendedCondition::vfunc_6(int a, void *obj, int c)
{
    Frame f;
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Res *r = ((Target *)obj)->FUN_000592a0()->FUN_00059a30();
    if (!r)
        return 0;
    if (!useBody) {
        r->loc->FUN_00059a50(&f.pos);
    } else {
        Body *body = r->body;
        if (!body)
            return 0;
        f.pos = body->pos;
    }
    Hit *hit = 0;
    if (useVel) {
        float s = scale;
        f.tmp.x = s * r->vel.x;
        f.tmp.y = s * r->vel.y;
        f.tmp.z = s * r->vel.z + f.pos.z;
        f.w.z = f.tmp.z;
        f.w.x = f.tmp.x + f.pos.x;
        f.w.y = f.tmp.y + f.pos.y;
    } else if (useScaled) {
        f.tmp = dir;
        V3 *p = FUN_00083e00(&f.ret, &f.tmp, scale);
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
        float v = f.outA.y - f.w.y;
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
