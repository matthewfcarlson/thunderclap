// STATUS: equivalent (tools/equiv.py level 3: 321 inputs, branch coverage 46/48, incomplete)
// MapThing::vfunc_5 @ 0x000ec360
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
typedef unsigned __int64 u64;
extern "C" double sin(double);
extern "C" double atan2(double y, double x);

struct V2 { float x, y; };
struct V3 { float x, y, z; };

class MapThing;

struct KHold;
struct Parent {
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13();
    virtual void v14(V3 *out, MapThing *who);
    virtual void v15(V2 *out, MapThing *who);
    virtual float v16(MapThing *who);
    virtual float v17(MapThing *who);
    int pad4;
    struct KHold *f8;
};

struct KObj {
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3(); virtual void k4(); virtual void k5(); virtual void k6(); virtual void k7(); virtual void k8(); virtual void k9(); virtual void k10(); virtual void k11(); virtual void k12(); virtual void k13(); virtual void k14(); virtual void k15(); virtual void k16(); virtual void k17(); virtual void k18(); virtual void k19(); virtual void k20(); virtual void k21(); virtual void k22(); virtual void k23(); virtual void k24(); virtual void k25(); virtual void k26(); virtual void k27(); virtual void k28(); virtual void k29(); virtual void k30(); virtual void k31(); virtual void k32(); virtual void k33(); virtual void k34(); virtual void k35(); virtual void k36(); virtual void k37(); virtual void k38(); virtual void k39(); virtual void k40(); virtual void k41(); virtual void k42(); virtual void k43();
    virtual int v44();
};

struct KHold {
    char pad0[4];
    KObj *f4;
};

struct VBuf {
    char pad0[8];
    V3 *pos;
    char padc[4];
    unsigned int *color;
    V2 *uv;
    void FUN_0008ef00();
};

struct Gfx {
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15(); virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19(); virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23(); virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual void g29();
    virtual VBuf *v30(void *a, int b, int c, int d, int e);
    virtual void v31(VBuf *vb);
};

struct Dev {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Render {
    Dev *dev;
    void FUN_00293d00(const V3 *v);
    void FUN_00293d40(float a, float b, float c);
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293c50(float a);
};

struct Sprite {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void v8(int a, int b);
};

struct Item {
    int id;
    float x;
    float f8;
    float z;
};

struct Surf {
    char pad0[0x10];
    void *f10;
};

struct Map {
    char pad0[0x24];
    float xlo;                       // 0x24
    float zhi;                       // 0x28
    float xhi;                       // 0x2c
    float zlo;                       // 0x30
    float scale;                     // 0x34
    char pad38[0x22c - 0x38];
    Sprite *tbl[10];                 // 0x22c
    Surf *FUN_000c7b60();
    int *FUN_000c8540();
    int FUN_000c8180();
    Item *FUN_000c8190(int i);
};

struct Pick {
    void FUN_000352b0(V3 *out);
    void FUN_00035550(V3 *out);
};

struct Pickers {
    char pad0[0x20];
    Pick *FUN_00024280(u64 name);
};

struct MapSrc {
    Map *FUN_000cae70();
};

struct MapHolder {
    char pad0[8];
    MapSrc *f8;
};

struct Clock {
    float FUN_00085f80();
};

struct World {
    char pad0[0x20];
    Pickers *f20;
    char pad24[0x3c - 0x24];
    MapHolder *f3c;
    char pad40[0x58 - 0x40];
    Clock *f58;
};

struct Ent {
    int e0;
    float val;
    int zero;
    int two;
};

struct Loc1 {
    int hdr;
    Ent e[8];
    int pad84;
    int cur;
    int pad8c;
    void FUN_000f7fe0(int k);
    void FUN_000f78e0();
};

struct Loc2 {
    int c0;
    char pad4[0x20];
    void FUN_000f7930();
    void FUN_000f8500(const char *s, int k, int one);
    void FUN_000f7960();
};

struct Frame {
    int s10;                         // S+0x10
    int s14;
    float s18;
    float s1c;
    float xlo;                       // 0x20
    float zhi;                       // 0x24
    V2 wh;                           // 0x28
    int pad30;
    float xhi;                       // 0x34
    float zlo;                       // 0x38
    float spanX;                     // 0x3c
    float spanZ;                     // 0x40
    int s44;
    V3 l48;                          // 0x48
    V3 l54;                          // 0x54
    V3 l60;                          // 0x60
    Loc2 loc2;                       // 0x6c
    Loc1 loc1;                       // 0x90
};

#define EMIT(X, Y, Z, U, V) { V3 *pp_ = vb->pos; pp_->z = (Z); pp_->x = (X); pp_->y = (Y); unsigned int *cp_ = vb->color; *cp_ = 0x96ffffff; V2 *up_ = vb->uv; up_->x = (U); up_->y = (V); vb->FUN_0008ef00(); }

class MapThing {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void vfunc_5();
    char pad4[0x14 - 0x4];
    Parent *f14;
    char pad18[0x74 - 0x18];
    unsigned char b74;
    char pad75[0xa4 - 0x75];
    int fa4;
    char pada8[0x118 - 0xa8];
    int f118;
};

void MapThing::vfunc_5()
{
    if (b74 == 0)
        return;
    Frame f;
    int k = f14->f8->f4->v44();
    Map *map = DAT_004dd700->f3c->f8->FUN_000cae70();
    f.s18 = map->scale;
    f14->v15(&f.wh, this);
    f.wh.x = f.wh.y * f.s18;
    Surf *s = map->FUN_000c7b60();
    if (s != 0) {
        (*(Render**)&DAT_0052c2ac)->dev->v15(0);
        f14->v14(&f.l48, this);
        (*(Render**)&DAT_0052c2ac)->FUN_00293d00(&f.l48);
        VBuf *vb = DAT_0052c2a8->v30(s->f10, 1, 0x2021, 4, 0);
        EMIT(f.wh.x * -0.5f, f.wh.y * -0.5f, 0.0f, 0.0f, 0.0f);
        EMIT(f.wh.x * -0.5f, f.wh.y * 0.5f, 0.0f, 0.0f, 1.0f);
        EMIT(f.wh.x * 0.5f, f.wh.y * -0.5f, 0.0f, 1.0f, 0.0f);
        EMIT(f.wh.x * 0.5f, f.wh.y * 0.5f, 0.0f, 1.0f, 1.0f);
        DAT_0052c2a8->v31(vb);
        (*(Render**)&DAT_0052c2ac)->dev->v16(0);
    }

    f.loc1.FUN_000f7fe0(k);
    f.loc1.e[f.loc1.cur].two = 2;
    f.loc1.e[f.loc1.cur].zero = 0;
    f.s18 = f14->v17(this);
    float prod = f14->v16(this) * f.s18;
    f.loc1.e[f.loc1.cur].val = prod;
    (*(Render**)&DAT_0052c2ac)->dev->v15(0);
    f14->v14(&f.l48, this);
    (*(Render**)&DAT_0052c2ac)->FUN_00293d00(&f.l48);
    f.loc2.FUN_000f7930();
    f.loc2.FUN_000f8500("SELECT Destination", k, 1);
    f.loc2.c0 = fa4;
    (*(Render**)&DAT_0052c2ac)->dev->v16(0);

    float g1 = DAT_004dd700->f58->FUN_00085f80() * 16.0f + DAT_004de98c;
    DAT_004de98c = g1;
    if (g1 > 6.2831855f)
        DAT_004de98c = DAT_004de98c - 6.2831855f;
    float g2 = DAT_004dd700->f58->FUN_00085f80() * 4.0f + DAT_004de988;
    DAT_004de988 = g2;
    if (g2 > 6.2831855f)
        DAT_004de988 = DAT_004de988 - 6.2831855f;

    Sprite *keep = map->tbl[0];
    if (map->tbl[6] != 0 && keep != 0) {
        f.xlo = map->xlo;
        f.zhi = map->zhi;
        f.xhi = map->xhi;
        f.zlo = map->zlo;
        f.spanX = f.xhi - f.xlo;
        f.spanZ = f.zlo - f.zhi;
        (*(Render**)&DAT_0052c2ac)->dev->v15(0);
        f14->v14(&f.l60, this);
        (*(Render**)&DAT_0052c2ac)->FUN_00293d00(&f.l60);
        int *ids = map->FUN_000c8540();
        if (*ids != -1) {
            do {
                int idx;
                for (idx = 0; idx < map->FUN_000c8180(); idx++) {
                    Item *it = map->FUN_000c8190(idx);
                    if (it == 0)
                        continue;
                    if (it->id != *ids)
                        continue;
                    if (!(it->x > f.xlo))
                        continue;
                    if (!(it->z > f.zlo))
                        continue;
                    if (!(it->x < f.xhi))
                        continue;
                    if (!(it->z < f.zhi))
                        continue;
                    (*(Render**)&DAT_0052c2ac)->dev->v15(0);
                    float a2 = ((f.zhi - it->z) / f.spanZ + 0.5f) * f.wh.y;
                    float a1 = ((it->x - f.xhi) / f.spanX + 0.5f) * f.wh.x;
                    (*(Render**)&DAT_0052c2ac)->FUN_00293d40(a1, a2, 0.0f);
                    if (idx == f118) {
                        f.s1c = (float)sin(DAT_004de98c) * 0.05f + 0.4f;
                        (*(Render**)&DAT_0052c2ac)->FUN_00293da0(f.s1c, f.s1c, f.s1c);
                    } else if (f118 == -1 && (it->id == 9 || it->id == 8)) {
                        f.s1c = (float)sin(DAT_004de988) * 0.025f + 0.25f;
                        (*(Render**)&DAT_0052c2ac)->FUN_00293da0(f.s1c, f.s1c, f.s1c);
                    } else {
                        (*(Render**)&DAT_0052c2ac)->FUN_00293da0(0.275f, 0.275f, 0.275f);
                    }
                    map->tbl[it->id]->v8(0, 0);
                    (*(Render**)&DAT_0052c2ac)->dev->v16(0);
                }
                ids++;
            } while (*ids != -1);
        }

        Pickers *pks = DAT_004dd700->f20;
        Pick *pk = pks->FUN_00024280(FUN_0027b020("hulk"));
        pk->FUN_000352b0(&f.l54);
        if (f.l54.x > f.xlo && f.l54.z > f.zlo && f.l54.x < f.xhi && f.l54.z < f.zhi) {
            pk->FUN_00035550(&f.l48);
            float nz = f.l48.z;
            float nx = f.l48.x;
            float a2 = ((f.zhi - f.l54.z) / f.spanZ + 0.5f) * f.wh.y;
            float a1 = ((f.l54.x - f.xhi) / f.spanX + 0.5f) * f.wh.x;
            (*(Render**)&DAT_0052c2ac)->FUN_00293d40(a1, a2, 0.0f);
            (*(Render**)&DAT_0052c2ac)->FUN_00293c50((float)atan2(nz, nx) - 1.5707964f);
            (*(Render**)&DAT_0052c2ac)->FUN_00293da0(0.3f, 0.3f, 0.3f);
            keep->v8(0, 0);
        }
        (*(Render**)&DAT_0052c2ac)->dev->v16(0);
    }
    f.loc2.FUN_000f7960();
    f.loc1.FUN_000f78e0();
}
