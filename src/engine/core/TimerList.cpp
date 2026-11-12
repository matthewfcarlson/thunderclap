// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00267ba0..0x00268300 (kind game, layer engine, confidence high), dominant class core::TimerList
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/unknown.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fc34aa1a {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc34aa1a {} using namespace fn_fc34aa1a;
namespace fn_fc34aa1a { extern "C" char DAT_0042af64[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fc34aa1a {
class TimerList {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    int mRefCount;
};
class IRefCount_267c90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
class TimerBase {
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
    virtual void vfunc_9();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
};
struct List_267ca0 {
    char pad[0x1c];
    unsigned int count;
    int* items;
};
} // namespace fn_fc34aa1a
namespace core {
struct TimerManager {
    char reserved[0x1c];
    unsigned int count;
    core::Timer** timers;
};
}
namespace fn_fc34aa1a {
struct X_267de0 {
    char pad[0x14];
    unsigned value;
};
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
class Object {
  public:
    virtual ~Object();
    int field;
    Object();
};
class Object_267ed0 : public core::BaseObject {
  public:
    int field;
    virtual Object_267ed0* vfunc_0(unsigned char);
};
extern void __cdecl FUN_00266f00(int, Object_267ed0*);
typedef unsigned long DWORD;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(DWORD*);
}
int __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042afcc[];
extern "C" char DAT_0042afd4[];
struct Callback_267fd0 {
    virtual void A();
    virtual void B();
};
void Init_00267090(int);
struct TimerList_267fd0 {
    void* v0;
    void* v1;
    int value;
    char pad[12];
    Callback_267fd0* cb;
    int gap;
    int arg;
    void F();
};
namespace XAPILIB {
int __stdcall QueryPerformanceCounter(__int64 *);
}
unsigned int __cdecl FUN_00267e20(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
class Timer;
class Child_2680f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(Timer*);
};
class Owner_2680f0 {
  public:
    virtual void f0();
    virtual void f1();
    char pad[0x14];
    Child_2680f0* child;
};
class Timer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
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
    int refs;
    char pad[0x18];
    Owner_2680f0* owner;
};
} // namespace fn_fc34aa1a
namespace core {
struct Timer_268220 {
    unsigned fun_00268070(core::TimerList*, unsigned, unsigned, unsigned, unsigned, unsigned);
};
}
namespace core {
struct Source {
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
    virtual Timer_268220* get();
};
}


// 0x00267ba0 core::TimerList::vfunc_0 (4 B): matches/0x00267ba0.cpp
// sym: ?vfunc_0@TimerList@core@@UAEXXZ
void core::TimerList::vfunc_0() {
    ++this->f_0c;
}

namespace fn_fc34aa1a {

// 0x00267bb0 core::TimerList::vfunc_1 (13 B): matches/0x00267bb0.cpp
// sym: ?f1@TimerList@fn_fc34aa1a@@UAEXXZ
void TimerList::f1() {
    if (--mRefCount == 0)
        f2(1);
}

} // namespace fn_fc34aa1a

// 0x00267bc0 core::TimerList::vfunc_4 (129 B): matches/0x00267bc0.cpp [wrapped: conflict: core::TimerList]
// sym: ?vfunc_4@TimerList@core@fn_00267bc0@@UAEXI@Z
namespace fn_00267bc0 {
typedef unsigned int uint32_267bc0;
struct Callback_267bc0 {
    virtual void vfunc_0(uint32_267bc0 elapsed, uint32_267bc0 data);
};
struct Timer {
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
    char pad04[4];
    uint32_267bc0 state;
    uint32_267bc0 interval;
    char pad10[4];
    uint32_267bc0 elapsed;
    Callback_267bc0* callback;
    uint32_267bc0 data;
};
namespace core {
struct TimerList {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(uint32_267bc0 now);
    virtual void vfunc_5();
    char pad04[12];
    unsigned char started;
    char pad11[3];
    uint32_267bc0 last;
    char pad18[4];
    uint32_267bc0 count;
    Timer** timers;
};
void TimerList::vfunc_4(uint32_267bc0 now) {
    if (!started) {
        last = now;
        started = 1;
        return;
    }
    uint32_267bc0 delta = now - last;
    last = now;
    for (uint32_267bc0 i = 0; i < count; ++i) {
        Timer* timer = timers[i];
        if (timer) {
            timer->elapsed += delta;
            if (timer->elapsed >= timer->interval) {
                if (timer->state == 1)
                    timer->vfunc_10();
                Callback_267bc0* callback = timer->callback;
                uint32_267bc0 amount = timer->elapsed;
                timer->elapsed = 0;
                if (callback) {
                    callback->vfunc_0(amount, timer->data);
                }
            }
        }
    }
}
} // namespace core
} // namespace fn_00267bc0


// 0x00267c90 core::Timer::vfunc_0 (4 B): matches/0x00267c90.cpp
// sym: ?vfunc_0@Timer@core@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void core::Timer::vfunc_0() {
    ++this->f_04;
}


// 0x00267ca0 core::Timer::vfunc_9 (68 B): matches/0x00267ca0.cpp
// sym: ?vfunc_9@Timer@core@@UAEXXZ
void core::Timer::vfunc_9() {
    if (!this->f_10) {
        this->f_14 = 0;
        this->f_10 = 1;
        List_267ca0* p = (*(List_267ca0 *volatile *)&this->f_20);
        unsigned int n = p->count;
        unsigned int i = 0;
        if (n > 0) {
            int* items = p->items;
            int* cur = items;
            do {
                if (*cur == 0) {
                    items[i] = (hulk_intptr)this;
                    return;
                }
                ++i;
                ++cur;
            } while (i < (*(List_267ca0 *volatile *)&this->f_20)->count);
        }
    }
}


// 0x00267cf0 core::Timer::vfunc_10 (65 B): matches/0x00267cf0.cpp
// sym: ?vfunc_10@Timer@core@@UAEXXZ
 // namespace core
void core::Timer::vfunc_10() {
    if (this->f_10) {
        TimerManager* mgr = (*(TimerManager *volatile *)&this->f_20);
        this->f_10 = 0;
        unsigned int i = 0;
        if (mgr->count > 0) {
            core::Timer** list = mgr->timers;
            core::Timer** cur = list;
            do {
                if (*cur == this) {
                    list[i] = 0;
                    break;
                }
                ++i;
                ++cur;
            } while (i < (*(TimerManager *volatile *)&this->f_20)->count);
        }
    }
}


// 0x00267d40 core::Timer::vfunc_3 (17 B): matches/0x00267d40.cpp
// sym: ?vfunc_3@Timer@core@@UAEXHH@Z
void core::Timer::vfunc_3(int x, int y) {
    this->f_18 = x;
    this->f_1c = y;
}


// 0x00267d60 core::Timer::vfunc_4 (10 B): matches/0x00267d60.cpp
// sym: ?vfunc_4@Timer@core@@UAEXH@Z
// Same code shape as 0x00254720 (propagated; names are from that function)
void core::Timer::vfunc_4(int ) {
    this->f_18 = 0;
}


// 0x00267d70 core::Timer::vfunc_5 (4 B): matches/0x00267d70.cpp
// sym: ?vfunc_5@Timer@core@@UAEIXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
unsigned int core::Timer::vfunc_5() {
    return this->f_0c;
}


// 0x00267d80 core::Timer::vfunc_6 (44 B): matches/0x00267d80.cpp
// sym: ?vfunc_6@Timer@core@@UAEXH@Z
void core::Timer::vfunc_6(int x) {
    if (this->f_10) {
        vfunc_10();
        (*(int *)&this->f_0c) = x;
        vfunc_9();
    } else {
        (*(int *)&this->f_0c) = x;
    }
}

namespace fn_fc34aa1a {

// 0x00267db0 core::Timer::vfunc_7 (4 B): matches/0x00267db0.cpp
// sym: ?FUN_00267db0@fn_fc34aa1a@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_00267db0(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_fc34aa1a

// 0x00267dc0 core::Timer::vfunc_8 (10 B): matches/0x00267dc0.cpp
// sym: ?vfunc_8@Timer@core@@UAEXH@Z
// Same code shape as 0x000fc4b0 (propagated; names are from that function)
void core::Timer::vfunc_8(int value) {
    this->f_08 = value;
}


// 0x00267dd0 core::Timer::vfunc_11 (11 B): matches/0x00267dd0.cpp
// sym: ?vfunc_11@Timer@core@@UAE_NXZ
bool core::Timer::vfunc_11() {
    return this->f_10 == 0;
}

namespace fn_fc34aa1a {

// 0x00267de0 core::Timer::vfunc_12 (4 B): matches/0x00267de0.cpp
// sym: ?target@fn_fc34aa1a@@YIIPAUX_267de0@1@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
unsigned __fastcall target(X_267de0* self) {
    return self->value;
}

} // namespace fn_fc34aa1a

// 0x00267df0 core::Timer::vfunc_13 (40 B): matches/0x00267df0.cpp [wrapped: conflict: core::Timer]
// sym: ?vfunc_13@Timer@core@fn_00267df0@@UAEMXZ
namespace fn_00267df0 {
namespace core {
class Timer {
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
    virtual hulk_freg vfunc_13();
    int a[2];
    unsigned int denominator;
    int b;
    unsigned int numerator;
};
hulk_freg Timer::vfunc_13() {
    return (hulk_freg)numerator / (hulk_freg)denominator;     // x87: both fild, unrounded
}
} // namespace core
} // namespace fn_00267df0

namespace fn_fc34aa1a {

// 0x00267e20 FUN_00267e20 (99 B): matches/0x00267e20.cpp
// sym: ?MulDiv64@fn_fc34aa1a@@YA_K_K00@Z
unsigned __int64 MulDiv64(unsigned __int64 a, unsigned __int64 b, unsigned __int64 c) {
    unsigned __int64 q = a / c;
    unsigned __int64 r = a % c;
    return r * b / c + q * b;
}


// 0x00267e90 core::BaseObject::vfunc_0 (31 B): matches/0x00267e90.cpp
// sym: ?f2@NonCopyable@pure3d@fn_fc34aa1a@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_0042af64;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00267eb0 FUN_00267eb0 (26 B): matches/0x00267eb0.cpp
// sym: ??0Object@fn_fc34aa1a@@QAE@XZ
// data: gValue_267eb0 = DAT_004cdbb0
Object::Object() {
    field = DAT_004cdbb0;
    Init();
}


// 0x00267ed0 core::Object::vfunc_0 (46 B): matches/0x00267ed0.cpp
// sym: ?vfunc_0@Object_267ed0@fn_fc34aa1a@@UAEPAV12@E@Z
// data: g_saved = DAT_004cdbb0
Object_267ed0* Object_267ed0::vfunc_0(unsigned char param) {
    (*(volatile int*)&DAT_004cdbb0) = field;
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042af64);
    if (param & 1)
        FUN_00266f00((*(volatile int*)&DAT_004cdbb0), this);
    return this;
}


// 0x00267f00 FUN_00267f00 (52 B): matches/0x00267f00.cpp
// sym: _FUN_00267f00
extern "C" int __cdecl FUN_00267f00(void) {
    DWORD local[2];
    XAPILIB::QueryPerformanceCounter(local);
    return FUN_00267e20(local[0], local[1], 1000000, 0, (*(DWORD*)&DAT_00528380), (*(DWORD*)&DAT_00528384));
}

} // namespace fn_fc34aa1a

// 0x00267f40 FUN_00267f40 (52 B): matches/0x00267f40.cpp [wrapped: conflict: FUN_00267e20]
// sym: _FUN_00267f40
namespace fn_00267f40 {
// Same code shape as 0x00267f00 (propagated; names are from that function)

typedef unsigned long DWORD;
namespace XAPILIB {
void __stdcall QueryPerformanceCounter(DWORD*);
}
unsigned __int64 __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
extern "C" unsigned __int64 __cdecl FUN_00267f40(void) {
    DWORD local[2];
    XAPILIB::QueryPerformanceCounter(local);
    return FUN_00267e20(local[0], local[1], 1000000, 0, (*(DWORD*)&DAT_00528380), (*(DWORD*)&DAT_00528384));
}
} // namespace fn_00267f40


// 0x00267f80 FUN_00267f80 (52 B): matches/0x00267f80.cpp [wrapped: conflict: DWORD]
// sym: _FUN_00267f80
namespace fn_00267f80 {

typedef unsigned int DWORD;
struct LARGE_INTEGER {
    DWORD low;
    DWORD high;
};
extern "C++" __declspec(nothrow) int __stdcall QueryPerformanceCounter(LARGE_INTEGER*);
extern "C++" __declspec(nothrow) int __cdecl FUN_00267e20(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);
extern "C" int FUN_00267f80() {
    LARGE_INTEGER n;
    QueryPerformanceCounter(&n);
    return FUN_00267e20(n.low, n.high, 1000, 0, (*(DWORD*)&DAT_00528380), (*(DWORD*)&DAT_00528384));
}
} // namespace fn_00267f80

namespace fn_fc34aa1a {

// 0x00267fd0 FUN_00267fd0 (59 B): matches/0x00267fd0.cpp
// sym: ?F@TimerList_267fd0@fn_fc34aa1a@@QAEXXZ
void TimerList_267fd0::F() {
    v0 = (void*)((hulk_intptr)DAT_0042afd4);
    v1 = (void*)((hulk_intptr)DAT_0042afcc);
    Init_00267090(arg);
    cb->B();
    DAT_004cdbb0 = value;
    v1 = (void*)((hulk_intptr)DAT_0042af64);
    v0 = (void*)((hulk_intptr)DAT_003f6098);
}

} // namespace fn_fc34aa1a

// 0x00268010 core::TimerList::vfunc_0_adj4 (8 B): matches/0x00268010.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?f@C_268010@fn_00268010@@W3AEXXZ
namespace fn_00268010 {
class A_268010 {
  public:
    virtual void f();
    virtual ~A_268010();
};
class B_268010 {
  public:
    virtual void f();
    virtual ~B_268010();
};
class C_268010 : public A_268010, public B_268010 {
  public:
    virtual void f();
    virtual ~C_268010();
    int mX;
};
void C_268010::f() {
    mX = 0;
}
C_268010::~C_268010() {}
} // namespace fn_00268010


// 0x00268020 core::TimerList::vfunc_5 (70 B): equivalent/0x00268020.cpp
// sym: ?vfunc_5@TimerList@core@@UAEXXZ @af8830d36394 @w35f89150bf2f
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// core::TimerList::vfunc_5 @ 0x00268020
void core::TimerList::vfunc_5() {
 __int64 counter;
 XAPILIB::QueryPerformanceCounter(&counter);
 unsigned int result = FUN_00267e20((unsigned int)counter, (unsigned int)(counter >> 32), 1000, 0, (*(unsigned int*)&DAT_00528380), (*(unsigned int*)&DAT_00528384));
 this->vfunc_4((int)result);
}


// 0x00268070 FUN_00268070 (89 B): matches/0x00268070.cpp [wrapped: conflict: Timer]
// sym: ??0Timer@fn_00268070@@QAE@PAUObj_268070@1@HHHDH@Z
namespace fn_00268070 {
extern "C" char DAT_0042aff0[];
struct Obj_268070 {
    virtual void f();
};
class Timer {
  public:
    hulk_intptr x0;
    int x4;
    int x8;
    int xc;
    char flag;
    char pad[7];
    int x18;
    int x1c;
    Obj_268070* obj;
    void vfunc_9_00267ca0();
    Timer(Obj_268070* e, int b, int c, int d, char g, int f);
};
void InitTimer_002705f0();
Timer::Timer(Obj_268070* e, int b, int c, int d, char g, int f) {
    x8 = f;
    x0 = ((hulk_intptr)DAT_0042aff0);
    x4 = 1;
    xc = b;
    flag = 0;
    x18 = c;
    x1c = d;
    obj = e;
    InitTimer_002705f0();
    e->f();
    if (g)
        vfunc_9_00267ca0();
}
} // namespace fn_00268070

namespace fn_fc34aa1a {

// 0x002680f0 core::Timer::vfunc_1 (39 B): matches/0x002680f0.cpp
// sym: ?f1@Timer@fn_fc34aa1a@@UAEXXZ
void Timer::f1() {
    if (--refs == 0) {
        Owner_2680f0* o = owner;
        f2(0);
        o->child->f4(this);
        o->f1();
    }
}

} // namespace fn_fc34aa1a

// 0x00268120 FUN_00268120 (151 B): matches/0x00268120.cpp [wrapped: conflict: core::ITimerList; core::Object; core::TimerList]
// sym: ??0TimerList@core@fn_00268120@@QAE@II@Z
namespace fn_00268120 {
// FUN_00268120 @ 0x00268120

void __cdecl FUN_002705f0();
void __cdecl FUN_002702a0(void *, unsigned, unsigned, unsigned, unsigned, const char *, unsigned);
extern "C" void *__cdecl FUN_00266e00(unsigned, unsigned);
namespace core {
struct ITimerList {
    virtual void timerMethod() HULK_PURE64;
};
struct Object {
    int id;
    virtual void objectMethod();
    Object() {
        id = DAT_004cdbb0;
        FUN_002705f0();
    }
};
struct TimerList : ITimerList, Object {
    int active;
    char enabled;
    char reserved[7];
    char entries[4];
    unsigned count;
    void **items;
    TimerList(unsigned size, unsigned tag);
    virtual void timerMethod();
    virtual void objectMethod();
};
TimerList::TimerList(unsigned size, unsigned tag) {
    active = 1;
    enabled = 0;
    count = size;
    FUN_002705f0();
    FUN_002702a0(entries, 0x24, size, 0, tag, "TimerList", 4);
    items = (void **)FUN_00266e00(tag, size * 4);
    FUN_002705f0();
    for (unsigned i = 0; i < size; ++i)
        items[i] = 0;
}
}
} // namespace fn_00268120


// 0x002681c0 core::TimerList::vfunc_2 (86 B): matches/0x002681c0.cpp [wrapped: conflict: TimerList]
// sym: ?v2@TimerList@fn_002681c0@@UAEPAV12@E@Z
namespace fn_002681c0 {
// data: global_2681c0 = DAT_004cdbb0

typedef unsigned char byte_2681c0;
typedef unsigned int u32_2681c0;
extern void __cdecl FUN_00267090(u32_2681c0);
extern void __cdecl FUN_00266f00(u32_2681c0, void*);
extern int hulk_at_0042afd4, hulk_at_0042afcc, hulk_at_0042af64, hulk_at_003f6098;
struct Helper_2681c0 {
    virtual void f0();
    virtual void f1();
};
class TimerList {
  public:
    virtual void v0();
    virtual void v1();
    virtual TimerList* v2(byte_2681c0);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char p0[4];
    u32_2681c0 field8;
    char pad[12];
    Helper_2681c0* helper;
    u32_2681c0 pad1;
    u32_2681c0 field20;
};
TimerList* TimerList::v2(byte_2681c0 p) {
    u32_2681c0 x = field20;
    *(hulk_uintptr*)this = (hulk_uintptr)&hulk_at_0042afd4;
    *((u32_2681c0*)this + 1) = (hulk_uintptr)&hulk_at_0042afcc;
    FUN_00267090(x);
    helper->f1();
    (*(u32_2681c0*)&DAT_004cdbb0) = field8;
    *((u32_2681c0*)this + 1) = (hulk_uintptr)&hulk_at_0042af64;
    *(hulk_uintptr*)this = (hulk_uintptr)&hulk_at_003f6098;
    if (p & 1)
        FUN_00266f00((*(u32_2681c0*)&DAT_004cdbb0), this);
    return this;
}
} // namespace fn_002681c0


// 0x00268220 core::TimerList::vfunc_3 (70 B): matches/0x00268220.cpp
// sym: ?vfunc_3@TimerList@core@@UAEXHHHHHH@Z
 // namespace core
void core::TimerList::vfunc_3(hulk_intptr __p0, int __p1, int __p2, int __p3, int __p4, int __p5) { unsigned int * result = (unsigned int *)__p0; unsigned int a = (unsigned int)__p1; unsigned int b = (unsigned int)__p2; unsigned int c = (unsigned int)__p3; unsigned int d = (unsigned int)__p4; unsigned int e = (unsigned int)__p5;

    Timer_268220* timer = (*(Source * *)&this->f_18)->get();
    *result = timer ? timer->fun_00268070(this, a, b, c, d, e) : 0;
}


// 0x00268270 core::Timer::vfunc_2 (49 B): matches/0x00268270.cpp [wrapped: conflict: Timer]
// sym: ?vfunc_2@Timer@fn_00268270@@UAEPAV12@H@Z
namespace fn_00268270 {
typedef unsigned char u8;
extern void thunk_FUN_00267090(void*);
extern void* hulk_at_0042aff0;
extern void* refVftable;
class Timer {
  public:
    virtual void f0();
    virtual void f1();
    virtual Timer* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void vfunc_10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    char pad[12];
    u8 active;
};
Timer* Timer::vfunc_2(int flag) {
    *(void**)this = &hulk_at_0042aff0;
    if (active)
        Timer::vfunc_10();
    *(void**)this = &refVftable;
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00268270

