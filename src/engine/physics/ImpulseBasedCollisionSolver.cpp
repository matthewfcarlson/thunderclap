// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f79f0..0x002f8d90 (kind game, layer engine, confidence high), dominant class physics::ImpulseBasedCollisionSolver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f524d977 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f524d977 {} using namespace fn_f524d977;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f524d977 {
struct Ref_2f79f0 {
    virtual void f0();
    virtual void f1();
};
struct SymMatrix_2f79f0 {
    char x[1];
    void init_002fcaa0();
};
extern int hulk_at_004316e8;
class ImpulseBasedCollisionSolver_2f79f0 {
  public:
    virtual void v();
    Ref_2f79f0* a;
    char gap[0x94 - 8];
    SymMatrix_2f79f0 e94;
    char gap2[0xb0 - 0x95];
    SymMatrix_2f79f0 eb0;
    char gap3[0xcc - 0xb1];
    SymMatrix_2f79f0 ecc;
    char gap4[0xfc - 0xcd];
    Ref_2f79f0* b;
    void cleanup();
};
struct Y_2f7a40 {
    void Fnm_003046f0(int);
};
struct X_2f7a40 {
    char pad[0x74];
    Y_2f7a40* y;
};
class C_2f7a40 {
  public:
    char pad[0xfc];
    X_2f7a40* field;
    void target();
};
struct Global_2f7a60 {
    char pad[0x28];
    int a;
    char pad2[4];
    int b;
};
class Obj_2f7a60 {
  public:
    char pad[0xe8];
    int a;
    int b;
};
class B_2f7a80 {
  public:
    virtual void F();
};
class A_2f7a80 {
  public:
    int pad;
    B_2f7a80* p;
    void Set(B_2f7a80* b);
};
struct S_2f7a90 {
    int a[17];
    S_2f7a90(const S_2f7a90& o);
};
struct Vec3_2f7b00 { float x, y, z; };
class Probe_2f7b00 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(Vec3_2f7b00 *in, Vec3_2f7b00 *out, int arg);
};
struct Target_2f7b00 {
    char pad0[0x1c];
    int arg1c;
    int arg20;
    Vec3_2f7b00 n;
    char pad1[0x38 - 0x30];
    Vec3_2f7b00 in0;
    Vec3_2f7b00 in1;
    char pad2[0xc];
    Vec3_2f7b00 out0;
    Vec3_2f7b00 out1;
    Vec3_2f7b00 diff;
    float dot;
    Probe_2f7b00 *p84;
    Probe_2f7b00 *p88;
    void FUN_002f7b00();
};
class O_2f7b70 {
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
    virtual void v17(int, int, int, int, int);
    virtual void v18();
    virtual void v19();
    virtual void v20(int, int, int, int, int);
};
struct Q_2f7b70 {
};
class C_2f7bd0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
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
    virtual bool first(int, int, int, int, int, int);
    virtual void a19();
    virtual bool second(int, int, int, int, int);
};
class Context_2f7c30 {
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
    virtual int Check(int, int);
};
class Param_2f7c30 {
  public:
    virtual void f0();
    char pad[12];
    int value;
    char pad2[0x4c - 0x14];
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
    virtual void Apply(int, int, int);
};
struct Value {
    char pad[0x14];
    float v;
};
struct Link {
    char pad[0x1c];
    Value* val;
};
extern "C" float __cdecl blend_002f2930(Value*, Value*);
class Obj {
  public:
    char a[0x14];
    Link* left;
    Link* right;
    char b[0x70];
    void* first;
    void* second;
    char c[0x5f];
    char flag;
    hulk_freg Get();
};
class Ref_2f7d00 {
  public:
    virtual void x();
    virtual void y(int, int);
};
class CollisionSolverAgent {
  public:
    virtual void a();
    virtual void b();
    virtual void c(int, int);
    virtual void d();
    virtual void vfunc_4(int, int);
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    void* pad;
    void* mObject;
};
typedef unsigned int u32_2f7d40;
class Ref_2f7d40 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(void*, void*);
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual int check(u32_2f7d40);
};
class Wrap_2f7d40 {
  public:
    char pad[0x18];
    Ref_2f7d40* obj;
};
struct Arg_2f7d40 {
    char x[8];
    Wrap_2f7d40* first;
    Wrap_2f7d40* second;
    u32_2f7d40 a;
    u32_2f7d40 b;
};
class Obj_2f7dc0 {
  public:
    char pad[0x6c];
    int state;
    void helper_002ef8b0(int);
};
class Ref_2f7dc0 {
  public:
    char pad[0x20];
    int state;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*, int, void*, int, int, int, int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct CollisionAnalyser_nv_2f7e50 {
    void* init_0030e480();
};
struct Obj_2f7e50 {
    char pad[8];
    void* member;
};
class Ref_2f7e80 {
  public:
    virtual void Release(int);
};
class Owner_2f7e80 {
    char pad[8];
    Ref_2f7e80* mRef;

  public:
    void Clear();
};
class Action_2f7ea0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Ref_2f7fc0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Chunk {
  public:
    void init_002fcaa0();
    char pad[0x1c];
};
class ImpulseBasedCollisionSolver_2f7fc0 {
  public:
    virtual ~ImpulseBasedCollisionSolver_2f7fc0();
    virtual void vfunc_1_002f8a00();
    virtual bool vfunc_2_002f7bd0(void*, int, int, int, int, int);
    virtual void vfunc_3_002f7c30(void*, int, int, int);
    virtual void vfunc_4_002f8730();
    Ref_2f7fc0* r4;
    char pad1[0x8c];
    Chunk c94;
    Chunk cb0;
    Chunk ccc;
    char pad2[0x14];
    Ref_2f7fc0* rfc;
};
void thunk_FUN_00267090(ImpulseBasedCollisionSolver_2f7fc0*);
struct Sub8_2f8020 {
    void FUN_0030e190(int v);
};
struct Q_2f8020 {
    char pad0[0x1ec];
    hulk_intptr f1ec;               // 0x1ec
    char pad1f0[4];
    unsigned char f1f4;     // 0x1f4
};
struct Body_2f8020 {
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7();
    virtual void b8();
    virtual Q_2f8020 *b9(int v);
};
struct Holder_2f8020 {
    char pad0[0x18];
    Body_2f8020 *body;             // 0x18
};
struct Obj1_2f8020 {
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3();
    virtual void o4(); virtual void o5();
    virtual int o6();
    char pad04[0x38 - 0x4];
    int f38;                // 0x38
    int f3c;                // 0x3c
    char pad40[0x48 - 0x40];
    int f48;                // 0x48
};
struct Rec_2f8020 {
    int f0;
    Obj1_2f8020 *o1;               // 0x04
    Holder_2f8020 *p1;             // 0x08
    Holder_2f8020 *p2;             // 0x0c
    int f1c;                // 0x10
    int f20;                // 0x14
    float f24;              // 0x18
    float f28;              // 0x1c
    float f2c;              // 0x20
    int f30;                // 0x24
    int flags;              // 0x28
    int f38;                // 0x2c
    int f3c;                // 0x30
    int f40;                // 0x34
    int f44;                // 0x38
    int f48;                // 0x3c
    int f4c;                // 0x40
};
struct List_2f8020 {
    Rec_2f8020 *begin;
    Rec_2f8020 *end;
};
struct Zone_2f8020 {
    char pad0[8];
    int f8;                 // 0x8
    int fc;                 // 0xc
    char pad10[0x74 - 0x10];
    Holder_2f8020 *f74;            // 0x74
    void FUN_002ef440(int v);
};
struct Core_2f8020 {
    virtual void c0(); virtual void c1(); virtual void c2();
    virtual void c3(List_2f8020 *l, int a);
    virtual void c4(List_2f8020 *l, int a);
    virtual int c5(Rec_2f8020 *r, int it);
    virtual int c6(Body_2f8020 *b84, int f1c, Body_2f8020 *b88, int f20, int *f38, float k, float len, Q_2f8020 **q1, Q_2f8020 **q2);
    char pad04[4];
    Sub8_2f8020 *obj8;             // 0x8
};
class Solver_2f8020 {
public:
    virtual void s0();
    virtual void s1();
    Core_2f8020 *core;             // 0x4
    List_2f8020 *list;             // 0x8
    Rec_2f8020 r;                  // 0xc
    char pad50[0x74 - 0x50];
    float f74;
    float f78;
    float f7c;
    float k;                // 0x80
    Body_2f8020 *o84;              // 0x84
    Body_2f8020 *o88;              // 0x88
    Q_2f8020 *q1;                  // 0x8c
    Q_2f8020 *q2;                  // 0x90
    char pad94[0xf0 - 0x94];
    char f0;                // 0xf0
    char f1;                // 0xf1
    char padf2[6];
    int iters;              // 0xf8
    Zone_2f8020 *zone;             // 0xfc
    void FUN_002f7b00();
    void FUN_002f8020(List_2f8020 *l, int unused, int a3);
};
struct V3_2f8300 {
    float x, y, z;
};
struct Peer_2f8300 {
    char pad[0x1c];
    float f1c;
};
struct SymMatrix {
    char pad[4];
    float f4;
    char rest[0x14];
    void FUN_002fca90() throw();
    void FUN_002fcaa0() throw();
};
struct Target_2f8300 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7(V3_2f8300 *r, void *p);
};
hulk_freg FUN_002f2950(float a, float b);
struct ImpulseBasedCollisionSolver_2f8300 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual float v4();
    Target_2f8300 *target;                 // 0x04
    char pad08[4];
    char pos[8];                    // 0x0c
    Peer_2f8300 *peer14;                   // 0x14
    Peer_2f8300 *peer18;                   // 0x18
    char pad1c[8];
    V3_2f8300 dir;                         // 0x24
    char pad30[0x20];
    V3_2f8300 res;                         // 0x50
    char pad5c[0x18];
    V3_2f8300 vec74;                       // 0x74
    float f80;                      // 0x80
    char pad84[0x10];
    char a94[0x1c];                 // 0x94
    char ab0[0x1c];                 // 0xb0
    SymMatrix mat;                  // 0xcc
    char padE8[0xb];
    char fF3;
    char fF4;
    float FUN_002f7ca0() throw();
    int FUN_002f8300();
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_00431700[];
class Ref_2f8820 {
  public:
    virtual void Release(int);
};
struct Obj_2f8820 {
    void* vptr;
    char pad[4];
    Ref_2f8820* ref;
};
struct Vec3_2f8920 { float x,y,z; };
struct Body_2f8920 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual bool slot11(); virtual void slot12(); virtual void slot13(); virtual float slot14(); virtual float slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(Vec3_2f8920*,Vec3_2f8920*,int); virtual void slot26(); virtual void slot27(int);
};
struct AgentInput {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual Body_2f8920* slot9(int);
 char pad[0x68]; int mode;
};
struct V3_2f8a00 {
    float x;
    float y;
    float z;
};
class Collider_2f8a00 {
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
    virtual char v24(V3_2f8a00* a, V3_2f8a00* b, int id);
};
class Body_2f8a00 {
public:
    char pad00[0x6c];
    int state;
};
} // namespace fn_f524d977
class World {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int v8(Body_2f8a00* body, int id);
};
namespace fn_f524d977 {
class ImpulseBasedCollisionSolver {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual char vfunc_2(Collider_2f8a00* a, Collider_2f8a00* b, V3_2f8a00* p, V3_2f8a00* q, int ia, int ib);
    virtual void vfunc_3(Collider_2f8a00* c, int a, int b, unsigned char f);
    virtual void vfunc_4();
    World* world;               // 0x04
    char pad08[0x1c - 8];
    int idA;                    // 0x1c
    int idB;                    // 0x20
    V3_2f8a00 normal;                  // 0x24
    char pad30[4];
    unsigned int flags;         // 0x34
    V3_2f8a00 p38;
    V3_2f8a00 p44;
    V3_2f8a00 p50;
    V3_2f8a00 p5c;
    V3_2f8a00 p68;
    V3_2f8a00 p74;
    float t;                    // 0x80
    Body_2f8a00* bodyA;                // 0x84
    Body_2f8a00* bodyB;                // 0x88
    Collider_2f8a00* collA;            // 0x8c
    Collider_2f8a00* collB;            // 0x90
    V3_2f8a00 p94;
    char pad_a0[0xb0 - 0xa0];
    V3_2f8a00 pb0;
    char pad_bc[0xf0 - 0xbc];
    char f0;
    char f1;
    char f2;
    char sameObject;
    int FUN_002f8300();
    void FUN_002f7b70(Collider_2f8a00* a, Collider_2f8a00* b, V3_2f8a00* p, V3_2f8a00* q, int ia, int ib);
};
struct Thing_2f8d70 {
    unsigned int a[11];
};


// 0x002f79f0 FUN_002f79f0 (70 B): matches/0x002f79f0.cpp
// sym: ?cleanup@ImpulseBasedCollisionSolver_2f79f0@fn_f524d977@@QAEXXZ
void ImpulseBasedCollisionSolver_2f79f0::cleanup() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_004316e8;
    if (a)
        a->f1();
    if (b)
        b->f1();
    ecc.init_002fcaa0();
    eb0.init_002fcaa0();
    e94.init_002fcaa0();
}


// 0x002f7a40 FUN_002f7a40 (17 B): matches/0x002f7a40.cpp
// sym: ?target@C_2f7a40@fn_f524d977@@QAEXXZ
void C_2f7a40::target() {
    field->y->Fnm_003046f0(1);
}


// 0x002f7a60 FUN_002f7a60 (29 B): matches/0x002f7a60.cpp
// sym: ?target@fn_f524d977@@YIXPAVObj_2f7a60@1@@Z
void __fastcall target(Obj_2f7a60* self) {
    self->a = (*(Global_2f7a60**)&DAT_00554c10)->b;
    self->b = (*(Global_2f7a60**)&DAT_00554c10)->a;
}


// 0x002f7a80 FUN_002f7a80 (16 B): matches/0x002f7a80.cpp
// sym: ?Set@A_2f7a80@fn_f524d977@@QAEXPAVB_2f7a80@2@@Z
void A_2f7a80::Set(B_2f7a80* b) {
    p = b;
    b->F();
}


// 0x002f7a90 FUN_002f7a90 (109 B): matches/0x002f7a90.cpp
// sym: ??0S_2f7a90@fn_f524d977@@QAE@ABU01@@Z
S_2f7a90::S_2f7a90(const S_2f7a90& o) {
    a[0] = o.a[0];
    a[1] = o.a[1];
    a[2] = o.a[2];
    a[3] = o.a[3];
    a[4] = o.a[4];
    a[5] = o.a[5];
    a[6] = o.a[6];
    a[7] = o.a[7];
    a[8] = o.a[8];
    a[9] = o.a[9];
    a[10] = o.a[10];
    a[11] = o.a[11];
    a[12] = o.a[12];
    a[13] = o.a[13];
    a[14] = o.a[14];
    a[15] = o.a[15];
    a[16] = o.a[16];
}


// 0x002f7b00 FUN_002f7b00 (108 B): equivalent/0x002f7b00.cpp
// sym: ?FUN_002f7b00@Target_2f7b00@fn_f524d977@@QAEXXZ @3f4be25edd36 @w2de7ba235ea1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f7b00 @ 0x002f7b00
void Target_2f7b00::FUN_002f7b00()
{
    p84->v8(&in0, &out0, arg1c);
    p88->v8(&in1, &out1, arg20);
    diff.x = out0.x - out1.x;
    diff.y = out0.y - out1.y;
    diff.z = out0.z - out1.z;
    volatile Vec3_2f7b00 *d = &diff;
    dot = ((n.z * d->z) + (n.y * d->y)) + (n.x * d->x);
}

} // namespace fn_f524d977

// 0x002f7b70 FUN_002f7b70 (83 B): matches/0x002f7b70.cpp
// sym: ?FUN_002f7b70@ImpulseBasedCollisionSolver@physics@@QAEXPAXHHHHH@Z
void physics::ImpulseBasedCollisionSolver::FUN_002f7b70(void* __p0, int a3, int a4, hulk_intptr a5, int a6, int a7) { O_2f7b70 * p = (O_2f7b70 *)__p0;

    if (p) {
        p->v17(a4, (hulk_intptr)this + 0x24, a3, a6, a7);
        p->v20(a4, a5, a3, a6, a7);
    } else {
        ((owners::C_2fd0a0 *)(((Q_2f7b70*)a5)))->FUN_002fd0a0();
    }
}


// 0x002f7bd0 physics::ImpulseBasedCollisionSolver::vfunc_2 (92 B): matches/0x002f7bd0.cpp
// sym: ?vfunc_2@ImpulseBasedCollisionSolver@physics@@UAE_NPAXHHHHH@Z
bool physics::ImpulseBasedCollisionSolver::vfunc_2(void* __p0, int a, int b, int c, int d, int e) { C_2f7bd0 * o = (C_2f7bd0 *)__p0;

    bool r = true;
    if (o) {
        if (!o->first(b, (hulk_intptr)((char*)this + 0x50), c, a, d, e)) {
            o->second(b, c, a, d, e);
            r = false;
        }
    }
    return r;
}


// 0x002f7c30 physics::ImpulseBasedCollisionSolver::vfunc_3 (61 B): matches/0x002f7c30.cpp
// sym: ?vfunc_3@ImpulseBasedCollisionSolver@physics@@UAEXPAXHHH@Z
void physics::ImpulseBasedCollisionSolver::vfunc_3(void* __p0, int a, int b, int c) { Param_2f7c30 * p = (Param_2f7c30 *)__p0;

    if (p && !(this->f_34 & 1)) {
        int val = p->value;
        if ((*(Context_2f7c30 * *)&this->f_04)->Check(val, a) != 1)
            p->Apply(c, a, b);
    }
}

namespace fn_f524d977 {

// 0x002f7ca0 FUN_002f7ca0 (84 B): matches/0x002f7ca0.cpp
// sym: ?Get@Obj@fn_f524d977@@QAEMXZ
// data: zero = DAT_003f32e0
hulk_freg Obj::Get() {
    if (flag)
        return DAT_003f32e0;
    if (first && second) {
        Value* r = right->val;
        Value* l = left->val;
        return blend_002f2930(l, r);
    }
    if (first)
        return left->val->v;
    return right->val->v;
}

} // namespace fn_f524d977

// 0x002f7d00 physics::CollisionSolverAgent::vfunc_3 (17 B): matches/0x002f7d00.cpp
// sym: ?vfunc_3@CollisionSolverAgent@physics@@UAEXHH@Z
void physics::CollisionSolverAgent::vfunc_3(int a, int b) {
    if ((*(Ref_2f7d00 * *)&this->f_08))
        (*(Ref_2f7d00 * *)&this->f_08)->y(a, b);
}

namespace fn_f524d977 {

// 0x002f7d20 physics::CollisionSolverAgent::vfunc_4 (17 B): matches/0x002f7d20.cpp
// sym: ?vfunc_4@CollisionSolverAgent@fn_f524d977@@UAEXHH@Z
void CollisionSolverAgent::vfunc_4(int x, int y) {
    if (mObject)
        ((CollisionSolverAgent*)mObject)->c(x, y);
}

} // namespace fn_f524d977

// 0x002f7d40 physics::CollisionSolverAgent::vfunc_5 (90 B): matches/0x002f7d40.cpp
// sym: ?vfunc_5@CollisionSolverAgent@physics@@UAEHPAX0@Z
int physics::CollisionSolverAgent::vfunc_5(void* __p0, void* __p1) { void * p = (void *)__p0; void * secondArg = (void *)__p1;

    Arg_2f7d40* q = (Arg_2f7d40*)p;
    int r = 0;
    if (!q->first->obj->check(q->a) && !q->second->obj->check(q->b)) {
        if (!(*(Ref_2f7d40 * *)&this->f_08))
            r = 1;
    }
    if ((*(Ref_2f7d40 * *)&this->f_08))
        (*(Ref_2f7d40 * *)&this->f_08)->d(p, secondArg);
    return r;
}


// 0x002f7dc0 physics::CollisionSolverAgent::vfunc_6 (128 B): matches/0x002f7dc0.cpp
// sym: ?vfunc_6@CollisionSolverAgent@physics@@UAEIIIIIIIIII@Z
unsigned int physics::CollisionSolverAgent::vfunc_6(hulk_uintptr __p0, unsigned int __p1, hulk_uintptr __p2, unsigned int __p3, unsigned int __p4, unsigned int __p5, unsigned int __p6, hulk_uintptr __p7, hulk_uintptr __p8) { void * a = (void *)__p0; int b = (int)__p1; void * c = (void *)__p2; int d = (int)__p3; int e = (int)__p4; int f = (int)__p5; int g = (int)__p6; int * p = (int *)__p7; int * q = (int *)__p8;

    if (*p && !((Ref_2f7dc0*)*(hulk_intptr*)p)->state && !((Obj_2f7dc0*)a)->state)
        ((Obj_2f7dc0*)a)->helper_002ef8b0(1);
    if (*q && !((Ref_2f7dc0*)*(hulk_intptr*)q)->state && !((Obj_2f7dc0*)c)->state)
        ((Obj_2f7dc0*)c)->helper_002ef8b0(1);
    if ((*(void * *)&this->f_08))
        ((Ref_2f7dc0*)(*(void * *)&this->f_08))->f4(a, b, c, d, e, f, g);
    return (unsigned int)(0);
}


// 0x002f7e40 physics::CollisionSolverAgent::vfunc_7 (5 B): matches/0x002f7e40.cpp
// sym: ?vfunc_7@CollisionSolverAgent@physics@@UAEHPAXH@Z
// Same code shape as 0x0026fe10 (propagated; names are from that function)
 // namespace core
int physics::CollisionSolverAgent::vfunc_7(void* __p0, hulk_intptr ) {
    return 0;
}

namespace fn_f524d977 {

// 0x002f7e50 FUN_002f7e50 (43 B): matches/0x002f7e50.cpp
// sym: ?FUN_002f7e50@fn_f524d977@@YIXPAUObj_2f7e50@1@@Z
void __fastcall FUN_002f7e50(Obj_2f7e50* self) {
    if (self->member == 0) {
        void* p = FUN_0008d690(0x6c);
        void* r;
        if (p != 0) {
            r = ((CollisionAnalyser_nv_2f7e50*)(((physics::CollisionAnalyser*)(((physics::CollisionAnalyser*)p)))))->init_0030e480();
        } else {
            r = 0;
        }
        self->member = r;
    }
}


// 0x002f7e80 FUN_002f7e80 (25 B): matches/0x002f7e80.cpp
// sym: ?Clear@Owner_2f7e80@fn_f524d977@@QAEXXZ
void Owner_2f7e80::Clear() {
    if (mRef) {
        mRef->Release(1);
        mRef = 0;
    }
}

} // namespace fn_f524d977

// 0x002f7ea0 physics::CollisionSolverAgent::vfunc_10 (5 B): matches/0x002f7ea0.cpp
// sym: ?vfunc_10@CollisionSolverAgent@physics@@UAE_NPAX0@Z
// Same code shape as 0x0012da20 (propagated; names are from that function)
bool physics::CollisionSolverAgent::vfunc_10(void* __p0, void* __p1) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1;

    return (bool)(1);
}


// 0x002f7eb0 physics::CollisionSolverAgent::vfunc_11 (5 B): matches/0x002f7eb0.cpp
// sym: ?vfunc_11@CollisionSolverAgent@physics@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool physics::CollisionSolverAgent::vfunc_11(void* __p0) {
    return true;
}


// 0x002f7ee0 FUN_002f7ee0 (212 B): matches/0x002f7ee0.cpp [wrapped: conflict: FUN_0008d690]
// sym: ??0ImpulseBasedCollisionSolver_2f7ee0@fn_002f7ee0@@QAE@XZ
namespace fn_002f7ee0 {

extern void* DAT_004316e8[];
struct SubA_2f7ee0 {
    char pad[0x88];
    void Init_002f8d70() throw();
};
struct SymMatrix_2f7ee0 {
    char pad[0x1c];
    void Init_002fca90() throw();
};
// (x64t4) the environment (DAT_00554c10, 0x002ecf60): pure3d::Entity's words, then its floats (the length and
// damping words at 0x28 / 0x30 on the 32-bit builds)
struct Cfg_2f7ee0 {
    void* vftable;
    char pad04[0xc];
    float f10[6];
    int a;
    int pad2;
    int b;
};
// (x64t4) physics::CollisionWall with the words its constructor 0x0030e700 writes (decls/physics_world.h; was a
// 0x60-byte pad, which the 64-bit constructor overran)
struct CollisionWall_2f7ee0 : HulkCollisionWall {
    CollisionWall_2f7ee0* Ctor_0030e700() throw();
};
struct CollisionObject_2f7ee0 {
    char pad[8];
    char tail[0x80];
    CollisionObject_2f7ee0* Ctor_00304f50(CollisionWall_2f7ee0*) throw();
};
struct Ref_2f7ee0 {
    virtual void a() throw();
};
struct Name_2f7ee0 {
};
void* __cdecl FUN_0008d690(unsigned) throw();
void* __cdecl thunk_FUN_0008d690(unsigned) throw();
extern "C" Ref_2f7ee0* __cdecl FUN_002efa90(CollisionObject_2f7ee0*, int, int) throw();
class ImpulseBasedCollisionSolver_2f7ee0 {
  public:
    void* vptr;
    int m4, m8;
    SubA_2f7ee0 sa;
    SymMatrix_2f7ee0 s1, s2, s3;
    int me8, mec;
    int mf0;
    char cf4;
    int mf8;
    Ref_2f7ee0* mfc;
    ImpulseBasedCollisionSolver_2f7ee0() throw();
};
ImpulseBasedCollisionSolver_2f7ee0::ImpulseBasedCollisionSolver_2f7ee0() throw() {
    vptr = DAT_004316e8;
    m4 = 0;
    m8 = 0;
    sa.Init_002f8d70();
    s1.Init_002fca90();
    s2.Init_002fca90();
    s3.Init_002fca90();
    cf4 = 0;
    mf8 = 3;
    me8 = (*(Cfg_2f7ee0**)&DAT_00554c10)->b;
    mec = (*(Cfg_2f7ee0**)&DAT_00554c10)->a;
    CollisionWall_2f7ee0* p = (CollisionWall_2f7ee0*)FUN_0008d690((int)sizeof(CollisionWall_2f7ee0));
    CollisionWall_2f7ee0* q = p ? p->Ctor_0030e700() : 0;
    CollisionObject_2f7ee0* r = (CollisionObject_2f7ee0*)thunk_FUN_0008d690(sizeof(HulkCollisionObject));   // (x64t5) the CollisionObject record (decls/physics_world.h; 0x80 on 32-bit)
    CollisionObject_2f7ee0* t = r ? r->Ctor_00304f50(q) : 0;
    Ref_2f7ee0* x = FUN_002efa90(t, 0, 0);
    mfc = x;
    x->a();
    ((owners::Target_27b040 *)(((Name_2f7ee0*)((char*)t + 8))))->FUN_0027b040((hulk_uintptr)"ATGWorldCollision");
}
} // namespace fn_002f7ee0

namespace fn_f524d977 {

// 0x002f7fc0 physics::ImpulseBasedCollisionSolver::vfunc_0 (91 B): matches/0x002f7fc0.cpp
// sym: ??_GImpulseBasedCollisionSolver_2f7fc0@fn_f524d977@@UAEPAXI@Z
ImpulseBasedCollisionSolver_2f7fc0::~ImpulseBasedCollisionSolver_2f7fc0() {
    if (r4)
        r4->f1();
    if (rfc)
        rfc->f1();
    ccc.init_002fcaa0();
    cb0.init_002fcaa0();
    c94.init_002fcaa0();
}


// 0x002f8020 FUN_002f8020 (732 B): equivalent/0x002f8020.cpp
// sym: ?FUN_002f8020@Solver_2f8020@fn_f524d977@@QAEXPAUList_2f8020@2@HH@Z @6faf78b5f491 @w030b791694e2
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 31/38, incomplete)
// FUN_002f8020 @ 0x002f8020
void Solver_2f8020::FUN_002f8020(List_2f8020 *l, int unused, int a3)
{
    if (core->obj8 != 0)
        core->obj8->FUN_0030e190(a3);
    hulk_intptr n = l->end - l->begin;
    if (n == 0)
        return;
    list = l;
    core->c3(l, a3);
    int it = 0;
    f1 = 1;
    do {
        f0 = 1;
        Rec_2f8020 *cur = list->begin;
        if (cur != list->end) {
            do {
                if ((cur->flags & 1) == 0) {
                    r = *cur;
                    if (r.o1->o6() == 4) {
                        Zone_2f8020 *z = zone;
                        Obj1_2f8020 *o = r.o1;
                        r.p2 = z->f74;
                        z->FUN_002ef440(o->f48);
                        Obj1_2f8020 *o2 = r.o1;
                        zone->fc = o2->f38;
                        zone->f8 = o2->f3c;
                    }
                    if (core->c5(&r, it + 1) == 1) {
                        cur->flags = cur->flags | 1;
                    } else {
                        Body_2f8020 *b84 = r.p1->body;
                        Body_2f8020 *b88 = r.p2->body;
                        o84 = b84;
                        o88 = b88;
                        Q_2f8020 *a = b84->b9(r.f1c);
                        q1 = a;
                        Q_2f8020 *b = o88->b9(r.f20);
                        Q_2f8020 *qa = q1;
                        q2 = b;
                        if (qa != 0) {
                            hulk_intptr t = qa->f1ec;
                            if (t == 0)
                                qa->f1ec = (hulk_intptr)r.p2;
                            else if (t != (hulk_intptr)r.p2)
                                qa->f1f4 = qa->f1f4 & 0xfe;
                        }
                        if (b != 0) {
                            hulk_intptr t = b->f1ec;
                            if (t == 0)
                                b->f1ec = (hulk_intptr)r.p1;
                            else if (t != (hulk_intptr)r.p1)
                                b->f1f4 = b->f1f4 & 0xfe;
                        }
                        FUN_002f7b00();
                        bool hit = false;
                        if (f1 != 0) {
                            double nk = -k;
                            double X = nk * r.f24 + f74;
                            double Y = nk * r.f28 + f78;
                            double Z = nk * r.f2c + f7c;
                            float len = (float)sqrt(X * X + (Y * Y + Z * Z));
                            if (core->c6(o84, r.f1c, o88, r.f20, &r.f38, k, len, &q1, &q2) == 1) {
                                cur->flags = cur->flags | 1;
                                hit = true;
                            }
                        }
                        if (!hit) {
                            if (q1 == 0 && q2 == 0) {
                                cur->flags = cur->flags | 1;
                            } else {
                                s1();
                                cur->flags = r.flags;
                            }
                        }
                    }
                }
                cur = cur + 1;
            } while (cur != list->end);
        }
        char done = f0;
        it++;
        f1 = 0;
        if (done != 0)
            break;
    } while (it < iters);
    core->c4(list, 0);
}


// 0x002f8300 FUN_002f8300 (1062 B): equivalent/0x002f8300.cpp
// sym: ?FUN_002f8300@ImpulseBasedCollisionSolver_2f8300@fn_f524d977@@QAEHXZ @74f608e0b478 @w835321aa2621
// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 12/12)
// FUN_002f8300 @ 0x002f8300
int ImpulseBasedCollisionSolver_2f8300::FUN_002f8300()
{
    volatile V3_2f8300 *r = &res;
    struct Frame {
        float f10;
        float f14;
        float f18;
        float f1c;
        float f20;
        V3_2f8300 d;
        V3_2f8300 a30;
        V3_2f8300 v3c;
        V3_2f8300 v48;
        SymMatrix m54;
    } fr;

    r->z = 0.0f;
    r->y = 0.0f;
    r->x = 0.0f;
    ((owners::V_2fcb30 *)&mat)->FUN_002fcb30((owners::V_2fcb30 *)a94, (owners::V_2fcb30 *)ab0);
    if (mat.f4 == 0.0f)
        return 1;
    fr.f1c = v4() - 1.0f;
    if (fF3 == 0)
        fr.f10 = FUN_002f2950(peer14->f1c, peer18->f1c);
    else
        *(int *)&fr.f10 = 0;
    fr.f20 = FUN_002f7ca0();
    fr.d = dir;
    fr.m54.FUN_002fca90();
    ((owners::Sym3_2fd0c0 *)&(fr.m54))->FUN_002fd0c0((const owners::Sym3_2fd0c0 *)(SymMatrix *)(&mat));
    ((owners::Transform_2fd020 *)&mat)->FUN_002fd020((float *)(V3_2f8300 *)(&fr.d), (float *)(V3_2f8300 *)(&fr.v3c));
    hulk_freg s = (-1.0f / (fr.v3c.z * fr.d.z + fr.v3c.y * fr.d.y + fr.v3c.x * fr.d.x)) * f80;
    fr.a30.x = fr.d.x * s;
    fr.a30.y = fr.d.y * s;
    fr.a30.z = fr.d.z * s;
    if (fF4 != 0) {
        if (fr.f10 == 0.0f) {
            r->x = fr.a30.x;
            r->y = fr.a30.y;
            r->z = fr.a30.z;
        } else {
            ((owners::Transform_2fd020 *)&(fr.m54))->FUN_002fd020((float *)(V3_2f8300 *)(&vec74), (float *)(V3_2f8300 *)(&fr.v48));
            r->x = fr.v48.x + fr.a30.x;
            r->y = fr.v48.y + fr.a30.y;
            r->z = fr.v48.z + fr.a30.z;
            r->x = r->x * -1.0f;
            r->y = r->y * -1.0f;
            r->z = r->z * -1.0f;
            double w = fr.f1c + 1.0f;
            r->x = fr.a30.x * w + r->x;
            r->y = fr.a30.y * w + r->y;
            r->z = fr.a30.z * w + r->z;
        }
    } else {
        ((owners::Transform_2fd020 *)&(fr.m54))->FUN_002fd020((float *)(V3_2f8300 *)(&vec74), (float *)(V3_2f8300 *)(&fr.v48));
        double x0 = fr.v48.x + fr.a30.x;
        r->x = (float)x0;
        fr.f14 = fr.v48.y + fr.a30.y;
        r->y = fr.f14;
        fr.f18 = fr.v48.z + fr.a30.z;
        r->z = fr.f18;
        double u = fr.f20 + 1.0f;
        double nu = -u;
        r->x = nu * r->x;
        r->y = nu * r->y;
        r->z = nu * r->z;
        double w = fr.f1c + 1.0f;
        fr.f1c = (float)w;
        r->x = fr.a30.x * w + r->x;
        r->y = fr.a30.y * w + r->y;
        r->z = fr.a30.z * w + r->z;
        double q = fr.d.z * r->z + fr.d.y * r->y + fr.d.x * r->x;
        double nq = -q;
        fr.v3c.x = fr.d.x * nq + r->x;
        fr.v3c.y = fr.d.y * nq + r->y;
        fr.v3c.z = fr.d.z * nq + r->z;
        double P = (fr.d.z * r->z + fr.d.y * r->y + fr.d.x * r->x) * fr.f10;
        double L = fr.v3c.z * fr.v3c.z + fr.v3c.y * fr.v3c.y + fr.v3c.x * fr.v3c.x;
        double R;
        if (P * P < L) {
            fr.v3c.z = fr.f18;
            fr.v3c.y = fr.f14;
            double dd = fr.v48.z * fr.d.z + fr.v48.y * fr.d.y + fr.v48.x * fr.d.x;
            double x = fr.d.x * dd + fr.v48.x;
            double y = fr.d.y * dd + fr.v48.y;
            double z = fr.d.z * dd + fr.v48.z;
            double S = z * z + y * y + x * x;
            fr.v3c.x = (float)x0;
            double sq = sqrt(S);
            double T = sq + (fr.v3c.z * fr.d.z + fr.v3c.y * fr.d.y + fr.v3c.x * fr.d.x) * fr.f10;
            if (T == 0.0) {
                r->z = 0.0f;
                r->y = 0.0f;
                r->x = 0.0f;
                fr.m54.FUN_002fcaa0();
                return 1;
            }
            double DD = fr.a30.z * fr.d.z + fr.a30.y * fr.d.y + fr.a30.x * fr.d.x;
            R = DD / T * fr.f1c * fr.f10;
        } else {
            R = u;
        }
        r->x = (float)x0;
        r->y = fr.f14;
        r->z = fr.f18;
        double nr = -R;
        r->x = nr * r->x;
        r->y = nr * r->y;
        r->z = nr * r->z;
        double w2 = fr.f1c;
        r->x = fr.a30.x * w2 + r->x;
        r->y = fr.a30.y * w2 + r->y;
        r->z = fr.a30.z * w2 + r->z;
    }
    int ret = target->v7((V3_2f8300 *)r, pos);
    fr.m54.FUN_002fcaa0();
    return ret;
}

} // namespace fn_f524d977

// 0x002f8730 physics::ImpulseBasedCollisionSolver::vfunc_4 (208 B): equivalent/0x002f8730.cpp [wrapped: conflict: physics::ImpulseBasedCollisionSolver]
// sym: ?vfunc_4@ImpulseBasedCollisionSolver@physics@fn_002f8730@@UAEMXZ @c8454b4676a5 @w9fedb0bb7645
namespace fn_002f8730 {
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 6/6)
// physics::ImpulseBasedCollisionSolver::vfunc_4 @ 0x002f8730

extern float __cdecl FUN_002f2900(unsigned int, unsigned int);
extern unsigned char DAT_004d2c52;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

struct Body_2f8730 { char pad[0x1c]; unsigned int value; };
namespace physics {
struct ImpulseBasedCollisionSolver {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual hulk_freg vfunc_4();
 char pad04[0x10]; Body_2f8730* first; Body_2f8730* second; char pad1c[0x14]; float threshold; char pad34[0x4c]; float velocity; char pad84[0x64]; float energy; float scale; char padf0[2]; unsigned char flag;
};
// x87: the result comes back unrounded in st0 (hulk_freg return: double natively; callers declared `float` read st0)
hulk_freg ImpulseBasedCollisionSolver::vfunc_4() {
 float saved = threshold;
 float result = FUN_002f2900(first->value, second->value);
 if (!(result > 1.0f)) result = 1.0f;
 if (!(saved < energy)) { flag=1; return result; }
 union { float f; unsigned int u; } bits;
 bits.f=velocity; bits.u &= 0x7fffffff;
 float limit=(float)sqrt(((double)energy-saved)*scale*2);
 if ((result-1.0f)*bits.f <= limit) {
  bits.f=velocity; bits.u &= 0x7fffffff;
  double factor=(double)DAT_004d2c54/bits.f;
  flag=DAT_004d2c52;
  return factor*limit+1.0f;
 }
 flag=1; return result;
}
}
} // namespace fn_002f8730


// 0x002f8800 FUN_002f8800 (17 B): matches/0x002f8800.cpp [wrapped: conflict: CollisionSolverAgent]
// sym: ??0CollisionSolverAgent@fn_002f8800@@QAE@XZ
namespace fn_002f8800 {
extern "C" char DAT_00431700[];
class CollisionSolverAgent {
  public:
    void* vptr;
    int a;
    int b;
    CollisionSolverAgent();
};
CollisionSolverAgent::CollisionSolverAgent() {
    a = 0;
    vptr = (void*)((hulk_intptr)DAT_00431700);
    b = 0;
}
} // namespace fn_002f8800

namespace fn_f524d977 {

// 0x002f8820 FUN_002f8820 (37 B): matches/0x002f8820.cpp
// sym: ?FUN_002f8820@fn_f524d977@@YIXPAUObj_2f8820@1@PAX@Z
void __fastcall FUN_002f8820(Obj_2f8820* p, void*) {
    p->vptr = (void*)((hulk_intptr)DAT_00431700);
    if (p->ref) {
        p->ref->Release(1);
        p->ref = 0;
    }
    p->vptr = (void*)((hulk_intptr)DAT_003f6098);
}

} // namespace fn_f524d977

// 0x002f8850 physics::CollisionSolverAgent::vfunc_8 (208 B): equivalent/0x002f8850.cpp [wrapped: conflict: physics::CollisionSolverAgent]
// sym: ?vfunc_8@CollisionSolverAgent@physics@fn_002f8850@@UAEHPAUContact_2f8850@3@H@Z @3ed3a8dd9341 @w7f258ca0dd35
namespace fn_002f8850 {
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 8/8)
// physics::CollisionSolverAgent::vfunc_8 @ 0x002f8850

struct Vec_2f8850 { float x,y,z; };
struct Body_2f8850 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual float s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(Vec_2f8850*,Vec_2f8850*,int);
 char pad[0x20]; int state;
};
struct Contact_2f8850 { char pad[0x50]; Vec_2f8850 velocity; char pad2[0x14]; Body_2f8850* body; void FUN_002ef8b0(int); };
namespace physics {
struct CollisionSolverAgent {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual int vfunc_8(Contact_2f8850*,int);
};
int CollisionSolverAgent::vfunc_8(Contact_2f8850* c,int unused) {
 Body_2f8850* b=c->body;
 if(!b || b->state) return 0;
 Vec_2f8850 v=c->velocity, a,d;
 b->s25(&a,&d,-1);
 hulk_freg radius=b->s14();
 hulk_freg rr=radius*radius;
 hulk_freg vv=v.z*v.z+v.x*v.x+v.y*v.y;
 volatile float stored=vv;
 if(!(vv<rr)) rr=stored;
 hulk_freg aa=a.z*a.z+a.y*a.y+a.x*a.x;
 if((*(const float*)&DAT_004d2c58)*rr<aa) { c->FUN_002ef8b0(1); return 1; }
 return 0;
}
}
} // namespace fn_002f8850


// 0x002f8920 physics::CollisionSolverAgent::vfunc_9 (219 B): equivalent/0x002f8920.cpp
// sym: ?vfunc_9@CollisionSolverAgent@physics@@UAEHHH@Z @45d9d17a6540 @wfa416bd8d5a4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// physics::CollisionSolverAgent::vfunc_9 @ 0x002f8920
int physics::CollisionSolverAgent::vfunc_9(hulk_intptr __p0, int index) { AgentInput * input = (AgentInput *)__p0;

 Body_2f8920* body=input->slot9(index);
 if(input->mode!=1) { body->slot27(-1); return 0; }
 if(!body->slot11() || index>0) return 0;
 Vec3_2f8920 a,b;
 body->slot25(&a,&b,-1);
 float r=body->slot14();
 if(!((r+r)*(r+r) >= a.z*a.z+a.x*a.x+a.y*a.y)) return 0;
 r=body->slot15();
 if(!((r+r)*(r+r) >= b.z*b.z+b.y*b.y+b.x*b.x)) return 0;
 body->slot27(-1);
 return 1;
}

namespace fn_f524d977 {

// 0x002f8a00 physics::ImpulseBasedCollisionSolver::vfunc_1 (814 B): equivalent/0x002f8a00.cpp
// sym: ?vfunc_1@ImpulseBasedCollisionSolver@fn_f524d977@@UAEXXZ @fefaffd30d56 @w359c28946194
// STATUS: equivalent (tools/equiv.py level 3: 20038 inputs, branch coverage 48/48)
// physics::ImpulseBasedCollisionSolver::vfunc_1 @ 0x002f8a00
void ImpulseBasedCollisionSolver::vfunc_1()
{
    Collider_2f8a00* a = collA;
    Collider_2f8a00* b = collB;
    sameObject = (a == b);
    if (t >= -1.0e-6f)
        return;

    if (f1) {
        if (a != 0 && bodyA->state != 1 && idA == 0)
            collA = 0;
        if (b != 0 && bodyB->state != 1 && idB == 0)
            collB = 0;
        if (collA == 0 && collB == 0) {
            flags |= 1;
            return;
        }
    }

    FUN_002f7b70(collA, collB, &p38, &p94, idA, idB);
    FUN_002f7b70(collB, collA, &p44, &pb0, idB, idA);

    char firstA = f1;
    char firstB = f1;
    f0 = 0;
    for (;;) {
        if (FUN_002f8300() == 1) {
            flags |= 1;
            return;
        }
        char hit = vfunc_2(collA, collB, &p38, &p94, idA, idB);
        if (hit) {
            char ok = hit;
            if (firstA) {
                ok = world->v8(bodyA, idA) != 1;
                firstA = 0;
            }
            if (ok) {
                p50.x = p50.x * -1.0f;
                p50.y = p50.y * -1.0f;
                p50.z = p50.z * -1.0f;
                char hit2 = vfunc_2(collB, collA, &p44, &pb0, idB, idA);
                if (hit2) {
                    if (firstB) {
                        hit2 = world->v8(bodyB, idB) != 1;
                        firstB = 0;
                    }
                } else if (collB->v24(&p44, &p68, idB)) {
                    p74.x = p5c.x - p68.x;
                    p74.y = p5c.y - p68.y;
                    p74.z = p5c.z - p68.z;
                    t = normal.z * *(volatile float *)&p74.z + normal.y * *(volatile float *)&p74.y + normal.x * *(volatile float *)&p74.x; // the original reloads the rounded p74 members
                }
                if (hit2)
                    break;
            }
        } else if (collA->v24(&p38, &p5c, idA)) {
            p74.x = p5c.x - p68.x;
            p74.y = p5c.y - p68.y;
            p74.z = p5c.z - p68.z;
            t = normal.z * *(volatile float *)&p74.z + normal.y * *(volatile float *)&p74.y + normal.x * *(volatile float *)&p74.x; // the original reloads the rounded p74 members
        }
        if (flags & 1)
            break;
    }

    if (collA == collB) {
        vfunc_3(collA, idA, idB, f2);
        vfunc_3(collB, idB, idA, f2);
    } else {
        vfunc_3(collA, idA, -1, f2);
        vfunc_3(collB, idB, -1, f2);
    }
}

} // namespace fn_f524d977

// 0x002f8d30 physics::CollisionSolverAgent::vfunc_2 (57 B): matches/0x002f8d30.cpp [wrapped: conflict: CollisionSolverAgent]
// sym: ?vfunc_2@CollisionSolverAgent@fn_002f8d30@@QAEPAV12@E@Z
namespace fn_002f8d30 {
extern "C" char DAT_003f6098[];
extern "C" char DAT_00431700[];
class Ref_2f8d30 {
  public:
    virtual void a(int);
};
class CollisionSolverAgent {
  public:
    hulk_intptr vptr;
    int pad4;
    Ref_2f8d30* mPtr;
    CollisionSolverAgent* vfunc_2(unsigned char);
};
extern void thunk_0008d330(CollisionSolverAgent*);
CollisionSolverAgent* CollisionSolverAgent::vfunc_2(unsigned char flag) {
    vptr = ((hulk_intptr)DAT_00431700);
    if (mPtr) {
        mPtr->a(1);
        mPtr = 0;
    }
    vptr = ((hulk_intptr)DAT_003f6098);
    if (flag & 1)
        thunk_0008d330(this);
    return this;
}
} // namespace fn_002f8d30

namespace fn_f524d977 {

// 0x002f8d70 FUN_002f8d70 (28 B): matches/0x002f8d70.cpp
// sym: ?FUN_002f8d70@fn_f524d977@@YIPAUThing_2f8d70@1@PAU21@@Z
Thing_2f8d70* __fastcall FUN_002f8d70(Thing_2f8d70* p) {
    p->a[0] = 0;
    p->a[1] = 0;
    p->a[2] = 0;
    p->a[3] = 0;
    p->a[4] = 0xffffffff;
    p->a[5] = 0xffffffff;
    p->a[10] = 0;
    return p;
}

} // namespace fn_f524d977
