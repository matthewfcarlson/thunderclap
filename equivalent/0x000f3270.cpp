// STATUS: equivalent (tools/equiv.py level 3: 3172 inputs, branch coverage 94/94)
// FEThingsBase::vfunc_35 @ 0x000f3270
typedef unsigned __int64 u64;
void *FUN_0008d690(unsigned int size);
u64 __cdecl FUN_0027b020(const char *s);

namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
namespace pure3d { class CompositeDrawable; }

struct Loaded {
    virtual void l0();
};

struct Inventory {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded *find(void *caster, u64 key);
};
extern Inventory *DAT_004dd9cc;
Loaded *__cdecl FUN_000c0d80(Inventory *inv, const char *name);

struct Color {
    unsigned int v;
    Color *FUN_000115c0(int r, int g, int b, int a);
};

struct Reader {
    const char *FUN_000fad90();
    float FUN_000fad30();
    u64 FUN_000faeb0();
    char FUN_000f9e90();
    void FUN_000fa0a0();
    int FUN_000fb150();
};

struct Item {
    char pad0[0x10];
    unsigned int color;              // 0x10
    float f14;                       // 0x14
    char pad18[4];
    Item *FUN_000dee10();
};

struct Sub {
    char pad0[0x38];
    float f38;
};

struct Dest {
    char pad0[0x14];
    Sub *f14;
    unsigned int f18;
    char pad1c[0x30 - 0x1c];
    unsigned char b30;
    char pad31[3];
    float f34;
    int f38;
    unsigned int f3c;
    unsigned char b40;
    char pad41[3];
    unsigned int f44;
    unsigned char b48;
    char pad49[3];
    unsigned int f4c;
    char pad50[0x68 - 0x50];
    unsigned char b68;
    char pad69[3];
    int f6c;
    int f70;
    char pad74[0x90 - 0x74];
    u64 f90;
    char pad98[0xa4 - 0x98];
    int fa4;
    char pada8[0xc0 - 0xa8];
    int fc0;
    int fc4;
    char padc8[0xd0 - 0xc8];
    int fd0;
    int fd4;

    void FUN_000e2ac0(Item *it);
    void FUN_000e9090(Loaded *l);
    void FUN_000e9130(Loaded *l);
    void FUN_000e9100(Loaded *l);
    void FUN_000e04f0(const char *s);
    float *FUN_000e2820(float *tmp);
};

struct Key {
    virtual void k0();
    virtual int v1();
};

class FEThingsBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(int a, unsigned int *dstp);
    virtual void v34();
    virtual bool vfunc_35(Reader *r, int unused, Dest *dst, Key *key);

    int FUN_000e6530(const char *name);
    int FUN_000e7ec0(u64 id, Reader *r);
    int FUN_000e7f10(u64 id, Reader *r);
};

bool FEThingsBase::vfunc_35(Reader *r, int unused, Dest *dst, Key *key)
{
    int hash = key->v1();
    switch (hash) {
    case 0x9af45bd7: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fc4 = h;
        return true;
    }
    case 0xd3cd5a63: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fc0 = h;
        return true;
    }
    case 0xd3f62292: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fd0 = h;
        dst->fd4 = h;
        return true;
    }
    case 0xda695544: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fc0 = h;
        dst->fc4 = h;
        return true;
    }
    case 0xe5160039: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fd0 = h;
        return true;
    }
    case 0xee4f9831: {
        int h = FUN_000e6530(r->FUN_000fad90());
        if (h == 0) {
            r->FUN_000fa0a0();
            return false;
        }
        dst->fd4 = h;
        return true;
    }
    case 0x8b025b6b: {
        u64 id = r->FUN_000faeb0();
        if ((unsigned int)id != 0xa6dce4eb)
            return false;
        void *mem = FUN_0008d690(0x1c);
        Item *it = 0;
        if (mem != 0)
            it = ((Item *)mem)->FUN_000dee10();
        if (r->FUN_000f9e90())
            it->f14 = r->FUN_000fad30();
        unsigned int col = it->color;
        if (r->FUN_000f9e90()) {
            int cr = (int)r->FUN_000fad30();
            int cg = (int)r->FUN_000fad30();
            int cb = (int)r->FUN_000fad30();
            col = (col & 0xff000000) | (((cr & 0xff) << 8 | (cg & 0xff)) << 8) | (cb & 0xff);
            if (r->FUN_000f9e90()) {
                int ca = (int)r->FUN_000fad30();
                col = (col & 0xffffff) | (ca << 24);
            }
        }
        it->color = col;
        dst->FUN_000e2ac0(it);
        return true;
    }
    case 0xb660a5ef:
        dst->fa4 = (int)r->FUN_000fad30();
        return true;
    case 0xd208ebe9: {
        int cr = (int)r->FUN_000fad30();
        int cg = (int)r->FUN_000fad30();
        int cb = (int)r->FUN_000fad30();
        int ca = 0xff;
        if (r->FUN_000f9e90())
            ca = (int)r->FUN_000fad30();
        Color c;
        dst->b48 = 1;
        dst->f4c = c.FUN_000115c0(cr, cg, cb, ca)->v;
        return true;
    }
    case 0x158c2674: {
        int cr = (int)r->FUN_000fad30();
        int cg = (int)r->FUN_000fad30();
        int cb = (int)r->FUN_000fad30();
        int ca = 0xff;
        if (r->FUN_000f9e90())
            ca = (int)r->FUN_000fad30();
        Color c;
        dst->f3c = c.FUN_000115c0(cr, cg, cb, ca)->v;
        return true;
    }
    case 0x58a3e29a: {
        int cr = (int)r->FUN_000fad30();
        int cg = (int)r->FUN_000fad30();
        int cb = (int)r->FUN_000fad30();
        int ca = 0xff;
        if (r->FUN_000f9e90())
            ca = (int)r->FUN_000fad30();
        dst->b40 = 1;
        dst->f44 = (((ca << 8 | cr) << 8 | cg) << 8) | cb;
        return true;
    }
    case 0xf7d14590: {
        const char *nm = r->FUN_000fad90();
        Inventory *inv = DAT_004dd9cc;
        u64 key2 = FUN_0027b020(nm);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
        Loaded *l = inv->find(&caster, key2);
        dst->FUN_000e9090(l);
        return true;
    }
    case 0x116152a5:
        dst->f70 = FUN_000e7f10(r->FUN_000faeb0(), r);
        return true;
    case 0xdaf00033:
        dst->f6c = FUN_000e7ec0(r->FUN_000faeb0(), r);
        return true;
    case 0x09a7e15a:
        dst->FUN_000e9130(FUN_000c0d80(DAT_004dd9cc, r->FUN_000fad90()));
        return true;
    case 0x18688526:
        return true;
    case 0x2d848685:
        dst->FUN_000e04f0(r->FUN_000fad90());
        return true;
    case 0x3cbe40fa:
        dst->f90 = r->FUN_000faeb0();
        return true;
    case 0x42ba2ee5: {
        unsigned int *p = &dst->f18;
        v33(r->FUN_000fb150(), p);
        int v = 0;
        if (r->FUN_000f9e90())
            v = (int)r->FUN_000fad30();
        *p = v;
        dst->fa4 = v;
        return true;
    }
    case 0x47329b05: {
        dst->FUN_000e9100(FUN_000c0d80(DAT_004dd9cc, r->FUN_000fad90()));
        if (r->FUN_000f9e90()) {
            if (r->FUN_000fad30() != 0.0f) {
                dst->b68 = 1;
                return true;
            }
        }
        dst->b68 = 0;
        return true;
    }
    case 0x47c943ae: {
        float v = r->FUN_000fad30();
        if (!(v > 0.0f) && v == v) {
            float tmp;
            v = *dst->FUN_000e2820(&tmp);
        }
        dst->f34 = v;
        dst->b30 = 1;
        dst->f38 = -1;
        return true;
    }
    case 0xe897502e:
        dst->f14->f38 = r->FUN_000fad30();
        return true;
    }
    return false;
}
