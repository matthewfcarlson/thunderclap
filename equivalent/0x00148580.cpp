// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 23/24, incomplete)
// FUN_00148580 @ 0x00148580
#include "decls/data/game/hulkfight/motion.h"

struct Vec3_148580 { float x, y, z; };

class RefCounted_148580 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

struct Stats_148580 {
    char pad0[0x12c];
    RefCounted_148580 *ref;
    char pad130[0x334 - 0x130];
    Stats_148580 *altTarget;
    Stats_148580 *target;
    char pad33c[0x1e58 - 0x33c];
    float blend;
    float FUN_000354c0();
};

struct Params {
    char pad0[0x10];
    int f10;
    int f14;
    float f18;
    char pad1c[4];
    int f20;
    int f24;
    float f28;
    float f2c;
    int f30;
    unsigned char f34;
    char pad35[3];
    union {
        float f38;
        int f38i;
    };
    int f3c;
    float f40;
    int f44;
    float f48;
    int f4c;
    int f50;
};

struct Effect_148580 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    char pad14[4];
    Vec3_148580 dir;
    unsigned char f24;
    char pad25[0x4c - 0x25];
    RefCounted_148580 *ref4c;
    RefCounted_148580 *ref50;
    int f54;
    int f58;
    char pad5c[0x68 - 0x5c];
    int f68;
    char pad6c[0x74 - 0x6c];
    int f74;
    float f78;
    void FUN_000595f0(Vec3_148580 *dir, int a, float b, int c);
};

void *__fastcall FUN_000592a0(void *owner);
Stats_148580 *__fastcall FUN_00059a30(void *x);
extern "C" void FUN_00224d70(float v, Vec3_148580 *dir);

// equiv-conv: FUN_00148580 ecx esi edi
bool FUN_00148580(void *owner, Effect_148580 *fx, Params *p)
{
    if (owner == 0)
        return false;
    Stats_148580 *s = FUN_00059a30(FUN_000592a0(owner));
    if (s == 0)
        return false;

    Stats_148580 *t = s->target;
    if (t == 0) {
        t = s->altTarget;
        if (t == 0)
            return false;
    }

    RefCounted_148580 *r = t->ref;
    if (r)
        r->vfunc_0();
    if (fx->ref4c)
        fx->ref4c->vfunc_1();
    fx->ref4c = r;

    r = s->ref;
    if (r)
        r->vfunc_0();
    if (fx->ref50)
        fx->ref50->vfunc_1();
    fx->ref50 = r;

    fx->f74 = p->f10;
    fx->f10 = 0;
    fx->fc = 0;
    fx->f8 = 0;

    float v = s->FUN_000354c0();
    if (p->f14 == 0)
        v = t->FUN_000354c0();
    fx->dir = (*(Vec3_148580*)&DAT_004ae358);
    FUN_00224d70(v + p->f18, &fx->dir);

    fx->f0 = p->f20;
    fx->f4 = p->f24;
    fx->f54 = p->f30;
    fx->f24 = p->f34;
    fx->f58 = p->f38i;
    float x = p->f28;
    fx->f78 = x;
    if (x < p->f2c)
        fx->f78 = (p->f2c - x) * t->blend + x;
    fx->f68 = p->f50;

    float w = p->f48;
    if (w < 0.0f)
        w = p->f38;

    v = s->FUN_000354c0();
    if (p->f3c == 0)
        v = t->FUN_000354c0();
    Vec3_148580 dir2 = (*(Vec3_148580*)&DAT_004ae358);
    FUN_00224d70(v + p->f40, &dir2);
    fx->FUN_000595f0(&dir2, p->f44, w, p->f4c);
    return true;
}
