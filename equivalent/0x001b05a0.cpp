// STATUS: equivalent (tools/equiv.py level 3: 3060 inputs, branch coverage 127/134, incomplete)
// FUN_001b05a0 @ 0x001b05a0
#include "decls/address.h"
extern unsigned int DAT_004dc0e0;
extern unsigned int DAT_004dc0e4;
extern float DAT_004c3754;
extern float DAT_004c3758;
extern float DAT_004c375c;
extern float DAT_004c372c;
extern float DAT_004c3734;

struct V3_1b05a0 {
    float x, y, z;
    float FUN_0022d180();
};

float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
void __cdecl FUN_00224d70(float angle, V3_1b05a0 *axis);

static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

struct Tri_1b05a0 {
    char pad00[0x16];
    unsigned char b16;
    char pad17[0x18 - 0x17];
};

struct Mesh44 {
    char pad00[0x18];
    Tri_1b05a0 *tris;
};

struct Geo {
    char pad00[0x44];
    Mesh44 *f44;
    void FUN_001af890(V3_1b05a0 *out, int idx);
};

struct Entity;
struct Info_1b05a0 {
    char pad00[0x18];
    void *f18;
};

struct Contact_1b05a0 {
    char pad00[0xc];
    Info_1b05a0 *info;
    char pad10[4];
    int f14;
    V3_1b05a0 n;
    int f24;
    char pad28[4];
    V3_1b05a0 p;
    V3_1b05a0 q;
    char FUN_002f8e10(Geo **geo, unsigned int *idx);
};

struct Ent114Body {
    char pad00[8];
    unsigned int f8;
    unsigned int fc;
    char pad10[0x12c - 0x10];
    int f12c;
    char pad130[0x138 - 0x130];
    int f138;
    void FUN_00038e80(int a, void *hit, int b, V3_1b05a0 *p, V3_1b05a0 *n, int c);
};

struct Ent114 {
    char pad00[8];
    Ent114Body *f8;
    int kind;
};

struct Reg4c {
    char FUN_00079950(void *pos);
    int FUN_00079800(void *pos);
    void FUN_0007ba60(int i);
    float FUN_0007a820(int i);
    struct Sparks *FUN_0007ad00(void *pos);
};

struct Sparks {
    void FUN_00083320(V3_1b05a0 *q, V3_1b05a0 *n, int c, int d, V3_1b05a0 *z, int e);
};

struct Grid38 {
    void FUN_001f6cd0(Tri_1b05a0 *tri, void *hit, V3_1b05a0 *q, V3_1b05a0 *n, V3_1b05a0 *dir, int mode, float r1, float r2, int *out, int z);
};
struct Grid34 {
    void FUN_001ebea0(int a, Entity *e);
};

struct World {
    char pad00[0x20];
    struct Holder_1b05a0 *f20;
    char pad24[0x34 - 0x24];
    Grid34 *f34;
    Grid38 *f38;
    char pad3c[0x4c - 0x3c];
    Reg4c *f4c;
};

struct Holder_1b05a0 {
    char pad00[0x124];
    Entity *cur;
};

struct HitObj_1b05a0 {
    char pad00[0xc];
    int kind;
};

struct Body72 {
    char pad00[0x20];
    float f20;
    char pad24[0x34 - 0x24];
    float f34;
};

struct Obj1d72_1b05a0 {
    char pad00[0x50];
    V3_1b05a0 v50;
    char pad5c[0x6c - 0x5c];
    int f6c;
    struct Ob70 *f70;
    struct Ob74 *f74;
};
struct Ob74 {
    char pad00[0x20];
    Body72 *f20;
};
struct Ob70 {
    void FUN_0016fc60(V3_1b05a0 *out);
};

struct Chk {
    char FUN_001d4e40();
    int FUN_001d5e80(int a);
};

struct Dummy964 {
    float FUN_000787e0(int a, float b);
};
Dummy964 *__cdecl FUN_000964d0();


struct Entity {
    char pad00[8];
    char pos8[0x38];
    int f40;
    char pad44[0xec - 0x44];
    Chk *fec;
    char padf0[0x114 - 0xf0];
    Ent114 *f114;
    char pad118[0x12c - 0x118];
    int f12c;
    char pad130[0x134 - 0x130];
    int f134;
    char pad138[0x148 - 0x138];
    Entity *other;
    char b14c;
    char b14d;
    char pad14e[0x1c9 - 0x14e];
    char b1c9;
    char pad1ca[0x1fc - 0x1ca];
    int f1fc;
    char pad200[0x218 - 0x200];
    float f218;
    char pad21c[0x248 - 0x21c];
    int f248;
    char pad24c[0x334 - 0x24c];
    Entity *ign334;
    Entity *ign338;
    void FUN_001d6ac0(int a);
    char FUN_001d6a80();
    int FUN_001d64a0();
    char FUN_001d6980();
    V3_1b05a0 *FUN_001d6b40();
    V3_1b05a0 *FUN_001d6b30();
    void FUN_00035660(V3_1b05a0 *out);
    char FUN_000373d0();
    Obj1d72_1b05a0 *FUN_001d72e0();
    void FUN_001d6ad0(V3_1b05a0 *p);
    float FUN_001d8160();
    void FUN_0027d4f0(int a);
    void FUN_001d69f0(V3_1b05a0 *out);
    void FUN_001d8cd0();
    void FUN_001d7510();
    void FUN_001d6ec0(int a, int b, int c);
    void FUN_00038e80(int a, HitObj_1b05a0 *hit, int b, V3_1b05a0 *p, V3_1b05a0 *n, int c);
};

char __stdcall FUN_001b05a0(Entity *self, HitObj_1b05a0 *hit, Contact_1b05a0 *c)
{
#define world DAT_004dd700
    float tmpf;

    if (AbsF(c->n.y) <= 1e-05f) {
        if (c->q.y <= 0.2f) {
            Geo *B = 0;
            unsigned int A = 0;
            if (!c->FUN_002f8e10(&B, &A))
                return 1;
            Tri_1b05a0 *tri = &B->f44->tris[(unsigned short)A];
            float minV = 1000.0f;
            float maxV = -1000.0f;
            unsigned short *idx = (unsigned short *)((char *)tri + 0x10);
            for (int k = 0; k < 3; k++) {
                V3_1b05a0 out;
                B->FUN_001af890(&out, idx[k]);
                if (out.y < minV)
                    minV = out.y;
                if (out.y > maxV)
                    maxV = out.y;
            }
            if (!(maxV - minV > 1.0f))
                return 1;
        } else {
            self->FUN_001d6ac0(1);
        }
    }

    if (self->FUN_001d6a80())
        return 1;

    Entity *cur = (Entity *)world->f20->cur;
    Entity *other = self->other;
    bool toBlock;
    bool skipBlk = false;
    if (other != 0) {
        if (other == cur || other->ign338 == cur || other->ign334 == cur)
            skipBlk = true;
        toBlock = true;
    } else {
        toBlock = !self->fec->FUN_001d4e40();
    }
    if (toBlock && !skipBlk) {
        Geo *B = 0;
        unsigned int A = 0;
        if (c->FUN_002f8e10(&B, &A)) {
            Tri_1b05a0 *tri = &B->f44->tris[(unsigned short)A];
            if (tri->b16 & 8)
                return 1;
        }
    }
    if (other != 0 && other->FUN_000373d0()) {
        V3_1b05a0 p, n;
        if (hit != c->info->f18) {
            n.x = c->n.x * -1.0f;
            n.y = c->n.y * -1.0f;
            n.z = c->n.z * -1.0f;
            p = c->q;
        } else {
            p = c->p;
            n = c->n;
        }
        other->FUN_00038e80(other->f12c, hit, c->f14, &p, &n, c->f24);
        return 1;
    }

    if (self->f114 != 0) {
        if (self->f134 == 0 && self->FUN_001d64a0() != 5) {
            Ent114 *o = self->f114;
            if (o->kind == 1) {
                Ent114Body *X = o->f8;
                if (X->f8 == DAT_004dc0e0 && X->fc == DAT_004dc0e4 && !(X->f138 > 0))
                    X->FUN_00038e80(X->f12c, hit, c->f14, &c->q, &c->n, c->f24);
            }
        }
    }
    if (self->f114 == 0) {
        if (self->b14d)
            goto L5cb;
        if (self->FUN_001d6980())
            goto L5cb;
    }

    {
        Ent114Body *ebx = 0;
        if (self->f114 != 0 && self->f114->kind == 1) {
            ebx = self->f114->f8;
            if (ebx->f8 != DAT_004dc0e0 || ebx->fc != DAT_004dc0e4)
                ebx = 0;
        }
        char al = 0;
        if (self->b14c)
            al = world->f4c->FUN_00079950(&self->pos8);
        if (ebx == 0 && al != 0)
            goto L5cb;

        V3_1b05a0 *edi = self->FUN_001d6b40();
        V3_1b05a0 *eax = self->FUN_001d6b30();
        V3_1b05a0 v;
        v.x = eax->x - edi->x;
        v.y = eax->y - edi->y;
        v.z = eax->z - edi->z;
        float thr = 15.0f;
        double lenSq;
        if (ebx != 0) {
            V3_1b05a0 t;
            ((Entity *)ebx)->FUN_00035660(&t);
            lenSq = t.z * t.z + t.y * t.y + t.x * t.x;
            thr = 64.0f;
        } else {
            Obj1d72_1b05a0 *o = self->FUN_001d72e0();
            V3_1b05a0 *q = &o->v50;
            lenSq = q->z * q->z + q->y * q->y + q->x * q->x;
        }
        if (!(lenSq > thr))
            goto L5cb;
        if (!(v.z * v.z + v.y * v.y + v.x * v.x > 2.0f))
            goto L5cb;
        {
            Geo *B = 0;
            unsigned int A = 0;
            if (!c->FUN_002f8e10(&B, &A))
                goto L5cb;
            Tri_1b05a0 *tri = &B->f44->tris[(unsigned short)A];
            if (tri == 0)
                goto L5cb;
            if (tri->b16 & 8)
                goto L5cb;
            self->FUN_001d6ad0(self->FUN_001d6b40());
            float lo = 2.0f;
            float hi = 0.5f;
            float rr = self->FUN_001d8160() * 0.01f;
            rr = FUN_000186b0(&rr, &hi, &lo);
            V3_1b05a0 qv = c->q;
            V3_1b05a0 nv = c->n;
            V3_1b05a0 dir;
            if (self->fec->FUN_001d5e80(self->f40) == 3) {
                float ang = FUN_000964d0()->FUN_000787e0(0, 180.0f);
                dir.x = DAT_004c3754;
                dir.y = DAT_004c3758;
                dir.z = DAT_004c375c;
                FUN_00224d70(ang, &dir);
            } else {
                if (ebx != 0) {
                    ((Entity *)ebx)->FUN_00035660(&dir);
                } else {
                    Obj1d72_1b05a0 *o = self->FUN_001d72e0();
                    dir = o->v50;
                }
                dir.FUN_0022d180();
            }
            int out = 0;
            world->f38->FUN_001f6cd0(tri, hit, &qv, &nv, &dir, 8, rr, rr, &out, 0);
            world->f34->FUN_001ebea0(out, self);
        }
    }

L5cb:
    if (self->b1c9 && self->f1fc != 0) {
        if (self->fec->FUN_001d5e80(self->f40) == 4) {
            if (!(self->f218 < 10.0f))
                self->FUN_0027d4f0(9);
        }
    }
    if (hit->kind != 5 && self->b1c9) {
        Obj1d72_1b05a0 *o = self->FUN_001d72e0();
        V3_1b05a0 *q = &o->v50;
        if (q->z * q->z + q->y * q->y + q->x * q->x > 25.0f) {
            bool doIt = false;
            if (self->fec->FUN_001d5e80(self->f40) != 3) {
                doIt = true;
            } else {
                Obj1d72_1b05a0 *edi = self->FUN_001d72e0();
                V3_1b05a0 tv;
                tv.x = 0;
                tv.y = 0;
                tv.z = 0;
                if (edi->f70)
                    edi->f70->FUN_0016fc60(&tv);
                else
                    self->FUN_001d69f0(&tv);
                float h = 0.0f;
                if (edi->f74 && edi->f74->f20)
                    h = edi->f74->f20->f34;
                float P;
                if ((void *)edi == c->info->f18)
                    P = c->q.y;
                else
                    P = c->p.y;
                float D = P - (tv.y - h);
                if (!(h * 0.75f > D)) {
                    if (!(AbsF(c->n.y) > 0.3f))
                        doIt = true;
                }
            }
            if (doIt) {
                self->f248 = 1;
                self->FUN_001d8cd0();
            }
        }
    }

    if (self->b14c) {
        if (world->f4c->FUN_00079950(&self->pos8)) {
            if (!(AbsF(c->n.y - 1.0f) <= 1e-05f)) {
                self->FUN_001d7510();
                Reg4c *ebx = world->f4c;
                int edi = ebx->FUN_00079800(&self->pos8);
                if (edi != -1) {
                    ebx->FUN_0007ba60(edi);
                    if (ebx->FUN_0007a820(edi) > DAT_004c3734)
                        self->FUN_001d6ec0((int)DAT_004c372c, 0, 0);
                }
            }
        }
    }

    if (self->b14d) {
        void *edi = c->info->f18;
        V3_1b05a0 qq;
        if ((void *)self->FUN_001d72e0() == edi)
            qq = c->q;
        else
            qq = c->p;
        Sparks *sp = world->f4c->FUN_0007ad00(&self->pos8);
        if (sp) {
            V3_1b05a0 z;
            z.x = 0;
            z.y = 0;
            z.z = 0;
            sp->FUN_00083320(&qq, &c->n, c->f24, 0, &z, 0);
            if (self->FUN_001d72e0()->f6c == 0)
                return 1;
        }
    }
    self->FUN_0027d4f0(8);
    return 0;
}
