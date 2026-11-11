// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027ca80..0x0027f2a0 (kind game, layer engine, confidence high), dominant class pure3d::prop::StateProp
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/content.h"
#include "gen/owners.h"
#include "gen/physics.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f03c5b48 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_f03c5b48 {} using namespace fn_f03c5b48;
#include "engine/pure3d/prop.h"

// ---- declarations shared by the functions below
namespace fn_f03c5b48 {
class ParamValue_27ca80 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Child_27caa0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int a, int b);
};
struct Entry_27caa0 {
    Child_27caa0* child;       // 0x0
    int pad4;
    unsigned int flags; // 0x8
};
class Device_27caa0 {
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
    virtual void vfunc_16(int a);
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23(int a, int b);
};
struct Context {
    Device_27caa0* device;
};
class StateProp {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int a, int b);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15();
    virtual void vfunc_16();
    char pad04[0x9c - 4];
    Child_27caa0* drawable;        // 0x9c
    char padA0[0xb4 - 0xa0];
    int entryCount;         // 0xb4
    Entry_27caa0 entries[1];       // 0xb8
};
const float gScale_27cb40 = 33.333332061767578125f;
class Sink_27cb40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(float, int);
};
class Obj_27cb40 {
  public:
    char pad[0x44];
    float value;
    char pad2[0x54];
    Sink_27cb40* sink;
    void set(float);
};
struct X_27cc40 {
    void Call_0027af00();
    X_27cc40* Target();
};
struct Dispatcher_27cc60;
struct Event_27cc60 {
    char pad00[0xc];
    float time;
};
struct Timeline_27cc60 {
    char pad00[0x34];
    int count;
    Event_27cc60 *events;
};
class Listener_27cc60 {
public:
    virtual void OnEvent(Event_27cc60 *event, Dispatcher_27cc60 *dispatcher);
};
struct Dispatcher_27cc60 {
    char pad00[0x90];
    int listenerCount;
    Listener_27cc60 *listeners[16];
    void FUN_0027cc60(Timeline_27cc60 *timeline, float from, float to);
};
struct Matrix {
  public:
    float m[16];
    void FUN_0022b980();
};
struct Query_27cd10 {
    char pad0[0xc];
    float x;                    // 0xc
    float y;                    // 0x10
    float z;                    // 0x14
    int field18;                // 0x18
    char pad1c[0x28 - 0x1c];
    char blockA[8];             // 0x28
    char blockB[8];             // 0x30
    int field38;                // 0x38
    int field3c;                // 0x3c
    char pad40[0x48 - 0x40];
    int outMode;                // 0x48
    int inMode;                 // 0x4c
};
struct Palette_27cd10 {
    char pad0[0x1c];
    Matrix *matrices;           // 0x1c
    int FUN_002843a0(int a, int b);
};
struct Holder_27cd10 {
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
    virtual Palette_27cd10 *palette();     // 0x2c
};
struct Target_27cd10 {
    int FUN_00283a40(void *block, Matrix *m, float scale, int f);
    int FUN_00283b10(void *block, Palette_27cd10 *pal, void *block2, Matrix *m, float scale, int f);
    void FUN_0027ff90(int hit, int a, int b);
};
class Renderer_27cd10 {
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
    virtual Matrix *worldMatrix();      // 0x3c
    int field4;
    int field8;                         // 0x8
    int fieldc;                         // 0xc
    char pad10[0x9c - 0x10];
    Holder_27cd10 *holder;                     // 0x9c

    Target_27cd10 *FUN_0027f250();
    void FUN_0027cd10(Query_27cd10 *q);
};
class C_27cf70 {
    char pad[0x48];
};
class Obj_27d3e0 {
  public:
    hulk_intptr call_0027d0f0(pure3d::prop::StateProp*);
};
extern void* __cdecl thunk_FUN_0008d690(int);
struct Key_27d410 { char pad[8]; unsigned int a; unsigned int b; };
struct KeyList_27d410 { char pad[0x1c]; Key_27d410** begin; Key_27d410** end; };
struct Selector_27d410 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Select(int index, int flag);
    char pad[0x98 - 4];
    KeyList_27d410* list;
    void FUN_0027d410(const unsigned int* id);
};
struct Item_27d4f0 { int f0, f4; int key; int target; };
struct Entry_27d4f0 { char pad[0x24]; int count; Item_27d4f0* items; };
struct Table_27d4f0 { char pad[0x1c]; Entry_27d4f0** entries; };
class Node {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Fire(int target, int flag);
    char pad4[0x40 - 4];
    int index;
    char pad44[0x98 - 0x44];
    Table_27d4f0* table;
    char pad9c[0xb4 - 0x9c];
    int childCount;
    struct Child { Node* node; int f4; unsigned flags; } child[1];
    void FUN_0027d4f0(int key);
};
} // namespace fn_f03c5b48
namespace pure3d { namespace prop {
struct Source {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12();
    char pad[0x10];
    unsigned int position[6];
    unsigned int bounds[4];
};
} }
namespace fn_f03c5b48 {
struct Ref_27d680 {
    virtual void f0();
    virtual void f1();
};
struct Child_27d680 {
    virtual void f0();
};
struct H;
struct H {
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
    virtual void a13(Child_27d680*);
};
typedef unsigned int U_27db30;
struct Spawned_27db30;
typedef void (__fastcall *ApplyMethod)(Spawned_27db30*, U_27db30, U_27db30);
struct SpawnVtable { ApplyMethod slots[7]; };
struct Record_27db30 { U_27db30 x; unsigned short id; char pad[6]; };
struct Selector_27db30 { char pad[0x3c]; Record_27db30* records; unsigned char FUN_00298960(U_27db30* value); };
struct Owner_27db30 { char pad[0x44]; Selector_27db30* selector; };
struct Service_27db30 { void FUN_002fe6b0(U_27db30 value); };
struct Entity_27db30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual U_27db30 v4(U_27db30 id,U_27db30 zero);
 char pad[0x80]; unsigned char active;
 Spawned_27db30* FUN_002fdf40(U_27db30 id,U_27db30 a,U_27db30 b);
 U_27db30 FUN_002ef4a0();
  void FUN_002fd4b0(U_27db30 id,U_27db30 zero); void FUN_002fd4f0();
};
struct Holder_27db30 { char pad[0x10]; Entity_27db30* entity; };
struct Spawned_27db30 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(U_27db30 value);
 char pad[0x6c]; Service_27db30* service;
 void FUN_002ef440(U_27db30 value);
};
struct Transform_27db30 { char pad[0x50]; U_27db30 position[3]; U_27db30 rotation[3]; };
struct Child_27db30 { virtual void v0(); char pad[0xc]; Transform_27db30* transform; };
struct PhysicsInstance_nv_27db30 {
    Child_27db30* FUN_002fc880(Spawned_27db30* object,U_27db30 zero);
};
struct Target_27db30 { char pad[0x9c]; Owner_27db30* owner; Holder_27db30* holder; void run(physics::PhysicsInstance* parent,U_27db30 a,U_27db30 b,U_27db30 x,U_27db30 y,U_27db30 z,U_27db30 rx,U_27db30 ry,U_27db30 rz); };
struct Id64_27dca0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af70(Id64_27dca0 *src);
    Id64_27dca0 *FUN_0027b0e0(const char *name);
};
class Chain_27dca0;
struct Event_27dca0 {
    Id64_27dca0 id;
    int type;
    int value;
};
class Handler_27dca0 {
public:
    virtual void vfunc_0(Event_27dca0 *ev, Chain_27dca0 *chain);
};
class Chain_27dca0 {
public:
    char pad00[0x90];
    int count;                  // 0x90
    Handler_27dca0 *handlers[1];       // 0x94
    void FUN_0027dca0();
};
struct Effect_27dd30 {
    char pad0[0x40];
    unsigned int idLo;      // 0x40
    unsigned int idHi;      // 0x44
    char pad48[8];
    float time;             // 0x50
    char pad54[4];
};
struct EffectList {
    char pad0[0x44];
    int count;              // 0x44
    Effect_27dd30 *items;          // 0x48
};
class Player_27dd30 {
public:
    void FUN_0027cd10(Effect_27dd30 *e);
    void FUN_0027dd30(EffectList *list, float lo, float hi);
};
} // namespace fn_f03c5b48
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f03c5b48 {
struct Target_27dde0 {
    void FUN_002f39e0(void* matrix);
};
struct Elem_27dde0 {
    char pad[0x10];
    Target_27dde0* target;
};
struct Group_27dde0 {
    char pad[0x1c];
    int begin;
    int end;
};
class Obj_27dde0 {
  public:
    char pad00[0x48];
    char matrix[0x40];
    char pad88[0x98 - 0x88];
    Group_27dde0* group;
    char pad9c[0xac - 0x9c];
    Elem_27dde0** elems;
    int* FUN_0027dde0(const void* src);
};
struct Values { char pad[0x38]; volatile int first; volatile int second; };
struct Entry { char pad[0x10]; Values * volatile values; };
struct Range { char pad[0x1c]; volatile int begin; volatile int end; };
struct Owner { char pad0[0x98]; Range * volatile range; char pad1[0x10]; Entry ** volatile entries; int *FUN_0027de50(int a,hulk_intptr b); };
typedef unsigned int u32_27ded0;
struct Resource_27e650 {
 virtual void AddRef();
 virtual void Release();
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void SetPosition(float);
 virtual void slot13();
 virtual void SetRange(float, float);
 virtual void slot15();
 virtual void SetMode(int);
 virtual void slot17();
 virtual void Enable(int);
};
struct Controller_27e650 {
 char pad0[0x40];
 int state;
 int secondary;
 char pad48[0x40];
 Resource_27e650* resource;
 unsigned char flag;
 void FUN_0027d780();
 void FUN_0027dca0();
 void FUN_0027e650(Resource_27e650*, float, float);
};
typedef unsigned int U_27e760;
typedef unsigned __int64 U64_27e760;
} // namespace fn_f03c5b48
extern U64_27e760 __cdecl FUN_0027b020(U_27e760);
namespace fn_f03c5b48 {
struct Input_27e780 { char pad0[12]; float x,y,z; char pad1[32]; unsigned a,b; char pad2[12]; int mode; };
struct Bones_27e780 { char pad[28]; Matrix* matrices; unsigned FUN_002843a0(unsigned,unsigned); };
struct Provider_27e780 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual Bones_27e780* v11(); };
struct Output_27e780 { void FUN_0027dde0(Matrix*); };
struct Controller_27ed90 {
    void FUN_002fc670(int);
};
struct Object {
  public:
    virtual void AddRef();
    virtual void release();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void v11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual Matrix* v15();
    char _m_pad_4[0x98];
    Provider_27e780* provider;
    Controller_27ed90* controller;
    void target(Output_27e780*,Input_27e780*);
    void Release() { release(); }
};
struct Entry_27d6c0 {
    Object* object;
    unsigned int state;
    unsigned int extra;
};
struct Container_27d6c0 {
    char padding[0xb4];
    int count;
    Entry_27d6c0 entries[1];
    bool remove(Object* object);
};
struct Entry_27ed90 {
    Object* object;
    void* data;
    unsigned flags;
};
struct Owner_27ed90 {
    char pad[0xb4];
    int count;
    Entry_27ed90 entries[4];
    void FUN_0027e780(Object*, void*);
    bool FUN_0027ed90(Object*, void*, unsigned);
};

} // namespace fn_f03c5b48

// 0x0027ca80 pure3d::prop::StateProp::vfunc_5 (6 B): matches/0x0027ca80.cpp
// sym: ?vfunc_5@StateProp@prop@pure3d@@UAEHXZ
// Same code shape as 0x00234f10 (propagated; names are from that function)
int pure3d::prop::StateProp::vfunc_5() {
    return 8;
}


// 0x0027ca90 pure3d::prop::StateProp::vfunc_3 (3 B): matches/0x0027ca90.cpp
// sym: ?vfunc_3@StateProp@prop@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::prop::StateProp::vfunc_3() {
    return true;
}

namespace fn_f03c5b48 {

// 0x0027caa0 pure3d::prop::StateProp::vfunc_8 (126 B): matches/0x0027caa0.cpp
// sym: ?vfunc_8@StateProp@fn_f03c5b48@@UAEXHH@Z
// pure3d::prop::StateProp::vfunc_8 @ 0x0027caa0
void StateProp::vfunc_8(int a, int b)
{
    for (int i = 0; i < entryCount; i++) {
        if (entries[i].flags & 2)
            entries[i].child->vfunc_8(a, b);
    }
    int v = vfunc_15();
    (*(Context**)&DAT_0052c2ac)->device->vfunc_23(0, v);
    drawable->vfunc_8(a, b);
    (*(Context**)&DAT_0052c2ac)->device->vfunc_16(0);
}

} // namespace fn_f03c5b48

// 0x0027cb20 pure3d::prop::StateProp::vfunc_9 (25 B): matches/0x0027cb20.cpp
// sym: ?vfunc_9@StateProp@prop@pure3d@@UAEXXZ
void pure3d::prop::StateProp::vfunc_9() {
    vfunc_16(0, 1);
    vfunc_6(0, 0);
}

namespace fn_f03c5b48 {

// 0x0027cb40 FUN_0027cb40 (37 B): matches/0x0027cb40.cpp
// sym: ?set@Obj_27cb40@fn_f03c5b48@@QAEXM@Z
void Obj_27cb40::set(float x) {
    value = x;
    sink->f6(x * gScale_27cb40, 0);
}

} // namespace fn_f03c5b48

// 0x0027cb70 FUN_0027cb70 (7 B): matches/0x0027cb70.cpp
// sym: ?FUN_0027cb70@C_27cb70@owners@@QAEHXZ
// Same code shape as 0x000cae70 (propagated; names are from that function)
int owners::C_27cb70::FUN_0027cb70() {
    return value;
}


// 0x0027cb80 FUN_0027cb80 (42 B): matches/0x0027cb80.cpp
// sym: ?FUN_0027cb80@C_27cb80@owners@@QAE_NPAX@Z
bool owners::C_27cb80::FUN_0027cb80(void* p) {
    if (p && count < 1) {
        items[count] = p;
        ++count;
        return true;
    }
    return false;
}


// 0x0027cc20 pure3d::prop::StateProp::vfunc_14 (22 B): matches/0x0027cc20.cpp [wrapped: conflict: StateProp]
// sym: ?vfunc_14@StateProp@fn_0027cc20@@UAEXXZ
namespace fn_0027cc20 {
struct Inner_27cc20 {
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
    virtual void vfunc_14();
};
struct DrawableHierarchy {
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void l();
    virtual void m();
    virtual void vfunc_14();
};
struct StateProp : DrawableHierarchy {
    char pad[0x98];
    Inner_27cc20* mInner;
    virtual void s15();
    virtual void s16();
    virtual void vfunc_14();
};
void StateProp::vfunc_14() {
    mInner->vfunc_14();
    DrawableHierarchy::vfunc_14();
}
} // namespace fn_0027cc20

namespace fn_f03c5b48 {

// 0x0027cc40 FUN_0027cc40 (12 B): matches/0x0027cc40.cpp
// sym: ?Target@X_27cc40@fn_f03c5b48@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_27cc40* X_27cc40::Target() {
    Call_0027af00();
    return this;
}


// 0x0027cc60 FUN_0027cc60 (161 B): matches/0x0027cc60.cpp
// sym: ?FUN_0027cc60@Dispatcher_27cc60@fn_f03c5b48@@QAEXPAUTimeline_27cc60@2@MM@Z
// FUN_0027cc60 @ 0x0027cc60
// FUN_0027cc60 @ 0x0027cc60: notifies every listener of each timeline event whose time lies in [from, to)
void Dispatcher_27cc60::FUN_0027cc60(Timeline_27cc60 *timeline, float from, float to)
{
    if (listenerCount <= 0)
        return;
    for (int i = 0; i < timeline->count; i++) {
        Event_27cc60 *event = &timeline->events[i];
        if (event->time >= from && event->time < to) {
            for (int k = 0; k < listenerCount; k++)
                listeners[k]->OnEvent(event, this);
        }
    }
}


// 0x0027cd10 FUN_0027cd10 (553 B): equivalent/0x0027cd10.cpp
// sym: ?FUN_0027cd10@Renderer_27cd10@fn_f03c5b48@@QAEXPAUQuery_27cd10@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 20/20)
// FUN_0027cd10 @ 0x0027cd10
void Renderer_27cd10::FUN_0027cd10(Query_27cd10 *q)
{
    struct Frame {
        Target_27cd10 *target;
        Renderer_27cd10 *self;
        Matrix o2;
        Matrix o1;
        Matrix mc;
    } fr;

    fr.self = this;
    Target_27cd10 *target = FUN_0027f250();
    fr.target = target;
    if (target == 0)
        return;

    Palette_27cd10 *pal = holder->palette();

    switch (q->inMode) {
    case 0:
        fr.o2.FUN_0022b980();
        ((owners::Target_22be40 *)&(fr.o2))->FUN_0022be40((const int *)(struct Query_27cd10 *)q);
        ((owners::Matrix_22bc20 *)&(fr.o2))->FUN_0022bc20(q->x, q->y, q->z);
        {
            int idx = pal->FUN_002843a0(q->field38, q->field3c);
            Matrix *m;
            if (idx == 0xffff)
                m = worldMatrix();
            else
                m = &pal->matrices[idx];
            ((owners::Matrix_22ca90 *)&(fr.o1))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&fr.o2), (const owners::Matrix_22ca90 *)(Matrix *)m);
        }
        break;
    case 1:
        fr.o2.FUN_0022b980();
        ((owners::Target_22be40 *)&(fr.o2))->FUN_0022be40((const int *)(struct Query_27cd10 *)q);
        ((owners::Matrix_22bc20 *)&(fr.o2))->FUN_0022bc20(q->x, q->y, q->z);
        ((owners::Matrix_22ca90 *)&(fr.o1))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&fr.o2), (const owners::Matrix_22ca90 *)(Matrix *)(worldMatrix()));
        break;
    case 2:
        fr.o1.FUN_0022b980();
        ((owners::Target_22be40 *)&(fr.o1))->FUN_0022be40((const int *)(struct Query_27cd10 *)q);
        ((owners::Matrix_22bc20 *)&(fr.o1))->FUN_0022bc20(q->x, q->y, q->z);
        break;
    default:
        break;
    }

    int hit;
    switch (q->outMode) {
    case 0: {
        int idx = pal->FUN_002843a0(*(int *)&q->blockB[0], *(int *)&q->blockB[4]);
        Matrix *m;
        if (idx == 0xffff)
            m = worldMatrix();
        else
            m = &pal->matrices[idx];
        fr.mc = *m;
        ((owners::Matrix_22c120 *)&(fr.mc))->FUN_0022c120();
        ((owners::Matrix_22ca90 *)&(fr.o2))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&fr.o1), (const owners::Matrix_22ca90 *)(Matrix *)(&fr.mc));
        hit = fr.target->FUN_00283b10(q->blockA, pal, q->blockB, &fr.o2, -1.0f, q->field18);
        break;
    }
    case 1: {
        fr.mc = *worldMatrix();
        ((owners::Matrix_22c120 *)&(fr.mc))->FUN_0022c120();
        ((owners::Matrix_22ca90 *)&(fr.o2))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&fr.o1), (const owners::Matrix_22ca90 *)(Matrix *)(&fr.mc));
        hit = fr.target->FUN_00283b10(q->blockA, pal, 0, &fr.o2, -1.0f, q->field18);
        break;
    }
    case 2:
        hit = fr.target->FUN_00283a40(q->blockA, &fr.o1, -1.0f, q->field18);
        break;
    default:
        return;
    }

    if (hit)
        fr.target->FUN_0027ff90(hit, fr.self->field8, fr.self->fieldc);
}

} // namespace fn_f03c5b48

// 0x0027cf40 FUN_0027cf40 (36 B): matches/0x0027cf40.cpp
// sym: ?FUN_0027cf40@Owner_27cf40@owners@@QAEXH@Z
void owners::Owner_27cf40::FUN_0027cf40(int x) {
    owners::Owner_27cf40* p = GetThing();
    if (p)
        p->DoThing(a, b, x);
}

namespace fn_f03c5b48 {

// 0x0027cf70 pure3d::prop::StateProp::vfunc_15 (4 B): matches/0x0027cf70.cpp
// sym: ?FUN_0027cf70@fn_f03c5b48@@YIPAXPAVC_27cf70@1@@Z
// Same code shape as 0x00092090 (propagated; names are from that function)
void* __fastcall FUN_0027cf70(C_27cf70* self) {
    return (char*)self + 0x48;
}

} // namespace fn_f03c5b48

// 0x0027d0f0 FUN_0027d0f0 (747 B): equivalent/0x0027d0f0.cpp [wrapped: conflict: pure3d::DrawableHierarchy; pure3d::prop::StateProp]
// sym: ??0StateProp@prop@pure3d@fn_0027d0f0@@QAE@PAV0123@@Z
namespace fn_0027d0f0 {
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 40/40)
// FUN_0027d0f0 @ 0x0027d0f0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif


void *FUN_0008d690(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);

struct Name_27d0f0 {
    char data[8];
    void FUN_0027af70(Name_27d0f0 *other);
};

struct Matrix16_27d0f0 {
    unsigned int w[16];
};

class RefCounted_27d0f0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Flag_27d0f0 {
    void FUN_00284ad0(char value);
};

class Material_27d0f0 : public RefCounted_27d0f0 {
public:
    virtual void v2();
    virtual void v3();
    virtual Material_27d0f0 *Clone();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual int Hash();
    char pad04[0x44];
    int f48;
    Flag_27d0f0 *f4c;
    Flag_27d0f0 *f50;
    void FUN_002998d0(int arg);
};

class WorldCollisionObject_27d0f0 : public RefCounted_27d0f0 {
public:
    char pad04[0xc];
    void *source;
    WorldCollisionObject_27d0f0 *FUN_002fe1a0(void *source);
};

struct Shape_27d0f0 {
    char pad0[0x10];
    void *source;
    char pad14[0x18];
    unsigned int priority;
    char pad30[0x1c];
};

struct CollisionMesh_27d0f0 {
    CollisionMesh_27d0f0 *FUN_002f3630(void *source);
    void FUN_002f39e0(Matrix16_27d0f0 *m);
};

struct PtrVec_27d0f0 {
    Shape_27d0f0 **begin;
    Shape_27d0f0 **end;
};

class PhysicsInstance_27d0f0;

class Group_27d0f0 : public RefCounted_27d0f0 {
public:
    char pad04[4];
    Name_27d0f0 name;
    char pad10[4];
    int f14;
    int f18;
    PtrVec_27d0f0 shapes;
};

struct Part_27d0f0 {
    char pad[0x10];
    Part_27d0f0 *p10;
};

class PhysicsInstance_27d0f0 : public RefCounted_27d0f0 {
public:
    char pad04[0xc];
    Part_27d0f0 *p10;
    PhysicsInstance_27d0f0 *FUN_002fc740(int a, int b, int c, int d);
    void *FUN_002fc6f0();
    void FUN_002fc700(void *a, int b);
};

namespace pure3d {
class __declspec(novtable) DrawableHierarchy {
public:
    virtual void d0();
    char pad4[4];
    Name_27d0f0 name;
    char pad10[0x30];
    void FUN_002a3480();
    DrawableHierarchy() throw() { FUN_002a3480(); }
};

namespace prop {
class StateProp : public DrawableHierarchy {
public:
    virtual void s1();
    int f40;
    int f44;
    Matrix16_27d0f0 matrix;
    int f88;
    char b8c;
    char pad8d[3];
    int f90;
    int f94;
    Group_27d0f0 *group;
    Material_27d0f0 *material;
    PhysicsInstance_27d0f0 *holder;
    void *table;
    unsigned int count;
    WorldCollisionObject_27d0f0 **colliders;
    char dirty;

    StateProp(StateProp *src);
};

StateProp::StateProp(StateProp *src)
{
    f40 = src->f40;
    f44 = src->f44;
    f88 = 0;
    b8c = src->b8c;
    f90 = 0;
    group = 0;
    material = 0;
    holder = 0;
    table = 0;
    count = 0;
    dirty = 0;
    name.FUN_0027af70(&src->group->name);

    Group_27d0f0 *g = src->group;
    if (g)
        g->AddRef();
    if (group)
        group->Release();
    group = g;

    Material_27d0f0 *m = src->material->Clone();
    if (m)
        m->AddRef();
    if (material)
        material->Release();
    material = m;
    if (m->f48 == 0)
        m->FUN_002998d0(0);
    if (material->f4c)
        material->f4c->FUN_00284ad0(1);
    if (material->f50)
        material->f50->FUN_00284ad0(1);

    matrix = src->matrix;

    if (((int)((char *)group->shapes.end - (char *)group->shapes.begin) & ~3) > 0) {
        int i = 0;
        do {
            WorldCollisionObject_27d0f0 *c = src->colliders[i];
            if (c == 0) {
                colliders[i] = 0;
            } else {
                void *source = c->source;
                CollisionMesh_27d0f0 *s = (CollisionMesh_27d0f0 *)FUN_0008d690(0xd4);
                CollisionMesh_27d0f0 *obj;
                if (s)
                    obj = s->FUN_002f3630(source);
                else
                    obj = 0;
                obj->FUN_002f39e0(&matrix);
                WorldCollisionObject_27d0f0 *w = (WorldCollisionObject_27d0f0 *)thunk_FUN_0008d690(0x18);
                if (w)
                    w = w->FUN_002fe1a0(obj);
                colliders[i] = w;
                colliders[i]->AddRef();
                dirty = 1;
            }
            i++;
        } while (i < (group->shapes.end - group->shapes.begin));
    }

    if (group->f14) {
        PhysicsInstance_27d0f0 *h = (PhysicsInstance_27d0f0 *)FUN_0008d690(0x18);
        if (h) {
            int a = group->f14;
            int b = group->f18;
            int tmp1 = material->Hash();
            h = h->FUN_002fc740(a, b, tmp1, 0);
        }
        if (h)
            h->AddRef();
        if (holder)
            holder->Release();
        holder = h;
        void * tmp1 = src->holder->FUN_002fc6f0();
        holder->FUN_002fc700(tmp1, 0);
    }

    if (group) {
        if (((int)((char *)group->shapes.end - (char *)group->shapes.begin) & ~3) > 0) {
            int i = 0;
            do {
                unsigned int v = group->shapes.begin[i]->priority;
                if (v > count)
                    count = v;
                i++;
            } while (i < (group->shapes.end - group->shapes.begin));
        }
        table = FUN_0008d6d0(count * 24);
        memset(table, 0, count * 24);
    }
    f94 = 0;
}
}
}
} // namespace fn_0027d0f0


// 0x0027d3e0 pure3d::prop::StateProp::vfunc_4 (34 B): matches/0x0027d3e0.cpp
// sym: ?vfunc_4@StateProp@prop@pure3d@@UAEPAXXZ
void* pure3d::prop::StateProp::vfunc_4() {
    void* p = thunk_FUN_0008d690(0xe8);
    if (p)
        return (void*)(((Obj_27d3e0*)p)->call_0027d0f0(this));
    return (void*)(0);
}

namespace fn_f03c5b48 {

// 0x0027d410 FUN_0027d410 (119 B): equivalent/0x0027d410.cpp
// sym: ?FUN_0027d410@Selector_27d410@fn_f03c5b48@@QAEXPBI@Z
// STATUS: equivalent (tools/equiv.py level 3: 170 inputs, branch coverage 8/8)
// FUN_0027d410 @ 0x0027d410
void Selector_27d410::FUN_0027d410(const unsigned int* id) {
    int index = -1;
    hulk_intptr n = list->end - list->begin;
    unsigned int a = id[0];
    unsigned int b = id[1];
    Key_27d410** it = list->begin;
    for (int i = 0; i < n; ++i, ++it) {
        if ((*it)->a == a && (*it)->b == b) {
            index = i;
            break;
        }
    }
    Select(index, 1);
}


// 0x0027d4f0 FUN_0027d4f0 (139 B): matches/0x0027d4f0.cpp
// sym: ?FUN_0027d4f0@Node@fn_f03c5b48@@QAEXH@Z
// FUN_0027d4f0 @ 0x0027d4f0
void Node::FUN_0027d4f0(int key) {
    if (index == -1) return;
    for (int i = 0; i < childCount; i++) {
        if (child[i].flags & 8)
            child[i].node->FUN_0027d4f0(key);
    }
    Entry_27d4f0* e = table->entries[index];
    int n = e->count;
    for (int k = 0; k < n; k++) {
        Item_27d4f0* it = (Item_27d4f0*)((char*)e->items + k * 0x10);
        if (it->key == key)
            Fire(it->target, 1);
    }
}

} // namespace fn_f03c5b48

// 0x0027d580 FUN_0027d580 (147 B): equivalent/0x0027d580.cpp [wrapped: conflict: Node]
// sym: ?FUN_0027d580@Node@fn_0027d580@@QAEXHH@Z
namespace fn_0027d580 {
// STATUS: equivalent (tools/equiv.py level 3: 177 inputs, branch coverage 14/14)
// FUN_0027d580 @ 0x0027d580
class Node;

struct ChildLink {
    Node *node;             // 0x0
    int pad4;
    unsigned char flags;    // 0x8
    char pad9[3];
};

struct Record_27d580 {
    int keyA;               // 0x0
    int keyB;               // 0x4
    int pad8;
    int value;              // 0xc
};

struct Group_27d580 {
    char pad0[0x24];
    int recordCount;        // 0x24
    Record_27d580 *records;        // 0x28
};

struct Table_27d580 {
    char pad0[0x1c];
    Group_27d580 **groups;         // 0x1c
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
    virtual void v15();
    virtual void Trigger(int value, int flag);      // slot 16

    char pad4[0x40 - 4];
    int groupIndex;         // 0x40
    char pad44[0x98 - 0x44];
    Table_27d580 *table;           // 0x98
    char pad9c[0xb4 - 0x9c];
    int childCount;         // 0xb4
    ChildLink children[1];  // 0xb8

    void FUN_0027d580(int keyA, int keyB);
};

void Node::FUN_0027d580(int keyA, int keyB)
{
    for (int i = 0; i < childCount; i++) {
        if (children[i].flags & 8)
            children[i].node->FUN_0027d580(keyA, keyB);
    }

    Group_27d580 *g = table->groups[groupIndex];
    int recordCount = g->recordCount;
    for (int i = 0; i < recordCount; i++) {
        Record_27d580 *r = &g->records[i];
        if (r->keyA == keyA && r->keyB == keyB)
            Trigger(r->value, 1);
    }
}
} // namespace fn_0027d580


// 0x0027d620 pure3d::prop::StateProp::vfunc_12 (94 B): equivalent/0x0027d620.cpp
// sym: ?vfunc_12@StateProp@prop@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::prop::StateProp::vfunc_12 @ 0x0027d620
void pure3d::prop::StateProp::vfunc_12() {
    (*(Source * *)&this->f_9c)->vfunc_12();
    Source *s = (*(Source * *)&this->f_9c);
    for (int i = 0; i < 6; ++i) (*(unsigned int (*)[6])&this->f_14)[i] = s->position[i];
    s = (*(Source * *)&this->f_9c);
    for (int i = 0; i < 4; ++i) (*(unsigned int (*)[4])&this->f_2c)[i] = s->bounds[i];
}


// 0x0027d680 pure3d::prop::StateProp::vfunc_13 (50 B): matches/0x0027d680.cpp
// sym: ?vfunc_13@StateProp@prop@pure3d@@UAEXPAX@Z
void pure3d::prop::StateProp::vfunc_13(void* __p0) { Child_27d680 * p = (Child_27d680 *)__p0;

    if (p)
        p->f0();
    Ref_27d680*& cur = (*(Ref_27d680 * *)&this->f_10);
    if (cur)
        cur->f1();
    cur = (Ref_27d680*)p;
    (*(H * *)&this->f_9c)->a13(p);
}

namespace fn_f03c5b48 {

// 0x0027d6c0 FUN_0027d6c0 (190 B): equivalent/0x0027d6c0.cpp
// sym: ?remove@Container_27d6c0@fn_f03c5b48@@QAE_NPAUObject@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 167 inputs, branch coverage 11/12, incomplete)
// FUN_0027d6c0 @ 0x0027d6c0
bool Container_27d6c0::remove(Object* object) {
    if (!object) return false;
    int index;
    for (index = 0; index < count; ++index) {
        if (entries[index].object == object) break;
    }
    if (index >= count) return false;
    Entry_27d6c0& entry = entries[index];
    entry.state = 0;
    if (entry.object) {
        entry.object->release();
        entry.object = 0;
    }
    int last = count - 1;
    count = last;
    if (index < last) {
        entry.object = entries[last].object;
        entry.state = entries[last].state;
        entry.extra = entries[last].extra;
        entries[count].object = 0;
        entries[count].state = 0;
    }
    return true;
}

} // namespace fn_f03c5b48

// 0x0027d780 FUN_0027d780 (942 B): equivalent/0x0027d780.cpp [wrapped: conflict: Node]
// sym: ?FUN_0027d780@Scene_27d780@fn_0027d780@@QAEXXZ
namespace fn_0027d780 {
// STATUS: equivalent (tools/equiv.py level 3: 415 inputs, branch coverage 60/60)
// FUN_0027d780 @ 0x0027d780
// equiv-map: ?thunk_FUN_002ee510@Cache@@QAEXPAUChoice@@@Z = 0x002ee700

struct Choice {
    char pad[0x10];
    int value;
};

struct Cache {
    void thunk_FUN_002ee510(Choice* c);
    void FUN_002ee6d0(Choice* c);
};


class Node {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int a, int b);
    virtual void vfunc_7();
    virtual void vfunc_8(int v);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(float v);
    virtual float vfunc_13();
    virtual void vfunc_14(float a, float b);
    virtual void vfunc_15();
    virtual void vfunc_16(int v);
    virtual void vfunc_17();
    virtual void vfunc_18(int v);
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

class Child_27d780 {
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
    void FUN_002a3b60();
};

struct Elem_27d780 {
    char pad00[0xc];
    int f0c;
    char flag;
    char pad11[3];
    float lo;
    float hi;
    int f1c;
};

struct Flag16 {
    char pad00[8];
    unsigned char flag;
    char pad09[7];
};

struct Entry_27d780 {
    char pad00[0x18];
    Flag16* flags;
    char pad1c[4];
    Elem_27d780* elems;
};

struct Table_27d780 {
    char pad00[0x1c];
    Entry_27d780** begin;
    Entry_27d780** end;
};

struct Item12 {
    int f0;
    int f4;
    Child_27d780* child;
};

struct Group_27d780 {
    char pad00[0x3c];
    Item12* begin;
    Item12* end;
    void FUN_002987d0(unsigned int i);
};

struct Nodes_27d780 {
    char pad00[0x24];
    Node** begin;
    Node** end;
    void FUN_00299230(unsigned int i);
    void FUN_002989c0(unsigned int i);
};

struct Board {
    char pad00[0x44];
    Group_27d780* group;
    Nodes_27d780* nodes;
};

class Marker_27d780 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    char active;
};

struct Marks {
    char pad00[0x1f8];
    Marker_27d780** items;
    char pad1fc[4];
    int count;
};

struct Gadget_27d780 {
    char pad00[0x70];
    Marks* marks;
    char pad74[0x84 - 0x74];
    char flag84;
    char flag85;
    void FUN_002fd4b0(int a, int b);
    void FUN_002fd4f0();
    void FUN_002fe2c0();
    void FUN_002fe420(Board* b);
    void FUN_002fe2e0();
};

struct Holder_27d780 {
    char pad00[0x10];
    Gadget_27d780* gadget;
    void FUN_002fc670(int v);
};

struct Frame_27d780 {
    float lo;
    float hi;
    float cur;
    union {
        unsigned char b;
        unsigned int w;
    } i;
    int off20;
    union {
        int off4;
        unsigned char b;
        unsigned int w;
    } j;
    Entry_27d780* x;
    Group_27d780* d;
    void* self;
};

class Scene_27d780 {
public:
    virtual void vfunc_0();
    char pad04[0x40 - 4];
    int current;
    char pad44[0x98 - 0x44];
    Table_27d780* table;
    Board* board;
    Holder_27d780* holder;
    char pada4[0xac - 0xa4];
    Choice** choices;
    void FUN_0027d780();
};

void Scene_27d780::FUN_0027d780()
{
    Frame_27d780 f;
    Entry_27d780* x = table->begin[current];
    Board* b = board;
    Nodes_27d780* nodes = b->nodes;
    Group_27d780* group = b->group;
    hulk_intptr total = nodes->end - nodes->begin;
    f.x = x;
    f.d = group;
    f.self = this;
    unsigned char n = (unsigned char)total;
    f.i.b = 0;
    if (n != 0) {
        f.off20 = 0;
        f.j.off4 = 0;
        do {
            Elem_27d780* e = (Elem_27d780*)((char*)f.x->elems + f.off20);
            Node* node = *(Node**)((char*)nodes->begin + f.j.off4);
            f.lo = e->lo;
            f.hi = e->hi;
            if (f.lo == f.hi && !e->flag) {
                nodes->FUN_00299230(f.i.w);
                node->vfunc_23();
                node->vfunc_14(f.lo, f.hi);
                node->vfunc_6(0, 1);
            } else {
                nodes->FUN_002989c0(f.i.w);
                f.cur = node->vfunc_13();
                if (!e->flag) {
                    node->vfunc_23();
                } else {
                    if ((f.cur > f.lo && f.cur > f.hi) || (f.cur < f.lo && f.cur < f.hi))
                        f.lo = f.cur;
                }
                node->vfunc_8(e->f1c);
                if (f.lo > f.hi) {
                    node->vfunc_16(3);
                    node->vfunc_14(f.hi, f.lo);
                } else {
                    node->vfunc_16(2);
                    node->vfunc_14(f.lo, f.hi);
                }
                node->vfunc_18(e->f0c);
                if (!e->flag)
                    node->vfunc_12(f.lo);
            }
            f.i.b++;
            f.off20 += 0x20;
            f.j.off4 += 4;
        } while (f.i.b < n);
        group = f.d;
    }

    ((owners::Obj_2988e0 *)group)->FUN_002988e0();
    hulk_intptr total2 = group->end - group->begin;
    unsigned char n2 = (unsigned char)total2;
    f.j.b = 0;
    if (n2 != 0) {
        f.off20 = 0;
        int off12 = 0;
        do {
            Flag16* fl = (Flag16*)((char*)f.x->flags + f.off20);
            if (fl->flag == 1) {
                group->FUN_002987d0(f.j.w);
            } else {
                Child_27d780* child = *(Child_27d780**)((char*)group->begin + off12 + 8);
                if (child) {
                    if (child->vfunc_15() == 4)
                        child->FUN_002a3b60();
                }
            }
            f.j.b++;
            f.off20 += 0x10;
            off12 += 12;
        } while (f.j.b < n2);
    }

    Scene_27d780* self = (Scene_27d780*)f.self;
    Table_27d780* t = self->table;
    for (int k = 0; k < (int)(t->end - t->begin); k++) {
        Choice* ch = self->choices[k];
        if (ch)
            (*(Cache**)&DAT_00554c14)->thunk_FUN_002ee510(ch);
        t = self->table;
    }
    Choice* cc = self->choices[self->current];
    if (cc)
        (*(Cache**)&DAT_00554c14)->FUN_002ee6d0(cc);

    if (!self->holder)
        return;
    Gadget_27d780* g = self->holder->gadget;
    if (g->flag84) {
        ((owners::C_2fd4a0 *)g)->FUN_002fd4a0();
        for (unsigned int k = 0; k < n2; k++)
            g->FUN_002fd4b0(f.d->begin[k].f4, f.x->flags[k].flag);
        Marks* m = g->marks;
        bool found = false;
        if (m) {
            for (int k = 0; k < m->count; k++) {
                Marker_27d780* mk = m->items[k];
                if (mk->active) {
                    if (mk->vfunc_7() > 0.0f) {
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found)
            self->holder->FUN_002fc670(2);
        g->FUN_002fd4f0();
    } else if (g->flag85) {
        g->FUN_002fe2c0();
        g->FUN_002fe420(self->board);
        g->FUN_002fe2e0();
    }
}
} // namespace fn_0027d780

namespace fn_f03c5b48 {

// 0x0027db30 FUN_0027db30 (294 B): equivalent/0x0027db30.cpp
// sym: ?run@Target_27db30@fn_f03c5b48@@QAEXPAVPhysicsInstance@physics@@IIIIIIII@Z
// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 8/8)
// FUN_0027db30 @ 0x0027db30
void Target_27db30::run(physics::PhysicsInstance* parent,U_27db30 a,U_27db30 b,U_27db30 x,U_27db30 y,U_27db30 z,U_27db30 rx,U_27db30 ry,U_27db30 rz) {
 if (!holder || !holder->entity->active) return;
 unsigned char selection = owner->selector->FUN_00298960(&a);
 U_27db30 id = owner->selector->records[selection].id;
 Spawned_27db30* object = holder->entity->FUN_002fdf40(id,a,b);
 if (!object) return;
 U_27db30 value = holder->entity->FUN_002ef4a0();
 object->FUN_002ef440(value);
 object->service->FUN_002fe6b0((*(hulk_uintptr*)&DAT_00554c10));
 Entity_27db30* entity = holder->entity;
 SpawnVtable* table = *reinterpret_cast<SpawnVtable**>(object);
 value = entity->v4(id,0);
 table->slots[6](object,0,value);
 ((owners::C_2fd4a0 *)entity)->FUN_002fd4a0();
 entity->FUN_002fd4b0(id,0);
 entity->FUN_002fd4f0();
 Child_27db30* child = parent ? ((PhysicsInstance_nv_27db30*)(((physics::PhysicsInstance*)(parent))))->FUN_002fc880(object,0) : 0;
 Transform_27db30* transform = child->transform;
 transform->position[0]=x;
 transform->position[1]=y;
 transform->position[2]=z;
 transform = child->transform;
 transform->rotation[0]=rx;
 transform->rotation[1]=ry;
 transform->rotation[2]=rz;
 child->v0();
}


// 0x0027dca0 FUN_0027dca0 (130 B): equivalent/0x0027dca0.cpp
// sym: ?FUN_0027dca0@Chain_27dca0@fn_f03c5b48@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 19468 inputs, branch coverage 4/4)
// FUN_0027dca0 @ 0x0027dca0
void Chain_27dca0::FUN_0027dca0()
{
    Event_27dca0 ev;
    Id64_27dca0 empty;

    ev.id.FUN_0027af00();
    ev.type = -1;
    empty.FUN_0027b0e0(((char*)&DAT_003f335c));
    ev.id.FUN_0027af70(&empty);
    empty.FUN_0027af50();
    ev.value = 0;

    for (int i = 0; i < count; i++)
        handlers[i]->vfunc_0(&ev, this);

    ev.id.FUN_0027af50();
}


// 0x0027dd30 FUN_0027dd30 (164 B): equivalent/0x0027dd30.cpp
// sym: ?FUN_0027dd30@Player_27dd30@fn_f03c5b48@@QAEXPAUEffectList@2@MM@Z
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 14/14)
// FUN_0027dd30 @ 0x0027dd30
void Player_27dd30::FUN_0027dd30(EffectList *list, float lo, float hi)
{
    if (!(DAT_0052c298 & 1)) {
        DAT_0052c298 |= 1;
        unsigned __int64 id = FUN_0027b020("Effect");
        DAT_0052c290 = (unsigned int)id;
        DAT_0052c294 = (unsigned int)(id >> 32);
    }
    for (int i = 0; i < list->count; i++) {
        Effect_27dd30 *e = &list->items[i];
        if (e->idLo == DAT_0052c290 && e->idHi == DAT_0052c294 && e->time >= lo && e->time < hi)
            FUN_0027cd10(e);
    }
}


// 0x0027dde0 FUN_0027dde0 (102 B): equivalent/0x0027dde0.cpp
// sym: ?FUN_0027dde0@Obj_27dde0@fn_f03c5b48@@QAEPAHPBX@Z
// STATUS: equivalent (tools/equiv.py level 3: 376 inputs, branch coverage 6/6)
// FUN_0027dde0 @ 0x0027dde0
int* Obj_27dde0::FUN_0027dde0(const void* src) {
    int* range = &group->begin;
    memcpy(matrix, src, 0x40);
    int i = 0;
    if (0 < (int)((range[1] - range[0]) & 0xfffffffc)) {
        do {
            if (elems[i] != 0)
                elems[i]->target->FUN_002f39e0(matrix);
            range = &group->begin;
            i++;
        } while (i < (range[1] - range[0]) >> 2);
    }
    return range;
}


// 0x0027de50 FUN_0027de50 (90 B): equivalent/0x0027de50.cpp
// sym: ?FUN_0027de50@Owner@fn_f03c5b48@@QAEPAHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2945 inputs, branch coverage 6/6)
// FUN_0027de50 @ 0x0027de50
int *Owner::FUN_0027de50(int a,hulk_intptr b) { int i=0; Range *r=range; if (((r->end-r->begin)&~3)>0) { do { Entry *e=entries[i]; if(e) { Values *v=e->values; v->first=a; v->second=b; } r=range; int end=r->end; int begin=r->begin; ++i; if (!(i < (end-begin)>>2)) break; } while (true); } return (int *)&r->begin; }

} // namespace fn_f03c5b48

// 0x0027ded0 content::LoadInventory::DynamicCaster<pure3d::prop::StatePropData>::vfunc_0 (30 B): matches/0x0027ded0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VStatePropData@prop@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::prop::StatePropData>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x0027def0 FUN_0027def0 (988 B): equivalent/0x0027def0.cpp [wrapped: conflict: pure3d::DrawableHierarchy; pure3d::prop::StateProp]
// sym: ??0StateProp@prop@pure3d@fn_0027def0@@QAE@PAVGroup_27def0@3@H@Z
namespace fn_0027def0 {
// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 59/64, incomplete)
// FUN_0027def0 @ 0x0027def0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif


void *FUN_0008d690(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);

struct Name_27def0 {
    int w0;
    int w1;
    void FUN_0027af70(Name_27def0 *other);
};

struct Matrix16_27def0 {
    unsigned int w[16];
    void FUN_0022b980();
};

class RefCounted_27def0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Flag_27def0 {
    void FUN_00284ad0(char value);
};

class Material_27def0 : public RefCounted_27def0 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual int Hash();
    char pad04[0x44];
    int f48;
    Flag_27def0 *f4c;
    Flag_27def0 *f50;
    void FUN_002998d0(int arg);
};

struct Source_27def0 {
    char pad0[8];
    Name_27def0 name;
    void *source;
};

class Collider_27def0 : public RefCounted_27def0 {
public:
    char pad04[4];
    Name_27def0 name;
    void *source;
    Collider_27def0 *FUN_002fe1a0(void *source);
};

struct Shape_27def0 {
    char pad0[0x2c];
    unsigned int priority;
    char pad30[0x1c];
    Source_27def0 *src;
};

struct ShapeObj_27def0 {
    ShapeObj_27def0 *FUN_002f3630(void *source);
};

struct PtrVec_27def0 {
    Shape_27def0 **begin;
    Shape_27def0 **end;
};

class Holder_27def0 : public RefCounted_27def0 {
public:
    char pad04[0xc];
    void *p10;
    Holder_27def0 *FUN_002fc740(void *a, int b, int c, int d);
    void FUN_002fc670(int v);
};

struct Kind_27def0 {
    char pad0[0x78];
    int kind;
};

class Part_27def0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Material_27def0 *v4();
};

class Group_27def0 : public RefCounted_27def0 {
public:
    char pad04[4];
    Name_27def0 name;
    Part_27def0 *p10;
    Kind_27def0 *f14;
    Part_27def0 *part() { return p10; }
    int f18;
    PtrVec_27def0 shapes;
};

namespace pure3d {
class __declspec(novtable) DrawableHierarchy {
public:
    virtual void d0();
    char pad4[4];
    Name_27def0 name;
    char pad10[0x30];
    void FUN_002a3480();
    DrawableHierarchy() throw() { FUN_002a3480(); }
};

namespace prop {
class StateProp : public DrawableHierarchy {
public:
    virtual void s1();
    int f40;
    int f44;
    Matrix16_27def0 matrix;
    int f88;
    char b8c;
    char pad8d[3];
    int f90;
    int f94;
    Group_27def0 *group;
    Material_27def0 *material;
    Holder_27def0 *holder;
    void *table;
    unsigned int count;
    Collider_27def0 **colliders;
    char dirty;
    char padb1[3];
    int fb4;
    int tail[12];
    void FUN_0027d780();

    StateProp(Group_27def0 *a, int b);
};

StateProp::StateProp(Group_27def0 *a, int b)
{
    f40 = b;
    f44 = 0;
    f88 = 0;
    b8c = 1;
    f90 = 0;
    group = 0;
    material = 0;
    holder = 0;
    table = 0;
    count = 0;
    colliders = 0;
    dirty = 0;
    fb4 = 0;
    name.FUN_0027af70(&a->name);
    if (a)
        a->AddRef();
    if (group)
        group->Release();
    group = a;

    Material_27def0 *m = a->part()->v4();
    if (m)
        m->AddRef();
    if (material)
        material->Release();
    material = m;
    if (m->f48 == 0)
        m->FUN_002998d0(0);
    if (material->f4c)
        material->f4c->FUN_00284ad0(1);
    if (material->f50)
        material->f50->FUN_00284ad0(1);

    matrix.FUN_0022b980();

    Kind_27def0 *k = group->f14;
    if (k) {
        bool two = k->kind == 2;
        Holder_27def0 *h = (Holder_27def0 *)FUN_0008d690(0x18);
        if (h) {
            Kind_27def0 *fk = group->f14;
            int fv = group->f18;
            h = h->FUN_002fc740(fk, fv, material->Hash(), two);
        }
        if (h)
            h->AddRef();
        if (holder)
            holder->Release();
        holder = h;
        h->FUN_002fc670(2);
        if (material->f4c)
            material->f4c->FUN_00284ad0(1);
        if (material->f50)
            material->f50->FUN_00284ad0(1);
    }

    if ((hulk_uintptr)a >= 1u) {
        if (((int)((char *)a->shapes.end - (char *)a->shapes.begin) & ~3) > 0) {
            int i = 0;
            do {
                unsigned int v = a->shapes.begin[i]->priority;
                if (v > count)
                    count = v;
                i++;
            } while (i < (a->shapes.end - a->shapes.begin));
        }
        void *t = FUN_0008d6d0(count * 24);
        table = t;
        memset(t, 0, count * 24);
    }

    colliders = (Collider_27def0 **)FUN_0008d6d0((a->shapes.end - a->shapes.begin) * 4);
    int fin = 0;
    if (((hulk_uintptr)a >= 1u) && ((int)((char *)a->shapes.end - (char *)a->shapes.begin) & ~3) > 0) {
        int j = 0;
        do {
            Source_27def0 *s = a->shapes.begin[j]->src;
            if (s == 0) {
                colliders[j] = 0;
            } else {
                Collider_27def0 *found = 0;
                for (int k2 = 0; k2 < j; k2++) {
                    Collider_27def0 *c = colliders[k2];
                    if (c != 0 && c->name.w0 == s->name.w0 && c->name.w1 == s->name.w1) {
                        found = c;
                        break;
                    }
                }
                if (found) {
                    colliders[j] = found;
                    colliders[j]->AddRef();
                    dirty = 1;
                } else {
                    ShapeObj_27def0 *so = (ShapeObj_27def0 *)FUN_0008d690(0xd4);
                    void *sobj;
                    if (so)
                        sobj = so->FUN_002f3630(s->source);
                    else
                        sobj = 0;
                    Collider_27def0 *w = (Collider_27def0 *)thunk_FUN_0008d690(0x18);
                    if (w)
                        w = w->FUN_002fe1a0(sobj);
                    colliders[j] = w;
                    colliders[j]->name.FUN_0027af70(&s->name);
                    colliders[j]->AddRef();
                    dirty = 1;
                }
            }
            j++;
        } while (j < (a->shapes.end - a->shapes.begin));
    }
    f94 = fin;
    memset(tail, 0, sizeof(tail));
    FUN_0027d780();
}
}
}
} // namespace fn_0027def0


// 0x0027e2d0 FUN_0027e2d0 (481 B): equivalent/0x0027e2d0.cpp [wrapped: conflict: pure3d::prop::StateProp]
// sym: ??1StateProp@prop@pure3d@fn_0027e2d0@@QAE@XZ
namespace fn_0027e2d0 {
// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 31/34, incomplete)
// FUN_0027e2d0 @ 0x0027e2d0

struct Ref_27e2d0 { virtual void slot0(); virtual void release(); };
struct Item_27e2d0 : Ref_27e2d0 { char pad[0xc]; unsigned key; char pad2[0x60]; unsigned handle; };
struct State_27e2d0 { char pad[0x2c]; int count; };
struct Data_27e2d0 : Ref_27e2d0 { char pad[0x18]; State_27e2d0 **begin; State_27e2d0 **end; };
struct Entry_27e2d0 { unsigned unused[4]; Item_27e2d0 *object; Ref_27e2d0 *extra; };
struct Attachment_27e2d0 { Ref_27e2d0 *object; unsigned unused[2]; };
struct Manager_27e2d0 { void FUN_002eecb0(unsigned); void FUN_002ee700(Item_27e2d0*); };
struct Registry_27e2d0 { void FUN_002834b0(unsigned); };
extern Registry_27e2d0 *__cdecl FUN_0027f250();
extern void __cdecl FUN_0008d330(void*);
extern void __cdecl FUN_0008d340(void*);
struct DrawableHierarchy_27e2d0 { virtual void slot0(); void FUN_002a35f0(); };
namespace pure3d { namespace prop {
struct StateProp : DrawableHierarchy_27e2d0 {
 virtual void slot0();
 ~StateProp();
 char pad0[0x3c]; int stateIndex; char pad1[0x44]; Ref_27e2d0 *resource; char pad2[0xc]; Data_27e2d0 *data; Ref_27e2d0 *other1; Ref_27e2d0 *other2; Entry_27e2d0 *entries; unsigned entryCount; Item_27e2d0 **items; unsigned unknown; int attachmentCount; Attachment_27e2d0 attachments[1];
};
StateProp::~StateProp() {
 int count = data->begin[stateIndex]->count;
 for(int i=0;i<count;++i) {
  Entry_27e2d0 *e=entries+i;
  if(e->object) {
   (*(Manager_27e2d0**)&DAT_00554c14)->FUN_002eecb0(e->object->handle);
   e->object->release();
   if(e->extra) e->extra->release();
  }
 }
 for(int j=0;j < data->end-data->begin;++j) {
  if(items[j]) {
   Registry_27e2d0 *r=FUN_0027f250();
   if(r) r->FUN_002834b0(items[j]->key);
   if((*(Manager_27e2d0**)&DAT_00554c14)) (*(Manager_27e2d0**)&DAT_00554c14)->FUN_002ee700(items[j]);
  }
  Item_27e2d0 **p=items+j;
  if(*p) { (*p)->release(); *p=0; }
 }
 FUN_0008d330(items);
 for(int k=0;k<attachmentCount;++k) {
  Attachment_27e2d0 *a=attachments+k;
  if(a->object) { a->object->release(); a->object=0; }
 }
 unsigned bytes=entryCount*24u;
 unsigned *words=(unsigned*)entries;
 for(unsigned n=0;n<(bytes>>2);++n) words[n]=0;
 FUN_0008d340(entries);
 if(resource) { resource->release(); resource=0; }
 if(data) { data->release(); data=0; }
 if(other1) { other1->release(); other1=0; }
 if(other2) { other2->release(); other2=0; }
 FUN_002a35f0();
}
}}
} // namespace fn_0027e2d0


// 0x0027e4c0 pure3d::prop::StateProp::vfunc_16 (389 B): equivalent/0x0027e4c0.cpp [wrapped: conflict: FUN_0027f250]
// sym: ?FUN_0027e4c0@StateProp_27e4c0@fn_0027e4c0@@QAEXH_N@Z
namespace fn_0027e4c0 {
// STATUS: equivalent (tools/equiv.py level 3: 287 inputs, branch coverage 34/34)
// pure3d::prop::StateProp::vfunc_16 @ 0x0027e4c0
// equiv-map: ?thunk_FUN_002ee510@Cache@@QAEXPAUChoice@@@Z = 0x002ee700
// equiv-map: ?thunk_FUN_002ee710@Cache@@QAEXH@Z = 0x002eecb0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif


struct Res_27e4c0 {
    virtual void vfn0();
    virtual void vfn1();
};
struct Stage_27e4c0 {
    virtual void vfn0();
    virtual void vfn1();
    char pad[0x74 - 4];
    int key;                 // 0x74
};
struct Slot_27e4c0 {                // 0x18 bytes
    char pad0[0x10];
    Stage_27e4c0 *stage;            // 0x10
    Res_27e4c0 *aux;                // 0x14
};
struct Choice {
    char pad[0x10];
    int value;               // 0x10
};
struct Cache {
    void thunk_FUN_002ee710(int key);
    void thunk_FUN_002ee510(Choice *c);
    void FUN_002ee6d0(Choice *c);
};
struct Entry_27e4c0 {
    char pad[0x2c];
    int slotCount;           // 0x2c
};
struct Table_27e4c0 {
    char pad[0x1c];
    Entry_27e4c0 **entries;         // 0x1c
    Entry_27e4c0 **entriesEnd;      // 0x20
};
struct Layout_27e4c0 {
    void FUN_00283460(int a, int b, int c);
    void FUN_002834b0(int v);
};
Layout_27e4c0 *FUN_0027f250();

class StateProp_27e4c0 {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(int a, int b);
    char pad04[4];
    int f8;
    int fc;
    char pad10[0x40 - 0x10];
    int current;             // 0x40
    int f44;
    char pad48[0x88 - 0x48];
    Res_27e4c0 *f88;
    char f8c;
    char pad8d[0x98 - 0x8d];
    Table_27e4c0 *table;            // 0x98
    char pad9c[0xa4 - 0x9c];
    Slot_27e4c0 *slots;             // 0xa4
    int slotsPerEntry;       // 0xa8
    Choice **choices;        // 0xac
    void FUN_0027d780();
    void FUN_0027dca0();
    void FUN_0027e4c0(int index, bool notify);
};

void StateProp_27e4c0::FUN_0027e4c0(int index, bool notify)
{
    if (index < 0) return;
    if (index >= (int)(table->entriesEnd - table->entries)) return;
    if (current == -1) {
        if (f88 != 0) {
            f88->vfn1();
            f88 = 0;
        }
    }
    Layout_27e4c0 *layout = FUN_0027f250();
    if (layout != 0) {
        layout->FUN_00283460(f8, fc, 0);
    }
    if (current != -1) {
        int n = table->entries[current]->slotCount;
        for (int i = 0; i < n; i++) {
            Slot_27e4c0 *s = &slots[i];
            if (slots[i].stage != 0) {
                (*(Cache**)&DAT_00554c14)->thunk_FUN_002ee710(slots[i].stage->key);
                s->stage->vfn1();
                if (s->aux != 0)
                    s->aux->vfn1();
            }
        }
    }
    if (current != index && current != -1) {
        Choice *old = choices[current];
        if (old != 0) {
            if (old != choices[index]) {
                Layout_27e4c0 *l2 = FUN_0027f250();
                l2->FUN_002834b0(choices[current]->value);
            }
            (*(Cache**)&DAT_00554c14)->thunk_FUN_002ee510(choices[current]);
        }
        if (choices[index] != 0) {
            (*(Cache**)&DAT_00554c14)->FUN_002ee6d0(choices[index]);
        }
    }
    memset(slots, 0, slotsPerEntry * 24);
    current = index;
    f44 = 0;
    FUN_0027d780();
    if (notify)
        vfn6(0, 0);
    if (f8c == 1)
        FUN_0027dca0();
}
} // namespace fn_0027e4c0

namespace fn_f03c5b48 {

// 0x0027e650 FUN_0027e650 (260 B): equivalent/0x0027e650.cpp
// sym: ?FUN_0027e650@Controller_27e650@fn_f03c5b48@@QAEXPAUResource_27e650@2@MM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_0027e650 @ 0x0027e650
void Controller_27e650::FUN_0027e650(Resource_27e650* incoming, float start, float end) {
 if (resource) {
  if (!incoming) {
   resource->Release();
   resource = 0;
   state = 0;
   secondary = 0;
   FUN_0027d780();
   if (flag == 1) FUN_0027dca0();
   return;
  }
 } else if (!incoming) return;
 incoming->AddRef();
 if (resource) resource->Release();
 resource = incoming;
 state = -1;
 if (start > end) {
  resource->SetRange(end, start);
  resource->SetPosition(start);
  resource->SetMode(3);
  resource->Enable(1);
 } else {
  resource->SetRange(start, end);
  resource->SetPosition(start);
  resource->SetMode(2);
  resource->Enable(1);
 }
}

} // namespace fn_f03c5b48

// 0x0027e760 FUN_0027e760 (29 B): matches/0x0027e760.cpp
// sym: ?FUN_0027e760@Obj_27e760@owners@@QAEXI@Z
// Same code shape as 0x000238b0 (propagated; names are from that function)
void owners::Obj_27e760::FUN_0027e760(U_27e760 param) {
    U64_27e760 a = FUN_0027b020(param);
    Second(a);
}

namespace fn_f03c5b48 {

// 0x0027e780 FUN_0027e780 (260 B): equivalent/0x0027e780.cpp
// sym: ?target@Object@fn_f03c5b48@@QAEXPAUOutput_27e780@2@PAUInput_27e780@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0027e780 @ 0x0027e780
void Object::target(Output_27e780* output,Input_27e780* input) { Bones_27e780* bones=provider->v11(); Matrix local,result; switch(input->mode) { case 2: result.FUN_0022b980(); ((owners::Target_22be40 *)&result)->FUN_0022be40((const int *)(Input_27e780 *)input); ((owners::Matrix_22bc20 *)&result)->FUN_0022bc20(input->x, input->y, input->z); break; case 0: case 1: { int mode=input->mode; local.FUN_0022b980(); ((owners::Target_22be40 *)&local)->FUN_0022be40((const int *)(Input_27e780 *)input); ((owners::Matrix_22bc20 *)&local)->FUN_0022bc20(input->x, input->y, input->z); Matrix* parent; if(mode==0) { unsigned index=bones->FUN_002843a0(input->a,input->b); if(index!=65535) parent=&bones->matrices[index]; else parent=v15(); } else parent=v15(); ((owners::Matrix_22ca90 *)&result)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&local), (const owners::Matrix_22ca90 *)(Matrix *)parent); break; } } output->FUN_0027dde0(&result); }

} // namespace fn_f03c5b48

// 0x0027e8b0 pure3d::prop::StatePropLoader::vfunc_2 (31 B): matches/0x0027e8b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0027e8b0@@UAEPAV123@E@Z
namespace fn_0027e8b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_27e8b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_27e8b0 {
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
} // namespace fn_0027e8b0


// 0x0027e920 pure3d::prop::StateProp::vfunc_6 (1131 B): equivalent/0x0027e920.cpp [wrapped: conflict: StateProp]
// sym: ?v6@StateProp@fn_0027e920@@UAEXMTArg2_27e920@2@@Z
namespace fn_0027e920 {
// STATUS: equivalent (tools/equiv.py level 3: 16356 inputs, branch coverage 66/66)
// pure3d::prop::StateProp::vfunc_6 @ 0x0027e920
struct V3_27e920 {
    float x, y, z;
};
struct Mat16 {
    float m[16];
};

struct Seg_27e920 {
    char type;
    char pad1[3];
    int f4;
    float f8;
};
struct SubInfo {
    char pad0[8];
    int f8;
    int fc;
    float f10;
    V3_27e920 a;
    V3_27e920 b;
    char pad2c[4];
};
struct State_27e920 {
    char pad0[0x10];
    Seg_27e920 *seg;
    char pad14[0x2c - 0x14];
    int subCount;
    SubInfo *subs;
};
struct StateList {
    char pad0[0x1c];
    State_27e920 **states;
};

struct Pair_27e920 {
    int a;
    int b;
};
struct Info74 {
    char pad[8];
    int a;
    int b;
};
struct MatSource_27e920 {
    char pad[0x74];
    Info74 *info;
};
struct Table_27e920 {
    char pad[0x3c];
    int *rows;
    unsigned char FUN_00298960(Pair_27e920 *p);
};

struct Sink84 {
};
class Obj18_27e920 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float dt, int flag);
};

struct Entry_27e920 {
    char pad0[0x10];
    MatSource_27e920 *obj;
    char pad14[4];
    void FUN_002fc580(float t, int flag);
};

class MatOwner {
  public:
    virtual void m0();
    char pad[0x18];
    Mat16 *mats;
};

class Ctl88 : public Obj18_27e920 {
  public:
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
    virtual char v22();
};

struct Slot48 {
    char pad0[8];
    unsigned char count;
    char pad9[0x18 - 9];
    unsigned char *order;
    char pad1c[0x24 - 0x1c];
    Ctl88 **objs;
    void FUN_00299230(int idx);
};

struct Ctl9cB;
class Ctl9c : public Obj18_27e920 {
  public:
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Sink84 *v11();
    char pad[0x44 - 4];
    Table_27e920 *table;
    Slot48 *slot48;
};
class Ctl9cB : public Obj18_27e920 {
  public:
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual MatOwner *v11();
};

struct ListEntry {
    void *obj;
    int f4;
    unsigned char flags;
    char pad[3];
};

struct Frame_27e920 {
    float oldT;
    union {
        int cnt;
        Pair_27e920 pair;
    };
    State_27e920 *s;
    V3_27e920 b;
    V3_27e920 a;
};

union Arg2_27e920 {
    int v;
    char b;
};

class StateProp {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float dt, Arg2_27e920 a2);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int v15();
    virtual void v16(int a, int b);
    char pad04[0x40 - 4];
    int state;
    float t;
    char pad48[0x88 - 0x48];
    Ctl88 *p88;
    char b8c;
    char pad8d[0x98 - 0x8d];
    StateList *states;
    Ctl9c *p9c;
    Entry_27e920 *pa0;
    Entry_27e920 *pa4;
    char pada8[0xb4 - 0xa8];
    int entryCount;
    ListEntry entries[1];

    void FUN_0027e780(void *obj, int f4);
    void FUN_0027d780();
    void FUN_0027dca0();
    void FUN_0027cc60(State_27e920 *s, float a, float b);
    void FUN_0027dd30(State_27e920 *s, float a, float b);
    void FUN_0027db30(Entry_27e920 *e, int f8, int fc, V3_27e920 a, V3_27e920 b);
};

void StateProp::v6(float dt, Arg2_27e920 a2)
{
    for (int i = 0; i < entryCount; i++) {
        ListEntry *e = &entries[i];
        if (e->flags & 4)
            FUN_0027e780(e->obj, e->f4);
        if (e->flags & 1)
            ((Obj18_27e920 *)e->obj)->v6(dt, a2.v);
    }
    Frame_27e920 fr;
    fr.oldT = t;
    t = dt * 0.03f + t;
    if (state == -1) {
        char flag = a2.b;
        p88->v6(dt, a2.v);
        if (pa0)
            pa0->FUN_002fc580(dt * 0.001f, 0);
        if (((char)((owners::C_284ae0 *)p88)->FUN_00284ae0()) || flag) {
            Ctl9c *p = p9c;
            int r = v15();
            ((owners::C_284820 *)(p->v11()))->FUN_00284820((hulk_intptr)r);
        }
        if (flag == 1 && p88->v22() == flag) {
            if (p88) {
                p88->v1();
                p88 = 0;
            }
            state = 0;
            t = 0;
            FUN_0027d780();
            if (b8c == 1)
                FUN_0027dca0();
        }
        return;
    }
    fr.s = states->states[state];
    Seg_27e920 *seg = fr.s->seg;
    while (seg->type == 1 && seg->f8 >= fr.oldT && seg->f8 < t) {
        if (b8c == 1)
            FUN_0027cc60(fr.s, fr.oldT, seg->f8);
        if (state == seg->f4) {
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = seg->f8;
            bits.u &= 0x7fffffff;
            if (bits.f <= 1e-05f)
                break;
        }
        hulk_freg rem = t - seg->f8;
        v16(seg->f4, 0);
        dt = rem;
        t = dt;
        fr.s = states->states[state];
        seg = fr.s->seg;
        dt = dt * 33.333332f;
        fr.oldT = 0;
    }
    if (b8c == 1)
        FUN_0027cc60(fr.s, fr.oldT, t);
    FUN_0027dd30(fr.s, fr.oldT, t);
    Slot48 *sl = p9c->slot48;
    if (sl->count || a2.b)
        p9c->v6(dt, a2.v);
    unsigned int n = sl->count;
    while (n) {
        n--;
        unsigned char idx = sl->order[(unsigned char)n];
        if (sl->objs[idx]->v22())
            sl->FUN_00299230(sl->order[(unsigned char)n]);
    }
    if (!pa0)
        return;
    State_27e920 *cur = states->states[state];
    fr.cnt = cur->subCount;
    if (fr.cnt > 0) {
        int off1 = 0, off2 = 0;
        a2.v = fr.cnt;
        do {
            Entry_27e920 *e = (Entry_27e920 *)((char *)pa4 + off1);
            SubInfo *f = (SubInfo *)((char *)fr.s->subs + off2);
            if (!e->obj && f->f10 <= t) {
                fr.a = f->a;
                fr.b = f->b;
                FUN_0027db30(e, f->f8, f->fc, fr.a, fr.b);
            }
            off2 += 0x30;
            off1 += 0x18;
            a2.v--;
        } while (a2.v != 0);
    }
    dt = dt * 0.001f;
    pa0->FUN_002fc580(dt, 0);
    if (fr.cnt > 0) {
        int off = 0;
        a2.v = fr.cnt;
        do {
            Entry_27e920 *e = (Entry_27e920 *)((char *)pa4 + off);
            if (e->obj) {
                e->FUN_002fc580(dt, 0);
                fr.pair.a = ((Entry_27e920 *)((char *)pa4 + off))->obj->info->a;
                fr.pair.b = ((Entry_27e920 *)((char *)pa4 + off))->obj->info->b;
                unsigned char row = p9c->table->FUN_00298960(&fr.pair);
                Ctl9c *pp = p9c;
                int dstIndex = pp->table->rows[row * 3 + 1];
                Mat16 *src = ((Mat16 *)((owners::C_2fc6f0 *)(((Entry_27e920 *)((char *)pa4 + off))))->FUN_002fc6f0());
                MatOwner *owner = (MatOwner *)pp->v11();
                owner->mats[dstIndex] = *src;
            }
            off += 0x18;
            a2.v--;
        } while (a2.v != 0);
    }
}
} // namespace fn_0027e920

namespace fn_f03c5b48 {

// 0x0027ed90 FUN_0027ed90 (179 B): matches/0x0027ed90.cpp
// sym: ?FUN_0027ed90@Owner_27ed90@fn_f03c5b48@@QAE_NPAUObject@2@PAXI@Z
bool Owner_27ed90::FUN_0027ed90(Object* object, void* data, unsigned flags) {
    if (!object || !data || count >= 4)
        return false;
    if (flags & 4) {
        if (object->controller)
            object->controller->FUN_002fc670(2);
        FUN_0027e780(object, data);
    }
    Entry_27ed90* entry = &entries[count];
    object->AddRef();
    if (entry->object)
        entry->object->Release();
    entry->object = object;
    entries[count].data = data;
    entries[count].flags = flags;
    ++count;
    return true;
}

} // namespace fn_f03c5b48

// 0x0027eeb0 pure3d::prop::StatePropLoader::vfunc_5 (201 B): equivalent/0x0027eeb0.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster; pure3d::prop::StateProp; pure3d::prop::StatePropLoader]
// sym: ?vfunc_5@StatePropLoader@prop@pure3d@fn_0027eeb0@@UAEXPAPAUStateProp@234@PAIPAUReader@4@PAUInventory_27eeb0@4@@Z
namespace fn_0027eeb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::prop::StatePropLoader::vfunc_5 @ 0x0027eeb0
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

typedef unsigned __int64 U64_27eeb0;
struct Stream { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Reader { char pad[0x284]; Stream* stream; };
namespace pure3d { namespace prop { struct StatePropData; struct StateProp { char pad[8]; unsigned a,b; StateProp* FUN_0027def0(StatePropData*, int); }; } }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void vfunc_0(); }; } }
struct Inventory_27eeb0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual pure3d::prop::StatePropData* v3(content::LoadInventory::DynamicCaster<pure3d::prop::StatePropData>*, U64_27eeb0); };
extern void* __cdecl FUN_00263ea0(unsigned);
namespace pure3d { namespace prop { struct StatePropLoader { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(StateProp**, unsigned*, Reader*, Inventory_27eeb0*); }; } }
void pure3d::prop::StatePropLoader::vfunc_5(StateProp** out, unsigned* id, Reader* reader, Inventory_27eeb0* inventory) {
 struct { unsigned char padding[3]; unsigned char length; unsigned ignored; char name[256]; } local;
 reader->stream->FUN_002647e0(&local.ignored,1,4,1);
 reader->stream->FUN_002647e0(&local.length,1,1,1);
 unsigned n=local.length;
 reader->stream->FUN_002647e0(local.name,n,1,1);
 local.name[n]=0;
 U64_27eeb0 key=FUN_0027b020(local.name);
 content::LoadInventory::DynamicCaster<StatePropData> caster;
 StatePropData* data=inventory->v3(&caster,key);
 StateProp* obj=(StateProp*)FUN_00263ea0(0xe8);
 if(obj) obj=obj->FUN_0027def0(data,0);
 *out=obj;
 id[0]=obj->a;
 id[1]=obj->b;
}
} // namespace fn_0027eeb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0027f070 FUN_0027f070 (312 B): equivalent/0x0027f070.cpp
// sym: ?FUN_0027f070@Vertex_27f070@owners@@QAEXPBU12@0M@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0027f070 @ 0x0027f070
void owners::Vertex_27f070::FUN_0027f070(const owners::Vertex_27f070* from, const owners::Vertex_27f070* to, float t)
{
    x = (to->x - from->x) * t + from->x;
    y = (to->y - from->y) * t + from->y;
    z = (to->z - from->z) * t + from->z;
    r = (unsigned char)(int)((to->r - from->r) * t + from->r);
    g = (unsigned char)(int)((to->g - from->g) * t + from->g);
    b = (unsigned char)(int)((to->b - from->b) * t + from->b);
    a = (unsigned char)(int)((to->a - from->a) * t + from->a);
    u = (to->u - from->u) * t + from->u;
    v = (to->v - from->v) * t + from->v;
}

namespace fn_f03c5b48 {

// 0x0027f250 FUN_0027f250 (6 B): matches/0x0027f250.cpp
// sym: ?FUN_0027f250@fn_f03c5b48@@YAHXZ
// Same code shape as 0x00085cd0 (propagated; names are from that function)
hulk_intptr FUN_0027f250(void) {
    return *(hulk_intptr*)&DAT_0052c29c;
}

} // namespace fn_f03c5b48
