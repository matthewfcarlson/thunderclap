// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 14/14)
// FUN_000ce280 @ 0x000ce280
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct Vec3_ce280 {
    float x, y, z;
};

union Word_ce280 {
    float f;
    int i;
    unsigned int u;
};

struct Cell_ce280 {
    Word_ce280 a, b, c, d;
};

struct Source_ce280 {
    int FUN_000f7240(unsigned int lo, unsigned int hi);
};

struct Handle_ce280 {
    void FUN_0008ef90(const Vec3_ce280 *pos, int color);
};

struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual Handle_ce280 *v30(int a, int b, int c, int d, int e);
    virtual void v31(Handle_ce280 *h);
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57();
    virtual void v58(int on);
};

struct Pass_ce280 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_ce280 {
    Pass_ce280 *pass;
    void FUN_00293d00(const Vec3_ce280 *color);
};

struct Texture {
    char pad0[0x10];
    int id;
};

struct Builder {
    char hdr[8];
    Cell_ce280 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source_ce280 *src);
    void FUN_000f78e0();
    float FUN_000cb750(int idx, int mode);
    float FUN_000cb6f0(int idx, int mode);
    void FUN_000f87c0(int idx, int mode, void *extra);
};


class Billboard_ce280 {
public:
    char pad0[0x78];
    float size;             // 0x78
    Source_ce280 *source;         // 0x7c
    char pad80[0x94 - 0x80];
    char extra[0x228 - 0x94];
    unsigned int keyLo;     // 0x228
    unsigned int keyHi;     // 0x22c
    float height;           // 0x230
    Texture *texture;       // 0x234
    int alpha;              // 0x238

    void FUN_000ce280();
};

struct Frame_ce280 {
    float w;
    Word_ce280 hb;
    Vec3_ce280 v[4];
    Builder x;
};

void Billboard_ce280::FUN_000ce280()
{
    if (source == 0)
        return;
    if ((keyLo | keyHi) == 0)
        return;

    Frame_ce280 f;
    f.x.FUN_000f7fe0(source);
    int idx = source->FUN_000f7240(keyLo, keyHi);
    if (idx != -1) {
        f.x.cells[f.x.cursor].a.f = DAT_0049fd14 * size;
        f.x.cells[f.x.cursor].c.i = 2;
        int mode = DAT_0049fd18;
        f.x.cells[f.x.cursor].b.i = 1;
        f.x.scale = 1.0f;
        f.x.cells[f.x.cursor].d.u = (alpha << 24) | 0x14c828;

        f.w = f.x.FUN_000cb750(idx, mode) * 1.3f;
        float t = f.x.FUN_000cb6f0(idx, DAT_0049fd18) * 1.4f;
        if (t < height)
            height = t;
        if (height < 0.0f)
            height = 0.0f;

        f.hb.f = height;
        f.hb.u &= 0x7fffffff;
        if (!(f.hb.f <= 1e-05f)) {
            DAT_0052c2a8->v58(0);
            (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v15(0);
            Vec3_ce280 *c = &f.v[0];
            *c = (*(Vec3_ce280*)&DAT_004ddea4);
            (*(PassHolder_ce280**)&DAT_0052c2ac)->FUN_00293d00(c);
            Handle_ce280 *h = DAT_0052c2a8->v30(texture->id, 1, 0x2020, 4, 0);

            f.v[0].x = f.w * -0.5f;
            f.v[0].y = height * -0.5f;
            f.v[0].z = 0.0f;
            f.v[1].y = height * 0.5f;
            f.v[1].z = 0.0f;
            f.w = f.w * 0.5f;
            f.v[1].x = f.w;
            f.v[2].x = f.v[0].x;
            f.v[2].z = 0.0f;
            f.v[2].y = f.v[1].y;
            f.v[3].x = f.w;
            f.v[3].y = f.v[0].y;
            f.v[3].z = 0.0f;
            h->FUN_0008ef90(&f.v[0], 0x7f000000);
            h->FUN_0008ef90(&f.v[2], 0x7f000000);
            h->FUN_0008ef90(&f.v[3], 0x7f000000);
            h->FUN_0008ef90(&f.v[1], 0x7f000000);
            DAT_0052c2a8->v31(h);
            (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v16(0);
            DAT_0052c2a8->v58(1);
            if (alpha > 0) {
                (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v15(0);
                Vec3_ce280 *c2 = &f.v[1];
                *c2 = (*(Vec3_ce280*)&DAT_004ddea4);
                (*(PassHolder_ce280**)&DAT_0052c2ac)->FUN_00293d00(c2);
                f.x.FUN_000f87c0(idx, DAT_0049fd18, extra);
                (*(PassHolder_ce280**)&DAT_0052c2ac)->pass->v16(0);
            }
        }
    }
    f.x.FUN_000f78e0();
}
