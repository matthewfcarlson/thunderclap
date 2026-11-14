// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x003101f0..0x00312440 (kind game, layer engine, confidence high), dominant class physics::ArticulatedPhysicsObject
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fec45b2c {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fec45b2c {} using namespace fn_fec45b2c;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fec45b2c {
extern "C" char DAT_0043217c[];
class ArticulatedPhysicsObject_3101f0 {
  public:
    ArticulatedPhysicsObject_3101f0* Init();
};
struct ArticulatedPhysicsObject_nv_3101f0 {
    void InitBase_002f5480();
};
extern int hulk_at_0043217c;
class Obj_3103e0 {
  public:
    virtual void Kill(int);
    virtual void Release();
};
extern void Free_0008d340(void*);
struct ArticulatedPhysicsObject_nv_3103e0 {
    void Tail_002f5640();
};
struct Vec3_310490 {
    int x, y, z;
};
struct Item_310490 {
    char pad[0x98];
    int a, b, c;
};
struct Holder_310490 {
    char pad[0x10];
    int* records;
};
struct Ctx_310490 {
  public:
    void* Get_0030f490(int);
};
struct A_310490 {
  public:
    void* Next_0030edf0();
};
struct B_310490 {
  public:
    void* Next_0030f100();
};
struct C_310490 {
  public:
};
struct Root_310490 {
    char pad[0x1fc];
    Item_310490** items;
    char pad2[8];
    Ctx_310490* context;
    char pad3[0x14];
    Holder_310490* holder;
    void Do(int, Vec3_310490*, char);
};
class PhysicsObject {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void vfunc_7();
};
struct Vec3_310550 {
    float x, y, z;
};
struct Mat4_310550 {
    float m[16];
};
struct SymMatrix {
    int vptr;
    int m[6];
    void FUN_002fca90();
    void FUN_002fcaa0();
    void FUN_002fcd60(void* basis);
};
struct Joint_310550 {
    Joint_310550* FUN_0030f100();
};
struct Link_310550 {
    Joint_310550* FUN_0030edf0();
};
struct Manager_310550 {
    Link_310550* FUN_0030f490(int index);
};
struct Owner_310550 {
    char pad00[0x40];
    Vec3_310550 pos;
    char pad4c[0x94 - 0x4c];
    char frozen;
};
struct Body_310550 {
    char pad00[4];
    char active;
    char pad05[0x38 - 5];
    float mass;
    char pad3c[0x68 - 0x3c];
    int inertia[6];
    float ax, ay, az;
    char pad8c[0xd4 - 0x8c];
    float bx, by, bz;
};
extern "C" void FUN_00305b00(SymMatrix* out, Vec3_310550* offset, float mass);
struct Frame_310550 {
    Vec3_310550 v;
    SymMatrix s2;
    Vec3_310550 w;
    SymMatrix s1;
    Mat4_310550 m;
};
class Rigid {
public:
    char pad00[0x10];
    Owner_310550* owner;
    char pad14[0x40 - 0x14];
    float mass;
    float invMass;
    char pad48[0x58 - 0x48];
    Mat4_310550 mat;
    float cx, cy, cz;
    char flaga4;
    char pada5[3];
    Vec3_310550 localCenter;
    Vec3_310550 refPoint;
    char padc0[0xdc - 0xc0];
    SymMatrix inertiaBody;
    SymMatrix total;
    SymMatrix inertiaWorld;
    char pad130[0x1f8 - 0x130];
    Body_310550** bodies;
    char pad1fc[4];
    int count;
    char pad204[4];
    Manager_310550* manager;
    float time;
    float timeMax;

    void FUN_00310550();
};
struct Vec3_310910 { float x,y,z; };
} // namespace fn_fec45b2c
namespace physics {
struct SimulatedObject_310910 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void vfunc_22(Vec3_310910*);
 int unused; int count; int next;
 char pad[0xd4-0x10]; Vec3_310910 position; char pad2[0xec-0xe0]; unsigned char active;
};
}
namespace physics {
struct Joint {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
}
namespace fn_fec45b2c {
struct Vec3_310bc0 { float x,y,z; };
struct Work_310bc0 { char data[28]; void FUN_002fca90(); void FUN_002fcaa0(); };
struct Item_310bc0 { char pad0[128]; Vec3_310bc0 position; char pad1[72]; Vec3_310bc0 offset; };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
 virtual void slot17(Vec3_310bc0*,Vec3_310bc0*,int,int,int);
 virtual bool slot18(Vec3_310bc0*,Vec3_310bc0*,Work_310bc0*,int,int,int);
 virtual void slot19(int,int,int);
 virtual void slot20(Vec3_310bc0*,Work_310bc0*,int,int,int);
 char padding[0x1f8]; Item_310bc0** items;
 void FUN_00310bc0(int index,float scale,Vec3_310bc0* direction);
};
typedef unsigned int uint_310d80;
class Thing_310e90 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_310e90 {
    char pad[0x220];
    Thing_310e90* member;

  public:
    void Set(Thing_310e90* p);
};
struct SubObj_310ec0 {
    char pad0[4];
};
struct Node {
  public:
    char _m_pad_0[0x4];
    char active;
    char _m_pad_5[0x1];
    short kind;
    int key;
    char _m_pad_c[0x10];
    Node *next;
    Node** childBegin;
    Node** childEnd;
    char _m_pad_28[0x8];
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    char _m_pad_44[0x4];
    SubObj_310ec0 sub;
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    char _m_pad_64[0x4];
    float f68;
    float f6c;
    float f70;
    float f74;
    float f78;
    float f7c;
    char _m_pad_80[0x70];
    float fF0;
    void clean_003099d0();
};
class ArticulatedPhysicsObject : public PhysicsObject {
  public:
    virtual void vfunc_7();
    char pad[0x1f4];
    Node** mItems;
    int gap;
    int mCount;
};
class ArticulatedPhysicsObject_310b30 {
public:
    char pad00[0x1fc];
    Node **nodes;
    char pad200[0x214 - 0x200];
    Node *first;
    Node *cursor;
    unsigned char active;
    void FUN_00310b30(ArticulatedPhysicsObject_310b30 *owner, int a, int b);
};
struct Tree_310ec0 {
    char pad0[0x3c];
    float total;            // 0x3c
    float weight;           // 0x40
    float invWeight;        // 0x44
    char pad48[0x1b0];
    Node** nodes;           // 0x1f8
    char pad1fc[4];
    int nodeCount;          // 0x200
    char pad204[8];
    int cur;                // 0x20c
    int next;               // 0x210

    void FUN_00310ec0();
    void FUN_00310550();
};
class Sub_311060 {
  public:
    void second_00308ba0(int);
    void third_00308b20();
};
struct ThisCall_00310550 {
    void FUN_00310550();
};
struct State_3111f0 {
    char pad[0x94];
    char busy;
};
struct H3_3111f0 {
    void* Get_0030f100();
};
struct H2_3111f0 {
    H3_3111f0* Get_0030edf0();
};
struct H1 {
    H2_3111f0* Get_0030f490(int);
};
struct Item_3111f0 {
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
    virtual void Use(void*);
    int pad;
    int id;
};
struct Obj_3111f0 {
    char pad0[0x10];
    State_3111f0* state;
    char pad1[0x1e4];
    Item_3111f0** items;
    char pad2[4];
    int count;
    char pad3[4];
    H1* helper;
    void Run();
    void Tail_00310550();
};
extern "C" void __cdecl FUN_00310d80(unsigned int *, int, int, unsigned int);
typedef unsigned int UInt;
extern "C" void __cdecl FUN_00311740(unsigned int *, int, int, unsigned int);
struct UIntRange_3119b0 {
    unsigned int *first;
    unsigned int *second;
};
void __cdecl FUN_003117f0(unsigned int *a, unsigned int *b, unsigned int *c);
struct BoneList;
struct Y_311d50 {
    Z *FUN_0030f100();
};
struct X_311d50 {
    Y_311d50 *FUN_0030edf0();
};
struct SkeletonData_311d50 {
    char pad00[0x28];
    unsigned short *parent;
};
struct Source_311d50 {
    char pad00[8];
    SkeletonData_311d50 *data;
    X_311d50 *FUN_0030f490(int id);
};
class Bone_311d50 {
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
    virtual void v10(Z *z);
    char pad04[4];
    int id;
    int parentIndex;
    char pad10[0x1c - 0x10];
    Bone_311d50 *parent;
    Bone_311d50 **childBegin;
    Bone_311d50 **childEnd;
    Bone_311d50 **childCapEnd;
    char pad2c[0xe4 - 0x2c];
    float weight;
    char padE8[0xef - 0xe8];
    char marked;
};
typedef void (__fastcall *BoneSlot10)(Bone_311d50 *self, int unused, Z *z);
static inline void **VtableOf(Bone_311d50 *b)
{
    return *(void ***)b;
}
extern "C" void *FUN_0008d6d0(unsigned int size);
extern "C" void *FUN_00266e00(int kind, unsigned int size);
extern "C" void FUN_00267090(void *p);
extern "C++" __declspec(nothrow) void __cdecl FUN_00311c20(int *, int *, int);
class SkeletonBuilder {
public:
    char pad00[0x1f8];
    Bone_311d50 **list;
    Bone_311d50 **table;
    int count;
    int capacity;
    Source_311d50 *source;
    void FUN_00311d50();
    void FUN_00310ec0();
};
struct Obj_312130;
struct Ref_312130 { virtual void AddRef() = 0; };
struct Context { char pad[0x88]; Ref_312130* ref; };
struct Child_312130 {
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
 virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
 virtual void v12()=0; virtual void v13()=0; virtual void v14()=0; virtual void v15()=0;
 virtual void v16()=0; virtual void v17()=0; virtual void v18()=0; virtual void v19()=0;
 virtual void v20()=0; virtual void v21()=0; virtual void v22()=0; virtual void v23()=0;
 virtual void v24()=0; virtual void v25()=0; virtual void v26()=0;
 virtual Child_312130* Clone()=0;
};
struct Obj_312130 {
 char pad0[0x1f8]; Child_312130** children; int unknown1fc; int count; int unknown204;
 Ref_312130* ref208; int field20c; int field210; int field214; int field218;
 unsigned char field21c, field21d; char pad21e[2]; Ref_312130* ref220; int field224;
 int field228,field22c,field230;
 void FUN_002f75d0(Obj_312130*,Context*);
 void FUN_00311d50();
 void FUN_00312130(Obj_312130* dst, Context* context);
};
class Item_312240 {
  public:
    virtual void Use();
    virtual void Release();
};
class Owner_312240 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void Notify();
    char pad[0x204];
    Item_312240* item;
    void HelperA_00311d50();
    void HelperB_003111f0();
    void Set(Item_312240*);
};
class Helper_3122a0 {
  public:
    void Init_002f5480();
};
struct ArticulatedPhysicsObject_nv_3122a0 {
    void Setup_00312130(void*, unsigned int);
};
extern "C" void* __cdecl alloc(hulk_uintptr);


// 0x003101f0 FUN_003101f0 (35 B): matches/0x003101f0.cpp
// sym: ?Init@ArticulatedPhysicsObject_3101f0@fn_fec45b2c@@QAEPAV12@XZ
ArticulatedPhysicsObject_3101f0* ArticulatedPhysicsObject_3101f0::Init() {
    ((ArticulatedPhysicsObject_nv_3101f0*)(((physics::ArticulatedPhysicsObject*)(this))))->InitBase_002f5480();
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0043217c);
    *(unsigned int*)((char*)this + 0x1fc) = 0;
    *(unsigned int*)((char*)this + 0x24) = 1;
    return this;
}


// 0x00310220 physics::ArticulatedPhysicsObject::vfunc_30 (1 B): matches/0x00310220.cpp
// sym: ?FUN_00310220@fn_fec45b2c@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00310220() {}

} // namespace fn_fec45b2c

// 0x003103e0 FUN_003103e0 (118 B): matches/0x003103e0.cpp
// sym: ?FUN_003103e0@ArticulatedPhysicsObject@physics@@QAEXXZ
void physics::ArticulatedPhysicsObject::FUN_003103e0() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0043217c;
    if ((*(Obj_3103e0 * *)&this->f_220))
        (*(Obj_3103e0 * *)&this->f_220)->Release();
    if ((*(Obj_3103e0 * *)&this->f_208))
        (*(Obj_3103e0 * *)&this->f_208)->Release();
    for (int i = 0; i < this->f_200; ++i) {
        Obj_3103e0* p = (*(Obj_3103e0 ** *)&this->f_1f8)[i];
        if (p)
            p->Kill(1);
    }
    Free_0008d340((*(Obj_3103e0 ** *)&this->f_1f8));
    Free_0008d340((*(void * *)&this->f_1fc));
    ((ArticulatedPhysicsObject_nv_3103e0*)this)->Tail_002f5640();
}


// 0x00310460 FUN_00310460 (34 B): matches/0x00310460.cpp
// sym: ?FUN_00310460@C_310460@owners@@QAE_NHD@Z
bool owners::C_310460::FUN_00310460(int index, char value) {
    char* p = (char*)arr[index];
    if (p && p[4] != value)
        p[4] = value;
    return false;
}

namespace fn_fec45b2c {

// 0x00310490 FUN_00310490 (122 B): matches/0x00310490.cpp
// sym: ?Do@Root_310490@fn_fec45b2c@@QAEXHPAUVec3_310490@2@D@Z
void Root_310490::Do(int index, Vec3_310490* out, char flag) {
    if (!flag) {
        Item_310490* item = items[index];
        if (item) {
            out->x = item->a;
            out->y = item->b;
            out->z = item->c;
            return;
        }
    }
    void* a = context->Get_0030f490(index);
    void* b = ((A_310490*)a)->Next_0030edf0();
    void* c = ((B_310490*)b)->Next_0030f100();
    ((owners::M_22c3b0 *)(((C_310490*)c)))->FUN_0022c3b0((float *)(holder->records + index * 7), (float *)(Vec3_310490 *)out);
}


// 0x00310510 physics::ArticulatedPhysicsObject::vfunc_7 (60 B): matches/0x00310510.cpp
// sym: ?vfunc_7@ArticulatedPhysicsObject@fn_fec45b2c@@UAEXXZ
void ArticulatedPhysicsObject::vfunc_7() {
    PhysicsObject::vfunc_7();
    int i = 0;
    if (mCount > 0) {
        do {
            mItems[i]->clean_003099d0();
            ++i;
        } while (i < mCount);
    }
}


// 0x00310550 FUN_00310550 (947 B): equivalent/0x00310550.cpp
// sym: ?FUN_00310550@Rigid@fn_fec45b2c@@QAEXXZ @86535483a1d8 @w6c532178c961
// STATUS: equivalent (tools/equiv.py level 3: 212 inputs, branch coverage 22/22)
// FUN_00310550 @ 0x00310550
void Rigid::FUN_00310550()
{
    if (!(mass > 0.0f))
        return;
    if (!(time >= timeMax))
        return;
    if (owner->frozen)
        return;

    Frame_310550 f;
    time = 0;
    cz = 0;
    cy = 0;
    cx = 0;
    for (int i = 0; i < count; i++) {
        Body_310550* b = bodies[i];
        if (b->mass > 0.0f && b->active) {
            f.v.x = b->bx + b->ax;
            f.v.y = b->by + b->ay;
            f.v.z = b->bz + b->az;
            float mass1 = bodies[i]->mass;
            cx = f.v.x * mass1 + cx;
            cy = f.v.y * mass1 + cy;
            cz = f.v.z * mass1 + cz;
        }
    }
    cx = invMass * cx;
    cy = invMass * cy;
    cz = invMass * cz;
    Vec3_310550* op = &owner->pos;
    f.w.x = cx - op->x;
    f.w.y = cy - op->y;
    f.w.z = cz - op->z;
    f.m = mat;
    ((owners::M_22c0b0 *)&(f.m))->FUN_0022c0b0();
    ((owners::M_22c3b0 *)&(f.m))->FUN_0022c3b0((float *)(Vec3_310550 *)(&f.w), (float *)(Vec3_310550 *)(&localCenter));
    flaga4 = 0;
    f.s1.FUN_002fca90();
    f.s2.FUN_002fca90();
    ((owners::C_2fd0a0 *)&total)->FUN_002fd0a0();
    for (int i = 0; i < count; i++) {
        Body_310550* b = bodies[i];
        if (b->mass > 0.0f && b->active) {
            f.v.x = b->ax + b->bx;
            f.v.y = b->ay + b->by;
            f.v.z = b->az + b->bz - cz;
            f.v.x = f.v.x - cx;
            f.v.y = f.v.y - cy;
            FUN_00305b00(&f.s1, &f.v, bodies[i]->mass);
            Body_310550* b2 = bodies[i];
            f.s2.m[0] = b2->inertia[0];
            f.s2.m[1] = b2->inertia[1];
            f.s2.m[2] = b2->inertia[2];
            f.s2.m[3] = b2->inertia[3];
            f.s2.m[4] = b2->inertia[4];
            f.s2.m[5] = b2->inertia[5];
            f.s2.FUN_002fcd60(manager->FUN_0030f490(i)->FUN_0030edf0()->FUN_0030f100());
            ((owners::V_2fcaf0 *)&(f.s1))->FUN_002fcaf0((owners::V_2fcaf0 *)(SymMatrix *)(&f.s2));
            ((owners::V_2fcaf0 *)&total)->FUN_002fcaf0((owners::V_2fcaf0 *)(SymMatrix *)(&f.s1));
        }
    }
    inertiaBody.m[0] = total.m[0];
    inertiaBody.m[1] = total.m[1];
    inertiaBody.m[2] = total.m[2];
    inertiaBody.m[3] = total.m[3];
    inertiaBody.m[4] = total.m[4];
    inertiaBody.m[5] = total.m[5];
    f.m = mat;
    ((owners::M_22c0b0 *)&(f.m))->FUN_0022c0b0();
    inertiaBody.FUN_002fcd60(&f.m);
    ((owners::Sym3_2fd0c0 *)&inertiaWorld)->FUN_002fd0c0((const owners::Sym3_2fd0c0 *)(SymMatrix *)(&total));
    ((owners::M_22c3b0 *)&mat)->FUN_0022c3b0((float *)(Vec3_310550 *)(&refPoint), (float *)(Vec3_310550 *)(&f.v));
    cx = f.v.x + cx;
    cy = f.v.y + cy;
    cz = f.v.z + cz;
    f.s2.FUN_002fcaa0();
    f.s1.FUN_002fcaa0();
}

} // namespace fn_fec45b2c

// 0x00310910 physics::ArticulatedPhysicsObject::vfunc_24 (235 B): equivalent/0x00310910.cpp
// sym: ?vfunc_24@ArticulatedPhysicsObject@physics@@UAE_NHHH@Z @37c0b276863c @w12d4490ded19
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// physics::ArticulatedPhysicsObject::vfunc_24 @ 0x00310910
bool physics::ArticulatedPhysicsObject::vfunc_24(hulk_intptr __p0, hulk_intptr __p1, int index) { const Vec3_310910 * point = (const Vec3_310910 *)__p0; Vec3_310910 * result = (Vec3_310910 *)__p1;

 bool changed=false;
 SimulatedObject_310910 *node=(*(SimulatedObject_310910 ** *)&this->f_1fc)[index];
 while(node) {
  if(node->count<=0) break;
  if(node->active) {
   Vec3_310910 delta; delta.x=point->x-node->position.x; delta.y=point->y-node->position.y; delta.z=point->z-node->position.z;
   Vec3_310910 velocity; node->vfunc_22(&velocity);
   volatile float z=velocity.x*delta.y-velocity.y*delta.x; // the original rounds z through its frame
   result->x += velocity.y*delta.z-velocity.z*delta.y;
   result->y += velocity.z*delta.x-velocity.x*delta.z;
   result->z += z;
   changed=true;
  }
  node=(*(SimulatedObject_310910 ** *)&this->f_1fc)[node->next];
 }
 return changed;
}


// 0x00310a00 physics::ArticulatedPhysicsObject::vfunc_25 (180 B): equivalent/0x00310a00.cpp [wrapped: conflict: physics::ArticulatedPhysicsObject; physics::PhysicsObject]
// sym: ?vfunc_25@ArticulatedPhysicsObject@physics@fn_00310a00@@QAE_NPAUVec_310a00@3@0H@Z @7972b07a4951 @w222e5c5e48a3
namespace fn_00310a00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// physics::ArticulatedPhysicsObject::vfunc_25 @ 0x00310a00
struct Vec_310a00 { float x,y,z; };
struct Body_310a00 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(Vec_310a00*);
 short unused; short active; char pad[0x78]; Vec_310a00 position;
};
namespace physics {
struct PhysicsObject { bool vfunc_25_002f5d20(Vec_310a00*,Vec_310a00*,int); };
struct ArticulatedPhysicsObject : PhysicsObject { char pad[0x1fc]; Body_310a00** bodies; bool vfunc_25(Vec_310a00*,Vec_310a00*,int); };
}
bool physics::ArticulatedPhysicsObject::vfunc_25(Vec_310a00* out,Vec_310a00* input,int index) {
 if(index<0) return PhysicsObject::vfunc_25_002f5d20(out,input,-1);
 if(bodies[index]->active>0) {
 bodies[index]->s22(input);
 Vec_310a00& p=bodies[index]->position;
 float y=p.x*input->z-p.z*input->x;
 float z=p.y*input->x-p.x*input->y;
 float x=input->y*p.z-input->z*p.y;
 out->x=x; out->y=y; out->z=z;
 } else { out->z=0;out->y=0;out->x=0;input->z=0;input->y=0;input->x=0; }
 return true;
}
} // namespace fn_00310a00


// 0x00310ac0 physics::ArticulatedPhysicsObject::vfunc_26 (5 B): matches/0x00310ac0.cpp
// sym: ?vfunc_26@ArticulatedPhysicsObject@physics@@UAE_NH@Z
// Same code shape as 0x00244f40 (propagated; names are from that function)
bool physics::ArticulatedPhysicsObject::vfunc_26(int a) {
    return false;
}


// 0x00310ad0 physics::ArticulatedPhysicsObject::vfunc_27 (82 B): equivalent/0x00310ad0.cpp
// sym: ?vfunc_27@ArticulatedPhysicsObject@physics@@UAEXH@Z @fa2386713729 @waf866161bb0d
// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 4/4)
// physics::ArticulatedPhysicsObject::vfunc_27 @ 0x00310ad0
void physics::ArticulatedPhysicsObject::vfunc_27(int index) {
    if (index == -1) {
        (*(int (*)[6])&this->f_14c)[0] = 0;
        (*(int (*)[6])&this->f_14c)[1] = 0;
        (*(int (*)[6])&this->f_14c)[2] = 0;
        (*(int (*)[6])&this->f_14c)[3] = 0;
        (*(int (*)[6])&this->f_14c)[4] = 0;
        (*(int (*)[6])&this->f_14c)[5] = 0;
        this->f_148 = 1;
    } else {
        Joint *joint = (*(Joint ** *)&this->f_1fc)[index];
        if (joint) joint->vfunc_3();
    }
}

namespace fn_fec45b2c {

// 0x00310b30 FUN_00310b30 (136 B): matches/0x00310b30.cpp
// sym: ?FUN_00310b30@ArticulatedPhysicsObject_310b30@fn_fec45b2c@@QAEXPAV12@HH@Z
// FUN_00310b30 @ 0x00310b30
void ArticulatedPhysicsObject_310b30::FUN_00310b30(ArticulatedPhysicsObject_310b30 *owner, int a, int b)
{
    if (a < 0)
        return;
    Node **table = nodes;
    first = table[a];
    if (owner != this)
        return;
    active = 1;
    Node *other = table[b];
    if (!other)
        return;
    if (first->key < other->key) {
        cursor = first;
    } else {
        cursor = other;
        other = first;
    }
    while (cursor) {
        if (((owners::Node_309b20 *)cursor)->FUN_00309b20((owners::Node_309b20 *)(Node *)other))
            return;
        cursor = cursor->next;
    }
}


// 0x00310bc0 FUN_00310bc0 (275 B): equivalent/0x00310bc0.cpp
// sym: ?FUN_00310bc0@Object@fn_fec45b2c@@QAEXHMPAUVec3_310bc0@2@@Z @a9367f0aac88 @w0c663b8cab90
// STATUS: equivalent (tools/equiv.py level 3: 190 inputs, branch coverage 4/4)
// FUN_00310bc0 @ 0x00310bc0
void Object::FUN_00310bc0(int index,float scale,Vec3_310bc0* direction) {
 Item_310bc0* item=items[index];
 Vec3_310bc0 position; position.x=item->offset.x+item->position.x; position.y=item->offset.y+item->position.y; position.z=item->offset.z+item->position.z;
 Vec3_310bc0 delta; delta.x=scale*direction->x; delta.y=scale*direction->y; delta.z=scale*direction->z;
 Work_310bc0 work; work.FUN_002fca90();
 slot17(&position,direction,0,index,-1);
 do { slot20(&position,&work,0,index,-1); } while (!slot18(&position,&delta,&work,0,index,-1));
 slot19(0,index,-1);
 work.FUN_002fcaa0();
}


// 0x00310d80 FUN_00310d80 (74 B): matches/0x00310d80.cpp
// sym: _FUN_00310d80
// Same code shape as 0x002feb70 (propagated; names are from that function)
extern "C" void __cdecl FUN_00310d80(unsigned int * p, int n, int limit, unsigned int value) {
    int parent = (n - 1) / 2;
    if (limit < n) {
        do {
            uint_310d80 x = p[parent];
            if (x >= value)
                break;
            p[n] = x;
            n = parent;
            parent = (n - 1) / 2;
        } while (limit < n);
    }
    p[n] = value;
}


// 0x00310dd0 FUN_00310dd0 (150 B): equivalent/0x00310dd0.cpp
// sym: ?FUN_00310dd0@fn_fec45b2c@@YAXPAH00@Z @fff34162d876 @w209cc2860326
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 17/18, incomplete)
// FUN_00310dd0 @ 0x00310dd0
// std::rotate for a range of 4-byte elements (cycle-leader algorithm)
void FUN_00310dd0(int *first, int *middle, int *last)
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
            int *hole = first + cycles;
            int *next = hole;
            int holeValue = *hole;
            int *next1 = (next + shift == last) ? first : next + shift;
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

} // namespace fn_fec45b2c

// 0x00310e70 physics::ArticulatedPhysicsObject::vfunc_2 (30 B): matches/0x00310e70.cpp
// sym: ??_GArticulatedPhysicsObject@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::ArticulatedPhysicsObject::~ArticulatedPhysicsObject() {}

namespace fn_fec45b2c {

// 0x00310e90 FUN_00310e90 (44 B): matches/0x00310e90.cpp
// sym: ?Set@Owner_310e90@fn_fec45b2c@@QAEXPAVThing_310e90@2@@Z
void Owner_310e90::Set(Thing_310e90* p) {
    if (p)
        p->A();
    if (member)
        member->B();
    member = p;
}


// 0x00310ec0 FUN_00310ec0 (392 B): equivalent/0x00310ec0.cpp
// sym: ?FUN_00310ec0@Tree_310ec0@fn_fec45b2c@@QAEXXZ @38a523c96c3f @w0d0ec04ff426
// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 22/26, incomplete)
// FUN_00310ec0 @ 0x00310ec0
void Tree_310ec0::FUN_00310ec0()
{
    int i;
    total = 0;   // zero bit pattern, stores of integer 0
    weight = 0;
    for (i = 0; i < nodeCount; i++) {
        Node* n = nodes[i];
        n->f34 = n->f30;
        n->f3c = n->f38;
        n->f4c = n->f68;
        n->f50 = n->f6c;
        n->f54 = n->f70;
        n->f58 = n->f74;
        n->f5c = n->f78;
        n->f60 = n->f7c;
        n->fF0 = (n->f60 + n->f58 + n->f4c) * (*(float*)&DAT_0040d258);
        if (n->active) {
            total = n->f34 + total;
            weight = weight + n->f3c;
        }
    }
    if (weight > (*(float*)&DAT_003f32e0)) {
        invWeight = (*(float*)&DAT_003f32dc) / weight;
        for (int k = nodeCount - 1; k >= 0; k--) {
            Node* s = nodes[k];
            for (unsigned j = 0; j < (unsigned)(s->childEnd - s->childBegin); j++) {
                Node* c = s->childBegin[j];
                if (c->kind == 0 && c->active) {
                    s->f34 = c->f34 + s->f34;
                    s->f3c = c->f3c + s->f3c;
                    s->fF0 = c->fF0 + s->fF0;
                    ((owners::V_2fcaf0 *)&(s->sub))->FUN_002fcaf0((owners::V_2fcaf0 *)(SubObj_310ec0 *)(&c->sub));
                }
            }
        }
    }
    for (i = 0; i < nodeCount; i++) {
        Node* n = nodes[i];
        if (n->f3c > (*(float*)&DAT_003f32e0))
            n->f40 = (*(float*)&DAT_003f32dc) / n->f3c;
    }
    cur = next;
    FUN_00310550();
}

// 0x00311050 thunk_FUN_00310ec0 (5 B): not yet verified
} // namespace fn_fec45b2c

// 0x00311060 FUN_00311060 (56 B): matches/0x00311060.cpp
// sym: ?FUN_00311060@C_311060@owners@@QAEXXZ
void owners::C_311060::FUN_00311060() {
    a = b;
    ((ThisCall_00310550*)(this))->FUN_00310550();
    b = 0x4e6e6b28;
    Sub_311060* p = (Sub_311060*)((char*)this + 0x168);
    p->second_00308ba0(0x3c83126f);
    p->third_00308b20();
}


// 0x003110a0 physics::ArticulatedPhysicsObject::vfunc_5 (332 B): equivalent/0x003110a0.cpp [wrapped: conflict: physics::ArticulatedPhysicsObject; physics::PhysicsObject]
// sym: ?vfunc_5@ArticulatedPhysicsObject@physics@fn_003110a0@@UAEXM@Z @8db74b25e217 @w714c9cce5485
namespace fn_003110a0 {
// STATUS: equivalent (tools/equiv.py level 3: 19796 inputs, branch coverage 12/12)
// physics::ArticulatedPhysicsObject::vfunc_5 @ 0x003110a0
class Child_3110a0 {
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
    virtual void vfunc_11(float a, float b, float dt);
};

struct Body_3110a0 {
    char pad0[0x5c];
    float spin[3];
    char pad68[0x94 - 0x68];
    unsigned char frozen;
};

namespace physics {
class PhysicsObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float dt);
};

class ArticulatedPhysicsObject : public PhysicsObject {
public:
    virtual void vfunc_5(float dt);
    char pad04[0xc];
    Body_3110a0 *body;
    char pad14[0xc0 - 0x14];
    float velocity[3];
    char padcc[0x1f8 - 0xcc];
    Child_3110a0 **children;
    char pad1fc[4];
    int childCount;
    char pad204[0x20c - 0x204];
    float elapsed;
    char pad210[0x224 - 0x210];
    float dt;
    float dampLinear;
    float dampAngular;
    float dampOverall;
};
}

void physics::ArticulatedPhysicsObject::vfunc_5(float dtArg)
{
    dt = dtArg;
    PhysicsObject::vfunc_5(dtArg);
    if (body->frozen != 0)
        return;

    float a = 1.0f - dtArg * dampLinear;
    if (!(0.0f < a))
        a = 0.0f;
    float b = 1.0f - dtArg * dampAngular;
    if (!(0.0f < b))
        b = 0.0f;
    hulk_freg c = 1.0f - dtArg * dampOverall;
    if (!(0.0f < c))
        c = 0.0f;

    velocity[0] = c * velocity[0];
    velocity[1] = c * velocity[1];
    velocity[2] = c * velocity[2];
    float *spin = body->spin;
    spin[0] = c * spin[0];
    spin[1] = c * spin[1];
    spin[2] = c * spin[2];

    for (int i = 0; i < childCount; i++)
        children[i]->vfunc_11(a, b, dtArg);

    elapsed = dt + elapsed;
}
} // namespace fn_003110a0

namespace fn_fec45b2c {

// 0x003111f0 FUN_003111f0 (117 B): matches/0x003111f0.cpp
// sym: ?Run@Obj_3111f0@fn_fec45b2c@@QAEXXZ
void Obj_3111f0::Run() {
    if (state->busy)
        return;
    for (int i = 0; i < count; i++) {
        H2_3111f0* h = helper->Get_0030f490(items[i]->id);
        items[i]->Use(h->Get_0030edf0()->Get_0030f100());
    }
    Tail_00310550();
}

} // namespace fn_fec45b2c

// 0x00311270 physics::ArticulatedPhysicsObject::vfunc_17 (142 B): matches/0x00311270.cpp [wrapped: conflict: physics::ArticulatedPhysicsObject]
// sym: ?vfunc_17@ArticulatedPhysicsObject@physics@fn_00311270@@UAEXHHHHH@Z
namespace fn_00311270 {
// data: zero_311270 = DAT_003f32e0

namespace physics {
class ArticulatedPhysicsObject {
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
    virtual void vfunc_17(int, int, int, int, int);
    char p[0x3c];
    float field40;
    char q[0x104];
    unsigned char f148;
    char r[0xb3];
    int* items;
    char s[0x14];
    int field214, field218;
    unsigned char f21c, f21d;
    void first_00310b30(int, int, int);
};
class Elem_311270 {
    char p[0xef];
    unsigned char enabled;

  public:
    void second_0030a270(int, int);
};
} // namespace physics
void physics::ArticulatedPhysicsObject::vfunc_17(int a1, int a2, int a3, int a4, int a5) {
    if (field40 != DAT_003f32e0) {
        f148 = 1;
        f21d = 0;
        if (a4 < 0 || !*((unsigned char*)((char*)items[a4] + 0xef))) {
            f148 = 1;
            return;
        }
        first_00310b30(a3, a4, a5);
        ((Elem_311270*)items[a4])->second_0030a270(a1, a2);
        field218 = 0;
        field214 = 0;
        f21c = 0;
    }
}
} // namespace fn_00311270


// 0x00311300 physics::ArticulatedPhysicsObject::vfunc_20 (167 B): matches/0x00311300.cpp [wrapped: conflict: physics::ArticulatedPhysicsObject; physics::PhysicsObject]
// sym: ?vfunc_20@ArticulatedPhysicsObject@physics@fn_00311300@@UAEXHPAUMat_311300@3@HHH@Z
namespace fn_00311300 {
// physics::ArticulatedPhysicsObject::vfunc_20 @ 0x00311300
struct Mat_311300 {
    void FUN_002fd0a0();
    void FUN_002fd0c0(Mat_311300 *m);
};

class Part_311300 {
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
    virtual void v13(int a, Mat_311300 *m);
    char pad04[0xef - 4];
    char enabled;             // 0xef
};

namespace physics {

class PhysicsObject {
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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20(int a, Mat_311300 *m, int c, int d, int e);
};

class ArticulatedPhysicsObject : public PhysicsObject {
public:
    virtual void vfunc_20(int a, Mat_311300 *m, int c, int index, int e);
    char pad04[0x40 - 4];
    float f40;                // 0x40
    char pad44[0x1fc - 0x44];
    Part_311300 **parts;             // 0x1fc
    char pad200[0x214 - 0x200];
    int f214;
    int f218;
    char f21c;
    void FUN_00310b30(int c, int index, int e);
};

void ArticulatedPhysicsObject::vfunc_20(int a, Mat_311300 *m, int c, int index, int e)
{
    if (f40 == 0.0f) {
        m->FUN_002fd0a0();
        return;
    }
    PhysicsObject::vfunc_20(a, m, c, -1, -1);
    if (index >= 0 && parts[index]->enabled) {
        m->FUN_002fd0c0(m);
        FUN_00310b30(c, index, e);
        parts[index]->v13(a, m);
        m->FUN_002fd0c0(m);
        f218 = 0;
        f214 = 0;
        f21c = 0;
    }
}

}
} // namespace fn_00311300


// 0x003113b0 physics::ArticulatedPhysicsObject::vfunc_18 (293 B): equivalent/0x003113b0.cpp [wrapped: conflict: physics::ArticulatedPhysicsObject; physics::PhysicsObject]
// sym: ?vfunc_18@ArticulatedPhysicsObject@physics@fn_003113b0@@QAE_NPAXPAUVector@3@00HH@Z @dbec3713f6d2 @w7d9b69df8492
namespace fn_003113b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// physics::ArticulatedPhysicsObject::vfunc_18 @ 0x003113b0
struct Vector { float x,y,z; };
struct Body_3113b0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual bool slot14(void*,Vector*,void*);
 char pad[0xeb]; unsigned char enabled;
};
namespace physics {
struct PhysicsObject {
 char pad[0x40]; float mass; char pad2[0x1b8]; Body_3113b0** bodies; char pad3[0x14]; unsigned int state214,state218; unsigned char state21c;
 bool vfunc_18_002f5c70(void*,Vector*,void*,void*,int,int);
};
struct ArticulatedPhysicsObject : PhysicsObject {
 void FUN_00310b30(void*,int,int);
 bool vfunc_18(void*,Vector*,void*,void*,int,int);
};
}
bool physics::ArticulatedPhysicsObject::vfunc_18(void* a,Vector* v,void* c,void* d,int index,int last) {
 if (!(mass > 0.0f)) return false;
 if(index < 0 || !bodies[index]->enabled) return PhysicsObject::vfunc_18_002f5c70(a,v,c,d,-1,-1);
 Vector copy = *v;
 FUN_00310b30(d,index,last);
 bool result = bodies[index]->slot14(a,&copy,c);
 state218 = 0; state214 = 0; state21c = 0;
 if(result && (copy.z*copy.z + copy.x*copy.x + copy.y*copy.y > 1e-05f))
 return PhysicsObject::vfunc_18_002f5c70(a,&copy,c,d,-1,-1);
 return result;
}
} // namespace fn_003113b0


// 0x003114e0 physics::ArticulatedPhysicsObject::vfunc_19 (376 B): equivalent/0x003114e0.cpp [wrapped: conflict: physics::ArticulatedPhysicsObject; physics::PhysicsObject]
// sym: ?vfunc_19@ArticulatedPhysicsObject@physics@fn_003114e0@@UAEXHHH@Z @0bb9bdcf5f48 @wd48636a8a53a
namespace fn_003114e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 20/20)
// physics::ArticulatedPhysicsObject::vfunc_19 @ 0x003114e0

struct Vec3_3114e0 { float x, y, z; };

struct Shape_3114e0 {
    char pad00[0x6c];
    int state;
    char pad70[0x94 - 0x70];
    char frozen;
};

struct Joint_3114e0 {
    void FUN_0030bf70();
};

struct Solver_3114e0 {
    void FUN_0030a7b0(Vec3_3114e0 a, Vec3_3114e0 b);
    void FUN_0030a9d0(Vec3_3114e0 a, Vec3_3114e0 b, int flag);
};

struct Chain_3114e0 {
    char pad00[0x34];
    void FUN_002fd020(float* in, Vec3_3114e0* out);
};


namespace physics {

class ArticulatedPhysicsObject;

class PhysicsObject {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
    virtual void vfunc_19(int a, int b, int c);
};

class ArticulatedPhysicsObject : public PhysicsObject {
public:
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26();
    virtual void vfunc_27(int a);
    char pad04[0x10 - 4];
    Shape_3114e0* shape;
    char pad14[0x114 - 0x14];
    Chain_3114e0 chain;
    char noChain;
    char pad149[3];
    Vec3_3114e0 anchor;
    float v158[3];
    char pad164[0x1f8 - 0x164];
    Solver_3114e0** solver;
    char pad1fc[0x214 - 0x1fc];
    int cur214;
    Joint_3114e0* joint;
    char flag21c;
    char done;
    char pad21e[0x234 - 0x21e];
    char enabled;
    void FUN_00310b30(ArticulatedPhysicsObject* who, int idx, int idx2);
    void vfunc_19(int a1, int a2, int a3);
};

void ArticulatedPhysicsObject::vfunc_19(int a1, int a2, int a3)
{
    if (done)
        return;
    if (shape->state != 1)
        vfunc_27(-1);
    if (!shape->frozen && a2 >= 0) {
        if (!(*(char*)&DAT_004d3388) || !enabled)
            a1 &= ~0xff;
        FUN_00310b30(a3 >= 0 ? this : 0, a2, a3);
        if (joint) {
            joint->FUN_0030bf70();
        } else {
            Vec3_3114e0 v;
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            if (!noChain)
                chain.FUN_002fd020(v158, &v);
            if (!(char)a1) {
                (*solver)->FUN_0030a7b0(anchor, v);
            } else {
                (*solver)->FUN_0030a9d0(anchor, v, 1);
            }
        }
        joint = 0;
        cur214 = 0;
        flag21c = 0;
    }
    PhysicsObject::vfunc_19(a1, -1, -1);
    done = 1;
}

}
} // namespace fn_003114e0

namespace fn_fec45b2c {

// 0x00311740 FUN_00311740 (90 B): matches/0x00311740.cpp
// sym: _FUN_00311740
// Same code shape as 0x002ff860 (propagated; names are from that function)
extern "C" void FUN_00311740(unsigned int* data, int index, int count, unsigned int value) {
    int orig = index;
    int child = index * 2 + 2;
    if (child < count) {
        do {
            unsigned int v = data[child];
            if (v < data[child - 1])
                --child;
            v = data[child];
            data[index] = v;
            index = child;
            child = child * 2 + 2;
        } while (child < count);
    }
    if (child == count) {
        data[index] = data[count - 1];
        index = count - 1;
    }
    FUN_00310d80(data, index, orig, value);
}


// 0x003117f0 FUN_003117f0 (287 B): equivalent/0x003117f0.cpp
// sym: ?FUN_003117f0@fn_fec45b2c@@YAXPAI00@Z @b90cbbcfac42 @w6c01c9ee97d2
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 32/32)
// FUN_003117f0 @ 0x003117f0
void __cdecl FUN_003117f0(UInt* first, UInt* middle, UInt* last)
{
    hulk_intptr distance = last - first;
    UInt a, b;
    if (distance > 40) {
        hulk_intptr step = (distance + 1) / 8;
        UInt* leftMedian = first + step;
        UInt* leftEnd = first + 2 * step;
        a = *leftMedian; b = *first;
        if (a < b) { *leftMedian = b; *first = a; }
        a = *leftEnd; b = *leftMedian;
        if (a < b) { *leftEnd = b; *leftMedian = a; }
        a = *leftMedian; b = *first;
        if (a < b) { *leftMedian = b; *first = a; }
        UInt* midStart = middle - step;
        UInt* midEnd = middle + step;
        a = *middle; b = *midStart;
        if (a < b) { *middle = b; *midStart = a; }
        a = *midEnd; b = *middle;
        if (a < b) { *midEnd = b; *middle = a; }
        a = *middle; b = *midStart;
        if (a < b) { *middle = b; *midStart = a; }
        UInt* rightMedian = last - step;
        UInt* rightStart = last - 2 * step;
        a = *rightMedian; b = *rightStart;
        if (a < b) { *rightMedian = b; *rightStart = a; }
        a = *last; b = *rightMedian;
        if (a < b) { *last = b; *rightMedian = a; }
        a = *rightMedian; b = *rightStart;
        if (a < b) { *rightMedian = b; *rightStart = a; }
        a = *middle; b = *leftMedian;
        if (a < b) { *middle = b; *leftMedian = a; }
        a = *rightMedian; b = *middle;
        if (a < b) { *rightMedian = b; *middle = a; }
        a = *middle; b = *leftMedian;
        if (a < b) { *middle = b; *leftMedian = a; }
    } else {
        a = *middle; b = *first;
        if (a < b) { *middle = b; *first = a; }
        a = *last; b = *middle;
        if (a < b) { *last = b; *middle = a; }
        a = *middle; b = *first;
        if (a < b) { *middle = b; *first = a; }
    }
}


// 0x00311910 FUN_00311910 (57 B): matches/0x00311910.cpp
// sym: ?FUN_00311910@fn_fec45b2c@@YAXPAH0@Z
void __cdecl FUN_00311910(int* first, int* last) {
    hulk_intptr n = last - first;
    hulk_intptr i = n / 2;
    while (i > 0) {
        FUN_00311740((unsigned int *)(int *)first, (hulk_intptr)(--i), (hulk_intptr)n, (int)(first[i]));
    }
}


// 0x003119b0 FUN_003119b0 (310 B): equivalent/0x003119b0.cpp
// sym: _FUN_003119b0 @266cf5ad0e36 @wc42a98a394c7
// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 36/42, incomplete)
// FUN_003119b0 @ 0x003119b0
// std::_Unguarded_partition for unsigned int* (three-way split around a median pivot).
extern "C" void *__cdecl FUN_003119b0(void *out, unsigned int *first, unsigned int *last)
{
    unsigned int *mid = first + (last - first) / 2;
    FUN_003117f0(first, mid, last - 1);

    unsigned int *pfirst = mid;
    unsigned int *plast = pfirst + 1;
    while (first < pfirst && !(*(pfirst - 1) < *pfirst) && !(*pfirst < *(pfirst - 1)))
        --pfirst;
    while (plast < last && !(*plast < *pfirst) && !(*pfirst < *plast))
        ++plast;

    unsigned int *gfirst = plast;
    unsigned int *glast = pfirst;
    unsigned int t;

    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (*pfirst < *gfirst)
                ;
            else if (*gfirst < *pfirst)
                break;
            else {
                t = *plast;
                *plast = *gfirst;
                *gfirst = t;
                ++plast;
            }
        }
        for (; first < glast; --glast) {
            if (*(glast - 1) < *pfirst)
                ;
            else if (*pfirst < *(glast - 1))
                break;
            else {
                --pfirst;
                t = *pfirst;
                *pfirst = *(glast - 1);
                *(glast - 1) = t;
            }
        }
        if (glast == first && gfirst == last) {
            ((UIntRange_3119b0 *)out)->first = pfirst;
            ((UIntRange_3119b0 *)out)->second = plast;
            return (UIntRange_3119b0 *)((UIntRange_3119b0 *)out);
        }
        if (glast == first) {
            if (plast != gfirst) {
                t = *pfirst;
                *pfirst = *plast;
                *plast = t;
            }
            ++plast;
            t = *pfirst;
            *pfirst = *gfirst;
            *gfirst = t;
            ++pfirst;
            ++gfirst;
        } else if (gfirst == last) {
            --glast;
            --pfirst;
            if (glast != pfirst) {
                t = *glast;
                *glast = *pfirst;
                *pfirst = t;
            }
            --plast;
            t = *pfirst;
            *pfirst = *plast;
            *plast = t;
        } else {
            --glast;
            t = *gfirst;
            *gfirst = *glast;
            *glast = t;
            ++gfirst;
        }
    }
}


// 0x00311b20 FUN_00311b20 (112 B): matches/0x00311b20.cpp
// sym: _FUN_00311b20
extern "C" void FUN_00311b20(unsigned* first, unsigned* last) {
    if (first == last)
        return;
    unsigned* i = first + 1;
    while (i != last) {
        unsigned v = *i;
        if (v < *first) {
            if (first != i && i != i + 1)
                Rot(first, i, i + 1, 0, 0);
        } else if (v < *(i - 1)) {
            unsigned* p = i - 1;
            unsigned* q;
            do {
                q = p;
                p--;
            } while (v < *p);
            if (q != i && i != i + 1)
                Rot(q, i, i + 1, 0, 0);
        }
        i++;
    }
}


// 0x00311bd0 FUN_00311bd0 (67 B): equivalent/0x00311bd0.cpp
// sym: _FUN_00311bd0 @340c3ea078a2 @w47c86de70fe6
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00311bd0 @ 0x00311bd0
extern "C" void __cdecl FUN_00311bd0(int* first, int* last) {
    hulk_intptr count = last - first;
    while (count > 1) {
        int value = first[count - 1];
        first[count - 1] = first[0];
        FUN_00311740((unsigned int *)(int *)first, 0, (hulk_intptr)(count - 1), (int)value);
        --count;
    }
}

} // namespace fn_fec45b2c

// 0x00311c20 FUN_00311c20 (203 B): equivalent/0x00311c20.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00311c20 @49294b19dc88 @w4b37aba64d9a
namespace fn_00311c20 {
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_00311c20 @ 0x00311c20
struct Partition { int* first; int* second; };
extern "C++" __declspec(nothrow) void * __cdecl FUN_003119b0(void *, unsigned int *, unsigned int *);
extern "C++" __declspec(nothrow) void __cdecl FUN_00311b20(unsigned *, unsigned *);
void __cdecl FUN_00311910(int* begin, int* end, int a, int b);
extern "C++" __declspec(nothrow) void __cdecl FUN_00311bd0(int *, int *);
extern "C" void __cdecl FUN_00311c20(int* begin, int* end, int depth) {
    while (end - begin > 32) {
        if (depth <= 0) {
            if (((hulk_intptr)end - (hulk_intptr)begin & ~3) > 4)
                FUN_00311910(begin, end, 0, 0);
            FUN_00311bd0(begin, end);
            return;
        }
        Partition split;
        FUN_003119b0((Partition *)(&split), (unsigned int *)(int *)begin, (unsigned int *)(int *)end);
        depth /= 2;
        depth += depth / 2;
        if ((((hulk_intptr)split.first - (hulk_intptr)begin) & ~3) < (((hulk_intptr)end - (hulk_intptr)split.second) & ~3)) {
            FUN_00311c20(begin, split.first, depth);
            begin = split.second;
        } else {
            FUN_00311c20(split.second, end, depth);
            end = split.first;
        }
    }
    if (end - begin > 1) FUN_00311b20((unsigned *)(int *)begin, (unsigned *)(int *)end);
}
} // namespace fn_00311c20

namespace fn_fec45b2c {

// 0x00311d50 FUN_00311d50 (985 B): equivalent/0x00311d50.cpp
// sym: ?FUN_00311d50@SkeletonBuilder@fn_fec45b2c@@QAEXXZ @d15c02d92f69 @wb100e86b1408
// STATUS: equivalent (tools/equiv.py level 3: 212 inputs, branch coverage 64/68, incomplete)
// FUN_00311d50 @ 0x00311d50
void SkeletonBuilder::FUN_00311d50()
{
    SkeletonData_311d50 *data = source->data;
    if (table != 0) {
        for (int i = 0; i < count; i++) {
            int id = list[i]->id;
            X_311d50 *x = source->FUN_0030f490(id);
            void **vt = VtableOf(table[id]);
            Z *z = x->FUN_0030edf0()->FUN_0030f100();
            ((BoneSlot10)vt[10])(table[id], 0, z);
        }
        FUN_00310ec0();
        return;
    }
    capacity = ((owners::C_30f450 *)source)->FUN_0030f450();
    Bone_311d50 **mem = (Bone_311d50 **)FUN_0008d6d0(capacity * sizeof(Bone_311d50 *));
    table = mem;
    memset(mem, 0, capacity * 4);
    for (int i = 0; i < count; i++) {
        Bone_311d50 *b = list[i];
        table[b->id] = b;
    }
    int *counts = (int *)FUN_00266e00(1, capacity * 4);
    memset(counts, 0, capacity * 4);
    for (int i = 0; i < count; i++) {
        int id = list[i]->id;
        int p = data->parent[id];
        for (;;) {
            if (table[p] != 0 && id != p) {
                counts[p]++;
                break;
            }
            p = data->parent[p];
            if (p <= 0) {
                break;
            }
        }
        if (i > 0 && p == 0 && table[0] != 0 && list[i]->parent == 0) {
            counts[0]++;
        }
    }
    for (int i = 0; i < count; i++) {
        Bone_311d50 *b = table[list[i]->id];
        int n = counts[list[i]->id];
        Bone_311d50 **begin;
        if (n != 0) {
            begin = (Bone_311d50 **)FUN_0008d6d0(n * sizeof(Bone_311d50 *));
            b->childBegin = begin;
            if (begin != 0) {
                b->childCapEnd = begin + n;
            } else {
                begin = 0;
                b->childCapEnd = 0;
            }
        } else {
            b->childBegin = 0;
            begin = 0;
            b->childCapEnd = 0;
        }
        b->childEnd = begin;
    }
    FUN_00267090(counts);
    for (int i = 0; i < count; i++) {
        Bone_311d50 *b = list[i];
        int id = b->id;
        int p = data->parent[id];
        b->parentIndex = p;
        for (;;) {
            if (table[p] != 0 && id != p) {
                Bone_311d50 *par = table[p];
                list[i]->parent = par;
                Bone_311d50 *owner = table[p];
                if (owner->childEnd < owner->childCapEnd) {
                    Bone_311d50 **e = owner->childEnd;
                    owner->childEnd = e + 1;
                    if (e != 0) {
                        *e = list[i];
                    }
                }
                owner = table[p];
                FUN_00311c20((int *)(Bone_311d50 * *)(owner->childBegin), (int *)(Bone_311d50 * *)(owner->childEnd), (hulk_intptr)(owner->childEnd - owner->childBegin));
                break;
            }
            p = data->parent[p];
            if (p <= 0) {
                break;
            }
        }
        if (i > 0 && p == 0 && table[0] != 0 && list[i]->parent == 0) {
            Bone_311d50 *root = table[0];
            list[i]->parent = root;
            root = table[0];
            if (root->childEnd < root->childCapEnd) {
                Bone_311d50 **e = root->childEnd;
                root->childEnd = e + 1;
                if (e != 0) {
                    *e = list[i];
                }
            }
            root = table[0];
            FUN_00311c20((int *)(Bone_311d50 * *)(root->childBegin), (int *)(Bone_311d50 * *)(root->childEnd), (hulk_intptr)(root->childEnd - root->childBegin));
        }
        Bone_311d50 *cur = list[i];
        if (cur->weight > 0.0f || (cur->parent != 0 && cur->parent->marked == 1)) {
            cur->marked = 1;
        }
        X_311d50 *x = source->FUN_0030f490(id);
        void **vt = VtableOf(table[id]);
        Z *z = x->FUN_0030edf0()->FUN_0030f100();
        ((BoneSlot10)vt[10])(table[id], 0, z);
    }
    FUN_00310ec0();
}


// 0x00312130 FUN_00312130 (259 B): equivalent/0x00312130.cpp
// sym: ?FUN_00312130@Obj_312130@fn_fec45b2c@@QAEXPAU12@PAUContext@2@@Z @1eda7e881b85 @w847ac4b5a57f
// STATUS: equivalent (tools/equiv.py level 3: 454 inputs, branch coverage 8/8)
// FUN_00312130 @ 0x00312130
void Obj_312130::FUN_00312130(Obj_312130* dst, Context* context) {
 FUN_002f75d0(dst,context);
 dst->count=count;
 if(count>0) dst->children=(Child_312130 **)FUN_0008d6d0((unsigned)count * sizeof(Child_312130 *));
 for(int i=0;i<count;++i) {
   Child_312130* result=children[i]->Clone();
   dst->children[i]=result;
   ((owners::C_30a260 *)(dst->children[i]))->FUN_0030a260((hulk_intptr)(Obj_312130 *)dst);
 }
 dst->field20c=0;
 dst->ref208=context->ref;
 dst->ref208->AddRef();
 dst->ref220=ref220;
 if(dst->ref220) dst->ref220->AddRef();
 dst->FUN_00311d50();
 dst->field228=field228;
 dst->field22c=field22c;
 int value=field230;
 dst->field214=0;
 dst->field218=0;
 dst->field230=value;
 dst->field21c=0;
 dst->field21d=1;
 field224=0;
}


// 0x00312240 FUN_00312240 (93 B): matches/0x00312240.cpp
// sym: ?Set@Owner_312240@fn_fec45b2c@@QAEXPAVItem_312240@2@@Z
void Owner_312240::Set(Item_312240* next) {
    Item_312240* old = item;
    if (!next) {
        if (old)
            old->Release();
        item = 0;
        return;
    }
    if (next != old) {
        if (old)
            old->Release();
        item = next;
        next->Use();
        HelperA_00311d50();
        HelperB_003111f0();
        Notify();
    }
}

} // namespace fn_fec45b2c

// 0x003122a0 physics::ArticulatedPhysicsObject::vfunc_28 (83 B): matches/0x003122a0.cpp
// sym: ?vfunc_28@ArticulatedPhysicsObject@physics@@UAEPAXI@Z
void* physics::ArticulatedPhysicsObject::vfunc_28(unsigned int a) {
    void* p = alloc(0x238);
    if (p) {
        ((Helper_3122a0*)p)->Init_002f5480();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0043217c);
        *(unsigned int*)((char*)p + 0x1fc) = 0;
        *(unsigned int*)((char*)p + 0x24) = 1;
    } else {
        p = 0;
    }
    ((ArticulatedPhysicsObject_nv_3122a0*)this)->Setup_00312130(p, a);
    *(unsigned int*)((char*)p + 0x24) = *(unsigned int*)((char*)&this->f_24);
    return (void*)((physics::ArticulatedPhysicsObject*)p);
}

