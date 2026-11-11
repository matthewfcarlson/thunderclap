// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fe570..0x002feae0 (kind game, layer engine, confidence high), dominant class physics::SimulatedObject
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fa862d6d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fa862d6d {} using namespace fn_fa862d6d;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fa862d6d {
namespace fight {
class Condition_2fe610 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
}
namespace fight {
class Param_2fe610 {
  public:
    virtual void pvfunc_0();
    virtual void pvfunc_1();
};
}
extern int physics_vftable;
class Child_2fe680 {
  public:
    virtual void f0();
    virtual void f1();
};
class SimulatedObject {
  public:
    SimulatedObject();
    union { void* vftable; hulk_intptr vptr; };
    char _m_pad_4[0xc];
    int field10;
    char _m_pad_14[0x4];
    int field18;
    union { int field1c; Child_2fe680* member; };
    unsigned char field20;
    char _m_pad_21[0x3];
    int field24;
    int field28;
    void Init();
    void Finish();
};
struct SimulatedObject_2fe680 {
    void Tail();
};
extern int gVtable_2fe680;
class C_2fe6a0 {
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
    char pad[0x18 - 4];
    int value;
    void set(int x);
};
class Ref_2fe6b0 {
  public:
    virtual void Init();
    virtual void Release();
};
class Obj_2fe6b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    char pad[0x1c - 4];
    Ref_2fe6b0* ref;
    virtual void v7();
    virtual void Changed();
    void Set(Ref_2fe6b0*);
};
class Ref {
  public:
    virtual void add();
};
class Part {
  public:
    char pad[16];
    void copy(Part* src);
};
class Obj {
  public:
    char pad0[8];
    Part part;
    int value;
    Ref* ptr;
    void fn(Obj* dst, int x);
};

} // namespace fn_fa862d6d

// 0x002fe570 FUN_002fe570 (64 B): equivalent/0x002fe570.cpp [wrapped: conflict: physics::SimulatedObject]
// sym: ??0SimulatedObject@physics@fn_002fe570@@QAE@I@Z
namespace fn_002fe570 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fe570 @ 0x002fe570

namespace physics {
struct Base {
    virtual void dummy();
    char pad[12];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char active;
    char pad2[3];
    unsigned int type;
    unsigned int id;
    Base();
};
struct SimulatedObject : Base {
    virtual void dummy();
    SimulatedObject(unsigned int value);
};
SimulatedObject::SimulatedObject(unsigned int value) {
    a = 0;
    b = 0;
    d = 0;
    c = value;
    active = 1;
    type = 3;
    id = (*(unsigned int*)&DAT_00555478)++;
}
}
} // namespace fn_002fe570


// 0x002fe5b0 physics::SimulatedObject::vfunc_5 (3 B): matches/0x002fe5b0.cpp
// sym: ?vfunc_5@SimulatedObject@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::SimulatedObject::vfunc_5(int a) {
    (void)a;
}

namespace fn_fa862d6d {

// 0x002fe5c0 physics::SimulatedObject::vfunc_7 (1 B): matches/0x002fe5c0.cpp
// sym: ?FUN_002fe5c0@fn_fa862d6d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002fe5c0() {}


// 0x002fe5d0 physics::SimulatedObject::vfunc_8 (1 B): matches/0x002fe5d0.cpp
// sym: ?FUN_002fe5d0@fn_fa862d6d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002fe5d0() {}

} // namespace fn_fa862d6d

// 0x002fe5e0 physics::SimulatedObject::vfunc_9 (3 B): matches/0x002fe5e0.cpp
// sym: ?vfunc_9@SimulatedObject@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::SimulatedObject::vfunc_9(int a) {
    (void)a;
}

namespace fn_fa862d6d {

// 0x002fe5f0 physics::SimulatedObject::vfunc_10 (1 B): matches/0x002fe5f0.cpp
// sym: ?FUN_002fe5f0@fn_fa862d6d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002fe5f0() {}

} // namespace fn_fa862d6d

// 0x002fe600 physics::SimulatedObject::vfunc_21 (7 B): matches/0x002fe600.cpp
// sym: ?vfunc_21@SimulatedObject@physics@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg physics::SimulatedObject::vfunc_21() {
    return DAT_003f32dc;
}


// 0x002fe610 physics::SimulatedObject::vfunc_25 (5 B): matches/0x002fe610.cpp
// sym: ?vfunc_25@SimulatedObject@physics@@UAE_NPAXKK@Z
// Same code shape as 0x0023d2e0 (propagated; names are from that function)
 // namespace fight
bool physics::SimulatedObject::vfunc_25(void* __p0, unsigned long __p1, unsigned long __p2) {
    return false;
}


// 0x002fe620 physics::SimulatedObject::vfunc_26 (5 B): matches/0x002fe620.cpp
// sym: ?vfunc_26@SimulatedObject@physics@@UAE_NH@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool physics::SimulatedObject::vfunc_26(int __p0) {
    return true;
}


// 0x002fe630 physics::SimulatedObject::vfunc_27 (3 B): matches/0x002fe630.cpp
// sym: ?vfunc_27@SimulatedObject@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::SimulatedObject::vfunc_27(int a) {
    (void)a;
}

namespace fn_fa862d6d {

// 0x002fe640 FUN_002fe640 (54 B): matches/0x002fe640.cpp
// sym: ??0SimulatedObject@fn_fa862d6d@@QAE@XZ
// data: g_counter_2fe640 = DAT_00555478
SimulatedObject::SimulatedObject() {
    Init();
    field10 = 0;
    field18 = 0;
    field1c = 0;
    vptr = (hulk_intptr)&physics_vftable;
    field20 = 1;
    field24 = 3;
    field28 = (*(int*)&DAT_00555478);
    ++(*(int*)&DAT_00555478);
}


// 0x002fe680 FUN_002fe680 (29 B): matches/0x002fe680.cpp
// sym: ?Finish@SimulatedObject@fn_fa862d6d@@QAEXXZ
void SimulatedObject::Finish() {
    vftable = &gVtable_2fe680;
    if (member)
        member->f1();
    ((SimulatedObject_2fe680*)this)->Tail();
}


// 0x002fe6a0 FUN_002fe6a0 (15 B): matches/0x002fe6a0.cpp
// sym: ?set@C_2fe6a0@fn_fa862d6d@@QAEXH@Z
void C_2fe6a0::set(int x) {
    value = x;
    f7();
}


// 0x002fe6b0 FUN_002fe6b0 (45 B): matches/0x002fe6b0.cpp
// sym: ?Set@Obj_2fe6b0@fn_fa862d6d@@QAEXPAVRef_2fe6b0@2@@Z
void Obj_2fe6b0::Set(Ref_2fe6b0* value) {
    if (ref != value) {
        if (ref)
            ref->Release();
        ref = value;
        value->Init();
        Changed();
    }
}

} // namespace fn_fa862d6d

// 0x002fe6e0 physics::SimulatedObject::vfunc_22 (3 B): matches/0x002fe6e0.cpp
// sym: ?vfunc_22@SimulatedObject@physics@@UAEXHHHHHH@Z
void physics::SimulatedObject::vfunc_22(int , int , int , int , int , int ) {}

namespace fn_fa862d6d {

// 0x002fe6f0 FUN_002fe6f0 (64 B): matches/0x002fe6f0.cpp
// sym: ?fn@Obj@fn_fa862d6d@@QAEXPAV12@H@Z
void Obj::fn(Obj* dst, int x) {
    *(int*)((char*)dst + 0x10) = x;
    dst->value = value;
    dst->ptr = ptr;
    *(int*)((char*)dst + 0x14) = 0;
    if (ptr)
        dst->ptr->add();
    dst->part.copy(&part);
}

} // namespace fn_fa862d6d

// 0x002fe730 physics::SimulatedObject::vfunc_2 (50 B): matches/0x002fe730.cpp [wrapped: conflict: SimulatedObject]
// sym: ?vfunc_2@SimulatedObject@fn_002fe730@@UAEPAU12@I@Z
namespace fn_002fe730 {
struct Ref_2fe730 {
    virtual void a();
    virtual void b();
};
extern void* vftable_2fe730;
struct SimulatedObject {
    virtual void v0();
    virtual void v1();
    virtual SimulatedObject* vfunc_2(unsigned int);
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
    char pad[0x18];
    Ref_2fe730* member;
    void helper();
};
void thunk(SimulatedObject*);
SimulatedObject* SimulatedObject::vfunc_2(unsigned int flag) {
    *(void**)this = &vftable_2fe730;
    if (member)
        member->b();
    helper();
    if (flag & 1)
        thunk(this);
    return this;
}
} // namespace fn_002fe730

