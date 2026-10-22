// STATUS: equivalent (tools/equiv.py level 3: 19992 inputs, branch coverage 32/32)
// hulkfight::motion::FireProjectileAction::vfunc_5 @ 0x0019ae50
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "compat/ptr.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct V3_19ae50 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3_19ae50 *other, float limit);
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_19ae50 *axis, float angle);
    void FUN_0022ca90(const Matrix *src, void *arg);
    void FUN_0022c2b0(const V3_19ae50 *in, V3_19ae50 *out);
    void FUN_0022c3b0(const V3_19ae50 *in, V3_19ae50 *out);
};

class Refd_19ae50 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Pool_19ae50 {
    int FUN_001b6b00(int id, V3_19ae50 *a);
    void FUN_001b6d00(int id, class ProjectileEffect_19ae50 *p);
};

struct World {
    char pad0[0x14];
    Pool_19ae50 *pool;
};

struct Allocator {
    void *FUN_0008fe90(unsigned int size);
};

struct Cfg_19ae50 {
    char pad0[0x2c];
    float f2c;
    char pad30[0x40 - 0x30];
    V3_19ae50 v40;
    V3_19ae50 v4c;
    float f58;
    float f5c;
    char pad60[0x68 - 0x60];
    int f68;
    int f6c;
    char pad70[0x74 - 0x70];
    char b74;
    char pad75[7];
    int f7c;
};

class ProjectileEffect_19ae50 : public Refd_19ae50 {
public:
    char pad04[0x14 - 4];
    int f14;
    char pad18[0x20 - 0x18];
    void *f20;
    Refd_19ae50 *f24;
    V3_19ae50 f28;
    V3_19ae50 f34;
    V3_19ae50 f40;
    float f4c;
    ProjectileEffect_19ae50 *FUN_00195a90(Cfg_19ae50 *cfg);
};

struct Target_19ae50 : Refd_19ae50 {
};

struct Ctx_19ae50;

struct Stats_19ae50 {
    char pad0[0x328];
    Target_19ae50 *target;
    Target_19ae50 *FUN_00039c60(V3_19ae50 *a, V3_19ae50 *b, int lo, int hi, int z1, int z2, int z3);
};

struct Ctx_19ae50 {
    Stats_19ae50 *FUN_00059a30();
    char FUN_00059a50(V3_19ae50 *out);
};

struct OwnerObj_19ae50 {
    char pad0[8];
    void *f8;
    Ctx_19ae50 *FUN_000592a0();
};

struct Rng_19ae50 {
    float FUN_000787e0(int lo, int hi);
};
Rng_19ae50 *FUN_000964d0();

class Weapon_19ae50 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void *v15();
};

struct Ctrl_19ae50 {
    char pad0[0x1c];
    char *mats;
};

char __cdecl FUN_00096b50(Target_19ae50 *t, V3_19ae50 *c, void *out);

union Slot_19ae50 {
    int i;
    float f;
    unsigned int u;
};

class FireProjectileAction {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vfunc_5(int a1, Slot_19ae50 a2);
    char pad04[0x18];
    Cfg_19ae50 *cfg;
    OwnerObj_19ae50 *owner;
    float f24;
    Weapon_19ae50 *f28;
    Ctrl_19ae50 *f2c;
    int f30;
};

bool FireProjectileAction::vfunc_5(int a1, Slot_19ae50 a2)
{
    struct Frame {
        V3_19ae50 b;
        V3_19ae50 a;
        float period;
        float r1;
        V3_19ae50 bm;
        Pool_19ae50 *pool;
        V3_19ae50 P;
        V3_19ae50 c;
        int s48;
        int s4c;
        Stats_19ae50 *fighter;
        float r2;
        Ctx_19ae50 *ctx;
        V3_19ae50 tmp;
        V3_19ae50 zv;
        V3_19ae50 tmp3;
        V3_19ae50 tmp2;
        int out;
        V3_19ae50 v;
        Matrix M;
        Matrix M2;
        Matrix M3;
    } f;

    if (a1 != 1)
        return true;
    f.pool = DAT_004dd700->pool;
    f.ctx = owner->FUN_000592a0();
    f.fighter = f.ctx->FUN_00059a30();
    double sum = (double)a2.f + f24;
    f24 = (float)sum;
    Cfg_19ae50 *c0 = cfg;
    if (c0->f2c > 0.0f)
        f.period = (float)(1.0 / c0->f2c);
    else
        f.period = a2.f;
    if (!(sum > f.period))
        return true;

    do {
        Ctrl_19ae50 *ctrl = f2c;
        f24 = (float)((double)f24 - f.period);
        f.a.z = 0.0f;
        f.a.y = 0.0f;
        f.a.x = 0.0f;
        f.b.x = 0.0f;
        f.b.y = 0.0f;
        f.b.z = -1.0f;
        if (ctrl != 0) {
            int idx6 = f30 << 6;
            Weapon_19ae50 *w = f28;
            if (w != 0) {
                const Matrix *src = (const Matrix *)(ctrl->mats + idx6);
                f.M.FUN_0022ca90(src, w->v15());
            } else {
                memcpy(&f.M, ctrl->mats + idx6, sizeof(Matrix));
            }
            f.tmp = cfg->v40;
            f.M.FUN_0022c2b0(&f.tmp, &f.a);
            f.tmp2 = cfg->v4c;
            f.M.FUN_0022c3b0(&f.tmp2, &f.b);
            f.b.FUN_0022d110();
        }
        int id = cfg->f7c;
        int slot = f.pool->FUN_001b6b00(id, &f.a);
        if (slot >= 0) {
            void *mem = (*(Allocator*)&DAT_004e2210).FUN_0008fe90(0x50);
            ProjectileEffect_19ae50 *proj;
            if (mem)
                proj = ((ProjectileEffect_19ae50 *)mem)->FUN_00195a90(cfg);
            else
                proj = 0;
            proj->AddRef();
            proj->f20 = owner->f8;
            proj->f14 = id;
            Target_19ae50 *tgt = f.fighter->target;
            if (tgt == 0) {
                Cfg_19ae50 *c1 = cfg;
                tgt = f.fighter->FUN_00039c60(&f.a, &f.b, c1->f68, c1->f6c, 0, 0, 0);
                if (tgt != 0)
                    tgt->AddRef();
            } else {
                tgt->AddRef();
            }
            if (proj->f24 != 0)
                proj->f24->Release();
            proj->f24 = tgt;
            if (tgt != 0) {
                if (cfg->b74) {
                    if (FUN_00096b50(tgt, &f.tmp3, &f.out)) {
                        f.b.x = f.tmp3.x - f.a.x;
                        f.b.y = f.tmp3.y - f.a.y;
                        f.b.z = f.tmp3.z - f.a.z;
                        f.b.FUN_0022d110();
                    }
                }
            }
            Cfg_19ae50 *c3 = cfg;
            f.r1 = c3->f58;
            if (f.r1 > 0.0f) {
                Rng_19ae50 *rng = FUN_000964d0();
                f.r1 = rng->FUN_000787e0(0, *(int *)&f.r1);
                f.r2 = rng->FUN_000787e0(0, 0x40c90fdb);
                f.zv.x = 0.0f;
                f.zv.y = 1.0f;
                f.zv.z = 0.0f;
                if (f.b.FUN_0022d2b0(&f.zv, 1e-5f)) {
                    f.c.x = (float)((double)(f.b.y * -1.0f) - (double)(f.b.z * 0.0f));
                    f.c.y = (float)((double)(f.b.z * 0.0f) - (double)(f.b.x * -1.0f));
                    f.c.z = (float)((double)(f.b.x * 0.0f) - (double)(f.b.y * 0.0f));
                } else {
                    f.c.x = (float)((double)(f.b.y * 0.0f) - (double)f.b.z);
                    f.c.y = (float)((double)(f.b.z * 0.0f) - (double)(f.b.x * 0.0f));
                    f.c.z = (float)((double)f.b.x - (double)(f.b.y * 0.0f));
                }
                f.M2.FUN_0022b980();
                f.M2.FUN_0022baf0(&f.c, f.r1);
                f.M3.FUN_0022b980();
                f.M3.FUN_0022baf0(&f.b, f.r2);
                f.M2.FUN_0022c3b0(&f.b, &f.v);
                f.M3.FUN_0022c3b0(&f.v, &f.b);
            }
            proj->f40 = f.b;
            Cfg_19ae50 *c4 = cfg;
            hulk_freg f5c = c4->f5c;
            proj->f4c = f5c;
            hulk_freg m = f5c * f24;
            double bxm = (double)f.b.x * m;
            f.bm.y = f.b.y * m;
            f.bm.z = f.b.z * m;
            f.P.x = 0.0f;
            f.P.y = 0.0f;
            f.P.z = 0.0f;
            f.a.x = (float)(bxm + f.a.x);
            f.a.y = f.bm.y + f.a.y;
            f.a.z = f.bm.z + f.a.z;
            f.ctx->FUN_00059a50(&f.P);
            f.P.y = f.a.y;
            proj->f28 = f.P;
            proj->f34 = f.a;
            f.pool->FUN_001b6d00(slot, proj);
            proj->Release();
        }
    } while (f24 > f.period);
    return true;
}
