// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00085d90..0x00088e60 (kind game, layer game, confidence high), dominant class CTimeManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5b26912 {
#define TREE_TU_END }
namespace fn_f5b26912 {} using namespace fn_f5b26912;
namespace fn_f5b26912 { extern "C" char DAT_003ffab4[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
namespace fn_f5b26912 {
extern "C" unsigned __int64 __cdecl FUN_00267f40();
struct Bits {
    unsigned lo;
    unsigned hi;
};
union U {
    unsigned __int64 n;
    Bits b;
};
class X {
  public:
    char _m_pad_0[0x30];
    unsigned __int64 v;
    char _m_pad_38[0x24];
    char buf[0x40];
    char flag;
    hulk_freg Get();
    void Set(const char* s);
};
extern float scale_86100;
extern "C" void __cdecl FUN_001eb200();
struct Obj_86180 {
    void Call(int);
};
class Obj_861f0;
class A_861f0 {
  public:
    void F();
    void G(Obj_861f0*, int);
};
class Obj_861f0 {
  public:
    char pad[4];
    int m4;
    char pad2[0x18];
    A_861f0* m20;
    void Target();
};
class Inner_86240 {
  public:
    void Step();
};
class Target_86240 {
  public:
    char pad[0x1c];
    Inner_86240* member;
    void Run();
};
extern bool FUN_0008db80();
extern "C" void FUN_0008db90();
struct X_86270 {
    int pad;
    unsigned int value;
};
class C_86280 {
    char pad[0x20];

  public:
    unsigned int value;
};
class Obj_862c0 {
    char pad[0x10];

  public:
    unsigned int value;
};
struct X_862d0 {
    char pad[0x14];
    unsigned value;
};
class C_862e0 {
    char pad[0x30];

  public:
    unsigned int value;
};
class A_86380 {
    char pad[0x4c];

  public:
    unsigned int value;
};
struct Inner_863e0 {
    char pad[0x18];
    void f();
};
struct Mid_863e0 {
    char pad[0x18];
    Inner_863e0* p;
};
struct Root_863e0 {
    char pad[0x54];
    Mid_863e0* p;
};
extern Root_863e0* g_863e0;
struct Inner_86400 {
    char pad[0x18];
};
struct Mid_86400 {
    char pad[0x18];
    Inner_86400* p18;
};
struct Outer_86400 {
    char pad[0x54];
    Mid_86400* p54;
};
extern Outer_86400* gGlobal_86400;
struct Final_86400 {
    void Run();
};
struct Obj_86400 {
    int a;
    char pad[4];
    int c;
    void Run();
};
struct A_86420 {
    void f();
};
struct B_86420 {
    void g();
};
struct Hub_86420 {
    char pad[0x10];
    A_86420* a;
    char pad2[4];
    B_86420* b;
};
struct Manager_86420 {
    char pad[0x54];
    Hub_86420* hub;
};
extern Manager_86420* gManager_86420;
struct A_865d0 {
    void f2();
    void f4();
    void f6(int);
    void f8(void*, int);
};
struct B_865d0 {
    void f3(int);
};
struct C_865d0 {
    void f5();
};
struct Obj_865d0 {
    char pad0[4];
    int v4;
    char pad8[0x18];
    A_865d0* p20;
    char pad24[0xc];
    C_865d0* p30;
    char pad34[4];
    B_865d0* p38;
    A_865d0* init();
};
struct Target_86630;
struct Audio_86630 { void FUN_000ae9a0(int); void FUN_000ae980(); };
struct Stop_86630 { void FUN_000afe80(); };
struct Panel_86630 { void FUN_001b8780(int); void FUN_001b8900(int); };
struct View { void FUN_001b7590(); };
struct Resource_86630;
struct Renderer_86630 { void FUN_00208820(); void FUN_00206320(Resource_86630*); };
struct State_86630 { int value; };
struct Controller_86630 { void FUN_000bd1b0(int); void FUN_000bc100(); void FUN_000bf0e0(Target_86630*,State_86630*); void FUN_000bb600(); };
struct Service_86630 { void FUN_0022aba0(int); };
extern int __cdecl FUN_00267f00();
extern "C" Service_86630* __stdcall FUN_000964d0();
struct Manager_86630 { void FUN_001d2760(); void FUN_001d4530(); void FUN_001d15d0(int); void FUN_001d3c50(); };
extern Manager_86630* __cdecl FUN_001d4c90();
struct Sub_86630 { void FUN_001e11d0(); };
struct Scene_86630 { void FUN_001ee020(); void FUN_001ec310(int); };
struct Handler_86630 { void FUN_0008dba0(Target_86630*); };
struct Item_86630 { void FUN_001bc4e0(); };
struct Loader_86630 { void FUN_000d6b20(Target_86630*); };
struct Resource_86630 { void FUN_00089980(); };
struct Flag_86630 { char pad[8]; unsigned char enabled; };
struct Context { char pad0[4]; Flag_86630* flag; char pad8[4]; Sub_86630* sub; char pad10[48]; Item_86630* item; void FUN_00088940(Target_86630*,Resource_86630*); };
struct GlobalSub { char pad[16]; Audio_86630* audio; char pad14[4]; Stop_86630* stop; };
} // namespace fn_f5b26912
struct World { char pad[84]; GlobalSub* sub; };
namespace fn_f5b26912 {
struct Target_86630 { char pad0[4]; State_86630* state; char pad8[4]; Context* context; Audio_86630* audio; char pad14[4]; Stop_86630* stop; Handler_86630* handler; Controller_86630* controller; Panel_86630* panel; Renderer_86630* renderer; Loader_86630* loader; Scene_86630* scene; View* view; Resource_86630* resource; char pad3c[20]; unsigned char enabled; void FUN_00086630(); };
typedef unsigned int u32_86900;
struct Worker_86900 {
    void Reset(int);
};
struct Tail_86900 {
    void Run();
};
struct State_86900 {
    char p0[0x10];
    u32_86900 x10, x14, x18, x1c;
    char p20[0x18];
    u32_86900 x38, x3c;
    char p40[8];
    u8 x48;
};
struct Obj_86900 {
    char p0[8];
    State_86900* state;
    char pc[0x10];
    Worker_86900* worker;
    char p20[0x10];
    Tail_86900* tail;
};
class A_86940 {
  public:
    void Run();
};
class B_86940 {
  public:
    void Finish();
};
class Thing_86940 {
  public:
    char pad[0x18];
    A_86940* a;
    char pad2[0x14];
    B_86940* b;
    void Run();
};
class Other_86960 {
  public:
    void First();
};
class Thing_86960 {
  public:
    char pad[0x30];
    Other_86960* a;
    Other_86960* b;
    void Run();
};
struct State {
    int value;
};
struct First {
    void f();
};
struct Second {
    void g();
};
struct A {
    char pad[0x10];
    First* first;
    char pad2[4];
    Second* second;
};
struct Root {
    char pad[0x54];
    A* a;
};
extern Root* globalRoot;
class Obj {
  public:
    char pad[4];
    State* state;
    void run();
};
class C10_86a40 {
  public:
    void F();
};
class C14_86a40 {
  public:
    void F(int);
};
class C18 {
  public:
    void F(int);
};
class C1c;
class C20;
class C24 {
  public:
    void F(C1c*);
};
class C28 {
  public:
    void F();
};
class C2c {
  public:
    void F(int);
};
class C30 {
  public:
    void F(int, int);
};
class C48 {
  public:
    void F();
};
class A_86a40;
class C20 {
  public:
    void F(A_86a40*, int*, int, C30*, C24*);
};
struct State_86a40 {
    int id;
};
class A_86a40 {
  public:
    char pad0[4];
    State_86a40* p4;
    char pad8[8];
    C10_86a40* p10;
    C14_86a40* p14;
    C18* p18;
    C1c* p1c;
    C20* p20;
    C24* p24;
    C28* p28;
    C2c* p2c;
    C30* p30;
    char pad34[20];
    C48* p48;
    void Run(int);
};
extern bool __cdecl Check();
class B_86da0 {
  public:
    void a();
};
bool b80();
void thunk();
void f656a0();
class C_86da0 {
  public:
};
class A_86da0 {
  public:
    char pad[0x1c];
    B_86da0* x;
    char pad2[0x10];
    C_86da0* y;
    void tail();
    void run();
};
struct Function_86eb0 { virtual void vfunc_0(); virtual void vfunc_1(); };
class Function_86fa0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void**, void**);
};
extern "C" char DAT_003ffb80[];
extern "C" char DAT_0048e10c[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
typedef bool (*Fn_86fc0)();
class Function4_86fc0 : public FUN_001d0480 {
  public:
    void* vt;
    ScriptFunctionFields f;
    Fn_86fc0 member1c;
    Function4_86fc0(const char*, Fn_86fc0);
};
class CActorManager_87270 {
  public:
    void f();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
} // namespace fn_f5b26912
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f5b26912 {
class __declspec(novtable) MethodBase_87a90 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_87a90(const char* n, int k) { FUN_001d0480(n, k); }
};
template <class R>
class Function0_87a90 : public MethodBase_87a90 {
  public:
    typedef R (*Fn)();
    Function0_87a90(const char* name, Fn f) : MethodBase_87a90(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};
struct Registry_87a90 {
    void FUN_00087a90(const char* name, float (*fn)());
};
class CActorManager_87cb0 {
  public:
    float Get();
};
typedef float (CActorManager_87cb0::*Fn_87cb0)();
class CActorManager_87d40 {
  public:
    void run();
};
extern owners::Obj_88530* g_88530;
struct Sim_88670;
struct Cfg_88670 { char pad[0x2c]; int v2c; };
struct Ctx_88670 {
    void *FUN_00086320();
    Cfg_88670 *FUN_00086380();
};
struct CSimControllerManager_nv_88670 {
    CSimControllerManager *FUN_000b3c90(int a);
    void FUN_000b3d00();
};
struct CCameraManager_nv_88670 {
    CCameraManager *FUN_0009dd20();
};
struct Sys10 { void FUN_001b3fc0(); };
struct CSPManager_nv_88670 {
    CSPManager *FUN_001e7470();
    void FUN_001de360(Sim_88670 *s);
};
struct CPatrolPathManager_nv_88670 {
    CPatrolPathManager *FUN_00106e90(int n);
    void FUN_001063e0();
};
struct CPathManager_nv_88670 {
    CPathManager *FUN_001aec00();
    void FUN_001acd80();
};
struct F_88670 { F_88670 *FUN_00025a90();  };
struct CWorldCollisionManager_nv_88670 {
    CWorldCollisionManager *FUN_002023e0();
    void FUN_00203490();
};
struct CTriggerVolumeManager_nv_88670 {
    CTriggerVolumeManager *FUN_001ff580();
    void FUN_00200c10(Sim_88670 *s);
};
struct CScenarioManager_nv_88670 {
    CScenarioManager *FUN_001cd150();
    void FUN_001cfb20(Sim_88670 *s);
};
struct CEventManager_nv_88670 {
    CEventManager *FUN_001cc360();
};
struct K_88670 {  void FUN_001eebc0(); };
struct L_88670 { L_88670 *FUN_001f6c30(); void FUN_001f81c0(); };
struct CSimOverlayManager_nv_88670 {
    CSimOverlayManager *FUN_000d75c0();
};
struct CExtraRenderingCallback_nv_88670 {
    CExtraRenderingCallback *FUN_001bceb0();
};
struct O_88670 { O_88670 *FUN_00059ad0(); };
struct CGameDataHandler_nv_88670 {
    CGameDataHandler *FUN_001fae80();
    void FUN_001fb1e0();
};
struct CAmbientsManager_nv_88670 {
    CAmbientsManager *FUN_0007f950();
};
struct R_88670 { void FUN_00066c20(Sim_88670 *s); };
extern "C" Sys10 *__cdecl FUN_001b6580();
extern "C" void *__cdecl FUN_001b6990();
R_88670 *__stdcall FUN_000678d0();
struct Sim_88670 {
    void FUN_00088670(Ctx_88670 *ctx, hulk_intptr arg1);
    int pad0;
    CSimControllerManager *a;     // 4
    CCameraManager *b;     // 8
    CSPManager *c;     // c
    Sys10 *s10; // 10
    void *s14;
    CPatrolPathManager *d;     // 18
    CPathManager *e;     // 1c
    F_88670 *f;     // 20
    CWorldCollisionManager *g;     // 24
    CTriggerVolumeManager *h;     // 28
    CScenarioManager *i;     // 2c
    CEventManager *j;     // 30
    K_88670 *k;     // 34
    L_88670 *l;     // 38
    CSimOverlayManager *m;     // 3c
    CExtraRenderingCallback *n;     // 40
    O_88670 *o;     // 44
    CGameDataHandler *p;     // 48
    CAmbientsManager *q;     // 4c
    Cfg_88670 *cfg50; // 50
    Ctx_88670 *ctx;   // 54
    void *p58;  // 58
    char pad1[0x9d - 0x5c];
    char ready;
};
} // namespace fn_f5b26912
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned);
#endif

namespace fn_f5b26912 {

// 0x00085d90 FUN_00085d90 (43 B): matches/0x00085d90.cpp
// sym: ?FUN_00085d90@fn_f5b26912@@YA_NXZ
bool __cdecl FUN_00085d90() {
    int sum = 0;
    signed char c = DAT_0049bfc8[0];
    if (c) {
        const signed char* text = (const signed char*)DAT_0049bfc8;
        do {
            sum += c;
            ++text;
            c = *text;
        } while (c);
    }
    return sum == DAT_0049c0c8;
}


// 0x00085e60 FUN_00085e60 (60 B): matches/0x00085e60.cpp
// sym: _FUN_00085e60
extern "C" double __cdecl FUN_00085e60(unsigned __int64 bits) {
    double result = (double)bits;
    result *= (*(float*)&DAT_003ffaa4);
    return result;
}

} // namespace fn_f5b26912

// 0x00085f50 FUN_00085f50 (10 B): matches/0x00085f50.cpp
// sym: ?FUN_00085f50@Thing_85f50@owners@@QAEXE@Z
void owners::Thing_85f50::FUN_00085f50(unsigned char value) {
    field = value;
}


// 0x00085f80 FUN_00085f80 (60 B): matches/0x00085f80.cpp
// sym: ?FUN_00085f80@Counter_85f80@owners@@QAENXZ
// data: scale = DAT_003ffaa4
double owners::Counter_85f80::FUN_00085f80() {
    return (double)value * DAT_003ffaa4;
}


// 0x00085fc0 FUN_00085fc0 (60 B): matches/0x00085fc0.cpp
// sym: ?FUN_00085fc0@Timer_85fc0@owners@@QAENXZ
// data: scale = DAT_003ffaa4
double owners::Timer_85fc0::FUN_00085fc0() {
    return (double)ticks * DAT_003ffaa4;
}

namespace fn_f5b26912 {

// 0x00086000 FUN_00086000 (59 B): matches/0x00086000.cpp
// sym: _FUN_00086000
extern "C" long double __cdecl FUN_00086000() {
    U x;
    x.n = FUN_00267f40();
    unsigned high = x.b.hi;
    x.b.hi = high & 0x7fffffff;
    long double a = (__int64)x.n;
    x.b.hi = high & 0x80000000;
    x.b.lo = 0;
    long double b = (__int64)x.n;
    b = -b;
    return (b + a) * DAT_003ffaa4;
}

} // namespace fn_f5b26912

// 0x00086040 FUN_00086040 (60 B): matches/0x00086040.cpp
// sym: ?FUN_00086040@Clock_86040@owners@@QAENXZ
// data: scale = DAT_003ffaa4
double owners::Clock_86040::FUN_00086040() {
    return (double)count * DAT_003ffaa4;
}


// 0x00086080 FUN_00086080 (60 B): matches/0x00086080.cpp
// sym: ?FUN_00086080@Obj_86080@owners@@QAENXZ
// data: scale = DAT_003ffaa4
double owners::Obj_86080::FUN_00086080() {
    return (double)ticks * DAT_003ffaa4;
}

namespace fn_f5b26912 {

// 0x000860c0 FUN_000860c0 (60 B): matches/0x000860c0.cpp
// sym: ?Get@X@fn_f5b26912@@QAEMXZ
// data: scale = DAT_003ffaa4
hulk_freg X::Get() {
    return (double)v * DAT_003ffaa4;
}

} // namespace fn_f5b26912

// 0x00086100 FUN_00086100 (33 B): matches/0x00086100.cpp
// sym: ?FUN_00086100@Thing_86100@owners@@QAEXM@Z
void owners::Thing_86100::FUN_00086100(float x) {
    value = (__int64)(x * 65536.0f);
    FUN_001eb200();
}


// 0x00086130 FUN_00086130 (60 B): matches/0x00086130.cpp [wrapped: conflict: X; X::Get]
// sym: ?Get@X@fn_00086130@@QAENXZ
namespace fn_00086130 {

struct X {
    char pad[0x38];
    unsigned int lo;
    unsigned int hi;
    double Get();
};
double X::Get() {
    struct Q {
        unsigned int lo;
        unsigned int hi;
    };
    Q a = *(Q*)&lo;
    unsigned int h = a.hi;
    a.hi &= 0x7fffffff;
    double v = (double)*(__int64*)&a;
    a.hi = h & 0x80000000;
    a.lo = 0;
    double n = -(double)*(__int64*)&a;
    return (n + v) * DAT_003ffaac;
}
} // namespace fn_00086130

namespace fn_f5b26912 {

// 0x00086180 FUN_00086180 (23 B): matches/0x00086180.cpp
// sym: ?Target@fn_f5b26912@@YGXHHHH@Z
// data: gObject_86180 = DAT_004dd6e8
void __stdcall Target(int a, int b, int c, int d) {
    if ((*(Obj_86180**)&DAT_004dd6e8))
        (*(Obj_86180**)&DAT_004dd6e8)->Call(a);
}


// 0x000861f0 FUN_000861f0 (26 B): matches/0x000861f0.cpp
// sym: ?Target@Obj_861f0@fn_f5b26912@@QAEXXZ
void Obj_861f0::Target() {
    m20->F();
    m20->G(this, m4);
}


// 0x00086240 FUN_00086240 (43 B): matches/0x00086240.cpp
// sym: ?Run@Target_86240@fn_f5b26912@@QAEXXZ
void Target_86240::Run() {
    if (member != 0) {
        while (FUN_0008db80()) {
            FUN_0008db90();
            member->Step();
        }
    }
}


// 0x00086270 FUN_00086270 (4 B): matches/0x00086270.cpp
// sym: ?FUN_00086270@fn_f5b26912@@YIIPAUX_86270@1@@Z
hulk_uintptr __fastcall FUN_00086270(X_86270* p) {
    return p->value;
}


// 0x00086280 FUN_00086280 (4 B): matches/0x00086280.cpp
// sym: ?target@fn_f5b26912@@YIIPAVC_86280@1@@Z
hulk_uintptr __fastcall target(C_86280* self) {
    return self->value;
}

} // namespace fn_f5b26912

// 0x00086290 FUN_00086290 (4 B): matches/0x00086290.cpp
// sym: ?FUN_00086290@Obj_86290@owners@@QAEHXZ
hulk_intptr owners::Obj_86290::FUN_00086290() {
    return mValue;
}


// 0x000862a0 FUN_000862a0 (4 B): matches/0x000862a0.cpp
// sym: ?FUN_000862a0@Target_862a0@owners@@QAEIXZ
hulk_uintptr owners::Target_862a0::FUN_000862a0() {
    return value;
}


// 0x000862b0 FUN_000862b0 (4 B): matches/0x000862b0.cpp
// sym: ?FUN_000862b0@C_862b0@owners@@QAEIXZ
hulk_uintptr owners::C_862b0::FUN_000862b0() {
    return *(unsigned int*)((char*)this + 0x2c);
}

namespace fn_f5b26912 {

// 0x000862c0 FUN_000862c0 (4 B): matches/0x000862c0.cpp
// sym: @FUN_000862c0@4
// Same code shape as 0x00059a30 (propagated; names are from that function)
extern "C" hulk_uintptr __fastcall FUN_000862c0(Obj_862c0* self) {
    return self->value;
}


// 0x000862d0 FUN_000862d0 (4 B): matches/0x000862d0.cpp
// sym: ?target@fn_f5b26912@@YIIPAUX_862d0@1@@Z
hulk_uintptr __fastcall target(X_862d0* self) {
    return self->value;
}


// 0x000862e0 FUN_000862e0 (4 B): matches/0x000862e0.cpp
// sym: @FUN_000862e0@4
extern "C" hulk_uintptr __fastcall FUN_000862e0(C_862e0* self) {
    return self->value;
}


// 0x00086300 FUN_00086300 (4 B): matches/0x00086300.cpp
// sym: @FUN_00086300@4
extern "C" unsigned int __fastcall FUN_00086300(void* p) {
    return *(unsigned int*)((char*)p + 0x34);
}

} // namespace fn_f5b26912

// 0x00086310 FUN_00086310 (4 B): matches/0x00086310.cpp
// sym: ?FUN_00086310@C_86310@owners@@QAEIXZ
hulk_uintptr owners::C_86310::FUN_00086310() {
    return value;
}

namespace fn_f5b26912 {

// 0x00086320 FUN_00086320 (4 B): matches/0x00086320.cpp
// sym: ?FUN_00086320@fn_f5b26912@@YIHPAX@Z
hulk_intptr __fastcall FUN_00086320(void* p) {
    return *(int*)((char*)p + 8);
}


// 0x00086330 FUN_00086330 (4 B): matches/0x00086330.cpp
// sym: @FUN_00086330@4
// Same code shape as 0x00059a40 (propagated; names are from that function)
extern "C" hulk_intptr __fastcall FUN_00086330(hulk_intptr object) {
    return *(int*)(object + 0x18);
}

} // namespace fn_f5b26912

// 0x00086340 FUN_00086340 (4 B): matches/0x00086340.cpp
// sym: ?FUN_00086340@A_86340@owners@@QAEIXZ
hulk_uintptr owners::A_86340::FUN_00086340() {
    return value;
}


// 0x00086350 FUN_00086350 (4 B): matches/0x00086350.cpp [wrapped: conflict: CJumpTrack]
// sym: ?vfunc_26@CJumpTrack@fn_00086350@@UAEIXZ
namespace fn_00086350 {
// Same code shape as 0x00069100 (propagated; names are from that function)
class CJumpTrack {
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
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual hulk_uintptr vfunc_26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    char pad[0x40 - 4];
    unsigned int m;
};
hulk_uintptr CJumpTrack::vfunc_26() {
    return m;
}
} // namespace fn_00086350


// 0x00086370 FUN_00086370 (4 B): matches/0x00086370.cpp
// sym: ?FUN_00086370@A_86370@owners@@QAEHXZ
hulk_intptr owners::A_86370::FUN_00086370() {
    return x;
}

namespace fn_f5b26912 {

// 0x00086380 FUN_00086380 (4 B): matches/0x00086380.cpp
// sym: ?target@fn_f5b26912@@YIIPAVA_86380@1@@Z
hulk_uintptr __fastcall target(A_86380* self) {
    return self->value;
}

} // namespace fn_f5b26912

// 0x000863e0 FUN_000863e0 (30 B): matches/0x000863e0.cpp
// sym: ?FUN_000863e0@Target_863e0@owners@@QAEXI@Z
void owners::Target_863e0::FUN_000863e0(unsigned int x) {
    b = a;
    a = x;
    g_863e0->p->p->f();
}

namespace fn_f5b26912 {

// 0x00086400 FUN_00086400 (29 B): matches/0x00086400.cpp
// sym: ?Run@Obj_86400@fn_f5b26912@@QAEXXZ
void Obj_86400::Run() {
    a = c;
    c = 0;
    ((Final_86400*)gGlobal_86400->p54->p18)->Run();
}

} // namespace fn_f5b26912

// 0x00086420 FUN_00086420 (47 B): matches/0x00086420.cpp
// sym: ?FUN_00086420@Target_86420@owners@@QAEXH@Z
void owners::Target_86420::FUN_00086420(int v) {
    value = v;
    if (v == 1)
        gManager_86420->hub->a->f();
    gManager_86420->hub->b->g();
}


// 0x000865b0 CGame::vfunc_0 (31 B): matches/0x000865b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_000865b0@@UAEPAV123@E@Z
namespace fn_000865b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003ffab4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000865b0

namespace fn_f5b26912 {

// 0x000865d0 FUN_000865d0 (93 B): matches/0x000865d0.cpp
// sym: ?target@fn_f5b26912@@YIXPAUObj_865d0@1@@Z
// data: flag_865d0 = DAT_004dd6f0
void __fastcall target(Obj_865d0* self) {
    A_865d0* edi = self->init();
    if (!(*(unsigned char*)&DAT_004dd6f0))
        edi->f2();
    else
        (*(unsigned char*)&DAT_004dd6f0) = 0;
    self->p38->f3(0);
    edi->f4();
    self->p30->f5();
    edi->f6(1);
    ((owners::Thing_1d3c50 *)edi)->FUN_001d3c50();
    self->p20->f8(self, self->v4);
}


// 0x00086630 FUN_00086630 (349 B): equivalent/0x00086630.cpp
// sym: ?FUN_00086630@Target_86630@fn_f5b26912@@QAEXXZ @f1e8c5c26a8e @wf881096794fb
// STATUS: equivalent (tools/equiv.py level 3: 19784 inputs, branch coverage 0/0)
// FUN_00086630 @ 0x00086630
void Target_86630::FUN_00086630() {
 audio->FUN_000ae9a0(0);
 panel->FUN_001b8780(0);
 panel->FUN_001b8900(0);
 stop->FUN_000afe80();
 DAT_004dd700->sub->audio->FUN_000ae980();
 view->FUN_001b7590();
 context->flag->enabled=1;
 renderer->FUN_00208820();
 controller->FUN_000bd1b0(0);
 int arg1_ = FUN_00267f00();
 FUN_000964d0()->FUN_0022aba0(arg1_);
 Manager_86630* manager=FUN_001d4c90();
 manager->FUN_001d2760();
 controller->FUN_000bc100();
 context->sub->FUN_001e11d0();
 scene->FUN_001ee020();
 controller->FUN_000bf0e0(this,state);
 manager->FUN_001d4530();
 controller->FUN_000bd1b0(0);
 scene->FUN_001ec310(1);
 manager->FUN_001d15d0(1);
 manager->FUN_001d3c50();
 manager->FUN_001d15d0(1);
 handler->FUN_0008dba0(this);
 context->item->FUN_001bc4e0();
 controller->FUN_000bd1b0(0);
 renderer->FUN_00206320(resource);
 loader->FUN_000d6b20(this);
 controller->FUN_000bd1b0(0);
 context->FUN_00088940(this,resource);
 resource->FUN_00089980();
 controller->FUN_000bd1b0(0);
 Controller_86630* lastController=controller;
 enabled=1;
 lastController->FUN_000bb600();
 state->value=3;
 DAT_004dd700->sub->stop->FUN_000afe80();
}

} // namespace fn_f5b26912

// 0x00086790 FUN_00086790 (359 B): equivalent/0x00086790.cpp [wrapped: conflict: World]
// sym: ?FUN_00086790@Object@fn_00086790@@QAEXXZ @5cd506111fd2 @w9d4a3fffc75c
namespace fn_00086790 {
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 21/26, incomplete)
// FUN_00086790 @ 0x00086790
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

struct Switch_86790 { void FUN_0008db60(int); };
struct Item_86790 { void FUN_000af0f0(void*); };
struct Source_86790 { void FUN_000ae840(); };
struct Input_86790 { void FUN_000af3c0(int); Item_86790* FUN_000af3a0(int); };
struct Pump_86790 { void FUN_000bd1b0(int); };
struct State_86790 { char pad[5]; unsigned char active; };
extern "C" void FUN_002684c0();
State_86790* FUN_0008e090();
bool FUN_0008db80();
struct Renderer_86790 { char pad[0xd8]; int state; void FUN_0028f9a0(); void FUN_0028faf0(int); };
struct Manager_86790 { void FUN_000afe80(); };
struct Subsystem_86790 { char pad[0x18]; Manager_86790* manager; };
struct World { char pad[0x54]; Subsystem_86790* subsystem; };
struct Animation { void FUN_001ec480(const char*,const char*); void FUN_001eb2a0(float,int); };
struct Object { char pad0[4]; int* result; char pad8[8]; Source_86790* source; Input_86790* input; char pad18[4]; Switch_86790* gate; Pump_86790* pump; char pad24[12]; Animation* animation; void FUN_00086790(); };
void Object::FUN_00086790() {
 gate->FUN_0008db60(1);
 if (!(*(unsigned char*)&DAT_004dd890) && source && input) {
  bool done=false;
  while (!done) {
   FUN_002684c0();
   source->FUN_000ae840();
   input->FUN_000af3c0(0);
   if (!FUN_0008e090()->active || FUN_0008db80()) { gate->FUN_0008db60(0); return; }
   int data[41];
   input->FUN_000af3a0(0)->FUN_000af0f0(data);
   if ((*(unsigned char*)&DAT_004dd841) || data[0]==1 || data[0]==2 || data[12]==1 || data[12]==2) done=true;
   pump->FUN_000bd1b0(1);
  }
 }
 for(int i=0;i<3;++i) {
  (*(Renderer_86790**)&DAT_0052c2b4)->state=-1;
  (*(Renderer_86790**)&DAT_0052c2b4)->FUN_0028f9a0();
  (*(Renderer_86790**)&DAT_0052c2b4)->FUN_0028faf0(1);
 }
 *result=4;
 DAT_004dd700->subsystem->manager->FUN_000afe80();
 (*(unsigned char*)&DAT_004e222c)=1;
 (*(unsigned char*)&DAT_004e222d)=1;
 animation->FUN_001ec480("start","poststart");
 animation->FUN_001eb2a0(0.01f,0);
 gate->FUN_0008db60(0);
}
} // namespace fn_00086790
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5b26912 {

// 0x00086900 FUN_00086900 (59 B): matches/0x00086900.cpp
// sym: ?FUN_00086900@fn_f5b26912@@YIXPAUObj_86900@1@@Z
void __fastcall FUN_00086900(Obj_86900* self) {
    self->worker->Reset(0);
    (*(u8*)&DAT_004dd6f0) = 0;
    State_86900* s = self->state;
    s->x48 = 0;
    s->x3c = 0;
    s->x10 = 0;
    s->x14 = 0;
    s->x18 = 0;
    s->x1c = 0;
    s->x38 = 0x10000;
    self->tail->Run();
}


// 0x00086940 FUN_00086940 (20 B): matches/0x00086940.cpp
// sym: ?Run@Thing_86940@fn_f5b26912@@QAEXXZ
void Thing_86940::Run() {
    a->Run();
    b->Finish();
}


// 0x00086960 FUN_00086960 (27 B): matches/0x00086960.cpp
// sym: ?Run@Thing_86960@fn_f5b26912@@QAEXXZ
// data: gFlag_86960 = DAT_004dd6f0
void Thing_86960::Run() {
    (*(unsigned char*)&DAT_004dd6f0) = 1;
    a->First();
    ((owners::Object_1b83c0 *)b)->FUN_001b83c0();
}


// 0x00086a10 FUN_00086a10 (48 B): matches/0x00086a10.cpp
// sym: ?run@Obj@fn_f5b26912@@QAEXXZ
void Obj::run() {
    State* s = state;
    if (s->value == 4) {
        s->value = 1;
        globalRoot->a->first->f();
        globalRoot->a->second->g();
    }
}


// 0x00086a40 FUN_00086a40 (131 B): matches/0x00086a40.cpp
// sym: ?Run@A_86a40@fn_f5b26912@@QAEXH@Z
void A_86a40::Run(int arg) {
    p10->F();
    p14->F(arg);
    if (Check())
        return;
    if (p4->id != 7) {
        p30->F(arg, 0);
        p48->F();
        p20->F(this, (int*)p4, arg, p30, p24);
        p2c->F(arg);
        p28->F();
        p24->F(p1c);
        return;
    }
    p18->F(arg);
}

} // namespace fn_f5b26912

// 0x00086ad0 FUN_00086ad0 (479 B): equivalent/0x00086ad0.cpp [wrapped: conflict: FUN_0008db80; FUN_0008e090; World]
// sym: ?FUN_00086ad0@Game_86ad0@fn_00086ad0@@QAEXXZ @5ca94bb2f9e5 @w80c3b5488e5e
namespace fn_00086ad0 {
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 36/38, incomplete)
// FUN_00086ad0 @ 0x00086ad0
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

struct Flags_86ad0 {
    char pad0[4];
    char started;       // +4
    char quit;          // +5
    char pad1;
    char busy;          // +7
    char pad2;
    char paused;        // +9
};

struct PadState_86ad0 {
    char pad0[0x10];
    float value;
    char pad1[0x44 - 0x14];
};

struct Pad_86ad0 {
    void FUN_000ada70(PadState_86ad0 *out);
};

struct PadList_86ad0 {
    Pad_86ad0 *FUN_000ae640(int index);
    void FUN_000ae840();
};

struct Audio_86ad0 {
    void FUN_001eb870();
    void FUN_001eb890();
    void FUN_001eb2a0(float a, int b);
};

struct Fader_86ad0 {
    void FUN_001b8110(int ms);
};

struct Context {
    char pad[0x30];
    Audio_86ad0 *audio;
    Fader_86ad0 *fader;
};

struct World {
    char pad[0x54];
    Context *ctx;
};

struct Game_86ad0 {
    void FUN_00086ad0();
    char pad0[0x10];
    PadList_86ad0 *pads;
    char pad1[0x24 - 0x14];
    struct Renderer_86ad0 *renderer;
};

struct Renderer_86ad0 {
    void FUN_001bc040();
};


Flags_86ad0 *FUN_0008e090();
extern "C" void FUN_002684c0();
char FUN_0008db80();

void Game_86ad0::FUN_00086ad0()
{
    if (DAT_0049c0dc > 0) {
        DAT_0049c0dc--;
        if (DAT_0049c0dc == 0)
            FUN_0008e090()->started = 1;
    }

    if (!FUN_0008e090()->started)
        return;

    if (!FUN_0008e090()->paused && !FUN_0008e090()->quit) {
        DAT_004dd700->ctx->audio->FUN_001eb870();
        FUN_0008e090()->paused = 1;
        for (int n = 10; n != 0; n--)
            DAT_004dd700->ctx->audio->FUN_001eb2a0(0.01f, 0);
    }

    if (FUN_0008e090()->quit)
        return;

    do {
        renderer->FUN_001bc040();
        FUN_0008e090()->busy = 1;
        FUN_002684c0();
        (*(int*)&DAT_004dda40)++;
    } while (!FUN_0008e090()->quit);

    bool rising = false;
    bool settled = false;
    PadState_86ad0 state;
    while (!(rising && settled) && FUN_0008e090()->quit) {
        int i = 0;
        do {
            pads->FUN_000ae640(i)->FUN_000ada70(&state);
            float v = state.value;
            if (rising) {
                if (v < 0.2f) {
                    settled = true;
                    break;
                }
            } else if (v > 0.2f) {
                rising = true;
                break;
            }
            i++;
        } while (i < 1);
        pads->FUN_000ae840();
    }

    if (FUN_0008e090()->busy && FUN_0008e090()->quit) {
        FUN_0008e090()->busy = 0;
        if (!FUN_0008db80()) {
            DAT_004dd700->ctx->audio->FUN_001eb890();
            FUN_0008e090()->paused = 0;
            for (int n = 10; n != 0; n--)
                DAT_004dd700->ctx->audio->FUN_001eb2a0(0.01f, 0);
            DAT_004dd700->ctx->fader->FUN_001b8110(500);
        }
    }
    DAT_004e222c = 1;
    (*(char*)&DAT_004ddbe1) = 1;
    (*(char*)&DAT_004e222d) = 1;
}
} // namespace fn_00086ad0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00086cb0 FUN_00086cb0 (227 B): matches/0x00086cb0.cpp [wrapped: conflict: World]
// sym: ?FUN_00086cb0@Target_86cb0@fn_00086cb0@@QAEXXZ
namespace fn_00086cb0 {
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

struct Reset_86cb0 {
    void FUN_00024800();
};
struct World {
    char pad[0x20];
    Reset_86cb0* reset;
};
struct UI_86cb0 {
    void FUN_0023f720(int*, int);
    bool FUN_0023f760(const char*, int, int);
    void FUN_0023f740();
};
struct Check_86cb0 {
    bool FUN_0008db70();
};
struct Mode_86cb0 {
    int kind;
};
struct Special_86cb0 {
    void FUN_001b7d10(int, int);
};
struct Draw {
    void FUN_001b93a0(Mode_86cb0*, int, int, int, int, int);
};
struct Memory_86cb0 {
    void FUN_0008d0a0(int);
};
extern Memory_86cb0* __stdcall FUN_0008ceb0();
extern "C" void __cdecl FUN_000969c0(int);
extern "C" void __cdecl FUN_00096740();
struct Target_86cb0 {
    int field0;
    Mode_86cb0* mode;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    Check_86cb0* check;
    int field20;
    Draw* draw;
    int field28;
    int field2c;
    int field30;
    Special_86cb0* special;
    int field38;
    void FUN_00086cb0();
};
void Target_86cb0::FUN_00086cb0() {
    if (DAT_004dd700)
        DAT_004dd700->reset->FUN_00024800();
    if (!DAT_0049c0d8)
        return;
    if (!check->FUN_0008db70())
        return;
    if (mode->kind == 4)
        FUN_000969c0(0);
    if (DAT_0049caa0 && mode->kind == 7) {
        special->FUN_001b7d10(field14, field18);
    } else {
        (*(UI_86cb0**)&DAT_004dd6e8)->FUN_0023f720(&DAT_0049c108, 0);
        if ((*(unsigned char*)&DAT_004dd83e) || (*(UI_86cb0**)&DAT_004dd6e8)->FUN_0023f760("Display Memory Usage", 0x4d, 0)) {
            FUN_0008ceb0()->FUN_0008d0a0(0);
        }
        (*(UI_86cb0**)&DAT_004dd6e8)->FUN_0023f740();
        draw->FUN_001b93a0(mode, fieldc, field20, field2c, field38, field28);
    }
    if ((*(unsigned char*)&DAT_004dd8e4))
        FUN_00096740();
}
} // namespace fn_00086cb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5b26912 {

// 0x00086da0 FUN_00086da0 (94 B): matches/0x00086da0.cpp
// sym: ?run@A_86da0@fn_f5b26912@@QAEXXZ
void A_86da0::run() {
    if (x)
        x->a();
    else {
        thunk();
        f656a0();
    }
    if (y)
        ((owners::Thing_1eb2a0 *)y)->FUN_001eb2a0(0, 0);
    if (x) {
        while (b80()) {
            FUN_0008db90();
            x->a();
        }
    }
    tail();
}

} // namespace fn_f5b26912

// 0x00086e40 Function0<float>::vfunc_2 (30 B): matches/0x00086e40.cpp [wrapped: conflict: Function; Function0]
// sym: ?f2@Function0@fn_00086e40@@UAEXPAX0PAM@Z
namespace fn_00086e40 {
class Function {
  public:
    virtual void a();
    virtual void b();
};
typedef float(__cdecl* Fn_86e40)();
class Function0 : public Function {
  public:
    virtual void a();
    virtual void b();
    virtual void f2(void*, void*, float*);
    char pad[0x18];
    Fn_86e40 mFn;
};
void Function0::f2(void*, void*, float* out) {
    Fn_86e40 fn = mFn;
    float v = fn();
    if (out)
        *out = v;
}
} // namespace fn_00086e40


// 0x00086e60 FUN_00086e60 (76 B): matches/0x00086e60.cpp [wrapped: conflict: Function2]
// sym: ??0Function2@fn_00086e60@@QAE@PBDP6AMMM@Z@Z
namespace fn_00086e60 {
// data: gName = DAT_0048e128
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_001d04d0(const char*);
// Function2's constructor (name, function): Function's fields (include/decls/data/script.h), then the bound
// function pointer.
typedef float (*Fn_86e60)(float, float);
class Function_86e60 : public ScriptFunctionFields {
  public:
    Function_86e60(const char*, int);
    virtual void f();
};
class Function2 : public Function_86e60 {
  public:
    Function2(const char*, Fn_86e60);
    virtual void f();
    Fn_86e60 value;
};
Function2::Function2(const char* a, Fn_86e60 b) : Function_86e60(a, 2) {
    value = b;
    retType = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
}
} // namespace fn_00086e60


// 0x00086eb0 Function2<float,float,float>::vfunc_2 (62 B): equivalent/0x00086eb0.cpp
// sym: ?vfunc_2@?$Function2@MMM@@UAEXPAX00@Z @d52456eb04f4 @w3840516b40e0
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Function2<float,float,float>::vfunc_2 @ 0x00086eb0
template <> void Function2<float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; const float * args = (const float *)__p1; float * result = (float *)__p2;
 float value = (*(float (**)(float, float))&this->f_1c)(args[0], args[1]); if (result) *result = value; }


// 0x00086f30 Function1<const_char_*,const_char_*>::vfunc_2 (28 B): matches/0x00086f30.cpp [wrapped: conflict: Function; Function1]
// sym: ?f2@Function1@fn_00086f30@@UAEXPAXPAPBD1@Z
namespace fn_00086f30 {
typedef const char*(__cdecl* Fn_86f30)(const char*);
struct Function {
    virtual void f0();
    virtual void f1();
};
struct Function1 : Function {
    char pad[0x1c - sizeof(Function)];
    Fn_86f30 mFn;
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, const char**, const char**);
};
void Function1::f2(void*, const char** arg, const char** out) {
    const char* a = *arg;
    Fn_86f30 fn = mFn;
    const char* result = fn(a);
    if (out)
        *out = result;
}
} // namespace fn_00086f30


// 0x00086f50 FUN_00086f50 (76 B): matches/0x00086f50.cpp [wrapped: conflict: Function2]
// sym: ??0Function2@fn_00086f50@@QAE@PBDP6APBD00@Z@Z
namespace fn_00086f50 {
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

// Function2's constructor (name, function): Function's fields (include/decls/data/script.h), then the bound
// function pointer.
typedef const char* (*Fn_86f50)(const char*, const char*);
class Function_86f50 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_86f50(const char*, int);
};
class Function2 : public Function_86f50 {
  public:
    virtual void f();
    Fn_86f50 d;
    Function2(const char*, Fn_86f50);
};
Function2::Function2(const char* s, Fn_86f50 v) : Function_86f50(s, 2) {
    d = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
} // namespace fn_00086f50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00086fa0 Function2<const_char_*,const_char_*,const_char_*>::vfunc_2 (32 B): matches/0x00086fa0.cpp
// sym: ?vfunc_2@?$Function2@PBDPBDPBD@@UAEXPAX00@Z
template <> void Function2<const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * ignored = (void *)__p0; void ** args = (void **)__p1; void ** out = (void **)__p2;

    void* a = args[0];
    void* b = args[1];
    void* fn = (*(void * *)&this->f_1c);
    void* value = ((void*(__cdecl*)(void*, void*))fn)(a, b);
    if (out)
        *out = value;
}

namespace fn_f5b26912 {

// 0x00086fc0 FUN_00086fc0 (102 B): matches/0x00086fc0.cpp
// sym: ??0Function4_86fc0@fn_f5b26912@@QAE@PBDP6A_NXZ@Z
Function4_86fc0::Function4_86fc0(const char* a, Fn_86fc0 b) : FUN_001d0480(a, 4) {
    vt = (void*)DAT_003ffb80;
    member1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}

} // namespace fn_f5b26912

// 0x00087030 Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::vfunc_2 (168 B): equivalent/0x00087030.cpp [wrapped: conflict: Function; Function4]
// sym: ?vfunc_2@?$Function4@_NUVector@math@fn_00087030@@U123@U123@U123@@fn_00087030@@UAEXIPBUVector@math@2@PA_N@Z @f1a990f3fa15 @w00eee243ceb7
namespace fn_00087030 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::vfunc_2 @ 0x00087030
namespace math { struct Vector { float x,y,z; }; }
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
template<class R,class A,class B,class C,class D> struct Function4 : Function {
 virtual void vfunc_2(unsigned unused, const math::Vector* args, bool* result);
 char padding[24];
 R (__cdecl *callback)(A,B,C,D);
};
template<> void Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::vfunc_2(unsigned unused, const math::Vector* args, bool* result) {
 unsigned char value = ((unsigned char (__cdecl*)(math::Vector,math::Vector,math::Vector,math::Vector))callback)(args[0],args[1],args[2],args[3]);
 if(result) *(unsigned char*)result = value;
}
} // namespace fn_00087030


// 0x000870e0 Function0<float>::vfunc_0 (30 B): matches/0x000870e0.cpp
// sym: ??_G?$Function0@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function0<float>::~Function0() {}


// 0x00087100 Function2<float,float,float>::vfunc_0 (30 B): matches/0x00087100.cpp
// sym: ??_G?$Function2@MMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function2<float, float, float>::~Function2() {}


// 0x00087120 Function1<const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00087120.cpp
// sym: ??_G?$Function1@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function1<const char *, const char *>::~Function1() {}


// 0x00087140 Function2<const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00087140.cpp
// sym: ??_G?$Function2@PBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function2<const char *, const char *, const char *>::~Function2() {}


// 0x00087160 Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x00087160.cpp
// sym: ??_G?$Function4@_NVVector@math@@V12@V12@V12@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function4<bool,math::Vector,math::Vector,math::Vector,math::Vector>::~Function4() {}


// 0x000871c0 Method0<CTimeManager,float>::vfunc_0 (30 B): matches/0x000871c0.cpp
// sym: ??_G?$Method0@VCTimeManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CTimeManager, float>::~Method0() {}


// 0x000871e0 Method0<CTimeManager,float>::vfunc_2 (34 B): matches/0x000871e0.cpp [wrapped: conflict: Function]
// sym: ?f2@Method0Base_871e0@fn_000871e0@@UAEXPAX0PAM@Z
namespace fn_000871e0 {
// Same code shape as 0x0002e080 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_871e0 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_871e0::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
} // namespace fn_000871e0


// 0x00087250 Method0<CGame,void>::vfunc_0 (30 B): matches/0x00087250.cpp
// sym: ??_G?$Method0@VCGame@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CGame, void>::~Method0() {}


// 0x00087270 Method0<CGame,void>::vfunc_2 (12 B): matches/0x00087270.cpp
// sym: ?vfunc_2@?$Method0@VCGame@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CGame, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_87270 * a = (CActorManager_87270 *)__p0;

    (a->*(*(void (CActorManager_87270::**)())&this->f_1c))();
}


// 0x000872a0 FUN_000872a0 (230 B): equivalent/0x000872a0.cpp [wrapped: conflict: World]
// sym: ?FUN_000872a0@Tracker_872a0@fn_000872a0@@QAEXXZ @60f68d47b784 @w11d3dd579ac2
namespace fn_000872a0 {
// STATUS: equivalent (tools/equiv.py level 3: 19806 inputs, branch coverage 2/2)
// FUN_000872a0 @ 0x000872a0
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

struct Vec3_872a0 {
    float x, y, z;
};

struct Pos_872a0 {
    void FUN_00059a50(Vec3_872a0 *out);
};

struct Body_872a0 {
    char pad0[0x10];
    Pos_872a0 *pos;
    void FUN_000ae990();
    void FUN_000afe80();
    hulk_freg FUN_000354c0();
};

struct Link_872a0 {
    char pad0[8];
    char flag;
};


struct Entity {
    char pad0[0x124];
    Body_872a0 *body;
};

struct Holder_872a0 {
    char pad0[4];
    Link_872a0 *link;
    char pad1[0x20 - 8];
    Entity *entity;
};

struct Display_872a0 {
    char pad0[0x10];
    Body_872a0 *a;
    char pad1[4];
    Body_872a0 *b;
};

struct World {
    char pad1[0x54];
    Display_872a0 *display;
};

struct Camera {
    void FUN_00089900(float angle);
    void FUN_000898a0(Vec3_872a0 v);
};

struct Sub0_872a0 {
    void FUN_001b7590();
};

struct Sub1_872a0 {
    void FUN_000bd1b0(int arg);
};

struct Status_872a0 {
    int state;
};

class Tracker_872a0 {
public:
    void FUN_000872a0();
    void FUN_00086980(int flag);

    char pad0[4];
    Status_872a0 *status;
    char pad1[4];
    Holder_872a0 *holder;
    char pad2[0x20 - 0x10];
    Sub1_872a0 *sub1;
    char pad3[0x34 - 0x24];
    Sub0_872a0 *sub0;
    Camera *camera;
};


void Tracker_872a0::FUN_000872a0()
{
    sub0->FUN_001b7590();
    holder->link->flag = 1;
    Vec3_872a0 pos;
    holder->entity->body->pos->FUN_00059a50(&pos);
    camera->FUN_000898a0(pos);
    float angle = holder->entity->body->FUN_000354c0() * 57.295776f;
    camera->FUN_00089900(angle);
    sub1->FUN_000bd1b0(0);
    FUN_00086980(((char)((owners::Target_89a40 *)camera)->FUN_00089a40()));
    if (((char)((owners::Target_89a40 *)camera)->FUN_00089a40())) {
        status->state = 1;
        DAT_004dd700->display->a->FUN_000ae990();
        DAT_004dd700->display->b->FUN_000afe80();
    } else {
        status->state = 2;
        DAT_004dd700->display->b->FUN_000afe80();
    }
}
} // namespace fn_000872a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00087940 FUN_00087940 (73 B): matches/0x00087940.cpp
// sym: ?FUN_00087940@Thing_87940@owners@@QAEXXZ
void owners::Thing_87940::FUN_00087940() {
    if (!Check())
        Set(1);
    while (*state != 8) {
        StepA();
        if (*state != 8)
            StepB();
    }
    Set(1);
}


// 0x00087990 FUN_00087990 (41 B): equivalent/0x00087990.cpp [wrapped: conflict: thunk]
// sym: ?target@fn_00087990@@YAXXZ @a7bec8500dc8 @w17976cdf05f9
namespace fn_00087990 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_00087990 @ 0x00087990
extern "C" {
struct Run_87990 { void fn86(); };
struct Obj_87990 {
    char pad0[0x54];
    hulk_intptr field54;
    char pad58[0x9d - 0x58];
    char flag9d;
};
extern "C++" { extern Obj_87990* gObj_87990; }
extern "C++" { __declspec(nothrow) void __cdecl thunk(); }
extern "C++" { __declspec(nothrow) void __cdecl fnTail(); }
}
void target() {
    Obj_87990* p = gObj_87990;
    if (p && p->flag9d && p->field54) {
        ((Run_87990*)p->field54)->fn86();
        return;
    }
    thunk();
    fnTail();
}
} // namespace fn_00087990

namespace fn_f5b26912 {

// 0x00087a90 FUN_00087a90 (96 B): equivalent/0x00087a90.cpp
// sym: ?FUN_00087a90@Registry_87a90@fn_f5b26912@@QAEXPBDP6AMXZ@Z @8a4391c56988 @w78a1e31c5a19
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087a90 @ 0x00087a90
void Registry_87a90::FUN_00087a90(const char* name, float (*fn)()) {
    HULK_SIZE32(Function0_87a90<float>, 0x20);
    void* mem = FUN_0008d690((int)sizeof(Function0_87a90<float>));
    Function0_87a90<float>* c = 0;
    if (mem)
        c = new (mem) Function0_87a90<float>(name, fn);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)name, (hulk_intptr)c);
}

} // namespace fn_f5b26912

// 0x00087b40 FUN_00087b40 (109 B): equivalent/0x00087b40.cpp [wrapped: conflict: Function1]
// sym: ?FUN_00087b40@Registry_87b40@fn_00087b40@@QAEXPBDP6APBD0@Z@Z @55b8be934468 @w6de191a5b759
namespace fn_00087b40 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087b40 @ 0x00087b40
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class __declspec(novtable) MethodBase_87b40 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_87b40(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class A, class R>
class Function1 : public MethodBase_87b40 {
  public:
    typedef R (*Fn)(A);
    Function1(const char* name, Fn f) : MethodBase_87b40(name, 1) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    Fn fn;
};

struct Registry_87b40 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087b40(const char* name, const char* (*fn)(const char*));
};

void Registry_87b40::FUN_00087b40(const char* name, const char* (*fn)(const char*)) {
    typedef Function1<const char*, const char*> Alloc_87b40;
    HULK_SIZE32(Alloc_87b40, 0x20);
    void* mem = FUN_0008d690((int)sizeof(Function1<const char*, const char*>));
    Function1<const char*, const char*>* c = 0;
    if (mem)
        c = new (mem) Function1<const char*, const char*>(name, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00087b40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00087c90 Closure0<CTimeManager,float>::vfunc_0 (30 B): matches/0x00087c90.cpp
// sym: ??_G?$Function2@PBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CTimeManager, float>::~Closure0() {}


// 0x00087cb0 Closure0<CTimeManager,float>::vfunc_2 (35 B): matches/0x00087cb0.cpp
// sym: ?vfunc_2@?$Closure0@VCTimeManager@@M@@UAEXPAX00@Z
// Same code shape as 0x0002fe60 (propagated; names are from that function)
template <> void Closure0<CTimeManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_87cb0* m = (*(CActorManager_87cb0 * *)&this->f_20);
    Fn_87cb0 fn = (*(Fn_87cb0 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}


// 0x00087d20 Closure0<CGame,void>::vfunc_0 (30 B): matches/0x00087d20.cpp
// sym: ??_G?$Method0@VCGame@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CGame, void>::~Closure0() {}


// 0x00087d40 Closure0<CGame,void>::vfunc_2 (11 B): matches/0x00087d40.cpp
// sym: ?vfunc_2@?$Closure0@VCGame@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CGame, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_87d40 * *)&this->f_20)->*(*(void (CActorManager_87d40::**)())&this->f_1c))();
}


// 0x00087d50 FUN_00087d50 (109 B): equivalent/0x00087d50.cpp [wrapped: conflict: Closure0; Method0]
// sym: ?FUN_00087d50@Registry_87d50@fn_00087d50@@QAEXPBDPAVCTimeManager@2@P832@AEMXZ@Z @630c0cd1bed9 @waef388d77456
namespace fn_00087d50 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087d50 @ 0x00087d50
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CTimeManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_87d50 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_87d50(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R>
class Method0 : public MethodBase_87d50 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_87d50(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e128));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_87d50 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087d50(const char* name, CTimeManager* owner, float (CTimeManager::*fn)());
};

void Registry_87d50::FUN_00087d50(const char* name, CTimeManager* owner, float (CTimeManager::*fn)()) {
    typedef Closure0<CTimeManager, float> Alloc_87d50;
    HULK_SIZE32(Alloc_87d50, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CTimeManager, float>));
    Closure0<CTimeManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CTimeManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00087d50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00087dc0 FUN_00087dc0 (109 B): equivalent/0x00087dc0.cpp [wrapped: conflict: CGame; Closure0; Method0]
// sym: ?FUN_00087dc0@Registry_87dc0@fn_00087dc0@@QAEXPBDPAVCGame@2@P832@AEXXZ@Z @da593595568c @w00791763eebb
namespace fn_00087dc0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087dc0 @ 0x00087dc0
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CGame { public: void FUN_dummy(); };

class __declspec(novtable) MethodBase_87dc0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char*, int);
    MethodBase_87dc0(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R>
class Method0 : public MethodBase_87dc0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_87dc0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_87dc0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087dc0(const char* name, CGame* owner, void (CGame::*fn)());
};

void Registry_87dc0::FUN_00087dc0(const char* name, CGame* owner, void (CGame::*fn)()) {
    typedef Closure0<CGame, void> Alloc_87dc0;
    HULK_SIZE32(Alloc_87dc0, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CGame, void>));
    Closure0<CGame, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CGame, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00087dc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00087e30 FUN_00087e30 (80 B): matches/0x00087e30.cpp [wrapped: conflict: FUN_001d4c90]
// sym: ?FUN_00087e30@fn_00087e30@@YIPAUObj_87e30@1@PAU21@@Z
namespace fn_00087e30 {
typedef unsigned int u32_87e30;
extern "C" unsigned __int64 FUN_00267f40();
// CTimeManager (0x00087e30 constructs it): its fields, and the member 0x000860c0 (time_GetElapsedTime) it binds to
// Lua through ScriptHandler's Closure0<CTimeManager, float> helper 0x00087d50 (a real member-function pointer: one
// code pointer on every build, docs/native-build.md sh2).
struct Obj_87e30 {
    u32_87e30 v;
    u32_87e30 x;
    u32_87e30 a, b, c, d, e, f;
    u32_87e30 pad[6];
    u32_87e30 limit;
    u32_87e30 other;
    u32_87e30 tail[4];          // (x64t9-mgr) to the XBE's 80 bytes (include/decls/managers.h's HulkTimeManager)
    float FUN_000860c0();
};
HULK_MGR_SAME(Obj_87e30, HulkTimeManager);
struct Handler_87e30 {
    void FUN_00087d50(const char*, Obj_87e30*, float (Obj_87e30::*)());
};
extern "C++" __declspec(nothrow) Handler_87e30* __cdecl FUN_001d4c90();
Obj_87e30* __fastcall FUN_00087e30(Obj_87e30* p) {
    p->limit = 0x10000;
    p->other = 0;
    unsigned __int64 q = FUN_00267f40();
    p->a = (u32_87e30)q;
    p->b = (u32_87e30)(q >> 32);
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 0;
    p->v = 0x1046a;
    p->x = 0;
    Handler_87e30* h = FUN_001d4c90();
    if (h)
        h->FUN_00087d50("time_GetElapsedTime", p, &Obj_87e30::FUN_000860c0);
    return p;
}
} // namespace fn_00087e30


// 0x00087e80 FUN_00087e80 (407 B): equivalent/0x00087e80.cpp [wrapped: conflict: CGame; FUN_001d4c90; Function2]
// sym: ??0CGame@fn_00087e80@@QAE@XZ @5694862b6c13 @w084c4e49510e
namespace fn_00087e80 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00087e80 @ 0x00087e80
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

namespace math { class Vector_87e80 { public: float x, y, z; }; }
// CGame and the two members it binds to Lua (Quit, fe_restart: Closure0<CGame, void> through the helper 0x00087dc0);
// complete before any pointer to a member is formed (one code pointer on every build).
extern "C" char DAT_003ffab4[];  // CGame's vftable
extern "C" char DAT_003ffb50[];  // Function2<float, float, float>'s
extern "C" char DAT_003ffb70[];  // Function2<const char*, const char*, const char*>'s
struct CGame { void* vftable; int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s; unsigned char flag; CGame(); void FUN_00086a10(); void FUN_000861f0(); };
// The free functions bound as Function<N> (0x00086fa0's Invoke calls them __cdecl): their real types are the game's
// Function<N> instantiations.
float __cdecl FUN_000964e0();
float __cdecl FUN_00096540(float, float);
extern "C" const char* __cdecl FUN_00096ed0(const char*, const char*);
const char* __cdecl FUN_00096f10(const char*);
bool __cdecl FUN_00096f40(math::Vector_87e80, math::Vector_87e80, math::Vector_87e80, math::Vector_87e80);

struct Registry_87e80 { void FUN_00087dc0(const char*, CGame*, void (CGame::*)()); void FUN_00087a90(const char*, float (__cdecl*)()); void FUN_00087b40(const char*, const char* (__cdecl*)(const char*)); void FUN_001d3b70(const char*,void*); };
extern "C++" __declspec(nothrow) Registry_87e80* __cdecl FUN_001d4c90(); extern "C" void* __cdecl FUN_0008d690(unsigned);
// Function's fields (include/decls/data/script.h) after the vftable; Function<N> keeps the bound free function after
// them. The vftables are the game's (stored by address: a local class's own vftable would be the 64-bit link's stub).
struct FunctionBase_87e80 { void* vftable; ScriptFunctionFields f; void FUN_001d0480(const char*,int); };
struct Function4_87e80 : FunctionBase_87e80 { bool (__cdecl* callback)(math::Vector_87e80, math::Vector_87e80, math::Vector_87e80, math::Vector_87e80); void* FUN_00086fc0(const char*, bool (__cdecl*)(math::Vector_87e80, math::Vector_87e80, math::Vector_87e80, math::Vector_87e80)); };
template<class R,class A,class B> struct Function2 : FunctionBase_87e80 { R (__cdecl* callback)(A, B); };
CGame::CGame() { vftable=(void*)DAT_003ffab4; a=b=0; d=e=f=g=h=i=j=k=l=m=n=o=p=q=r=s=0; flag=0; Registry_87e80* reg=FUN_001d4c90(); typedef Function2<float,float,float> Alloc1_87e80; HULK_SIZE32(Alloc1_87e80,0x20); typedef Function2<const char*,const char*,const char*> Alloc2_87e80; HULK_SIZE32(Alloc2_87e80,0x20); HULK_SIZE32(Function4_87e80,0x20); reg->FUN_00087dc0("Quit",this,&CGame::FUN_00086a10); reg->FUN_00087a90("util_GetRandomFloat",FUN_000964e0); Function2<float,float,float>* one=(Function2<float,float,float>*)FUN_0008d690((int)sizeof(Function2<float,float,float>)); if(one) { one->FUN_001d0480("util_GetWorldOrientation",2); one->vftable=(void*)DAT_003ffb50; one->callback=FUN_00096540; one->f.retType=FUN_001d04d0(((int*)&DAT_0048e128)); one->f.argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e128)); one->f.argTypes[1]=FUN_001d04d0(((int*)&DAT_0048e128)); } reg->FUN_001d3b70("util_GetWorldOrientation",one); reg->FUN_00087b40("util_MakeUID",FUN_00096f10); Function2<const char*,const char*,const char*>* two=(Function2<const char*,const char*,const char*>*)FUN_0008d690((int)sizeof(Function2<const char*,const char*,const char*>)); if(two) { two->FUN_001d0480("util_AppendToUID",2); two->vftable=(void*)DAT_003ffb70; two->callback=FUN_00096ed0; two->f.retType=FUN_001d04d0(((int*)&DAT_0048e0f0)); two->f.argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e0f0)); two->f.argTypes[1]=FUN_001d04d0(((int*)&DAT_0048e0f0)); } reg->FUN_001d3b70("util_AppendToUID",two); Function4_87e80* three=(Function4_87e80*)FUN_0008d690((int)sizeof(Function4_87e80)); void* result=0; if(three) result=three->FUN_00086fc0("hack_IsFieldGoal",FUN_00096f40); reg->FUN_001d3b70("hack_IsFieldGoal",result); reg->FUN_00087dc0("fe_restart",this,&CGame::FUN_000861f0); }
} // namespace fn_00087e80
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00088530 FUN_00088530 (29 B): matches/0x00088530.cpp
// sym: ?FUN_00088530@Obj_88530@owners@@QAEXXZ
void owners::Obj_88530::FUN_00088530() {
    g_88530 = this;
    FUN_00088020();
    FUN_000879c0();
    FUN_00087940();
}


// 0x00088600 FUN_00088600 (85 B): equivalent/0x00088600.cpp [wrapped: conflict: World]
// sym: ??0World@fn_00088600@@QAE@XZ @11fc19f1e939 @w3577c59934e1
namespace fn_00088600 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00088600 @ 0x00088600
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

// (x64t9-mgr) include/decls/managers.h's HulkWorld: the 21 managers 0x00088670 stores, its object at 0x58, the name
// (0x00088e10), a flag and the ready flag
class World {
public:
    virtual void vfn0();
    World();
    void* f[21];
    void* f58;
    char name[0x40];
    char f9c;
    char flag;
};
HULK_MGR_SAME(World, HulkWorld);

World::World()
{
    for (int i = 0; i < 21; i++)
        f[i] = 0;
    DAT_004dd700 = this;
    flag = 0;
}
} // namespace fn_00088600
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5b26912 {

// 0x00088670 FUN_00088670 (713 B): equivalent/0x00088670.cpp
// sym: ?FUN_00088670@Sim_88670@fn_f5b26912@@QAEXPAUCtx_88670@2@H@Z @c6201aef935b @w59e4b2687fbb
// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 34/34)
// FUN_00088670 @ 0x00088670
void Sim_88670::FUN_00088670(Ctx_88670 *arg0, hulk_intptr arg1)
{
    ctx = arg0;
    p58 = arg0->FUN_00086320();
    cfg50 = arg0->FUN_00086380();

    CSimControllerManager *ta = (CSimControllerManager *)FUN_0008d690(0xc);
    if (ta)
        ta = ((CSimControllerManager_nv_88670*)(ta))->FUN_000b3c90(arg1);
    a = ta;
    ((CSimControllerManager_nv_88670*)(ta))->FUN_000b3d00();

    CCameraManager *tb = (CCameraManager *)FUN_0008d690(0xc8);
    if (tb)
        tb = ((CCameraManager_nv_88670*)(tb))->FUN_0009dd20();
    b = tb;
    ((owners::A_98e20 *)(((CCameraManager_nv_88670*)(tb))))->FUN_00098e20((hulk_intptr)(Ctx_88670 *)arg0);

    s10 = FUN_001b6580();
    s10->FUN_001b3fc0();

    CSPManager *tc = (CSPManager *)FUN_0008d690(0x1eee8);
    if (tc)
        tc = ((CSPManager_nv_88670*)(tc))->FUN_001e7470();
    c = tc;
    ((CSPManager_nv_88670*)(tc))->FUN_001de360(this);

    s14 = FUN_001b6990();

    CPatrolPathManager *td = (CPatrolPathManager *)FUN_0008d690(0x10);
    if (td)
        td = ((CPatrolPathManager_nv_88670*)(td))->FUN_00106e90(0x100);
    d = td;
    ((CPatrolPathManager_nv_88670*)(td))->FUN_001063e0();

    CPathManager *te = (CPathManager *)FUN_0008d690(0x2c);
    if (te)
        te = ((CPathManager_nv_88670*)(te))->FUN_001aec00();
    e = te;
    ((CPathManager_nv_88670*)(te))->FUN_001acd80();

    F_88670 *tf = (F_88670 *)FUN_0008d690(0xd40);
    if (tf)
        tf = tf->FUN_00025a90();
    f = tf;
    ((owners::X_243f0 *)tf)->FUN_000243f0((hulk_intptr)(Sim_88670 *)this);

    CWorldCollisionManager *tg = (CWorldCollisionManager *)FUN_0008d690(0x68);
    if (tg)
        tg = ((CWorldCollisionManager_nv_88670*)(tg))->FUN_002023e0();
    g = tg;
    ((CWorldCollisionManager_nv_88670*)(tg))->FUN_00203490();

    CTriggerVolumeManager *th = (CTriggerVolumeManager *)FUN_0008d690(0x43c);
    if (th)
        th = ((CTriggerVolumeManager_nv_88670*)(th))->FUN_001ff580();
    h = th;
    ((CTriggerVolumeManager_nv_88670*)(th))->FUN_00200c10(this);

    CScenarioManager *ti = (CScenarioManager *)FUN_0008d690(0x14ac);
    if (ti)
        ti = ((CScenarioManager_nv_88670*)(ti))->FUN_001cd150();
    i = ti;
    ((CScenarioManager_nv_88670*)(ti))->FUN_001cfb20(this);

    CEventManager *tj = (CEventManager *)FUN_0008d690(0x404);
    if (tj)
        tj = ((CEventManager_nv_88670*)(tj))->FUN_001cc360();
    j = tj;
    ((owners::C_1cb3f0 *)(((CEventManager_nv_88670*)(tj))))->FUN_001cb3f0((hulk_intptr)(Sim_88670 *)this);

    K_88670 *tk = (K_88670 *)FUN_0008d690(8);
    if (tk)
        tk = ((K_88670 *)((owners::C_1ebba0 *)tk)->FUN_001ebba0((hulk_intptr)(Sim_88670 *)this, (hulk_intptr)(Ctx_88670 *)arg0));
    k = tk;
    tk->FUN_001eebc0();

    L_88670 *tl = (L_88670 *)FUN_0008d690(0x60);
    if (tl)
        tl = tl->FUN_001f6c30();
    l = tl;
    tl->FUN_001f81c0();

    CSimOverlayManager *tm = (CSimOverlayManager *)FUN_0008d690(0x10);
    if (tm)
        tm = ((CSimOverlayManager_nv_88670*)(tm))->FUN_000d75c0();
    m = tm;
    int arg_v2c = ctx->FUN_00086380()->v2c; // MSVC evaluates the argument before loading the receiver m
    ((owners::A_d6f00 *)(((CSimOverlayManager_nv_88670*)(m))))->FUN_000d6f00(arg_v2c);

    CExtraRenderingCallback *tn = (CExtraRenderingCallback *)FUN_0008d690(0x2c);
    if (tn)
        tn = ((CExtraRenderingCallback_nv_88670*)(tn))->FUN_001bceb0();
    n = tn;

    O_88670 *to = (O_88670 *)FUN_0008d690(0x10);
    if (to)
        to = to->FUN_00059ad0();
    o = to;

    CGameDataHandler *tp = (CGameDataHandler *)FUN_0008d690(0x34);
    if (tp)
        tp = ((CGameDataHandler_nv_88670*)(tp))->FUN_001fae80();
    p = tp;
    ((CGameDataHandler_nv_88670*)(tp))->FUN_001fb1e0();

    CAmbientsManager *tq = (CAmbientsManager *)FUN_0008d690(0x3838);
    if (tq)
        tq = ((CAmbientsManager_nv_88670*)(tq))->FUN_0007f950();
    q = tq;
    ((owners::C_78c50 *)(((CAmbientsManager_nv_88670*)(tq))))->FUN_00078c50((hulk_intptr)(Sim_88670 *)this);

    FUN_000678d0()->FUN_00066c20(this);
    ready = 1;
}

} // namespace fn_f5b26912

// 0x00088c30 FUN_00088c30 (467 B): equivalent/0x00088c30.cpp [wrapped: conflict: FUN_000678d0; FUN_00085e60; FUN_001d4c90; FUN_00267f00]
// sym: ?update@Target_88c30@fn_00088c30@@QAEXPAHPAX@Z @fa8286ed1104 @wb5a37b020fec
namespace fn_00088c30 {
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 12/12)
// FUN_00088c30 @ 0x00088c30

struct Target_88c30;
struct Vec_88c30 { unsigned int x,y,z; };
struct Service_88c30 {
 void FUN_001ce020(void*); void FUN_001cbfe0(void*); void FUN_000b3d80(void*); void FUN_00106430(Target_88c30*,void*); void FUN_001af770(); void FUN_000677d0(); void FUN_0002ab40(Target_88c30*,void*); void FUN_001e6f10(Target_88c30*,void*);  void FUN_001b5da0(Target_88c30*,void*); void FUN_001dbe50(Target_88c30*); void FUN_0002ae80(Target_88c30*,void*); void FUN_001b6a90(Target_88c30*,void*); void FUN_001fc6a0(void*); void FUN_001f7320(Target_88c30*,void*); void FUN_001d1160(void*); void FUN_0009bb50(Target_88c30*,void*); Vec_88c30* FUN_001c39b0(); Vec_88c30* FUN_001c39c0();  void FUN_001eda90(Vec_88c30,Vec_88c30,Vec_88c30); void FUN_001c04e0(void*); void FUN_001bc710(void*); Service_88c30* FUN_00086320(); float FUN_00085fc0(); void FUN_000d6f30(Target_88c30*,float); void FUN_001ed320(Target_88c30*,void*); void FUN_000b3d40();
};
extern Service_88c30* __cdecl FUN_000678d0();
extern unsigned int __cdecl FUN_00267f00();
extern float __cdecl FUN_00085e60(unsigned int,unsigned int);
extern Service_88c30* __cdecl FUN_001d4c90();
extern Service_88c30* __cdecl FUN_001c3d90();
struct Target_88c30 {
 unsigned int field0;
 Service_88c30 *s04,*s08,*s0c,*s10,*s14,*s18,*s1c,*s20,*s24,*s28,*s2c,*s30,*s34,*s38,*s3c,*s40,*s44,*s48,*s4c,*s50,*s54;
 void update(int* kind,void* arg);
};
void Target_88c30::update(int* kind,void* arg) {
 if (*kind==6 || *kind==7) { s04->FUN_000b3d40(); return; }
 s2c->FUN_001ce020(arg);
 s30->FUN_001cbfe0(arg);
 s04->FUN_000b3d80(arg);
 s18->FUN_00106430(this,arg);
 s1c->FUN_001af770();
 FUN_000678d0()->FUN_000677d0();
 s20->FUN_0002ab40(this,arg);
 unsigned int start=0;
 if((*(unsigned char*)&DAT_004dd8e4)) start=FUN_00267f00();
 s0c->FUN_001e6f10(this,arg);
 if((*(unsigned char*)&DAT_004dd8e4)) {
 unsigned int end=FUN_00267f00();
 if((*(unsigned char*)&DAT_004dd8e4)) DAT_004dd918=FUN_00085e60(end-start,0);
 }
 ((owners::C_80b70 *)s4c)->FUN_00080b70((hulk_uintptr)(Target_88c30 *)this, (hulk_uintptr)arg);
 s10->FUN_001b5da0(this,arg);
 s0c->FUN_001dbe50(this);
 s20->FUN_0002ae80(this,arg);
 s14->FUN_001b6a90(this,arg);
 s28->FUN_001fc6a0(arg);
 s38->FUN_001f7320(this,arg);
 Service_88c30* optional=FUN_001d4c90();
 if(optional) optional->FUN_001d1160(arg);
 s08->FUN_0009bb50(this,arg);
 Service_88c30* source=FUN_001c3d90();
 Service_88c30* destination=s34;
 Vec_88c30* a=source->FUN_001c39b0();
 Vec_88c30* b=source->FUN_001c39c0();
 Vec_88c30* c=((Vec_88c30 *)((owners::Object_1c39d0 *)source)->FUN_001c39d0());
 destination->FUN_001eda90(*c,*b,*a);
 s50->FUN_001c04e0(arg);
 s40->FUN_001bc710(arg);
 Service_88c30* consumer=s3c;
 Service_88c30* time=s54->FUN_00086320();
 float delta=time->FUN_00085fc0();
 consumer->FUN_000d6f30(this,delta);
 s34->FUN_001ed320(this,arg);
}
} // namespace fn_00088c30

namespace fn_f5b26912 {

// 0x00088e10 FUN_00088e10 (33 B): matches/0x00088e10.cpp
// sym: ?Set@X@fn_f5b26912@@QAEXPBD@Z
void X::Set(const char* s) {
    strncpy(buf, s, 0x40);
    flag = 1;
}

} // namespace fn_f5b26912

// 0x00088e40 FUN_00088e40 (17 B): matches/0x00088e40.cpp
// sym: ?FUN_00088e40@A_88e40@owners@@QAEPAXXZ
void* owners::A_88e40::FUN_00088e40() {
    if (flag)
        return (char*)this + 0x5c;
    return 0;
}

