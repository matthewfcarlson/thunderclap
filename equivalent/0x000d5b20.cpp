// STATUS: equivalent (tools/equiv.py level 3: 20046 inputs, branch coverage 27/28, incomplete)
// MessageOverlay::vfunc_4 @ 0x000d5b20
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "compat/ptr.h"

struct Rec_d5b20 {
    int a, b, c;
};

class Dev_d5b20 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
struct Ctx_d5b20 {
    Dev_d5b20 *dev;
    void FUN_00293d00(void *p);
    void FUN_00293d40(float a, float b, int c);
};

class Obj24_d5b20 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6();
    virtual float v7();
    virtual void v8();
    virtual float v9(void *p);
    virtual float v10(void *p);
};
struct Owner_d5b20 {
    char pad[0x24];
    Obj24_d5b20 *p24;
};

struct Builder {
    char data[8];
    void FUN_000f7fe0(Owner_d5b20 *o);
    void FUN_000f78e0();
    void FUN_000f81b0(void *a, int b, void *c);
};

struct Vtx_d5b20 {
    float a;
    int b;
    int c;
    unsigned int color;
};
struct Q_d5b20 {
    int a, b;
    float c;
};

struct Elem_d5b20 {
    char obj[0x200];
    char obj2[0x18];
    float f0, f4, f8;
    int fc, f10;
    char pad22c[8];
    char flag;
    char pad235[0x23c - 0x235];
};
struct Item_d5b20 {
    char pad0[0x100];
    unsigned int color;
    float f0, f4;
};

struct Frame_d5b20 {
    float u;
    float s;
    Rec_d5b20 *savedRec;
    float t1;
    Q_d5b20 q;
    Builder a;
    Vtx_d5b20 v[8];
    int n;
    float w;
};

class MessageOverlay {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    char pad04[8];
    Owner_d5b20 *owner;
    char pad10[4];
    Elem_d5b20 elems[2];
    Item_d5b20 items[3];
    char pad7b0[4];
    float f7b4;
    float f7b8;
    char pad7bc[0x7d4 - 0x7bc];
    char f7d4[4];
    void FUN_000d50f0();
};

void MessageOverlay::v4()
{
    if (!owner)
        return;
    Frame_d5b20 f;
    FUN_000d50f0();
    f.a.FUN_000f7fe0(owner);
    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
    f.q.a = 0;
    f.q.b = 0;
    f.q.c = f7b8;
    (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d00(&f.q);
    for (int k = 0; k < 2; k++) {
        Elem_d5b20 *e = &elems[k];
        if (e->flag) {
            f.v[f.n].a = e->f8 * f7b4;
            f.v[f.n].c = e->f10;
            f.v[f.n].b = e->fc;
            f.w = (*(float*)&DAT_004a06cc);
            int alpha;
            if (e->f0 < DAT_004a06a8) {
                alpha = 0;
            } else if (DAT_004a06ac + DAT_004a06a8 > e->f0) {
                alpha = (int)((e->f0 - DAT_004a06a8) / DAT_004a06ac * 255.0f);
            } else if (DAT_004a06ac + e->f4 + DAT_004a06a8 > e->f0) {
                alpha = 0xff;
            } else {
                f.u = (DAT_004a06b8 - (((e->f0 - DAT_004a06a8) - DAT_004a06ac) - e->f4)) / DAT_004a06b8;
                hulk_freg u;
                if (1.0f < f.u)
                    u = 1.0f;
                else if (0.0f < f.u)
                    u = f.u;
                else
                    u = 0.0f;
                alpha = (int)(u * 255.0f);
            }
            f.v[f.n].color = (alpha << 24) | 0xfef618;
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
            (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d00(e->obj2);
            f.a.FUN_000f81b0(e->obj, DAT_004ddf98, f7d4);
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
        }
    }
    float *tbl = ((float*)&DAT_0040b158);
    Rec_d5b20 *rec = ((Rec_d5b20*)&DAT_004ddfcc);
    for (int k = 0; (Rec_d5b20 *)rec < (Rec_d5b20 *)&(*(float*)&DAT_004ddff0); k++, rec++, tbl++) {
        Item_d5b20 *it = &items[k];
        if (it->f0 < (*(float*)&DAT_004ddff0)) {
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
            (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d00(rec);
            if (it->f4 + 0.5f > it->f0) {
                f.v[f.n].a = f7b4 * *tbl;
                f.v[f.n].b = 0;
                f.v[f.n].c = 1;
                unsigned int col = it->color;
                if (it->f0 >= it->f4) {
                    int a = 0xff - (int)((it->f0 - it->f4) * 510.0f);
                    col = ((unsigned int)a << 24) | (col & 0xffffff);
                }
                f.v[f.n].color = col;
                f.a.FUN_000f81b0(it, 0, f7d4);
            }
            if (it->f0 < 1.0f) {
                Obj24_d5b20 *o = owner->p24;
                if (o) {
                    double q = 14.0f / o->v7();
                    double tf = *tbl * f7b4; // MSVC would reassociate the product
                    f.s = tf * q;
                    f.t1 = o->v10(it) * f.s;
                    f.s = o->v9(it) * f.s;
                    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v15(0);
                    (*(Ctx_d5b20**)&DAT_0052c2ac)->FUN_00293d40(f.t1 * 0.5f, f.s * -0.5f, 0);
                    f.v[f.n].a = (1.0f + it->f0) * *tbl * f7b4;
                    f.v[f.n].b = 1;
                    f.v[f.n].c = 2;
                    int a = (int)(it->f0 * 255.0f);
                    f.v[f.n].color = ((unsigned int)(-1 - a) << 24) | (it->color & 0xffffff);
                    f.a.FUN_000f81b0(it, 0, 0);
                    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
                }
            }
            (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
        }
    }
    (*(Ctx_d5b20**)&DAT_0052c2ac)->dev->v16(0);
    f.a.FUN_000f78e0();
}
