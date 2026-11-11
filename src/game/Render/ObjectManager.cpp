// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c5ae0..0x001c5e20 (kind game, layer game, confidence medium), dominant class Render::ObjectManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/Render.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb16b970 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_fb16b970 {} using namespace fn_fb16b970;
#include "game/Render.h"

// ---- declarations shared by the functions below
namespace fn_fb16b970 {
struct Sub_1c5ae0 {
};
struct Helper {
    unsigned int Get();
};
struct Owner_1c5ae0 {
    char pad[0x128];
    Sub_1c5ae0 sub;
    void Run(hulk_intptr x);
};
struct Inner_1c5b00 {
    int Helper(int);
};
struct Outer_1c5b00 {
    char pad[0x128];
    Inner_1c5b00 inner;
    int Target(hulk_intptr);
};
typedef unsigned int U_1c5b10;
struct Part_1c5b10 {
    void f5d30();
};
struct Sub_1c5b10 {
    U_1c5b10 f75e0(U_1c5b10);
    void f7550(U_1c5b10);
};
extern void __cdecl thunk(U_1c5b10);
class ObjectManager_1c5b50 : public CAction {
  public:
    ObjectManager_1c5b50* vfunc_2(unsigned char);
};
struct ThisCall_001c5890 {
    void FUN_001c5890();
};
extern void thunk_FUN_00267090(ObjectManager_1c5b50*);
class A_1c5be0 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c5be0 {
  public:
    A_1c5be0* p;
    void run();
};
class A_1c5c00 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c5c00 {
  public:
    A_1c5c00* p;
    void run();
};
class Provider_1c5c20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int Get();
};
class Builder {
  public:
    void* Create(int, int);
};
class Result_1c5c20 {
  public:
    void Finish(int);
};
class Owner_1c5c20 {
  public:
    char pad[8];
    Provider_1c5c20* provider;
    int value;
    void* Run(int);
};
class A_1c5cb0 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c5cb0 {
  public:
    A_1c5cb0* p;
    void run();
};
class A_1c5cd0 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c5cd0 {
  public:
    A_1c5cd0* p;
    void run();
};
class Obj_1c5cf0 {
  public:
    virtual void A();
    virtual void B();
};
struct ThisCall_0027af30 {
    void Init(int);
};
class Thing_1c5cf0 {
  public:
    char pad[8];
    Obj_1c5cf0* p;
    int q;
    Thing_1c5cf0* Set(hulk_intptr, Obj_1c5cf0*);
};
class Ref_1c5d30 {
  public:
    virtual void f0();
    virtual void Release();
};
class Base_1c5d30 {
  public:
    void Finish();
};
class Target_1c5d30 : public Base_1c5d30 {
  public:
    char pad[8];
    Ref_1c5d30* volatile b;
    Ref_1c5d30* volatile a;
    void Clear();
};


// 0x001c5ae0 FUN_001c5ae0 (29 B): matches/0x001c5ae0.cpp
// sym: ?Run@Owner_1c5ae0@fn_fb16b970@@QAEXH@Z
void Owner_1c5ae0::Run(hulk_intptr x) {
    ((Render::StoreBase *)&sub)->FUN_001c7870((int)(((Helper*)x)->Get()), (int)x);
}


// 0x001c5b00 FUN_001c5b00 (11 B): matches/0x001c5b00.cpp
// sym: ?Target@Outer_1c5b00@fn_fb16b970@@QAEHH@Z
int Outer_1c5b00::Target(hulk_intptr a0) {
    return inner.Helper(a0);
}

} // namespace fn_fb16b970

// 0x001c5b10 FUN_001c5b10 (57 B): matches/0x001c5b10.cpp
// sym: ?FUN_001c5b10@Obj_1c5b10@owners@@QAEXI@Z
void owners::Obj_1c5b10::FUN_001c5b10(U_1c5b10 arg) {
    Sub_1c5b10* sub = (Sub_1c5b10*)((char*)this + 0x128);
    U_1c5b10 r = sub->f75e0(arg);
    sub->f7550(arg);
    if (r) {
        ((Part_1c5b10*)r)->f5d30();
        thunk(r);
    }
}

namespace fn_fb16b970 {

// 0x001c5b50 Render::ObjectManager::vfunc_0 (30 B): matches/0x001c5b50.cpp
// sym: ?vfunc_2@ObjectManager_1c5b50@fn_fb16b970@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
ObjectManager_1c5b50* ObjectManager_1c5b50::vfunc_2(unsigned char flags) {
    ((ThisCall_001c5890*)(this))->FUN_001c5890();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fb16b970

// 0x001c5b70 FUN_001c5b70 (3 B): matches/0x001c5b70.cpp [wrapped: conflict: pure3d::Entity; pure3d::LightGroup]
// sym: ?Self@LightGroup@pure3d@fn_001c5b70@@QAEPAV123@XZ
namespace fn_001c5b70 {
// Same code shape as 0x002a1130 (propagated; names are from that function)
namespace pure3d {

class Entity {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};

class LightGroup : public Entity {
  public:
    LightGroup* Self();
    char pad2[0x40];
};

LightGroup* LightGroup::Self() {
    return this;
}

} // namespace pure3d
} // namespace fn_001c5b70

namespace fn_fb16b970 {

// 0x001c5be0 FUN_001c5be0 (22 B): matches/0x001c5be0.cpp
// sym: ?run@B_1c5be0@fn_fb16b970@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c5be0::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c5c00 FUN_001c5c00 (22 B): matches/0x001c5c00.cpp
// sym: ?run@B_1c5c00@fn_fb16b970@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c5c00::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c5c20 FUN_001c5c20 (84 B): matches/0x001c5c20.cpp
// sym: ?Run@Owner_1c5c20@fn_fb16b970@@QAEPAXH@Z
void* Owner_1c5c20::Run(int arg) {
    int n = provider->Get();
    void* p = FUN_0008d690(0xb0);
    void* r;
    if (p)
        r = ((Builder*)p)->Create(arg, n);
    else
        r = 0;
    ((Result_1c5c20*)r)->Finish(value);
    return r;
}


// 0x001c5cb0 FUN_001c5cb0 (22 B): matches/0x001c5cb0.cpp
// sym: ?run@B_1c5cb0@fn_fb16b970@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c5cb0::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c5cd0 FUN_001c5cd0 (22 B): matches/0x001c5cd0.cpp
// sym: ?run@B_1c5cd0@fn_fb16b970@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c5cd0::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c5cf0 FUN_001c5cf0 (64 B): matches/0x001c5cf0.cpp
// sym: ?Set@Thing_1c5cf0@fn_fb16b970@@QAEPAV12@HPAVObj_1c5cf0@2@@Z
Thing_1c5cf0* Thing_1c5cf0::Set(hulk_intptr arg, Obj_1c5cf0* value) {
    ((ThisCall_0027af30*)(this))->Init(arg);
    p = 0;
    if (value) {
        value->A();
        if (p)
            p->B();
    }
    p = value;
    q = 0;
    return this;
}


// 0x001c5d30 FUN_001c5d30 (49 B): matches/0x001c5d30.cpp
// sym: ?Clear@Target_1c5d30@fn_fb16b970@@QAEXXZ
void Target_1c5d30::Clear() {
    Ref_1c5d30* x = a;
    if (x)
        x->Release();
    a = 0;
    x = b;
    if (x)
        x->Release();
    b = 0;
    Finish();
}

} // namespace fn_fb16b970
