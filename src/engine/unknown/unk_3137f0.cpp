// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003137f0..0x00319580 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc854b07 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc854b07 {} using namespace fn_fc854b07;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fc854b07 {
struct Vec3_3137f0 {
    float x, y, z;
};
class Body_3137f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_3137f0 *position();
    char pad4[0x54 - 4];
    Vec3_3137f0 normals[3];
};
struct Vec3_313940 {
    float x, y, z;
    void FUN_0022d180();
};
union FloatBits_313940 {
    float f;
    unsigned int u;
};
struct Box_313940 {
    char pad00[0x48];
    Vec3_313940 ext;
    Vec3_313940 row[3];
    hulk_freg FUN_002fbcd0(const Vec3_313940 *axis);
    hulk_freg FUN_002fbdc0(const Vec3_313940 *axis, int skip);
};
class BoxTest {
public:
    char pad00[0x0c];
    float margin;
    char pad10[4];
    Vec3_313940 d;
    bool Separated(Box_313940 *a, Box_313940 *b);
};
static inline float AbsBits(float v)
{
    FloatBits_313940 bits;
    bits.f = v;
    bits.u &= 0x7fffffff;
    return bits.f;
}
struct V3_3140d0 {
    float x, y, z;
    void FUN_0022d180();
};
struct Box_3140d0;
struct Shape_3140d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_3140d0 *v4();
    char pad4[0x40];
    V3_3140d0 dir;         // 0x44
    float halfLen;  // 0x50
    float radius;   // 0x54
    bool flag;      // 0x58
};
struct Box_3140d0 {
    char pad0[0x48];
    float ext[3];
    V3_3140d0 axes[3];     // 0x54
    hulk_freg FUN_002fbcd0(V3_3140d0 *v);
    hulk_freg FUN_002fbdc0(V3_3140d0 *v, int i);
};
class Tester_3140d0 {
public:
    char pad0[0xc];
    float r;        // 0xc
    char pad10[4];
    V3_3140d0 n;           // 0x14
    bool FUN_00313b70(Box_3140d0 *a, V3_3140d0 *p, int z0, int z1, Shape_3140d0 **pb, float rad, int z2);
    bool FUN_003140d0(Box_3140d0 *a, Shape_3140d0 *b);
};
struct Vec3_314380 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Plane_314380 {
    char pad0[0x44];
    Vec3_314380 n;           // 0x44
    char pad1[4];
    float d;          // 0x54
};
struct V3_314430 {
    float x;
    float y;
    float z;
    void FUN_001f6bc0(V3_314430 *a, float s, V3_314430 *b);
    void FUN_00011110(V3_314430 *a, V3_314430 *b);
    hulk_freg FUN_0022d110();
    hulk_freg FUN_000111f0();
};
float __cdecl FUN_00083d90(float *x);
class Prim_314430 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_314430 *v4();
    char pad04[0x44 - 4];
    V3_314430 v;
    float f50;
    float f54;
    char b58;
};
class Sweeper_314430;
class Sweeper_314430 {
public:
    char pad0[0xc];
    float r;
    char pad10[4];
    V3_314430 n;
    bool FUN_00314430(Prim_314430 *p, V3_314430 *a1, float a2, V3_314430 *a3, float *a4, V3_314430 *a5, V3_314430 *a6, char a7);
};
struct V3_3148c0 { float v[3]; };
extern "C" int __cdecl FUN_00305a40(V3_3148c0 *dir, int mode);
struct V3_314a10 {
    float x, y, z;
    void FUN_000111b0(const V3_314a10* a, const V3_314a10* b);
    hulk_freg FUN_0022d110();
    void FUN_001f6bc0(const V3_314a10* base, float scale, const V3_314a10* dir);
};
struct Capsule {
    char pad00[0xc];
    float inner;
    float radius;
    int FUN_00314a10(const V3_314a10* a1, const V3_314a10* a2, const V3_314a10* axis, float f4, float f5, char flag, V3_314a10* out, V3_314a10* out2);
};
struct Vec3_314be0 {
    float x, y, z;
};
union FloatBits_314be0 {
    float f;
    unsigned int u;
};
class Contact_314be0 {
public:
    int a;
    int b;
    char pad08[8];
    int x10;
    int x14;
    Vec3_314be0 n;
    float f24;
    char pad28[4];
    Vec3_314be0 v2c;
    Vec3_314be0 v38;
    void FUN_002f7a90(Contact_314be0* other);
};
struct ContactVec {
    Contact_314be0* begin;
    Contact_314be0* end;
    Contact_314be0* cap;
};
class ContactManager {
public:
    char pad00[8];
    ContactVec* vec;
    char pad0c[4];
    float tolerance;
    char pad14[0x30 - 0x14];
    int count;
    char pad34[4];
    unsigned int flags;
    void FUN_00314be0(int a1, hulk_intptr a2, hulk_intptr a3, hulk_intptr a4, int a5, Vec3_314be0* normal);
};
union Wd_314f50 {
    float f;
    hulk_uintptr u;
};
struct V3_314f50 {
    float x, y, z;
    float FUN_0022d110();
};
struct BoxA_314f50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual V3_314f50 *Center();
};
struct BoxB {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual V3_314f50 *Center();
    void FUN_002fb940(volatile float *out, hulk_intptr idx);
};
typedef BoxA_314f50 VBox;
class Sweep_314f50 {
public:
    char pad0[0xc];
    float f0c;
    float f10;
    float delta[3];
    void FUN_00313540(hulk_uintptr order, float a, float b, float c);
    void FUN_003137f0(BoxA_314f50 *a, volatile float *p, hulk_uintptr e1, hulk_uintptr e2, int axis);
    void FUN_00314be0(BoxA_314f50 *a, volatile float *p, BoxB *b, volatile float *c, hulk_uintptr d, volatile float *n);
    void FUN_00314f50(BoxA_314f50 *a, BoxB *b);
};
struct Vec3_315620 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
union FloatBits_315620 {
    float f;
    unsigned int u;
};
class Body_315620 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_315620* vfunc_4();
};
class Resolver_315620 {
public:
    char pad0[0x14];
    Vec3_315620 offset;
    void FUN_00314be0(Body_315620* a, Vec3_315620* pa, Body_315620* b, Vec3_315620* pb, float depth, Vec3_315620* dir);
    bool FUN_00315620(Vec3_315620* p0, Vec3_315620* axis0, float k0, Vec3_315620* p1, Vec3_315620* axis1, float k1, Vec3_315620* ref, float scale, float sign, Body_315620* b0, Body_315620* b1);
};
union Bits_315860 {
    float f;
    unsigned int u;
};
struct V3_315860 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct BoxData {
    char pad00[0x38];
    int f38;                    // 0x38
    char pad3c[0xc];
    float ext[3];               // 0x48
    V3_315860 axis[3];                 // 0x54
};
class Shape_315860 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3_315860 *getCenter();
    char pad04[0x30];
    float radius;               // 0x34
    char pad38[0xc];
    V3_315860 v44;                     // 0x44
    float f50;                  // 0x50
    float f54;                  // 0x54
};
class Tester_315860 {
public:
    char pad00[0xc];
    float f0c;                  // 0x0c
    char pad10[4];
    V3_315860 v14;                     // 0x14
    void FUN_00314be0(BoxData *box, V3_315860 *q, Shape_315860 *shape, V3_315860 *p, float d, V3_315860 *out);
    void FUN_00315860(BoxData *box, Shape_315860 *shape);
};
struct V3_3160f0 {
    float x, y, z;
};
union FloatBits_3160f0 {
    float f;
    unsigned int u;
};
struct CapB;
class BoxA_3160f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_3160f0* v4();
    char pad04[0x48 - 4];
    float ext[3];
    V3_3160f0 axis[3];
    void FUN_002fb990(V3_3160f0* out, int axis, int sign);
};
class CapB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_3160f0* v4();
    char pad04[0x44 - 4];
    V3_3160f0 dir;
    float f50;
    float f54;
};
struct Frame_3160f0 {
    float scratch;
    float f4unused;
    float adp;
    float m;
    float inv;
    float s;
    int j;
    int i;
    float f54;
    float kx;
    float ky;
    float kz;
    V3_3160f0 out;
    V3_3160f0 u;
    float len;
    float q;
};
class Collider_3160f0 {
public:
    char pad00[0xc];
    float f0c;
    char pad10[4];
    V3_3160f0 d;
    void FUN_00315620(V3_3160f0* out, V3_3160f0* axis, float ext, V3_3160f0* u, V3_3160f0* b, float f50, float* kv, float L, float m, BoxA_3160f0* a, CapB* cap);
    void FUN_003160f0(BoxA_3160f0* a, CapB* b);
};
struct Vec3 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_00011110(const Vec3 *a, const Vec3 *b);
    void FUN_000111b0(const Vec3 *a, const Vec3 *b);
    void FUN_001f6bc0(const Vec3 *base, float s, const Vec3 *dir);
};
class Body {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3 *vfunc_4();
    char pad04[0x44 - 4];
    Vec3 n;                          // 0x44
    float f50;                       // 0x50
    float f54;                       // 0x54
    char b58;                        // 0x58
};
float __cdecl FUN_000186f0(float *a, float *b);
class Resolver {
public:
    char pad00[0x0c];
    float threshold;                 // 0x0c
    char pad10[4];
    Vec3 offset;                     // 0x14
    Vec3 dir;                        // 0x20
    void FUN_00314be0(Body *a, Vec3 *pa, Body *b, Vec3 *pb, float depth, Vec3 *dir);
    void FUN_00316410(Body *a, Vec3 *vel, Vec3 *axis, float range, Body *b, float lat0, float lat, bool sweep);
};
static __forceinline float AbsIn(FloatBits &slot, float v)
{
    slot.f = v;
    slot.u &= 0x7fffffff;
    return slot.f;
}
struct Vec_317610 { float x,y,z; };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec_317610* position(); virtual void slot5(); virtual int kind();
 char pad[0x44-4]; float nx,ny,nz,radius; char pad54[4]; unsigned char flag;
};
struct Controller_317610 {
 char pad0[0x10]; float margin; char pad14[0x35-0x14]; unsigned char flag;
 bool FUN_00313b70(void*,Vec_317610*,Vec_317610*,Vec_317610*,float*,float,int);
 void FUN_00314be0(void*,Vec_317610*,Object*,Vec_317610*,float,Vec_317610*);
 void target(void*,Object*,const Vec_317610*,float);
};
struct Item { char pad[0x24]; float key; char rest[0x1c]; };
struct Store { char pad[4]; Item * volatile cursor; };
struct Owner { char pad[8]; Store *store; char rest[0x24]; int count; unsigned char FUN_003188d0(float value); };
struct Vec3_318910 {
    float x, y, z;
};
class Probe_318910 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_318910 *v4();
    char pad04[0x44 - 4];
    float dirX;
    float dirY;
    float dirZ;
    float time;
    int ref;
    char done;
};
struct Elem44 {
    char pad[0x24];
    float key;
    char pad2[0x44 - 0x28];
};
struct ThisCall_002f7a90 {
  public:
    void FUN_002f7a90(Item *item);
    void FUN_002f7a90(Elem44 *e);
};
struct ElemList {
    Elem44 *begin;
    Elem44 *end;
};
struct Frame_318910 {
    float t;
    float tmp;
    float sq;
    int n;
    int counter;
    Vec3_318910 d;
    Vec3_318910 p;
    Vec3_318910 out1;
    Vec3_318910 out2;
};
class Solver_318910 {
public:
    char pad0[8];
    ElemList *list;
    char pad1[0x14 - 0xc];
    float dx;
    float dy;
    float dz;
    char pad2[0x2c - 0x20];
    float lenSq;
    int count;

    char FUN_00314430(Probe_318910 *y, Vec3_318910 *p, int ref, Vec3_318910 *d, float *lenSq, Vec3_318910 *out2, Vec3_318910 *out1, int one);
    void FUN_00314be0(Probe_318910 *y, Vec3_318910 *out2, Probe_318910 *x, Vec3_318910 *out1, float lenSq, Vec3_318910 *d);
    char FUN_003188d0(float lenSq);
    void FUN_00318910(Probe_318910 *a1, Probe_318910 *a2);
};
struct Vec3_318bb0 { float x, y, z; };
union FloatBits_318bb0 {
    float f;
    unsigned int u;
};
class Shape_318bb0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_318bb0 *position();
    char pad04[0x44 - 4];
    Vec3_318bb0 normal;
    float extent;
    float limit;
    unsigned char active;
};
bool __cdecl FUN_00314380(Shape_318bb0 *a, Shape_318bb0 *b, Vec3_318bb0 *dir, Vec3_318bb0 *out);
class Contact_318bb0 {
public:
    char pad00[0x14];
    Vec3_318bb0 delta;
    void FUN_00316410(Shape_318bb0 *a, Vec3_318bb0 *out, Vec3_318bb0 *normal, float extent, Shape_318bb0 *b, float d1, float d2, int one);
    void Test(Shape_318bb0 *a, Shape_318bb0 *b);
};
class SimpleFilter1D {
  public:
    virtual ~SimpleFilter1D();
    int a, b, c, d;
    SimpleFilter1D();
};


// 0x003137f0 FUN_003137f0 (327 B): equivalent/0x003137f0.cpp
// sym: ?FUN_003137f0@fn_fc854b07@@YGXPAVBody_3137f0@1@PAUVec3_3137f0@1@MMH@Z @7ae5ac82098b @w3d2d1ac94335
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 16/16)
// FUN_003137f0 @ 0x003137f0
void __stdcall FUN_003137f0(Body_3137f0 *body, Vec3_3137f0 *pos, float a, float b, int index)
{
    int i = (index < 2) ? index + 1 : 0;
    Vec3_3137f0 *p = body->position();
    hulk_freg dx = pos->x - p->x;
    hulk_freg dy = pos->y - p->y;
    hulk_freg dz = pos->z - p->z;

    if (a > 0.0f) {
        const Vec3_3137f0 *n = &body->normals[i];
        hulk_freg dot = dz * n->z + dy * n->y + dx * n->x;
        hulk_freg s;
        if (dot < 0.0f)
            s = -1.0f;
        else if (dot > 0.0f)
            s = 1.0f;
        else
            s = 0.0f;
        hulk_freg t = -s * a;
        pos->x = t * n->x + pos->x;
        pos->y = t * n->y + pos->y;
        pos->z = t * n->z + pos->z;
    }
    if (b > 0.0f) {
        i = (i < 2) ? i + 1 : 0;
        const Vec3_3137f0 *n = &body->normals[i];
        hulk_freg dot = dz * n->z + dy * n->y + dx * n->x;
        hulk_freg s;
        if (dot < 0.0f)
            s = -1.0f;
        else if (dot > 0.0f)
            s = 1.0f;
        else
            s = 0.0f;
        hulk_freg t = -s * b;
        pos->x = t * n->x + pos->x;
        pos->y = t * n->y + pos->y;
        pos->z = t * n->z + pos->z;
    }
}


// 0x00313940 FUN_00313940 (559 B): equivalent/0x00313940.cpp
// sym: ?Separated@BoxTest@fn_fc854b07@@QAE_NPAUBox_313940@2@0@Z @0c914d830fce @w08a7fe56529f
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 15/16, incomplete)
// FUN_00313940 @ 0x00313940
bool BoxTest::Separated(Box_313940 *a, Box_313940 *b)
{
    int i;
    int j;
    float t;

    for (i = 0; i < 3; i++) {
        double lim = b->FUN_002fbcd0(&a->row[i]) + (&a->ext.x)[i];
        t = a->row[i].z * d.z + d.y * a->row[i].y + a->row[i].x * d.x;
        lim += margin;
        if (lim < AbsBits(t)) {
            return true;
        }
        lim = a->FUN_002fbcd0(&b->row[i]) + (&b->ext.x)[i];
        t = b->row[i].y * d.y + b->row[i].z * d.z + d.x * b->row[i].x;
        lim += margin;
        if (lim < AbsBits(t)) {
            return true;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            float dot = b->row[j].y * a->row[i].y + a->row[i].x * b->row[j].x + b->row[j].z * a->row[i].z;
            float adot = AbsBits(dot);
            float diff = AbsBits(adot - 1.0f);
            if (diff <= 1e-5f) {
                continue;
            }
            Vec3_313940 cross;
            cross.x = a->row[i].y * b->row[j].z - b->row[j].y * a->row[i].z;
            cross.y = a->row[i].z * b->row[j].x - a->row[i].x * b->row[j].z;
            cross.z = b->row[j].y * a->row[i].x - a->row[i].y * b->row[j].x;
            if (margin > 0.0f) {
                cross.FUN_0022d180();
            }
            volatile float rb = b->FUN_002fbdc0(&cross, j);
            double lim = a->FUN_002fbdc0(&cross, i) + rb;
            t = cross.z * d.z + cross.y * d.y + cross.x * d.x;
            lim += margin;
            if (lim < AbsBits(t)) {
                return true;
            }
        }
    }
    return false;
}

} // namespace fn_fc854b07

// 0x00313b70 FUN_00313b70 (1367 B): equivalent/0x00313b70.cpp [wrapped: conflict: FUN_00083d90]
// sym: ?FUN_00313b70@Sweeper_313b70@fn_00313b70@@QAEDTArg1_313b70@2@TArg2_313b70@2@TArg3_313b70@2@PAUVec3_313b70@2@PAMMTArg7@2@@Z @b9862590e444 @we37596ccad68
namespace fn_00313b70 {
// STATUS: equivalent (tools/equiv.py level 3: 2161 inputs, branch coverage 50/50)
// FUN_00313b70 @ 0x00313b70

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_313b70 {
    float x, y, z;
    float FUN_0022d110() throw();
    void FUN_00011160(float s, Vec3_313b70 *d) throw();
    void FUN_00095e80(float s, Vec3_313b70 *axis) throw();
};

class Box_313b70 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual Vec3_313b70 *v4() throw();
    char pad04[0x34];
    int f38;
    char pad3c[0xc];
    float ext[3];
    Vec3_313b70 axis[3];
};

union FloatBits_313b70 {
    float f;
    unsigned int u;
};

union Arg1_313b70 {
    Box_313b70 *box;
    float f;
    unsigned int u;
};

union Arg2_313b70 {
    Vec3_313b70 *p;
    float f;
};

union Arg3_313b70 {
    Vec3_313b70 *out;
    Vec3_313b70 *axis;
};

union Arg7 {
    char flag;
    float s;
};

float __cdecl FUN_00083d90(float *w) throw();
char __cdecl FUN_00018960(float a, float b, float eps) throw();

class Sweeper_313b70 {
public:
    char pad00[0xc];
    float f0c;
    float f10;
    void FUN_00313540(int *out, unsigned int e0, unsigned int e1, unsigned int e2) throw();
    void FUN_003137f0(Box_313b70 *box, Vec3_313b70 *pt, unsigned int r1, unsigned int r2, int idx) throw();
    char FUN_00313b70(Arg1_313b70 a1, Arg2_313b70 a2, Arg3_313b70 a3, Vec3_313b70 *a4, float *a5, float a6, Arg7 a7);
};

char Sweeper_313b70::FUN_00313b70(Arg1_313b70 a1, Arg2_313b70 a2, Arg3_313b70 a3, Vec3_313b70 *a4, float *a5, float a6, Arg7 a7)
{
    union IntF {
        int i;
        float f;
    };
    struct Frame {
        float c;
        float tmp1;
        float tmp2;
        Sweeper_313b70 *self;
        float R;
        float E[3];
        float W[3];
        IntF G[3];
    } f;

    Box_313b70 *box = a1.box;
    Vec3_313b70 *P = a2.p;
    f.R = a6 + f10;
    f.self = this;
    const Vec3_313b70 *cen = box->v4();
    double dx = P->x - cen->x;
    double dy = P->y - cen->y;
    f.G[1].f = (float)dy;
    double dz = P->z - cen->z;
    f.G[2].f = (float)dz;
    if (box->f38 == 0) {
        double w0 = f.G[2].f * box->axis[0].z + dy * box->axis[0].y + dx * box->axis[0].x;
        f.W[0] = (float)w0;
        a1.f = (float)w0;
        a1.u &= 0x7fffffff;
        f.E[0] = a1.f - a6 - box->ext[0];
        double w1 = f.G[2].f * box->axis[1].z + dy * box->axis[1].y + dx * box->axis[1].x;
        f.W[1] = (float)w1;
        a1.f = (float)w1;
        a1.u &= 0x7fffffff;
        f.E[1] = a1.f - a6 - box->ext[1];
        double w2 = f.G[2].f * box->axis[2].z + dy * box->axis[2].y + dx * box->axis[2].x;
        f.W[2] = (float)w2;
        a1.f = (float)w2;
    } else {
        f.W[0] = (float)dx;
        f.W[2] = f.G[2].f;
        f.W[1] = (float)dy;
        a1.f = (float)dx;
        a1.u &= 0x7fffffff;
        f.E[0] = a1.f - a6 - box->ext[0];
        a1.f = f.G[1].f;
        a1.u &= 0x7fffffff;
        f.E[1] = a1.f - a6 - box->ext[1];
        a1.f = f.G[2].f;
    }
    a1.u &= 0x7fffffff;
    f.E[2] = a1.f - a6 - box->ext[2];
    FUN_00313540(&f.G[0].i, *(unsigned int *)&f.E[0], *(unsigned int *)&f.E[1], *(unsigned int *)&f.E[2]);
    int idx = f.G[0].i;
    double m = (a6 < box->ext[idx]) ? a6 : box->ext[idx];
    if (f.E[idx] < f0c) {
        if (-m > f.E[idx]) {
            if (a7.flag == 0)
                return 1;
            Vec3_313b70 *cp = a3.out;
            *cp = *P;
            float w = f.W[idx];
            double sg;
            if (w < 0.0f)
                sg = -1.0;
            else if (w > 0.0f)
                sg = 1.0;
            else
                sg = 0.0;
            double ns = -sg;
            Vec3_313b70 *ax = &box->axis[idx];
            a4->x = ns * ax->x;
            a4->y = ns * ax->y;
            a4->z = ns * ax->z;
            double t = a6 + f.E[idx];
            cp->x = t * a4->x + cp->x;
            cp->y = t * a4->y + cp->y;
            cp->z = t * a4->z + cp->z;
            P->x = a6 * a4->x + P->x;
            P->y = a6 * a4->y + P->y;
            unsigned int eb = *(volatile unsigned int *)&f.E[idx];
            P->z = a6 * a4->z + P->z;
            *(unsigned int *)a5 = eb;
            return 1;
        }
    }
    for (int k = 0; k < 3; k++) {
        int bp = f.G[k].i;
        f.c = f.E[bp];
        *a5 = f.c;
        double m2 = (a6 < box->ext[bp]) ? a6 : box->ext[bp];
        if (!(f.c < f0c))
            continue;
        if (!(-m2 < f.c))
            continue;
        int n1 = (bp < 2) ? bp + 1 : 0;
        f.tmp1 = f.W[n1];
        *(unsigned int *)&f.tmp1 &= 0x7fffffff;
        double v1 = f.tmp1 - box->ext[n1];
        a2.f = (0.0f < v1) ? (float)v1 : 0.0f;
        if (!(a2.f <= f.R))
            continue;
        int n2 = (n1 < 2) ? n1 + 1 : 0;
        f.tmp2 = f.W[n2];
        *(unsigned int *)&f.tmp2 &= 0x7fffffff;
        double v2 = f.tmp2 - box->ext[n2];
        a1.f = (0.0f < v2) ? (float)v2 : 0.0f;
        if (!(a1.f <= f.R))
            continue;
        if (a2.f > 0.0f || a1.f > 0.0f) {
            double t = f.c + a6;
            double sq = t * t;
            sq = sq + a1.f * a1.f;
            sq = sq + a2.f * a2.f;
            *a5 = (float)(sqrt(sq) - a6);
        }
        if (!(*a5 < f0c))
            continue;
        if (a7.flag == 0)
            return 1;
        double r = FUN_00083d90(&f.W[bp]);
        a7.s = (float)(-r);
        Vec3_313b70 *cp = a3.out;
        *cp = *P;
        double q = (a6 + f.E[bp]) * a7.s;
        Vec3_313b70 *ax = &box->axis[bp];
        cp->x = q * ax->x + cp->x;
        cp->y = q * ax->y + cp->y;
        cp->z = q * ax->z + cp->z;
        a3.axis = ax;
        if (a2.f > 0.0f || a1.f > 0.0f) {
            if (a6 + *a5 > 0.001f) {
                FUN_003137f0(box, cp, *(unsigned int *)&a2.f, *(unsigned int *)&a1.f, bp);
                a4->x = cp->x - P->x;
                a4->y = cp->y - P->y;
                a4->z = cp->z - P->z;
                float len = a4->FUN_0022d110();
                if (FUN_00018960(len, 0.0f, 1e-05f))
                    a4->FUN_00095e80(a7.s, a3.axis);
                P->FUN_00011160(a6, a4);
                return 1;
            }
        }
        a4->x = a7.s * ax->x;
        a4->y = a7.s * ax->y;
        a4->z = a7.s * ax->z;
        P->x = a6 * a4->x + P->x;
        P->y = a6 * a4->y + P->y;
        P->z = a6 * a4->z + P->z;
        return 1;
    }
    return 0;
}
} // namespace fn_00313b70

namespace fn_fc854b07 {

// 0x003140d0 FUN_003140d0 (688 B): equivalent/0x003140d0.cpp
// sym: ?FUN_003140d0@Tester_3140d0@fn_fc854b07@@QAE_NPAUBox_3140d0@2@PAUShape_3140d0@2@@Z @92dad38ba545 @w6896aa5e3c8b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_003140d0 @ 0x003140d0
bool Tester_3140d0::FUN_003140d0(Box_3140d0 *a, Shape_3140d0 *b)
{
    Shape_3140d0 *bb = b;
    if (!bb->flag) {
        V3_3140d0 t;
        float h = bb->halfLen;
        t.x = h * bb->dir.x;
        t.y = h * bb->dir.y;
        t.z = h * bb->dir.z;
        V3_3140d0 *p = bb->v4();
        t.x = t.x + p->x;
        t.y = t.y + p->y;
        t.z = t.z + p->z;
        if (FUN_00313b70(a, &t, 0, 0, &b, bb->radius, 0))
            return false;
        h = -bb->halfLen;
        t.x = h * bb->dir.x;
        t.y = h * bb->dir.y;
        t.z = h * bb->dir.z;
        p = bb->v4();
        t.x = t.x + p->x;
        t.y = t.y + p->y;
        t.z = t.z + p->z;
        if (FUN_00313b70(a, &t, 0, 0, &b, bb->radius, 0))
            return false;
    }
    union { float f; unsigned u; } ab;
    V3_3140d0 *d = &bb->dir;
    double e = a->FUN_002fbcd0(d) + bb->halfLen;
    volatile float dot = d->z * n.z + d->y * n.y + d->x * n.x;
    ab.f = dot;
    ab.u &= 0x7fffffff;
    dot = ab.f;
    double reach = e + r;
    if (reach < dot)
        return true;
    for (int i = 0; i < 3; i++) {
        V3_3140d0 *c = &a->axes[i];
        volatile float dd = d->x * c->x + d->z * c->z + d->y * c->y;
        volatile float nc = c->z * n.z + c->y * n.y + c->x * n.x;
        ab.f = dd;
        ab.u &= 0x7fffffff;
        volatile float a1 = ab.f;
        ab.f = nc;
        ab.u &= 0x7fffffff;
        volatile float a2 = ab.f;
        double s = sqrt(1.0f - a1 * a1) * bb->radius;
        s = s + a1 * bb->halfLen;
        s = s + a->ext[i];
        s = s + r;
        if (s < a2)
            return true;
    }
    for (int i = 0; i < 3; i++) {
        V3_3140d0 *c = &a->axes[i];
        V3_3140d0 cr;
        cr.x = c->y * d->z - d->y * c->z;
        cr.y = d->x * c->z - d->z * c->x;
        cr.z = d->y * c->x - d->x * c->y;
        if (r > 0.0f)
            cr.FUN_0022d180();
        double e2 = a->FUN_002fbdc0(&cr, i) + bb->radius;
        volatile float dc = cr.x * n.x + cr.y * n.y + cr.z * n.z;
        ab.f = dc;
        ab.u &= 0x7fffffff;
        dc = ab.f;
        double reach2 = e2 + r;
        if (reach2 < dc)
            return true;
    }
    return false;
}


// 0x00314380 FUN_00314380 (167 B): equivalent/0x00314380.cpp
// sym: ?FUN_00314380@fn_fc854b07@@YA_NPAUPlane_314380@1@HPAUVec3_314380@1@1@Z @a5b4f197b3f1 @wd30ce946dd09
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 2/2)
// FUN_00314380 @ 0x00314380
bool __cdecl FUN_00314380(Plane_314380 *plane, hulk_intptr unused, Vec3_314380 *v, Vec3_314380 *out)
{
    v->FUN_0022d110();
    // x87: dot, s and k stay in registers (53 bits); |dot| is tested on a rounded frame copy
    hulk_freg dot = (hulk_freg)plane->n.z * v->z + (hulk_freg)plane->n.y * v->y + (hulk_freg)plane->n.x * v->x;
    union { float f; unsigned int u; } a;
    a.f = (float)dot;
    a.u &= 0x7fffffff;
    if (1.0f - a.f < 1.0e-6f)
        return false;
    hulk_freg s = plane->d / (hulk_freg)sqrt(1.0f - dot * dot);
    out->x = s * v->x;
    out->y = s * v->y;
    out->z = s * v->z;
    hulk_freg k = -(dot * s);
    out->x += k * plane->n.x;
    out->y += k * plane->n.y;
    out->z += k * plane->n.z;
    return true;
}


// 0x00314430 FUN_00314430 (1154 B): equivalent/0x00314430.cpp
// sym: ?FUN_00314430@Sweeper_314430@fn_fc854b07@@QAE_NPAVPrim_314430@2@PAUV3_314430@2@M1PAM11D@Z @a34346b6b99d @w0835ad492779
// STATUS: equivalent (tools/equiv.py level 3: 3080 inputs, branch coverage 43/46, incomplete)
// FUN_00314430 @ 0x00314430
bool Sweeper_314430::FUN_00314430(Prim_314430 *p, V3_314430 *a1, float a2, V3_314430 *a3, float *a4, V3_314430 *a5, V3_314430 *a6, char a7)
{
    struct {
        float d;
        float absd;
        Sweeper_314430 *self;
        V3_314430 *np;
    } l;
    double d = p->v.z * n.z + p->v.y * n.y + p->v.x * n.x;
    l.self = this;
    l.np = &n;
    l.d = (float)d;
    double t = *a4 - d * l.d;
    float u;
    if (0.0 < t)
        u = (float)t;
    else
        u = 0.0f;
    char cl = p->b58;
    double L;
    if (cl)
        L = 0.0;
    else
        L = p->f54;
    L = L + p->f50;
    union {
        float f;
        unsigned int i;
    } ab;
    ab.f = l.d;
    ab.i &= 0x7fffffff;
    l.absd = ab.f;
    if (!(L + a2 + r > ab.f))
        return false;
    double R = a2 + p->f54 + r;
    if (!(u < R * R))
        return false;
    if (a5 == 0 || a6 == 0)
        return true;
    float f54c = p->f54;
    if (u < 0.0f)
        return false;
    u = (float)sqrt(u);
    if (cl) {
        double X = ab.f - p->f50;
        double Y = u - f54c;
        if (Y < X && u < f54c) {
            double W = ab.f - (a2 + p->f50);
            *a4 = (float)W;
            if (!(W < r))
                return false;
            ((owners::Vec3_95e80 *)a3)->FUN_00095e80(FUN_00083d90(&l.d), (float const *)(V3_314430 *)(&p->v));
            a6->FUN_001f6bc0(a1, a2, a3);
            a5->FUN_001f6bc0(a6, *a4, a3);
            return true;
        }
    } else if (ab.f >= p->f50) {
        if (!a7)
            return false;
        a5->FUN_001f6bc0(p->v4(), -(FUN_00083d90(&l.d) * p->f50), &p->v);
        a3->FUN_00011110(a5, a1);
        double len = a3->FUN_0022d110();
        double X2 = len - p->f54 - a2;
        *a4 = (float)X2;
        if (!(X2 < l.self->r))
            return false;
        ((owners::Vec3_11160 *)a5)->FUN_00011160(-p->f54, (const owners::Vec3_11160 *)(V3_314430 *)a3);
        a6->FUN_001f6bc0(a5, -*a4, a3);
        return true;
    }

    if (!(u > 1.0e-6f))
        return false;
    V3_314430 tmp;
    ((owners::Vec3_95e80 *)&tmp)->FUN_00095e80(-l.d, (float const *)(V3_314430 *)(&p->v));
    ((owners::Vec3_34440 *)a3)->FUN_00034440((owners::Vec3_34440 *)(V3_314430 *)(l.np), (owners::Vec3_34440 *)(V3_314430 *)(&tmp));
    *a4 = (float)(u - f54c - a2);
    ((owners::Vec3_11140 *)a3)->FUN_00011140(1.0f / u);
    double len2 = a3->FUN_000111f0();
    union {
        float f;
        unsigned int i;
    } e;
    e.f = (float)(len2 - 1.0);
    e.i &= 0x7fffffff;
    if (e.f > 0.01f)
        ((owners::Vec3_11140 *)a3)->FUN_00011140((float)(1.0 / sqrt(len2)));
    ab.f = l.d;
    ab.i &= 0x7fffffff;
    if (ab.f > p->f50) {
        union {
            float f;
            unsigned int i;
        } b2;
        b2.f = l.d;
        b2.i &= 0x7fffffff;
        double q = p->f50 / b2.f;
        tmp.x = tmp.x * q;
        tmp.y = tmp.y * q;
        tmp.z = tmp.z * q;
    }
    a5->FUN_001f6bc0(&tmp, -f54c, a3);
    ((owners::V3_110d0 *)a5)->FUN_000110d0((owners::V3_110d0 *)(V3_314430 *)(p->v4()));
    ab.f = l.d;
    ab.i &= 0x7fffffff;
    if (ab.f <= p->f50) {
        a6->FUN_001f6bc0(a1, a2, a3);
        return true;
    }
    if (!p->b58)
        return false;
    a3->FUN_00011110(a5, a1);
    double len = a3->FUN_0022d110();
    *a4 = (float)len;
    if (len == 0.0) {
        a3->FUN_00011110(a5, a1);
        a3->x = a3->x * 1000.0f;
        a3->y = a3->y * 1000.0f;
        a3->z = a3->z * 1000.0f;
        double len3 = a3->FUN_0022d110() * 0.001f;
        *a4 = (float)len3;
        if (len3 == 0.0)
            return false;
    }
    if (!(a2 + l.self->r >= *a4))
        return false;
    *a4 = *a4 - a2;
    a6->FUN_001f6bc0(a5, -*a4, a3);
    return true;
}


// 0x003148c0 FUN_003148c0 (334 B): equivalent/0x003148c0.cpp
// sym: ?FUN_003148c0@fn_fc854b07@@YG_NPAUV3_3148c0@1@00000_N@Z @15d1b80cd3d5 @w21051ce65e91
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_003148c0 @ 0x003148c0
// Solves for the point where two planes' constraints meet along the plane
// orthogonal to the dominant axis of the cross product of a3 and a4.
bool __stdcall FUN_003148c0(V3_3148c0 *a1, V3_3148c0 *a2, V3_3148c0 *a3, V3_3148c0 *a4, V3_3148c0 *result, V3_3148c0 *axisDir, bool computeAxis)
{
    if (computeAxis) {
        // all three components are computed before any is stored (the output may alias the inputs)
        double cx = a3->v[1] * a4->v[2] - a3->v[2] * a4->v[1];
        double cy = a3->v[2] * a4->v[0] - a3->v[0] * a4->v[2];
        double cz = a3->v[0] * a4->v[1] - a3->v[1] * a4->v[0];
        axisDir->v[0] = (float)cx;
        axisDir->v[1] = (float)cy;
        axisDir->v[2] = (float)cz;
    }
    float len = (float)sqrt(axisDir->v[0] * axisDir->v[0] + axisDir->v[1] * axisDir->v[1] + axisDir->v[2] * axisDir->v[2]);
    if (len < 9.99999997e-007f)
        return false;

    float d1 = -(a1->v[2] * a3->v[2] + a1->v[1] * a3->v[1] + a3->v[0] * a1->v[0]);
    float d2 = -(a2->v[2] * a4->v[2] + a2->v[1] * a4->v[1] + a2->v[0] * a4->v[0]);
    int axis = FUN_00305a40(axisDir, 1);
    int u = 0;
    int w = 1;
    if (axis == 0) {
        u = 1;
        w = 2;
    } else if (axis == 1) {
        u = 2;
        w = 0;
    }
    float t1 = a4->v[u];
    float t2 = a3->v[u];
    float pivot = axisDir->v[axis];
    result->v[axis] = 0.0f;
    result->v[u] = (a3->v[w] * d2 - a4->v[w] * d1) / pivot;
    result->v[w] = (t1 * d1 - t2 * d2) / pivot;
    return true;
}


// 0x00314a10 FUN_00314a10 (456 B): equivalent/0x00314a10.cpp
// sym: ?FUN_00314a10@Capsule@fn_fc854b07@@QAEHPBUV3_314a10@2@00MMDPAU32@1@Z @a4e04461346b @w7a012c599dd7
// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 12/12)
// FUN_00314a10 @ 0x00314a10
int Capsule::FUN_00314a10(const V3_314a10* a1, const V3_314a10* a2, const V3_314a10* axis, float f4, float f5, char flag, V3_314a10* out, V3_314a10* out2)
{
    V3_314a10 d;
    d.x = a2->x - a1->x;
    d.y = a2->y - a1->y;
    d.z = a2->z - a1->z;
    hulk_freg dd = d.z * d.z + d.x * d.x + d.y * d.y;
    float reach = radius + radius + f4 + f5;
    if (dd > reach * reach)
        return -1;
    double len = sqrt(dd);
    float lenf = (float)len;
    if (f5 + radius > len + f4 || f4 + radius > lenf + f5) {
        *out = *a1;
        return 0;
    }
    hulk_freg f4sq = f4 * f4;
    hulk_freg u = (f4sq - f5 * f5) + lenf * lenf;
    hulk_freg w = u / (lenf + lenf);
    float v = f4sq - w * w;
    hulk_freg r = w / lenf;
    out->x = d.x * r + a1->x;
    out->y = d.y * r + a1->y;
    out->z = d.z * r + a1->z;
    if (flag == 0)
        return 1;
    if (v <= inner * inner)
        return 1;
    V3_314a10 c;
    c.FUN_000111b0(&d, axis);
    c.FUN_0022d110();
    if (v < 0.0f)
        return -1;
    float s = (float)sqrt(v);
    out2->FUN_001f6bc0(out, s, &c);
    out->FUN_001f6bc0(out2, s * -2.0f, &c);
    return 2;
}


// 0x00314be0 FUN_00314be0 (838 B): equivalent/0x00314be0.cpp
// sym: ?FUN_00314be0@ContactManager@fn_fc854b07@@QAEXHHHHHPAUVec3_314be0@2@@Z @1aec10f68ca0 @we70e341746f1
// STATUS: equivalent (tools/equiv.py level 3: 3043 inputs, branch coverage 42/50, incomplete)
// FUN_00314be0 @ 0x00314be0
void ContactManager::FUN_00314be0(int a1, hulk_intptr a2, hulk_intptr a3, hulk_intptr a4, int a5, Vec3_314be0* normal)
{
    struct Frame {
        ContactVec* vecSlot;
        Contact_314be0* elem;
        float absTmp;
        float tolsq;
        Vec3_314be0 qd;
        int bitA;
        Vec3_314be0 qB;
        int bitB;
        Vec3_314be0 pA;
        Vec3_314be0 pB;
        Contact_314be0 c;
    } f;

    volatile float t = normal->x * normal->x + normal->y * normal->y + normal->z * normal->z - 1.0f;
    FloatBits_314be0 ab;
    ab.f = t;
    ab.u &= 0x7fffffff;
    if (ab.f > 0.01f)
        return;
    ((Contact_314be0 *)((owners::Obj_2f8ec0 *)&(f.c))->FUN_002f8ec0(a1, a2, (hulk_intptr)a3, a4, a5, (hulk_intptr)(Vec3_314be0 *)normal));
    if (flags != 0 && count > 0) {
        f.bitB = flags & 2;
        if (f.bitB) {
            f.pB = f.c.v2c;
            f.qB = f.c.v38;
        }
        f.bitA = flags & 1;
        if (f.bitA)
            f.pA = f.c.n;
        f.vecSlot = vec;
        hulk_intptr n = vec->end - vec->begin;
        hulk_intptr idx = n - 1;
        if (idx >= n - count) {
            f.elem = vec->begin + idx;
            for (;;) {
                Contact_314be0* e = f.elem;
                int sign;
                if (a1 == e->a && a3 == e->b) {
                    sign = 0;
                    if (f.c.x10 == e->x10 && f.c.x14 == e->x14)
                        sign = 1;
                } else if (a1 == e->b && a3 == e->a) {
                    sign = 0;
                    if (f.c.x10 == e->x14 && f.c.x14 == e->x10)
                        sign = -1;
                } else {
                    break;
                }
                if (sign != 0) {
                    bool skipA = false;
                    if (f.bitB) {
                        Vec3_314be0* pa = sign == 1 ? &e->v2c : &e->v38;
                        Vec3_314be0* qa = sign == 1 ? &e->v38 : &e->v2c;
                        double dx = pa->x - f.pB.x;
                        double dy = pa->y - f.pB.y;
                        double dz = pa->z - f.pB.z;
                        double s1 = dz * dz + dy * dy + dx * dx;
                        f.qd.x = qa->x - f.qB.x;
                        f.qd.y = qa->y - f.qB.y;
                        f.qd.z = qa->z - f.qB.z;
                        double tol = tolerance * 0.001f;
                        f.tolsq = tol * tol;
                        if (s1 < f.tolsq) {
                            if (f.qd.z * f.qd.z + f.qd.y * f.qd.y + f.qd.x * f.qd.x < f.tolsq)
                                return;
                        }
                    }
                    if (f.bitA) {
                        f.absTmp = f.pA.x * e->n.x + f.pA.z * e->n.z + f.pA.y * e->n.y;
                        FloatBits_314be0 d;
                        d.f = f.absTmp;
                        d.u &= 0x7fffffff;
                        if (d.f < 0.7f) {
                            if (f.c.f24 > f.elem->f24)
                                f.elem->FUN_002f7a90(&f.c);
                            return;
                        }
                    }
                }
                idx--;
                f.elem = f.elem - 1;
                if (!(idx >= n - count))
                    break;
            }
        }
        count = count + 1;
        Contact_314be0* dst = f.vecSlot->end;
        if (dst >= f.vecSlot->cap)
            return;
        f.vecSlot->end = dst + 1;
        if (dst != 0)
            *dst = f.c;
        return;
    }
    count = count + 1;
    ContactVec* v = vec;
    Contact_314be0* dst = v->end;
    if (dst >= v->cap)
        return;
    v->end = dst + 1;
    if (dst != 0)
        *dst = f.c;
}


// 0x00314f50 FUN_00314f50 (1739 B): equivalent/0x00314f50.cpp
// sym: ?FUN_00314f50@Sweep_314f50@fn_fc854b07@@QAEXPAUBoxA_314f50@2@PAUBoxB@2@@Z @3f1f1b55cef1 @wb6831bc80d40
// STATUS: equivalent (tools/equiv.py level 3: 20040 inputs, branch coverage 50/50)
// FUN_00314f50 @ 0x00314f50
// Sweep::FUN_00314f50 (this=ecx, ret 8): box-vs-box separating-axis sweep. Generated from the original code
// with work/cq/x87c3.py: the frame is the volatile slot array L[] at the original offsets (E-0xc4..E-4,
// including the compiler's scratch/pointer slots, because the current checker compares the CONTENTS of locals
// passed by pointer and a fuzzed axis index reads those slots), FPU-resident values are recomputed inline from
// volatile reads, slot loads through an index are snapshotted at load time.
void Sweep_314f50::FUN_00314f50(BoxA_314f50 *pa, BoxB *pb)
{
    volatile float *T = (volatile float *)this;
    volatile float *A = (volatile float *)pa;
    volatile Wd_314f50 L[49];
    hulk_freg f11;
    hulk_freg f22;
    hulk_freg f26;
    hulk_freg f35;
    hulk_freg f36;
    hulk_freg f37;
    hulk_freg f46;
    hulk_freg f47;
    hulk_freg f48;
    hulk_freg f7;
    hulk_intptr r10_edx;
    int r12_edx;
    int r13_eax;
    int r14_ecx;
    int r15_ebp;
    hulk_intptr r16_ecx;
    hulk_intptr r17_ecx;
    int r18_eax;
    hulk_intptr r19_ecx;
    int r1_ebp;
    hulk_intptr r20_edx;
    hulk_intptr r21_edx;
    hulk_intptr r23_edx;
    hulk_intptr r24_ecx;
    hulk_intptr r25_edx;
    hulk_intptr r27_edx;
    hulk_intptr r28_edx;
    hulk_intptr r29_ecx;
    int r2_edi;
    int r30_edi;
    int r31_eax;
    int r32_eax;
    int r33_ecx;
    hulk_intptr r38_edx;
    hulk_intptr r39_eax;
    hulk_intptr r3_ecx;
    int r40_edx;
    hulk_intptr r41_eax;
    int r42_eax;
    int r43_eax;
    int r44_ecx;
    int r4_eax;
    hulk_intptr r5_edx;
    hulk_intptr r6_edx;
    hulk_intptr r8_edx;
    hulk_intptr r9_ecx;
    unsigned tmpi, esiv, ecxv; int jo, cnt, kk, n1, n2, special; volatile float *ca, *cb, *cb2;
    volatile float * r34_eax;
    volatile float * r45_ecx;
    ca = (volatile float *)((VBox *)pa)->Center();
    cb = (volatile float *)((VBox *)pb)->Center();
    hulk_freg l0 = cb[0];
    hulk_freg l1 = ca[0];
    T[5] = (l0 - l1);
    hulk_freg l3 = cb[1];
    hulk_freg l4 = ca[1];
    T[6] = (l3 - l4);
    hulk_freg l6 = cb[2];
    hulk_freg l7 = ca[2];
    T[7] = (l6 - l7);
    if (*(volatile int *)&A[14] == 0) {
    r1_ebp = 0;
    r2_edi = 0;
    L[8].f = (((A[23] * T[7]) + (A[22] * T[6])) + (A[21] * T[5]));
    L[9].f = (((A[26] * T[7]) + (A[25] * T[6])) + (A[24] * T[5]));
    L[10].f = (((A[29] * T[7]) + (A[28] * T[6])) + (A[27] * T[5]));
        cnt = 0; jo = 0;
        do {
            ((BoxB *)pb)->FUN_002fb940(&L[2].f, cnt);
    r3_ecx = L[8].u;
    L[0].u = r3_ecx;
    r4_eax = 0x7fffffff;
    r5_edx = r3_ecx & r4_eax;
    L[0].u = r5_edx;
    r6_edx = L[9].u;
    *(volatile float *)((char *)L + 88 + (int)jo*1) = (((L[4].f * A[23]) + (L[3].f * A[22])) + (L[2].f * A[21]));
    L[1].f = (((L[4].f * A[23]) + (L[3].f * A[22])) + (L[2].f * A[21]));
    L[1].u = L[1].u & r4_eax;
    f7 = L[0].f;
    L[0].u = r6_edx;
    r8_edx = r6_edx & r4_eax;
    *(volatile float *)((char *)L + 148 + (int)jo*1) = (f7 - (L[1].f + A[18]));
    L[0].u = r8_edx;
    *(volatile float *)((char *)L + 92 + (int)jo*1) = (((L[4].f * A[26]) + (L[3].f * A[25])) + (L[2].f * A[24]));
    L[1].f = (((L[4].f * A[26]) + (L[3].f * A[25])) + (L[2].f * A[24]));
    L[1].u = L[1].u & r4_eax;
    r9_ecx = L[10].u;
    r10_edx = r9_ecx & r4_eax;
    f11 = L[0].f;
    L[0].u = r9_ecx;
    L[0].u = r10_edx;
    *(volatile float *)((char *)L + 152 + (int)jo*1) = (f11 - (L[1].f + A[19]));
    *(volatile float *)((char *)L + 96 + (int)jo*1) = (((L[4].f * A[29]) + (L[3].f * A[28])) + (L[2].f * A[27]));
    L[1].f = (((L[4].f * A[29]) + (L[3].f * A[28])) + (L[2].f * A[27]));
    L[1].u = L[1].u & r4_eax;
    jo = jo + 12;
    cnt = cnt + 1;
    *(volatile float *)((char *)L + 144 + (int)jo*1) = (L[0].f - (L[1].f + A[20]));
        } while (jo < 0x30);
    } else {
    r12_edx = *(volatile unsigned*)&T[5];
    r13_eax = *(volatile unsigned*)&T[6];
    r14_ecx = *(volatile unsigned*)&T[7];
    L[8].u = r12_edx;
    r15_ebp = 0;
    L[9].u = r13_eax;
    L[10].u = r14_ecx;
        L[6].u = (hulk_uintptr)&L[22].f;
        cnt = 0; jo = 0;
        do {
            ((BoxB *)pb)->FUN_002fb940((volatile float *)L[6].u, cnt);
    hulk_freg sx90 = *(volatile float *)((char *)L + 88 + (int)jo*1);
    r16_ecx = L[8].u;
    L[0].f = sx90;
    L[1].u = r16_ecx;
    r17_ecx = L[0].u;
    r18_eax = 0x7fffffff;
    r19_ecx = r17_ecx & r18_eax;
    L[0].u = r19_ecx;
    r20_edx = r16_ecx & r18_eax;
    L[1].u = r20_edx;
    r21_edx = L[9].u;
    jo = jo + 12;
    f22 = L[1].f;
    L[1].u = r21_edx;
    r23_edx = r21_edx & r18_eax;
    *(volatile float *)((char *)L + 136 + (int)jo*1) = (f22 - (L[0].f + A[18]));
    L[1].u = r23_edx;
    hulk_freg sx96 = *(volatile float *)((char *)L + 80 + (int)jo*1);
    L[0].f = sx96;
    L[0].u = L[0].u & r18_eax;
    r24_ecx = L[10].u;
    r25_edx = r24_ecx & r18_eax;
    f26 = L[1].f;
    L[1].u = r24_ecx;
    L[1].u = r25_edx;
    r27_edx = L[6].u;
    *(volatile float *)((char *)L + 140 + (int)jo*1) = (f26 - (L[0].f + A[19]));
    hulk_freg sx102 = *(volatile float *)((char *)L + 84 + (int)jo*1);
    r28_edx = r27_edx + 12;
    L[0].f = sx102;
    L[6].u = r28_edx;
    L[0].u = L[0].u & r18_eax;
    cnt = cnt + 1;
    *(volatile float *)((char *)L + 144 + (int)jo*1) = (L[1].f - (L[0].f + A[20]));
        } while (jo < 0x30);
    }
    cnt = 0;
    L[6].u = 0;
    L[12].u = (hulk_uintptr)&L[38].f;
    do {
        esiv = L[12].u;
        ((Sweep_314f50 *)T)->FUN_00313540((hulk_uintptr)&L[34].f, ((volatile float *)esiv)[-1], ((volatile float *)esiv)[0], ((volatile float *)esiv)[1]);
        L[15].u = 0;
        do {
            int done = 0;
            do {
    r29_ecx = L[15].u;
    r30_edi = *(volatile unsigned *)((char *)L + 136 + (int)r29_ecx*4);
    r31_eax = r30_edi + cnt*1;
    r32_eax = r31_eax << 2;
    hulk_freg sx108 = *(volatile float *)((char *)L + 148 + (int)r32_eax*1);
    L[1].u = 0xbf800000;
    L[0].f = sx108;
    hulk_freg sx109 = *(volatile float *)((char *)L + 88 + (int)r32_eax*1);
    hulk_freg sx110 = *(volatile float *)((char *)L + 32 + (int)r30_edi*4);
                if (!((-(sx109 * sx110)) < 0.0f))
                    L[1].u = 0x3f800000;
                ((BoxB *)pb)->FUN_002fb940(&L[2].f, L[6].u);
    r33_ecx = r30_edi + r30_edi*2 + 21;
    r34_eax = A + r33_ecx;
    f35 = L[2].f;
    L[2].f = ((f35 * L[1].f) + T[5]);
    f36 = L[3].f;
    L[3].f = ((f36 * L[1].f) + T[6]);
    f37 = L[4].f;
    L[4].f = ((f37 * L[1].f) + T[7]);
    L[7].f = (((L[4].f * r34_eax[2]) + (L[3].f * r34_eax[1])) + (L[2].f * r34_eax[0]));
                if (L[0].f < 0.0f) {
    r38_edx = L[7].u;
    L[5].u = r38_edx;
    r39_eax = L[5].u;
    r40_edx = 0x7fffffff;
    r41_eax = r39_eax & r40_edx;
    L[5].u = r41_eax;
                    if (L[5].f > A[r30_edi + 18])
                        break;
                }
                if (!(L[0].f <= T[3]))
                    break;
                if (!((A[r30_edi + 18] * -2.0f) < L[0].f)) {
    hulk_freg sx151 = *(volatile float *)((char *)L + 32 + (int)r30_edi*4);
                    if (!((L[7].f * sx151) < 0.0f))
                        break;
                }
                n1 = (int)r30_edi >= 2 ? 0 : r30_edi + 1;
    r42_eax = n1 + cnt*1;
    hulk_freg sx155 = *(volatile float *)((char *)L + 88 + (int)r42_eax*4);
    hulk_freg sx157 = *(volatile float *)((char *)L + 32 + (int)n1*4);
    L[14].f = ((L[1].f * sx155) + sx157);
    L[14].u = L[14].u & 0x7fffffff;
    L[5].f = (L[14].f - A[n1 + 18]);
                if (!((L[14].f - A[n1 + 18]) <= (L[0].f > 0.0f ? T[4] : 0.0f)))
                    break;
                n2 = n1 >= 2 ? 0 : n1 + 1;
    r43_eax = n2 + cnt*1;
    hulk_freg sx165 = *(volatile float *)((char *)L + 88 + (int)r43_eax*4);
    hulk_freg sx167 = *(volatile float *)((char *)L + 32 + (int)n2*4);
    L[13].f = ((L[1].f * sx165) + sx167);
    L[13].u = L[13].u & 0x7fffffff;
    L[7].f = (L[13].f - A[n2 + 18]);
                if (!((L[13].f - A[n2 + 18]) <= (L[0].f > 0.0f ? T[4] : 0.0f)))
                    break;
    hulk_freg sx174 = *(volatile float *)((char *)L + 32 + (int)r30_edi*4);
    L[11].u = 0xbf800000;
                if (!(sx174 < 0.0f))
                    L[11].u = 0x3f800000;
                ((BoxB *)pb)->FUN_002fb940(&L[2].f, L[6].u);
                cb2 = (volatile float *)((VBox *)pb)->Center();
    r44_ecx = r30_edi + r30_edi*2 + 21;
    r45_ecx = A + r44_ecx;
    f46 = L[2].f;
    L[2].f = ((f46 * L[1].f) + cb2[0]);
    f47 = L[3].f;
    L[3].f = ((f47 * L[1].f) + cb2[1]);
    f48 = L[4].f;
    L[4].f = ((f48 * L[1].f) + cb2[2]);
    L[19].f = (((-(L[11].f * L[0].f)) * r45_ecx[0]) + L[2].f);
    L[20].f = (((-(L[11].f * L[0].f)) * r45_ecx[1]) + L[3].f);
    L[21].f = (((-(L[11].f * L[0].f)) * r45_ecx[2]) + L[4].f);
                special = (T[3] == T[4]) && (L[0].f > 0.0f) && ((L[5].f > 0.0f) || (L[7].f > 0.0f)) && (((L[7].f > 0.0f ? L[7].f : 0.0f) * (L[7].f > 0.0f ? L[7].f : 0.0f) + (L[5].f > 0.0f ? L[5].f : 0.0f) * (L[5].f > 0.0f ? L[5].f : 0.0f)) + L[0].f * L[0].f > 0.001f);
                if (special) {
                    ((Sweep_314f50 *)T)->FUN_003137f0((BoxA_314f50 *)A, &L[19].f, L[5].u, L[7].u, r30_edi);
    L[16].f = (L[19].f - L[2].f);
    L[17].f = (L[20].f - L[3].f);
    L[18].f = (L[21].f - L[4].f);
                    L[0].f = ((V3_314f50 *)&L[16].f)->FUN_0022d110();
                } else {
    L[16].f = ((-L[11].f) * r45_ecx[0]);
    L[17].f = ((-L[11].f) * r45_ecx[1]);
    L[18].f = ((-L[11].f) * r45_ecx[2]);
                }
                ((Sweep_314f50 *)T)->FUN_00314be0((BoxA_314f50 *)A, &L[19].f, (BoxB *)pb, &L[2].f, L[0].u, &L[16].f);
                done = 1;
            } while (0);
            if (done)
                break;
            kk = L[15].u + 1;
            L[15].u = kk;
        } while (kk < 3);
        esiv = L[6].u + 1;
        ecxv = L[12].u + 12;
        cnt += 3;
        L[6].u = esiv;
        L[12].u = ecxv;
    } while (cnt < 12);
}


// 0x00315620 FUN_00315620 (576 B): equivalent/0x00315620.cpp
// sym: ?FUN_00315620@Resolver_315620@fn_fc854b07@@QAE_NPAUVec3_315620@2@0M00M0MMPAVBody_315620@2@1@Z @7121f1dc9690 @w5475aa5e7214
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 12/12)
// FUN_00315620 @ 0x00315620
bool Resolver_315620::FUN_00315620(Vec3_315620* p0, Vec3_315620* axis0, float k0, Vec3_315620* p1, Vec3_315620* axis1, float k1, Vec3_315620* ref, float scale, float sign, Body_315620* b0, Body_315620* b1)
{
    Vec3_315620 d;
    FloatBits_315620 bits;

    d.x = (p1->x - p0->x) + offset.x;
    d.y = (p1->y - p0->y) + offset.y;
    volatile float dzr = p1->z - p0->z; // the original rounds the z difference before adding the offset
    d.z = dzr + offset.z;

    hulk_freg cx = d.y * ref->z - d.z * ref->y;
    hulk_freg cy = d.z * ref->x - d.x * ref->z;
    hulk_freg cz = d.x * ref->y - d.y * ref->x;
    hulk_freg inv = 1.0f / (scale * scale);

    double u0 = (cz * axis0->z + cy * axis0->y + cx * axis0->x) * k0; // MSVC would reassociate dot*k0*inv
    float t0 = u0 * inv;
    bits.f = t0;
    bits.u &= 0x7fffffff;
    if (!(bits.f <= 1.0f))
        return false;

    double u1 = (cz * axis1->z + cy * axis1->y + cx * axis1->x) * k1;
    float t1 = u1 * inv;
    bits.f = t1;
    bits.u &= 0x7fffffff;
    if (!(bits.f <= 1.0f))
        return false;

    if (b0 == 0 || b1 == 0)
        return true;

    Vec3_315620* v0 = b0->vfunc_4();
    p0->x = v0->x + p0->x;
    p0->y = v0->y + p0->y;
    p0->z = v0->z + p0->z;
    Vec3_315620* v1 = b1->vfunc_4();
    p1->x = p1->x + v1->x;
    p1->y = v1->y + p1->y;
    p1->z = v1->z + p1->z;

    ((owners::Vec3_11160 *)p0)->FUN_00011160(-(t1 * k0), (const owners::Vec3_11160 *)(Vec3_315620 *)axis0);
    ((owners::Vec3_11160 *)p1)->FUN_00011160(-(t0 * k1), (const owners::Vec3_11160 *)(Vec3_315620 *)axis1);

    d.x = p0->x - p1->x;
    d.y = p0->y - p1->y;
    d.z = p0->z - p1->z;
    float len = d.FUN_0022d110();
    if (len < 1.0e-6f)
        return false;
    if (sign < 0.0f) {
        len = -len;
        d.x = d.x * -1.0f;
        d.y = d.y * -1.0f;
        d.z = d.z * -1.0f;
    }
    FUN_00314be0(b0, p0, b1, p1, len, &d);
    return true;
}


// 0x00315860 FUN_00315860 (1073 B): equivalent/0x00315860.cpp
// sym: ?FUN_00315860@Tester_315860@fn_fc854b07@@QAEXPAUBoxData@2@PAVShape_315860@2@@Z @184eff379eb0 @wda73448eafbc
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 30/30)
// FUN_00315860 @ 0x00315860
void Tester_315860::FUN_00315860(BoxData *box, Shape_315860 *shape)
{
    struct Frame {
        float sgn;
        float pad14;
        float r1;
        float r2;
        float e;
        float sgn2;
        float f;
        float absf;
        V3_315860 P;
        V3_315860 c;
        V3_315860 q48;
        V3_315860 w;
        V3_315860 out;
    } fr;
    Bits_315860 ab;
    float *cv = &fr.c.x;

    if (box->f38 == 0) {
        fr.c.x = box->axis[0].z * v14.z + box->axis[0].y * v14.y + box->axis[0].x * v14.x;
        fr.c.y = box->axis[1].z * v14.z + box->axis[1].y * v14.y + box->axis[1].x * v14.x;
        fr.c.z = box->axis[2].z * v14.z + box->axis[2].y * v14.y + box->axis[2].x * v14.x;
    } else {
        fr.c = v14;
    }

    for (int i = 0; i < 3; i++) {
        ab.f = cv[i];
        ab.u &= 0x7fffffff;
        double dd0 = ab.f - box->ext[i];
        float d = dd0;
        if (!(dd0 > 0.0))
            continue;
        if (!(shape->radius + f0c > d))
            continue;
        bool flag = true;
        if (cv[i] < 0.0f)
            fr.sgn = -1.0f;
        else if (cv[i] > 0.0f)
            fr.sgn = 1.0f;
        else
            fr.sgn = 0.0f;
        fr.sgn2 = fr.sgn;
        V3_315860 *row = &box->axis[i];
        fr.e = row->z * shape->v44.z + row->y * shape->v44.y + row->x * shape->v44.x;

        for (;;) {
            float s2;
            if (fr.e < 0.0f)
                s2 = -1.0f;
            else if (fr.e > 0.0f)
                s2 = 1.0f;
            else
                s2 = 0.0f;
            double k = s2 * shape->f50 * fr.sgn2;
            fr.P.x = k * shape->v44.x;
            fr.P.y = k * shape->v44.y;
            fr.P.z = k * shape->v44.z;
            double ux = row->y * shape->v44.z - row->z * shape->v44.y;
            double uy = row->z * shape->v44.x - row->x * shape->v44.z;
            double uz = row->x * shape->v44.y - row->y * shape->v44.x;
            fr.w.x = uz * shape->v44.y - uy * shape->v44.z;
            fr.w.y = ux * shape->v44.z - uz * shape->v44.x;
            fr.w.z = uy * shape->v44.x - ux * shape->v44.y;
            fr.w.FUN_0022d110();
            double m = fr.sgn * shape->f54;
            fr.P.x = fr.w.x * m + fr.P.x;
            fr.P.y = fr.w.y * m + fr.P.y;
            fr.P.z = fr.w.z * m + fr.P.z;
            fr.f = fr.P.z * row->z + fr.P.y * row->y + fr.P.x * row->x;
            ab.f = fr.f;
            ab.u &= 0x7fffffff;
            fr.absf = ab.f;
            double dd = d - fr.absf;
            d = dd;
            if (dd <= f0c) {
                int j = (i >= 2) ? 0 : i + 1;
                V3_315860 *rj = &box->axis[j];
                fr.r1 = cv[j] - (fr.P.z * rj->z + fr.P.y * rj->y + fr.P.x * rj->x);
                ab.f = fr.r1;
                ab.u &= 0x7fffffff;
                if (ab.f - box->ext[j] <= 0.0f) {
                    int k2 = (j >= 2) ? 0 : j + 1;
                    V3_315860 *rk = &box->axis[k2];
                    fr.r2 = cv[k2] - (fr.P.z * rk->z + fr.P.y * rk->y + fr.P.x * rk->x);
                    ab.f = fr.r2;
                    ab.u &= 0x7fffffff;
                    if (ab.f - box->ext[k2] <= 0.0f) {
                        V3_315860 *cc = shape->getCenter();
                        fr.P.x = fr.P.x + cc->x;
                        fr.P.y = fr.P.y + cc->y;
                        fr.P.z = fr.P.z + cc->z;
                        double t = fr.sgn * d;
                        // y1 and z1 are rounded frame copies in the original
                        volatile float y1 = t * row->y;
                        volatile float z1 = t * row->z;
                        fr.q48.x = t * row->x + fr.P.x;
                        fr.q48.y = y1 + fr.P.y;
                        fr.q48.z = z1 + fr.P.z;
                        fr.out.x = fr.sgn * row->x;
                        fr.out.y = fr.sgn * row->y;
                        fr.out.z = fr.sgn * row->z;
                        FUN_00314be0(box, &fr.q48, shape, &fr.P, d, &fr.out);
                    }
                }
            }
            if (!flag)
                break;
            ab.f = fr.e;
            ab.u &= 0x7fffffff;
            if (!(2.0 * (ab.f * shape->f50) + d <= f0c))
                break;
            fr.sgn2 = -fr.sgn2;
            ab.f = cv[i];
            ab.u &= 0x7fffffff;
            flag = false;
            d = ab.f - box->ext[i];
        }
    }
}

} // namespace fn_fc854b07

// 0x00315ca0 FUN_00315ca0 (1100 B): equivalent/0x00315ca0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00315ca0@Resolver@fn_00315ca0@@QAEXPAVBody@2@0@Z @a3ee62fe3ee8 @w217c41239245
namespace fn_00315ca0 {
// STATUS: equivalent (tools/equiv.py level 3: 3049 inputs, branch coverage 26/26)
// FUN_00315ca0 @ 0x00315ca0
// equiv-map: ?thunk_FUN_002fb860@Body@@QAEXPAUVec3@@H@Z = 0x002fb940

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


struct Vec3 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void MulAdd(float s, const Vec3 &d, const Vec3 &a) { x = s * d.x + a.x; y = s * d.y + a.y; z = s * d.z + a.z; }
};

union FloatBits {
    float f;
    unsigned int u;
};

class Body {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3 *vfunc_4();
    char pad04[0x44 - 4];
    Vec3 n;                          // 0x44
    float f50;                       // 0x50
    float f54;                       // 0x54
    char b58;                        // 0x58
    void thunk_FUN_002fb860(Vec3 *out, int i);
};

float __cdecl FUN_00083d90(float *v);

// The original keeps this reciprocal unrounded on the FPU stack (double here, to avoid the compiler folding it).
static double Reciprocal(float r, float f54)
{
    return -1.0f / (r + f54);
}

class Resolver {
public:
    char pad00[0x0c];
    float threshold;                 // 0x0c
    char pad10[4];
    Vec3 offset;                     // 0x14
    Vec3 dir;                        // 0x20
    void FUN_00314be0(Body *a, Vec3 *pa, Body *b, Vec3 *pb, float depth, Vec3 *dir);
    void FUN_00315ca0(Body *a1, Body *a2);
};

void Resolver::FUN_00315ca0(Body *a1, Body *a2)
{
    float skip;
    if (a2->b58)
        skip = 0.0f;
    else
        skip = a2->f54;

    for (int i = 0; i < 4; i++) {
        Vec3 v;
        Vec3 c;
        Vec3 w;
        struct {
            float t;
            float r;
        } tr;
        FloatBits ad;
        FloatBits at;
        a1->thunk_FUN_002fb860(&v, i);

        hulk_freg dot = v.z * offset.z + v.y * offset.y + v.x * offset.x;
        ad.f = dot;
        ad.u &= 0x7fffffff;
        if (!(ad.f > 1e-6f))
            continue;
        if (dot > 0.0f) {
            v.x = v.x * -1.0f;
            v.y = v.y * -1.0f;
            v.z = v.z * -1.0f;
        }
        w.x = v.x + offset.x;
        w.y = v.y + offset.y;
        // x87: w.z is stored with fst and the register copy feeds the dot product
        hulk_freg wz = v.z + offset.z;
        w.z = wz;
        tr.t = wz * a2->n.z + w.y * a2->n.y + w.x * a2->n.x;
        at.f = tr.t;
        at.u &= 0x7fffffff;
        hulk_freg distw = at.f - a2->f50;     // stored with fst; the register copy is compared
        float dist = distw;
        if (!(distw - skip <= threshold))
            continue;

        hulk_freg nt = -tr.t;
        dir.x = nt * a2->n.x;
        dir.y = nt * a2->n.y;
        dir.z = nt * a2->n.z;
        dir.x = w.x + dir.x;
        dir.y = w.y + dir.y;
        dir.z = w.z + dir.z;
        // (the original reloads the stored float components here rather than reusing the unrounded sums)
        volatile float *dv = &dir.x;
        // x87: the root and the gap stay in registers; the gap is stored with fst and compared unrounded
        hulk_freg gap = sqrt(dv[0] * dv[0] + dv[1] * dv[1] + dv[2] * dv[2]) - a2->f54;
        tr.r = gap;
        if (!(gap <= threshold))
            continue;

        if (a2->b58 == 0 && at.f >= a2->f50) {
            hulk_freg s2 = -(FUN_00083d90(&tr.t) * a2->f50);
            dir.x = s2 * a2->n.x;
            dir.y = s2 * a2->n.y;
            dir.z = s2 * a2->n.z;
            dir.x = w.x + dir.x;
            dir.y = w.y + dir.y;
            dir.z = w.z + dir.z;
            hulk_freg gap2 = dir.FUN_0022d110() - a2->f54;
            tr.r = gap2;
            if (!(gap2 <= threshold))
                continue;
            Vec3 *p = a1->vfunc_4();
            v.x = v.x + p->x;
            v.y = v.y + p->y;
            v.z = v.z + p->z;
            hulk_freg nr = -tr.r;
            struct { hulk_freg x; float y, z; } sc;   // dir * nr: x stays in a register, y and z are stored
            sc.x = nr * dir.x;
            sc.y = nr * dir.y;
            sc.z = nr * dir.z;
            c.x = sc.x + v.x;
            c.y = sc.y + v.y;
            c.z = sc.z + v.z;
        } else {
            Vec3 *p = a1->vfunc_4();
            v.x = v.x + p->x;
            v.y = v.y + p->y;
            v.z = v.z + p->z;
            if (a2->b58 != 0 && -threshold < dist) {
                hulk_freg sg = FUN_00083d90(&tr.t);
                tr.r = dist;
                dir.x = sg * a2->n.x;
                dir.y = sg * a2->n.y;
                dir.z = sg * a2->n.z;
                c.MulAdd(-dist, dir, v);
            } else {
                if (tr.r == -a2->f54)
                    continue;
                double inv = Reciprocal(tr.r, a2->f54);
                dir.x = inv * dir.x;
                dir.y = inv * dir.y;
                dir.z = inv * dir.z;
                struct { hulk_freg x, y; float z; } sc;   // dir * r: x and y stay in registers, z is stored
                sc.x = tr.r * dv[0];
                sc.y = tr.r * dv[1];
                sc.z = tr.r * dv[2];
                c.x = sc.x + v.x;
                c.y = sc.y + v.y;
                c.z = sc.z + v.z;
                if (dist > 0.0f) {
                    hulk_freg sd = -(FUN_00083d90(&tr.t) * dist);
                    c.x = sd * a2->n.x + c.x;
                    c.y = sd * a2->n.y + c.y;
                    c.z = sd * a2->n.z + c.z;
                    dir.x = v.x - c.x;
                    dir.y = v.y - c.y;
                    dir.z = v.z - c.z;
                    tr.r = dir.FUN_0022d110();
                } else {
                    dir.x = dir.x * -1.0f;
                    dir.y = dir.y * -1.0f;
                    dir.z = dir.z * -1.0f;
                }
            }
        }
        FUN_00314be0(a1, &v, a2, &c, tr.r, &dir);
    }
}
} // namespace fn_00315ca0

namespace fn_fc854b07 {

// 0x003160f0 FUN_003160f0 (791 B): equivalent/0x003160f0.cpp
// sym: ?FUN_003160f0@Collider_3160f0@fn_fc854b07@@QAEXPAVBoxA_3160f0@2@PAVCapB@2@@Z @40359616d1bc @wcfa4bf0d27fa
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 20/20)
// FUN_003160f0 @ 0x003160f0
void Collider_3160f0::FUN_003160f0(BoxA_3160f0* a, CapB* b)
{
    Frame_3160f0 f;
    V3_3160f0* pa = a->v4();
    V3_3160f0* pb = b->v4();
    d.x = pb->x - pa->x;
    d.y = pb->y - pa->y;
    d.z = pb->z - pa->z;
    for (f.i = 0; f.i < 3; f.i++) {
        V3_3160f0* ax = &a->axis[f.i];
        V3_3160f0* bb = &b->dir;
        double cx = bb->z * ax->y - bb->y * ax->z;
        double cy = ax->z * bb->x - bb->z * ax->x;
        volatile float cz = bb->y * ax->x - ax->y * bb->x;
        double k = b->f50 * a->ext[f.i];
        volatile float kf = (float)k;
        f.kx = (float)(k * cx);
        f.ky = (float)(cy * kf);
        // x87: kz is stored with fst and its register copy multiplies the stored one in |k|^2
        double kzw = cz * kf;
        f.kz = (float)kzw;
        double Lx = kzw * f.kz + f.ky * f.ky + f.kx * f.kx;
        volatile float L = (float)Lx;
        if (!(Lx > 9.99999997475243e-007f))
            continue;
        double dpx = f.kz * d.z + f.ky * d.y + f.kx * d.x;
        f.adp = (float)dpx;
        FloatBits_3160f0 fb;
        fb.f = f.adp;
        fb.u &= 0x7fffffff;
        f.adp = fb.f;
        if (!(f.adp > 9.99999997475243e-007f))
            continue;
        f.f54 = b->f54;
        f.len = (float)sqrt((double)L);
        double invx = 1.0f / f.len;
        f.inv = (float)invx;
        f.s = (float)(invx * dpx);
        for (f.j = 0; f.j < 2; f.j++) {
            a->FUN_002fb990(&f.out, f.i, f.j);
            f.q = (f.out.z * f.kz + f.out.y * f.ky + f.out.x * f.kx) * f.inv;
            FloatBits_3160f0 sb;
            sb.f = f.s;
            sb.u &= 0x7fffffff;
            FloatBits_3160f0 qb;
            qb.f = f.q;
            qb.u &= 0x7fffffff;
            f.m = (float)(sb.f - (qb.f + f.f54));
            float aq = qb.f;
            double mn;
            if (aq < b->f54)
                mn = aq;
            else
                mn = b->f54;
            if (!(aq > 9.99999997475243e-007f))
                continue;
            if (!(f.m < f0c))
                continue;
            if (!(-mn < f.m))
                continue;
            if (f.q * f.s < 0.0f) {
                f.out.x = f.out.x * -1.0f;
                f.out.y = f.out.y * -1.0f;
                f.out.z = f.out.z * -1.0f;
            }
            double w = f.inv * b->f54;
            if (f.s > 0.0f)
                w = -w;
            f.u.x = (float)(f.kx * w);
            f.u.y = (float)(f.ky * w);
            f.u.z = (float)(f.kz * w);
            FUN_00315620(&f.out, &a->axis[f.i], a->ext[f.i], &f.u, bb, b->f50, &f.kx, f.len, f.m, a, b);
        }
    }
}


// 0x00316410 FUN_00316410 (4607 B): equivalent/0x00316410.cpp
// sym: ?FUN_00316410@Resolver@fn_fc854b07@@QAEXPAVBody@2@PAUVec3@2@1M0MM_N@Z @e6c8bb1d1143 @w16a3c12f98c7
// STATUS: equivalent (tools/equiv.py level 3: 3111 inputs, branch coverage 99/104, incomplete)
// FUN_00316410 @ 0x00316410
// FUN_00316410 @ 0x00316410
// Resolver::FUN_00316410 (this=ecx, ret 0x20): contact emitter for a swept disc/segment against body b
// (axis b->n, half length f50, radius f54). Four cases: moving along b's axis, moving across it, the
// two-sided sweep (inside && sweep), and the general case that tests both ends of b.
// The locals live in one Frame at the original's stack slots (several slots hold different values in
// different blocks), because the callees get pointers into it.
void Resolver::FUN_00316410(Body *a, Vec3 *vel, Vec3 *axis, float range, Body *b, float lat0, float lat, bool sweep)
{
    // Stack frame at the original's offsets from esp after `sub esp, 0x88`.
    struct Frame {
        union { Vec3 *off; FloatBits w; } s00;                       // 0x00
        FloatBits s04;                                               // 0x04
        FloatBits s08;                                               // 0x08
        FloatBits s0c;                                               // 0x0c
        FloatBits s10;                                               // 0x10
        Vec3 P;                                                      // 0x14
        FloatBits s20;                                               // 0x20
        Resolver *self;                                              // 0x24
        char pad28[3];
        bool inside;                                                 // 0x2b
        union { float pa; int count; float side; };                  // 0x2c
        union { float dp; float dist; float c2; };                   // 0x30
        union { float pm; float spa; };                              // 0x34
        union { float pp; int i; };                                  // 0x38
        union { Vec3 Q; Vec3 T; };                                   // 0x3c
        union { float sup; float sv; };                              // 0x48
        union { Vec3 R; Vec3 Y; };                                   // 0x4c
        Vec3 U;                                                      // 0x58
        Vec3 X;                                                      // 0x64
        float sin2;                                                  // 0x70
        float un;                                                    // 0x74
        float scn;                                                   // 0x78
        Vec3 Z;                                                      // 0x7c
    } fr;

    fr.self = this;
    if (range <= 9.99999997e-007f)
        return;
    fr.s00.off = &offset;
    if (((offset.z * vel->z + offset.y * vel->y) + offset.x * vel->x) > 0.0f) {
        vel->x = vel->x * -1.0f;
        vel->y = vel->y * -1.0f;
        vel->z = vel->z * -1.0f;
    }
    fr.s0c.f = ((b->n.z * axis->z + b->n.y * axis->y) + axis->x * b->n.x);
    fr.s04.u = fr.s0c.u & 0x7fffffff;                      // |cos| of the sweep axis to b's axis
    fr.s0c.f = ((b->n.z * vel->z + b->n.y * vel->y) + b->n.x * vel->x) + lat0;
    fr.s0c.u &= 0x7fffffff;
    if (!(fr.s0c.f - (AbsIn(fr.s08, lat) + b->f50) <= threshold))
        return;
    fr.inside = AbsIn(fr.s08, lat) + fr.s0c.f < b->f50;

    if (fr.s04.f >= 0.999f && !fr.inside) {
        // Sweeping along b's axis.
        fr.P.x = fr.s00.off->x + vel->x;
        fr.P.y = fr.s00.off->y + vel->y;
        // x87: P.z (stored with fst), the gap, sq and r stay in registers (53 bits)
        hulk_freg pz = fr.s00.off->z + vel->z;
        fr.P.z = pz;
        lat = ((pz * b->n.z + fr.P.y * b->n.y) + fr.P.x * b->n.x);   // the dead argument slot holds the axial distance
        hulk_freg gap = (AbsIn(fr.s08, lat) - range) - b->f50;
        fr.s10.f = gap;
        if (!(gap <= threshold))
            return;
        hulk_freg sq = ((fr.P.x * fr.P.x + fr.P.z * fr.P.z) + fr.P.y * fr.P.y) - lat * lat;
        hulk_freg r = threshold + b->f54;
        if (!(sq <= r * r))
            return;
        if (sq >= 9.99999997e-007f && sq < fr.s10.f * fr.s10.f) {
            fr.self->dir.FUN_001f6bc0(&fr.P, -lat, &b->n);
            fr.s0c.f = ((fr.self->dir.z * vel->z + fr.self->dir.y * vel->y) + fr.self->dir.x * vel->x);
            vel->FUN_001f6bc0(&fr.self->dir, FUN_00083d90(&lat) * b->f50, &b->n);
            ((owners::V3_110d0 *)vel)->FUN_000110d0((owners::V3_110d0 *)(const Vec3 *)(b->vfunc_4()));
            fr.s10.f = fr.self->dir.FUN_0022d110();
            if (!(FUN_00083d90(&fr.s0c.f) < 0.0f)
                && !(((fr.s00.off->z * fr.self->dir.z + fr.s00.off->y * fr.self->dir.y) + fr.s00.off->x * fr.self->dir.x) > 0.0f)) {
                fr.s10.f = -(fr.s10.f + b->f54);
                fr.self->dir.x = fr.self->dir.x * -1.0f;
                fr.self->dir.y = fr.self->dir.y * -1.0f;
                fr.self->dir.z = fr.self->dir.z * -1.0f;
            } else {
                fr.s10.f = fr.s10.f - b->f54;
            }
            fr.P.FUN_001f6bc0(vel, -fr.s10.f, &fr.self->dir);
        } else {
            fr.s0c.f = FUN_00083d90(&lat);
            fr.s00.w.f = ((fr.P.x * axis->x + fr.P.z * axis->z) + fr.P.y * axis->y);
            vel->FUN_001f6bc0(&fr.P, -(FUN_00083d90(&fr.s00.w.f) * range), axis);
            ((owners::V3_110d0 *)vel)->FUN_000110d0((owners::V3_110d0 *)(const Vec3 *)(b->vfunc_4()));
            fr.P.FUN_001f6bc0(vel, -(fr.s0c.f * fr.s10.f), &b->n);
            ((owners::Vec3_95e80 *)&(fr.self->dir))->FUN_00095e80(fr.s0c.f, (float const *)(const Vec3 *)(&b->n));
        }
        fr.self->FUN_00314be0(a, vel, b, &fr.P, fr.s10.f, &fr.self->dir);
        return;
    }

    if (fr.s04.f / range <= 0.001f) {
        // Sweeping across b's axis.
        fr.P.x = fr.s00.off->x + vel->x;
        fr.P.y = fr.s00.off->y + vel->y;
        // x87: P.z (stored with fst), the gap, r, hh, pa and pm stay in registers (53 bits)
        hulk_freg pz = fr.s00.off->z + vel->z;
        fr.P.z = pz;
        fr.dp = ((pz * b->n.z + fr.P.y * b->n.y) + fr.P.x * b->n.x);
        hulk_freg gap = AbsIn(fr.s08, fr.dp) - b->f50;
        fr.s08.f = gap;
        if (!(gap <= threshold))
            return;
        fr.self->dir.FUN_000111b0(&b->n, axis);
        fr.s0c.f = ((fr.P.z * fr.self->dir.z + fr.P.y * fr.self->dir.y) + fr.P.x * fr.self->dir.x);
        fr.s10.u = fr.s0c.u & 0x7fffffff;
        hulk_freg r = fr.self->threshold + b->f54;
        if (!(fr.s10.f <= r))
            return;
        hulk_freg hh = r * r - fr.s10.f * fr.s10.f;
        if (hh < 0.0f)
            return;
        fr.s20.f = (float)sqrt(hh);
        hulk_freg pa = ((fr.P.x * axis->x + fr.P.z * axis->z) + fr.P.y * axis->y);
        fr.pa = pa;
        fr.pp = pa + range;
        hulk_freg pm = *(volatile float *)&fr.pa - range;     // the original reloads the stored (rounded) pa
        fr.pm = pm;
        fr.s0c.f = pm * fr.pp;
        fr.s00.w.f = FUN_00083d90(&fr.s0c.f);
        if (!(fr.s00.w.f < 0.0f)) {
            if (!(AbsIn(fr.s04, fr.pp) <= fr.s20.f) && !(AbsIn(fr.s04, fr.pm) <= fr.s20.f))
                return;
        }
        hulk_freg side = fr.s10.f - b->f54;
        fr.s10.f = side;
        if ((!(side > fr.s08.f) && !(AbsIn(fr.s04, fr.s08.f / b->f50) > 0.1f))
            || !(AbsIn(fr.s04, fr.s20.f - b->f54) >= 9.99999997e-007f)) {
            // Touching b's side.
            if (AbsIn(fr.s04, fr.pa) <= fr.s20.f) {
                *vel = fr.P;
            } else {
                fr.s04.f = fr.pm;
                fr.s0c.f = fr.pp;
                fr.s04.u &= 0x7fffffff;
                fr.s0c.u &= 0x7fffffff;
                fr.s0c.f = range - (fr.s20.f - FUN_000186f0(&fr.s0c.f, &fr.s04.f) * fr.s00.w.f);
                vel->FUN_001f6bc0(&fr.P, -(FUN_00083d90(&fr.pa) * fr.s0c.f), axis);
            }
            ((owners::V3_110d0 *)vel)->FUN_000110d0((owners::V3_110d0 *)(const Vec3 *)(b->vfunc_4()));
            ((owners::Vec3_95e80 *)&(fr.self->dir))->FUN_00095e80(FUN_00083d90(&fr.dp), (float const *)(const Vec3 *)(&b->n));
            ((owners::Vec3_95e80 *)&(fr.P))->FUN_00095e80(-fr.s08.f, (float const *)(const Vec3 *)(&fr.self->dir));
            fr.P.x = fr.P.x + vel->x;
            fr.P.y = fr.P.y + vel->y;
            fr.P.z = fr.P.z + vel->z;
            fr.self->FUN_00314be0(a, vel, b, &fr.P, fr.s08.f, &fr.self->dir);
            return;
        }
        if (fr.s00.w.f > 0.0f) {
            // Hitting b's end cap.
            vel->FUN_001f6bc0(&fr.P, (AbsIn(fr.s04, fr.pp) < AbsIn(fr.s08, fr.pm) ? 1.0f : -1.0f) * range, axis);
            ((owners::Vec3_95e80 *)&(fr.P))->FUN_00095e80(fr.dp, (float const *)(const Vec3 *)(&b->n));
            fr.self->dir.FUN_00011110(vel, &fr.P);
            fr.s10.f = fr.self->dir.FUN_0022d110() - b->f54;
            ((owners::V3_110d0 *)vel)->FUN_000110d0((owners::V3_110d0 *)(const Vec3 *)(b->vfunc_4()));
            Vec3 *c = b->vfunc_4();
            fr.P.x = fr.P.x + c->x;
            fr.P.y = fr.P.y + c->y;
            fr.P.z = fr.P.z + c->z;
            ((owners::Vec3_11160 *)&(fr.P))->FUN_00011160(b->f54, (const owners::Vec3_11160 *)(const Vec3 *)(&fr.self->dir));
        } else {
            // Hitting b's rim.
            if (((fr.P.z * fr.self->dir.z + fr.P.y * fr.self->dir.y) + fr.P.x * fr.self->dir.x) < 0.0f) {
                fr.self->dir.x = fr.self->dir.x * -1.0f;
                fr.self->dir.y = fr.self->dir.y * -1.0f;
                fr.self->dir.z = fr.self->dir.z * -1.0f;
            }
            vel->FUN_001f6bc0(b->vfunc_4(), fr.dp, &b->n);
            ((owners::Vec3_11160 *)vel)->FUN_00011160(fr.s10.f + b->f54, (const owners::Vec3_11160 *)(const Vec3 *)(&fr.self->dir));
            fr.P.FUN_001f6bc0(b->vfunc_4(), FUN_00083d90(&fr.dp) * b->f50, &b->n);
            ((owners::Vec3_11160 *)&(fr.P))->FUN_00011160(b->f54, (const owners::Vec3_11160 *)(const Vec3 *)(&fr.self->dir));
        }
        fr.self->FUN_00314be0(a, vel, b, &fr.P, fr.s10.f, &fr.self->dir);
        return;
    }

    if (fr.inside && sweep) {
        // Swept both ways along the axis.
        ((owners::Vec3_34440 *)&(fr.P))->FUN_00034440((owners::Vec3_34440 *)(const Vec3 *)(fr.s00.off), (owners::Vec3_34440 *)(const Vec3 *)vel);
        for (fr.count = 2; fr.count != 0; range = range * -1.0f, fr.count--) {
            fr.Q.x = range * axis->x + fr.P.x;
            fr.Q.y = range * axis->y + fr.P.y;
            // x87: the original keeps Q.z (stored with fst), the axial distance, s2, the root and the radial
            // distance in registers (53 bits); only their stored copies are rounded
            hulk_freg qz = range * axis->z + fr.P.z;
            fr.Q.z = qz;
            hulk_freg ax = (qz * b->n.z + fr.Q.y * b->n.y) + fr.Q.x * b->n.x;
            fr.s04.f = ax;
            hulk_freg s2 = ((fr.Q.x * fr.Q.x + fr.Q.z * fr.Q.z) + fr.Q.y * fr.Q.y) - ax * ax;
            hulk_freg rr = s2 > 0.0f ? (hulk_freg)sqrt(s2) : (hulk_freg)0.0f;
            fr.s08.f = AbsIn(fr.s00.w, fr.s04.f) - b->f50;
            hulk_freg dist = rr - b->f54;
            fr.dist = dist;
            if (!(dist < fr.self->threshold))
                continue;
            fr.s0c.f = FUN_00083d90(&fr.s04.f);
            Vec3 *c = b->vfunc_4();
            vel->x = fr.Q.x + c->x;
            vel->y = fr.Q.y + c->y;
            vel->z = fr.Q.z + c->z;
            if (fr.s08.f > fr.dist) {
                fr.self->dir = b->n;
                ((owners::Vec3_11140 *)&(fr.self->dir))->FUN_00011140(fr.s0c.f);
                fr.R.FUN_001f6bc0(vel, AbsIn(fr.s04, fr.s08.f) * fr.s0c.f, &b->n);
            } else {
                fr.self->dir.FUN_001f6bc0(&fr.Q, -fr.s04.f, &b->n);
                fr.self->dir.FUN_0022d110();
                fr.R.FUN_001f6bc0(b->vfunc_4(), fr.s04.f, &b->n);
                ((owners::Vec3_11160 *)&(fr.R))->FUN_00011160(b->f54, (const owners::Vec3_11160 *)(const Vec3 *)(&fr.self->dir));
                fr.s08.f = fr.dist;
            }
            fr.self->FUN_00314be0(a, vel, b, &fr.R, fr.s08.f, &fr.self->dir);
        }
        return;
    }

    // General case: test both ends of b.
    fr.P.x = fr.s00.off->x + vel->x;
    fr.P.y = fr.s00.off->y + vel->y;
    // x87: P.z (stored with fst), L, the squared reach, g, w, the moved point's y and z, e, dl and r stay in
    // registers (53 bits)
    hulk_freg pz = fr.s00.off->z + vel->z;
    fr.P.z = pz;
    fr.s08.f = ((pz * b->n.z + fr.P.y * b->n.y) + fr.P.x * b->n.x);
    fr.s04.f = FUN_00083d90(&fr.s08.f);
    fr.s00.w.f = ((b->n.z * axis->z + b->n.y * axis->y) + axis->x * b->n.x);
    fr.s0c.f = ((fr.P.x * axis->x + fr.P.z * axis->z) + fr.P.y * axis->y);
    fr.spa = FUN_00083d90(&fr.s0c.f);
    fr.scn = FUN_00083d90(&fr.s00.w.f);
    fr.c2 = fr.s00.w.f * fr.s00.w.f;
    fr.sin2 = 1.0f - fr.c2;
    for (fr.i = 0; fr.i < 2; fr.i++) {
        hulk_freg L = fr.i == 0 ? b->f50 - fr.s08.f : fr.s08.f + b->f50;
        if (fr.c2 == 0.0f)
            continue;
        hulk_freg reach = L * ((fr.sin2 / fr.c2 + 1.0f) * L);
        fr.s20.f = reach;
        if (!(reach < range * range))
            continue;
        hulk_freg g = -(fr.scn * fr.s04.f);
        if (AbsIn(fr.s00.w, fr.s08.f) < b->f50
            && ((fr.s04.f > 0.0f && fr.i == 0) || (fr.s04.f < 0.0f && fr.i == 1)))
            g = g * -1.0f;
        hulk_freg w = g * (hulk_freg)sqrt(fr.s20.f);
        vel->x = w * axis->x;
        vel->y = w * axis->y;
        vel->z = w * axis->z;
        fr.s00.w.f = fr.P.x + vel->x;
        vel->x = fr.s00.w.f;
        hulk_freg vy = fr.P.y + vel->y;
        vel->y = vy;
        hulk_freg vz = fr.P.z + vel->z;
        vel->z = vz;
        fr.s20.f = ((vz * b->n.z + vy * b->n.y) + fr.s00.w.f * b->n.x);
        hulk_freg e = -(FUN_00083d90(&fr.s20.f) * b->f50);
        fr.self->dir.x = e * b->n.x + fr.s00.w.f;
        fr.self->dir.y = e * b->n.y + vel->y;
        fr.self->dir.z = e * b->n.z + vel->z;
        hulk_freg dl = ((fr.self->dir.z * fr.self->dir.z + fr.self->dir.y * fr.self->dir.y) + fr.self->dir.x * fr.self->dir.x);
        hulk_freg r = fr.self->threshold + b->f54;
        if (!(dl < r * r))
            continue;
        fr.s00.w.f = (float)sqrt(dl);
        if (fr.c2 < 0.5f) {
            fr.T.FUN_000111b0(axis, &b->n);
            fr.T.FUN_0022d110();
            fr.s00.w.f = ((fr.T.x * fr.P.x + fr.T.z * fr.P.z) + fr.T.y * fr.P.y);
            if (FUN_00083d90(&fr.s00.w.f) < 0.0f) {
                fr.T.x = fr.T.x * -1.0f;
                fr.T.y = fr.T.y * -1.0f;
                fr.T.z = fr.T.z * -1.0f;
                fr.U.FUN_000111b0(&fr.T, &b->n);
            } else {
                fr.U.FUN_000111b0(&b->n, &fr.T);
            }
            fr.U.FUN_0022d110();
            fr.un = ((fr.U.z * axis->z + fr.U.y * axis->y) + fr.U.x * axis->x);
            hulk_freg rad = fr.self->threshold + b->f54;     // x87: kept in st0 (53 bits), not stored
            fr.s00.w.f = fr.s00.w.f * fr.s00.w.f;
            if (rad * rad - *(volatile float *)&fr.s00.w.f <= 0.0f)     // the original reloads the stored (rounded) square
                continue;
            fr.s00.w.f = (float)sqrt(rad * rad - *(volatile float *)&fr.s00.w.f);
            fr.s20.f = ((fr.U.x * fr.P.x + fr.U.z * fr.P.z) + fr.U.y * fr.P.y);
            fr.sup = FUN_00083d90(&fr.s20.f);
            fr.s10.f = fr.s20.f;
            fr.s20.u &= 0x7fffffff;
            fr.side = fr.s20.f > fr.s00.w.f ? -1.0f : 1.0f;
            hulk_freg z = fr.s20.f - fr.side * fr.s00.w.f;    // x87: z and 1/un stay in registers
            fr.s0c.f = z;
            fr.s0c.u &= 0x7fffffff;
            hulk_freg inv = 1.0f / fr.un;
            fr.s20.f = ((fr.s00.w.f + fr.s00.w.f) - fr.s0c.f) * inv;
            fr.s10.f = z * inv;
            if (AbsIn(fr.s00.w, fr.s20.f) > range)
                fr.s20.f = FUN_00083d90(&fr.s20.f) * range;
            if (AbsIn(fr.s00.w, fr.s10.f) > range)
                fr.s10.f = FUN_00083d90(&fr.s10.f) * range;
            if (fr.sup * fr.spa > 0.0f) {
                fr.X.FUN_001f6bc0(&fr.P, -((fr.s20.f * fr.side) * fr.spa), axis);
                fr.Y.FUN_001f6bc0(&fr.P, -(fr.s10.f * fr.spa), axis);
            } else {
                fr.X.FUN_001f6bc0(&fr.P, (fr.s20.f * fr.side) * fr.spa, axis);
                fr.Y.FUN_001f6bc0(&fr.P, fr.s10.f * fr.spa, axis);
            }
            fr.sv = ((b->n.z * vel->z + b->n.y * vel->y) + b->n.x * vel->x);
            fr.s00.w.f = FUN_00083d90(&fr.sv);
            ((owners::Vec3_95e80 *)&(fr.self->dir))->FUN_00095e80(fr.s00.w.f, (float const *)(const Vec3 *)(&b->n));
            // x87: the distance is stored (fst) and compared unrounded
            hulk_freg dx = ((fr.X.z * b->n.z + fr.X.y * b->n.y) + fr.X.x * b->n.x) * fr.s00.w.f - b->f50;
            fr.s20.f = dx;
            if (dx < fr.self->threshold * 1.03f) {
                *vel = fr.X;
            } else {
                *vel = fr.Y;
                hulk_freg dy = ((fr.Y.z * b->n.z + fr.Y.y * b->n.y) + fr.Y.x * b->n.x) * fr.s00.w.f - b->f50;
                fr.s20.f = dy;
                if (dy >= fr.self->threshold * 1.03f)
                    continue;
            }
            ((owners::V3_110d0 *)vel)->FUN_000110d0((owners::V3_110d0 *)(const Vec3 *)(b->vfunc_4()));
        } else {
            ((owners::V3_110d0 *)vel)->FUN_000110d0((owners::V3_110d0 *)(const Vec3 *)(b->vfunc_4()));
            if (fr.s00.w.f != 0.0f)
                ((owners::Vec3_11140 *)&(fr.self->dir))->FUN_00011140(1.0f / fr.s00.w.f);
            else
                fr.self->dir = b->n;
            fr.s20.f = fr.s00.w.f - b->f54;
        }
        fr.Z.FUN_001f6bc0(vel, -fr.s20.f, &fr.self->dir);
        fr.self->FUN_00314be0(a, vel, b, &fr.Z, fr.s20.f, &fr.self->dir);
    }
}


// 0x00317610 FUN_00317610 (225 B): equivalent/0x00317610.cpp
// sym: ?target@Controller_317610@fn_fc854b07@@QAEXPAXPAUObject@2@PBUVec_317610@2@M@Z @383bf7eef0f9 @w493327440324
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00317610 @ 0x00317610
void Controller_317610::target(void* a,Object* obj,const Vec_317610* input,float value) {
 Vec_317610 point=*input; Vec_317610 result,other;
 if (FUN_00313b70(a,&point,&result,&other,&value,value,1)) {
  bool skip=false;
  if(obj->kind()==2 && !flag && !obj->flag) {
   Vec_317610* origin=obj->position();
   union {float f; unsigned int u;} dot;
   dot.f=(point.z-origin->z)*obj->nz+(point.y-origin->y)*obj->ny+(point.x-origin->x)*obj->nx;
   dot.u &= 0x7fffffff;
   skip=(obj->radius-margin)>dot.f;
  }
  if(!skip) FUN_00314be0(a,&result,obj,&point,value,&other);
 }
}

} // namespace fn_fc854b07

// 0x00317700 FUN_00317700 (4549 B): equivalent/0x00317700.cpp [wrapped: conflict: Vec3]
// sym: ?FUN_00317700@Resolver@fn_00317700@@QAE_NPAVBody@2@0D_N@Z @aea6d2ea7a4e @w5797b2b0673c
namespace fn_00317700 {
// STATUS: equivalent (tools/equiv.py level 3: 20036 inputs, branch coverage 122/126, incomplete)
// FUN_00317700 @ 0x00317700
// FUN_00317700 @ 0x00317700
// Resolver::FUN_00317700 (this=ecx, ret 0x10): contact emitter for two swept bodies. Each body is a segment
// (n = axis, f50 = half length) with radius f54; b58 says whether the body is "long" (capsule) or not.
// Both short: test the four end-point pairs as spheres. Both long: end-point pairs, then the parallel case or
// the closest points of the two axes. Mixed: test the short body's two end points against the long one.
// The locals live in one Frame at the original's stack slots (several slots hold different values in
// different blocks), because the callees get pointers into it.

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    void FUN_001f6bc0(const Vec3 *base, float s, const Vec3 *dir);
};

union FloatBits {
    float f;
    unsigned int u;
};

class Body {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3 *vfunc_4();
    char pad04[0x44 - 4];
    Vec3 n;                          // 0x44
    float f50;                       // 0x50
    float f54;                       // 0x54
    char b58;                        // 0x58
};

float __cdecl FUN_00083d90(float *v);

class Resolver {
public:
    char pad00[0x0c];
    float threshold;                 // 0x0c
    char pad10[4];
    Vec3 offset;                     // 0x14
    Vec3 dir;                        // 0x20
    void FUN_00314be0(Body *a, Vec3 *pa, Body *b, Vec3 *pb, float depth, Vec3 *dir);
    int FUN_00314a10(const Vec3 *a1, const Vec3 *a2, const Vec3 *axis, float f4, float f5, char flag, Vec3 *out, Vec3 *out2);
    bool FUN_00314430(Body *p, Vec3 *a1, float a2, Vec3 *a3, float *a4, Vec3 *a5, Vec3 *a6, char a7);
    bool FUN_003148c0(Vec3 *a1, Vec3 *a2, Vec3 *a3, Vec3 *a4, Vec3 *result, Vec3 *axisDir, bool computeAxis);
    bool FUN_00317700(Body *a, Body *b, char mode, bool emit);
};

bool Resolver::FUN_00317700(Body *a, Body *b, char mode, bool emit)
{
    // Stack frame, at the original's offsets (comments: offset from esp after the register pushes).
    struct Frame {
        union { float rb0; float e2; float B1; float r0; };          // 0x10
        union { float d; Body *s1; };                                // 0x14
        union { int i0; FloatBits tmp; float qq; };                  // 0x18
        union { int rc; float Y; float A1; };                        // 0x1c
        float d0;                                                    // 0x20
        union { float ra; float t1; };                               // 0x24
        union { float sinAB; float t2; };                            // 0x28
        Vec3 pB;                                                     // 0x2c
        union { float ra0; Vec3 *pa2; };                             // 0x38
        char pad3c[2];
        char swapped;                                                // 0x3e
        bool hit;                                                    // 0x3f
        Vec3 pA;                                                     // 0x40
        union { int j0; Vec3 *pb2; float lenSq; };                   // 0x4c
        union { Vec3 u; Vec3 qr; Vec3 negDir; };                     // 0x50
        float rb;                                                    // 0x5c
        union { float e1; float disc; };                             // 0x60
        union { Vec3 Q0; Vec3 N; };                                  // 0x64
        union { Vec3 P0; Vec3 W; };                                  // 0x70
        union { Vec3 w; Vec3 P; };                                   // 0x7c
        union { float len; FloatBits tb; };                          // 0x88
        Vec3 Q;                                                      // 0x8c
        int j;                                                       // 0x98
        union { float nd; FloatBits ad; float sd; };                 // 0x9c
        union { Vec3 *outA; int i; };                                // 0xa0
        union { Vec3 *outB; float C1; };                             // 0xa4
        union { Vec3 R; Vec3 S; };                                   // 0xa8
        FloatBits ta;                                                // 0xb4
        Vec3 hit2;                                                   // 0xb8
        FloatBits diff;                                              // 0xc4
        float cosAB;                                                 // 0xc8
        Vec3 axis;                                                   // 0xcc
        Vec3 pA2;                                                    // 0xd8
    } fr;

    fr.hit = 0;
    if (emit) {
        fr.outA = &fr.pA;
        fr.outB = &fr.pB;
    } else {
        fr.outB = 0;
        fr.outA = 0;
    }

    if (!a->b58 && !b->b58) {
        // Both short: test the end points of the two axes as spheres.
        fr.ra0 = a->f50;
        for (fr.i0 = 0; fr.i0 < 2; fr.i0++) {
            fr.rb0 = b->f50;
            for (fr.j0 = 0; fr.j0 < 2; fr.j0++) {
                fr.u.x = fr.ra0 * a->n.x;
                fr.u.y = fr.ra0 * a->n.y;
                fr.u.z = fr.ra0 * a->n.z;
                fr.w.x = fr.rb0 * b->n.x;
                fr.w.y = fr.rb0 * b->n.y;
                fr.w.z = fr.rb0 * b->n.z;
                Vec3 *ca = a->vfunc_4();
                fr.P0.x = fr.u.x + ca->x;
                fr.P0.y = fr.u.y + ca->y;
                fr.P0.z = fr.u.z + ca->z;
                Vec3 *cb = b->vfunc_4();
                fr.Q0.x = fr.w.x + cb->x;
                fr.Q0.y = fr.w.y + cb->y;
                fr.Q0.z = fr.w.z + cb->z;
                dir.x = fr.P0.x - fr.Q0.x;
                dir.y = fr.P0.y - fr.Q0.y;
                dir.z = fr.P0.z - fr.Q0.z;
                fr.len = dir.FUN_0022d110();
                if ((b->f54 + a->f54) + threshold >= fr.len
                    && !(((fr.u.z * dir.z + fr.u.y * dir.y) + fr.u.x * dir.x) > 0.0f)
                    && !(((fr.w.z * dir.z + fr.w.y * dir.y) + fr.w.x * dir.x) < 0.0f)) {
                    if (emit) {
                        float ha = -a->f54;
                        fr.pA.x = ha * dir.x + fr.P0.x;
                        fr.pA.y = ha * dir.y + fr.P0.y;
                        fr.pA.z = ha * dir.z + fr.P0.z;
                        float hb = b->f54;
                        fr.pB.x = hb * dir.x + fr.Q0.x;
                        fr.pB.y = hb * dir.y + fr.Q0.y;
                        fr.pB.z = hb * dir.z + fr.Q0.z;
                        FUN_00314be0(a, &fr.pA, b, &fr.pB, fr.len - (b->f54 + a->f54), &dir);
                    }
                    return true;
                }
                fr.rb0 = fr.rb0 * -1.0f;
            }
            fr.ra0 = fr.ra0 * -1.0f;
        }
        return fr.hit;
    }

    if (a->b58 && b->b58) {
        // Both long.
        volatile Vec3 *offw = &offset;
        volatile Vec3 *dirw = &dir;
        fr.cosAB = ((a->n.z * b->n.z + a->n.y * b->n.y) + b->n.x * a->n.x);
        fr.N.x = a->n.y * b->n.z - a->n.z * b->n.y;
        fr.N.y = a->n.z * b->n.x - b->n.z * a->n.x;
        fr.N.z = b->n.y * a->n.x - a->n.y * b->n.x;
        fr.axis = fr.N;
        fr.sinAB = fr.N.FUN_0022d110();
        fr.ra = a->f50;
        for (fr.i = 0; fr.i < 2; fr.i++) {
            fr.rb = b->f50;
            for (fr.j = 0; fr.j < 2; fr.j++, fr.rb = fr.rb * -1.0f) {
                Vec3 *ca = a->vfunc_4();
                fr.P.x = fr.ra * a->n.x + ca->x;
                fr.P.y = fr.ra * a->n.y + ca->y;
                fr.P.z = fr.ra * a->n.z + ca->z;
                Vec3 *cb = b->vfunc_4();
                fr.Q.x = fr.rb * b->n.x + cb->x;
                fr.Q.y = fr.rb * b->n.y + cb->y;
                fr.Q.z = fr.rb * b->n.z + cb->z;
                offw->x = fr.P.x - fr.Q.x;
                offw->y = fr.P.y - fr.Q.y;
                offw->z = fr.P.z - fr.Q.z;
                if ((fr.rb * fr.ra) * fr.cosAB > 0.0f)
                    continue;

                float hmax = a->f54 < b->f54 ? b->f54 : a->f54;
                if (fr.sinAB < threshold / hmax) {
                    // Nearly parallel axes.
                    float s = fr.rb < 0.0f ? -1.0f : (fr.rb > 0.0f ? 1.0f : 0.0f);
                    dirw->x = s * b->n.x;
                    dirw->y = s * b->n.y;
                    dirw->z = s * b->n.z;
                    fr.d = ((dir.z * offset.z + dir.y * offset.y) + dir.x * offset.x);
                    if (!(fr.d < threshold))
                        continue;
                    float rmin = a->f50 < b->f50 ? a->f50 : b->f50;
                    if (!(rmin + rmin > -fr.d))
                        continue;
                    fr.Q.x = fr.d * dir.x + fr.Q.x;
                    fr.Q.y = fr.d * dir.y + fr.Q.y;
                    fr.Q.z = fr.d * dir.z + fr.Q.z;
                    int rc;
                    if (a->f54 < b->f54)
                        rc = FUN_00314a10(&fr.P, &fr.Q, &a->n, a->f54, b->f54, 1, &fr.pA, &fr.pA2);
                    else
                        rc = FUN_00314a10(&fr.Q, &fr.P, &b->n, b->f54, a->f54, 1, &fr.pA, &fr.pA2);
                    fr.rc = rc;
                    if (rc == -1)
                        continue;
                    if (emit) {
                        fr.nd = -fr.d;
                        fr.pB.x = fr.nd * dir.x + fr.pA.x;
                        fr.pB.y = fr.nd * dir.y + fr.pA.y;
                        fr.pB.z = fr.nd * dir.z + fr.pA.z;
                        FUN_00314be0(a, &fr.pA, b, &fr.pB, fr.d, &dir);
                        if (fr.rc == 2) {
                            fr.pB.FUN_001f6bc0(&fr.pA2, fr.nd, &dir);
                            FUN_00314be0(a, &fr.pA2, b, &fr.pB, fr.d, &dir);
                        }
                    }
                    return true;
                }

                // Separation along each axis, beyond the other body's reach.
                fr.ta.f = ((a->n.z * offset.z + a->n.y * offset.y) + a->n.x * offset.x);
                fr.ta.u &= 0x7fffffff;
                float sa = fr.ta.f - fr.sinAB * b->f54;
                if (sa > threshold)
                    continue;
                fr.tb.f = ((b->n.z * offset.z + b->n.y * offset.y) + offset.x * b->n.x);
                fr.tb.u &= 0x7fffffff;
                float sb = fr.tb.f - fr.sinAB * a->f54;
                if (sb > threshold)
                    continue;
                if (sa <= sb) {
                    fr.swapped = 1;
                    float s = FUN_00083d90(&fr.rb);
                    dirw->x = s * b->n.x;
                    dirw->y = s * b->n.y;
                    dirw->z = s * b->n.z;
                } else {
                    fr.swapped = 0;
                    float s = FUN_00083d90(&fr.ra);
                    dirw->x = s * a->n.x;
                    dirw->y = s * a->n.y;
                    dirw->z = s * a->n.z;
                    offw->x = offset.x * -1.0f;
                    offw->y = offset.y * -1.0f;
                    offw->z = offset.z * -1.0f;
                }

                // Closest points of the two axes.
                FUN_003148c0(&fr.P, &fr.Q, &a->n, &b->n, &fr.R, &fr.axis, false);
                float px = fr.P.x - fr.R.x;
                float py = fr.P.y - fr.R.y;
                float pz = fr.P.z - fr.R.z;
                fr.qr.x = fr.Q.x - fr.R.x;
                fr.qr.y = fr.Q.y - fr.R.y;
                fr.qr.z = fr.Q.z - fr.R.z;
                fr.e1 = ((px * fr.N.x + pz * fr.N.z) + py * fr.N.y);
                fr.e2 = ((fr.qr.x * fr.N.x + fr.qr.z * fr.N.z) + fr.qr.y * fr.N.y);
                float da = ((px * px + pz * pz) + py * py) - fr.e1 * fr.e1;
                fr.Y = ((fr.qr.x * fr.qr.x + fr.qr.z * fr.qr.z) + fr.qr.y * fr.qr.y) - fr.e2 * fr.e2;
                if (!(0.0f < da))
                    da = 0.0f;
                if (!(0.0f < fr.Y))
                    fr.Y = 0.0f;
                float za = a->f54 * a->f54 - da;
                za = za > 0.0f ? (float)sqrt(za) : 0.0f;
                float zb = b->f54 * b->f54 - fr.Y;
                zb = zb > 0.0f ? (float)sqrt(zb) : 0.0f;
                fr.diff.f = fr.e1 - fr.e2;
                fr.ad.u = fr.diff.u & 0x7fffffff;
                if (!(fr.ad.f - (zb + za) < threshold))
                    continue;

                Body *s2;
                if (fr.swapped) {
                    s2 = a;
                    fr.s1 = b;
                    fr.pb2 = &fr.P;
                    fr.pa2 = &fr.Q;
                } else {
                    s2 = b;
                    fr.s1 = a;
                    fr.pb2 = &fr.Q;
                    fr.pa2 = &fr.P;
                }
                float c = 1.0f - fr.sinAB * fr.sinAB;
                c = c > 0.0f ? (float)sqrt(c) : 0.0f;
                fr.rc = FUN_00314a10(fr.pa2, fr.pb2, &fr.s1->n, fr.s1->f54, c * s2->f54, 1, &fr.pA, &fr.hit2);
                if (fr.rc == 1 || fr.rc == 2) {
                    fr.pB.x = fr.pA.x - fr.pa2->x;
                    fr.pB.y = fr.pA.y - fr.pa2->y;
                    fr.pB.z = fr.pA.z - fr.pa2->z;
                    fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                }
                if ((fr.rc == 1 || fr.rc == 2) && fr.d0 < threshold && fr.sinAB < 0.5f) {
                    if (!emit)
                        return true;
                    fr.pB.FUN_001f6bc0(&fr.pA, -fr.d0, &dir);
                    FUN_00314be0(s2, &fr.pA, fr.s1, &fr.pB, fr.d0, &dir);
                }
                if (fr.rc == 2) {
                    fr.pB.x = fr.hit2.x - fr.pa2->x;
                    fr.pB.y = fr.hit2.y - fr.pa2->y;
                    fr.pB.z = fr.hit2.z - fr.pa2->z;
                    fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                    if (fr.d0 < threshold && fr.sinAB < 0.5f) {
                        if (!emit)
                            return true;
                        fr.pB.FUN_001f6bc0(&fr.hit2, -fr.d0, &dir);
                        FUN_00314be0(s2, &fr.hit2, fr.s1, &fr.pB, fr.d0, &dir);
                    }
                }

                // Points of s2's axis at the distance s1's radius from s1's axis: solve the quadratic.
                fr.W.x = fr.N.z * s2->n.y - fr.N.y * s2->n.z;
                fr.W.y = fr.N.x * s2->n.z - fr.N.z * s2->n.x;
                fr.W.z = fr.N.y * s2->n.x - fr.N.x * s2->n.y;
                fr.W.FUN_0022d110();
                Body *s1 = fr.s1;
                float p = ((fr.W.z * s1->n.z + fr.W.y * s1->n.y) + fr.W.x * s1->n.x);
                float q = ((s1->n.z * offset.z + s1->n.y * offset.y) + offset.x * s1->n.x);
                fr.A1 = ((1.0f - p * p) * s2->f54) * s2->f54;
                float r = ((fr.W.z * offset.z + fr.W.y * offset.y) + fr.W.x * offset.x);
                fr.B1 = ((r - q * p) * s2->f54) * 2.0f;
                fr.C1 = (((offset.z * offset.z + offset.y * offset.y) + offset.x * offset.x) - q * q) - s1->f54 * s1->f54;
                float ac = fr.C1 * fr.A1;
                fr.disc = (fr.B1 * fr.B1) - (ac * 4.0f);
                fr.tmp.f = ac;
                fr.tmp.u &= 0x7fffffff;
                if (fr.tmp.f < 9.99999997e-007f) {
                    bool solved = false;
                    if (fr.disc >= 0.0f) {
                        float sg = FUN_00083d90(&fr.B1);
                        fr.sd = (float)sqrt(fr.disc);
                        fr.qq = ((fr.sd * sg) + fr.B1) * -2.0f;
                        if (fr.qq != 0.0f && fr.A1 != 0.0f) {
                            fr.t1 = fr.qq / fr.A1;
                            fr.t2 = fr.C1 / fr.qq;
                            solved = true;
                        }
                    }
                    if (!solved) {
                        fr.t2 = 0.0f;
                        fr.t1 = 0.0f;
                        if (offset.FUN_00018990() < fr.s1->f54) {
                            fr.t1 = 1.0f;
                            fr.t2 = -1.0f;
                        }
                    }
                } else {
                    if (!(fr.disc >= 0.0f))
                        continue;
                    float root = (float)sqrt(fr.disc);
                    float inv = 1.0f / fr.A1;
                    fr.t1 = ((root - fr.B1) * inv) * 0.5f;
                    fr.t2 = ((-fr.B1 - root) * inv) * 0.5f;
                }
                fr.tmp.f = fr.t1;
                fr.tmp.u &= 0x7fffffff;
                if (!(fr.tmp.f <= 1.0f))
                    fr.t1 = FUN_00083d90(&fr.t1);
                fr.tmp.f = fr.t2;
                fr.tmp.u &= 0x7fffffff;
                if (!(fr.tmp.f <= 1.0f))
                    fr.t2 = FUN_00083d90(&fr.t2);

                                float s = fr.t1 * s2->f54;
                fr.pA.x = fr.W.x * s + fr.pb2->x;
                fr.pA.y = fr.W.y * s + fr.pb2->y;
                fr.pA.z = fr.W.z * s + fr.pb2->z;
                fr.pB.x = fr.pA.x - fr.pa2->x;
                fr.pB.y = fr.pA.y - fr.pa2->y;
                fr.pB.z = fr.pA.z - fr.pa2->z;
                fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                if (fr.d0 < threshold) {
                    if (!emit)
                        return true;
                    fr.pB.FUN_001f6bc0(&fr.pA, -fr.d0, &dir);
                    FUN_00314be0(s2, &fr.pA, fr.s1, &fr.pB, fr.d0, &dir);
                }
                s = fr.t2 * s2->f54;
                fr.pA.x = fr.W.x * s + fr.pb2->x;
                fr.pA.y = fr.W.y * s + fr.pb2->y;
                fr.pA.z = fr.W.z * s + fr.pb2->z;
                fr.pB.x = fr.pA.x - fr.pa2->x;
                fr.pB.y = fr.pA.y - fr.pa2->y;
                fr.pB.z = fr.pA.z - fr.pa2->z;
                fr.d0 = ((fr.pB.z * dir.z + fr.pB.y * dir.y) + fr.pB.x * dir.x);
                if (fr.d0 < threshold && emit) {
                    fr.pB.FUN_001f6bc0(&fr.pA, -fr.d0, &dir);
                    FUN_00314be0(s2, &fr.pA, fr.s1, &fr.pB, fr.d0, &dir);
                }
                return true;
            }
            fr.ra = fr.ra * -1.0f;
        }
        return fr.hit;
    }

    // One long body (lng) and one short one (sht): test the short body's end points.
    Body *lng = a;
    Body *sht = b;
    if (b->b58) {
        offset.x = offset.x * -1.0f;
        offset.y = offset.y * -1.0f;
        offset.z = offset.z * -1.0f;
        lng = b;
        sht = a;
    }
    fr.r0 = sht->f50;
    for (fr.j = 0; fr.j < 2; fr.j++) {
        Vec3 *cs = sht->vfunc_4();
        fr.S.x = fr.r0 * sht->n.x + cs->x;
        fr.S.y = fr.r0 * sht->n.y + cs->y;
        fr.S.z = fr.r0 * sht->n.z + cs->z;
        Vec3 *cl = lng->vfunc_4();
        offset.x = cl->x - fr.S.x;
        offset.y = cl->y - fr.S.y;
        offset.z = cl->z - fr.S.z;
        fr.lenSq = ((offset.z * offset.z + offset.y * offset.y) + offset.x * offset.x);
        if (FUN_00314430(lng, &fr.S, sht->f54, &dir, &fr.lenSq, fr.outA, fr.outB, mode)) {
            fr.hit = 1;
            if (!emit)
                return true;
            if (lng == a) {
                FUN_00314be0(lng, &fr.pA, sht, &fr.pB, fr.lenSq, &dir);
            } else {
                fr.negDir = dir;
                fr.negDir.x = fr.negDir.x * -1.0f;
                fr.negDir.y = fr.negDir.y * -1.0f;
                fr.negDir.z = fr.negDir.z * -1.0f;
                FUN_00314be0(sht, &fr.pB, lng, &fr.pA, fr.lenSq, &fr.negDir);
            }
        }
        fr.r0 = fr.r0 * -1.0f;
    }
    return fr.hit;
}
} // namespace fn_00317700

namespace fn_fc854b07 {

// 0x003188d0 FUN_003188d0 (62 B): equivalent/0x003188d0.cpp
// sym: ?FUN_003188d0@Owner@fn_fc854b07@@QAEEM@Z @3c3968b26b7c @w5c43663b3d4f
// STATUS: equivalent (tools/equiv.py level 3: 17909 inputs, branch coverage 3/4, incomplete)
// FUN_003188d0 @ 0x003188d0
unsigned char Owner::FUN_003188d0(float value)
{
    Store *s = store;
    Item *old = s->cursor;
    if (value < old[-1].key) {
        s->cursor = old - 1;
        if ((hulk_uintptr)(old - 1) < (hulk_uintptr)s->cursor)
            ((ThisCall_002f7a90*)(this))->FUN_002f7a90(s->cursor);
        --count;
        return 0;
    }
    return 1;
}


// 0x00318910 FUN_00318910 (659 B): equivalent/0x00318910.cpp
// sym: ?FUN_00318910@Solver_318910@fn_fc854b07@@QAEXPAVProbe_318910@2@0@Z @f2e3d95bd06e @w959df1b66773
// STATUS: equivalent (tools/equiv.py level 3: 20042 inputs, branch coverage 21/22, incomplete)
// FUN_00318910 @ 0x00318910
void Solver_318910::FUN_00318910(Probe_318910 *a1, Probe_318910 *a2)
{
    Frame_318910 fr;
    fr.n = count;
    for (fr.counter = 2; fr.counter != 0; fr.counter--) {
        Probe_318910 *x = (fr.counter == 2) ? a2 : a1;
        Probe_318910 *y = (fr.counter == 2) ? a1 : a2;
        if (x->done)
            continue;

        Vec3_318910 *q0;
        Vec3_318910 *p0;
        fr.t = x->time;
        p0 = x->v4();
        fr.p.x = fr.t * x->dirX + p0->x;
        fr.p.y = fr.t * x->dirY + p0->y;
        fr.p.z = fr.t * x->dirZ + p0->z;
        q0 = y->v4();
        dx = q0->x - fr.p.x;
        dy = q0->y - fr.p.y;
        dz = q0->z - fr.p.z;
        lenSq = *(volatile float *)&dz * *(volatile float *)&dz + dy * dy + dx * dx; // dz is reloaded (rounded) from the member
        if (FUN_00314430(y, &fr.p, x->ref, &fr.d, &lenSq, &fr.out2, &fr.out1, 1)) {
            fr.sq = fr.d.z * fr.d.z + fr.d.y * fr.d.y + fr.d.x * fr.d.x;
            if (fr.sq > 0.0f) {
                fr.tmp = fr.sq - 1.0f;
                if (fr.tmp < 0.0f)
                    fr.tmp = -fr.tmp;
                if (fr.tmp > 0.01f) {
                    double inv = 1.0 / sqrt((double)fr.sq);
                    fr.d.x = (float)(fr.d.x * inv);
                    fr.d.y = (float)(fr.d.y * inv);
                    fr.d.z = (float)(fr.d.z * inv);
                }
            }
            if (fr.n < count) {
                Elem44 *oldEnd = list->end;
                if (!(lenSq < oldEnd[-1].key))
                    continue;
                Elem44 *newEnd = list->end - 1;
                list->end = newEnd;
                if (oldEnd - 1 < newEnd)
                    ((ThisCall_002f7a90*)(this))->FUN_002f7a90(newEnd);
                count--;
            }
            FUN_00314be0(y, &fr.out2, x, &fr.out1, lenSq, &fr.d);
        } else {
            fr.sq = -x->time;
            p0 = x->v4();
            fr.p.x = fr.sq * x->dirX + p0->x;
            fr.p.y = fr.sq * x->dirY + p0->y;
            fr.p.z = fr.sq * x->dirZ + p0->z;
            q0 = y->v4();
            dx = q0->x - fr.p.x;
            dy = q0->y - fr.p.y;
            dz = q0->z - fr.p.z;
            lenSq = *(volatile float *)&dz * *(volatile float *)&dz + dy * dy + dx * dx; // dz is reloaded (rounded) from the member
            if (!FUN_00314430(y, &fr.p, x->ref, &fr.d, &lenSq, &fr.out2, &fr.out1, 1))
                continue;
            if (fr.n < count) {
                if (FUN_003188d0(lenSq))
                    continue;
            }
            FUN_00314be0(y, &fr.out2, x, &fr.out1, lenSq, &fr.d);
        }
    }
}


// 0x00318bb0 FUN_00318bb0 (557 B): equivalent/0x00318bb0.cpp
// sym: ?Test@Contact_318bb0@fn_fc854b07@@QAEXPAVShape_318bb0@2@0@Z @ede0388227c8 @w334f41926e49
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 14/14)
// FUN_00318bb0 @ 0x00318bb0
void Contact_318bb0::Test(Shape_318bb0 *a, Shape_318bb0 *b)
{
    struct Frame {
        char pad[3];
        bool parallel;
        int counter;
        float adot;
        float crossVal;
        float crossAbs;
        Vec3_318bb0 dir;
        Vec3_318bb0 out;
    } fr;
    Shape_318bb0 *p = b;
    Shape_318bb0 *q = a;
    FloatBits_318bb0 bits;

    bits.f = p->normal.z * q->normal.z + p->normal.y * q->normal.y + p->normal.x * q->normal.x;
    bits.u &= 0x7fffffff;
    fr.adot = bits.f;
    fr.counter = 2;
    do {
        if (p->active) {
            if (fr.adot < 0.1f) {
                fr.parallel = true;
                fr.dir = p->normal;
            } else {
                fr.parallel = false;
                Vec3_318bb0 *qp = q->position();
                Vec3_318bb0 *pp = p->position();
                fr.dir.x = pp->x - qp->x;
                fr.dir.y = pp->y - qp->y;
                fr.dir.z = pp->z - qp->z;
            }
            if (FUN_00314380(q, p, &fr.dir, &fr.out)) {
                bool ok = true;
                Vec3_318bb0 *pp = p->position();
                Vec3_318bb0 *qp = q->position();
                delta.x = qp->x - pp->x;
                delta.y = qp->y - pp->y;
                delta.z = qp->z - pp->z;
                if (fr.parallel) {
                    fr.dir.x = p->normal.y * q->normal.z - p->normal.z * q->normal.y;
                    fr.dir.y = q->normal.x * p->normal.z - p->normal.x * q->normal.z;
                    fr.dir.z = p->normal.x * q->normal.y - q->normal.x * p->normal.y;
                    fr.crossVal = (fr.out.z + delta.z) * fr.dir.z + (fr.out.y + delta.y) * fr.dir.y +
                                  (fr.out.x + delta.x) * fr.dir.x;
                    bits.f = fr.crossVal;
                    bits.u &= 0x7fffffff;
                    fr.crossAbs = bits.f;
                    if (fr.crossAbs > p->limit) {
                        Vec3_318bb0 *qp2 = q->position();
                        Vec3_318bb0 *pp2 = p->position();
                        fr.dir.x = pp2->x - qp2->x;
                        fr.dir.y = pp2->y - qp2->y;
                        fr.dir.z = pp2->z - qp2->z;
                        ok = FUN_00314380(q, p, &fr.dir, &fr.out);
                    }
                }
                if (ok) {
                    FUN_00316410(q, &fr.out, &q->normal, q->extent, p,
                                 p->normal.z * delta.z + p->normal.y * delta.y + p->normal.x * delta.x,
                                 (p->normal.z * q->normal.z + p->normal.y * q->normal.y + p->normal.x * q->normal.x) * q->extent,
                                 1);
                }
            }
        }
        q = b;
        p = a;
        fr.counter--;
    } while (fr.counter != 0);
}

} // namespace fn_fc854b07

// 0x00318de0 FUN_00318de0 (1161 B): equivalent/0x00318de0.cpp [wrapped: macros]
// sym: ?FUN_00318de0@Collider@fn_00318de0@@QAEXPAVBox@2@0@Z @2b432463b6ee @wc10d842872fd
namespace fn_00318de0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// FUN_00318de0 @ 0x00318de0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3 {
    float x;
    float y;
    float z;
};

class Box {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3 *v4();
    char pad04[0x48 - 4];
    float ext[3];
    V3 axes[3];
    void FUN_002fb990(V3 *out, int axis, int side);
};

class Collider {
public:
    char pad0[0xc];
    float thr;
    char pad10[4];
    V3 d;
    char pad20[0x30 - 0x20];
    int count;
    void FUN_00313650(int *order, float *gap);
    void FUN_00315620(V3 *p, V3 *aAxis, float aExt, V3 *q, V3 *bAxis, float bExt, V3 *n, float len, float gap, Box *a0, Box *a1);
    void FUN_00318de0(Box *a0, Box *a1);
};

struct Frame {
    int k;
    float t14;
    V3 n;
    float *aExtPtr;
    float *bAxisPtr;
    float *aAxisPtr;
    Collider *self;
    float inv;
    float t38;
    int j;
    float t40;
    float *bExtPtr;
    float absPd;
    int i;
    float pd;
    float t54;
    float absPa;
    float absPb;
    float pa[4];
    float pb[4];
    float gap[4];
    V3 q[4];
    int order[4];
    V3 p[4];
};

#define BITS(x) (*(unsigned int *)&(x))
#define FL(x) (*(float *)&(x))

void Collider::FUN_00318de0(Box *a0, Box *a1)
{
    Frame f;

    V3 *posA = a0->v4();
    V3 *posB = a1->v4();
    f.self = this;
    f.self->d.x = posB->x - posA->x;
    f.self->d.y = posB->y - posA->y;
    f.self->d.z = posB->z - posA->z;

    for (f.i = 0; f.i < 3; f.i++) {
        for (f.j = 0; f.j < 3; f.j++) {
            V3 *ax = &a0->axes[f.i];
            V3 *bx = &a1->axes[f.j];
            double cx = ax->y * bx->z - ax->z * bx->y;
            double cy = ax->z * bx->x - ax->x * bx->z;
            f.n.z = bx->y * ax->x - ax->y * bx->x;
            double p = a1->ext[f.j] * a0->ext[f.i];
            f.t14 = (float)p;
            f.n.x = (float)(p * cx);
            f.n.y = (float)(cy * f.t14);
            double nzx = f.n.z * f.t14;
            f.n.z = (float)nzx;
            double l = nzx * f.n.z;
            l = l + f.n.y * f.n.y;
            l = l + f.n.x * f.n.x;
            f.t14 = (float)l;
            if (!(l > 1.0e-6f))
                continue;
            double proj = f.n.z * f.self->d.z;
            proj = proj + f.n.y * f.self->d.y;
            proj = proj + f.n.x * f.self->d.x;
            f.t40 = (float)proj;
            BITS(f.t40) &= 0x7fffffff;
            if (!(f.t40 > 1.0e-6f))
                continue;
            volatile float *vt = &f.t14;
            *vt = (float)sqrt((double)f.t14);
            double invx = 1.0f / *vt;
            f.inv = (float)invx;
            f.pd = (float)(invx * proj);

            int idx = 0;
            for (f.k = 0; f.k < 2; f.k++) {
                for (int m = 0; m < 2; m++) {
                    a0->FUN_002fb990(&f.p[idx], f.i, f.k);
                    a1->FUN_002fb990(&f.q[idx], f.j, m);
                    double pa = (f.n.z * f.p[idx].z + f.n.y * f.p[idx].y + f.n.x * f.p[idx].x) * f.inv;
                    f.pa[idx] = (float)pa;
                    double pb = (f.n.z * f.q[idx].z + f.n.y * f.q[idx].y + f.n.x * f.q[idx].x) * f.inv;
                    f.pb[idx] = (float)pb;
                    BITS(f.absPd) = BITS(f.pd) & 0x7fffffff;
                    f.t54 = (float)pa;
                    f.t38 = (float)pb;
                    BITS(f.t54) &= 0x7fffffff;
                    BITS(f.t38) &= 0x7fffffff;
                    f.gap[idx] = (float)(f.absPd - (f.t38 + f.t54));
                    idx++;
                }
            }

            f.self->FUN_00313650(f.order, f.gap);
            for (int e = 3; e >= 0; e--) {
                int c = f.order[e];
                BITS(f.k) = BITS(f.pb[c]);
                BITS(f.absPb) = BITS(f.k) & 0x7fffffff;
                BITS(f.k) = BITS(f.pa[c]);
                BITS(f.absPa) = BITS(f.k) & 0x7fffffff;
                double mm;
                if (f.absPa < f.absPb)
                    mm = f.absPa;
                else
                    mm = f.absPb;
                BITS(f.k) = BITS(f.pa[c]) & 0x7fffffff;
                if (!(FL(f.k) > 1.0e-6f))
                    continue;
                BITS(f.k) = BITS(f.pb[c]) & 0x7fffffff;
                if (!(FL(f.k) > 1.0e-6f))
                    continue;
                if (!(f.gap[c] < f.self->thr))
                    continue;
                if (!(-mm < f.gap[c]))
                    continue;
                if (f.pd * f.pa[c] < 0.0f) {
                    f.p[c].x = f.p[c].x * -1.0f;
                    f.p[c].y = f.p[c].y * -1.0f;
                    f.p[c].z = f.p[c].z * -1.0f;
                }
                if (-(f.pd * f.pb[c]) < 0.0f) {
                    f.q[c].x = f.q[c].x * -1.0f;
                    f.q[c].y = f.q[c].y * -1.0f;
                    f.q[c].z = f.q[c].z * -1.0f;
                }
                f.self->FUN_00315620(&f.p[c], &a0->axes[f.i], a0->ext[f.i], &f.q[c], &a1->axes[f.j], a1->ext[f.j], &f.n, f.t14, f.gap[c], a0, a1);
                if (f.self->count > 3)
                    break;
            }
        }
    }
}
} // namespace fn_00318de0
#undef BITS
#undef FL


// 0x00319270 FUN_00319270 (195 B): equivalent/0x00319270.cpp [wrapped: conflict: Object]
// sym: ?target@Solver_319270@fn_00319270@@QAEXPAUObject@2@PAUInput_319270@2@@Z @561a2e307fab @w78ae48ff0818
namespace fn_00319270 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00319270 @ 0x00319270
struct Vec3_319270 { float x,y,z; };
struct Input_319270 { char pad[0x44]; Vec3_319270 axis; };
struct Object { char pad[0x48]; float scale[3]; Vec3_319270 axes[3]; void FUN_002fb990(Vec3_319270* out,int axis,int side); };
struct Solver_319270 { char pad[0x14]; Vec3_319270 direction; void FUN_00316410(Object*,Vec3_319270*,Vec3_319270*,float,Input_319270*,float,float,int); void target(Object*,Input_319270*); };
void Solver_319270::target(Object* obj,Input_319270* input) {
 float projection = (input->axis.z * direction.z + input->axis.y * direction.y) + input->axis.x * direction.x;
 Vec3_319270 point;
 for(int i=0;i<3;++i) {
  float component = ((obj->axes[i].z * input->axis.z + obj->axes[i].y * input->axis.y) + input->axis.x * obj->axes[i].x) * obj->scale[i];
  for(int j=0;j<2;++j) {
   obj->FUN_002fb990(&point,i,j);
   FUN_00316410(obj,&point,&obj->axes[i],obj->scale[i],input,projection,component,0);
  }
 }
}
} // namespace fn_00319270

namespace fn_fc854b07 {

// 0x00319560 FUN_00319560 (23 B): matches/0x00319560.cpp
// sym: ??0SimpleFilter1D@fn_fc854b07@@QAE@XZ
SimpleFilter1D::SimpleFilter1D() : a(0), b(0), c(0), d(0) {}

} // namespace fn_fc854b07
