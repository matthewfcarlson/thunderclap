// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00357740..0x0035a640 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc83e8cf {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc83e8cf {} using namespace fn_fc83e8cf;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fc83e8cf {
struct V {
  public:
    float x;
    float y;
    float z;
};
struct T_357740 {
    V a;
    int f[9];
    V b;
    T_357740* Set(const V* pa, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11,
           const V* pb);
};
struct Vec3_3577c0 {
    float x, y, z;
};
struct Vec3_357960 {
    float x, y, z;
};
bool __cdecl FUN_0022de70(const Vec3_357960* point, const Vec3_357960* direction, const Vec3_357960* planePoint, const Vec3_357960* normal, Vec3_357960* result, float* parameter);
extern "C" bool __cdecl FUN_003577c0(const void *, const void *, const void *, const void *, const void *);
static inline float dot(V* a, V* b) {
    return a->z * b->z + a->y * b->y + a->x * b->x;
}
struct Vec3_357aa0 {
    float x, y, z;
};
struct Mat4_357aa0 {
    float m[4][4];
};
struct Frame_357aa0 {
    Vec3_357aa0 d;
    Vec3_357aa0 out;
    Mat4_357aa0 mat;
};
struct Vec3_357be0 {
    float x, y, z;
};
struct Frame_357be0 {
    Vec3_357be0 w;
    Vec3_357be0 dir;
};
extern "C" void __cdecl FUN_0022d730(Vec3_357be0 *a, Vec3_357be0 *dirA, float lenA, Vec3_357be0 *b, Vec3_357be0 *dirB, float lenB, int p7, int p8);
struct Vec3_357ea0 { float x, y, z; };
struct Frame_357ea0 {
    float d0, d1, d2;
    Vec3_357ea0 t0, t1, t2;
};
extern "C" void __cdecl FUN_001fd640(void *, void *, void *, void *);
struct V3_358030 {
    float x, y, z;
    void FUN_0022d180();
};
extern "C" char FUN_0022d550(V3_358030 *s, V3_358030 *dir, V3_358030 *a, V3_358030 *b, float *outA, float *outB);
char FUN_00357be0(V3_358030 *s, V3_358030 *dir, V3_358030 *a, V3_358030 *b, float *outA, float *outB);
struct Frame_358030 {
    volatile float inv;
    volatile float rx;
    volatile float qzp;
    volatile float rz;
    float pr[6];      // (ray t, edge t) for each of the three edges
    volatile float t38, t3c, t40;
    V3_358030 dn;
    V3_358030 target;
    float dist[3];
    volatile float qx;
    float rzp;
    volatile float t70;
    float len[3];
    V3_358030 n[3];
};
struct Vec3_358630 {
    float x, y, z;
};
struct Vec3_358700 {
    float x, y, z;
};
union FS_358700 {
    float f;
    unsigned int u;
};
union VecSlot {
    Vec3_358700 *v;
    float f;
};
bool FUN_00358630(Vec3_358700 *a, Vec3_358700 *dir, float radius, float len, int zero, float planeD, Vec3_358700 *n, VecSlot *out);
extern "C" bool __cdecl FUN_00357960(const void *, const void *, float, const void *, const void *, const void *, const void *, float *, void *, void *);
bool FUN_00358030(Vec3_358700 *a, Vec3_358700 *dir, int f1, Vec3_358700 *p5, Vec3_358700 *p6, void *p7, float *s, Vec3_358700 *pt, Vec3_358700 *q, float *w, float *t, int f2, int f3, int f4);
struct Vec3_359260 {
    float x, y, z;
};
static inline float fabsf_(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}
extern "C" void __cdecl FUN_00357ea0(const void *, const void *, const void *, const void *, void *, bool, bool, bool);
struct Vec3_359450 {
    float x, y, z;
};
struct Vec3 {
    float x, y, z;
};
extern void __cdecl FUN_003579f0(const Vec3* axis, const Vec3* const* tri, float* mn, float* mx);
extern "C" void __cdecl FUN_00359450(const void *, const void *, const void *, const void *, const void *, const void *, float *, float *);
struct Vec3_359860 {
    float x, y, z;
};
struct Matrix {
    float m[16];
};
struct Vec3_35a190 {
    float x, y, z;
};
struct Box_35a190 {
    Vec3_35a190 center;
    Vec3_35a190 axis[3];
    float extent[3];
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00359a80(const void *, float, int *, void *);
struct Vec3_35a2a0 {
    float x, y, z;
};
struct Hull_35a2a0 {
    char pad0[0x3c];
    void FUN_00357740(Vec3_35a2a0 *p, Vec3_35a2a0 axisX, Vec3_35a2a0 axisY, Vec3_35a2a0 axisZ, Vec3_35a2a0 *q);
};
bool __cdecl FUN_00359510(Vec3_35a2a0 *a1, Vec3_35a2a0 *a2, Vec3_35a2a0 *a3, Vec3_35a2a0 *a4, Vec3_35a2a0 *a5, Vec3_35a2a0 *a6, Vec3_35a2a0 *a7, Vec3_35a2a0 *a8, Vec3_35a2a0 *a9, int f0, int f1, int f2);
void __cdecl FUN_0035a190(Hull_35a2a0 *hull, Vec3_35a2a0 *a6, Vec3_35a2a0 *a7, Vec3_35a2a0 *a8, int *count, Vec3_35a2a0 *out);
float __cdecl FUN_00359860(Vec3_35a2a0 *a1, Vec3_35a2a0 *a2, Vec3_35a2a0 *a3, Vec3_35a2a0 *a4, Vec3_35a2a0 *a5, Vec3_35a2a0 *dir, Vec3_35a2a0 *point);
struct Vec3_35a4c0 {
    float x, y, z;
};
char __cdecl FUN_0035a2a0(Vec3_35a4c0 *a1, Vec3_35a4c0 *a2, Vec3_35a4c0 *axisX, Vec3_35a4c0 *axisY, Vec3_35a4c0 *axisZ, Vec3_35a4c0 *v0, Vec3_35a4c0 *v1, Vec3_35a4c0 *v2,
                          Vec3_35a4c0 *normal, float *depth, Vec3_35a4c0 *centre, Vec3_35a4c0 *outN, int f1, int f2, int f4);
int __cdecl FUN_00209f50();
extern "C" void FUN_0035a6c0(int);


// 0x00357740 FUN_00357740 (115 B): matches/0x00357740.cpp
// sym: ?Set@T_357740@fn_fc83e8cf@@QAEPAU12@PBUV@2@HHHHHHHHH0@Z
T_357740* T_357740::Set(const V* pa, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11,
          const V* pb) {
    a = *pa;
    b = *pb;
    f[0] = p3;
    f[1] = p4;
    f[2] = p5;
    f[3] = p6;
    f[4] = p7;
    f[5] = p8;
    f[6] = p9;
    f[7] = p10;
    f[8] = p11;
    return this;
}


// 0x003577c0 FUN_003577c0 (415 B): equivalent/0x003577c0.cpp
// sym: _FUN_003577c0 @6ed628b204fc @w5dbbd1578af7
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 12/12)
// FUN_003577c0 @ 0x003577c0
// Is p inside the triangle v1 v2 v3 (all on the plane with normal n)?
// x87: the edges, cz and the two dot products stay in registers (53 bits); cx and cy go through the frame
extern "C" bool FUN_003577c0(const void * p_, const void * v1_, const void * v2_, const void * v3_, const void * n_)
{
    const Vec3_3577c0 * p = (const Vec3_3577c0 *)p_;
    const Vec3_3577c0 * v1 = (const Vec3_3577c0 *)v1_;
    const Vec3_3577c0 * v2 = (const Vec3_3577c0 *)v2_;
    const Vec3_3577c0 * v3 = (const Vec3_3577c0 *)v3_;
    const Vec3_3577c0 * n = (const Vec3_3577c0 *)n_;
    struct Frame {
        float cx, cy;
        float spare;
    } fr;
    int outside = 0;

    hulk_freg ex = v2->x - v1->x;
    hulk_freg ey = v2->y - v1->y;
    hulk_freg ez = v2->z - v1->z;
    fr.cx = ey * n->z - ez * n->y;
    fr.cy = ez * n->x - ex * n->z;
    hulk_freg cz = ex * n->y - ey * n->x;
    hulk_freg a = cz * p->z;
    a += fr.cx * p->x;
    a += fr.cy * p->y;
    hulk_freg b = fr.cx * v1->x;
    b += fr.cy * v1->y;
    b += cz * v1->z;
    if (a - b > 0.0f)
        outside = 1;

    hulk_freg fx = v3->x - v2->x;
    hulk_freg fy = v3->y - v2->y;
    hulk_freg fz = v3->z - v2->z;
    fr.cx = fy * n->z - fz * n->y;
    fr.cy = fz * n->x - fx * n->z;
    cz = fx * n->y - fy * n->x;
    a = cz * p->z;
    a += fr.cx * p->x;
    a += fr.cy * p->y;
    b = fr.cy * v2->y;
    b += fr.cx * v2->x;
    b += cz * v2->z;
    if (a - b > 0.0f)
        outside++;
    if (outside == 1)
        return false;

    hulk_freg gx = v1->x - v3->x;
    hulk_freg gy = v1->y - v3->y;
    hulk_freg gz = v1->z - v3->z;
    fr.cx = gy * n->z - gz * n->y;
    fr.cy = gz * n->x - gx * n->z;
    cz = gx * n->y - gy * n->x;
    a = cz * p->z;
    a += fr.cx * p->x;
    a += fr.cy * p->y;
    b = cz * v3->z;
    b += fr.cy * v3->y;
    b += fr.cx * v3->x;
    if (a - b > 0.0f)
        outside++;
    return outside == 0 || outside == 3;
}


// 0x00357960 FUN_00357960 (129 B): equivalent/0x00357960.cpp
// sym: _FUN_00357960 @ee98575d3ee9 @wd2f45368fc93
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00357960 @ 0x00357960
extern "C" bool FUN_00357960(const void * origin, const void * dir, float reach, const void * p5, const void * p6, const void * p7, const void * n, float* dist, void * hit, void * outN_)
{
    Vec3_357960 * outN = (Vec3_357960 *)outN_;
    if (!FUN_0022de70(((const Vec3_357960 *)origin), ((const Vec3_357960 *)dir), ((const Vec3_357960 *)p5), ((const Vec3_357960 *)n), ((Vec3_357960 *)hit), dist)) {
        return false;
    }
    if (*dist < 0.0f) {
        return false;
    }
    if (reach < *dist) {
        return false;
    }
    *outN = *((const Vec3_357960 *)n);
    return FUN_003577c0((const Vec3_357960 *)((Vec3_357960 *)hit), (const Vec3_357960 *)((const Vec3_357960 *)p5), (const Vec3_357960 *)((const Vec3_357960 *)p6), (const Vec3_357960 *)((const Vec3_357960 *)p7), (const Vec3_357960 *)((const Vec3_357960 *)n));
}


// 0x003579f0 FUN_003579f0 (161 B): matches/0x003579f0.cpp
// sym: ?Proj@fn_fc83e8cf@@YAXPAUV@1@PAPAU21@PAM2@Z
void Proj(V* d, V** t, float* mn, float* mx) {
    V* a = t[0];
    float v0 = a->z * d->z + a->y * d->y + a->x * d->x;
    *mn = v0;
    *mx = v0;
    float v1 = dot(d, t[1]);
    if (v1 < *mn)
        *mn = v1;
    else if (v1 > *mx)
        *mx = v1;
    hulk_freg v2 = dot(d, t[2]);
    if (v2 < *mn)
        *mn = v2;
    else if (v2 > *mx)
        *mx = v2;
}


// 0x00357aa0 FUN_00357aa0 (316 B): equivalent/0x00357aa0.cpp
// sym: ?FUN_00357aa0@fn_fc83e8cf@@YA_NPAUVec3_357aa0@1@00000@Z @3adb10cd99b4 @w2477305d344d
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00357aa0 @ 0x00357aa0
// Is point `pt` (relative to `origin`), expressed in the basis (ax, ay, az), inside the box `half`?
bool FUN_00357aa0(Vec3_357aa0 *origin, Vec3_357aa0 *half, Vec3_357aa0 *ax, Vec3_357aa0 *ay, Vec3_357aa0 *az, Vec3_357aa0 *pt)
{
    Frame_357aa0 f;
    f.d.x = pt->x - origin->x;
    f.d.y = pt->y - origin->y;
    f.d.z = pt->z - origin->z;

    f.mat.m[0][0] = ax->x;
    f.mat.m[0][1] = ay->x;
    f.mat.m[0][2] = az->x;
    f.mat.m[0][3] = 0;
    f.mat.m[1][0] = ax->y;
    f.mat.m[1][1] = ay->y;
    f.mat.m[1][2] = az->y;
    f.mat.m[1][3] = 0;
    f.mat.m[2][0] = ax->z;
    f.mat.m[2][1] = ay->z;
    f.mat.m[2][2] = az->z;
    f.mat.m[2][3] = 0;
    f.mat.m[3][0] = 0;
    f.mat.m[3][1] = 0;
    f.mat.m[3][2] = 0;
    f.mat.m[3][3] = 1.0f;

    ((owners::Mat_22c2b0 *)&(f.mat))->FUN_0022c2b0((float *)(Vec3_357aa0 *)(&f.d), (float *)(Vec3_357aa0 *)(&f.out));

    if (-half->x > f.out.x) return false;
    if (half->x < f.out.x) return false;
    if (-half->y > f.out.y) return false;
    if (half->y < f.out.y) return false;
    if (-half->z > f.out.z) return false;
    if (half->z < f.out.z) return false;
    return true;
}


// 0x00357be0 FUN_00357be0 (253 B): equivalent/0x00357be0.cpp
// sym: ?FUN_00357be0@fn_fc83e8cf@@YAXPAUVec3_357be0@1@000HH@Z @21a80df316e7 @wee8a440e217c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00357be0 @ 0x00357be0
// Builds the unit direction and length of the segments p0->p1 and p2->p3 and forwards them.
// dx and dy stay unrounded on the FPU, everything the original stores is read back from memory.
void FUN_00357be0(Vec3_357be0 *p0, Vec3_357be0 *p1, Vec3_357be0 *p2, Vec3_357be0 *p3, int arg5, int arg6)
{
    Frame_357be0 frame;
    volatile Frame_357be0 *fr = &frame;
    double dx = p1->x - p0->x;
    double dy = p1->y - p0->y;
    fr->dir.z = p1->z - p0->z;
    fr->w.x = p3->x - p2->x;
    fr->w.y = p3->y - p2->y;
    fr->w.z = p3->z - p2->z;
    volatile float lenA = (float)sqrt(fr->dir.z * fr->dir.z + dy * dy + dx * dx);
    volatile float lenB = (float)sqrt(fr->w.z * fr->w.z + fr->w.y * fr->w.y + fr->w.x * fr->w.x);
    volatile float invA = 1.0f / lenA;
    fr->dir.x = (float)(dx * invA);
    fr->dir.y = (float)(dy * invA);
    fr->dir.z = fr->dir.z * invA;
    double invB = 1.0f / lenB;
    fr->w.x = (float)(fr->w.x * invB);
    fr->w.y = (float)(fr->w.y * invB);
    fr->w.z = (float)(fr->w.z * invB);
    FUN_0022d730(p0, &frame.dir, lenA, p2, &frame.w, lenB, arg5, arg6);
}

} // namespace fn_fc83e8cf

// 0x00357ce0 FUN_00357ce0 (440 B): equivalent/0x00357ce0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00357ce0@fn_00357ce0@@YAXPBUVec3_357ce0@1@000PAU21@1_N22@Z @988feef79061 @w3264d3100409
namespace fn_00357ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00357ce0 @ 0x00357ce0
struct Vec3_357ce0 {
    float x, y, z;
};

extern "C" void __cdecl FUN_001fd640(void *, void *, void *, void *);

static const float FLT_MAX_ = 3.4028235e+38f;

static float DistSq(const Vec3_357ce0 &q, const Vec3_357ce0 *p)
{
    float dx = q.x - p->x;
    float dy = q.y - p->y;
    float dz = q.z - p->z;
    return dz * dz + dy * dy + dx * dx;
}

void FUN_00357ce0(const Vec3_357ce0 *p, const Vec3_357ce0 *a, const Vec3_357ce0 *b, const Vec3_357ce0 *c,
                  Vec3_357ce0 *outFrom, Vec3_357ce0 *outTo, bool testAB, bool testBC, bool testCA)
{
    struct Frame {
        float dist0;
        float pad;
        float dist1;
        Vec3_357ce0 qAB;
        Vec3_357ce0 qBC;
        Vec3_357ce0 qCA;
    } f;
    f.dist0 = FLT_MAX_;
    f.dist1 = FLT_MAX_;
    if (testAB) {
        FUN_001fd640((void *)(const Vec3_357ce0 *)p, (void *)(const Vec3_357ce0 *)a, (void *)(const Vec3_357ce0 *)b, (Vec3_357ce0 *)(&f.qAB));
        f.dist0 = DistSq(f.qAB, p);
    }
    if (testBC) {
        FUN_001fd640((void *)(const Vec3_357ce0 *)p, (void *)(const Vec3_357ce0 *)b, (void *)(const Vec3_357ce0 *)c, (Vec3_357ce0 *)(&f.qBC));
        // the original measures qAB here (a stale buffer, even when testAB was false), not qBC
        f.dist0 = DistSq(f.qAB, p);
    }
    if (testCA) {
        FUN_001fd640((void *)(const Vec3_357ce0 *)p, (void *)(const Vec3_357ce0 *)c, (void *)(const Vec3_357ce0 *)a, (Vec3_357ce0 *)(&f.qCA));
        f.dist1 = DistSq(f.qCA, p);
    }
    if (f.dist0 <= FLT_MAX_ && f.dist0 <= f.dist1) {
        *outFrom = *a;
        *outTo = *b;
    } else if (FLT_MAX_ <= f.dist1) {
        *outFrom = *b;
        *outTo = *c;
    } else {
        *outFrom = *c;
        *outTo = *a;
    }
}
} // namespace fn_00357ce0

namespace fn_fc83e8cf {

// 0x00357ea0 FUN_00357ea0 (389 B): equivalent/0x00357ea0.cpp
// sym: _FUN_00357ea0 @2f216db5eba0 @wa932b4b10753
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00357ea0 @ 0x00357ea0
extern "C" void FUN_00357ea0(const void *p, const void *a, const void *b, const void *c, void * out_,
                  bool testAB, bool testBC, bool testCA)
{
    Vec3_357ea0 * out = (Vec3_357ea0 *)out_;
    Frame_357ea0 f;
    f.d0 = 3.4028235e38f;
    f.d1 = 3.4028235e38f;
    f.d2 = 3.4028235e38f;
    if (testAB) {
        FUN_001fd640((void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)p), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)a), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)b), (Vec3_357ea0 *)(&f.t0));
        float dx = f.t0.x - ((const Vec3_357ea0 *)p)->x;
        float dy = f.t0.y - ((const Vec3_357ea0 *)p)->y;
        float dz = f.t0.z - ((const Vec3_357ea0 *)p)->z;
        f.d0 = dz * dz + dy * dy + dx * dx;
    }
    if (testBC) {
        FUN_001fd640((void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)p), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)b), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)c), (Vec3_357ea0 *)(&f.t1));
        float dx = f.t1.x - ((const Vec3_357ea0 *)p)->x;
        float dy = f.t1.y - ((const Vec3_357ea0 *)p)->y;
        float dz = f.t1.z - ((const Vec3_357ea0 *)p)->z;
        f.d1 = dz * dz + dy * dy + dx * dx;
    }
    if (testCA) {
        FUN_001fd640((void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)p), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)c), (void *)(const Vec3_357ea0 *)((const Vec3_357ea0 *)a), (Vec3_357ea0 *)(&f.t2));
        float dx = f.t2.x - ((const Vec3_357ea0 *)p)->x;
        float dy = f.t2.y - ((const Vec3_357ea0 *)p)->y;
        float dz = f.t2.z - ((const Vec3_357ea0 *)p)->z;
        f.d2 = dz * dz + dy * dy + dx * dx;
    }
    if (f.d0 <= f.d1 && f.d0 <= f.d2) {
        *out = f.t0;
    } else if (f.d1 <= f.d2) {
        *out = f.t1;
    } else {
        *out = f.t2;
    }
}


// 0x00358030 FUN_00358030 (1532 B): equivalent/0x00358030.cpp
// sym: ?FUN_00358030@fn_fc83e8cf@@YAXPAUV3_358030@1@0D000PAM0011DDD@Z @cbe6a3671890 @wc0f21bee3e4c
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 18/18)
// FUN_00358030 @ 0x00358030
// Closest approach of a ray (S, D) to the three edges of a triangle; reports the nearest edge.
void FUN_00358030(V3_358030 *S, V3_358030 *D, char useSegment, V3_358030 *P1, V3_358030 *P0, V3_358030 *P2,
                  float *outRay, V3_358030 *outPoint, V3_358030 *outDir, float *outLen, float *outEdgeT,
                  char doEdge0, char doEdge1, char doEdge2)
{
    Frame_358030 f;
    f.dn = *D;
    f.target.x = S->x + D->x;
    f.target.y = S->y + D->y;
    f.target.z = S->z + D->z;
    f.dn.FUN_0022d180();
    for (int i = 0; i < 6; i++)
        f.pr[i] = 3.4028235e38f;
    f.dist[0] = 3.4028235e38f;
    f.dist[1] = 3.4028235e38f;
    f.dist[2] = 3.4028235e38f;

    if (doEdge0) {
        hulk_freg dx = P1->x - P0->x;
        hulk_freg dy = P1->y - P0->y;
        f.t40 = P1->z - P0->z;
        f.len[0] = (float)sqrt(dx * dx + f.t40 * f.t40 + dy * dy);
        f.inv = DAT_003f32dc / f.len[0];
        f.n[0].x = dx * f.inv;
        f.n[0].y = dy * f.inv;
        f.n[0].z = f.t40 * f.inv;
        if (useSegment)
            FUN_00357be0(S, &f.target, P0, P1, &f.pr[0], &f.pr[1]);
        else
            FUN_0022d550(S, &f.dn, P0, P1, &f.pr[0], &f.pr[1]);
        f.qzp = f.n[0].z * f.pr[1];
        f.qx = f.n[0].x * f.pr[1] + P0->x;
        f.t40 = f.dn.z * f.pr[0];
        f.rx = f.dn.x * f.pr[0] + S->x;
        f.rz = f.t40 + S->z;
        f.t38 = f.rx - f.qx;
        f.t3c = (f.dn.y * f.pr[0] + S->y) - (f.n[0].y * f.pr[1] + P0->y);
        double dz = f.rz - (f.qzp + P0->z);
        double sq = f.t38 * f.t38;      // (summed in the original's order: x, z, y)
        sq += dz * dz;
        sq += f.t3c * f.t3c;
        f.dist[0] = (float)sqrt(sq);
    }
    if (doEdge1) {
        hulk_freg dx = P0->x - P2->x;
        hulk_freg dy = P0->y - P2->y;
        f.rz = P0->z - P2->z;
        f.len[1] = (float)sqrt(dx * dx + f.rz * f.rz + dy * dy);
        f.inv = DAT_003f32dc / f.len[1];
        f.n[1].x = dx * f.inv;
        f.n[1].y = dy * f.inv;
        f.n[1].z = f.rz * f.inv;
        if (useSegment)
            FUN_00357be0(S, &f.target, P2, P0, &f.pr[2], &f.pr[3]);
        else
            FUN_0022d550(S, &f.dn, P2, P0, &f.pr[2], &f.pr[3]);
        f.qzp = f.n[1].z * f.pr[3];
        f.qx = f.n[1].x * f.pr[3] + P2->x;
        f.t70 = f.dn.z * f.pr[2];
        f.rx = f.dn.x * f.pr[2] + S->x;
        f.rz = f.t70 + S->z;
        f.t38 = f.rx - f.qx;
        f.t3c = (f.dn.y * f.pr[2] + S->y) - (f.n[1].y * f.pr[3] + P2->y);
        double dz = f.rz - (f.qzp + P2->z);
        double sq = f.t38 * f.t38;      // (summed in the original's order: x, z, y)
        sq += dz * dz;
        sq += f.t3c * f.t3c;
        f.dist[1] = (float)sqrt(sq);
    }
    if (doEdge2) {
        hulk_freg dx = P2->x - P1->x;
        hulk_freg dy = P2->y - P1->y;
        f.rz = P2->z - P1->z;
        f.len[2] = (float)sqrt(dx * dx + f.rz * f.rz + dy * dy);
        f.inv = DAT_003f32dc / f.len[2];
        f.n[2].x = dx * f.inv;
        f.n[2].y = dy * f.inv;
        f.n[2].z = f.rz * f.inv;
        if (useSegment)
            FUN_00357be0(S, &f.target, P1, P2, &f.pr[4], &f.pr[5]);
        else
            FUN_0022d550(S, &f.dn, P1, P2, &f.pr[4], &f.pr[5]);
        f.qzp = f.n[2].z * f.pr[5];
        f.qx = f.n[2].x * f.pr[5] + P1->x;
        f.t70 = f.dn.z * f.pr[4];
        f.rx = f.dn.x * f.pr[4] + S->x;
        f.rz = f.t70 + S->z;
        f.t38 = f.rx - f.qx;
        f.t3c = (f.dn.y * f.pr[4] + S->y) - (f.n[2].y * f.pr[5] + P1->y);
        double dz = f.rz - (f.qzp + P1->z);
        double sq = dz * dz;            // (summed in the original's order: z, y, x)
        sq += f.t3c * f.t3c;
        sq += f.t38 * f.t38;
        f.dist[2] = (float)sqrt(sq);
    }
    if (f.dist[0] <= f.dist[1] && f.dist[0] <= f.dist[2]) {
        *outRay = f.pr[0];
        *outEdgeT = f.pr[1];
        *outPoint = *P0;
        *outDir = f.n[0];
        *outLen = f.len[0];
    } else if (f.dist[1] <= f.dist[2]) {
        *outRay = f.pr[2];
        *outEdgeT = f.pr[3];
        *outPoint = *P2;
        *outDir = f.n[1];
        *outLen = f.len[1];
    } else {
        *outRay = f.pr[4];
        *outEdgeT = f.pr[5];
        *outPoint = *P1;
        *outDir = f.n[2];
        *outLen = f.len[2];
    }
}


// 0x00358630 FUN_00358630 (195 B): equivalent/0x00358630.cpp
// sym: ?FUN_00358630@fn_fc83e8cf@@YA_NPBUVec3_358630@1@0MMDM0PAM@Z @642a6b2812dd @w2678f3933c34
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 4/4)
// FUN_00358630 @ 0x00358630
// Interval test along a direction: writes (centre - radius) to *out and returns whether |centre| <= radius.
bool __cdecl FUN_00358630(const Vec3_358630 *a, const Vec3_358630 *b, float k1, float k2, char flag, float offset,
                          const Vec3_358630 *dir, float *out)
{
    // x87: the centre, the root and the radius stay in registers (53 bits); |t| and q go through the frame
    hulk_freg centre = (hulk_freg)a->z * dir->z + (hulk_freg)a->y * dir->y + (hulk_freg)dir->x * a->x + offset;

    AbsFloat t;
    t.f = b->z * dir->z + b->y * dir->y + b->x * dir->x;
    t.bits &= 0x7fffffff;

    AbsFloat q;
    q.f = 1.0f - t.f * t.f;
    q.bits &= 0x7fffffff;

    hulk_freg radius;
    if (flag)
        radius = (hulk_freg)sqrt(q.f) * k1 + (hulk_freg)t.f * k2;
    else
        radius = (hulk_freg)t.f * k2 + k1;

    *out = (float)(centre - radius);

    AbsFloat c;
    c.f = (float)centre;
    c.bits &= 0x7fffffff;
    return c.f <= radius;
}


// 0x00358700 FUN_00358700 (1026 B): equivalent/0x00358700.cpp
// sym: ?FUN_00358700@fn_fc83e8cf@@YA_NPAUVec3_358700@1@0MMTVecSlot@1@0PAX1PAM00@Z @70e5d67fb5d3 @w2d2486a54e07
// STATUS: equivalent (tools/equiv.py level 3: 19971 inputs, branch coverage 14/14)
// FUN_00358700 @ 0x00358700
// Swept sphere (segment start a, direction dir, half length len, radius) against a triangle plane.
bool FUN_00358700(Vec3_358700 *a, Vec3_358700 *dir, float radius, float len, VecSlot p5, Vec3_358700 *p6, void *p7, VecSlot n8,
                  float *dist, Vec3_358700 *hit, Vec3_358700 *outN)
{
    struct Frame {
        FS_358700 ad;          // 0x00
        float w;        // 0x04
        Vec3_358700 lo;        // 0x08
        Vec3_358700 hi;        // 0x14
        Vec3_358700 v;         // 0x20
        Vec3_358700 pt;        // 0x2c
        float spare[3]; // 0x38
    } f;
    Vec3_358700 *n = n8.v;
    if (!FUN_00358630(a, dir, radius, len, 0, -(p5.v->z * n->z + p5.v->y * n->y + n->x * p5.v->x), n, &n8))
        return false;

    f.pt.x = len * dir->x;
    f.ad.f = len * dir->z;
    f.lo.x = a->x - f.pt.x;
    f.lo.y = a->y - len * dir->y;
    f.lo.z = a->z - len * dir->z;
    f.hi.x = f.pt.x + a->x;
    f.hi.y = len * dir->y + a->y;
    f.hi.z = f.ad.f + a->z;

    hulk_freg d = ((f.lo.z - p6->z) * n->z + (f.lo.y - p6->y) * n->y) + (f.lo.x - p6->x) * n->x;
    *dist = d;
    f.ad.f = d;
    f.ad.u &= 0x7fffffff;
    if (f.ad.f < radius) {
        f.v.x = d * n->x;
        f.v.y = d * n->y;
        f.pt.z = f.lo.z - d * n->z;
        hit->z = f.pt.z;
        hit->x = f.lo.x - f.v.x;
        hit->y = f.lo.y - f.v.y;
        if (FUN_003577c0((Vec3_358700 *)hit, (Vec3_358700 *)(p5.v), (Vec3_358700 *)p6, p7, (Vec3_358700 *)n)) {
            *dist = n8.f;
            *outN = *n;
            return true;
        }
    }

    d = ((f.hi.z - p6->z) * n->z + (f.hi.y - p6->y) * n->y) + (f.hi.x - p6->x) * n->x;
    *dist = d;
    f.ad.f = d;
    f.ad.u &= 0x7fffffff;
    if (f.ad.f < radius) {
        f.v.x = d * n->x;
        f.v.y = d * n->y;
        f.pt.z = f.hi.z - d * n->z;
        hit->z = f.pt.z;
        hit->x = f.hi.x - f.v.x;
        hit->y = f.hi.y - f.v.y;
        if (FUN_003577c0((Vec3_358700 *)hit, (Vec3_358700 *)(p5.v), (Vec3_358700 *)p6, p7, (Vec3_358700 *)n)) {
            *dist = n8.f;
            *outN = *n;
            return true;
        }
    }

    if (FUN_00357960((Vec3_358700 *)(&f.lo), (Vec3_358700 *)dir, len + len + radius, (Vec3_358700 *)(p5.v), (Vec3_358700 *)p6, p7, (Vec3_358700 *)n, dist, (Vec3_358700 *)hit, (Vec3_358700 *)outN)) {
        *dist = n8.f;
        return true;
    }

    f.v.x = f.hi.x - f.lo.x;
    f.v.y = f.hi.y - f.lo.y;
    f.v.z = f.hi.z - f.lo.z;
    FUN_00358030(&f.lo, &f.v, 1, p5.v, p6, p7, &p5.f, &f.pt, &f.hi, &f.w, &f.ad.f, 1, 1, 1);
    // `x`, `z` and the sums below are stored to float temporaries by the original where noted; the rest stays on the FPU stack
    double pdx = p5.f * dir->x;
    double pdy = p5.f * dir->y;
    volatile float sz = p5.f * dir->z;
    volatile float x1 = pdx + f.lo.x;
    volatile float qz = f.hi.z * f.ad.f;
    volatile float px = f.pt.x + f.hi.x * f.ad.f;
    hit->x = px;
    volatile float pz = f.pt.z + qz;
    hit->y = f.pt.y + f.hi.y * f.ad.f;
    hit->z = pz;
    volatile float dx = x1 - px;
    volatile float dy = (pdy + f.lo.y) - (*(volatile float *)&f.pt.y + *(volatile float *)&f.hi.y * *(volatile float *)&f.ad.f);
    double dz = ((double)sz + (double)f.lo.z) - (double)pz;
    double ddy = dy;
    double ddx = dx;
    double r = sqrt((dz * dz + ddy * ddy) + ddx * ddx) - radius;
    *dist = (float)r;
    if (!(r < 0.0))
        return false;
    *dist = n8.f;
    *outN = *n;
    return true;
}

} // namespace fn_fc83e8cf

// 0x00358b10 FUN_00358b10 (1869 B): equivalent/0x00358b10.cpp [wrapped: macros; helper definitions (4 out-of-line function bodies)]
// sym: _FUN_00358b10 @26ce70b647be @w1fe342eb2f60
namespace fn_00358b10 {
// STATUS: equivalent (tools/equiv.py level 3: 3286 inputs, branch coverage 20/20)
// FUN_00358b10 @ 0x00358b10
// FUN_00358b10: sweep a capsule (centre c, unit axis `axis`, half length halfLen, radius) against one
// polygon plane (point planePt, normal n; a6/a7 select the polygon) and report the contact:
// outDist (distance), outPoint (point on the plane) and outNormal (a copy of n). 11 stack args, cdecl, bool result.
//
// Floats the original stores to its frame are rounded to 24 bits (hulk_fslot); values it combines on the
// x87 stack stay unrounded (double locals and inline expressions). The result vectors are copied as raw
// 32-bit words, as the original does, so NaN payloads survive.

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


#if defined(_MSC_VER) && !defined(__clang__)
typedef volatile float hulk_fslot; // forces the store-and-reload MSVC 7.1 would otherwise skip
#else
typedef float hulk_fslot;
#endif

struct V3_358b10 {
    float x, y, z;
    void FUN_000111b0(const V3_358b10 *a, const V3_358b10 *b); // this = a x b
    void FUN_0022d180();                                       // normalise
    hulk_freg FUN_00018990();                                      // length
};

bool FUN_00358630(float *p, float *dir, float r, float t, int flag, float d, float *n, float *out);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00357960(const void *, const void *, float, const void *, const void *, const void *, const void *, float *, void *, void *);
void FUN_00358030(float *a, float *dir, int flag, float *p5, int a6, int a7, float *o8c, float *o20, float *o44, float *o4, float *o64, int f1, int f2, int f3);
void FUN_0022de70(float *a, float *b, float *p5, float *p8, float *o50, float *o8);
extern "C++" __declspec(nothrow) bool __cdecl FUN_003577c0(const void *, const void *, const void *, const void *, const void *);
extern "C" float *FUN_00083e00(float *out, float *dir, float t);

static void CopyBits(float *dst, const volatile float *src)
{
    *(unsigned int *)dst = *(const volatile unsigned int *)src;
}

static float AbsBits(float v)
{
    unsigned int bits = *(unsigned int *)&v & 0x7fffffff;
    return *(float *)&bits;
}

static void CopyBits3(float *dst, const float *src)
{
    CopyBits(dst + 0, src + 0);
    CopyBits(dst + 1, src + 1);
    CopyBits(dst + 2, src + 2);
}

// The original's stack frame, in slot order: the callees' out-parameters and the vectors passed to them live
// here, and the checker's stubs write through those pointers, so the layout is part of the behaviour.
// A second copy of p1 sits in q1 until q1 is recomputed.
struct Frame_358b10 {
    hulk_fslot t;          // position along the axis
    hulk_fslot p1[3];
    hulk_fslot q1[3];
    hulk_fslot d[3];       // axis x n, later the normalised chord direction
    hulk_fslot u;          // scale of toAxis
    hulk_fslot planeHit;   // distance the plane test reports
    hulk_fslot start[3];   // c - halfLen * axis
    hulk_fslot contact[3]; // contact point on the plane
    hulk_fslot toAxis[3];  // direction from the polygon point towards the axis; its z is first axis offset z
    hulk_fslot q[3];       // (n x axis) x axis
    hulk_fslot nearEnd[3]; // capsule end nearer to the plane
    hulk_fslot onPoly[3];  // closest point on the polygon
    hulk_fslot tmp[3];     // scratch vector returned by FUN_00083e00
    hulk_fslot side;
    hulk_fslot unusedOut;
};

#define FP(v) ((float *)(v))

extern "C" bool FUN_00358b10(float *c, float *axis, float radius, float halfLen, float *planePt, int a6, int a7,
                  float *n, float *outDist, float *outPoint, float *outNormal)
{
    Frame_358b10 fr;

    // Plane offset: -(n . planePt).
    hulk_fslot planeD = -(((n[2] * planePt[2]) + (n[1] * planePt[1])) + (n[0] * planePt[0]));
    if (!FUN_00358630(c, axis, radius, halfLen, 1, planeD, n, FP(&fr.planeHit)))
        return false;

    // The capsule's far end: start = c - halfLen * axis.
    fr.toAxis[2] = halfLen * axis[2];
    fr.start[0] = c[0] - (halfLen * axis[0]);
    fr.start[1] = c[1] - (halfLen * axis[1]);
    fr.start[2] = c[2] - fr.toAxis[2];
    hulk_fslot fullLen = halfLen + halfLen;

    if (FUN_00357960((float *)(FP(fr.start)), (float *)axis, fullLen, (float *)planePt, (const void *)(hulk_uintptr)(int)a6, (const void *)(hulk_uintptr)(int)a7, (float *)n, outDist, (float *)outPoint, (float *)outNormal)) {
        CopyBits(&outDist[0], &fr.planeHit);
        return true;
    }

    // Closest approach of the axis segment to the polygon.
    FUN_00358030(FP(fr.start), axis, 0, planePt, a6, a7, FP(&fr.t), FP(fr.onPoly), FP(fr.toAxis),
                 FP(&fr.unusedOut), FP(&fr.u), 1, 1, 1);
    if (0.0f < fr.t && fr.t < fullLen) {
        float axisY = axis[1];
        hulk_fslot tz = fr.t * axis[2];
        hulk_fslot tx = (fr.t * axis[0]) + fr.start[0];
        hulk_fslot nz = fr.toAxis[2] * fr.u;
        hulk_fslot px = fr.onPoly[0] + (fr.toAxis[0] * fr.u);
        CopyBits(&outPoint[0], &px);
        hulk_fslot pz = fr.onPoly[2] + nz;
        outPoint[1] = fr.onPoly[1] + (fr.toAxis[1] * fr.u);
        outPoint[2] = fr.onPoly[2] + nz;
        hulk_fslot dx = tx - px;
        hulk_fslot dy = ((fr.t * axisY) + fr.start[1]) - (fr.onPoly[1] + (fr.toAxis[1] * fr.u));
        double dist = sqrt(((dx * dx) + (((tz + fr.start[2]) - pz) * ((tz + fr.start[2]) - pz))) + (dy * dy));
        outDist[0] = (float)dist;
        if (dist < radius) {
            CopyBits3(outNormal, n);
            CopyBits(&outDist[0], &fr.planeHit);
            return true;
        }
    }

    // Pick whichever capsule end is closer to the plane.
    hulk_fslot endZ = halfLen * axis[2];
    hulk_fslot endX = (halfLen * axis[0]) + c[0];
    hulk_fslot endZ2 = endZ + c[2];
    hulk_fslot startSide = (((fr.start[2] * n[2]) + (fr.start[1] * n[1])) + (fr.start[0] * n[0])) -
                           (((n[2] * planePt[2]) + (n[1] * planePt[1])) + (n[0] * planePt[0]));
    hulk_fslot startDist = AbsBits(startSide);
    hulk_fslot endSide = (((endZ2 * n[2]) + (((halfLen * axis[1]) + c[1]) * n[1])) + (endX * n[0])) -
                         (((n[2] * planePt[2]) + (n[1] * planePt[1])) + (n[0] * planePt[0]));
    hulk_fslot endDist = AbsBits(endSide);
    if (startDist < endDist) {
        fr.nearEnd[0] = fr.start[0];
        fr.nearEnd[1] = fr.start[1];
        fr.nearEnd[2] = fr.start[2];
    } else {
        fr.nearEnd[0] = endX;
        fr.nearEnd[1] = (halfLen * axis[1]) + c[1];
        fr.nearEnd[2] = endZ2;
    }

    // q = (n x axis) x axis: the part of n perpendicular to the axis.
    hulk_fslot cx = (n[1] * axis[2]) - (n[2] * axis[1]);
    hulk_fslot cz = (n[0] * axis[1]) - (n[1] * axis[0]);
    fr.q[0] = (((n[2] * axis[0]) - (n[0] * axis[2])) * axis[2]) - (cz * axis[1]);
    fr.q[1] = (((n[0] * axis[1]) - (n[1] * axis[0])) * axis[0]) - (cx * axis[2]);
    fr.q[2] = (cx * axis[1]) - (((n[2] * axis[0]) - (n[0] * axis[2])) * axis[0]);

    FUN_0022de70(FP(fr.nearEnd), FP(fr.q), planePt, n, FP(fr.contact), FP(&fr.side));
    hulk_fslot sideDist = AbsBits(fr.side);
    if (sideDist > radius)
        return false;
    if (FUN_003577c0((float *)(FP(fr.contact)), (float *)planePt, (const void *)(hulk_uintptr)(int)a6, (const void *)(hulk_uintptr)(int)a7, (float *)n)) {
        CopyBits3(outPoint, FP(fr.contact));
        CopyBits(&outDist[0], &fr.planeHit);
        CopyBits3(outNormal, n);
        return true;
    }

    // Intersect the axis line with the capsule radius around the contact point: a quadratic in the
    // distance along d = axis x n.
    ((V3_358b10 *)FP(fr.d))->FUN_000111b0((V3_358b10 *)axis, (V3_358b10 *)n);
    hulk_fslot dd = ((fr.d[2] * fr.d[2]) + (fr.d[1] * fr.d[1])) + (fr.d[0] * fr.d[0]);
    double halfB = ((fr.d[2] * (fr.contact[2] - fr.nearEnd[2])) + ((fr.contact[1] - fr.nearEnd[1]) * fr.d[1])) +
                   ((fr.contact[0] - fr.nearEnd[0]) * fr.d[0]);
    hulk_fslot twoB = halfB + halfB;
    double gap = (((fr.contact[2] - fr.nearEnd[2]) * (fr.contact[2] - fr.nearEnd[2])) +
                  ((fr.contact[1] - fr.nearEnd[1]) * (fr.contact[1] - fr.nearEnd[1]))) +
                 ((fr.contact[0] - fr.nearEnd[0]) * (fr.contact[0] - fr.nearEnd[0]));
    double disc = ((halfB + halfB) * twoB) - (((gap - (radius * radius)) * dd) * 4.0f);
    if (!(1e-5f < disc))
        return false;
    hulk_fslot root = sqrt(disc);
    hulk_fslot twoA = dd + dd;

    hulk_fslot step1 = (root - twoB) / twoA;
    float *r1 = FUN_00083e00(FP(fr.tmp), FP(fr.d), step1);
    fr.q1[0] = fr.contact[0] + r1[0];
    fr.q1[1] = fr.contact[1] + r1[1];
    fr.q1[2] = fr.contact[2] + r1[2];
    fr.p1[0] = fr.contact[0] + r1[0];
    fr.p1[1] = fr.contact[1] + r1[1];
    fr.p1[2] = fr.q1[2];
    hulk_fslot step2 = ((-twoB) - root) / twoA;
    r1 = FUN_00083e00(FP(fr.tmp), FP(fr.d), step2);
    fr.tmp[2] = fr.contact[2] + r1[2];
    fr.d[0] = (fr.contact[0] + r1[0]) - fr.q1[0];
    fr.d[1] = (fr.contact[1] + r1[1]) - fr.q1[1];
    fr.d[2] = fr.tmp[2] - fr.q1[2];
    ((V3_358b10 *)FP(fr.d))->FUN_0022d180();

    // Nearest approach of the new axis segment to the polygon.
    FUN_00358030(FP(fr.p1), FP(fr.d), 1, planePt, a6, a7, FP(&fr.t), FP(fr.onPoly), FP(fr.toAxis),
                 FP(&fr.unusedOut), FP(&fr.u), 1, 1, 1);
    r1 = FUN_00083e00(FP(fr.tmp), FP(fr.d), fr.t);
    fr.q1[0] = fr.p1[0] + r1[0];
    fr.q1[1] = fr.p1[1] + r1[1];
    fr.q1[2] = fr.p1[2] + r1[2];
    r1 = FUN_00083e00(FP(fr.tmp), FP(fr.toAxis), fr.u);
    hulk_fslot ox = r1[0];
    hulk_fslot oy = r1[1];
    hulk_fslot oz = r1[2];
    fr.tmp[2] = fr.onPoly[2] + oz;
    outPoint[0] = fr.onPoly[0] + ox;
    outPoint[1] = fr.onPoly[1] + oy;
    outPoint[2] = fr.onPoly[2] + oz;
    fr.toAxis[0] = fr.q1[0] - (fr.onPoly[0] + ox);
    fr.toAxis[1] = fr.q1[1] - (fr.onPoly[1] + oy);
    fr.toAxis[2] = fr.q1[2] - fr.tmp[2];
    double len = ((V3_358b10 *)FP(fr.toAxis))->FUN_00018990();
    outDist[0] = (float)len;
    if (!(len < 0.1f))
        return false;
    CopyBits3(outNormal, n);
    CopyBits(&outDist[0], &fr.planeHit);
    return true;
}
} // namespace fn_00358b10
#undef FP

namespace fn_fc83e8cf {

// 0x00359260 FUN_00359260 (496 B): equivalent/0x00359260.cpp
// sym: _FUN_00359260 @5feb1c12b3d5 @wa7224aee3796
// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 14/14)
// FUN_00359260 @ 0x00359260
// Ray/plane distance plus triangle containment test; falls back to the closest edge point.
extern "C" bool FUN_00359260(Vec3_359260* origin, float eps, Vec3_359260* a, Vec3_359260* b, Vec3_359260* c, Vec3_359260* normal,
                  float* dist, Vec3_359260* hit, Vec3_359260* outDir, bool e0, bool e1, bool e2)
{
    double zx = (origin->z - b->z) * normal->z + (origin->x - b->x) * normal->x; // keep the original's summation order
    hulk_freg d = zx + (origin->y - b->y) * normal->y;
    *dist = d;
    if (fabsf_(d) > eps)
        return false;

    hulk_freg mx = d * normal->x;
    volatile float my = d * normal->y;
    volatile float mz = d * normal->z;
    hit->x = origin->x - mx;
    hit->y = origin->y - my;
    hit->z = origin->z - mz;

    if (FUN_003577c0((Vec3_359260 *)hit, (Vec3_359260 *)a, (Vec3_359260 *)b, (Vec3_359260 *)c, (Vec3_359260 *)normal)) {
        *outDir = *normal;
        *dist = *dist - eps;
        return true;
    }

    if (!e0 && !e1 && !e2)
        return false;

    FUN_00357ea0((Vec3_359260 *)origin, (Vec3_359260 *)a, (Vec3_359260 *)b, (Vec3_359260 *)c, (Vec3_359260 *)hit, e0, e1, e2);

    double dx = origin->x - hit->x; // the offsets stay in registers (unrounded) for len2
    double dy = origin->y - hit->y;
    double dz = origin->z - hit->z;
    outDir->x = dx;
    outDir->y = dy;
    outDir->z = dz;
    float len2 = dz * dz + dy * dy + dx * dx;
    if (eps * eps < len2)
        return false;

    if (!(fabsf_(len2) <= 0.00001f)) {
        double len = sqrt(len2); // unrounded in st0 in the original
        *dist = len;
        double inv = 1.0f / len;
        outDir->x = outDir->x * inv;
        outDir->y = outDir->y * inv;
        outDir->z = outDir->z * inv;
    } else {
        *dist = 0.0f;
        *outDir = *normal;
    }
    *dist = *dist - eps;
    return true;
}


// 0x00359450 FUN_00359450 (178 B): equivalent/0x00359450.cpp
// sym: _FUN_00359450 @b757b0c5f216 @wa83547b77b74
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 0/0)
// FUN_00359450 @ 0x00359450
// Interval of a box (centre c, half extents ext, axes ax/ay/az) projected onto a direction.
extern "C" void __cdecl FUN_00359450(const void * dir_, const void *c, const void * ext_, const void *ax, const void *ay,
                          const void *az, float *outMin, float *outMax)
{
    const Vec3_359450 * dir = (const Vec3_359450 *)dir_;
    const Vec3_359450 * ext = (const Vec3_359450 *)ext_;
    hulk_freg centre = ((const Vec3_359450 *)c)->z * dir->z + ((const Vec3_359450 *)c)->y * dir->y + ((const Vec3_359450 *)c)->x * dir->x;

    AbsFloat px, py, pz;
    px.f = ((const Vec3_359450 *)ax)->z * dir->z + ((const Vec3_359450 *)ax)->y * dir->y + ((const Vec3_359450 *)ax)->x * dir->x;
    px.bits &= 0x7fffffff;
    py.f = ((const Vec3_359450 *)ay)->z * dir->z + ((const Vec3_359450 *)ay)->y * dir->y + ((const Vec3_359450 *)ay)->x * dir->x;
    py.bits &= 0x7fffffff;
    pz.f = ((const Vec3_359450 *)az)->z * dir->z + ((const Vec3_359450 *)az)->y * dir->y + ((const Vec3_359450 *)az)->x * dir->x;
    pz.bits &= 0x7fffffff;

    hulk_freg radius = pz.f * ext->z + py.f * ext->y + px.f * ext->x;
    *outMin = centre - radius;
    *outMax = centre + radius;
}


// 0x00359510 FUN_00359510 (835 B): equivalent/0x00359510.cpp
// sym: ?FUN_00359510@fn_fc83e8cf@@YA_NPBUVec3@1@PBM000000@Z @65c43ea2e865 @w2f4a25048fd0
// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 17/18, incomplete)
// FUN_00359510 @ 0x00359510
// Triangle (t0,t1,t2) against an oriented box (center, half extents, three axes): separating-axis test.
bool __cdecl FUN_00359510(const Vec3* center, const float* half, const Vec3* ax0, const Vec3* ax1,
                          const Vec3* ax2, const Vec3* t0, const Vec3* t1, const Vec3* t2) {
    struct Frame {
        float mn, lo, hi, mx;
        int j;
        int diff;
        Vec3 v;
        Vec3 e2;
        Vec3 e1;
        const Vec3* axes[3];
        const Vec3* tri[3];
        Vec3 edge[3];
    } f;
    f.axes[0] = ax0;
    f.axes[1] = ax1;
    f.axes[2] = ax2;
    f.tri[0] = t0;
    f.tri[1] = t1;
    f.tri[2] = t2;
    const float* h = half;
    // the first loop walks half[] and axes[] together (the original keeps their byte distance in a stack slot)
    f.diff = (int)((const char*)f.axes - (const char*)half);
    for (f.j = 0; f.j < 3; f.j++, h++) {
        f.v = **(const Vec3* const*)((const char*)h + f.diff);
        FUN_003579f0(&f.v, f.tri, &f.mn, &f.mx);
        double d = (double)f.v.x * center->x;
        d = d + (double)f.v.y * center->y;
        d = d + (double)f.v.z * center->z;
        f.lo = (float)(d - *h);
        double hi = d + *h;
        f.hi = (float)hi;
        if (hi < f.mn)
            return false;
        if (f.mx < f.lo)
            return false;
    }
    f.e1.x = t1->x - t0->x;
    f.e1.y = t1->y - t0->y;
    f.e1.z = t1->z - t0->z;
    f.edge[0] = f.e1;
    f.e2.x = t2->x - t0->x;
    f.e2.y = t2->y - t0->y;
    f.e2.z = t2->z - t0->z;
    f.edge[1] = f.e2;
    f.edge[2].x = f.e2.x - f.e1.x;
    f.edge[2].y = f.e2.y - f.e1.y;
    f.edge[2].z = f.e2.z - f.e1.z;
    f.v.x = f.e2.z * f.e1.y - f.e2.y * f.e1.z;
    f.v.y = f.e1.z * f.e2.x - f.e2.z * f.e1.x;
    hulk_freg vz = f.e2.y * f.e1.x - f.e1.y * f.e2.x;   // stored rounded, used unrounded
    f.v.z = vz;
    hulk_freg dd = vz * t0->z;     // one term per statement, in the listing's order
    dd += f.v.y * t0->y;
    dd += f.v.x * t0->x;
    f.mn = dd;
    f.mx = dd;
    FUN_00359450((const Vec3 *)(&f.v), (const Vec3 *)center, (const float *)half, (const Vec3 *)ax0, (const Vec3 *)ax1, (const Vec3 *)ax2, &f.lo, &f.hi);
    if (f.hi < f.mn)
        return false;
    if (f.mn < f.lo)
        return false;
    for (f.j = 0; f.j < 3; f.j++) {
        for (int i = 0; i < 3; i++) {
            const Vec3* a = f.axes[i];
            const Vec3& e = f.edge[f.j];
            f.v.x = e.y * a->z - e.z * a->y;
            f.v.y = a->x * e.z - a->z * e.x;
            f.v.z = a->y * e.x - a->x * e.y;
            FUN_003579f0(&f.v, f.tri, &f.mn, &f.mx);
            FUN_00359450((const Vec3 *)(&f.v), (const Vec3 *)center, (const float *)half, (const Vec3 *)ax0, (const Vec3 *)ax1, (const Vec3 *)ax2, &f.lo, &f.hi);
            if (f.hi < f.mn)
                return false;
            if (f.mx < f.lo)
                return false;
        }
    }
    return true;
}


// 0x00359860 FUN_00359860 (541 B): equivalent/0x00359860.cpp
// sym: ?FUN_00359860@fn_fc83e8cf@@YAMPAUVec3_359860@1@000000@Z @002846f1983e @wf3394bc543c8
// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 18/18)
// FUN_00359860 @ 0x00359860
// Slab test of a ray against an oriented box: returns the negated smallest per-axis ratio.
hulk_freg FUN_00359860(Vec3_359860 *origin, Vec3_359860 *extent, Vec3_359860 *axisX, Vec3_359860 *axisY, Vec3_359860 *axisZ, Vec3_359860 *dir, Vec3_359860 *point)
{
    struct Frame {
        Vec3_359860 v;
        Vec3_359860 q;
        Vec3_359860 p;
        Matrix m;
    } f;

    f.m.m[0] = axisX->x;
    f.m.m[1] = axisY->x;
    f.m.m[2] = axisZ->x;
    f.m.m[3] = 0.0f;
    f.m.m[4] = axisX->y;
    f.m.m[5] = axisY->y;
    f.m.m[6] = axisZ->y;
    f.m.m[7] = 0.0f;
    f.m.m[8] = axisX->z;
    f.m.m[9] = axisY->z;
    f.m.m[10] = axisZ->z;
    f.m.m[11] = 0.0f;
    f.m.m[12] = 0.0f;
    f.m.m[13] = 0.0f;
    f.m.m[14] = 0.0f;
    f.m.m[15] = 1.0f;

    f.v.x = point->x - origin->x;
    f.v.y = point->y - origin->y;
    f.v.z = point->z - origin->z;
    ((owners::Mat_22c2b0 *)&(f.m))->FUN_0022c2b0((float *)(const Vec3_359860 *)(&f.v), (float *)(Vec3_359860 *)(&f.p));
    ((owners::Mat_22c2b0 *)&(f.m))->FUN_0022c2b0((float *)(const Vec3_359860 *)dir, (float *)(Vec3_359860 *)(&f.q));

    float best = 1.0e12f;

    if (!(fabsf_(f.q.x) <= 1e-5f)) {
        double t = (extent->x + (f.q.x < 0.0f ? f.p.x : -f.p.x)) / fabs(f.q.x);
        volatile float r = (float)t; // rounded through the frame in the original
        if (t < best)
            best = r;
    }
    if (!(fabsf_(f.q.y) <= 1e-5f)) {
        double t = (extent->y + (f.q.y < 0.0f ? f.p.y : -f.p.y)) / fabs(f.q.y);
        volatile float r = (float)t; // rounded through the frame in the original
        if (t < best)
            best = r;
    }
    if (!(fabsf_(f.q.z) <= 1e-5f)) {
        double t = (extent->z + (f.q.z < 0.0f ? f.p.z : -f.p.z)) / fabs(f.q.z);
        volatile float r = (float)t; // rounded through the frame in the original
        if (t < best)
            best = r;
    }
    return -best;
}

} // namespace fn_fc83e8cf

// 0x00359a80 FUN_00359a80 (1805 B): equivalent/0x00359a80.cpp [wrapped: macros]
// sym: _FUN_00359a80 @54e2ebb3e84b @wf6d824126738
namespace fn_00359a80 {
// STATUS: equivalent (tools/equiv.py level 3: 11399 inputs, branch coverage 67/72, incomplete)
// FUN_00359a80 @ 0x00359a80

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


struct V3 {
    float x, y, z;
};

union FBits {
    float f;
    unsigned int u;
};

// a + (b - a) * t, with t = da / (da - db), written out so the FPU keeps t and the differences unrounded
#define LERP(dst, a, b, da, db)                                  \
    do {                                                         \
        float *pa_ = (a);                                        \
        float *pb_ = (b);                                        \
        volatile float tx_, ty_, dz_;                            \
        hulk_freg t_ = (hulk_freg)(da) / ((hulk_freg)(da) - (db)); \
        dz_ = pb_[2] - pa_[2];                                   \
        tx_ = ((hulk_freg)pb_[0] - pa_[0]) * t_;                 \
        ty_ = ((hulk_freg)pb_[1] - pa_[1]) * t_;                 \
        (dst)[2] = (hulk_freg)dz_ * t_ + pa_[2];                 \
        (dst)[0] = tx_ + pa_[0];                                 \
        (dst)[1] = ty_ + pa_[1];                                 \
    } while (0)

extern "C" void FUN_00359a80(const void * plane_, float d, int *pcount, void * v_)
{
    const V3 * plane = (const V3 *)plane_;
    V3 * v = (V3 *)v_;
    struct Frame {
        char padA[0x1c];
        float dist[12];
        char padB[12];
        V3 out[12];
    } F;
    int n = *pcount;
    int pos = 0;
    int neg = 0;
    int first = -1;
    int i;
    FBits a;
    a.f = d;
    a.u &= 0x7fffffff;
    for (i = 0; i < n; i++) {
        F.dist[i] = (hulk_freg)v[i].x * plane->x + (hulk_freg)v[i].z * plane->z + (hulk_freg)v[i].y * plane->y - d +
                    (hulk_freg)a.f * 1e-5f;
        if (F.dist[i] >= 0.0f) {
            pos++;
            if (first < 0)
                first = i;
        } else {
            neg++;
        }
    }
    int k = 0;
    if (n == 2) {
        if (pos <= 0) {
            *pcount = 0;
            return;
        }
        if (neg <= 0)
            return;
        int other = (first == 0);
        LERP((float *)&v[other], (float *)&v[first], (float *)&v[other], F.dist[first], F.dist[other]);
        return;
    }
    if (pos <= 0) {
        *pcount = 0;
        return;
    }
    if (neg <= 0) {
        *pcount = n;
        return;
    }
    int c = first;
    if (c > 0) {
        LERP((float *)&F.out[0], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
        k = 1;
        while (c < n && F.dist[c] >= 0.0f) {
            F.out[k++] = v[c];
            c++;
        }
        if (c < n) {
            LERP((float *)&F.out[k], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
        } else {
            LERP((float *)&F.out[k], (float *)&v[0], (float *)&v[n - 1], F.dist[0], F.dist[n - 1]);
        }
        k++;
    } else {
        c = 0;
        while (c < n && F.dist[c] >= 0.0f) {
            F.out[k++] = v[c];
            c++;
        }
        LERP((float *)&F.out[k], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
        k++;
        bool entered = false;
        if (c < n) {
            while (c < n) {
                if (!(F.dist[c] < 0.0f)) {
                    entered = true;
                    break;
                }
                c++;
            }
        }
        if (entered && c < n) {
            LERP((float *)&F.out[k], (float *)&v[c], (float *)&v[c - 1], F.dist[c], F.dist[c - 1]);
            k++;
            while (c < n && F.dist[c] >= 0.0f) {
                F.out[k++] = v[c];
                c++;
            }
        } else {
            LERP((float *)&F.out[k], (float *)&v[0], (float *)&v[n - 1], F.dist[0], F.dist[n - 1]);
            k++;
        }
    }
    memcpy(v, F.out, k * sizeof(V3));
    *pcount = k;
}
} // namespace fn_00359a80
#undef LERP

namespace fn_fc83e8cf {

// 0x0035a190 FUN_0035a190 (268 B): equivalent/0x0035a190.cpp
// sym: ?FUN_0035a190@fn_fc83e8cf@@YA_NPAUBox_35a190@1@PAUVec3_35a190@1@11PAH1@Z @bc2b6f5f0e6a @w77894e886afc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0035a190 @ 0x0035a190
// Clips the triangle (a, b, c) against the six faces of an oriented box.
// Returns true when something is left (the polygon is in `out`, its vertex count in *count).
bool FUN_0035a190(Box_35a190 *box, Vec3_35a190 *a, Vec3_35a190 *b, Vec3_35a190 *c, int *count, Vec3_35a190 *out)
{
    *count = 3;
    out[0] = *a;
    out[1] = *b;
    out[2] = *c;
    for (int s = -1; s <= 1; s += 2) {
        float sign = (float)s;
        for (int k = 0; k < 3; k++) {
            Vec3_35a190 n;
            n.x = sign * box->axis[k].x;
            n.y = sign * box->axis[k].y;
            n.z = sign * box->axis[k].z;
            FUN_00359a80((Vec3_35a190 *)(&n), n.x * box->center.x + n.y * box->center.y + n.z * box->center.z - box->extent[k], count, (Vec3_35a190 *)out);
        }
    }
    return *count > 0;
}


// 0x0035a2a0 FUN_0035a2a0 (542 B): equivalent/0x0035a2a0.cpp
// sym: ?FUN_0035a2a0@fn_fc83e8cf@@YA_NPAUVec3_35a2a0@1@00000000PAM00@Z @3170b490c4a6 @w05fde517f2e2
// STATUS: equivalent (tools/equiv.py level 3: 157 inputs, branch coverage 10/10)
// FUN_0035a2a0 @ 0x0035a2a0
// Oriented-box overlap: centroid of the clipped contact points and penetration along the reversed direction.
bool FUN_0035a2a0(Vec3_35a2a0 *a1, Vec3_35a2a0 *a2, Vec3_35a2a0 *axisX, Vec3_35a2a0 *axisY, Vec3_35a2a0 *axisZ, Vec3_35a2a0 *a6, Vec3_35a2a0 *a7, Vec3_35a2a0 *a8,
                  Vec3_35a2a0 *dir, float *depth, Vec3_35a2a0 *centre, Vec3_35a2a0 *normal)
{
    struct Frame {
        Vec3_35a2a0 neg;
        int count;
        Hull_35a2a0 hull;
        Vec3_35a2a0 pts[12];
    } f;

    if (!FUN_00359510(a1, a2, axisX, axisY, axisZ, a6, a7, a8, dir, 1, 1, 1))
        return false;

    f.hull.FUN_00357740(a1, *axisX, *axisY, *axisZ, a2);
    FUN_0035a190(&f.hull, a6, a7, a8, &f.count, f.pts);
    if (f.count == 0)
        return false;

    centre->z = 0.0f;
    centre->y = 0.0f;
    centre->x = 0.0f;
    if (f.count > 0) {
        hulk_freg sx = 0.0f;
        hulk_freg sy = 0.0f;
        hulk_freg sz = 0.0f;
        const Vec3_35a2a0 *p = f.pts;
        int n = f.count;
        do {
            sx += p->x;
            sy += p->y;
            sz += p->z;
            ++p;
            --n;
        } while (n != 0);
        centre->z = sz;
        centre->y = sy;
        centre->x = sx;
    }
    hulk_freg inv = 1.0f / (float)f.count;
    centre->x = inv * centre->x;
    centre->y = inv * centre->y;
    centre->z = inv * centre->z;

    f.neg.x = dir->x * -1.0f;
    f.neg.y = dir->y * -1.0f;
    f.neg.z = dir->z * -1.0f;
    hulk_freg d = FUN_00359860(a1, a2, axisX, axisY, axisZ, &f.neg, centre);
    *depth = d;
    if (!(d > 0.0f)) {
        *normal = *dir;
        return true;
    }
    return false;
}


// 0x0035a4c0 FUN_0035a4c0 (159 B): matches/0x0035a4c0.cpp
// sym: _FUN_0035a4c0
// FUN_0035a4c0 @ 0x0035a4c0
// Oriented-box overlap against the world axes: the same test as FUN_0035a2a0 with an identity basis.
extern "C" char __cdecl FUN_0035a4c0(Vec3_35a4c0 *a1, Vec3_35a4c0 *a2, Vec3_35a4c0 *v0, Vec3_35a4c0 *v1, Vec3_35a4c0 *v2, Vec3_35a4c0 *normal, float *depth,
                          Vec3_35a4c0 *centre, Vec3_35a4c0 *outN, int f1, int f2, int f4)
{
    struct Frame {
        Vec3_35a4c0 axisZ;
        Vec3_35a4c0 axisY;
        Vec3_35a4c0 axisX;
    } fr;
    fr.axisZ.x = 0.0f; fr.axisZ.y = 0.0f; fr.axisZ.z = 1.0f;
    fr.axisY.x = 0.0f; fr.axisY.y = 1.0f; fr.axisY.z = 0.0f;
    fr.axisX.x = 1.0f; fr.axisX.y = 0.0f; fr.axisX.z = 0.0f;
    return FUN_0035a2a0(a1, a2, &fr.axisX, &fr.axisY, &fr.axisZ, v0, v1, v2, normal, depth, centre, outN, f1, f2, f4);
}


// 0x0035a590 FUN_0035a590 (144 B): equivalent/0x0035a590.cpp
// sym: ?FUN_0035a590@fn_fc83e8cf@@YAHXZ @99175298c974 @w1bfa4cb1fc0c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/11)
// FUN_0035a590 @ 0x0035a590
// FUN_0035a590 @ 0x0035a590: one-letter language/region code for the index FUN_00209f50 returns (1..9).
int FUN_0035a590()
{
    int code = '?';
    switch (FUN_00209f50()) {
    case 1: code = 'E'; break;
    case 2: code = 'J'; break;
    case 3: code = 'G'; break;
    case 4: code = 'F'; break;
    case 5: code = 'S'; break;
    case 6: code = 'I'; break;
    case 7: code = 'K'; break;
    case 8: code = 'C'; break;
    case 9: code = 'P'; break;
    }
    return code;
}


// 0x0035a620 thunk_FUN_0035a6c0 (5 B): matches/0x0035a620.cpp
// sym: ?thunk_FUN_0035a6c0@fn_fc83e8cf@@YAXH@Z
// thunk_FUN_0035a6c0 @ 0x0035a620: jmp FUN_0035a6c0
void thunk_FUN_0035a6c0(int v) { FUN_0035a6c0(v); }


// 0x0035a630 FUN_0035a630 (6 B): matches/0x0035a630.cpp
// sym: ?FUN_0035a630@fn_fc83e8cf@@YAHXZ
// FUN_0035a630 @ 0x0035a630: getter for the value FUN_0035a6c0 stores
int FUN_0035a630() { return DAT_004dbf6c; }

} // namespace fn_fc83e8cf
