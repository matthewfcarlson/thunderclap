// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 61/62, incomplete)
// hulkfight::motion::FireMissileAction::vfunc_5 @ 0x0019e430
// hulkfight::motion::FireMissileAction::vfunc_5 @ 0x0019e430
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct V3_19e430 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
};

class CSPHulkProp;

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Prop_19e430 {
    char pad[4];
};

struct Inventory_19e430 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Prop_19e430 *v3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, unsigned __int64 key);
};

struct Holder44_19e430 { Inventory_19e430 *FUN_00203d70(); };
struct Holder28_19e430 { Holder44_19e430 *FUN_000862a0(); };
struct FlagSrc {
    char FUN_00092940(int id);
};
struct World {
    char pad0[0x14];
    void *pool;
    char pad18[0x54 - 0x18];
    Holder28_19e430 *holder;
};

struct Matrix {
    float m[16];
    void FUN_0022ca90(const Matrix *src, void *arg);
    void FUN_0022c2b0(const V3_19e430 *in, V3_19e430 *out);
    void FUN_0022c3b0(const V3_19e430 *in, V3_19e430 *out);
};

struct CtrlSub {
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Ctrl_19e430 {
    char pad0[8];
    CtrlSub *sub;
    char padc[0x1c - 0xc];
    Matrix *mats;
};

class Entity {
public:
    char pad0[0x74];
    int f74;
};

class Weapon_19e430 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void *v15();
    Ctrl_19e430 *FUN_001d68d0();
    Entity *FUN_001d72e0();
};

struct Target_19e430 { char pad[4]; };

class Projectile_19e430 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x14 - 4];
    int f14;
    char pad18[0x44 - 0x18];
    void *f44;
    char pad48[0x54 - 0x48];
    float f54, f58, f5c, f60, f64, f68;
    V3_19e430 dir;
    float f78;
    int f7c;
    char pad80[0xdc - 0x80];
    Projectile_19e430 *FUN_001962b0(struct Cfg_19e430 *cfg, Prop_19e430 *prop);
    void FUN_00196640(Target_19e430 *t);
};

struct Pool_19e430 {
    int FUN_001b6b00(int id, V3_19e430 *a);
    void FUN_001b6d00(int id, Projectile_19e430 *p);
};

struct Allocator {
    void *FUN_0008fe90(unsigned int size);
};

struct Stats_19e430 {
    char pad0[0x120];
    Ctrl_19e430 *ctrl;
    char pad124[4];
    int f128;
    char pad12c[0x328 - 0x12c];
    Target_19e430 *target;
    char pad32c[0x1d14 - 0x32c];
    float f1d14;
    char pad1d18[4];
    int f1d1c;
    Weapon_19e430 *FUN_00035ef0(int slot);
    void FUN_00035660(V3_19e430 *out);
    Target_19e430 *FUN_00039c60(V3_19e430 *a, V3_19e430 *b, int lo, int hi, int z1, int z2, int z3);
};

struct Context {
    char pad[4];
    void FUN_00059a50(V3_19e430 *out);
};

struct Cfg_19e430 {
    char pad0[0x10];
    unsigned __int64 key10;
    char pad18[0x34 - 0x18];
    int slot;
    unsigned int key38lo;
    unsigned int key38hi;
    V3_19e430 v40;
    V3_19e430 v4c;
    char b58;
    char pad59[3];
    float f5c;
    char pad60[0x68 - 0x60];
    int f68;
    int f6c;
    char pad70[0x74 - 0x70];
    char b74;
    char b75;
    char b76;
    char pad77[0xb4 - 0x77];
    int fb4;
};

struct Owner_19e430 { char pad[8]; void *f8; };


Context *__fastcall FUN_000592a0(Owner_19e430 *owner);
Stats_19e430 *__fastcall FUN_00059a30(Context *ctx);
FlagSrc *__fastcall FUN_00086340(Holder28_19e430 *s);
unsigned __int64 __cdecl FUN_0027afb0(const char *s);
char __cdecl FUN_00096b50(Target_19e430 *t, V3_19e430 *c, void *out);
// equiv-conv: FUN_001947a0 esi stack stack
void __cdecl FUN_001947a0(V3_19e430 *pos, Stats_19e430 *fighter, float x);

namespace hulkfight {
namespace motion {
class FireMissileAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int a0, int a1);
    char pad04[0x18];
    Cfg_19e430 *cfg;
    Owner_19e430 *owner;
};

char FireMissileAction::vfunc_5(int a0, int a1)
{
    if (a0 != 1)
        return 1;
    if (owner == 0)
        return 0;

    union Word {
        Prop_19e430 *prop;
        Weapon_19e430 *wo;
        float f;
        unsigned int u;
    };
    struct Frame {
        Word s10;
        Word s14;
        char pad18[3];
        char ok;
        Stats_19e430 *fighter;
        V3_19e430 tmp;
        V3_19e430 a;
        V3_19e430 b;
        void *pool;
        V3_19e430 pos;
        Context *ctx;
        int id;
        Matrix m;
    } f;

    f.pool = DAT_004dd700->pool;
    f.ctx = FUN_000592a0(owner);
    f.fighter = FUN_00059a30(f.ctx);
    Inventory_19e430 *inv = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    char flag = FUN_00086340(DAT_004dd700->holder)->FUN_00092940(0x2f);
    bool got = false;
    if (flag) {
        if ((DAT_004e16f0 & 1) == 0) {
            DAT_004e16f0 |= 1;
            (*(unsigned __int64*)&DAT_004e16e8) = FUN_0027afb0("cow_male_cow_male");
        }
        f.s10.prop = inv->v3(new (&f.s10) content::LoadInventory::DynamicCaster<CSPHulkProp>, (*(unsigned __int64*)&DAT_004e16e8));
        got = f.s10.prop != 0;
    }
    if (!got) {
        f.s10.prop = inv->v3(new (&f.s10) content::LoadInventory::DynamicCaster<CSPHulkProp>, cfg->key10);
        if (f.s10.prop == 0)
            return 0;
    }

    Cfg_19e430 *c0 = cfg;
    int slot = c0->slot;
    Ctrl_19e430 *ctrl = f.fighter->ctrl;
    int idx = 0;
    f.s14.wo = 0;
    if (slot >= 0 && slot < 8) {
        Weapon_19e430 *w = f.fighter->FUN_00035ef0(slot);
        if (w != 0) {
            if (f.fighter->f128 != 0)
                f.s14.wo = w;
            ctrl = w->FUN_001d68d0();
            Entity *e = w->FUN_001d72e0();
            if (e == 0 || w->FUN_001d72e0()->f74 == 0)
                f.s14.wo = w;
        }
    }
    if (ctrl != 0) {
        Cfg_19e430 *c1 = cfg;
        if ((c1->key38lo | c1->key38hi) != 0) {
            idx = ctrl->sub->FUN_0027b200(c1->key38lo, c1->key38hi);
            if (idx == 0xffff)
                idx = 0;
        }
    }
    f.a.x = 0.0f;
    f.a.y = 0.0f;
    f.a.z = 0.0f;
    f.b.x = 0.0f;
    f.b.y = 0.0f;
    f.b.z = -1.0f;
    if (ctrl != 0) {
        Matrix *src = ctrl->mats + idx;
        if (f.s14.wo != 0) {
            f.m.FUN_0022ca90(src, f.s14.wo->v15());
        } else {
            memcpy(&f.m, src, sizeof(Matrix));
        }
        f.tmp = cfg->v40;
        f.m.FUN_0022c2b0(&f.tmp, &f.a);
        f.tmp = cfg->v4c;
        f.m.FUN_0022c3b0(&f.tmp, &f.b);
        f.b.FUN_0022d110();
    }

    int fb4 = cfg->fb4;
    f.id = ((Pool_19e430 *)f.pool)->FUN_001b6b00(fb4, &f.a);
    if (f.id < 0)
        return 0;
    void *mem = (*(Allocator*)&DAT_004e2210).FUN_0008fe90(0xdc);
    Projectile_19e430 *proj;
    if (mem)
        proj = ((Projectile_19e430 *)mem)->FUN_001962b0(cfg, f.s10.prop);
    else
        proj = 0;
    proj->AddRef();
    proj->f44 = owner->f8;
    proj->f14 = fb4;
    Target_19e430 *tgt = f.fighter->target;
    if (tgt == 0) {
        Cfg_19e430 *c3 = cfg;
        f.s10.u = c3->f6c;
        f.s14.u = c3->f68;
        tgt = f.fighter->FUN_00039c60(&f.a, &f.b, c3->f68, c3->f6c, 0, 0, 0);
    }
    proj->FUN_00196640(tgt);

    Cfg_19e430 *c4 = cfg;
    bool bl = false;
    f.s10.u = 0;
    f.s14.u = 0;
    if (c4->b76) {
        if (f.fighter->f1d1c != 0) {
            f.s14.f = f.fighter->f1d14;
            if (f.fighter->f1d14 != 0.0f && f.s14.f != 0.0f)
                bl = true;
        }
    }
    if (tgt != 0) {
        if (c4->b74 || bl) {
            f.ok = FUN_00096b50(tgt, &f.tmp, &f.s10);
            if (bl) {
                FUN_001947a0(&f.tmp, f.fighter, f.s14.f);
                if (!cfg->b75)
                    proj->f7c = 0;
            }
            if (f.ok) {
                f.b.x = f.tmp.x - f.a.x;
                f.b.y = f.tmp.y - f.a.y;
                f.b.z = f.tmp.z - f.a.z;
                f.b.FUN_0022d110();
            }
        }
    }
    proj->dir.x = f.b.x;
    proj->dir.y = f.b.y;
    proj->dir.z = f.b.z;

    Cfg_19e430 *c5 = cfg;
    f.s10.f = c5->f5c;
    float w78 = f.s10.f;
    if (c5->b58) {
        f.fighter->FUN_00035660(&f.tmp);
        w78 = f.tmp.FUN_00018990() + f.s10.f;
    }
    proj->f78 = w78;
    f.pos.x = 0.0f;
    f.pos.y = 0.0f;
    f.pos.z = 0.0f;
    f.ctx->FUN_00059a50(&f.pos);
    f.pos.y = f.a.y;
    proj->f54 = f.pos.x;
    proj->f58 = f.pos.y;
    proj->f5c = f.pos.z;
    proj->f60 = f.a.x;
    proj->f64 = f.a.y;
    proj->f68 = f.a.z;
    ((Pool_19e430 *)f.pool)->FUN_001b6d00(f.id, proj);
    proj->Release();
    return 0;
}
}
}
