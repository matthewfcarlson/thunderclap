// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002df4d0..0x002e1610 (kind game, layer engine, confidence high), dominant class pure3d::PrimGroupStreamed
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f1455a33 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f1455a33 {} using namespace fn_f1455a33;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f1455a33 {
extern "C" char DAT_0042fb54[];
typedef unsigned int U_2df4d0;
class DrawablePrimitive_2df4d0 {
  public:
    char pad[0x40];
    DrawablePrimitive_2df4d0();
};
class PrimGroup : public DrawablePrimitive_2df4d0 {
  public:
    U_2df4d0 a, b, c, d, e;
    PrimGroup(U_2df4d0 x, U_2df4d0 y);
};
class pddiObject_2df510 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_2df510 : public pddiObject_2df510 {};
class pddiBaseShader_2df510 : public pddiShader_2df510 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_2df510 : public pddiBaseShader_2df510 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Manager_2df540 {
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
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32(int, int);
};
extern Manager_2df540* hulk_at_0052c2a8;
class Obj_2df690 {
  public:
    void FUN_002d0950(int, int, int);
};
class Obj_2df6b0 {
  public:
    void FUN(int, int, int);
};
class Helper_2df6f0 {
  public:
    void go_002d0950(int, int, int);
};
class Helper_2df710 {
  public:
    void go(int, int, int);
};
class Obj_2df750 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void* s4();
    virtual void s5(void*);
    virtual void s6();
};
class Global_2df750 {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32(void*, Obj_2df750*);
};
class Sub_2df750 {
  public:
    void call(void*, int, int);
};
struct Res_2df750 {
    char pad[0x10];
    void* val;
};
extern Global_2df750* gGlobal_2df750;
struct X_2df7d0 {
};
struct C_2df7d0 {
    char pad[0x5c];
    X_2df7d0* member;
    void target();
};
class RenderObjectLoader_2df7f0 {
  public:
    virtual void f();
    char pad[4];
    RenderObjectLoader_2df7f0();
};
class PrimGroupLoader : public RenderObjectLoader_2df7f0 {
  public:
    virtual void g();
    int a, b;
    char c, d;
    short e;
    int f0, f1, f2, f3, f4, f5;
    PrimGroupLoader();
};
class AnimationFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void vfunc_8(int);
    char pad[0x18 - 4];
    int field;
};
class RenderObjectLoader_2df850 {
  public:
    RenderObjectLoader_2df850();
    virtual void Fn();
    int unused;
};
class OldPrimGroupLoader : public RenderObjectLoader_2df850 {
  public:
    OldPrimGroupLoader();
    virtual void Fn();
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
};
struct Other_2dfc90 {
};
struct Data_2dfc90 {
    char pad[12];
    uint count;
    char pad2[12];
    int data;
};
struct Src_2dfc90 {
    char pad[32];
    int data;
};
struct Obj_2dfc90 {
    char pad[8];
    Other_2dfc90* p;
    void f(Src_2dfc90* s, Data_2dfc90* d);
};
extern void* hulk_at_0042fb54[];
class Ref_2dfd40 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2dfd40 {
  public:
    void* vptr;
    void Fin_002a50a0();
};
class PrimGroup_2dfd40 : public DrawablePrimitive_2dfd40 {
  public:
    char pad[0x3c];
    Ref_2dfd40* m40;
    ~PrimGroup_2dfd40();
};
struct Ref_2dfd70 {
    virtual void AddRef();
    virtual void Release();
    int pad[5];
    int kind;
};
class Base {
  public:
    Base();
    virtual void f();
    char pad[0x3c];
};
class PrimGroup_2dfde0 : public Base {
  public:
    int x40, x44, x48, x4c, x50;
    char pad2[4];
    int x58;
    PrimGroup_2dfde0(int a, int b) : x40(0), x44(0), x48(a), x4c(b), x50(-1), x58(0) {}
};
class PrimGroupOptimized : public PrimGroup_2dfde0 {
  public:
    PrimGroupOptimized(int a, int b);
    virtual void f();
};
extern int hulk_at_0042fba4;
extern int vt2_2dffa0;
class Ref_2dffa0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroup_2dffa0 {
  public:
    void* vptr;
    ~PrimGroup_2dffa0() throw();
};
class PrimGroupOptimized_2dffa0 : public PrimGroup_2dffa0 {
  public:
    char p40[60];
    Ref_2dffa0* a40;
    char p58[20];
    Ref_2dffa0* a58;
    ~PrimGroupOptimized_2dffa0() throw();
};
extern "C" char DAT_0042fbd4[];
class PrimGroupOptimized_2dffe0 {
  public:
    void Init_002a5060();
};
class PrimGroupSkinnedOptimized : public PrimGroupOptimized_2dffe0 {
  public:
    char pad[0x40];
    int a40, a44, a48, a4c, a50;
    char p54[4];
    int a58;
    char p5c[4];
    int a60, a64;
    PrimGroupSkinnedOptimized* setup(int x, int y);
};
class Ref_2e0090 {
  public:
    virtual void f();
    virtual void Release();
};
extern int hulk_at_0042fbd4, vtOpt, vtBase;
class PrimGroupSkinnedOptimized_2e0090 {
  public:
    void* vptr;
    char p4[0x3c];
    Ref_2e0090* m40;
    char p44[0x14];
    Ref_2e0090* m58;
    char p5c[4];
    Ref_2e0090* m60;
    Ref_2e0090* m64;
    void Cleanup();
    void BaseCleanup_002a50a0();
};
class Helper_2e00f0 {
  public:
    hulk_intptr run_002e0020(pure3d::PrimGroupSkinnedOptimized*);
};
class PrimGroupOptimized_2e0110 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5(int, void*);
    virtual void f6(void*, void*);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};
struct Vec_2e0110 {
    int* begin;
    int* end;
    hulk_uintptr size() const { return end - begin; }
};
struct Arr_2e0110 {
    int pad[2];
    Vec_2e0110 v;
};
struct Base_2e0110 {
    char pad[8];
    void* data;
};
class Manager_2e0110 {
  public:
};
class PrimGroupSkinnedOptimized_2e0110 : public PrimGroupOptimized_2e0110 {
  public:
    char pad[0x3c];
    void* p40;
    char p44[0x14];
    void* p58;
    void* p5c;
    Base_2e0110* p60;
    Arr_2e0110* p64;
    void f6();
};
class Thing_2e01a0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2e01a0 {
  public:
    char pad[0x60];
    Thing_2e01a0* mThing;
    void Set(Thing_2e01a0* p);
};
extern int hulk_at_0042fc04;
extern int vt2_2e02a0;
class Ref_2e02a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroup_2e02a0 {
  public:
    void* vptr;
    ~PrimGroup_2e02a0() throw();
};
class PrimGroupStreamed_2e02a0 : public PrimGroup_2e02a0 {
  public:
    char p40[60];
    Ref_2e02a0* a40;
    char p5c[24];
    Ref_2e02a0* a5c;
    ~PrimGroupStreamed_2e02a0() throw();
};
struct V3_2e02e0 { float x, y, z; };
struct V4_2e02e0 { float x, y, z, w; };
struct Bounds_2e02e0 {
    V3_2e02e0 lo;
    V3_2e02e0 hi;
    V4_2e02e0 *FUN_000a8890(V4_2e02e0 *out);
};
struct Xform_2e02e0 {
    char pad0[0x10];
    V3_2e02e0 *offset;
};
struct Mesh_2e02e0 {
    char pad0[0x18];
    V3_2e02e0 *points;
    char pad1c[0x58 - 0x1c];
    Xform_2e02e0 *xform;
};
class PrimGroupStreamed {
public:
    char pad0[0x14];
    Bounds_2e02e0 bounds;
    V4_2e02e0 sphere;
    char pad3c[0x4c - 0x3c];
    unsigned int count;
    char pad50[0x5c - 0x50];
    Mesh_2e02e0 *mesh;
    void FUN_002e02e0();
};
extern int hulk_at_0042fc3c;
extern int vt2_2e04e0;
extern int vt3;
class Ref_2e04e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroupStreamed_2e04e0 {
  public:
    void* vptr;
    ~PrimGroupStreamed_2e04e0() throw();
};
class PrimGroupSkinnedStreamed_2e04e0 : public PrimGroupStreamed_2e04e0 {
  public:
    char p40[60];
    Ref_2e04e0* a40;
    char p5c[24];
    Ref_2e04e0* a5c;
    Ref_2e04e0* a60;
    Ref_2e04e0* a64;
    ~PrimGroupSkinnedStreamed_2e04e0() throw();
};
class Helper_2e0540 {
  public:
    hulk_intptr run_002e0460(pure3d::PrimGroupSkinnedStreamed*);
};
struct Vec3_2e0560 {
    float x, y, z;
};
struct Sphere_2e0560 {
    float x, y, z, r;
};
struct BBox {
    Vec3_2e0560 lo;
    Vec3_2e0560 hi;
    Sphere_2e0560* FUN_000a8890(Sphere_2e0560* out);
};
struct SkinData {
    char pad00[0x20];
    Vec3_2e0560* points;
};
struct SkinHolder_2e0560 {
    char pad00[0x20];
    Vec3_2e0560* points;
};
class PrimGroupSkinnedStreamed_2e0560 {
public:
    char pad00[0x14];
    BBox box;
    Sphere_2e0560 sphere;
    char pad3c[0x10];
    unsigned int count;
    char pad50[0xc];
    SkinHolder_2e0560* skin;
    void FUN_002e0560();
};
class Thing_2e05f0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2e05f0 {
  public:
    char pad[0x60];
    Thing_2e05f0* mThing;
    void Set(Thing_2e05f0* p);
};
extern int hulk_at_0042fc74;
class Ref_2e06e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroupSkinnedOptimized_2e06e0 {
  public:
    void* vptr;
    char pad[0x64];
    Ref_2e06e0* child;
    ~PrimGroupSkinnedOptimized_2e06e0() throw();
};
class PrimGroupSkinnedPC_2e06e0 : public PrimGroupSkinnedOptimized_2e06e0 {
  public:
    ~PrimGroupSkinnedPC_2e06e0() throw();
};
extern "C" char DAT_0042fc74[];
class Ref_2e0710 {
  public:
    virtual void f0();
    virtual void f1();
};
struct PrimGroupSkinnedPC_nv_2e0710 {
    void init_002e0020(pure3d::PrimGroupSkinnedPC*);
};
extern void* alloc_00263ea0(hulk_uintptr);
extern int hulk_at_0042fca4;
extern int vt2_2e09e0;
class Ref_2e09e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroup_2e09e0 {
  public:
    void* vptr;
    ~PrimGroup_2e09e0() throw();
};
class VertexAnimPrimGroup_2e09e0 : public PrimGroup_2e09e0 {
  public:
    char p40[60];
    Ref_2e09e0* a40;
    char p58[20];
    Ref_2e09e0* a58;
    Ref_2e09e0* a5c;
    ~VertexAnimPrimGroup_2e09e0() throw();
};
class Other_2e0a40 {
  public:
    hulk_intptr helper_002e0880(pure3d::VertexAnimPrimGroup*);
};
struct Ref_2e0b10 {
    virtual void addRef();
    virtual void release();
};
struct Block6 {
    int v[6];
};
struct Block4_2e0b10 {
    int v[4];
};
struct Holder_2e0b10 {
    char pad00[0x58];
    Ref_2e0b10 *ref;
};
class Prim_2e0b10 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad04[0x14 - 4];
    Block6 b14;
    Block4_2e0b10 b2c;
    char pad3c[0x5c - 0x3c];
    Holder_2e0b10 *holder;
};
class VertexAnimPrimGroup {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad04[0x14 - 4];
    Block6 b14;
    Block4_2e0b10 b2c;
    char pad3c[0x58 - 0x3c];
    Prim_2e0b10 *prim;
    Ref_2e0b10 *ref;
};
struct V3_2e0cc0 {
    int x, y, z;
};
struct VtxRec {
    int idx;
    V3_2e0cc0 v;
};
struct UvRec {
    int idx;
    int a, b;
};
struct Pair8 {
    int a, b;
};
struct Entry8 {
    int a, b;
};
struct VtxVec {
    VtxRec *begin;
    VtxRec *end;
    VtxRec *cap;
};
struct UvVec {
    UvRec *begin;
    UvRec *end;
    UvRec *cap;
};
struct Src_2e0cc0 {
    char pad0[0x14];
    VtxRec *vbegin;        // 0x14
    VtxRec *vend;          // 0x18
    char pad1c[4];
    VtxRec *nbegin;        // 0x20
    VtxRec *nend;          // 0x24
    char pad28[4];
    UvVec uv[4];           // 0x2c
    UvVec ext[2];          // 0x5c
};
struct Mesh_2e0cc0 {
    char pad0[0x10];
    V3_2e0cc0 *f10;
    V3_2e0cc0 *f14;
    Pair8 *uv[4];          // 0x18
    Entry8 *ext[2];        // 0x28
};
class Model_2e0cc0 {
public:
    char pad0[0x5c];
    Mesh_2e0cc0 *mesh;            // 0x5c
    void FUN_002e0cc0(Src_2e0cc0 *src, char flag);
};
struct Elem16 {
    int id;
    float v[3];
};
struct Elem12_2e1020 {
    int id;
    float v[2];
};
struct Emitter_2e1020 {
    char pad0[0x10];
    void *kindA;
    void *kindB;
    void *slots[6];
    void FUN_002c6eb0(int id, const float *v, int ctx);
    void FUN_002c6ef0(int id, const float *v, int ctx);
    void FUN_002c6f30(int id, const float *v, int k, int ctx);
    void FUN_002c6f70(int id, const float *v, int k, int ctx);
};
struct Lists_2e1020 {
    Elem12_2e1020 *begin;
    Elem12_2e1020 *end;
    Elem12_2e1020 *cap;
};
struct Batch_2e1020 {
    char pad0[0x14];
    Elem16 *aBegin;
    Elem16 *aEnd;
    char pad1c[0x20 - 0x1c];
    Elem16 *bBegin;
    Elem16 *bEnd;
    char pad28[0x2c - 0x28];
    Lists_2e1020 lists[6];
};
class Dispatcher_2e1020 {
public:
    char pad0[0x5c];
    Emitter_2e1020 *emitter;

    void FUN_002e1020(Batch_2e1020 *batch, int ctx, unsigned int mask);
};
struct V3_2e11e0 {
    float x, y, z;
};
struct Delta {
    int vertex;
    float dx, dy, dz;
};
struct DeltaList {
    char pad0[0x14];
    Delta* begin;
    Delta* end;
};
struct VertexBuffer_2e11e0 {
    char pad0[0x10];
    V3_2e11e0* verts;
};
class Morph {
public:
    char pad0[0x5c];
    VertexBuffer_2e11e0* buffer;

    void FUN_002e11e0(DeltaList* list, float weight);
};
extern void* g_vftable_0042fb84[];
class Ref_2e13b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e13b0 {
  public:
    void* vptr;
    void Fin_002a3e90();
};
class PrimGroupLoader_2e13b0 : public RenderObjectLoader_2e13b0 {
  public:
    char pad[4];
    Ref_2e13b0* m;
    ~PrimGroupLoader_2e13b0();
};
extern void* hulk_at_0042fb94[];
class Ref_2e13e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class RenderObjectLoader_2e13e0 {
  public:
    void* vptr;
    void Fin_002a3e90();
};
class OldPrimGroupLoader_2e13e0 : public RenderObjectLoader_2e13e0 {
  public:
    char pad[4];
    Ref_2e13e0* m;
    ~OldPrimGroupLoader_2e13e0();
};
extern void* g_vftable_2e1470[];
} // namespace fn_f1455a33
void operator delete(void*);
namespace fn_f1455a33 {
class Ref_2e1470 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2e1470 {
  public:
    void* vptr;
    void Fin_002a50a0();
};
class PrimGroup_2e1470 : public DrawablePrimitive_2e1470 {
  public:
    char pad[60];
    Ref_2e1470* m;
    PrimGroup_2e1470* f2(unsigned char flags);
};
extern int vt1_2e14b0, vt2;
extern void Free_00263f30(void*);
class Ref_2e14b0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroup_2e14b0 {
  public:
    void* vptr;
    void Fini_002a50a0();
};
class PrimGroupOptimized_2e14b0 : public PrimGroup_2e14b0 {
  public:
    char p[0x3c];
    Ref_2e14b0* a40;
    char q[0x14];
    Ref_2e14b0* a58;
    PrimGroupOptimized_2e14b0* vfunc2(unsigned char f);
};
extern "C" void thunk_FUN_00267090(void*) throw();
struct Ref_2e1530 {
    virtual void a() throw();
    virtual void release() throw();
};
class PrimGroupStreamed_2e1530 {
  public:
    void* vptr;
    char pad[0x3c];
    Ref_2e1530* r40;
    char pad2[0x5c - 0x44];
    Ref_2e1530* r5c;
    PrimGroupStreamed_2e1530* vfunc_2(unsigned char f) throw();
    void Fini_002a50a0() throw();
};
extern void* g_vt_2e15b0[];
class Ref_2e15b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class PrimGroupSkinnedOptimized_2e15b0 {
  public:
    void* vptr;
    void Fin_002e0090();
};
class PrimGroupSkinnedPC_2e15b0 : public PrimGroupSkinnedOptimized_2e15b0 {
  public:
    char pad[104 - 4];
    Ref_2e15b0* m;
    PrimGroupSkinnedPC_2e15b0* f2(unsigned char flags);
};


// 0x002df4d0 FUN_002df4d0 (49 B): matches/0x002df4d0.cpp
// sym: ??0PrimGroup@fn_f1455a33@@QAE@II@Z
PrimGroup::PrimGroup(U_2df4d0 x, U_2df4d0 y) {
    a = 0;
    b = 0;
    c = x;
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042fb54);
    d = y;
    e = 0xffffffff;
}

} // namespace fn_f1455a33

// 0x002df510 pure3d::PrimGroup::vfunc_5 (6 B): matches/0x002df510.cpp
// sym: ?vfunc_5@PrimGroup@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::PrimGroup::vfunc_5() {
    return 1;
}


// 0x002df520 pure3d::PrimGroup::vfunc_7 (4 B): matches/0x002df520.cpp
// sym: ?vfunc_7@PrimGroup@pure3d@@UAEIXZ
// Same code shape as 0x00069100 (propagated; names are from that function)
hulk_uintptr pure3d::PrimGroup::vfunc_7() {
    return (*(unsigned int *)&this->f_40);
}


// 0x002df530 pure3d::PrimGroup::vfunc_9 (14 B): matches/0x002df530.cpp
// sym: ?vfunc_9@PrimGroup@pure3d@@UAEEXZ
unsigned char pure3d::PrimGroup::vfunc_9() {
    if ((*(void * *)&this->f_40))
        return *((unsigned char*)(*(void * *)&this->f_40) + 0x14);
    return 0;
}


// 0x002df540 pure3d::PrimGroupOptimized::vfunc_6 (38 B): matches/0x002df540.cpp
// sym: ?vfunc_6@PrimGroupOptimized@pure3d@@UAEXXZ
void pure3d::PrimGroupOptimized::vfunc_6() {
    int a = (*(void * *)&this->f_40) ? *(int*)((char*)(*(void * *)&this->f_40) + 0x10) : 0;
    hulk_at_0052c2a8->f32(a, (hulk_intptr)(*(void * *)&this->f_58));
}

namespace fn_f1455a33 {

// 0x002df570 pure3d::PrimGroupOptimized::vfunc_10 (1 B): matches/0x002df570.cpp
// sym: ?FUN_002df570@fn_f1455a33@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002df570() {}

} // namespace fn_f1455a33

// 0x002df580 pure3d::PrimGroupSkinnedOptimized::vfunc_3 (3 B): matches/0x002df580.cpp
// sym: ?vfunc_3@PrimGroupSkinnedOptimized@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::PrimGroupSkinnedOptimized::vfunc_3() {
    return true;
}


// 0x002df590 pure3d::PrimGroupStreamed::vfunc_5 (6 B): matches/0x002df590.cpp
// sym: ?vfunc_5@PrimGroupStreamed@pure3d@@UAEHXZ
int pure3d::PrimGroupStreamed::vfunc_5() {
    return 0x81;
}


// 0x002df5a0 pure3d::PrimGroupStreamed::vfunc_6 (227 B): equivalent/0x002df5a0.cpp [wrapped: conflict: pure3d::PrimGroupStreamed]
// sym: ?vfunc_6@PrimGroupStreamed@pure3d@fn_002df5a0@@UAEXXZ @1fb375ed8bf2 @w7442a2382977
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002df5a0 {
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 16/16)
// pure3d::PrimGroupStreamed::vfunc_6 @ 0x002df5a0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Resource_2df5a0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(void*); };
struct Mesh_2df5a0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual int v11(); };
struct Holder_2df5a0 { char pad[16]; Mesh_2df5a0* mesh; };
struct Stream { char pad[8]; unsigned flags; unsigned fallback; unsigned count; };
struct Gfx { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void* v30(Mesh_2df5a0*,unsigned,unsigned,unsigned,int); virtual void v31(void*); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual Resource_2df5a0* v89(int); };
namespace pure3d { struct PrimGroupStreamed { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void vfunc_6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(void*); char pad[60]; Holder_2df5a0* holder; unsigned kind; char pad2[16]; void* binding; Stream* stream; }; }
void pure3d::PrimGroupStreamed::vfunc_6() {
 unsigned flags = stream->flags & 0xfffffe7f;
 if(binding) { Resource_2df5a0* r=DAT_0052c2a8->v89(0x106); if(r) r->v6(binding); }
 Mesh_2df5a0* mesh=holder ? holder->mesh : 0;
 int n=mesh->v11();
 unsigned count=stream->count;
 for(int i=0;i<n;++i) { unsigned size=count; if(!size) size=stream->fallback; void* p=DAT_0052c2a8->v30(mesh,kind,flags,size,i); v12(p); DAT_0052c2a8->v31(p); }
 if(binding) { Resource_2df5a0* r=DAT_0052c2a8->v89(0x106); if(r) r->v6(0); }
}
} // namespace fn_002df5a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002df690 pure3d::PrimGroupStreamed::vfunc_12 (20 B): matches/0x002df690.cpp
// sym: ?vfunc_12@PrimGroupStreamed@pure3d@@UAEXH@Z
void pure3d::PrimGroupStreamed::vfunc_12(int a) {
    (*(Obj_2df690 * *)&this->f_5c)->FUN_002d0950(a, 0, 0);
}


// 0x002df6b0 pure3d::PrimGroupStreamed::vfunc_11 (20 B): matches/0x002df6b0.cpp
// sym: ?vfunc_11@PrimGroupStreamed@pure3d@@UAEXH@Z
// Same code shape as 0x002df690 (propagated; names are from that function)
void pure3d::PrimGroupStreamed::vfunc_11(int a) {
    (*(Obj_2df6b0 * *)&this->f_5c)->FUN(a, 0, 0);
}


// 0x002df6d0 pure3d::PrimGroupSkinnedStreamed::vfunc_5 (6 B): matches/0x002df6d0.cpp
// sym: ?vfunc_5@PrimGroupSkinnedStreamed@pure3d@@UAEHXZ
int pure3d::PrimGroupSkinnedStreamed::vfunc_5() {
    return (int)(0x181);
}


// 0x002df6e0 pure3d::PrimGroupSkinnedStreamed::vfunc_3 (3 B): matches/0x002df6e0.cpp
// sym: ?vfunc_3@PrimGroupSkinnedStreamed@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::PrimGroupSkinnedStreamed::vfunc_3() {
    return true;
}


// 0x002df6f0 pure3d::PrimGroupSkinnedStreamed::vfunc_12 (24 B): matches/0x002df6f0.cpp
// sym: ?vfunc_12@PrimGroupSkinnedStreamed@pure3d@@UAEXH@Z
void pure3d::PrimGroupSkinnedStreamed::vfunc_12(int arg) {
    ((Helper_2df6f0*)(*(hulk_intptr *)&this->f_5c))->go_002d0950(arg, this->f_60, this->f_64);
}


// 0x002df710 pure3d::PrimGroupSkinnedStreamed::vfunc_11 (24 B): matches/0x002df710.cpp
// sym: ?vfunc_11@PrimGroupSkinnedStreamed@pure3d@@UAEXH@Z
// Same code shape as 0x002df6f0 (propagated; names are from that function)
void pure3d::PrimGroupSkinnedStreamed::vfunc_11(int arg) {
    ((Helper_2df710*)(*(hulk_intptr *)&this->f_5c))->go(arg, this->f_60, this->f_64);
}


// 0x002df730 pure3d::PrimGroupSkinnedPC::vfunc_5 (6 B): matches/0x002df730.cpp
// sym: ?vfunc_5@PrimGroupSkinnedPC@pure3d@@UAEHXZ
int pure3d::PrimGroupSkinnedPC::vfunc_5() {
    return (int)(0x101);
}


// 0x002df740 pure3d::PrimGroupSkinnedPC::vfunc_3 (3 B): matches/0x002df740.cpp
// sym: ?vfunc_3@PrimGroupSkinnedPC@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::PrimGroupSkinnedPC::vfunc_3() {
    return true;
}


// 0x002df750 pure3d::PrimGroupSkinnedPC::vfunc_6 (84 B): matches/0x002df750.cpp
// sym: ?vfunc_6@PrimGroupSkinnedPC@pure3d@@UAEXXZ
void pure3d::PrimGroupSkinnedPC::vfunc_6() {
    void* r = (*(Obj_2df750 * *)&this->f_58)->s4();
    (*(Sub_2df750 * *)&this->f_68)->call(r, this->f_60, this->f_64);
    (*(Obj_2df750 * *)&this->f_58)->s5(r);
    (*(Obj_2df750 * *)&this->f_58)->s6();
    void* v = (*(Res_2df750 * *)&this->f_40) ? (*(Res_2df750 * *)&this->f_40)->val : 0;
    gGlobal_2df750->g32(v, (*(Obj_2df750 * *)&this->f_58));
}


// 0x002df7b0 pure3d::VertexAnimPrimGroup::vfunc_5 (6 B): matches/0x002df7b0.cpp
// sym: ?vfunc_5@VertexAnimPrimGroup@pure3d@@UAEHXZ
// Same code shape as 0x002df000 (propagated; names are from that function)
 // namespace pure3d
int pure3d::VertexAnimPrimGroup::vfunc_5() {
    return 0x40;
}


// 0x002df7c0 pure3d::VertexAnimPrimGroup::vfunc_3 (3 B): matches/0x002df7c0.cpp
// sym: ?vfunc_3@VertexAnimPrimGroup@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::VertexAnimPrimGroup::vfunc_3() {
    return true;
}

namespace fn_f1455a33 {

// 0x002df7d0 FUN_002df7d0 (8 B): matches/0x002df7d0.cpp
// sym: ?target@C_2df7d0@fn_f1455a33@@QAEXXZ
void C_2df7d0::target() {
    ((owners::Thing_2c7070 *)member)->FUN_002c7070();
}

} // namespace fn_f1455a33

// 0x002df7e0 FUN_002df7e0 (4 B): matches/0x002df7e0.cpp
// sym: ?FUN_002df7e0@Object_2df7e0@owners@@QAEHXZ
// Same code shape as 0x0025d3e0 (propagated; names are from that function)
hulk_intptr owners::Object_2df7e0::FUN_002df7e0() {
    return mValue;
}

namespace fn_f1455a33 {

// 0x002df7f0 FUN_002df7f0 (58 B): matches/0x002df7f0.cpp
// sym: ??0PrimGroupLoader@fn_f1455a33@@QAE@XZ
PrimGroupLoader::PrimGroupLoader()
    : RenderObjectLoader_2df7f0(), a(0), b(0), c(0), e(0), f0(0), f3(0), f4(0), f5(0), d(1), f1(-1), f2(-1) {}


// 0x002df840 FUN_002df840 (10 B): matches/0x002df840.cpp
// sym: ?vfunc_8@AnimationFrameController@fn_f1455a33@@UAEXH@Z
// Same code shape as 0x00284b50 (propagated; names are from that function)
void AnimationFrameController::vfunc_8(int x) {
    field = x;
}


// 0x002df850 FUN_002df850 (44 B): matches/0x002df850.cpp
// sym: ??0OldPrimGroupLoader@fn_f1455a33@@QAE@XZ
OldPrimGroupLoader::OldPrimGroupLoader() : a(0), b(0), c(-1), d(-1), e(0), f(0), g(0) {}

} // namespace fn_f1455a33

// 0x002df890 FUN_002df890 (10 B): matches/0x002df890.cpp
// sym: ?FUN_002df890@Thing_2df890@owners@@QAEXH@Z
// Same code shape as 0x00083d20 (propagated; names are from that function)
void owners::Thing_2df890::FUN_002df890(int x) {
    value = x;
}

namespace fn_f1455a33 {

// 0x002dfc90 FUN_002dfc90 (65 B): matches/0x002dfc90.cpp
// sym: ?f@Obj_2dfc90@fn_f1455a33@@QAEXPAUSrc_2dfc90@2@PAUData_2dfc90@2@@Z
void Obj_2dfc90::f(Src_2dfc90* s, Data_2dfc90* d) {
    uint n = 0;
    if (d->count > 0) {
        int off = 0;
        do {
            ((owners::Matrix_22ca90 *)(((Other_2dfc90*)((char*)p + off))))->FUN_0022ca90((const owners::Matrix_22ca90 *)(hulk_uintptr)(int)(s->data + off), (const owners::Matrix_22ca90 *)(hulk_uintptr)(int)(d->data + off));
            n++;
            off += 0x40;
        } while (n < d->count);
    }
}

} // namespace fn_f1455a33

// 0x002dfce0 FUN_002dfce0 (86 B): matches/0x002dfce0.cpp [wrapped: conflict: PrimGroup]
// sym: ??0PrimGroup@fn_002dfce0@@QAE@ABV01@@Z
namespace fn_002dfce0 {
class Ref_2dfce0 {
  public:
    virtual void f0();
    virtual void f1();
};
class DrawablePrimitive_2dfce0 {
  public:
    virtual void v();
    DrawablePrimitive_2dfce0(const DrawablePrimitive_2dfce0&);
    char pad[0x3c];
    Ref_2dfce0* ref;
    int a, b, c, d;
};
class PrimGroup : public DrawablePrimitive_2dfce0 {
  public:
    virtual void v();
    PrimGroup(const PrimGroup&);
};
PrimGroup::PrimGroup(const PrimGroup& other) : DrawablePrimitive_2dfce0(other) {
    ref = 0;
    a = other.a;
    b = other.b;
    c = other.c;
    d = other.d;
    Ref_2dfce0* p = other.ref;
    if (p)
        p->f0();
    if (ref)
        ref->f1();
    ref = p;
}
} // namespace fn_002dfce0

namespace fn_f1455a33 {

// 0x002dfd40 FUN_002dfd40 (36 B): matches/0x002dfd40.cpp
// sym: ??1PrimGroup_2dfd40@fn_f1455a33@@QAE@XZ
PrimGroup_2dfd40::~PrimGroup_2dfd40() {
    vptr = hulk_at_0042fb54;
    _ReadWriteBarrier();
    if (m40) {
        m40->Release();
        m40 = 0;
    }
    Fin_002a50a0();
}

} // namespace fn_f1455a33

// 0x002dfd70 pure3d::PrimGroup::vfunc_8 (99 B): matches/0x002dfd70.cpp
// sym: ?vfunc_8@PrimGroup@pure3d@@UAEXPAX@Z
void pure3d::PrimGroup::vfunc_8(void* __p0) { Ref_2dfd70 * r = (Ref_2dfd70 *)__p0;

    if (r)
        r->AddRef();
    if ((*(Ref_2dfd70 * *)&this->f_40))
        (*(Ref_2dfd70 * *)&this->f_40)->Release();
    (*(Ref_2dfd70 * *)&this->f_40) = r;
    if (r && (r->kind == 1 || r->kind == 3 || r->kind == 7 || r->kind == 2 || r->kind == 4 || r->kind == 5 ||
              r->kind == 6)) {
        this->f_10 = 1;
        return;
    }
    this->f_10 = 0;
}

namespace fn_f1455a33 {

// 0x002dfde0 FUN_002dfde0 (52 B): matches/0x002dfde0.cpp
// sym: ??0PrimGroupOptimized@fn_f1455a33@@QAE@HH@Z
PrimGroupOptimized::PrimGroupOptimized(int a, int b) : PrimGroup_2dfde0(a, b) {}

} // namespace fn_f1455a33

// 0x002dfe20 FUN_002dfe20 (93 B): matches/0x002dfe20.cpp [wrapped: conflict: PrimGroupOptimized]
// sym: ??0PrimGroupOptimized@fn_002dfe20@@QAE@PAVRef_2dfe20@1@HH@Z
namespace fn_002dfe20 {
class Ref_2dfe20 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_2dfe20 {
  public:
    Base_2dfe20();
    virtual void f();
    char pad[0x3c];
};
class PrimGroup_2dfe20 : public Base_2dfe20 {
  public:
    int a, b, c, d, e;
    char pad2[4];
    PrimGroup_2dfe20(int x, int y) : Base_2dfe20() {
        a = 0;
        b = 0;
        c = x;
        d = y;
        e = -1;
    }
};
class PrimGroupOptimized : public PrimGroup_2dfe20 {
  public:
    PrimGroupOptimized(Ref_2dfe20*, int, int);
    virtual void f();
    Ref_2dfe20* ref;
    void SetRef(Ref_2dfe20*);
};
inline void PrimGroupOptimized::SetRef(Ref_2dfe20* p) {
    if (p)
        p->AddRef();
    if (ref)
        ref->Release();
    ref = p;
}
PrimGroupOptimized::PrimGroupOptimized(Ref_2dfe20* p, int x, int y) : PrimGroup_2dfe20(x, y) {
    ref = 0;
    SetRef(p);
}
} // namespace fn_002dfe20


// 0x002dfe80 FUN_002dfe80 (210 B): equivalent/0x002dfe80.cpp [wrapped: conflict: pure3d::PrimGroupOptimized]
// sym: ??0PrimGroupOptimized@pure3d@fn_002dfe80@@QAE@PAU012@@Z @255c20588677 @w18456fea3679
namespace fn_002dfe80 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002dfe80 @ 0x002dfe80

struct Resource_2dfe80 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void* lock(); virtual void unlock(void*); char pad[12]; unsigned int value; };
struct Descriptor_2dfe80 { unsigned int kind,width; unsigned char flags[8]; unsigned int count,resource; unsigned char a,b; unsigned short unused; unsigned int zero1,zero2; };
struct Manager_2dfe80 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual Resource_2dfe80* create(Descriptor_2dfe80*); }; 
struct Layout_2dfe80 { char pad[64]; unsigned int f40,kind,width,count,index,f54; Resource_2dfe80* buffer; Resource_2dfe80* sourceResource; void FUN_002a5060(); };
struct Base_2dfe80 { char pad[60]; unsigned int f40,kind,width,count,index,f54; Resource_2dfe80* buffer; Resource_2dfe80* sourceResource;
 Base_2dfe80(Layout_2dfe80* destination,Layout_2dfe80* source) { unsigned int w=source->width,n=source->count; destination->FUN_002a5060(); destination->kind=0; destination->f40=0; destination->width=w; destination->count=n; destination->index=~0u; }
};
namespace pure3d {
struct PrimGroupOptimized : Base_2dfe80 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void copy(void*); PrimGroupOptimized(PrimGroupOptimized* source); };
PrimGroupOptimized::PrimGroupOptimized(PrimGroupOptimized* source) : Base_2dfe80((Layout_2dfe80*)this,(Layout_2dfe80*)source) { buffer=0; kind=source->kind; Descriptor_2dfe80 desc; desc.kind=kind; desc.width=width; for(int i=0;i<7;++i) desc.flags[i]=32; desc.count=count; desc.resource=source->sourceResource ? source->sourceResource->value : 0; desc.a=0; desc.b=0; desc.zero1=0; desc.zero2=0; buffer=(*(Manager_2dfe80**)&DAT_0052c2a0)->create(&desc); void* data=buffer->lock(); source->copy(data); buffer->unlock(data); buffer->s0(); }
}
} // namespace fn_002dfe80

namespace fn_f1455a33 {

// 0x002dffa0 FUN_002dffa0 (61 B): matches/0x002dffa0.cpp
// sym: ??1PrimGroupOptimized_2dffa0@fn_f1455a33@@QAE@XZ
PrimGroupOptimized_2dffa0::~PrimGroupOptimized_2dffa0() throw() {
    vptr = &hulk_at_0042fba4;
    _ReadWriteBarrier();
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    vptr = &vt2_2dffa0;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}


// 0x002dffe0 FUN_002dffe0 (58 B): matches/0x002dffe0.cpp
// sym: ?setup@PrimGroupSkinnedOptimized@fn_f1455a33@@QAEPAV12@HH@Z
PrimGroupSkinnedOptimized* PrimGroupSkinnedOptimized::setup(int x, int y) {
    Init_002a5060();
    a40 = 0;
    a44 = 0;
    a48 = x;
    a4c = y;
    a58 = 0;
    a60 = 0;
    a64 = 0;
    a50 = -1;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042fbd4);
    return this;
}

} // namespace fn_f1455a33

// 0x002e0020 FUN_002e0020 (112 B): matches/0x002e0020.cpp [wrapped: conflict: pure3d::PrimGroupOptimized; pure3d::PrimGroupSkinnedOptimized]
// sym: ??0PrimGroupSkinnedOptimized@pure3d@fn_002e0020@@QAE@ABU012@@Z
namespace fn_002e0020 {
struct Ref_2e0020 {
    virtual void AddRef();
    virtual void Release();
};
struct SP {
    Ref_2e0020* p;
    SP() : p(0) {}
    void operator=(Ref_2e0020* r) {
        if (r)
            r->AddRef();
        if (p)
            p->Release();
        p = r;
    }
};
namespace pure3d {
struct Base_2e0020 {
    virtual void v0();
    Base_2e0020(const Base_2e0020&);
    char pad[0x54];
};
struct PrimGroupOptimized : Base_2e0020 {
    PrimGroupOptimized(const PrimGroupOptimized& o) : Base_2e0020(o) { m58 = o.m58.p; }
    virtual void v1();
    SP m58;
    int m5c;
};
struct PrimGroupSkinnedOptimized : PrimGroupOptimized {
    PrimGroupSkinnedOptimized(const PrimGroupSkinnedOptimized& o);
    virtual void v2();
    int m60;
    SP m64;
};
PrimGroupSkinnedOptimized::PrimGroupSkinnedOptimized(const PrimGroupSkinnedOptimized& o)
    : PrimGroupOptimized(o), m60(0) {
    m64 = o.m64.p;
}
} // namespace pure3d
} // namespace fn_002e0020

namespace fn_f1455a33 {

// 0x002e0090 FUN_002e0090 (93 B): matches/0x002e0090.cpp
// sym: ?Cleanup@PrimGroupSkinnedOptimized_2e0090@fn_f1455a33@@QAEXXZ
void PrimGroupSkinnedOptimized_2e0090::Cleanup() {
    *(void* volatile*)&vptr = &hulk_at_0042fbd4;
    _ReadWriteBarrier();
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    *(void* volatile*)&vptr = &vtOpt;
    _ReadWriteBarrier();
    if (m58) {
        m58->Release();
        m58 = 0;
    }
    *(void* volatile*)&vptr = &vtBase;
    _ReadWriteBarrier();
    if (m40) {
        m40->Release();
        m40 = 0;
    }
    BaseCleanup_002a50a0();
}

} // namespace fn_f1455a33

// 0x002e00f0 pure3d::PrimGroupSkinnedOptimized::vfunc_4 (31 B): matches/0x002e00f0.cpp
// sym: ?vfunc_4@PrimGroupSkinnedOptimized@pure3d@@UAEPAXXZ
// Same code shape as 0x002c3140 (propagated; names are from that function)
void* pure3d::PrimGroupSkinnedOptimized::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return (void*)(((Helper_2e00f0*)p)->run_002e0020(this));
    return (void*)(0);
}

namespace fn_f1455a33 {

// 0x002e0110 pure3d::PrimGroupSkinnedOptimized::vfunc_6 (133 B): matches/0x002e0110.cpp
// sym: ?f6@PrimGroupSkinnedOptimized_2e0110@fn_f1455a33@@QAEXXZ
void PrimGroupSkinnedOptimized_2e0110::f6() {
    PrimGroupOptimized_2e0110* s = ((PrimGroupOptimized_2e0110 *)((owners::Obj_28fad0 *)((*(Manager_2e0110**)&DAT_0052c2b4)))->FUN_0028fad0());
    s->f2();
    Vec_2e0110* vv = &p64->v;
    unsigned n = vv->size();
    s->f4(n);
    for (int i = 0; i < (unsigned)n; ++i) {
        int idx = p64->v.begin[i];
        s->f5(i, (char*)p60->data + (idx << 6));
    }
    void* x = p40 ? *((void**)p40 + 4) : 0;
    s->f6(x, p58);
    s->f3();
}


// 0x002e01a0 FUN_002e01a0 (38 B): matches/0x002e01a0.cpp
// sym: ?Set@Owner_2e01a0@fn_f1455a33@@QAEXPAVThing_2e01a0@2@@Z
// Same code shape as 0x000e9100 (propagated; names are from that function)
void Owner_2e01a0::Set(Thing_2e01a0* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}


// 0x002e02a0 FUN_002e02a0 (61 B): matches/0x002e02a0.cpp
// sym: ??1PrimGroupStreamed_2e02a0@fn_f1455a33@@QAE@XZ
PrimGroupStreamed_2e02a0::~PrimGroupStreamed_2e02a0() throw() {
    vptr = &hulk_at_0042fc04;
    _ReadWriteBarrier();
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    vptr = &vt2_2e02a0;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}


// 0x002e02e0 pure3d::PrimGroupStreamed::vfunc_10 (334 B): equivalent/0x002e02e0.cpp
// sym: ?FUN_002e02e0@PrimGroupStreamed@fn_f1455a33@@QAEXXZ @7b31b05b0084 @wcfb71da60cae
// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 12/12)
// pure3d::PrimGroupStreamed::vfunc_10 @ 0x002e02e0
void PrimGroupStreamed::FUN_002e02e0()
{
    V3_2e02e0 *pts = mesh->points;
    Xform_2e02e0 *xf = mesh->xform;
    V4_2e02e0 tmp; // scratch point (x,y,z); FUN_000a8890 then reuses it as its 4-float output
    if (xf && xf->offset) {
        V3_2e02e0 *off = xf->offset;
        bounds.lo.x = off->x + pts->x;
        bounds.lo.y = pts->y + off->y;
        bounds.lo.z = pts->z + off->z;
        bounds.hi.x = off->x + pts->x;
        bounds.hi.y = pts->y + off->y;
        bounds.hi.z = pts->z + off->z;
        for (unsigned int i = 1; i < count; i++) {
            tmp.x = pts[i].x + off->x;
            tmp.y = pts[i].y + off->y;
            tmp.z = off->z + pts[i].z;
            ((owners::V_a87f0 *)&bounds)->FUN_000a87f0((owners::V_a87f0 *)(V3_2e02e0 *)((V3_2e02e0 *)&tmp));
        }
    } else {
        bounds.lo = *pts;
        bounds.hi = *pts;
        for (unsigned int i = 1; i < count; i++)
            ((owners::V_a87f0 *)&bounds)->FUN_000a87f0((owners::V_a87f0 *)(V3_2e02e0 *)(&pts[i]));
    }
    sphere = *bounds.FUN_000a8890(&tmp);
}

} // namespace fn_f1455a33

// 0x002e0460 FUN_002e0460 (118 B): matches/0x002e0460.cpp [wrapped: conflict: PrimGroup]
// sym: ??0PrimGroupSkinnedStreamed_2e0460@fn_002e0460@@QAE@ABV01@@Z
namespace fn_002e0460 {
class Ref_2e0460 {
  public:
    virtual void f0();
    virtual void f1();
};
class PrimGroup {
  public:
    virtual void v();
    PrimGroup(const PrimGroup&);
    char pad[0x54];
};
class PrimGroupStreamed_2e0460 : public PrimGroup {
  public:
    virtual void v();
    PrimGroupStreamed_2e0460(const PrimGroupStreamed_2e0460& o) : PrimGroup(o) {
        r1 = 0;
        x58 = o.x58;
        Ref_2e0460* p = o.r1;
        if (p)
            p->f0();
        if (r1)
            r1->f1();
        r1 = p;
    }
    int x58;
    Ref_2e0460* r1;
};
class PrimGroupSkinnedStreamed_2e0460 : public PrimGroupStreamed_2e0460 {
  public:
    virtual void v();
    PrimGroupSkinnedStreamed_2e0460(const PrimGroupSkinnedStreamed_2e0460& o);
    int x60;
    Ref_2e0460* r2;
};
PrimGroupSkinnedStreamed_2e0460::PrimGroupSkinnedStreamed_2e0460(const PrimGroupSkinnedStreamed_2e0460& o) : PrimGroupStreamed_2e0460(o) {
    x60 = 0;
    r2 = 0;
    Ref_2e0460* p = o.r2;
    if (p)
        p->f0();
    if (r2)
        r2->f1();
    r2 = p;
}
} // namespace fn_002e0460

namespace fn_f1455a33 {

// 0x002e04e0 FUN_002e04e0 (93 B): matches/0x002e04e0.cpp
// sym: ??1PrimGroupSkinnedStreamed_2e04e0@fn_f1455a33@@QAE@XZ
PrimGroupSkinnedStreamed_2e04e0::~PrimGroupSkinnedStreamed_2e04e0() throw() {
    vptr = &hulk_at_0042fc3c;
    _ReadWriteBarrier();
    if (a60) {
        a60->Release();
        a60 = 0;
    }
    if (a64) {
        a64->Release();
        a64 = 0;
    }
    vptr = &vt2_2e04e0;
    _ReadWriteBarrier();
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    vptr = &vt3;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}

} // namespace fn_f1455a33

// 0x002e0540 pure3d::PrimGroupSkinnedStreamed::vfunc_4 (31 B): matches/0x002e0540.cpp
// sym: ?vfunc_4@PrimGroupSkinnedStreamed@pure3d@@UAEPAXXZ
// Same code shape as 0x002c3140 (propagated; names are from that function)
void* pure3d::PrimGroupSkinnedStreamed::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return (void*)(((Helper_2e0540*)p)->run_002e0460(this));
    return (void*)(0);
}

namespace fn_f1455a33 {

// 0x002e0560 pure3d::PrimGroupSkinnedStreamed::vfunc_10 (129 B): equivalent/0x002e0560.cpp
// sym: ?FUN_002e0560@PrimGroupSkinnedStreamed_2e0560@fn_f1455a33@@QAEXXZ @08192263b622 @wf0efb442da58
// STATUS: equivalent (tools/equiv.py level 3: 16764 inputs, branch coverage 4/4)
// pure3d::PrimGroupSkinnedStreamed::vfunc_10 @ 0x002e0560
// 0x002e0560: PrimGroupSkinnedStreamed::vfunc_10: rebuild the bounding box and sphere from the skin points
void PrimGroupSkinnedStreamed_2e0560::FUN_002e0560()
{
    Sphere_2e0560 tmp;
    const Vec3_2e0560* pts = skin->points;
    box.lo = pts[0];
    box.hi = pts[0];
    for (unsigned int i = 1; i < count; i++)
        ((owners::V_a87f0 *)&box)->FUN_000a87f0((owners::V_a87f0 *)(const Vec3_2e0560 *)(&pts[i]));
    const Sphere_2e0560* s = box.FUN_000a8890(&tmp);
    sphere = *s;
}


// 0x002e05f0 FUN_002e05f0 (38 B): matches/0x002e05f0.cpp
// sym: ?Set@Owner_2e05f0@fn_f1455a33@@QAEXPAVThing_2e05f0@2@@Z
// Same code shape as 0x000e9100 (propagated; names are from that function)
void Owner_2e05f0::Set(Thing_2e05f0* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}

} // namespace fn_f1455a33

// 0x002e0620 FUN_002e0620 (117 B): equivalent/0x002e0620.cpp [wrapped: conflict: pure3d::PrimGroupSkinnedPC]
// sym: ??0PrimGroupSkinnedPC@pure3d@fn_002e0620@@QAE@HHH@Z @49f15f9a28b7 @wafe9e12ba565
namespace fn_002e0620 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e0620 @ 0x002e0620
// equiv-map: ??0Base@@QAE@XZ = 0x002a5060
class PrimGroupSkinnedOptimized_2e0620 {
public:
    PrimGroupSkinnedOptimized_2e0620();
    virtual void f0();
    char pad4[0x40 - 4];
};

class VertexList_2e0620 {
public:
    VertexList_2e0620 *FUN_002c86d0(int a, int b, int c);
    virtual void f0();
};

extern "C" void *__cdecl FUN_0008d690(unsigned int n);

namespace pure3d {
class PrimGroupSkinnedPC : public PrimGroupSkinnedOptimized_2e0620 {
public:
    PrimGroupSkinnedPC(int a, int b, int c);
    virtual void f0();
    int f40, f44, f48, f4c, f50;
    char pad54[4];
    int f58;
    char pad5c[4];
    int f60, f64;
    VertexList_2e0620 *f68;
};
}

pure3d::PrimGroupSkinnedPC::PrimGroupSkinnedPC(int a, int b, int c)
{
    f40 = 0;
    f44 = 0;
    f48 = a;
    f4c = b;
    f50 = -1;
    f58 = 0;
    f60 = 0;
    f64 = 0;
    VertexList_2e0620 *s = 0;
    void *mem = FUN_0008d690(0x5c);
    if (mem != 0)
        s = ((VertexList_2e0620 *)mem)->FUN_002c86d0(a, b, 0);
    f68 = s;
    s->f0();
}
} // namespace fn_002e0620

namespace fn_f1455a33 {

// 0x002e06e0 FUN_002e06e0 (36 B): matches/0x002e06e0.cpp
// sym: ??1PrimGroupSkinnedPC_2e06e0@fn_f1455a33@@QAE@XZ
PrimGroupSkinnedPC_2e06e0::~PrimGroupSkinnedPC_2e06e0() throw() {
    vptr = &hulk_at_0042fc74;
    _ReadWriteBarrier();
    if (child) {
        child->Release();
        child = 0;
    }
}

} // namespace fn_f1455a33

// 0x002e0710 pure3d::PrimGroupSkinnedPC::vfunc_4 (79 B): matches/0x002e0710.cpp
// sym: ?vfunc_4@PrimGroupSkinnedPC@pure3d@@UAEPAXXZ
void* pure3d::PrimGroupSkinnedPC::vfunc_4() {
    pure3d::PrimGroupSkinnedPC* p = (pure3d::PrimGroupSkinnedPC*)alloc_00263ea0(0x70);
    if (p) {
        ((PrimGroupSkinnedPC_nv_2e0710*)(p))->init_002e0020(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042fc74);
        *(unsigned int*)((char*)p + 0x68) = 0;
        Ref_2e0710* r = (*(Ref_2e0710 * *)&this->f_68);
        if (r)
            r->f0();
        Ref_2e0710* q = *(Ref_2e0710**)((char*)p + 0x68);
        if (q)
            q->f1();
        *(Ref_2e0710**)((char*)p + 0x68) = r;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x002e0760 FUN_002e0760 (284 B): equivalent/0x002e0760.cpp [wrapped: conflict: pure3d::VertexAnimPrimGroup]
// sym: ?init@VertexAnimPrimGroup@pure3d@fn_002e0760@@QAEPAU123@PAUSource_2e0760@3@@Z @66c199a06ffe @w1e9657556cb0
inline void* __cdecl operator new(size_t, void* address) { return address; }
namespace fn_002e0760 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e0760 @ 0x002e0760
/* size_t: tree_prelude.h */

struct Ref_2e0760 { virtual void AddRef(); virtual void Release(); };
struct Six { unsigned a[6]; }; struct Four_2e0760 { unsigned a[4]; };
struct Source_2e0760 { virtual void AddRef(); virtual void Release(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual Ref_2e0760* GetRef(); char pad[12]; unsigned type; Six six; Four_2e0760 four; unsigned field3c; Ref_2e0760* resource; unsigned value44; unsigned value48; unsigned value4c; unsigned FUN_002a50b0(); };
namespace pure3d { struct VertexAnimPrimGroup { virtual void slot0(); char pad[12]; unsigned type; Six six; Four_2e0760 four; unsigned field3c; Ref_2e0760* resource; unsigned value44; unsigned value48; unsigned value4c; unsigned value50; unsigned value54; Source_2e0760* source; unsigned value5c; void FUN_002a5060(); VertexAnimPrimGroup* init(Source_2e0760* other); }; }
pure3d::VertexAnimPrimGroup* pure3d::VertexAnimPrimGroup::init(Source_2e0760* other) { unsigned a=other->value48, b=other->value4c; FUN_002a5060(); resource=0; value44=0; value48=a; value4c=b; value50=~0u; new (this) VertexAnimPrimGroup(*this); source=0; value5c=0; type=other->FUN_002a50b0(); Six s=other->six; six=s; Four_2e0760 f=other->four; four=f; value44=other->value44; Ref_2e0760* r=other->GetRef(); if(r) r->AddRef(); if(resource) resource->Release(); resource=r; other->AddRef(); if(source) source->Release(); source=other; return this; }
} // namespace fn_002e0760


// 0x002e0880 FUN_002e0880 (349 B): equivalent/0x002e0880.cpp [wrapped: conflict: pure3d::DrawablePrimitive; pure3d::VertexAnimPrimGroup]
// sym: ??0VertexAnimPrimGroup@pure3d@fn_002e0880@@QAE@ABV012@@Z @5fe3702df030 @w383340219818
namespace fn_002e0880 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_002e0880 @ 0x002e0880
extern "C" void *FUN_0008d690(unsigned int size);

struct Vec3_2e0880 { float x, y, z; };

class RefObj_2e0880 {
public:
    virtual void AddRef();
    virtual void Release();
};

class VertexOffsetList_2e0880 : public RefObj_2e0880 {
public:
    char pad04[0x2c];
    VertexOffsetList_2e0880 *FUN_002c84a0(VertexOffsetList_2e0880 *other);
};

class Provider_2e0880 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual RefObj_2e0880 *v4();
};

namespace pure3d {

class __declspec(novtable) DrawablePrimitive {
public:
    virtual void v0();
    char pad04[0xc];
    void *f10;
    Vec3_2e0880 bmin;
    Vec3_2e0880 bmax;
    float plane[4];
    char pad3c[4];
    RefObj_2e0880 *obj40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[4];
    Provider_2e0880 *prov58;
    VertexOffsetList_2e0880 *sub5c;
    void FUN_002a5060();
    void *FUN_002a50b0();
    DrawablePrimitive(int a, int b)
    {
        FUN_002a5060();
        obj40 = 0;
        f44 = 0;
        f48 = a;
        f4c = b;
        f50 = -1;
        prov58 = 0;
        sub5c = 0;
    }
};

class VertexAnimPrimGroup : public DrawablePrimitive {
public:
    VertexAnimPrimGroup(const VertexAnimPrimGroup &src);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual RefObj_2e0880 *v7();

};

VertexAnimPrimGroup::VertexAnimPrimGroup(const VertexAnimPrimGroup &src) : DrawablePrimitive(src.f48, src.f4c)
{
    f10 = ((DrawablePrimitive &)src).FUN_002a50b0();
    bmin = src.bmin;
    bmax = src.bmax;
    plane[0] = src.plane[0];
    plane[1] = src.plane[1];
    plane[2] = src.plane[2];
    plane[3] = src.plane[3];
    f44 = src.f44;

    RefObj_2e0880 *o = ((VertexAnimPrimGroup &)src).v7();
    if (o)
        o->AddRef();
    if (obj40)
        obj40->Release();
    obj40 = o;

    RefObj_2e0880 *p = src.prov58->v4();
    if (p)
        p->AddRef();
    if (prov58)
        ((RefObj_2e0880 *)prov58)->Release();
    prov58 = (Provider_2e0880 *)p;

    if (src.sub5c) {
        VertexOffsetList_2e0880 *mem = (VertexOffsetList_2e0880 *)FUN_0008d690((int)sizeof(VertexOffsetList_2e0880));
        VertexOffsetList_2e0880 *s;
        if (mem)
            s = mem->FUN_002c84a0(src.sub5c);
        else
            s = 0;
        sub5c = s;
        s->AddRef();
    }
    f50 = src.f50;
}

}
} // namespace fn_002e0880

namespace fn_f1455a33 {

// 0x002e09e0 FUN_002e09e0 (87 B): matches/0x002e09e0.cpp
// sym: ??1VertexAnimPrimGroup_2e09e0@fn_f1455a33@@QAE@XZ
VertexAnimPrimGroup_2e09e0::~VertexAnimPrimGroup_2e09e0() throw() {
    vptr = &hulk_at_0042fca4;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    if (a5c) {
        a5c->Release();
        a5c = 0;
    }
    vptr = &vt2_2e09e0;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}

} // namespace fn_f1455a33

// 0x002e0a40 pure3d::VertexAnimPrimGroup::vfunc_4 (31 B): matches/0x002e0a40.cpp
// sym: ?vfunc_4@VertexAnimPrimGroup@pure3d@@UAEPAXXZ
// Same code shape as 0x002a7540 (propagated; names are from that function)
void* pure3d::VertexAnimPrimGroup::vfunc_4() {
    pure3d::VertexAnimPrimGroup* self = this;
    Other_2e0a40* p = (Other_2e0a40*)allocate(0x60);
    if (p)
        return (void*)(p->helper_002e0880(self));
    return (void*)(0);
}


// 0x002e0a60 pure3d::VertexAnimPrimGroup::vfunc_6 (175 B): equivalent/0x002e0a60.cpp [wrapped: conflict: pure3d::VertexAnimPrimGroup]
// sym: ?vfunc_6@VertexAnimPrimGroup@pure3d@fn_002e0a60@@UAEXXZ @faccdc66046c @w5e7bbac17ee1
namespace fn_002e0a60 {
// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 16/16)
// pure3d::VertexAnimPrimGroup::vfunc_6 @ 0x002e0a60
struct Ref_2e0a60 {
 virtual void vfunc_0();
 virtual void vfunc_1();
};
struct State_2e0a60 { char pad[0x58]; Ref_2e0a60* current; };
struct Renderer_2e0a60 {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual Ref_2e0a60* vfunc_7();
 virtual void vfunc_8(Ref_2e0a60*);
 char pad[0x58];
 State_2e0a60* state;
};
namespace pure3d {
struct VertexAnimPrimGroup {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 char pad0[0x3c];
 Ref_2e0a60* material;
 char pad1[0x14];
 Renderer_2e0a60* renderer;
 Ref_2e0a60* animation;
};
void VertexAnimPrimGroup::vfunc_6() {
 Renderer_2e0a60* r = renderer;
 State_2e0a60* state = r->state;
 Ref_2e0a60* previous = state->current;
 Ref_2e0a60* saved = r->vfunc_7();
 if (previous) previous->vfunc_0();
 Ref_2e0a60* replacement = animation;
 if (replacement) replacement->vfunc_0();
 if (state->current) state->current->vfunc_1();
 state->current = replacement;
 if (saved) saved->vfunc_0();
 renderer->vfunc_8(material);
 renderer->vfunc_6();
 renderer->vfunc_8(saved);
 if (saved) saved->vfunc_1();
 if (previous) previous->vfunc_0();
 if (state->current) state->current->vfunc_1();
 state->current = previous;
 if (previous) previous->vfunc_1();
}
}
} // namespace fn_002e0a60

namespace fn_f1455a33 {

// 0x002e0b10 pure3d::VertexAnimPrimGroup::vfunc_10 (418 B): equivalent/0x002e0b10.cpp
// sym: ?vfunc_10@VertexAnimPrimGroup@fn_f1455a33@@UAEXXZ @c300801cd508 @w8cbf077e5cad
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// pure3d::VertexAnimPrimGroup::vfunc_10 @ 0x002e0b10
void VertexAnimPrimGroup::vfunc_10()
{
    Holder_2e0b10 *holder = prim->holder;
    Ref_2e0b10 *old = holder->ref;
    if (old)
        old->addRef();
    Ref_2e0b10 *mine = ref;
    if (mine)
        mine->addRef();
    if (holder->ref)
        holder->ref->release();
    holder->ref = mine;

    Block6 save14 = prim->b14;
    Block4_2e0b10 save2c = prim->b2c;
    prim->vfunc_10();
    b14 = prim->b14;
    b2c = prim->b2c;
    prim->b14 = save14;
    prim->b2c = save2c;

    if (old)
        old->addRef();
    if (holder->ref)
        holder->ref->release();
    holder->ref = old;
    if (old)
        old->release();
}


// 0x002e0cc0 FUN_002e0cc0 (857 B): equivalent/0x002e0cc0.cpp
// sym: ?FUN_002e0cc0@Model_2e0cc0@fn_f1455a33@@QAEXPAUSrc_2e0cc0@2@D@Z @463c7c630fe2 @w5911e9b57f25
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 38/38)
// FUN_002e0cc0 @ 0x002e0cc0
void Model_2e0cc0::FUN_002e0cc0(Src_2e0cc0 *src, char flag)
{
    if (flag == 1)
        ((owners::Thing_2c7070 *)mesh)->FUN_002c7070();
    unsigned int i;
    if (mesh->f10 != 0) {
        hulk_uintptr n = src->vend - src->vbegin;
        for (i = 0; i < n; i++) {
            VtxRec *e = &src->vbegin[i];
            int idx = e->idx;
            V3_2e0cc0 *d = &mesh->f10[idx];
            d->x = e->v.x;
            d->y = e->v.y;
            d->z = e->v.z;
        }
    }
    if (mesh->f14 != 0) {
        hulk_uintptr n = src->nend - src->nbegin;
        for (i = 0; i < n; i++) {
            VtxRec *e = &src->nbegin[i];
            int idx = e->idx;
            V3_2e0cc0 *d = &mesh->f14[idx];
            d->x = e->v.x;
            d->y = e->v.y;
            d->z = e->v.z;
        }
    }
    int k;
    for (k = 0; k < 4; k++) {
        if (mesh->uv[k] != 0) {
            hulk_intptr n = src->uv[k].end - src->uv[k].begin;
            for (int j = 0; j < n; j++) {
                UvRec *e = &src->uv[k].begin[j];
                Pair8 *base = mesh->uv[k];
                int a = e->a;
                int idx = e->idx;
                base[idx].a = a;
                base[idx].b = e->b;
            }
        }
    }
    for (k = 0; k < 2; k++) {
        if (mesh->ext[k] != 0) {
            hulk_intptr n = src->ext[k].end - src->ext[k].begin;
            for (int j = 0; j < n; j++) {
                UvRec *e = &src->ext[k].begin[j];
                ((owners::S_2c6d60 *)&(mesh->ext[k][e->idx]))->FUN_002c6d60((const owners::S_2c6d60 *)(&e->a));
            }
        }
    }
}


// 0x002e1020 FUN_002e1020 (438 B): equivalent/0x002e1020.cpp
// sym: ?FUN_002e1020@Dispatcher_2e1020@fn_f1455a33@@QAEXPAUBatch_2e1020@2@HI@Z @7f56559f8309 @wd99ac8899263
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 35/36, incomplete)
// FUN_002e1020 @ 0x002e1020
void Dispatcher_2e1020::FUN_002e1020(Batch_2e1020 *batch, int ctx, unsigned int mask)
{
    if (emitter->kindA && (mask & 0x10)) {
        hulk_uintptr n = batch->aEnd - batch->aBegin;
        if (n != 0) {
            for (unsigned int i = 0; i != n; i++) {
                Elem16 *e = &batch->aBegin[i];
                emitter->FUN_002c6eb0(e->id, e->v, ctx);
            }
        }
    }
    if (emitter->kindB && (mask & 0x20)) {
        hulk_uintptr n = batch->bEnd - batch->bBegin;
        if (n != 0) {
            for (unsigned int i = 0; i != n; i++) {
                Elem16 *e = &batch->bBegin[i];
                emitter->FUN_002c6ef0(e->id, e->v, ctx);
            }
        }
    }
    for (int k = 0; k < 4; k++) {
        if (emitter->slots[k] && (mask & (1 << k))) {
            hulk_uintptr n = batch->lists[k].end - batch->lists[k].begin;
            if (n != 0) {
                for (unsigned int i = 0; i != n; i++) {
                    Elem12_2e1020 *e = &batch->lists[k].begin[i];
                    emitter->FUN_002c6f30(e->id, e->v, k, ctx);
                }
            }
        }
    }
    for (int k = 0; k < 2; k++) {
        if (emitter->slots[4 + k] && (mask & (0x40 << k))) {
            hulk_uintptr n = batch->lists[4 + k].end - batch->lists[4 + k].begin;
            if (n != 0) {
                for (unsigned int i = 0; i != n; i++) {
                    Elem12_2e1020 *e = &batch->lists[4 + k].begin[i];
                    emitter->FUN_002c6f70(e->id, e->v, k, ctx);
                }
            }
        }
    }
}


// 0x002e11e0 FUN_002e11e0 (453 B): equivalent/0x002e11e0.cpp
// sym: ?FUN_002e11e0@Morph@fn_f1455a33@@QAEXPAUDeltaList@2@M@Z @a10e3e8d341e @w988b15a5c4cd
// STATUS: equivalent (tools/equiv.py level 3: 22 inputs, branch coverage 8/8)
// FUN_002e11e0 @ 0x002e11e0
// Adds weight * delta to each referenced vertex.
void Morph::FUN_002e11e0(DeltaList* list, float weight)
{
    hulk_intptr count = list->end - list->begin;
    for (unsigned i = 0; i < (unsigned)count; i++) {
        const Delta* d = &list->begin[i];
        float x = weight * d->dx;
        float y = weight * d->dy;
        float z = weight * d->dz;
        V3_2e11e0* v = &buffer->verts[d->vertex];
        v->x += x;
        v->y += y;
        v->z += z;
    }
}


// 0x002e13b0 FUN_002e13b0 (36 B): matches/0x002e13b0.cpp
// sym: ??1PrimGroupLoader_2e13b0@fn_f1455a33@@QAE@XZ
PrimGroupLoader_2e13b0::~PrimGroupLoader_2e13b0() {
    vptr = g_vftable_0042fb84;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a3e90();
}


// 0x002e13e0 FUN_002e13e0 (36 B): matches/0x002e13e0.cpp
// sym: ??1OldPrimGroupLoader_2e13e0@fn_f1455a33@@QAE@XZ
OldPrimGroupLoader_2e13e0::~OldPrimGroupLoader_2e13e0() {
    vptr = hulk_at_0042fb94;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a3e90();
}


// 0x002e1440 FUN_002e1440 (40 B): matches/0x002e1440.cpp
// sym: _FUN_002e1440
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002e1440(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}


// 0x002e1470 pure3d::PrimGroup::vfunc_2 (57 B): matches/0x002e1470.cpp
// sym: ?f2@PrimGroup_2e1470@fn_f1455a33@@QAEPAV12@E@Z
PrimGroup_2e1470* PrimGroup_2e1470::f2(unsigned char flags) {
    vptr = g_vftable_2e1470;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a50a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x002e14b0 pure3d::PrimGroupOptimized::vfunc_2 (82 B): matches/0x002e14b0.cpp
// sym: ?vfunc2@PrimGroupOptimized_2e14b0@fn_f1455a33@@QAEPAV12@E@Z
PrimGroupOptimized_2e14b0* PrimGroupOptimized_2e14b0::vfunc2(unsigned char f) {
    vptr = &vt1_2e14b0;
    _ReadWriteBarrier();
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    vptr = &vt2;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
    Fini_002a50a0();
    if (f & 1)
        Free_00263f30(this);
    return this;
}

} // namespace fn_f1455a33

// 0x002e1510 pure3d::PrimGroupSkinnedOptimized::vfunc_2 (30 B): matches/0x002e1510.cpp
// sym: ??_GPrimGroupSkinnedOptimized@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::PrimGroupSkinnedOptimized::~PrimGroupSkinnedOptimized() {}

namespace fn_f1455a33 {

// 0x002e1530 pure3d::PrimGroupStreamed::vfunc_2 (82 B): matches/0x002e1530.cpp
// sym: ?vfunc_2@PrimGroupStreamed_2e1530@fn_f1455a33@@QAEPAV12@E@Z
PrimGroupStreamed_2e1530* PrimGroupStreamed_2e1530::vfunc_2(unsigned char f) throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if (r5c) {
        r5c->release();
        r5c = 0;
    }
    vptr = vB;
    _ReadWriteBarrier();
    if (r40) {
        r40->release();
        r40 = 0;
    }
    Fini_002a50a0();
    if (f & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f1455a33

// 0x002e1590 pure3d::PrimGroupSkinnedStreamed::vfunc_2 (30 B): matches/0x002e1590.cpp
// sym: ??_GPrimGroupSkinnedStreamed@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::PrimGroupSkinnedStreamed::~PrimGroupSkinnedStreamed() {}

namespace fn_f1455a33 {

// 0x002e15b0 pure3d::PrimGroupSkinnedPC::vfunc_2 (57 B): matches/0x002e15b0.cpp
// sym: ?f2@PrimGroupSkinnedPC_2e15b0@fn_f1455a33@@QAEPAV12@E@Z
PrimGroupSkinnedPC_2e15b0* PrimGroupSkinnedPC_2e15b0::f2(unsigned char flags) {
    vptr = g_vt_2e15b0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002e0090();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f1455a33

// 0x002e15f0 pure3d::VertexAnimPrimGroup::vfunc_2 (30 B): matches/0x002e15f0.cpp
// sym: ??_GVertexAnimPrimGroup@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::VertexAnimPrimGroup::~VertexAnimPrimGroup() {}

