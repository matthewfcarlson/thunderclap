// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027f2a0..0x002843c0 (kind game, layer engine, confidence high), dominant class pure3d::prop::CMotionTrail
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f4890d4c {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_f4890d4c {} using namespace fn_f4890d4c;
#include "engine/pure3d/prop.h"

// ---- declarations shared by the functions below
namespace fn_f4890d4c {
struct Worker_27f2a0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void Run(int, int);
};
struct Manager_27f2a0 {
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
    virtual void Do0(int);
    virtual void Do2(int);
    virtual void Do1(int, int);
};
struct Holder_27f2a0 {
    Manager_27f2a0* mgr;
};
struct Obj_27f2a0 {
    char pad0[0x20];
    int field20;
    char pad24[0x3c];
    Manager_27f2a0* field60;
    void* field64;
    char pad68[8];
    unsigned field70;
    void target(int, int);
};
struct Entry {
    int key;
    char pad[0x44];
    int active;
    int unused;
    int a;
    int b;
    char tail[8];
};
class Manager {
    char pad[0x18];
    Entry entries[100];

  public:
    bool Set(int key, int a, int b);
};
class Obj_27f380 {
  public:
    char pad[0x18];
    struct E {
        int key;
        char p[0x44];
        int active;
        char q[0x14];
    } entries[100];
    int tail;
    void f(int);
};
struct Entry_27f3c0 {
    int key;
    char pad[0x44];
    int occupied;
    char tail[0x14];
};
struct Block_27f3c0 {
    int x[16];
};
class Manager_27f3c0 {
  public:
    char pad[0x18];
    Entry_27f3c0 entries[100];
    int Update(int key, Block_27f3c0* source);
};
struct Item_27f410 {
    int key;
    char pad[0x44];
    int flag;
    char tail[0x14];
};
struct Caller_27f410 {
    char pad[0x20];
};
struct Obj_27f410 {
    char pad[0x18];
    Item_27f410 items[100];
    int run(int key, int arg);
};
} // namespace fn_f4890d4c
struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void SetTexture(int handle, int value);                         // slot 32
    virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61();
    virtual void SetFlag(char on);                                          // slot 62
    virtual char GetFlag();                                                 // slot 63
};
namespace fn_f4890d4c {
struct Resource_27f4a0 {
    char pad0[0x10];
    int handle;             // 0x10
};
struct Slot_27f4a0 {
    Resource_27f4a0 *resource;     // 0x0
    char pad4[0xc];
    int value;              // 0x10
    char pad14[8];
};
class Ring_27f4a0 {
public:
    char pad0[0x10];
    unsigned int cursor;    // 0x10
    int count;              // 0x14
    char pad18[0x28 - 0x18];
    Slot_27f4a0 slots[100];        // 0x28

    void FUN_0027f4a0();
};
class Obj_27f5a0 {
  public:
    Obj_27f5a0();
};
struct Vec3_27f5f0 { float x,y,z; };
struct Vertex_27f5f0 { Vec3_27f5f0 position; Vec3_27f5f0 normal; };
struct Geometry {
 Vec3_27f5f0* FUN_001b5860(Vec3_27f5f0* result, int index);
 Vec3_27f5f0* FUN_001b56a0(int index, int corner);
};
struct Context { char pad[0x594]; Geometry geometry; };
extern "C" void * __cdecl FUN_001b6580(void);
class Buffer_27f6f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(void*);
};
class Conv {
  public:
};
struct Obj_27f6f0 {
    char p0[4];
    void* a;
    unsigned int index;
    char p1[4];
    Buffer_27f6f0* buffer;
    char p2[0x14];
};
extern "C" char DAT_0042c48c[];
typedef unsigned int u32_27f830;
extern void __cdecl thunk_FUN_00267090(u32_27f830);
class pddiObject_27f880 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_27f880 : public pddiObject_27f880 {};
class pddiBaseShader_27f880 : public pddiShader_27f880 {
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
class d3dShader_27f880 : public pddiBaseShader_27f880 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class pddiObject_27f8a0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_27f8a0 : public pddiObject_27f8a0 {};
class pddiBaseShader_27f8a0 : public pddiShader_27f8a0 {
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
class d3dShader_27f8a0 : public pddiBaseShader_27f8a0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Ref_27fee0 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_27fee0 {
  public:
    Ref_27fee0* a;
    char pad[8];
    Ref_27fee0* b;
    Ref_27fee0* c;
    Ref_27fee0* d;
    Ref_27fee0* e;
    void Clear();
};
class A_27ff40 {
  public:
    void Fnf_0027f2a0(int, int);
};
class B_27ff40 {
  public:
    void Fnf_0027f750(int, int);
};
class V {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void f6(int, int);
    virtual void _m_vf7();
    virtual void f(int, int);
};
class C_27ff40 {
  public:
    char p[12];
    A_27ff40* a;
    char q[4];
    B_27ff40* b;
    V* c;
    void f(int, int);
};
class D {
  public:
    void Fnf_0027f4a0();
    int Fnf_00283e10(int, int, int, int, int, int, int, int);
};
class C_27ff80 {
  public:
    char pad[0x10];
    D* member;
    void target();
};
} // namespace fn_f4890d4c
extern "C" void _ReadWriteBarrier();
namespace fn_f4890d4c {
struct Sub_27ff90 {
    void Forward_0027f330(int a, int b, int c);
};
struct Owner_27ff90 {
    char pad[12];
    Sub_27ff90* m_sub;
    void fn(int a, int b, int c);
};
class C_27ffb0 {
  public:
    char pad[12];
    C_27ffb0* field;
    int Fng_0027f380(int);
    int f(int);
};
class C_27ffc0 {
  public:
    char pad[12];
    C_27ffc0* field;
    int Fng_0027f3c0(int, int);
    int f(int, hulk_intptr);
};
class C_27ffd0 {
  public:
    char pad[12];
    C_27ffd0* field;
    void Fng_0027f410(int, int);
    void f(int, int);
};
extern const float g_value_27ffe0;
struct Entry_27fff0 { unsigned a,b; Object* object; };
struct Container_27fff0 { char pad[0x3c]; Entry_27fff0* begin; Entry_27fff0* end; };
class Object {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual int kind();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void Attach(int arg);
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual int subtype();
    char _m_pad_4[0x40];
    Container_27fff0* container;
    char _m_pad_48[0x10];
    float value;
    void FUN_002a3be0(int, float);
};
class Entity_280120 {
  public:
    Entity_280120();
    virtual void v();
};
class EffectQueue : public Entity_280120 {
  public:
    char pad[12];
    int one;
    char rest[0x60 - 0x14];
    virtual void v();
    EffectQueue();
};
class Item_280160 {
  public:
    virtual void A();
    virtual void Release();
};
struct Resource_280380 {
 virtual void AddRef();
 virtual void Release();
 unsigned FUN_002843a0(unsigned a, unsigned b);
};
struct Key_280380 { unsigned a,b; };
struct Matrix { unsigned words[16]; };
struct Slot_280380 {
 unsigned id;
 unsigned char flag;
 char pad[3];
 Matrix matrix;
 Resource_280380* first;
 Resource_280380* second;
 unsigned value1,value2,index,extra;
};
struct Manager_280380 {
 char pad[16];
 unsigned nextId;
 char pad2[4];
 Slot_280380 slots[100];
 unsigned FUN_00280380(Resource_280380* first, Resource_280380* second, const Key_280380* key, const Matrix* matrix, unsigned extra);
};
class Transform_280460 {
public:
    char data[0x40];
    void FUN_0022b980();
};
struct Item_280460 {
    int id;
    char flag;
    char pad5[3];
    Transform_280460 transform;
    Object* held;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
};
class SlotTable_280460 {
public:
    char pad0[0x10];
    int nextId;
    char pad14[4];
    Item_280460 items[100];

    int FUN_00280460(Object* object, int arg, int value);
};
struct Vec3_2804f0 {
    float x, y, z;
    void FUN_0022d180();
};
struct Mat4_2804f0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bec0(Vec3_2804f0 *dir, Vec3_2804f0 *up);
    void FUN_0022be60(float x, float y, float z);
};
struct Slot_2804f0 {
    int id;
    int pad04;
    Mat4_2804f0 matrix;
    int active;
    char pad4c[0x5c - 0x4c];
    float value;
};
class Holder_2804f0 {
public:
    char pad00[0x18];
    Slot_2804f0 slots[100];
    int FUN_002804f0(int id, Vec3_2804f0 *from, Vec3_2804f0 *to, int unused);
};
class Obj_2807d0 {
  public:
    virtual void a();
    virtual void b();
};
class Target_2807d0 {
  public:
    char pad[0x14];
    int x14;
    Obj_2807d0* p18;
    int x1c;
    void f();
};
class Item_280800 {
  public:
    virtual void f();
    virtual void Release();
};
struct Record_280800 {
    Item_280800* ptr;
    char pad[24];
};
class Owner_280800 {
  public:
    char pad[0x14];
    int state;
    char pad2[0x10];
    Record_280800 items[100];
    void clear();
};
struct V3_2809b0 {
    float x, y, z;
};
struct Pair_2809b0 {
    unsigned short face;
    unsigned short key;
};
struct Face_2809b0 {
    Pair_2809b0 pairs[3];              // 0x00
    char pad0c[4];
    unsigned short v[3];        // 0x10
    unsigned short bits;        // 0x16
};
struct MeshData_2809b0 {
    char pad0[0x18];
    Face_2809b0 *faces;                // 0x18
};
struct Mesh_2809b0 {
    char pad0[0x40];
    int key;                    // 0x40
    MeshData_2809b0 *data;             // 0x44
    V3_2809b0 *FUN_001af890(V3_2809b0 *out, unsigned int idx);
    V3_2809b0 *FUN_002f37d0(V3_2809b0 *out, Face_2809b0 *f);
};
char __cdecl FUN_00280840(int a, int b, V3_2809b0 *c, V3_2809b0 *d, V3_2809b0 *e);
char __cdecl FUN_0027f540(Face_2809b0 *f, Face_2809b0 **arr, int count);
class Walker_2809b0 {
public:
    void FUN_002809b0(Mesh_2809b0 *mesh, int arg2, int arg3, Face_2809b0 *arg4, Face_2809b0 *node,
                      Face_2809b0 **arr, int *pcount, int max, int skipBits, int skipDot);
};
struct Vtx_280be0 {
    float x, y, z;
    int w0, w1, w2;
};
struct Plane_280be0 {
    float nx, ny, nz;
    float d;
    void FUN_0022e1f0(Vtx_280be0* a, Vtx_280be0* b, float* t);
};
struct V3_280d90 {
    float x, y, z;
    float FUN_0022d110();
};
struct Vtx_280d90 {
    V3_280d90 p;
    V3_280d90 n;
};
char FUN_00280840(const V3_280d90 *center, float radius, const Vtx_280d90 *a, const Vtx_280d90 *b, const Vtx_280d90 *c);
static __forceinline void MidNormal(Vtx_280d90 *m, const Vtx_280d90 *a, const Vtx_280d90 *b)
{
    m->n.x = (b->n.x - a->n.x) * 0.5f + a->n.x;
    m->n.y = (b->n.y - a->n.y) * 0.5f + a->n.y;
    m->n.z = (b->n.z - a->n.z) * 0.5f + a->n.z;
}
static __forceinline void MidPos(Vtx_280d90 *m, const Vtx_280d90 *a, const Vtx_280d90 *b)
{
    m->p.x = (b->p.x - a->p.x) * 0.5f + a->p.x;
    m->p.y = (b->p.y - a->p.y) * 0.5f + a->p.y;
    m->p.z = (b->p.z - a->p.z) * 0.5f + a->p.z;
}
static __forceinline float EdgeLen(const Vtx_280d90 *a, const Vtx_280d90 *b)
{
    float dx = b->p.x - a->p.x;
    float dy = b->p.y - a->p.y;
    float dz = b->p.z - a->p.z;
    return (float)sqrt(dz * dz + dy * dy + dx * dx);
}
struct Plane_281e60 {
    float nx, ny, nz, d;
};
struct Vtx_281e60 {
    unsigned int f[6];
};
struct Frame_281e60 {
    int count;
    Vtx_281e60 outBuf[10];
    Vtx_281e60 bufC[10];
    Vtx_281e60 bufB[10];
    Vtx_281e60 bufA[10];
};
void __cdecl FUN_00280be0(const Plane_281e60* plane, const Vtx_281e60* in, int inCount, Vtx_281e60* out, int* outCount);
struct V3_281fd0 { float x, y, z; };
struct V2_281fd0 { float x, y; };
struct Tri_281fd0 {
    char pad0[0x10];
    unsigned short idx[3];
    char pad16[2];
};
struct Vtx_281fd0 {
    float x, y, z;
    unsigned int color;
    float u, v;
};
struct Palette_281fd0 {
    char pad0[0xc];
    unsigned int* colors;
    unsigned char* indices;
    int pad14;
    Tri_281fd0* tris;
};
struct Xform_281fd0 {
};
struct Ctx_281fd0 {
    char pad0[0x44];
    Palette_281fd0* pal;
    V3_281fd0* FUN_002f3830(V3_281fd0* out, Tri_281fd0* item);
    void FUN_001af890(V3_281fd0* out, unsigned int idx);
};
class Item_282140 {
  public:
    virtual void F0();
    virtual void F1();
};
struct Entry_282140 {
    int id;
    char p[4];
    Item_282140* item;
    char tail[0x10];
};
class Owner_282140 {
  public:
    char pad[0x20];
    Entry_282140 entries[100];
    void Remove(int id);
};
class Ref_282190 {
  public:
    virtual void A();
    virtual void Release();
};
struct Entry_282190 {
    int key;
    Ref_282190* value;
    char pad[0x14];
};
class Owner_282190 {
  public:
    char pad[0x24];
    Entry_282190 entries[100];
    void Remove(int);
};
class Thing_2823c0 {
  public:
    virtual void f();
    virtual void Release();
};
class Obj_2823c0 {
  public:
    char pad[0x20];
    Thing_2823c0* a;
    char pad2[8];
    Thing_2823c0* b;
    char pad3[0x24];
    Thing_2823c0* c;
    void Clear();
};
typedef unsigned int u32_282650;
class CMotionTrailQueue {
  public:
    hulk_uintptr vtable;
    char _m_pad_4[0x44];
    char* items;
    char _m_pad_4c[0xc];
    u32_282650 state;
    union { u8* bytes; u32_27f830 field5c; };
    void Run_002a4ff0();
    void Finish();
    void vfunc_9();
};
struct Item_282650 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
};
class Obj_282690 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Helper_282690 {
  public:
    void helper_0029b9d0(void*, int, int, int);
};
class Item_2826e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void call(int, int);
    virtual bool test();
};
struct Entry_2826e0 {
    Item_2826e0* p;
    char pad[12];
};
struct Item_282740 {
    char pad[0x7c];
    float value;
};
struct Slot_282740 {
    Item_282740* ptr;
    char pad[12];
};
class Obj_282740 {
  public:
    char pad48[0x48];
    Slot_282740* items;
    char pad4c[0x5c - 0x4c];
    unsigned int* keys;
    void Update(unsigned int key);
};
class Ref_2828b0 {
  public:
    virtual void f0();
    virtual void f1();
};
union Word_282a10 {
    float f;
    unsigned int u;
};
struct VertexBuf_282a10 {
    Word_282a10 w[0x31];          // 12 xyz triples at 0, copied words at 0x12 + 3*i, reference point at 0x24..0x26, color at 0x30

    void Blend(VertexBuf_282a10 *src, int count, float a3, float a4, float a5, float a6, float a7, float a8);
};
class Obj_2830e0 {
  public:
    virtual void f();
    virtual void g();
};
struct Vec3_283110 {
    float x, y, z;
};
struct Skeleton_283110 {
    char pad0[0x1c];
    char *joints;
};
struct JointXform {
    void FUN_0022c2b0(Vec3_283110 *out, Vec3_283110 *in);
};
struct TrailSample {
    Vec3_283110 pos[12];
    char rest[16];
    void FUN_0027fa00(Vec3_283110 *pts);
};
struct TrailData {
    char pad0[0x1c];
    char *joints;
};
struct ThisCall_0027fee0 {
    void FUN_0027fee0();
};
class Obj_283340 {
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
};
class Hlp {
  public:
    void FUN_00280800();
};
class Holder_283340 {
  public:
    char p0[0x20];
    Obj_283340* b;
    char p1[8];
    Obj_283340* a;
    char p2[0x24];
    Obj_283340* c;
};
class C_283340 {
  public:
    char p0[0x0c];
    Hlp* x;
    Hlp* y;
    Holder_283340* h;
    Obj_283340* z;
    void run();
};
class Item_2833a0 {
  public:
    virtual void A();
    virtual void B();
};
class Inner_2833a0 {
  public:
    char pad[0x14];
    int value;
    Item_2833a0* item;
};
class Owner_2833a0 {
  public:
    Item_2833a0* item;
    char pad[0x0c];
    Inner_2833a0* inner;
    void set(Item_2833a0* p);
};
class A_2833f0 {
  public:
    virtual void f();
    virtual void g();
};
struct B_2833f0 {
    char pad0[0x14];
    int m14;
    A_2833f0* m18;
    int m1c;
};
struct C_2833f0 {
    A_2833f0* m0;
    char pad4[0xc];
    B_2833f0* m10;
    void target();
};
class C_283450 {
  public:
    char pad[12];
    C_283450* field;
    void Fng_002804f0(int, int, int, int);
    void f(hulk_intptr, hulk_intptr, hulk_intptr, int);
};
class Sub {
  public:
    void Fn_00280630(int a, int b, int c);
    int Call_0027b200(int a, int b);
};
class Target {
    char pad[12];
    Sub* ptr;

  public:
    void Fn(int a, int b, int c);
};
typedef void(__fastcall* Fn_283480)(void*);
struct Obj_283480 {
    Fn_283480* v;
};
extern Obj_283480* hulk_at_0052c2a8;
struct U_283480 {
    void Fnf_00282140(int);
};
struct T_283480 {
    char pad[0x10];
    U_283480* m;
    void go(int);
};
typedef void(__fastcall* Fn_2834b0)(void*);
struct Obj_2834b0 {
    Fn_2834b0* v;
};
extern Obj_2834b0* gObj_2834b0;
struct U_2834b0 {
    void Fnf_00282190(int);
};
struct T_2834b0 {
    char pad[0x10];
    U_2834b0* m;
    void go(int);
};
class Y_2834e0 {
  public:
    void Fng_00282740(int);
};
class X_2834e0 {
    char pad[0x18];
    Y_2834e0* p;

  public:
    void f(int);
};
class EffectQueue_2834f0 {
  public:
    virtual void Fnf_00038290();
    void Cleanup2_0027afd0();
    ~EffectQueue_2834f0();
    int mData;
};
struct RefObj_283510 { virtual void AddRef(); virtual void Release(); };
struct Rec_283510 {
    RefObj_283510* obj;
    int f4, f8, fc, f10;
    int f14;
    int id;
    char flag;
    char pad[0x60 - 0x1d];
};
class Table_283510 {
public:
    Rec_283510 rec[102];
    int FUN_002804f0(int id, int a, int b, int c);
    int Add(RefObj_283510* o, int a, int b, int c);
};
class Ref_2835a0 {
  public:
    virtual void A();
    virtual void B();
};
struct Slot_2835a0 {
    Ref_2835a0* p;
    char pad[0x18];
};
class CDecalQueue {
  public:
    virtual void FnA_00038290();
    CDecalQueue();
    ~CDecalQueue();
    void Init_00280800();
    void Tail_0027afd0();
    char pad[0x34];
    Slot_2835a0 items[100];
};
extern "C" char DAT_0042c514[];
class Ref_2835e0 {
  public:
    virtual void f0();
    virtual void Release();
};
class CLightQueue {
  public:
    void* vptr;
    char pad04[0x10];
    Ref_2835e0* m14;
    char pad18[8];
    Ref_2835e0* m20;
    char pad24[8];
    Ref_2835e0* m2c;
    char pad30[0x24];
    Ref_2835e0* m54;
};
extern "C" void __fastcall FUN_0027afd0(CLightQueue*);
struct V3_2837e0 {
    int a, b, c;
};
struct Inner_2837e0 {
    void Fn_002828e0(int a, int b, int c, int d, int e, int f, int g, int h, V3_2837e0 v, int i, int j, int k);
};
struct Obj_2837e0 {
    char pad0[0x48];
    char* mArr;
    char pad1[0xc];
    unsigned mCount;
    char* mInfo;
    unsigned Run(int a, int b, int c, int d, int e, int f, int g, int h, V3_2837e0 v, int i, int j, int k);
};
struct Resource_283900 {
 virtual void acquire();
 virtual void release();
 Resource_283900* FUN_00280120();
 Resource_283900* FUN_00280690(unsigned context);
 Resource_283900* FUN_002821d0();
 Resource_283900* FUN_00283730();
};
extern void* __cdecl FUN_00263ea0(unsigned size);
struct Manager_283900 {
 unsigned state;
 unsigned owner;
 unsigned enabled;
 Resource_283900* first;
 Resource_283900* second;
 Resource_283900* third;
 Resource_283900* fourth;
 Manager_283900* FUN_00283900(unsigned ownerValue, unsigned context);
};
struct B_283a10 {
    void FnF_002801b0(int);
};
struct C_283a10 {
    void FnG_00283640(int);
};
class A_283a10 {
  public:
    char p[12];
    B_283a10* a;
    char q[4];
    C_283a10* b;
    V* c;
    void Run(int);
};
struct Triple_283d60 {
    int a, b, c;
};
class Mgr_283d60 {
  public:
    int Fn_002837e0(int, int, int, int, int, int, int, int, Triple_283d60, int, int, int);
};
class Obj_283d60 {
    char pad[24];
    Mgr_283d60* mgr;

  public:
    int Go(int, int, int, int, int, int, int, int, Triple_283d60, int, int, int);
};
extern int hulk_at_0042c4dc;
struct EffectQueue_283dc0 {
    void* m_vptr;
    void base2_dtor_0027afd0();
    void* scalar_dtor(unsigned char flags);
};
class C_2842e0 {
  public:
    char pad[0x10];
    D* member;
    hulk_intptr target(hulk_intptr, int, int, hulk_intptr, hulk_intptr, hulk_intptr, int, int);
};
struct Block64 {
    int w[16];
};
struct Row16_2842f0 {
    int a, b, c, d;
};
struct Clone {
    char pad0[0x10];
    Row16_2842f0 *rows;            // 0x10
    Block64 *blocksA;       // 0x14
    Row16_2842f0 *extraRows;       // 0x18
    Block64 *blocksB;       // 0x1c
};
struct Maker_2842f0 {
    Clone *FUN_0027b240();
};
struct Source_2842f0 {
    char pad0[8];
    Maker_2842f0 *maker;           // 0x08
    unsigned int count;     // 0x0c
    Row16_2842f0 *rows;            // 0x10
    Block64 *blocksA;       // 0x14
    Row16_2842f0 *extraRows;       // 0x18
    Block64 *blocksB;       // 0x1c
};
class Frames_2842f0 : public Source_2842f0 {
public:
    Clone * FUN_002842f0();
};
class Thing {
  public:
    char pad[8];
    Sub* field;
    int Fn(int a, int b);
};


// 0x0027f2a0 FUN_0027f2a0 (143 B): matches/0x0027f2a0.cpp
// sym: ?target@Obj_27f2a0@fn_f4890d4c@@QAEXHH@Z
// data: gHolder_27f2a0 = DAT_0052c2ac
void Obj_27f2a0::target(int a, int b) {
    char* p = (char*)this + 0x70;
    for (int i = 100; i != 0; --i, p += 0x60) {
        Worker_27f2a0* w = *(Worker_27f2a0**)(p - 16);
        if (w) {
            (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do0(0);
            unsigned n = *(unsigned*)p;
            if (n != 0xffff)
                (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do1(0, n * 64 + *(unsigned*)((*(char**)(p - 12)) + 0x1c));
            (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do1(0, (hulk_intptr)(p - 0x50));
            w->Run(a, b);
            (*(Holder_27f2a0**)&DAT_0052c2ac)->mgr->Do2(0);
        }
    }
}


// 0x0027f330 FUN_0027f330 (72 B): matches/0x0027f330.cpp
// sym: ?Set@Manager@fn_f4890d4c@@QAE_NHHH@Z
bool Manager::Set(int key, int a, int b) {
    bool result = false;
    int i = 0;
    Entry* p = entries;
    while (i < 100) {
        if (p->active && p->key == key) {
            int offset = i * 0x60;
            *(int*)((char*)this + offset + 0x68) = a;
            *(int*)((char*)this + offset + 0x6c) = b;
            result = true;
            break;
        }
        ++i;
        ++p;
    }
    return result;
}


// 0x0027f380 FUN_0027f380 (60 B): matches/0x0027f380.cpp
// sym: ?f@Obj_27f380@fn_f4890d4c@@QAEXH@Z
void Obj_27f380::f(int x) {
    for (int i = 0; i < 100; i++) {
        if (entries[i].active != 0 && entries[i].key == x) {
            *(int*)((char*)this + i * 0x60 + 0x74) = 0;
            return;
        }
    }
}


// 0x0027f3c0 FUN_0027f3c0 (69 B): matches/0x0027f3c0.cpp
// sym: ?Update@Manager_27f3c0@fn_f4890d4c@@QAEHHPAUBlock_27f3c0@2@@Z
int Manager_27f3c0::Update(int key, Block_27f3c0* source) {
    int i = 0;
    while (i < 100) {
        if (entries[i].occupied != 0 && entries[i].key == key) {
            Block_27f3c0* dest = (Block_27f3c0*)((char*)this + 0x20 + i * 0x60);
            *dest = *source;
            return key;
        }
        ++i;
    }
    return 0;
}


// 0x0027f410 FUN_0027f410 (70 B): matches/0x0027f410.cpp
// sym: ?run@Obj_27f410@fn_f4890d4c@@QAEHHH@Z
int Obj_27f410::run(int key, int arg) {
    int i = 0;
    while (items[i].flag == 0 || items[i].key != key) {
        ++i;
        if (i >= 100)
            return 0;
    }
    ((owners::Target_22be40 *)(((Caller_27f410*)((char*)this + 0x20 + i * 0x60))))->FUN_0022be40((const int *)(hulk_uintptr)(int)arg);
    return key;
}


// 0x0027f4a0 FUN_0027f4a0 (146 B): equivalent/0x0027f4a0.cpp
// sym: ?FUN_0027f4a0@Ring_27f4a0@fn_f4890d4c@@QAEXXZ @05e992396c5a @w79abf2a4fc37
// STATUS: equivalent (tools/equiv.py level 3: 1557 inputs, branch coverage 6/6)
// FUN_0027f4a0 @ 0x0027f4a0
void Ring_27f4a0::FUN_0027f4a0()
{
    union {
        unsigned int word;
        char flag;
    } saved;
    saved.flag = DAT_0052c2a8->GetFlag();
    DAT_0052c2a8->SetFlag(0);
    for (int i = 0; i < 85; i++) {
        Slot_27f4a0 *s = &slots[(cursor + i + 15) % 100];
        if (s->resource != 0 && s->value != 0)
            DAT_0052c2a8->SetTexture(s->resource->handle, s->value);
    }
    count = 15;
    DAT_0052c2a8->SetFlag((char)saved.word);
}


// 0x0027f540 FUN_0027f540 (37 B): matches/0x0027f540.cpp
// sym: ?Find@fn_f4890d4c@@YAEHPAHH@Z
unsigned char Find(hulk_intptr value, int* array, int count) {
    int i = 0;
    if (count > 0) {
        do {
            if (value == array[i])
                return 1;
            ++i;
        } while (i < count);
    }
    return 0;
}


// 0x0027f5a0 FUN_0027f5a0 (3 B): matches/0x0027f5a0.cpp
// sym: ??0Obj_27f5a0@fn_f4890d4c@@QAE@XZ
Obj_27f5a0::Obj_27f5a0() {}


// 0x0027f5f0 FUN_0027f5f0 (223 B): equivalent/0x0027f5f0.cpp
// sym: _FUN_0027f5f0 @a357b3d7543f @wa14b11224e6e
// STATUS: equivalent (tools/equiv.py level 3: 188 inputs, branch coverage 6/6)
// FUN_0027f5f0 @ 0x0027f5f0
extern "C" void __cdecl FUN_0027f5f0(int unused, int count, const int* indices, void * vertices_) {
    Vertex_27f5f0 * vertices = (Vertex_27f5f0 *)vertices_;
 Geometry* geometry = &((Context *)FUN_001b6580())->geometry;
 for (int i=0; i<count; ++i) {
  Vec3_27f5f0 temporary;
  Vec3_27f5f0 normal = *geometry->FUN_001b5860(&temporary, indices[i]);
  Vec3_27f5f0 offset;
  offset.x = normal.x * 0.03f;
  offset.y = normal.y * 0.03f;
  offset.z = normal.z * 0.03f;
  for (int j=0; j<3; ++j, ++vertices) {
   vertices->normal = normal;
   Vec3_27f5f0* position = geometry->FUN_001b56a0(indices[i], j);
   vertices->position.x = offset.x + position->x;
   vertices->position.y = offset.y + position->y;
   vertices->position.z = offset.z + position->z;
  }
 }
}


// 0x0027f6f0 FUN_0027f6f0 (83 B): matches/0x0027f6f0.cpp
// sym: _FUN_0027f6f0@4
extern "C" void __stdcall FUN_0027f6f0(void * self) {
    char local[12];
    if (((Obj_27f6f0 *)self)->index != 0xffff) {
        Conv* c = (Conv*)((char*)*((void**)((char*)((Obj_27f6f0 *)self)->a + 0x1c)) + (((Obj_27f6f0 *)self)->index << 6));
        ((owners::Mat_22c2b0 *)c)->FUN_0022c2b0((float *)((char*)((Obj_27f6f0 *)self) + 0x14), (float *)local);
        ((Obj_27f6f0 *)self)->buffer->f8(local);
    } else {
        ((Obj_27f6f0 *)self)->buffer->f8((char*)((Obj_27f6f0 *)self) + 0x14);
    }
}

} // namespace fn_f4890d4c

// 0x0027f750 FUN_0027f750 (221 B): equivalent/0x0027f750.cpp [wrapped: conflict: Gfx]
// sym: ?target@Object@fn_0027f750@@QAEXII@Z @a29aa17be786 @w95c30230f91a
namespace fn_0027f750 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0027f750 @ 0x0027f750
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

struct Gfx {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void draw(unsigned int, unsigned int); virtual void v33(); virtual void v34(); virtual void reset(unsigned int); virtual void v36(); virtual void v37(); virtual void state(unsigned int,unsigned int); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void set(unsigned char); virtual unsigned char get();
};
struct Resource_27f750 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void bind(int); };
struct Data_27f750 { char pad[16]; unsigned int value; };
struct Object { char pad0[20]; Data_27f750* data; char pad1[20]; Resource_27f750* resource; char pad2[36]; unsigned int count; void target(unsigned int,unsigned int); };
void Object::target(unsigned int,unsigned int) {
 unsigned char saved = DAT_0052c2a8->get();
 DAT_0052c2a8->set(0);
 DAT_0052c2a8->state(0,0);
 DAT_0052c2a8->state(1,0);
 DAT_0052c2a8->state(2,0);
 DAT_0052c2a8->state(3,0);
 DAT_0052c2a8->reset(0);
 if(data && resource) {
 resource->bind(0);
 DAT_0052c2a8->state(0,1);
 if(count) DAT_0052c2a8->draw(data->value,count);
 }
 DAT_0052c2a8->set(saved);
}
} // namespace fn_0027f750
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f4890d4c {

// 0x0027f830 FUN_0027f830 (29 B): matches/0x0027f830.cpp
// sym: ?Finish@CMotionTrailQueue@fn_f4890d4c@@QAEXXZ
void CMotionTrailQueue::Finish() {
    u32_27f830 x = field5c;
    vtable = ((hulk_intptr)DAT_0042c48c);
    thunk_FUN_00267090(x);
    Run_002a4ff0();
}

} // namespace fn_f4890d4c

// 0x0027f850 pure3d::prop::CMotionTrailQueue::vfunc_3 (3 B): matches/0x0027f850.cpp
// sym: ?vfunc_3@CMotionTrailQueue@prop@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::prop::CMotionTrailQueue::vfunc_3() {
    return (bool)(0);
}

namespace fn_f4890d4c {

// 0x0027f860 pure3d::prop::CMotionTrailQueue::vfunc_4 (3 B): matches/0x0027f860.cpp
// sym: ?GetZero@fn_f4890d4c@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f4890d4c

// 0x0027f870 pure3d::prop::CMotionTrailQueue::vfunc_7 (3 B): matches/0x0027f870.cpp
// sym: ?vfunc_7@CMotionTrailQueue@prop@pure3d@@UAEDXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
char pure3d::prop::CMotionTrailQueue::vfunc_7() {
    return (char)(0);
}


// 0x0027f880 pure3d::prop::CMotionTrailQueue::vfunc_15 (6 B): matches/0x0027f880.cpp
// sym: ?vfunc_15@CMotionTrailQueue@prop@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::prop::CMotionTrailQueue::vfunc_15() {
    return 1;
}


// 0x0027f8a0 pure3d::prop::CMotionTrail::vfunc_5 (6 B): matches/0x0027f8a0.cpp
// sym: ?vfunc_5@CMotionTrail@prop@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::prop::CMotionTrail::vfunc_5() {
    return 1;
}


// 0x0027f9e0 pure3d::prop::CMotionTrail::vfunc_7 (4 B): matches/0x0027f9e0.cpp
// sym: ?vfunc_7@CMotionTrail@prop@pure3d@@UAEIXZ
// Same code shape as 0x00069100 (propagated; names are from that function)
hulk_uintptr pure3d::prop::CMotionTrail::vfunc_7() {
    return (*(unsigned int *)&this->f_40);
}


// 0x0027f9f0 pure3d::prop::CMotionTrail::vfunc_9 (3 B): matches/0x0027f9f0.cpp
// sym: ?vfunc_9@CMotionTrail@prop@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::prop::CMotionTrail::vfunc_9() {
    return 0;
}


// 0x0027fa00 FUN_0027fa00 (295 B): equivalent/0x0027fa00.cpp
// sym: ?FUN_0027fa00@State_27fa00@owners@@QAEPAU12@PBU12@@Z @da631e54e2b3 @w850e7cdaa086
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0027fa00 @ 0x0027fa00
owners::State_27fa00* owners::State_27fa00::FUN_0027fa00(const owners::State_27fa00* source)
{
    for (int i = 0; i < 40; ++i)
        words[i] = source->words[i];
    return this;
}


// 0x0027fb30 pure3d::prop::CMotionTrail::vfunc_12 (31 B): matches/0x0027fb30.cpp
// sym: ?vfunc_12@CMotionTrail@prop@pure3d@@UAEHXZ
 // namespace pure3d
int pure3d::prop::CMotionTrail::vfunc_12() {
    return this->f_80 + this->f_7c <= 0.0f;
}

namespace fn_f4890d4c {

// 0x0027fee0 FUN_0027fee0 (88 B): matches/0x0027fee0.cpp
// sym: ?Clear@Owner_27fee0@fn_f4890d4c@@QAEXXZ
// data: gValue_27fee0 = DAT_0052c29c
void Owner_27fee0::Clear() {
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    if (e) {
        e->Release();
        e = 0;
    }
    (*(int*)&DAT_0052c29c) = 0;
}


// 0x0027ff40 FUN_0027ff40 (49 B): matches/0x0027ff40.cpp
// sym: ?f@C_27ff40@fn_f4890d4c@@QAEXHH@Z
void C_27ff40::f(int x, int y) {
    a->Fnf_0027f2a0(x, y);
    b->Fnf_0027f750(x, y);
    c->f(x, y);
}


// 0x0027ff80 FUN_0027ff80 (8 B): matches/0x0027ff80.cpp
// sym: ?target@C_27ff80@fn_f4890d4c@@QAEXXZ
void C_27ff80::target() {
    member->Fnf_0027f4a0();
}


// 0x0027ff90 FUN_0027ff90 (26 B): matches/0x0027ff90.cpp
// sym: ?fn@Owner_27ff90@fn_f4890d4c@@QAEXHHH@Z
void Owner_27ff90::fn(int a, int b, int c) {
    m_sub->Forward_0027f330(a, b, c);
    _ReadWriteBarrier();
}


// 0x0027ffb0 FUN_0027ffb0 (8 B): matches/0x0027ffb0.cpp
// sym: ?f@C_27ffb0@fn_f4890d4c@@QAEHH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
int C_27ffb0::f(int a0) {
    return field->Fng_0027f380(a0);
}


// 0x0027ffc0 FUN_0027ffc0 (8 B): matches/0x0027ffc0.cpp
// sym: ?f@C_27ffc0@fn_f4890d4c@@QAEHHH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
int C_27ffc0::f(int a0, hulk_intptr a1) {
    return field->Fng_0027f3c0(a0, a1);
}


// 0x0027ffd0 FUN_0027ffd0 (8 B): matches/0x0027ffd0.cpp
// sym: ?f@C_27ffd0@fn_f4890d4c@@QAEXHH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void C_27ffd0::f(int a0, int a1) {
    field->Fng_0027f410(a0, a1);
}


// 0x0027ffe0 FUN_0027ffe0 (9 B): matches/0x0027ffe0.cpp
// sym: ?FUN_0027ffe0@fn_f4890d4c@@YGMH@Z
float __stdcall FUN_0027ffe0(int unused) {
    return 10000.0f;
}


// 0x0027fff0 FUN_0027fff0 (294 B): equivalent/0x0027fff0.cpp
// sym: ?FUN_0027fff0@fn_f4890d4c@@YGXPAVObject@1@M@Z @f7aa7ebe7741 @w0384b1ff1076
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 20/20)
// FUN_0027fff0 @ 0x0027fff0
void __stdcall FUN_0027fff0(Object* object, float value) {
 union { float f; unsigned u; } delta;
 delta.f = value - DAT_003f32dc; delta.u &= 0x7fffffff;
 if (delta.f <= DAT_0042c46c) return;
 if (object->kind() == 4) {
  Container_27fff0* container = object->container;
  unsigned count = (unsigned char)(container->end - container->begin);
  for (unsigned i=0; i<count; ++i) {
   Object* child = container->begin[(unsigned char)i].object;
   if (!child) continue;
   if (child->subtype()==4) {
    child->FUN_002a3be0(8,value); child->FUN_002a3be0(9,value); child->FUN_002a3be0(11,value);
   } else if (child->subtype()==8) child->value=value;
  }
 } else if (object->kind()==1) {
  if (object->subtype()==4) {
   object->FUN_002a3be0(8,value); object->FUN_002a3be0(9,value); object->FUN_002a3be0(11,value);
  } else if(object->subtype()==8) object->value=value;
 }
}


// 0x00280120 FUN_00280120 (56 B): matches/0x00280120.cpp
// sym: ??0EffectQueue@fn_f4890d4c@@QAE@XZ
EffectQueue::EffectQueue() {
    one = 1;
    int* p = (int*)(&rest[0x4c]);
    for (int i = 0; i < 100; ++i) {
        p[-18] = 0;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 24;
    }
}

} // namespace fn_f4890d4c

// 0x00280160 FUN_00280160 (67 B): matches/0x00280160.cpp
// sym: ?FUN_00280160@Owner_280160@owners@@QAEXXZ
void owners::Owner_280160::FUN_00280160() {
    owners::Owner_280160* p = this;
    int n = 100;
    state = 1;
    do {
        p->clear = 0;
        p->x = 0;
        p->y = 0;
        p = (owners::Owner_280160*)((char*)p + 0x60);
        p = (owners::Owner_280160*)((char*)p - 0x60);
        if (p->first) {
            ((Item_280160*)p->first)->Release();
            p->first = 0;
        }
        if (p->second) {
            ((Item_280160*)p->second)->Release();
            p->second = 0;
        }
        p = (owners::Owner_280160*)((unsigned char*)p + 0x60);
        --n;
    } while (n != 0);
}


// 0x002801b0 FUN_002801b0 (460 B): equivalent/0x002801b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002801b0@VoicePool_2801b0@fn_002801b0@@QAEXM@Z @b20c69512f7e @w20c8bd41ca9e
namespace fn_002801b0 {
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 31/32, incomplete)
// FUN_002801b0 @ 0x002801b0
class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    virtual void v6(float ms, int flags);
    virtual bool v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int v15();
    virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27(int a);
};

struct Entry_2801b0 {
    unsigned char active;  // 0x00
    char pad01[7];
    Node *part;            // 0x08
};

struct Mixer {
    char pad00[0x3c];
    Entry_2801b0 *begin;          // 0x3c
    Entry_2801b0 *end;            // 0x40
};

class Part_2801b0 : public Node {
public:
    char pad04[0x48 - 4];
    char **items;          // 0x48 (16-byte records, first word is a Node*)
    char **itemsEnd;       // 0x4c
    char pad50[0xa4 - 0x50];
    Node *sink;            // 0xa4
};

class Voice_2801b0 : public Node {
public:
    char pad04[0x44 - 4];
    Mixer *mixer;          // 0x44
    Node *fx0;             // 0x48 (unused here)
    Node *fx1;             // 0x4c
    Node *fx2;             // 0x50
};

struct Slot_2801b0 {
    unsigned char retired; // 0x00
    char pad01[0x44 - 1];
    Voice_2801b0 *voice;          // 0x44
    Node *aux;             // 0x48
    char pad4c[0x58 - 0x4c];
    float timer;           // 0x58
    char pad5c[4];
};

class VoicePool_2801b0 {
public:
    char pad00[0x1c];
    Slot_2801b0 slots[100];       // 0x1c
    void FUN_002801b0(float dt);
};

static void StopFx(Node *&fx)
{
    fx->v16(2);
    fx->v18(1);   // the original reloads the member after the first call
}

void VoicePool_2801b0::FUN_002801b0(float dt)
{
    for (int i = 0; i < 100; i++) {
        Slot_2801b0 *s = &slots[i];
        Voice_2801b0 *v = s->voice;
        if (v == 0)
            continue;
        v->v6(dt * 1000.0f, 0);
        if (v->v7()) {
            if (s->voice) {
                s->voice->v1();
                s->voice = 0;
            }
            if (s->aux) {
                s->aux->v1();
                s->aux = 0;
            }
            continue;
        }
        if (!(s->timer >= 0.0f))
            continue;
        s->timer = s->timer - dt;
        if (!(s->timer < 0.0f))
            continue;
        if (s->retired) {
            if (s->voice) {
                s->voice->v1();
                s->voice = 0;
            }
            if (s->aux) {
                s->aux->v1();
                s->aux = 0;
            }
            continue;
        }
        if (s->voice->v5() == 4) {
            Voice_2801b0 *cur = s->voice;
            Mixer *m = cur->mixer;
            unsigned char n = (unsigned char)(m->end - m->begin);
            for (int k = 0; k < (int)n; k++) {
                Part_2801b0 *p = (Part_2801b0 *)m->begin[(unsigned char)k].part;
                if (p->v15() == 4) {
                    hulk_intptr count = ((char *)p->itemsEnd - (char *)p->items) >> 4;
                    for (int j = 0; j < count; j++) {
                        Node *item = *(Node **)((char *)p->items + j * 16);
                        item->v27(0);
                    }
                    StopFx(p->sink);
                } else {
                    m->begin[(unsigned char)k].active = 0;
                }
            }
            if (cur->fx1)
                StopFx(cur->fx1);
            if (cur->fx2)
                StopFx(cur->fx2);
        }
        s->retired = 1;
        s->timer = 4.0f;
    }
}
} // namespace fn_002801b0

namespace fn_f4890d4c {

// 0x00280380 FUN_00280380 (217 B): equivalent/0x00280380.cpp
// sym: ?FUN_00280380@Manager_280380@fn_f4890d4c@@QAEIPAUResource_280380@2@0PBUKey_280380@2@PBUMatrix@2@I@Z @26bc908223a2 @wb9f2fdecf31f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00280380 @ 0x00280380
unsigned Manager_280380::FUN_00280380(Resource_280380* first, Resource_280380* second, const Key_280380* key, const Matrix* matrix, unsigned extra) {
 int i;
 for(i=0;i<100;++i) if(!slots[i].first) break;
 if(i==100) return 0;
 Slot_280380& s=slots[i];
 unsigned id=nextId;
 s.id=id;
 s.matrix=*matrix;
 if(first) first->AddRef();
 if(s.first) s.first->Release();
 s.first=first;
 if(second) second->AddRef();
 if(s.second) s.second->Release();
 s.second=second;
 s.index=65535;
 if(second) {
 if(key) s.index=second->FUN_002843a0(key->a,key->b);
 if(!key || s.index==65535) s.index=0;
 }
 s.value1=0;
 s.value2=0;
 s.flag=0;
 s.extra=extra;
 ++nextId;
 return id;
}


// 0x00280460 FUN_00280460 (141 B): equivalent/0x00280460.cpp
// sym: ?FUN_00280460@SlotTable_280460@fn_f4890d4c@@QAEHPAVObject@2@HH@Z @c2e664485916 @wf45a760a3636
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00280460 @ 0x00280460
// Claim a free slot (of 100) for a ref-counted object and return the slot's new id (0 when none is free).
int SlotTable_280460::FUN_00280460(Object* object, int arg, int value)
{
    Item_280460* item = items;
    for (int i = 0; ; ++i, ++item) {
        if (item->held == 0) {
            break;
        }
        if (i + 1 >= 100) {
            return 0;
        }
    }

    int id = nextId;
    item->id = id;
    item->transform.FUN_0022b980();
    if (object) {
        object->AddRef();
    }
    if (item->held) {
        item->held->Release();
    }
    item->held = object;
    object->Attach(arg);
    item->field4c = 0;
    item->flag = 0;
    item->field50 = 0;
    item->field54 = 0;
    item->field58 = 0xffff;
    item->field5c = value;
    ++nextId;
    return id;
}


// 0x002804f0 FUN_002804f0 (307 B): equivalent/0x002804f0.cpp
// sym: ?FUN_002804f0@Holder_2804f0@fn_f4890d4c@@QAEHHPAUVec3_2804f0@2@0H@Z @b77251dd4f5e @wd484fed54b74
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002804f0 @ 0x002804f0
int Holder_2804f0::FUN_002804f0(int id, Vec3_2804f0 *from, Vec3_2804f0 *to, int unused)
{
    int i;
    for (i = 0; i < 100; i++) {
        if (slots[i].active != 0 && slots[i].id == id)
            break;
    }
    if (i >= 100)
        return id;

    Vec3_2804f0 dir;
    dir.x = to->x - from->x;
    dir.y = to->y - from->y;
    dir.z = to->z - from->z;
    float lenSq = dir.z * dir.z + dir.y * dir.y + dir.x * dir.x;
    dir.FUN_0022d180();

    Mat4_2804f0 look;
    look.FUN_0022b980();
    Vec3_2804f0 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    look.FUN_0022bec0(&dir, &up);
    ((owners::Target_22be40 *)&look)->FUN_0022be40((const int *)(Vec3_2804f0 *)from);

    Mat4_2804f0 scale;
    scale.FUN_0022b980();
    scale.FUN_0022be60(1.0f, 1.0f, (float)sqrt(lenSq));

    Mat4_2804f0 result;
    ((owners::Matrix_22ca90 *)&result)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat4_2804f0 *)(&scale), (const owners::Matrix_22ca90 *)(Mat4_2804f0 *)(&look));
    slots[i].matrix = result;
    slots[i].value = 1000.0f;
    return id;
}

} // namespace fn_f4890d4c

// 0x00280630 FUN_00280630 (90 B): equivalent/0x00280630.cpp [wrapped: conflict: Entry; Manager]
// sym: ?FUN_00280630@Manager@fn_00280630@@QAEXHHD@Z @dd34eae360e6 @w94eabcda6470
namespace fn_00280630 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_00280630 @ 0x00280630
struct Resource { virtual void unused(); virtual void release(); }; struct Entry { Resource* first; Resource* second; int key1; int key2; char pad10[4]; int active; char pad18[0x48]; }; struct Manager { char pad[0x60]; Entry entries[100]; void FUN_00280630(int key1, int key2, char remove); }; void Manager::FUN_00280630(int key1, int key2, char remove) { for (int i=0;i<100;++i) { Entry& e=entries[i]; if (e.first && e.key1==key1 && e.key2==key2) { if (remove) { if (e.first) { e.first->release(); e.first=0; } if (e.second) { e.second->release(); e.second=0; } } else e.active=0; } } }
} // namespace fn_00280630


// 0x00280690 FUN_00280690 (261 B): matches/0x00280690.cpp [wrapped: conflict: pure3d::Entity; pure3d::prop::CDecalQueue]
// sym: ??0CDecalQueue@prop@pure3d@fn_00280690@@QAE@H@Z
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_00280690 {
// FUN_00280690 @ 0x00280690



int FUN_00266da0(int heap);

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0_00038290();
    char pad04[4];
    char nameHolder[8];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

struct Params {
    int f00;
    int f04;
    char c08, c09, c0a, c0b, c0c, c0d, c0e;
    char c0f;
    int f10;
    int f14;
    char b18, b19;
    char pad1a[2];
    int f1c;
    int f20;
};

class Part_280690 {
public:
    virtual void v0(int a, int b, int c);
};

class Instance {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Part_280690 *v4();
    virtual void v5(Part_280690 *part);
    virtual void v6();
};

class Factory_280690 {
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
    virtual Instance *v10(Params *params);
};

struct Entry_280690 {
    int count;
    char pad04[0xc];
    Instance *instance;
    char pad14[8];
};

namespace pure3d {
namespace prop {
class CDecalQueue : public Entity {
public:
    virtual void v1_000382a0();
    int f10;
    int f14;
    int f18;
    int f1c;
    char pad20[8];
    Entry_280690 entries[100];

    CDecalQueue(int heap);
};
}
}

pure3d::prop::CDecalQueue::CDecalQueue(int heap)
{
    f14 = 0xf;
    f18 = 0;
    f1c = heap;
    int previous = FUN_00266da0(heap);
    Params p;
    p.c0b = ' ';
    p.c0a = ' ';
    p.c09 = ' ';
    p.c08 = ' ';
    p.c0c = ' ';
    p.c0d = ' ';
    p.c0e = ' ';
    p.f00 = 0;
    p.f04 = 0x2021;
    p.f10 = 0x42;
    p.f14 = 0;
    p.b18 = 0;
    p.b19 = 0;
    p.f1c = 0;
    p.f20 = 0;
    for (int i = 0; i < 100; i++) {
        entries[i].count = 0;
        entries[i].instance = (*(Factory_280690**)&DAT_0052c2a0)->v10(&p);
        entries[i].instance->v0();
        Part_280690 *part = entries[i].instance->v4();
        for (int n = 0x42; n != 0; n--)
            part->v0(0, 0, 0);
        entries[i].instance->v5(part);
        entries[i].instance->v6();
    }
    FUN_00266da0(previous);
}
} // namespace fn_00280690

namespace fn_f4890d4c {

// 0x002807d0 FUN_002807d0 (38 B): matches/0x002807d0.cpp
// sym: ?f@Target_2807d0@fn_f4890d4c@@QAEXXZ
void Target_2807d0::f() {
    if (p18) {
        p18->b();
        p18 = 0;
    }
    x1c = 0;
    x14 = 0xf;
}


// 0x00280800 FUN_00280800 (50 B): matches/0x00280800.cpp
// sym: ?clear@Owner_280800@fn_f4890d4c@@QAEXXZ
void Owner_280800::clear() {
    for (int i = 0; i < 100; i++) {
        if (items[i].ptr) {
            items[i].ptr->Release();
            items[i].ptr = 0;
        }
    }
    state = 15;
}

} // namespace fn_f4890d4c

// 0x00280840 FUN_00280840 (361 B): equivalent/0x00280840.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00280840@fn_00280840@@YAHPBUV3_280840@1@M000@Z @f36e4f713385 @wd32508b041fd
namespace fn_00280840 {
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8; --wine 611 inputs)
// FUN_00280840 @ 0x00280840

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_280840 { float x, y, z; };

static hulk_freg DistSq(const V3_280840 &c, const V3_280840 *p) {
    hulk_freg dx = c.x - p->x;
    hulk_freg dy = c.y - p->y;
    hulk_freg dz = c.z - p->z;
    return dz * dz + dy * dy + dx * dx;
}

int __cdecl FUN_00280840(const V3_280840 *center, float margin, const V3_280840 *a, const V3_280840 *b, const V3_280840 *c) {
    hulk_freg sx0 = a->x + b->x;
    hulk_freg sy = a->y + b->y;
    float sz0 = b->z + a->z;
    float sx = (float)(sx0 + c->x);
    sy = sy + c->y;
    hulk_freg sz = sz0 + c->z;
    V3_280840 m;
    m.x = sx * 0.33333334f;
    m.y = sy * 0.33333334f;
    m.z = sz * 0.33333334f;
    float best = 0.0f;
    hulk_freg d = DistSq(m, a);
    if (d > best) best = (float)d;
    d = DistSq(m, b);
    if (d > best) best = (float)d;
    d = DistSq(m, c);
    if (d > best) best = (float)d;
    hulk_freg r = sqrt((double)best);
    hulk_freg dc = sqrt((double)DistSq(m, center));
    return r + margin > dc;
}
} // namespace fn_00280840

namespace fn_f4890d4c {

// 0x002809b0 FUN_002809b0 (549 B): equivalent/0x002809b0.cpp
// sym: ?FUN_002809b0@Walker_2809b0@fn_f4890d4c@@QAEXPAUMesh_2809b0@2@HHPAUFace_2809b0@2@1PAPAU42@PAHHHH@Z @5d7263b84b71 @w8ad2a0e1acb6
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 18/22, incomplete)
// FUN_002809b0 @ 0x002809b0
void Walker_2809b0::FUN_002809b0(Mesh_2809b0 *mesh, int arg2, int arg3, Face_2809b0 *arg4, Face_2809b0 *node,
                          Face_2809b0 **arr, int *pcount, int max, int skipBits, int skipDot)
{
    int n = *pcount;
    if (n >= max)
        return;

    arr[n] = node;
    *pcount = *pcount + 1;
    int nodeBits = (node->bits >> 5) & 0x1f;

    for (int i = 0; i < 3; ++i) {
        unsigned int key = node->pairs[i].key;
        unsigned short face = node->pairs[i].face;
        if (key != (unsigned int)mesh->key || face == 0xffff)
            continue;

        Face_2809b0 *f = &mesh->data->faces[face];
        unsigned short v2 = f->v[1];
        unsigned short v1 = f->v[0];
        V3_2809b0 t[7];
        V3_2809b0 *r1 = mesh->FUN_001af890(&t[0], f->v[2]);
        V3_2809b0 *r2 = mesh->FUN_001af890(&t[1], v2);
        V3_2809b0 *r3 = mesh->FUN_001af890(&t[2], v1);
        if (!FUN_00280840(arg2, arg3, r3, r2, r1))
            continue;

        V3_2809b0 *p = mesh->FUN_002f37d0(&t[3], f);
        V3_2809b0 *q = mesh->FUN_002f37d0(&t[4], arg4);
        float dot1 = p->z * q->z + p->y * q->y + p->x * q->x;
        p = mesh->FUN_002f37d0(&t[5], f);
        q = mesh->FUN_002f37d0(&t[6], node);
        float dot2 = p->z * q->z + p->y * q->y + p->x * q->x;

        if ((char)skipBits == 0) {
            if (((f->bits >> 5) & 0x1f) != nodeBits)
                continue;
        }
        if ((char)skipDot == 0) {
            if (!((double)dot1 > 0.5))
                continue;
            if (!((double)dot2 > 0.5))
                continue;
        }
        if (FUN_0027f540(f, arr, *pcount))
            continue;

        FUN_002809b0(mesh, arg2, arg3, arg4, f, arr, pcount, max, skipBits, skipDot);
    }
}


// 0x00280be0 FUN_00280be0 (356 B): equivalent/0x00280be0.cpp
// sym: ?FUN_00280be0@fn_f4890d4c@@YAXPAUPlane_280be0@1@PAUVtx_280be0@1@H1PAH@Z @53e9c4286caf @we238712c73eb
// STATUS: equivalent (tools/equiv.py level 3: 17260 inputs, branch coverage 14/14)
// FUN_00280be0 @ 0x00280be0
// Sutherland-Hodgman clip of a closed polygon against one plane.
void FUN_00280be0(Plane_280be0* plane, Vtx_280be0* verts, int count, Vtx_280be0* out, int* outCount)
{
    bool prevInside = (-plane->d >= (verts->z * plane->nz + verts->y * plane->ny + plane->nx * verts->x));
    // the original keeps the destination vertex pointer in the frame word right after each t
    struct { float tOutgoing; Vtx_280be0* dstOut; float tIncoming; Vtx_280be0* dstIn; } f;
    *outCount = 0;
    for (int i = 1; i <= count; i++) {
        Vtx_280be0* prev = &verts[i - 1];
        Vtx_280be0* cur = &verts[i % count];
        bool curInside = (-plane->d >= (cur->z * plane->nz + cur->y * plane->ny + plane->nx * cur->x));
        if (prevInside) {
            if (!curInside) {
                f.dstOut = &out[*outCount];
                plane->FUN_0022e1f0(prev, cur, &f.tOutgoing);
                ((owners::Vertex_27f070 *)(f.dstOut))->FUN_0027f070((const owners::Vertex_27f070 *)(Vtx_280be0 *)prev, (const owners::Vertex_27f070 *)(Vtx_280be0 *)cur, f.tOutgoing);
                (*outCount)++;
            } else {
                out[*outCount] = *cur;
                (*outCount)++;
            }
        } else if (curInside) {
            f.dstIn = &out[*outCount];
            plane->FUN_0022e1f0(prev, cur, &f.tIncoming);
            ((owners::Vertex_27f070 *)(f.dstIn))->FUN_0027f070((const owners::Vertex_27f070 *)(Vtx_280be0 *)prev, (const owners::Vertex_27f070 *)(Vtx_280be0 *)cur, f.tIncoming);
            (*outCount)++;
            out[*outCount] = *cur;
            (*outCount)++;
        }
        prevInside = curInside;
    }
}


// 0x00280d90 FUN_00280d90 (4292 B): equivalent/0x00280d90.cpp
// sym: ?FUN_00280d90@fn_f4890d4c@@YAXPAUVtx_280d90@1@HHPAHUV3_280d90@1@MM@Z @922c6dcd68eb @w21c96b64aefd
// STATUS: equivalent (tools/equiv.py level 3: 795 inputs, branch coverage 37/38, incomplete)
// FUN_00280d90 @ 0x00280d90
void FUN_00280d90(Vtx_280d90 *verts, int n, int limit, int *outN, V3_280d90 center, float radius, float maxEdge)
{
    int pass = 8;
    do {
        int i = 0;
        int snap = n;
        Vtx_280d90 *slot = verts;
        while (i < snap) {
            if (n >= limit - 9)
                break;
            Vtx_280d90 t[3];
            t[0] = slot[0];
            t[1] = slot[1];
            t[2] = slot[2];
            if (!FUN_00280840(&center, radius, &t[0], &t[1], &t[2])) {
                slot[0] = verts[n - 3];
                slot[1] = verts[n - 2];
                slot[2] = verts[n - 1];
                n -= 3;
                snap -= 3;
            } else {
                float len[3];
                unsigned idx3 = 2;
                len[0] = EdgeLen(&t[0], &t[1]);
                len[1] = EdgeLen(&t[1], &t[2]);
                len[2] = EdgeLen(&t[2], &t[0]);
                unsigned big = 0;
                unsigned mid = 1;
                if (len[1] > len[0]) {
                    big = 1;
                    mid = 0;
                }
                if (len[2] > len[mid]) {
                    idx3 = mid;
                    mid = 2;
                }
                if (len[mid] > len[big]) {
                    unsigned tmp = big;
                    big = mid;
                    mid = tmp;
                }
                Vtx_280d90 m[3];
                MidPos(&m[0], &t[0], &t[1]);
                MidNormal(&m[0], &t[0], &t[1]);
                m[0].n.FUN_0022d110();
                MidPos(&m[1], &t[1], &t[2]);
                MidNormal(&m[1], &t[1], &t[2]);
                m[1].n.FUN_0022d110();
                MidPos(&m[2], &t[2], &t[0]);
                MidNormal(&m[2], &t[2], &t[0]);
                m[2].n.FUN_0022d110();

                Vtx_280d90 out[12];
                int count;
                if (!(len[big] > maxEdge)) {
                    out[0] = t[0];
                    out[1] = t[1];
                    out[2] = t[2];
                    count = 3;
                } else if (!(len[mid] > maxEdge)) {
                    unsigned e1 = (big + 1) % 3;
                    unsigned e2 = (big + 2) % 3;
                    out[0] = m[big];
                    out[1] = t[e2];
                    out[2] = t[big];
                    out[3] = m[big];
                    out[4] = t[e1];
                    out[5] = t[e2];
                    count = 6;
                } else if (!(len[idx3] > maxEdge)) {
                    out[0] = m[big];
                    out[1] = m[mid];
                    out[2] = t[big];
                    out[3] = m[big];
                    out[4] = t[mid];
                    out[5] = m[mid];
                    out[6] = t[idx3];
                    out[7] = t[(idx3 + 1) % 3];
                    out[8] = m[(idx3 + 2) % 3];
                    count = 9;
                } else {
                    out[0] = m[0];
                    out[1] = m[1];
                    out[2] = m[2];
                    out[3] = t[0];
                    out[4] = m[0];
                    out[5] = m[2];
                    out[6] = t[1];
                    out[7] = m[1];
                    out[8] = m[0];
                    out[9] = t[2];
                    out[10] = m[2];
                    out[11] = m[1];
                    count = 12;
                }

                int k = 0;
                if (count > 0) {
                    do {
                        if (!FUN_00280840(&center, radius, &out[k], &out[k + 1], &out[k + 2])) {
                            out[k] = out[count - 3];
                            out[k + 1] = out[count - 2];
                            out[k + 2] = out[count - 1];
                            count -= 3;
                            k -= 3;
                        }
                        k += 3;
                    } while (k < count);
                }

                if (count >= 3) {
                    slot[0] = out[0];
                    slot[1] = out[1];
                    slot[2] = out[2];
                }
                for (int j = 3; j < count; j++)
                    verts[n++] = out[j];
            }
            i += 3;
            slot += 3;
        }
        pass--;
    } while (pass != 0);
    *outN = n;
}


// 0x00281e60 FUN_00281e60 (360 B): equivalent/0x00281e60.cpp
// sym: ?FUN_00281e60@fn_f4890d4c@@YAXPBUPlane_281e60@1@PBUVtx_281e60@1@PAU31@PAH@Z @07892ce52f80 @w575be71cfcad
// STATUS: equivalent (tools/equiv.py level 3: 43 inputs, branch coverage 4/4)
// FUN_00281e60 @ 0x00281e60
void __cdecl FUN_00281e60(const Plane_281e60* planes, const Vtx_281e60* tri, Vtx_281e60* out, int* outCount)
{
    Frame_281e60 f;

    FUN_00280be0(&planes[0], tri, 3, f.bufC, &f.count);
    FUN_00280be0(&planes[1], f.bufC, f.count, f.bufB, &f.count);
    FUN_00280be0(&planes[2], f.bufB, f.count, f.bufA, &f.count);
    FUN_00280be0(&planes[3], f.bufA, f.count, f.outBuf, &f.count);

    int n = f.count;
    *outCount = 0;
    if (n > 2) {
        for (int i = 1; i <= n - 2; i++) {
            int idx;
            idx = (*outCount)++;
            out[idx] = f.outBuf[0];
            idx = (*outCount)++;
            out[idx] = f.outBuf[i];
            idx = (*outCount)++;
            out[idx] = f.outBuf[i + 1];
        }
    }
}


// 0x00281fd0 FUN_00281fd0 (367 B): equivalent/0x00281fd0.cpp
// sym: ?FUN_00281fd0@fn_f4890d4c@@YAXPAUCtx_281fd0@1@PAUV2_281fd0@1@PAUXform_281fd0@1@HPAPAUTri_281fd0@1@PAUVtx_281fd0@1@@Z @ec7f61190b41 @w89afb069baf9
// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 8/8)
// FUN_00281fd0 @ 0x00281fd0
void FUN_00281fd0(Ctx_281fd0* ctx, V2_281fd0* scale, Xform_281fd0* xf, int n, Tri_281fd0** items, Vtx_281fd0* out)
{
    for (; n > 0; n--, items++) {
        V3_281fd0 tmp;
        V3_281fd0* r = ctx->FUN_002f3830(&tmp, *items);
        V3_281fd0 off;
        off.x = r->x * 0.1f;
        off.y = r->y * 0.1f;
        off.z = r->z * 0.1f;
        for (int j = 0; j < 3; j++) {
            V3_281fd0 p;
            V3_281fd0 q;
            ctx->FUN_001af890(&p, (*items)->idx[j]);
            ((owners::Mat_22c2b0 *)xf)->FUN_0022c2b0((float *)(V3_281fd0 *)(&p), (float *)(V3_281fd0 *)(&q));
            out->x = p.x + off.x;
            out->y = p.y + off.y;
            out->z = p.z + off.z;
            Palette_281fd0* pal = ctx->pal;
            unsigned int color;
            if (pal->indices != 0) {
                int tri = (int)(*items - pal->tris);
                color = pal->colors[pal->indices[(unsigned short)tri * 3 + j]];
            } else {
                color = 0xffff00ff;
            }
            out->color = color;
            out->u = q.x / scale->x + 0.5f;
            out->v = q.y / scale->y + 0.5f;
            out++;
        }
    }
}


// 0x00282140 FUN_00282140 (70 B): matches/0x00282140.cpp
// sym: ?Remove@Owner_282140@fn_f4890d4c@@QAEXH@Z
void Owner_282140::Remove(int id) {
    int i = 0;
    while (entries[i].item == 0 || entries[i].id != id) {
        ++i;
        if (i >= 100)
            return;
    }
    if (entries[i].item) {
        entries[i].item->F1();
        entries[i].item = 0;
    }
}


// 0x00282190 FUN_00282190 (55 B): matches/0x00282190.cpp
// sym: ?Remove@Owner_282190@fn_f4890d4c@@QAEXH@Z
void Owner_282190::Remove(int key) {
    for (int i = 0; i < 100; ++i) {
        if (entries[i].value != 0 && entries[i].key == key) {
            Ref_282190* volatile* q = (Ref_282190* volatile*)&entries[i].value;
            Ref_282190* p = *q;
            if (p) {
                p->Release();
                entries[i].value = 0;
            }
        }
    }
}

} // namespace fn_f4890d4c

// 0x002821d0 FUN_002821d0 (495 B): equivalent/0x002821d0.cpp [wrapped: conflict: pure3d::prop::CLightQueue]
// sym: ??0CLightQueue@prop@pure3d@fn_002821d0@@QAE@XZ @681c5985ce7e @wf6cfb38ddc08
namespace fn_002821d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002821d0 @ 0x002821d0
void *__cdecl FUN_00263ea0(unsigned int size);

class Attr_2821d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void setInt(unsigned int tag, int value);
    virtual void setFloat(unsigned int tag, float value);
    virtual void setColor(unsigned int tag, unsigned int value);
};

class Shader_2821d0 {
public:
    virtual void addRef();
    char pad04[0xc];
    Attr_2821d0 *attr;              // 0x10
    char locked;             // 0x14
    char pad15[3];
    int mode;                // 0x18
    char pad1c[4];
    Shader_2821d0 *FUN_0028edf0(const char *name, int flags);
};

namespace pure3d {
namespace prop {

class __declspec(novtable) QueueBase {
public:
    virtual void v0_00038290();
    char pad04[0x10];
    void FUN_0027b070();
    QueueBase() { FUN_0027b070(); }
};

class CLightQueue : public QueueBase {
public:
    Shader_2821d0 *res;                // 0x14
    int f18;
    int f1c;
    int f20;
    char pad24[8];
    int f2c;
    char pad30[0x54 - 0x30];
    int f54;
    virtual void v1_000382a0();
    virtual void v2();
    CLightQueue();
};

CLightQueue::CLightQueue()
{
    f18 = 0;
    f2c = 0;
    f1c = 0;
    f20 = 0;
    f54 = 0;
    void *mem = FUN_00263ea0(0x20);
    Shader_2821d0 *r = 0;
    if (mem)
        r = static_cast<Shader_2821d0 *>(mem)->FUN_0028edf0("simple", 0);
    res = r;
    res->addRef();

    Shader_2821d0 *e = res;
    e->attr->setInt(0x54494c, 1);
    e->locked = 1;
    res->attr->setInt(0x44495332, 0);
    res->attr->setInt(0x444d4853, 1);
    res->attr->setInt(0x444d4946, 1);
    e = res;
    e->attr->setInt(0x444d4c42, 2);
    e->mode = 2;
    res->attr->setInt(0x444d5655, 0);
    res->attr->setInt(0x4d564243, 4);
    res->attr->setInt(0x4e494d4d, 0);
    res->attr->setInt(0x504d4341, 4);
    res->attr->setInt(0x50564243, 0);
    res->attr->setInt(0x54535441, 0);
    res->attr->setInt(0x5642434d, 0);
    res->attr->setInt(0x58414d4d, 7);
    res->attr->setInt(0x59564243, 0);
    res->attr->setFloat(0x48544341, 0.5f);
    res->attr->setFloat(0x4e494853, 0.0f);
    res->attr->setFloat(0x5048534d, 0.5f);
    res->attr->setFloat(0x56564243, 0.0f);
    res->attr->setColor(0x43455053, 0xff000000);
    res->attr->setColor(0x46464944, 0xffffffff);
    res->attr->setColor(0x49424d41, 0xffffffff);
    res->attr->setColor(0x53494d45, 0xff000000);
}

}
}
} // namespace fn_002821d0

namespace fn_f4890d4c {

// 0x002823c0 FUN_002823c0 (62 B): matches/0x002823c0.cpp
// sym: ?Clear@Obj_2823c0@fn_f4890d4c@@QAEXXZ
void Obj_2823c0::Clear() {
    if (b) {
        b->Release();
        b = 0;
    }
    if (a) {
        a->Release();
        a = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
}

} // namespace fn_f4890d4c

// 0x00282400 FUN_00282400 (507 B): equivalent/0x00282400.cpp [wrapped: conflict: Gfx]
// sym: ?FUN_00282400@Builder@fn_00282400@@QAEXPAUItem_282400@2@@Z @8f6f798760d1 @we6cdab20e1a3
namespace fn_00282400 {
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 13/14, incomplete)
// FUN_00282400 @ 0x00282400
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

struct V3_282400 {
    float x, y, z;
};

struct Elem_282400 {
    char data[0x18];
};

struct Desc_282400 {
    int f0;
    int flags;
    char name[7];
    char padf;
    int count;
    int f14;
    char f18;
    char f19;
    char pad1a[2];
    int f1c;
    int f20;
};

class Buf_282400 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(float* a, float* b);
};

class Stream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Buf_282400* v4();
    virtual void v5(Buf_282400* b);
    virtual void v6();
};

class Factory_282400 {
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
    virtual Stream* v10(Desc_282400* d);
};

class Gfx {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
};

struct Source_282400 {
    char pad0[0x18];
    V3_282400 pos;
};

struct Registry_282400 {
    int FUN_001b4890(V3_282400* pos, int key, int* ids, int cap);
};

struct Singleton_282400 {
    char pad0[0x594];
    Registry_282400 registry;
};

struct Item_282400 {
    char pad0[0x10];
    Source_282400* source;
    char pad14[0xc];
    V3_282400 savedPos;
    char pad2c[4];
    int key0;
    int key1;
    Stream* stream;
};

typedef void* (__fastcall *CtorFn)(void*);
void* __fastcall FUN_0027f5a0(void* p);
void __stdcall FUN_00011520(void* arr, unsigned int size, int count, CtorFn ctor);
extern "C++" __declspec(nothrow) void __stdcall FUN_0027f6f0(void *);
extern "C" void * __cdecl FUN_001b6580(void);
extern "C++" __declspec(nothrow) void __cdecl FUN_0027f5f0(int, int, const int *, void *);
void __cdecl FUN_00280d90(Elem_282400* out, int n3, int cap, int* outCount, V3_282400 center, int key0, int key1);
int __cdecl FUN_00266da0(int mode);


class Builder {
  public:
    char pad0[0x18];
    int mode;
    void FUN_00282400(Item_282400* item);
};

void Builder::FUN_00282400(Item_282400* item)
{
    struct Frame {
        int b0;
        int b1;
        V3_282400 a;
        Desc_282400 desc;
        int ids[0x1f4];
        Elem_282400 arr[0x5dc];
    } fr;
    if (item == 0)
        return;
    if (item->source == 0)
        return;
    FUN_0027f6f0((Item_282400 *)item);
    fr.a = item->source->pos;
    fr.b0 = item->key0;
    fr.b1 = item->key1;
    int key0 = fr.b0;
    int n = ((Singleton_282400 *)FUN_001b6580())->registry.FUN_001b4890(&fr.a, key0, fr.ids, 0x1f4);
    FUN_00011520(fr.arr, 0x18, 0x5dc, FUN_0027f5a0);
    FUN_0027f5f0(key0, n, fr.ids, (Elem_282400 *)(fr.arr));
    int key1 = fr.b1;
    V3_282400 center = fr.a;
    fr.b0 = 0;
    FUN_00280d90(fr.arr, n * 3, 0x5dc, &fr.b0, center, key0, key1);
    int count = fr.b0;
    Stream* stream = 0;
    if (count != 0) {
        for (int i = 0; i < 7; i++)
            fr.desc.name[i] = ' ';
        fr.desc.f0 = 0;
        fr.desc.flags = 0x2010;
        fr.desc.count = count;
        fr.desc.f14 = 0;
        fr.desc.f18 = 0;
        fr.desc.f19 = 0;
        fr.desc.f1c = 0;
        fr.desc.f20 = 0;
        int prev = FUN_00266da0(mode);
        stream = (*(Factory_282400**)&DAT_0052c2a0)->v10(&fr.desc);
        Buf_282400* buf = stream->v4();
        for (int i = 0; i < count; i++) {
            buf->v15((float*)&fr.arr[i], (float*)&fr.arr[i] + 3);
        }
        stream->v5(buf);
        stream->v6();
        FUN_00266da0(prev);
    }
    DAT_0052c2a8->v91();
    if (stream)
        stream->v0();
    if (item->stream)
        item->stream->v1();
    item->stream = stream;
    item->savedPos = fr.a;
}
} // namespace fn_00282400
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00282610 pure3d::prop::CMotionTrailQueue::vfunc_2 (50 B): matches/0x00282610.cpp [wrapped: conflict: CMotionTrailQueue]
// sym: ?vfunc_2@CMotionTrailQueue@fn_00282610@@QAEPAV12@E@Z
namespace fn_00282610 {
extern "C++" __declspec(nothrow) void __cdecl subFree_0008d340(void* p);
extern "C++" __declspec(nothrow) void __cdecl objDelete_00263f30(void* p);
extern const char hulk_at_0042c48c[];

class CMotionTrailQueue {
  public:
    virtual ~CMotionTrailQueue();
    char pad[0x58];
    void* m_sub;
    void Cleanup_002a4ff0();
    CMotionTrailQueue* vfunc_2(unsigned char flag);
};

CMotionTrailQueue* CMotionTrailQueue::vfunc_2(unsigned char flag) {
    void* sub = m_sub;
    *(const char**)this = hulk_at_0042c48c;
    subFree_0008d340(sub);
    Cleanup_002a4ff0();
    if (flag & 1) {
        objDelete_00263f30((void*)this);
    }
    return this;
}
} // namespace fn_00282610

namespace fn_f4890d4c {

// 0x00282650 pure3d::prop::CMotionTrailQueue::vfunc_9 (50 B): matches/0x00282650.cpp
// sym: ?vfunc_9@CMotionTrailQueue@fn_f4890d4c@@QAEXXZ
void CMotionTrailQueue::vfunc_9() {
    int i = 0;
    state = 1;
    for (int j = 0; j < 0x60; j += 0x10, i += 8) {
        (*(Item_282650**)(items + j))->n();
        bytes[i + 4] = 0;
    }
}

} // namespace fn_f4890d4c

// 0x00282690 pure3d::prop::CMotionTrailQueue::vfunc_8 (76 B): matches/0x00282690.cpp
// sym: ?vfunc_8@CMotionTrailQueue@prop@pure3d@@UAEXHH@Z
void pure3d::prop::CMotionTrailQueue::vfunc_8(hulk_intptr a, int b) {
    for (int i = 0; i < 6; ++i) {
        if ((*(char * *)&this->f_5c)[i * 8 + 4]) {
            if (a) {
                ((Helper_282690*)a)->helper_0029b9d0(this, i, 0, b);
            } else {
                Obj_282690* o = *(Obj_282690**)((*(char * *)&this->f_48) + i * 16);
                o->f6();
            }
        }
    }
}


// 0x002826e0 pure3d::prop::CMotionTrailQueue::vfunc_6 (88 B): matches/0x002826e0.cpp
// sym: ?vfunc_6@CMotionTrailQueue@prop@pure3d@@UAEXHH@Z
void pure3d::prop::CMotionTrailQueue::vfunc_6(int arg, int unused) {
    int i;
    for (i = 0; i < 6; i++) {
        Item_2826e0* p = (*(Entry_2826e0 * *)&this->f_48)[i].p;
        if ((*(char * *)&this->f_5c)[i * 8 + 4] && p) {
            p->call(arg, 0);
            if (p->test())
                (*(char * *)&this->f_5c)[i * 8 + 4] = 0;
        }
    }
}

namespace fn_f4890d4c {

// 0x00282740 FUN_00282740 (78 B): matches/0x00282740.cpp
// sym: ?Update@Obj_282740@fn_f4890d4c@@QAEXI@Z
// data: zero_282740 = DAT_003f32e0
void Obj_282740::Update(unsigned int key) {
    unsigned int* p = keys;
    int i = 0;
    while (i < 6) {
        if (*p == key) {
            Item_282740* v = items[key % 6].ptr;
            if (v->value > DAT_003f32e0)
                v->value = 0.0f;
            return;
        }
        ++i;
        p += 2;
    }
}

} // namespace fn_f4890d4c

// 0x00282790 FUN_00282790 (69 B): matches/0x00282790.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CMotionTrail@fn_00282790@@QAE@XZ
namespace fn_00282790 {
class DrawablePrimitive_282790 {
  public:
    virtual void Dummy_00038290();
    DrawablePrimitive_282790();
};
class CMotionTrail : public DrawablePrimitive_282790 {
  public:
    virtual void V();
    char p0[0x0c];
    int x;
    char p1[0x2c];
    int a;
    int b;
    char p2[0x1c];
    void* p;
    char p3[0x0c];
    void* q;
    void* r;
    CMotionTrail();
};
extern void* __cdecl Alloc_0008d6d0(unsigned int);
void CMotionTrail::V() {}
CMotionTrail::CMotionTrail() {
    a = 0;
    b = 0;
    x = 1;
    p = Alloc_0008d6d0(8000);
    q = Alloc_0008d6d0(0x18);
    r = Alloc_0008d6d0(0x48);
}
} // namespace fn_00282790


// 0x002827e0 pure3d::prop::CMotionTrail::vfunc_10 (195 B): equivalent/0x002827e0.cpp [wrapped: conflict: pure3d::prop::CMotionTrail]
// sym: ?vfunc_10@CMotionTrail@prop@pure3d@fn_002827e0@@UAEXXZ @3f0e2904b203 @w10c67fbb91ac
namespace fn_002827e0 {
// STATUS: equivalent (tools/equiv.py level 3: 667 inputs, branch coverage 6/6)
// pure3d::prop::CMotionTrail::vfunc_10 @ 0x002827e0
struct Vector { float x,y,z; };
struct Sphere_2827e0 { float x,y,z,r; };
struct Bounds_2827e0 { float values[6]; void FUN_000a87f0(Vector*); Sphere_2827e0* FUN_000a8890(Sphere_2827e0*); };
namespace pure3d { namespace prop {
struct CMotionTrail {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
 char pad04[16]; Bounds_2827e0 bounds; Sphere_2827e0 sphere; char pad3c[8]; int active; int count; char pad4c[24]; char* samples; int index; int span;
};
void CMotionTrail::vfunc_10() {
 if(active) {
   int offset=0;
   for(int i=0;i<count;++i,offset+=12) {
     bounds.FUN_000a87f0((Vector*)(samples+index*160+offset));
     int sum=span+index;
     int next=(sum%(sum-1))%50;
     bounds.FUN_000a87f0((Vector*)(samples+next*160+offset));
   }
   Sphere_2827e0 temporary;
   Sphere_2827e0* result=bounds.FUN_000a8890(&temporary);
   sphere.x=result->x; sphere.y=result->y; sphere.z=result->z; sphere.r=result->r;
 } else {
   for(int j=0;j<6;++j) bounds.values[j]=0.0f;
   sphere.x=0.0f; sphere.y=0.0f; sphere.z=0.0f; sphere.r=0.0f;
 }
}
}}
} // namespace fn_002827e0


// 0x002828b0 pure3d::prop::CMotionTrail::vfunc_13 (43 B): matches/0x002828b0.cpp
// sym: ?vfunc_13@CMotionTrail@prop@pure3d@@UAEXXZ
void pure3d::prop::CMotionTrail::vfunc_13() {
    if ((*(Ref_2828b0 * *)&this->f_40)) {
        (*(Ref_2828b0 * *)&this->f_40)->f1();
        (*(Ref_2828b0 * *)&this->f_40) = 0;
    }
    if ((*(Ref_2828b0 * *)&this->f_44)) {
        (*(Ref_2828b0 * *)&this->f_44)->f1();
        (*(Ref_2828b0 * *)&this->f_44) = 0;
    }
}


// 0x002828e0 FUN_002828e0 (296 B): equivalent/0x002828e0.cpp [wrapped: conflict: Object]
// sym: ?FUN_002828e0@Object@fn_002828e0@@QAEXIMPAUResource_2828e0@2@0PBUKey_2828e0@2@PBUTriple_2828e0@2@H1IIIMMM@Z @c552b7fb1706 @w5add3f6cfc60
namespace fn_002828e0 {
// STATUS: equivalent (tools/equiv.py level 3: 236 inputs, branch coverage 12/12)
// FUN_002828e0 @ 0x002828e0
struct Key_2828e0 { unsigned a,b; };
struct Triple_2828e0 { unsigned a,b,c; };
struct Resource_2828e0 { virtual void AddRef(); virtual void Release(); unsigned FUN_002843a0(unsigned a,unsigned b); };
struct Object {
 char pad[0x40]; Resource_2828e0* first; Resource_2828e0* second; int count; float invC,invA,invB; unsigned x,y,z; char gap[4]; unsigned zeroA,zeroB,result; unsigned* indices; Triple_2828e0* triples; unsigned finalA; float finalB,invFinal;
 void FUN_002828e0(unsigned a,float b,Resource_2828e0* r2,Resource_2828e0* r1,const Key_2828e0* keys,const Triple_2828e0* data,int n,const Key_2828e0* key,unsigned x0,unsigned y0,unsigned z0,float f1,float f2,float f3);
};
void Object::FUN_002828e0(unsigned a,float b,Resource_2828e0* r2,Resource_2828e0* r1,const Key_2828e0* keys,const Triple_2828e0* data,int n,const Key_2828e0* key,unsigned x0,unsigned y0,unsigned z0,float f1,float f2,float f3) {
 if(r1) r1->AddRef();
 if(first) first->Release();
 first=r1;
 if(r2) r2->AddRef();
 if(second) second->Release();
 second=r2;
 count=n;
 invB=1.0f/f3; invA=1.0f/f1; invC=1.0f/f2;
 x=x0; y=y0; z=z0;
 result=r2->FUN_002843a0(key->a,key->b);
 zeroA=0; zeroB=0;
 for(int i=0;i<n;++i) {
 indices[i]=r2->FUN_002843a0(keys[i].a,keys[i].b);
 triples[i].a=data[i].a; triples[i].b=data[i].b; triples[i].c=data[i].c;
 }
 finalA=a; finalB=b; invFinal=1.0f/b;
}
} // namespace fn_002828e0

namespace fn_f4890d4c {

// 0x00282a10 FUN_00282a10 (739 B): equivalent/0x00282a10.cpp
// sym: ?Blend@VertexBuf_282a10@fn_f4890d4c@@QAEXPAU12@HMMMMMM@Z @316b6e5fec4f @w99ad888a32e6
// STATUS: equivalent (tools/equiv.py level 3: 2552 inputs, branch coverage 22/22)
// FUN_00282a10 @ 0x00282a10
void VertexBuf_282a10::Blend(VertexBuf_282a10 *src, int count, float a3, float a4, float a5, float a6, float a7, float a8)
{
    double t = 1.0f - (double)a3 * a6;
    if (!(t > 0.0f))
        t = 0.0f;

    for (int i = 0; i < count; i++) {
        for (int k = 0; k < 3; k++)
            w[i * 3 + k].f = (float)((src->w[i * 3 + k].f - src->w[0x24 + k].f) * t + src->w[0x24 + k].f);
        w[0x12 + i * 3 + 0].u = src->w[0x12 + i * 3 + 0].u;
        w[0x12 + i * 3 + 1].u = src->w[0x12 + i * 3 + 1].u;
        w[0x12 + i * 3 + 2].u = src->w[0x12 + i * 3 + 2].u;
    }

    double y = 1.0f - (double)a3 * a7;
    if (!(y > 0.0f))
        y = 0.0f;
    if (a4 < 0.0f) {
        double s = (double)a4 * a5 + 1.0f;
        if (!(s > 0.0f))
            s = 0.0f;
        y = y * s;
    }
    int v = (int)(__int64)(y * 255.0f); // _ftol: the low word of the 64-bit conversion
    w[0x30].u = ((((0xffffff00u | v) << 8) | v) << 8) | v;

    double z = 1.0f - (double)a3 * a8;
    if (!(z > 0.0f))
        z = 0.0f;
    for (int k = 0; k < count; k++)
        w[0x24 + k * 2].f = (float)z;
}

} // namespace fn_f4890d4c

// 0x00282d00 pure3d::prop::CMotionTrail::vfunc_6 (983 B): equivalent/0x00282d00.cpp [wrapped: conflict: DAT_0052c2a8]
// sym: ?vfunc_6@CMotionTrail@fn_00282d00@@UAEXXZ @7bcd6a42704e @wad6fdb823d0c
namespace fn_00282d00 {
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 16/16)
// pure3d::prop::CMotionTrail::vfunc_6 @ 0x00282d00
struct Vec3 {
    float x, y, z;
};

struct UV {
    float u, v;
};

class VertexBuffer {
public:
    char pad00[8];
    Vec3 *pos;
    char padc[4];
    unsigned int *color;
    UV *uv;
    void FUN_0008ef00();
};

class Device {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual VertexBuffer *v30(void *handle, int a, int flags, int size, int b);
    virtual void v31(VertexBuffer *vb);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int v);
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62(int v);
    virtual char v63();
};

struct RingElem {
    char pad00[0x9c];
    float vstep;
};

struct Slice {
    Vec3 pos[6];
    Vec3 aux[6];
    UV uv[6];
    unsigned int color;
    void FUN_00282a10(RingElem *e, int n, float v, int a, int b, int c, int d, int f);
};

struct Handle {
    char pad00[0x10];
    void *handle;
};


#define DAT_0052c2a8 (*(Device * *)&::DAT_0052c2a8)


struct Vec3i {
    int x, y, z;
};

struct UVi {
    int u, v;
};

// One vertex: the original loads each of the buffer's attribute pointers once and copies
// the words as integers.
static inline void Emit(VertexBuffer *vb, const Vec3 *p, unsigned int color, const UV *uv)
{
    Vec3i *dst = (Vec3i *)vb->pos;
    const Vec3i *src = (const Vec3i *)p;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    *vb->color = color;
    UVi *t = (UVi *)vb->uv;
    t->u = ((const UVi *)uv)->u;
    t->v = ((const UVi *)uv)->v;
    vb->FUN_0008ef00();
}

class CMotionTrail {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0x40 - 4];
    Handle *shader;
    char pad44[4];
    int segs;
    int p4c;
    int p50;
    int p54;
    char pad58[0x64 - 0x58];
    RingElem *ring;
    int head;
    int count;
    char pad70[0x7c - 0x70];
    int p7c;
    char pad80[4];
    int p84;
};

// Every local sits at the original's frame offset, r0/r1 at the top next to the return
// address: with more than 6 segments the uv loops run past uv[6] and the emit loops read
// past the strips into these slots (diffBA/diffAB are the original's pointer-difference
// temporaries), so the layout is observable.
struct Frame {
    int innerI;
    int j;
    Slice *a;
    Slice *b;
    int slot20;
    float v;
    unsigned int color;
    union {
        char c;
        int i;
    } saved1;
    int saved2;
    hulk_intptr diffBA;
    hulk_intptr diffAB;
    Slice r0;
    Slice r1;
};

void CMotionTrail::vfunc_6()
{
    if (shader == 0) {
        return;
    }
    if (count < 2) {
        return;
    }
    Frame f;
    f.saved1.c = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    f.saved2 = DAT_0052c2a8->v55();
    DAT_0052c2a8->v54(0);

    f.a = &f.r0;
    f.b = &f.r1;
    f.a->FUN_00282a10(&ring[(count + head - 1) % 50], segs, 0.0f, p7c, p84, p50, p4c, p54);
    for (int i = 0; i < segs; i++) {
        float t = (float)i / (float)(segs - 1);
        f.r1.uv[i].v = t;
        f.r0.uv[i].v = t;
    }
    VertexBuffer *vb = DAT_0052c2a8->v30(shader->handle, 1, 0x2021, (segs + 1) * (count - 1) * 2, 0);
    f.v = 0.0f;
    for (f.j = count - 1; f.j > 0; f.j--) {
        int idx = (f.j + head - 1) % 50;
        f.v = f.v + ring[idx].vstep;
        f.b->FUN_00282a10(&ring[idx], segs, f.v, p7c, p84, p50, p4c, p54);
        f.color = f.a->color;
        Emit(vb, &f.a->pos[0], f.color, &f.a->uv[0]);
        Emit(vb, &f.b->pos[0], f.b->color, &f.b->uv[0]);
        if (segs > 1) {
            f.diffBA = (char *)f.b - (char *)f.a;
            f.diffAB = (char *)f.a - (char *)f.b;
        }
        for (f.innerI = 1; f.innerI < segs; f.innerI++) {
            Emit(vb, &f.a->pos[f.innerI], f.color, &f.a->uv[f.innerI]);
            Emit(vb, &f.b->pos[f.innerI], f.b->color, &f.b->uv[f.innerI]);
        }
        Emit(vb, &f.b->pos[segs - 1], f.b->color, &f.b->uv[segs - 1]);
        Emit(vb, &f.b->pos[0], f.b->color, &f.b->uv[0]);
        Slice *tmp = f.a;
        f.a = f.b;
        f.b = tmp;
    }
    DAT_0052c2a8->v31(vb);
    DAT_0052c2a8->v62(f.saved1.i);
    DAT_0052c2a8->v54(f.saved2);
}
} // namespace fn_00282d00
#undef DAT_0052c2a8


// 0x002830e0 pure3d::prop::CMotionTrail::vfunc_8 (38 B): matches/0x002830e0.cpp
// sym: ?vfunc_8@CMotionTrail@prop@pure3d@@UAEXPAX@Z
void pure3d::prop::CMotionTrail::vfunc_8(void* __p0) { Obj_2830e0 * p = (Obj_2830e0 *)__p0;

    if (p)
        p->f();
    if ((*(Obj_2830e0 * *)&this->f_40))
        (*(Obj_2830e0 * *)&this->f_40)->g();
    (*(Obj_2830e0 * *)&this->f_40) = p;
}


// 0x00283110 pure3d::prop::CMotionTrail::vfunc_11 (523 B): equivalent/0x00283110.cpp
// sym: ?vfunc_11@CMotionTrail@prop@pure3d@@UAEXMH@Z @04aefaf5a1d4 @wd3ac202b70e3
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 26/26)
// pure3d::prop::CMotionTrail::vfunc_11 @ 0x00283110
void pure3d::prop::CMotionTrail::vfunc_11(float dt, int unused) {
    struct Frame {
        Vec3_283110 d;
        float lenSq;
        Vec3_283110 pts[6];
        Vec3_283110 cross[6];
        struct { volatile unsigned x, y, z; } p;
        volatile float savedDt;
    } fr;

    if ((*(void * *)&this->f_40) == 0)
        return;
    if (this->f_7c > 0.0f && this->f_70 != 0xffff) {
        const unsigned *root = (const unsigned *)((*(TrailData * *)&this->f_44)->joints + 64 * this->f_70 + 0x30);
        fr.p.x = root[0];
        fr.p.y = root[1];
        fr.p.z = root[2];
        for (int i = 0; i < this->f_48; i++) {
            JointXform *m = (JointXform *)((*(TrailData * *)&this->f_44)->joints + 64 * (*(int * *)&this->f_74)[i]);
            m->FUN_0022c2b0((*(Vec3_283110 * *)&this->f_78) + i, &fr.pts[i]);
        }
        float maxSq = 0.0f;
        if (this->f_6c > 0) {
            TrailSample *s = (*(TrailSample * *)&this->f_64) + (this->f_68 + this->f_6c - 1) % 50;
            int n = this->f_48;
            const Vec3_283110 *cur = s->pos;
            Vec3_283110 *pt = fr.pts;
            Vec3_283110 *cr = fr.cross;
            for (int i = 0; i < n; i++) {
                fr.d.x = cur->x - pt->x;
                fr.d.y = cur->y - pt->y;
                fr.d.z = cur->z - pt->z;
                fr.lenSq = fr.d.z * fr.d.z + fr.d.y * fr.d.y + fr.d.x * fr.d.x;
                if (maxSq < fr.lenSq)
                    maxSq = fr.lenSq;
                if (i > 1) {
                    float wx = cur[-1].x - pt->x;
                    float wy = cur[-1].y - pt->y;
                    float wz = cur[-1].z - pt->z;
                    cr->x = fr.d.y * wz - wy * fr.d.z;
                    cr->y = fr.d.z * wx - wz * fr.d.x;
                    cr->z = wy * fr.d.x - fr.d.y * wx;
                }
                cur++;
                pt++;
                cr++;
            }
        }
        fr.savedDt = dt;
        if (sqrt(maxSq) > 0.01f || this->f_6c == 0) {
            if (this->f_6c < 49)
                this->f_6c++;
            else
                this->f_68 = (this->f_68 + 1) % 50;
            (*(TrailSample * *)&this->f_64)[(this->f_68 + this->f_6c - 1) % 50].FUN_0027fa00(fr.pts);
        }
    }
    this->f_7c -= dt;
}

namespace fn_f4890d4c {

// 0x00283320 FUN_00283320 (30 B): matches/0x00283320.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f4890d4c@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_0027fee0*)(this))->FUN_0027fee0();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00283340 FUN_00283340 (90 B): matches/0x00283340.cpp
// sym: ?run@C_283340@fn_f4890d4c@@QAEXXZ
void C_283340::run() {
    ((owners::Owner_280160 *)x)->FUN_00280160();
    y->FUN_00280800();
    Holder_283340* s = h;
    if (s->a) {
        s->a->f1();
        s->a = 0;
    }
    if (s->b) {
        s->b->f1();
        s->b = 0;
    }
    if (s->c) {
        s->c->f1();
        s->c = 0;
    }
    z->f9();
}


// 0x002833a0 FUN_002833a0 (71 B): matches/0x002833a0.cpp
// sym: ?set@Owner_2833a0@fn_f4890d4c@@QAEXPAVItem_2833a0@2@@Z
void Owner_2833a0::set(Item_2833a0* p) {
    if (p)
        p->A();
    if (item)
        item->B();
    item = p;
    Inner_2833a0* q = inner;
    if (p)
        p->A();
    if (q->item)
        q->item->B();
    q->item = p;
    q->value = 0xf;
}


// 0x002833f0 FUN_002833f0 (60 B): matches/0x002833f0.cpp
// sym: ?target@C_2833f0@fn_f4890d4c@@QAEXXZ
void C_2833f0::target() {
    B_2833f0* b = m10;
    if (b->m18) {
        b->m18->g();
        b->m18 = 0;
    }
    b->m1c = 0;
    b->m14 = 0xf;
    if (m0) {
        m0->g();
        m0 = 0;
    }
}


// 0x00283450 FUN_00283450 (8 B): matches/0x00283450.cpp
// sym: ?f@C_283450@fn_f4890d4c@@QAEXHHHH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void C_283450::f(hulk_intptr a0, hulk_intptr a1, hulk_intptr a2, int a3) {
    field->Fng_002804f0(a0, a1, a2, a3);
}


// 0x00283460 FUN_00283460 (26 B): matches/0x00283460.cpp
// sym: ?Fn@Target@fn_f4890d4c@@QAEXHHH@Z
void Target::Fn(int a, int b, int c) {
    ptr->Fn_00280630(a, b, c);
    _ReadWriteBarrier();
}


// 0x00283480 FUN_00283480 (34 B): matches/0x00283480.cpp
// sym: ?go@T_283480@fn_f4890d4c@@QAEXH@Z
void T_283480::go(int x) {
    hulk_at_0052c2a8->v[91](hulk_at_0052c2a8);
    m->Fnf_00282140(x);
}


// 0x002834b0 FUN_002834b0 (34 B): matches/0x002834b0.cpp
// sym: ?go@T_2834b0@fn_f4890d4c@@QAEXH@Z
// Same code shape as 0x00283480 (propagated; names are from that function)
void T_2834b0::go(int x) {
    gObj_2834b0->v[91](gObj_2834b0);
    m->Fnf_00282190(x);
}


// 0x002834e0 FUN_002834e0 (8 B): matches/0x002834e0.cpp
// sym: ?f@X_2834e0@fn_f4890d4c@@QAEXH@Z
// Same code shape as 0x001c37f0 (propagated; names are from that function)
void X_2834e0::f(int a0) {
    p->Fng_00282740(a0);
}


// 0x002834f0 FUN_002834f0 (22 B): matches/0x002834f0.cpp
// sym: ??1EffectQueue_2834f0@fn_f4890d4c@@QAE@XZ
// Same code shape as 0x001c5640 (propagated; names are from that function)
EffectQueue_2834f0::~EffectQueue_2834f0() {
    ((owners::Owner_280160 *)this)->FUN_00280160();
    Cleanup2_0027afd0();
}


// 0x00283510 FUN_00283510 (138 B): equivalent/0x00283510.cpp
// sym: ?Add@Table_283510@fn_f4890d4c@@QAEHPAURefObj_283510@2@HHH@Z @c2678efca2a8 @w8ea1629742fd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00283510 @ 0x00283510
int Table_283510::Add(RefObj_283510* o, int a, int b, int c) {
    int i = 0;
    while (i < 100) {
        if (!rec[i + 1].obj) break;
        i++;
    }
    if (i >= 100) return 0;
    int id = rec[0].f10;
    rec[i].id = id;
    rec[i].flag = 0;
    if (o) o->AddRef();
    RefObj_283510* old = rec[i + 1].obj;
    if (old) old->Release();
    rec[i + 1].obj = o;
    rec[i + 1].f4 = 0; rec[i + 1].f8 = 0; rec[i + 1].fc = 0;
    rec[i + 1].f10 = 0xffff;
    FUN_002804f0(id, a, b, c);
    rec[0].f10++;
    return id;
}


// 0x002835a0 FUN_002835a0 (57 B): matches/0x002835a0.cpp
// sym: ??1CDecalQueue@fn_f4890d4c@@QAE@XZ
CDecalQueue::~CDecalQueue() {
    Init_00280800();
    for (int i = 0; i < 100; i++) {
        if (items[i].p) {
            items[i].p->B();
            items[i].p = 0;
        }
    }
    Tail_0027afd0();
}


// 0x002835e0 FUN_002835e0 (81 B): matches/0x002835e0.cpp
// sym: ?FUN_002835e0@fn_f4890d4c@@YIXPAVCLightQueue@1@@Z
void __fastcall FUN_002835e0(CLightQueue* self) {
    self->vptr = (void*)((hulk_intptr)DAT_0042c514);
    _ReadWriteBarrier();
    if (self->m2c) {
        self->m2c->Release();
        self->m2c = 0;
    }
    if (self->m20) {
        self->m20->Release();
        self->m20 = 0;
    }
    if (self->m54) {
        self->m54->Release();
        self->m54 = 0;
    }
    if (self->m14) {
        self->m14->Release();
        self->m14 = 0;
    }
    FUN_0027afd0(self);
}

} // namespace fn_f4890d4c

// 0x00283640 FUN_00283640 (235 B): equivalent/0x00283640.cpp [wrapped: conflict: Object]
// sym: ?update@Object@fn_00283640@@QAEXM@Z @49c44143ba61 @w7ebaa7ac1d51
namespace fn_00283640 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// FUN_00283640 @ 0x00283640
struct Vec3_283640 { float x,y,z; };
struct Transform_283640 {  char storage[64]; };
struct Owner_283640 { virtual void slot0(); virtual void release(); char pad[0x18]; Transform_283640* transforms; };
struct Effect_283640 { virtual void slot0(); virtual void release(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void position(Vec3_283640*); char pad[0x14]; Vec3_283640 pos; };
struct Object { char pad[0x1c]; unsigned field1c; Owner_283640* owner; unsigned index; float lifetime; Effect_283640* effect; Vec3_283640 location; Vec3_283640 center; float radius; void FUN_00282400(void*); void update(float dt); };
void Object::update(float dt) {
 if (!effect) return;
 if (lifetime >= 0.0f) {
  double t = (double)lifetime - dt;
  lifetime = (float)t;
  if (t < 0.0f) {
   if (effect) { effect->release(); effect = 0; }
   if (owner) { owner->release(); owner = 0; }
  }
 }
 if (!effect) return;
 Vec3_283640 temp;
 Vec3_283640* p = &location;
 if (index != 0xffff) {
  ((owners::Mat_22c2b0 *)&(owner->transforms[index]))->FUN_0022c2b0((float *)(Vec3_283640 *)(&location), (float *)(Vec3_283640 *)(&temp));
  p = &temp;
 }
 effect->position(p);
 double x = (double)center.x - effect->pos.x;
 double y = (double)center.y - effect->pos.y;
 double z = (double)center.z - effect->pos.z;
 double r = radius;
 if (r*r < ((z*z + x*x) + y*y)) FUN_00282400(&field1c);
}
} // namespace fn_00283640


// 0x00283730 FUN_00283730 (162 B): equivalent/0x00283730.cpp [wrapped: conflict: CMotionTrail]
// sym: ?FUN_00283730@CMotionTrailQueue@fn_00283730@@QAEPAV12@XZ @5e0d8f4c334f @w5fb9867707b2
namespace fn_00283730 {
// STATUS: equivalent (tools/equiv.py level 3: 2865 inputs, branch coverage 4/4)
// FUN_00283730 @ 0x00283730
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
extern "C" char DAT_0042c48c[];
extern "C" char DAT_0042c52c[];
void *FUN_0008d6d0(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);

class CMotionTrail {
public:
    hulk_intptr vt;
    char pad1[0x0c];
    int f10;
    char pad2[0x2c];
    int f40;
    int f44;
    char pad3[0x1c];
    void *f64;
    char pad4[0x0c];
    void *f74;
    void *f78;
    void FUN_002a5060();
};

class CMotionTrailQueue {
public:
    hulk_intptr vt;
    char pad1[0x54];
    int f58;
    unsigned char *flags;
    void FUN_002a4e10(int n);
    void FUN_002a4500(int idx, CMotionTrail *t);
    CMotionTrailQueue *FUN_00283730();
};

CMotionTrailQueue *CMotionTrailQueue::FUN_00283730()
{
    FUN_002a4e10(6);
    vt = (hulk_intptr)DAT_0042c48c;
    f58 = 1;
    flags = (unsigned char *)FUN_0008d6d0(0x30);
    for (int i = 0; i < 6; i++) {
        CMotionTrail *t = (CMotionTrail *)thunk_FUN_0008d690(0x88);
        if (t) {
            t->FUN_002a5060();
            t->vt = (hulk_intptr)DAT_0042c52c;
            t->f40 = 0;
            t->f44 = 0;
            t->f10 = 1;
            t->f64 = FUN_0008d6d0(8000);
            t->f74 = FUN_0008d6d0(0x18);
            t->f78 = FUN_0008d6d0(0x48);
        }
        FUN_002a4500(i, t);
        flags[i * 8 + 4] = 0;
    }
    return this;
}
} // namespace fn_00283730

namespace fn_f4890d4c {

// 0x002837e0 FUN_002837e0 (142 B): matches/0x002837e0.cpp
// sym: ?Run@Obj_2837e0@fn_f4890d4c@@QAEIHHHHHHHHUV3_2837e0@2@HHH@Z
unsigned Obj_2837e0::Run(int a, int b, int c, int d, int e, int f, int g, int h, V3_2837e0 v, int i, int j, int k) {
    unsigned n = mCount;
    unsigned idx = n % 6;
    ((Inner_2837e0*)(*(char**)(mArr + idx * 16)))->Fn_002828e0(a, b, c, d, e, f, g, h, v, i, j, k);
    *(unsigned*)(mInfo + idx * 8) = n;
    *(char*)(mInfo + idx * 8 + 4) = 1;
    mCount++;
    return n;
}

} // namespace fn_f4890d4c

// 0x00283870 FUN_00283870 (85 B): matches/0x00283870.cpp [wrapped: conflict: CMotionTrail]
// sym: ?Dtor@CMotionTrail@fn_00283870@@QAEXXZ
namespace fn_00283870 {
extern "C" void _ReadWriteBarrier();
extern char hulk_at_0042c52c[];
class Ref_283870 {
  public:
    virtual void f0();
    virtual void f1();
};
class DrawablePrimitive_283870 {
  public:
    void BaseDtor_002a50a0();
};
extern void __cdecl thunk_FUN_00267090(void*);
class CMotionTrail : public DrawablePrimitive_283870 {
  public:
    void* vptr;
    char p[0x3c];
    Ref_283870* m40;
    Ref_283870* m44;
    char p48[0x1c];
    void* m64;
    char p68[0xc];
    void* m74;
    void* m78;
    void Dtor();
};
void CMotionTrail::Dtor() {
    vptr = hulk_at_0042c52c;
    _ReadWriteBarrier();
    if (m40) {
        m40->f1();
        m40 = 0;
    }
    if (m44) {
        m44->f1();
        m44 = 0;
    }
    thunk_FUN_00267090(m64);
    thunk_FUN_00267090(m74);
    thunk_FUN_00267090(m78);
    BaseDtor_002a50a0();
}
} // namespace fn_00283870

namespace fn_f4890d4c {

// 0x00283900 FUN_00283900 (268 B): equivalent/0x00283900.cpp
// sym: ?FUN_00283900@Manager_283900@fn_f4890d4c@@QAEPAU12@II@Z @cf959d6c53d3 @w060ae1b7813d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_00283900 @ 0x00283900
Manager_283900* Manager_283900::FUN_00283900(unsigned ownerValue, unsigned context) {
 state=0; owner=ownerValue; enabled=1; first=0; second=0; third=0; fourth=0;
 (*(Manager_283900**)&DAT_0052c29c)=this;
 Resource_283900* storage=(Resource_283900*)FUN_00263ea0(0x2598);
 Resource_283900* value=storage ? storage->FUN_00280120() : 0;
 if(value) value->acquire();
 if(first) first->release();
 first=value;
 storage=(Resource_283900*)FUN_00263ea0(0xb10);
 value=storage ? storage->FUN_00280690(context) : 0;
 if(value) value->acquire();
 if(second) second->release();
 second=value;
 storage=(Resource_283900*)FUN_00263ea0(0x58);
 value=storage ? storage->FUN_002821d0() : 0;
 if(value) value->acquire();
 if(third) third->release();
 third=value;
 storage=(Resource_283900*)FUN_00263ea0(0x60);
 value=storage ? storage->FUN_00283730() : 0;
 if(value) value->acquire();
 if(fourth) fourth->release();
 fourth=value;
 return this;
}


// 0x00283a10 FUN_00283a10 (42 B): matches/0x00283a10.cpp
// sym: ?Run@A_283a10@fn_f4890d4c@@QAEXH@Z
void A_283a10::Run(int x) {
    a->FnF_002801b0(x);
    b->FnG_00283640(x);
    c->f6(x, 0);
}

} // namespace fn_f4890d4c

// 0x00283a40 FUN_00283a40 (195 B): equivalent/0x00283a40.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?FUN_00283a40@Target_283a40@fn_00283a40@@QAEIPAUKey_283a40@2@III@Z @95e737a07ec2 @w1d428ef4d55e
namespace fn_00283a40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283a40 @ 0x00283a40
namespace pure3d { class DrawableHierarchy; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Key_283a40 { unsigned a,b; };
struct Hierarchy_283a40 { virtual void acquire(); virtual void release(); };
struct Item_283a40 { virtual void v0(); virtual void v1(); virtual void v2(); virtual Item_283a40* lookup(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned,unsigned); virtual Hierarchy_283a40* hierarchy(); };
struct Inventory_283a40 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void size(unsigned*,unsigned,unsigned,unsigned); };
Inventory_283a40* __cdecl FUN_00266f40(unsigned);
unsigned __cdecl FUN_00266da0(unsigned);
struct Context { unsigned FUN_00280380(Hierarchy_283a40*,unsigned,unsigned,unsigned,unsigned); };
struct Target_283a40 { Item_283a40* source; unsigned id; unsigned pad; Context* context; void FUN_0027fff0(Hierarchy_283a40*,unsigned); hulk_uintptr FUN_00283a40(Key_283a40*,hulk_uintptr,unsigned,unsigned); };
hulk_uintptr Target_283a40::FUN_00283a40(Key_283a40* key,hulk_uintptr a,unsigned b,unsigned c) {
 if (!source) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Item_283a40* item=source->lookup(&caster,key->a,key->b);
 if (!item) return 0;
 unsigned size;
 FUN_00266f40(id)->size(&size,0,0,0);
 if(size<0xc800) return 0;
 unsigned saved=FUN_00266da0(id);
 Hierarchy_283a40* h=item->hierarchy();
 FUN_00266da0(saved);
 h->acquire();
 FUN_0027fff0(h,c);
 unsigned result=context->FUN_00280380(h,0,0,a,b);
 h->release();
 return result;
}
} // namespace fn_00283a40


// 0x00283b10 FUN_00283b10 (201 B): equivalent/0x00283b10.cpp [wrapped: conflict: FUN_00266f40; content::LoadInventory::DynamicCaster; pure3d::DrawableHierarchy]
// sym: ?run@Target_283b10@fn_00283b10@@QAEIPAUKey_283b10@2@IIIII@Z @2cd3a9d3d3fb @w602eb1faf5e5
namespace fn_00283b10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283b10 @ 0x00283b10
namespace pure3d { struct DrawableHierarchy { virtual void retain(); virtual void release(); }; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Key_283b10 { unsigned first, second; };
struct Item_283b10 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual pure3d::DrawableHierarchy* get(); };
struct Inventory_283b10 { virtual void f0(); virtual void f1(); virtual void f2(); virtual Item_283b10* find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*, unsigned, unsigned); };
struct Status_283b10 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void query(unsigned*, unsigned, unsigned, unsigned); };
extern Status_283b10* __cdecl FUN_00266f40(unsigned);
extern unsigned __cdecl FUN_00266da0(unsigned);
struct Builder { unsigned FUN_00280380(pure3d::DrawableHierarchy*, unsigned, unsigned, unsigned, unsigned); };
struct Target_283b10 { Inventory_283b10* inventory; unsigned context; unsigned unused; Builder* builder; void FUN_0027fff0(pure3d::DrawableHierarchy*, unsigned); unsigned run(Key_283b10*,unsigned,unsigned,unsigned,unsigned,unsigned); };
unsigned Target_283b10::run(Key_283b10* key,unsigned a,unsigned b,unsigned c,unsigned d,unsigned e) {
 if (!inventory) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Item_283b10* item=inventory->find(&caster,key->first,key->second);
 if (!item) return 0;
 unsigned amount;
 FUN_00266f40(context)->query(&amount,0,0,0);
 if(amount<0xc800) return 0;
 unsigned saved=FUN_00266da0(context);
 pure3d::DrawableHierarchy* drawable=item->get();
 FUN_00266da0(saved);
 drawable->retain();
 FUN_0027fff0(drawable,e);
 unsigned result=builder->FUN_00280380(drawable,a,b,c,d);
 drawable->release();
 return result;
}
} // namespace fn_00283b10


// 0x00283be0 FUN_00283be0 (191 B): equivalent/0x00283be0.cpp [wrapped: conflict: FUN_00266f40; content::LoadInventory::DynamicCaster]
// sym: ?FUN_00283be0@Target_283be0@fn_00283be0@@QAEIPAUPair_283be0@2@III@Z @126b0589a92e @w2d7155e2a926
namespace fn_00283be0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283be0 @ 0x00283be0
namespace pure3d { class DrawableHierarchy; }
namespace content { namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void Cast(); };
} }
struct Pair_283be0 { unsigned first, second; };
struct Item_283be0 {
 virtual void AddRef();
 virtual void Release();
 virtual void slot2();
 virtual void slot3();
 virtual Item_283be0* GetItem();
};
struct Source_283be0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual Item_283be0* Find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned,unsigned);
};
struct Stats_283be0 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
 virtual void Query(unsigned*,unsigned,unsigned,unsigned);
};
extern Stats_283be0* __cdecl FUN_00266f40(unsigned);
extern unsigned __cdecl FUN_00266da0(unsigned);
struct Manager_283be0 { unsigned FUN_00280460(Item_283be0*,unsigned,unsigned); };
struct Target_283be0 {
 Source_283be0* source; unsigned id; unsigned pad; Manager_283be0* manager;
 void FUN_0027fff0(Item_283be0*,unsigned);
 unsigned FUN_00283be0(Pair_283be0*,unsigned,unsigned,unsigned);
};
unsigned Target_283be0::FUN_00283be0(Pair_283be0* pair,unsigned a,unsigned b,unsigned c) {
 if (!source) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Item_283be0* item=source->Find(&caster,pair->first,pair->second);
 if (!item) return 0;
 unsigned size;
 Stats_283be0* stats=FUN_00266f40(id);
 stats->Query(&size,0,0,0);
 if(size<0xc800u) return 0;
 unsigned handle=FUN_00266da0(id);
 item=item->GetItem();
 FUN_00266da0(handle);
 item->AddRef();
 FUN_0027fff0(item,c);
 unsigned result=manager->FUN_00280460(item,a,b);
 item->Release();
 return result;
}
} // namespace fn_00283be0


// 0x00283ca0 FUN_00283ca0 (179 B): equivalent/0x00283ca0.cpp [wrapped: conflict: FUN_00266f40; content::LoadInventory; pure3d::DrawableHierarchy]
// sym: ?FUN_00283ca0@Target_283ca0@fn_00283ca0@@QAEHPAUKey_283ca0@2@III@Z @7181eeada214 @w41ac377c9709
namespace fn_00283ca0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00283ca0 @ 0x00283ca0
namespace pure3d { struct DrawableHierarchy { virtual void AddRef(); virtual void Release(); }; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual T* Cast(void*); }; }; }
struct Key_283ca0 { unsigned a,b; };
struct Entry_283ca0 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual pure3d::DrawableHierarchy* m4(); };
struct Inventory_283ca0 { virtual void m0(); virtual void m1(); virtual void m2(); virtual Entry_283ca0* Find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*,unsigned,unsigned); };
struct Stats_283ca0 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void Query(unsigned*,unsigned,unsigned,unsigned); };
extern Stats_283ca0* __cdecl FUN_00266f40(unsigned);
extern unsigned __cdecl FUN_00266da0(unsigned);
struct Destination_283ca0 { int FUN_00283510(pure3d::DrawableHierarchy*,unsigned,unsigned,unsigned); };
struct Target_283ca0 { Inventory_283ca0* inventory; unsigned id; unsigned pad; Destination_283ca0* dest; hulk_intptr FUN_00283ca0(Key_283ca0*,hulk_uintptr,hulk_uintptr,unsigned); };
hulk_intptr Target_283ca0::FUN_00283ca0(Key_283ca0* key,hulk_uintptr a,hulk_uintptr b,unsigned c) {
 if (!inventory) return 0;
 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
 Entry_283ca0* entry=inventory->Find(&caster,key->a,key->b);
 if (!entry) return 0;
 unsigned count;
 FUN_00266f40(id)->Query(&count,0,0,0);
 if(count<0xc800) return 0;
 unsigned handle=FUN_00266da0(id);
 pure3d::DrawableHierarchy* drawable=entry->m4();
 FUN_00266da0(handle);
 drawable->AddRef();
 int result=dest->FUN_00283510(drawable,a,b,c);
 drawable->Release();
 return result;
}
} // namespace fn_00283ca0

namespace fn_f4890d4c {

// 0x00283d60 FUN_00283d60 (91 B): matches/0x00283d60.cpp
// sym: ?Go@Obj_283d60@fn_f4890d4c@@QAEHHHHHHHHHUTriple_283d60@2@HHH@Z
int Obj_283d60::Go(int a, int b, int c, int d, int e, int f, int g, int h, Triple_283d60 t, int j, int k, int l) {
    return mgr->Fn_002837e0(a, b, c, d, e, f, g, h, t, j, k, l);
}


// 0x00283dc0 pure3d::prop::EffectQueue::vfunc_2 (43 B): matches/0x00283dc0.cpp
// sym: ?scalar_dtor@EffectQueue_283dc0@fn_f4890d4c@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* EffectQueue_283dc0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0042c4dc;
    ((owners::Owner_280160 *)this)->FUN_00280160();
    base2_dtor_0027afd0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f4890d4c

// 0x00283df0 pure3d::prop::CDecalQueue::vfunc_2 (30 B): matches/0x00283df0.cpp
// sym: ??_GCDecalQueue@prop@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::prop::CDecalQueue::~CDecalQueue() {}


// 0x00283e10 FUN_00283e10 (1108 B): equivalent/0x00283e10.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?FUN_00283e10@Target_283e10@fn_00283e10@@QAEIPA_KHPAUWorld@2@PAUV3_283e10@2@2PAMHH@Z @7c2c623e1574 @w368831714e12
namespace fn_00283e10 {
// STATUS: equivalent (tools/equiv.py level 3: 158 inputs, branch coverage 26/28, incomplete)
// FUN_00283e10 @ 0x00283e10
// FUN_00283e10 @ 0x00283e10: queue a screen quad: clip it against the view planes and emit its vertices


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


typedef unsigned __int64 Key_283e10;

namespace pure3d { class Shader; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct V3_283e10 {
    float x, y, z;
    void FUN_00011090();
};

struct Mat4_283e10 {
    float m[16];
    void FUN_0022ba00();
    void FUN_0022be40(const V3_283e10 *pos);
    void FUN_0022bec0(const V3_283e10 *fwd, const V3_283e10 *up);
    void FUN_0022c120();
    void FUN_0022c410(int n, const V3_283e10 *src, V3_283e10 *dst);
};

struct Plane_283e10 {
    float a, b, c, d;
    void FUN_00078850();
    void FUN_0022dfe0(const V3_283e10 *p0, const V3_283e10 *p1, const V3_283e10 *p2);
};

void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3_283e10::*ctor)());
void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Plane_283e10::*ctor)());

struct Vert {
    V3_283e10 pos;
    float w;
    float uv[2];
};

struct Clip {
    char data[0x48];
};

class Renderer_283e10 {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void v13(const V3_283e10 *pos, float w, const float *uv);
};

class Batch_283e10 {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual Renderer_283e10 *v4();
    virtual void v5(Renderer_283e10 *r);
    virtual void v6();
};

class Chunks_283e10 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void v6(unsigned int id, int flag);
};

class Shader {
public:
    virtual void addRef();
    virtual void release();
    char pad4[0xc];
    Chunks_283e10 *chunks;
};

class Loader_283e10 {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual Shader *v3(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster, Key_283e10 key);
};

struct World {
    void FUN_002f3830(V3_283e10 *out, int a1);
};

struct Slot_283e10 {
    unsigned int id;
    int tag;
    Shader *shader;
    V3_283e10 pos;
    Batch_283e10 *batch;
};

int __cdecl FUN_00266da0(int mode);
void __cdecl FUN_00281fd0(World *w, float *size, Mat4_283e10 *m, int n, void **objs, Clip *clips);
void __cdecl FUN_00281e60(Plane_283e10 *planes, Clip *clip, Vert *out, int *n);

class Target_283e10;

struct Frame_283e10 {
    union {
        float negHalfH;          // 0x00
        int nloc;
    } u0;
    union {
        Slot_283e10 *slot;              // 0x04
        Batch_283e10 *batch;
    } u4;
    int cnt;                     // 0x08
    Target_283e10 *self;                // 0x0c
    int stash10;                 // 0x10
    unsigned int c;              // 0x14
    Shader *shader;              // 0x18
    content::LoadInventory::DynamicCaster<pure3d::Shader> caster;  // 0x1c
    int oldMode;                 // 0x20
    V3_283e10 out24;                    // 0x24
    V3_283e10 corners[4];               // 0x30
    V3_283e10 p;                        // 0x60
    Mat4_283e10 m;                      // 0x6c
    Plane_283e10 planes[4];             // 0xac
    Mat4_283e10 m2;                     // 0xec
    void *objs[40];              // 0x12c
    Clip clips[40];              // 0x1cc
    Vert verts[0x42];            // 0xd0c
    char unused[0x7d8c - 0xd0c - 0x42 * 0x18];
};

class Target_283e10 {
public:
    char pad0[0x10];
    unsigned int counter;        // 0x10
    int count;                   // 0x14
    Loader_283e10 *loader;              // 0x18
    int mode;                    // 0x1c
    Slot_283e10 slots[100];             // 0x20
    unsigned int FUN_00283e10(Key_283e10 *key, int a1, World *world, V3_283e10 *pos, V3_283e10 *up, float *size, int a6, int a7);
    void FUN_002809b0(World *w, V3_283e10 *pos, float radius, int a1, int a1b, void **out, int *cnt, int max, int z0, int z1);
};

unsigned int Target_283e10::FUN_00283e10(Key_283e10 *key, int a1, World *world, V3_283e10 *pos, V3_283e10 *up, float *size, int a6, int a7)
{
    Frame_283e10 f;
    int i;
    f.self = this;
    new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Shader>;
    f.shader = loader->v3(&f.caster, *key);
    if (f.shader == 0)
        return 0;
    int n0 = count;
    if (n0 <= 1)
        return 0;
    f.c = counter;
    Slot_283e10 *slot = &slots[f.c % 100];
    f.u4.slot = slot;
    count = n0 - 1;
    f.shader->chunks->v6(0x444d5655, 1);
    world->FUN_002f3830(&f.out24, a1);
    f.m.FUN_0022ba00();
    f.m.FUN_0022be40(pos);
    f.m.FUN_0022bec0(&f.out24, up);
    memcpy(&f.m2, &f.m, sizeof(Mat4_283e10));
    f.m2.FUN_0022c120();
    FUN_00011520(f.planes, 0x10, 4, &Plane_283e10::FUN_00078850);
    FUN_00011520(f.corners, 0xc, 4, &V3_283e10::FUN_00011090);
    float hw = size[0] * 0.5f;
    float hh = size[1] * 0.5f;
    f.corners[0].z = 0;
    f.corners[1].z = 0;
    f.corners[2].z = 0;
    f.corners[3].z = 0;
    f.corners[0].x = -hw;
    f.u0.negHalfH = -hh;
    f.corners[0].y = f.u0.negHalfH;
    f.corners[3].y = f.u0.negHalfH;
    f.corners[1].x = -hw;
    f.corners[1].y = hh;
    f.corners[2].x = hw;
    f.corners[2].y = hh;
    f.corners[3].x = hw;
    f.m.FUN_0022c410(4, f.corners, f.corners);
    for (i = 0; i < 4; i++) {
        f.p.x = f.out24.x + f.corners[i].x;
        f.p.y = f.out24.y + f.corners[i].y;
        f.p.z = f.out24.z + f.corners[i].z;
        f.planes[i].FUN_0022dfe0(&f.corners[i], &f.corners[(i + 1) % 4], &f.p);
        f.planes[i].a = f.planes[i].a * -1.0f;
        f.planes[i].b = f.planes[i].b * -1.0f;
        f.planes[i].c = f.planes[i].c * -1.0f;
        f.planes[i].d = f.planes[i].d * -1.0f;
    }
    f.cnt = 0;
    float radius = (size[0] < size[1] ? size[1] : size[0]) * 0.71f;
    FUN_002809b0(world, pos, radius, a1, a1, f.objs, &f.cnt, 0x28, 0, 0);
    FUN_00281fd0(world, size, &f.m2, f.cnt, f.objs, f.clips);
    int total = 0;
    int cnt = f.cnt;
    if (cnt > 0) {
        for (i = 0; i < f.cnt; i++) {
            FUN_00281e60(f.planes, &f.clips[i], &f.verts[total], &f.u0.nloc);
            total += f.u0.nloc;
        }
        if (total > 0) {
            f.oldMode = FUN_00266da0(mode);
            if (total >= 0x42)
                total = 0x42;
            f.u4.batch = slot->batch;
            Renderer_283e10 *r = f.u4.batch->v4();
            for (i = 0; i < total; i++)
                r->v13(&f.verts[i].pos, f.verts[i].w, f.verts[i].uv);
            if (total < 0x42) {
                Vert *last = &f.verts[total - 1];
                for (i = 0x42 - total; i > 0; i--)
                    r->v13(&last->pos, last->w, last->uv);
            }
            f.u4.batch->v5(r);
            f.u4.batch->v6();
            FUN_00266da0(f.oldMode);
        }
    }
    f.shader->addRef();
    if (slot->shader != 0)
        slot->shader->release();
    slot->shader = f.shader;
    slot->tag = a7;
    slot->id = f.c;
    slot->pos = *pos;
    counter = counter + 1;
    return f.c;
}
} // namespace fn_00283e10


// 0x00284270 pure3d::prop::CLightQueue::vfunc_2 (30 B): matches/0x00284270.cpp
// sym: ??_GCLightQueue@prop@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::prop::CLightQueue::~CLightQueue() {}


// 0x00284290 pure3d::prop::CMotionTrail::vfunc_2 (30 B): matches/0x00284290.cpp
// sym: ??_GCMotionTrail@prop@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::prop::CMotionTrail::~CMotionTrail() {}

namespace fn_f4890d4c {

// 0x002842e0 FUN_002842e0 (8 B): matches/0x002842e0.cpp
// sym: ?target@C_2842e0@fn_f4890d4c@@QAEHHHHHHHHH@Z
// Same code shape as 0x0027ff80 (propagated; names are from that function)
hulk_intptr C_2842e0::target(hulk_intptr a0, int a1, int a2, hulk_intptr a3, hulk_intptr a4, hulk_intptr a5, int a6, int a7) {
    return member->Fnf_00283e10(a0, a1, a2, a3, a4, a5, a6, a7);
}


// 0x002842f0 FUN_002842f0 (164 B): matches/0x002842f0.cpp
// sym: ?FUN_002842f0@Frames_2842f0@fn_f4890d4c@@QAEPAUClone@2@XZ
// FUN_002842f0 @ 0x002842f0
Clone * Frames_2842f0::FUN_002842f0()
{
    Clone *dst = maker->FUN_0027b240();
    for (unsigned int i = 0; i < count; i++) {
        dst->blocksA[i] = blocksA[i];
        dst->blocksB[i] = blocksB[i];
        dst->rows[i] = rows[i];
        if (extraRows != 0)
            dst->extraRows[i] = extraRows[i];
    }
    return dst;
}


// 0x002843a0 FUN_002843a0 (21 B): matches/0x002843a0.cpp
// sym: ?Fn@Thing@fn_f4890d4c@@QAEHHH@Z
int Thing::Fn(int a, int b) {
    int r_ret = field->Call_0027b200(a, b);
    _ReadWriteBarrier();
    return r_ret;
}

} // namespace fn_f4890d4c
