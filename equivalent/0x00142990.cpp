// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 36/36)
// hulkfight::motion::WallRunAction::vfunc_3 @ 0x00142990
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-conv: FUN_00142940 eax
extern "C" double sqrt(double);
void *thunk_FUN_0008d690(unsigned int size);

union FloatBits_142990 {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits_142990 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

struct V3_142990 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3_142990 *other, float epsilon);
};

int FUN_00142940(const void *id);

struct Name_142990 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Rig_142990 {
    virtual void v0();
    virtual void v1();
    char pad04[4];
    Name_142990 name;
    char pad10[0x89c - 0x10];
    bool b89c;
    bool b89d;
    Rig_142990 *FUN_00229760(int a, int b, int c, int *desc, int d);
};

struct Root_142990 {
    virtual void v0();
    virtual void v1();
    char pad04[4];
    Name_142990 name;
    Root_142990 *FUN_002248f0(unsigned int id);
};

struct Stats_142990 {
    char pad0[0x1ae0];
    V3_142990 vB;
    char pad1aec[0x1af8 - 0x1aec];
    V3_142990 vA;
    char pad1b04[0x2008 - 0x1b04];
    int i2008;
    char pad200c[0x2064 - 0x200c];
    V3_142990 vec2064;
    float FUN_0003ec00(int z);
    char FUN_000356c0(V3_142990 *out);
};

struct Scene_142990 {
    int FUN_002226b0();
    void FUN_00222890(Rig_142990 *r, float a, int b, float c, int d, int e, float f);
};

struct Pool_142990 {
    Stats_142990 *FUN_00059a30();
    Scene_142990 *FUN_00059a40();
};

struct Owner_142990 {
    Pool_142990 *FUN_000592a0();
};

struct Config_142990 {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    bool flag24;
    char pad25[0x38 - 0x25];
    char id1[8];
    char id2[8];
    char id3[8];
    int i50;
    int i54;
    int i58;
};

extern "C" void __cdecl FUN_0015cfd0(int h, Rig_142990 *r);

namespace hulkfight { namespace motion {

class WallRunAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a0, int a1);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Config_142990 *cfg;    // 0x1c
    Owner_142990 *owner;   // 0x20
    Rig_142990 *rig;       // 0x24
    Root_142990 *root;     // 0x28
    V3_142990 w;           // 0x2c
    V3_142990 a;           // 0x38
    V3_142990 b;           // 0x44
    bool flag50;    // 0x50
    char pad51[3];
    int i54;        // 0x54
};

char WallRunAction::vfunc_3(int a0, int a1)
{
    Pool_142990 *pool = owner->FUN_000592a0();
    Stats_142990 *stats = pool->FUN_00059a30();

    V3_142990 v = stats->vA;
    V3_142990 z;
    z.x = 0.0f;
    z.y = 0.0f;
    z.z = 0.0f;
    if (v.FUN_0022d2b0(&z, 1e-5f)) {
        v = stats->vB;
        z.x = 0.0f;
        z.y = 0.0f;
        z.z = 0.0f;
        if (v.FUN_0022d2b0(&z, 1e-5f))
            return 0;
    }

    v.y = 0.0f;
    v.FUN_0022d110();
    a.ix = v.ix;
    a.iy = v.iy;
    a.iz = v.iz;
    b.ix = v.ix;
    b.iy = v.iy;
    b.iz = v.iz;
    i54 = stats->i2008;
    w.ix = 0;
    w.iy = 0;
    w.iz = 0;
    if (cfg->flag24) {
        flag50 = true;
        w.ix = stats->vec2064.ix;
        w.iy = stats->vec2064.iy;
        w.iz = stats->vec2064.iz;
        float dot = v.z * w.z + v.y * w.y + v.x * w.x;
        if (dot < 0.0f) {
            float nd = -dot;
            V3_142990 t;
            t.ix = v.ix;
            t.iy = v.iy;
            t.iz = v.iz;
            t.y = t.y * nd;
            t.z = t.z * nd;
            w.x = t.x * nd + w.x;
            w.y = t.y + w.y;
            w.z = t.z + w.z;
        }
        if (w.y < 0.0f)
            w.iy = 0;
        float len = w.FUN_0022d110();
        if (AbsF(len) <= 1e-5f) {
            w.ix = 0;
            w.y = 1.0f;
            w.iz = 0;
        }
        if (w.y < 0.70710677f) {
            float zz = w.z;
            w.y = 0.70710677f;
            double r = sqrt(w.x * w.x + zz * zz);
            double k = 0.70710677f / r;
            w.x = (float)(k * w.x);
            w.z = (float)(k * w.z);
        }
        float R = stats->FUN_0003ec00(0);
        float c1c = cfg->f1c;
        float m = c1c + R * (cfg->f20 - c1c);
        w.x = m * w.x;
        w.y = m * w.y;
        w.z = m * w.z;
    } else {
        flag50 = false;
        stats->FUN_000356c0(&w);
        float dot = v.z * w.z + v.y * w.y + v.x * w.x;
        if (dot < 0.0f) {
            float nd = -dot;
            V3_142990 t;
            t.ix = v.ix;
            t.iy = v.iy;
            t.iz = v.iz;
            t.y = t.y * nd;
            t.z = t.z * nd;
            w.x = t.x * nd + w.x;
            w.y = t.y + w.y;
            w.z = t.z + w.z;
        }
        Config_142990 *c = cfg;
        float c18 = c->f18;
        if (c18 > 0.0f && c18 > w.y)
            w.y = c18;
        float c14 = c->f14;
        if (c14 > 0.0f) {
            double len = sqrt(w.x * w.x + w.y * w.y + w.z * w.z);
            if (len <= 0.0) {
                w.ix = 0;
                w.y = 1.0f;
                w.iz = 0;
                len = 1.0;
            }
            if (len < c14) {
                double k = c14 / len;
                w.x = (float)(k * w.x);
                w.y = (float)(k * w.y);
                w.z = (float)(k * w.z);
            }
        }
    }

    Scene_142990 *scene = pool->FUN_00059a40();
    if (scene == 0)
        return 0;
    int h = scene->FUN_002226b0();
    int id1 = FUN_00142940(cfg->id1);
    int id2 = FUN_00142940(cfg->id2);
    int id3 = FUN_00142940(cfg->id3);
    int desc[10];
    desc[0] = 0;
    desc[1] = 0;
    desc[2] = 0;
    desc[3] = 0;
    desc[4] = 0;
    desc[5] = id2;
    desc[6] = id2;
    desc[7] = id1;
    desc[8] = 0;
    desc[9] = id3;
    void *mem = thunk_FUN_0008d690(0x910);
    Rig_142990 *obj = 0;
    if (mem)
        obj = ((Rig_142990 *)mem)->FUN_00229760(h, 4, 2, desc, 0);
    if (obj)
        obj->v0();
    if (rig)
        rig->v1();
    rig = obj;
    FUN_0015cfd0(h, obj);
    int c54 = cfg->i54;
    int c58 = cfg->i58;
    int c50 = cfg->i50;
    rig->b89d = false;
    rig->b89c = false;
    rig->name.FUN_0027b040("wallRunLoco");
    scene->FUN_00222890(rig, -1.0f, c50, 1.0f, c54, c58, -1.0f);

    void *mem2 = thunk_FUN_0008d690(0x70);
    Root_142990 *r2 = 0;
    if (mem2)
        r2 = ((Root_142990 *)mem2)->FUN_002248f0(0);
    root = r2;
    r2->name.FUN_0027b040("wallRunRoot");
    root->v0();
    scene->FUN_00222890((Rig_142990 *)root, -1.0f, c50 - 1, 1.0f, c54, c58, -1.0f);
    return 1;
}

}}
