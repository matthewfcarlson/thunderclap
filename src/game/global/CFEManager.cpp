// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/content.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f53c52ab {
#define TREE_TU_END }
namespace fn_f53c52ab {} using namespace fn_f53c52ab;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f53c52ab {
struct Provider_be230 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual int slot44();
};
struct Binding_be230 {
    void FUN_000f8500(void*, int, int);
};
struct Channel {
    char pad[0x18];
    Binding_be230 binding;
};
struct Item_be230 {
    char pad0[4];
    Provider_be230* provider;
    char pad8[0x990];
    Channel* first;
    Channel* second;
    Channel* third;
    void FUN_000bb820(void*, int, int);
    void FUN_000e5f70();
    void FUN_000e5f00(int);
};
struct Manager_be230 {
    char pad[0x2218];
    Item_be230* active;
    Item_be230* FUN_000e7620(int);
    bool FUN_000be230(hulk_intptr, void*, void*, void*, void*, int, int, int);
};
class Dummy_be5a0 {
  public:
    void Call(void*);
};
class Owner_be5c0 {};
typedef void (Owner_be5c0::*Fn_be5c0)(const char*, const char*, const char*, const char*, int, int);
class Function_be5c0 : public ScriptFunctionFields {
  public:
    Function_be5c0(const char*, int);
    virtual void v0();
};
class Method6_be5c0 : public Function_be5c0 {
  public:
    Method6_be5c0(const char*, Fn_be5c0);
    Fn_be5c0 m1c;
};
struct Function_be660 {
    virtual void f0();
    virtual void f1();
};
void FUN_000be680(const char*, const char*, const char*, int);
class CActorManager_be720 {
  public:
    void f();
};
class Dummy_be790 {
  public:
    void Call(void*);
};
class CFEManager_be820 {
  public:
    void Call(const char*, int);
};
class Function_be820 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Function_be8f0 {
    virtual void f0();
    virtual void f1();
};
void FUN_000be910(const char*, const char*, const char*, int);
struct Obj_be910;
typedef void (Obj_be910::*Fn_be910)(int, int, int, int, int, int, int);
struct Obj_be910 {
    int x;
};
extern char DAT_00409108[];
class Owner_be950 {};
typedef void (Owner_be950::*Fn_be950)(const char*, const char*, const char*, const char*, const char*, const char*);
class Method6_be950 {
public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_be950 p1c;
    void FUN_001d0480(const char*, int);
    Method6_be950* Init(const char* arg, Fn_be950 value);
};
struct Function_be9f0 {
    virtual void f0();
    virtual void f1();
};
void FUN_000bea10(const char*, const char*, const char*, int);
class CFEManager_beac0 {
  public:
    void Call(const char*, int);
};
class Function_beac0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Function_beb40 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_bebc0 {
  public:
    void Call(void*);
};
typedef unsigned int u32_bebf0;
class Sub_bef60 {
  public:
    int SubFn_000bc750();
};
class Obj_bef60 {
  public:
    char pad[4];
    Sub_bef60* m;
    int Target(void* a, void* b);
};
struct Arg {
    char* name;
    char* value;
};
struct Inner_bf0e0 { char pad[0x2c]; int f2c; };
struct Arg_bf0e0 { char pad[0xc]; Inner_bf0e0* f0c; };
struct G_bf0e0 { void FUN_002665a0(); };
struct S_bf0e0 {
  char pad0[0x10]; int f10;
  char pad1[0x38-0x14]; int f38;
  char pad2[0x1bc8-0x3c]; unsigned char f1bc8;
  char pad3[0x1c0c-0x1bc9]; unsigned char f1c0c;
  char pad4[0x1c4c-0x1c0d]; unsigned char f1c4c;
  void FUN_000befc0(void*, int, int);
  void FUN_000bf0e0(Arg_bf0e0*, hulk_intptr);
};
extern "C" void __cdecl FUN_000fc100(void*, int);
struct Obj34 {
    int GetCount_00089450();
    void Reset_00089d30();
};
struct Dlg_bf1e0 {
    void Init_000be230(const char*, const char*, const void*, const char*, const char*, int, int, int);
};
struct Game_bf1e0 {
    char pad0[0x10];
    int state;
    char pad14[0x1c];
    int member30;
    Obj34* o34;
    char pad38[0x1cc0];
    int value1cf8;
    void Use_000b5030(int);
    void Finish_000b9650();
    void Run();
};
extern Dlg_bf1e0* __stdcall CreateDialog_000fc3d0();
extern "C" void __cdecl FUN_000fc280(const char*);
class D {
  public:
    void Init_000be230(hulk_intptr, hulk_intptr, hulk_intptr, hulk_intptr, hulk_intptr, int, int, int);
};
class C_bf260 {
  public:
    char p[16];
    int state;
    char q[28];
    int m30, m34;
    void Next_000b96e0();
};
extern D* __stdcall Make_000fc3d0();
struct A_bf560 {
    void FnF_00089380();
    int FnG_001cc900();
    void FnK_001cd410();
    void FnL_00089a30(int);
};
struct Obj_bf560 {
    char pad[0x30];
    int m30;
    A_bf560* m34;
    A_bf560* m38;
};
class Manager_bfbe0 {
  public:
    void Start_001b7310(const char*, int, int);
};
class Factory_bfbe0 {
  public:
    owners::Game_bfbe0* Create_00086300();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
} // namespace fn_f53c52ab
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f53c52ab {
class __declspec(novtable) MethodBase_bfcc0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_bfcc0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};
template <class R>
class Function0_bfcc0 : public MethodBase_bfcc0 {
  public:
    typedef R (*Fn)();
    Function0_bfcc0(const char* name, Fn f) : MethodBase_bfcc0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    }
    Fn fn;
};
struct Registry_bfcc0 {
    void FUN_000bfcc0(const char* name, void (*fn)());
};
class CActorManager_bfe80 {
  public:
    void invoke(const char*);
};
class CActorManager_bff90 {
  public:
    void run();
};
class CActorManager_c0010 {
  public:
    void invoke(const char*);
};
class CActorManager_c00b0 {
  public:
    void Method(const char*, float);
};
struct Pair_c00b0 {
    const char* s;
    float f;
};
struct CFEManager_c0120 {
    void Do(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
};
struct Args {
    const char* values[7];
};
class Function_c0120 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};
class CFEManager_c01c0 {
  public:
    void method(const char*, const char*, const char*, const char*, const char*, const char*);
};
inline const char* take(const char**& p) {
    return *p++;
}
class CActorManager_c0280 {
  public:
    void Method(const char*, float);
};
struct Pair_c0280 {
    const char* s;
    float f;
};
class CActorManager_c0300 {
  public:
    int act();
};
class CActorManager_c0390 {
  public:
    void invoke(const char*);
};
class B_c04a0 {
  public:
    int FnG_000bf160();
};
class A_c04a0 {
  public:
    char pad[4];
    B_c04a0* p;
    int Fn(int a, int b);
};
class Inner {
  public:
    void action_000bf260();
    void Step_000bf560();
};
class Outer {
  public:
    char pad[4];
    Inner* inner;
    int run(void* arg, int unused);
};
extern "C" void Finish_000fc300();
class Holder_c05f0 {
  public:
    void set_000bf5c0(long);
};
class C_c05f0 {
  public:
    int pad;
    Holder_c05f0* value;
};
class CFEManager_c06e0 {};
typedef void (CFEManager_c06e0::*Fn_c06e0)(const char*, const char*, const char*, const char*, int, int);
class Registry_c06e0 { public:
    void FUN_000c06e0(const char* a1, CFEManager_c06e0* a2, Fn_c06e0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_c06e0;
template<> class Closure6_c06e0<CFEManager_c06e0, void, const char*, const char*, const char*, const char*, int, int> : public ScriptFunctionFields { public: virtual void v(); Fn_c06e0 fn; CFEManager_c06e0* owner; Closure6_c06e0(CFEManager_c06e0* o) { owner = o; } };
class Raw_c06e0 { public: void FUN_000be5c0(const char*, Fn_c06e0); };
class CFEManager_c0850 {};
typedef void (CFEManager_c0850::*Fn_c0850)(const char*, const char*, const char*, const char*, const char*, const char*, const char*);
class Registry_c0850 { public:
    void FUN_000c0850(const char* a1, CFEManager_c0850* a2, Fn_c0850 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7_c0850;
template<> class Closure7_c0850<CFEManager_c0850, void, const char*, const char*, const char*, const char*, const char*, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_c0850 fn; CFEManager_c0850* owner; Closure7_c0850(CFEManager_c0850* o) { owner = o; } };
class Raw_c0850 { public: void FUN_000be840(const char*, Fn_c0850); };
class CFEManager_c08b0 {};
typedef void (CFEManager_c08b0::*Fn_c08b0)(const char*, const char*, const char*, const char*, const char*, const char*);
class Registry_c08b0 { public:
    void FUN_000c08b0(const char* a1, CFEManager_c08b0* a2, Fn_c08b0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_c08b0;
template<> class Closure6_c08b0<CFEManager_c08b0, void, const char*, const char*, const char*, const char*, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_c08b0 fn; CFEManager_c08b0* owner; Closure6_c08b0(CFEManager_c08b0* o) { owner = o; } };
class Raw_c08b0 { public: void FUN_000be950(const char*, Fn_c08b0); };
extern "C" char DAT_003fef7c[];
struct Obj_c0d80 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(void*, unsigned long long);
};
extern unsigned long long Get_0027b020(void*);
class DynamicCasterBase_c0db0 {
  public:
    virtual void cast();
};
class DynamicCaster_c0db0 : public DynamicCasterBase_c0db0 {
  public:
    virtual void cast();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int load(DynamicCasterBase_c0db0*, unsigned __int64);
};
extern unsigned __int64 findShader_0027b020(const char*);
class DynamicCaster_c0de0 {
  public:
    virtual void Cast_00046280(void*);
};
struct Sub_c1f00 {
    void Fn_000c1790(int);
};
struct Obj_c1f00 {
    char pad[4];
    Sub_c1f00* mSub;
    int Run(int flag, int* p);
};
struct Sub_c1f30 {
    int FnG_000c1ac0();
};
struct Obj_c1f30 {
    char pad[4];
    Sub_c1f30* m;
    int F(int a, int b);
};
class CAction_c1f50 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_c1f50* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CFEManager_c1f50 : public CAction_c1f50 {
  public:
    CFEManager_c1f50* vfunc_2(unsigned char);
};
struct CFEManager_nv_c1f50 {
    void FUN_000c1430();
};
extern void thunk_FUN_00267090(CFEManager_c1f50*);
struct Obj_c2b90 {
    char pad[0x158];
    int mVal;
};
struct Target_c2b90 {
    void FnA_000bfa10(int, int);
    void FnB_000b64f0();
    void FnC_000b63a0();
    void FnD_000c21b0(int);
};
struct Holder_c2b90 {
    int pad;
    Target_c2b90* mT;
    int Handle(int, int*);
};
extern char hulk_at_0049dba4[], hulk_at_0049faf4[];
void* Cast_000fc260(int);
class CUnlockable_c3db0 {
  public:
    virtual void v0();
};
class CUnlockableGallery_c3db0 : public CUnlockable_c3db0 {
  public:
    const char* FUN_00092320();
    const char* FUN_00092330();
};
class ItemTable_c3db0 {
  public:
};
class Screen_c3db0 {
  public:
    char pad0[0x10];
    int field10;
    char pad1[0x4c - 0x14];
    ItemTable_c3db0* items;
    char pad2[0x1878 - 0x50];
    char flag1878;
    char pad3[3];
    int selected;
    char pad4[0x1a04 - 0x1880];
    char flag1a04;
    char pad5[3];
    int field1a08;
    void FUN_000ba040();
    char FUN_000c3900(const char* a, int b, int c, int d, const char* e, int f, int g);
    void FUN_000c3db0();
};
class Child {
  public:
    void act_000c2c20();
};
class Obj {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual int f3(DynamicCaster_c0de0*, __int64);
    union { Child* child; Inner* inner; Obj* other; };
    void FUN_000bea10(int, int, int, int, int, int);
    void action_000bf1e0();
    int fn(void* p, int unused);
    int Run(int a, int b);
    int fn(int a, int b);
};
typedef void (Obj::*Func)(int, int, int, int, int, int);
struct Handler {
    char pad[4];
    Obj* ptr;
    int Process(int, Arg*);
};
extern __int64 helper_0027b020(Obj*);
typedef unsigned int uint_000c3e70;
class Helper {
  public:
    int Fn_000c31e0(int x);
};
class C_000c3e70 {
  public:
    int pad;
    Helper* mPtr;
    int Fn(uint_000c3e70 a, int* b);
};
class Sub_c4000 {
  public:
    void FnF_00094590();
};
class Obj_c4000 {
    char pad[0x4c];

  public:
    Sub_c4000* sub;
    void FnG_000c3ea0();
};
class Target_c4000 {
    char pad[4];
    Obj_c4000* obj;

  public:
    int F(int a, int b);
};
extern void* hulk_at_00409078[];
extern void* hulk_at_00409080[];
} // namespace fn_f53c52ab
void* operator new(size_t);
namespace fn_f53c52ab {
struct H0_c43a0 {
    void* vptr;
    void* self;
    void* fn;
    H0_c43a0(void* s, void* f) : vptr(v0), self(s), fn(f) {}
};
struct H1 {
    void* vptr;
    void* self;
    void* fn;
    H1(void* s, void* f) : vptr(hulk_at_00409078), self(s), fn(f) {}
};
struct H2_c43a0 {
    void* vptr;
    void* self;
    void* fn;
    H2_c43a0(void* s, void* f) : vptr(hulk_at_00409080), self(s), fn(f) {}
};
extern "C" void FUN_000fc1e0(const char*, H0_c43a0*);
extern "C" void FUN_000fc220(const char*, H1*);
extern "C" void FUN_000fc200(const char*, H2_c43a0*);
void Mb45e0_000b45e0();
void Mb45f0_000b45f0();
void Mb4610_000b4610();
void Mbbb40_000bbb40();
void Mbbb80_000bbb80();
void Mbbb90_000bbb90();
void Mbbbb0_000bbbb0();
void Mbbc00_000bbc00();
void Mbbc20_000bbc20();
void Mbbc50_000bbc50();
void Mbbc90_000bbc90();
void Mbbcb0_000bbcb0();
void Mbbcd0_000bbcd0();
void Mbbcf0_000bbcf0();
void Mbbd10_000bbd10();
void Mbbd30_000bbd30();
void Mbbd60_000bbd60();
void Mbbd80_000bbd80();
void Mbbda0_000bbda0();
void Mbbdc0_000bbdc0();
void Mbbdf0_000bbdf0();
void Mbbe20_000bbe20();
void Mbbe50_000bbe50();
void Mbbe90_000bbe90();
void Mbbeb0_000bbeb0();
void Mbbed0_000bbed0();
void Mbbef0_000bbef0();
void Mbbf00_000bbf00();
void Mbbf20_000bbf20();
void Mbbf60_000bbf60();
void Mbbf70_000bbf70();
void Mbbfa0_000bbfa0();
void Mbbfd0_000bbfd0();
void Mbbff0_000bbff0();
void Mbc010_000bc010();
extern "C" void FUN_000bc030();
extern "C" void FUN_000bc040();
void Mbc050_000bc050();
void Mbc060_000bc060();
void Mbc080_000bc080();
void Mbc0a0_000bc0a0();
void Mbc0b0_000bc0b0();
void Mbc0d0_000bc0d0();
void Mbc0f0_000bc0f0();
void Mbecd0_000becd0();
void Mbef60_000bef60();
void Mbef80_000bef80();
void Mc04a0_000c04a0();
void Mc04c0_000c04c0();
void Mc04e0_000c04e0();
void Mc0500_000c0500();
void Mc0540_000c0540();
void Mc0590_000c0590();
void Mc05d0_000c05d0();
void Mc05f0_000c05f0();
void Mc0630_000c0630();
void Mc1f00_000c1f00();
void Mc1f30_000c1f30();
void Mc2b90_000c2b90();
void Mc3e50_000c3e50();
void Mc3e70_000c3e70();
void Mc4000_000c4000();
class CFrontEndCallback_c43a0 {
  public:
    void* vptr;
    void* m4;
    CFrontEndCallback_c43a0* ctor(void* arg);
};


// 0x000be230 FUN_000be230 (213 B): matches/0x000be230.cpp
// sym: ?FUN_000be230@Manager_be230@fn_f53c52ab@@QAE_NHPAX000HHH@Z
bool Manager_be230::FUN_000be230(hulk_intptr id, void* setup, void* a, void* b, void* c, int mode, int x, int y) {
    if (active)
        return false;
    Item_be230* item = FUN_000e7620(id);
    if (setup)
        item->FUN_000bb820(setup, x, y);
    if (a) {
        Binding_be230* dest = &item->first->binding;
        dest->FUN_000f8500(a, item->provider->slot44(), 1);
    }
    if (b) {
        Binding_be230* dest = &item->second->binding;
        dest->FUN_000f8500(b, item->provider->slot44(), 1);
    }
    if (c) {
        Binding_be230* dest = &item->third->binding;
        dest->FUN_000f8500(c, item->provider->slot44(), 1);
    }
    item->FUN_000e5f70();
    item->FUN_000e5f00(mode);
    active = item;
    return true;
}

} // namespace fn_f53c52ab

// 0x000be310 FUN_000be310 (213 B): matches/0x000be310.cpp [wrapped: conflict: Channel]
// sym: ?FUN_000be310@Owner_be310@fn_000be310@@QAE_NIPAX000III@Z
namespace fn_000be310 {
struct Provider_be310 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual unsigned int slot44();
};
struct Binding_be310 {
    void FUN_000f8500(void*, unsigned int, int);
};
struct Channel {
    char pad[0x18];
    Binding_be310 binding;
};
struct Item_be310 {
    char pad0[4];
    Provider_be310* provider;
    char pad8[0x990];
    Channel* first;
    Channel* second;
    Channel* third;
    void FUN_000bb970(void*, unsigned int, unsigned int);
    void FUN_000e5f70();
    void FUN_000e5f00(unsigned int);
};
struct Owner_be310 {
    char pad[0x2218];
    Item_be310* active;
    Item_be310* FUN_000e7620(unsigned int);
    bool FUN_000be310(hulk_uintptr, void*, void*, void*, void*, unsigned int, hulk_uintptr, hulk_uintptr);
};
bool Owner_be310::FUN_000be310(hulk_uintptr id, void* setup, void* a, void* b, void* c, unsigned int mode,
                         hulk_uintptr x, hulk_uintptr y) {
    if (active)
        return false;
    Item_be310* item = FUN_000e7620(id);
    if (setup)
        item->FUN_000bb970(setup, x, y);
    if (a) {
        Binding_be310* binding = &item->first->binding;
        binding->FUN_000f8500(a, item->provider->slot44(), 1);
    }
    if (b) {
        Binding_be310* binding = &item->second->binding;
        binding->FUN_000f8500(b, item->provider->slot44(), 1);
    }
    if (c) {
        Binding_be310* binding = &item->third->binding;
        binding->FUN_000f8500(c, item->provider->slot44(), 1);
    }
    item->FUN_000e5f70();
    item->FUN_000e5f00(mode);
    active = item;
    return true;
}
} // namespace fn_000be310


// 0x000be4a0 Function1<void,const_char_*>::vfunc_0 (30 B): matches/0x000be4a0.cpp
// sym: ??_G?$Function1@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function1<void, const char *>::~Function1() {}
#if defined(HULK_PTR64)
template class Function1<void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe4a0)
#endif


// 0x000be4c0 Function1<void,const_char_*>::vfunc_2 (14 B): matches/0x000be4c0.cpp [wrapped: conflict: Function; Function1]
// sym: ?v2@Function1@fn_000be4c0@@UAEXHPAPBDH@Z
namespace fn_000be4c0 {
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Function1 : public Function {
    char pad[0x18];

  public:
    void(__cdecl* mFn)(const char*);
    virtual void v0();
    virtual void v1();
    virtual void v2(int, const char**, int);
};
void Function1::v2(int, const char** p, int) {
    mFn(*p);
}
} // namespace fn_000be4c0


// 0x000be510 Function0<void>::vfunc_0 (30 B): matches/0x000be510.cpp
// sym: ??_G?$Function0@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function0<void>::~Function0() {}
#if defined(HULK_PTR64)
template class Function0<void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe510)
#endif


// 0x000be530 Function0<void>::vfunc_2 (6 B): matches/0x000be530.cpp [wrapped: conflict: Function]
// sym: ?f2@Function0_be530@fn_000be530@@UAEXHHH@Z
namespace fn_000be530 {
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Function0_be530 : public Function {
  public:
    virtual void f0();
    virtual void f2(int, int, int);
    char pad[0x18];
    void(__cdecl* mFn)();
};
void Function0_be530::f2(int, int, int) {
    mFn();
}
} // namespace fn_000be530


// 0x000be580 Method1<CFEManager,void,char_*>::vfunc_0 (30 B): matches/0x000be580.cpp
// sym: ??_G?$Method1@VCFEManager@@XPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CFEManager, void, char *>::~Method1() {}


// 0x000be5a0 Method1<CFEManager,void,char_*>::vfunc_2 (19 B): matches/0x000be5a0.cpp
// sym: ?vfunc_2@?$Method1@VCFEManager@@XPAD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CFEManager, void, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_be5a0* d = (Dummy_be5a0*)a;
    (d->*(*(void (Dummy_be5a0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CFEManager, void, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe580)
#endif

namespace fn_f53c52ab {

// 0x000be5c0 FUN_000be5c0 (128 B): matches/0x000be5c0.cpp
// sym: ??0Method6_be5c0@fn_f53c52ab@@QAE@PBDP8Owner_be5c0@1@AEX0000HH@Z@Z
// Method6<Owner, void, const char* x4, int, int>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
Method6_be5c0::Method6_be5c0(const char* p, Fn_be5c0 x) : Function_be5c0(p, 6) {
    m1c = x;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e134));
    argTypes[5] = FUN_001d04d0(((char*)&DAT_0048e134));
}

} // namespace fn_f53c52ab

// 0x000be640 Method6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_0 (30 B): matches/0x000be640.cpp
// sym: ??_G?$Method6@VCFEManager@@XPBDPBDPBDPBDHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>::~Method6() {}


// 0x000be660 Method6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_2 (30 B): matches/0x000be660.cpp
// sym: ?vfunc_2@?$Method6@VCFEManager@@XPBDPBDPBDPBDHH@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_000be680(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe640)
#endif

namespace fn_f53c52ab {

// 0x000be680 FUN_000be680 (53 B): matches/0x000be680.cpp
// sym: ?forward@fn_f53c52ab@@YAXPAVObj@1@PAHHP821@AEXHHHHHH@Z@Z
void forward(Obj* obj, int* v, int unused, Func fn) {
    int a = *v++;
    int b = *v++;
    int c = *v++;
    int d = *v++;
    int e = v[1];
    int f = v[0];
    (obj->*fn)(a, b, c, d, f, e);
}

} // namespace fn_f53c52ab

// 0x000be700 Method0<CFEManager,void>::vfunc_0 (30 B): matches/0x000be700.cpp
// sym: ??_G?$Method0@VCFEManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CFEManager, void>::~Method0() {}


// 0x000be720 Method0<CFEManager,void>::vfunc_2 (12 B): matches/0x000be720.cpp
// sym: ?vfunc_2@?$Method0@VCFEManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CFEManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_be720 * a = (CActorManager_be720 *)__p0;

    (a->*(*(void (CActorManager_be720::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CFEManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe700)
#endif


// 0x000be770 Method1<CFEManager,void,const_char_*>::vfunc_0 (30 B): matches/0x000be770.cpp
// sym: ??_G?$Method1@VCFEManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CFEManager, void, const char *>::~Method1() {}


// 0x000be790 Method1<CFEManager,void,const_char_*>::vfunc_2 (19 B): matches/0x000be790.cpp
// sym: ?vfunc_2@?$Method1@VCFEManager@@XPAD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CFEManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_be790* d = (Dummy_be790*)a;
    (d->*(*(void (Dummy_be790::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CFEManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe770)
#endif


// 0x000be800 Method2<CFEManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000be800.cpp
// sym: ??_G?$Method2@VCFEManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CFEManager, void, const char *, const char *>::~Method2() {}


// 0x000be820 Method2<CFEManager,void,const_char_*,const_char_*>::vfunc_2 (23 B): matches/0x000be820.cpp
// sym: ?vfunc_2@?$Method2@VCFEManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CFEManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_be820* m = (CFEManager_be820*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_be820::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CFEManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe800)
#endif


// 0x000be840 FUN_000be840 (141 B): matches/0x000be840.cpp [wrapped: conflict: Method7]
// sym: ??0Method7@fn_000be840@@QAE@PBDP8Owner_be840@1@AEX0000000@Z@Z
namespace fn_000be840 {
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

// Method7<Owner, void, const char* x7>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class Owner_be840 {};
typedef void (Owner_be840::*Fn_be840)(const char*, const char*, const char*, const char*, const char*, const char*,
                                      const char*);
class Function_be840 : public ScriptFunctionFields {
  public:
    Function_be840(const char* a, int n);
    virtual void Call();
};

class Method7 : public Function_be840 {
  public:
    Method7(const char* a, Fn_be840 b);
    virtual void Call();
    Fn_be840 m1c;
};


Method7::Method7(const char* a, Fn_be840 b) : Function_be840(a, 7) {
    m1c = b;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[4] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[5] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[6] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
} // namespace fn_000be840
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000be8d0 Method7<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000be8d0.cpp
// sym: ??_G?$Method7@VCFEManager@@XPBDPBDPBDPBDPBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::~Method7() {}


// 0x000be8f0 Method7<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (30 B): matches/0x000be8f0.cpp
// sym: ?vfunc_2@?$Method7@VCFEManager@@XPBDPBDPBDPBDPBDPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_000be910(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe8d0)
#endif

namespace fn_f53c52ab {

// 0x000be910 FUN_000be910 (62 B): matches/0x000be910.cpp
// sym: ?FUN_000be910@fn_f53c52ab@@YAXPAUObj_be910@1@PAHHP821@AEXHHHHHHH@Z@Z
// Same code shape as 0x00094490 (propagated; names are from that function)
void __cdecl FUN_000be910(Obj_be910* a, int* p, int b, Fn_be910 fn) {
    int* q = p;
    int v0 = *q;
    q++;
    int v1 = *q;
    q++;
    int v2 = *q;
    q++;
    int v3 = *q;
    q++;
    int v4 = *q;
    q++;
    int v5 = *q;
    q++;
    int v6 = *q;
    (a->*fn)(v0, v1, v2, v3, v4, v5, v6);
}


// 0x000be950 FUN_000be950 (128 B): matches/0x000be950.cpp
// sym: ?Init@Method6_be950@fn_f53c52ab@@QAEPAV12@PBDP8Owner_be950@2@AEX000000@Z@Z
// FUN_000be950 @ 0x000be950
// 0x000be950: Method6 callback object constructor (bool/byte flags from the per-type descriptor words)
Method6_be950* Method6_be950::Init(const char* arg, Fn_be950 value)
{
    FUN_001d0480(arg, 6);
    vptr = (void*)DAT_00409108;
    p1c = value;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[5] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    return this;
}

} // namespace fn_f53c52ab

// 0x000be9d0 Method6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000be9d0.cpp
// sym: ??_G?$Method6@VCFEManager@@XPBDPBDPBDPBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *>::~Method6() {}


// 0x000be9f0 Method6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (30 B): matches/0x000be9f0.cpp
// sym: ?vfunc_2@?$Method6@VCFEManager@@XPBDPBDPBDPBDPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_000bea10(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbe9d0)
#endif

namespace fn_f53c52ab {

// 0x000bea10 FUN_000bea10 (53 B): matches/0x000bea10.cpp
// sym: ?FUN_000bea10@fn_f53c52ab@@YAXPAVObj@1@PAHHP821@AEXHHHHHH@Z@Z
void __cdecl FUN_000bea10(Obj* object, int* values, int unused,
                          void (Obj::*callback)(int, int, int, int, int, int)) {
    int a = *values++;
    int b = *values++;
    int c = *values++;
    int d = *values++;
    int e = *values++;
    int f = *values++;
    (object->*callback)(a, b, c, d, e, f);
}

} // namespace fn_f53c52ab

// 0x000beaa0 Method2<CFEManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x000beaa0.cpp
// sym: ??_G?$Method2@VCFEManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CFEManager, void, const char *, int>::~Method2() {}


// 0x000beac0 Method2<CFEManager,void,const_char_*,int>::vfunc_2 (23 B): matches/0x000beac0.cpp
// sym: ?vfunc_2@?$Method2@VCFEManager@@XPBDPBD@@UAEXPAX00@Z
template <> void Method2<CFEManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_beac0* m = (CFEManager_beac0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_beac0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CFEManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbeaa0)
#endif


// 0x000beb20 Method0<CFEManager,int>::vfunc_0 (30 B): matches/0x000beb20.cpp
// sym: ??_G?$Method0@VCFEManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CFEManager, int>::~Method0() {}


// 0x000beb40 Method0<CFEManager,int>::vfunc_2 (22 B): matches/0x000beb40.cpp
// sym: ?vfunc_2@?$Method0@VCFEManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CFEManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method0<CFEManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbeb20)
#endif


// 0x000beba0 Method1<CFEManager,void,int>::vfunc_0 (30 B): matches/0x000beba0.cpp
// sym: ??_G?$Method1@VCFEManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CFEManager, void, int>::~Method1() {}


// 0x000bebc0 Method1<CFEManager,void,int>::vfunc_2 (19 B): matches/0x000bebc0.cpp
// sym: ?vfunc_2@?$Method1@VCFEManager@@XPAD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CFEManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_bebc0* d = (Dummy_bebc0*)a;
    (d->*(*(void (Dummy_bebc0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CFEManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbeba0)
#endif


// 0x000bebf0 content::LoadInventory::DynamicCaster<pure3d::Texture>::vfunc_0 (30 B): matches/0x000bebf0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VTexture@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::Texture>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    __RTDynamicCast((void*)((hulk_uintptr)p), 0, (void*)(&type_refcount), (void*)(&type_animation), 0);
}


// 0x000becd0 FUN_000becd0 (647 B): equivalent/0x000becd0.cpp [wrapped: conflict: DAT_0049dba4]
// sym: ?run@Target_becd0@fn_000becd0@@QAEHHPAPBD@Z @c58837230c1c @w173af38a2961
namespace fn_000becd0 {
// STATUS: equivalent (tools/equiv.py level 3: 3153 inputs, branch coverage 32/32)
// FUN_000becd0 @ 0x000becd0
struct Entry_becd0 { char pad[0x10]; int a,b; char tail[0x10]; };
struct Manager_becd0 { char pad[0x26c]; const char* names[128]; char gap[0x14]; Entry_becd0 entries[1]; bool FUN_000b4dc0(const char*);  void FUN_000bc5c0(const char*,const char*,int,int); int FUN_000b4d70(int,int); void FUN_000bc6a0(); };
struct Record_becd0 { char pad[0x14]; int value; char tail[0x20]; };
struct Item_becd0 { char pad[0x154]; int index; Record_becd0 records[128]; int count; };
struct Service_becd0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void* get(); };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" long __cdecl atol(const char*);
#endif

extern int DAT_0049dba4, DAT_0049dbbc;
extern unsigned DAT_004d9968;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __fastcall __security_check_cookie(unsigned);
#endif

void* __cdecl FUN_000fc260(const char*);
Item_becd0* __cdecl FUN_00344e74(void*,int,int*,int*,int);
Service_becd0* __cdecl FUN_000fc3d0();
struct Object {  };
void __cdecl FUN_000964a0(char*,int,const char*,...);
struct Target_becd0 { int unknown; Manager_becd0* manager; int run(int,const char**); };
int Target_becd0::run(int argc,const char** argv) {
 unsigned cookie=DAT_004d9968;
 int result=-1;
 do {
 if(!manager || argc!=4) break;
 const char* command=argv[0]; const char* name=argv[1];
 int mode=atol(argv[2]); if(mode<0 || mode>=3) break;
 int variant=atol(argv[3]); if(variant<1 || variant>2) break;
 Manager_becd0* m=manager;
 if(m->FUN_000b4dc0(command) && ((owners::K_b4c10 *)m)->FUN_000b4c10(name)) { m->FUN_000bc5c0(command,name,mode,variant); result=0; break; }
 Item_becd0* primary=FUN_00344e74(FUN_000fc260("mission_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 FUN_00344e74(FUN_000fc260("story_mission_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 FUN_00344e74(FUN_000fc260("side_mission_selector"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 Item_becd0* item=FUN_00344e74(FUN_000fc260(name),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 bool match=true; const char* s="oneshot";
 if(item && item->count>0) { for(int i=0;i<8;i++) if(command[i]!=s[i]) {match=false;break;} }
 else match=false;
 if(!match) { manager->FUN_000bc6a0(); result=0; break; }
 Record_becd0* record=item->records+item->index;
 Service_becd0* service=FUN_000fc3d0();
 int recvalue=record->value;   // MSVC pushes the argument before it calls get()
 __int64 key=((__int64)((owners::Obj_f72c0 *)(((Object*)service->get())))->FUN_000f72c0(recvalue));
 m=manager;
 int found=m->FUN_000b4d70((int)key,(int)(key>>32));
 if(found!=-1) {
 char buffer[128];
 FUN_000964a0(buffer,128,"c%02dm%02d",m->entries[found].a,m->entries[found].b);
 manager->FUN_000bc5c0(command,buffer,mode,variant); result=0; break;
 }
 if(item!=primary) break;
 int index=item->index;
 if(index<0 || index>=128 || !m->names[index]) break;
 manager->FUN_000bc5c0(command,manager->names[index],mode,variant); result=0;
 } while(false);
 __security_check_cookie(cookie);
 return result;
}
} // namespace fn_000becd0

namespace fn_f53c52ab {

// 0x000bef60 FUN_000bef60 (23 B): matches/0x000bef60.cpp
// sym: ?Target@Obj_bef60@fn_f53c52ab@@QAEHPAX0@Z
int Obj_bef60::Target(void* a, void* b) {
    Sub_bef60* s = m;
    if (!s)
        return -1;
    s->SubFn_000bc750();
    return 0;
}


// 0x000bef80 FUN_000bef80 (64 B): matches/0x000bef80.cpp
// sym: ?Process@Handler@fn_f53c52ab@@QAEHHPAUArg@2@@Z
int Handler::Process(int mode, Arg* arg) {
    if (!ptr)
        return -1;
    if (mode != 2)
        return -1;
    if (arg->value)
        ((owners::MenuScreen_bc9f0 *)ptr)->FUN_000bc9f0((hulk_intptr)(arg->name), (int)(atol(arg->value)));
    return 0;
}


// 0x000bf0e0 FUN_000bf0e0 (118 B): matches/0x000bf0e0.cpp
// sym: ?FUN_000bf0e0@S_bf0e0@fn_f53c52ab@@QAEXPAUArg_bf0e0@2@H@Z
// FUN_000bf0e0 @ 0x000bf0e0
void S_bf0e0::FUN_000bf0e0(Arg_bf0e0* a, hulk_intptr){
  (*(G_bf0e0**)&DAT_004dd9cc)->FUN_002665a0();
  FUN_000befc0((*(void**)&DAT_0049f3c4), 14, 1);
  FUN_000befc0((*(void**)&DAT_0049f3cc), 14, 1);
  FUN_000fc100((*(void**)&DAT_0049f3b0), 0);
  f10 = 8;
  (*(unsigned char*)&DAT_004e222c) = 1;
  f1c0c = 0;
  f1c4c = 0;
  f38 = a->f0c->f2c;
  f1bc8 = 1;
}

} // namespace fn_f53c52ab

// 0x000bf160 FUN_000bf160 (117 B): matches/0x000bf160.cpp [wrapped: conflict: FUN_000fc260; FUN_000fc3d0]
// sym: ?FUN_000bf160@DifficultyScreen@fn_000bf160@@QAEXXZ
namespace fn_000bf160 {
// FUN_000bf160 @ 0x000bf160
class FEObject_bf160 {
public:
    virtual void v0();
};

class TextButton_bf160 : public FEObject_bf160 {
public:
    char pad04[0x74 - 4];
    unsigned char f74;
    char pad75[0x141 - 0x75];
    unsigned char f141;
};

struct Item_bf160 {
    char pad0[0x14];
    int id;
};

class Panel_bf160 {
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
    virtual void Select(int id);
};

class Manager_bf160 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Panel_bf160 *Find(const char *name);
};

struct Settings_bf160 {
    char pad0[0xabf];
    unsigned char difficulty;
};

Manager_bf160 *__cdecl FUN_000fc3d0();
Item_bf160 *__cdecl FUN_000fc260(const char *name);

class DifficultyScreen {
public:
    char pad0[0x34];
    Settings_bf160 *settings;
    void FUN_000bf160();
};

void DifficultyScreen::FUN_000bf160()
{
    Panel_bf160 *sel = FUN_000fc3d0()->Find("difficulty_select");
    if (sel != 0) {
        Item_bf160 *normal = FUN_000fc260("difficulty_normal");
        if (normal != 0)
            sel->Select(normal->id);
    }
    TextButton_bf160 *hard = dynamic_cast<TextButton_bf160 *>((FEObject_bf160 *)FUN_000fc260("difficulty_hard"));
    if (hard != 0) {
        unsigned char v = ((owners::Target_893c0 *)settings)->FUN_000893c0();
        hard->f141 = v;
        hard->f74 = v;
    }
}
} // namespace fn_000bf160

namespace fn_f53c52ab {

// 0x000bf1e0 FUN_000bf1e0 (121 B): matches/0x000bf1e0.cpp
// sym: ?Run@Game_bf1e0@fn_f53c52ab@@QAEXXZ
// data: gZero_bf1e0 = DAT_003f335c
void Game_bf1e0::Run() {
    if (o34) {
        if (o34->GetCount_00089450() > 0) {
            if (member30) {
                CreateDialog_000fc3d0()
                    ->Init_000be230("FEGenericDialog", "TBS_MENU_ITEM_RESTART_DEMO", ((char*)&DAT_003f335c), "TBS_MENU_ITEM_OK", "TBS_CANCEL", 2, 0, 0);
                state = 0x12;
                Finish_000b9650();
            }
        } else {
            o34->Reset_00089d30();
            Use_000b5030(value1cf8);
            FUN_000fc280("save_new_game");
        }
    }
}


// 0x000bf260 FUN_000bf260 (77 B): matches/0x000bf260.cpp
// sym: ?Target@fn_f53c52ab@@YIXPAVC_bf260@1@@Z
void __fastcall Target(C_bf260* self) {
    if (self->m34 && self->m30) {
        Make_000fc3d0()->Init_000be230(((hulk_intptr)((char*)&DAT_0040914c)), ((hulk_intptr)((char*)&DAT_0040915c)), ((hulk_intptr)((char*)&DAT_003f335c)), ((hulk_intptr)((char*)&DAT_00408ee8)), ((hulk_intptr)((char*)&DAT_00408fa0)), 2, 0, 0);
        self->state = 0x13;
        self->Next_000b96e0();
    }
}


// 0x000bf560 FUN_000bf560 (85 B): matches/0x000bf560.cpp
// sym: ?Target@fn_f53c52ab@@YIXPAUObj_bf560@1@@Z
void __fastcall Target(Obj_bf560* p) {
    if (p->m38) {
        p->m34->FnF_00089380();
        if (!p->m38->FnG_001cc900()) {
            if (p->m30 && p->m34 && p->m38) {
                ((::CScenarioManager *)(p->m38))->FUN_001cc620(9);
                p->m34->FnL_00089a30(0);
                FUN_000fc300();
            }
            return;
        }
        p->m38->FnK_001cd410();
    }
}

} // namespace fn_f53c52ab

// 0x000bf5c0 FUN_000bf5c0 (1102 B): equivalent/0x000bf5c0.cpp [wrapped: conflict: FUN_000fc3d0]
// sym: ?FUN_000bf5c0@Screen_bf5c0@fn_000bf5c0@@QAEDH@Z @d8ef570f05b7 @wf61a8445dcd8
namespace fn_000bf5c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2244 inputs, branch coverage 10/10)
// FUN_000bf5c0 @ 0x000bf5c0
class CUnlockable_bf5c0 {
  public:
    virtual void v0();
};
class CUnlockableMove_bf5c0 : public CUnlockable_bf5c0 {
  public:
    char pad[4];
    char flag;
    void FUN_00091f30(int arg);
};
class ItemTable_bf5c0 {
  public:
};
struct Game_bf5c0 {
    char FUN_000be230(const char* cls, const char* msg, const char* title, const char* ok,
                      const char* cancel, int buttons, int a, int b);
};
Game_bf5c0* __cdecl FUN_000fc3d0();

class Screen_bf5c0 {
  public:
    char pad0[0x4c];
    ItemTable_bf5c0* items;
    char FUN_000bf5c0(int lastRow);
};

char Screen_bf5c0::FUN_000bf5c0(int lastRow) {
    int table[7][20] = {
        { -1 },
        { 0x266, 0x267, 0x268, 0x269, 0x26a, 0x2a6, 0x2b0, 0x28f, 0x26d, 0x271, 0x2af, 0x27f, 0x296, -1 },
        { 0x26b, 0x26c, 0x26e, 0x26f, 0x270, 0x283, 0x274, 0x278, 0x27b, 0x2b4, 0x2b5, 0x2b7, 0x2b8,
          0x2b9, 0x27e, 0x2b6, 0x2ab, -1 },
        { 0x272, 0x27c, 0x27d, 0x276, 0x280, 0x273, 0x285, 0x289, 0x28a, 0x28b, 0x2a4, 0x2ad, 0x2b3,
          0x2b1, 0x299, 0x29b, 0x29f, -1 },
        { 0x286, 0x28c, 0x28d, 0x290, 0x293, 0x294, 0x295, 0x298, 0x2a2, 0x2ae, 0x2b2, 0x287, -1 },
        { 0x29c, 0x29e, 0x28e, 0x2a3, 0x2ba, -1 },
        { -1 }
    };
    for (int i = 0; i <= lastRow && i < 7; i++) {
        const int* p = table[i];
        if (*p != -1) {
            do {
                CUnlockableMove_bf5c0* m = dynamic_cast<CUnlockableMove_bf5c0*>(((CUnlockable_bf5c0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)(*p))));
                if (m) {
                    m->flag = 0;
                    m->FUN_00091f30(1);
                }
                ++p;
            } while (*p != -1);
        }
    }
    return FUN_000fc3d0()->FUN_000be230("FEGenericDialog", "Moves unlocked", "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
}
} // namespace fn_000bf5c0


// 0x000bfbe0 FUN_000bfbe0 (103 B): matches/0x000bfbe0.cpp
// sym: ?FUN_000bfbe0@Game_bfbe0@owners@@QAEXPAXM@Z
void owners::Game_bfbe0::FUN_000bfbe0(void* arg, float dt) {
    timer += dt;
    if (Check(0, 1))
        timer = 0.0f;
    if (timer >= 66.6f) {
        ((Manager_bfbe0*)((Factory_bfbe0*)arg)->Create_00086300())->Start_001b7310("attract", 1000, 1);
        timer = 0.0f;
    }
}


// 0x000bfc50 FUN_000bfc50 (109 B): equivalent/0x000bfc50.cpp [wrapped: conflict: Function1]
// sym: ?FUN_000bfc50@Registry_bfc50@fn_000bfc50@@QAEXPBDP6AX0@Z@Z @ce941f3a36f6 @w8985ac9603f5
namespace fn_000bfc50 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000bfc50 @ 0x000bfc50
// FUN_000bfc50 @ 0x000bfc50  (generated by work/closure/gen.py)
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



// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_bfc50 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_bfc50(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class R, class A>
class Function1 : public MethodBase_bfc50 {
  public:
    typedef R (*Fn)(A);
    Function1(const char* name, Fn f) : MethodBase_bfc50(name, 1) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    Fn fn;
};

struct Registry_bfc50 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000bfc50(const char* name, void (*fn)(const char*));
};

void Registry_bfc50::FUN_000bfc50(const char* name, void (*fn)(const char*)) {
    typedef Function1<void, const char*> Built_t;
    HULK_SIZE32(Built_t, 0x20);
    void* mem = FUN_0008d690((int)sizeof(Function1<void, const char*>));
    Function1<void, const char*>* c = 0;
    if (mem)
        c = new (mem) Function1<void, const char*>(name, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000bfc50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f53c52ab {

// 0x000bfcc0 FUN_000bfcc0 (96 B): equivalent/0x000bfcc0.cpp
// sym: ?FUN_000bfcc0@Registry_bfcc0@fn_f53c52ab@@QAEXPBDP6AXXZ@Z @2197b2e1f196 @wff3c4636b530
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000bfcc0 @ 0x000bfcc0
// FUN_000bfcc0 @ 0x000bfcc0  (generated by work/closure/gen.py)
void Registry_bfcc0::FUN_000bfcc0(const char* name, void (*fn)()) {
    typedef Function0_bfcc0<void> Built_t;
    HULK_SIZE32(Built_t, 0x20);
    void* mem = FUN_0008d690((int)sizeof(Function0_bfcc0<void>));
    Function0_bfcc0<void>* c = 0;
    if (mem)
        c = new (mem) Function0_bfcc0<void>(name, fn);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)name, (hulk_intptr)c);
}

} // namespace fn_f53c52ab

// 0x000bfe10 FUN_000bfe10 (76 B): matches/0x000bfe10.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_000bfe10@@QAE@PAX00@Z
namespace fn_000bfe10 {

extern "C++" __declspec(nothrow) unsigned char __cdecl Find_001d04d0(void*);
class Parent {
  public:
    virtual void invoke();
    Parent(void*, int);
};
class Closure1_bfe10 : public Parent {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* ptr;
    Closure1_bfe10(void*, void*);
};
Closure1_bfe10::Closure1_bfe10(void* p, void* q) : Parent(p, 1) {
    ptr = q;
    b = Find_001d04d0(((int*)&DAT_0048e100));
    a = Find_001d04d0(((int*)&DAT_0049cad8));
}
class Closure1 : public Closure1_bfe10 {
  public:
    virtual void invoke();
    void* ptr2;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* p, void* q, void* r) : Closure1_bfe10(p, r) {
    ptr2 = q;
}
} // namespace fn_000bfe10


// 0x000bfe60 Closure1<CFEManager,void,char_*>::vfunc_0 (30 B): matches/0x000bfe60.cpp
// sym: ??_G?$Method1@VCFEManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CFEManager, void, char *>::~Closure1() {}


// 0x000bfe80 Closure1<CFEManager,void,char_*>::vfunc_2 (18 B): matches/0x000bfe80.cpp
// sym: ?vfunc_2@?$Closure1@VCFEManager@@XPAD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CFEManager, void, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_bfe80 * *)&this->f_20)->*(*(void (CActorManager_bfe80::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CFEManager, void, char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbfe60)
#endif


// 0x000bfed0 Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_0 (30 B): matches/0x000bfed0.cpp
// sym: ??_G?$Method6@VCFEManager@@XPBDPBDPBDPBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>::~Closure6() {}
#if defined(HULK_PTR64)
template class Closure6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbfed0)
#endif


// 0x000bff70 Closure0<CFEManager,void>::vfunc_0 (30 B): matches/0x000bff70.cpp
// sym: ??_G?$Method2@VCFEManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CFEManager, void>::~Closure0() {}


// 0x000bff90 Closure0<CFEManager,void>::vfunc_2 (11 B): matches/0x000bff90.cpp
// sym: ?vfunc_2@?$Closure0@VCFEManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CFEManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_bff90 * *)&this->f_20)->*(*(void (CActorManager_bff90::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<CFEManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbff70)
#endif


// 0x000bffa0 FUN_000bffa0 (76 B): matches/0x000bffa0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_000bffa0@@QAE@PBDPAVOwner_bffa0@1@P821@AEX0@Z@Z
namespace fn_000bffa0 {

// Closure1<Owner, void, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_bffa0 {};
typedef void (Owner_bffa0::*Fn_bffa0)(const char*);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char lookup_001d04d0(const void*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* n) : CtorV_001d0480(n, 1) { }
};
class Closure1_bffa0 : public Base {
  public:
    virtual bool Fnf_001d04c0(int, int);
    Fn_bffa0 name;
    Closure1_bffa0(const char*, Fn_bffa0);
};
class Closure1 : public Closure1_bffa0 {
  public:
    virtual void Fng_000c0010(void*, void*, void*);
    Owner_bffa0* p;
    Closure1(const char*, Owner_bffa0*, Fn_bffa0);
};
Closure1_bffa0::Closure1_bffa0(const char* n, Fn_bffa0 s) : Base(n) {
    name = s;
    retType = lookup_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = lookup_001d04d0(((int*)&DAT_0048e0f0));
}
Closure1::Closure1(const char* n, Owner_bffa0* v, Fn_bffa0 s) : Closure1_bffa0(n, s) {
    p = v;
}
} // namespace fn_000bffa0


// 0x000bfff0 Closure1<CFEManager,void,const_char_*>::vfunc_0 (30 B): matches/0x000bfff0.cpp
// sym: ??_G?$Method0@VCFEManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CFEManager, void, const char *>::~Closure1() {}


// 0x000c0010 Closure1<CFEManager,void,const_char_*>::vfunc_2 (18 B): matches/0x000c0010.cpp
// sym: ?vfunc_2@?$Closure1@VCFEManager@@XPAD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CFEManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_c0010 * *)&this->f_20)->*(*(void (CActorManager_c0010::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CFEManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xbfff0)
#endif


// 0x000c0030 FUN_000c0030 (89 B): matches/0x000c0030.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_000c0030@@QAE@PBDPAVOwner_0c0030@1@P821@AEX00@Z@Z
namespace fn_000c0030 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_004090e8[2];
extern void* hulk_at_004092e0[2];

// Closure2<Owner, void, const char*, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_0c0030 {};
typedef void (Owner_0c0030::*Fn_0c0030)(const char*, const char*);
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_0c0030 fn;            // 0x1c
    Owner_0c0030* owner;     // 0x20

    Closure2(const char* a1, Owner_0c0030* a2, Fn_0c0030 a3);
};

Closure2::Closure2(const char* a1, Owner_0c0030* a2, Fn_0c0030 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_004090e8;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_004092e0;
    owner = a2;
}
} // namespace fn_000c0030
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c0090 Closure2<CFEManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000c0090.cpp
// sym: ??_G?$Method1@VCFEManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CFEManager, void, const char *, const char *>::~Closure2() {}


// 0x000c00b0 Closure2<CFEManager,void,const_char_*,const_char_*>::vfunc_2 (22 B): matches/0x000c00b0.cpp
// sym: ?vfunc_2@?$Closure2@VCFEManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CFEManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_c00b0 * p = (Pair_c00b0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_c00b0 * *)&this->f_20)->*(*(void (CActorManager_c00b0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CFEManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xc0090)
#endif


// 0x000c0120 Closure7<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (73 B): matches/0x000c0120.cpp
// sym: ?vfunc_2@?$Closure7@VCFEManager@@XPBDPBDPBDPBDPBDPBDPBD@@UAEXPAX00@Z
template <> void Closure7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * p0 = (void *)__p0; void * p1 = (void *)__p1; void * p2 = (void *)__p2;

    Args* args = (Args*)p1;
    const char** a = args->values;
    const char* v0 = *a++;
    const char* v1 = *a++;
    const char* v2 = *a++;
    const char* v3 = *a++;
    const char* v4 = *a++;
    const char* v5 = *a++;
    const char* v6 = *a++;
    ((*(CFEManager_c0120 * *)&this->f_20)->*(*(void (CFEManager_c0120::**)(const char *, const char *, const char *, const char *, const char *, const char *, const char *))&this->f_1c))(v0, v1, v2, v3, v4, v5, v6);
}


// 0x000c01c0 Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (58 B): matches/0x000c01c0.cpp
// sym: ?vfunc_2@?$Closure6@VCFEManager@@XPBDPBDPBDPBDPBDPBD@@UAEXPAX00@Z
template <> void Closure6<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char ** a = (const char **)__p1;

    const char* t0 = take(a);
    const char* t1 = take(a);
    const char* t2 = take(a);
    const char* t3 = take(a);
    const char* t4 = take(a);
    const char* t5 = take(a);
    ((*(CFEManager_c01c0 * *)&this->f_20)->*(*(void (CFEManager_c01c0::**)(const char *, const char *, const char *, const char *, const char *, const char *))&this->f_1c))(t0, t1, t2, t3, t4, t5);
}


// 0x000c0200 FUN_000c0200 (89 B): matches/0x000c0200.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_000c0200@@QAE@PBDPAVOwner_0c0200@1@P821@AEX0H@Z@Z
namespace fn_000c0200 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
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


extern void* hulk_at_00409118[2];
extern void* hulk_at_00409310[2];

// Closure2<Owner, void, const char*, int>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_0c0200 {};
typedef void (Owner_0c0200::*Fn_0c0200)(const char*, int);
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_0c0200 fn;            // 0x1c
    Owner_0c0200* owner;     // 0x20

    Closure2(const char* a1, Owner_0c0200* a2, Fn_0c0200 a3);
};

Closure2::Closure2(const char* a1, Owner_0c0200* a2, Fn_0c0200 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00409118;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_00409310;
    owner = a2;
}
} // namespace fn_000c0200
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c0280 Closure2<CFEManager,void,const_char_*,int>::vfunc_2 (22 B): matches/0x000c0280.cpp
// sym: ?vfunc_2@?$Closure2@VCFEManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CFEManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_c0280 * p = (Pair_c0280 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_c0280 * *)&this->f_20)->*(*(void (CActorManager_c0280::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x000c0300 Closure0<CFEManager,int>::vfunc_2 (23 B): matches/0x000c0300.cpp
// sym: ?vfunc_2@?$Closure0@VCFEManager@@H@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CFEManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_c0300* obj = (*(CActorManager_c0300 * *)&this->f_20);
    int (CActorManager_c0300::*fn)() = (*(int (CActorManager_c0300::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}


// 0x000c0320 FUN_000c0320 (76 B): matches/0x000c0320.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_000c0320@@QAE@HHH@Z
namespace fn_000c0320 {
// data: str1 = DAT_0048e100, str2 = DAT_0048e134

class Function_c0320 {
  public:
    Function_c0320(int, int);
    virtual void f();
    char pad[12];
    char b10;
    char pad2[7];
    char b18;
    char pad3[3];
    int x1c;
};
extern "C++" __declspec(nothrow) int check_001d04d0(const char*);
class Method1 : public Function_c0320 {
  public:
    Method1(int a, int c) : Function_c0320(a, 1) {
        x1c = c;
        b18 = (char)check_001d04d0(((const char*)&DAT_0048e100));
        b10 = (char)check_001d04d0(((const char*)&DAT_0048e134));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int a, int b, int c);
    virtual void f();
    int x20;
};
Closure1::Closure1(int a, int b, int c) : Method1(a, c) {
    x20 = b;
}
} // namespace fn_000c0320


// 0x000c0390 Closure1<CFEManager,void,int>::vfunc_2 (18 B): matches/0x000c0390.cpp
// sym: ?vfunc_2@?$Closure1@VCFEManager@@XPAD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CFEManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_c0390 * *)&this->f_20)->*(*(void (CActorManager_c0390::**)(const char *))&this->f_1c))(*b);
}

namespace fn_f53c52ab {

// 0x000c04a0 FUN_000c04a0 (23 B): matches/0x000c04a0.cpp
// sym: ?Fn@A_c04a0@fn_f53c52ab@@QAEHHH@Z
int A_c04a0::Fn(int a, int b) {
    B_c04a0* q = p;
    if (q == 0)
        return -1;
    q->FnG_000bf160();
    return 0;
}


// 0x000c04c0 FUN_000c04c0 (31 B): matches/0x000c04c0.cpp
// sym: ?fn@Obj@fn_f53c52ab@@QAEHPAXH@Z
int Obj::fn(void* p, int unused) {
    if (!other)
        return -1;
    if (p)
        return -1;
    other->action_000bf1e0();
    return 0;
}


// 0x000c04e0 FUN_000c04e0 (31 B): matches/0x000c04e0.cpp
// sym: ?run@Outer@fn_f53c52ab@@QAEHPAXH@Z
int Outer::run(void* arg, int unused) {
    if (!inner)
        return -1;
    if (arg)
        return -1;
    inner->action_000bf260();
    return 0;
}

} // namespace fn_f53c52ab

// 0x000c0500 FUN_000c0500 (57 B): matches/0x000c0500.cpp [wrapped: conflict: atol]
// sym: ?run@Obj_c0500@fn_000c0500@@QAEJHPAPAD@Z
namespace fn_000c0500 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern long __cdecl atol(const char*);
#endif

struct Inner_c0500 {
    void call_000bf2b0(long);
};
struct Obj_c0500 {
    int pad;
    Inner_c0500* value;
    long run(int count, char** strings);
};
long Obj_c0500::run(int count, char** strings) {
    if (!value)
        return -1;
    long n = 0;
    if (count > 0)
        n = atol(*strings);
    value->call_000bf2b0(n);
    return 0;
}
} // namespace fn_000c0500


// 0x000c0540 FUN_000c0540 (68 B): matches/0x000c0540.cpp [wrapped: conflict: Target]
// sym: ?Func@Obj@fn_000c0540@@QAEHHPAPBD@Z
namespace fn_000c0540 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" long __cdecl atol(const char*);
#endif

class Target {
  public:
    void action_000bf450(const char*, long);
};
class Obj {
  public:
    char pad[4];
    Target* ptr;
    int Func(int n, const char** args);
};
int Obj::Func(int n, const char** args) {
    if (!ptr)
        return -1;
    if (n <= 0)
        return -1;
    const char* s = args[0];
    long v = 0;
    if (n > 1)
        v = atol(args[1]);
    ptr->action_000bf450(s, v);
    return 0;
}
} // namespace fn_000c0540


// 0x000c0590 FUN_000c0590 (57 B): matches/0x000c0590.cpp [wrapped: conflict: atol]
// sym: ?run@Obj_c0590@fn_000c0590@@QAEJHPAPAD@Z
namespace fn_000c0590 {
// Same code shape as 0x000c0500 (propagated; names are from that function)

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern long __cdecl atol(const char*);
#endif

struct Inner_c0590 {
    void call_000bf4e0(long);
};
struct Obj_c0590 {
    int pad;
    Inner_c0590* value;
    long run(int count, char** strings);
};
long Obj_c0590::run(int count, char** strings) {
    if (!value)
        return -1;
    long n = 0;
    if (count > 0)
        n = atol(*strings);
    value->call_000bf4e0(n);
    return 0;
}
} // namespace fn_000c0590

namespace fn_f53c52ab {

// 0x000c05d0 FUN_000c05d0 (28 B): matches/0x000c05d0.cpp
// sym: ?Run@Obj@fn_f53c52ab@@QAEHHH@Z
int Obj::Run(int a, int b) {
    if (!inner)
        return -1;
    inner->Step_000bf560();
    Finish_000fc300();
    return 0;
}


// 0x000c05f0 FUN_000c05f0 (54 B): matches/0x000c05f0.cpp
// sym: ?target@fn_f53c52ab@@YIHPAVC_c05f0@1@HHPAPBD@Z
int __fastcall target(C_c05f0* self, int, int arg, const char** text) {
    if (self->value == 0)
        return -1;
    if (arg != 1)
        return -1;
    long n = atol(*text);
    self->value->set_000bf5c0(n);
    return 0;
}

} // namespace fn_f53c52ab

// 0x000c0630 FUN_000c0630 (89 B): matches/0x000c0630.cpp [wrapped: conflict: DAT_0049dba4]
// sym: ?Handle@Handler_c0630@fn_000c0630@@QAEHHPAPAUObj_c0630@2@@Z
namespace fn_000c0630 {
struct Obj_c0630 {
    char pad[0x158];
    int id;
};
struct Mgr_c0630 {
    void Set_000bfa10(int, int);
};
struct Handler_c0630 {
    char pad[4];
    Mgr_c0630* mgr;
    int Handle(int, Obj_c0630**);
};
extern "C" void* __cdecl FUN_000fc260(void*);
extern "C" Obj_c0630* __cdecl FUN_00344e74(void*, void*, void*, void*, int);
extern char DAT_0049dba4, DAT_0049faf4;
int Handler_c0630::Handle(int msg, Obj_c0630** arg) {
    if (mgr && msg == 1) {
        Obj_c0630* v = *arg;
        Obj_c0630* q = FUN_00344e74(FUN_000fc260(v), 0, &DAT_0049dba4, &DAT_0049faf4, 0);
        if (q) {
            mgr->Set_000bfa10(q->id, 1);
            return 0;
        }
    }
    return -1;
}
} // namespace fn_000c0630

namespace fn_f53c52ab {

// 0x000c06e0 FUN_000c06e0 (83 B): equivalent/0x000c06e0.cpp
// sym: ?FUN_000c06e0@Registry_c06e0@fn_f53c52ab@@QAEXPBDPAVCFEManager_c06e0@2@P832@AEX0000HH@Z@Z @4eda6d6ca48d @w6e59540c635b
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000c06e0 @ 0x000c06e0
// FUN_000c06e0 @ 0x000c06e0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_c06e0::FUN_000c06e0(const char* a1, CFEManager_c06e0* a2, Fn_c06e0 a3) {
    typedef Closure6_c06e0<CFEManager_c06e0, void, const char*, const char*, const char*, const char*, int, int> Alloc_c06e0;
    HULK_SIZE32(Alloc_c06e0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_c06e0));
    void* x = 0;
    if (m) {
        ((Raw_c06e0*)m)->FUN_000be5c0(a1, a3);
        x = new (m) Closure6_c06e0<CFEManager_c06e0, void, const char*, const char*, const char*, const char*, int, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f53c52ab

// 0x000c0740 FUN_000c0740 (109 B): equivalent/0x000c0740.cpp [wrapped: conflict: CFEManager; Closure0; Method0]
// sym: ?FUN_000c0740@Registry_c0740@fn_000c0740@@QAEXPBDPAVCFEManager@2@P832@AEXXZ@Z @782e2d892bf7 @wed015ba76295
namespace fn_000c0740 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000c0740 @ 0x000c0740
// FUN_000c0740 @ 0x000c0740  (generated by work/closure/gen.py)
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


class CFEManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_c0740 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_c0740(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_c0740 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_c0740(name, 0) {
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

struct Registry_c0740 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000c0740(const char* name, CFEManager* owner, void (CFEManager::*fn)());
};

void Registry_c0740::FUN_000c0740(const char* name, CFEManager* owner, void (CFEManager::*fn)()) {
    typedef Closure0<CFEManager, void> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CFEManager, void>));
    Closure0<CFEManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CFEManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000c0740
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f53c52ab {

// 0x000c0850 FUN_000c0850 (83 B): equivalent/0x000c0850.cpp
// sym: ?FUN_000c0850@Registry_c0850@fn_f53c52ab@@QAEXPBDPAVCFEManager_c0850@2@P832@AEX0000000@Z@Z @a01c91ed61b6 @wd8834da2d617
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000c0850 @ 0x000c0850
// FUN_000c0850 @ 0x000c0850  (generated by tools/equiv_gen/reg_helper.py)
void Registry_c0850::FUN_000c0850(const char* a1, CFEManager_c0850* a2, Fn_c0850 a3) {
    typedef Closure7_c0850<CFEManager_c0850, void, const char*, const char*, const char*, const char*, const char*, const char*, const char*> Alloc_c0850;
    HULK_SIZE32(Alloc_c0850, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_c0850));
    void* x = 0;
    if (m) {
        ((Raw_c0850*)m)->FUN_000be840(a1, a3);
        x = new (m) Closure7_c0850<CFEManager_c0850, void, const char*, const char*, const char*, const char*, const char*, const char*, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000c08b0 FUN_000c08b0 (83 B): equivalent/0x000c08b0.cpp
// sym: ?FUN_000c08b0@Registry_c08b0@fn_f53c52ab@@QAEXPBDPAVCFEManager_c08b0@2@P832@AEX000000@Z@Z @baf52c5ef980 @wc429d72ca8c0
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000c08b0 @ 0x000c08b0
// FUN_000c08b0 @ 0x000c08b0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_c08b0::FUN_000c08b0(const char* a1, CFEManager_c08b0* a2, Fn_c08b0 a3) {
    typedef Closure6_c08b0<CFEManager_c08b0, void, const char*, const char*, const char*, const char*, const char*, const char*> Alloc_c08b0;
    HULK_SIZE32(Alloc_c08b0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_c08b0));
    void* x = 0;
    if (m) {
        ((Raw_c08b0*)m)->FUN_000be950(a1, a3);
        x = new (m) Closure6_c08b0<CFEManager_c08b0, void, const char*, const char*, const char*, const char*, const char*, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f53c52ab

// 0x000c0960 FUN_000c0960 (109 B): equivalent/0x000c0960.cpp [wrapped: conflict: CFEManager; Closure0; Method0]
// sym: ?FUN_000c0960@Registry_c0960@fn_000c0960@@QAEXPBDPAVCFEManager@2@P832@AEHXZ@Z @8b0c1f78521e @w25104c649a85
namespace fn_000c0960 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000c0960 @ 0x000c0960
// FUN_000c0960 @ 0x000c0960  (generated by work/closure/gen.py)
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


class CFEManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_c0960 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_c0960(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_c0960 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_c0960(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_c0960 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000c0960(const char* name, CFEManager* owner, int (CFEManager::*fn)());
};

void Registry_c0960::FUN_000c0960(const char* name, CFEManager* owner, int (CFEManager::*fn)()) {
    typedef Closure0<CFEManager, int> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CFEManager, int>));
    Closure0<CFEManager, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<CFEManager, int>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000c0960
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f53c52ab {

// 0x000c0d80 FUN_000c0d80 (42 B): matches/0x000c0d80.cpp
// sym: _FUN_000c0d80
extern "C" hulk_intptr FUN_000c0d80(Obj_c0d80* p, hulk_intptr b) {
    unsigned long long x = Get_0027b020((void*)b);
    struct Local {
        void* v;
    };
    Local local;
    local.v = (void*)((hulk_intptr)DAT_003fef7c);
    return p->f3(&local, x);
}


// 0x000c0db0 FUN_000c0db0 (42 B): matches/0x000c0db0.cpp
// sym: _FUN_000c0db0
extern "C" hulk_intptr FUN_000c0db0(Inventory* inv, const char* name) {
    unsigned __int64 s = findShader_0027b020(name);
    DynamicCaster_c0db0 caster;
    return inv->load(&caster, s);
}


// 0x000c0de0 FUN_000c0de0 (42 B): matches/0x000c0de0.cpp
// sym: _FUN_000c0de0
extern "C" hulk_intptr FUN_000c0de0(Obj* obj, Obj* value) {
    __int64 a = helper_0027b020(value);
    DynamicCaster_c0de0 caster;
    return obj->f3(&caster, a);
}

} // namespace fn_f53c52ab

// 0x000c1ac0 FUN_000c1ac0 (138 B): equivalent/0x000c1ac0.cpp [wrapped: conflict: FUN_0027b020; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?ShowDecryptBar@fn_000c1ac0@@YAXXZ @d426c66ac12c @wb7c0c84a4cd4
namespace fn_000c1ac0 {
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 4/4)
// FUN_000c1ac0 @ 0x000c1ac0

namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase { public: virtual void cast(void* p); };
template <class T> class DynamicCaster : public DynamicCasterBase { public: virtual void cast(void* p); };
} }
namespace pure3d { class CompositeDrawable; }
extern char DAT_0049dba4[];
extern char DAT_0049f48c[];
void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
void* __cdecl FUN_000fc260(const char* name);
extern "C" int __cdecl FUN_000fc1b0();
struct Id_c1ac0 { unsigned lo, hi; };
Id_c1ac0 __cdecl FUN_0027b020(const char* s);
struct Label_c1ac0 { void FUN_000f8500(const char* text, int a, int b); };
struct Element_c1ac0 { char pad[0x18]; Label_c1ac0 label; };
class Drawable {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(float t, int flag); virtual void v7(); virtual void v8();
    virtual void v9();
};
class Inventory_c1ac0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Drawable* Find(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>* caster, unsigned lo, unsigned hi);
};
void ShowDecryptBar() {
    Element_c1ac0* e = (Element_c1ac0*)FUN_00344e74(FUN_000fc260("dycrypting_sequence_text"), 0, DAT_0049dba4, DAT_0049f48c, 0);
    if (e)
        e->label.FUN_000f8500("", FUN_000fc1b0(), 1);
    Inventory_c1ac0* inv = (*(Inventory_c1ac0**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Id_c1ac0 id = FUN_0027b020("decryptingProgressBar");
    Drawable* d = inv->Find(&caster, id.lo, id.hi);
    if (d) {
        d->v9();
        d->v6(10.0f, 0);
    }
}
} // namespace fn_000c1ac0


// 0x000c1ed0 FUN_000c1ed0 (42 B): matches/0x000c1ed0.cpp [wrapped: conflict: Target]
// sym: _FUN_000c1ed0
namespace fn_000c1ed0 {
struct DynamicCasterVtable {
    char unused;
};
extern DynamicCasterVtable DAT_00409148;
extern unsigned __int64 __cdecl FUN_0027b020(void*);
struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(void*, unsigned, unsigned);
};
extern "C" int __cdecl FUN_000c1ed0(Target* target, void* resource) {
    unsigned __int64 result = FUN_0027b020(resource);
    DynamicCasterVtable* caster = &DAT_00409148;
    return target->slot3(&caster, (unsigned)result, (unsigned)(result >> 32));
}
} // namespace fn_000c1ed0

namespace fn_f53c52ab {

// 0x000c1f00 FUN_000c1f00 (37 B): matches/0x000c1f00.cpp
// sym: ?Run@Obj_c1f00@fn_f53c52ab@@QAEHHPAH@Z
int Obj_c1f00::Run(int flag, int* p) {
    if (!mSub)
        return -1;
    if (flag != 1)
        return -1;
    mSub->Fn_000c1790(*p);
    return 0;
}


// 0x000c1f30 FUN_000c1f30 (23 B): matches/0x000c1f30.cpp
// sym: ?F@Obj_c1f30@fn_f53c52ab@@QAEHHH@Z
int Obj_c1f30::F(int a, int b) {
    if (!m)
        return -1;
    m->FnG_000c1ac0();
    return 0;
}


// 0x000c1f50 CFEManager::vfunc_0 (30 B): matches/0x000c1f50.cpp
// sym: ?vfunc_2@CFEManager_c1f50@fn_f53c52ab@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CFEManager_c1f50* CFEManager_c1f50::vfunc_2(unsigned char flags) {
    ((CFEManager_nv_c1f50*)(((CFEManager*)(this))))->FUN_000c1430();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000c2b90 FUN_000c2b90 (118 B): matches/0x000c2b90.cpp
// sym: ?Handle@Holder_c2b90@fn_f53c52ab@@QAEHHPAH@Z
int Holder_c2b90::Handle(int a, int* p) {
    if (mT && a == 1) {
        int x = *p;
        Obj_c2b90* o = ((Obj_c2b90 *)__RTDynamicCast(Cast_000fc260(x), 0, (void*)(hulk_at_0049dba4), (void*)(hulk_at_0049faf4), 0));
        if (o) {
            int v = o->mVal;
            mT->FnA_000bfa10(v, 0);
            mT->FnB_000b64f0();
            mT->FnC_000b63a0();
            mT->FnD_000c21b0(0x266);
            return 0;
        }
    }
    return -1;
}

// 0x000c2c10 thunk_FUN_000c21b0 (5 B): not yet verified
} // namespace fn_f53c52ab

// 0x000c3ce0 FUN_000c3ce0 (206 B): matches/0x000c3ce0.cpp
// sym: ?FUN_000c3ce0@Object_c3ce0@owners@@QAEXXZ
void owners::Object_c3ce0::FUN_000c3ce0() {
    if (!enabled)
        return;
    FUN_000c21b0(0);
    FUN_000c21b0(0x34);
    FUN_000c21b0(0x52);
    FUN_000c21b0(0x5c);
    FUN_000c21b0(0x66);
    FUN_000c21b0(0x70);
    FUN_000c21b0(0x7a);
    FUN_000c21b0(0x84);
    FUN_000c21b0(0x1bf);
    FUN_000c21b0(0x1f1);
    FUN_000c21b0(0x20a);
    FUN_000c21b0(0x22e);
    FUN_000c21b0(0x244);
    FUN_000c21b0(0x248);
    FUN_000c21b0(0x258);
    FUN_000c21b0(0x261);
    FUN_000c21b0(0x266);
    FUN_000c21b0(0x1d);
}

namespace fn_f53c52ab {

// 0x000c3db0 FUN_000c3db0 (148 B): matches/0x000c3db0.cpp
// sym: ?FUN_000c3db0@Screen_c3db0@fn_f53c52ab@@QAEXXZ
// FUN_000c3db0 @ 0x000c3db0
void Screen_c3db0::FUN_000c3db0() {
    CUnlockableGallery_c3db0* g = dynamic_cast<CUnlockableGallery_c3db0*>(((CUnlockable_c3db0 *)((owners::C_92ad0 *)items)->FUN_00092ad0((hulk_intptr)selected)));
    if (g == 0)
        return;
    if (FUN_000c3900(g->FUN_00092330(), DAT_0049fb34, DAT_0049fb38, 1, g->FUN_00092320(), 0, 1000)) {
        flag1a04 = 0;
        flag1878 = 1;
        field10 = 0;
        ((owners::Target_92360 *)g)->FUN_00092360(0);
        FUN_000ba040();
        field1a08 = 0;
    }
}


// 0x000c3e50 FUN_000c3e50 (23 B): matches/0x000c3e50.cpp
// sym: ?fn@Obj@fn_f53c52ab@@QAEHHH@Z
int Obj::fn(int a, int b) {
    if (!child)
        return -1;
    child->act_000c2c20();
    return 0;
}


// 0x000c3e70 FUN_000c3e70 (37 B): matches/0x000c3e70.cpp
// sym: ?Fn@C_000c3e70@fn_f53c52ab@@QAEHIPAH@Z
int C_000c3e70::Fn(uint_000c3e70 a, int* b) {
    Helper* p = mPtr;
    if (!p)
        return -1;
    if (a != 1)
        return -1;
    int x = *b;
    mPtr->Fn_000c31e0(x);
    return 0;
}

} // namespace fn_f53c52ab

// 0x000c3ea0 FUN_000c3ea0 (337 B): matches/0x000c3ea0.cpp [wrapped: conflict: FUN_000fc260]
// sym: ?FUN_000c3ea0@Screen_c3ea0@fn_000c3ea0@@QAEXXZ
namespace fn_000c3ea0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_000c3ea0 @ 0x000c3ea0
extern char DAT_0049dba4[];
extern char DAT_0049dbbc[];
extern char DAT_0049f4a4[];

struct Widget;
extern Widget* __cdecl FUN_000fc260(const char* name);
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern "C" bool FUN_00035da0();

class Selector_c3ea0 {
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
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int value);
};
struct Flag_c3ea0 {
    char pad[5];
    unsigned char value;
};
struct Button_c3ea0 {
    char pad[0x74];
    unsigned char f74;
    char pad75[0x141 - 0x75];
    unsigned char f141;
};
struct Panel_c3ea0 {
};
struct Inner_c3ea0 {
    void FUN_000adc30();
};
struct Holder_c3ea0 {
};
class Screen_c3ea0 {
  public:
    char pad[0x34];
    Panel_c3ea0* panel;
    char pad38[0x44 - 0x38];
    Flag_c3ea0* flag;
    char pad48[0x60 - 0x48];
    Holder_c3ea0* holder;
    void FUN_000b5ad0();
    void FUN_000b5b90();
    void FUN_000b63a0();
    void FUN_000b64f0();
    void FUN_000b7660();
    void FUN_000b7cd0();
    void FUN_000b8240();
    void FUN_000b86b0();
    void FUN_000b8860();
    void FUN_000b9930();
    void FUN_000b9ad0();
    void FUN_000b9bf0();
    void FUN_000ba040();
    void FUN_000bb600();
    void FUN_000c21b0(int id);
    void FUN_000c3ea0();
};
void Screen_c3ea0::FUN_000c3ea0() {
    Selector_c3ea0* vibration = (Selector_c3ea0*)FUN_00344e74(FUN_000fc260("control_config_vibration_selector"), 0,
                                                  DAT_0049dba4, DAT_0049dbbc, 0);
    if (vibration && flag)
        vibration->vfunc_25(flag->value == 0);
    FUN_000b5ad0();
    Selector_c3ea0* targeting =
        (Selector_c3ea0*)FUN_00344e74(FUN_000fc260("targeting_selector"), 0, DAT_0049dba4, DAT_0049dbbc, 0);
    if (targeting) {
        int off = FUN_00035da0() == 0;
        targeting->vfunc_25(off);
    }
    ((Inner_c3ea0 *)((owners::C_b3ec0 *)holder)->FUN_000b3ec0(0))->FUN_000adc30();
    ((owners::Object_c3ce0 *)this)->FUN_000c3ce0();
    FUN_000b9930();
    FUN_000b5b90();
    FUN_000b9ad0();
    FUN_000b9bf0();
    FUN_000b63a0();
    FUN_000b64f0();
    FUN_000b7660();
    FUN_000bb600();
    FUN_000c21b0(0x266);
    FUN_000c21b0(0x34);
    FUN_000b7cd0();
    FUN_000b8240();
    FUN_000b86b0();
    Button_c3ea0* replay =
        (Button_c3ea0*)FUN_00344e74(FUN_000fc260("replay_story_mode_button"), 0, DAT_0049dba4, DAT_0049f4a4, 0);
    if (panel && replay) {
        unsigned char v = ((owners::Target_893c0 *)panel)->FUN_000893c0();
        replay->f141 = v;
        replay->f74 = v;
    }
    FUN_000b8860();
    FUN_000ba040();
}
} // namespace fn_000c3ea0

namespace fn_f53c52ab {

// 0x000c4000 FUN_000c4000 (28 B): matches/0x000c4000.cpp
// sym: ?F@Target_c4000@fn_f53c52ab@@QAEHHH@Z
int Target_c4000::F(int a, int b) {
    obj->sub->FnF_00094590();
    obj->FnG_000c3ea0();
    return 0;
}


// 0x000c43a0 FUN_000c43a0 (2833 B): matches/0x000c43a0.cpp
// sym: ?ctor@CFrontEndCallback_c43a0@fn_f53c52ab@@QAEPAV12@PAX@Z
CFrontEndCallback_c43a0* CFrontEndCallback_c43a0::ctor(void* arg) {
    vptr = gV;
    m4 = arg;
    FUN_000fc1e0("Print", new H0_c43a0(this, (void*)Mb45e0_000b45e0));
    FUN_000fc1e0("SetDifficulty", new H0_c43a0(this, (void*)Mbbb40_000bbb40));
    FUN_000fc1e0("ResetDifficultySelectScreen", new H0_c43a0(this, (void*)Mc04a0_000c04a0));
    FUN_000fc1e0("ResetGame", new H0_c43a0(this, (void*)Mc04c0_000c04c0));
    FUN_000fc1e0("ReplayStoryMode", new H0_c43a0(this, (void*)Mc04e0_000c04e0));
    FUN_000fc1e0("StartGame", new H0_c43a0(this, (void*)Mbecd0_000becd0));
    FUN_000fc1e0("StartNextMission", new H0_c43a0(this, (void*)Mbef60_000bef60));
    FUN_000fc1e0("ReturnToNullMission", new H0_c43a0(this, (void*)Mc0500_000c0500));
    FUN_000fc1e0("ExitSim", new H0_c43a0(this, (void*)Mc0540_000c0540));
    FUN_000fc1e0("RestartSim", new H0_c43a0(this, (void*)Mc0590_000c0590));
    FUN_000fc1e0("Continue", new H0_c43a0(this, (void*)Mc05d0_000c05d0));
    FUN_000fc1e0("SaveGame", new H0_c43a0(this, (void*)Mbbb80_000bbb80));
    FUN_000fc1e0("ChangeLocale", new H0_c43a0(this, (void*)Mc1f00_000c1f00));
    FUN_000fc1e0("JumpMarkerSelected", new H0_c43a0(this, (void*)Mbbb90_000bbb90));
    FUN_000fc1e0("JumpMarkerSelectionCancelled", new H0_c43a0(this, (void*)Mbbbb0_000bbbb0));
    FUN_000fc1e0("ResetJumpMarkers", new H0_c43a0(this, (void*)Mbbc00_000bbc00));
    FUN_000fc1e0("AwardCheatersSmashPoints", new H0_c43a0(this, (void*)Mbbc20_000bbc20));
    FUN_000fc220("VideoBrightnessChanged", new H1(this, (void*)Mbbc50_000bbc50));
    FUN_000fc200("TargetingLockChanged", new H2_c43a0(this, (void*)Mbbc90_000bbc90));
    FUN_000fc220("AudioDialogueVolumeChanged", new H1(this, (void*)Mbbcb0_000bbcb0));
    FUN_000fc220("AudioMusicVolumeChanged", new H1(this, (void*)Mbbcd0_000bbcd0));
    FUN_000fc220("AudioSoundEffectsVolumeChanged", new H1(this, (void*)Mbbcf0_000bbcf0));
    FUN_000fc200("AudioQualityChanged", new H2_c43a0(this, (void*)Mbbd10_000bbd10));
    FUN_000fc200("SubtitlesChanged", new H2_c43a0(this, (void*)Mbbd30_000bbd30));
    FUN_000fc200("ControlConfigVibrationChanged", new H2_c43a0(this, (void*)Mbbd60_000bbd60));
    FUN_000fc200("CameraInvertXChanged", new H2_c43a0(this, (void*)Mbbd80_000bbd80));
    FUN_000fc200("CameraInvertYChanged", new H2_c43a0(this, (void*)Mbbda0_000bbda0));
    FUN_000fc200("CheatGrayHulkChanged", new H2_c43a0(this, (void*)Mbbdc0_000bbdc0));
    FUN_000fc200("CheatInvulnerabilityChanged", new H2_c43a0(this, (void*)Mbbdf0_000bbdf0));
    FUN_000fc200("CheatAllMovesChanged", new H2_c43a0(this, (void*)Mbbe20_000bbe20));
    FUN_000fc200("MissionSelectedChanged", new H2_c43a0(this, (void*)Mbbef0_000bbef0));
    FUN_000fc1e0("DoSaveScreens", new H0_c43a0(this, (void*)Mbbf00_000bbf00));
    FUN_000fc1e0("DoUnlockable", new H0_c43a0(this, (void*)Mc3e70_000c3e70));
    FUN_000fc1e0("BackScreen", new H0_c43a0(this, (void*)Mb45f0_000b45f0));
    FUN_000fc1e0("SetUpMoveDescScreen", new H0_c43a0(this, (void*)Mc3e50_000c3e50));
    FUN_000fc1e0("UpdateStoryRecap", new H0_c43a0(this, (void*)Mbc060_000bc060));
    FUN_000fc1e0("DoUnlockChapterMoves", new H0_c43a0(this, (void*)Mc05f0_000c05f0));
    FUN_000fc1e0("DoFECodeInput", new H0_c43a0(this, (void*)Mc2b90_000c2b90));
    FUN_000fc1e0("DoSimCodeInput", new H0_c43a0(this, (void*)Mc0630_000c0630));
    FUN_000fc1e0("DoFullscreenAnswer", new H0_c43a0(this, (void*)Mbbf20_000bbf20));
    FUN_000fc1e0("UnlockAllBonus", new H0_c43a0(this, (void*)Mc4000_000c4000));
    FUN_000fc1e0("ClearScreenHistory", new H0_c43a0(this, (void*)Mb4610_000b4610));
    FUN_000fc1e0("StartFE", new H0_c43a0(this, (void*)Mbc080_000bc080));
    FUN_000fc1e0("UpdateCheatsScreen", new H0_c43a0(this, (void*)Mbc0b0_000bc0b0));
    FUN_000fc1e0("ApplyCheatsSettings", new H0_c43a0(this, (void*)Mbc0d0_000bc0d0));
    FUN_000fc1e0("EnterBlonskyFile", new H0_c43a0(this, (void*)Mbbeb0_000bbeb0));
    FUN_000fc1e0("UpdateControlButtonString", new H0_c43a0(this, (void*)Mbef80_000bef80));
    FUN_000fc1e0("UpdateVibrationTextControl", new H0_c43a0(this, (void*)Mbbed0_000bbed0));
    FUN_000fc1e0("UpdateSimAudioWidgets", new H0_c43a0(this, (void*)Mbc0a0_000bc0a0));
    FUN_000fc1e0("InitMUCheck", new H0_c43a0(this, (void*)Mbc0f0_000bc0f0));
    FUN_000fc1e0("TriggerAnimationSound", new H0_c43a0(this, (void*)Mbbe50_000bbe50));
    FUN_000fc1e0("DialogSelectionChanged", new H0_c43a0(this, (void*)Mbbe90_000bbe90));
    FUN_000fc200("BlonskyFileSelectedChanged", new H2_c43a0(this, (void*)Mbbf60_000bbf60));
    FUN_000fc1e0("ResetDecryptingSequence", new H0_c43a0(this, (void*)Mc1f30_000c1f30));
    FUN_000fc1e0("PlayBlonskyFileDialogue", new H0_c43a0(this, (void*)Mbbf70_000bbf70));
    FUN_000fc1e0("UpdateMissionBriefingScreen", new H0_c43a0(this, (void*)Mbbfa0_000bbfa0));
    FUN_000fc1e0("UpdateMissionObjectivesScreen", new H0_c43a0(this, (void*)Mbc010_000bc010));
    FUN_000fc1e0("UpdateHintScreen", new H0_c43a0(this, (void*)Mbbfd0_000bbfd0));
    FUN_000fc1e0("UpdateSmartHintScreen", new H0_c43a0(this, (void*)Mbbff0_000bbff0));
    FUN_000fc200("BuyableMoveSelectedChanged", new H2_c43a0(this, (void*)FUN_000bc030));
    FUN_000fc200("EnabledMoveSelectedChanged", new H2_c43a0(this, (void*)FUN_000bc040));
    FUN_000fc200("JumpMarkerSelectedChanged", new H2_c43a0(this, (void*)Mbc050_000bc050));
    return this;
}

} // namespace fn_f53c52ab
