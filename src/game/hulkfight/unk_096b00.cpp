// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00096b00..0x00098420 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe8da7f1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe8da7f1 {} using namespace fn_fe8da7f1;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_fe8da7f1 {
struct Helper_96b00 {
    char pad[8];
};
struct Obj_96b00 {
    char pad0[8];
    Helper_96b00* helper;
    int state;
    char pad10[0x40];
    int a;
    int b;
    int c;
};
struct Vec3_96b50 { float x, y, z; };
struct Part_96b50 { char pad[0x1b0]; int f1b0; };
struct Prop_96b50 {
    char pad0[0x10];
    int kind;
    char pad1[0x28 - 0x14];
    unsigned int flags;
    char pad2[0x64 - 0x2c];
    Vec3_96b50 pos;
};
struct Actor_96b50 {
    char pad0[0xfc];
    int mode;
    char pad1[0x11c - 0x100];
    Part_96b50 *part;
    char pad2[0x148 - 0x120];
    Actor_96b50 *parent;
    char pad3[0x1b0c - 0x14c];
    float f1b0c;
    char pad4[0x20b0 - 0x1b10];
    int busy;
    bool FUN_001d6980();
    int FUN_001d73f0();
    void FUN_001d69f0(Vec3_96b50 *out);
    int FUN_00035cf0();
    void FUN_000350c0(Vec3_96b50 *out);
};
struct Checker_96b50 {
    char pad[0x20];
};
} // namespace fn_fe8da7f1
struct World {
    char pad[0x20];
    Checker_96b50 *checker;
};
namespace fn_fe8da7f1 {
struct Event_96b50 {
    char pad0[8];
    union {
        Prop_96b50 *prop;
        Actor_96b50 *actor;
    } target;
    int type;
};
struct Vec3_96ce0 {
    int x, y, z;
};
class Provider_96ce0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual Vec3_96ce0* Get();
};
struct Holder_96ce0 {
    char pad[0x20];
    Provider_96ce0* p;
};
class Obj_96ce0 {
  public:
    char pad0[0x40];
    int x, y, z;
    char pad1[0x28];
    Holder_96ce0* h;
};
extern "C" void FUN_00267760(unsigned int, unsigned int, const char*, ...);
struct Id64_96e50 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af30(Id64_96e50* src);
    void FUN_0027af50();
    void FUN_0027af70(Id64_96e50* src);
    Id64_96e50* FUN_0027b0e0(const char* name);
};
extern "C" unsigned __int64 __cdecl FUN_00096d80(const char* hex);
extern "C" unsigned __int64 f1(unsigned int);
extern "C" unsigned __int64 f2(unsigned int, unsigned __int64);
extern "C" int f3_00267760(char*, unsigned int, const char*, ...);
extern "C" unsigned __int64 __cdecl getval_002672f0(int, int, int);
extern "C" int __cdecl fmt_00267760(char*, int, const char*, ...);
struct Vec3_96f40 {
    float x, y, z;
};
struct Plane_96f40 {
    float nx, ny, nz, d;
    void FUN_0022dfe0(const Vec3_96f40 *a, const Vec3_96f40 *b, const Vec3_96f40 *c);
    char FUN_0022e1f0(const Vec3_96f40 *from, const Vec3_96f40 *to, float *t);
};
struct Vec3_970f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
hulk_freg __cdecl FUN_000189c0(float v);
hulk_freg __cdecl FUN_00018a20(float cosine);
struct V3_97540 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_00018990();
};
struct Stats_97540 {
    char pad0[0x148];
    Stats_97540 *f148;
    char FUN_00035660(V3_97540 *out);
};
struct Ent_97540 {
    char pad0[8];
    Stats_97540 *f8;
    int kind;
    char pad10[0x50 - 0x10];
    V3_97540 pos;
};
class Level_97540 {
public:
    char FUN_00039440(Ent_97540 *e, V3_97540 *h, float *o, int z);
};
double __cdecl FUN_00097290(V3_97540 a, V3_97540 b);
union PtrOrFloat3 {
    V3_97540 *p;
    float f;
};
union EntOrFloat {
    Ent_97540 *e;
    float f;
};
struct V3_97a30 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_000111b0(const V3_97a30 *a, const V3_97a30 *b);
    hulk_freg FUN_000111f0();
};
struct Mat_97a30 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_97a30 *axis, float angle);
};
struct Rng_97a30 {
    hulk_freg FUN_000787e0(float lo, float hi);
};
extern "C" bool __cdecl FUN_00096b50(void *, void *, int *);
extern "C" void __cdecl FUN_00096b00(void *, int *);
extern "C" float __cdecl FUN_00018710(float *k, float *len);
void __cdecl FUN_00224d70(float angle, V3_97a30 *v);
union FU_97a30 {
    float f;
    unsigned int u;
};
struct Frame_97a30 {
    float s;            // 0x00
    V3_97a30 v;               // 0x04
    float len;          // 0x10
    V3_97a30 r;               // 0x14
    V3_97a30 p;               // 0x20
    V3_97a30 w;               // 0x2c
    union {
        int err;
        float k;
    } u38;              // 0x38
    V3_97a30 axis;            // 0x3c
    V3_97a30 cross;           // 0x48
    Mat_97a30 m;              // 0x54
};
struct V3_98190 {
    float x, y, z;
};
struct Mat_98190 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_98190 *axis, float angle);
};
int __cdecl FUN_00097a30(int a1, float a2, int a3, int a4, int a5, int a6, int a7, V3_98190 *b, int a9, int a10, int a11, int a12);
struct Helper_98380 {
};
class CamInit {
  public:
    void InitBase_000a9400();
};
class CamSetup {
  public:
    void SetupPart_000a9050();
};
class CamCfg {
  public:
};
struct Blend_983d0 {
    hulk_intptr vft;
    char pad04[0x8 - 4];
    char cfg08[0xd0 - 0x8];
    int fieldd0;
    char padd4[0x170 - 0xd4];
    int field170;
    int field174;
    char pad178[0x17c - 0x178];
    int field17c;
    char pad180[0x1a8 - 0x180];
    int field1a8;
};


// 0x00096b00 FUN_00096b00 (72 B): matches/0x00096b00.cpp
// sym: _FUN_00096b00
extern "C" void __cdecl FUN_00096b00(void * self, int* out) {
    int n = ((Obj_96b00 *)self)->state;
    --n;
    if (n != 0) {
        out[0] = ((Obj_96b00 *)self)->a;
        out[1] = ((Obj_96b00 *)self)->b;
        out[2] = ((Obj_96b00 *)self)->c;
        return;
    }
    if (!((owners::C_35660 *)(((Obj_96b00 *)self)->helper))->FUN_00035660((int *)out)) {
        out[0] = ((Obj_96b00 *)self)->a;
        out[1] = ((Obj_96b00 *)self)->b;
        out[2] = ((Obj_96b00 *)self)->c;
    }
}


// 0x00096b50 FUN_00096b50 (389 B): equivalent/0x00096b50.cpp
// sym: _FUN_00096b50
// STATUS: equivalent (tools/equiv.py level 3: 189 inputs, branch coverage 48/48)
// FUN_00096b50 @ 0x00096b50
extern "C" bool FUN_00096b50(void *ev, void * out_, int *result)
{
    Vec3_96b50 * out = (Vec3_96b50 *)out_;
    *result = -10;
    if (((Event_96b50 *)ev) == 0) return false;
    if (((Event_96b50 *)ev)->type == 1) {
        Actor_96b50 *a = ((Event_96b50 *)ev)->target.actor;
        if (a == 0) return false;
        if (a->busy != 0) return false;
        if (a->part == 0) return false;
        if (a->part->f1b0 == 0) return false;
        Checker_96b50 *c = DAT_004dd700->checker;
        if (((owners::Obj_24540 *)c)->FUN_00024540((hulk_intptr)(Actor_96b50 *)a)) return false;
        a->FUN_000350c0(out);
        *result = a->FUN_00035cf0();
        return true;
    }
    if (((Event_96b50 *)ev)->type == 5) {
        Actor_96b50 *a = ((Event_96b50 *)ev)->target.actor;
        if (a == 0) return false;
        if (a->mode == 2 || a->mode == 3 || a->mode == 1) return false;
        if (!((owners::Self_1d7450 *)a)->FUN_001d7450()) return false;
        if (a->FUN_001d6980()) return false;
        Actor_96b50 *p = a->parent;
        if (p != 0) {
            if (p->busy != 0) return false;
            if (p->f1b0c <= 0.0f) return false;
            if (p->part == 0) return false;
            if (p->part->f1b0 == 0) return false;
            *result = p->FUN_00035cf0();
            a->FUN_001d69f0(out);
            return true;
        }
        *result = a->FUN_001d73f0();
        a->FUN_001d69f0(out);
        return true;
    }
    if (((Event_96b50 *)ev)->type == 7) {
        Prop_96b50 *p = ((Event_96b50 *)ev)->target.prop;
        if (p == 0) return false;
        if ((p->flags >> 7) & 1) return false;
        if (p->kind == 5 || p->kind == 6) return false;
        *out = p->pos;
        *result = -9;
        return true;
    }
    return false;
}


// 0x00096ce0 FUN_00096ce0 (94 B): matches/0x00096ce0.cpp
// sym: _FUN_00096ce0
extern "C" bool FUN_00096ce0(Obj_96ce0* self, Vec3_96ce0* out, int* scalar) {
    bool r = false;
    Holder_96ce0* h = self->h;
    if (h && h->p) {
        Provider_96ce0* p = h->p;
        Vec3_96ce0* v = p->Get();
        out->x = v->x;
        out->y = v->y;
        out->z = v->z;
        *scalar = *(int*)((char*)p + 0x34);
        r = true;
    } else {
        out->x = self->x;
        out->y = self->y;
        out->z = self->z;
        *scalar = 0x3f800000;
    }
    return r;
}


// 0x00096d50 FUN_00096d50 (34 B): matches/0x00096d50.cpp
// sym: _FUN_00096d50
extern "C" void FUN_00096d50(hulk_uintptr p1, unsigned int p2, unsigned int p3, unsigned int p4) {
    FUN_00267760(p1, p2, (const char*)((hulk_intptr)((char*)&DAT_00404adc)), p4, p3);
}


// 0x00096e50 FUN_00096e50 (113 B): equivalent/0x00096e50.cpp
// sym: _FUN_00096e50
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// FUN_00096e50 @ 0x00096e50
// Builds an Id64 from a name, or from a "0x..." literal.
extern "C" Id64_96e50* FUN_00096e50(Id64_96e50* result, const char* text)
{
    Id64_96e50 id;
    Id64_96e50 tmp;
    id.FUN_0027af00();
    if (text != 0) {
        Id64_96e50* parsed;
        if (text[0] == '0' && text[1] == 'x') {
            unsigned __int64 v = FUN_00096d80(text);
            parsed = ((Id64_96e50 *)((owners::Pair_27af10 *)&tmp)->FUN_0027af10((unsigned int)v, (unsigned int)(v >> 32)));
        } else {
            parsed = tmp.FUN_0027b0e0(text);
        }
        id.FUN_0027af70(parsed);
        tmp.FUN_0027af50();
    }
    result->FUN_0027af30(&id);
    id.FUN_0027af50();
    return result;
}


// 0x00096ed0 FUN_00096ed0 (50 B): matches/0x00096ed0.cpp
// sym: _FUN_00096ed0
// data: buf = DAT_004dd948, fmt = DAT_00404adc
extern "C" char* FUN_00096ed0(unsigned int a, unsigned int b) {
    unsigned __int64 n = f2(b, f1(a));
    f3_00267760(((char*)&DAT_004dd948), 64, DAT_00404adc, (unsigned int)(n >> 32), (unsigned int)n);
    return ((char*)&DAT_004dd948);
}


// 0x00096f10 FUN_00096f10 (42 B): matches/0x00096f10.cpp
// sym: _FUN_00096f10
// data: buf = DAT_004dd988
extern "C" char* __cdecl FUN_00096f10(int x) {
    unsigned __int64 v = getval_002672f0(x, 0, 0);
    fmt_00267760(((char*)&DAT_004dd988), 64, "0x%08x%08x", (unsigned)(v >> 32), (unsigned)v);
    return ((char*)&DAT_004dd988);
}


// 0x00096f40 FUN_00096f40 (418 B): equivalent/0x00096f40.cpp
// sym: ?FUN_00096f40@fn_fe8da7f1@@YADUVec3_96f40@1@000@Z
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8; --wine 601 inputs)
// FUN_00096f40 @ 0x00096f40
char FUN_00096f40(Vec3_96f40 v1, Vec3_96f40 v2, Vec3_96f40 v3, Vec3_96f40 v4)
{
    Plane_96f40 plane;
    float t;
    Vec3_96f40 up;
    up.x = v3.x;
    up.y = v3.y + 1.0f;
    up.z = v3.z;
    plane.FUN_0022dfe0(&v3, &up, &v4);
    if (!plane.FUN_0022e1f0(&v1, &v2, &t))
        return 0;

    Vec3_96f40 d;
    d.x = v2.x - v1.x;
    d.y = v2.y - v1.y;
    d.z = v2.z - v1.z;
    hulk_freg dtx = d.x * t;
    hulk_freg dty = d.y * t;
    float dtz = d.z * t;
    Vec3_96f40 q;
    q.x = v1.x + dtx;
    hulk_freg qy = v1.y + dty;
    q.z = v1.z + dtz;
    if (qy < v3.y)
        return 0;

    hulk_freg ex = v4.x - v3.x;
    hulk_freg ey = v4.y - v3.y;
    hulk_freg ez = v4.z - v3.z;
    hulk_freg lenSq = ez * ez + ey * ey + ex * ex;

    hulk_freg gx = q.x - v3.x;
    hulk_freg gy = 0.0f;
    hulk_freg gz = q.z - v3.z;
    float hx = q.x - v4.x;
    float hy = v3.y - v4.y;
    float hz = q.z - v4.z;
    if (lenSq < gz * gz + gy * gy + gx * gx)
        return 0;
    if (lenSq < hz * hz + hy * hy + hx * hx)
        return 0;
    return 1;
}


// 0x000970f0 FUN_000970f0 (406 B): equivalent/0x000970f0.cpp
// sym: ?FUN_000970f0@fn_fe8da7f1@@YAMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20059 inputs, branch coverage 17/20, incomplete)
// FUN_000970f0 @ 0x000970f0
hulk_freg FUN_000970f0(float x, float z)
{
    if (fabs(x) <= 1e-5f && fabs(z) <= 1e-5f)
        return 0.0f;

    Vec3_970f0 v;
    v.x = x;
    v.y = 0.0f;
    v.z = z;
    v.FUN_0022d110();

    hulk_freg a = v.z * 0.0f - v.y;
    hulk_freg b = v.x - v.z * 0.0f;
    hulk_freg c = v.y * 0.0f - v.x * 0.0f;
    hulk_freg m = sqrt(c * c + b * b + a * a);

    hulk_freg angle;
    if (fabs(m - 1.0f) <= 1e-5f)
        angle = 90.0f;
    else
        angle = FUN_000189c0(m) * 57.2957764f;

    if (x >= 0.0f) {
        if (z >= 0.0f)
            angle = angle + 270.0f;
        else if (z < 0.0f)
            angle = 90.0f - angle;
    } else if (x < 0.0f) {
        if (z < 0.0f)
            angle = angle + 90.0f;
        else if (z >= 0.0f)
            angle = 270.0f - angle;
    }
    if (angle == 360.0f)
        angle = 0.0f;
    return angle;
}


// 0x00097290 FUN_00097290 (133 B): equivalent/0x00097290.cpp
// sym: ?FUN_00097290@fn_fe8da7f1@@YAMMMMMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// FUN_00097290 @ 0x00097290
hulk_freg FUN_00097290(float ax, float ay, float az, float bx, float by, float bz)
{
    double lenB = sqrt(bz * bz + by * by + bx * bx);
    double lenA = sqrt(az * az + ay * ay + ax * ax);
    double product = lenA * lenB;
    if (product <= 0.0f)
        return 0.0f;
    return FUN_00018a20((float)((bz * az + by * ay + bx * ax) / product));
}


// 0x00097320 FUN_00097320 (294 B): equivalent/0x00097320.cpp
// sym: ?FUN_00097320@fn_fe8da7f1@@YAMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 14/14)
// FUN_00097320 @ 0x00097320
hulk_freg __cdecl FUN_00097320(float a, float b) {
    bool negative = a < 0.0f;
    double magnitude = negative ? -(double)a : (double)a;
    int whole = (int)magnitude;
    double na = (magnitude - whole) + (whole % 360);
    if (negative) na = 360.0f - na;
    volatile float ar = (hulk_freg)na; // the original reloads the rounded copy from its frame slot
    negative = b < 0.0f;
    magnitude = negative ? -(double)b : (double)b;
    whole = (int)magnitude;
    double nb = (magnitude - whole) + (whole % 360);
    if (negative) nb = 360.0f - nb;
    hulk_freg br = (hulk_freg)nb;
    float direct = (hulk_freg)(nb - ar);
    if (nb > 180.0f) br = (hulk_freg)(nb - 360.0f);
    if (ar > 180.0f) na = (double)ar - 360.0f;
    double wrapped = (double)br - na;
    hulk_freg wr = (hulk_freg)wrapped;
    union Bits { float f; unsigned int u; } x,y;
    x.f = direct; x.u &= 0x7fffffff;
    y.f = wr; y.u &= 0x7fffffff;
    if (x.f < y.f) return direct;
    return (hulk_freg)wrapped;
}


// 0x00097540 FUN_00097540 (1255 B): equivalent/0x00097540.cpp
// sym: _FUN_00097540
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 30/30)
// FUN_00097540 @ 0x00097540
extern "C" char FUN_00097540(Level_97540 *a1, V3_97540 *a2, V3_97540 *a3, float a4, float a5, Ent_97540 *a6, V3_97540 *a7, V3_97540 *a8, char a9)
{
    struct Frame {
        float s0;
        V3_97540 w;
        V3_97540 d;
        V3_97540 hpos;
        V3_97540 q3;
        V3_97540 c34;
        V3_97540 c40;
        V3_97540 c4c;
        V3_97540 u;
    } f;

    V3_97540 *dir = a3;
    float hd;
    float hdist;
    a7->x = a4 * dir->x;
    a7->y = a4 * dir->y;
    a7->z = a4 * dir->z;
    Ent_97540 *ent = a6;
    if (ent == 0)
        return 0;
    if (!a1->FUN_00039440(ent, &f.hpos, &f.s0, 0))
        return 0;
    if (a8 != 0) {
        a8->x = f.hpos.x;
        a8->y = f.hpos.y;
        a8->z = f.hpos.z;
    }
    V3_97540 *org = a2;
    f.d.x = f.hpos.x - org->x;
    f.c40.x = f.d.x;
    f.d.y = f.hpos.y - org->y;
    f.c40.y = f.d.y;
    f.d.z = f.hpos.z - org->z;
    f.c40.z = f.d.z;
    hdist = (float)sqrt(f.c40.z * f.c40.z + f.c40.x * f.c40.x);
    f.d.FUN_0022d110();
    a7->x = (float)(f.d.x * a4);
    f.c40.x = a7->x;
    a7->y = f.d.y * a4;
    double zp = (double)f.d.z * a4;
    a7->z = (float)zp;
    hd = (float)sqrt(zp * zp + (double)f.c40.x * f.c40.x);
    if (!(hdist > 3.0f))
        return 1;
    if (!(hd > 1.0f))
        return 1;

    f.w = ent->pos;
    if (ent->kind == 1) {
        ent->f8->FUN_00035660(&f.w);
    } else if (ent->kind == 5) {
        Stats_97540 *s = ent->f8->f148;
        if (s != 0)
            s->FUN_00035660(&f.w);
    }
    double lsq = f.w.z * f.w.z + f.w.y * f.w.y + f.w.x * f.w.x;
    if (lsq > 225.0f) {
        f.w.FUN_0022d110();
        f.w.x = f.w.x * 15.0f;
        f.w.y = f.w.y * 15.0f;
        f.w.z = f.w.z * 15.0f;
    }
    f.c4c = f.w;
    f.c34.x = org->x;
    f.c34.x = f.c34.x - f.hpos.x;
    f.c34.y = org->y;
    f.c34.z = org->z;
    f.c34.y = f.c34.y - f.hpos.y;
    f.c34.z = f.c34.z - f.hpos.z;
    f.u.x = f.c34.x;
    f.u.y = 0.0f;
    f.u.z = f.c34.z;
    f.u.FUN_0022d110();
    double v = f.c4c.z * f.u.z + f.c4c.x * f.u.x + f.u.y * 0.0f + hd;
    if (v < 1.0)
        v = 1.0;
    double ratio = hdist / v;
    float t;
    if (ratio < 30.0)
        t = (float)ratio;
    else
        t = 30.0f;

    f.c34.x = f.hpos.x;
    f.c34.z = f.hpos.z;
    f.c34.y = f.hpos.y;
    f.c34.y = 0.0f;
    f.w.x = f.w.x * t;
    f.w.y = f.w.y * t;
    f.w.z = f.w.z * t;
    f.c4c.x = f.w.x + f.hpos.x;
    f.c4c.y = f.w.y + f.hpos.y;
    f.c4c.z = f.w.z + f.hpos.z;
    f.c40.x = f.c4c.x;
    f.c40.y = 0.0f;
    f.c40.z = f.c4c.z;
    f.c40.x = f.c40.x - org->x;
    f.c40.z = f.c40.z - org->z;
    f.c34.x = f.c34.x - org->x;
    f.c34.z = f.c34.z - org->z;
    double ret = FUN_00097290(f.c40, f.c34);
    if (ret > 45.0f)
        return 1;

    if (a8 != 0) {
        a8->x = f.c4c.x;
        a8->y = f.c4c.y;
        a8->z = f.c4c.z;
    }
    f.q3.x = f.c4c.x - org->x;
    f.q3.y = f.c4c.y - org->y;
    f.q3.z = f.c4c.z - org->z;
    f.c40.x = f.q3.x;
    f.c4c.x = f.q3.x;
    f.c40.y = f.q3.y;
    f.c4c.y = 0.0f;
    f.c4c.z = f.q3.z;
    f.c4c.y = 0.0f;
    if (f.c4c.FUN_00018990() < 2.0f)
        return 1;
    f.q3.FUN_0022d110();
    ((owners::Vec3_95e80 *)a7)->FUN_00095e80(a4, (float const *)(const V3_97540 *)(&f.q3));
    if (a9) {
        a7->y = (float)(((double)t * t * a5 * 0.5f + f.c40.y) / t);
    }
    return 1;
}


// 0x00097a30 FUN_00097a30 (1841 B): equivalent/0x00097a30.cpp
// sym: ?FUN_00097a30@fn_fe8da7f1@@YAHMMMPAXMPAUV3_97a30@1@M1MMMH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 54/54)
// FUN_00097a30 @ 0x00097a30
int __cdecl FUN_00097a30(float a0, float a1, float a2, void *a3, float a4, V3_97a30 *a5, float a6, V3_97a30 *a7,
                         float a8, float a9, float a10, int a11)
{
    Frame_97a30 f;
    int mode;

    f.v.x = 0.0f;
    f.v.y = 0.0f;
    f.v.z = 0.0f;
    if (!FUN_00096b50(a3, (V3_97a30 *)(&f.v), &f.u38.err))
        return a11;
    f.v.y = f.v.y + a4;

    mode = a11;
    if (a9 != 0.0f && a10 != 0.0f) {
        Rng_97a30 *rng = (*(Rng_97a30**)&DAT_004e5acc);
        if (mode == 1)
            mode = ((owners::Random_11380 *)rng)->FUN_00011380(2, 0xb);
        switch (mode) {
        case 2:
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            break;
        case 3:
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            break;
        case 4:
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            break;
        case 5:
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            break;
        case 6:
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            break;
        case 7:
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            break;
        case 8:
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            f.v.z = rng->FUN_000787e0(a9, a10) + f.v.z;
            break;
        case 9:
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            f.v.z = f.v.z - rng->FUN_000787e0(a9, a10);
            break;
        case 10:
            f.v.x = rng->FUN_000787e0(a9, a10) + f.v.x;
            break;
        case 11:
            f.v.x = f.v.x - rng->FUN_000787e0(a9, a10);
            break;
        default:
            break;
        }
    }

    f.w.x = f.v.x - a5->x;
    f.w.y = f.v.y - a5->y;
    f.w.z = f.v.z - a5->z;
    f.len = f.w.FUN_0022d110();
    if (a8 != 0.0f)
        FUN_00224d70(a8, &f.w);

    if (f.w.x * a7->x + f.w.y * a7->y + f.w.z * a7->z < a2)
        return 0;
    *a7 = f.w;
    if (a0 <= 0.0f)
        return mode;
    if (a1 <= 0.0f)
        return mode;

    f.s = f.len / a0;
    f.r.x = 0.0f;
    f.r.y = 0.0f;
    f.r.z = 0.0f;
    FUN_00096b00(a3, (int *)(V3_97a30 *)(&f.r));
    f.r.y = 0.0f;
    double c = f.r.FUN_0022d110();
    if (c > a0)
        c = a0;
    f.r.x = f.r.x * c;
    f.r.y = f.r.y * c;
    double zz = f.r.z * c;
    f.r.z = (float)zz;
    if (f.len > 50.0f) {
        f.u38.k = 1.0f - (f.len - 50.0f) * 0.02f;
        f.len = 0.0f;
        double fac = FUN_00018710(&f.u38.k, &f.len);
        f.r.x = f.r.x * fac;
        f.r.y = f.r.y * fac;
        zz = fac * f.r.z;
    }
    f.r.x = f.r.x * f.s;
    f.r.y = f.r.y * f.s;
    f.r.z = (float)(zz * f.s);

    f.v.x = f.r.x + f.v.x;
    f.p.x = f.v.x;
    f.v.y = f.r.y + f.v.y;
    f.p.y = f.v.y;
    f.v.z = f.r.z + f.v.z;
    f.p.z = f.v.z;
    f.p.x = f.p.x - a5->x;
    f.p.y = f.p.y - a5->y;
    f.p.z = f.p.z - a5->z;
    f.p.FUN_0022d110();
    double dot = f.p.x * a7->x + f.p.z * a7->z + f.p.y * a7->y;

    double sd = f.s * a1;
    f.s = (float)sd;
    if (sd < 0.0f || f.s > 3.14159274f)
        f.s = 3.14159274f;

    if (dot < cos(f.s) - DAT_004dd940) {
        if (dot > DAT_004dd940 - 1.0f) {
            f.axis.FUN_000111b0(&f.p, a7);
            if (f.axis.FUN_000111f0() > 0.0f) {
                f.m.FUN_0022b980();
                f.m.FUN_0022baf0(&f.axis, f.s);
                ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(const V3_97a30 *)a7, (float *)(V3_97a30 *)(&f.p));
            }
        }
    }
    if (a8 == 0.0f) {
        a7->x = f.p.x;
        a7->y = f.p.y;
        a7->z = f.p.z;
    } else {
        a7->y = f.p.y;
    }

    if (a6 <= 0.0f)
        return mode;
    double F = FUN_000189c0(f.p.y);
    f.u38.k = (float)F;
    FU_97a30 q;
    q.f = f.u38.k;
    q.u &= 0x7fffffff;
    f.len = q.f;
    if (!(f.len < a6))
        return mode;
    double sd2 = ((a6 - f.len) / a6) * (f.s * 0.5f);
    f.s = (float)sd2;
    if (sd2 > a6)
        f.s = a6;
    if (f.s > 0.785398185f)
        f.s = 0.785398185f;
    if (f.s + F < 1.57079637f) {
        f.axis.x = 0.0f;
        f.axis.y = 1.0f;
        f.axis.z = 0.0f;
        f.cross.FUN_000111b0(&f.axis, a7);
        f.m.FUN_0022b980();
        f.m.FUN_0022baf0(&f.cross, f.s);
        ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(const V3_97a30 *)a7, (float *)(V3_97a30 *)(&f.p));
        a7->y = f.p.y;
        a7->x = f.p.x;
        a7->z = f.p.z;
        return mode;
    }
    a7->x = 0.0f;
    a7->y = 1.0f;
    a7->z = 0.0f;
    return mode;
}


// 0x00098190 FUN_00098190 (485 B): equivalent/0x00098190.cpp
// sym: _FUN_00098190
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 12/12)
// FUN_00098190 @ 0x00098190
extern "C" int FUN_00098190(float a1, int a2, float a3, int a4, int a5, int a6, int a7, V3_98190 *io, int a9, int a10, int a11)
{
    V3_98190 a = *io;
    V3_98190 b = *io;
    int result = FUN_00097a30(a2, a3, a4, a5, a6, a7, 0, &b, a9, a10, a11, 1);
    if (!result)
        return 0;

    float p = a1 * a3;
    float c;
    if (p < 0.0f || p > 3.14159274f)
        c = -1.0f;
    else
        c = (float)cos(p);
    float dot = b.z * a.z + b.y * a.y + b.x * a.x;
    if (dot >= c - DAT_004dd940) {
        *io = b;
        return result;
    }
    if (!(DAT_004dd940 - 1.0f >= dot)) {
        V3_98190 cross;
        cross.x = a.z * b.y - b.z * a.y;
        cross.y = b.z * a.x - a.z * b.x;
        cross.z = b.x * a.y - b.y * a.x;
        if (cross.z * cross.z + cross.y * cross.y + cross.x * cross.x > 0.0f) {
            Mat_98190 m;
            m.FUN_0022b980();
            m.FUN_0022baf0(&cross, p);
            ((owners::M_22c3b0 *)&m)->FUN_0022c3b0((float *)(const V3_98190 *)(&a), (float *)(V3_98190 *)io);
        }
    }
    return result;
}

} // namespace fn_fe8da7f1

// 0x00098380 FUN_00098380 (41 B): matches/0x00098380.cpp
// sym: ?FUN_00098380@Obj_98380@owners@@QAEXI@Z
void owners::Obj_98380::FUN_00098380(hulk_uintptr arg) {
    owners::Obj_98380 local;
    ((owners::Matrix_22ca90 *)(((Helper_98380*)&local)))->FUN_0022ca90((const owners::Matrix_22ca90 *)(owners :: Obj_98380 *)this, (const owners::Matrix_22ca90 *)(hulk_uintptr)(unsigned int)(((unsigned int)arg)));
    *this = local;
}

namespace fn_fe8da7f1 {

// 0x000983d0 FUN_000983d0 (79 B): matches/0x000983d0.cpp
// sym: @FUN_000983d0@4
// data: gName_983d0 = DAT_0049e108
extern "C" Blend_983d0* __fastcall FUN_000983d0(Blend_983d0* self) {
    char* p;
    CamCfg* c;
    ((CamInit*)self)->InitBase_000a9400();
    self->vft = ((hulk_intptr)DAT_00404b3c);
    p = (char*)&self->field1a8;
    ((CamSetup*)p)->SetupPart_000a9050();
    c = (CamCfg*)self->cfg08;
    const char* n = DAT_0049e108;
    self->fieldd0 = 5;
    ((owners::Target_27b040 *)c)->FUN_0027b040((hulk_uintptr)n);
    *(int*)p = 0;
    self->field174 = 0;
    self->field170 = 0;
    self->field17c = 0;
    return self;
}

} // namespace fn_fe8da7f1
