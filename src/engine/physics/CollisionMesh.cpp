// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f32b0..0x002f4df0 (kind game, layer engine, confidence high), dominant class physics::CollisionMesh
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f77c5fbc {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f77c5fbc {} using namespace fn_f77c5fbc;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f77c5fbc {
union FloatBits_2f32b0 {
    float f;
    unsigned int u;
};
struct CollisionVolume_2f33c0 {
    virtual void f0();
    CollisionVolume_2f33c0();
};
struct WorldCollisionVolume_2f33c0 : CollisionVolume_2f33c0 {
    WorldCollisionVolume_2f33c0();
    virtual void f0();
};
class ParamValue_2f3620 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class X_2f37c0 {
    char pad[0x44];

  public:
    int m;
    hulk_intptr __fastcall f();
};
struct Vec { float x,y,z; };
struct Temp { float x,y,z; char extra[4]; void FUN_0022dfe0(const Vec*,const Vec*,const Vec*); };
struct Indices { char pad[16]; unsigned short a,b,c; };
struct Buffer { char pad[8]; Vec* vertices; };
struct Object { char pad[0x44]; Buffer* buffer; Vec* FUN_002f37d0(Vec* result, const Indices* indices); };
struct Vec3_2f3830 {
    float x, y, z;
    void FUN_0022dfe0(const Vec3_2f3830* a, const Vec3_2f3830* b, const Vec3_2f3830* c);
};
struct Xform_2f3830 { char data[0x80];  };
struct VertexBuf_2f3830 { char pad[8]; Vec3_2f3830* verts; };
struct Tri_2f3830 { char pad[0x10]; unsigned short a, b, c; };
class Mesh_2f3830 {
public:
    char pad0[0x44];
    VertexBuf_2f3830* vb;
    char pad1[4];
    Xform_2f3830 xf;
    char transformed;
    Vec3_2f3830* GetNormal(Vec3_2f3830* out, const Tri_2f3830* t);
};
class CollisionMesh {
  public:
    char pad[0x44];
    struct Data {
        char a[8];
        int* vertices;
        char b[12];
        unsigned short* indices;
    }* data;
    void vfunc_18(int, int*, int*, int*);
};
extern "C" int __cdecl FUN_0034483c();
struct Block_2f39e0 {
    unsigned int x[16];
};
void __fastcall Helper(Block_2f39e0*);
struct Obj_2f39e0 {
    char pad[0x4c];
    Block_2f39e0 a;
    Block_2f39e0 b;
    unsigned char flag;
    int count;
    void Target(Block_2f39e0* p);
};
typedef unsigned short ushort_2f3ac0;
extern void* CollisionVolume_2f3bb0_vftable[];
class CollisionVolume_2f3bb0 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class WorldCollisionVolume_2f3bb0 : public CollisionVolume_2f3bb0 {
  public:
    WorldCollisionVolume_2f3bb0* vfunc_5(signed char flags);
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_0043147c[];
typedef unsigned int u32_2f3c00;
extern void ReleaseThing(u32_2f3c00);
class Other_2f3c00 {
  public:
    void Do(int);
};
class SharedData {
  public:
    hulk_uintptr vft;
    u32_2f3c00 pad;
    u32_2f3c00 a;
    u32_2f3c00 b;
    u32_2f3c00 c;
    u32_2f3c00 d;
    Other_2f3c00* e;
};
void Free(void* p);
void Free2(void* p);
struct Ref_2f3cd0 {
    virtual void a() throw();
    virtual void release() throw();
};
class CollisionMesh_2f3cd0 {
  public:
    void* vptr;
    char pad[0x40];
    Ref_2f3cd0* ref;
    void Fini() throw();
    void dtor() throw();
};
struct Rec_2f3db0 { int w[6]; Rec_2f3db0* FUN_00298530(void* a, void* b); };
struct Inner_2f3db0 { char pad[0x24]; Rec_2f3db0 rec; };
struct CollisionMesh_2f3db0 {
    char pad0[0x44]; Inner_2f3db0* inner;
    char pad1[0xcc - 0x48]; char flag;
    Rec_2f3db0 Get();
};
struct Vec3_2f3e40 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
union FloatBits_2f3e40 {
    float f;
    unsigned int u;
};
struct Segment_2f3e40 {
    Vec3_2f3e40 a;
    Vec3_2f3e40 b;
};
struct ClipOut {
    Vec3_2f3e40 a;
    Vec3_2f3e40 b;
    Vec3_2f3e40 start;
    Vec3_2f3e40 dir;
};
struct Bounds_2f3e40 {
    char pad00[0x24];
    Vec3_2f3e40 origin;
    char pad30[0x3c - 0x30];
    Vec3_2f3e40 scale;
};
void fix(unsigned short*, int, int, int);
static __forceinline void SwapIfLess(unsigned short *a, unsigned short *b)
{
    if (*a < *b) {
        unsigned short t = *a;
        *a = *b;
        *b = t;
    }
}
static __forceinline void Med3(unsigned short *first, unsigned short *mid, unsigned short *last)
{
    SwapIfLess(mid, first);
    SwapIfLess(last, mid);
    SwapIfLess(mid, first);
}
typedef unsigned short u16_2f4350;
void FUN_002f40f0(u16_2f4350*, hulk_intptr, hulk_intptr, u16_2f4350);
typedef unsigned short ushort_2f4590;
extern void FUN_002f3b10(ushort_2f4590*, ushort_2f4590*, ushort_2f4590*, int, int);
void __cdecl FUN_002f40f0(unsigned short *, int, hulk_intptr, unsigned int);
struct Range_2f46a0 { unsigned short* first; unsigned short* second; };
extern "C++" __declspec(nothrow) void * __cdecl FUN_002f43f0(void *, unsigned short *, unsigned short *);
extern "C" void __cdecl FUN_002f4590(unsigned short *, unsigned short *);
void __cdecl FUN_002f4350(unsigned short* first, unsigned short* last, int, int);
extern "C" void __cdecl FUN_002f4650(unsigned short *, unsigned short *);

} // namespace fn_f77c5fbc

// 0x002f32b0 FUN_002f32b0 (162 B): equivalent/0x002f32b0.cpp
// sym: ?FUN_002f32b0@Axis_2f32b0@owners@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f32b0 @ 0x002f32b0
// FUN_002f32b0 @ 0x002f32b0: snaps a direction vector to the dominant axis when one component is near +-1
void owners::Axis_2f32b0::FUN_002f32b0()
{
    FloatBits_2f32b0 a;
    a.f = x;
    a.u &= 0x7fffffff;
    dominant = 0;
    if (a.f > 0.9999f) {
        dominant = 2;
        x = 1.0f;
        z = 0.0f;
        y = 0.0f;
        return;
    }
    FloatBits_2f32b0 b;
    b.f = y;
    b.u &= 0x7fffffff;
    if (b.f > 0.9999f) {
        dominant = 3;
        x = 0.0f;
        y = 1.0f;
        z = 0.0f;
        return;
    }
    FloatBits_2f32b0 c;
    c.f = z;
    c.u &= 0x7fffffff;
    if (c.f > 0.9999f) {
        dominant = 4;
        x = 0.0f;
        z = 1.0f;
        y = 0.0f;
    }
}


// 0x002f3360 FUN_002f3360 (90 B): matches/0x002f3360.cpp
// sym: ?FUN_002f3360@Box_2f3360@owners@@QAEEPAU12@@Z
unsigned char owners::Box_2f3360::FUN_002f3360(owners::Box_2f3360* b) {
    return b->v[3] >= v[0] && b->v[0] <= v[3] && b->v[4] >= v[1] && b->v[1] <= v[4] && b->v[5] >= v[2] &&
           b->v[2] <= v[5];
}

namespace fn_f77c5fbc {

// 0x002f33c0 FUN_002f33c0 (18 B): matches/0x002f33c0.cpp
// sym: ??0WorldCollisionVolume_2f33c0@fn_f77c5fbc@@QAE@XZ
WorldCollisionVolume_2f33c0::WorldCollisionVolume_2f33c0() {}


// 0x002f33e0 physics::CollisionVolume::vfunc_6 (3 B): matches/0x002f33e0.cpp
// sym: ?GetZero@fn_f77c5fbc@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f77c5fbc

// 0x002f33f0 physics::CollisionVolume::vfunc_11 (3 B): matches/0x002f33f0.cpp
// sym: ?vfunc_11@CollisionVolume@physics@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::CollisionVolume::vfunc_11(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x002f3530 FUN_002f3530 (177 B): equivalent/0x002f3530.cpp [wrapped: conflict: physics::CollisionMesh]
// sym: ??0CollisionMesh@physics@fn_002f3530@@QAE@XZ
void* __cdecl operator new(size_t);
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002f3530 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 2/2)
// FUN_002f3530 @ 0x002f3530
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

typedef unsigned int uint;
  

extern void* __cdecl FUN_002f2750(unsigned __int64);
struct Matrix { char bytes[64]; void FUN_0022b980(); };
struct FUN_003060a0 { virtual void baseVirtual(); char bytes[52]; FUN_003060a0(); };
namespace physics {
struct CollisionMesh : FUN_003060a0 {
 virtual void meshVirtual();
 uint a,b,c;
 struct SharedData {
 virtual void initialize();
 uint a,b; char pad[8]; uint c,d; unsigned short e,f,g; char tail[50];
 };
 SharedData* shared; void* material; Matrix m1,m2;
 unsigned char flag; char pad[3]; uint id;
 CollisionMesh();
};
}
physics::CollisionMesh::CollisionMesh() {
 a=0;b=0;c=0;flag=0;
 (*(void**)&DAT_0055543c)=((char*)((char*)&DAT_00554c30 + 2056)); (*(void**)&DAT_00555440)=((char*)((char*)&DAT_00554c30 + 8));
 SharedData* p=new SharedData;
 if(p) { p->a=0;p->b=0;p->c=0;p->d=0;p->e=0;p->f=0;p->g=0; }
 shared=p; shared->initialize();
 material=FUN_002f2750(FUN_0027b020("concrete"));
 m1.FUN_0022b980(); m2.FUN_0022b980();
 id=(*(uint*)&DAT_00555448)+0x3d70000; (*(uint*)&DAT_00555448)=id;
}
} // namespace fn_002f3530
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002f35f0 physics::CollisionMesh::vfunc_5 (3 B): matches/0x002f35f0.cpp
// sym: ?vfunc_5@CollisionMesh@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::CollisionMesh::vfunc_5(int a, int b) {}


// 0x002f3600 physics::CollisionMesh::vfunc_4 (7 B): matches/0x002f3600.cpp
// sym: ?vfunc_4@CollisionMesh@physics@@UAEHXZ
 // namespace physics
hulk_intptr physics::CollisionMesh::vfunc_4() {
    return this->f_44 + 0x48;
}


// 0x002f3610 physics::CollisionMesh::vfunc_3 (7 B): matches/0x002f3610.cpp
// sym: ?vfunc_3@CollisionMesh@physics@@UAEHXZ
// Same code shape as 0x002f3600 (propagated; names are from that function)
 // namespace physics
hulk_intptr physics::CollisionMesh::vfunc_3() {
    return this->f_44 + 0x48;
}


// 0x002f3620 physics::CollisionMesh::vfunc_6 (6 B): matches/0x002f3620.cpp
// sym: ?vfunc_6@CollisionMesh@physics@@UAEHXZ
// Same code shape as 0x00055210 (propagated; names are from that function)
int physics::CollisionMesh::vfunc_6() {
    return 4;
}


// 0x002f3630 FUN_002f3630 (125 B): equivalent/0x002f3630.cpp [wrapped: conflict: physics::CollisionMesh]
// sym: ??0CollisionMesh@physics@fn_002f3630@@QAE@ABV012@@Z
namespace fn_002f3630 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f3630 @ 0x002f3630
// equiv-map: ??0MeshBase@@QAE@XZ = 0x003060a0

class Ref_2f3630 {
public:
    virtual void vfunc_0();
};

class WorldCollisionVolume_2f3630 {
public:
    WorldCollisionVolume_2f3630() throw();
    virtual void vfunc_0();
    char pad04[0x34];
};

namespace physics {
class CollisionMesh : public WorldCollisionVolume_2f3630 {
public:
    int f38, f3c, f40;
    Ref_2f3630* ref;               // 0x44
    int f48;
    int block4c[16];        // 0x4c
    int block8c[16];        // 0x8c
    char flagCC;            // 0xcc
    char padcd[3];
    int fD0;
    CollisionMesh(const CollisionMesh& other) throw();
    virtual void vfunc_0();
};
}

physics::CollisionMesh::CollisionMesh(const CollisionMesh& other) throw()
{
    f38 = other.f38;
    f3c = other.f3c;
    f40 = other.f40;
    ref = other.ref;
    f48 = other.f48;
    flagCC = other.flagCC;
    for (int i = 0; i < 16; i++)
        block4c[i] = other.block4c[i];
    for (int i = 0; i < 16; i++)
        block8c[i] = other.block8c[i];
    fD0 = other.fD0;
    if (ref)
        ref->vfunc_0();
}
} // namespace fn_002f3630


// 0x002f36c0 physics::CollisionMesh::vfunc_17 (241 B): matches/0x002f36c0.cpp [wrapped: conflict: physics::CollisionMesh]
// sym: ?vfunc_17@CollisionMesh@physics@fn_002f36c0@@QAE_NPBUVec_2f36c0@3@I@Z
namespace fn_002f36c0 {

struct Vec_2f36c0 {
    float x, y, z;
    void FUN_0022d210(const void*);
};
struct Triangle_2f36c0 {
    char data[24];
    void FUN_002fb190(Vec_2f36c0*, void*, unsigned int);
};
struct MeshData_2f36c0 {
    char pad[24];
    Triangle_2f36c0* triangles;
};
struct Query_2f36c0 {
    char pad[8];
    unsigned short* begin;
    unsigned short* end;
    void FUN_002f91e0();
    void FUN_002fa1f0(Vec_2f36c0*, void*);
};
struct Reset_2f36c0 {
    void FUN_003037e0();
};
struct Context {
    char pad[0x1b0];
    Reset_2f36c0 reset;
};
namespace physics {
struct CollisionMesh {
    virtual void v0();
    char pad[0x40];
    MeshData_2f36c0* mesh;
    char pad2[0x44];
    char transform[0x40];
    unsigned char transformed;
    bool vfunc_17(const Vec_2f36c0*, unsigned int);
};
} // namespace physics
bool physics::CollisionMesh::vfunc_17(const Vec_2f36c0* input, unsigned int flags) {
    if (flags & 0x10)
        (*(Context**)&DAT_00554c14)->reset.FUN_003037e0();
    Vec_2f36c0 point = *input;
    if (transformed)
        point.FUN_0022d210(transform);
    Query_2f36c0 q;
    q.FUN_002f91e0();
    Vec_2f36c0 bounds[2];
    bounds[0] = point;
    bounds[1] = point;
    bounds[0].y = -1.0e12f;
    *(*(unsigned short**)&DAT_0055543c) = 0;
    q.begin = (*(unsigned short**)&DAT_00555440);
    q.end = (*(unsigned short**)&DAT_00555440);
    q.FUN_002fa1f0(bounds, this);
    for (unsigned short* p = q.begin; p != q.end; ++p)
        mesh->triangles[*p].FUN_002fb190(&point, this, flags);
    return true;
}
} // namespace fn_002f36c0

namespace fn_f77c5fbc {

// 0x002f37c0 FUN_002f37c0 (7 B): matches/0x002f37c0.cpp
// sym: ?f@X_2f37c0@fn_f77c5fbc@@QAIHXZ
hulk_intptr __fastcall X_2f37c0::f() {
    return m + 0x24;
}


// 0x002f37d0 FUN_002f37d0 (86 B): equivalent/0x002f37d0.cpp
// sym: ?FUN_002f37d0@Object@fn_f77c5fbc@@QAEPAUVec@2@PAU32@PBUIndices@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 13512 inputs, branch coverage 0/0)
// FUN_002f37d0 @ 0x002f37d0
// FUN_002f37d0 @ 0x002f37d0
Vec* Object::FUN_002f37d0(Vec* result, const Indices* indices)
{
    Temp temp;
    Vec* vertices = buffer->vertices;
    temp.FUN_0022dfe0(vertices + indices->a, vertices + indices->b, vertices + indices->c);
    result->x = temp.x;
    result->y = temp.y;
    result->z = temp.z;
    return result;
}


// 0x002f3830 FUN_002f3830 (152 B): equivalent/0x002f3830.cpp
// sym: ?GetNormal@Mesh_2f3830@fn_f77c5fbc@@QAEPAUVec3_2f3830@2@PAU32@PBUTri_2f3830@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 2/2)
// FUN_002f3830 @ 0x002f3830
Vec3_2f3830* Mesh_2f3830::GetNormal(Vec3_2f3830* out, const Tri_2f3830* t)
{
    Vec3_2f3830* v = vb->verts;
    Vec3_2f3830 res;
    Vec3_2f3830 tmp;
    Vec3_2f3830* pa = v + t->a;
    Vec3_2f3830* pb = v + t->b;
    Vec3_2f3830* pc = v + t->c;
    if (transformed) {
        tmp.FUN_0022dfe0(pa, pb, pc);
        ((owners::M_22c3b0 *)&xf)->FUN_0022c3b0((float *)(const Vec3_2f3830 *)(&tmp), (float *)(Vec3_2f3830 *)(&res));
    } else {
        tmp.FUN_0022dfe0(pa, pb, pc);
        res = tmp;
    }
    *out = res;
    return out;
}


// 0x002f38d0 physics::CollisionMesh::vfunc_18 (139 B): matches/0x002f38d0.cpp
// sym: ?vfunc_18@CollisionMesh@fn_f77c5fbc@@QAEXHPAH00@Z
void CollisionMesh::vfunc_18(int n, int* a, int* b, int* c) {
    int off = (n * 3) * 8;
    unsigned short k = *(unsigned short*)((char*)data->indices + off + 16);
    int* p = data->vertices + k * 3;
    a[0] = p[0];
    a[1] = p[1];
    a[2] = p[2];
    k = *(unsigned short*)((char*)data->indices + off + 18);
    p = data->vertices + k * 3;
    b[0] = p[0];
    b[1] = p[1];
    b[2] = p[2];
    k = *(unsigned short*)((char*)data->indices + off + 20);
    p = data->vertices + k * 3;
    c[0] = p[0];
    c[1] = p[1];
    c[2] = p[2];
}

} // namespace fn_f77c5fbc

// 0x002f3960 FUN_002f3960 (125 B): equivalent/0x002f3960.cpp
// sym: ?FUN_002f3960@Quantizer_2f3960@owners@@QAEXPAGPBM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f3960 @ 0x002f3960
// Quantizes three floats (last component first) into 16-bit values.
void owners::Quantizer_2f3960::FUN_002f3960(unsigned short *out, const float *in)
{
    for (int i = 2; i >= 0; i--) {
        float v = (in[i] - scale[9 + i]) * scale[15 + i];
        if (v <= 0.0f)
            out[i] = 0;
        else if (v > 65535.0f)
            out[i] = 0xffff;
        else
            out[i] = (unsigned short)(int)v;
    }
}

namespace fn_f77c5fbc {

// 0x002f39e0 FUN_002f39e0 (71 B): matches/0x002f39e0.cpp
// sym: ?Target@Obj_2f39e0@fn_f77c5fbc@@QAEXPAUBlock_2f39e0@2@@Z
void Obj_2f39e0::Target(Block_2f39e0* p) {
    Block_2f39e0* dst = &a;
    Block_2f39e0* src = p;
    *dst = *src;
    b = a;
    Helper(&b);
    flag = 1;
    count = count + 1;
}


// 0x002f3ac0 FUN_002f3ac0 (80 B): matches/0x002f3ac0.cpp
// sym: ?FUN_002f3ac0@fn_f77c5fbc@@YAXPAGHHG@Z
void FUN_002f3ac0(ushort_2f3ac0* a, int b, int c, ushort_2f3ac0 d) {
    int i = (b - 1) / 2;
    if (c < b) {
        do {
            ushort_2f3ac0 v = a[i];
            if (v >= d)
                break;
            a[b] = v;
            b = i;
            i = (b - 1) / 2;
        } while (c < b);
    }
    a[b] = d;
}


// 0x002f3b10 FUN_002f3b10 (151 B): equivalent/0x002f3b10.cpp
// sym: ?FUN_002f3b10@fn_f77c5fbc@@YAXPAF00@Z
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 17/18, incomplete)
// FUN_002f3b10 @ 0x002f3b10
// std::rotate for a range of 2-byte elements (cycle-leader algorithm)
void FUN_002f3b10(short *first, short *middle, short *last)
{
    int shift = (int)(middle - first);
    int total = (int)(last - first);
    int cycles = total;
    for (int factor = shift; factor != 0;) {
        int rem = cycles % factor;
        cycles = factor;
        factor = rem;
    }
    if (cycles < total) {
        for (; cycles > 0; --cycles) {
            short *hole = first + cycles;
            short *next = hole;
            short holeValue = *hole;
            short *next1 = (next + shift == last) ? first : next + shift;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                int left = (int)(last - next1);
                next1 = (shift < left) ? next1 + shift : first + (shift - left);
            }
            *next = holeValue;
        }
    }
}


// 0x002f3bb0 physics::WorldCollisionVolume::vfunc_2 (36 B): matches/0x002f3bb0.cpp
// sym: ?vfunc_5@WorldCollisionVolume_2f3bb0@fn_f77c5fbc@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
WorldCollisionVolume_2f3bb0* WorldCollisionVolume_2f3bb0::vfunc_5(signed char flags) {
    *(void***)this = CollisionVolume_2f3bb0_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f77c5fbc

// 0x002f3be0 physics::CollisionMesh::SharedData::vfunc_2 (30 B): matches/0x002f3be0.cpp
// sym: ??_GSharedData@CollisionMesh@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::CollisionMesh::SharedData::~SharedData() {}

namespace fn_f77c5fbc {

// 0x002f3c00 FUN_002f3c00 (95 B): matches/0x002f3c00.cpp
// sym: ?FUN_002f3c00@fn_f77c5fbc@@YIXPAVSharedData@1@@Z
void __fastcall FUN_002f3c00(SharedData* p) {
    p->vft = ((hulk_intptr)DAT_0043147c);
    if (p->a)
        ReleaseThing(p->a);
    if (p->b)
        ReleaseThing(p->b);
    if (p->c)
        ReleaseThing(p->c);
    if (p->d)
        ReleaseThing(p->d);
    if (p->e)
        p->e->Do(3);
    p->vft = ((hulk_intptr)DAT_003f6098);
}

} // namespace fn_f77c5fbc

// 0x002f3c60 FUN_002f3c60 (97 B): matches/0x002f3c60.cpp
// sym: ?FUN_002f3c60@T_2f3c60@owners@@QAEPAU12@E@Z
owners::T_2f3c60* owners::T_2f3c60::FUN_002f3c60(unsigned char f) {
    if (f & 2) {
        int n = ((int*)this)[-1];
        owners::T_2f3c60* p = this + n;
        while (--n >= 0) {
            --p;
            p->Dtor();
        }
        if (f & 1)
            Free((int*)this - 1);
        return (owners::T_2f3c60*)((int*)this - 1);
    }
    Dtor();
    if (f & 1)
        Free2(this);
    return this;
}

namespace fn_f77c5fbc {

// 0x002f3cd0 FUN_002f3cd0 (42 B): matches/0x002f3cd0.cpp
// sym: ?dtor@CollisionMesh_2f3cd0@fn_f77c5fbc@@QAEXXZ
void CollisionMesh_2f3cd0::dtor() throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if (ref) {
        ref->release();
        ref = 0;
    }
    vptr = vB;
    Fini();
}

} // namespace fn_f77c5fbc

// 0x002f3d00 physics::CollisionMesh::vfunc_16 (174 B): equivalent/0x002f3d00.cpp [wrapped: conflict: physics::CollisionMesh]
// sym: ?vfunc_16@CollisionMesh@physics@fn_002f3d00@@UAE_NPBUVec_2f3d00@3@0PAX@Z
namespace fn_002f3d00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::CollisionMesh::vfunc_16 @ 0x002f3d00
struct Vec_2f3d00 { float x,y,z; };
struct CollisionRay_2f3d00 { char data[0x84]; void FUN_00306ef0(const Vec_2f3d00*,const Vec_2f3d00*,float); void FUN_00306fb0(); };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

namespace physics { struct CollisionMesh {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual bool vfunc_15(CollisionRay_2f3d00*,void*); virtual bool vfunc_16(const Vec_2f3d00*,const Vec_2f3d00*,void*);
}; }
bool physics::CollisionMesh::vfunc_16(const Vec_2f3d00* start,const Vec_2f3d00* end,void* out) {
Vec_2f3d00 direction;
 double dx=(double)end->x-start->x;
 double dy=(double)end->y-start->y;
 direction.z=end->z-start->z;
 float length=(float)sqrt((double)(end->z-start->z)*direction.z+dx*dx+dy*dy);
 volatile float inverse=1.0f/length;
 direction.x=(float)(dx*inverse); direction.y=(float)(dy*inverse); direction.z*=inverse;
 CollisionRay_2f3d00 ray; ray.FUN_00306ef0(start,&direction,length);
 bool result=vfunc_15(&ray,out);
 ray.FUN_00306fb0(); return result;
}
} // namespace fn_002f3d00

namespace fn_f77c5fbc {

// 0x002f3db0 FUN_002f3db0 (138 B): matches/0x002f3db0.cpp
// sym: ?Get@CollisionMesh_2f3db0@fn_f77c5fbc@@QAE?AURec_2f3db0@2@XZ
// FUN_002f3db0 @ 0x002f3db0
Rec_2f3db0 CollisionMesh_2f3db0::Get() {
    if (flag) {
        Rec_2f3db0 tmp;
        tmp.FUN_00298530((char*)this + 0x4c, &inner->rec);
        return tmp;
    }
    return inner->rec;
}

} // namespace fn_f77c5fbc

// 0x002f3e40 FUN_002f3e40 (563 B): equivalent/0x002f3e40.cpp
// sym: ?FUN_002f3e40@CollisionMesh@physics@@QAEXPAX0@Z
// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 27/28, incomplete)
// FUN_002f3e40 @ 0x002f3e40
void physics::CollisionMesh::FUN_002f3e40(void* __p0, void* __p1) { ClipOut * out = (ClipOut *)__p0; const Segment_2f3e40 * seg = (const Segment_2f3e40 *)__p1;

    Bounds_2f3e40 *bd = (*(Bounds_2f3e40 * *)&this->f_44);
    float tmin;
    double tmax;
    int axis;
    float *s;
    float *dp;

    out->a.x = seg->a.x - bd->origin.x;
    out->a.y = seg->a.y - bd->origin.y;
    out->a.z = seg->a.z - bd->origin.z;
    out->a.x = bd->scale.x * out->a.x;
    out->a.y = out->a.y * bd->scale.y;
    out->a.z = out->a.z * bd->scale.z;
    out->b.x = seg->b.x - bd->origin.x;
    out->b.y = seg->b.y - bd->origin.y;
    out->b.z = seg->b.z - bd->origin.z;
    out->b.x = bd->scale.x * out->b.x;
    out->b.y = bd->scale.y * out->b.y;
    out->b.z = bd->scale.z * out->b.z;
    out->start = out->a;
    out->dir.x = out->b.x - out->a.x;
    out->dir.y = out->b.y - out->a.y;
    out->dir.z = out->b.z - out->a.z;

    tmax = out->dir.FUN_0022d110();
    if (tmax == 0.0f) {
        return;
    }
    if (out->a.x >= 0.0f && out->a.y >= 0.0f && out->a.z >= 0.0f && out->b.x <= 65535.0f &&
        out->b.y <= 65535.0f && out->b.z <= 65535.0f) {
        return;
    }

    tmin = 0.0f;
    s = &out->start.z;
    dp = &out->dir.z;
    for (axis = 0; axis < 3; axis++) {
        FloatBits_2f3e40 bits;
        bits.f = *dp;
        bits.u &= 0x7fffffff;
        if (bits.f >= 1e-5f) {
            double inv = 1.0f / *dp;
            float t0 = (float)-(inv * *s);
            double t1 = (65535.0f - *s) * inv;
            float t1f = (float)t1;
            if (t0 > t1) {
                if (t1 > tmin) {
                    tmin = (float)t1;
                }
                if (t0 < tmax) {
                    tmax = t0;
                }
            } else {
                if (t0 > tmin) {
                    tmin = t0;
                }
                if (t1 < tmax) {
                    tmax = t1f;
                }
            }
        }
        s--;
        dp--;
    }

    out->a.x = tmin * out->dir.x + out->start.x;
    out->a.y = tmin * out->dir.y + out->start.y;
    out->a.z = tmin * out->dir.z + out->start.z;
    out->b.x = tmax * out->dir.x + out->start.x;
    out->b.y = tmax * out->dir.y + out->start.y;
    out->b.z = tmax * out->dir.z + out->start.z;
}

namespace fn_f77c5fbc {

// 0x002f40f0 FUN_002f40f0 (96 B): matches/0x002f40f0.cpp
// sym: ?sift@fn_f77c5fbc@@YAXPAGHHH@Z
void sift(unsigned short* a, int i, hulk_intptr n, int x) {
    int orig = i;
    int child;
    while ((child = i * 2 + 2) < n) {
        if (a[child] < a[child - 1])
            --child;
        a[i] = a[child];
        i = child;
    }
    if (child == n) {
        a[i] = a[n - 1];
        i = n - 1;
    }
    fix(a, i, orig, x);
}

} // namespace fn_f77c5fbc

// 0x002f41a0 physics::CollisionMesh::vfunc_2 (63 B): matches/0x002f41a0.cpp [wrapped: merged class would differ: CollisionMesh: nested type with a declarator]
// sym: ?vfunc_2@CollisionMesh@fn_002f41a0@@UAEPAV12@E@Z
namespace fn_002f41a0 {
extern "C" void _ReadWriteBarrier();
extern char meshVT[];
extern char worldVT[];
class WorldCollisionVolume {
  public:
    void Cleanup();
};
class CollisionMesh {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CollisionMesh* vfunc_2(unsigned char flag);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    char pad[0x40];
    void* mMember;
};
class Ref_2f41a0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern void ReleaseMesh(CollisionMesh*);

CollisionMesh* CollisionMesh::vfunc_2(unsigned char flag) {
    *(void**)this = (void*)meshVT;
    _ReadWriteBarrier();
    if (mMember) {
        ((Ref_2f41a0*)mMember)->Release();
        mMember = 0;
    }
    *(void**)this = (void*)worldVT;
    ((WorldCollisionVolume*)this)->Cleanup();
    if (flag & 1)
        ReleaseMesh(this);
    return this;
}
} // namespace fn_002f41a0

namespace fn_f77c5fbc {

// 0x002f41e0 FUN_002f41e0 (362 B): matches/0x002f41e0.cpp
// sym: _FUN_002f41e0
// FUN_002f41e0 @ 0x002f41e0
extern "C" void __cdecl FUN_002f41e0(unsigned short *first, unsigned short *mid, unsigned short *last)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        Med3(first, first + step, first + 2 * step);
        Med3(mid - step, mid, mid + step);
        Med3(last - 2 * step, last - step, last);
        Med3(first + step, mid, last - step);
    } else {
        Med3(first, mid, last);
    }
}


// 0x002f4350 FUN_002f4350 (59 B): matches/0x002f4350.cpp
// sym: ?FUN_002f4350@fn_f77c5fbc@@YAXPAG0@Z
void FUN_002f4350(u16_2f4350* first, u16_2f4350* last) {
    hulk_intptr count = ((char*)last - (char*)first) >> 1;
    hulk_intptr i = count / 2;
    while (i > 0) {
        --i;
        u16_2f4350 v = first[i];
        FUN_002f40f0(first, i, count, v);
    }
}

} // namespace fn_f77c5fbc

// 0x002f43f0 FUN_002f43f0 (355 B): equivalent/0x002f43f0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_002f43f0
namespace fn_002f43f0 {
// STATUS: equivalent (tools/equiv.py level 3: 28 inputs, branch coverage 37/42, incomplete)
// FUN_002f43f0 @ 0x002f43f0
struct UShortRange {
    unsigned short* first;
    unsigned short* last;
};

extern "C++" __declspec(nothrow) void FUN_002f41e0(unsigned short* a, unsigned short* b, unsigned short* c);

static void SwapU16(unsigned short* a, unsigned short* b)
{
    unsigned short t = *a;
    *a = *b;
    *b = t;
}

// std::_Partition for unsigned short, with equal-range grouping; returns the
// range of elements equal to the median-of-three pivot.
extern "C" void * FUN_002f43f0(void * out, unsigned short* first, unsigned short* last)
{
    int n = (int)(last - first);
    unsigned short* mid = first + n / 2;
    FUN_002f41e0(first, mid, last - 1);

    unsigned short* pmid = mid;
    while (first < pmid && !(pmid[-1] < *pmid) && !(*pmid < pmid[-1]))
        --pmid;
    unsigned short* pfirst = mid + 1;
    while (pfirst < last && !(*pmid < *pfirst) && !(*pfirst < *pmid))
        ++pfirst;

    unsigned short* gfirst = pfirst;
    unsigned short* glast = pmid;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (*pmid < *gfirst) {
            } else if (*gfirst < *pmid) {
                break;
            } else {
                SwapU16(pfirst, gfirst);
                ++pfirst;
            }
        }
        for (; first < glast; --glast) {
            if (glast[-1] < *pmid) {
            } else if (*pmid < glast[-1]) {
                break;
            } else {
                --pmid;
                SwapU16(pmid, glast - 1);
            }
        }
        if (glast == first) {
            if (gfirst == last) {
                ((UShortRange *)out)->last = pfirst;
                ((UShortRange *)out)->first = pmid;
                return (UShortRange *)((UShortRange *)out);
            }
            if (pfirst != gfirst)
                SwapU16(pfirst, pmid);
            SwapU16(pmid, gfirst);
            ++pfirst;
            ++pmid;
            ++gfirst;
        } else {
            --glast;
            if (gfirst == last) {
                --pmid;
                if (glast != pmid)
                    SwapU16(glast, pmid);
                --pfirst;
                SwapU16(pmid, pfirst);
            } else {
                SwapU16(gfirst, glast);
                ++gfirst;
            }
        }
    }
}
} // namespace fn_002f43f0

namespace fn_f77c5fbc {

// 0x002f4590 FUN_002f4590 (114 B): matches/0x002f4590.cpp
// sym: _FUN_002f4590
extern "C" void FUN_002f4590(unsigned short * first, unsigned short * last) {
    ushort_2f4590* cur;
    ushort_2f4590* next;
    if (first != last) {
        cur = first + 1;
        if (cur != last) {
            next = first + 2;
            do {
                ushort_2f4590 value = *cur;
                ushort_2f4590* pos = first;
                if (value < *first) {
                    if (pos != cur && cur != next)
                        FUN_002f3b10(pos, cur, next, 0, 0);
                } else {
                    ushort_2f4590* prev = next - 2;
                    if (value < *prev) {
                        do {
                            pos = prev;
                            prev = pos - 1;
                        } while (value < *prev);
                        if (pos != cur && cur != next)
                            FUN_002f3b10(pos, cur, next, 0, 0);
                    }
                }
                cur++;
                next++;
            } while (cur != last);
        }
    }
}


// 0x002f4650 FUN_002f4650 (69 B): equivalent/0x002f4650.cpp
// sym: _FUN_002f4650
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_002f4650 @ 0x002f4650
extern "C" void __cdecl FUN_002f4650(unsigned short *first, unsigned short *last)
{
    hulk_intptr bytes = (char *)last - (char *)first;
    while ((bytes >> 1) > 1) {
        unsigned int saved = *(unsigned short *)((char *)first + bytes - 2);
        *(unsigned short *)((char *)first + bytes - 2) = *first;
        FUN_002f40f0(first, 0, (bytes - 2) >> 1, saved);
        bytes -= 2;
    }
}


// 0x002f46a0 FUN_002f46a0 (202 B): equivalent/0x002f46a0.cpp
// sym: _FUN_002f46a0
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_002f46a0 @ 0x002f46a0
extern "C" void __cdecl FUN_002f46a0(unsigned short* first, unsigned short* last, int depth) {
 while (last-first > 32) {
  if (depth <= 0) {
   if (last-first > 1) FUN_002f4350(first,last,0,0);
   FUN_002f4650(first,last);
   return;
  }
  Range_2f46a0 split;
  FUN_002f43f0((Range_2f46a0 *)(&split),first,last);
  depth = depth/2 + (depth/2)/2;
  if (split.first-first < last-split.second) {
   FUN_002f46a0(first,split.first,depth);
   first=split.second;
  } else {
   FUN_002f46a0(split.second,last,depth);
   last=split.first;
  }
 }
 if (last-first > 1) FUN_002f4590(first,last);
}


// 0x002f4790 FUN_002f4790 (26 B): matches/0x002f4790.cpp
// sym: ?wrapper@fn_f77c5fbc@@YAXHH@Z
void wrapper(hulk_intptr a, hulk_intptr b) {
    FUN_002f46a0((unsigned short *)(hulk_uintptr)(int)a, (unsigned short *)(hulk_uintptr)(int)b, (b - a) >> 1);
}

} // namespace fn_f77c5fbc
