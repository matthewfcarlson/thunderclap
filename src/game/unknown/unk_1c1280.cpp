// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c1280..0x001c1440 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f0dc78b5 {
#define TREE_TU_END }
namespace fn_f0dc78b5 {} using namespace fn_f0dc78b5;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f0dc78b5 {
class B_1c1280 {
  public:
    void F(int, int, int, int);
};
class A_1c1280 {
  public:
    char pad[4];
    B_1c1280* m;
    void F(int, int, int, int);
};
class A_1c12b0 {
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
    virtual int f14();
    virtual void f15();
};
class B_1c12b0 {
  public:
    char pad[8];
    A_1c12b0* p;
};
struct Inner_1c12c0 {
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
    virtual int target();
};
struct Wrapper_1c12c0 {
    int pad[2];
    Inner_1c12c0* ptr;
};
class Thing_1c12f0 {
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
    virtual int get();
};
class Wrapper_1c12f0 {
  public:
    char pad[8];
    Thing_1c12f0* value;
};
class Base_1c1300 {
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
    virtual int Get();
};
class Owner_1c1300 {
  public:
    char pad[8];
    Base_1c1300* mBase;
};
class Inner_1c1310 {
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
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual int f18(void*, unsigned);
};
class Outer_1c1310 {
    char pad[8];

  public:
    Inner_1c1310* p;
    int target(void* arg);
};
class D {
  public:
    void f(int);
};
class C_1c1330 {
  public:
    char pad[0xbc];
    D* member;
    void g(int);
};
struct Child_1c1340 {
    void First(int);
    void Second();
};
struct Thing_1c1340 {
    char pad[0xbc];
    Child_1c1340* volatile child;
    int value;
    void Run();
};
class Thing_1c1370 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class Manager_1c1370 {
  public:
    void Prep(int);
};
class Obj_1c1370 {
  public:
    char pad[0xbc];
    Manager_1c1370* mBC;
    int mC0;
    void Target(char flag);
};
struct Child_1c13d0 {
    void First(int);
    void Second();
};
struct Thing_1c13d0 {
    char pad[0xbc];
    Child_1c13d0* volatile child;
    int value;
    void Run();
};


// 0x001c1280 FUN_001c1280 (8 B): matches/0x001c1280.cpp
// sym: ?F@A_1c1280@fn_f0dc78b5@@QAEXHHHH@Z
void A_1c1280::F(int a0, int a1, int a2, int a3) {
    m->F(a0, a1, a2, a3);
}


// 0x001c12b0 FUN_001c12b0 (8 B): matches/0x001c12b0.cpp
// sym: ?target@fn_f0dc78b5@@YIHPAVB_1c12b0@1@@Z
hulk_intptr __fastcall target(B_1c12b0* self) {
    return self->p->f14();
}


// 0x001c12c0 FUN_001c12c0 (8 B): matches/0x001c12c0.cpp
// sym: ?FUN_001c12c0@fn_f0dc78b5@@YIHPAUWrapper_1c12c0@1@@Z
hulk_intptr __fastcall FUN_001c12c0(Wrapper_1c12c0* self) {
    return self->ptr->target();
}


// 0x001c12f0 FUN_001c12f0 (12 B): matches/0x001c12f0.cpp
// sym: ?FUN_001c12f0@fn_f0dc78b5@@YIHPAVWrapper_1c12f0@1@@Z
hulk_intptr __fastcall FUN_001c12f0(Wrapper_1c12f0* self) {
    return self->value->get() + 0x20;
}


// 0x001c1300 FUN_001c1300 (12 B): matches/0x001c1300.cpp
// sym: ?FUN_001c1300@fn_f0dc78b5@@YIHPAVOwner_1c1300@1@@Z
hulk_intptr __fastcall FUN_001c1300(Owner_1c1300* self) {
    return self->mBase->Get() + 0x30;
}


// 0x001c1310 FUN_001c1310 (22 B): matches/0x001c1310.cpp
// sym: ?target@Outer_1c1310@fn_f0dc78b5@@QAEHPAX@Z
int Outer_1c1310::target(void* arg) {
    Inner_1c1310* q = p;
    return q->f18(arg, *(unsigned*)((char*)arg + 12));
}


// 0x001c1330 FUN_001c1330 (11 B): matches/0x001c1330.cpp
// sym: ?g@C_1c1330@fn_f0dc78b5@@QAEXH@Z
void C_1c1330::g(int a0) {
    member->f(a0);
}


// 0x001c1340 FUN_001c1340 (44 B): matches/0x001c1340.cpp
// sym: ?Run@Thing_1c1340@fn_f0dc78b5@@QAEXXZ
void Thing_1c1340::Run() {
    child->First(value);
    child->Second();
    ((pure3d::DisplayList *)child)->FUN_0029bba0();
}


// 0x001c1370 FUN_001c1370 (69 B): matches/0x001c1370.cpp
// sym: ?Target@Obj_1c1370@fn_f0dc78b5@@QAEXD@Z
void Obj_1c1370::Target(char flag) {
    mBC->Prep(mC0);
    Thing_1c1370* t = ((Thing_1c1370 *)((owners::X_29b6d0 *)mBC)->FUN_0029b6d0(0));
    if (flag)
        t->f3();
    t->f4();
    t->f5();
}


// 0x001c13c0 FUN_001c13c0 (1 B): matches/0x001c13c0.cpp
// sym: ?FUN_001c13c0@fn_f0dc78b5@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001c13c0() {}


// 0x001c13d0 FUN_001c13d0 (44 B): matches/0x001c13d0.cpp
// sym: ?Run@Thing_1c13d0@fn_f0dc78b5@@QAEXXZ
// Same code shape as 0x001c1340 (propagated; names are from that function)
void Thing_1c13d0::Run() {
    child->First(value);
    child->Second();
    ((pure3d::DisplayList *)child)->FUN_0029bba0();
}


// 0x001c1400 FUN_001c1400 (1 B): matches/0x001c1400.cpp
// sym: ?FUN_001c1400@fn_f0dc78b5@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001c1400() {}


// 0x001c1410 FUN_001c1410 (1 B): matches/0x001c1410.cpp
// sym: ?FUN_001c1410@fn_f0dc78b5@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001c1410() {}

} // namespace fn_f0dc78b5
