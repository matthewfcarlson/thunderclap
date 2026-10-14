// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 24/24)
// CSmartPropUpdateAttachmentAction::vfunc_4 @ 0x0001ed60
struct Vec3_1ed60 {
    float x, y, z;
    float FUN_0022d110();
};

struct Matrix {
    float m[12];
    Vec3_1ed60 trans;
    float w;
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022c120();
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
};

class Entity {
public:
    char pad0[0xc];
    int kind;
    Matrix mat;
};

class Prop_1ed60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Matrix *v15();
    char pad[0xfc - 4];
    int state;
    Entity *FUN_001d72e0();
};

struct Finder_1ed60 {
    int FUN_0027b200(unsigned __int64 key);
};

struct Table_1ed60 {
    char pad0[8];
    Finder_1ed60 *finder;
    char pad1[0x1c - 0x0c];
    Matrix *mats;
};

struct Scene_1ed60 {
    char pad[0x64];
    Table_1ed60 *table;
};

struct Stats_1ed60 {
    void FUN_0003acf0(int a, Prop_1ed60 *b, int c, int d, int e, Matrix *f);
};

struct Fighter_1ed60 {
    Stats_1ed60 *FUN_00059a30();
    Scene_1ed60 *FUN_00059a40();
};

struct Owner_1ed60 {
    Fighter_1ed60 *FUN_000592a0();
};

struct Config_1ed60 {
    char pad0[0x14];
    int f14;
    unsigned __int64 key;
    int f20;
    int f24;
    char flag28;
    char pad29[0x2c - 0x29];
    Vec3_1ed60 pos2;
    Vec3_1ed60 pos3;
    float f44;
};

struct Frame_1ed60 {
    Vec3_1ed60 L;
    float s;
    Vec3_1ed60 T2;
    int c20;
    int c24;
    Stats_1ed60 *stats;
    Matrix M;
    Matrix N;
    Matrix Q;
};

class CSmartPropUpdateAttachmentAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad04[0x1c - 4];
    Owner_1ed60 *owner;
    Config_1ed60 *cfg;
    Prop_1ed60 *prop;
};

void CSmartPropUpdateAttachmentAction::vfunc_4()
{
    if (!prop)
        return;
    if (prop->FUN_001d72e0()) {
        if (prop->FUN_001d72e0()->kind != 5)
            return;
    }
    if (prop->state == 2 || prop->state == 3)
        return;

    Frame_1ed60 fr;
    int idx = 0xffff;
    Table_1ed60 *tbl = 0;
    Fighter_1ed60 *fighter = owner->FUN_000592a0();
    fr.stats = fighter->FUN_00059a30();
    Scene_1ed60 *sc = fighter->FUN_00059a40();
    if (sc) {
        tbl = sc->table;
        if (tbl)
            idx = tbl->finder->FUN_0027b200(cfg->key);
    }
    fr.c24 = cfg->f24;
    fr.c20 = cfg->f20;
    if (cfg->flag28) {
        fr.M.FUN_0022b980();
        Vec3_1ed60 *v = &cfg->pos3;
        fr.M.FUN_0022bc20(v->x, v->y, v->z);
        Vec3_1ed60 *p = &cfg->pos2;
        fr.L = *p;
        fr.M.trans = *p;
    } else {
        fr.N = tbl->mats[idx];
        fr.N.FUN_0022c120();
        Matrix *src;
        if (prop->FUN_001d72e0())
            src = &prop->FUN_001d72e0()->mat;
        else
            src = prop->v15();
        fr.Q = *src;
        fr.M.FUN_0022ca90(&fr.Q, &fr.N);
        fr.s = cfg->f44;
        if (fr.s > 0.0f) {
            fr.L = fr.M.trans;
            fr.T2 = cfg->pos2;
            fr.L.x = fr.L.x - fr.T2.x;
            fr.L.y = fr.L.y - fr.T2.y;
            fr.L.z = fr.L.z - fr.T2.z;
            if (fr.L.FUN_0022d110() > fr.s) {
                fr.L.x = fr.L.x * fr.s;
                fr.L.y = fr.L.y * fr.s;
                fr.L.z = fr.L.z * fr.s;
                fr.T2 = cfg->pos2;
                fr.M.trans.x = fr.T2.x + fr.L.x;
                fr.M.trans.y = fr.T2.y + fr.L.y;
                fr.L.z = fr.T2.z + fr.L.z;
                fr.M.trans.z = fr.L.z;
            }
        }
    }
    fr.stats->FUN_0003acf0(cfg->f14, prop, idx, fr.c20, fr.c24, &fr.M);
    if (prop) {
        prop->v1();
        prop = 0;
    }
}
