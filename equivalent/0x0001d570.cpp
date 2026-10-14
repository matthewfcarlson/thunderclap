// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 44/44)
// CAutoTargetAction::vfunc_7 @ 0x0001d570
struct V3_1d570 {
    float x, y, z;
    bool FUN_0022d2b0(V3_1d570 *other, float eps);
};

struct Target_1d570 {
    virtual void ref();
    virtual void unref();
};

struct Fighter_1d570 {
    char pad0[0x328];
    Target_1d570 *f328;                    // 0x328
    char pad32c[0x3a4 - 0x32c];
    Target_1d570 *f3a4;                    // 0x3a4
    char pad3a8[0x1d70 - 0x3a8];
    unsigned int idLo;               // 0x1d70
    unsigned int idHi;               // 0x1d74
    char pad1d78[0x2064 - 0x1d78];
    V3_1d570 v2064;
    char pad2070[4];
    V3_1d570 v2074;
    V3_1d570 v2080;
    void FUN_000350c0(V3_1d570 *out);
    void FUN_00035550(V3_1d570 *out);
    char FUN_0003a440(V3_1d570 *a, V3_1d570 *b, float c, float d, Target_1d570 *t);
    Target_1d570 *FUN_00039c60(V3_1d570 *a, V3_1d570 *b, float lo, float hi, unsigned int p, unsigned int q, float r);
    float FUN_000354c0();
    void FUN_0003ffa0(Target_1d570 *t, int z);
};

struct Anchor_1d570 {
    Fighter_1d570 *FUN_00059a30();
};

struct Owner_1d570 {
    Anchor_1d570 *FUN_000592a0();
};

class Entity {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual V3_1d570 *v8(V3_1d570 *out);
};

struct Registry_1d570 {
    Entity *FUN_001fc8c0(unsigned int lo, unsigned int hi);
};

struct World {
    char pad0[0x28];
    Registry_1d570 *registry;              // 0x28
};
extern World *DAT_004dd700;

struct Part18_1d570 {
    void FUN_00221d20(float h);
};

struct Part_1d570 {
    char pad0[0x18];
    Part18_1d570 part18;                   // 0x18
};

struct Cfg_1d570 {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    unsigned int flags;              // 0x20
    float f24;
    float f28;
    char pad2c[0x38 - 0x2c];
    char b38;
};

union FS_1d570 {
    float f;
    unsigned int u;
};

float __cdecl FUN_00224f10(V3_1d570 *v);
float __cdecl FUN_00224fc0(float a, float b);
void __cdecl FUN_00224d70(float angle, V3_1d570 *v);
void __cdecl FUN_00096a90(Target_1d570 *t, V3_1d570 *out);

class CAutoTargetAction {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual char vfunc_7(float dt);
    char pad04[0x1c - 4];
    Owner_1d570 *f1c;
    Cfg_1d570 *cfg;                        // 0x20
    Part_1d570 *f24;
    Target_1d570 *f28;
    float f2c;
};

char CAutoTargetAction::vfunc_7(float dt)
{
    if (f24 == 0)
        return 0;
    Fighter_1d570 *F = f1c->FUN_000592a0()->FUN_00059a30();
    struct Frame {
        float h;
        FS_1d570 ad;
        float len;
        float rate;
        float s10;
        V3_1d570 p;
        V3_1d570 a;
        V3_1d570 b;
        V3_1d570 z;
    } f;
    V3_1d570 &a = f.a;
    V3_1d570 &b = f.b;
    V3_1d570 &p = f.p;
    V3_1d570 &z = f.z;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    F->FUN_000350c0(&a);
    F->FUN_00035550(&b);
    p = b;
    char atOrigin = 0;
    if (f28 == 0) {
        p = F->v2080;
        z.x = 0.0f;
        z.y = 0.0f;
        z.z = 0.0f;
        if (p.FUN_0022d2b0(&z, 1e-5f)) {
            p = F->v2074;
            z.x = 0.0f;
            z.y = 0.0f;
            z.z = 0.0f;
            if (p.FUN_0022d2b0(&z, 1e-5f)) {
                p = F->v2064;
                z.x = 0.0f;
                z.y = 0.0f;
                z.z = 0.0f;
                if (p.FUN_0022d2b0(&z, 1e-5f)) {
                    p = b;
                    atOrigin = 1;
                } else {
                    FUN_00224d70(cfg->f24, &p);
                }
            }
        }
        Target_1d570 *t;
        if (cfg->flags & 2) {
            t = F->f3a4;
        } else {
            t = F->f328;
            bool keep = false;
            if (t != 0) {
                f.s10 = cfg->f1c;
                if (!(cfg->flags & 1))
                    f.s10 = 3.402823466e+38f;
                keep = F->FUN_0003a440(&a, &p, 6.2831855f, f.s10, t) != 0;
            }
            if (!keep) {
                if (atOrigin)
                    f.s10 = 0.0f;
                else
                    f.s10 = f2c;
                t = F->FUN_00039c60(&a, &p, cfg->f18, cfg->f1c, 0x80000000u, 0, f.s10);
                if (t == 0)
                    p = b;
            }
        }
        if (t != 0)
            t->ref();
        if (f28 != 0)
            f28->unref();
        f28 = t;
    }

    if (cfg->b38 != 0) {
        Registry_1d570 *reg = DAT_004dd700->registry;
        if (reg == 0)
            return 1;
        Entity *e = reg->FUN_001fc8c0(F->idLo, F->idHi);
        if (e == 0)
            return 1;
        V3_1d570 *r = e->v8(&z);
        p.x = r->x;
        p.y = r->y;
        float rz = r->z;
        p.x = p.x - a.x;
        p.y = p.y - a.y;
        p.z = rz - a.z;
        FUN_00224d70(cfg->f28, &p);
    } else if (f28 != 0) {
        if (F->f328 == 0)
            F->FUN_0003ffa0(f28, 0);
        FUN_00096a90(f28, &z);
        p.x = z.x - a.x;
        p.y = z.y - a.y;
        p.z = z.z - a.z;
        FUN_00224d70(cfg->f28, &p);
    }

    f.h = F->FUN_000354c0();
    f.len = FUN_00224f10(&p);
    f.s10 = cfg->f14;
    if (f.s10 <= 0.0f) {
        f.h = f.len;
    } else {
        float diff = FUN_00224fc0(f.h, f.len);
        f.rate = f.s10 * dt;
        f.ad.f = diff;
        f.ad.u &= 0x7fffffffu;
        if (f.ad.f <= f.rate) {
            f.h = f.len;
        } else if (diff < 0.0f) {
            f.h = f.h - f.rate;
        } else {
            f.h = f.rate + f.h;
        }
    }
    f24->part18.FUN_00221d20(f.h);
    if (!(f2c < 0.0f))
        f2c = f2c - f.s10 * dt;
    return 1;
}
