// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x002980b0..0x0029b100 (kind game, layer engine, confidence high), dominant class pure3d::OldCompositeDrawableLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/content.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f40ca5f7 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f40ca5f7 {} using namespace fn_f40ca5f7;
namespace fn_f40ca5f7 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f40ca5f7 {
struct Pair3 { Vec3 first, second; void FUN_002980b0(Vec3* out); };
extern "C" char DAT_0042d484[];
struct CompositeDrawable {
    void* vf;
    char pad[0x3c];
    int a, b, c, d, e;
    void Init_002a3480();
    CompositeDrawable* Run();
};
class ParamValue_298270 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
struct Matrix3_298530 { float r[3][4]; };
struct Box_298530 { float min[3]; float max[3]; void FUN_00298530(const Matrix3_298530* m, const Box_298530* src); };
struct Pt_298530 { float v[3];  };
static inline float fabsf_(float f)
{
    union { float f; unsigned int u; } x;
    x.f = f;
    x.u &= 0x7fffffff;
    return x.f;
}
class X_2987b0 {
  public:
    char pad[8];
    class Y_2987b0* p;
    void f();
};
class Y_2987b0 {
  public:
    virtual void a();
    virtual void b();
};
struct Queue {
    char pad0[0x20];
    unsigned char count;
    char pad21[3];
    unsigned char* reverse;
    char pad28[8];
    unsigned char* entries;
    void FUN_00298810(unsigned char index);
};
struct Entry_298870 {
    char pad[8];
    void* p;
};
class Obj_298870 {
  public:
    char pad00[0x20];
    unsigned char count;
    char pad21[3];
    unsigned char* out;
    char pad28[8];
    unsigned char* other;
    char pad34[8];
    Entry_298870* entries;
    Entry_298870* end;
    void Run();
};
struct Entry { char pad[8]; int first; int second; };
struct Item {
  public:
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    char _m_pad_4[0x4];
    Entry *entry;
    void FUN_00288080(int);
};
struct Owner {
  public:
    char _m_pad_0[0x3c];
    Item *begin;
    union { Item *end; int value; };
    char _m_pad_44[0x8];
    Item* item;
    unsigned char FUN_00298960(const int *key);
    void FUN_00298f90(Item* p);
};
typedef unsigned char u8_2989c0;
typedef unsigned int u32_2989c0;
} // namespace fn_f40ca5f7
namespace pure3d {
struct Drawable_298b30 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned arg, unsigned flag);
 unsigned char FUN_00284ae0();
};
}
namespace pure3d {
struct State_298b30 { void FUN_00284820(unsigned); };
}
namespace pure3d {
struct Entry_298b30 { unsigned a,b; Drawable_298b30* drawable; };
}
namespace pure3d {
struct Hierarchy_298b30 { char pad[0x20]; unsigned char count; char pad2[15]; unsigned char* indices; char pad3[8]; Entry_298b30* entries; };
}
namespace pure3d {
struct Alternate { char pad[8]; unsigned char count; char pad2[15]; unsigned char* indices; char pad3[8]; Drawable_298b30** entries; };
}
namespace pure3d {
struct CompositeDrawable_nv_298b30 {
    unsigned char FUN_00284ae0();
};
}
namespace fn_f40ca5f7 {
class Obj_298c00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual char Check();
};
class Obj22 {
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
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual char Check();
};
struct First_298c00 {
    char pad20[0x20];
    unsigned char count;
    char pad[0xf];
    unsigned char* ids;
    char pad2[8];
    Obj_298c00** objs;
};
struct Second_298c00 {
    char pad8[8];
    unsigned char count;
    char pad[0xf];
    unsigned char* ids;
    char pad2[8];
    Obj22** objs;
};
struct Matrix_298cb0 {
    float m[16];
    void FUN_0022b980();
};
struct V3_298cb0 {
    float x, y, z;
};
class Part_298cb0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetVisible(int a, int b);
    char pad04[0x10 - 4];
    char flag;
};
struct Transforms {
    char pad0[0x1c];
    Matrix_298cb0 *matrices;
};
struct Anchor_298cb0 {
    char pad0[0x4c];
    V3_298cb0 offset;
};
struct Owner_298cb0 {
    char pad0[0x18];
    Anchor_298cb0 *anchor;
    Anchor_298cb0 *FUN_0029b490();
};
class Element_298cb0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Draw(Owner_298cb0 *owner, int arg);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int GetKind();
};
struct Entry_298cb0 {
    char kind;
    char pad1[3];
    int index;
    Element_298cb0 *element;
};
struct DrawList {
    char pad0[0x20];
    unsigned char count;
    char pad21[0x30 - 0x21];
    unsigned char *order;
    char pad34[0x3c - 0x34];
    Entry_298cb0 *entries;
};
class Device_298cb0 {
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
    virtual void SetState(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void SetTransform(int a, Matrix_298cb0 *m);
};
struct DeviceRef { Device_298cb0 *device; };
struct Camera_298cb0 {
    char pad0[0x8c];
    struct Xf { char pad[0x30]; V3_298cb0 pos; } xf;
    Xf *FUN_0028faa0();
};
struct CameraRef { Camera_298cb0 *camera; };
struct Node_298e60 {
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
};
struct Group_298e60 {
    char pad00[0x20];
    unsigned char count;
    char pad21[0xf];
    unsigned char *order;
    char pad34[8];
    struct Slot_298e60 *slots;
    void FUN_00298870();
};
struct Slot_298e60 {
    char pad00[8];
    Node_298e60 *node;
};
struct Alt {
    char pad00[8];
    unsigned char count;
    char pad09[0xf];
    unsigned char *order;
    char pad1c[8];
    Node_298e60 **nodes;
};
class Shader {
public:
    virtual void AddRef();
    virtual void Release();
};
class CompositeDrawable_298f00;
struct Slot_298f00 {
    char pad00[8];
    CompositeDrawable_298f00 *drawable;     // 0x8
};
struct SlotList_298f00 {
    char pad00[0x3c];
    Slot_298f00 *begin;            // 0x3c
    Slot_298f00 *end;              // 0x40
};
struct Listener_298f00 {
    void FUN_00288080(Shader *shader);
};
class CompositeDrawable_298f00 {
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
    virtual void vfunc_10(Shader *shader);
    char pad04[0x3c];
    Shader *shader;         // 0x40
    SlotList_298f00 *slots;        // 0x44
    char pad48[4];
    Listener_298f00 *listener;     // 0x4c
};
class Ref_299010 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Child_299010 {
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
    virtual void v13(Ref_299010 *r);
};
struct Elem_299010 { int a; int b; Child_299010 *c; };
struct Impl_299010 { char pad[0x3c]; Elem_299010 *begin; Elem_299010 *end; };
class Item_299080 {
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
    virtual void reset();
};
struct Entry_299080 {
    char pad[8];
    Item_299080* item;
};
struct Array {
    Entry_299080* first;
    Entry_299080* last;
    unsigned char size() const { return (unsigned char)(last - first); }
};
struct Vec_299080 {
    char pad[0x3c];
    Array arr;
};
class Ref_299080 {
  public:
    virtual void f0();
    virtual void release();
};
class Ref_299170 {
  public:
    virtual void f0();
    virtual void Release();
};
class Target_299170 {
  public:
    char pad[8];
    Ref_299170* mRef;
    hulk_intptr Destroy(int flags);
};
extern void __cdecl thunk_FUN_00267090(Target_299170*);
typedef unsigned int u32_2991b0;
typedef unsigned char u8_299230;
class Ref_299250 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class DrawableHierarchy_299250 {
  public:
    virtual ~DrawableHierarchy_299250() throw();
    char pad[0x3c];
};
class CompositeDrawable_299250 : public DrawableHierarchy_299250 {
  public:
    virtual ~CompositeDrawable_299250() throw();
    void Clear_00299080();
    Ref_299250* a;
    Ref_299250* b;
    Ref_299250* c;
    Ref_299250* d;
    Ref_299250* e;
};
struct Mat_2992c0 { float m[16]; };
struct Box_2992c0 {
    float min[3];
    float max[3];
    void FUN_00298530(const Mat_2992c0 *m, const Box_2992c0 *src);
    float *FUN_000a8890(float *tmp);
};
class Drawable_2992c0 {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15();
    char pad04[0x14 - 4];
    Box_2992c0 bounds;
};
struct Entry_2992c0 {
    char type;
    char pad1[3];
    int matrixIndex;
    Drawable_2992c0 *drawable;
};
struct Layout_2992c0 {
    char pad0[0x20];
    unsigned char count;
    char pad21[0x30 - 0x21];
    unsigned char *order;
    char pad34[0x3c - 0x34];
    Entry_2992c0 *entries;
};
struct Skeleton_2992c0 {
    char pad0[0x1c];
    Mat_2992c0 *matrices;
};
extern "C" char DAT_0042d4d4[];
class CompositeDrawableLoader : public HulkChunkHandler {
  public:
    CompositeDrawableLoader();
};
extern void* hulk_at_0042d50c[];
} // namespace fn_f40ca5f7
void operator delete(void*);
namespace fn_f40ca5f7 {
class Ref_299830 {
  public:
    virtual void F0();
    virtual void Release();
};
class ActiveControllerList_299830 {
  public:
    void* vptr;
    char pad[8];
    void* mc;
    char pad2[8];
    void* m18;
    char pad3[8];
    Ref_299830** m24;
    Ref_299830** m28;
    ~ActiveControllerList_299830();
};
void *__cdecl FUN_0008d690(unsigned int size);
class RefCounted_2998d0 {
public:
    virtual void addRef();
    virtual void release();
};
class Item_2998d0 {
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
    virtual unsigned count();
    virtual void v17();
    virtual RefCounted_2998d0 *get(unsigned index);
};
struct Entry_2998d0 {
    int a;
    int b;
    Item_2998d0 *item;
};
struct Source_2998d0 {
    char pad[0x3c];
    Entry_2998d0 *begin;
    Entry_2998d0 *end;
};
struct ActiveControllerList_nv_2998d0 {
    pure3d::CompositeDrawable::ActiveControllerList *FUN_00299680(unsigned count);
};
class Owner_2998d0 {
public:
    char pad00[0x44];
    Source_2998d0 *source;          // 0x44
    pure3d::CompositeDrawable::ActiveControllerList *bundle;          // 0x48
    RefCounted_2998d0 *extraA;      // 0x4c
    RefCounted_2998d0 *extraB;      // 0x50

    void FUN_002998d0(unsigned char release);
};
class X_299ac0 {
  public:
    virtual void A();
    virtual void B();
};
struct Item_299ac0 {
    char pad[8];
    X_299ac0* p;
};
struct Obj_299ba0 {
    int a;
    int b;
};
class DynamicCaster_299bc0 {
  public:
    DynamicCaster_299bc0(unsigned __int64& v) { v = v; }
    virtual void Fna_001a6ee0(void*);
    virtual void b();
    virtual void Fnc_001a6f10(void*);
    virtual void d();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void f(DynamicCaster_299bc0*, unsigned __int64);
};
extern "C" unsigned __int64 __cdecl Make(int);
extern int hulk_at_0042d51c;
extern void* Alloc_0008d6d0(unsigned int) throw();
struct Buf_299cd0 {
    char* b;
    char* e;
    void Init(unsigned n) throw() {
        if (n > 0) {
            b = (char*)Alloc_0008d6d0(n);
            if (b) {
                e = b + n;
                return;
            }
        }
        b = 0;
        e = 0;
    }
};
struct Sub_299cd0 {
    void Fill_00299540(unsigned, const unsigned char*) throw();
};
class ActivePrimitiveList_299cd0 {
  public:
    void* vptr;
    int a4;
    Buf_299cd0 x8;
    int p10;
    Buf_299cd0 x14;
    int p1c;
    char c20;
    char p21[3];
    Buf_299cd0 x24;
    int p2c;
    Buf_299cd0 x30;
    int p38;
    Sub_299cd0 s3c;
    ActivePrimitiveList_299cd0(unsigned char n) throw();
};
extern void __cdecl Release_0008d340(void*) throw();
extern void __cdecl FUN_00299ac0(void*, void*) throw();
template <int N> struct Buf_299fa0 {
    void* p;
    char pad[N - 4];
    ~Buf_299fa0() {
        if (p)
            Release_0008d340(p);
    }
};
struct Range_299fa0 {
    void* b;
    void* e;
    ~Range_299fa0() {
        if (b) {
            FUN_00299ac0(b, e);
            Release_0008d340(b);
        }
    }
};
class IRefCount {
  public:
    virtual ~IRefCount() {}
    int pad4;
};
class ActivePrimitiveList_299fa0 : public IRefCount {
  public:
    Buf_299fa0<0xc> m8;
    Buf_299fa0<0x10> m14;
    Buf_299fa0<0xc> m24;
    Buf_299fa0<0xc> m30;
    Range_299fa0 m3c;
    virtual ~ActivePrimitiveList_299fa0();
};
class Allocated_29a170 {
  public:
    hulk_intptr method_0029a010(pure3d::CompositeDrawable*);
};
extern Allocated_29a170* alloc_00263ea0(int);


// 0x002980b0 FUN_002980b0 (90 B): equivalent/0x002980b0.cpp
// sym: ?FUN_002980b0@Pair3@fn_f40ca5f7@@QAEXPAUVec3@2@@Z @6727dab31689 @w44d6e41f23ee
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002980b0 @ 0x002980b0
void Pair3::FUN_002980b0(Vec3* out) {
    out->x = (first.x + second.x) * 0.5f;
    out->y = (first.y + second.y) * 0.5f;
    out->z = (first.z + second.z) * 0.5f;
}


// 0x00298180 FUN_00298180 (63 B): equivalent/0x00298180.cpp
// sym: _FUN_00298180 @84d313291030 @w4a7f9a58af6d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00298180 @ 0x00298180
extern "C" int __cdecl FUN_00298180(int value) {
    switch (value) {
    case 2: return 1;
    case 4: return 2;
    case 8: return 3;
    case 16: return 6;
    case 32: return 4;
    case 64: return 5;
    default: return 0;
    }
}


// 0x00298230 FUN_00298230 (35 B): matches/0x00298230.cpp
// sym: ?Run@CompositeDrawable@fn_f40ca5f7@@QAEPAU12@XZ
CompositeDrawable* CompositeDrawable::Run() {
    Init_002a3480();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    vf = (void*)((hulk_intptr)DAT_0042d484);
    return this;
}

} // namespace fn_f40ca5f7

// 0x00298260 pure3d::CompositeDrawable::vfunc_11 (4 B): matches/0x00298260.cpp
// sym: ?vfunc_11@CompositeDrawable@pure3d@@UAEIXZ
// Same code shape as 0x00069100 (propagated; names are from that function)
hulk_uintptr pure3d::CompositeDrawable::vfunc_11() {
    return this->f_40;
}


// 0x00298270 pure3d::CompositeDrawable::vfunc_5 (6 B): matches/0x00298270.cpp
// sym: ?vfunc_5@CompositeDrawable@pure3d@@UAEHXZ
// Same code shape as 0x00055210 (propagated; names are from that function)
int pure3d::CompositeDrawable::vfunc_5() {
    return 4;
}


// 0x00298280 pure3d::CompositeDrawable::vfunc_3 (3 B): matches/0x00298280.cpp
// sym: ?vfunc_3@CompositeDrawable@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::CompositeDrawable::vfunc_3() {
    return true;
}

namespace fn_f40ca5f7 {

// 0x00298530 FUN_00298530 (471 B): equivalent/0x00298530.cpp
// sym: ?FUN_00298530@Box_298530@fn_f40ca5f7@@QAEXPBUMatrix3_298530@2@PBU12@@Z @4047d94ffed3 @w495a7139b0db
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_00298530 @ 0x00298530
void Box_298530::FUN_00298530(const Matrix3_298530* m, const Box_298530* src)
{
    Pt_298530 c;
    float ext[3];
    float p[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        c.v[i] = (src->max[i] + src->min[i]) * 0.5f;
    }
    for (i = 0; i < 3; i++) {
        // the original multiplies the unrounded half-extent for column 0 and the rounded copy for the others
        double hd = src->max[i] - c.v[i];
        volatile float hs = hd;
        p[i][0] = hd * m->r[i][0];
        for (j = 1; j < 3; j++) {
            p[i][j] = hs * m->r[i][j];
        }
    }
    for (j = 0; j < 3; j++) {
        ext[j] = (fabsf_(p[2][j]) + fabsf_(p[1][j])) + fabsf_(p[0][j]);
    }
    ((owners::Obj_22d210 *)&c)->FUN_0022d210((owners::Obj_22d210 *)(const Matrix3_298530 *)m);
    max[0] = ext[0] + c.v[0];
    max[1] = ext[1] + c.v[1];
    max[2] = ext[2] + c.v[2];
    min[0] = c.v[0] - ext[0];
    min[1] = c.v[1] - ext[1];
    min[2] = c.v[2] - ext[2];
}


// 0x002987b0 FUN_002987b0 (24 B): matches/0x002987b0.cpp
// sym: ?f@X_2987b0@fn_f40ca5f7@@QAEXXZ
void X_2987b0::f() {
    if (p) {
        p->b();
        p = 0;
    }
}

} // namespace fn_f40ca5f7

// 0x002987d0 FUN_002987d0 (61 B): matches/0x002987d0.cpp
// sym: ?FUN_002987d0@X_2987d0@owners@@QAEXE@Z
void owners::X_2987d0::FUN_002987d0(unsigned char v) {
    unsigned int i = v;
    if (entries[i * 3 + 2] && buffer[i] == 0xff) {
        buffer[i] = count;
        output[count] = v;
        ++count;
    }
}

namespace fn_f40ca5f7 {

// 0x00298810 FUN_00298810 (81 B): matches/0x00298810.cpp
// sym: ?FUN_00298810@Queue@fn_f40ca5f7@@QAEXE@Z
void Queue::FUN_00298810(unsigned char index) {
    --count;
    unsigned char value = entries[index];
    reverse[value] = 0xff;
    if (count != index) {
        entries[index] = entries[count];
        reverse[entries[index]] = index;
    }
    entries[count] = 0xff;
}


// 0x00298870 FUN_00298870 (106 B): matches/0x00298870.cpp
// sym: ?Run@Obj_298870@fn_f40ca5f7@@QAEXXZ
void Obj_298870::Run() {
    unsigned char* c = &count;
    *c = 0;
    hulk_uintptr n = end - entries;
    for (unsigned int i = 0; i < n; ++i) {
        if (entries[i].p) {
            out[i] = count;
            other[count] = (unsigned char)i;
            ++count;
        } else {
            out[i] = 0xff;
            other[i] = 0xff;
        }
    }
}

} // namespace fn_f40ca5f7

// 0x002988e0 FUN_002988e0 (58 B): matches/0x002988e0.cpp
// sym: ?FUN_002988e0@Obj_2988e0@owners@@QAEXXZ
void owners::Obj_2988e0::FUN_002988e0() {
    unsigned int n = (end - start) / 12;
    unsigned int i = 0;
    if (n != 0) {
        do {
            a[i] = 0xff;
            b[i] = 0xff;
            ++i;
        } while (i < n);
    }
    flag = 0;
}

namespace fn_f40ca5f7 {

// 0x00298960 FUN_00298960 (87 B): equivalent/0x00298960.cpp
// sym: ?FUN_00298960@Owner@fn_f40ca5f7@@QAEEPBH@Z @8a92cdd093e2 @wa65b8c77072d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00298960 @ 0x00298960
unsigned char Owner::FUN_00298960(const int *key) {
    unsigned char count = (unsigned char)(end - begin);
    for (unsigned char i = 0; i < count; ++i) {
        Entry *e = begin[i].entry;
        if (e->first == key[0] && e->second == key[1]) return i;
    }
    return 0xff;
}

} // namespace fn_f40ca5f7

// 0x002989c0 FUN_002989c0 (54 B): matches/0x002989c0.cpp
// sym: ?FUN_002989c0@Buffer_2989c0@owners@@QAEXE@Z
void owners::Buffer_2989c0::FUN_002989c0(u8_2989c0 value) {
    if (flags[value] != 0 && data[value] == 0xff) {
        data[value] = count;
        out[count] = value;
        ++count;
    }
}


// 0x00298a00 FUN_00298a00 (81 B): matches/0x00298a00.cpp
// sym: ?FUN_00298a00@X_298a00@owners@@QAEXE@Z
void owners::X_298a00::FUN_00298a00(unsigned char value) {
    --count;
    map[items[value]] = 0xff;
    if (count != value) {
        unsigned char* it = items;
        it[value] = it[count];
        map[items[value]] = value;
    }
    items[count] = 0xff;
}


// 0x00298a60 FUN_00298a60 (75 B): matches/0x00298a60.cpp
// sym: ?FUN_00298a60@Mapping_298a60@owners@@QAEXXZ
void owners::Mapping_298a60::FUN_00298a60() {
    count = 0;
    _ReadWriteBarrier();
    hulk_uintptr n = last - first;
    unsigned i = 0;
    while (i < n) {
        if (first[i]) {
            forward[i] = count;
            reverse[count] = (unsigned char)i;
            ++count;
        } else {
            forward[i] = 255;
            reverse[i] = 255;
        }
        ++i;
    }
}


// 0x00298b30 pure3d::CompositeDrawable::vfunc_6 (197 B): equivalent/0x00298b30.cpp
// sym: ?vfunc_6@CompositeDrawable@pure3d@@UAEXHH@Z @33715ec383a6 @w5ff139eed54f
// STATUS: equivalent (tools/equiv.py level 3: 2661 inputs, branch coverage 20/20)
// pure3d::CompositeDrawable::vfunc_6 @ 0x00298b30
void pure3d::CompositeDrawable::vfunc_6(int __p0, int __p1) { unsigned int arg = (unsigned int)__p0; unsigned int flag = (unsigned int)__p1;

 if (!(*(Alternate * *)&this->f_48)) {
  unsigned count = (*(Hierarchy_298b30 * *)&this->f_44)->count;
  for(unsigned i=0;i<count;++i) (*(Hierarchy_298b30 * *)&this->f_44)->entries[(*(Hierarchy_298b30 * *)&this->f_44)->indices[i]].drawable->vfunc_6(arg,flag);
  if((*(Drawable_298b30 * *)&this->f_4c)) (*(Drawable_298b30 * *)&this->f_4c)->vfunc_6(arg,flag);
  if((*(Drawable_298b30 * *)&this->f_50)) (*(Drawable_298b30 * *)&this->f_50)->vfunc_6(arg,flag);
 } else {
  unsigned count=(*(Alternate * *)&this->f_48)->count;
  for(unsigned i=0;i<count;++i) (*(Alternate * *)&this->f_48)->entries[(*(Alternate * *)&this->f_48)->indices[i]]->vfunc_6(arg,flag);
 }
 if((*(Drawable_298b30 * *)&this->f_4c)) {
  unsigned char enabled=((CompositeDrawable_nv_298b30*)((*(Drawable_298b30 * *)&this->f_4c)))->FUN_00284ae0();
  if(enabled==1 || (unsigned char)flag==1) (*(State_298b30 * *)&this->f_40)->FUN_00284820(0);
 }
}


// 0x00298c00 pure3d::CompositeDrawable::vfunc_7 (172 B): matches/0x00298c00.cpp
// sym: ?vfunc_7@CompositeDrawable@pure3d@@UAEDXZ
char pure3d::CompositeDrawable::vfunc_7() {
    unsigned char i = 0;
    if (!(*(Second_298c00 * *)&this->f_48)) {
        unsigned char n = (*(First_298c00 * *)&this->f_44)->count;
        while (i < n) {
            Obj_298c00* o = (*(First_298c00 * *)&this->f_44)->objs[(*(First_298c00 * *)&this->f_44)->ids[i] * 3 + 2];
            if (!o->Check())
                return 0;
            ++i;
        }
        if ((*(Obj22 * *)&this->f_4c) && !(*(Obj22 * *)&this->f_4c)->Check())
            return 0;
        if ((*(Obj22 * *)&this->f_50) && !(*(Obj22 * *)&this->f_50)->Check())
            return 0;
    } else {
        unsigned char n = (*(Second_298c00 * *)&this->f_48)->count;
        while (i < n) {
            Obj22* o = (*(Second_298c00 * *)&this->f_48)->objs[(*(Second_298c00 * *)&this->f_48)->ids[i]];
            if (!o->Check())
                return 0;
            ++i;
        }
    }
    return 1;
}


// 0x00298cb0 pure3d::CompositeDrawable::vfunc_8 (432 B): equivalent/0x00298cb0.cpp
// sym: ?vfunc_8@CompositeDrawable@pure3d@@UAEXHH@Z @0aced57464bf @we74120658954
// STATUS: equivalent (tools/equiv.py level 3: 19980 inputs, branch coverage 22/22)
// pure3d::CompositeDrawable::vfunc_8 @ 0x00298cb0
void pure3d::CompositeDrawable::vfunc_8(hulk_intptr __p0, int arg) { Owner_298cb0 * owner = (Owner_298cb0 *)__p0;

    if ((*(Part_298cb0 * *)&this->f_4c) != 0) {
        if (!((char)((owners::C_284ae0 *)((*(Part_298cb0 * *)&this->f_4c)))->FUN_00284ae0())) {
            (*(Part_298cb0 * *)&this->f_4c)->SetVisible(0, 1);
            ((owners::C_284820 *)((*(Transforms * *)&this->f_40)))->FUN_00284820((hulk_intptr)0);
        }
    }
    if ((*(Part_298cb0 * *)&this->f_50) != 0) {
        if (!((char)((owners::C_284ae0 *)((*(Part_298cb0 * *)&this->f_50)))->FUN_00284ae0()))
            (*(Part_298cb0 * *)&this->f_50)->SetVisible(0, 1);
    }
    if (owner != 0) {
        if (owner->FUN_0029b490() != 0) {
            Matrix_298cb0 m;
            V3_298cb0 v;
            m.FUN_0022b980();
            ((owners::Target_22be40 *)&m)->FUN_0022be40((const int *)(const struct V3_298cb0 *)(&(*(CameraRef**)&DAT_0052c2b0)->camera->FUN_0028faa0()->pos));
            v = (*(V3_298cb0 *)&this->f_2c);
            ((owners::Obj_22d210 *)&v)->FUN_0022d210((owners::Obj_22d210 *)(const Matrix_298cb0 *)((*(Transforms * *)&this->f_40)->matrices));
            ((owners::Obj_22d210 *)&v)->FUN_0022d210((owners::Obj_22d210 *)(const Matrix_298cb0 *)(&m));
            owner->FUN_0029b490()->offset = v;
            ((owners::Caller_29fd20 *)(owner->FUN_0029b490()))->FUN_0029fd20((hulk_intptr)(pure3d :: CompositeDrawable *)this);
        }
    }
    unsigned int n = (*(DrawList * *)&this->f_44)->count;
    if (n != 0) {
        for (unsigned int i = 0; n != 0; n--, i++) {
            Entry_298cb0 *e = &(*(DrawList * *)&this->f_44)->entries[(*(DrawList * *)&this->f_44)->order[i]];
            if (e->kind == 1) {
                Element_298cb0 *el = e->element;
                if (el->GetKind() == 2 || el->GetKind() == 0x40) {
                    el->Draw(owner, arg);
                } else {
                    int idx = e->index;
                    (*(DeviceRef**)&DAT_0052c2ac)->device->SetTransform(0, &(*(Transforms * *)&this->f_40)->matrices[idx]);
                    el->Draw(owner, arg);
                    (*(DeviceRef**)&DAT_0052c2ac)->device->SetState(0);
                }
            }
        }
    }
}


// 0x00298e60 pure3d::CompositeDrawable::vfunc_9 (157 B): equivalent/0x00298e60.cpp
// sym: ?vfunc_9@CompositeDrawable@pure3d@@UAEXXZ @dcccde4b2500 @w177e4c9ed4a9
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 16/16)
// pure3d::CompositeDrawable::vfunc_9 @ 0x00298e60
// pure3d::CompositeDrawable::vfunc_9: run the update hook of every child (in order), then of the two extra drawables
void pure3d::CompositeDrawable::vfunc_9() {
    if ((*(Alt * *)&this->f_48) == 0) {
        if ((*(Group_298e60 * *)&this->f_44) != 0) {
            (*(Group_298e60 * *)&this->f_44)->FUN_00298870();
            unsigned char n = (*(Group_298e60 * *)&this->f_44)->count;
            for (unsigned int i = 0; i < n; i++)
                (*(Group_298e60 * *)&this->f_44)->slots[(*(Group_298e60 * *)&this->f_44)->order[i]].node->v9();
        }
        if ((*(Node_298e60 * *)&this->f_4c) != 0)
            (*(Node_298e60 * *)&this->f_4c)->v23();
        if ((*(Node_298e60 * *)&this->f_50) != 0)
            (*(Node_298e60 * *)&this->f_50)->v23();
    } else {
        unsigned char n = (*(Alt * *)&this->f_48)->count;
        for (unsigned int i = 0; i < n; i++)
            (*(Alt * *)&this->f_48)->nodes[(*(Alt * *)&this->f_48)->order[i]]->v23();
    }
}

namespace fn_f40ca5f7 {

// 0x00298f00 pure3d::CompositeDrawable::vfunc_10 (131 B): equivalent/0x00298f00.cpp
// sym: ?vfunc_10@CompositeDrawable_298f00@fn_f40ca5f7@@UAEXPAVShader@2@@Z @1ca3c16eae76 @wb0553895baa0
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 12/12)
// pure3d::CompositeDrawable::vfunc_10 @ 0x00298f00
void CompositeDrawable_298f00::vfunc_10(Shader *newShader)
{
    if (newShader != 0)
        newShader->AddRef();
    if (shader != 0)
        shader->Release();
    shader = newShader;

    if (listener != 0)
        listener->FUN_00288080(newShader);

    unsigned char count = (unsigned char)(slots->end - slots->begin);
    for (unsigned char i = 0; i < count; i++) {
        CompositeDrawable_298f00 *child = slots->begin[i].drawable;
        if (child != 0)
            child->vfunc_10(shader);
    }
}


// 0x00298f90 FUN_00298f90 (57 B): equivalent/0x00298f90.cpp
// sym: ?FUN_00298f90@Owner@fn_f40ca5f7@@QAEXPAUItem@2@@Z @1fbf6a7aa345 @w6f51f28356cd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00298f90 @ 0x00298f90
void Owner::FUN_00298f90(Item* p) { if(p) p->FUN_00000000(); if(item) item->FUN_00000004(); item=p; if(p) p->FUN_00288080(value); }

} // namespace fn_f40ca5f7

// 0x00299010 pure3d::CompositeDrawable::vfunc_13 (109 B): equivalent/0x00299010.cpp
// sym: ?vfunc_13@CompositeDrawable@pure3d@@UAEXPAX@Z @598a25eb245a @wc36161586958
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// pure3d::CompositeDrawable::vfunc_13 @ 0x00299010
void pure3d::CompositeDrawable::vfunc_13(void* __p0) { Ref_299010 * r = (Ref_299010 *)__p0;

    if (r != 0)
        r->AddRef();
    if ((*(Ref_299010 * *)&this->f_10) != 0)
        (*(Ref_299010 * *)&this->f_10)->Release();
    (*(Ref_299010 * *)&this->f_10) = r;
    unsigned int count = (unsigned char)((*(Impl_299010 * *)&this->f_44)->end - (*(Impl_299010 * *)&this->f_44)->begin);
    for (unsigned int i = 0; i < count; i++)
        (*(Impl_299010 * *)&this->f_44)->begin[i].c->v13(r);
}


// 0x00299080 pure3d::CompositeDrawable::vfunc_14 (89 B): matches/0x00299080.cpp
// sym: ?vfunc_14@CompositeDrawable@pure3d@@UAEXXZ
void pure3d::CompositeDrawable::vfunc_14() {
    if ((*(Ref_299080 * *)&this->f_10)) {
        (*(Ref_299080 * *)&this->f_10)->release();
        (*(Ref_299080 * *)&this->f_10) = 0;
    }
    unsigned char n = (*(Vec_299080 * *)&this->f_44)->arr.size();
    for (unsigned char i = 0; i < n; ++i)
        (*(Vec_299080 * *)&this->f_44)->arr.first[i].item->reset();
}

namespace fn_f40ca5f7 {

// 0x00299170 FUN_00299170 (44 B): matches/0x00299170.cpp
// sym: ?Destroy@Target_299170@fn_f40ca5f7@@QAEHH@Z
hulk_intptr Target_299170::Destroy(int flags) {
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    if (flags & 1)
        thunk_FUN_00267090(this);
    return (hulk_intptr)this;
}

} // namespace fn_f40ca5f7

// 0x002991b0 content::LoadInventory::DynamicCaster<pure3d::DrawableContainer>::vfunc_0 (30 B): matches/0x002991b0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VDrawableContainer@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::DrawableContainer>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002991e0 content::LoadInventory::DynamicCaster<pure3d::PolySkin>::vfunc_0 (30 B): matches/0x002991e0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?vfunc_0@DynamicCaster@LoadInventory@content@fn_002991e0@@UAEPAXPAX@Z
namespace fn_002991e0 {
extern char DAT_0048d5bc;
extern char DAT_004cf460;
extern "C" void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
namespace content {
namespace LoadInventory {
class DynamicCasterBase {
  public:
    virtual void* vfunc_0(void*);
};
class DynamicCaster {
  public:
    virtual void* vfunc_0(void*);
};
} // namespace LoadInventory
} // namespace content
void* content::LoadInventory::DynamicCaster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, (const char*)&DAT_0048d5bc, (const char*)&DAT_004cf460, 0);
}
} // namespace fn_002991e0


// 0x00299230 FUN_00299230 (28 B): matches/0x00299230.cpp
// sym: ?FUN_00299230@Obj_299230@owners@@QAEXE@Z
void owners::Obj_299230::FUN_00299230(u8_299230 index) {
    int value = table[index];
    if ((u8_299230)value != 0xff)
        g(value);
}

namespace fn_f40ca5f7 {

// 0x00299250 FUN_00299250 (101 B): matches/0x00299250.cpp
// sym: ??1CompositeDrawable_299250@fn_f40ca5f7@@UAE@XZ
CompositeDrawable_299250::~CompositeDrawable_299250() throw() {
    Clear_00299080();
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
}

} // namespace fn_f40ca5f7

// 0x002992c0 pure3d::CompositeDrawable::vfunc_12 (324 B): equivalent/0x002992c0.cpp
// sym: ?vfunc_12@CompositeDrawable@pure3d@@UAEXXZ @0f0cbc8a0106 @w65cbfa2a63e7
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 10/10)
// pure3d::CompositeDrawable::vfunc_12 @ 0x002992c0
void pure3d::CompositeDrawable::vfunc_12() {
    ((owners::C_284820 *)((*(Skeleton_2992c0 * *)&this->f_40)))->FUN_00284820((hulk_intptr)0);

    (*(Box_2992c0 *)&this->f_14).min[0] = 1e12f;
    (*(Box_2992c0 *)&this->f_14).min[1] = 1e12f;
    (*(Box_2992c0 *)&this->f_14).min[2] = 1e12f;
    (*(Box_2992c0 *)&this->f_14).max[0] = -1e12f;
    (*(Box_2992c0 *)&this->f_14).max[1] = -1e12f;
    (*(Box_2992c0 *)&this->f_14).max[2] = -1e12f;
    (*(float (*)[4])&this->f_2c)[0] = 0.0f;
    (*(float (*)[4])&this->f_2c)[1] = 0.0f;
    (*(float (*)[4])&this->f_2c)[2] = 0.0f;
    (*(float (*)[4])&this->f_2c)[3] = 0.0f;

    Box_2992c0 box;
    unsigned char n = (*(Layout_2992c0 * *)&this->f_44)->count;
    for (int i = 0; i < n; i++) {
        Entry_2992c0 *e = &(*(Layout_2992c0 * *)&this->f_44)->entries[(*(Layout_2992c0 * *)&this->f_44)->order[i]];
        if (e->type == 1) {
            Drawable_2992c0 *d = e->drawable;
            d->vfunc_12();
            box = d->bounds;
            if (d->vfunc_15() != 2 && d->vfunc_15() != 0x40)
                box.FUN_00298530(&(*(Skeleton_2992c0 * *)&this->f_40)->matrices[e->matrixIndex], &box);
            ((owners::V_a87f0 *)&((*(Box_2992c0 *)&this->f_14)))->FUN_000a87f0((owners::V_a87f0 *)(box.min));
            ((owners::V_a87f0 *)&((*(Box_2992c0 *)&this->f_14)))->FUN_000a87f0((owners::V_a87f0 *)(box.max));
        }
    }

    float *s = (*(Box_2992c0 *)&this->f_14).FUN_000a8890(box.min);
    (*(float (*)[4])&this->f_2c)[0] = s[0];
    (*(float (*)[4])&this->f_2c)[1] = s[1];
    (*(float (*)[4])&this->f_2c)[2] = s[2];
    (*(float (*)[4])&this->f_2c)[3] = s[3];
}

namespace fn_f40ca5f7 {

// 0x00299410 FUN_00299410 (27 B): matches/0x00299410.cpp
// sym: ??0CompositeDrawableLoader@fn_f40ca5f7@@QAE@XZ
CompositeDrawableLoader::CompositeDrawableLoader() {
    refs = 0;
    id = 0x123000;
    f0c = 0;
    f10 = 0;
    vftable = (void*)DAT_0042d4d4;
}

} // namespace fn_f40ca5f7

// 0x00299430 pure3d::CompositeDrawableLoader::vfunc_2 (31 B): matches/0x00299430.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00299430@@UAEPAV123@E@Z
namespace fn_00299430 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_299430 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_299430 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00299430


// 0x00299470 pure3d::OldCompositeDrawableLoader::vfunc_2 (31 B): matches/0x00299470.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00299470@@UAEPAV123@E@Z
namespace fn_00299470 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_299470 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_299470 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00299470


// 0x00299540 FUN_00299540 (89 B): equivalent/0x00299540.cpp [wrapped: conflict: Entry]
// sym: ?FUN_00299540@Container@fn_00299540@@QAEPAU12@IH@Z @333c27cd4345 @w6afa5433dd34
namespace fn_00299540 {
// STATUS: equivalent (tools/equiv.py level 3: 2618 inputs, branch coverage 9/10, incomplete)
// FUN_00299540 @ 0x00299540
struct Entry { unsigned char active; char pad[3]; unsigned int first; unsigned int second; }; struct Container { Entry* begin; Entry* end; Container* FUN_00299540(hulk_uintptr count, hulk_intptr unused); }; void* __cdecl FUN_0008d6d0(unsigned int size); Container* Container::FUN_00299540(hulk_uintptr count, hulk_intptr unused) { if (count != 0) { unsigned int bytes = count * 12; Entry* entries = (Entry*)FUN_0008d6d0(bytes); begin = entries; if (entries) { volatile hulk_uintptr limit = (hulk_uintptr)entries + bytes; end = (Entry*)limit; volatile hulk_uintptr cursor = (hulk_uintptr)entries; while (cursor != limit) { Entry* p = (Entry*)cursor; if (p) { p->active = 1; p->first = 0; p->second = 0; } cursor = cursor + 12; } return this; } } begin = 0; end = 0; return this; }
} // namespace fn_00299540


// 0x00299680 FUN_00299680 (140 B): equivalent/0x00299680.cpp [wrapped: conflict: pure3d::CompositeDrawable]
// sym: ??0ActiveControllerList@CompositeDrawable@pure3d@fn_00299680@@QAE@E@Z @2262c52792c1 @w55f110165b7c
namespace fn_00299680 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00299680 @ 0x00299680
// pure3d::CompositeDrawable::ActiveControllerList constructor: three arrays sized by a byte count.
void* __cdecl FUN_0008d6d0(unsigned int size);

namespace pure3d {
class CompositeDrawable {
public:
    class ActiveControllerList {
    public:
        virtual void v0_00018b30();
        int refCount;
        char flag;
        char pad9[3];
        char* firstBegin;
        char* firstEnd;
        char pad14[4];
        char* secondBegin;
        char* secondEnd;
        char pad20[4];
        int* thirdBegin;
        int* thirdEnd;

        ActiveControllerList(unsigned char count);
    };
};
}

pure3d::CompositeDrawable::ActiveControllerList::ActiveControllerList(unsigned char count)
{
    refCount = 0;
    flag = 0;

    if (count > 0) {
        firstBegin = (char*)FUN_0008d6d0(count);
        if (firstBegin) {
            firstEnd = firstBegin + count;
        } else {
            firstBegin = 0;
            firstEnd = 0;
        }
    } else {
        firstBegin = 0;
        firstEnd = 0;
    }

    if (count > 0) {
        secondBegin = (char*)FUN_0008d6d0(count);
        if (secondBegin) {
            secondEnd = secondBegin + count;
        } else {
            secondBegin = 0;
            secondEnd = 0;
        }
    } else {
        secondBegin = 0;
        secondEnd = 0;
    }

    if (count > 0) {
        thirdBegin = (int*)FUN_0008d6d0(count * 4);
        if (thirdBegin) {
            thirdEnd = thirdBegin + count;
            return;
        }
    }
    thirdBegin = 0;
    thirdEnd = 0;
}
} // namespace fn_00299680

namespace fn_f40ca5f7 {

// 0x00299830 FUN_00299830 (120 B): matches/0x00299830.cpp
// sym: ??1ActiveControllerList_299830@fn_f40ca5f7@@QAE@XZ
ActiveControllerList_299830::~ActiveControllerList_299830() {
    vptr = hulk_at_0042d50c;
    _ReadWriteBarrier();
    hulk_uintptr n = m28 - m24;
    for (unsigned i = 0; i < n; i++) {
        Ref_299830** p = &m24[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m24)
        operator delete[](m24);
    if (m18)
        operator delete[](m18);
    if (mc)
        operator delete[](mc);
    vptr = (void**)DAT_003f6098;
}

} // namespace fn_f40ca5f7

// 0x002998b0 pure3d::CompositeDrawable::vfunc_2 (30 B): matches/0x002998b0.cpp
// sym: ??_GCompositeDrawable@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::CompositeDrawable::~CompositeDrawable() {}

namespace fn_f40ca5f7 {

// 0x002998d0 FUN_002998d0 (490 B): equivalent/0x002998d0.cpp
// sym: ?FUN_002998d0@Owner_2998d0@fn_f40ca5f7@@QAEXE@Z @fbcf02934e37 @wd47df86bc918
// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 41/44, incomplete)
// FUN_002998d0 @ 0x002998d0
void Owner_2998d0::FUN_002998d0(unsigned char release)
{
    if (bundle != 0) {
        if (release == 1) {
            if (bundle != 0) {
                bundle->vfunc_1();
                bundle = 0;
            }
        }
        if (bundle != 0)
            return;
    }

    int n = (unsigned char)(source->end - source->begin);
    unsigned total = 0;
    int i;
    for (i = 0; i < n; i++) {
        Item_2998d0 *item = source->begin[(unsigned char)i].item;
        if (item != 0)
            total += item->count();
    }
    if (extraA != 0)
        total++;
    if (extraB != 0)
        total++;

    pure3d::CompositeDrawable::ActiveControllerList *b = (pure3d::CompositeDrawable::ActiveControllerList *)FUN_0008d690(0x30);
    if (b != 0)
        b = ((ActiveControllerList_nv_2998d0*)(b))->FUN_00299680(total);
    bundle = b;
    b->vfunc_0();

    for (i = 0; i < n; i++) {
        Item_2998d0 *item = source->begin[(unsigned char)i].item;
        unsigned j = 0;
        if (item->count() != 0) {
            do {
                *(RefCounted_2998d0 **)&(*(RefCounted_2998d0 ** *)&bundle->f_24)[total - 1] = 0;
                RefCounted_2998d0 **slot = (RefCounted_2998d0 **)&(*(RefCounted_2998d0 ** *)&bundle->f_24)[total - 1];
                RefCounted_2998d0 *r = item->get(j);
                if (r != 0)
                    r->addRef();
                RefCounted_2998d0 *old = *slot;
                if (old != 0)
                    old->release();
                *slot = r;
                total--;
                j++;
            } while (j < item->count());
        }
    }

    if (extraB != 0) {
        *(RefCounted_2998d0 **)&(*(RefCounted_2998d0 ** *)&bundle->f_24)[total - 1] = 0;
        RefCounted_2998d0 *r = extraB;
        RefCounted_2998d0 **slot = (RefCounted_2998d0 **)&(*(RefCounted_2998d0 ** *)&bundle->f_24)[total - 1];
        if (r != 0)
            r->addRef();
        RefCounted_2998d0 *old = *slot;
        if (old != 0)
            old->release();
        *slot = r;
        total--;
    }
    if (extraA != 0) {
        *(RefCounted_2998d0 **)&(*(RefCounted_2998d0 ** *)&bundle->f_24)[total - 1] = 0;
        RefCounted_2998d0 *r = extraA;
        RefCounted_2998d0 **slot = (RefCounted_2998d0 **)&(*(RefCounted_2998d0 ** *)&bundle->f_24)[total - 1];
        if (r != 0)
            r->addRef();
        RefCounted_2998d0 *old = *slot;
        if (old != 0)
            old->release();
        *slot = r;
    }
    ((owners::Mapping_298a60 *)(((ActiveControllerList_nv_2998d0*)(bundle))))->FUN_00298a60();
}


// 0x00299ac0 FUN_00299ac0 (45 B): matches/0x00299ac0.cpp
// sym: ?FUN_00299ac0@fn_f40ca5f7@@YAXPAUItem_299ac0@1@0@Z
void FUN_00299ac0(Item_299ac0* first, Item_299ac0* last) {
    for (; first != last; ++first) {
        if (first->p) {
            first->p->B();
            first->p = 0;
        }
    }
}

} // namespace fn_f40ca5f7

// 0x00299b80 pure3d::CompositeDrawable::ActiveControllerList::vfunc_2 (30 B): matches/0x00299b80.cpp
// sym: ??_GActiveControllerList@CompositeDrawable@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::CompositeDrawable::ActiveControllerList::~ActiveControllerList() {}

namespace fn_f40ca5f7 {

// 0x00299ba0 FUN_00299ba0 (32 B): matches/0x00299ba0.cpp
// sym: ?target@fn_f40ca5f7@@YIXPAUObj_299ba0@1@@Z
// Same code shape as 0x002907f0 (propagated; names are from that function)
void __fastcall target(Obj_299ba0* self) {
    if (self->a) {
        f(self->a, self->b);
        g(self->a);
    }
}


// 0x00299bc0 FUN_00299bc0 (42 B): matches/0x00299bc0.cpp
// sym: ?target@fn_f40ca5f7@@YAXPAVObj@1@H@Z
void __cdecl target(Obj* obj, int n) {
    unsigned __int64 v = Make(n);
    DynamicCaster_299bc0 caster(v);
    obj->f(&caster, v);
}

} // namespace fn_f40ca5f7

// 0x00299c50 FUN_00299c50 (123 B): matches/0x00299c50.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0ActivePrimitiveList_299c50@fn_00299c50@@QAE@XZ
void* operator new(size_t n);
namespace fn_00299c50 {


class Base_299c50 {
  public:
    Base_299c50() { mA = 0; }
    virtual void f0();
    int mA;
};

class ActivePrimitiveList_299c50 : public Base_299c50 {
  public:
    ActivePrimitiveList_299c50();
    virtual void f0();
    char* mBuf1;
    char* mEnd1;
    char pad10[4];
    char* mBuf2;
    char* mEnd2;
    char pad1c[4];
    char mFlag;
    char pad21[3];
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
};

void Base_299c50::f0() {}

ActivePrimitiveList_299c50::ActivePrimitiveList_299c50() {
    char* p = (char*)operator new(0x20);
    mBuf1 = p;
    if (p) {
        mEnd1 = p + 0x20;
    } else {
        mBuf1 = 0;
        mEnd1 = 0;
    }
    char* q = (char*)operator new(0x20);
    mBuf2 = q;
    if (q) {
        mEnd2 = q + 0x20;
    } else {
        mBuf2 = 0;
        mEnd2 = 0;
    }
    mFlag = 0;
    m24 = 0;
    m28 = 0;
    m30 = 0;
    m34 = 0;
    m3c = 0;
    m40 = 0;
    for (unsigned int i = 0; i < 0x20; i++) {
        mBuf1[i] = 0;
        mBuf2[i] = 0;
    }
}

void ActivePrimitiveList_299c50::f0() {}
} // namespace fn_00299c50

namespace fn_f40ca5f7 {

// 0x00299cd0 FUN_00299cd0 (201 B): matches/0x00299cd0.cpp
// sym: ??0ActivePrimitiveList_299cd0@fn_f40ca5f7@@QAE@E@Z
ActivePrimitiveList_299cd0::ActivePrimitiveList_299cd0(unsigned char n) throw() {
    a4 = 0;
    vptr = &hulk_at_0042d51c;
    x8.Init(0x20);
    x14.Init(0x20);
    unsigned len = n;
    c20 = 0;
    x24.Init(len);
    x30.Init(len);
    s3c.Fill_00299540(len, &n);
    for (unsigned i = 0; i < 0x20; i++) {
        x8.b[i] = 0;
        x14.b[i] = 0;
    }
}

} // namespace fn_f40ca5f7

// 0x00299da0 FUN_00299da0 (512 B): equivalent/0x00299da0.cpp [wrapped: conflict: pure3d::CompositeDrawable::ActivePrimitiveList]
// sym: ??0ActivePrimitiveList@CompositeDrawable@pure3d@fn_00299da0@@QAE@ABV0123@@Z @b09fa57c1a75 @w77af69ce1da9
namespace fn_00299da0 {
// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 24/24)
// FUN_00299da0 @ 0x00299da0
void* FUN_0008d6d0(unsigned int size);

class Ref_299da0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Ref_299da0* Clone();
};

struct PrimEntry {
    char flag;
    int value;
    Ref_299da0* ref;
};

struct PrimEntryList {
    PrimEntry* begin;
    PrimEntry* end;
    int pad;
    void FUN_00299540(hulk_intptr count, PrimEntryList* const* fill);
};

namespace pure3d {
namespace CompositeDrawable {

class ActivePrimitiveList {
public:
    virtual void v0_00018b30();
    int field04;
    char* bufA;
    char* bufAEnd;
    int pad10;
    char* bufB;
    char* bufBEnd;
    int pad1c;
    char flag;
    char* data24;
    char* data24End;
    int pad2c;
    char* data30;
    char* data30End;
    int pad38;
    PrimEntryList entries;

    ActivePrimitiveList(const ActivePrimitiveList& src);
};

ActivePrimitiveList::ActivePrimitiveList(const ActivePrimitiveList& src)
{
    field04 = 0;

    char* p = (char*)FUN_0008d6d0(0x20);
    bufA = p;
    if (p) {
        bufAEnd = p + 0x20;
    } else {
        bufA = 0;
        bufAEnd = 0;
    }

    p = (char*)FUN_0008d6d0(0x20);
    bufB = p;
    if (p) {
        bufBEnd = p + 0x20;
    } else {
        bufB = 0;
        bufBEnd = 0;
    }

    flag = src.flag;

    hulk_intptr n = src.data24End - src.data24;
    if (n != 0) {
        p = (char*)FUN_0008d6d0(n);
        data24 = p;
        if (p) {
            data24End = p + n;
        } else {
            data24 = 0;
            data24End = 0;
        }
    } else {
        data24 = 0;
        data24End = 0;
    }

    n = src.data30End - src.data30;
    if (n != 0) {
        p = (char*)FUN_0008d6d0(n);
        data30 = p;
        if (p) {
            data30End = p + n;
        } else {
            data30 = 0;
            data30End = 0;
        }
    } else {
        data30 = 0;
        data30End = 0;
    }

    const ActivePrimitiveList* srcRef = &src;
    entries.FUN_00299540(src.entries.end - src.entries.begin, (PrimEntryList* const*)&srcRef);

    hulk_uintptr count = src.entries.end - src.entries.begin;
    for (unsigned int i = 0; i < count; i++) {
        data24[i] = src.data24[i];
        data30[i] = src.data30[i];
        entries.begin[i].value = src.entries.begin[i].value;
        entries.begin[i].flag = src.entries.begin[i].flag;
        Ref_299da0* r = src.entries.begin[i].ref;
        if (r) {
            PrimEntry* d = &entries.begin[i];
            Ref_299da0* c = r->Clone();
            if (c)
                c->AddRef();
            if (d->ref)
                d->ref->Release();
            d->ref = c;
        }
    }

    for (unsigned int i = 0; i < 0x20; i++) {
        bufA[i] = src.bufA[i];
        bufB[i] = src.bufB[i];
    }
}

}
}
} // namespace fn_00299da0

namespace fn_f40ca5f7 {

// 0x00299fa0 FUN_00299fa0 (110 B): matches/0x00299fa0.cpp
// sym: ??1ActivePrimitiveList_299fa0@fn_f40ca5f7@@UAE@XZ
ActivePrimitiveList_299fa0::~ActivePrimitiveList_299fa0() {}

} // namespace fn_f40ca5f7

// 0x0029a010 FUN_0029a010 (343 B): equivalent/0x0029a010.cpp [wrapped: conflict: pure3d::CompositeDrawable]
// sym: ??0CompositeDrawable@pure3d@fn_0029a010@@QAE@ABV012@@Z @22505ea55470 @we61d3e565019
namespace fn_0029a010 {
// STATUS: equivalent (tools/equiv.py level 3: 18724 inputs, branch coverage 30/30)
// FUN_0029a010 @ 0x0029a010
void *__cdecl FUN_0008d690(unsigned int size);

namespace pure3d {
class CompositeDrawable;
}

struct Peer_29a010 {
    char pad00[0x44];
    pure3d::CompositeDrawable *owner;
};

struct ChildEntry {
    int a;
    int b;
    Peer_29a010 *item;
};

struct ActivePrimitiveList_29a010 {
    virtual void c0();
    char pad04[0x3c - 4];
    ChildEntry *begin;
    ChildEntry *end;
    ActivePrimitiveList_29a010 *FUN_00299da0(ActivePrimitiveList_29a010 *src);
    void FUN_00298870();
};

struct Clock_29a010 {
    void *FUN_002842f0();
};

struct Sink4c {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Sink4c *s4();
    void FUN_00288080(Clock_29a010 *clock);
};

struct Sink50 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Sink50 *s4();
    void FUN_002a8310(pure3d::CompositeDrawable *cd);
};

class __declspec(novtable) DrawableHierarchy_29a010 {
public:
    virtual void b0_00038290();
    char pad04[0x3c];
    void FUN_002a3530(const DrawableHierarchy_29a010 *src);
    DrawableHierarchy_29a010(const DrawableHierarchy_29a010 &src) { FUN_002a3530(&src); }
};

namespace pure3d {
class CompositeDrawable : public DrawableHierarchy_29a010 {
public:
    virtual void vfunc_1_000382a0();
    virtual void vfunc_2();
    virtual void vfunc_3_00298280();
    virtual void vfunc_4_0029a170();
    virtual void vfunc_5_00298270();
    virtual void vfunc_6_00298b30(int, int);
    virtual void vfunc_7_00298c00();
    virtual void vfunc_8_00298cb0(hulk_intptr, int);
    virtual void vfunc_9_00298e60();
    virtual void hulk_slot_vfunc_10_00298f00(void *clock); void vfunc_10_00298f00(void *clock);
    virtual void vfunc_11_00298260();
    virtual void vfunc_12_002992c0();
    Clock_29a010 *clock;
    ActivePrimitiveList_29a010 *children;
    void *f48;
    Sink4c *sink4c;
    Sink50 *sink50;
    void FUN_002998d0(int v);
    CompositeDrawable(const CompositeDrawable &src);
};
}

pure3d::CompositeDrawable::CompositeDrawable(const CompositeDrawable &src)
    : DrawableHierarchy_29a010(src)
{
    clock = 0;
    children = 0;
    f48 = 0;
    sink4c = 0;
    sink50 = 0;

    if (src.children != 0) {
        void *mem = FUN_0008d690(0x48);
        ActivePrimitiveList_29a010 *c = 0;
        if (mem)
            c = ((ActivePrimitiveList_29a010 *)mem)->FUN_00299da0(src.children);
        children = c;
        children->c0();
        children->FUN_00298870();
        unsigned char n = (unsigned char)(children->end - children->begin);
        if (n != 0) {
            unsigned char i = 0;
            do {
                Peer_29a010 *p = children->begin[i].item;
                if (p != 0)
                    p->owner = this;
                i++;
                n = (unsigned char)(children->end - children->begin);
            } while (i < n);
        }
    }
    if (src.clock != 0)
        vfunc_10_00298f00(src.clock->FUN_002842f0());

    if (src.sink4c != 0) {
        Sink4c *s = src.sink4c->s4();
        if (s)
            s->s0();
        if (sink4c)
            sink4c->s1();
        sink4c = s;
        if (s)
            s->FUN_00288080(clock);
    }
    if (src.sink50 != 0) {
        Sink50 *s = src.sink50->s4();
        if (s)
            s->s0();
        if (sink50)
            sink50->s1();
        sink50 = s;
        if (s)
            s->FUN_002a8310(this);
    }
    if (src.f48 != 0)
        FUN_002998d0(0);
}
} // namespace fn_0029a010


// 0x0029a170 pure3d::CompositeDrawable::vfunc_4 (31 B): matches/0x0029a170.cpp
// sym: ?vfunc_4@CompositeDrawable@pure3d@@UAEPAXXZ
void* pure3d::CompositeDrawable::vfunc_4() {
    Allocated_29a170* p = alloc_00263ea0(0x58);
    if (p)
        return (void*)(p->method_0029a010(this));
    return (void*)(0);
}


// 0x0029a630 pure3d::OldCompositeDrawableLoader::vfunc_5 (2764 B): equivalent/0x0029a630.cpp [wrapped: macros]
// sym: ?vfunc_5@OldCompositeDrawableLoader@pure3d@fn_0029a630@@UAEXPAPAUCompositeDrawable@23@PA_KPAUChunk@3@PAULoadInventory@content@3@@Z @564718e2222f @w9fc08a5585a8
inline void* operator new(size_t,void* p) { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0029a630 {
// STATUS: equivalent (tools/equiv.py level 3: 287 inputs, branch coverage 119/144, incomplete)
// pure3d::OldCompositeDrawableLoader::vfunc_5 @ 0x0029a630
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

typedef unsigned __int64 UID;

struct Reader { void FUN_002647e0(void*,int,int,int); }; struct Chunk { char pad[0x284]; Reader* reader; bool FUN_002669f0(); int FUN_00266a30(); void FUN_00266be0(); };
namespace pure3d { class Geometry; class BillboardObject; class ParticleSystem; class Skeleton; class PolySkin; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; virtual void s0(); virtual void s1(); virtual void s2(); virtual void* find(void*,unsigned int,unsigned int); }; }
struct Name { void FUN_0027b040(char*); char bytes[0x38]; };
struct Object { virtual void add(); virtual void release(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void attach(Object*); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual int kind(); char pad[0x3c]; float visibility; void* owner; Object* FUN_0027b240(); };
struct Entry { int unused; int joint; Object* object; }; struct Group { virtual void add(); char p4[4]; unsigned char* starts; char pc[8]; unsigned char* counts; char p18[0x24]; Entry* entries; Group* FUN_00299cd0(int); void FUN_00298870(); };
namespace pure3d { struct CompositeDrawable { virtual void v0_00038290(); virtual void v1_000382a0(); virtual void v2(); virtual void v3_00298280(); virtual void v4_0029a170(); virtual void v5_00298270(); virtual void v6_00298b30(int, int); virtual void v7_00298c00(); virtual void v8_00298cb0(hulk_intptr, int); virtual void v9_00298e60(); virtual void v10_00298f00(void*); virtual void v11_00298260(); virtual void done_002992c0(); char p4[4]; Name name; Object* skeleton; Group* group; int a,b,c; void FUN_002a3480(); }; struct OldCompositeDrawableLoader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void vfunc_5(CompositeDrawable**,UID*,Chunk*,content::LoadInventory*); }; }
void* __cdecl FUN_00263ea0(int); void* __cdecl FUN_0008d690(int); void* __cdecl FUN_0008d6d0(int); void __cdecl FUN_0008d340(void*);  
void pure3d::OldCompositeDrawableLoader::vfunc_5(CompositeDrawable** result,UID* uid,Chunk* chunk,content::LoadInventory* inventory) {
 struct Workspace {
 char unused[3]; unsigned char length; int geometryJoint; int remaining; float skinVisibility; Object** skins; char unused24[2]; unsigned char skinLength, geometryLength; int temporary; unsigned ng,ns; int* geometryJoints; unsigned nb; Object** geometries; int* particleJoints; Object** particles; int* billboardJoints; Object** billboards; unsigned np; CompositeDrawable* composite; char caster[4]; int skinCaster; int particleCount,skinCount; float particleVisibility; char fallback[4]; float geometryVisibility; int geometryCount,particleJoint,offset; int particleIgnored,skinIgnored,geometryIgnored; char name[128],skeleton[128]; } w;
 #define READ(p,n,s) chunk->reader->FUN_002647e0(p,n,s,1)
 READ(&w.length,1,1); int n=w.length; READ(w.name,n,1); w.name[n]=0; READ(&w.length,1,1); n=w.length; READ(w.skeleton,n,1); w.skeleton[n]=0;
 CompositeDrawable* composite=(CompositeDrawable*)FUN_00263ea0(0x58); if(composite) { composite->FUN_002a3480(); new(composite) CompositeDrawable; composite->skeleton=0; composite->group=0; composite->a=0; composite->b=0; composite->c=0; } w.composite=composite;
 composite->name.FUN_0027b040(w.name); *uid=FUN_002672f0(w.name,0,0);
 w.skins=0; w.geometries=0; w.particles=0; w.billboards=0; w.geometryJoints=0; w.particleJoints=0; w.billboardJoints=0; w.ns=0; w.ng=0; w.np=0; w.nb=0;
 while(chunk->FUN_002669f0()) {
 int type=chunk->FUN_00266a30();
 if(type==0x4513 || type==0x4514 || type==0x4517) {
 int* countAddress=type==0x4513?&w.skinCount:type==0x4514?&w.geometryCount:&w.particleCount; READ(countAddress,1,4); int count=*countAddress;
 if(type==0x4513) { if(!w.skins) w.skins=(Object**)FUN_0008d6d0(count*4); }
 if(type==0x4514) { if(!w.geometries) w.geometries=(Object**)FUN_0008d6d0(count*4); if(!w.billboards) w.billboards=(Object**)FUN_0008d6d0(count*4); if(!w.geometryJoints) w.geometryJoints=(int*)FUN_0008d6d0(count*4); if(!w.billboardJoints) w.billboardJoints=(int*)FUN_0008d6d0(count*4); }
 if(type==0x4517) { if(!w.particles) w.particles=(Object**)FUN_0008d6d0(count*4); if(!w.particleJoints) w.particleJoints=(int*)FUN_0008d6d0(count*4); }
 if(count>0) { int* remaining=type==0x4514?&w.temporary:&w.remaining; *remaining=count;
 do {
 if(chunk->FUN_002669f0()) {
 unsigned int si=w.ns,gi=w.ng,bi=w.nb,pi=w.np;
 if(type==0x4517) w.temporary=(char*)w.particleJoints-(char*)w.particles;
 if(type==0x4514) { w.remaining=(hulk_intptr)(w.billboardJoints+bi); w.offset=(char*)w.billboards-(char*)w.billboardJoints; w.skinCaster=(char*)w.geometries-(char*)w.geometryJoints; }
 do {
 int child=chunk->FUN_00266a30();
 if(child==(type==0x4513?0x4515:type==0x4514?0x4516:0x4518)) {
 unsigned char* lengthAddress=type==0x4513?&w.skinLength:type==0x4514?&w.geometryLength:&w.length; READ(lengthAddress,1,1); n=*lengthAddress; READ(w.name,n,1); w.name[n]=0;
 int* ignoredAddress=type==0x4513?&w.skinIgnored:type==0x4514?&w.geometryIgnored:&w.particleIgnored; READ(ignoredAddress,1,4);
 int* jointAddress=type==0x4514?&w.geometryJoint:&w.particleJoint; if(type!=0x4513) READ(jointAddress,1,4);
 Object* object; UID id;
 if(type==0x4513) { id=FUN_0027b020(w.name); void* caster=new(&w.skinCaster) content::LoadInventory::DynamicCaster<PolySkin>; object=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32)); w.skins[si]=object; }
 else if(type==0x4517) { w.particleJoints[pi]=w.particleJoint; id=FUN_0027b020(w.name); void* caster=new(w.caster) content::LoadInventory::DynamicCaster<ParticleSystem>; object=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32)); w.particles[pi]=object; }
 else { id=FUN_0027b020(w.name); void* caster=new(w.caster) content::LoadInventory::DynamicCaster<Geometry>; object=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32)); if(!object) { id=FUN_0027b020(w.name); void* fallback=new(w.fallback) content::LoadInventory::DynamicCaster<BillboardObject>; object=(Object*)inventory->find(fallback,(unsigned)id,(unsigned)(id>>32)); } }
 if(object) {
 if(type==0x4514) { int k=object->kind(); if(k==1) { w.geometries[gi]=object; w.geometryJoints[gi++]=w.geometryJoint; ++w.ng; } else if(k==8) { w.billboards[bi]=object; w.billboardJoints[bi++]=w.geometryJoint; ++w.nb; w.remaining+=4; } }
 while(chunk->FUN_002669f0()) { if(chunk->FUN_00266a30()==0x4519) { float* visibilityAddress=type==0x4513?&w.skinVisibility:type==0x4514?&w.geometryVisibility:&w.particleVisibility; READ(visibilityAddress,1,4); float visibility=*visibilityAddress; if(!(visibility>=0.0f && visibility<=1.0f)) visibility=visibility>1.0f?1.0f:0.0f; if(type==0x4513) w.skins[si]->visibility=visibility; else if(type==0x4517) w.particles[pi]->visibility=visibility; else object->visibility=visibility; } chunk->FUN_00266be0(); }
 if(type==0x4513) { ++w.ns; ++si; } else if(type==0x4517) { ++w.np; ++pi; }
 }
 }
 chunk->FUN_00266be0();
 } while(chunk->FUN_002669f0());
 }
 } while(--*remaining);
 }
 }
 chunk->FUN_00266be0();
 }
 unsigned int total=w.ng+w.ns+w.np+w.nb; w.geometryJoint=0;
 UID id=FUN_0027b020(w.skeleton); void* caster=new(&w.skinVisibility) content::LoadInventory::DynamicCaster<Skeleton>; Object* skeleton=(Object*)inventory->find(caster,(unsigned)id,(unsigned)(id>>32));
 if(skeleton) { Object* replacement=skeleton->FUN_0027b240(); if(replacement) replacement->add(); if(composite->skeleton) composite->skeleton->release(); composite->skeleton=replacement; }
 Group* group=(Group*)FUN_0008d690(0x48); if(group) group=group->FUN_00299cd0(total); composite->group=group; group->add();
 unsigned int index=0;
 for(int category=0;category<4;++category) {
 unsigned int count=category==0?w.ng:category==1?w.ns:category==2?w.np:w.nb;
 composite->group->starts[category]=(unsigned char)index; composite->group->counts[category]=(unsigned char)count;
 Object** objects=category==0?w.geometries:category==1?w.skins:category==2?w.particles:w.billboards; int* joints=category==0?w.geometryJoints:category==2?w.particleJoints:w.billboardJoints;
 for(unsigned int i=0;i<count;++i) {
 if(category!=1) composite->group->entries[(unsigned char)index].joint=joints[i];
 Object** slot=&composite->group->entries[(unsigned char)index].object; Object* value=objects[i]; if(value) value->add(); if(*slot) (*slot)->release(); *slot=value;
 if(category==1) objects[i]->attach(composite->skeleton); objects[i]->owner=composite; ++index;
 }
 }
 composite->group->FUN_00298870(); composite->done_002992c0(); FUN_0008d340(w.skins); FUN_0008d340(w.geometries); FUN_0008d340(w.particles); FUN_0008d340(w.billboards); FUN_0008d340(w.geometryJoints); FUN_0008d340(w.particleJoints); FUN_0008d340(w.billboardJoints); *result=composite;
}
} // namespace fn_0029a630
#undef READ
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

