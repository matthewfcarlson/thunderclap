// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002efca0..0x002f27c0 (kind game, layer engine, confidence high), dominant class physics::CollisionSphere
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f5d8432d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f5d8432d {} using namespace fn_f5d8432d;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f5d8432d {
struct BaseInput { void FUN_00306380(); };
struct Text_2efca0 {  };
struct Observer_2efca0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); };
struct CollisionObject_2efca0;
struct Result_2efca0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void attach(CollisionObject_2efca0*); Result_2efca0* FUN_002ef7f0(int); };
struct CollisionObject_2efca0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual CollisionObject_2efca0* attach(Result_2efca0*); char pad4[4]; Text_2efca0 text; char pad9[15]; Result_2efca0* child; char pad1c[4]; Observer_2efca0* observer; char pad24[44]; unsigned char flag50; char pad51[23]; unsigned char flag68; unsigned char flag69; char pad6a[2]; int field6c; char pad70[16]; CollisionObject_2efca0* FUN_00304f50(BaseInput*);  };
extern void* __cdecl FUN_00263ea0(unsigned int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern int __cdecl FUN_002f2750(__int64);
class ParamValue_2efed0 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class CollisionVolume {
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
    virtual void vfunc_14(void*);
};
class CollisionSphere : public CollisionVolume {
  public:
    virtual void b2();
    virtual void b3();
    virtual void* vfunc_4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b11();
    void vfunc_14(void*);
};
class Other {
  public:
};
extern void* hulk_at_004312dc[];
class CollisionVolume_2effd0 {
  public:
    void Destroy_00306ac0(); // FUN_00236d60, __thiscall, this in ecx
};
class CollisionSphere_2effd0 : public CollisionVolume_2effd0 {
  public:
    CollisionSphere_2effd0* vfunc_5(signed char flags);
};
struct X_2f0000 {
    void* Get();
};
struct Vec3_2f01c0 { float x, y, z; };
union FloatBits_2f01c0 {
    float f;
    unsigned int u;
};
struct Vec3_2f04c0 {
    float x, y, z;
};
struct Vec3_2f05f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
union Slot_2f05f0 {
    const Vec3_2f05f0 *ptr;
    float f;
};
char FUN_002f0080(Vec3_2f05f0 *p, Vec3_2f05f0 *q, Vec3_2f05f0 *extent);
char FUN_002f04c0(Vec3_2f05f0 *p, Vec3_2f05f0 *dir, float len, float radius, float *t);
extern float Compute_002f0230(int, int, int);
struct Vec3_2f0780 {
    float x, y, z;
};
char FUN_002f0080(Vec3_2f0780 *p, Vec3_2f0780 *q, Vec3_2f0780 *extent);
hulk_freg FUN_002f0230(Vec3_2f0780 *p, Vec3_2f0780 *d, Vec3_2f0780 *extent);
struct V3_2f08d0 {
    float x, y, z;
};
extern "C" float __cdecl FUN_00083d90(float *v);
union FBits_2f08d0 {
    float f;
    unsigned int u;
};
struct Vec3_2f0d80 { float x,y,z; };
extern bool __cdecl FUN_002f0080(Vec3_2f0d80*, Vec3_2f0d80*, Vec3_2f0d80*);
extern bool __cdecl FUN_002f08d0(Vec3_2f0d80*, Vec3_2f0d80*, void*, float, float, Vec3_2f0d80*);
struct Vec3_2f0e80 { float x, y, z; };
struct Mat4_2f0e80 {
    float m[4][4];
    void FUN_0022b980();
};
struct Volume_2f0e80 {
    char pad0[0x38];
    int identity;           // 0x38
    char pad1[0x48 - 0x3c];
    Vec3_2f0e80 center;            // 0x48
    float rot[9];           // 0x54
};
bool FUN_002f0080(const Vec3_2f0e80 *a, const Vec3_2f0e80 *b, const Vec3_2f0e80 *c);
float FUN_002f0230(const Vec3_2f0e80 *a, const Vec3_2f0e80 *b, const Vec3_2f0e80 *c);
struct Vec3_2f1010 {
    float x, y, z;
};
class Shape_2f1010 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_2f1010 *vfunc_4();
    char pad04[0x28 - 4];
    Vec3_2f1010 extent;
};
char FUN_002f0080(Vec3_2f1010 *p, Vec3_2f1010 *q, Vec3_2f1010 *extent);
char FUN_002f0e80(Vec3_2f1010 *p, Vec3_2f1010 *q, Vec3_2f1010 *d, float radius, Shape_2f1010 *shape, float *t);
union Bits_2f1160 {
    float f;
    unsigned int u;
};
struct V3_2f1160 {
    float x, y, z;
    hulk_freg FUN_00018990();
};
struct Obj_2f1160;
struct Q_2f1160 {
    char pad00[0x6c];
    int f6c;
};
struct Parent_2f1160 {
    char pad00[0x18];
    Q_2f1160 *q;
    char pad1c[4];
    Obj_2f1160 *root;                  // 0x20
};
struct List_2f1160 {
    Obj_2f1160 **begin;
    Obj_2f1160 **end;
};
struct Obj_2f1160 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3_2f1160 *getCenter();
    virtual void s5();
    virtual int kind();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void v10();
    char pad04[0xc];
    Parent_2f1160 *parent;             // 0x10
    List_2f1160 *children;             // 0x14
    char enabled;               // 0x18
    char flag19;                // 0x19
    char pad1a[0xe];
    V3_2f1160 ext;                     // 0x28
    float radius;               // 0x34
    char pad38[0xc];
    V3_2f1160 box44;                   // 0x44
    float f50;                  // 0x50
    float f54;                  // 0x54
    char b58;                   // 0x58
};
struct Query_2f1160 {
    Bits_2f1160 t;                     // 0x00
    Bits_2f1160 f4;                    // 0x04
    Obj_2f1160 *obj;                   // 0x08
};
union Slot_2f1160 {
    Query_2f1160 *q;
    Bits_2f1160 t;
};
bool FUN_002f0080(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *s);
bool FUN_002f04c0(V3_2f1160 *q, V3_2f1160 *dir, Bits_2f1160 a4, float rad, Bits_2f1160 *t);
bool FUN_002f0730(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *a3, V3_2f1160 *s, Bits_2f1160 *t);
bool FUN_002f0e80(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *a3, unsigned int f4, Obj_2f1160 *obj, Bits_2f1160 *t);
bool FUN_002f08d0(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *box, float a, float b, V3_2f1160 *out);
union Bits_2f15a0 {
    float f;
    unsigned int u;
};
struct V3_2f15a0 {
    float x, y, z;
    void FUN_00011160(unsigned int t, void *arg);
};
struct Obj_2f15a0;
struct Q_2f15a0 {
    char pad00[0x6c];
    int f6c;
};
struct Parent_2f15a0 {
    char pad00[0x18];
    Q_2f15a0 *q;                       // 0x18
    char pad1c[4];
    Obj_2f15a0 *root;                  // 0x20
};
struct List_2f15a0 {
    Obj_2f15a0 **begin;
    Obj_2f15a0 **end;
};
struct Obj_2f15a0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3_2f15a0 *getCenter();
    virtual void s5();
    virtual int kind();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void v10();
    char pad04[0xc];
    Parent_2f15a0 *parent;             // 0x10
    List_2f15a0 *children;             // 0x14
    char enabled;               // 0x18
    char flag19;                // 0x19
    char pad1a[0xe];
    V3_2f15a0 ext;                     // 0x28
    float radius;               // 0x34
    char pad38[0xc];
    V3_2f15a0 box44;                   // 0x44
    float f50;                  // 0x50
    float f54;                  // 0x54
    char b58;                   // 0x58
};
union Arg5 {
    Obj_2f15a0 *obj;
    unsigned char top;
    Bits_2f15a0 t;
};
struct Hit_2f15a0 {
    int mode;                   // 0x00
    Bits_2f15a0 f4;                    // 0x04
    Obj_2f15a0 *obj;                   // 0x08
    V3_2f15a0 pos;                     // 0x0c
    char b18;                   // 0x18
};
bool FUN_002f0080(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *s);
bool FUN_002f04c0(V3_2f15a0 *q, V3_2f15a0 *dir, int a4, float rad, float *t);
bool FUN_002f0730(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *a3, V3_2f15a0 *s, float *t);
bool FUN_002f0e80(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *a3, unsigned int f4, Obj_2f15a0 *obj, float *t);
bool FUN_002f08d0(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *box, float a, float b, V3_2f15a0 *out);
struct V3_2f1ce0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_00018990();
};
struct Mat4_2f1ce0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_2f1ce0 *axis, float angle);
};
union Bits_2f1ce0 {
    int i;
    float f;
};
struct Vec_2f1ce0 {
    class Shape_2f1ce0 **begin;
    class Shape_2f1ce0 **end;
};
class Shape_2f1ce0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual V3_2f1ce0 *v4();
    virtual void v5();
    virtual int v6();
    char pad04[0x14 - 0x4];
    Vec_2f1ce0 *f14;
    char pad18[0x34 - 0x18];
    float f34;
    Bits_2f1ce0 f38;
    Bits_2f1ce0 f3c;
    Bits_2f1ce0 f40;
    union {
        V3_2f1ce0 v;
        struct {
            Bits_2f1ce0 f44;
            Bits_2f1ce0 f48;
            Bits_2f1ce0 f4c;
        } b;
    } u44;
    Bits_2f1ce0 f50;
    Bits_2f1ce0 f54;
    Bits_2f1ce0 f58;
    Bits_2f1ce0 f5c;
    Bits_2f1ce0 f60;
    Bits_2f1ce0 f64;
    Bits_2f1ce0 f68;
    Bits_2f1ce0 f6c;
    Bits_2f1ce0 f70;
    Bits_2f1ce0 f74;
};
extern "C" void __cdecl FUN_00305f00(const V3_2f1ce0 *a, const V3_2f1ce0 *b, V3_2f1ce0 *axis, float *angle);
void __cdecl FUN_002f0120(float q, float ext, float *w, char *flag);
struct Frame_2f1ce0 {
    V3_2f1ce0 q;                            // S+0x10
    Bits_2f1ce0 x1c;                        // 0x1c
    union {
        float f20;
        struct {
            char p20[2];
            char flagC;
            char flagB;
        } b;
    } u20;                           // 0x20
    Bits_2f1ce0 f24;                        // 0x24
    V3_2f1ce0 w;                            // 0x28
    union {
        float f34;
        struct {
            char p34[3];
            char flagA;
        } b;
    } u34;                           // 0x34
    Bits_2f1ce0 f38;                        // 0x38
    Bits_2f1ce0 f3c;                        // 0x3c
    Shape_2f1ce0 *ret;                      // 0x40
    Bits_2f1ce0 f44;                        // 0x44
    Mat4_2f1ce0 M;                          // 0x48
    Mat4_2f1ce0 M2;                         // 0x88
};
struct Buffer_2f2440 {
    int count;
    int capacity;
    char* data;
    void Reserve_00201cd0(int);
    char* Next();
};
class Vec3_2f2470 {
  public:
    int x, y, z;
};
class Arr_2f2470 {
  public:
    int count;
    int capacity;
    Vec3_2f2470* data;
    void Grow_00201cd0(int);
    void Insert(int index, Vec3_2f2470* value);
};
struct Item_2f24f0 { union { float value; unsigned int bits; }; unsigned int second; unsigned int third; };
struct List_2f24f0 { int count; int capacity; Item_2f24f0* data; void FUN_00201cd0(int capacity); void FUN_002f2470(int index, const Item_2f24f0* item); };
struct Entry { int first; int second; char rest[24]; };
struct Table {
    Entry entries[64];
    int count;
    Entry* FUN_002f2670(int first, int second);
};


// 0x002efca0 FUN_002efca0 (219 B): equivalent/0x002efca0.cpp
// sym: ?target@fn_f5d8432d@@YAPAUResult_2efca0@1@PAUBaseInput@1@PBD@Z @ad78378b28ee @wcb7ea960c6d9
// STATUS: equivalent (tools/equiv.py level 3: 19946 inputs, branch coverage 15/16, incomplete)
// FUN_002efca0 @ 0x002efca0
Result_2efca0* __cdecl target(BaseInput* input, const char* name) {
 input->FUN_00306380();
 CollisionObject_2efca0* n = (CollisionObject_2efca0*)FUN_00263ea0(128);
 if(n) n=n->FUN_00304f50(input);
 n->field6c=0; n->flag50=0;
 ((owners::Target_27b040 *)&(n->text))->FUN_0027b040((hulk_uintptr)(name ? name : "Not baptized yet"));
 ((owners::C_304740 *)n)->FUN_00304740((hulk_intptr)(FUN_002f2750(FUN_0027b020(""))));
 Result_2efca0* r=(Result_2efca0*)FUN_0008d690(136);
 if(r) r=r->FUN_002ef7f0(0);
 if(!r) return 0;
 bool replaced=false;
 if(n->child) { n=n->attach(r); replaced=true; } else n->child=r;
 r->attach(n);
 if(!replaced) { if(n->flag68 || n->flag69) n->observer->v10(); n->observer->v8(); }
 return r;
}

} // namespace fn_f5d8432d

// 0x002efe50 FUN_002efe50 (81 B): equivalent/0x002efe50.cpp [wrapped: conflict: physics::CollisionSphere]
// sym: ??0CollisionSphere@physics@fn_002efe50@@QAE@PBUVec3@2@M@Z @ac8be4629dd4 @w3fcd333c807d
namespace fn_002efe50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002efe50 @ 0x002efe50
struct Vec3 { float x,y,z; }; namespace physics { struct FUN_003060a0 { virtual void method(); char padding[0x18]; FUN_003060a0(); }; struct CollisionSphere : FUN_003060a0 { Vec3 position; float values[5]; Vec3 otherPosition; CollisionSphere(const Vec3* position, float value); }; } physics::CollisionSphere::CollisionSphere(const Vec3* position, float value) { this->position = *position; otherPosition = *position; for (int i=0;i<5;++i) values[i]=value; }
} // namespace fn_002efe50

namespace fn_f5d8432d {

// 0x002efeb0 physics::CollisionVolume::vfunc_8 (1 B): matches/0x002efeb0.cpp
// sym: ?FUN_002efeb0@fn_f5d8432d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002efeb0() {}


// 0x002efec0 physics::CollisionVolume::vfunc_13 (1 B): matches/0x002efec0.cpp
// sym: ?FUN_002efec0@fn_f5d8432d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002efec0() {}

} // namespace fn_f5d8432d

// 0x002efed0 physics::CollisionSphere::vfunc_6 (6 B): matches/0x002efed0.cpp
// sym: ?vfunc_6@CollisionSphere@physics@@UAEHXZ
// Same code shape as 0x0004f4b0 (propagated; names are from that function)
int physics::CollisionSphere::vfunc_6() {
    return 7;
}

namespace fn_f5d8432d {

// 0x002efee0 physics::CollisionSphere::vfunc_4 (4 B): matches/0x002efee0.cpp
// sym: ?FUN@fn_f5d8432d@@YIPAHPAXH@Z
// Same code shape as 0x001c39c0 (propagated; names are from that function)
int* __fastcall FUN(void* p, int) {
    return (int*)((char*)p + 0x3c);
}

} // namespace fn_f5d8432d

// 0x002efef0 physics::CollisionSphere::vfunc_3 (4 B): matches/0x002efef0.cpp [wrapped: same definition as 0x002efee0 in this TU]
// sym: ?FUN@fn_002efef0@@YIPAHPAXH@Z
namespace fn_002efef0 {
// Same code shape as 0x001c39c0 (propagated; names are from that function)
int* __fastcall FUN(void* p, int) {
    return (int*)((char*)p + 0x3c);
}
} // namespace fn_002efef0

namespace fn_f5d8432d {

// 0x002eff10 physics::CollisionSphere::vfunc_14 (59 B): matches/0x002eff10.cpp
// sym: ?vfunc_14@CollisionSphere@fn_f5d8432d@@UAEXPAX@Z
void CollisionSphere::vfunc_14(void* out) {
    CollisionVolume::vfunc_14(out);
    void* a = vfunc_4();
    void* b = ((CollisionVolume*)out)->vfunc_4();
    *(int*)b = *(int*)a;
    ((int*)b)[1] = ((int*)a)[1];
    ((int*)b)[2] = ((int*)a)[2];
    *(int*)((char*)out + 0x38) = *(int*)((char*)this + 0x38);
}

} // namespace fn_f5d8432d

// 0x002eff50 physics::CollisionSphere::vfunc_7 (36 B): matches/0x002eff50.cpp [wrapped: conflict: CollisionSphere]
// sym: ?vfunc_7@CollisionSphere@fn_002eff50@@QAEXM@Z
namespace fn_002eff50 {
class CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(float);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
};
class CollisionSphere : public CollisionVolume {
  public:
    char pad[0x34];
    float radius;
    void vfunc_7(float);
};
void CollisionSphere::vfunc_7(float x) {
    CollisionVolume::v7(x);
    x = x * radius;
    *(float*)((char*)this + 0x34) = x;
    *(float*)((char*)this + 0x28) = x;
    *(float*)((char*)this + 0x2c) = x;
    *(float*)((char*)this + 0x30) = x;
}
} // namespace fn_002eff50


// 0x002effa0 physics::CollisionSphere::vfunc_5 (3 B): matches/0x002effa0.cpp
// sym: ?vfunc_5@CollisionSphere@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::CollisionSphere::vfunc_5(int a, int b) {}


// 0x002effb0 physics::CollisionSphere::vfunc_11 (30 B): matches/0x002effb0.cpp
// sym: ?vfunc_11@CollisionSphere@physics@@UAEXPAX@Z
 // namespace physics
void physics::CollisionSphere::vfunc_11(void* __p0) { Other * p = (Other *)__p0;

    ((owners::Mat_22c2b0 *)p)->FUN_0022c2b0((float *)(hulk_uintptr)(hulk_intptr)(vfunc_4()), (float *)(hulk_uintptr)(hulk_intptr)(vfunc_4()));
}

namespace fn_f5d8432d {

// 0x002effd0 physics::CollisionSphere::vfunc_2 (36 B): matches/0x002effd0.cpp
// sym: ?vfunc_5@CollisionSphere_2effd0@fn_f5d8432d@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CollisionSphere_2effd0* CollisionSphere_2effd0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004312dc;
    Destroy_00306ac0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002f0000 FUN_002f0000 (4 B): matches/0x002f0000.cpp
// sym: ?Get@X_2f0000@fn_f5d8432d@@QAEPAXXZ
void* X_2f0000::Get() {
    return (char*)this + 0xc;
}


// 0x002f0030 FUN_002f0030 (75 B): matches/0x002f0030.cpp
// sym: ?FUN_002f0030@fn_f5d8432d@@YAHMMM@Z
int FUN_002f0030(float a, float b, float c) {
    if ((!(a > c) || !(b > c)) && (!(a < -c) || !(b < -c)))
        return 0;
    return 1;
}

} // namespace fn_f5d8432d

// 0x002f0080 FUN_002f0080 (152 B): equivalent/0x002f0080.cpp [wrapped: conflict: FUN_002f0030]
// sym: ?FUN_002f0080@fn_002f0080@@YA_NPBUV3_2f0080@1@00@Z @7e8d24a2c56c @w3bdad45834fe
namespace fn_002f0080 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002f0080 @ 0x002f0080
struct V3_2f0080 { float x; float y; float z; };
char __cdecl FUN_002f0030(float a, float b, float c);

// Interval overlap test on three axes: true when the extent test on x passes
// outright, otherwise falls back to the z and y interval tests.
bool __cdecl FUN_002f0080(const V3_2f0080* a, const V3_2f0080* b, const V3_2f0080* c)
{
    float m = c->x;
    if (b->x > m && a->x > m)
        return true;
    m = -m;
    if (b->x < m && a->x < m)
        return true;
    if (FUN_002f0030(b->z, a->z, c->z))
        return true;
    return FUN_002f0030(b->y, a->y, c->y) != 0;
}
} // namespace fn_002f0080


// 0x002f0120 FUN_002f0120 (103 B): matches/0x002f0120.cpp [wrapped: compile error C2732: linkage specification contradicts earlier specification for 'fn_f5d8432d::FUN_002f0120']
// sym: _FUN_002f0120
namespace fn_002f0120 {
// data: kZero_2f0120 = DAT_003f32e0

extern "C" void FUN_002f0120(float a, float b, float* out, char* ok) {
    if (a < -b) {
        *out = -b;
        *ok = 0;
        return;
    }
    if (a < DAT_003f32e0) {
        *out = a;
        *ok = 1;
        return;
    }
    if (a < b) {
        *out = a;
        *ok = 1;
        return;
    }
    *out = b;
    *ok = 0;
}
} // namespace fn_002f0120

namespace fn_f5d8432d {

// 0x002f01c0 FUN_002f01c0 (107 B): equivalent/0x002f01c0.cpp
// sym: ?FUN_002f01c0@fn_f5d8432d@@YAHPBUVec3_2f01c0@1@0@Z @94b06293413f @w789bfc70c7f7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f01c0 @ 0x002f01c0
// True when |a| <= limit on every axis (NaN fails).
int FUN_002f01c0(const Vec3_2f01c0* a, const Vec3_2f01c0* limit)
{
    FloatBits_2f01c0 t;
    t.f = a->x;
    t.u &= 0x7fffffff;
    if (!(t.f <= limit->x))
        return 0;
    t.f = a->y;
    t.u &= 0x7fffffff;
    if (!(t.f <= limit->y))
        return 0;
    t.f = a->z;
    t.u &= 0x7fffffff;
    if (!(t.f <= limit->z))
        return 0;
    return 1;
}

} // namespace fn_f5d8432d

// 0x002f0230 FUN_002f0230 (643 B): equivalent/0x002f0230.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002f0230@fn_002f0230@@YAMPBUV3_2f0230@1@00@Z @8e72e614d3c9 @wea807ceb5e28
namespace fn_002f0230 {
// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 36/36)
// FUN_002f0230 @ 0x002f0230

struct V3_2f0230 {
    float x, y, z;
};


bool __cdecl FUN_002f01c0(const V3_2f0230 *origin, const V3_2f0230 *extent);

union FBits_2f0230 {
    float f;
    unsigned int u;
};

static float absf(float v)
{
    FBits_2f0230 b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

hulk_freg FUN_002f0230(const V3_2f0230 *origin, const V3_2f0230 *dir, const V3_2f0230 *extent)
{
    float tx = 2.0f;
    float ty = 2.0f;
    double tz = DAT_003f5cf8; // the original keeps tz in an x87 register (unrounded)

    if (FUN_002f01c0(origin, extent))
        return 0.0f;

    if (origin->x * dir->x < 0.0f) {
        tx = absf(origin->x) - extent->x;
        bool hit = tx >= 0.0f && tx <= absf(dir->x);
        if (hit) {
            tx = tx / absf(dir->x);
            hit = !(absf(tx * dir->y + origin->y) >= extent->y) && !(absf(tx * dir->z + origin->z) >= extent->z);
        }
        if (!hit)
            tx = 2.0f;
    }
    if (origin->y * dir->y < 0.0f) {
        ty = absf(origin->y) - extent->y;
        bool hit = ty >= 0.0f && ty <= absf(dir->y);
        if (hit) {
            ty = ty / absf(dir->y);
            hit = !(absf(ty * dir->x + origin->x) >= extent->x) && !(absf(ty * dir->z + origin->z) >= extent->z);
        }
        if (!hit)
            ty = 2.0f;
    }
    if (origin->z * dir->z < 0.0f) {
        float tzd = absf(origin->z) - extent->z;
        bool hit = tzd >= 0.0f && tzd <= absf(dir->z);
        if (hit) {
            tz = tzd / absf(dir->z);
            hit = !(absf(tz * dir->x + origin->x) >= extent->x) && !(absf(tz * dir->y + origin->y) >= extent->y);
        }
        if (!hit)
            tz = DAT_003f5cf8;
    }
    double r = tz;
    if (ty < r)
        r = ty;
    if (tx < r)
        r = tx;
    return r;
}
} // namespace fn_002f0230

namespace fn_f5d8432d {

// 0x002f04c0 FUN_002f04c0 (301 B): equivalent/0x002f04c0.cpp
// sym: ?FUN_002f04c0@fn_f5d8432d@@YA_NPBUVec3_2f04c0@1@0MMPAM@Z @3e07894a12cc @w1d01f0f00007
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 8/8)
// FUN_002f04c0 @ 0x002f04c0
bool FUN_002f04c0(const Vec3_2f04c0 *c, const Vec3_2f04c0 *d, float maxDist, float radius, float *out)
{
    // x87: b, pz, q, s, x1 and the e terms stay in registers; px, py, y1, z1 and radius^2 are stored (rounded)
    radius = radius * radius;
    hulk_freg cc = c->x * c->x + c->y * c->y + c->z * c->z;
    if (cc <= radius) {
        *out = 0.0f;
        return true;
    }
    hulk_freg b = c->x * d->x + c->y * d->y + d->z * c->z;
    if (b >= 0.0f)
        return false;
    b = -b;
    float px = b * d->x + c->x;
    float py = b * d->y + c->y;
    hulk_freg pz = b * d->z + c->z;
    hulk_freg q = pz * pz + px * px + py * py;
    if (!(q < radius))
        return false;
    hulk_freg s = -sqrt(radius - q);
    hulk_freg x1 = s * d->x + px;
    float y1 = s * d->y + py;
    float z1 = s * d->z + pz;
    hulk_freg ex = x1 - c->x;
    hulk_freg ey = y1 - c->y;
    hulk_freg ez = z1 - c->z;
    hulk_freg sum = ez * ez + ex * ex + ey * ey;
    if (!(sum <= (hulk_freg)maxDist * maxDist))
        return false;
    *out = (float)sqrt(sum);
    return true;
}


// 0x002f05f0 FUN_002f05f0 (307 B): equivalent/0x002f05f0.cpp
// sym: ?FUN_002f05f0@fn_f5d8432d@@YA_NUVec3_2f05f0@1@0TSlot_2f05f0@1@MMPAU21@@Z @8eb7aa79b1bd @w428cdf6838f9
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 6/6)
// FUN_002f05f0 @ 0x002f05f0
// Segment p -> q (both relative to origin) swept with a margin of (r0 + r1);
// on a hit writes the world-space hit point to out.  The origin slot is reused
// as scratch for the hit parameter, and r0/r1 as scratch for radius/length.
bool FUN_002f05f0(Vec3_2f05f0 p, Vec3_2f05f0 q, Slot_2f05f0 origin, float r0, float r1, Vec3_2f05f0 *out)
{
    const Vec3_2f05f0 *o = origin.ptr;
    Vec3_2f05f0 dir;

    p.x = p.x - o->x;
    p.y = p.y - o->y;
    p.z = p.z - o->z;
    q.x = q.x - o->x;
    q.y = q.y - o->y;
    q.z = q.z - o->z;

    float r = r0 + r1;
    dir.x = r;
    dir.y = r;
    dir.z = r;
    r0 = r;
    origin.f = r;
    if (FUN_002f0080(&p, &q, &dir))
        return false;

    dir.x = q.x - p.x;
    dir.y = q.y - p.y;
    dir.z = q.z - p.z;
    r1 = dir.FUN_0022d110();
    if (!FUN_002f04c0(&p, &dir, r1, r0, &origin.f))
        return false;

    if (out) {
        out->x = p.x + o->x;
        out->y = p.y + o->y;
        out->z = p.z + o->z;
        out->x = dir.x * origin.f + out->x;
        out->y = dir.y * origin.f + out->y;
        out->z = dir.z * origin.f + out->z;
    }
    return true;
}


// 0x002f0730 FUN_002f0730 (65 B): matches/0x002f0730.cpp
// sym: ?Test@fn_f5d8432d@@YA_NHHHHPAM@Z
bool Test(hulk_intptr a, hulk_intptr b, hulk_intptr c, hulk_intptr d, float* out) {
    float x = Compute_002f0230(a, c, d);
    *out = x;
    if (x >= 0.0f) {
        if (x <= DAT_003f32dc)
            return true;
    }
    return false;
}


// 0x002f0780 FUN_002f0780 (322 B): equivalent/0x002f0780.cpp
// sym: ?FUN_002f0780@fn_f5d8432d@@YA_NUVec3_2f0780@1@0PBU21@0MPAU21@@Z @468a9a09f5df @w70532b061463
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 8/8)
// FUN_002f0780 @ 0x002f0780
// Segment p -> q (relative to origin) against a box grown by r; on a hit within the
// segment writes the world-space hit point to out.  The r slot is reused for the hit parameter.
bool FUN_002f0780(Vec3_2f0780 p, Vec3_2f0780 q, const Vec3_2f0780 *origin, Vec3_2f0780 box, float r, Vec3_2f0780 *out)
{
    Vec3_2f0780 d;

    p.x = p.x - origin->x;
    p.y = p.y - origin->y;
    p.z = p.z - origin->z;
    q.x = q.x - origin->x;
    q.y = q.y - origin->y;
    q.z = q.z - origin->z;
    box.x = box.x + r;
    box.y = box.y + r;
    box.z = box.z + r;
    if (FUN_002f0080(&p, &q, &box))
        return false;

    d.x = q.x - p.x;
    d.y = q.y - p.y;
    d.z = q.z - p.z;
    r = FUN_002f0230(&p, &d, &box);
    if (r < 0.0f)
        return false;
    if (!(r <= 1.0f))
        return false;

    if (out) {
        out->x = p.x + origin->x;
        out->y = p.y + origin->y;
        out->z = p.z + origin->z;
        out->x = d.x * r + out->x;
        out->y = d.y * r + out->y;
        out->z = d.z * r + out->z;
    }
    return true;
}


// 0x002f08d0 FUN_002f08d0 (1195 B): equivalent/0x002f08d0.cpp
// sym: ?FUN_002f08d0@fn_f5d8432d@@YA_NPAUV3_2f08d0@1@00MM0@Z @83066076ee17 @wb616a028a733
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 53/54, incomplete)
// FUN_002f08d0 @ 0x002f08d0
// Segment (p -> p + dir) vs sphere around q: finds the entry point.
bool FUN_002f08d0(V3_2f08d0 *p, V3_2f08d0 *q, V3_2f08d0 *dir, float tol, float radius, V3_2f08d0 *out)
{
    float c0 = p->x * p->x + p->y * p->y + p->z * p->z;
    float dot0 = p->y * dir->y + p->x * dir->x + p->z * dir->z;
    float r2 = radius * radius;
    FBits_2f08d0 ab;
    ab.f = dot0;
    ab.u &= 0x7fffffff;
    bool cl = ab.f > tol;

    if (c0 <= r2 && !cl) {
        out->x = p->x;
        out->y = p->y;
        out->z = p->z;
        return true;
    }

    V3_2f08d0 diff;
    diff.x = q->x - p->x;
    diff.y = q->y - p->y;
    diff.z = q->z - p->z;
    float e = q->y * dir->y + q->x * dir->x + q->z * dir->z;

    V3_2f08d0 P;
    if (cl) {
        if (e * dot0 > 0.0f) {
            if ((e > tol && dot0 > tol) || (-e > tol && -dot0 > tol))
                return false;
        }
        float s = dot0 < 0.0f ? -1.0f : (0.0f < dot0 ? 1.0f : 0.0f);
        float t = (s * tol - dot0) / (e - dot0);
        if (t - 0.01f > 0.0f && t + 0.01f < 1.0f) {
            P.x = diff.x * t + p->x;
            P.y = diff.y * t + p->y;
            P.z = diff.z * t + p->z;
            double m = -(double)(FUN_00083d90(&dot0) * tol);
            double x2 = m * dir->x + P.x;
            double y2 = m * dir->y + P.y;
            double z2 = m * dir->z + P.z;
            double qq = z2 * z2 + y2 * y2 + x2 * x2;
            if (qq <= r2) {
                out->x = P.x;
                out->y = P.y;
                out->z = P.z;
                return true;
            }
        }
    }

    double dd = e - dot0;
    double n2 = diff.z * diff.z + diff.x * diff.x + diff.y * diff.y;
    float K = (float)(n2 - dd * dd);
    double pd = diff.x * p->x + diff.y * p->y + diff.z * p->z;
    double B2 = (pd - dd * dot0) * 2.0;
    double D = B2 * B2 - ((c0 - (double)dot0 * dot0 - r2) * K) * 4.0f;
    if (D < 0.0f)
        return false;
    double sq = sqrt(D);
    float t1 = (float)((sq - B2) / (K * 2.0));
    float t2 = (float)((-B2 - sq) / (K * 2.0));

    bool ok1 = (t1 - 0.01f > 0.0f) && (t1 + 0.01f < 1.0f);
    bool ok2 = (t2 - 0.01f > 0.0f) && (t2 + 0.01f < 1.0f);
    V3_2f08d0 R1, R2;
    if (ok1) {
        R1.x = diff.x * t1 + p->x;
        R1.y = diff.y * t1 + p->y;
        R1.z = diff.z * t1 + p->z;
        FBits_2f08d0 v;
        v.f = R1.x * dir->x + R1.y * dir->y + R1.z * dir->z;
        v.u &= 0x7fffffff;
        ok1 = v.f <= tol;
    }
    if (ok2) {
        R2.x = diff.x * t2 + p->x;
        R2.y = diff.y * t2 + p->y;
        R2.z = diff.z * t2 + p->z;
        FBits_2f08d0 v;
        v.f = R2.x * dir->x + R2.y * dir->y + R2.z * dir->z;
        v.u &= 0x7fffffff;
        ok2 = v.f <= tol;
    }
    if (ok1) {
        V3_2f08d0 *r = &R1;
        if (ok2 && !(t1 < t2))
            r = &R2;
        out->x = r->x;
        out->y = r->y;
        out->z = r->z;
        return true;
    }
    if (ok2) {
        out->x = R2.x;
        out->y = R2.y;
        out->z = R2.z;
        return true;
    }
    return false;
}


// 0x002f0d80 FUN_002f0d80 (241 B): equivalent/0x002f0d80.cpp
// sym: ?FUN_002f0d80@fn_f5d8432d@@YA_NUVec3_2f0d80@1@0PAU21@PAXMMM1@Z @7982262803d5 @w6f341b94a6be
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f0d80 @ 0x002f0d80
bool __cdecl FUN_002f0d80(Vec3_2f0d80 a, Vec3_2f0d80 b, Vec3_2f0d80* center, void* data, float r1, float r2, float r3, Vec3_2f0d80* output) {
 Vec3_2f0d80 local;
 a.x -= center->x; a.y -= center->y; a.z -= center->z;
 b.x -= center->x; b.y -= center->y; b.z -= center->z;
 local.x = local.y = local.z = r1 + r2 + r3;
 if (FUN_002f0080(&a,&b,&local)) return false;
 if (!FUN_002f08d0(&a,&b,data,r1+r3,r2+r3,&local)) return false;
 if (output) {
 float x = local.x + center->x;
 float y = local.y + center->y;
 local.z = local.z + center->z;
 output->z = local.z;
 output->x = x;
 output->y = y;
 }
 return true;
}


// 0x002f0e80 FUN_002f0e80 (390 B): equivalent/0x002f0e80.cpp
// sym: ?FUN_002f0e80@fn_f5d8432d@@YA_NPBUVec3_2f0e80@1@00MPBUVolume_2f0e80@1@PAM@Z @1cc7e3bc8718 @w866af15db24e
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_002f0e80 @ 0x002f0e80
bool FUN_002f0e80(const Vec3_2f0e80 *p0, const Vec3_2f0e80 *p1, const Vec3_2f0e80 *p2, float margin, const Volume_2f0e80 *vol, float *outT)
{
    Vec3_2f0e80 a = *p0;
    Vec3_2f0e80 b = *p2;
    Vec3_2f0e80 c;
    Vec3_2f0e80 d;
    Vec3_2f0e80 e;
    e.x = vol->center.x + margin;
    e.y = vol->center.y + margin;
    e.z = vol->center.z + margin;
    if (vol->identity == 0) {
        Mat4_2f0e80 mat;
        mat.FUN_0022b980();
        mat.m[0][0] = vol->rot[0];
        mat.m[0][1] = vol->rot[1];
        mat.m[0][2] = vol->rot[2];
        mat.m[1][0] = vol->rot[3];
        mat.m[1][1] = vol->rot[4];
        mat.m[1][2] = vol->rot[5];
        mat.m[2][0] = vol->rot[6];
        mat.m[2][1] = vol->rot[7];
        mat.m[2][2] = vol->rot[8];
        ((owners::Matrix_22c120 *)&mat)->FUN_0022c120();
        ((owners::M_22c3b0 *)&mat)->FUN_0022c3b0((float *)(const Vec3_2f0e80 *)p0, (float *)(Vec3_2f0e80 *)(&a));
        ((owners::M_22c3b0 *)&mat)->FUN_0022c3b0((float *)(const Vec3_2f0e80 *)p2, (float *)(Vec3_2f0e80 *)(&b));
        ((owners::M_22c3b0 *)&mat)->FUN_0022c3b0((float *)(const Vec3_2f0e80 *)p1, (float *)(Vec3_2f0e80 *)(&c));
        if (FUN_002f0080(&a, &c, &e))
            return false;
    }
    float t = FUN_002f0230(&a, &b, &e);
    *outT = t;
    if (t < 0.0f)
        return false;
    return t <= 1.0f;
}


// 0x002f1010 FUN_002f1010 (323 B): equivalent/0x002f1010.cpp
// sym: ?FUN_002f1010@fn_f5d8432d@@YA_NUVec3_2f1010@1@0PAVShape_2f1010@1@MPAU21@@Z @80cb5e1ebe09 @wf1e7e01643a5
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 6/6)
// FUN_002f1010 @ 0x002f1010
// Segment p -> q tested against a shape grown by radius; on a hit writes the world-space hit point.
// The radius parameter slot receives the hit parameter t.
bool FUN_002f1010(Vec3_2f1010 p, Vec3_2f1010 q, Shape_2f1010 *shape, float radius, Vec3_2f1010 *out)
{
    Vec3_2f1010 ext;
    Vec3_2f1010 d;

    Vec3_2f1010 *o = shape->vfunc_4();
    p.x = p.x - o->x;
    p.y = p.y - o->y;
    p.z = p.z - o->z;
    o = shape->vfunc_4();
    q.x = q.x - o->x;
    q.y = q.y - o->y;
    q.z = q.z - o->z;
    ext.x = radius + shape->extent.x;
    ext.y = radius + shape->extent.y;
    ext.z = radius + shape->extent.z;
    if (FUN_002f0080(&p, &q, &ext))
        return false;

    d.x = q.x - p.x;
    d.y = q.y - p.y;
    d.z = q.z - p.z;
    if (!FUN_002f0e80(&p, &q, &d, radius, shape, &radius))
        return false;

    if (out) {
        o = shape->vfunc_4();
        out->x = p.x + o->x;
        out->y = p.y + o->y;
        out->z = p.z + o->z;
        out->x = d.x * radius + out->x;
        out->y = d.y * radius + out->y;
        out->z = d.z * radius + out->z;
    }
    return true;
}


// 0x002f1160 FUN_002f1160 (1073 B): equivalent/0x002f1160.cpp
// sym: ?FUN_002f1160@fn_f5d8432d@@YA_NPAUV3_2f1160@1@00TBits_2f1160@1@TSlot_2f1160@1@@Z @04c541e11c2c @w6ca2bd592557
// STATUS: equivalent (tools/equiv.py level 3: 20062 inputs, branch coverage 53/54, incomplete)
// FUN_002f1160 @ 0x002f1160
bool FUN_002f1160(V3_2f1160 *p, V3_2f1160 *dir, V3_2f1160 *a3, Bits_2f1160 a4, Slot_2f1160 slot)
{
    struct Frame {
        V3_2f1160 q;
        V3_2f1160 r;
        V3_2f1160 s;
    } fr;
    Query_2f1160 *q = slot.q;
    bool hit;

    if (!q->obj->enabled)
        return false;
    if (!q->obj->parent->root->flag19)
        q->obj->v10();
    fr.q = *p;
    V3_2f1160 *c = q->obj->getCenter();
    fr.q.x = fr.q.x - c->x;
    fr.q.y = fr.q.y - c->y;
    fr.q.z = fr.q.z - c->z;
    fr.r = fr.q;
    fr.r.x = fr.r.x + a3->x;
    fr.r.y = fr.r.y + a3->y;
    fr.r.z = fr.r.z + a3->z;
    fr.s.y = (*(Bits_2f1160*)&DAT_00554c18).f;
    fr.s.z = (*(Bits_2f1160*)&DAT_00554c18).f;
    Obj_2f1160 *o0 = q->obj;
    if (DAT_004d2a3c == 0 && o0->radius > 0.0f) {
        float w = (*(Bits_2f1160*)&DAT_00554c18).f + o0->radius;
        fr.s.x = w;
        fr.s.y = w;
        fr.s.z = w;
    } else {
        o0 = q->obj;
        fr.s.x = (*(Bits_2f1160*)&DAT_00554c18).f + o0->ext.x;
        fr.s.y = fr.s.y + o0->ext.y;
        fr.s.z = fr.s.z + o0->ext.z;
    }
    if (FUN_002f0080(&fr.q, &fr.r, &fr.s))
        return false;

    hit = false;
    if (o0->kind() == 1) {
        if (DAT_004d2a3c == 0 && q->obj->parent->root == q->obj) {
            hit = FUN_002f04c0(&fr.q, dir, a4, q->obj->radius + (*(Bits_2f1160*)&DAT_00554c18).f, &q->t);
        } else {
            hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &slot.t);
            if (!hit)
                return hit;
            if ((*(char*)&DAT_004d2a40))
                q->t.f = slot.t.f * a4.f;
        }
        if (!hit)
            return false;
        if (DAT_004d2a3c != 2 && (*(char*)&DAT_004d2a40))
            return hit;

        Obj_2f1160 *self = q->obj;
        q->t.f = 1000000000.0f;
        V3_2f1160 a3c = *a3;
        Query_2f1160 child;
        child.t.u = 0;
        child.f4.u = 0;
        slot.t = a4;
        hit = false;
        hulk_uintptr count = self->children->end - self->children->begin;
        if (count == 0)
            return hit;
        unsigned int i = 0;
        do {
            child.obj = self->children->begin[i];
            Slot_2f1160 cs;
            cs.q = &child;
            if (FUN_002f1160(p, dir, &a3c, slot.t, cs)) {
                if (child.t.f < q->t.f) {
                    q->t = child.t;
                    q->f4 = child.f4;
                    q->obj = child.obj;
                    hit = true;
                    slot.t = child.t;
                    a3c.x = child.t.f * dir->x;
                    a3c.y = child.t.f * dir->y;
                    a3c.z = child.t.f * dir->z;
                }
            }
            i++;
        } while (i < (unsigned int)(self->children->end - self->children->begin));
        return hit;
    }
    if (q->obj->kind() == 5 && DAT_004d2a3c == 2) {
        hit = FUN_002f0e80(&fr.q, &fr.r, a3, (*(Bits_2f1160*)&DAT_00554c18).u, q->obj, &slot.t);
    } else if (q->obj->kind() == 2 && DAT_004d2a3c == 2) {
        Obj_2f1160 *o = q->obj;
        float v = o->f50;
        if (!o->b58)
            v = v + o->f54;
        if (!FUN_002f08d0(&fr.q, &fr.r, &o->box44, v + (*(Bits_2f1160*)&DAT_00554c18).f, o->f54 + (*(Bits_2f1160*)&DAT_00554c18).f, &fr.s))
            return false;
        fr.s.x = fr.s.x - fr.q.x;
        fr.s.y = fr.s.y - fr.q.y;
        fr.s.z = fr.s.z - fr.q.z;
        q->t.f = fr.s.FUN_00018990();
        return true;
    } else {
        int k = q->obj->kind();
        if ((k == 7 && DAT_004d2a3c == 2) || DAT_004d2a3c == 0)
            return FUN_002f04c0(&fr.q, dir, a4, q->obj->radius + (*(Bits_2f1160*)&DAT_00554c18).f, &q->t);
        hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &slot.t);
    }
    if (hit) {
        hit = true;
        q->t.f = slot.t.f * a4.f;
    }
    return hit;
}


// 0x002f15a0 FUN_002f15a0 (1068 B): equivalent/0x002f15a0.cpp
// sym: ?FUN_002f15a0@fn_f5d8432d@@YA_NPAUV3_2f15a0@1@00HTArg5@1@PAUHit_2f15a0@1@@Z @2341bccdfd52 @w8731df50f999
// STATUS: equivalent (tools/equiv.py level 3: 20100 inputs, branch coverage 62/68, incomplete)
// FUN_002f15a0 @ 0x002f15a0
bool FUN_002f15a0(V3_2f15a0 *p, V3_2f15a0 *dir, V3_2f15a0 *a3, int a4, Arg5 a5, Hit_2f15a0 *st)
{
    struct Frame {
        Bits_2f15a0 t10;
        V3_2f15a0 q;
        V3_2f15a0 r;
        V3_2f15a0 s;
        char gap[0x14];
    } fr;
    Obj_2f15a0 *obj = a5.obj;

    if (!obj->enabled)
        return false;
    bool top = (obj->parent->root == obj);
    a5.top = top;
    fr.q = *p;
    V3_2f15a0 *c = obj->getCenter();
    fr.q.x = fr.q.x - c->x;
    fr.q.y = fr.q.y - c->y;
    fr.q.z = fr.q.z - c->z;
    if (top || obj->kind() != 1) {
        double n = -(fr.q.y * dir->y + fr.q.z * dir->z + fr.q.x * dir->x);
        double px = n * dir->x + fr.q.x;
        double py = n * dir->y + fr.q.y;
        double pz = n * dir->z + fr.q.z;
        double rr = obj->radius + st->f4.f;
        if (rr * rr < pz * pz + py * py + px * px)
            return false;
    }

    Obj_2f15a0 *root = obj->parent->root;
    if (!root->flag19) {
        if (st->mode == 2 || !st->b18 || !top || obj->parent->q->f6c == 1)
            obj->v10();
    }

    fr.r.x = fr.q.x + a3->x;
    fr.r.y = fr.q.y + a3->y;
    fr.r.z = fr.q.z + a3->z;
    fr.s.y = st->f4.f;
    fr.s.z = st->f4.f;
    if (st->mode == 0 && obj->radius > 0.0f) {
        hulk_freg w = st->f4.f + obj->radius;
        fr.s.x = w;
        fr.s.y = w;
        fr.s.z = w;
    } else {
        fr.s.x = st->f4.f + obj->ext.x;
        fr.s.y = fr.s.y + obj->ext.y;
        fr.s.z = fr.s.z + obj->ext.z;
    }
    if (FUN_002f0080(&fr.q, &fr.r, &fr.s))
        return false;

    bool hit;
    if (obj->kind() == 1) {
        if (st->mode == 0 && top) {
            hit = FUN_002f04c0(&fr.q, dir, a4, obj->radius + st->f4.f, &fr.t10.f);
            a5.top = hit;
            if (st->b18) {
                if (!hit)
                    return false;
                st->obj = obj;
                st->pos = *p;
                st->pos.FUN_00011160(fr.t10.u, dir);
                return hit;
            }
        } else {
            hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &fr.t10.f);
            a5.top = hit;
            if (st->b18 && st->mode == 1) {
                if (!hit)
                    return hit;
                st->obj = obj;
                st->pos = *p;
                st->pos.FUN_00011160(fr.t10.u, a3);
                return hit;
            }
        }
        if (!hit)
            return false;
        unsigned int i = 0;
        while (i < (unsigned int)(obj->children->end - obj->children->begin)) {
            Obj_2f15a0 *child = obj->children->begin[i];
            Arg5 c;
            c.obj = child;
            if (FUN_002f15a0(p, dir, a3, a4, c, st))
                return true;
            i++;
        }
        return false;
    }
    if (obj->kind() == 5 && st->mode == 2) {
        if (!FUN_002f0e80(&fr.q, &fr.r, a3, st->f4.u, obj, &a5.t.f))
            return false;
        st->obj = obj;
        st->pos = *p;
        st->pos.FUN_00011160(a5.t.u, a3);
        return true;
    }
    if (obj->kind() == 2 && st->mode == 2) {
        hulk_freg v = obj->f50;
        if (!obj->b58)
            v = v + obj->f54;
        if (!FUN_002f08d0(&fr.q, &fr.r, &obj->box44, v + st->f4.f, obj->f54 + st->f4.f, &st->pos))
            return false;
        st->obj = obj;
        ((owners::V3_110d0 *)&(st->pos))->FUN_000110d0((owners::V3_110d0 *)(V3_2f15a0 *)(obj->getCenter()));
        return true;
    }
    if (obj->kind() != 7 && st->mode != 0) {
        hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &a5.t.f);
        if (!hit)
            return false;
        st->obj = obj;
        st->pos = *p;
        st->pos.FUN_00011160(a5.t.u, a3);
        return true;
    }
    hit = FUN_002f04c0(&fr.q, dir, a4, obj->radius + st->f4.f, &a5.t.f);
    if (!hit)
        return false;
    st->obj = obj;
    st->pos = *p;
    st->pos.FUN_00011160(a5.t.u, dir);
    return true;
}

} // namespace fn_f5d8432d

// 0x002f19d0 FUN_002f19d0 (744 B): equivalent/0x002f19d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002f19d0@fn_002f19d0@@YA_NPAUVec3_2f19d0@1@PAVShape_2f19d0@1@@Z @a2088ac9c76e @wfd4ac1ad1417
namespace fn_002f19d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 43/43)
// FUN_002f19d0 @ 0x002f19d0
struct Vec3_2f19d0 {
    float x, y, z;
};

struct Vec3Thiscall : Vec3_2f19d0 {
};

union FloatBits_2f19d0 {
    float f;
    unsigned int u;
};

static float AbsF(float x)
{
    FloatBits_2f19d0 b;
    b.f = x;
    b.u &= 0x7fffffff;
    return b.f;
}

class Shape_2f19d0;

struct ShapeList {
    Shape_2f19d0 **begin;
    Shape_2f19d0 **end;
};

class Shape_2f19d0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3_2f19d0 *Center();
    virtual void v5();
    virtual int Type();
    virtual void v7(); virtual void v8(); virtual void v9();
    virtual void Prepare();
    char pad04[0x10];
    ShapeList *children;
    char pad18;
    char ready;
    char pad1a[0xe];
    float boxHalf[3];
    float radius;
    int axisAligned;
    char pad3c[8];
    union {
        struct {
            float axis[3];
            float halfLength;
            float radius2;
            char flat;
        } capsule;
        struct {
            float pad44;
            float half[3];
            float axes[9];
        } box;
    };
};

bool FUN_002f19d0(Vec3_2f19d0 *p, Shape_2f19d0 *shape)
{
    if (!shape->ready)
        shape->Prepare();

    Vec3_2f19d0 *c = shape->Center();
    Vec3Thiscall d;
    d.x = p->x - c->x;
    d.y = p->y - c->y;
    d.z = p->z - c->z;

    switch (shape->Type()) {
    case 1:
        if (!(AbsF(d.x) <= shape->boxHalf[0]))
            return false;
        if (!(AbsF(d.y) <= shape->boxHalf[1]))
            return false;
        if (!(AbsF(d.z) <= shape->boxHalf[2]))
            return false;
        for (unsigned int i = 0; i < (unsigned int)(shape->children->end - shape->children->begin); i++) {
            if (FUN_002f19d0(p, shape->children->begin[i]))
                return true;
        }
        return false;

    case 2: {
        double t = (double)d.z * shape->capsule.axis[2] + (double)d.y * shape->capsule.axis[1] + (double)d.x * shape->capsule.axis[0];
        double lim;
        if (shape->capsule.flat)
            lim = 0.0f;
        else
            lim = shape->capsule.radius2;
        float tf = (float)t;
        lim = lim + shape->capsule.halfLength;
        if (!(lim >= AbsF(tf)))
            return false;
        ((owners::Vec3_11160 *)&d)->FUN_00011160(-tf, (const owners::Vec3_11160 *)(shape->capsule.axis));
        double sum = (double)d.z * d.z + (double)d.y * d.y + (double)d.x * d.x;
        return sum <= shape->capsule.radius2;
    }

    case 5:
        if (shape->axisAligned == 0) {
            const float *m = shape->box.axes;
            float t0 = (float)((double)d.z * m[2] + (double)d.y * m[1] + (double)d.x * m[0]);
            if (!(AbsF(t0) <= shape->box.half[0]))
                return false;
            float t1 = (float)((double)d.z * m[5] + (double)d.y * m[4] + (double)d.x * m[3]);
            if (!(AbsF(t1) <= shape->box.half[1]))
                return false;
            float t2 = (float)((double)d.z * m[8] + (double)d.y * m[7] + (double)d.x * m[6]);
            return AbsF(t2) <= shape->box.half[2];
        }
        if (!(AbsF(d.x) <= shape->box.half[0]))
            return false;
        if (!(AbsF(d.y) <= shape->box.half[1]))
            return false;
        return AbsF(d.z) <= shape->box.half[2];

    case 7: {
        double sum = (double)d.z * d.z + (double)d.y * d.y + (double)d.x * d.x;
        double r2 = (double)shape->radius * shape->radius;
        return r2 >= sum;
    }
    }
    return false;
}
} // namespace fn_002f19d0

namespace fn_f5d8432d {

// 0x002f1ce0 FUN_002f1ce0 (1829 B): equivalent/0x002f1ce0.cpp
// sym: _FUN_002f1ce0 @a67037dd0779 @wcd3c2d60c6d5
// STATUS: equivalent (tools/equiv.py level 3: 3076 inputs, branch coverage 61/62, incomplete)
// FUN_002f1ce0 @ 0x002f1ce0
extern "C" Shape_2f1ce0 *__cdecl FUN_002f1ce0(const V3_2f1ce0 *p, Shape_2f1ce0 *shape, V3_2f1ce0 *out, float *dist)
{
    Frame_2f1ce0 f;
    f.ret = shape;
    int kind = shape->v6() - 1;
    if (kind > 7)
        return shape;

    if (kind == 6) {
        const V3_2f1ce0 *c = shape->v4();
        out->x = p->x - c->x;
        out->y = p->y - c->y;
        out->z = p->z - c->z;
        hulk_freg len = out->FUN_0022d110();   // x87: the length stays in st0 (fld st0 / fstp *dist); the radius is subtracted from it unrounded
        *dist = len;
        if (len <= 0.000001f || len != len) {
            *dist = 0.0f;
            out->y = 0.0f;
            out->z = 0.0f;
            out->x = 1.0f;
            return shape;
        }
        *dist = len - shape->f34;
        return shape;
    }

    if (kind == 7) {
        const V3_2f1ce0 *c = shape->v4();
        out->x = p->x - c->x;
        out->y = p->y - c->y;
        out->z = p->z - c->z;
        *dist = shape->f3c.f * out->y + shape->f40.f * out->z + shape->f38.f * out->x;
        out->x = shape->f38.f;
        out->y = shape->f3c.f;
        out->z = shape->f40.f;
        return shape;
    }

    if (kind == 0) {
        float best = 1.0e9f;
        bool first = true;
        unsigned int i;
        for (i = 0; i < (unsigned int)(shape->f14->end - shape->f14->begin); i++) {
            V3_2f1ce0 tmp;
            Shape_2f1ce0 *r = FUN_002f1ce0(p, shape->f14->begin[i], &tmp, &best);
            if (first) {
                first = false;
                *dist = best + 1.0f;
            }
            if (best < *dist) {
                *dist = best;
                *out = tmp;
                f.ret = r;
            }
        }
        return f.ret;
    }

    if (kind == 1) {
        shape->v4();
        f.q = *p;
        f.M.FUN_0022b980();
        if (shape->f60.i == 0) {
            if (!(DAT_00554c2c & 1)) {
                DAT_00554c2c = DAT_00554c2c | 1;
                (*(V3_2f1ce0*)&DAT_00554c20).x = 0.0f;
                (*(V3_2f1ce0*)&DAT_00554c20).y = 1.0f;
                (*(V3_2f1ce0*)&DAT_00554c20).z = 0.0f;
            }
            float ang;
            FUN_00305f00(&shape->u44.v, ((V3_2f1ce0*)&DAT_00554c20), &f.w, &ang);
            f.M.FUN_0022baf0(&f.w, -ang);
            const V3_2f1ce0 *c = shape->v4();
            f.M.m[12] = c->x;
            f.M.m[13] = c->y;
            f.M.m[14] = c->z;
            f.M2 = f.M;
            ((owners::Matrix_22c120 *)&(f.M2))->FUN_0022c120();
            ((owners::Obj_22d210 *)&(f.q))->FUN_0022d210((owners::Obj_22d210 *)(const struct Mat4_2f1ce0 *)(&f.M2));
        } else {
            const V3_2f1ce0 *c;
            if (shape->f60.i == 3) {
                c = shape->v4();
            } else if (shape->f60.i == 2) {
                float t = f.q.x;
                f.q.x = f.q.y;
                f.q.y = t;
                c = shape->v4();
            } else {
                float t = f.q.z;
                f.q.z = f.q.y;
                f.q.y = t;
                c = shape->v4();
            }
            f.q.x = f.q.x - c->x;
            f.q.y = f.q.y - c->y;
            f.q.z = f.q.z - c->z;
        }
        f.x1c.f = shape->f54.f;
        double r = sqrt(f.q.z * f.q.z + f.q.x * f.q.x);
        if (r < f.x1c.f) {
            f.w.x = f.q.x;
            f.w.z = f.q.z;
        } else {
            double inv = 1.0 / r;
            f.w.x = (float)((f.x1c.f * inv) * f.q.x);
            f.w.z = (float)((inv * f.x1c.f) * f.q.z);
        }
        f.f24.f = -shape->f50.f;
        float cy;
        if (f.q.y < f.f24.f)
            cy = f.f24.f;
        else if (f.q.y < 0.0f)
            cy = f.q.y;
        else if (f.q.y < shape->f50.f)
            cy = f.q.y;
        else
            cy = shape->f50.f;
        out->x = f.q.x - f.w.x;
        out->y = f.q.y - cy;
        out->z = f.q.z - f.w.z;
        *dist = out->FUN_00018990();
        int sel = shape->f60.i;
        if (sel == 0) {
            ((owners::Obj_22d260 *)out)->FUN_0022d260((owners::Obj_22d260 *)(const struct Mat4_2f1ce0 *)(&f.M));
        } else if (sel == 2) {
            float t = out->x;
            out->x = out->y;
            out->y = t;
        } else if (sel == 4) {
            float t = out->z;
            out->z = out->y;
            out->y = t;
        }
        out->FUN_0022d110();
        return shape;
    }

    if (kind == 4) {
        f.q = *p;
        if (shape->f38.i == 0) {
            f.M.FUN_0022b980();
            f.M.m[0] = shape->f54.f;
            f.M.m[1] = shape->f58.f;
            f.M.m[2] = shape->f5c.f;
            f.M.m[4] = shape->f60.f;
            f.M.m[5] = shape->f64.f;
            f.M.m[6] = shape->f68.f;
            f.M.m[8] = shape->f6c.f;
            f.M.m[9] = shape->f70.f;
            f.M.m[10] = shape->f74.f;
            const V3_2f1ce0 *c = shape->v4();
            f.M.m[12] = c->x;
            f.M.m[13] = c->y;
            f.M.m[14] = c->z;
            f.M2 = f.M;
            ((owners::Matrix_22cdb0 *)&(f.M2))->FUN_0022cdb0();
            ((owners::Obj_22d210 *)&(f.q))->FUN_0022d210((owners::Obj_22d210 *)(const struct Mat4_2f1ce0 *)(&f.M2));
        } else {
            const V3_2f1ce0 *c = shape->v4();
            f.q.x = f.q.x - c->x;
            f.q.y = f.q.y - c->y;
            f.q.z = f.q.z - c->z;
        }
        f.x1c.f = shape->u44.b.f48.f;
        f.f44.f = shape->u44.b.f4c.f;
        f.f38.f = shape->f50.f;
        FUN_002f0120(f.q.x, f.x1c.f, &f.w.x, &f.u34.b.flagA);
        FUN_002f0120(f.q.y, f.f44.f, &f.w.y, &f.u20.b.flagB);
        FUN_002f0120(f.q.z, f.f38.f, &f.w.z, &f.u20.b.flagC);
        char bl = f.u34.b.flagA;
        if (bl && f.u20.b.flagB && f.u20.b.flagC) {
            float *selp = &f.w.x;
            f.f24.f = f.w.x - f.q.x;
            f.f24.i &= 0x7fffffff;
            float val = FUN_00083d90(&f.w.x) * f.x1c.f;
            f.f3c.f = f.w.y - f.q.y;
            f.x1c.f = f.f3c.f;
            f.x1c.i &= 0x7fffffff;
            if (f.x1c.f < f.f24.f) {
                f.f24.f = f.f3c.f;
                f.f24.i &= 0x7fffffff;
                selp = &f.w.y;
                val = FUN_00083d90(&f.w.y) * f.f44.f;
            }
            f.x1c.f = f.w.z - f.q.z;
            f.x1c.i &= 0x7fffffff;
            if (f.x1c.f < f.f24.f) {
                selp = &f.w.z;
                val = FUN_00083d90(&f.w.z) * f.f38.f;
            }
            *selp = val;
        }
        // x87: the differences are stored to out (rounded) but the length is taken from the unrounded register copies
        hulk_freg dx = f.q.x - f.w.x;
        out->x = dx;
        hulk_freg dy = f.q.y - f.w.y;
        out->y = dy;
        hulk_freg dz = f.q.z - f.w.z;
        out->z = dz;
        *dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
        if (shape->f38.i == 0)
            ((owners::Obj_22d260 *)out)->FUN_0022d260((owners::Obj_22d260 *)(const struct Mat4_2f1ce0 *)(&f.M));
        out->FUN_0022d110();
        if (bl && f.u20.b.flagB && f.u20.b.flagC)
            *dist = -*dist;
        return shape;
    }
    return shape;
}


// 0x002f2440 FUN_002f2440 (37 B): matches/0x002f2440.cpp
// sym: ?Next@Buffer_2f2440@fn_f5d8432d@@QAEPADXZ
char* Buffer_2f2440::Next() {
    if (count >= capacity)
        Reserve_00201cd0(capacity * 2);
    ++count;
    return data + count * 12 - 12;
}


// 0x002f2470 FUN_002f2470 (119 B): matches/0x002f2470.cpp
// sym: ?Insert@Arr_2f2470@fn_f5d8432d@@QAEXHPAVVec3_2f2470@2@@Z
void Arr_2f2470::Insert(int index, Vec3_2f2470* value) {
    if (count >= capacity)
        Grow_00201cd0(count * 2);
    int i;
    for (i = count; i > index; --i)
        data[i] = data[i - 1];
    data[index] = *value;
    ++count;
}


// 0x002f24f0 FUN_002f24f0 (263 B): equivalent/0x002f24f0.cpp
// sym: _FUN_002f24f0 @b1c794d334c0 @w269a8bb63caf
// STATUS: equivalent (tools/equiv.py level 3: 390 inputs, branch coverage 16/16)
// FUN_002f24f0 @ 0x002f24f0
extern "C" void __cdecl FUN_002f24f0(List_2f24f0* list, const Item_2f24f0* item, const Vector* direction, Vector* output, float* valueOut) {
 if ((*(unsigned char*)&DAT_00554c1c)) {
  if (list->count == 0) {
   if (list->capacity <= 0) list->FUN_00201cd0(list->capacity * 2);
   ++list->count;
   Item_2f24f0* dest = &list->data[list->count-1];
   dest->bits = item->bits; dest->second = item->second; dest->third = item->third;
  } else {
   Item_2f24f0* dest = list->data;
   if (item->value < dest->value) { dest->bits = item->bits; dest->second = item->second; dest->third = item->third; }
  }
  float value = item->value;
  *valueOut = value;
  output->x = value * direction->x;
  output->y = value * direction->y;
  output->z = value * direction->z;
 } else {
  int oldCount = list->count;
  if (oldCount > 0) {
   Item_2f24f0* cursor = list->data;
   for (int i=0; i<list->count; ++i, ++cursor) {
    if (item->value < cursor->value) { list->FUN_002f2470(i, item); return; }
   }
  }
  if (oldCount >= list->capacity) list->FUN_00201cd0(list->capacity * 2);
  ++list->count;
  Item_2f24f0* dest = &list->data[list->count-1];
  dest->bits = item->bits; dest->second = item->second; dest->third = item->third;
 }
}


// 0x002f2670 FUN_002f2670 (78 B): equivalent/0x002f2670.cpp
// sym: ?FUN_002f2670@Table@fn_f5d8432d@@QAEPAUEntry@2@HH@Z @ace047573f5b @w17a2e92a0c16
// STATUS: equivalent (tools/equiv.py level 3: 2288 inputs, branch coverage 9/10, incomplete)
// FUN_002f2670 @ 0x002f2670
Entry* Table::FUN_002f2670(int first, int second) {
    for (int i = 0; i < count; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return &entries[i];
    }
    return &entries[0];
}

} // namespace fn_f5d8432d

// 0x002f2700 FUN_002f2700 (15 B): matches/0x002f2700.cpp
// sym: ?FUN_002f2700@Obj_2f2700@owners@@QAEXM@Z
void owners::Obj_2f2700::FUN_002f2700(float v) {
    b = v;
    a = v;
}


// 0x002f2730 FUN_002f2730 (19 B): matches/0x002f2730.cpp
// sym: ?FUN_002f2730@Obj_2f2730@owners@@QAEXH@Z
void owners::Obj_2f2730::FUN_002f2730(int v) {
    int t = m18;
    m1c = v;
    m8 = t;
    mc = v;
}


// 0x002f2750 FUN_002f2750 (22 B): matches/0x002f2750.cpp [wrapped: conflict: FUN_002f2750]
// sym: _FUN_002f2750
namespace fn_002f2750 {
// Same code shape as 0x00080ba0 (propagated; names are from that function)

class Obj_2f2750 {
  public:
    int method_002f2670(unsigned int, unsigned int);
};
extern "C" int FUN_002f2750(unsigned int a, unsigned int b) {
    return (*(Obj_2f2750**)&DAT_00554c30)->method_002f2670(a, b);
}
} // namespace fn_002f2750

