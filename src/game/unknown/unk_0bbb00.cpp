// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000bbb00..0x000bc1e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc9dd2b5 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc9dd2b5 {} using namespace fn_fc9dd2b5;
namespace fn_fc9dd2b5 { extern "C" char DAT_004076ec[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fc9dd2b5 {
struct O_bbb00 {
    char pad[0x88];
    int m;
};
class ISoundManager_bbb20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public ISoundManager_bbb20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
struct State_bbb40 {
    char pad[0x1cf8];
    long value;
};
class Handler_bbb40 {
  public:
    void* pad;
    State_bbb40* state;
    int FUN_000bbb40(int type, const char** value);
};
class A_bbb90 {
  public:
    int Fn_000b50d0();
};
struct B_bbb90 {
    char pad[4];
    A_bbb90* m;
    int F(int a, int b);
};
class Sub_bbcd0 {
  public:
    void Fn_001eb9e0(int a);
};
class Mgr_bbcd0 {
  public:
    char pad[0x3c];
    Sub_bbcd0* sub;
    void Fn(int a);
};
class Obj_bbcd0 {
  public:
    char pad[4];
    Mgr_bbcd0* mgr;
    void Fn(int a);
};
class B {
  public:
    void Run_001eba30(int);
};
class A {
  public:
    char pad[0x3c];
    B* b;
    inline void Fn(int n) {
        if (b)
            b->Run_001eba30(n);
    }
};
class C {
  public:
    int pad;
    A* a;
    void Fn(int);
};
class Child {
  public:
    void Set_000b5920(char);
    void Fn_00092870(int, bool);
    void Fn_000b8f20();
};
class Parent {
  public:
    char pad[4];
    Child* child;
    void Fn(int value);
};
class Owner {
  public:
    char _m_pad_0[0x4c];
    Child* child;
    void Action_000b99b0();
};
class Item {
  public:
    void Use_001ec480(const char*, void*);
};
class Asset {
  public:
    char pad[0x3c];
    Item* item;
};
class X {
  public:
    void* v;
    union { Asset* a; Owner* owner; };
    void Run(int p);
    int Fn(int type, void** p);
};
class C_bbe90 {
  public:
    virtual void A();
    int F(int a, int b);
    int* mP;
};
class Layout_bbeb0 {
  public:
    void* mVptr;
    struct Sub {
        int mField;
        void Select_000b78e0(const char* name);
    }* mMember;
    int Get(int a, int b);
};
class Thing {
  public:
    char pad[4];
    Child* p;
    void Fn(int);
};
extern "C" int __cdecl FUN_000fc280(const char* s);
class H {
  public:
};
class C_bbf20 {
  public:
    char pad[4];
    H* field;
    int F(int, char**);
};
class Dest {
  public:
    void Fn_000b78e0(int);
};
class Obj {
  public:
    char _m_pad_0[0x4];
    union { Owner* owner; Dest* p; void* ptr; };
    void Set(void* p);
    int Run(int n, int* v);
    int Fn(int a, int b);
    void Do_000b5ca0();
};
struct Values { int first; int second; };
struct Helper_bbfd0 {
    int FnF_000b7ff0();
};
class Obj_bbfd0 {
  public:
    char pad[4];
    Helper_bbfd0* m;
    int Fn(int a, int b);
};
class Helper_bbff0 {
  public:
    int Go_000b8430();
};
class Base_bbff0 {
  public:
    virtual void V0();
    virtual void V1();
    Helper_bbff0* mVal;
    int Fn(int a, int b);
};
extern "C" void __stdcall FUN_000bc040(int a);
class Y_bc050 {
  public:
    void Fn_000b8e70(float);
};
class X_bc050 {
  public:
    char pad[4];
    Y_bc050* m;
    void Fn(float unused);
};
class P_bc060 {
  public:
    int Fng_000b8940();
};
class O_bc060 {
  public:
    void* pad;
    P_bc060* m;
    int f(int a, int b);
};
class Sub_bc080 {
  public:
    char pad[0x10];
    int field;
};
class Obj_bc080 {
  public:
    char pad[4];
    Sub_bc080* m0;
    int Fn(int a, int b);
};
class Wrapper {
  public:
    int pad;
    Obj* obj;
    int Run(int a, int b);
};
struct Inner { char pad[16]; int value; };
struct Object {
  public:
    char _m_pad_0[0x4];
    Inner* inner;
    void FUN_000b79a0(int first, int second);
    int FUN_000bc0f0(int a, int b);
};
struct Handler { char pad[4]; Object *object; int FUN_000bbfa0(int type, Values *values); };
extern "C" void __cdecl FUN_000fc130(const void *arg);
extern "C" void __cdecl FUN_0008d340(void *p);
class Scene_bc100 {
public:
    void FUN_000f7ce0();
};
class Resource_bc100 {
public:
    void FUN_001bf860(int flag);
    void FUN_001bdf00();
};
class Hook_bc100 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
};
class Pool_bc100 {
public:
    void FUN_002665a0();
};
class Display_bc100 {
public:
    void FUN_00294980(int arg);
};
struct Flag_bc100 {
    char pad0[4];
    char ready;
};
extern "C" Scene_bc100 *__cdecl FUN_000fc1b0();
extern "C" Hook_bc100 *__cdecl FUN_000fc3d0();
extern "C" Flag_bc100 *__cdecl FUN_0008e090();
class Loader_bc100 {
public:
    void FUN_000bc100();

    char pad0[0x10];
    int state;
    char pad1[0x20 - 0x14];
    Display_bc100 *display;
    int displayArg;
    char active;
    char pad2[0x5c - 0x29];
    Resource_bc100 *resource;
    char pad3[0x6c - 0x60];
    void *slotsA[128];
    void *slotsB[128];
};


// 0x000bbb00 FUN_000bbb00 (18 B): matches/0x000bbb00.cpp
// sym: ?FUN_000bbb00@fn_fc9dd2b5@@YIXPAUO_bbb00@1@PAX@Z
void __fastcall FUN_000bbb00(O_bbb00* self, void*) {
    if (self->m > 0)
        --self->m;
}


// 0x000bbb20 CFESoundManager::vfunc_0 (31 B): matches/0x000bbb20.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fc9dd2b5@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004076ec;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000bbb40 FUN_000bbb40 (54 B): matches/0x000bbb40.cpp
// sym: ?FUN_000bbb40@Handler_bbb40@fn_fc9dd2b5@@QAEHHPAPBD@Z
int Handler_bbb40::FUN_000bbb40(int type, const char** value) {
    if (state == 0)
        return -1;
    if (type != 1)
        return -1;
    state->value = atol(*value);
    return 0;
}

} // namespace fn_fc9dd2b5

// 0x000bbb80 FUN_000bbb80 (14 B): matches/0x000bbb80.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Fn@Obj@fn_000bbb80@@QAEHHH@Z
namespace fn_000bbb80 {
class Obj {
  public:
    int a;
    int b;
    int Fn(int x, int y);
};
int Obj::Fn(int x, int y) {
    return (b != 0) - 1;
}
} // namespace fn_000bbb80

namespace fn_fc9dd2b5 {

// 0x000bbb90 FUN_000bbb90 (23 B): matches/0x000bbb90.cpp
// sym: ?F@B_bbb90@fn_fc9dd2b5@@QAEHHH@Z
int B_bbb90::F(int a, int b) {
    A_bbb90* p = m;
    if (!p)
        return -1;
    int r = p->Fn_000b50d0();
    r = 0;
    return r;
}

} // namespace fn_fc9dd2b5

// 0x000bbbb0 FUN_000bbbb0 (66 B): matches/0x000bbbb0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Cancel@Obj@fn_000bbbb0@@QAEHHH@Z
namespace fn_000bbbb0 {
// data: gFlag = DAT_004e222c, msg = DAT_00407974

class Event {
  public:
    Event(const char*);
    char data[32];
};
class Receiver {
  public:
    void Fire_001cbc20(Event*);
};
class Root {
    char pad[48];

  public:
    Receiver* recv;
};
extern Root* hulk_at_004dd700;
class Obj {
  public:
    void* v;
    void* p;
    int Cancel(int, int);
};
int Obj::Cancel(int a, int b) {
    if (!p)
        return -1;
    Event e(((char*)&DAT_00407974));
    hulk_at_004dd700->recv->Fire_001cbc20(&e);
    DAT_004e222c = 1;
    return 0;
}
} // namespace fn_000bbbb0


// 0x000bbc00 FUN_000bbc00 (32 B): matches/0x000bbc00.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Fn2@Obj@fn_000bbc00@@QAEHHH@Z
namespace fn_000bbc00 {
class Sub {
  public:
    int Fn_00089980();
};
struct Obj {
    int pad;
    void* mPtr;
    char pad2[0x34 - 8];
    Sub* mSub;
    int Fn2(int a, int b);
};
int Obj::Fn2(int a, int b) {
    void* p = mPtr;
    if (!p)
        return -1;
    Sub* s = *(Sub* volatile*)((char*)p + 0x34);
    if (s)
        s->Fn_00089980();
    return 0;
}
} // namespace fn_000bbc00


// 0x000bbc20 FUN_000bbc20 (37 B): matches/0x000bbc20.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Run@Owner@fn_000bbc20@@QAEHHH@Z
namespace fn_000bbc20 {
class Timer {
  public:
    void Set_000900a0(int);
};
class Obj {
  public:
    char pad[0x50];
    Timer* timer;
};
class Owner {
  public:
    void* v;
    Obj* obj;
    int Run(int a, int b);
};
int Owner::Run(int a, int b) {
    if (!obj)
        return -1;
    Timer* t = obj->timer;
    if (t)
        t->Set_000900a0(50000);
    return 0;
}
} // namespace fn_000bbc20


// 0x000bbc50 FUN_000bbc50 (49 B): matches/0x000bbc50.cpp [wrapped: compile error in a shared declaration (C2065)]
// sym: ?FUN_000bbc50@Object@fn_000bbc50@@QAEXM@Z
namespace fn_000bbc50 {

struct Inner {
    char pad[0x54];
    void* value;
};
struct Object {
    char pad[4];
    Inner* inner;
    void FUN_000bbc50(float input);
};
extern "C" void __cdecl FUN_001b8750(float value);
void Object::FUN_000bbc50(float input) {
    if (inner && inner->value) {
        FUN_001b8750((*(float*)&DAT_00407b04) * ((*(volatile float*)&input) * (*(float*)&DAT_003f3358)) + (*(float*)&DAT_00406130));
    }
}
} // namespace fn_000bbc50


// 0x000bbc90 FUN_000bbc90 (26 B): matches/0x000bbc90.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Check@Obj@fn_000bbc90@@QAEXPAX@Z
namespace fn_000bbc90 {
void __cdecl Fn_00035db0(char);
class Obj {
  public:
    int pad;
    void* ptr;
    void Check(void* p);
};
void Obj::Check(void* p) {
    if (ptr)
        Fn_00035db0(p == 0);
}
} // namespace fn_000bbc90


// 0x000bbcb0 FUN_000bbcb0 (18 B): matches/0x000bbcb0.cpp [wrapped: compile error in a shared declaration (C2065)]
// sym: ?Run@Wrapper@fn_000bbcb0@@QAEXH@Z
namespace fn_000bbcb0 {
class Inner {
  public:
    char pad[0x3c];
    Inner* ptr;
    void Fn_001eba80(int);
    void Dispatch(int x) {
        if (ptr)
            ptr->Fn_001eba80(x);
    }
};
class Wrapper {
  public:
    char pad[4];
    Inner* obj;
    void Run(int x);
};
void Wrapper::Run(int x) {
    obj->Dispatch(x);
}
} // namespace fn_000bbcb0

namespace fn_fc9dd2b5 {

// 0x000bbcd0 FUN_000bbcd0 (18 B): matches/0x000bbcd0.cpp
// sym: ?Fn@Obj_bbcd0@fn_fc9dd2b5@@QAEXH@Z
void Obj_bbcd0::Fn(int a) {
    Mgr_bbcd0* m = mgr;
    if (m->sub)
        m->sub->Fn_001eb9e0(a);
}


// 0x000bbcf0 FUN_000bbcf0 (18 B): matches/0x000bbcf0.cpp
// sym: ?Fn@C@fn_fc9dd2b5@@QAEXH@Z
void C::Fn(int n) {
    a->Fn(n);
}

} // namespace fn_fc9dd2b5

// 0x000bbd10 FUN_000bbd10 (18 B): matches/0x000bbd10.cpp [wrapped: compile error in a shared declaration (C2065)]
// sym: ?Do@Host@fn_000bbd10@@QAEXH@Z
namespace fn_000bbd10 {
class Inner {
  public:
    void Run_001ebad0(int);
};
class Outer {
  public:
    char pad[0x3c];
    Inner* inner;
    inline void Do(int n) {
        if (inner)
            inner->Run_001ebad0(n);
    }
};
class Host {
  public:
    char pad[4];
    Outer* outer;
    void Do(int);
};
void Host::Do(int n) {
    outer->Do(n);
}
} // namespace fn_000bbd10


// 0x000bbd30 FUN_000bbd30 (45 B): matches/0x000bbd30.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Set@Obj@fn_000bbd30@@QAEXPAX@Z
namespace fn_000bbd30 {
class Sub {
  public:
    char pad[12];
    unsigned char flag;
    void Change_001be490();
};
class Holder {
  public:
    char pad[0x5c];
    Sub* sub;
};
class Obj {
  public:
    char pad[4];
    Holder* holder;
    void Set(void* p);
};
void Obj::Set(void* p) {
    if (holder) {
        unsigned char b = p == 0;
        Sub* s = holder->sub;
        if (s) {
            if (s->flag != b)
                s->Change_001be490();
            s->flag = b;
        }
    }
}
} // namespace fn_000bbd30

namespace fn_fc9dd2b5 {

// 0x000bbd60 FUN_000bbd60 (28 B): matches/0x000bbd60.cpp
// sym: ?Fn@Parent@fn_fc9dd2b5@@QAEXH@Z
void Parent::Fn(int value) {
    if (child)
        child->Set_000b5920(!value);
}


// 0x000bbd80 FUN_000bbd80 (24 B): matches/0x000bbd80.cpp
// sym: ?Set@Obj@fn_fc9dd2b5@@QAEXPAX@Z
// data: gFlag = DAT_004dd83a
void Obj::Set(void* p) {
    if (ptr)
        (*(unsigned char*)&DAT_004dd83a) = (p == 0);
}

} // namespace fn_fc9dd2b5

// 0x000bbda0 FUN_000bbda0 (24 B): matches/0x000bbda0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Fn@Obj@fn_000bbda0@@QAEXPAX@Z
namespace fn_000bbda0 {

class Obj {
  public:
    void Fn(void* p);
    char pad[4];
    void* m;
};
void Obj::Fn(void* p) {
    if (m)
        (*(unsigned char*)&DAT_004dd83b) = (p == 0);
}
} // namespace fn_000bbda0


// 0x000bbdc0 FUN_000bbdc0 (36 B): matches/0x000bbdc0.cpp [wrapped: compile error in a shared declaration (C2065)]
// sym: ?Run@Target@fn_000bbdc0@@QAEXPAX@Z
namespace fn_000bbdc0 {
class Inner {
  public:
    void Set_00092870(int, bool);
};
class Owner {
  public:
    char pad[0x4c];
    Inner* inner;
};
class Target {
  public:
    char pad[4];
    Owner* owner;
    void Run(void* p);
};
void Target::Run(void* p) {
    if (owner && owner->inner)
        owner->inner->Set_00092870(2, !p);
}
} // namespace fn_000bbdc0


// 0x000bbdf0 FUN_000bbdf0 (39 B): matches/0x000bbdf0.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_000bbdf0@@QAEXPAX@Z
namespace fn_000bbdf0 {
class Inner {
  public:
    void Act_00092870(int, char);
};
class Obj {
  public:
    char pad[4];
    struct Mid {
        char pad[0x4c];
        Inner* p;
    }* mid;
    void Fn(void* p);
};
void Obj::Fn(void* p) {
    if (mid && mid->p)
        mid->p->Act_00092870(0x2e4, p == 0);
}
} // namespace fn_000bbdf0

namespace fn_fc9dd2b5 {

// 0x000bbe20 FUN_000bbe20 (36 B): matches/0x000bbe20.cpp
// sym: ?Run@X@fn_fc9dd2b5@@QAEXH@Z
void X::Run(int p) {
    if (owner && owner->child)
        owner->child->Fn_00092870(0x1d, !p);
}


// 0x000bbe50 FUN_000bbe50 (49 B): matches/0x000bbe50.cpp
// sym: ?Fn@X@fn_fc9dd2b5@@QAEHHPAPAX@Z
// data: metalanim = DAT_00407b08
int X::Fn(int type, void** p) {
    Asset* q = a;
    if (!q)
        return -1;
    if (type != 1)
        return -1;
    void* v = *p;
    if (v)
        q->item->Use_001ec480(((char*)&DAT_00407b08), v);
    return 0;
}


// 0x000bbe90 FUN_000bbe90 (28 B): matches/0x000bbe90.cpp
// sym: ?F@C_bbe90@fn_fc9dd2b5@@QAEHHH@Z
int C_bbe90::F(int a, int b) {
    int* p = mP;
    if (!p)
        return -1;
    *(int*)((char*)p + 0x1d34) = 0;
    return 0;
}


// 0x000bbeb0 FUN_000bbeb0 (28 B): matches/0x000bbeb0.cpp
// sym: ?Get@Layout_bbeb0@fn_fc9dd2b5@@QAEHHH@Z
int Layout_bbeb0::Get(int a, int b) {
    struct Sub* p = mMember;
    if (!p)
        return -1;
    p->Select_000b78e0("blonsky_file_selector");
    return 0;
}

} // namespace fn_fc9dd2b5

// 0x000bbed0 FUN_000bbed0 (31 B): matches/0x000bbed0.cpp [wrapped: conflict: Obj]
// sym: ?target@Obj@fn_000bbed0@@QAEHPAX0@Z
namespace fn_000bbed0 {
class Other {
  public:
};
class Obj {
  public:
    int dummy;
    Other* ptr;
    int target(void* a, void* b);
};
int Obj::target(void* a, void* b) {
    Other* p = ptr;
    if (!p)
        return -1;
    if (a)
        return -1;
    ((owners::Owner_b5a30 *)p)->FUN_000b5a30();
    return 0;
}
} // namespace fn_000bbed0

namespace fn_fc9dd2b5 {

// 0x000bbef0 FUN_000bbef0 (15 B): matches/0x000bbef0.cpp
// sym: ?Fn@Thing@fn_fc9dd2b5@@QAEXH@Z
void Thing::Fn(int unused) {
    if (p)
        p->Fn_000b8f20();
}


// 0x000bbf00 FUN_000bbf00 (18 B): matches/0x000bbf00.cpp
// sym: _FUN_000bbf00@8
extern "C" int __stdcall FUN_000bbf00(const char* a, int b) {
    FUN_000fc280("save_game");
    return 0;
}


// 0x000bbf20 FUN_000bbf20 (58 B): matches/0x000bbf20.cpp
// sym: ?F@C_bbf20@fn_fc9dd2b5@@QAEHHPAPAD@Z
int C_bbf20::F(int p, char** q) {
    if (field == 0)
        return -1;
    if (p != 1)
        return -1;
    if (*q != 0) {
        long v = atol(*q);
        ((owners::Obj_b4b00 *)field)->FUN_000b4b00((int)v);
    }
    return 0;
}

} // namespace fn_fc9dd2b5

// 0x000bbf60 FUN_000bbf60 (15 B): matches/0x000bbf60.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Fn@Wrap@fn_000bbf60@@QAEXH@Z
namespace fn_000bbf60 {
class Obj {
  public:
    void Do_000b7860(int);
};
class Wrap {
  public:
    char pad[4];
    Obj* p;
    void Fn(int);
};
void Wrap::Fn(int x) {
    if (p)
        p->Do_000b7860(x);
}
} // namespace fn_000bbf60

namespace fn_fc9dd2b5 {

// 0x000bbf70 FUN_000bbf70 (37 B): matches/0x000bbf70.cpp
// sym: ?Run@Obj@fn_fc9dd2b5@@QAEHHPAH@Z
int Obj::Run(int n, int* v) {
    Dest* q = p;
    if (!q)
        return -1;
    if (n != 1)
        return -1;
    q->Fn_000b78e0(*v);
    return 0;
}


// 0x000bbfa0 FUN_000bbfa0 (41 B): equivalent/0x000bbfa0.cpp
// sym: ?FUN_000bbfa0@Handler@fn_fc9dd2b5@@QAEHHPAUValues@2@@Z @2c4b11d71c66 @w8ecc73e2659c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000bbfa0 @ 0x000bbfa0
int Handler::FUN_000bbfa0(int type, Values *values) {
    if (!object || type != 2) return -1;
    object->FUN_000b79a0(values->first, values->second);
    return 0;
}


// 0x000bbfd0 FUN_000bbfd0 (23 B): matches/0x000bbfd0.cpp
// sym: ?Fn@Obj_bbfd0@fn_fc9dd2b5@@QAEHHH@Z
int Obj_bbfd0::Fn(int a, int b) {
    if (m == 0)
        return -1;
    m->FnF_000b7ff0();
    return 0;
}


// 0x000bbff0 FUN_000bbff0 (23 B): matches/0x000bbff0.cpp
// sym: ?Fn@Base_bbff0@fn_fc9dd2b5@@QAEHHH@Z
int Base_bbff0::Fn(int a, int b) {
    if (!mVal)
        return -1;
    mVal->Go_000b8430();
    return 0;
}

} // namespace fn_fc9dd2b5

// 0x000bc010 FUN_000bc010 (31 B): matches/0x000bc010.cpp [wrapped: compile error in a shared declaration (C2065)]
// sym: ?FUN_000bc010@Object@fn_000bc010@@QAEHPAX0@Z
namespace fn_000bc010 {
struct Inner {
    void FUN_000b8d00();
};
struct Object {
    char padding[4];
    Inner* value;
    int FUN_000bc010(void* first, void* second);
};
int Object::FUN_000bc010(void* first, void* second) {
    if (!value)
        return -1;
    if (first)
        return -1;
    value->FUN_000b8d00();
    return 0;
}
} // namespace fn_000bc010

namespace fn_fc9dd2b5 {

// 0x000bc030 FUN_000bc030 (3 B): matches/0x000bc030.cpp
// sym: _FUN_000bc030@4
extern "C" void __stdcall FUN_000bc030(int a) {}


// 0x000bc040 FUN_000bc040 (3 B): matches/0x000bc040.cpp
// sym: _FUN_000bc040@4
extern "C" void __stdcall FUN_000bc040(int a) {}


// 0x000bc050 FUN_000bc050 (15 B): matches/0x000bc050.cpp
// sym: ?Fn@X_bc050@fn_fc9dd2b5@@QAEXM@Z
void X_bc050::Fn(float unused) {
    if (m)
        m->Fn_000b8e70(unused);
}


// 0x000bc060 FUN_000bc060 (23 B): matches/0x000bc060.cpp
// sym: ?f@O_bc060@fn_fc9dd2b5@@QAEHHH@Z
int O_bc060::f(int a, int b) {
    P_bc060* p = m;
    if (!p)
        return -1;
    p->Fng_000b8940();
    return 0;
}


// 0x000bc080 FUN_000bc080 (25 B): matches/0x000bc080.cpp
// sym: ?Fn@Obj_bc080@fn_fc9dd2b5@@QAEHHH@Z
int Obj_bc080::Fn(int a, int b) {
    if (!m0)
        return -1;
    m0->field = 4;
    return 0;
}


// 0x000bc0a0 FUN_000bc0a0 (13 B): matches/0x000bc0a0.cpp
// sym: ?Fn@Obj@fn_fc9dd2b5@@QAEHHH@Z
int Obj::Fn(int a, int b) {
    owner->Action_000b99b0();
    return 0;
}

} // namespace fn_fc9dd2b5

// 0x000bc0b0 FUN_000bc0b0 (23 B): matches/0x000bc0b0.cpp [wrapped: compile error in a shared declaration (C2143)]
// sym: ?Run@Holder@fn_000bc0b0@@QAEHHH@Z
namespace fn_000bc0b0 {
class Obj {
  public:
    void Work_000b5bf0();
};
class Holder {
  public:
    int pad;
    Obj* obj;
    int Run(int a, int b);
};
int Holder::Run(int a, int b) {
    if (!obj)
        return -1;
    obj->Work_000b5bf0();
    return 0;
}
} // namespace fn_000bc0b0

namespace fn_fc9dd2b5 {

// 0x000bc0d0 FUN_000bc0d0 (23 B): matches/0x000bc0d0.cpp
// sym: ?Run@Wrapper@fn_fc9dd2b5@@QAEHHH@Z
int Wrapper::Run(int a, int b) {
    if (!obj)
        return -1;
    obj->Do_000b5ca0();
    return 0;
}


// 0x000bc0f0 FUN_000bc0f0 (15 B): equivalent/0x000bc0f0.cpp
// sym: ?FUN_000bc0f0@Object@fn_fc9dd2b5@@QAEHHH@Z @303b4a0aede5 @wbe5d75b6af29
// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 0/0)
// FUN_000bc0f0 @ 0x000bc0f0
int Object::FUN_000bc0f0(int a, int b) {
    inner->value = 16;
    return 0;
}


// 0x000bc100 FUN_000bc100 (218 B): equivalent/0x000bc100.cpp
// sym: ?FUN_000bc100@Loader_bc100@fn_fc9dd2b5@@QAEXXZ @711c786abc5c @w5a9aa63f6a56
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_000bc100 @ 0x000bc100
void Loader_bc100::FUN_000bc100()
{
    active = 0;
    FUN_000fc130(DAT_0049f3ac);
    for (int i = 0; i < 128; i++) {
        if (slotsA[i] == 0)
            break;
        FUN_0008d340(slotsA[i]);
        slotsA[i] = 0;
    }
    for (int i = 0; i < 128; i++) {
        if (slotsB[i] == 0)
            break;
        FUN_0008d340(slotsB[i]);
        slotsB[i] = 0;
    }
    FUN_000fc160();
    Scene_bc100 *scene = FUN_000fc1b0();
    if (scene)
        scene->FUN_000f7ce0();
    if (resource) {
        resource->FUN_001bf860(1);
        resource->FUN_001bdf00();
    }
    Hook_bc100 *hook = FUN_000fc3d0();
    if (hook)
        hook->vf65();
    (*(Pool_bc100**)&DAT_004dd9cc)->FUN_002665a0();
    display->FUN_00294980(displayArg);
    state = 6;
    FUN_0008e090()->ready = 1;
}

} // namespace fn_fc9dd2b5
