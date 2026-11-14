// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d64c0..0x001d7890 (kind game, layer game, confidence high), dominant class CSPHulkPropInstance
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fff2a2ba {
#define TREE_TU_END }
namespace fn_fff2a2ba {} using namespace fn_fff2a2ba;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fff2a2ba {
extern unsigned __int64 __cdecl FUN_0027afb0(const char*);
struct Input_1d64c0 { bool FUN_00092940(int); };
struct Manager_1d64c0 {  };
} // namespace fn_fff2a2ba
struct World { char pad[0x54]; Manager_1d64c0* manager; };
namespace fn_fff2a2ba {
struct Identity { char pad[8]; uint low, high; };
class C_1d6640 {
  public:
    char pad0[0x40];
    int a;
    char pad44[0xa8];
    C_1d6640* p;
    int Fng_001d5f40(int);
    int target();
};
struct Obj_1d6670 {
    char pad0[0x40];
    int value;
    char pad1[0xa8];
    void* context;
};
struct CSPHulkPropInstance_nv_1d6670 {
    int Get_001d5e80(int);
};
extern const float g_one_1d6670;
extern const float g_hundredth;
extern const float g_factor;
struct Vec_1d66b0 { float x,y,z; };
struct Transform_1d66b0 { char rotation[48]; Vec_1d66b0 position; unsigned int tail; void FUN_0022b980(); };
struct Orientation_1d66b0 { bool FUN_0022d2b0(Vec_1d66b0*,float); };
struct Handle_1d66b0 { unsigned int a,b; };
struct Manager_1d66b0 { void FUN_00283a40(Handle_1d66b0*,Transform_1d66b0*,float,float); };
extern "C" Manager_1d66b0* __cdecl FUN_0027f250();
extern "C" void __cdecl FUN_00224db0(Transform_1d66b0*,Vec_1d66b0*,Orientation_1d66b0*);
struct GraphEntry {
    int pad0;
    int pad4;
    int type;
    int value;
};
struct GraphNode {
    char pad00[0x24];
    int count;
    GraphEntry *entries;
};
struct Graph_1d6770 {
    GraphNode *FUN_001d56f0(int id);
    int FUN_001d5710();
};
struct Listener_1d6770 {
    void FUN_002fc670(int v);
};
class StateWalker {
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
    virtual void vfunc_16(int state, int flag);
    char pad04[0x40 - 4];
    int current;
    char pad44[0xa0 - 0x44];
    Listener_1d6770 *listener;
    char pada4[0xec - 0xa4];
    Graph_1d6770 *graph;
    void FUN_001d6770();
};
class C_1d68d0 {
  public:
    char pad[0x11c];
    int* p;
};
extern const char s1_1d68e0[];
class B_1d6980 {
  public:
};
class A_1d6980 {
  public:
    char pad[0xec];
    B_1d6980* p;
    int F();
};
class B_1d6990 {
  public:
};
class A_1d6990 {
  public:
    char pad[0xec];
    B_1d6990* p;
    int F();
};
struct V3_1d69f0 { float x, y, z; };
struct Matrix {
};
struct Bone_1d69f0 {
    char pad0[0x30];
    V3_1d69f0 pos;
    int pad3c;
};
struct BoneTable_1d69f0 {
    char pad0[0x1c];
    Bone_1d69f0 *bones;
};
class BoneSource_1d69f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual BoneTable_1d69f0 *v11();
};
class BoneIndexer { public:  };
class Skeleton {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual Matrix *v15();
    char pad04[0x9c - 4];
    BoneSource_1d69f0 *source;
    char padA0[0xec - 0xa0];
    BoneIndexer *indexer;
    void FUN_001d69f0(V3_1d69f0 *out);
};
class A_1d6a80 {
  public:
    char pad[0x120];
    int value;
};
class Target_1d6ab0 {
    char pad[0x111];

  public:
    unsigned char value;
};
struct Fallback {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
};
struct Obj_1d6b40 {
    char pad0[0xa0];
    void* pA0;
    char padA4[0x78];
    Fallback* fb;
};
extern int __fastcall FUN_002fc6f0(void* p);
struct Block_1d6b60 {
    unsigned long v[16];
};
class Inner_1d6b60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(Block_1d6b60 b);
};
class Store {
  public:
    void F670_002fc670(int x);
    void F700_002fc700(Block_1d6b60* b, unsigned long x);
};
class Obj_1d6b60 {
  public:
    char p[0xa0];
    Store* store;
    char q[0x78];
    Inner_1d6b60* inner;
    char r[0x38];
    unsigned long x, y, z;
    void F7dde0_0027dde0(Block_1d6b60* b);
    void run(Block_1d6b60 b, unsigned long arg);
};
struct Target_1d6c50 {
    char pad[0x250];
    unsigned int value;
};
class Target_1d6c90 {
    char pad[0x258];

  public:
    unsigned int value;
};
struct Thing_1d6cb0 {
    char pad[0x25c];
};
class C_1d6cd0 {
  public:
    char pad[0x270];
    float value;
};
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
struct A_1d6ce0 {
    bool run_001d4df0();
};
struct B_1d6ce0 {
    bool run_00099790();
};
struct G_1d6ce0 {
    char pad[8];
    B_1d6ce0* p;
};
extern G_1d6ce0* hulk_at_004dd700;
struct Table_1d7100 {
    char pad[0x1c];
    int* entries;
};
struct Obj_1d7100 {
    char pad0[0x40];
    int index;
    char pad1[0x54];
    Table_1d7100* table;
    int Find(int);
};
struct Id_1d7150 {
    unsigned int lo;
    unsigned int hi;
};
struct Counter_1d7150 {
    int FUN_001d5710();
};
struct Item_1d7150 {
    char pad00[8];
    unsigned int lo;
    unsigned int hi;
};
struct ItemList_1d7150 {
    char pad00[0x1c];
    Item_1d7150 **items;
};
class Manager_1d7150 {
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
    virtual void Select(int index, int flag);
    char pad04[0x94];
    ItemList_1d7150 *list;
    char pad9c[0xec - 0x9c];
    Counter_1d7150 *counter;
    bool SelectById(int id);
};
class Helper_1d72a0 {
  public:
};
class Other_1d72a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* Get();
};
struct Obj_1d72a0 {
    char pad[0xa0];
    Helper_1d72a0* p;
    char pad2[0x78];
    Other_1d72a0* other;
    char pad3[0x44];
    unsigned a, b, c;
};
class Obj_1d7300 {
  public:
    char pad[0xa0];
    void* a;
};
class Item_1d7330 {
  public:
    virtual void F0();
    virtual void F1();
};
class Owner_1d7330 {
  public:
    char pad[0x134];
    Item_1d7330* item;
    void Set(Item_1d7330* p);
};
struct Vec3Bits {
    int x, y, z;
};
struct Vec4Bits {
    int x, y, z, w;
};
class Source_1d7360 {
public:
    char pad0[0x2c];
    Vec4Bits value;
};
class Leaf {
public:
    char pad0[0x34];
    int weight;
};
class Mid_1d7360 {
public:
    char pad0[0x20];
    Leaf* leaf;
};
class Link_1d7360 {
public:
    char pad0[0x74];
    Mid_1d7360* mid;
};
class Parent_1d7360 {
public:
    char pad0[0x10];
    Link_1d7360* link;
};
class Result_1d7360 {
public:
};
class Node {
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
    virtual Result_1d7360* Transform();
    char pad4[0x9c - 4];
    Source_1d7360* source;
    Parent_1d7360* parent;

    bool FUN_001d7360(Vec4Bits* out);
};
struct Val_1d73f0 {
    char pad[0x18];
    float value;
};
struct Global_1d73f0 {
    char pad[0x24];
    Val_1d73f0* p;
};
extern Global_1d73f0* g_1d73f0;
class Helper_1d73f0 {
  public:
};
class Other_1d73f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3a();
    virtual int f4();
};
struct CSPHulkPropInstance_nv_1d73f0 {
    int run_001d5d20(int);
};
class Self_1d73f0 {
  public:
    char p0[0x40];
    int arg;
    char p1[0xa0 - 0x44];
    Helper_1d73f0* a;
    char p2[0xec - 0xa4];
    CSPHulkPropInstance* d;
    char p3[0x11c - 0xf0];
    Other_1d73f0* b;
};
class Ref_1d7460 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_1d7460 {
    char pad[0x1dc];
    Ref_1d7460* p;

  public:
    void Set(Ref_1d7460*);
};
class Ref_1d7490 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Owner_1d7490 {
  public:
    char pad[0x11c];
    Ref_1d7490* value;
    void Set(Ref_1d7490* p);
};
class First_1d74c0 {
  public:
    virtual void A();
};
class Second_1d74c0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1d74c0 {
  public:
    char pad[0x120];
    First_1d74c0* ptr;
    int a;
    int b;
    unsigned char c;
    void whatever(First_1d74c0*, int, int, unsigned char);
};
class Res_1d7510 {
  public:
    void Release_002fc670(int);
};
class Y_1d7510 {
  public:
    void Go_00065ee0(float* v);
};
Y_1d7510* __stdcall GetY_000678d0();
class Fn_1d7510 {
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
    virtual float Get();
};
struct B_1d7510 {
    char p[0x10];
};
struct Mid_1d7510 {
    char p[0x10];
    Fn_1d7510* c70;
};
struct Mid2 {
    char p[0x70];
    Fn_1d7510* f;
};
struct Link_1d7510 {
    char p[0x10];
    Mid2* m;
};
class W_1d7510 {
  public:
    char p0[8];
    float x, y;
    char p1[0x90];
    Link_1d7510* l;
    char p2[0x148];
    char flag;
    void F();
};
class Inner_1d7590 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    void helper_002ef8b0(int);
};
struct Wrap_1d7590 {
    char pad[0x10];
    Inner_1d7590* ptr;
};
class Outer_1d7590 {
  public:
    char pad[0xa0];
    Wrap_1d7590* ptr;
    void run();
};
struct Vec {
    char pad[0x1c];
    int* begin;
    int* end;
};
class Obj {
    char pad[0x98];
    Vec* v;
    char pad2[0x10];
    void** items;

  public:
    void* Get(int index);
};
struct Result { char pad[0x50]; char data; };
struct Container { char pad[0x10]; Result *result; };
struct Object {
  public:
    char _m_pad_0[0x9c];
    Identity* identity;
    Container *container;
    char _m_pad_a4[0xa9];
    unsigned char flag;
    char _m_pad_14e[0xf2];
    Handle_1d66b0 handle;
    int FUN_001d64c0();
    void target(Vec_1d66b0*,Orientation_1d66b0*);
    void *FUN_001d77c0();
};
struct Mat_1d7810 {
    float m[12];
    float x, y, z, w;
};
struct O_1d7810 {
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
    virtual Mat_1d7810* GetMat();
    char pad[0x154 - 0x40 + 0x40];
    float px, py, pz;
    void Fn(float x, float y, float z);
    void Apply_001d6b60(Mat_1d7810 m, int f);
};


// 0x001d64c0 FUN_001d64c0 (275 B): equivalent/0x001d64c0.cpp
// sym: ?FUN_001d64c0@Object@fn_fff2a2ba@@QAEHXZ @4f0b5bbf4a59 @w8d18c6953d02
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_001d64c0 @ 0x001d64c0
int Object::FUN_001d64c0() {
 unsigned __int64 value;
 if (!((*(uint*)&DAT_004e25e8) & 1)) { (*(uint*)&DAT_004e25e8) |= 1; value=FUN_0027afb0("miss_soldier_miss_soldier_grp"); (*(uint*)&DAT_004e25e0)=(uint)value; (*(uint*)&DAT_004e25e4)=(uint)(value>>32); }
 if (!((*(uint*)&DAT_004e25e8) & 2)) { (*(uint*)&DAT_004e25e8) |= 2; value=FUN_0027afb0("cow_male_cow_male"); (*(uint*)&DAT_004e25d8)=(uint)value; (*(uint*)&DAT_004e25dc)=(uint)(value>>32); }
 if (!((*(uint*)&DAT_004e25e8) & 4)) { (*(uint*)&DAT_004e25e8) |= 4; value=FUN_0027afb0("mlrsMissileLarge_mlrsMissileLarge"); (*(uint*)&DAT_004e25d0)=(uint)value; (*(uint*)&DAT_004e25d4)=(uint)(value>>32); }
 bool active=((Input_1d64c0 *)((owners::A_86340 *)(DAT_004dd700->manager))->FUN_00086340())->FUN_00092940(0x2f);
 uint low=identity->low, high=identity->high;
 if (low==(*(uint*)&DAT_004e25e0) && high==(*(uint*)&DAT_004e25e4)) return 1;
 if (low==(*(uint*)&DAT_004e25d0) && high==(*(uint*)&DAT_004e25d4)) return 1;
 if (active && !flag && low==(*(uint*)&DAT_004e25d8) && high==(*(uint*)&DAT_004e25dc)) return 1;
 return 0;
}

} // namespace fn_fff2a2ba

// 0x001d65f0 CSPHulkPropInstance::vfunc_16 (58 B): matches/0x001d65f0.cpp [wrapped: conflict: CSPHulkPropInstance]
// sym: ?vfunc_16@CSPHulkPropInstance@fn_001d65f0@@UAEXHH@Z
namespace fn_001d65f0 {
class StateProp {
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
    virtual void vfunc_16(int, int);
};
class CSPHulkPropInstance : public StateProp {
  public:
    char pad[0x3c];
    int field40;
    virtual void vfunc_16(int, int);
};
class Manager_1d65f0 {
  public:
    void helper_001ebd80(CSPHulkPropInstance*, const char*, int, int);
};
struct Root_1d65f0 {
    char pad[0x34];
    Manager_1d65f0* mgr;
};
extern Root_1d65f0* gManager_1d65f0;
void CSPHulkPropInstance::vfunc_16(int a, int b) {
    StateProp::vfunc_16(a, b);
    if (field40 == 0)
        gManager_1d65f0->mgr->helper_001ebd80(this, "State_0", 0x42480000, 0);
}
} // namespace fn_001d65f0

// 0x001d6630 thunk_FUN_0027d410 (5 B): not yet verified
namespace fn_fff2a2ba {

// 0x001d6640 FUN_001d6640 (16 B): matches/0x001d6640.cpp
// sym: ?target@C_1d6640@fn_fff2a2ba@@QAEHXZ
int C_1d6640::target() {
    return p->Fng_001d5f40(a);
}

} // namespace fn_fff2a2ba

// 0x001d6650 FUN_001d6650 (13 B): matches/0x001d6650.cpp
// sym: ?FUN_001d6650@Object_1d6650@owners@@QAEXH@Z
void owners::Object_1d6650::FUN_001d6650(hulk_intptr value) {
    this->value = ((int)value);
}


// 0x001d6660 FUN_001d6660 (7 B): matches/0x001d6660.cpp
// sym: ?FUN_001d6660@C_1d6660@owners@@QAEIXZ
hulk_uintptr owners::C_1d6660::FUN_001d6660() {
    return value;
}

namespace fn_fff2a2ba {

// 0x001d6670 FUN_001d6670 (51 B): matches/0x001d6670.cpp
// sym: ?FUN_001d6670@fn_fff2a2ba@@YIMPAUObj_1d6670@1@@Z
hulk_freg __fastcall FUN_001d6670(Obj_1d6670* self) {
    int result = ((CSPHulkPropInstance_nv_1d6670*)(((CSPHulkPropInstance*)self->context)))->Get_001d5e80(self->value);
    bool scale = result == 2;
    hulk_freg value = 1.0f;
    if (result == 3)
        value = 0.01f;
    if (scale)
        value *= 0.025f;
    return value;
}


// 0x001d66b0 FUN_001d66b0 (191 B): equivalent/0x001d66b0.cpp
// sym: ?target@Object@fn_fff2a2ba@@QAEXPAUVec_1d66b0@2@PAUOrientation_1d66b0@2@@Z @1afd0c0cb842 @w42135c90085c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001d66b0 @ 0x001d66b0
void Object::target(Vec_1d66b0* position, Orientation_1d66b0* orientation) {
 if (handle.a || handle.b) {
  Manager_1d66b0* manager=FUN_0027f250();
  Transform_1d66b0 transform;
  transform.FUN_0022b980();
  Vec_1d66b0 up; up.x=0.0f; up.y=1.0f; up.z=0.0f;
  if (!orientation->FUN_0022d2b0(&up,0.00001f)) {
   up.x=0.0f; up.y=1.0f; up.z=0.0f;
   FUN_00224db0(&transform,&up,orientation);
  }
  transform.position=*position;
  manager->FUN_00283a40(&handle,&transform,-1.0f,1.0f);
 }
}


// 0x001d6770 FUN_001d6770 (344 B): equivalent/0x001d6770.cpp
// sym: ?FUN_001d6770@StateWalker@fn_fff2a2ba@@QAEXXZ @609fd9906478 @wb2f447a97b4f
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 33/38, incomplete)
// FUN_001d6770 @ 0x001d6770
void StateWalker::FUN_001d6770()
{
    int best = -1;
    int cur = current;
    int ring[8];
    int ringIdx = 0;
    int iterations = 0;
    int k;

    for (k = 0; k < 8; k++)
        ring[k] = -1;

    for (;;) {
        ring[ringIdx] = cur;
        ringIdx = (ringIdx + 1) % 8;

        GraphNode *node = graph->FUN_001d56f0(cur);
        int count = node->count;
        bool found = false;
        bool hit = false;
        if (count > 0) {
            int start = current;
            GraphEntry *e = node->entries;
            for (int i = 0; i < count; i++, e++) {
                if (cur == start && e->type == 10) {
                    best = e->value;
                    hit = true;
                    break;
                }
                if (e->type == 13) {
                    cur = e->value;
                    found = true;
                    if (cur == start) {
                        best = graph->FUN_001d5710() - 1;
                        hit = true;
                        break;
                    }
                }
            }
        }

        if (!hit && !found) {
            if (best < 0) {
                if (cur != current)
                    best = cur;
                if (best < 0)
                    best = graph->FUN_001d5710() - 1;
            }
            break;
        }

        if (best < 0) {
            for (k = 0; k < 8; k++) {
                if (cur == ring[k]) {
                    best = graph->FUN_001d5710() - 1;
                    break;
                }
            }
        }
        iterations++;
        if (best >= 0)
            break;
        if (iterations >= 0x20)
            best = graph->FUN_001d5710() - 1;
        if (best >= 0)
            break;
    }

    if (current != best) {
        if (listener)
            listener->FUN_002fc670(2);
        vfunc_16(best, 1);
    }
}


// 0x001d68d0 FUN_001d68d0 (15 B): matches/0x001d68d0.cpp
// sym: ?target@fn_fff2a2ba@@YIHPAVC_1d68d0@1@@Z
hulk_intptr __fastcall target(C_1d68d0* self) {
    if (!self->p)
        return 0;
    return self->p[6];
}


// 0x001d68e0 FUN_001d68e0 (154 B): matches/0x001d68e0.cpp
// sym: _FUN_001d68e0
extern "C" const char* FUN_001d68e0(int x) {
    if (x == 1)
        return DAT_00422efc;
    if (x == 3)
        return DAT_00422ee4;
    if (x == 2)
        return DAT_00422ecc;
    if (x == 4)
        return DAT_00422eb8;
    if (x == 8)
        return DAT_00422eac;
    if (x == 7)
        return DAT_00422ea0;
    if (x == 6)
        return DAT_00422e84;
    if (x == 5)
        return DAT_00422e6c;
    if (x == 9)
        return DAT_00422e5c;
    if (x == 10)
        return DAT_00422e44;
    if (x == 11)
        return DAT_00422e2c;
    if (x == 12)
        return DAT_00422e14;
    if (x == 13)
        return DAT_00422dfc;
    return 0;
}


// 0x001d6980 FUN_001d6980 (11 B): matches/0x001d6980.cpp
// sym: ?F@A_1d6980@fn_fff2a2ba@@QAEHXZ
// Same code shape as 0x001d64a0 (propagated; names are from that function)
int A_1d6980::F() {
    return ((owners::Target_1d4df0 *)p)->FUN_001d4df0();
}


// 0x001d6990 FUN_001d6990 (11 B): matches/0x001d6990.cpp
// sym: ?F@A_1d6990@fn_fff2a2ba@@QAEHXZ
// Same code shape as 0x001d64a0 (propagated; names are from that function)
int A_1d6990::F() {
    return ((int)((owners::C_1d4e00 *)p)->FUN_001d4e00());
}

} // namespace fn_fff2a2ba

// 0x001d69a0 FUN_001d69a0 (14 B): matches/0x001d69a0.cpp
// sym: ?FUN_001d69a0@Target_1d69a0@owners@@QAEHXZ
int owners::Target_1d69a0::FUN_001d69a0() {
    return value != 0;
}


// 0x001d69b0 FUN_001d69b0 (7 B): matches/0x001d69b0.cpp
// sym: ?FUN_001d69b0@C_1d69b0@owners@@QAEEXZ
unsigned char owners::C_1d69b0::FUN_001d69b0() {
    return value;
}


// 0x001d69c0 FUN_001d69c0 (13 B): matches/0x001d69c0.cpp
// sym: ?FUN_001d69c0@A_1d69c0@owners@@QAEXE@Z
void owners::A_1d69c0::FUN_001d69c0(unsigned char x) {
    pad[0x1d0] = x;
}


// 0x001d69d0 FUN_001d69d0 (7 B): matches/0x001d69d0.cpp
// sym: ?FUN_001d69d0@Obj_1d69d0@owners@@QAEHXZ
int owners::Obj_1d69d0::FUN_001d69d0() {
    return mValue;
}


// 0x001d69e0 FUN_001d69e0 (13 B): matches/0x001d69e0.cpp
// sym: ?FUN_001d69e0@A_1d69e0@owners@@QAEXH@Z
void owners::A_1d69e0::FUN_001d69e0(int a) {
    x = a;
}

namespace fn_fff2a2ba {

// 0x001d69f0 FUN_001d69f0 (135 B): equivalent/0x001d69f0.cpp
// sym: ?FUN_001d69f0@Skeleton@fn_fff2a2ba@@QAEXPAUV3_1d69f0@2@@Z @f5b258d2ec76 @w68c966836cb6
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 2/2)
// FUN_001d69f0 @ 0x001d69f0
// Position of the bone this skeleton tracks (or the default offset transformed by its matrix).
void Skeleton::FUN_001d69f0(V3_1d69f0 *out)
{
    V3_1d69f0 offset;
    offset.x = 0.0f;
    offset.y = 0.75f;
    offset.z = 0.0f;
    int bone = ((owners::C_1d4f30 *)indexer)->FUN_001d4f30();
    if (bone != 0xffff) {
        BoneTable_1d69f0 *t = source->v11();
        *out = t->bones[bone].pos;
        return;
    }
    ((owners::Mat_22c2b0 *)(v15()))->FUN_0022c2b0((float *)(V3_1d69f0 *)(&offset), (float *)(V3_1d69f0 *)out);
}


// 0x001d6a80 FUN_001d6a80 (14 B): matches/0x001d6a80.cpp
// sym: ?target@fn_fff2a2ba@@YI_NPAVA_1d6a80@1@@Z
bool __fastcall target(A_1d6a80* self) {
    return self->value != 0;
}

} // namespace fn_fff2a2ba

// 0x001d6a90 FUN_001d6a90 (7 B): matches/0x001d6a90.cpp
// sym: ?FUN_001d6a90@Target_1d6a90@owners@@QAEEXZ
unsigned char owners::Target_1d6a90::FUN_001d6a90() {
    return value;
}


// 0x001d6aa0 FUN_001d6aa0 (13 B): matches/0x001d6aa0.cpp
// sym: ?FUN_001d6aa0@Target_1d6aa0@owners@@QAEXE@Z
void owners::Target_1d6aa0::FUN_001d6aa0(unsigned char value) {
    pad[0x1e0] = value;
}

namespace fn_fff2a2ba {

// 0x001d6ab0 FUN_001d6ab0 (7 B): matches/0x001d6ab0.cpp
// sym: ?FUN_001d6ab0@fn_fff2a2ba@@YIEPAVTarget_1d6ab0@1@@Z
unsigned char __fastcall FUN_001d6ab0(Target_1d6ab0* self) {
    return self->value;
}

} // namespace fn_fff2a2ba

// 0x001d6ac0 FUN_001d6ac0 (13 B): matches/0x001d6ac0.cpp
// sym: ?FUN_001d6ac0@Target_1d6ac0@owners@@QAEXE@Z
void owners::Target_1d6ac0::FUN_001d6ac0(unsigned char x) {
    value = x;
}


// 0x001d6ad0 FUN_001d6ad0 (33 B): matches/0x001d6ad0.cpp
// sym: ?FUN_001d6ad0@Target_1d6ad0@owners@@QAEXPAH@Z
void owners::Target_1d6ad0::FUN_001d6ad0(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}


// 0x001d6b30 FUN_001d6b30 (7 B): matches/0x001d6b30.cpp
// sym: ?FUN_001d6b30@Thing_1d6b30@owners@@QAEPAHXZ
int* owners::Thing_1d6b30::FUN_001d6b30() {
    return (int*)((char*)this + 0x17c);
}

namespace fn_fff2a2ba {

// 0x001d6b40 FUN_001d6b40 (32 B): matches/0x001d6b40.cpp
// sym: ?target@fn_fff2a2ba@@YIHPAUObj_1d6b40@1@@Z
hulk_intptr __fastcall target(Obj_1d6b40* self) {
    void* p = self->pA0;
    if (p) {
        int r = FUN_002fc6f0(p);
        return r + 0x30;
    }
    Fallback* f = self->fb;
    return f->f4();
}


// 0x001d6b60 FUN_001d6b60 (118 B): matches/0x001d6b60.cpp
// sym: ?run@Obj_1d6b60@fn_fff2a2ba@@QAEXUBlock_1d6b60@2@K@Z
void Obj_1d6b60::run(Block_1d6b60 b, unsigned long arg) {
    inner->g(b);
    F7dde0_0027dde0(&b);
    Store* s = store;
    if (s) {
        s->F670_002fc670(2);
        s->F700_002fc700(&b, arg);
    }
    x = b.v[12];
    y = b.v[13];
    z = b.v[14];
}

} // namespace fn_fff2a2ba

// 0x001d6be0 CSPHulkPropInstance::vfunc_15 (22 B): matches/0x001d6be0.cpp [wrapped: conflict: CSPHulkPropInstance]
// sym: ?vfunc_15@CSPHulkPropInstance@fn_001d6be0@@UAEXXZ
namespace fn_001d6be0 {
class StateProp {
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
    virtual void vfunc_15();
};
class CSPHulkPropInstance : public StateProp {
  public:
    char pad[0xa0 - sizeof(StateProp)];
    void* member;
    void vfunc_15();
};
class Other_1d6be0 {
  public:
    void Fnf_002fc6f0();
};
void CSPHulkPropInstance::vfunc_15() {
    if (member)
        ((Other_1d6be0*)member)->Fnf_002fc6f0();
    else
        StateProp::vfunc_15();
}
} // namespace fn_001d6be0


// 0x001d6c00 FUN_001d6c00 (67 B): matches/0x001d6c00.cpp [wrapped: merged class would differ: Vec: size 36 vs 12]
// sym: ?fn@Owner@fn_001d6c00@@QAEXXZ
namespace fn_001d6c00 {
// data: zero = DAT_004c6068

struct Vec {
    float x, y, z;
};
struct View {
    char bytes[64];
};
struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual View* get();
};
struct Owner {
    char pad[0x11c];
    Obj* obj;
    void fn();
};
void __cdecl output_00224f10(Vec*);
void Owner::fn() {
    View local = *obj->get();
    Vec v;
    ((owners::M_22c3b0 *)&local)->FUN_0022c3b0((float *)(((float*)&DAT_004c6068)), (float *)(Vec *)(&v));
    output_00224f10(&v);
}
} // namespace fn_001d6c00

namespace fn_fff2a2ba {

// 0x001d6c50 FUN_001d6c50 (7 B): matches/0x001d6c50.cpp
// sym: ?FUN_001d6c50@fn_fff2a2ba@@YIIPAUTarget_1d6c50@1@@Z
unsigned int __fastcall FUN_001d6c50(Target_1d6c50* self) {
    return self->value;
}

} // namespace fn_fff2a2ba

// 0x001d6c60 FUN_001d6c60 (13 B): matches/0x001d6c60.cpp
// sym: ?FUN_001d6c60@C_1d6c60@owners@@QAEXH@Z
void owners::C_1d6c60::FUN_001d6c60(int x) {
    value = x;
}


// 0x001d6c70 FUN_001d6c70 (7 B): matches/0x001d6c70.cpp
// sym: ?FUN_001d6c70@C_1d6c70@owners@@QAEHXZ
int owners::C_1d6c70::FUN_001d6c70() {
    return value;
}


// 0x001d6c80 FUN_001d6c80 (13 B): matches/0x001d6c80.cpp
// sym: ?FUN_001d6c80@C_1d6c80@owners@@QAEXH@Z
void owners::C_1d6c80::FUN_001d6c80(int x) {
    value = x;
}

namespace fn_fff2a2ba {

// 0x001d6c90 FUN_001d6c90 (7 B): matches/0x001d6c90.cpp
// sym: ?FUN_001d6c90@fn_fff2a2ba@@YIIPAVTarget_1d6c90@1@@Z
hulk_uintptr __fastcall FUN_001d6c90(Target_1d6c90* self) {
    return self->value;
}

} // namespace fn_fff2a2ba

// 0x001d6ca0 FUN_001d6ca0 (13 B): matches/0x001d6ca0.cpp
// sym: ?FUN_001d6ca0@A_1d6ca0@owners@@QAEXH@Z
void owners::A_1d6ca0::FUN_001d6ca0(int value) {
    field = value;
}

namespace fn_fff2a2ba {

// 0x001d6cb0 FUN_001d6cb0 (7 B): matches/0x001d6cb0.cpp
// sym: ?Target@fn_fff2a2ba@@YIPAUThing_1d6cb0@1@PAU21@@Z
Thing_1d6cb0* __fastcall Target(Thing_1d6cb0* self) {
    return (Thing_1d6cb0*)((char*)self + 0x25c);
}

} // namespace fn_fff2a2ba

// 0x001d6cc0 FUN_001d6cc0 (13 B): matches/0x001d6cc0.cpp
// sym: ?FUN_001d6cc0@C_1d6cc0@owners@@QAEXH@Z
void owners::C_1d6cc0::FUN_001d6cc0(int x) {
    value = x;
}

namespace fn_fff2a2ba {

// 0x001d6cd0 FUN_001d6cd0 (7 B): matches/0x001d6cd0.cpp
// sym: ?target@fn_fff2a2ba@@YIMPAVC_1d6cd0@1@@Z
float __fastcall target(C_1d6cd0* self) {
    return self->value;
}

} // namespace fn_fff2a2ba

// 0x001d6ce0 CSPHulkPropInstance::vfunc_8 (51 B): matches/0x001d6ce0.cpp
// sym: ?vfunc_8@CSPHulkPropInstance@@UAEXHH@Z
void CSPHulkPropInstance::vfunc_8(hulk_intptr x, int y) {
    if ((*(A_1d6ce0 * *)&this->f_ec)->run_001d4df0() && hulk_at_004dd700->p->run_00099790())
        return;
    (*(V * *)&this->f_9c)->f8(x, y);
}


// 0x001d6e10 FUN_001d6e10 (173 B): equivalent/0x001d6e10.cpp [wrapped: conflict: World]
// sym: ?FUN_001d6e10@Owner_1d6e10@fn_001d6e10@@QAEXPAUEntry_1d6e10@2@@Z @dc9da0294b36 @w7469358ce483
namespace fn_001d6e10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_001d6e10 @ 0x001d6e10
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

struct Entry_1d6e10;
struct Owner_1d6e10;
struct Resource_1d6e10 {
 Entry_1d6e10* FUN_00035b60();
};
struct Entry_1d6e10 {
 virtual void AddRef();
 virtual void Release();
 unsigned int reserved;
 union { Resource_1d6e10* resource; Owner_1d6e10* owner; } value;
 unsigned int type;
};
struct Manager_1d6e10 { bool FUN_000242d0(Resource_1d6e10*); };
struct World { char pad[0x20]; Manager_1d6e10* manager; };
void __cdecl FUN_00018810(Entry_1d6e10**, Entry_1d6e10*);
struct Owner_1d6e10 {
 char pad[0x24c];
 Entry_1d6e10* entry;
 void FUN_001d6e10(Entry_1d6e10* incoming);
};
void Owner_1d6e10::FUN_001d6e10(Entry_1d6e10* incoming) {
 if (entry && entry->type == 1 && DAT_004dd700->manager->FUN_000242d0(entry->value.resource)) return;
 if (incoming) incoming->AddRef();
 if (entry) entry->Release();
 entry = incoming;
 if (!incoming) return;
 if (incoming->type == 5) {
  Entry_1d6e10* nested = incoming->value.owner->entry;
  if (nested) FUN_00018810(&entry, nested);
 } else if (incoming->type == 1) {
  Resource_1d6e10* resource = incoming->value.resource;
  if (!DAT_004dd700->manager->FUN_000242d0(resource) && resource->FUN_00035b60())
   FUN_00018810(&entry, resource->FUN_00035b60());
 }
}
} // namespace fn_001d6e10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d6ec0 FUN_001d6ec0 (571 B): equivalent/0x001d6ec0.cpp [wrapped: conflict: FUN_0027afb0; World]
// sym: ?FUN_001d6ec0@Receiver_1d6ec0@fn_001d6ec0@@QAE_NHPAURef_1d6ec0@2@_N@Z @13691fffbfc7 @w94409098215b
namespace fn_001d6ec0 {
// STATUS: equivalent (tools/equiv.py level 3: 20042 inputs, branch coverage 54/54)
// FUN_001d6ec0 @ 0x001d6ec0
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

unsigned __int64 FUN_0027afb0(const char* s);

struct IdBlock {
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
};

struct Stats_1d6ec0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Scene_1d6ec0 {
    char pad0[0x80];
    Stats_1d6ec0 stats;
};

struct Boss {
    bool FUN_00092940(int flag);
};

struct Level_1d6ec0 {
};

struct Meter_1d6ec0 {
    int FUN_001d5e80(int mode);
    float FUN_001d4e90();
};

struct Effect_1d6ec0 {
    void FUN_001c4ac0(int* color, float scale);
};

struct Body_1d6ec0 {
    char pad0[0x1b0];
    int kind;
};

struct Fighter_1d6ec0 {
    char pad0[0x11c];
    Body_1d6ec0* body;
};

struct Ref_1d6ec0 {
    char pad0[8];
    Fighter_1d6ec0* fighter;
    int type;
};

struct Roster_1d6ec0 {
    char pad0[0x124];
    Fighter_1d6ec0* player;
    bool FUN_000242d0(Fighter_1d6ec0* f);
};

struct Rules {
    bool FUN_000997a0();
};

struct World {
    char pad0[8];
    Rules* rules;
    char pad0c[0x14];
    Roster_1d6ec0* roster;
    char pad24[0x30];
    Level_1d6ec0* level;
};


struct Hit;

class Receiver_1d6ec0 {
public:
    char pad0[0x40];
    int f40;
    char pad44[0x9c - 0x44];
    IdBlock* tag;
    char padA0[0xec - 0xa0];
    Meter_1d6ec0* meter;
    char padF0[0x108 - 0xf0];
    int health;
    int threshold;
    char pad110[4];
    Ref_1d6ec0* attackerRef;
    char pad118[4];
    Effect_1d6ec0* effect;
    char pad120[0x148 - 0x120];
    int blocked;
    char pad14c[0x194 - 0x14c];
    char immune;
    char pad195[3];
    int kindMatch;
    float kindScale;
    void FUN_001d6e10(Ref_1d6ec0* r);
    bool FUN_001d6ec0(int amount, Ref_1d6ec0* victim, bool forced);
};

bool Receiver_1d6ec0::FUN_001d6ec0(int amount, Ref_1d6ec0* victim, bool forced)
{
    if (!((*(unsigned int*)&DAT_004e25f8) & 1)) {
        (*(unsigned int*)&DAT_004e25f8) |= 1;
        (*(unsigned __int64*)&DAT_004e25f0) = FUN_0027afb0("bunker_bunker");
    }
    int dmg;

    IdBlock* tagBlock = tag;
    if (tagBlock) {
        unsigned int lo = tagBlock->idLo;
        unsigned int hi = tagBlock->idHi;
        Scene_1d6ec0* scene = ((Scene_1d6ec0 *)((owners::C_86310 *)(DAT_004dd700->level))->FUN_00086310());
        if (scene) {
            int a = scene->stats.FUN_00088fa0();
            int b = scene->stats.FUN_00088fb0();
            if (a == 10 && b == 0x1c && lo == (unsigned int)(__int64)(*(unsigned __int64*)&DAT_004e25f0) && hi == (unsigned int)(__int64)((*(unsigned __int64*)&DAT_004e25f0) >> 32))
                return false;
        }
    }

    if (immune)
        return false;

    Ref_1d6ec0* att = attackerRef;
    if (att) {
        if (att->type == 1 && DAT_004dd700->roster->FUN_000242d0(att->fighter) && !DAT_004dd700->rules->FUN_000997a0())
            return false;
        bool isMode2 = meter->FUN_001d5e80(f40) == 2;
        if (meter->FUN_001d4e90() > 0.0f) {
            dmg = (int)(__int64)(meter->FUN_001d4e90() * amount);
            amount = dmg;
        } else if (isMode2) {
            dmg = (int)(__int64)(amount * 0.05f);
            if (dmg > 1) {
                amount = dmg;
            } else {
                dmg = 1;
                amount = 1;
            }
        } else {
            if (!forced)
                return false;
            dmg = amount;
        }
    } else {
        dmg = amount;
    }

    forced = false;
    if (blocked)
        return false;

    if (victim && victim->type == 1) {
        Fighter_1d6ec0* ft = victim->fighter;
        if (ft->body) {
            if (ft->body->kind == kindMatch)
                dmg = (int)(__int64)(amount * kindScale);
        }
        World* g = DAT_004dd700;
        if (ft == g->roster->player) {
            if (((Boss *)((owners::A_86340 *)(g->level))->FUN_00086340())->FUN_00092940(0x14))
                dmg += dmg;
        }
    }

    if (dmg > threshold) {
        int h = health;
        if (h > 0)
            forced = true;
        health = h - dmg;
        if (forced) {
            amount = (int)(__int64)0xffc84040;
            effect->FUN_001c4ac0(&amount, 0.4f);
        }
        FUN_001d6e10(victim);
    }
    return forced;
}
} // namespace fn_001d6ec0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fff2a2ba {

// 0x001d7100 FUN_001d7100 (66 B): matches/0x001d7100.cpp
// sym: ?Find@Obj_1d7100@fn_fff2a2ba@@QAEHH@Z
int Obj_1d7100::Find(int index) {
    if (index == -1)
        index = this->index;
    int* p = (int*)this->table->entries[index];
    int a = p[2];
    int b = p[3];
    int result = -1;
    for (int i = 0; i < 8; ++i) {
        if (a == ((int*)((hulk_intptr)DAT_004e2560))[i * 2] && b == ((int*)((hulk_intptr)((char*)((char*)&DAT_004e2560 + 4))))[i * 2]) {
            result = i;
            break;
        }
    }
    return result;
}


// 0x001d7150 FUN_001d7150 (134 B): equivalent/0x001d7150.cpp
// sym: ?SelectById@Manager_1d7150@fn_fff2a2ba@@QAE_NH@Z @c1f180e76d9f @wc8bf3eaa0352
// STATUS: equivalent (tools/equiv.py level 3: 204 inputs, branch coverage 8/8)
// FUN_001d7150 @ 0x001d7150
bool Manager_1d7150::SelectById(int id)
{
    int count = counter->FUN_001d5710();
    if (count <= 0)
        return false;
    unsigned int lo = ((Id_1d7150*)&DAT_004e2560)[id].lo;
    unsigned int hi = ((Id_1d7150*)&DAT_004e2560)[id].hi;
    Item_1d7150 **p = list->items;
    for (int i = 0; i < count; i++) {
        if (p[i]->lo == lo && p[i]->hi == hi) {
            Select(i, 1);
            return true;
        }
    }
    return false;
}

} // namespace fn_fff2a2ba

// 0x001d71e0 FUN_001d71e0 (178 B): equivalent/0x001d71e0.cpp [wrapped: conflict: World]
// sym: ?FUN_001d71e0@Object@fn_001d71e0@@QAEXPAUReference@2@@Z @f88add6db4df @w9a10e8ab0dcf
namespace fn_001d71e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_001d71e0 @ 0x001d71e0
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

struct Value_1d71e0 { unsigned int value; char rest[28]; void FUN_00067e60(void*); void FUN_000679c0(); };
struct Manager_1d71e0 {  void FUN_00067c30(unsigned int, Value_1d71e0*); };
struct Services_1d71e0 { char pad[8]; Manager_1d71e0* manager; };
struct World { char pad[32]; Services_1d71e0* services; };
struct Payload_1d71e0 { char pad[16]; unsigned int* value; };
struct Reference { virtual void addRef(); virtual void release(); unsigned int reserved; Payload_1d71e0* payload; unsigned int type; };
struct Object { char pad[0x118]; Reference* reference; char pad2[0x1cc-0x11c]; unsigned int key; void FUN_001d71e0(Reference*); };
void Object::FUN_001d71e0(Reference* next) {
 if(reference == next) return;
 if(next) next->addRef();
 if(reference) reference->release();
 reference=next;
 if(!key) return;
 Manager_1d71e0* manager=DAT_004dd700->services->manager;
 void* found=((owners::C_67ad0 *)manager)->FUN_00067ad0(key);
 if(!found) return;
 Value_1d71e0 value; value.FUN_00067e60(found);
 if(reference && reference->type==1 && reference->payload) value.value=*reference->payload->value;
 else value.value=0;
 manager->FUN_00067c30(key,&value);
 value.FUN_000679c0();
}
} // namespace fn_001d71e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fff2a2ba {

// 0x001d72a0 FUN_001d72a0 (62 B): matches/0x001d72a0.cpp
// sym: ?FUN_001d72a0@fn_fff2a2ba@@YIXPAUObj_1d72a0@1@@Z
void __fastcall FUN_001d72a0(Obj_1d72a0* self) {
    unsigned* p;
    if (self->p)
        p = (unsigned*)((char*)((void *)((owners::C_2fc6f0 *)(self->p))->FUN_002fc6f0()) + 0x30);
    else
        p = (unsigned*)self->other->Get();
    self->a = p[0];
    self->b = p[1];
    self->c = p[2];
}

} // namespace fn_fff2a2ba

// 0x001d72e0 FUN_001d72e0 (17 B): matches/0x001d72e0.cpp
// sym: ?FUN_001d72e0@C_1d72e0@owners@@QAEHXZ
hulk_intptr owners::C_1d72e0::FUN_001d72e0() {
    if (p)
        return *(int*)((char*)p + 0x10);
    return 0;
}

namespace fn_fff2a2ba {

// 0x001d7300 FUN_001d7300 (33 B): matches/0x001d7300.cpp
// sym: ?FUN_001d7300@fn_fff2a2ba@@YIHPAVObj_1d7300@1@@Z
int __fastcall FUN_001d7300(Obj_1d7300* self) {
    void* p = self->a;
    if (p && *(void**)((char*)p + 0x10) && *(void**)((char*)*(void**)((char*)p + 0x10) + 0x70))
        return 1;
    return 0;
}


// 0x001d7330 FUN_001d7330 (44 B): matches/0x001d7330.cpp
// sym: ?Set@Owner_1d7330@fn_fff2a2ba@@QAEXPAVItem_1d7330@2@@Z
void Owner_1d7330::Set(Item_1d7330* p) {
    if (p)
        p->F0();
    if (item)
        item->F1();
    item = p;
}


// 0x001d7360 FUN_001d7360 (141 B): equivalent/0x001d7360.cpp
// sym: ?FUN_001d7360@Node@fn_fff2a2ba@@QAE_NPAUVec4Bits@2@@Z @56ffb8fc84ea @w2200f1f31ef7
// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 10/10)
// FUN_001d7360 @ 0x001d7360
// Fill `out` (x, y, z, w) from the attached transform source and its parent chain, then hand it to
// the virtual transform step and finish with the result object.
bool Node::FUN_001d7360(Vec4Bits* out)
{
    Source_1d7360* src = source;
    if (src != 0) {
        out->x = src->value.x;
        out->y = src->value.y;
        out->z = src->value.z;
        out->w = src->value.w;
    } else {
        out->z = 0;
        out->y = 0;
        out->x = 0;
    }

    Parent_1d7360* p = parent;
    if (p != 0 && p->link != 0 && p->link->mid != 0 && p->link->mid->leaf != 0) {
        out->w = p->link->mid->leaf->weight;
    }

    Vec3Bits local;
    local.x = out->x;
    local.y = out->y;
    local.z = out->z;
    ((owners::Mat_22c2b0 *)(Transform()))->FUN_0022c2b0((float *)(&local), (float *)out);
    return true;
}


// 0x001d73f0 FUN_001d73f0 (90 B): matches/0x001d73f0.cpp
// sym: ?target@fn_fff2a2ba@@YIHPAVSelf_1d73f0@1@@Z
int __fastcall target(Self_1d73f0* s) {
    float limit = g_1d73f0->p->value;
    hulk_intptr r;
    if (s->a)
        r = ((int)((owners::C_2fc6f0 *)(s->a))->FUN_002fc6f0()) + 0x30;
    else
        r = ((Other_1d73f0*)s->b)->f4();
    if (*(float*)(r + 4) < limit)
        return -10;
    int v = s->arg;
    CSPHulkPropInstance* d = s->d;
    return ((CSPHulkPropInstance_nv_1d73f0*)(d))->run_001d5d20(v);
}

} // namespace fn_fff2a2ba

// 0x001d7450 FUN_001d7450 (16 B): matches/0x001d7450.cpp
// sym: ?FUN_001d7450@Self_1d7450@owners@@QAE_NXZ
bool owners::Self_1d7450::FUN_001d7450() {
    return FUN_001d73f0() > -10;
}

namespace fn_fff2a2ba {

// 0x001d7460 FUN_001d7460 (48 B): matches/0x001d7460.cpp
// sym: ?Set@Owner_1d7460@fn_fff2a2ba@@QAEXPAVRef_1d7460@2@@Z
void Owner_1d7460::Set(Ref_1d7460* value) {
    if ((void*)this != (void*)value) {
        if (value)
            value->A();
        if (p)
            p->B();
        p = value;
    }
}


// 0x001d7490 FUN_001d7490 (44 B): matches/0x001d7490.cpp
// sym: ?Set@Owner_1d7490@fn_fff2a2ba@@QAEXPAVRef_1d7490@2@@Z
void Owner_1d7490::Set(Ref_1d7490* p) {
    if (p)
        p->AddRef();
    if (value)
        value->Release();
    value = p;
}


// 0x001d74c0 FUN_001d74c0 (74 B): matches/0x001d74c0.cpp
// sym: ?whatever@Obj_1d74c0@fn_fff2a2ba@@QAEXPAVFirst_1d74c0@2@HHE@Z
void Obj_1d74c0::whatever(First_1d74c0* p, int x, int y, unsigned char z) {
    if (p)
        p->A();
    Second_1d74c0* old = (Second_1d74c0*)ptr;
    if (old)
        old->B();
    ptr = p;
    b = y;
    a = x;
    c = z;
}


// 0x001d7510 FUN_001d7510 (116 B): matches/0x001d7510.cpp
// sym: ?F@W_1d7510@fn_fff2a2ba@@QAEXXZ
void W_1d7510::F() {
    Link_1d7510* k = l;
    if (!k)
        return;
    Mid2* m = k->m;
    if (!m)
        return;
    Fn_1d7510* f = m->f;
    if (f) {
        float v = f->Get();
        if (v != 0.0f) {
            ((Res_1d7510*)l)->Release_002fc670(1);
            return;
        }
        if (flag) {
            float t[2];
            t[0] = x;
            t[1] = y;
            GetY_000678d0()->Go_00065ee0(t);
        }
    }
}


// 0x001d7590 FUN_001d7590 (37 B): matches/0x001d7590.cpp
// sym: ?run@Outer_1d7590@fn_fff2a2ba@@QAEXXZ
void Outer_1d7590::run() {
    Wrap_1d7590* w = ptr;
    if (w) {
        Inner_1d7590* p = w->ptr;
        if (p) {
            p->helper_002ef8b0(0);
            p->f7();
        }
    }
}


// 0x001d75c0 FUN_001d75c0 (48 B): matches/0x001d75c0.cpp
// sym: ?Get@Obj@fn_fff2a2ba@@QAEPAXH@Z
void* Obj::Get(int index) {
    if (index < 0)
        return 0;
    int** p = &v->begin;
    if (index < (p[1] - p[0]))
        return items[index];
    return 0;
}


// 0x001d77c0 FUN_001d77c0 (78 B): equivalent/0x001d77c0.cpp
// sym: ?FUN_001d77c0@Object@fn_fff2a2ba@@QAEPAXXZ @7e2127cf801e @wd39380415df4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001d77c0 @ 0x001d77c0
void *Object::FUN_001d77c0() {
    if (!((*(int*)&DAT_004e2618) & 1)) {
        (*(int*)&DAT_004e2618) |= 1;
        (*(int*)&DAT_004e260c) = 0;
        (*(int*)&DAT_004e2610) = 0;
        (*(int*)&DAT_004e2614) = 0;
    }
    if (container && container->result)
        return &container->result->data;
    return ((int*)&DAT_004e260c);
}


// 0x001d7810 FUN_001d7810 (120 B): matches/0x001d7810.cpp
// sym: ?Fn@O_1d7810@fn_fff2a2ba@@QAEXMMM@Z
void O_1d7810::Fn(float x, float y, float z) {
    Mat_1d7810 m = *GetMat();
    m.x = x;
    m.y = y;
    m.z = z;
    Apply_001d6b60(m, 0);
    px = x;
    py = y;
    pz = z;
}

} // namespace fn_fff2a2ba
