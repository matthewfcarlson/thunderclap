// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a5150..0x002a6cb0 (kind game, layer engine, confidence high), dominant class pure3d::ProceduralVertexAnimController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fa65e9c0 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fa65e9c0 {} using namespace fn_fa65e9c0;
namespace fn_fa65e9c0 {
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "engine/pure3d.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fa65e9c0 {
struct Vec3_2a5290 { float x, y, z; };
struct Vec2_2a5290 { float x, y; };
struct Track {
    char pad0[0xc];
    int count;
    char pad10[8];
    Vec3_2a5290 *pos;
    char pad1c[0x1c];
    Vec2_2a5290 *uv[4];
};
extern "C" void __cdecl FUN_002a5260();
extern "C" char DAT_0042d9dc[];
class Controller_2a5420 {
  public:
    char pad[0x40];
    int a;
    int pad44;
    int b;
    int c;
    int d;
    int e;
};
extern "C" void __fastcall FUN_00284cd0(void*);
struct Vec2_2a54e0 {
    float x;
    float y;
};
struct Node {
    virtual void v0();
    virtual void v1();
    virtual unsigned GetId();
    virtual void v3();
    virtual void Apply(float t, float *out);
    int pad4;
    unsigned sub;
};
struct NodeList_2a58e0 {
    char pad0[0x14];
    int count;
};
struct Source_2a58e0 {
};
class Target_2a58e0 {
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
    virtual float Eval();
    virtual void v11();
    virtual void v12();
    virtual float GetTime();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Source_2a58e0 *GetSource();
};
extern "C++" __declspec(nothrow) void __cdecl FUN_002a5570(float, void *, void *, unsigned int, void *);
struct Frame_2a58e0 {
    float time;
    float timeCopy;
    float one;
    float vec[3];
    float zero;
    float half;
    float fifth;
};
struct Vec3_2a5a20 {
    float x, y, z;
    float FUN_0022d110();
};
struct Vec2_2a5a20 {
    float u, v;
};
struct Mesh_2a5a20 {
    char pad00[0xc];
    int count;
    char pad10[8];
    Vec3_2a5a20 *pos;
    char pad1c[0x38 - 0x1c];
    Vec2_2a5a20 *uv[4];
    unsigned char *color;
};
struct WaveParams {
    float speed;
    float cx, cy, cz;
    float dirx, diry, dirz;
    float radius;
    float falloff;
    float displace;
    float k28;
    float k2c;
    float k30;
    float uvAmp;
};
union FloatBits_2a5a20 {
    float f;
    unsigned int u;
};
static inline int Clamp255(int v)
{
    if (v < 0) {
        return 0;
    }
    if (v > 255) {
        return 255;
    }
    return v;
}
struct Item_2a5df0 {
    virtual void v0();
    virtual void v1();
    virtual int GetType();
    virtual void v3();
    virtual void v4(float time, float *out);
    int pad4;
    int subType;
};
struct V3_2a5df0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct List_2a5df0 {
    char pad0[0x14];
    int count;
};
struct Clips {
};
struct Anim_2a5df0 {
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
    virtual float v10();
    virtual void v11();
    virtual void v12();
    virtual float v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Clips *v25();
};
void __cdecl FUN_002a5a20(float v, int a2, int a3, int a4, float *params);
struct Frame_2a5df0 {
    float t;        // time; a TIME item overrides it; divides the result
    float t0;       // time as read at the start: passed to every item
    float f[14];
};
struct Parameter_2a6500 {
 virtual void v0(); virtual void v1(); virtual unsigned int type();
 unsigned int pad4; unsigned int name;
};
struct List_2a6500 {
 char pad[20]; int count;
};
struct Container_2a6500 {  };
struct Source_2a6500 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual float time();
 virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual Container_2a6500* container();
};
struct Values_2a6500 { float speed, p, c, a, u; };
extern int __cdecl FUN_002a5fd0(float, unsigned int, unsigned int, unsigned int, Values_2a6500*);
class SimpleFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void vfunc_24(int, int, int);
};
struct VertexAnimData {
    char pad0[0x1c];
    unsigned int tag;
};
class ProceduralVertexAnimController : public SimpleFrameController {
  public:
    virtual void _m_vf25();
    virtual int vfunc_26(void*);
    char _m_pad_4[0x38];
    VertexAnimData *data;
    char _m_pad_40[0x10];
    void (__cdecl *updateFn)();
    void vfunc_24(int a, int b, int c);
};
void __cdecl FUN_002a58e0();
void __cdecl FUN_002a5df0();
void __cdecl FUN_002a6500();
void __cdecl FUN_002a6610();
struct Item_2a67e0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual unsigned char Check();
    char pad[0x4c];
    int v50;
    char gap[8];
    int v5c;
};
struct Entry_2a67e0 {
    Item_2a67e0* item;
    char pad[12];
};
struct Vec_2a67e0 {
    Entry_2a67e0* begin;
    Entry_2a67e0* end;
    hulk_intptr size() const { return end - begin; }
};
struct Bag_2a67e0 {
    char pad[0x48];
    Vec_2a67e0 entries;
};
class Owner_2a67e0 {
  public:
    char pad[0x40];
    Bag_2a67e0* bag;
    char gap[8];
    int* ids;
    void(__cdecl* callback)(Owner_2a67e0*, int, int, int, int);
    void Run();
};
struct Ent_2a6840 {
    char pad0[0x4c];
    int f50;
    char pad1[0x5c - 0x54];
    int f5c;
    char pad2[0x68 - 0x60];
    int f68;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5();
};
struct Slot_2a6840 { Ent_2a6840 *ent; int pad[3]; };
struct Group_2a6840 { char pad[0x48]; Slot_2a6840 *begin; Slot_2a6840 *end; };
struct Target_2a6840 {
    char pad0[0x44];
    Group_2a6840 *group;
    int pad48;
    int *values;
    void (__cdecl *callback)(Target_2a6840 *self, int val, int a, int b, int c);
    void FUN_002a6840();
};
class Item_2a68b0 {
  public:
    virtual void A();
    virtual void Release();
};
void Free_0008d340(void*);
class ProceduralVertexAnimController_2a68b0 {
  public:
    char pad[0x40];
    int x40;
    int x44;
    unsigned int count;
    Item_2a68b0** items;
    void Run();
};
class ProceduralVertexAnimController_2a6910 {
  public:
    virtual void Fnf_00038290();
    void Cleanup1_002a68b0();
    void Cleanup2_00285800();
    ~ProceduralVertexAnimController_2a6910();
    int mData;
};
struct TypeInfo_2a6930 { unsigned int value; };
extern TypeInfo_2a6930 DAT_004cf8e8, DAT_004cf908;
struct Resource_2a6930 { char pad[0x5c]; void* data; };
struct Entry_2a6930 { void* object; char pad[12]; };
struct Source_2a6930 { char pad[0x48]; Entry_2a6930* begin; Entry_2a6930* end; };
struct VertexList_nv_2a6930 {
    pure3d::VertexList* FUN_002c8730(void*);
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" Resource_2a6930* __cdecl FUN_00344e74(void*, int, TypeInfo_2a6930*, TypeInfo_2a6930*, int);
struct ProceduralVertexAnimController_2a6930 { char pad[0x40]; Source_2a6930* source; unsigned int field44; unsigned int count; pure3d::VertexList** items; void FUN_002a68b0(); void target(Source_2a6930*); };
struct ProceduralVertexAnimController_nv_2a6b70 {
    void h1_002a67e0();
    void h2_002a6840();
};
extern int hulk_at_0042d9dc;
struct ProceduralVertexAnimController_2a6b90 {
    void* m_vptr;
    void base1_dtor_002a68b0();
    void base2_dtor_00285800();
    void* scalar_dtor(unsigned char flags);
};
typedef unsigned int U_2a6c60;
extern char hulk_at_0048f610;
struct ProceduralVertexAnimController_nv_2a6c60 {
    void Finish_002a6930(U_2a6c60);
};

} // namespace fn_fa65e9c0

// 0x002a5150 FUN_002a5150 (104 B): matches/0x002a5150.cpp [wrapped: conflict: pure3d::DrawablePrimitive]
// sym: ??0DrawablePrimitive@pure3d@fn_002a5150@@QAE@ABV012@@Z
namespace fn_002a5150 {
// FUN_002a5150 @ 0x002a5150
// equiv-map: ??0Resource@@QAE@XZ = 0x0027b070
class Entity_2a5150 {
public:
    Entity_2a5150();
    virtual void vfunc_0();
    int refs;
};
struct Sub_2a5150 {
    char data[8];
    void FUN_0027af70(const Sub_2a5150* other);
};
namespace pure3d {
class DrawablePrimitive : public Entity_2a5150 {
public:
    DrawablePrimitive(const DrawablePrimitive& src);
    virtual void vfunc_0();
    Sub_2a5150 sub;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
};
DrawablePrimitive::DrawablePrimitive(const DrawablePrimitive& src) : Entity_2a5150() {
    f10 = src.f10;
    sub.FUN_0027af70(&src.sub);
    f14 = src.f14;
    f18 = src.f18;
    f1c = src.f1c;
    f20 = src.f20;
    f24 = src.f24;
    f28 = src.f28;
    f2c = src.f2c;
    f30 = src.f30;
    f34 = src.f34;
    f38 = src.f38;
}
}
} // namespace fn_002a5150

namespace fn_fa65e9c0 {

// 0x002a5260 FUN_002a5260 (1 B): matches/0x002a5260.cpp
// sym: _FUN_002a5260
extern "C" void FUN_002a5260() {}


// 0x002a5290 FUN_002a5290 (384 B): equivalent/0x002a5290.cpp
// sym: _FUN_002a5290 @df8bae6804a7 @weee5497579f2
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 18/18; --wine 73 inputs)
// FUN_002a5290 @ 0x002a5290
extern "C" void FUN_002a5290(float t, void *a, void *b, unsigned int flags, float *c)
{
    Vec2_2a5290 *srcUv[4];
    Vec2_2a5290 *dstUv[4];
    srcUv[0] = ((Track *)a)->uv[0];
    dstUv[0] = ((Track *)b)->uv[0];
    srcUv[1] = ((Track *)a)->uv[1];
    dstUv[1] = ((Track *)b)->uv[1];
    srcUv[2] = ((Track *)a)->uv[2];
    dstUv[2] = ((Track *)b)->uv[2];
    srcUv[3] = ((Track *)a)->uv[3];
    dstUv[3] = ((Track *)b)->uv[3];
    Vec3_2a5290 *srcPos = ((Track *)a)->pos;
    Vec3_2a5290 *dstPos = ((Track *)b)->pos;
    int n = ((Track *)a)->count;
    if (n == 0)
        return;
    unsigned int moveFlag = flags & 0x10;
    do {
        n--;
        if (moveFlag != 0) {
            dstPos[n].x = srcPos[n].x + t * c[0] * c[2];
            dstPos[n].y = srcPos[n].y + t * c[0] * c[3];
            dstPos[n].z = srcPos[n].z + t * c[0] * c[4];
        }
        for (int i = 0; i < 4; i++) {
            if ((((unsigned int*)&DAT_0042d9c0)[i] & flags) == 0)
                continue;
            if (srcUv[i] == 0)
                continue;
            if (dstUv[i] == 0)
                continue;
            hulk_freg uu = t * c[1];   // `fst [temp]`: the first fmod gets the register, the second the stored float
            float ur = (float)uu;
            float f1 = (float)fmod(uu * c[5], 1.0);
            hulk_freg f2 = fmod(ur * c[6], 1.0);
            hulk_freg g1 = f1;
            if (f1 < 0.0)
                g1 = 1.0f - f1;
            if (f2 < 0.0)
                f2 = 1.0f - f2;
            dstUv[i][n].x = g1 + srcUv[i][n].x;
            dstUv[i][n].y = f2 + srcUv[i][n].y;
        }
    } while (n != 0);
}


// 0x002a5420 FUN_002a5420 (36 B): matches/0x002a5420.cpp
// sym: ?Target@fn_fa65e9c0@@YIPAVController_2a5420@1@PAV21@@Z
Controller_2a5420* __fastcall Target(Controller_2a5420* self) {
    FUN_00284cd0((void*)(self));
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4c) = 0;
    *(hulk_intptr*)self = ((hulk_intptr)DAT_0042d9dc);
    *(hulk_intptr*)((char*)self + 0x50) = ((hulk_intptr)(void (__cdecl*)())&FUN_002a5260);
    return self;
}

} // namespace fn_fa65e9c0

// 0x002a5450 pure3d::ProceduralVertexAnimController::vfunc_3 (3 B): matches/0x002a5450.cpp
// sym: ?vfunc_3@ProceduralVertexAnimController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ProceduralVertexAnimController::vfunc_3() {
    return true;
}

namespace fn_fa65e9c0 {

// 0x002a5460 pure3d::ProceduralVertexAnimController::vfunc_26 (28 B): matches/0x002a5460.cpp
// sym: ?vfunc_26@ProceduralVertexAnimController@fn_fa65e9c0@@UAEHPAX@Z
int ProceduralVertexAnimController::vfunc_26(void* p) {
    return p && *reinterpret_cast<int*>((char*)p + 0x28) > 0;
}


// 0x002a54e0 FUN_002a54e0 (83 B): matches/0x002a54e0.cpp
// sym: ?Vec2Normalize@fn_fa65e9c0@@YIMPAUVec2_2a54e0@1@@Z
// data: reciprocal = DAT_003f32dc, threshold_2a54e0 = DAT_004275c4, zero_2a54e0 = DAT_003f32e0
hulk_freg __fastcall Vec2Normalize(Vec2_2a54e0* v) {
    hulk_freg n = v->x * v->x + v->y * v->y;
    if (n >= (*(float*)&DAT_004275c4)) {
        hulk_freg r = (*(float*)&DAT_003f32dc) / (hulk_freg)sqrt(n);
        v->x *= r;
        v->y *= r;
        return (*(float*)&DAT_003f32dc) / r;
    }
    v->y = 0.0f;
    hulk_freg z = (*(float*)&DAT_003f32e0);
    v->x = 0.0f;
    return z;
}

} // namespace fn_fa65e9c0

// 0x002a5570 FUN_002a5570 (872 B): equivalent/0x002a5570.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_002a5570 @5d6d1f086552 @w21264fddd06f
namespace fn_002a5570 {
// STATUS: equivalent (tools/equiv.py level 3: 146 inputs, branch coverage 38/38)
// FUN_002a5570 @ 0x002a5570


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double cos(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V2_2a5570 {
    float x, y;
};

struct V3_2a5570 {
    float x, y, z;
};

struct Mesh_2a5570 {
    char pad00[0xc];
    unsigned int count;
    char pad10[8];
    V3_2a5570 *verts;
    char pad1c[0x38 - 0x1c];
    V2_2a5570 *uv[4];
};

struct Ripple {
    float speed;
    float cx;
    float cy;
    float cz;
    float radius;
    float ampA;
    float ampB;
};


static float Smooth(float w)
{
    if (w <= 0.0f)
        return 0.0f;
    if (w >= 1.0f)
        return 1.0f;
    return (3.0f - 2.0f * w) * w * w;
}

extern "C" void __cdecl FUN_002a5570(float t, void *a, void *b, unsigned int mask, void * p_)
{
    Ripple * p = (Ripple *)p_;
    unsigned int n = ((Mesh_2a5570 *)a)->count;
    V3_2a5570 *bv = ((Mesh_2a5570 *)b)->verts;
    V3_2a5570 *av = ((Mesh_2a5570 *)a)->verts;
    V2_2a5570 *srcUv[4];
    V2_2a5570 *dstUv[4];
    srcUv[0] = ((Mesh_2a5570 *)a)->uv[0];
    dstUv[0] = ((Mesh_2a5570 *)b)->uv[0];
    srcUv[1] = ((Mesh_2a5570 *)a)->uv[1];
    dstUv[1] = ((Mesh_2a5570 *)b)->uv[1];
    srcUv[2] = ((Mesh_2a5570 *)a)->uv[2];
    dstUv[2] = ((Mesh_2a5570 *)b)->uv[2];
    srcUv[3] = ((Mesh_2a5570 *)a)->uv[3];
    dstUv[3] = ((Mesh_2a5570 *)b)->uv[3];
    volatile float phase = t * p->speed * (*(float*)&DAT_0042d9a4);
    if (n == 0)
        return;

    unsigned int vflag = mask & 0x10;
    unsigned int i = n;
    do {
        i--;
        if (vflag) {
            volatile float w = 1.0f;
            hulk_freg dx = av[i].x - p->cx;
            hulk_freg dy = av[i].y - p->cy;
            volatile float dz = av[i].z - p->cz;
            if (p->radius > 0.0) {
                double d = sqrt((double)((dy * dy + dz * dz) + dx * dx));
                hulk_freg r = (hulk_freg)(p->radius - d);
                if (!(0.0f < r))
                    r = 0.0f;
                w = r / p->radius;
            }
            volatile float angle = dx + phase;
            double X = Smooth(w) * (cos((double)angle) * p->ampA);
            angle = dz + phase;
            double Z = Smooth(w) * (sin((double)angle) * p->ampA);
            bv[i].x = (hulk_freg)(X + av[i].x);
            bv[i].z = (hulk_freg)(Z + av[i].z);
        }
        for (int j = 0; j < 4; j++) {
            if (!(((unsigned int*)&DAT_0042d9c0)[j] & mask))
                continue;
            V2_2a5570 *src = srcUv[j];
            if (!src)
                continue;
            V2_2a5570 *dst = dstUv[j];
            if (!dst)
                continue;
            volatile float w = 1.0f;
            volatile float du = src[i].x - p->cx;
            volatile float dv = src[i].y - p->cy;
            if (p->radius > 0.0) {
                double d = sqrt((double)(dv * dv + du * du));
                hulk_freg r = (hulk_freg)(p->radius - d);
                if (!(0.0f < r))
                    r = 0.0f;
                w = r / p->radius;
            }
            volatile float angle = du + phase;
            double X = Smooth(w) * (cos((double)angle) * p->ampB);
            angle = dv + phase;
            double Z = Smooth(w) * (sin((double)angle) * p->ampB);
            dst[i].x = (hulk_freg)(X + src[i].x);
            dst[i].y = (hulk_freg)(Z + src[i].y);
        }
    } while (i != 0);
}
} // namespace fn_002a5570

namespace fn_fa65e9c0 {

// 0x002a58e0 FUN_002a58e0 (317 B): equivalent/0x002a58e0.cpp
// sym: ?FUN_002a58e0@fn_fa65e9c0@@YAXPAVTarget_2a58e0@1@0HH@Z @bd13e36a1b3a @wc2f6092aa46e
// STATUS: equivalent (tools/equiv.py level 3: 1166 inputs, branch coverage 20/20)
// FUN_002a58e0 @ 0x002a58e0
void FUN_002a58e0(Target_2a58e0 *self, Target_2a58e0 *obj, int a, int b)
{
    Frame_2a58e0 f;
    f.one = 1.0f;
    f.vec[0] = 0;
    f.vec[1] = 0;
    f.vec[2] = 0;
    f.zero = 0;
    f.half = 0.5f;
    f.fifth = 0.2f;
    f.time = self->GetTime();
    f.timeCopy = f.time;

    NodeList_2a58e0 *list = ((NodeList_2a58e0 *)((owners::Target_288a10 *)(self->GetSource()))->FUN_00288a10(0));
    for (int i = 0; i < list->count; i++) {
        Node *n = ((Node *)((owners::C_288950 *)list)->FUN_00288950(i));
        unsigned id = n->GetId();
        if (id == 0x31544c46) {
            switch (n->sub) {
            case 0x53505052:
                ((owners::Curve_28a1c0 *)n)->FUN_0028a1c0(f.timeCopy, &f.one);
                break;
            case 0x4c414652:
                ((owners::Curve_28a1c0 *)n)->FUN_0028a1c0(f.timeCopy, &f.zero);
                break;
            case 0x4d415052:
                ((owners::Curve_28a1c0 *)n)->FUN_0028a1c0(f.timeCopy, &f.half);
                break;
            case 0x4d415552:
                ((owners::Curve_28a1c0 *)n)->FUN_0028a1c0(f.timeCopy, &f.fifth);
                break;
            case 0x454d4954:
                ((owners::Curve_28a1c0 *)n)->FUN_0028a1c0(f.timeCopy, &f.time);
                break;
            }
        } else if (id == 0x54434556) {
            if (n->sub == 0x49524f52)
                n->Apply(f.timeCopy, f.vec);
        }
    }
    FUN_002a5570(f.time / self->Eval(), (Target_2a58e0 *)obj, (void *)(hulk_uintptr)(int)a, (int)b, (float *)(&f.one));
}


// 0x002a5a20 FUN_002a5a20 (966 B): equivalent/0x002a5a20.cpp
// sym: ?FUN_002a5a20@fn_fa65e9c0@@YAXMPAUMesh_2a5a20@1@0IPAUWaveParams@1@@Z @fda7fc2e3992 @wc6de533e971c
// STATUS: equivalent (tools/equiv.py level 3: 5291 inputs, branch coverage 50/54, incomplete)
// FUN_002a5a20 @ 0x002a5a20
void FUN_002a5a20(float time, Mesh_2a5a20 *a, Mesh_2a5a20 *b, unsigned int flags, WaveParams *p)
{
    unsigned char *srcColor = a->color;
    unsigned char *dstColor = b->color;
    Vec3_2a5a20 *srcPos = a->pos;
    Vec3_2a5a20 *dstPos = b->pos;
    Vec2_2a5a20 *src[4];
    Vec2_2a5a20 *dst[4];
    int c;
    for (c = 0; c < 4; c++) {
        src[c] = a->uv[c];
    }
    for (c = 0; c < 4; c++) {
        dst[c] = b->uv[c];
    }
    int i = a->count;

    Vec3_2a5a20 axis;
    axis.x = p->dirx;
    axis.y = p->diry;
    axis.z = 0.0f;
    axis.FUN_0022d110();

    while (i != 0) {
        i--;
        Vec3_2a5a20 *v = &srcPos[i];
        float dx = v->x - p->cx;
        float dy = v->y - p->cy;
        float dz = v->z - p->cz;
        float dot = dx * p->dirx + (dy * p->diry + dz * p->dirz);
        float t;
        if (p->radius != 0.0f) {
            t = dot / p->radius;
        } else {
            t = 0.0f;
        }
        volatile float u = time * p->speed + t;
        float falloff = 1.0f;
        if (p->falloff > 0.0) {
            FloatBits_2a5a20 ab;
            ab.f = dot;
            ab.u &= 0x7fffffff;
            float x = p->falloff - ab.f;
            if (!(0.0f < x)) {
                x = 0.0f;
            }
            falloff = x / p->falloff;
        }
        float w = (float)(sin(u * 6.2831855f) * falloff);
        if (flags & 0x10) {
            dstPos[i].y = w * p->displace + srcPos[i].y;
        }
        if ((flags & 0x40) && srcColor != 0) {
            float s = w + p->k30;
            double m1 = p->k28 * 255.0f;
            int d1 = (int)(__int64)(m1 * s);
            double m2 = p->k2c * 255.0f;
            int d2 = (int)(__int64)(m2 * s);
            unsigned char *e = &srcColor[i * 4];
            int r2 = Clamp255(e[2] + d1);
            int r1 = Clamp255(e[1] + d1);
            int r0 = Clamp255(e[0] + d1);
            int r3 = Clamp255(e[3] + d2);
            ((unsigned int *)dstColor)[i] = (unsigned int)(__int64)((((r3 << 8 | r2) << 8 | r1) << 8) | r0);
        }
        for (c = 0; c < 4; c++) {
            if ((((unsigned int*)&DAT_0042d9c0)[c] & flags) && src[c] != 0 && dst[c] != 0) {
                float du = src[c][i].u - p->cx;
                float dv = src[c][i].v - p->cy;
                float dot2 = du * p->dirx + (dv * p->diry + p->dirz * 0.0f);
                float t2;
                if (p->radius != 0.0f) {
                    t2 = dot2 / p->radius;
                } else {
                    t2 = 0.0f;
                }
                volatile float u2 = time * p->speed + t2;
                float falloff2 = 1.0f;
                if (p->falloff > 0.0) {
                    FloatBits_2a5a20 ab2;
                    ab2.f = dot2;
                    ab2.u &= 0x7fffffff;
                    float x2 = p->falloff - ab2.f;
                    if (!(0.0f < x2)) {
                        x2 = 0.0f;
                    }
                    falloff2 = x2 / p->falloff;
                }
                float amp = p->uvAmp;
                float w2 = (float)(sin(u2 * 6.2831855f) * falloff2);
                volatile float wy = w2 * p->diry;
                dst[c][i].u = w2 * p->dirx * amp + src[c][i].u;
                dst[c][i].v = wy * amp + src[c][i].v;
            }
        }
    }
}


// 0x002a5df0 FUN_002a5df0 (479 B): equivalent/0x002a5df0.cpp
// sym: ?FUN_002a5df0@fn_fa65e9c0@@YAXPAUAnim_2a5df0@1@HHH@Z @a8c5ae586713 @w0622479e9224
// STATUS: equivalent (tools/equiv.py level 3: 1176 inputs, branch coverage 30/30)
// FUN_002a5df0 @ 0x002a5df0
void FUN_002a5df0(Anim_2a5df0 *obj, int a2, int a3, int a4)
{
    Frame_2a5df0 fr;
    fr.f[0] = 1.0f;
    fr.f[1] = 0.0f;
    fr.f[2] = 0.0f;
    fr.f[3] = 0.0f;
    fr.f[4] = 1.0f;
    fr.f[5] = 0.0f;
    fr.f[6] = 0.0f;
    fr.f[7] = 10.0f;
    fr.f[8] = 0.0f;
    fr.f[9] = 1.0f;
    fr.f[10] = 0.5f;
    fr.f[11] = 0.0f;
    fr.f[12] = 0.0f;
    fr.f[13] = 0.2f;
    fr.t0 = fr.t = obj->v13();
    List_2a5df0 *list = ((List_2a5df0 *)((owners::Target_288a10 *)(obj->v25()))->FUN_00288a10(0));
    for (int i = 0; i < list->count; i++) {
        Item_2a5df0 *item = ((Item_2a5df0 *)((owners::C_288950 *)list)->FUN_00288950(i));
        int type = item->GetType();
        if (type == 0x31544c46) {
            float *dst;
            switch (item->subType) {
            case 0x53505657: dst = &fr.f[0]; break;
            case 0x4e454c57: dst = &fr.f[7]; break;
            case 0x4c414657: dst = &fr.f[8]; break;
            case 0x4d415057: dst = &fr.f[9]; break;
            case 0x4d414357: dst = &fr.f[10]; break;
            case 0x4d414157: dst = &fr.f[11]; break;
            case 0x464f4357: dst = &fr.f[12]; break;
            case 0x4d415557: dst = &fr.f[13]; break;
            case 0x454d4954: dst = &fr.t; break;
            default: continue;
            }
            ((owners::Curve_28a1c0 *)item)->FUN_0028a1c0(fr.t0, dst);
        } else if (type == 0x54434556) {
            if (item->subType == 0x49524f57) {
                item->v4(fr.t0, &fr.f[1]);
            } else if (item->subType == 0x52494457) {
                item->v4(fr.t0, &fr.f[4]);
                ((V3_2a5df0 *)&fr.f[4])->FUN_0022d110();
            }
        }
    }
    FUN_002a5a20(fr.t / obj->v10(), a2, a3, a4, fr.f);
}

} // namespace fn_fa65e9c0

// 0x002a5fd0 FUN_002a5fd0 (1320 B): equivalent/0x002a5fd0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002a5fd0@fn_002a5fd0@@YAXMPAUSrcMesh@1@PAUDstMesh@1@IPAUParams@1@@Z @85371c5e39ad @w21b5b194f296
namespace fn_002a5fd0 {
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 42/42)
// FUN_002a5fd0 @ 0x002a5fd0

struct V2_2a5fd0 {
    float x, y;
};

struct V3_2a5fd0 {
    float x, y, z;
};

struct Noise {
    hulk_freg FUN_00356fa0(const V3_2a5fd0 *v);
    hulk_freg FUN_00356e50(const V2_2a5fd0 *v);
};

extern "C" Noise *FUN_003576d0();

struct SrcMesh {
    char pad0[0xc];
    int n;
    char pad10[0x18 - 0x10];
    V3_2a5fd0 *pos;
    char pad1c[0x38 - 0x1c];
    V2_2a5fd0 *uv[4];
    unsigned int *col;
};

struct DstMesh {
    char pad0[0x18];
    V3_2a5fd0 *pos;
    char pad1c[0x38 - 0x1c];
    V2_2a5fd0 *uv[4];
    unsigned int *col;
};

struct Params {
    float tscale;
    float posScale;
    float colScale;
    float alphaScale;
    float uvScale;
};

static float Clamp01(float v)
{
    if (v >= 0.0f && v <= 1.0f)
        return v;
    if (v > 1.0f)
        return 1.0f;
    return 0.0f;
}

struct Frame_2a5fd0 {
    char pad0[0x10];
    int tmp10;                  // 10
    float tp;                   // 14
    Noise *noise;               // 18
    float v2;                   // 1c
    unsigned char *qptr;        // 20
    float g4;                   // 24 (also &uv.v)
    V3_2a5fd0 *dstcur;                 // 28
    unsigned int *Q;            // 2c
    float v1;                   // 30
    float v0;                   // 34
    float f1;                   // 38
    float f2;                   // 3c
    char pad40[4];
    float g3;                   // 44
    int diff;                   // 48
    int flags40;                // 4c
    unsigned int *R;            // 50
    int flags10;                // 54
    float uva;                  // 58
    char pad5c[4];
    float g2;                   // 60
    float g1;                   // 64
    V2_2a5fd0 uvq;                     // 68
    V2_2a5fd0 uvp;                     // 70
    V2_2a5fd0 *bs[4];                  // 78
    V2_2a5fd0 w88;                     // 88
    V3_2a5fd0 w90;                     // 90
    V3_2a5fd0 w9c;                     // 9c
    V3_2a5fd0 wa8;                     // a8
    V3_2a5fd0 wb4;                     // b4
    V3_2a5fd0 wc0;                     // c0
    V3_2a5fd0 wcc;                     // cc
    V2_2a5fd0 *as_[4];                 // d8
};

void FUN_002a5fd0(float t, SrcMesh *a, DstMesh *b, unsigned int flags, Params *c)
{
    Frame_2a5fd0 f;
    f.tp = t * c->tscale;
    f.dstcur = 0;
    V3_2a5fd0 *dst0 = b->pos;
    f.Q = a->col;
    f.R = b->col;
    f.as_[0] = a->uv[0];
    f.bs[0] = b->uv[0];
    f.as_[1] = a->uv[1];
    f.bs[1] = b->uv[1];
    f.as_[2] = a->uv[2];
    f.bs[2] = b->uv[2];
    f.as_[3] = a->uv[3];
    f.bs[3] = b->uv[3];
    int n = a->n;
    V3_2a5fd0 *src0 = a->pos;
    f.noise = FUN_003576d0();
    if (n == 0)
        return;
    f.flags40 = flags & 0x40;
    f.flags10 = flags & 0x10;
    f.dstcur = dst0 + n;
    f.qptr = (unsigned char *)f.Q + n * 4 + 1;
    V3_2a5fd0 *s = src0 + n;
    int i = n;
    hulk_freg s2 = 0.0f;
    do {
        i--;
        f.dstcur = f.dstcur - 1;
        f.qptr = f.qptr - 4;
        s = s - 1;
        if (f.flags10) {
            f.wcc.x = f.tp;
            f.wcc.y = s->y;
            f.wcc.z = s->z;
            f.f1 = f.noise->FUN_00356fa0(&f.wcc);
            f.wc0.x = s->x;
            f.wc0.y = f.tp;
            f.wc0.z = s->z;
            f.f2 = f.noise->FUN_00356fa0(&f.wc0);
            f.w90.x = s->x;
            f.w90.y = s->y;
            f.w90.z = f.tp;
            hulk_freg f3 = f.noise->FUN_00356fa0(&f.w90);
            s2 = c->posScale;
            volatile float m1 = f.f1 * s2;
            volatile float m2 = f.f2 * s2;
            hulk_freg m3 = f3 * s2;
            f.dstcur->x = m1 + s->x;
            f.dstcur->y = m2 + s->y;
            f.dstcur->z = m3 + s->z;
        }
        if (f.flags40 != 0 && f.Q != 0) {
            unsigned char *q = f.qptr;
            unsigned int ch2 = q[1];
            unsigned int ch1 = q[0];
            unsigned int ch0 = q[-1] & 0xff;
            unsigned int ch3 = q[2];
            const hulk_freg k = 0.003921569f;
            f.v2 = (float)(int)ch2 * k;
            f.v1 = (float)(int)ch1 * k;
            f.v0 = (float)(int)ch0 * k;
            hulk_freg v3 = (float)(int)ch3 * k;
            f.wb4.x = f.tp;
            f.wb4.y = f.v1;
            f.wb4.z = f.v0;
            hulk_freg Fa = f.noise->FUN_00356fa0(&f.wb4);
            volatile float G1 = Fa * c->colScale;
            f.w9c.x = f.v2;
            f.w9c.y = f.tp;
            f.w9c.z = f.v0;
            hulk_freg Fb = f.noise->FUN_00356fa0(&f.w9c);
            volatile float G2 = Fb * c->colScale;
            f.wa8.x = f.v2;
            f.wa8.y = f.v1;
            f.wa8.z = f.tp;
            hulk_freg Fc = f.noise->FUN_00356fa0(&f.wa8);
            volatile float G3 = Fc * c->colScale;
            f.w88.x = v3;
            f.w88.y = f.tp;
            hulk_freg Fd = f.noise->FUN_00356e50(&f.w88);
            volatile float G4 = Fd * c->alphaScale;
            hulk_freg T1 = Clamp01(G1 + f.v2);
            hulk_freg T2 = Clamp01(G2 + f.v1);
            hulk_freg T3 = Clamp01(G3 + f.v0);
            hulk_freg T4 = Clamp01(G4 + v3);
            unsigned int col = (int)(T4 * 255.0f);
            col <<= 8;
            col |= (int)(T1 * 255.0f);
            col <<= 8;
            col |= (int)(T2 * 255.0f);
            col <<= 8;
            col |= (int)(T3 * 255.0f);
            f.R[i] = col;
        }
        for (int k = 0; k < 4; k++) {
            if ((((unsigned int*)&DAT_0042d9c0)[k] & flags) != 0 && f.as_[k] != 0 && f.bs[k] != 0) {
                f.uvp.x = f.as_[k][i].x;
                f.uvp.y = f.tp;
                volatile float Fu = f.noise->FUN_00356e50(&f.uvp);
                f.uvq.x = f.as_[k][i].y;
                f.uvq.y = f.tp;
                hulk_freg Fv = f.noise->FUN_00356e50(&f.uvq);
                hulk_freg s3 = c->uvScale;
                volatile float mu = Fu * s3;
                hulk_freg mv = Fv * s3;
                f.bs[k][i].x = f.as_[k][i].x + mu;
                f.bs[k][i].y = f.as_[k][i].y + mv;
            }
        }
    } while (i != 0);
}
} // namespace fn_002a5fd0

namespace fn_fa65e9c0 {

// 0x002a6500 FUN_002a6500 (266 B): equivalent/0x002a6500.cpp
// sym: ?FUN_002a6500@fn_fa65e9c0@@YAHPAUSource_2a6500@1@III@Z @856610074fa8 @w4fc22fbe6b35
// STATUS: equivalent (tools/equiv.py level 3: 1172 inputs, branch coverage 18/18)
// FUN_002a6500 @ 0x002a6500
int __cdecl FUN_002a6500(Source_2a6500* source, unsigned int arg2, unsigned int arg3, unsigned int arg4) {
 Values_2a6500 values; values.speed=0.08f; values.p=0.5f; values.c=0.5f; values.a=0.0f; values.u=0.125f;
 float t=source->time(); float updatedTime=t;
 List_2a6500* list=((List_2a6500 *)((owners::Target_288a10 *)(source->container()))->FUN_00288a10(0));
 for(int i=0;i<list->count;++i) {
 Parameter_2a6500* param=((Parameter_2a6500 *)((owners::C_288950 *)list)->FUN_00288950(i));
 if(param->type()==0x31544c46) {
 float* value=0;
 switch(param->name) {
 case 0x4450534e: value=&values.speed; break;
 case 0x4d41504e: value=&values.p; break;
 case 0x4d41434e: value=&values.c; break;
 case 0x4d41414e: value=&values.a; break;
 case 0x4d41554e: value=&values.u; break;
 case 0x454d4954: value=&updatedTime; break;
 }
 if(value) ((owners::Curve_28a1c0 *)param)->FUN_0028a1c0(t, value);
 }
 }
 return FUN_002a5fd0(updatedTime,arg2,arg3,arg4,&values);
}

} // namespace fn_fa65e9c0

// 0x002a6610 FUN_002a6610 (328 B): equivalent/0x002a6610.cpp [wrapped: conflict: Node]
// sym: ?FUN_002a6610@fn_002a6610@@YAXPAVController_2a6610@1@III@Z @2917d89f0989 @wcc6af5af63eb
namespace fn_002a6610 {
// STATUS: equivalent (tools/equiv.py level 3: 1194 inputs, branch coverage 16/16)
// FUN_002a6610 @ 0x002a6610
class Overlay_2a6610;
struct Vec3_2a6610 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Vec2_2a6610 {
    float x, y;
    hulk_freg FUN_002a54e0();
};

class Node {
public:
    virtual void s0();
    virtual void s1();
    virtual int type();
    virtual void s3();
    virtual void direction(float v, Vec3_2a6610 *out);
    char pad4[8 - 4];
    int subtype;
};

class List_2a6610 {
public:
    char pad0[0x14];
    int count;
};

class Overlay_2a6610 {
public:
};

class Controller_2a6610 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual float f10();
    virtual void s11();
    virtual void s12();
    virtual float f13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual Overlay_2a6610 *f25();
};

struct Settings_2a6610 {
    float sp;
    float su;
    Vec3_2a6610 dir;
    Vec2_2a6610 d;
};

extern "C++" __declspec(nothrow) void __cdecl FUN_002a5290(float, void *, void *, unsigned int, float *);

void FUN_002a6610(Controller_2a6610 *c, unsigned int a2, unsigned int a3, unsigned int a4)
{
    struct Frame {
        float timeA;
        float timeB;
        Settings_2a6610 s;
    } fr;

    float t = c->f13();
    fr.timeB = t;
    fr.timeA = t;
    List_2a6610 *list = ((List_2a6610 *)((owners::Target_288a10 *)(c->f25()))->FUN_00288a10(0));
    fr.s.sp = 0.1f;
    fr.s.su = 0.1f;
    fr.s.dir.x = 1.0f;
    fr.s.dir.y = 0.0f;
    fr.s.dir.z = 0.0f;
    fr.s.d.x = 1.0f;
    fr.s.d.y = 0.0f;

    for (int i = 0; i < list->count; i++) {
        float v = fr.timeB;
        Node *n = ((Node *)((owners::C_288950 *)list)->FUN_00288950(i));
        int ty = n->type();
        if (ty == 0x31544c46) {
            float *target;
            if (n->subtype == 0x50535053)
                target = &fr.s.sp;
            else if (n->subtype == 0x50535553)
                target = &fr.s.su;
            else if (n->subtype == 0x454d4954)
                target = &fr.timeA;
            else
                continue;
            ((owners::Curve_28a1c0 *)n)->FUN_0028a1c0(v, target);
        } else if (ty == 0x54434556) {
            if (n->subtype == 0x52494453) {
                n->direction(v, &fr.s.dir);
                float x = fr.s.dir.x;
                float y = fr.s.dir.y;
                fr.s.d.x = x;
                fr.s.d.y = y;
                fr.s.dir.FUN_0022d110();
                fr.s.d.FUN_002a54e0();
            }
        }
    }
    FUN_002a5290(fr.timeA / c->f10(), (void *)(hulk_uintptr)(unsigned int)a2, (void *)(hulk_uintptr)(unsigned int)a3, a4, (float *)(Settings_2a6610 *)(&fr.s));
}
} // namespace fn_002a6610

namespace fn_fa65e9c0 {

// 0x002a6760 pure3d::ProceduralVertexAnimController::vfunc_24 (124 B): matches/0x002a6760.cpp
// sym: ?vfunc_24@ProceduralVertexAnimController@fn_fa65e9c0@@UAEXHHH@Z
// pure3d::ProceduralVertexAnimController::vfunc_24 @ 0x002a6760
void ProceduralVertexAnimController::vfunc_24(int a, int b, int c) {
    SimpleFrameController::vfunc_24(a, b, c);
    updateFn = FUN_002a5260;
    if (data == 0) {
        return;
    }
    switch (data->tag) {
    case 0x50525650:  // 'PVPR'
        updateFn = FUN_002a58e0;
        break;
    case 0x48535650:  // 'PVSH'
        updateFn = FUN_002a6610;
        break;
    case 0x534e5650:  // 'PVNS'
        updateFn = FUN_002a6500;
        break;
    case 0x56575650:  // 'PVWV'
        updateFn = FUN_002a5df0;
        break;
    default:
        updateFn = FUN_002a5260;
        break;
    }
}


// 0x002a67e0 FUN_002a67e0 (94 B): matches/0x002a67e0.cpp
// sym: ?Run@Owner_2a67e0@fn_fa65e9c0@@QAEXXZ
void Owner_2a67e0::Run() {
    int count = bag->entries.size();
    if (count) {
        int offset = count << 4;
        do {
            Item_2a67e0* item = *(Item_2a67e0**)((char*)bag->entries.begin + offset - 16);
            offset -= 16;
            --count;
            if (item && (item->Check() & 0x80))
                callback(this, ids[count], item->v5c, item->v50, 0);
        } while (count);
    }
}


// 0x002a6840 FUN_002a6840 (109 B): equivalent/0x002a6840.cpp
// sym: ?FUN_002a6840@Target_2a6840@fn_fa65e9c0@@QAEXXZ @263baa6788e7 @wdaf68631dea4
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 8/8)
// FUN_002a6840 @ 0x002a6840
void Target_2a6840::FUN_002a6840()
{
    hulk_intptr n = group->end - group->begin;
    if (n == 0)
        return;
    do {
        Ent_2a6840 *e = group->begin[n - 1].ent;
        n--;
        if (e != 0) {
            int saved = e->f50;
            int v;
            if (e->v5() < 0)
                v = e->f5c;
            else
                v = e->f68;
            callback(this, values[n], v, saved, 0);
        }
    } while (n != 0);
}


// 0x002a68b0 FUN_002a68b0 (85 B): matches/0x002a68b0.cpp
// sym: ?Run@ProceduralVertexAnimController_2a68b0@fn_fa65e9c0@@QAEXXZ
void ProceduralVertexAnimController_2a68b0::Run() {
    unsigned int i = 0;
    if (0 < count) {
        do {
            Item_2a68b0** slot = &items[i];
            Item_2a68b0* p = *slot;
            if (p) {
                p->Release();
                *slot = 0;
            }
            ++i;
        } while (i < count);
    }
    Free_0008d340(items);
    items = 0;
    x40 = 0;
    x44 = 0;
}


// 0x002a6910 FUN_002a6910 (22 B): matches/0x002a6910.cpp
// sym: ??1ProceduralVertexAnimController_2a6910@fn_fa65e9c0@@QAE@XZ
// Same code shape as 0x001c5640 (propagated; names are from that function)
ProceduralVertexAnimController_2a6910::~ProceduralVertexAnimController_2a6910() {
    Cleanup1_002a68b0();
    Cleanup2_00285800();
}


// 0x002a6930 FUN_002a6930 (238 B): equivalent/0x002a6930.cpp
// sym: ?target@ProceduralVertexAnimController_2a6930@fn_fa65e9c0@@QAEXPAUSource_2a6930@2@@Z @5b3bd6de0a10 @w4c6466084a60
// STATUS: equivalent (tools/equiv.py level 3: 284 inputs, branch coverage 14/14)
// FUN_002a6930 @ 0x002a6930
void ProceduralVertexAnimController_2a6930::target(Source_2a6930* input) {
 FUN_002a68b0(); source=input;
 if (!input) return;
 count=(unsigned int)(((int)((char*)input->end-(char*)input->begin))>>4);
 items=(pure3d::VertexList **)FUN_0008d6d0(count * sizeof(pure3d::VertexList *));
 unsigned int index=0, offset=0;
 while(index<count) {
  items[index]=0;
  Resource_2a6930* resource=FUN_00344e74(*(void**)((char*)source->begin+offset),0,&DAT_004cf8e8,&DAT_004cf908,0);
  if(resource) {
   pure3d::VertexList* memory=(pure3d::VertexList*)FUN_0008d690((int)sizeof(pure3d::VertexList));
   pure3d::VertexList* obj=memory ? ((VertexList_nv_2a6930*)(((pure3d::VertexList*)(memory))))->FUN_002c8730(resource->data) : 0;
   pure3d::VertexList** slot=items+index;
   if(obj) obj->vfunc_0();
   if(*slot) (*slot)->vfunc_1();
   *slot=obj;
  }
  ++index; offset+=16;
 }
}

} // namespace fn_fa65e9c0

// 0x002a6a20 FUN_002a6a20 (332 B): equivalent/0x002a6a20.cpp [wrapped: conflict: pure3d::PrimGroup; pure3d::PrimGroupSkinnedPC; pure3d::PrimGroupSkinnedStreamed]
// sym: ?FUN_002a6a20@ProceduralVertexAnimController_2a6a20@fn_002a6a20@@QAEXPAUSource_2a6a20@2@@Z @ccccf173b4a0 @wa375e89de85a
namespace fn_002a6a20 {
// STATUS: equivalent (tools/equiv.py level 3: 3128 inputs, branch coverage 22/22; Wine build 611 inputs, 22/22)
// FUN_002a6a20 @ 0x002a6a20
namespace pure3d {
class PrimGroup {
public:
    virtual void vfunc_0();
};
}

namespace pure3d {
class PrimGroupSkinnedStreamed : public pure3d::PrimGroup {
public:
    virtual void vfunc_0();
    char pad04[0x58];
    int streamHandle;
};
}

namespace pure3d {
class PrimGroupSkinnedPC : public pure3d::PrimGroup {
public:
    virtual void vfunc_0();
    char pad04[0x64];
    int geometryHandle;
};
}

struct Entry_2a6a20 {
    pure3d::PrimGroup *group;
    int pad[3];
};

struct Source_2a6a20 {
    char pad0[0x48];
    Entry_2a6a20 *begin;
    Entry_2a6a20 *end;
};

class RefCounted_2a6a20 {
public:
    virtual void AddRef();
    virtual void Release();
};

class VertexList_2a6a20 : public RefCounted_2a6a20 {
public:
    RefCounted_2a6a20 *FUN_002c8730(int handle);
};

void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d6d0(unsigned int size);

class ProceduralVertexAnimController_2a6a20 {
public:
    char pad0[0x44];
    Source_2a6a20 *source;
    hulk_uintptr count;
    RefCounted_2a6a20 **items;

    void FUN_002a68b0();
    void FUN_002a6a20(Source_2a6a20 *src);
};

void ProceduralVertexAnimController_2a6a20::FUN_002a6a20(Source_2a6a20 *src)
{
    FUN_002a68b0();
    source = src;
    if (src == 0)
        return;

    count = src->end - src->begin;
    items = (RefCounted_2a6a20 **)FUN_0008d6d0(count * 4);
    for (unsigned int i = 0; i < count; i++) {
        items[i] = 0;
        pure3d::PrimGroupSkinnedPC *pc = dynamic_cast<pure3d::PrimGroupSkinnedPC *>(source->begin[i].group);
        RefCounted_2a6a20 *res;
        RefCounted_2a6a20 **slot;
        if (pc != 0) {
            VertexList_2a6a20 *mem = (VertexList_2a6a20 *)FUN_0008d690(0x5c);
            if (mem != 0)
                res = mem->FUN_002c8730(pc->geometryHandle);
            else
                res = 0;
        } else {
            pure3d::PrimGroupSkinnedStreamed *st = dynamic_cast<pure3d::PrimGroupSkinnedStreamed *>(source->begin[i].group);
            if (st == 0)
                continue;
            VertexList_2a6a20 *mem = (VertexList_2a6a20 *)FUN_0008d690(0x5c);
            if (mem != 0)
                res = mem->FUN_002c8730(st->streamHandle);
            else
                res = 0;
        }
        slot = &items[i];
        if (res != 0)
            res->AddRef();
        if (*slot != 0)
            (*slot)->Release();
        *slot = res;
    }
}
} // namespace fn_002a6a20


// 0x002a6b70 pure3d::ProceduralVertexAnimController::vfunc_7 (25 B): matches/0x002a6b70.cpp
// sym: ?vfunc_7@ProceduralVertexAnimController@pure3d@@UAEXXZ
void pure3d::ProceduralVertexAnimController::vfunc_7() {
    if (this->f_40)
        ((ProceduralVertexAnimController_nv_2a6b70*)this)->h1_002a67e0();
    else if (this->f_44)
        ((ProceduralVertexAnimController_nv_2a6b70*)this)->h2_002a6840();
}

namespace fn_fa65e9c0 {

// 0x002a6b90 pure3d::ProceduralVertexAnimController::vfunc_2 (43 B): matches/0x002a6b90.cpp
// sym: ?scalar_dtor@ProceduralVertexAnimController_2a6b90@fn_fa65e9c0@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ProceduralVertexAnimController_2a6b90::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0042d9dc;
    base1_dtor_002a68b0();
    base2_dtor_00285800();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fa65e9c0

// 0x002a6c00 pure3d::ProceduralVertexAnimController::vfunc_4 (86 B): matches/0x002a6c00.cpp [wrapped: conflict: ProceduralVertexAnimController]
// sym: ?vfunc_4@ProceduralVertexAnimController@fn_002a6c00@@UAEPAXXZ
namespace fn_002a6c00 {
extern "C" char DAT_0042d9dc[];
typedef unsigned int u32_2a6c00;
extern void* __cdecl alloc_00263ea0(unsigned int);
class ProceduralVertexAnimController {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void* vfunc_4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    void init_00285780(ProceduralVertexAnimController*);
    void copyfield_002a6930(u32_2a6c00);
    char pad[0x3c];
    u32_2a6c00 field40, field44, field48, field4c, field50;
};
void* ProceduralVertexAnimController::vfunc_4() {
    ProceduralVertexAnimController* p = (ProceduralVertexAnimController*)alloc_00263ea0(0x58);
    if (p) {
        p->init_00285780(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042d9dc);
        p->field40 = 0;
        p->field48 = 0;
        p->field4c = 0;
        if (field40)
            p->copyfield_002a6930(field40);
        p->field50 = field50;
        return p;
    }
    return 0;
}
} // namespace fn_002a6c00


// 0x002a6c60 pure3d::ProceduralVertexAnimController::vfunc_5 (42 B): matches/0x002a6c60.cpp
// sym: ?vfunc_5@ProceduralVertexAnimController@pure3d@@UAEXPAX@Z
// Same code shape as 0x00293970 (propagated; names are from that function)
void pure3d::ProceduralVertexAnimController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    U_2a6c60 x = ((U_2a6c60)(hulk_uintptr)__RTDynamicCast((void*)(arg), 0, (void*)(&hulk_at_0048f610), (void*)(&CameraRTTI), 0));
    ((ProceduralVertexAnimController_nv_2a6c60*)this)->Finish_002a6930(x);
}

