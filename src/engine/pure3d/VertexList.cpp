// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c89b0..0x002d0930 (kind game, layer engine, confidence medium), dominant class pure3d::VertexList
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f7aa76dc {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f7aa76dc {} using namespace fn_f7aa76dc;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f7aa76dc {
extern int hulk_at_0042efc0, hulk_at_003f6098;
extern void Free_0008d340(void*);
class Ref_2c89b0 {
  public:
    virtual void f0();
    virtual void Release();
};
class VertexList_2c89b0 {
  public:
    void* vptr;
    int a4, a8, ac, a10;
    void *p14, *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34;
    void* q[4];
    void* r[2];
    void *p50, *p54;
    Ref_2c89b0* a58;
    ~VertexList_2c89b0();
};
struct Mat {
    float m[16];
};
struct MatSet {
    char pad00[8];
    Mat *mats;
};
struct Remap {
    char pad00[8];
    int *map;
};
class Skin {
public:
    char pad00[8];
    unsigned int flags;
    unsigned int count;
    char pad10[8];
    Vec3 *bindPos;
    Vec3 *srcA;
    Vec3 *dstBlend;
    Vec3 *dstA;
    Vec3 *srcB;
    Vec3 *dstB;
    Vec3 *srcC;
    Vec3 *dstC;
    char pad38[0x50 - 0x38];
    unsigned char *idx;
    float *weights;
    void FUN_002c92f0(MatSet *ms, Remap *rm);
};
struct Vec2_2c96e0 { float x, y; };
struct Vec3_2c96e0 { float x, y, z; };
struct Blend_2c96e0 {
    char pad00[0x10];
    Vec3_2c96e0* q0;
    Vec3_2c96e0* q1;
    Vec2_2c96e0* r0;
    Vec2_2c96e0* r1;
    Vec2_2c96e0* r2;
    Vec2_2c96e0* r3;
    short* d0;
    short* d1;
};
struct Source_2c96e0 {
    char pad00[8];
    unsigned flags;
    char pad0c[4];
    unsigned count;
    unsigned short* index;
    Vec3_2c96e0* p0;
    Vec3_2c96e0* p1;
    Vec3_2c96e0* p2;
    Vec3_2c96e0* p3;
    char pad28[0x38 - 0x28];
    Vec2_2c96e0* s0;
    Vec2_2c96e0* s1;
    Vec2_2c96e0* s2;
    Vec2_2c96e0* s3;
    unsigned* col0;
    unsigned* col1;
    char pad50[8];
    Blend_2c96e0* blend;
};
struct VertexSink_2c96e0 {
    char pad00[8];
    Vec3_2c96e0* pos;
    Vec3_2c96e0* normal;
    unsigned* color;
    Vec2_2c96e0* uv;
    void FUN_0008ef00();
};
static __forceinline int Clamp255(int v)
{
    if (v < 0)
        return 0;
    if (v > 255)
        return 255;
    return v;
}
static __forceinline unsigned AddColor(unsigned c, const short* d)
{
    int r = Clamp255(((c >> 16) & 0xff) + d[0]);
    int g = Clamp255(((c >> 8) & 0xff) + d[1]);
    int b = Clamp255((c & 0xff) + d[2]);
    int a = Clamp255((c >> 24) + d[3]);
    return (((a << 8 | r) << 8 | g) << 8) | b;
}
static __forceinline void PutPos(VertexSink_2c96e0* out, const Vec3_2c96e0* p, const Vec3_2c96e0* q)
{
    if (q) {
        float z = p->z + q->z;
        float y = p->y + q->y;
        float x = p->x + q->x;
        out->pos->x = x;
        out->pos->y = y;
        out->pos->z = z;
    } else {
        float z = p->z;
        float y = p->y;
        float x = p->x;
        out->pos->x = x;
        out->pos->y = y;
        out->pos->z = z;
    }
}
static __forceinline void PutNormal(VertexSink_2c96e0* out, const Vec3_2c96e0* p, const Vec3_2c96e0* q)
{
    if (q) {
        float z = p->z + q->z;
        float y = p->y + q->y;
        float x = p->x + q->x;
        out->normal->x = x;
        out->normal->y = y;
        out->normal->z = z;
    } else {
        float z = p->z;
        float y = p->y;
        float x = p->x;
        out->normal->x = x;
        out->normal->y = y;
        out->normal->z = z;
    }
}
static __forceinline void PutUv(VertexSink_2c96e0* out, int k, const Vec2_2c96e0* s, const Vec2_2c96e0* r)
{
    if (r) {
        float y = s->y + r->y;
        float x = s->x + r->x;
        out->uv[k].x = x;
        out->uv[k].y = y;
    } else {
        float y = s->y;
        float x = s->x;
        out->uv[k].x = x;
        out->uv[k].y = y;
    }
}
static __forceinline void PutColor(unsigned* dst, const unsigned* c, const short* d, unsigned i)
{
    if (d)
        *dst = AddColor(c[i], d + i * 4);
    else
        *dst = c[i];
}
struct Vec2_2cb2b0 { float x, y; };
struct Vec3_2cb2b0 { float x, y, z; };
struct Blend_2cb2b0 {
    char pad00[0x10];
    Vec3_2cb2b0* q0;
    Vec3_2cb2b0* q1;
    Vec2_2cb2b0* r0;
    Vec2_2cb2b0* r1;
    Vec2_2cb2b0* r2;
    Vec2_2cb2b0* r3;
    short* d0;
    short* d1;
};
struct Source_2cb2b0 {
    char pad00[8];
    unsigned flags;
    unsigned count;
    char pad10[4];
    unsigned short* index;
    Vec3_2cb2b0* p0;
    Vec3_2cb2b0* p1;
    Vec3_2cb2b0* p2;
    Vec3_2cb2b0* p3;
    char pad28[0x38 - 0x28];
    Vec2_2cb2b0* s0;
    Vec2_2cb2b0* s1;
    Vec2_2cb2b0* s2;
    Vec2_2cb2b0* s3;
    unsigned* col0;
    unsigned* col1;
    char pad50[8];
    Blend_2cb2b0* blend;
};
struct VertexSink_2cb2b0 {
    char pad00[8];
    Vec3_2cb2b0* pos;
    Vec3_2cb2b0* normal;
    unsigned* color;
    Vec2_2cb2b0* uv;
    void FUN_0008ef00();
};
static __forceinline void PutPos(VertexSink_2cb2b0* out, const Vec3_2cb2b0* p, const Vec3_2cb2b0* q)
{
    if (q) {
        float z = p->z + q->z;
        float y = p->y + q->y;
        float x = p->x + q->x;
        out->pos->x = x;
        out->pos->y = y;
        out->pos->z = z;
    } else {
        float z = p->z;
        float y = p->y;
        float x = p->x;
        out->pos->x = x;
        out->pos->y = y;
        out->pos->z = z;
    }
}
static __forceinline void PutNormal(VertexSink_2cb2b0* out, const Vec3_2cb2b0* p, const Vec3_2cb2b0* q)
{
    if (q) {
        float z = p->z + q->z;
        float y = p->y + q->y;
        float x = p->x + q->x;
        out->normal->x = x;
        out->normal->y = y;
        out->normal->z = z;
    } else {
        float z = p->z;
        float y = p->y;
        float x = p->x;
        out->normal->x = x;
        out->normal->y = y;
        out->normal->z = z;
    }
}
static __forceinline void PutUv(VertexSink_2cb2b0* out, int k, const Vec2_2cb2b0* s, const Vec2_2cb2b0* r)
{
    if (r) {
        float y = s->y + r->y;
        float x = s->x + r->x;
        out->uv[k].x = x;
        out->uv[k].y = y;
    } else {
        float y = s->y;
        float x = s->x;
        out->uv[k].x = x;
        out->uv[k].y = y;
    }
}
struct Vec2_2cd130 { float x, y; };
struct Vec3_2cd130 { float x, y, z; };
struct Blend_2cd130 {
    char pad00[0x10];
    Vec3_2cd130* q0;
    Vec3_2cd130* q1;
    Vec2_2cd130* r0;
    Vec2_2cd130* r1;
    Vec2_2cd130* r2;
    Vec2_2cd130* r3;
    short* d0;
    short* d1;
};
struct Source_2cd130 {
    char pad00[8];
    unsigned flags;
    char pad0c[4];
    unsigned count;
    unsigned short* index;
    Vec3_2cd130* p0;
    Vec3_2cd130* p1;
    Vec3_2cd130* p2;
    Vec3_2cd130* p3;
    Vec3_2cd130* t0;
    Vec3_2cd130* t1;
    Vec3_2cd130* t2;
    Vec3_2cd130* t3;
    Vec2_2cd130* s0;
    Vec2_2cd130* s1;
    Vec2_2cd130* s2;
    Vec2_2cd130* s3;
    unsigned* col0;
    unsigned* col1;
    char pad50[8];
    Blend_2cd130* blend;
};
struct VertexSink_2cd130 {
    virtual void SetPos(Vec3_2cd130 v);
    virtual void SetNormal(Vec3_2cd130 v);
    virtual void SetExtra0(Vec3_2cd130 v);
    virtual void SetExtra1(Vec3_2cd130 v);
    virtual void SetColor(unsigned c, int k);
    virtual void vf5();
    virtual void SetUv(Vec2_2cd130 uv, int k);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void SetPosNormalUv(Vec3_2cd130* pos, Vec3_2cd130* normal, Vec2_2cd130* uv);
    virtual void SetPosColorUv(Vec3_2cd130* pos, unsigned color, Vec2_2cd130* uv);
    virtual void SetPosUv(Vec3_2cd130* pos, Vec2_2cd130* uv);
    virtual void SetPosNormal(Vec3_2cd130* pos, Vec3_2cd130* normal);
    virtual void SetPosColor(Vec3_2cd130* pos, unsigned color);
};
static __forceinline Vec3_2cd130 Add3(const Vec3_2cd130& a, const Vec3_2cd130& b)
{
    Vec3_2cd130 v;
    v.z = a.z + b.z;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}
static __forceinline Vec2_2cd130 Add2(const Vec2_2cd130& a, const Vec2_2cd130& b)
{
    Vec2_2cd130 v;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}
struct Vec2_2cec10 { float x, y; };
struct Vec3_2cec10 { float x, y, z; };
struct Blend_2cec10 {
    char pad00[0x10];
    Vec3_2cec10* q0;
    Vec3_2cec10* q1;
    Vec2_2cec10* r0;
    Vec2_2cec10* r1;
    Vec2_2cec10* r2;
    Vec2_2cec10* r3;
    short* d0;
    short* d1;
};
struct Source_2cec10 {
    char pad00[8];
    unsigned flags;
    unsigned count;
    char pad10[8];
    Vec3_2cec10* p0;
    Vec3_2cec10* p1;
    Vec3_2cec10* p2;
    Vec3_2cec10* p3;
    Vec3_2cec10* t0;
    Vec3_2cec10* t1;
    Vec3_2cec10* t2;
    Vec3_2cec10* t3;
    Vec2_2cec10* s0;
    Vec2_2cec10* s1;
    Vec2_2cec10* s2;
    Vec2_2cec10* s3;
    unsigned* col0;
    unsigned* col1;
    char pad50[8];
    Blend_2cec10* blend;
};
struct VertexSink_2cec10 {
    virtual void SetPos(Vec3_2cec10 v);
    virtual void SetNormal(Vec3_2cec10 v);
    virtual void SetExtra0(Vec3_2cec10 v);
    virtual void SetExtra1(Vec3_2cec10 v);
    virtual void SetColor(unsigned c, int k);
    virtual void vf5();
    virtual void SetUv(Vec2_2cec10 uv, int k);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void SetPosNormalUv(Vec3_2cec10* pos, Vec3_2cec10* normal, Vec2_2cec10* uv);
    virtual void SetPosColorUv(Vec3_2cec10* pos, unsigned color, Vec2_2cec10* uv);
    virtual void SetPosUv(Vec3_2cec10* pos, Vec2_2cec10* uv);
    virtual void SetPosNormal(Vec3_2cec10* pos, Vec3_2cec10* normal);
    virtual void SetPosColor(Vec3_2cec10* pos, unsigned color);
};
static __forceinline Vec3_2cec10 Add3(const Vec3_2cec10& a, const Vec3_2cec10& b)
{
    Vec3_2cec10 v;
    v.z = a.z + b.z;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}
static __forceinline Vec2_2cec10 Add2(const Vec2_2cec10& a, const Vec2_2cec10& b)
{
    Vec2_2cec10 v;
    v.y = a.y + b.y;
    v.x = a.x + b.x;
    return v;
}
extern int hulk_at_0042efb0;
extern int ref_vftable_2d0800;
class VertexOffsetList {
  public:
    int* vptr;
    int p4, p8, pC;
    int a, b, c[4];
    int* d[2];
    void Clear();
};


// 0x002c89b0 FUN_002c89b0 (195 B): matches/0x002c89b0.cpp
// sym: ??1VertexList_2c89b0@fn_f7aa76dc@@QAE@XZ
VertexList_2c89b0::~VertexList_2c89b0() {
    vptr = &hulk_at_0042efc0;
    Free_0008d340(p14);
    Free_0008d340(p18);
    Free_0008d340(p1c);
    Free_0008d340(p20);
    Free_0008d340(p24);
    Free_0008d340(p28);
    Free_0008d340(p2c);
    Free_0008d340(p30);
    Free_0008d340(p34);
    for (int i = 0; i < 4; i++)
        Free_0008d340(q[i]);
    for (int i = 0; i < 2; i++)
        Free_0008d340(r[i]);
    Free_0008d340(p50);
    Free_0008d340(p54);
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    vptr = &hulk_at_003f6098;
}

} // namespace fn_f7aa76dc

// 0x002c8a80 FUN_002c8a80 (2146 B): equivalent/0x002c8a80.cpp [wrapped: macros]
// sym: ?Apply@Skin@fn_002c8a80@@QAEXPAUPal@2@PAUMap@2@@Z
namespace fn_002c8a80 {
// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 42/42)
// FUN_002c8a80 @ 0x002c8a80

struct V3 { float x, y, z; };

struct Mat4 { float m[16]; };

struct Pal {
    char pad00[8];
    Mat4 *mats;
};

struct Map {
    char pad00[8];
    int *idx;
};

struct Sub {
    char pad00[0x10];
    V3 *f10;
    V3 *f14;
};

// rotate (no translation) with the upper 3x3 of the matrix
#define ROT_X(M, x, y, z) ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0])
#define ROT_Y(M, x, y, z) ((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1])
#define ROT_Z(M, x, y, z) ((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2])
// transform with translation
#define XF_X(M, x, y, z) ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12])
#define XF_Y(M, x, y, z) ((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13])
#define XF_Z(M, x, y, z) ((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14])

// the original re-reads the base pointer and every source component for each output component
#define PTR(m) (*(V3 * volatile *)&(m))
#define VF(x) (*(volatile float *)&(x))

struct Skin {
    char pad00[0xc];
    unsigned int count;
    char pad10[0x18 - 0x10];
    V3 *f18;
    V3 *f1c;
    V3 *f20;
    V3 *f24;
    V3 *f28;
    V3 *f2c;
    V3 *f30;
    V3 *f34;
    char pad38[0x50 - 0x38];
    unsigned char (*bones)[4];
    float (*weights)[3];
    Sub *sub;
    void Apply(Pal *a, Map *b);
};

void Skin::Apply(Pal *a, Map *b)
{
    V3 *off10 = sub->f10;
    V3 *off14 = sub->f14;
    unsigned int i;

    if (f1c) {
        if (off14) {
            for (i = 0; i < *(volatile unsigned int *)&count; i++) {
                Mat4 *M = &a->mats[b->idx[bones[i][0]]];
                hulk_freg x = off14[i].x + f1c[i].x;
                hulk_freg y = off14[i].y + f1c[i].y;
                hulk_freg z = f1c[i].z + off14[i].z;
                PTR(f24)[i].x = ROT_X(M, x, y, z);
                PTR(f24)[i].y = ROT_Y(M, x, y, z);
                PTR(f24)[i].z = ROT_Z(M, x, y, z);
            }
        } else {
            for (i = 0; i < *(volatile unsigned int *)&count; i++) {
                Mat4 *M = &a->mats[b->idx[bones[i][0]]];
                PTR(f24)[i].x = ROT_X(M, VF(PTR(f1c)[i].x), VF(PTR(f1c)[i].y), VF(PTR(f1c)[i].z));
                PTR(f24)[i].y = ROT_Y(M, VF(PTR(f1c)[i].x), VF(PTR(f1c)[i].y), VF(PTR(f1c)[i].z));
                PTR(f24)[i].z = ROT_Z(M, VF(PTR(f1c)[i].x), VF(PTR(f1c)[i].y), VF(PTR(f1c)[i].z));
            }
        }
    }

    if (off10) {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            float x = f18[i].x + off10[i].x;
            float y = f18[i].y + off10[i].y;
            float z = f18[i].z + off10[i].z;
            float w0;
            if (weights)
                w0 = weights[i][0];
            else
                w0 = 1.0f;
            double rx = ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12]) * w0;
            volatile float ry = (float)(((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13]) * w0);
            volatile float rz = (float)(((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14]) * w0);
            if (!(w0 == 1.0f)) {
                float w1 = weights[i][1];
                Mat4 *M1 = &a->mats[b->idx[bones[i][1]]];
                double ax = rx + ((z) * (M1)->m[8] + (y) * (M1)->m[4] + (x) * (M1)->m[0] + (M1)->m[12]) * w1;
                double ay = ((z) * (M1)->m[9] + (y) * (M1)->m[5] + (x) * (M1)->m[1] + (M1)->m[13]) * w1 + ry;
                rz = (float)(((z) * (M1)->m[10] + (y) * (M1)->m[6] + (x) * (M1)->m[2] + (M1)->m[14]) * w1 + rz);
                float w2 = weights[i][2];
                Mat4 *M2 = &a->mats[b->idx[bones[i][2]]];
                volatile float bx = (float)(((z) * (M2)->m[8] + (y) * (M2)->m[4] + (x) * (M2)->m[0] + (M2)->m[12]) * w2 + ax);
                ry = (float)(((z) * (M2)->m[9] + (y) * (M2)->m[5] + (x) * (M2)->m[1] + (M2)->m[13]) * w2 + ay);
                rz = (float)(((z) * (M2)->m[10] + (y) * (M2)->m[6] + (x) * (M2)->m[2] + (M2)->m[14]) * w2 + rz);
                float w3 = (float)(1.0f - (weights[i][2] + weights[i][0] + weights[i][1]));
                Mat4 *M3 = &a->mats[b->idx[bones[i][3]]];
                rx = ((z) * (M3)->m[8] + (y) * (M3)->m[4] + (x) * (M3)->m[0] + (M3)->m[12]) * w3 + bx;
                ry = (float)(((z) * (M3)->m[9] + (y) * (M3)->m[5] + (x) * (M3)->m[1] + (M3)->m[13]) * w3 + ry);
                rz = (float)(((z) * (M3)->m[10] + (y) * (M3)->m[6] + (x) * (M3)->m[2] + (M3)->m[14]) * w3 + rz);
            }
            V3 *dst3 = f20;
            dst3[i].x = (float)rx;
            dst3[i].y = ry;
            dst3[i].z = rz;
        }
    } else {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            float w0;
            if (weights)
                w0 = weights[i][0];
            else
                w0 = 1.0f;
            float x = f18[i].x, y = f18[i].y, z = f18[i].z;
            double rx = ((z) * (M)->m[8] + (y) * (M)->m[4] + (x) * (M)->m[0] + (M)->m[12]) * w0;
            volatile float ry = (float)(((z) * (M)->m[9] + (y) * (M)->m[5] + (x) * (M)->m[1] + (M)->m[13]) * w0);
            volatile float rz = (float)(((z) * (M)->m[10] + (y) * (M)->m[6] + (x) * (M)->m[2] + (M)->m[14]) * w0);
            if (!(w0 == 1.0f)) {
                float w1 = weights[i][1];
                Mat4 *M1 = &a->mats[b->idx[bones[i][1]]];
                double ax = rx + ((z) * (M1)->m[8] + (y) * (M1)->m[4] + (x) * (M1)->m[0] + (M1)->m[12]) * w1;
                double ay = ((z) * (M1)->m[9] + (x) * (M1)->m[1] + (y) * (M1)->m[5] + (M1)->m[13]) * w1 + ry;
                rz = (float)(((z) * (M1)->m[10] + (x) * (M1)->m[2] + (y) * (M1)->m[6] + (M1)->m[14]) * w1 + rz);
                float w2 = weights[i][2];
                Mat4 *M2 = &a->mats[b->idx[bones[i][2]]];
                volatile float bx = (float)(((z) * (M2)->m[8] + (y) * (M2)->m[4] + (x) * (M2)->m[0] + (M2)->m[12]) * w2 + ax);
                ry = (float)(((z) * (M2)->m[9] + (x) * (M2)->m[1] + (y) * (M2)->m[5] + (M2)->m[13]) * w2 + ay);
                rz = (float)(((z) * (M2)->m[10] + (x) * (M2)->m[2] + (y) * (M2)->m[6] + (M2)->m[14]) * w2 + rz);
                float w3 = (float)(1.0f - (weights[i][2] + weights[i][0] + weights[i][1]));
                Mat4 *M3 = &a->mats[b->idx[bones[i][3]]];
                rx = ((z) * (M3)->m[8] + (y) * (M3)->m[4] + (x) * (M3)->m[0] + (M3)->m[12]) * w3 + bx;
                ry = (float)(((z) * (M3)->m[9] + (x) * (M3)->m[1] + (y) * (M3)->m[5] + (M3)->m[13]) * w3 + ry);
                rz = (float)(((z) * (M3)->m[10] + (x) * (M3)->m[2] + (y) * (M3)->m[6] + (M3)->m[14]) * w3 + rz);
            }
            V3 *dst3 = f20;
            dst3[i].x = (float)rx;
            dst3[i].y = ry;
            dst3[i].z = rz;
        }
    }

    if (f28) {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            PTR(f2c)[i].x = ROT_X(M, VF(PTR(f28)[i].x), VF(PTR(f28)[i].y), VF(PTR(f28)[i].z));
            PTR(f2c)[i].y = ROT_Y(M, VF(PTR(f28)[i].x), VF(PTR(f28)[i].y), VF(PTR(f28)[i].z));
            PTR(f2c)[i].z = ROT_Z(M, VF(PTR(f28)[i].x), VF(PTR(f28)[i].y), VF(PTR(f28)[i].z));
        }
    }
    if (f30) {
        for (i = 0; i < *(volatile unsigned int *)&count; i++) {
            Mat4 *M = &a->mats[b->idx[bones[i][0]]];
            PTR(f34)[i].x = ROT_X(M, VF(PTR(f30)[i].x), VF(PTR(f30)[i].y), VF(PTR(f30)[i].z));
            PTR(f34)[i].y = ROT_Y(M, VF(PTR(f30)[i].x), VF(PTR(f30)[i].y), VF(PTR(f30)[i].z));
            PTR(f34)[i].z = ROT_Z(M, VF(PTR(f30)[i].x), VF(PTR(f30)[i].y), VF(PTR(f30)[i].z));
        }
    }
}
} // namespace fn_002c8a80
#undef PTR
#undef ROT_X
#undef ROT_Y
#undef ROT_Z
#undef VF
#undef XF_X
#undef XF_Y
#undef XF_Z

namespace fn_f7aa76dc {

// 0x002c92f0 FUN_002c92f0 (1000 B): equivalent/0x002c92f0.cpp
// sym: ?FUN_002c92f0@Skin@fn_f7aa76dc@@QAEXPAUMatSet@2@PAURemap@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 56 inputs, branch coverage 14/14)
// FUN_002c92f0 @ 0x002c92f0
void Skin::FUN_002c92f0(MatSet *ms, Remap *rm)
{
    for (unsigned int i = 0; i < count; i++) {
        const float *m = ms->mats[rm->map[idx[i * 4]]].m;
        if (flags & 0x10) {
            dstA[i].x = srcA[i].z * m[8] + srcA[i].y * m[4] + srcA[i].x * m[0];
            dstA[i].y = srcA[i].z * m[9] + srcA[i].y * m[5] + m[1] * srcA[i].x;
            dstA[i].z = srcA[i].z * m[10] + srcA[i].y * m[6] + m[2] * srcA[i].x;
        }
        if (flags & 0x800) {
            dstB[i].x = srcB[i].z * m[8] + srcB[i].y * m[4] + m[0] * srcB[i].x;
            dstB[i].y = srcB[i].z * m[9] + srcB[i].y * m[5] + m[1] * srcB[i].x;
            dstB[i].z = srcB[i].z * m[10] + srcB[i].y * m[6] + m[2] * srcB[i].x;
        }
        if (flags & 0x1000) {
            dstC[i].x = srcC[i].z * m[8] + srcC[i].y * m[4] + m[0] * srcC[i].x;
            dstC[i].y = srcC[i].z * m[9] + srcC[i].y * m[5] + m[1] * srcC[i].x;
            dstC[i].z = srcC[i].z * m[10] + srcC[i].y * m[6] + m[2] * srcC[i].x;
        }
        float w;
        if (weights)
            w = weights[i * 3];
        else
            w = 1.0f;
        const Vec3 *p = &bindPos[i];
        double accX = (m[4] * p->y + m[8] * p->z + m[0] * p->x + m[12]) * w;
        float accY = (float)((m[5] * p->y + m[9] * p->z + m[1] * p->x + m[13]) * w);
        float accZ = (float)((m[6] * p->y + m[10] * p->z + m[2] * p->x + m[14]) * w);
        if (!(w == 1.0f)) {
            const float *W = &weights[i * 3];
            w = W[1];
            const float *m1 = ms->mats[rm->map[idx[i * 4 + 1]]].m;
            p = &bindPos[i];
            accX = accX + (m1[8] * p->z + m1[4] * p->y + p->x * m1[0] + m1[12]) * w;
            double ys = (m1[9] * p->z + m1[1] * p->x + m1[5] * p->y + m1[13]) * w + accY;
            accZ = (float)((m1[10] * p->z + m1[2] * p->x + m1[6] * p->y + m1[14]) * w + accZ);
            w = W[2];
            const float *m2 = ms->mats[rm->map[idx[i * 4 + 2]]].m;
            float tx = (float)((m2[8] * p->z + m2[4] * p->y + p->x * m2[0] + m2[12]) * w + accX);
            accY = (float)((m2[9] * p->z + m2[1] * p->x + m2[5] * p->y + m2[13]) * w + ys);
            accZ = (float)((m2[10] * p->z + m2[2] * p->x + m2[6] * p->y + m2[14]) * w + accZ);
            w = 1.0f - (W[2] + W[0] + W[1]);
            const float *m3 = ms->mats[rm->map[idx[i * 4 + 3]]].m;
            accX = (m3[8] * p->z + m3[4] * p->y + p->x * m3[0] + m3[12]) * w + tx;
            accY = (float)((m3[9] * p->z + m3[1] * p->x + m3[5] * p->y + m3[13]) * w + accY);
            accZ = (float)((m3[10] * p->z + m3[2] * p->x + m3[6] * p->y + m3[14]) * w + accZ);
        }
        dstBlend[i].x = (float)accX;
        dstBlend[i].y = accY;
        dstBlend[i].z = accZ;
    }
}


// 0x002c96e0 FUN_002c96e0 (7050 B): equivalent/0x002c96e0.cpp
// sym: _FUN_002c96e0
// STATUS: equivalent (tools/equiv.py level 3: 483 inputs, branch coverage 327/382, incomplete)
// FUN_002c96e0 @ 0x002c96e0
// equiv-conv: FUN_002c96e0 eax edx esi
extern "C" void FUN_002c96e0(Source_2c96e0* src, unsigned char flag, VertexSink_2c96e0* out)
{
    unsigned count = src->count;
    unsigned short* index = src->index;
    Vec3_2c96e0* p0;
    Vec3_2c96e0* p1;
    if (flag == 1) {
        p0 = src->p2;
        p1 = src->p3;
    } else {
        p0 = src->p0;
        p1 = src->p1;
    }
    unsigned* col0 = src->col0;
    unsigned* col1 = src->col1;
    Vec2_2c96e0* s0 = src->s0;
    Vec2_2c96e0* s1 = src->s1;
    Vec2_2c96e0* s2 = src->s2;
    Vec2_2c96e0* s3 = src->s3;
    unsigned flags = src->flags & 0xfffc7fff;
    Blend_2c96e0* b = src->blend;
    Vec3_2c96e0* q0 = 0;
    Vec3_2c96e0* q1 = 0;
    if (flag == 0) {
        q0 = b->q0;
        q1 = b->q1;
    }
    short* d0 = b->d0;
    short* d1 = b->d1;
    Vec2_2c96e0* r0 = b->r0;
    Vec2_2c96e0* r1 = b->r1;
    Vec2_2c96e0* r2 = b->r2;
    Vec2_2c96e0* r3 = b->r3;
    unsigned i;

    // jump table 0x2cb26c / byte table 0x2cb284: flags-0x2001 = 0x00, 0x0f, 0x10, 0x1f, 0x20 (everything else: the generic loop)
    switch (flags) {
    case 0x2020:
        if (d0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[index[i]], &d0[index[i] * 4]);
                    { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = AddColor(col0[index[i]], &d0[index[i] * 4]);
                { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->color[0] = col0[index[i]];
                { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = index[i];
            unsigned c = col0[v];
            *out->pos = p0[v];
            out->color[0] = c;
            out->FUN_0008ef00();
        }
        return;
    case 0x2010:
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float z = p1[index[i]].z + q1[index[i]].z; float y = p1[index[i]].y + q1[index[i]].y; float x = p1[index[i]].x + q1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float z = p1[index[i]].z + q1[index[i]].z; float y = p1[index[i]].y + q1[index[i]].y; float x = p1[index[i]].x + q1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float z = p1[index[i]].z; float y = p1[index[i]].y; float x = p1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = index[i];
            *out->pos = p0[v];
            *out->normal = p1[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2001:
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float y = s0[index[i]].y; float x = s0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = index[i];
            *out->pos = p0[v];
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2021:
        if (d0) {
            if (r0) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->color[0] = AddColor(col0[index[i]], &d0[index[i] * 4]);
                        { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                        { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                        out->FUN_0008ef00();
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[index[i]], &d0[index[i] * 4]);
                    { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[index[i]], &d0[index[i] * 4]);
                    { float y = s0[index[i]].y; float x = s0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = AddColor(col0[index[i]], &d0[index[i] * 4]);
                { float y = s0[index[i]].y; float x = s0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = col0[index[i]];
                    { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = col0[index[i]];
                { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->color[0] = col0[index[i]];
                { float y = s0[index[i]].y; float x = s0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = index[i];
            unsigned c = col0[v];
            *out->pos = p0[v];
            out->color[0] = c;
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2011:
        if (r0) {
            if (q1) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                        { float z = p1[index[i]].z + q1[index[i]].z; float y = p1[index[i]].y + q1[index[i]].y; float x = p1[index[i]].x + q1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                        { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                        out->FUN_0008ef00();
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[index[i]].z + q1[index[i]].z; float y = p1[index[i]].y + q1[index[i]].y; float x = p1[index[i]].x + q1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[index[i]].z; float y = p1[index[i]].y; float x = p1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[index[i]].y + r0[index[i]].y; float x = s0[index[i]].x + r0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[index[i]].z; float y = p1[index[i]].y; float x = p1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[index[i]].y; float x = s0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[index[i]].z + q1[index[i]].z; float y = p1[index[i]].y + q1[index[i]].y; float x = p1[index[i]].x + q1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[index[i]].y; float x = s0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[index[i]].z + q1[index[i]].z; float y = p1[index[i]].y + q1[index[i]].y; float x = p1[index[i]].x + q1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[index[i]].z; float y = p0[index[i]].y; float x = p0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float y = s0[index[i]].y; float x = s0[index[i]].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[index[i]].z; float y = p1[index[i]].y; float x = p1[index[i]].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[index[i]].z + q0[index[i]].z; float y = p0[index[i]].y + q0[index[i]].y; float x = p0[index[i]].x + q0[index[i]].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = index[i];
            *out->pos = p0[v];
            *out->normal = p1[v];
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    }

    for (i = 0; i < count; i++) {
        if (p1)
            PutNormal(out, &p1[index[i]], q1 ? &q1[index[i]] : 0);
        if (col0) PutColor(&out->color[0], col0, d0, index[i]);
        if (col1) PutColor(&out->color[1], col1, d1, index[i]);
        if (s0) PutUv(out, 0, &s0[index[i]], r0 ? &r0[index[i]] : 0);
        if (s1) PutUv(out, 1, &s1[index[i]], r1 ? &r1[index[i]] : 0);
        if (s2) PutUv(out, 2, &s2[index[i]], r2 ? &r2[index[i]] : 0);
        if (s3) PutUv(out, 3, &s3[index[i]], r3 ? &r3[index[i]] : 0);
        PutPos(out, &p0[index[i]], q0 ? &q0[index[i]] : 0);
        out->FUN_0008ef00();
    }
}


// 0x002cb2b0 FUN_002cb2b0 (7735 B): equivalent/0x002cb2b0.cpp
// sym: _FUN_002cb2b0
// STATUS: equivalent (tools/equiv.py level 3: 472 inputs, branch coverage 307/382, incomplete)
// FUN_002cb2b0 @ 0x002cb2b0
// equiv-conv: FUN_002cb2b0 ecx stack esi
extern "C" void FUN_002cb2b0(Source_2cb2b0* src, unsigned char flag, VertexSink_2cb2b0* out)
{
    unsigned count = src->count;
    Vec3_2cb2b0* p0;
    Vec3_2cb2b0* p1;
    if (flag == 1) {
        p0 = src->p2;
        p1 = src->p3;
    } else {
        p0 = src->p0;
        p1 = src->p1;
    }
    unsigned* col0 = src->col0;
    unsigned* col1 = src->col1;
    Vec2_2cb2b0* s0 = src->s0;
    Vec2_2cb2b0* s1 = src->s1;
    Vec2_2cb2b0* s2 = src->s2;
    Vec2_2cb2b0* s3 = src->s3;
    unsigned flags = src->flags & 0xfffc7fff;
    Blend_2cb2b0* b = src->blend;
    Vec3_2cb2b0* q0 = 0;
    Vec3_2cb2b0* q1 = 0;
    if (flag == 0) {
        q0 = b->q0;
        q1 = b->q1;
    }
    short* d0 = b->d0;
    short* d1 = b->d1;
    Vec2_2cb2b0* r0 = b->r0;
    Vec2_2cb2b0* r1 = b->r1;
    Vec2_2cb2b0* r2 = b->r2;
    Vec2_2cb2b0* r3 = b->r3;
    unsigned i;

    // jump table 0x2cd0e8 / byte table 0x2cd100: flags-0x2001 = 0x00, 0x0f, 0x10, 0x1f, 0x20 (everything else: the generic loop)
    switch (flags) {
    case 0x2020:
        if (d0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[i], &d0[i * 4]);
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = AddColor(col0[i], &d0[i * 4]);
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->color[0] = col0[i];
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            unsigned c = col0[v];
            *out->pos = p0[v];
            out->color[0] = c;
            out->FUN_0008ef00();
        }
        return;
    case 0x2010:
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            *out->pos = p0[v];
            *out->normal = p1[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2001:
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            *out->pos = p0[v];
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2021:
        if (d0) {
            if (r0) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->color[0] = AddColor(col0[i], &d0[i * 4]);
                        { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                        { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                        out->FUN_0008ef00();
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[i], &d0[i * 4]);
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = AddColor(col0[i], &d0[i * 4]);
                    { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = AddColor(col0[i], &d0[i * 4]);
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->color[0] = col0[i];
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->color[0] = col0[i];
                { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->color[0] = col0[i];
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            unsigned c = col0[v];
            *out->pos = p0[v];
            out->color[0] = c;
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    case 0x2011:
        if (r0) {
            if (q1) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                        { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                        { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                        out->FUN_0008ef00();
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[i].y + r0[i].y; float x = s0[i].x + r0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                    { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                    { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                    out->FUN_0008ef00();
                }
                return;
            }
            for (i = 0; i < count; i++) {
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[i].z + q1[i].z; float y = p1[i].y + q1[i].y; float x = p1[i].x + q1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z; float y = p0[i].y; float x = p0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                { float y = s0[i].y; float x = s0[i].x; out->uv->x = x; out->uv->y = y; }
                { float z = p1[i].z; float y = p1[i].y; float x = p1[i].x; out->normal->x = x; out->normal->y = y; out->normal->z = z; }
                { float z = p0[i].z + q0[i].z; float y = p0[i].y + q0[i].y; float x = p0[i].x + q0[i].x; out->pos->x = x; out->pos->y = y; out->pos->z = z; }
                out->FUN_0008ef00();
            }
            return;
        }
        for (i = 0; i < count; i++) {
            unsigned v = i;
            *out->pos = p0[v];
            *out->normal = p1[v];
            *out->uv = s0[v];
            out->FUN_0008ef00();
        }
        return;
    }

    for (i = 0; i < count; i++) {
        if (p1)
            PutNormal(out, &p1[i], q1 ? &q1[i] : 0);
        if (col0) PutColor(&out->color[0], col0, d0, i);
        if (col1) PutColor(&out->color[1], col1, d1, i);
        if (s0) PutUv(out, 0, &s0[i], r0 ? &r0[i] : 0);
        if (s1) PutUv(out, 1, &s1[i], r1 ? &r1[i] : 0);
        if (s2) PutUv(out, 2, &s2[i], r2 ? &r2[i] : 0);
        if (s3) PutUv(out, 3, &s3[i], r3 ? &r3[i] : 0);
        PutPos(out, &p0[i], q0 ? &q0[i] : 0);
        out->FUN_0008ef00();
    }
}


// 0x002cd130 FUN_002cd130 (6817 B): equivalent/0x002cd130.cpp
// sym: ?FUN_002cd130@fn_f7aa76dc@@YAXPAUSource_2cd130@1@EPAUVertexSink_2cd130@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 562 inputs, branch coverage 322/376, incomplete)
// FUN_002cd130 @ 0x002cd130
// equiv-conv: FUN_002cd130 eax edx esi
void FUN_002cd130(Source_2cd130* src, unsigned char flag, VertexSink_2cd130* out)
{
    unsigned count = src->count;
    unsigned short* index = src->index;
    Vec3_2cd130* p0;
    Vec3_2cd130* p1;
    Vec3_2cd130* t0;
    Vec3_2cd130* t1;
    if (flag == 1) {
        p0 = src->p2;
        p1 = src->p3;
        t0 = src->t1;
        t1 = src->t3;
    } else {
        p0 = src->p0;
        p1 = src->p1;
        t0 = src->t0;
        t1 = src->t2;
    }
    unsigned* col0 = src->col0;
    unsigned* col1 = src->col1;
    Vec2_2cd130* s0 = src->s0;
    Vec2_2cd130* s1 = src->s1;
    Vec2_2cd130* s2 = src->s2;
    Vec2_2cd130* s3 = src->s3;
    unsigned flags = src->flags & 0xfffc7fff;
    Blend_2cd130* b = src->blend;
    Vec3_2cd130* q0 = 0;
    Vec3_2cd130* q1 = 0;
    if (flag == 0) {
        q0 = b->q0;
        q1 = b->q1;
    }
    short* d0 = b->d0;
    short* d1 = b->d1;
    Vec2_2cd130* r0 = b->r0;
    Vec2_2cd130* r1 = b->r1;
    Vec2_2cd130* r2 = b->r2;
    Vec2_2cd130* r3 = b->r3;
    unsigned i;

    switch (flags) {
    case 0x2020:
        if (d0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[index[i]], 0);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColor(&p0[index[i]], col0[index[i]]);
        }
        return;
    case 0x2010:
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetNormal(p1[index[i]]);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormal(&p0[index[i]], &p1[index[i]]);
        }
        return;
    case 0x2001:
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[index[i]], 0);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosUv(&p0[index[i]], &s0[index[i]]);
        }
        return;
    case 0x2021:
        if (d0) {
            if (r0) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                        out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                        out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetPos(p0[index[i]]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                    out->SetUv(s0[index[i]], 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[index[i]], &d0[index[i] * 4]), 0);
                out->SetUv(s0[index[i]], 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(col0[index[i]], 0);
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(col0[index[i]], 0);
                out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[index[i]], 0);
                out->SetUv(s0[index[i]], 0);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColorUv(&p0[index[i]], col0[index[i]], &s0[index[i]]);
        }
        return;
    case 0x2011:
        if (r0) {
            if (q1) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                        out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                        out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                    out->SetPos(p0[index[i]]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                    out->SetNormal(p1[index[i]]);
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[index[i]], r0[index[i]]), 0);
                out->SetNormal(p1[index[i]]);
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(s0[index[i]], 0);
                    out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                    out->SetPos(Add3(p0[index[i]], q0[index[i]]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(s0[index[i]], 0);
                out->SetNormal(Add3(p1[index[i]], q1[index[i]]));
                out->SetPos(p0[index[i]]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[index[i]], 0);
                out->SetNormal(p1[index[i]]);
                out->SetPos(Add3(p0[index[i]], q0[index[i]]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormalUv(&p0[index[i]], &p1[index[i]], &s0[index[i]]);
        }
        return;
    }

    for (i = 0; i < count; i++) {
        if (p1)
            out->SetNormal(q1 ? Add3(p1[index[i]], q1[index[i]]) : p1[index[i]]);
        if (t0)
            out->SetExtra0(t0[index[i]]);
        if (t1)
            out->SetExtra1(t1[index[i]]);
        if (col0)
            out->SetColor(d0 ? AddColor(col0[index[i]], &d0[index[i] * 4]) : col0[index[i]], 0);
        if (col1)
            out->SetColor(d1 ? AddColor(col1[index[i]], &d1[index[i] * 4]) : col1[index[i]], 1);
        if (s0)
            out->SetUv(r0 ? Add2(s0[index[i]], r0[index[i]]) : s0[index[i]], 0);
        if (s1)
            out->SetUv(r1 ? Add2(s1[index[i]], r1[index[i]]) : s1[index[i]], 1);
        if (s2)
            out->SetUv(r2 ? Add2(s2[index[i]], r2[index[i]]) : s2[index[i]], 2);
        if (s3)
            out->SetUv(r3 ? Add2(s3[index[i]], r3[index[i]]) : s3[index[i]], 3);
        out->SetPos(q0 ? Add3(p0[index[i]], q0[index[i]]) : p0[index[i]]);
    }
}


// 0x002cec10 FUN_002cec10 (7087 B): equivalent/0x002cec10.cpp
// sym: _FUN_002cec10
// STATUS: equivalent (tools/equiv.py level 3: 604 inputs, branch coverage 302/376, incomplete)
// FUN_002cec10 @ 0x002cec10
// equiv-conv: FUN_002cec10 ecx edx esi
extern "C" void FUN_002cec10(Source_2cec10* src, unsigned char flag, VertexSink_2cec10* out)
{
    unsigned count = src->count;
    Vec3_2cec10* p0;
    Vec3_2cec10* p1;
    Vec3_2cec10* t0;
    Vec3_2cec10* t1;
    if (flag == 1) {
        p0 = src->p2;
        p1 = src->p3;
        t0 = src->t1;
        t1 = src->t3;
    } else {
        p0 = src->p0;
        p1 = src->p1;
        t0 = src->t0;
        t1 = src->t2;
    }
    unsigned* col0 = src->col0;
    unsigned* col1 = src->col1;
    Vec2_2cec10* s0 = src->s0;
    Vec2_2cec10* s1 = src->s1;
    Vec2_2cec10* s2 = src->s2;
    Vec2_2cec10* s3 = src->s3;
    unsigned flags = src->flags & 0xfffc7fff;
    Blend_2cec10* b = src->blend;
    Vec3_2cec10* q0 = 0;
    Vec3_2cec10* q1 = 0;
    if (flag == 0) {
        q0 = b->q0;
        q1 = b->q1;
    }
    short* d0 = b->d0;
    short* d1 = b->d1;
    Vec2_2cec10* r0 = b->r0;
    Vec2_2cec10* r1 = b->r1;
    Vec2_2cec10* r2 = b->r2;
    Vec2_2cec10* r3 = b->r3;
    unsigned i;

    switch (flags) {
    case 0x2020:
        if (d0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[i], 0);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColor(&p0[i], col0[i]);
        }
        return;
    case 0x2010:
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetNormal(Add3(p1[i], q1[i]));
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetNormal(Add3(p1[i], q1[i]));
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetNormal(p1[i]);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormal(&p0[i], &p1[i]);
        }
        return;
    case 0x2001:
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[i], r0[i]), 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[i], 0);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosUv(&p0[i], &s0[i]);
        }
        return;
    case 0x2021:
        if (d0) {
            if (r0) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                        out->SetUv(Add2(s0[i], r0[i]), 0);
                        out->SetPos(Add3(p0[i], q0[i]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetPos(p0[i]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                    out->SetUv(s0[i], 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(AddColor(col0[i], &d0[i * 4]), 0);
                out->SetUv(s0[i], 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (r0) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetColor(col0[i], 0);
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetColor(col0[i], 0);
                out->SetUv(Add2(s0[i], r0[i]), 0);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetColor(col0[i], 0);
                out->SetUv(s0[i], 0);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosColorUv(&p0[i], col0[i], &s0[i]);
        }
        return;
    case 0x2011:
        if (r0) {
            if (q1) {
                if (q0) {
                    for (i = 0; i < count; i++) {
                        out->SetUv(Add2(s0[i], r0[i]), 0);
                        out->SetNormal(Add3(p1[i], q1[i]));
                        out->SetPos(Add3(p0[i], q0[i]));
                    }
                    return;
                }
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetNormal(Add3(p1[i], q1[i]));
                    out->SetPos(p0[i]);
                }
                return;
            }
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(Add2(s0[i], r0[i]), 0);
                    out->SetNormal(p1[i]);
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(Add2(s0[i], r0[i]), 0);
                out->SetNormal(p1[i]);
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q1) {
            if (q0) {
                for (i = 0; i < count; i++) {
                    out->SetUv(s0[i], 0);
                    out->SetNormal(Add3(p1[i], q1[i]));
                    out->SetPos(Add3(p0[i], q0[i]));
                }
                return;
            }
            for (i = 0; i < count; i++) {
                out->SetUv(s0[i], 0);
                out->SetNormal(Add3(p1[i], q1[i]));
                out->SetPos(p0[i]);
            }
            return;
        }
        if (q0) {
            for (i = 0; i < count; i++) {
                out->SetUv(s0[i], 0);
                out->SetNormal(p1[i]);
                out->SetPos(Add3(p0[i], q0[i]));
            }
            return;
        }
        for (i = 0; i < count; i++) {
            out->SetPosNormalUv(&p0[i], &p1[i], &s0[i]);
        }
        return;
    }

    for (i = 0; i < count; i++) {
        if (p1)
            out->SetNormal(q1 ? Add3(p1[i], q1[i]) : p1[i]);
        if (t0)
            out->SetExtra0(t0[i]);
        if (t1)
            out->SetExtra1(t1[i]);
        if (col0)
            out->SetColor(d0 ? AddColor(col0[i], &d0[i * 4]) : col0[i], 0);
        if (col1)
            out->SetColor(d1 ? AddColor(col1[i], &d1[i * 4]) : col1[i], 1);
        if (s0)
            out->SetUv(r0 ? Add2(s0[i], r0[i]) : s0[i], 0);
        if (s1)
            out->SetUv(r1 ? Add2(s1[i], r1[i]) : s1[i], 1);
        if (s2)
            out->SetUv(r2 ? Add2(s2[i], r2[i]) : s2[i], 2);
        if (s3)
            out->SetUv(r3 ? Add2(s3[i], r3[i]) : s3[i], 3);
        out->SetPos(q0 ? Add3(p0[i], q0[i]) : p0[i]);
    }
}


// 0x002d0800 FUN_002d0800 (99 B): matches/0x002d0800.cpp
// sym: ?Clear@VertexOffsetList@fn_f7aa76dc@@QAEXXZ
void VertexOffsetList::Clear() {
atexit:;
    vptr = &hulk_at_0042efb0;
    ReleaseThing((void*)a);
    ReleaseThing((void*)b);
    int* p = c;
    int n = 4;
    do {
        ReleaseThing((void*)*(hulk_intptr*)p);
        ++p;
        --n;
    } while (n);
    int** q = d;
    n = 2;
    do {
        if (*q)
            ReleaseThing((char*)*q - 4);
        ++q;
        --n;
    } while (n);
    vptr = &ref_vftable_2d0800;
}

} // namespace fn_f7aa76dc

// 0x002d0870 pure3d::VertexList::vfunc_2 (30 B): matches/0x002d0870.cpp
// sym: ??_GVertexList@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::VertexList::~VertexList() {}

