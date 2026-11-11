// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f8d90..0x002f90c0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fefbc573 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fefbc573 {} using namespace fn_fefbc573;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fefbc573 {
class Inner_2f8e10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int Get();
};
class Outer_2f8e10 {
  public:
    char pad0[4];
    Inner_2f8e10* inner;
    char pad8[12];
    hulk_intptr value;
    bool target(void** out1, int** out2);
};
class Obj_2f8e80 {
  public:
    char pad[0x68];
    unsigned char m68;
    unsigned char m69;
    char p[6];
    unsigned char m70;
};
class Pair_2f8e80 {
  public:
    Obj_2f8e80* a;
    Obj_2f8e80* b;
    int c;
    int d;
    unsigned char e;
    void f();
};

} // namespace fn_fefbc573

// 0x002f8d90 FUN_002f8d90 (119 B): matches/0x002f8d90.cpp
// sym: ?FUN_002f8d90@Thing_2f8d90@owners@@QAEXPAH000H0@Z
void owners::Thing_2f8d90::FUN_002f8d90(int* a, int* c, int* b, int* e, int d, int* f) {
    m[0] = (hulk_intptr)a;
    m[1] = (hulk_intptr)b;
    m[2] = a[4];
    m[3] = b[4];
    m[4] = a[2];
    m[5] = b[2];
    m[11] = c[0];
    m[12] = c[1];
    m[13] = c[2];
    m[14] = e[0];
    m[15] = e[1];
    m[16] = e[2];
    m[9] = d;
    m[6] = f[0];
    m[7] = f[1];
    m[8] = f[2];
    m[10] = 0;
}

namespace fn_fefbc573 {

// 0x002f8e10 FUN_002f8e10 (46 B): matches/0x002f8e10.cpp
// sym: ?target@Outer_2f8e10@fn_fefbc573@@QAE_NPAPAXPAPAH@Z
bool Outer_2f8e10::target(void** out1, int** out2) {
    if (inner->Get() == 4) {
        *out2 = (int*)value;
        *out1 = inner;
        return true;
    }
    return false;
}


// 0x002f8e80 FUN_002f8e80 (61 B): matches/0x002f8e80.cpp
// sym: ?f@Pair_2f8e80@fn_fefbc573@@QAEXXZ
void Pair_2f8e80::f() {
    unsigned char z = 0;
    c = 0;
    if (a->m70 == z || b->m70 == z) {
        e = z;
        return;
    }
    if (a->m69 != z || b->m69 != z) {
        d = 0;
        e = 1;
        return;
    }
    if (a->m68 != z || b->m68 != z) {
        e = 1;
        return;
    }
    e = z;
}

} // namespace fn_fefbc573

// 0x002f8ec0 FUN_002f8ec0 (40 B): equivalent/0x002f8ec0.cpp
// sym: ?FUN_002f8ec0@Obj_2f8ec0@owners@@QAEPAU12@HHHHHH@Z @a0cf9a03f6f2 @w32d3f8d9af07
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f8ec0 @ 0x002f8ec0
owners::Obj_2f8ec0* owners::Obj_2f8ec0::FUN_002f8ec0(int a, int b, hulk_intptr c, int d, int e, hulk_intptr f) {
    FUN_002f8d90(a, b, ((int)c), d, e, ((int)f));
    return this;
}


// 0x002f8ef0 FUN_002f8ef0 (30 B): matches/0x002f8ef0.cpp
// sym: ?FUN_002f8ef0@X_2f8ef0@owners@@QAEPAU12@II@Z
owners::X_2f8ef0* owners::X_2f8ef0::FUN_002f8ef0(hulk_uintptr p, hulk_uintptr q) {
    a = ((unsigned int)p);
    b = ((unsigned int)q);
    c = 0;
    d = 0;
    e = 1;
    return this;
}


// 0x002f8f10 FUN_002f8f10 (417 B): equivalent/0x002f8f10.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002f8f10@Pair_2f8f10@fn_002f8f10@@QAEMM@Z @bd8f38931a6e @w3aa2014760ae
namespace fn_002f8f10 {
// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 14/14)
// FUN_002f8f10 @ 0x002f8f10


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_2f8f10 {
    float x, y, z;
};

struct Pos_2f8f10 {
    char pad00[0x50];
    Vec3_2f8f10 p;
};

struct Shape_2f8f10 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
    char pad04[0x28 - 4];
    Vec3_2f8f10 axis;
};

struct Body_2f8f10 {
    char pad00[0x18];
    Pos_2f8f10 *pos;
    char pad1c[4];
    Shape_2f8f10 *shape;
    char pad24[0x68 - 0x24];
    char active;
};

struct FloatBits_2f8f10 {
    float f;
};

class Pair_2f8f10 {
public:
    Body_2f8f10 *a;
    Body_2f8f10 *b;
    hulk_freg FUN_002f8f10(float t);
};

static float AxisDot(Shape_2f8f10 *s, Vec3_2f8f10 *v)
{
    float d = v->z * s->axis.z + v->y * s->axis.y + v->x * s->axis.x;
    int bits = *(int *)&d & 0x7fffffff;
    return *(float *)&bits;
}

hulk_freg Pair_2f8f10::FUN_002f8f10(float t)
{
    Vec3_2f8f10 v;
    if (a->active) {
        Pos_2f8f10 *p = a->pos;
        v.x = p->p.x;
        v.y = p->p.y;
        v.z = p->p.z;
    } else {
        v.x = 0.0f;
        v.y = 0;
        v.z = 0;
    }
    if (b->active) {
        Pos_2f8f10 *p = b->pos;
        v.x = v.x - p->p.x;
        v.y = v.y - p->p.y;
        v.z = v.z - p->p.z;
    }
    if (!(v.z * v.z + v.y * v.y + v.x * v.x > 1e-6f))
        return 0.0f;
    float len = (float)sqrt(v.z * v.z + v.y * v.y + v.x * v.x);
    float inv = 1.0f / len;
    v.x = v.x * inv;
    v.y = v.y * inv;
    v.z = v.z * inv;
    float dotA;
    Shape_2f8f10 *sa = a->shape;
    if (sa->vfunc_6() == 8)
        dotA = 1000000000.0f;
    else
        dotA = AxisDot(sa, &v);
    float dotB;
    Shape_2f8f10 *sb = b->shape;
    if (sb->vfunc_6() == 8)
        dotB = (*(float*)&DAT_00431754);
    else
        dotB = AxisDot(sb, &v);
    float m = dotB;
    if (dotA < dotB)
        m = dotA;
    if (len * t > DAT_004d2c60 * m)
        return len * t * DAT_004d2c5c;
    return 0.0f;
}
} // namespace fn_002f8f10

