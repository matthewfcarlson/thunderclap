// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 26/26)
// Render::LevelLoader::vfunc_5 @ 0x001c9160
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" int strcmp(const char *, const char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void __fastcall __security_check_cookie(unsigned int);

namespace pure3d { class DrawableHierarchy; class LightGroup; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Id64_1c9160 {
    unsigned int lo;
    unsigned int hi;
    Id64_1c9160 *FUN_0027b0e0(const char *s);
    void FUN_0027af70(Id64_1c9160 *other);
    void FUN_0027af50();
};

struct Loaded_1c9160 {
    virtual void l0();
};

struct Light {
    char pad00[0x28];
    char special;
};

struct LightGroup {
    char pad00[0x10];
    int size;
    int count;
    Light **arr;
};

struct Holder_1c9160 {
    void FUN_0029fa30();
    void FUN_0029f800(Light *l);
};

struct Lights_1c9160 {
    char pad00[0xc0];
    Holder_1c9160 *h0;
    Holder_1c9160 *h1;
};

struct Stream {
    void FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad00[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

struct Inventory_1c9160 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_1c9160 *find(void *caster, unsigned __int64 key);
};

struct Target_1c9160 {
    char pad00[0x758];
    Id64_1c9160 name;
    void FUN_001c7fa0(Loaded_1c9160 *a, Loaded_1c9160 *c);
    void FUN_001c8000(Loaded_1c9160 *b);
};

class Handler_1c9160 {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual int GetId();
    virtual void Load(int *x, Id64_1c9160 *y, Reader *r, Inventory_1c9160 *inv);
};

extern unsigned int DAT_004d9968;
unsigned __int64 __cdecl FUN_0027b020(const char *s);
void __cdecl FUN_0028fcc0(const char *fmt, ...);

namespace Render {

class LevelLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int *out1, Id64_1c9160 *out2, Reader *rd, Inventory_1c9160 *inv);
    char pad04[0x10];
    Target_1c9160 *target;
    Lights_1c9160 *lights;
    Handler_1c9160 *handler;
};

void LevelLoader::vfunc_5(int *out1, Id64_1c9160 *out2, Reader *rd, Inventory_1c9160 *inv)
{
    struct Frame {
        struct {
            char pad[3];
            unsigned char len;
        } l;
        union {
            int word;
            char caster[4];
        } s14;
        union {
            Loaded_1c9160 *a;
            LightGroup *lg;
        } s18;
        union {
            Loaded_1c9160 *b;
            char caster[4];
        } s1c;
        union {
            Loaded_1c9160 *c;
            char caster[4];
        } s20;
        LevelLoader *self;
        union {
            char caster[4];
            Id64_1c9160 id;
        } s28;
        char bufD[0x100];
        char bufB[0x100];
        char bufC[0x100];
        char bufA[0x100];
        char bufE[0x100];
        unsigned int cookie;
    } fr;

    fr.cookie = DAT_004d9968;
    fr.self = this;
    rd->stream->FUN_002647e0(&fr.l.len, 1, 1, 1);
    unsigned int len = fr.l.len;
    rd->stream->FUN_002647e0(fr.bufA, len, 1, 1);
    fr.bufA[len] = 0;
    rd->stream->FUN_002647e0(&fr.s14.word, 1, 4, 1);
    rd->stream->FUN_002647e0(&fr.l.len, 1, 1, 1);
    len = fr.l.len;
    rd->stream->FUN_002647e0(fr.bufB, len, 1, 1);
    fr.bufB[len] = 0;
    int emptyB = strcmp(fr.bufB, "") == 0;
    fr.s18.a = 0;
    fr.s20.c = 0;
    fr.s1c.b = 0;
    if (!emptyB) {
        sprintf(fr.bufC, "%s_static", fr.bufB);
        unsigned __int64 k1 = FUN_0027b020(fr.bufC);
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *c1 =
            new (fr.s1c.caster) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
        Loaded_1c9160 *r1 = inv->find(c1, k1);
        fr.s18.a = r1;
        unsigned __int64 k2 = FUN_0027b020(fr.bufC);
        content::LoadInventory::DynamicCaster<pure3d::LightGroup> *c2 =
            new (fr.s28.caster) content::LoadInventory::DynamicCaster<pure3d::LightGroup>;
        fr.s1c.b = inv->find(c2, k2);
        sprintf(fr.bufC, "%s_dynamic", fr.bufB);
        unsigned __int64 k3 = FUN_0027b020(fr.bufC);
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *c3 =
            new (fr.s20.caster) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
        Loaded_1c9160 *r3 = inv->find(c3, k3);
        fr.s20.c = r3;
        if (r1 == 0 && r3 == 0) {
            unsigned __int64 k4 = FUN_0027b020(fr.bufB);
            content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *c4 =
                new (fr.s14.caster) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
            fr.s18.a = inv->find(c4, k4);
        }
    }
    LevelLoader *self = fr.self;
    self->target->FUN_001c7fa0(fr.s18.a, fr.s20.c);
    if (fr.s1c.b)
        self->target->FUN_001c8000(fr.s1c.b);

    rd->stream->FUN_002647e0(&fr.l.len, 1, 1, 1);
    len = fr.l.len;
    rd->stream->FUN_002647e0(fr.bufD, len, 1, 1);
    fr.bufD[len] = 0;
    if (strcmp(fr.bufD, "") != 0) {
        FUN_0028fcc0("Background Lights: %s\n", fr.bufD);
        unsigned __int64 k5 = FUN_0027b020(fr.bufD);
        content::LoadInventory::DynamicCaster<pure3d::LightGroup> *c5 =
            new (fr.s14.caster) content::LoadInventory::DynamicCaster<pure3d::LightGroup>;
        fr.s18.lg = (LightGroup *)inv->find(c5, k5);
        self = fr.self;
        Target_1c9160 *tg = self->target;
        tg->name.FUN_0027af70(fr.s28.id.FUN_0027b0e0(fr.bufD));
        fr.s28.id.FUN_0027af50();
        self->lights->h0->FUN_0029fa30();
        self->lights->h1->FUN_0029fa30();
        int j = 0;
        if (fr.s18.lg->count > 0) {
            do {
                Light *light;
                if (j >= fr.s18.lg->size || (light = fr.s18.lg->arr[j]) == 0) {
                    FUN_0028fcc0("light %d is null in lightgroup %s\n", j, fr.bufD);
                } else {
                    if (light->special)
                        self->lights->h1->FUN_0029f800(light);
                    else
                        self->lights->h0->FUN_0029f800(light);
                }
                j++;
            } while (j < fr.s18.lg->count);
        }
    }

    rd->stream->FUN_002647e0(&fr.l.len, 1, 1, 1);
    len = fr.l.len;
    rd->stream->FUN_002647e0(fr.bufE, len, 1, 1);
    fr.bufE[len] = 0;
    while (rd->FUN_002669f0()) {
        rd->FUN_00266a30();
        fr.s14.word = 0;
        int want = self->handler->GetId();
        if (want == rd->FUN_00266c30())
            self->handler->Load(&fr.s14.word, &fr.s28.id, rd, inv);
        rd->FUN_00266be0();
    }
    *out1 = 0;
    out2->lo = 0;
    out2->hi = 0;
    __security_check_cookie(fr.cookie);
}
}
