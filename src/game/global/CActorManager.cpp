// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8e68f21 {
#define TREE_TU_END }
namespace fn_f8e68f21 {} using namespace fn_f8e68f21;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8e68f21 {
class Function_2c510 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_2c510 {
  public:
    bool (CActorManager_2c510::*m)(const char*, bool);
};
struct Pair_2c510 {
    const char* p;
    bool b;
};
class CFEManager_2c650 {
  public:
    void Call(const char*, int);
};
class Function_2c650 {
  public:
    virtual void f0();
    virtual void f1();
};
class CFEManager_2c6e0 {
  public:
    void Call(const char*, int);
};
class Function_2c6e0 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_2c760;
typedef float (CActorManager_2c760::*Fn_2c760)(const char*);
class CActorManager_2c760 {
  public:
    float Get(const char* s);
};
class CActorManager_2c7f0 {
  public:
    bool action(const char*);
};
class Function_2c7f0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager_2c7f0*, const char**, bool*);
};
struct CActorManager_2c890 { void FUN_0002c890(const char *, float, bool); };
struct CallArguments { const char *text; float value; bool enabled; };
class CActorManager_2c9b0 {
  public:
    int Do(const char*);
    inline int Invoke(int (CActorManager_2c9b0::*f)(const char*), const char* p) { return (this->*f)(p); }
};
class Function_2c9b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager_2c9b0*, const char**, int*);
};
class CActorManager_2ca30 {
  public:
    const char* Run(const char*);
};
class Function_2ca30 {
  public:
    virtual void v0();
    virtual void v1();
};
struct Function_2caf0 {
    virtual void f0();
    virtual void f1();
};
void FUN_0002cb10(const char*, const char*, const char*, int);
class Obj {
  public:
    char Method(int, int, int, int, char, int);
};
typedef char (Obj::*Fn)(int, int, int, int, char, int);
extern "C" char DAT_003f40dc[];
extern "C" char DAT_0048e10c[];
struct ThisCall_001d0480 {
  public:
    void FUN_001d0480(const char*, int);
    void InitHelper_001d0480(const char*, int);
};
class Owner_2cb60 {};
typedef void (Owner_2cb60::*Fn_2cb60)();
class Method7_2cb60 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_2cb60 func;
    Method7_2cb60* Init(const char* name, Fn_2cb60 fn);
};
struct Function_2cc10 {
    virtual void f0();
    virtual void f1();
};
void FUN_0002cc30(const char*, const char*, const char*, int);
struct Triple_2cc30 {
    int a, b, c;
};
class Target_2cc30 {
public:
    unsigned char Method(int a0, Triple_2cc30 t, int a4, int a5, int a6, unsigned int flagWord, int a8);
};
typedef unsigned char (Target_2cc30::*Fn_2cc30)(int, Triple_2cc30, int, int, int, unsigned int, int);
struct Block_2cc30 {
    int a0;
    Triple_2cc30 t;
    int a4;
    int a5;
    int a6;
    unsigned char flag;
    char pad[3];
    int a8;
};
union BlockArg {
    Block_2cc30* block;
    unsigned char flag;
    unsigned int word;
};
class CFEManager_2cdb0 {
  public:
    void Call(const char*, int);
};
class Function_2cdb0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_2ce30 {
  public:
    void Call(void*);
};
class Function_2ceb0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Function_2cf30 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_2cfb0 {
  public:
    int Act(const char*);
};
class Function_2cfb0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_2d040 {
  public:
    char Act(const char*, const char*);
};
class Function_2d040 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class CFEManager_2d0e0 {
  public:
    void Call(const char*, int);
};
class Function_2d0e0 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_2d210 {
  public:
    void Call(void*);
};
struct Vec_2d290 {
    int x, y, z;
};
class Actor_2d290 {
  public:
    bool Invoke(Vec_2d290 v);
};
typedef bool (Actor_2d290::*ActorFn_2d290)(Vec_2d290);
struct Vec_2d330 {
    unsigned x, y, z;
};
class CActorManager_2d330 {
  public:
    int Act(Vec_2d330 v);
};
typedef int (CActorManager_2d330::*ActFn_2d330)(Vec_2d330);
class Function_2d330 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_003f41ac[];
class Owner_2d370 {};
typedef void (Owner_2d370::*Fn_2d370)();
class Method7_2d370 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_2d370 func;
    Method7_2d370* Init(const char* name, Fn_2d370 fn);
};
struct Function_2d420 {
    virtual void f0();
    virtual void f1();
};
void FUN_0002d440(const char*, const char*, const char*, int);
class CFEManager_2d510 {
  public:
    void Call(const char*, int);
};
class Function_2d510 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_2d640 {
  public:
    bool Method(const char*, int);
};
class Function_2d640 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
};
class CActorManager_2d6d0 {
  public:
    bool Act(int);
};
class Function_2d6d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_2d750;
typedef unsigned char(__fastcall* Fn_2d750)(CActorManager_2d750*);
extern "C" char DAT_003f420c[];
class Owner_2d770 {};
typedef void (Owner_2d770::*Fn_2d770)();
class Method4_2d770 {
  public:
    void* vt;
    ScriptFunctionFields f;
    Fn_2d770 m1c;
    Method4_2d770(const char*, Fn_2d770);
};
struct CActorManager_2d800 {
    char unused;
};
extern "C" char DAT_003f421c[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Owner_2d830 {};
typedef void (Owner_2d830::*Fn_2d830)();
class Method4_2d830 : public FUN_001d0480 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_2d830 m1c;
    Method4_2d830(const char*, Fn_2d830);
};
class CActorManager_2d950 {
  public:
    void f();
};
struct Function_2da00 {
    virtual void f0();
    virtual void f1();
};
void FUN_0002da20(const char*, const char*, const char*, int);
extern "C" char DAT_003f424c[];
class Owner_2da60 {};
typedef void (Owner_2da60::*Fn_2da60)();
class Method3_2da60 {
  public:
    void* vf;
    ScriptFunctionFields f;
    Fn_2da60 m1c;
    void Init_001d0480(const char*, int);
    Method3_2da60(const char*, Fn_2da60);
};
extern "C" char DAT_003f425c[];
class Owner_2db20 {};
typedef void (Owner_2db20::*Fn_2db20)();
class Method3_2db20 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_2db20 member1c;
    Method3_2db20* Init(const char*, Fn_2db20);
};
extern int hulk_at_003f427c;
struct Function_2dc60 {
    Function_2dc60(const char*, int);
};
class Owner_2dc60 {};
typedef void (Owner_2dc60::*Fn_2dc60)();
struct Method3_2dc60 : Function_2dc60 {
    void* vftable;
    ScriptFunctionFields f;
    Fn_2dc60 field1c;
    Method3_2dc60(const char*, Fn_2dc60);
};
extern "C" char DAT_003f428c[];
class Owner_2dd00 {};
typedef void (Owner_2dd00::*Fn_2dd00)();
class Method4_2dd00 : public FUN_001d0480 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_2dd00 m1c;
    Method4_2dd00(const char*, Fn_2dd00);
};
class CActorManager_2ded0 {
  public:
    int Run(const char*, const char*);
};
struct Function_2ded0 {
    virtual void f0();
    virtual void f1();
    virtual void f2(CActorManager_2ded0*, const char**, int*);
};
class Dummy_2e000 {
  public:
    void Call(void*);
};
struct Vector_2e120 { float x, y, z; };
class CActorManager_2e120 {
public:
    Vector_2e120 Call(Vector_2e120 arg, float scale);
};
struct CallParams {
    Vector_2e120 arg;           // 0x00
    float scale;          // 0x0c
};
typedef Vector_2e120 (CActorManager_2e120::*VectorMethod)(Vector_2e120, float);
class CActorManager_2e200 {
  public:
    float Method(const char*, const char*);
};
struct Args {
    const char* a;
    const char* b;
};
typedef float (CActorManager_2e200::*MemFn)(const char*, const char*);
class Function_2e200 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class CActorManager_2e290 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_2e290::*MFn_2e290)(unsigned char);
class Function_2e290 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_003f431c[];
class Function_2e2b0 {
  public:
    Function_2e2b0(int, int);
};
class Method3_2e2b0 : public Function_2e2b0 {
  public:
    hulk_intptr v;
    char pad[0x18];
    int m1c;
    Method3_2e2b0(hulk_intptr, hulk_intptr);
};
} // namespace fn_f8e68f21
namespace math {
struct Vector_2e3d0 {
    float x, y, z;
};
}
namespace fn_f8e68f21 {
class CActorManager_2e3d0 {
public:
    bool Dummy(const char* name, math::Vector_2e3d0 a, math::Vector_2e3d0 b);
};
typedef bool (CActorManager_2e3d0::*ActorFn_2e3d0)(const char* name, math::Vector_2e3d0 a, math::Vector_2e3d0 b);
struct Args_2e3d0 {
    const char* name;
    math::Vector_2e3d0 a;
    math::Vector_2e3d0 b;
};
class Function_2e3d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CActorManager_2e6d0 {
  public:
    void Method(const char*, float);
};
struct Pair_2e6d0 {
    const char* s;
    float f;
};
class CActorManager_2e770 {
  public:
    void Method(const char*, float);
};
struct Pair_2e770 {
    const char* s;
    float f;
};
class CActorManager_2e800 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_2e800::*Fn_2e800)(const char*);
extern "C" char DAT_003f407c[];
extern "C" char DAT_003f439c[];
u8 GetHelper_001d04d0(const void*);
class Owner_2e830 {};
typedef void (Owner_2e830::*Fn_2e830)();
struct Closure1_2e830 {
    void* vptr;
    ScriptFunctionFields f;
    Fn_2e830 m1c;
    Owner_2e830* m20;
    Closure1_2e830* Build(const char*, Owner_2e830*, Fn_2e830);
};
class CActorManager_2e980 {};
struct Arguments {
  public:
    union { const char* first; const char* name; };
    union { const char* second; float value; };
    union { const char* other; float third; };
    float fourth;
    float fifth;
};
class Function_2ebc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct Arg_2ec60 {
    const char* s;
    unsigned char b;
};
class Actor_2ec60 {
  public:
    void invoke(const char*, unsigned char);
};
class CActorManager_2ed00 {
  public:
    void Method(const char*, float);
};
struct Pair_2ed00 {
    const char* s;
    float f;
};
extern "C" char DAT_003f410c[];
extern "C" char DAT_003f442c[];
} // namespace fn_f8e68f21
struct CActorManager {};
namespace fn_f8e68f21 {
extern char GetName_001d04d0(const char*);
class Closure1_2ed20 {
  public:
    hulk_intptr vt;
    char pad4[0x0c];
    char b10;
    char pad11[7];
    char b18;
    char pad19[3];
    CActorManager* p1c;
    void* p20;
    void Init_001d0480(const char*, int);
    Closure1_2ed20(const char*, void*, CActorManager*);
};
class CActorManager_2ed90 {
  public:
    void invoke(const char*);
};
class CActorManager_2ee10 {
  public:
    int act();
};
class CActorManager_2ee90 {
  public:
    int act();
};
struct CActorManager_2efc0 { bool FUN_0002efc0(const char *, const char *); };
struct Function_2efc0 { virtual void vfunc_0(); virtual void vfunc_1(); };
class CActorManager_2f070 {
  public:
    void Method(const char*, float);
};
struct Pair_2f070 {
    const char* s;
    float f;
};
class CActorManager_2f1c0 {
  public:
    void invoke(const char*);
};
class Function_2f290 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_2f290(const char*, int);
};
class Owner_2f290 {};
typedef void (Owner_2f290::*Fn_2f290)();
class Method1_2f290 : public Function_2f290 {
  public:
    virtual void f();
    Fn_2f290 c;
    Method1_2f290(const char* s, Fn_2f290 x) : Function_2f290(s, 1) {
        c = x;
        retType = FUN_001d04d0(((char*)&DAT_0048e0f0));
        argTypes[0] = FUN_001d04d0(DAT_0048e10c);
    }
};
class Closure1_2f290 : public Method1_2f290 {
  public:
    virtual void f();
    Owner_2f290* d;
    Closure1_2f290(const char*, Owner_2f290*, Fn_2f290);
};
class Function_2f390 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CActorManager_2f430 {
  public:
    void Method(const char*, float);
};
struct Pair_2f430 {
    const char* s;
    float f;
};
struct CActorManager_2f580 { bool callback(const char *, int); };
struct ActorArgs {
  public:
    const char *name;
    union { float a; int value; };
    float b;
    float c;
};
class CActorManager_2f6a0;
typedef unsigned char(__fastcall* Fn_2f6a0)(CActorManager_2f6a0*);
struct CActorManager_2f790 { void FUN_00000000(const char *, float, float, float); };
class CActorManager_2f820 {
  public:
    void run();
};
struct CActorManager_2f880 {};
struct CActorManager_2fa40 { bool FUN_00000000(const char *, float); };
struct CallArgs { const char *name; float value; };
struct CActorManager_2fb30 {
    void FUN_0002fb30(const char *, const char *, float, float);
};
class CActorManager_2fd40 {
public:
    int FUN_0002fd40(const char *, const char *);
};
extern "C" char DAT_003f42cc[];
extern "C" char DAT_003f45ec[];
class Owner_2fd70 {};
typedef void (Owner_2fd70::*Fn_2fd70)();
class Closure1_2fd70 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_2fd70 fn;
    Owner_2fd70* owner;
    Closure1_2fd70* Fn(const char* a, Owner_2fd70* b, Fn_2fd70 c);
};
class CActorManager_2fde0 {
  public:
    void invoke(const char*);
};
class CActorManager_2fe60 {
  public:
    float Get();
};
typedef float (CActorManager_2fe60::*Fn_2fe60)();
class CActorManager_2ffa0 {
  public:
    virtual float f(const char*, const char*);
};
class Actor_30040 {
  public:
    void fn(unsigned char);
};
struct Vector_301b0 { float x, y, z; };
struct CActorManager_301b0 { bool FUN_000301b0(const char *, Vector_301b0); };
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f8e68f21
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f8e68f21 {
class Owner {};
typedef bool (Owner::*Fn_301f0)(const char*, bool);
class Registry_301f0 { public:
    void FUN_000301f0(const char* a1, Owner* a2, Fn_301f0 a3);
};
class Closure2_301f0 { public: void* FUN_0002e4f0(const char*, Owner*, Fn_301f0); };
} // namespace fn_f8e68f21
namespace math {
class Vector_30240 { public: float x, y, z; };
}
namespace fn_f8e68f21 {
typedef void (Owner::*Fn_30240)(const char*, math::Vector_30240);
class Registry_30240 { public:
    void FUN_00030240(const char* a1, Owner* a2, Fn_30240 a3);
};
class Closure2_30240 { public: void* FUN_0002e5a0(const char*, Owner*, Fn_30240); };
} // namespace fn_f8e68f21
void* operator new(hulk_uintptr) throw();
namespace fn_f8e68f21 {
typedef void (Owner::*Fn_30290)(const char*, float);
class Registry_30290 {
  public:
    void FUN_00030290(const char* a1, Owner* a2, Fn_30290 a3);
};
class Closure2_30290 : public ScriptClosureView {
  public:
    Closure2_30290(const char*, Owner*, Fn_30290) throw();
};
} // namespace fn_f8e68f21
inline void* operator new(hulk_uintptr n) throw() {
    return FUN_0008d690((unsigned int)n);
}
namespace fn_f8e68f21 {
typedef void (Owner::*Fn_302e0)(const char*, int);
class Registry_302e0 {
  public:
    void FUN_000302e0(const char* a1, Owner* a2, Fn_302e0 a3);
};
class Closure2_302e0 : public ScriptClosureView {
  public:

    Closure2_302e0(const char*, Owner*, Fn_302e0) throw();
};
typedef bool (Owner::*Fn_30380)(const char*);
class Registry_30380 {
  public:
    void FUN_00030380(const char* a1, Owner* a2, Fn_30380 a3);
};
class Closure1_30380 : public ScriptClosureView {
  public:

    Closure1_30380(const char*, Owner*, Fn_30380) throw();
};
class CActorManager_303d0 {};
typedef void (CActorManager_303d0::*Fn_303d0)(const char*, float, bool);
class Registry_303d0 { public:
    void FUN_000303d0(const char* a1, CActorManager_303d0* a2, Fn_303d0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_303d0;
template<> class Closure3_303d0<CActorManager_303d0, void, const char*, float, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_303d0 fn; CActorManager_303d0* owner; Closure3_303d0(CActorManager_303d0* o) { owner = o; } };
class Raw_303d0 { public: void FUN_0002c810(const char*, Fn_303d0); };
class CActorManager_30430 {};
typedef void (CActorManager_30430::*Fn_30430)(const char*, float, const char*);
class Registry_30430 { public:
    void FUN_00030430(const char* a1, CActorManager_30430* a2, Fn_30430 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_30430;
template<> class Closure3_30430<CActorManager_30430, void, const char*, float, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_30430 fn; CActorManager_30430* owner; Closure3_30430(CActorManager_30430* o) { owner = o; } };
class Raw_30430 { public: void FUN_0002c8b0(const char*, Fn_30430); };
typedef int (Owner::*Fn_30490)(const char*);
class Registry_30490 { public:
    void FUN_00030490(const char* a1, Owner* a2, Fn_30490 a3);
};
class Closure1_30490 { public: void* FUN_0002e9a0(const char*, Owner*, Fn_30490); };
typedef const char* (Owner::*Fn_304e0)(const char*);
class Registry_304e0 { public:
    void FUN_000304e0(const char* a1, Owner* a2, Fn_304e0 a3);
};
class Closure1_304e0 { public: void* FUN_0002ea30(const char*, Owner*, Fn_304e0); };
class CActorManager_30530 {};
typedef bool (CActorManager_30530::*Fn_30530)(const char*, const char*, const char*, const char*, bool, const char*);
class Registry_30530 { public:
    void FUN_00030530(const char* a1, CActorManager_30530* a2, Fn_30530 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_30530;
template<> class Closure6_30530<CActorManager_30530, bool, const char*, const char*, const char*, const char*, bool, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_30530 fn; CActorManager_30530* owner; Closure6_30530(CActorManager_30530* o) { owner = o; } };
class Raw_30530 { public: void FUN_0002ca50(const char*, Fn_30530); };
} // namespace fn_f8e68f21
namespace math {
class Vector_30590 { public: float x, y, z; };
}
namespace fn_f8e68f21 {
class CActorManager_30590 {};
typedef bool (CActorManager_30590::*Fn_30590)(const char*, math::Vector_30590, float, const char*, const char*, bool, const char*);
class Registry_30590 { public:
    void FUN_00030590(const char* a1, CActorManager_30590* a2, Fn_30590 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7_30590;
template<> class Closure7_30590<CActorManager_30590, bool, const char*, math::Vector_30590, float, const char*, const char*, bool, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_30590 fn; CActorManager_30590* owner; Closure7_30590(CActorManager_30590* o) { owner = o; } };
class Raw_30590 { public: void FUN_0002cb60(const char*, Fn_30590); };
typedef void (Owner::*Fn_305f0)(const char*, bool);
class Registry_305f0 {
  public:
    void FUN_000305f0(const char* a1, Owner* a2, Fn_305f0 a3);
};
class Closure2_305f0 : public ScriptClosureView {
  public:

    Closure2_305f0(const char*, Owner*, Fn_305f0) throw();
};
typedef void (Owner::*Fn_30640)(float, float);
class Registry_30640 { public:
    void FUN_00030640(const char* a1, Owner* a2, Fn_30640 a3);
};
class Closure2_30640 { public: void* FUN_0002ec80(const char*, Owner*, Fn_30640); };
typedef void (Owner::*Fn_30690)(const char*);
class Registry_30690 { public:
    void FUN_00030690(const char* a1, Owner* a2, Fn_30690 a3);
};
class Closure1_30690 { public: void* FUN_0002ed20(const char*, Owner*, Fn_30690); };
typedef bool (Owner::*Fn_30810)(const char*, const char*);
class Registry_30810 { public:
    void FUN_00030810(const char* a1, Owner* a2, Fn_30810 a3);
};
class Closure2_30810 { public: void* FUN_0002ef40(const char*, Owner*, Fn_30810); };
typedef void (Owner::*Fn_30860)(const char*, const char*);
class Registry_30860 {
  public:
    void FUN_00030860(const char* a1, Owner* a2, Fn_30860 a3);
};
class Closure2_30860 {
  public:
    Closure2_30860(const char*, Owner*, Fn_30860);
};
} // namespace fn_f8e68f21
namespace math {
class Vector_309a0 { public: float x, y, z; };
}
namespace fn_f8e68f21 {
typedef const char* (Owner::*Fn_309a0)(math::Vector_309a0);
class Registry_309a0 { public:
    void FUN_000309a0(const char* a1, Owner* a2, Fn_309a0 a3);
};
class Closure1_309a0 { public: void* FUN_0002f290(const char*, Owner*, Fn_309a0); };
class CActorManager_309f0 {};
typedef void (CActorManager_309f0::*Fn_309f0)(const char*, float, float, float, float, float, const char*);
class Registry_309f0 { public:
    void FUN_000309f0(const char* a1, CActorManager_309f0* a2, Fn_309f0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7_309f0;
template<> class Closure7_309f0<CActorManager_309f0, void, const char*, float, float, float, float, float, const char*> : public ScriptFunctionFields { public: virtual void v(); Fn_309f0 fn; CActorManager_309f0* owner; Closure7_309f0(CActorManager_309f0* o) { owner = o; } };
class Raw_309f0 { public: void FUN_0002d370(const char*, Fn_309f0); };
typedef bool (Owner::*Fn_30af0)(const char*, int);
class Registry_30af0 { public:
    void FUN_00030af0(const char* a1, Owner* a2, Fn_30af0 a3);
};
class Closure2_30af0 { public: void* FUN_0002f500(const char*, Owner*, Fn_30af0); };
class CActorManager_30c00 {};
typedef void (CActorManager_30c00::*Fn_30c00)(const char*, float, int, float);
class Registry_30c00 { public:
    void FUN_00030c00(const char* a1, CActorManager_30c00* a2, Fn_30c00 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_30c00;
template<> class Closure4_30c00<CActorManager_30c00, void, const char*, float, int, float> : public ScriptFunctionFields { public: virtual void v(); Fn_30c00 fn; CActorManager_30c00* owner; Closure4_30c00(CActorManager_30c00* o) { owner = o; } };
class Raw_30c00 { public: void FUN_0002d770(const char*, Fn_30c00); };
class CActorManager_30c60 {};
typedef void (CActorManager_30c60::*Fn_30c60)(const char*, float, float, float);
class Registry_30c60 { public:
    void FUN_00030c60(const char* a1, CActorManager_30c60* a2, Fn_30c60 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_30c60;
template<> class Closure4_30c60<CActorManager_30c60, void, const char*, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_30c60 fn; CActorManager_30c60* owner; Closure4_30c60(CActorManager_30c60* o) { owner = o; } };
class Raw_30c60 { public: void FUN_0002d830(const char*, Fn_30c60); };
class CActorManager_30d30 {};
typedef void (CActorManager_30d30::*Fn_30d30)(const char*, const char*, float, float, float);
class Registry_30d30 { public:
    void FUN_00030d30(const char* a1, CActorManager_30d30* a2, Fn_30d30 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_30d30;
template<> class Closure5_30d30<CActorManager_30d30, void, const char*, const char*, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_30d30 fn; CActorManager_30d30* owner; Closure5_30d30(CActorManager_30d30* o) { owner = o; } };
class Raw_30d30 { public: void FUN_0002d960(const char*, Fn_30d30); };
class CActorManager_30d90 {};
typedef bool (CActorManager_30d90::*Fn_30d90)(const char*, float, float);
class Registry_30d90 { public:
    void FUN_00030d90(const char* a1, CActorManager_30d90* a2, Fn_30d90 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_30d90;
template<> class Closure3_30d90<CActorManager_30d90, bool, const char*, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_30d90 fn; CActorManager_30d90* owner; Closure3_30d90(CActorManager_30d90* o) { owner = o; } };
class Raw_30d90 { public: void FUN_0002da60(const char*, Fn_30d90); };
class CActorManager_30df0 {};
typedef void (CActorManager_30df0::*Fn_30df0)(const char*, float, float);
class Registry_30df0 { public:
    void FUN_00030df0(const char* a1, CActorManager_30df0* a2, Fn_30df0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_30df0;
template<> class Closure3_30df0<CActorManager_30df0, void, const char*, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_30df0 fn; CActorManager_30df0* owner; Closure3_30df0(CActorManager_30df0* o) { owner = o; } };
class Raw_30df0 { public: void FUN_0002db20(const char*, Fn_30df0); };
class CActorManager_30ea0 {};
typedef void (CActorManager_30ea0::*Fn_30ea0)(const char*, const char*, float);
class Registry_30ea0 { public:
    void FUN_00030ea0(const char* a1, CActorManager_30ea0* a2, Fn_30ea0 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_30ea0;
template<> class Closure3_30ea0<CActorManager_30ea0, void, const char*, const char*, float> : public ScriptFunctionFields { public: virtual void v(); Fn_30ea0 fn; CActorManager_30ea0* owner; Closure3_30ea0(CActorManager_30ea0* o) { owner = o; } };
class Raw_30ea0 { public: void FUN_0002dc60(const char*, Fn_30ea0); };
class CActorManager_30f00 {};
typedef void (CActorManager_30f00::*Fn_30f00)(const char*, const char*, float, float);
class Registry_30f00 { public:
    void FUN_00030f00(const char* a1, CActorManager_30f00* a2, Fn_30f00 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_30f00;
template<> class Closure4_30f00<CActorManager_30f00, void, const char*, const char*, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_30f00 fn; CActorManager_30f00* owner; Closure4_30f00(CActorManager_30f00* o) { owner = o; } };
class Raw_30f00 { public: void FUN_0002dd00(const char*, Fn_30f00); };
typedef const char* (Owner::*Fn_31000)(const char*, const char*);
class Registry_31000 {
  public:
    void FUN_00031000(const char* a1, Owner* a2, Fn_31000 a3);
};
class Closure2_31000 : public ScriptClosureView {
  public:

    Closure2_31000(const char*, Owner*, Fn_31000) throw();
};
typedef void (Owner::*Fn_31050)(float);
class Registry_31050 {
  public:
    void FUN_00031050(const char* a1, Owner* a2, Fn_31050 a3);
};
class Closure1_31050 : public ScriptClosureView {
  public:
    Closure1_31050(const char*, Owner*, Fn_31050) throw();
};
typedef void (Owner::*Fn_311b0)(bool);
class Closure1_311b0 : public ScriptClosureView {
  public:

    Closure1_311b0(const char*, Owner*, Fn_311b0) throw();
};
class Registry_311b0 {
  public:
    void FUN_000311b0(const char* a1, Owner* a2, Fn_311b0 a3);
};
class CActorManager_31200 {};
typedef void (CActorManager_31200::*Fn_31200)(int, int, int);
class Registry_31200 { public:
    void FUN_00031200(const char* a1, CActorManager_31200* a2, Fn_31200 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_31200;
template<> class Closure3_31200<CActorManager_31200, void, int, int, int> : public ScriptFunctionFields { public: virtual void v(); Fn_31200 fn; CActorManager_31200* owner; Closure3_31200(CActorManager_31200* o) { owner = o; } };
class Raw_31200 { public: void FUN_0002e2b0(const char*, Fn_31200); };
} // namespace fn_f8e68f21
namespace math {
class Vector_31260 { public: float x, y, z; };
}
namespace fn_f8e68f21 {
class CActorManager_31260 {};
typedef bool (CActorManager_31260::*Fn_31260)(const char*, math::Vector_31260, math::Vector_31260);
class Registry_31260 { public:
    void FUN_00031260(const char* a1, CActorManager_31260* a2, Fn_31260 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_31260;
template<> class Closure3_31260<CActorManager_31260, bool, const char*, math::Vector_31260, math::Vector_31260> : public ScriptFunctionFields { public: virtual void v(); Fn_31260 fn; CActorManager_31260* owner; Closure3_31260(CActorManager_31260* o) { owner = o; } };
class Raw_31260 { public: void FUN_0002e350(const char*, Fn_31260); };
} // namespace fn_f8e68f21
namespace math {
class Vector_312c0 { public: float x, y, z; };
}
namespace fn_f8e68f21 {
typedef bool (Owner::*Fn_312c0)(const char*, math::Vector_312c0);
class Registry_312c0 { public:
    void FUN_000312c0(const char* a1, Owner* a2, Fn_312c0 a3);
};
class Closure2_312c0 { public: void* FUN_00030130(const char*, Owner*, Fn_312c0); };

} // namespace fn_f8e68f21

// 0x0002c4f0 Method2<CActorManager,bool,const_char_*,bool>::vfunc_0 (30 B): matches/0x0002c4f0.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBD_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, bool, const char *, bool>::~Method2() {}


// 0x0002c510 Method2<CActorManager,bool,const_char_*,bool>::vfunc_2 (41 B): matches/0x0002c510.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@_NPBD_N@@UAEXPAX00@Z
template <> void Method2<CActorManager, bool, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c510 * obj = (CActorManager_2c510 *)__p0; Pair_2c510 * p = (Pair_2c510 *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_2c510::*fn)(const char*, bool) = (*(bool (CActorManager_2c510::**)(const char *, bool))&this->f_1c);
    const char* s = p->p;
    bool b = p->b;
    bool r = (obj->*fn)(s, b);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, bool, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c4f0)
#endif


// 0x0002c590 Method2<CActorManager,void,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x0002c590.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void, const char *,math::Vector>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c590)
#endif


// 0x0002c5b0 Method2<CActorManager,void,const_char_*,math::Vector>::vfunc_2 (48 B): equivalent/0x0002c5b0.cpp [wrapped: conflict: Args; CActorManager; Function; Method2]
// sym: ?vfunc_2@Method2@fn_0002c5b0@@UAEXPAUCActorManager@2@PBXH@Z @db11992ea1ff @w53dc8781dea7
namespace fn_0002c5b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method2<CActorManager,void,const_char_*,math::Vector>::vfunc_2 @ 0x0002c5b0
namespace math { struct Vector { float x, y, z; }; }
struct CActorManager { void FUN_0002c5b0(const char *, math::Vector); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method2 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager *actor, const void *args, int unused);
    char padding[0x18];
    void (CActorManager::*method)(const char *, math::Vector);
};
struct Args { const char *name; math::Vector position; };
void Method2::vfunc_2(CActorManager *actor, const void *data, int) {
    const Args *args = (const Args *)data;
    (actor->*method)(args->name, args->position);
}
} // namespace fn_0002c5b0


// 0x0002c630 Method2<CActorManager,void,const_char_*,float>::vfunc_0 (30 B): matches/0x0002c630.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void, const char *, float>::~Method2() {}


// 0x0002c650 Method2<CActorManager,void,const_char_*,float>::vfunc_2 (23 B): matches/0x0002c650.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CActorManager, void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_2c650* m = (CFEManager_2c650*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_2c650::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c630)
#endif


// 0x0002c6c0 Method2<CActorManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x0002c6c0.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void, const char *, int>::~Method2() {}


// 0x0002c6e0 Method2<CActorManager,void,const_char_*,int>::vfunc_2 (23 B): matches/0x0002c6e0.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CActorManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_2c6e0* m = (CFEManager_2c6e0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_2c6e0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c6c0)
#endif


// 0x0002c700 FUN_0002c700 (63 B): matches/0x0002c700.cpp [wrapped: conflict: Method1]
// sym: ??0Method1@fn_0002c700@@QAE@HH@Z
namespace fn_0002c700 {

extern unsigned char __cdecl GetFlag_001d04d0(const char*);
class Function_2c700 {
  public:
    virtual void V();
    Function_2c700(int a, int b) throw();
    char pad[0x1c - 4];
};
class Method1 : public Function_2c700 {
  public:
    virtual void V();
    Method1(int a, int b) throw();
    unsigned char x;
};
Method1::Method1(int a, int b) throw() : Function_2c700(a, 1) {
    *(int*)((char*)this + 0x1c) = b;
    *(unsigned char*)((char*)this + 0x18) = GetFlag_001d04d0(((char*)&DAT_0048e128));
    *(unsigned char*)((char*)this + 0x10) = GetFlag_001d04d0(((char*)&DAT_0048e0f0));
}
} // namespace fn_0002c700


// 0x0002c740 Method1<CActorManager,float,const_char_*>::vfunc_0 (30 B): matches/0x0002c740.cpp
// sym: ??_G?$Method1@UCActorManager@@MPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, float, const char *>::~Method1() {}


// 0x0002c760 Method1<CActorManager,float,const_char_*>::vfunc_2 (42 B): matches/0x0002c760.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@MPBD@@UAEXPAX00@Z
template <> void Method1<CActorManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c760 * a = (CActorManager_2c760 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_2c760 f = (*(Fn_2c760 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c740)
#endif


// 0x0002c790 FUN_0002c790 (63 B): matches/0x0002c790.cpp [wrapped: conflict: Method1]
// sym: ??0Method1@fn_0002c790@@QAE@PBDP8Owner_2c790@1@AEXXZ@Z
namespace fn_0002c790 {
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

// data: name1 = DAT_0048e0e4, name2 = DAT_0048e0f0
// Method1's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_2c790 : public CtorV_001d0480 {
  public:
    Function_2c790(const char* s) : CtorV_001d0480(s, 1) { }
};
class Owner_2c790 {};
typedef void (Owner_2c790::*Fn_2c790)();
class Method1 : public Function_2c790 {
  public:
    virtual bool fn_001d04c0(int, int);
    Fn_2c790 c;
    Method1(const char*, Fn_2c790);
};
Method1::Method1(const char* s, Fn_2c790 v) : Function_2c790(s) {
    c = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
} // namespace fn_0002c790
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0002c7d0 Method1<CActorManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x0002c7d0.cpp
// sym: ??_G?$Method1@UCActorManager@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, bool, const char *>::~Method1() {}


// 0x0002c7f0 Method1<CActorManager,bool,const_char_*>::vfunc_2 (29 B): matches/0x0002c7f0.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@_NPBD@@UAEXPAX00@Z
template <> void Method1<CActorManager, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c7f0 * obj = (CActorManager_2c7f0 *)__p0; const char ** arg = (const char **)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_2c7f0::*fn)(const char*) = (*(bool (CActorManager_2c7f0::**)(const char *))&this->f_1c);
    const char* val = *arg;
    bool r = (obj->*fn)(val);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c7d0)
#endif


// 0x0002c810 FUN_0002c810 (89 B): matches/0x0002c810.cpp [wrapped: conflict: Method3]
// sym: ?target@Method3@fn_0002c810@@QAEPAV12@PBDP8Owner_2c810@2@AEXXZ@Z
namespace fn_0002c810 {

extern "C" char DAT_003f408c[];
typedef unsigned char u8;
struct ThisCall_001d0480 {
    void setup_001d0480(const char*, int);
};
u8 __cdecl getval_001d04d0(const void*);
// Method3's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Owner_2c810 {};
typedef void (Owner_2c810::*Fn_2c810)();
class Method3 {
  public:
    void* vf;
    ScriptFunctionFields f;
    Fn_2c810 value;
    Method3* target(const char*, Fn_2c810);
};
Method3* Method3::target(const char* a, Fn_2c810 c) {
    ((ThisCall_001d0480*)(this))->setup_001d0480(a, 3);
    vf = (void*)DAT_003f408c;
    value = c;
    f.retType = getval_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = getval_001d04d0(((char*)&DAT_0048e0f0));
    f.argTypes[1] = getval_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[2] = getval_001d04d0(((char*)&DAT_0048e0e4));
    return this;
}
} // namespace fn_0002c810


// 0x0002c870 Method3<CActorManager,void,const_char_*,float,bool>::vfunc_0 (30 B): matches/0x0002c870.cpp
// sym: ??_G?$Method3@UCActorManager@@XPBDM_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CActorManager, void, const char *, float, bool>::~Method3() {}


// 0x0002c890 Method3<CActorManager,void,const_char_*,float,bool>::vfunc_2 (31 B): equivalent/0x0002c890.cpp
// sym: ?vfunc_2@?$Method3@UCActorManager@@XPBDM_N@@UAEXPAX00@Z @086ee6cd29ba @wc99d4108e717
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,float,bool>::vfunc_2 @ 0x0002c890
template <> void Method3<CActorManager, void, const char *, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c890 * actor = (CActorManager_2c890 *)__p0; const CallArguments * arguments = (const CallArguments *)__p1; hulk_intptr unused = (hulk_intptr)__p2;

 (actor->*(*(void (CActorManager_2c890::**)(const char *, float, bool))&this->f_1c))(arguments->text, arguments->value, arguments->enabled);
}
#if defined(HULK_PTR64)
template class Method3<CActorManager, void, const char *, float, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c870)
#endif


// 0x0002c8b0 FUN_0002c8b0 (89 B): matches/0x0002c8b0.cpp [wrapped: conflict: Method3]
// sym: ??0Method3@fn_0002c8b0@@QAE@PBDH@Z
namespace fn_0002c8b0 {

class Function_2c8b0 {
  public:
    Function_2c8b0(const char*, int);
    virtual void f();
};
extern "C++" __declspec(nothrow) char __cdecl lookup_001d04d0(const char*);
class Method3 : public Function_2c8b0 {
  public:
    Method3(const char*, hulk_intptr);
    char pad[12];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    int val;
};
Method3::Method3(const char* name, hulk_intptr x) : Function_2c8b0(name, 3) {
    val = x;
    d = lookup_001d04d0(((const char*)&DAT_0048e100));
    a = lookup_001d04d0(((const char*)&DAT_0048e0f0));
    b = lookup_001d04d0(((const char*)&DAT_0048e128));
    c = lookup_001d04d0(((const char*)&DAT_0048e0f0));
}
} // namespace fn_0002c8b0


// 0x0002c910 Method3<CActorManager,void,const_char_*,float,const_char_*>::vfunc_0 (30 B): matches/0x0002c910.cpp
// sym: ??_G?$Method3@UCActorManager@@XPBDMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CActorManager, void, const char *, float, const char *>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<CActorManager, void, const char *, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c910)
#endif


// 0x0002c930 Method3<CActorManager,void,const_char_*,float,const_char_*>::vfunc_2 (29 B): equivalent/0x0002c930.cpp [wrapped: conflict: Function; Method3]
// sym: ?vfunc_2@Method3@fn_0002c930@@UAEXPAUCActorManager@2@PBUArgs@2@PAX@Z @a7a6d240b96d @wba0c35a5e91c
namespace fn_0002c930 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,float,const_char_*>::vfunc_2 @ 0x0002c930
struct CActorManager {};
struct Args { const char *first; float second; const char *third; };
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager *, const Args *, void *);
};
struct Method3 : Function {
    char padding[0x1c - sizeof(Function)];
    void (CActorManager::*callback)(const char *, float, const char *);
    virtual void vfunc_2(CActorManager *, const Args *, void *);
};
void Method3::vfunc_2(CActorManager *actor, const Args *args, void *) {
    (actor->*callback)(args->first, args->second, args->third);
}
} // namespace fn_0002c930


// 0x0002c990 Method1<CActorManager,int,const_char_*>::vfunc_0 (30 B): matches/0x0002c990.cpp
// sym: ??_G?$Method1@UCActorManager@@HPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, int, const char *>::~Method1() {}


// 0x0002c9b0 Method1<CActorManager,int,const_char_*>::vfunc_2 (29 B): matches/0x0002c9b0.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@HPBD@@UAEXPAX00@Z
template <> void Method1<CActorManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2c9b0 * arg = (CActorManager_2c9b0 *)__p0; const char ** value = (const char **)__p1; int * out = (int *)__p2;

    int (CActorManager_2c9b0::*f)(const char*) = (*(int (CActorManager_2c9b0::**)(const char *))&this->f_1c);
    int r = arg->Invoke(f, *value);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2c990)
#endif


// 0x0002ca10 Method1<CActorManager,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002ca10.cpp
// sym: ??_G?$Method1@UCActorManager@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, const char *, const char *>::~Method1() {}


// 0x0002ca30 Method1<CActorManager,const_char_*,const_char_*>::vfunc_2 (29 B): matches/0x0002ca30.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@HPBD@@UAEXPAX00@Z
template <> void Method1<CActorManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2ca30 * obj = (CActorManager_2ca30 *)__p0; const char ** arg = (const char **)__p1; const char ** out = (const char **)__p2;

    const char* (CActorManager_2ca30::*f)(const char*) = (*(const char *(CActorManager_2ca30::**)(const char *))&this->f_1c);
    const char* p = *arg;
    const char* r = (obj->*f)(p);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ca10)
#endif


// 0x0002ca50 FUN_0002ca50 (128 B): matches/0x0002ca50.cpp [wrapped: conflict: Method6]
// sym: ??0Method6@fn_0002ca50@@QAE@PBDP8Owner_2ca50@1@AEXXZ@Z
namespace fn_0002ca50 {
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

extern "C" char DAT_003f40cc[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
// Method6's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2ca50 {};
typedef void (Owner_2ca50::*Fn_2ca50)();
class Method6 : public FUN_001d0480 {
  public:
    void* vt;
    ScriptFunctionFields f;
    Fn_2ca50 m1c;
    Method6(const char*, Fn_2ca50);
};
Method6::Method6(const char* a, Fn_2ca50 b) : FUN_001d0480(a, 6) {
    vt = (void*)((hulk_intptr)DAT_003f40cc);
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[5] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
}
} // namespace fn_0002ca50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0002cad0 Method6<CActorManager,bool,const_char_*,const_char_*,const_char_*,const_char_*,bool,const_char_*>::vfunc_0 (30 B): matches/0x0002cad0.cpp
// sym: ??_G?$Method6@UCActorManager@@_NPBDPBDPBDPBD_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CActorManager, bool, const char *, const char *, const char *, const char *, bool, const char *>::~Method6() {}


// 0x0002caf0 Method6<CActorManager,bool,const_char_*,const_char_*,const_char_*,const_char_*,bool,const_char_*>::vfunc_2 (30 B): matches/0x0002caf0.cpp
// sym: ?vfunc_2@?$Method6@UCActorManager@@_NPBDPBDPBDPBD_NPBD@@UAEXPAX00@Z
template <> void Method6<CActorManager, bool, const char *, const char *, const char *, const char *, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0002cb10(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method6<CActorManager, bool, const char *, const char *, const char *, const char *, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2cad0)
#endif

namespace fn_f8e68f21 {

// 0x0002cb10 FUN_0002cb10 (72 B): matches/0x0002cb10.cpp
// sym: ?FUN_0002cb10@fn_f8e68f21@@YAXPAVObj@1@PAHPADP821@AEDHHHHDH@Z@Z
void __cdecl FUN_0002cb10(Obj* self, int* args, char* out, Fn fn) {
    int* p = args;
    int a = *p++;
    int b = *p++;
    int c = *p++;
    int d = *p++;
    char e = *(char*)p++;
    int f = *p++;
    char value = (self->*fn)(a, b, c, d, e, f);
    if (out)
        *out = value;
}


// 0x0002cb60 FUN_0002cb60 (141 B): matches/0x0002cb60.cpp
// sym: ?Init@Method7_2cb60@fn_f8e68f21@@QAEPAV12@PBDP8Owner_2cb60@2@AEXXZ@Z
// FUN_0002cb60 @ 0x0002cb60
Method7_2cb60* Method7_2cb60::Init(const char* name, Fn_2cb60 fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (void*)DAT_003f40dc;
    func = fn;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}

} // namespace fn_f8e68f21

// 0x0002cbf0 Method7<CActorManager,bool,const_char_*,math::Vector,float,const_char_*,const_char_*,bool,const_char_*>::vfunc_0 (30 B): matches/0x0002cbf0.cpp
// sym: ??_G?$Method7@UCActorManager@@_NPBDVVector@math@@MPBDPBD_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method7<CActorManager, bool, const char *,math::Vector, float, const char *, const char *, bool, const char *>::~Method7() {}


// 0x0002cc10 Method7<CActorManager,bool,const_char_*,math::Vector,float,const_char_*,const_char_*,bool,const_char_*>::vfunc_2 (30 B): matches/0x0002cc10.cpp
// sym: ?vfunc_2@?$Method7@UCActorManager@@_NPBDVVector@math@@MPBDPBD_NPBD@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method7<CActorManager, bool, const char *,math::Vector, float, const char *, const char *, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0002cc30(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method7<CActorManager, bool, const char *,math::Vector, float, const char *, const char *, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2cbf0)
#endif

namespace fn_f8e68f21 {

// 0x0002cc30 FUN_0002cc30 (121 B): equivalent/0x0002cc30.cpp
// sym: ?FUN_0002cc30@fn_f8e68f21@@YAXPAVTarget_2cc30@1@TBlockArg@1@PAEP821@AEEHUTriple_2cc30@1@HHHIH@Z@Z @9a48b591be50 @w0a09c09b7ece
// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_0002cc30 @ 0x0002cc30
void FUN_0002cc30(Target_2cc30* self, BlockArg arg, unsigned char* out, Fn_2cc30 fn) {
    Block_2cc30* b = arg.block;
    int a0 = b->a0;
    Triple_2cc30 t = b->t;
    int a4 = b->a4;
    int a5 = b->a5;
    int a6 = b->a6;
    arg.flag = b->flag;
    unsigned char r = (self->*fn)(a0, t, a4, a5, a6, arg.word, b->a8);
    if (out)
        *out = r;
}

} // namespace fn_f8e68f21

// 0x0002cd00 Method2<CActorManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x0002cd00.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBD_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void, const char *, bool>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2cd00)
#endif


// 0x0002cd20 Method2<CActorManager,void,const_char_*,bool>::vfunc_2 (25 B): matches/0x0002cd20.cpp [wrapped: conflict: Args; CActorManager; Function; Method2]
// sym: ?v2@Method2@fn_0002cd20@@UAEXPAVCActorManager@2@PAUArgs@2@PAX@Z
namespace fn_0002cd20 {
class CActorManager {
  public:
    void Fn(const char*, bool);
};
struct Args {
    const char* name;
    bool flag;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager*, Args*, void*);
};
class Method2 : public Function {
  public:
    char pad[0x18];
    void (CActorManager::*method)(const char*, bool);
    virtual void v2(CActorManager* obj, Args* args, void* unused);
};
void Method2::v2(CActorManager* obj, Args* args, void* unused) {
    (obj->*method)(args->name, args->flag);
}
} // namespace fn_0002cd20


// 0x0002cd90 Method2<CActorManager,void,float,float>::vfunc_0 (30 B): matches/0x0002cd90.cpp
// sym: ??_G?$Method2@UCActorManager@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void, float, float>::~Method2() {}


// 0x0002cdb0 Method2<CActorManager,void,float,float>::vfunc_2 (23 B): matches/0x0002cdb0.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CActorManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_2cdb0* m = (CFEManager_2cdb0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_2cdb0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2cd90)
#endif


// 0x0002ce10 Method1<CActorManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0002ce10.cpp
// sym: ??_G?$Method1@UCActorManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, void, const char *>::~Method1() {}


// 0x0002ce30 Method1<CActorManager,void,const_char_*>::vfunc_2 (19 B): matches/0x0002ce30.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@XPBD@@UAEXPAX00@Z
template <> void Method1<CActorManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_2ce30* d = (Dummy_2ce30*)a;
    (d->*(*(void (Dummy_2ce30::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ce10)
#endif


// 0x0002ce90 Method0<CActorManager,const_char_*>::vfunc_0 (30 B): matches/0x0002ce90.cpp
// sym: ??_G?$Method0@UCActorManager@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CActorManager, const char *>::~Method0() {}


// 0x0002ceb0 Method0<CActorManager,const_char_*>::vfunc_2 (22 B): matches/0x0002ceb0.cpp
// sym: ?vfunc_2@?$Method0@UCActorManager@@PBD@@UAEXPAX00@Z
template <> void Method0<CActorManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method0<CActorManager, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ce90)
#endif


// 0x0002cf10 Method0<CActorManager,int>::vfunc_0 (30 B): matches/0x0002cf10.cpp
// sym: ??_G?$Method0@UCActorManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CActorManager, int>::~Method0() {}


// 0x0002cf30 Method0<CActorManager,int>::vfunc_2 (22 B): matches/0x0002cf30.cpp
// sym: ?vfunc_2@?$Method0@UCActorManager@@PBD@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CActorManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}
#if defined(HULK_PTR64)
template class Method0<CActorManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2cf10)
#endif


// 0x0002cf90 Method1<CActorManager,const_char_*,int>::vfunc_0 (30 B): matches/0x0002cf90.cpp
// sym: ??_G?$Method1@UCActorManager@@PBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, const char *, int>::~Method1() {}


// 0x0002cfb0 Method1<CActorManager,const_char_*,int>::vfunc_2 (29 B): matches/0x0002cfb0.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@HPBD@@UAEXPAX00@Z
template <> void Method1<CActorManager, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2cfb0 * obj = (CActorManager_2cfb0 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (CActorManager_2cfb0::*f)(const char*) = (*(int (CActorManager_2cfb0::**)(const char *))&this->f_1c);
    const char* a = *arg;
    int x = (obj->*f)(a);
    if (out)
        *out = x;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2cf90)
#endif


// 0x0002d020 Method2<CActorManager,bool,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002d020.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, bool, const char *, const char *>::~Method2() {}


// 0x0002d040 Method2<CActorManager,bool,const_char_*,const_char_*>::vfunc_2 (33 B): matches/0x0002d040.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@_NPBDPBD@@UAEXPAX00@Z
template <> void Method2<CActorManager, bool, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d040 * obj = (CActorManager_2d040 *)__p0; const char ** args = (const char **)__p1; char * out = (char *)__p2;

    char (CActorManager_2d040::*f)(const char*, const char*) = (*(char (CActorManager_2d040::**)(const char *, const char *))&this->f_1c);
    const char* a = args[0];
    const char* b = args[1];
    char r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, bool, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d020)
#endif


// 0x0002d0c0 Method2<CActorManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002d0c0.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void, const char *, const char *>::~Method2() {}


// 0x0002d0e0 Method2<CActorManager,void,const_char_*,const_char_*>::vfunc_2 (23 B): matches/0x0002d0e0.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CActorManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_2d0e0* m = (CFEManager_2d0e0*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_2d0e0::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d0c0)
#endif


// 0x0002d140 Method1<CActorManager,math::Vector,const_char_*>::vfunc_0 (30 B): matches/0x0002d140.cpp
// sym: ??_G?$Method1@UCActorManager@@VVector@math@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager,math::Vector, const char *>::~Method1() {}
#if defined(HULK_PTR64)
template class Method1<CActorManager,math::Vector, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d140)
#endif


// 0x0002d160 Method1<CActorManager,math::Vector,const_char_*>::vfunc_2 (69 B): equivalent/0x0002d160.cpp [wrapped: conflict: CActorManager; Method1]
// sym: ?vfunc_2@Method1@fn_0002d160@@UAEXPAUCActorManager@2@PAPBDPAUVector@2@@Z @97077a2a52c1 @we0844cc63fd1
namespace fn_0002d160 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CActorManager,math::Vector,const_char_*>::vfunc_2 @ 0x0002d160
struct Vector { float x, y, z; };
struct CActorManager {
    Vector* FUN_0002d160(Vector*, const char*);
};
struct Method1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* manager, const char** name, Vector* output);
    char padding[0x18];
    Vector* (CActorManager::*method)(Vector*, const char*);
};
void Method1::vfunc_2(CActorManager* manager, const char** name, Vector* output)
{
    Vector temporary;
    Vector result = *(manager->*method)(&temporary, *name);
    if (output) *output = result;
}
} // namespace fn_0002d160


// 0x0002d1f0 Method1<CActorManager,void,int>::vfunc_0 (30 B): matches/0x0002d1f0.cpp
// sym: ??_G?$Method1@UCActorManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, void, int>::~Method1() {}


// 0x0002d210 Method1<CActorManager,void,int>::vfunc_2 (19 B): matches/0x0002d210.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CActorManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_2d210* d = (Dummy_2d210*)a;
    (d->*(*(void (Dummy_2d210::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d1f0)
#endif


// 0x0002d270 Method1<CActorManager,bool,math::Vector>::vfunc_0 (30 B): matches/0x0002d270.cpp
// sym: ??_G?$Method1@UCActorManager@@_NVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, bool,math::Vector>::~Method1() {}


// 0x0002d290 Method1<CActorManager,bool,math::Vector>::vfunc_2 (49 B): matches/0x0002d290.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@_NVVector@math@@@@UAEXPAX00@Z
template <> void Method1<CActorManager, bool,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Vec_2d290 * v = (Vec_2d290 *)__p1; unsigned char * out = (unsigned char *)__p2;

    ActorFn_2d290 f = (*(ActorFn_2d290 *)&this->f_1c);
    unsigned char r = (unsigned char)((((Actor_2d290*)a)->*f)(*v));
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, bool,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d270)
#endif


// 0x0002d310 Method1<CActorManager,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x0002d310.cpp
// sym: ??_G?$Method1@UCActorManager@@PBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, const char *,math::Vector>::~Method1() {}


// 0x0002d330 Method1<CActorManager,const_char_*,math::Vector>::vfunc_2 (49 B): matches/0x0002d330.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@PBDVVector@math@@@@UAEXPAX00@Z
template <> void Method1<CActorManager, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d330 * obj = (CActorManager_2d330 *)__p0; Vec_2d330 * v = (Vec_2d330 *)__p1; unsigned int * out = (unsigned int *)__p2;

    ActFn_2d330 fn = (*(ActFn_2d330 *)&this->f_1c);
    int r = (obj->*fn)(*v);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d310)
#endif

namespace fn_f8e68f21 {

// 0x0002d370 FUN_0002d370 (141 B): matches/0x0002d370.cpp
// sym: ?Init@Method7_2d370@fn_f8e68f21@@QAEPAV12@PBDP8Owner_2d370@2@AEXXZ@Z
// FUN_0002d370 @ 0x0002d370
Method7_2d370* Method7_2d370::Init(const char* name, Fn_2d370 fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (void*)DAT_003f41ac;
    func = fn;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    return this;
}

} // namespace fn_f8e68f21

// 0x0002d400 Method7<CActorManager,void,const_char_*,float,float,float,float,float,const_char_*>::vfunc_0 (30 B): matches/0x0002d400.cpp
// sym: ??_G?$Method7@UCActorManager@@XPBDMMMMMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method7<CActorManager, void, const char *, float, float, float, float, float, const char *>::~Method7() {}


// 0x0002d420 Method7<CActorManager,void,const_char_*,float,float,float,float,float,const_char_*>::vfunc_2 (30 B): matches/0x0002d420.cpp
// sym: ?vfunc_2@?$Method7@UCActorManager@@XPBDMMMMMPBD@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method7<CActorManager, void, const char *, float, float, float, float, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0002d440(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method7<CActorManager, void, const char *, float, float, float, float, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d400)
#endif


// 0x0002d440 FUN_0002d440 (88 B): equivalent/0x0002d440.cpp [wrapped: conflict: Args]
// sym: ?FUN_0002d440@fn_0002d440@@YAXPAUCallbackObj@1@PBUArgs@1@IP6IX0IIIIIIII@Z@Z @9876e944addb @w113adbc320f0
namespace fn_0002d440 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0002d440 @ 0x0002d440
struct CallbackObj {};
struct Args { unsigned a,b,c,d,e,f,g; };
typedef void (__fastcall *Callback)(CallbackObj*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0002d440(CallbackObj* object, const Args* args, unsigned unused, Callback callback)
{
    callback(object, 0, args->a, args->b, args->c, args->d, args->e, args->f, args->g);
}
} // namespace fn_0002d440


// 0x0002d4f0 Method2<CActorManager,void,int,const_char_*>::vfunc_0 (30 B): matches/0x0002d4f0.cpp
// sym: ??_G?$Method2@UCActorManager@@XHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void, int, const char *>::~Method2() {}


// 0x0002d510 Method2<CActorManager,void,int,const_char_*>::vfunc_2 (23 B): matches/0x0002d510.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CActorManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_2d510* m = (CFEManager_2d510*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_2d510::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d4f0)
#endif


// 0x0002d580 Method2<CActorManager,void,math::Vector,float>::vfunc_0 (30 B): matches/0x0002d580.cpp
// sym: ??_G?$Method2@UCActorManager@@XVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, void,math::Vector, float>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CActorManager, void,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d580)
#endif


// 0x0002d5a0 Method2<CActorManager,void,math::Vector,float>::vfunc_2 (43 B): matches/0x0002d5a0.cpp [wrapped: conflict: Args; CActorManager; Function; Method2]
// sym: ?vfunc_2@Method2@fn_0002d5a0@@UAEXPAVCActorManager@2@PAXH@Z
namespace fn_0002d5a0 {
namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CActorManager {
  public:
    void act(math::Vector, float);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager*, void*, int);
};
struct Args {
    math::Vector v;
    float f;
};
class Method2 : public Function {
    char pad[0x18];

  public:
    void (CActorManager::*fn)(math::Vector, float);
    virtual void vfunc_2(CActorManager*, void*, int);
};
void Method2::vfunc_2(CActorManager* mgr, void* data, int unused) {
    Args* a = (Args*)data;
    (mgr->*fn)(a->v, a->f);
}
} // namespace fn_0002d5a0


// 0x0002d620 Method2<CActorManager,bool,const_char_*,int>::vfunc_0 (30 B): matches/0x0002d620.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, bool, const char *, int>::~Method2() {}


// 0x0002d640 Method2<CActorManager,bool,const_char_*,int>::vfunc_2 (33 B): matches/0x0002d640.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@_NPBDPBD@@UAEXPAX00@Z
template <> void Method2<CActorManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d640 * object = (CActorManager_2d640 *)__p0; void * args = (void *)__p1; bool * out = (bool *)__p2;

    struct Args {
        const char* name;
        int id;
    };
    Args* a = (Args*)args;
    bool (CActorManager_2d640::*f)(const char*, int) = (*(bool (CActorManager_2d640::**)(const char *, int))&this->f_1c);
    const char* name = a->name;
    int id = a->id;
    bool result = (object->*f)(name, id);
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, bool, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d620)
#endif


// 0x0002d6b0 Method1<CActorManager,bool,int>::vfunc_0 (30 B): matches/0x0002d6b0.cpp
// sym: ??_G?$Method1@UCActorManager@@_NH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, bool, int>::~Method1() {}


// 0x0002d6d0 Method1<CActorManager,bool,int>::vfunc_2 (29 B): matches/0x0002d6d0.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@_NPBD@@UAEXPAX00@Z
template <> void Method1<CActorManager, bool, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d6d0 * obj = (CActorManager_2d6d0 *)__p0; int * input = (int *)__p1; bool * out = (bool *)__p2;

    bool (CActorManager_2d6d0::*f)(int) = (*(bool (CActorManager_2d6d0::**)(int))&this->f_1c);
    int n = *input;
    bool r = (obj->*f)(n);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, bool, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d6b0)
#endif


// 0x0002d730 Method0<CActorManager,bool>::vfunc_0 (30 B): matches/0x0002d730.cpp
// sym: ??_G?$Method0@UCActorManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CActorManager, bool>::~Method0() {}


// 0x0002d750 Method0<CActorManager,bool>::vfunc_2 (22 B): matches/0x0002d750.cpp
// sym: ?vfunc_2@?$Method0@UCActorManager@@_N@@UAEXPAX00@Z
template <> void Method0<CActorManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d750 * obj = (CActorManager_2d750 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_2d750 fn = (*(Fn_2d750 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method0<CActorManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d730)
#endif

namespace fn_f8e68f21 {

// 0x0002d770 FUN_0002d770 (102 B): matches/0x0002d770.cpp
// sym: ??0Method4_2d770@fn_f8e68f21@@QAE@PBDP8Owner_2d770@1@AEXXZ@Z
Method4_2d770::Method4_2d770(const char* p, Fn_2d770 q) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(p, 4);
    vt = (void*)DAT_003f420c;
    m1c = q;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e134));
    f.argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e128));
}

} // namespace fn_f8e68f21

// 0x0002d7e0 Method4<CActorManager,void,const_char_*,float,int,float>::vfunc_0 (30 B): matches/0x0002d7e0.cpp
// sym: ??_G?$Method4@UCActorManager@@XPBDMHM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CActorManager, void, const char *, float, int, float>::~Method4() {}


// 0x0002d800 Method4<CActorManager,void,const_char_*,float,int,float>::vfunc_2 (46 B): matches/0x0002d800.cpp
// sym: ?vfunc_2@?$Method4@UCActorManager@@XPBDMHM@@UAEXPAX00@Z
template <> void Method4<CActorManager, void, const char *, float, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d800 * actor = (CActorManager_2d800 *)__p0; const char * args = (const char *)__p1;

    const char* name = *(const char**)args;
    args += 4;
    float value = *(float*)args;
    args += 4;
    int count = *(int*)args;
    args += 4;
    float other = *(float*)args;
    (actor->*(*(void (CActorManager_2d800::**)(const char *, float, int, float))&this->f_1c))(name, value, count, other);
}
#if defined(HULK_PTR64)
template class Method4<CActorManager, void, const char *, float, int, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d7e0)
#endif

namespace fn_f8e68f21 {

// 0x0002d830 FUN_0002d830 (102 B): matches/0x0002d830.cpp
// sym: ??0Method4_2d830@fn_f8e68f21@@QAE@PBDP8Owner_2d830@1@AEXXZ@Z
Method4_2d830::Method4_2d830(const char* a, Fn_2d830 b) : FUN_001d0480(a, 4) {
    vptr = (void*)DAT_003f421c;
    m1c = b;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e128));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e128));
}

} // namespace fn_f8e68f21

// 0x0002d8a0 Method4<CActorManager,void,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x0002d8a0.cpp
// sym: ??_G?$Method4@UCActorManager@@XPBDMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CActorManager, void, const char *, float, float, float>::~Method4() {}
#if defined(HULK_PTR64)
template class Method4<CActorManager, void, const char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d8a0)
#endif


// 0x0002d8c0 Method4<CActorManager,void,const_char_*,float,float,float>::vfunc_2 (46 B): equivalent/0x0002d8c0.cpp [wrapped: conflict: CActorManager; Method4]
// sym: ?target@Method4@fn_0002d8c0@@QAEXPAUCActorManager@2@PBII@Z @06f2e20faa8a @w509fe939fc52
namespace fn_0002d8c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CActorManager,void,const_char_*,float,float,float>::vfunc_2 @ 0x0002d8c0
struct CActorManager { void FUN_0002d8c0(const char *, float, float, float); };
struct Method4 {
    char padding[0x1c];
    void (CActorManager::*method)(const char *, float, float, float);
    void target(CActorManager *manager, const unsigned *arguments, unsigned unused);
};
void Method4::target(CActorManager *manager, const unsigned *arguments, unsigned unused) {
    (manager->*method)((const char *)arguments[0], *(const float *)&arguments[1], *(const float *)&arguments[2], *(const float *)&arguments[3]);
}
} // namespace fn_0002d8c0


// 0x0002d930 Method0<CActorManager,void>::vfunc_0 (30 B): matches/0x0002d930.cpp
// sym: ??_G?$Method0@UCActorManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CActorManager, void>::~Method0() {}


// 0x0002d950 Method0<CActorManager,void>::vfunc_2 (12 B): matches/0x0002d950.cpp
// sym: ?vfunc_2@?$Method0@UCActorManager@@X@@UAEXPAX00@Z
template <> void Method0<CActorManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2d950 * a = (CActorManager_2d950 *)__p0;

    (a->*(*(void (CActorManager_2d950::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Method0<CActorManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d930)
#endif


// 0x0002d960 FUN_0002d960 (115 B): matches/0x0002d960.cpp [wrapped: conflict: Method5]
// sym: ?Build@Method5@fn_0002d960@@QAEPAV12@PBDP8Owner_2d960@2@AEXXZ@Z
namespace fn_0002d960 {

extern "C" char DAT_003f423c[];
struct ThisCall_001d0480 {
    void Init_001d0480(const char*, int);
};
extern "C++" __declspec(nothrow) unsigned char __cdecl Get_001d04d0(void*);
// Method5's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Owner_2d960 {};
typedef void (Owner_2d960::*Fn_2d960)();
class Method5 : public ScriptFunctionFields {
  public:
    virtual void Dummy();
    Fn_2d960 arg;
    Method5* Build(const char* p2, Fn_2d960 p3);
};
Method5* Method5::Build(const char* p2, Fn_2d960 p3) {
    ((ThisCall_001d0480*)(this))->Init_001d0480(p2, 5);
    *(void**)this = (void*)DAT_003f423c;
    arg = p3;
    retType = Get_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = Get_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[1] = Get_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[2] = Get_001d04d0(((char*)&DAT_0048e128));
    argTypes[3] = Get_001d04d0(((char*)&DAT_0048e128));
    argTypes[4] = Get_001d04d0(((char*)&DAT_0048e128));
    return this;
}
} // namespace fn_0002d960


// 0x0002d9e0 Method5<CActorManager,void,const_char_*,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x0002d9e0.cpp
// sym: ??_G?$Method5@UCActorManager@@XPBDPBDMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CActorManager, void, const char *, const char *, float, float, float>::~Method5() {}


// 0x0002da00 Method5<CActorManager,void,const_char_*,const_char_*,float,float,float>::vfunc_2 (30 B): matches/0x0002da00.cpp
// sym: ?vfunc_2@?$Method5@UCActorManager@@XPBDPBDMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method5<CActorManager, void, const char *, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0002da20(a, b, c, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Method5<CActorManager, void, const char *, const char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2d9e0)
#endif


// 0x0002da20 FUN_0002da20 (50 B): matches/0x0002da20.cpp [wrapped: conflict: Callback]
// sym: ?FUN_0002da20@fn_0002da20@@YAXPAUCallback@1@RBIIP821@AEXIIIII@Z@Z
namespace fn_0002da20 {
struct Callback {
    void invoke(unsigned, unsigned, unsigned, unsigned, unsigned);
};
typedef void (Callback::*Method)(unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0002da20(Callback* object, const unsigned* volatile values, unsigned unused,
                          Method callback) {
    const unsigned* p = values;
    unsigned a = *p++;
    unsigned b = *p++;
    values = (const unsigned*)*p++;
    unsigned e = p[1];
    unsigned d = p[0];
    (object->*callback)(a, b, (hulk_uintptr)values, d, e);
}
} // namespace fn_0002da20

namespace fn_f8e68f21 {

// 0x0002da60 FUN_0002da60 (89 B): matches/0x0002da60.cpp
// sym: ??0Method3_2da60@fn_f8e68f21@@QAE@PBDP8Owner_2da60@1@AEXXZ@Z
Method3_2da60::Method3_2da60(const char* p, Fn_2da60 x) {
    Init_001d0480(p, 3);
    vf = (void*)DAT_003f424c;
    m1c = x;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_f8e68f21

// 0x0002dac0 Method3<CActorManager,bool,const_char_*,float,float>::vfunc_0 (30 B): matches/0x0002dac0.cpp
// sym: ??_G?$Method3@UCActorManager@@_NPBDMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CActorManager, bool, const char *, float, float>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<CActorManager, bool, const char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2dac0)
#endif


// 0x0002dae0 Method3<CActorManager,bool,const_char_*,float,float>::vfunc_2 (51 B): matches/0x0002dae0.cpp [wrapped: conflict: CActorManager; Fn; Function; Method3]
// sym: ?vfunc_2@Method3@fn_0002dae0@@UAEXPAVCActorManager@2@PAUArgs@2@PA_N@Z
namespace fn_0002dae0 {
class CActorManager {
  public:
    bool Do(const char*, float, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
typedef bool (CActorManager::*Fn)(const char*, float, float);
struct Args {
    const char* s;
    float x, y;
};
class Method3 : public Function {
    char pad[24];
    Fn fn;

  public:
    virtual void vfunc_2(CActorManager*, Args*, bool*);
};
void Method3::vfunc_2(CActorManager* obj, Args* args, bool* out) {
    Fn f = fn;
    const char* s = args->s;
    float x = args->x;
    float y = args->y;
    bool r = (obj->*f)(s, x, y);
    if (out)
        *out = r;
}
} // namespace fn_0002dae0

namespace fn_f8e68f21 {

// 0x0002db20 FUN_0002db20 (89 B): matches/0x0002db20.cpp
// sym: ?Init@Method3_2db20@fn_f8e68f21@@QAEPAV12@PBDP8Owner_2db20@2@AEXXZ@Z
Method3_2db20* Method3_2db20::Init(const char* arg1, Fn_2db20 arg2) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(arg1, 3);
    vftable = (void*)DAT_003f425c;
    member1c = arg2;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f8e68f21

// 0x0002db80 Method3<CActorManager,void,const_char_*,float,float>::vfunc_0 (30 B): matches/0x0002db80.cpp
// sym: ??_G?$Method3@UCActorManager@@XPBDMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CActorManager, void, const char *, float, float>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<CActorManager, void, const char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2db80)
#endif


// 0x0002dba0 Method3<CActorManager,void,const_char_*,float,float>::vfunc_2 (29 B): equivalent/0x0002dba0.cpp [wrapped: conflict: CActorManager; Function; Method3]
// sym: ?vfunc_2@Method3@fn_0002dba0@@UAEXPAUCActorManager@2@PAUActorArgs@2@PAX@Z @a7a6d240b96d @w05a13dc0adbf
namespace fn_0002dba0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,float,float>::vfunc_2 @ 0x0002dba0
struct CActorManager { void FUN_0002dba0(const char*, float, float); };
struct ActorArgs { const char* name; float first; float second; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* actor, ActorArgs* args, void* unused);
    char pad[0x18];
    void (CActorManager::*callback)(const char*, float, float);
};
void Method3::vfunc_2(CActorManager* actor, ActorArgs* args, void* unused) {
    (actor->*callback)(args->name, args->first, args->second);
}
} // namespace fn_0002dba0


// 0x0002dc10 Method2<CActorManager,bool,const_char_*,float>::vfunc_0 (30 B): matches/0x0002dc10.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, bool, const char *, float>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CActorManager, bool, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2dc10)
#endif


// 0x0002dc30 Method2<CActorManager,bool,const_char_*,float>::vfunc_2 (37 B): matches/0x0002dc30.cpp [wrapped: conflict: CActorManager; Function; Method2]
// sym: ?v2@Method2@fn_0002dc30@@QAEXPAVCActorManager@2@PAUArgs@2@PAD@Z
namespace fn_0002dc30 {
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class CActorManager {
  public:
    bool Act(const char*, float);
};
struct Args {
    const char* s;
    float f;
};
class Method2 : public Function {
    char pad[0x18];

  public:
    typedef bool (CActorManager::*Fn)(const char*, float);
    Fn fn;
    void v2(CActorManager* obj, Args* args, char* out);
};
void Method2::v2(CActorManager* obj, Args* args, char* out) {
    Fn f = fn;
    const char* s = args->s;
    float x = args->f;
    bool r = (obj->*f)(s, x);
    if (out)
        *out = r;
}
} // namespace fn_0002dc30

namespace fn_f8e68f21 {

// 0x0002dc60 FUN_0002dc60 (89 B): matches/0x0002dc60.cpp
// sym: ??0Method3_2dc60@fn_f8e68f21@@QAE@PBDP8Owner_2dc60@1@AEXXZ@Z
Method3_2dc60::Method3_2dc60(const char* a, Fn_2dc60 x) : Function_2dc60(a, 3) {
    *(void**)this = (void*)&hulk_at_003f427c;
    field1c = x;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e128));
}

} // namespace fn_f8e68f21

// 0x0002dcc0 Method3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x0002dcc0.cpp
// sym: ??_G?$Method3@UCActorManager@@XPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CActorManager, void, const char *, const char *, float>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<CActorManager, void, const char *, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2dcc0)
#endif


// 0x0002dce0 Method3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_2 (29 B): equivalent/0x0002dce0.cpp [wrapped: conflict: Function; Method3]
// sym: ?vfunc_2@Method3@fn_0002dce0@@UAEXPAUCActorManager@2@PBUActorArguments@2@PAX@Z @a7a6d240b96d @w69b19def5989
namespace fn_0002dce0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x0002dce0
struct CActorManager {};
struct ActorArguments { const char *first; const char *second; float value; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager *manager, const ActorArguments *arguments, void *unused);
    char padding[0x18];
    void (CActorManager::*callback)(const char *, const char *, float);
};
void Method3::vfunc_2(CActorManager *manager, const ActorArguments *arguments, void *unused) {
    (manager->*callback)(arguments->first, arguments->second, arguments->value);
}
} // namespace fn_0002dce0

namespace fn_f8e68f21 {

// 0x0002dd00 FUN_0002dd00 (102 B): matches/0x0002dd00.cpp
// sym: ??0Method4_2dd00@fn_f8e68f21@@QAE@PBDP8Owner_2dd00@1@AEXXZ@Z
Method4_2dd00::Method4_2dd00(const char* a, Fn_2dd00 b) : FUN_001d0480(a, 4) {
    vptr = (void*)DAT_003f428c;
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_f8e68f21

// 0x0002dd70 Method4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_0 (30 B): matches/0x0002dd70.cpp
// sym: ??_G?$Method4@UCActorManager@@XPBDPBDMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CActorManager, void, const char *, const char *, float, float>::~Method4() {}
#if defined(HULK_PTR64)
template class Method4<CActorManager, void, const char *, const char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2dd70)
#endif


// 0x0002dd90 Method4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_2 (40 B): equivalent/0x0002dd90.cpp [wrapped: conflict: Method4]
// sym: ?vfunc_2@Method4@fn_0002dd90@@UAEXPAUCActorManager@2@PBUArguments@2@PAX@Z @06f2e20faa8a @wf51ff9f09ecf
namespace fn_0002dd90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_2 @ 0x0002dd90
struct CActorManager {};
struct Arguments { const char* first; const char* second; float third; float fourth; };
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager* manager, const Arguments* arguments, void* unused);
    char padding[0x18];
    void (CActorManager::*callback)(const char*, const char*, float, float);
};
void Method4::vfunc_2(CActorManager* manager, const Arguments* arguments, void* unused) {
    (manager->*callback)(arguments->first, arguments->second, arguments->third, arguments->fourth);
}
} // namespace fn_0002dd90


// 0x0002de10 Method2<CActorManager,const_char_*,const_char_*,int>::vfunc_0 (30 B): matches/0x0002de10.cpp
// sym: ??_G?$Method2@UCActorManager@@PBDPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, const char *, const char *, int>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CActorManager, const char *, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2de10)
#endif


// 0x0002de30 Method2<CActorManager,const_char_*,const_char_*,int>::vfunc_2 (33 B): matches/0x0002de30.cpp [wrapped: conflict: CActorManager; Function; Method2]
// sym: ?v2@Method2@fn_0002de30@@UAEXPAVCActorManager@2@PAUArgs@2@PAH@Z
namespace fn_0002de30 {
class CActorManager {
  public:
    int Act(const char*, const char*);
};
struct Args {
    const char* a;
    const char* b;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager*, Args*, int*);
};
class Method2 : public Function {
    char pad[0x18];

  public:
    typedef int (CActorManager::*Fn)(const char*, const char*);
    Fn fn;
    void v2(CActorManager*, Args*, int*);
};
void Method2::v2(CActorManager* obj, Args* args, int* out) {
    Fn f = fn;
    const char* a = args->a;
    const char* b = args->b;
    int r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
} // namespace fn_0002de30


// 0x0002deb0 Method2<CActorManager,int,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002deb0.cpp
// sym: ??_G?$Method2@UCActorManager@@HPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, int, const char *, const char *>::~Method2() {}


// 0x0002ded0 Method2<CActorManager,int,const_char_*,const_char_*>::vfunc_2 (33 B): matches/0x0002ded0.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@HPBDPBD@@UAEXPAX00@Z
template <> void Method2<CActorManager, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2ded0 * a = (CActorManager_2ded0 *)__p0; const char ** b = (const char **)__p1; int * out = (int *)__p2;

    int (CActorManager_2ded0::*f)(const char*, const char*) = (*(int (CActorManager_2ded0::**)(const char *, const char *))&this->f_1c);
    const char* x = b[0];
    const char* y = b[1];
    int r = (a->*f)(x, y);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, int, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2deb0)
#endif


// 0x0002df50 Method2<CActorManager,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002df50.cpp
// sym: ??_G?$Method2@UCActorManager@@PBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, const char *, const char *, const char *>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CActorManager, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2df50)
#endif


// 0x0002df70 Method2<CActorManager,const_char_*,const_char_*,const_char_*>::vfunc_2 (33 B): matches/0x0002df70.cpp [wrapped: conflict: CActorManager; Function; Method2]
// sym: ?vfunc_2@Method2@fn_0002df70@@UAEXPAVCActorManager@2@PAUArgs@2@PAH@Z
namespace fn_0002df70 {
class CActorManager {
  public:
    int Do(const char*, const char*);
};
struct Args {
    const char* a;
    const char* b;
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager*, Args*, int*);
};
class Method2 : public Function {
  public:
    char pad[24];
    typedef int (CActorManager::*MemFn)(const char*, const char*);
    MemFn fn;
    virtual void vfunc_2(CActorManager*, Args*, int*);
};
void Method2::vfunc_2(CActorManager* obj, Args* args, int* out) {
    MemFn f = fn;
    const char* a = args->a;
    const char* b = args->b;
    int result = (obj->*f)(a, b);
    if (out)
        *out = result;
}
} // namespace fn_0002df70


// 0x0002dfe0 Method1<CActorManager,void,float>::vfunc_0 (30 B): matches/0x0002dfe0.cpp
// sym: ??_G?$Method1@UCActorManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, void, float>::~Method1() {}


// 0x0002e000 Method1<CActorManager,void,float>::vfunc_2 (19 B): matches/0x0002e000.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CActorManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_2e000* d = (Dummy_2e000*)a;
    (d->*(*(void (Dummy_2e000::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2dfe0)
#endif


// 0x0002e060 Method0<CActorManager,float>::vfunc_0 (30 B): matches/0x0002e060.cpp
// sym: ??_G?$Method0@UCActorManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CActorManager, float>::~Method0() {}
#if defined(HULK_PTR64)
template class Method0<CActorManager, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e060)
#endif


// 0x0002e080 Method0<CActorManager,float>::vfunc_2 (34 B): matches/0x0002e080.cpp [wrapped: conflict: Function]
// sym: ?f2@Method0Base_2e080@fn_0002e080@@UAEXPAX0PAM@Z
namespace fn_0002e080 {
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_2e080 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_2e080::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
} // namespace fn_0002e080


// 0x0002e100 Method2<CActorManager,math::Vector,math::Vector,float>::vfunc_0 (30 B): matches/0x0002e100.cpp
// sym: ??_G?$Method2@UCActorManager@@VVector@math@@V23@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager,math::Vector,math::Vector, float>::~Method2() {}


// 0x0002e120 Method2<CActorManager,math::Vector,math::Vector,float>::vfunc_2 (106 B): equivalent/0x0002e120.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@VVector@math@@V23@M@@UAEXPAX00@Z @ffc0ee1e1efd @w466ac40d7f4e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CActorManager,math::Vector,math::Vector,float>::vfunc_2 @ 0x0002e120
template <> void Method2<CActorManager,math::Vector,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e120 * owner = (CActorManager_2e120 *)__p0; CallParams * params = (CallParams *)__p1; Vector_2e120 * out = (Vector_2e120 *)__p2;

    Vector_2e120 result = (owner->*(*(VectorMethod *)&this->f_1c))(params->arg, params->scale);
    if (out != 0)
        *out = result;
}
#if defined(HULK_PTR64)
template class Method2<CActorManager,math::Vector,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e100)
#endif


// 0x0002e1e0 Method2<CActorManager,float,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002e1e0.cpp
// sym: ??_G?$Method2@UCActorManager@@MPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, float, const char *, const char *>::~Method2() {}


// 0x0002e200 Method2<CActorManager,float,const_char_*,const_char_*>::vfunc_2 (46 B): matches/0x0002e200.cpp
// sym: ?vfunc_2@?$Method2@UCActorManager@@MPBDPBD@@UAEXPAX00@Z
template <> void Method2<CActorManager, float, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e200 * obj = (CActorManager_2e200 *)__p0; Args * args = (Args *)__p1; float * out = (float *)__p2;

    MemFn f = (*(MemFn *)&this->f_1c);
    const char* a = args->a;
    const char* b = args->b;
    float r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
#if defined(HULK_PTR64)
template class Method2<CActorManager, float, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e1e0)
#endif


// 0x0002e270 Method1<CActorManager,void,bool>::vfunc_0 (30 B): matches/0x0002e270.cpp
// sym: ??_G?$Method1@UCActorManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CActorManager, void, bool>::~Method1() {}


// 0x0002e290 Method1<CActorManager,void,bool>::vfunc_2 (21 B): matches/0x0002e290.cpp
// sym: ?vfunc_2@?$Method1@UCActorManager@@X_N@@UAEXPAX00@Z
template <> void Method1<CActorManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e290 * obj = (CActorManager_2e290 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_2e290 *)&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CActorManager, void, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e270)
#endif

namespace fn_f8e68f21 {

// 0x0002e2b0 FUN_0002e2b0 (89 B): matches/0x0002e2b0.cpp
// sym: ??0Method3_2e2b0@fn_f8e68f21@@QAE@HH@Z
Method3_2e2b0::Method3_2e2b0(hulk_intptr a, hulk_intptr b) : Function_2e2b0(a, 3) {
    v = ((hulk_intptr)DAT_003f431c);
    m1c = b;
    *((char*)this + 0x18) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    *((char*)this + 0x10) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x11) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x12) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}

} // namespace fn_f8e68f21

// 0x0002e310 Method3<CActorManager,void,int,int,int>::vfunc_0 (30 B): matches/0x0002e310.cpp
// sym: ??_G?$Method3@UCActorManager@@XHHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CActorManager, void, int, int, int>::~Method3() {}
#if defined(HULK_PTR64)
template class Method3<CActorManager, void, int, int, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e310)
#endif


// 0x0002e330 Method3<CActorManager,void,int,int,int>::vfunc_2 (29 B): equivalent/0x0002e330.cpp [wrapped: conflict: Args; CActorManager; Function; Method3]
// sym: ?vfunc_2@Method3@fn_0002e330@@UAEXPAUCActorManager@2@PAUArgs@2@H@Z @a7a6d240b96d @w9b83a8b8e93b
namespace fn_0002e330 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,int,int,int>::vfunc_2 @ 0x0002e330
struct CActorManager { void FUN_0002e330(int, int, int); };
struct Args { int first, second, third; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_2(CActorManager* actor, Args* args, int unused);
    char pad[0x18];
    void (CActorManager::*callback)(int,int,int);
};
void Method3::vfunc_2(CActorManager* actor, Args* args, int unused) {
    (actor->*callback)(args->first, args->second, args->third);
}
} // namespace fn_0002e330


// 0x0002e350 FUN_0002e350 (89 B): matches/0x0002e350.cpp [wrapped: conflict: DAT_0048e10c; Method3]
// sym: ??0Method3@fn_0002e350@@QAE@PBDP8Owner_2e350@1@AEXXZ@Z
namespace fn_0002e350 {
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

extern "C" char DAT_003f432c[];
class Function_2e350 {
  public:
    void Init_001d0480(const char*, int);
};
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class Owner_2e350 {};
typedef void (Owner_2e350::*Fn_2e350)();
class Method3 : public Function_2e350 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_2e350 m1c;
    Method3(const char*, Fn_2e350);
};
extern const char s2_2e350[];
extern const char DAT_0048e10c[];
Method3::Method3(const char* a, Fn_2e350 x) {
    Init_001d0480(a, 3);
    v = (void*)DAT_003f432c;
    m1c = x;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(DAT_0048e10c);
    f.argTypes[2] = FUN_001d04d0(DAT_0048e10c);
}
} // namespace fn_0002e350
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0002e3b0 Method3<CActorManager,bool,const_char_*,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x0002e3b0.cpp
// sym: ??_G?$Method3@UCActorManager@@_NPBDVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CActorManager, bool, const char *,math::Vector,math::Vector>::~Method3() {}


// 0x0002e3d0 Method3<CActorManager,bool,const_char_*,math::Vector,math::Vector>::vfunc_2 (102 B): equivalent/0x0002e3d0.cpp
// sym: ?vfunc_2@?$Method3@UCActorManager@@_NPBDVVector@math@@V23@@@UAEXPAX00@Z @7c392f6af52b @w28fcddcb9c47
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CActorManager,bool,const_char_*,math::Vector,math::Vector>::vfunc_2 @ 0x0002e3d0
template <> void Method3<CActorManager, bool, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e3d0 * owner = (CActorManager_2e3d0 *)__p0; Args_2e3d0 * args = (Args_2e3d0 *)__p1; bool * result = (bool *)__p2;

    bool r = (owner->*(*(ActorFn_2e3d0 *)&this->f_1c))(args->name, args->a, args->b);
    if (result)
        *result = r;
}
#if defined(HULK_PTR64)
template class Method3<CActorManager, bool, const char *,math::Vector,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e3b0)
#endif


// 0x0002e490 Method2<CActorManager,bool,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x0002e490.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CActorManager, bool, const char *,math::Vector>::~Method2() {}
#if defined(HULK_PTR64)
template class Method2<CActorManager, bool, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e490)
#endif


// 0x0002e4f0 FUN_0002e4f0 (89 B): matches/0x0002e4f0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002e4f0@@QAE@PBDPAVOwner_2e4f0@1@P821@AEXXZ@Z
namespace fn_0002e4f0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f402c[2];
extern void* hulk_at_003f434c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2e4f0 {};
typedef void (Owner_2e4f0::*Fn_2e4f0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2e4f0 fn;            // 0x1c
    Owner_2e4f0* owner;     // 0x20
    Closure2(const char* a1, Owner_2e4f0* a2, Fn_2e4f0 a3);
};

Closure2::Closure2(const char* a1, Owner_2e4f0* a2, Fn_2e4f0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f402c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    vfptr = (void*)hulk_at_003f434c;
    owner = a2;
}
} // namespace fn_0002e4f0


// 0x0002e550 Closure2<CActorManager,bool,const_char_*,bool>::vfunc_0 (30 B): matches/0x0002e550.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, bool, const char *, bool>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, bool, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e550)
#endif


// 0x0002e570 Closure2<CActorManager,bool,const_char_*,bool>::vfunc_2 (46 B): equivalent/0x0002e570.cpp [wrapped: conflict: Arguments; CActorManager]
// sym: ?vfunc_2@Closure2_CActorManager_bool_const_char_bool@fn_0002e570@@UAEXPAXPAUArguments@2@PA_N@Z @8eb15ebc569e @w77c25302b90b
namespace fn_0002e570 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,bool>::vfunc_2 @ 0x0002e570
struct CActorManager { char unused; };
struct Arguments { const char *text; bool flag; };
class Closure2_CActorManager_bool_const_char_bool {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, Arguments *arguments, bool *result);
private:
    char padding[0x18];
    bool (CActorManager::*method)(const char *, bool);
    CActorManager *object;
};
void Closure2_CActorManager_bool_const_char_bool::vfunc_2(void *unused, Arguments *arguments, bool *result)
{
    bool value = (object->*method)(arguments->text, arguments->flag);
    if (result) *result = value;
}
} // namespace fn_0002e570


// 0x0002e5a0 FUN_0002e5a0 (89 B): matches/0x0002e5a0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002e5a0@@QAE@PBDPAVOwner_2e5a0@1@P821@AEXXZ@Z
namespace fn_0002e5a0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f403c[2];
extern void* hulk_at_003f435c[2];
extern void* hulk_at_0048e10c;

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2e5a0 {};
typedef void (Owner_2e5a0::*Fn_2e5a0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2e5a0 fn;            // 0x1c
    Owner_2e5a0* owner;     // 0x20
    Closure2(const char* a1, Owner_2e5a0* a2, Fn_2e5a0 a3);
};

Closure2::Closure2(const char* a1, Owner_2e5a0* a2, Fn_2e5a0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f403c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(&hulk_at_0048e10c);
    vfptr = (void*)hulk_at_003f435c;
    owner = a2;
}
} // namespace fn_0002e5a0


// 0x0002e600 Closure2<CActorManager,void,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x0002e600.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void, const char *,math::Vector>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e600)
#endif


// 0x0002e620 Closure2<CActorManager,void,const_char_*,math::Vector>::vfunc_2 (47 B): equivalent/0x0002e620.cpp [wrapped: conflict: Arguments; CActorManager; Closure2]
// sym: ?vfunc_2@Closure2@fn_0002e620@@UAEXPAXPBUArguments@2@0@Z @967618bc6127 @wf30778dea4a0
namespace fn_0002e620 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure2<CActorManager,void,const_char_*,math::Vector>::vfunc_2 @ 0x0002e620
struct Vector { float x, y, z; };
struct Arguments { const char *name; Vector position; };
class CActorManager {};
class Closure2;
typedef void (__fastcall *ActorMethod)(CActorManager *, Closure2 *, const char *, Vector);
class Closure2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const Arguments *arguments, void *unused2);
    char reserved[0x18];
    ActorMethod method;
    CActorManager *actor;
};
void Closure2::vfunc_2(void *unused, const Arguments *arguments, void *unused2) {
    method(actor, this, arguments->name, arguments->position);
}
} // namespace fn_0002e620


// 0x0002e650 FUN_0002e650 (89 B): matches/0x0002e650.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002e650@@QAE@PBDPAVOwner_2e650@1@P821@AEXXZ@Z
namespace fn_0002e650 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f404c[2];
extern void* hulk_at_003f436c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2e650 {};
typedef void (Owner_2e650::*Fn_2e650)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2e650 fn;            // 0x1c
    Owner_2e650* owner;     // 0x20
    Closure2(const char* a1, Owner_2e650* a2, Fn_2e650 a3);
};

Closure2::Closure2(const char* a1, Owner_2e650* a2, Fn_2e650 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f404c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_003f436c;
    owner = a2;
}
} // namespace fn_0002e650


// 0x0002e6b0 Closure2<CActorManager,void,const_char_*,float>::vfunc_0 (30 B): matches/0x0002e6b0.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void, const char *, float>::~Closure2() {}


// 0x0002e6d0 Closure2<CActorManager,void,const_char_*,float>::vfunc_2 (22 B): matches/0x0002e6d0.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@XPBDM@@UAEXPAX00@Z
template <> void Closure2<CActorManager, void, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2e6d0 * p = (Pair_2e6d0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2e6d0 * *)&this->f_20)->*(*(void (CActorManager_2e6d0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e6b0)
#endif


// 0x0002e6f0 FUN_0002e6f0 (89 B): matches/0x0002e6f0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002e6f0@@QAE@PBDPAVOwner_2e6f0@1@P821@AEXXZ@Z
namespace fn_0002e6f0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f405c[2];
extern void* hulk_at_003f437c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2e6f0 {};
typedef void (Owner_2e6f0::*Fn_2e6f0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2e6f0 fn;            // 0x1c
    Owner_2e6f0* owner;     // 0x20
    Closure2(const char* a1, Owner_2e6f0* a2, Fn_2e6f0 a3);
};

Closure2::Closure2(const char* a1, Owner_2e6f0* a2, Fn_2e6f0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f405c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_003f437c;
    owner = a2;
}
} // namespace fn_0002e6f0


// 0x0002e750 Closure2<CActorManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x0002e750.cpp
// sym: ??_G?$Method1@UCActorManager@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void, const char *, int>::~Closure2() {}


// 0x0002e770 Closure2<CActorManager,void,const_char_*,int>::vfunc_2 (22 B): matches/0x0002e770.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CActorManager, void, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2e770 * p = (Pair_2e770 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2e770 * *)&this->f_20)->*(*(void (CActorManager_2e770::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e750)
#endif


// 0x0002e790 FUN_0002e790 (76 B): matches/0x0002e790.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1_2e790@fn_0002e790@@QAE@PBDPAVOwner_2e790@1@P821@AEXXZ@Z
namespace fn_0002e790 {
// data: textA = DAT_0048e128, textB = DAT_0048e0f0

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) char __cdecl Check_001d04d0(const char*);
class Base : public CtorV_001d0480 {
  public:
    Base(const char* x) : CtorV_001d0480(x, 1) { }
};
class Owner_2e790 {};
typedef void (Owner_2e790::*Fn_2e790)();
class Method : public Base {
  public:
    virtual bool Fnf_001d04c0(int, int);
    Fn_2e790 name;
    Owner_2e790* val;
    Method(const char*, Owner_2e790*, Fn_2e790);
};
class Closure1_2e790 : public Method {
  public:
    virtual void Fng_0002e800(void*, void*, void*);
    Closure1_2e790(const char*, Owner_2e790*, Fn_2e790);
};
Closure1_2e790::Closure1_2e790(const char* x, Owner_2e790* y, Fn_2e790 z) : Method(x, y, z) {
    val = y;
}
Method::Method(const char* x, Owner_2e790* y, Fn_2e790 z) : Base(x) {
    name = z;
    retType = Check_001d04d0(((const char*)&DAT_0048e128));
    argTypes[0] = Check_001d04d0(((const char*)&DAT_0048e0f0));
}
} // namespace fn_0002e790


// 0x0002e7e0 Closure1<CActorManager,float,const_char_*>::vfunc_0 (30 B): matches/0x0002e7e0.cpp
// sym: ??_G?$Method3@UCActorManager@@XPBDMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, float, const char *>::~Closure1() {}


// 0x0002e800 Closure1<CActorManager,float,const_char_*>::vfunc_2 (43 B): matches/0x0002e800.cpp
// sym: ?vfunc_2@?$Closure1@UCActorManager@@MPBD@@UAEXPAX00@Z
template <> void Closure1<CActorManager, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr ignored = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_2e800* obj = (*(CActorManager_2e800 * *)&this->f_20);
    Fn_2e800 fn = (*(Fn_2e800 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e7e0)
#endif

namespace fn_f8e68f21 {

// 0x0002e830 FUN_0002e830 (76 B): matches/0x0002e830.cpp
// sym: ?Build@Closure1_2e830@fn_f8e68f21@@QAEPAU12@PBDPAVOwner_2e830@2@P832@AEXXZ@Z
Closure1_2e830* Closure1_2e830::Build(const char* a, Owner_2e830* b, Fn_2e830 c) {
    ((ThisCall_001d0480*)(this))->InitHelper_001d0480(a, 1);
    vptr = (void*)DAT_003f407c;
    m1c = c;
    f.retType = GetHelper_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = GetHelper_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    vptr = (void*)DAT_003f439c;
    m20 = b;
    return this;
}

} // namespace fn_f8e68f21

// 0x0002e880 Closure1<CActorManager,bool,const_char_*>::vfunc_0 (30 B): matches/0x0002e880.cpp
// sym: ??_G?$Method1@UCActorManager@@HPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, bool, const char *>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e880)
#endif


// 0x0002e8a0 Closure1<CActorManager,bool,const_char_*>::vfunc_2 (30 B): matches/0x0002e8a0.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_0002e8a0@@UAEXPAXPAPBDPA_N@Z
namespace fn_0002e8a0 {
// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void*, const char**, bool*);
    char pad[0x18];
    typedef bool(__fastcall* Fn)(void*, const char*, const char*);
    Fn mFn;
    void* mObj;
};
void Closure1::V2(void* a, const char** p, bool* out) {
    void* obj = mObj;
    Fn fn = mFn;
    bool r = fn(obj, *p, *p);
    if (out)
        *out = r;
}
} // namespace fn_0002e8a0


// 0x0002e8f0 Closure3<CActorManager,void,const_char_*,float,bool>::vfunc_0 (30 B): matches/0x0002e8f0.cpp
// sym: ??_G?$Method1@UCActorManager@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CActorManager, void, const char *, float, bool>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CActorManager, void, const char *, float, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e8f0)
#endif


// 0x0002e960 Closure3<CActorManager,void,const_char_*,float,const_char_*>::vfunc_0 (30 B): matches/0x0002e960.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBD_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CActorManager, void, const char *, float, const char *>::~Closure3() {}


// 0x0002e980 Closure3<CActorManager,void,const_char_*,float,const_char_*>::vfunc_2 (28 B): matches/0x0002e980.cpp
// sym: ?vfunc_2@?$Closure3@UCActorManager@@XPBDMPBD@@UAEXPAX00@Z
template <> void Closure3<CActorManager, void, const char *, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * args = (Arguments *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    const char* name = args->name;
    _ReadWriteBarrier();
    const char* other = args->other;
    float value = args->value;
    ((*(CActorManager_2e980 * *)&this->f_20)->*(*(void (CActorManager_2e980::**)(const char *, float, const char *))&this->f_1c))(name, value, other);
    _ReadWriteBarrier();
}
#if defined(HULK_PTR64)
template class Closure3<CActorManager, void, const char *, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e960)
#endif


// 0x0002e9a0 FUN_0002e9a0 (76 B): matches/0x0002e9a0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0002e9a0@@QAE@PBDPAVOwner_2e9a0@1@P821@AEXXZ@Z
namespace fn_0002e9a0 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct Function_2e9a0 : public ScriptFunctionFields {
    virtual void f0();
    Function_2e9a0(const char*, int);
};
class Owner_2e9a0 {};
typedef void (Owner_2e9a0::*Fn_2e9a0)();
struct Method1 : Function_2e9a0 {
    Method1(const char* a, Fn_2e9a0 b) : Function_2e9a0(a, 1) {
        m1c = b;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    virtual void f0();
    Fn_2e9a0 m1c;
};
struct Closure1 : Method1 {
    Closure1(const char* a, Owner_2e9a0* c, Fn_2e9a0 b);
    virtual void f0();
    Owner_2e9a0* m20;
};
Closure1::Closure1(const char* a, Owner_2e9a0* c, Fn_2e9a0 b) : Method1(a, b) {
    m20 = c;
}
} // namespace fn_0002e9a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0002e9f0 Closure1<CActorManager,int,const_char_*>::vfunc_0 (30 B): matches/0x0002e9f0.cpp
// sym: ??_G?$Method2@UCActorManager@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, int, const char *>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2e9f0)
#endif


// 0x0002ea10 Closure1<CActorManager,int,const_char_*>::vfunc_2 (30 B): matches/0x0002ea10.cpp [wrapped: conflict: ActorMethod; CActorManager]
// sym: ?vfunc_2@Closure1_CActorManager_int_const_char@fn_0002ea10@@QAEXPAXPAPBDPAH@Z
namespace fn_0002ea10 {
struct CActorManager {
    int FUN_00000000(const char*);
};
typedef int (CActorManager::*ActorMethod)(const char*);
struct Closure1_CActorManager_int_const_char {
    char padding[0x1c];
    ActorMethod method;
    CActorManager* actor;
    void vfunc_2(void* unused, const char** argument, int* result);
};
void Closure1_CActorManager_int_const_char::vfunc_2(void* unused, const char** argument, int* result) {
    CActorManager* a = actor;
    ActorMethod fn = method;
    int value = (a->*fn)(*argument);
    if (result)
        *result = value;
}
} // namespace fn_0002ea10


// 0x0002ea30 FUN_0002ea30 (76 B): matches/0x0002ea30.cpp [wrapped: conflict: Closure1]
// sym: ??0Closure1@fn_0002ea30@@QAE@PBDPAVOwner_2ea30@1@P821@AEXXZ@Z
namespace fn_0002ea30 {

extern void* hulk_at_003f40bc[2];
extern void* hulk_at_003f43dc[2];

// Closure1's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2ea30 {};
typedef void (Owner_2ea30::*Fn_2ea30)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure1 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2ea30 fn;            // 0x1c
    Owner_2ea30* owner;     // 0x20
    Closure1(const char* a1, Owner_2ea30* a2, Fn_2ea30 a3);
};

Closure1::Closure1(const char* a1, Owner_2ea30* a2, Fn_2ea30 a3) : FUN_001d0480(a1, 1) {
    vfptr = (void*)hulk_at_003f40bc;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_003f43dc;
    owner = a2;
}
} // namespace fn_0002ea30


// 0x0002ea80 Closure1<CActorManager,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002ea80.cpp
// sym: ??_G?$Method1@UCActorManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, const char *, const char *>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ea80)
#endif


// 0x0002eaa0 Closure1<CActorManager,const_char_*,const_char_*>::vfunc_2 (30 B): matches/0x0002eaa0.cpp [wrapped: conflict: CActorManager; Closure1]
// sym: ?v2@Closure1@fn_0002eaa0@@UAEHHPAPBDPAH@Z
namespace fn_0002eaa0 {
class CActorManager {
  public:
    int f(const char*);
};

class Closure1 {
  public:
    virtual void v0();
    virtual void v1();
    virtual int v2(int a, const char** b, int* out);
    char pad[0x18];
    int (CActorManager::*mFn)(const char*);
    CActorManager* mObj;
};

int Closure1::v2(int a, const char** b, int* out) {
    CActorManager* o = mObj;
    int (CActorManager::*fn)(const char*) = mFn;
    const char* p = *b;
    int r = (o->*fn)(p);
    if (out)
        *out = r;
    return r;
}
} // namespace fn_0002eaa0


// 0x0002eaf0 Closure6<CActorManager,bool,const_char_*,const_char_*,const_char_*,const_char_*,bool,const_char_*>::vfunc_0 (30 B): matches/0x0002eaf0.cpp
// sym: ??_G?$Method0@UCActorManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CActorManager, bool, const char *, const char *, const char *, const char *, bool, const char *>::~Closure6() {}
#if defined(HULK_PTR64)
template class Closure6<CActorManager, bool, const char *, const char *, const char *, const char *, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2eaf0)
#endif


// 0x0002eba0 Closure7<CActorManager,bool,const_char_*,math::Vector,float,const_char_*,const_char_*,bool,const_char_*>::vfunc_0 (30 B): matches/0x0002eba0.cpp
// sym: ??_G?$Method1@UCActorManager@@PBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure7<CActorManager, bool, const char *,math::Vector, float, const char *, const char *, bool, const char *>::~Closure7() {}


// 0x0002ebc0 Closure7<CActorManager,bool,const_char_*,math::Vector,float,const_char_*,const_char_*,bool,const_char_*>::vfunc_2 (29 B): matches/0x0002ebc0.cpp
// sym: ?vfunc_2@?$Closure7@UCActorManager@@_NPBDVVector@math@@MPBDPBD_NPBD@@UAEXPAX00@Z
template <> void Closure7<CActorManager, bool, const char *,math::Vector, float, const char *, const char *, bool, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Closure7<CActorManager, bool, const char *,math::Vector, float, const char *, const char *, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2eba0)
#endif


// 0x0002ebe0 FUN_0002ebe0 (89 B): matches/0x0002ebe0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002ebe0@@QAE@PBDPAVOwner_2ebe0@1@P821@AEXXZ@Z
namespace fn_0002ebe0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f40ec[2];
extern void* hulk_at_003f440c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2ebe0 {};
typedef void (Owner_2ebe0::*Fn_2ebe0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2ebe0 fn;            // 0x1c
    Owner_2ebe0* owner;     // 0x20
    Closure2(const char* a1, Owner_2ebe0* a2, Fn_2ebe0 a3);
};

Closure2::Closure2(const char* a1, Owner_2ebe0* a2, Fn_2ebe0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f40ec;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    vfptr = (void*)hulk_at_003f440c;
    owner = a2;
}
} // namespace fn_0002ebe0


// 0x0002ec40 Closure2<CActorManager,void,const_char_*,bool>::vfunc_0 (30 B): matches/0x0002ec40.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void, const char *, bool>::~Closure2() {}


// 0x0002ec60 Closure2<CActorManager,void,const_char_*,bool>::vfunc_2 (24 B): matches/0x0002ec60.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@XPBD_N@@UAEXPAX00@Z
template <> void Closure2<CActorManager, void, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_2ec60 * p = (Arg_2ec60 *)__p1;

    ((*(Actor_2ec60 * *)&this->f_20)->*(*(void (Actor_2ec60::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void, const char *, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ec40)
#endif


// 0x0002ec80 FUN_0002ec80 (89 B): matches/0x0002ec80.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002ec80@@QAE@PBDPAVOwner_2ec80@1@P821@AEXXZ@Z
namespace fn_0002ec80 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f40fc[2];
extern void* hulk_at_003f441c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2ec80 {};
typedef void (Owner_2ec80::*Fn_2ec80)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2ec80 fn;            // 0x1c
    Owner_2ec80* owner;     // 0x20
    Closure2(const char* a1, Owner_2ec80* a2, Fn_2ec80 a3);
};

Closure2::Closure2(const char* a1, Owner_2ec80* a2, Fn_2ec80 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f40fc;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_003f441c;
    owner = a2;
}
} // namespace fn_0002ec80


// 0x0002ece0 Closure2<CActorManager,void,float,float>::vfunc_0 (30 B): matches/0x0002ece0.cpp
// sym: ??_G?$Method2@UCActorManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void, float, float>::~Closure2() {}


// 0x0002ed00 Closure2<CActorManager,void,float,float>::vfunc_2 (22 B): matches/0x0002ed00.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CActorManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2ed00 * p = (Pair_2ed00 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2ed00 * *)&this->f_20)->*(*(void (CActorManager_2ed00::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ece0)
#endif

namespace fn_f8e68f21 {

// 0x0002ed20 FUN_0002ed20 (76 B): matches/0x0002ed20.cpp
// sym: ??0Closure1_2ed20@fn_f8e68f21@@QAE@PBDPAXPAUCActorManager@@@Z
Closure1_2ed20::Closure1_2ed20(const char* arg, void* p, CActorManager* cm) {
    Init_001d0480(arg, 1);
    vt = ((hulk_intptr)DAT_003f410c);
    p1c = cm;
    b18 = GetName_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = GetName_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    vt = ((hulk_intptr)DAT_003f442c);
    p20 = p;
}

} // namespace fn_f8e68f21

// 0x0002ed70 Closure1<CActorManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0002ed70.cpp
// sym: ??_G?$Method1@UCActorManager@@VVector@math@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, void, const char *>::~Closure1() {}


// 0x0002ed90 Closure1<CActorManager,void,const_char_*>::vfunc_2 (18 B): matches/0x0002ed90.cpp
// sym: ?vfunc_2@?$Closure1@UCActorManager@@XPBD@@UAEXPAX00@Z
template <> void Closure1<CActorManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2ed90 * *)&this->f_20)->*(*(void (CActorManager_2ed90::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ed70)
#endif


// 0x0002edf0 Closure0<CActorManager,const_char_*>::vfunc_0 (30 B): matches/0x0002edf0.cpp
// sym: ??_G?$Method1@UCActorManager@@XH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CActorManager, const char *>::~Closure0() {}


// 0x0002ee10 Closure0<CActorManager,const_char_*>::vfunc_2 (23 B): matches/0x0002ee10.cpp
// sym: ?vfunc_2@?$Closure0@UCActorManager@@PBD@@UAEXPAX00@Z
template <> void Closure0<CActorManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_2ee10* obj = (*(CActorManager_2ee10 * *)&this->f_20);
    int (CActorManager_2ee10::*fn)() = (*(int (CActorManager_2ee10::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Closure0<CActorManager, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2edf0)
#endif


// 0x0002ee70 Closure0<CActorManager,int>::vfunc_0 (30 B): matches/0x0002ee70.cpp
// sym: ??_G?$Method1@UCActorManager@@_NVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CActorManager, int>::~Closure0() {}


// 0x0002ee90 Closure0<CActorManager,int>::vfunc_2 (23 B): matches/0x0002ee90.cpp
// sym: ?vfunc_2@?$Closure0@UCActorManager@@PBD@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CActorManager, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_2ee90* obj = (*(CActorManager_2ee90 * *)&this->f_20);
    int (CActorManager_2ee90::*fn)() = (*(int (CActorManager_2ee90::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Closure0<CActorManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ee70)
#endif


// 0x0002eeb0 FUN_0002eeb0 (76 B): matches/0x0002eeb0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0002eeb0@@QAE@PBDHH@Z
namespace fn_0002eeb0 {
// data: textA = DAT_0048e0f0, textB = DAT_0048e134

extern "C++" __declspec(nothrow) unsigned char __cdecl getFlag_001d04d0(const char*);
class Function_2eeb0 {
  public:
    Function_2eeb0(const char*, int);
    virtual void f();
    char pad[12];
};
class Method1 : public Function_2eeb0 {
  public:
    Method1(const char* p, int x) : Function_2eeb0(p, 1) {
        value = x;
        flagA = getFlag_001d04d0(((char*)&DAT_0048e0f0));
        flagB = getFlag_001d04d0(((char*)&DAT_0048e134));
    }
    virtual void f();
    unsigned char flagB;
    char pad1[7];
    unsigned char flagA;
    char pad2[3];
    int value;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* p, int y, int x);
    virtual void f();
    int other;
};
Closure1::Closure1(const char* p, int y, int x) : Method1(p, x), other(y) {}
} // namespace fn_0002eeb0


// 0x0002ef00 Closure1<CActorManager,const_char_*,int>::vfunc_0 (30 B): matches/0x0002ef00.cpp
// sym: ??_G?$Method1@UCActorManager@@PBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, const char *, int>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2ef00)
#endif


// 0x0002ef20 Closure1<CActorManager,const_char_*,int>::vfunc_2 (30 B): matches/0x0002ef20.cpp [wrapped: conflict: CActorManager; Closure1]
// sym: ?vfunc_2@?$Closure1@VCActorManager@fn_0002ef20@@PBDH@fn_0002ef20@@UAEXPAXPAPBDPAH@Z
namespace fn_0002ef20 {
class CActorManager {};  // complete before the pointer-to-member: single-inheritance (4-byte) representation under every compiler
template <class T, class A, class R> class Closure1 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const char** argument, int* result);

  private:
    char padding[0x18];
    int (CActorManager::*method)(const char*);
    CActorManager* object;
};
template <>
void Closure1<CActorManager, const char*, int>::vfunc_2(void* unused, const char** argument, int* result) {
    CActorManager* obj = object;
    int (CActorManager::*fn)(const char*) = method;
    int value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}
} // namespace fn_0002ef20


// 0x0002ef40 FUN_0002ef40 (89 B): matches/0x0002ef40.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002ef40@@QAE@PBDPAVOwner_2ef40@1@P821@AEXXZ@Z
namespace fn_0002ef40 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f414c[2];
extern void* hulk_at_003f446c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2ef40 {};
typedef void (Owner_2ef40::*Fn_2ef40)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2ef40 fn;            // 0x1c
    Owner_2ef40* owner;     // 0x20
    Closure2(const char* a1, Owner_2ef40* a2, Fn_2ef40 a3);
};

Closure2::Closure2(const char* a1, Owner_2ef40* a2, Fn_2ef40 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f414c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_003f446c;
    owner = a2;
}
} // namespace fn_0002ef40


// 0x0002efa0 Closure2<CActorManager,bool,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002efa0.cpp
// sym: ??_G?$Method7@UCActorManager@@XPBDMMMMMPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, bool, const char *, const char *>::~Closure2() {}


// 0x0002efc0 Closure2<CActorManager,bool,const_char_*,const_char_*>::vfunc_2 (36 B): equivalent/0x0002efc0.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@_NPBDPBD@@UAEXPAX00@Z @e654de0dce29 @w4e3d89bebec6
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,const_char_*>::vfunc_2 @ 0x0002efc0
template <> void Closure2<CActorManager, bool, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** args = (const char **)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2efc0 * *)&this->f_20)->*(*(bool (CActorManager_2efc0::**)(const char *, const char *))&this->f_1c))(args[0], args[1]);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, bool, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2efa0)
#endif


// 0x0002eff0 FUN_0002eff0 (89 B): matches/0x0002eff0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002eff0@@QAE@PBDPAVOwner_2eff0@1@P821@AEXXZ@Z
namespace fn_0002eff0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f415c[2];
extern void* hulk_at_003f447c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2eff0 {};
typedef void (Owner_2eff0::*Fn_2eff0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2eff0 fn;            // 0x1c
    Owner_2eff0* owner;     // 0x20
    Closure2(const char* a1, Owner_2eff0* a2, Fn_2eff0 a3);
};

Closure2::Closure2(const char* a1, Owner_2eff0* a2, Fn_2eff0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f415c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_003f447c;
    owner = a2;
}
} // namespace fn_0002eff0


// 0x0002f050 Closure2<CActorManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002f050.cpp
// sym: ??_G?$Method2@UCActorManager@@XHPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void, const char *, const char *>::~Closure2() {}


// 0x0002f070 Closure2<CActorManager,void,const_char_*,const_char_*>::vfunc_2 (22 B): matches/0x0002f070.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CActorManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2f070 * p = (Pair_2f070 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2f070 * *)&this->f_20)->*(*(void (CActorManager_2f070::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f050)
#endif


// 0x0002f090 FUN_0002f090 (76 B): matches/0x0002f090.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_0002f090@@QAE@PAX00@Z
namespace fn_0002f090 {

extern char a[];
extern "C++" __declspec(nothrow) unsigned char __cdecl lookup_001d04d0(const char*);
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
    unsigned char flag10;
    char pad2[7];
    unsigned char flag18;
    char pad3[3];
    void* value;
};
class Closure1_2f090 : public Base {
  public:
    Closure1_2f090(void*, void*);
    virtual void f();
};
class Closure1 : public Closure1_2f090 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* other;
};
Closure1_2f090::Closure1_2f090(void* p, void* v) : Base(p, 1) {
    value = v;
    flag18 = lookup_001d04d0(a);
    flag10 = lookup_001d04d0(((char*)&DAT_0048e0f0));
}
Closure1::Closure1(void* p, void* v, void* q) : Closure1_2f090(p, q) {
    other = v;
}
} // namespace fn_0002f090


// 0x0002f0e0 Closure1<CActorManager,math::Vector,const_char_*>::vfunc_0 (30 B): matches/0x0002f0e0.cpp
// sym: ??_G?$Method2@UCActorManager@@XVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager,math::Vector, const char *>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager,math::Vector, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f0e0)
#endif


// 0x0002f100 Closure1<CActorManager,math::Vector,const_char_*>::vfunc_2 (70 B): equivalent/0x0002f100.cpp [wrapped: conflict: CActorManager]
// sym: ?vfunc_2@Closure@fn_0002f100@@UAEXPAXPAPBDPAUVector@2@@Z @307fff147072 @wb98e40599041
namespace fn_0002f100 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CActorManager,math::Vector,const_char_*>::vfunc_2 @ 0x0002f100
struct Vector { float x, y, z; };
struct CActorManager { Vector FUN_0002f100(const char *name); };
struct Closure {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **name, Vector *result);
    char pad[0x18];
    Vector (CActorManager::*method)(const char *);
    CActorManager *actorManager;
};
void Closure::vfunc_2(void *unused, const char **name, Vector *result) {
    Vector value = (actorManager->*method)(*name);
    if (result) *result = value;
}
} // namespace fn_0002f100


// 0x0002f150 FUN_0002f150 (76 B): matches/0x0002f150.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0002f150@@QAE@PBDPAVOwner_2f150@1@P821@AEXXZ@Z
namespace fn_0002f150 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Function_2f150 : public ScriptFunctionFields {
  public:
    Function_2f150(const char*, int);
    virtual void v();
};
class Owner_2f150 {};
typedef void (Owner_2f150::*Fn_2f150)();
class Method1 : public Function_2f150 {
  public:
    Fn_2f150 value;
    Method1(const char* p, Fn_2f150 x) : Function_2f150(p, 1) {
        value = x;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    }
    virtual void v();
};
class Closure1 : public Method1 {
  public:
    Owner_2f150* value2;
    Closure1(const char* p, Owner_2f150* n, Fn_2f150 x);
    virtual void v();
};
Closure1::Closure1(const char* p, Owner_2f150* n, Fn_2f150 x) : Method1(p, x) {
    value2 = n;
}
} // namespace fn_0002f150
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0002f1a0 Closure1<CActorManager,void,int>::vfunc_0 (30 B): matches/0x0002f1a0.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, void, int>::~Closure1() {}


// 0x0002f1c0 Closure1<CActorManager,void,int>::vfunc_2 (18 B): matches/0x0002f1c0.cpp
// sym: ?vfunc_2@?$Closure1@UCActorManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CActorManager, void, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2f1c0 * *)&this->f_20)->*(*(void (CActorManager_2f1c0::**)(const char *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, void, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f1a0)
#endif


// 0x0002f1e0 FUN_0002f1e0 (76 B): matches/0x0002f1e0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0002f1e0@@QAE@PBDPAVOwner_2f1e0@1@P821@AEXXZ@Z
namespace fn_0002f1e0 {
// data: text1 = DAT_0048e0e4

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
unsigned char __cdecl Lookup_001d04d0(const char*);
extern const char text2[];
class Function_2f1e0 : public CtorV_001d0480 {
  public:
    Function_2f1e0(const char* x) : CtorV_001d0480(x, 1) { }
};
class Owner_2f1e0 {};
typedef void (Owner_2f1e0::*Fn_2f1e0)();
class Method1 : public Function_2f1e0 {
  public:
    virtual void Fn();
    Fn_2f1e0 p;
    Owner_2f1e0* q;
    Method1(const char* x, Fn_2f1e0 y) : Function_2f1e0(x) {
        p = y;
        retType = Lookup_001d04d0(((const char*)&DAT_0048e0e4));
        argTypes[0] = Lookup_001d04d0(text2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Fn();
    Closure1(const char*, Owner_2f1e0*, Fn_2f1e0);
};
Closure1::Closure1(const char* x, Owner_2f1e0* y, Fn_2f1e0 z) : Method1(x, z) {
    q = y;
}
} // namespace fn_0002f1e0


// 0x0002f230 Closure1<CActorManager,bool,math::Vector>::vfunc_0 (30 B): matches/0x0002f230.cpp
// sym: ??_G?$Method1@UCActorManager@@_NH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, bool,math::Vector>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, bool,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f230)
#endif


// 0x0002f250 Closure1<CActorManager,bool,math::Vector>::vfunc_2 (52 B): matches/0x0002f250.cpp [wrapped: conflict: CActorManager; Closure1; Function]
// sym: ?vfunc_2@Closure1@fn_0002f250@@UAEXHPBUVector@math@2@PA_N@Z
namespace fn_0002f250 {
namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
class CActorManager {
  public:
    bool Action(math::Vector);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Closure1 : public Function {
  public:
    char pad[0x18];
    bool (CActorManager::*method)(math::Vector);
    CActorManager* obj;
    virtual void vfunc_2(int unused, const math::Vector* v, bool* out);
    inline bool invoke(math::Vector v) {
        CActorManager* o = obj;
        bool (CActorManager::*fn)(math::Vector) = method;
        return (o->*fn)(v);
    }
};
void Closure1::vfunc_2(int unused, const math::Vector* v, bool* out) {
    math::Vector copy = *v;
    bool result = invoke(copy);
    if (out)
        *out = result;
}
} // namespace fn_0002f250

namespace fn_f8e68f21 {

// 0x0002f290 FUN_0002f290 (76 B): matches/0x0002f290.cpp
// sym: ??0Closure1_2f290@fn_f8e68f21@@QAE@PBDPAVOwner_2f290@1@P821@AEXXZ@Z
Closure1_2f290::Closure1_2f290(const char* s, Owner_2f290* x, Fn_2f290 y) : Method1_2f290(s, y) {
    d = x;
}

} // namespace fn_f8e68f21

// 0x0002f2e0 Closure1<CActorManager,const_char_*,math::Vector>::vfunc_0 (30 B): matches/0x0002f2e0.cpp
// sym: ??_G?$Method0@UCActorManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, const char *,math::Vector>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, const char *,math::Vector>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f2e0)
#endif


// 0x0002f300 Closure1<CActorManager,const_char_*,math::Vector>::vfunc_2 (52 B): equivalent/0x0002f300.cpp [wrapped: conflict: CActorManager; Closure1]
// sym: ?vfunc_2@Closure1@fn_0002f300@@UAEXPAXPBUVector@2@PAI@Z @d145a21c7e71 @w810791563e95
namespace fn_0002f300 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CActorManager,const_char_*,math::Vector>::vfunc_2 @ 0x0002f300
struct Vector { float x, y, z; };
class CActorManager {
public:
    unsigned int FUN_0002f300(Vector value);
};
class Closure1 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const Vector *value, unsigned int *result);
    char reserved[0x18];
    unsigned int (CActorManager::*method)(Vector);
    CActorManager *manager;
};
void Closure1::vfunc_2(void *unused, const Vector *value, unsigned int *result)
{
    unsigned int answer = (manager->*method)(*value);
    if (result) *result = answer;
}
} // namespace fn_0002f300


// 0x0002f370 Closure7<CActorManager,void,const_char_*,float,float,float,float,float,const_char_*>::vfunc_0 (30 B): matches/0x0002f370.cpp
// sym: ??_G?$Method4@UCActorManager@@XPBDMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure7<CActorManager, void, const char *, float, float, float, float, float, const char *>::~Closure7() {}


// 0x0002f390 Closure7<CActorManager,void,const_char_*,float,float,float,float,float,const_char_*>::vfunc_2 (29 B): matches/0x0002f390.cpp
// sym: ?vfunc_2@?$Closure7@UCActorManager@@XPBDMMMMMPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ebc0 (propagated; names are from that function)
template <> void Closure7<CActorManager, void, const char *, float, float, float, float, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}
#if defined(HULK_PTR64)
template class Closure7<CActorManager, void, const char *, float, float, float, float, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f370)
#endif


// 0x0002f3b0 FUN_0002f3b0 (89 B): matches/0x0002f3b0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002f3b0@@QAE@PBDPAVOwner_2f3b0@1@P821@AEXXZ@Z
namespace fn_0002f3b0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f41bc[2];
extern void* hulk_at_003f44dc[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2f3b0 {};
typedef void (Owner_2f3b0::*Fn_2f3b0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2f3b0 fn;            // 0x1c
    Owner_2f3b0* owner;     // 0x20
    Closure2(const char* a1, Owner_2f3b0* a2, Fn_2f3b0 a3);
};

Closure2::Closure2(const char* a1, Owner_2f3b0* a2, Fn_2f3b0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f41bc;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_003f44dc;
    owner = a2;
}
} // namespace fn_0002f3b0


// 0x0002f410 Closure2<CActorManager,void,int,const_char_*>::vfunc_0 (30 B): matches/0x0002f410.cpp
// sym: ??_G?$Method0@UCActorManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void, int, const char *>::~Closure2() {}


// 0x0002f430 Closure2<CActorManager,void,int,const_char_*>::vfunc_2 (22 B): matches/0x0002f430.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@XPBDM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CActorManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_2f430 * p = (Pair_2f430 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2f430 * *)&this->f_20)->*(*(void (CActorManager_2f430::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void, int, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f410)
#endif


// 0x0002f450 FUN_0002f450 (89 B): matches/0x0002f450.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002f450@@QAE@PBDPAVOwner_2f450@1@P821@AEXXZ@Z
namespace fn_0002f450 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f41cc[2];
extern void* hulk_at_003f44ec[2];
extern void* TAB_48e0f0;

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2f450 {};
typedef void (Owner_2f450::*Fn_2f450)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2f450 fn;            // 0x1c
    Owner_2f450* owner;     // 0x20
    Closure2(const char* a1, Owner_2f450* a2, Fn_2f450 a3);
};

Closure2::Closure2(const char* a1, Owner_2f450* a2, Fn_2f450 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f41cc;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = LookupFlag_001d04d0(&TAB_48e0f0);
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_003f44ec;
    owner = a2;
}
} // namespace fn_0002f450


// 0x0002f4b0 Closure2<CActorManager,void,math::Vector,float>::vfunc_0 (30 B): matches/0x0002f4b0.cpp
// sym: ??_G?$Method3@UCActorManager@@_NPBDMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, void,math::Vector, float>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, void,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f4b0)
#endif


// 0x0002f4d0 Closure2<CActorManager,void,math::Vector,float>::vfunc_2 (42 B): matches/0x0002f4d0.cpp [wrapped: conflict: Closure2]
// sym: ?vfunc_2@Closure2@fn_0002f4d0@@QAEXPAXPAH0@Z
namespace fn_0002f4d0 {
struct Vector {
    int a, b, c;
};
class CActorManager;
class Closure2 {
  public:
    char pad[0x1c];
    void(__fastcall* fn)(CActorManager*, Closure2*, Vector, float);
    CActorManager* object;
    void vfunc_2(void* unused, int* p, void* unused2);
};
void Closure2::vfunc_2(void* unused, int* p, void* unused2) {
    fn(object, this, *(Vector*)p, *(float*)(p + 3));
}
} // namespace fn_0002f4d0


// 0x0002f500 FUN_0002f500 (89 B): matches/0x0002f500.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002f500@@QAE@PBDPAVOwner_2f500@1@P821@AEXXZ@Z
namespace fn_0002f500 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f41dc[2];
extern void* hulk_at_003f44fc[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2f500 {};
typedef void (Owner_2f500::*Fn_2f500)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2f500 fn;            // 0x1c
    Owner_2f500* owner;     // 0x20
    Closure2(const char* a1, Owner_2f500* a2, Fn_2f500 a3);
};

Closure2::Closure2(const char* a1, Owner_2f500* a2, Fn_2f500 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f41dc;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_003f44fc;
    owner = a2;
}
} // namespace fn_0002f500


// 0x0002f560 Closure2<CActorManager,bool,const_char_*,int>::vfunc_0 (30 B): matches/0x0002f560.cpp
// sym: ??_G?$Method3@UCActorManager@@XPBDMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, bool, const char *, int>::~Closure2() {}


// 0x0002f580 Closure2<CActorManager,bool,const_char_*,int>::vfunc_2 (36 B): equivalent/0x0002f580.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@_NPBDH@@UAEXPAX00@Z @e654de0dce29 @w4e3d89bebec6
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,int>::vfunc_2 @ 0x0002f580
template <> void Closure2<CActorManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const ActorArgs * args = (const ActorArgs *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2f580 * *)&this->f_20)->*(*(bool (CActorManager_2f580::**)(const char *, int))&this->f_1c))(args->name, args->value);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, bool, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f560)
#endif


// 0x0002f5b0 FUN_0002f5b0 (76 B): matches/0x0002f5b0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0002f5b0@@QAE@PBDPAVCActorManager_2f5b0@1@P821@AEXXZ@Z
namespace fn_0002f5b0 {
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

// Closure1<CActorManager, ...>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class CActorManager_2f5b0 {};
typedef void (CActorManager_2f5b0::*Fn_2f5b0)();
class Function_2f5b0 : public ScriptFunctionFields {
  public:
    virtual void v();
    Function_2f5b0(const char*, int);
};
class Method1 : public Function_2f5b0 {
  public:
    virtual void v();
    Fn_2f5b0 n;
    __forceinline Method1(const char* m, Fn_2f5b0 x) : Function_2f5b0(m, 1) {
        n = x;
        retType = FUN_001d04d0(&DAT_0048e0e4);
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void v();
    CActorManager_2f5b0* extra;
    Closure1(const char*, CActorManager_2f5b0*, Fn_2f5b0);
};
Closure1::Closure1(const char* mgr, CActorManager_2f5b0* n, Fn_2f5b0 x) : Method1(mgr, x) {
    extra = n;
}
} // namespace fn_0002f5b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0002f600 Closure1<CActorManager,bool,int>::vfunc_0 (30 B): matches/0x0002f600.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CActorManager, bool, int>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CActorManager, bool, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f600)
#endif


// 0x0002f620 Closure1<CActorManager,bool,int>::vfunc_2 (30 B): matches/0x0002f620.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_0002f620@@UAEXPAXPAPBDPA_N@Z
namespace fn_0002f620 {
// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void*, const char**, bool*);
    char pad[0x18];
    typedef bool(__fastcall* Fn)(void*, const char*, const char*);
    Fn mFn;
    void* mObj;
};
void Closure1::V2(void* a, const char** p, bool* out) {
    void* obj = mObj;
    Fn fn = mFn;
    bool r = fn(obj, *p, *p);
    if (out)
        *out = r;
}
} // namespace fn_0002f620


// 0x0002f680 Closure0<CActorManager,bool>::vfunc_0 (30 B): matches/0x0002f680.cpp
// sym: ??_G?$Method3@UCActorManager@@XPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CActorManager, bool>::~Closure0() {}


// 0x0002f6a0 Closure0<CActorManager,bool>::vfunc_2 (23 B): matches/0x0002f6a0.cpp
// sym: ?vfunc_2@?$Closure0@UCActorManager@@_N@@UAEXPAX00@Z
template <> void Closure0<CActorManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_2f6a0* o = (*(CActorManager_2f6a0 * *)&this->f_20);
    Fn_2f6a0 fn = (*(Fn_2f6a0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}
#if defined(HULK_PTR64)
template class Closure0<CActorManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f680)
#endif


// 0x0002f6f0 Closure4<CActorManager,void,const_char_*,float,int,float>::vfunc_0 (30 B): matches/0x0002f6f0.cpp
// sym: ??_G?$Method4@UCActorManager@@XPBDPBDMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CActorManager, void, const char *, float, int, float>::~Closure4() {}
#if defined(HULK_PTR64)
template class Closure4<CActorManager, void, const char *, float, int, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f6f0)
#endif


// 0x0002f710 Closure4<CActorManager,void,const_char_*,float,int,float>::vfunc_2 (45 B): equivalent/0x0002f710.cpp [wrapped: conflict: CActorManager; Closure4]
// sym: ?vfunc_2@Closure4@fn_0002f710@@UAEXHPBXH@Z @35da6a76506a @wc1e95d57ad4d
namespace fn_0002f710 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,float,int,float>::vfunc_2 @ 0x0002f710
class CActorManager {};
class Closure4 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, const void *arguments, int other);
    char padding[0x18];
    typedef void (CActorManager::*Method)(const char *, float, int, float);
    Method method;
    CActorManager *actor;
};
void Closure4::vfunc_2(int unused, const void *arguments, int other)
{
    struct Args { const char *name; float value; int index; float last; };
    const Args *args = (const Args *)arguments;
    (actor->*method)(args->name, args->value, args->index, args->last);
}
} // namespace fn_0002f710


// 0x0002f770 Closure4<CActorManager,void,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x0002f770.cpp
// sym: ??_G?$Method2@UCActorManager@@PBDPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CActorManager, void, const char *, float, float, float>::~Closure4() {}


// 0x0002f790 Closure4<CActorManager,void,const_char_*,float,float,float>::vfunc_2 (45 B): equivalent/0x0002f790.cpp
// sym: ?vfunc_2@?$Closure4@UCActorManager@@XPBDMMM@@UAEXPAX00@Z @35da6a76506a @w86f05f0358a7
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,float,float,float>::vfunc_2 @ 0x0002f790
template <> void Closure4<CActorManager, void, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; ActorArgs * args = (ActorArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CActorManager_2f790 * *)&this->f_20)->*(*(void (CActorManager_2f790::**)(const char *, float, float, float))&this->f_1c))(args->name, args->a, args->b, args->c);
}
#if defined(HULK_PTR64)
template class Closure4<CActorManager, void, const char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f770)
#endif


// 0x0002f800 Closure0<CActorManager,void>::vfunc_0 (30 B): matches/0x0002f800.cpp
// sym: ??_G?$Method2@UCActorManager@@HPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CActorManager, void>::~Closure0() {}


// 0x0002f820 Closure0<CActorManager,void>::vfunc_2 (11 B): matches/0x0002f820.cpp
// sym: ?vfunc_2@?$Closure0@UCActorManager@@X@@UAEXPAX00@Z
template <> void Closure0<CActorManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_2f820 * *)&this->f_20)->*(*(void (CActorManager_2f820::**)())&this->f_1c))();
}
#if defined(HULK_PTR64)
template class Closure0<CActorManager, void>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f800)
#endif


// 0x0002f860 Closure5<CActorManager,void,const_char_*,const_char_*,float,float,float>::vfunc_0 (30 B): matches/0x0002f860.cpp
// sym: ??_G?$Method2@UCActorManager@@PBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<CActorManager, void, const char *, const char *, float, float, float>::~Closure5() {}


// 0x0002f880 Closure5<CActorManager,void,const_char_*,const_char_*,float,float,float>::vfunc_2 (55 B): equivalent/0x0002f880.cpp
// sym: ?vfunc_2@?$Closure5@UCActorManager@@XPBDPBDMMM@@UAEXPAX00@Z @ad17d42b696f @wa74f3d089783
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure5<CActorManager,void,const_char_*,const_char_*,float,float,float>::vfunc_2 @ 0x0002f880
template <> void Closure5<CActorManager, void, const char *, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1;

    ((*(CActorManager_2f880 * *)&this->f_20)->*(*(void (CActorManager_2f880::**)(const char *, const char *, float, float, float))&this->f_1c))(args->first, args->second, args->third, args->fourth, args->fifth);
}
#if defined(HULK_PTR64)
template class Closure5<CActorManager, void, const char *, const char *, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f860)
#endif


// 0x0002f8f0 Closure3<CActorManager,bool,const_char_*,float,float>::vfunc_0 (30 B): matches/0x0002f8f0.cpp
// sym: ??_G?$Method1@UCActorManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CActorManager, bool, const char *, float, float>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CActorManager, bool, const char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f8f0)
#endif


// 0x0002f980 Closure3<CActorManager,void,const_char_*,float,float>::vfunc_0 (30 B): matches/0x0002f980.cpp
// sym: ??_G?$Method0@UCActorManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CActorManager, void, const char *, float, float>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CActorManager, void, const char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2f980)
#endif


// 0x0002f9c0 FUN_0002f9c0 (89 B): matches/0x0002f9c0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002f9c0@@QAE@PBDPAVOwner_2f9c0@1@P821@AEXXZ@Z
namespace fn_0002f9c0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)
extern void* hulk_at_003f426c[2];
extern void* hulk_at_003f458c[2];
extern void* hulk_at_0048e0e4;
extern void* hulk_at_0048e0f0;
extern void* hulk_at_0048e128;

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2f9c0 {};
typedef void (Owner_2f9c0::*Fn_2f9c0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2f9c0 fn;            // 0x1c
    Owner_2f9c0* owner;     // 0x20
    Closure2(const char* a1, Owner_2f9c0* a2, Fn_2f9c0 a3);
};

Closure2::Closure2(const char* a1, Owner_2f9c0* a2, Fn_2f9c0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f426c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(&hulk_at_0048e0e4);
    f.argTypes[0] = LookupFlag_001d04d0(&hulk_at_0048e0f0);
    f.argTypes[1] = LookupFlag_001d04d0(&hulk_at_0048e128);
    vfptr = (void*)hulk_at_003f458c;
    owner = a2;
}
} // namespace fn_0002f9c0


// 0x0002fa20 Closure2<CActorManager,bool,const_char_*,float>::vfunc_0 (30 B): matches/0x0002fa20.cpp
// sym: ??_G?$Method2@UCActorManager@@VVector@math@@V23@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, bool, const char *, float>::~Closure2() {}


// 0x0002fa40 Closure2<CActorManager,bool,const_char_*,float>::vfunc_2 (40 B): equivalent/0x0002fa40.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@_NPBDM@@UAEXPAX00@Z @e654de0dce29 @w869ed99f0dcb
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,float>::vfunc_2 @ 0x0002fa40
template <> void Closure2<CActorManager, bool, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; CallArgs * args = (CallArgs *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2fa40 * *)&this->f_20)->*(*(bool (CActorManager_2fa40::**)(const char *, float))&this->f_1c))(args->name, args->value);
    if (result) *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, bool, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2fa20)
#endif


// 0x0002faa0 Closure3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x0002faa0.cpp
// sym: ??_G?$Method2@UCActorManager@@MPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CActorManager, void, const char *, const char *, float>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CActorManager, void, const char *, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2faa0)
#endif


// 0x0002fb10 Closure4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_0 (30 B): matches/0x0002fb10.cpp
// sym: ??_G?$Method1@UCActorManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CActorManager, void, const char *, const char *, float, float>::~Closure4() {}


// 0x0002fb30 Closure4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_2 (39 B): equivalent/0x0002fb30.cpp
// sym: ?vfunc_2@?$Closure4@UCActorManager@@XPBDPBDMM@@UAEXPAX00@Z @35da6a76506a @w27dfc6c0d2b4
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_2 @ 0x0002fb30
template <> void Closure4<CActorManager, void, const char *, const char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const void * arguments = (const void *)__p1;

    struct Args {
        const char *first;
        const char *second;
        float third;
        float fourth;
    };
    const Args *args = (const Args *)arguments;
    ((*(CActorManager_2fb30 * *)&this->f_20)->*(*(void (CActorManager_2fb30::**)(const char *, const char *, float, float))&this->f_1c))(args->first, args->second, args->third, args->fourth);
}
#if defined(HULK_PTR64)
template class Closure4<CActorManager, void, const char *, const char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2fb10)
#endif


// 0x0002fb60 FUN_0002fb60 (89 B): matches/0x0002fb60.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002fb60@@QAE@PBDPAVOwner_2fb60@1@P821@AEXXZ@Z
namespace fn_0002fb60 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f429c[2];
extern void* hulk_at_003f45bc[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2fb60 {};
typedef void (Owner_2fb60::*Fn_2fb60)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2fb60 fn;            // 0x1c
    Owner_2fb60* owner;     // 0x20
    Closure2(const char* a1, Owner_2fb60* a2, Fn_2fb60 a3);
};

Closure2::Closure2(const char* a1, Owner_2fb60* a2, Fn_2fb60 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f429c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    vfptr = (void*)hulk_at_003f45bc;
    owner = a2;
}
} // namespace fn_0002fb60


// 0x0002fbc0 Closure2<CActorManager,const_char_*,const_char_*,int>::vfunc_0 (30 B): matches/0x0002fbc0.cpp
// sym: ??_G?$Method3@UCActorManager@@XHHH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, const char *, const char *, int>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, const char *, const char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2fbc0)
#endif


// 0x0002fbe0 Closure2<CActorManager,const_char_*,const_char_*,int>::vfunc_2 (36 B): equivalent/0x0002fbe0.cpp [wrapped: conflict: ActorMethod; Closure2]
// sym: ?vfunc_2@Closure2@fn_0002fbe0@@UAEXPAXPAPBDPAH@Z @5f2db1ebe681 @waf66c672aa7b
namespace fn_0002fbe0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,const_char_*,const_char_*,int>::vfunc_2 @ 0x0002fbe0
struct CActorManager {};
typedef int (CActorManager::*ActorMethod)(const char *, const char *);
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **arguments, int *result);
    char padding[0x18];
    ActorMethod method;
    CActorManager *actorManager;
};
void Closure2::vfunc_2(void *unused, const char **arguments, int *result)
{
    int value = (actorManager->*method)(arguments[0], arguments[1]);
    if (result != 0)
        *result = value;
}
} // namespace fn_0002fbe0


// 0x0002fc10 FUN_0002fc10 (89 B): matches/0x0002fc10.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002fc10@@QAE@PBDPAVOwner_2fc10@1@P821@AEXXZ@Z
namespace fn_0002fc10 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f42ac[2];
extern void* hulk_at_003f45cc[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2fc10 {};
typedef void (Owner_2fc10::*Fn_2fc10)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2fc10 fn;            // 0x1c
    Owner_2fc10* owner;     // 0x20
    Closure2(const char* a1, Owner_2fc10* a2, Fn_2fc10 a3);
};

Closure2::Closure2(const char* a1, Owner_2fc10* a2, Fn_2fc10 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f42ac;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e134));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_003f45cc;
    owner = a2;
}
} // namespace fn_0002fc10


// 0x0002fc70 Closure2<CActorManager,int,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002fc70.cpp
// sym: ??_G?$Method3@UCActorManager@@_NPBDVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, int, const char *, const char *>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, int, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2fc70)
#endif


// 0x0002fc90 Closure2<CActorManager,int,const_char_*,const_char_*>::vfunc_2 (36 B): equivalent/0x0002fc90.cpp [wrapped: conflict: CActorManager]
// sym: ?vfunc_2@Closure2_CActorManager_int_const_char_const_char@fn_0002fc90@@UAEXHPBUArguments@2@PAH@Z @5f2db1ebe681 @waf66c672aa7b
namespace fn_0002fc90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,int,const_char_*,const_char_*>::vfunc_2 @ 0x0002fc90
struct CActorManager { int FUN_0002fc90(const char *, const char *); };
struct Arguments { const char *first; const char *second; };
struct Closure2_CActorManager_int_const_char_const_char {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, const Arguments *arguments, int *result);
    char padding[0x18];
    int (CActorManager::*method)(const char *, const char *);
    CActorManager *object;
};
void Closure2_CActorManager_int_const_char_const_char::vfunc_2(int unused, const Arguments *arguments, int *result)
{
    int value = (object->*method)(arguments->first, arguments->second);
    if (result) *result = value;
}
} // namespace fn_0002fc90


// 0x0002fcc0 FUN_0002fcc0 (89 B): matches/0x0002fcc0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002fcc0@@QAE@PBDPAVOwner_2fcc0@1@P821@AEXXZ@Z
namespace fn_0002fcc0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f42bc[2];
extern void* hulk_at_003f45dc[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2fcc0 {};
typedef void (Owner_2fcc0::*Fn_2fcc0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2fcc0 fn;            // 0x1c
    Owner_2fcc0* owner;     // 0x20
    Closure2(const char* a1, Owner_2fcc0* a2, Fn_2fcc0 a3);
};

Closure2::Closure2(const char* a1, Owner_2fcc0* a2, Fn_2fcc0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f42bc;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_003f45dc;
    owner = a2;
}
} // namespace fn_0002fcc0


// 0x0002fd20 Closure2<CActorManager,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0002fd20.cpp
// sym: ??_G?$Method2@UCActorManager@@_NPBDVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager, const char *, const char *, const char *>::~Closure2() {}


// 0x0002fd40 Closure2<CActorManager,const_char_*,const_char_*,const_char_*>::vfunc_2 (36 B): equivalent/0x0002fd40.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@PBDPBDPBD@@UAEXPAX00@Z @5f2db1ebe681 @w1a588241b2b0
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CActorManager,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x0002fd40
template <> void Closure2<CActorManager, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** arguments = (const char **)__p1; int * result = (int *)__p2;

    int value = ((*(CActorManager_2fd40 * *)&this->f_20)->*(*(int (CActorManager_2fd40::**)(const char *, const char *))&this->f_1c))(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
#if defined(HULK_PTR64)
template class Closure2<CActorManager, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2fd20)
#endif

namespace fn_f8e68f21 {

// 0x0002fd70 FUN_0002fd70 (76 B): matches/0x0002fd70.cpp
// sym: ?Fn@Closure1_2fd70@fn_f8e68f21@@QAEPAV12@PBDPAVOwner_2fd70@2@P832@AEXXZ@Z
Closure1_2fd70* Closure1_2fd70::Fn(const char* a, Owner_2fd70* b, Fn_2fd70 c) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(a, 1);
    v = (void*)DAT_003f42cc;
    fn = c;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    v = (void*)DAT_003f45ec;
    owner = b;
    return this;
}

} // namespace fn_f8e68f21

// 0x0002fde0 Closure1<CActorManager,void,float>::vfunc_2 (18 B): matches/0x0002fde0.cpp
// sym: ?vfunc_2@?$Closure1@UCActorManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CActorManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_2fde0 * *)&this->f_20)->*(*(void (CActorManager_2fde0::**)(const char *))&this->f_1c))(*b);
}


// 0x0002fe60 Closure0<CActorManager,float>::vfunc_2 (35 B): matches/0x0002fe60.cpp
// sym: ?vfunc_2@?$Closure0@UCActorManager@@M@@UAEXPAX00@Z
template <> void Closure0<CActorManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_2fe60* m = (*(CActorManager_2fe60 * *)&this->f_20);
    Fn_2fe60 fn = (*(Fn_2fe60 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}


// 0x0002fe90 FUN_0002fe90 (89 B): matches/0x0002fe90.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002fe90@@QAE@PBDPAVOwner_2fe90@1@P821@AEXXZ@Z
namespace fn_0002fe90 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f42ec[2];
extern void* hulk_at_003f460c[2];
extern void* TAB_48e100;
extern void* TAB_48e0f0;

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2fe90 {};
typedef void (Owner_2fe90::*Fn_2fe90)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2fe90 fn;            // 0x1c
    Owner_2fe90* owner;     // 0x20
    Closure2(const char* a1, Owner_2fe90* a2, Fn_2fe90 a3);
};

Closure2::Closure2(const char* a1, Owner_2fe90* a2, Fn_2fe90 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f42ec;
    fn = a3;
    f.retType = LookupFlag_001d04d0(&TAB_48e100);
    f.argTypes[0] = LookupFlag_001d04d0(&TAB_48e0f0);
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    vfptr = (void*)hulk_at_003f460c;
    owner = a2;
}
} // namespace fn_0002fe90


// 0x0002ff10 Closure2<CActorManager,math::Vector,math::Vector,float>::vfunc_2 (12 B): matches/0x0002ff10.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_0002ff10@@UAEXHHH@Z
namespace fn_0002ff10 {
class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, int, int);
    char pad[0x18];
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int, int, int);
};
void Closure2::vfunc_2(int x, int a2, int a3) {
    Method2::vfunc_2(val, a2, a3);
}
} // namespace fn_0002ff10


// 0x0002ff20 FUN_0002ff20 (89 B): matches/0x0002ff20.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0002ff20@@QAE@PBDPAVOwner_2ff20@1@P821@AEXXZ@Z
namespace fn_0002ff20 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f42fc[2];
extern void* hulk_at_003f461c[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_2ff20 {};
typedef void (Owner_2ff20::*Fn_2ff20)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_2ff20 fn;            // 0x1c
    Owner_2ff20* owner;     // 0x20
    Closure2(const char* a1, Owner_2ff20* a2, Fn_2ff20 a3);
};

Closure2::Closure2(const char* a1, Owner_2ff20* a2, Fn_2ff20 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f42fc;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e128));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_003f461c;
    owner = a2;
}
} // namespace fn_0002ff20


// 0x0002ffa0 Closure2<CActorManager,float,const_char_*,const_char_*>::vfunc_2 (47 B): matches/0x0002ffa0.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@MPBDPBD@@UAEXPAX00@Z
template <> void Closure2<CActorManager, float, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned int * x = (unsigned int *)__p0; unsigned int * args = (unsigned int *)__p1; float * out = (float *)__p2;

    CActorManager_2ffa0* o = (*(CActorManager_2ffa0 * *)&this->f_20);
    float (CActorManager_2ffa0::*fn)(const char*, const char*) = (*(float (CActorManager_2ffa0::**)(const char *, const char *))&this->f_1c);
    const char* a = (const char*)args[0];
    const char* b = (const char*)args[1];
    float r = (o->*fn)(a, b);
    if (out)
        *out = r;
}


// 0x0002ffd0 FUN_0002ffd0 (76 B): matches/0x0002ffd0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0002ffd0@@QAE@PBDPAVOwner_2ffd0@1@P821@AEXXZ@Z
namespace fn_0002ffd0 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_2ffd0 : public CtorV_001d0480 {
  public:
    Function_2ffd0(const char* a) : CtorV_001d0480(a, 1) { }
};
class Owner_2ffd0 {};
typedef void (Owner_2ffd0::*Fn_2ffd0)();
class Method1 : public Function_2ffd0 {
  public:
    virtual void invoke();
    Fn_2ffd0 data;
    Method1(const char* a, Fn_2ffd0 c) : Function_2ffd0(a) {
        data = c;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    Owner_2ffd0* extra;
    Closure1(const char* a, Owner_2ffd0* b, Fn_2ffd0 c);
};
Closure1::Closure1(const char* a, Owner_2ffd0* b, Fn_2ffd0 c) : Method1(a, c) {
    extra = b;
}
} // namespace fn_0002ffd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00030040 Closure1<CActorManager,void,bool>::vfunc_2 (20 B): matches/0x00030040.cpp
// sym: ?vfunc_2@?$Closure1@UCActorManager@@X_N@@UAEXPAX00@Z
template <> void Closure1<CActorManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_30040 * *)&this->f_20)->*(*(void (Actor_30040::**)(unsigned char))&this->f_1c))(*arg);
}


// 0x00030120 Closure3<CActorManager,bool,const_char_*,math::Vector,math::Vector>::vfunc_2 (12 B): matches/0x00030120.cpp [wrapped: conflict: Closure2; Function; Method2]
// sym: ?vfunc_2@Closure2@fn_00030120@@UAEXHHH@Z
namespace fn_00030120 {
// Same code shape as 0x0002ff10 (propagated; names are from that function)
class CActorManager;
struct Vector {
    float x, y, z;
};
class Method2 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(int, int, int);
    char pad[0x18];
};
class Function {
  public:
    virtual void g0();
};
class Closure2 : public Method2, public Function {
  public:
    int val;
    virtual void vfunc_2(int, int, int);
};
void Closure2::vfunc_2(int x, int a2, int a3) {
    Method2::vfunc_2(val, a2, a3);
}
} // namespace fn_00030120


// 0x00030130 FUN_00030130 (89 B): matches/0x00030130.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_00030130@@QAE@PBDPAVOwner_30130@1@P821@AEXXZ@Z
namespace fn_00030130 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_003f433c[2];
extern void* hulk_at_003f465c[2];
extern void* TAB_48e134;

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_30130 {};
typedef void (Owner_30130::*Fn_30130)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
char __cdecl LookupFlag_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_30130 fn;            // 0x1c
    Owner_30130* owner;     // 0x20
    Closure2(const char* a1, Owner_30130* a2, Fn_30130 a3);
};

Closure2::Closure2(const char* a1, Owner_30130* a2, Fn_30130 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_003f433c;
    fn = a3;
    f.retType = LookupFlag_001d04d0(((void**)&DAT_0048e0e4));
    f.argTypes[0] = LookupFlag_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = LookupFlag_001d04d0(&TAB_48e134);
    vfptr = (void*)hulk_at_003f465c;
    owner = a2;
}
} // namespace fn_00030130


// 0x000301b0 Closure2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 (61 B): equivalent/0x000301b0.cpp
// sym: ?vfunc_2@?$Closure2@UCActorManager@@_NPBDVVector@math@@@@UAEXPAX00@Z @6c585092a365 @wa53bb2aee1dc
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x000301b0
template <> void Closure2<CActorManager, bool, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const void * data = (const void *)__p1; bool * result = (bool *)__p2;

    struct Arguments { const char *name; Vector_301b0 position; };
    const Arguments *args = (const Arguments *)data;
    bool value = ((*(CActorManager_301b0 * *)&this->f_20)->*(*(bool (CActorManager_301b0::**)(const char *, Vector_301b0))&this->f_1c))(args->name, args->position);
    if (result) *result = value;
}

namespace fn_f8e68f21 {

// 0x000301f0 FUN_000301f0 (70 B): equivalent/0x000301f0.cpp
// sym: ?FUN_000301f0@Registry_301f0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AE_N0_N@Z@Z @aeccf7ef3dcf @wd424ead24da9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000301f0 @ 0x000301f0
// FUN_000301f0 @ 0x000301f0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_301f0::FUN_000301f0(const char* a1, Owner* a2, Fn_301f0 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_301f0* e = (Closure2_301f0*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002e4f0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030240 FUN_00030240 (70 B): equivalent/0x00030240.cpp
// sym: ?FUN_00030240@Registry_30240@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEX0VVector_30240@math@@@Z@Z @c10c95a68458 @w6416760a2ac7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00030240 @ 0x00030240
// FUN_00030240 @ 0x00030240  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30240::FUN_00030240(const char* a1, Owner* a2, Fn_30240 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_30240* e = (Closure2_30240*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002e5a0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030290 FUN_00030290 (70 B): matches/0x00030290.cpp
// sym: ?FUN_00030290@Registry_30290@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEX0M@Z@Z
void Registry_30290::FUN_00030290(const char* a1, Owner* a2, Fn_30290 a3) {
    HULK_SIZE32(Closure2_30290, 0x24);
    Closure2_30290* e = new Closure2_30290(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}


// 0x000302e0 FUN_000302e0 (70 B): matches/0x000302e0.cpp
// sym: ?FUN_000302e0@Registry_302e0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEX0H@Z@Z
void Registry_302e0::FUN_000302e0(const char* a1, Owner* a2, Fn_302e0 a3) {
    HULK_SIZE32(Closure2_302e0, 0x24);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(new Closure2_302e0(a1, a2, a3)));
}


// 0x00030380 FUN_00030380 (70 B): matches/0x00030380.cpp
// sym: ?FUN_00030380@Registry_30380@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AE_N0@Z@Z
void Registry_30380::FUN_00030380(const char* a1, Owner* a2, Fn_30380 a3) {
    HULK_SIZE32(Closure1_30380, 0x24);
    Closure1_30380* e = new Closure1_30380(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}


// 0x000303d0 FUN_000303d0 (83 B): equivalent/0x000303d0.cpp
// sym: ?FUN_000303d0@Registry_303d0@fn_f8e68f21@@QAEXPBDPAVCActorManager_303d0@2@P832@AEX0M_N@Z@Z @e9789a1eb347 @wa20e6ee8ec20
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000303d0 @ 0x000303d0
// FUN_000303d0 @ 0x000303d0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_303d0::FUN_000303d0(const char* a1, CActorManager_303d0* a2, Fn_303d0 a3) {
    typedef Closure3_303d0<CActorManager_303d0, void, const char*, float, bool> Alloc_303d0;
    HULK_SIZE32(Alloc_303d0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_303d0));
    void* x = 0;
    if (m) {
        ((Raw_303d0*)m)->FUN_0002c810(a1, a3);
        x = new (m) Closure3_303d0<CActorManager_303d0, void, const char*, float, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030430 FUN_00030430 (83 B): equivalent/0x00030430.cpp
// sym: ?FUN_00030430@Registry_30430@fn_f8e68f21@@QAEXPBDPAVCActorManager_30430@2@P832@AEX0M0@Z@Z @1085fbb9384e @w035e8c6a7381
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030430 @ 0x00030430
// FUN_00030430 @ 0x00030430  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30430::FUN_00030430(const char* a1, CActorManager_30430* a2, Fn_30430 a3) {
    typedef Closure3_30430<CActorManager_30430, void, const char*, float, const char*> Alloc_30430;
    HULK_SIZE32(Alloc_30430, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30430));
    void* x = 0;
    if (m) {
        ((Raw_30430*)m)->FUN_0002c8b0(a1, a3);
        x = new (m) Closure3_30430<CActorManager_30430, void, const char*, float, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030490 FUN_00030490 (70 B): equivalent/0x00030490.cpp
// sym: ?FUN_00030490@Registry_30490@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEH0@Z@Z @8021c033702e @w13dd4c1457ed
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00030490 @ 0x00030490
// FUN_00030490 @ 0x00030490  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30490::FUN_00030490(const char* a1, Owner* a2, Fn_30490 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure1_30490* e = (Closure1_30490*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002e9a0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000304e0 FUN_000304e0 (70 B): equivalent/0x000304e0.cpp
// sym: ?FUN_000304e0@Registry_304e0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEPBD0@Z@Z @1d96525ce2d6 @w22cb138b4650
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000304e0 @ 0x000304e0
// FUN_000304e0 @ 0x000304e0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_304e0::FUN_000304e0(const char* a1, Owner* a2, Fn_304e0 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure1_304e0* e = (Closure1_304e0*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002ea30(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030530 FUN_00030530 (83 B): equivalent/0x00030530.cpp
// sym: ?FUN_00030530@Registry_30530@fn_f8e68f21@@QAEXPBDPAVCActorManager_30530@2@P832@AE_N0000_N0@Z@Z @2b37255c6b54 @wa505edbe93b3
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030530 @ 0x00030530
// FUN_00030530 @ 0x00030530  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30530::FUN_00030530(const char* a1, CActorManager_30530* a2, Fn_30530 a3) {
    typedef Closure6_30530<CActorManager_30530, bool, const char*, const char*, const char*, const char*, bool, const char*> Alloc_30530;
    HULK_SIZE32(Alloc_30530, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30530));
    void* x = 0;
    if (m) {
        ((Raw_30530*)m)->FUN_0002ca50(a1, a3);
        x = new (m) Closure6_30530<CActorManager_30530, bool, const char*, const char*, const char*, const char*, bool, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030590 FUN_00030590 (83 B): equivalent/0x00030590.cpp
// sym: ?FUN_00030590@Registry_30590@fn_f8e68f21@@QAEXPBDPAVCActorManager_30590@2@P832@AE_N0VVector_30590@math@@M00_N0@Z@Z @0d44eb422c2c @w4fa8a51cca3b
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030590 @ 0x00030590
// FUN_00030590 @ 0x00030590  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30590::FUN_00030590(const char* a1, CActorManager_30590* a2, Fn_30590 a3) {
    typedef Closure7_30590<CActorManager_30590, bool, const char*, math::Vector_30590, float, const char*, const char*, bool, const char*> Alloc_30590;
    HULK_SIZE32(Alloc_30590, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30590));
    void* x = 0;
    if (m) {
        ((Raw_30590*)m)->FUN_0002cb60(a1, a3);
        x = new (m) Closure7_30590<CActorManager_30590, bool, const char*, math::Vector_30590, float, const char*, const char*, bool, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000305f0 FUN_000305f0 (70 B): matches/0x000305f0.cpp
// sym: ?FUN_000305f0@Registry_305f0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEX0_N@Z@Z
void Registry_305f0::FUN_000305f0(const char* a1, Owner* a2, Fn_305f0 a3) {
    HULK_SIZE32(Closure2_305f0, 0x24);
    Closure2_305f0* e = new Closure2_305f0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}


// 0x00030640 FUN_00030640 (70 B): equivalent/0x00030640.cpp
// sym: ?FUN_00030640@Registry_30640@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEXMM@Z@Z @f7a8cbe17d2e @wf2eff8227cac
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00030640 @ 0x00030640
// FUN_00030640 @ 0x00030640  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30640::FUN_00030640(const char* a1, Owner* a2, Fn_30640 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_30640* e = (Closure2_30640*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002ec80(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030690 FUN_00030690 (70 B): equivalent/0x00030690.cpp
// sym: ?FUN_00030690@Registry_30690@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEX0@Z@Z @2852d56b3db9 @w653d8056fb65
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00030690 @ 0x00030690
// FUN_00030690 @ 0x00030690  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30690::FUN_00030690(const char* a1, Owner* a2, Fn_30690 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure1_30690* e = (Closure1_30690*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002ed20(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f8e68f21

// 0x000306e0 FUN_000306e0 (109 B): equivalent/0x000306e0.cpp [wrapped: conflict: CActorManager; Closure0; Method0]
// sym: ?FUN_000306e0@Registry_306e0@fn_000306e0@@QAEXPBDPAVCActorManager@2@P832@AEPBDXZ@Z @5f8daf579b1b @wab5ce5a50914
namespace fn_000306e0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000306e0 @ 0x000306e0
// FUN_000306e0 @ 0x000306e0  (generated by work/closure/gen.py)
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


class CActorManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_306e0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_306e0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_306e0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_306e0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_306e0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000306e0(const char* name, CActorManager* owner, const char* (CActorManager::*fn)());
};

void Registry_306e0::FUN_000306e0(const char* name, CActorManager* owner, const char* (CActorManager::*fn)()) {
    typedef Closure0<CActorManager, const char*> Alloc_306e0;
    HULK_SIZE32(Alloc_306e0, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CActorManager, const char*>));
    Closure0<CActorManager, const char*>* c = 0;
    if (mem)
        c = new (mem) Closure0<CActorManager, const char*>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000306e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00030750 FUN_00030750 (109 B): equivalent/0x00030750.cpp [wrapped: conflict: CActorManager; Closure0; Method0]
// sym: ?FUN_00030750@Registry_30750@fn_00030750@@QAEXPBDPAVCActorManager@2@P832@AEHXZ@Z @cf756b110c3e @w5ad328747996
namespace fn_00030750 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00030750 @ 0x00030750
// FUN_00030750 @ 0x00030750  (generated by work/closure/gen.py)
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


class CActorManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_30750 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_30750(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_30750 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_30750(name, 0) {
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

struct Registry_30750 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00030750(const char* name, CActorManager* owner, int (CActorManager::*fn)());
};

void Registry_30750::FUN_00030750(const char* name, CActorManager* owner, int (CActorManager::*fn)()) {
    typedef Closure0<CActorManager, int> Alloc_30750;
    HULK_SIZE32(Alloc_30750, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CActorManager, int>));
    Closure0<CActorManager, int>* c = 0;
    if (mem)
        c = new (mem) Closure0<CActorManager, int>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00030750
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f8e68f21 {

// 0x00030810 FUN_00030810 (70 B): equivalent/0x00030810.cpp
// sym: ?FUN_00030810@Registry_30810@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AE_N00@Z@Z @bda904035b14 @w9c2958ac6ebb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00030810 @ 0x00030810
// FUN_00030810 @ 0x00030810  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30810::FUN_00030810(const char* a1, Owner* a2, Fn_30810 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_30810* e = (Closure2_30810*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002ef40(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030860 FUN_00030860 (70 B): matches/0x00030860.cpp
// sym: ?FUN_00030860@Registry_30860@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEX00@Z@Z
void Registry_30860::FUN_00030860(const char* a1, Owner* a2, Fn_30860 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_30860* e = new (FUN_0008d690((int)sizeof(ScriptClosureView))) Closure2_30860(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}


// 0x000309a0 FUN_000309a0 (70 B): equivalent/0x000309a0.cpp
// sym: ?FUN_000309a0@Registry_309a0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEPBDVVector_309a0@math@@@Z@Z @63023534a494 @w5d10d65f6895
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000309a0 @ 0x000309a0
// FUN_000309a0 @ 0x000309a0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_309a0::FUN_000309a0(const char* a1, Owner* a2, Fn_309a0 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure1_309a0* e = (Closure1_309a0*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002f290(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000309f0 FUN_000309f0 (83 B): equivalent/0x000309f0.cpp
// sym: ?FUN_000309f0@Registry_309f0@fn_f8e68f21@@QAEXPBDPAVCActorManager_309f0@2@P832@AEX0MMMMM0@Z@Z @79d246cbf94d @w394da7e84c20
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_000309f0 @ 0x000309f0
// FUN_000309f0 @ 0x000309f0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_309f0::FUN_000309f0(const char* a1, CActorManager_309f0* a2, Fn_309f0 a3) {
    typedef Closure7_309f0<CActorManager_309f0, void, const char*, float, float, float, float, float, const char*> Alloc_309f0;
    HULK_SIZE32(Alloc_309f0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_309f0));
    void* x = 0;
    if (m) {
        ((Raw_309f0*)m)->FUN_0002d370(a1, a3);
        x = new (m) Closure7_309f0<CActorManager_309f0, void, const char*, float, float, float, float, float, const char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030af0 FUN_00030af0 (70 B): equivalent/0x00030af0.cpp
// sym: ?FUN_00030af0@Registry_30af0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AE_N0H@Z@Z @9b01ebfb321d @wcdc8cb50ce24
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00030af0 @ 0x00030af0
// FUN_00030af0 @ 0x00030af0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30af0::FUN_00030af0(const char* a1, Owner* a2, Fn_30af0 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_30af0* e = (Closure2_30af0*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_0002f500(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f8e68f21

// 0x00030b90 FUN_00030b90 (109 B): equivalent/0x00030b90.cpp [wrapped: conflict: CActorManager; Closure0; Method0]
// sym: ?FUN_00030b90@Registry_30b90@fn_00030b90@@QAEXPBDPAVCActorManager@2@P832@AE_NXZ@Z @647c1ac8ee87 @wdcdee8da3c71
namespace fn_00030b90 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00030b90 @ 0x00030b90
// FUN_00030b90 @ 0x00030b90  (generated by work/closure/gen.py)
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


class CActorManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_30b90 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_30b90(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_30b90 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_30b90(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_30b90 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00030b90(const char* name, CActorManager* owner, bool (CActorManager::*fn)());
};

void Registry_30b90::FUN_00030b90(const char* name, CActorManager* owner, bool (CActorManager::*fn)()) {
    typedef Closure0<CActorManager, bool> Alloc_30b90;
    HULK_SIZE32(Alloc_30b90, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CActorManager, bool>));
    Closure0<CActorManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CActorManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00030b90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f8e68f21 {

// 0x00030c00 FUN_00030c00 (83 B): equivalent/0x00030c00.cpp
// sym: ?FUN_00030c00@Registry_30c00@fn_f8e68f21@@QAEXPBDPAVCActorManager_30c00@2@P832@AEX0MHM@Z@Z @b1cdf269efde @w7de3e5ff1d24
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030c00 @ 0x00030c00
// FUN_00030c00 @ 0x00030c00  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30c00::FUN_00030c00(const char* a1, CActorManager_30c00* a2, Fn_30c00 a3) {
    typedef Closure4_30c00<CActorManager_30c00, void, const char*, float, int, float> Alloc_30c00;
    HULK_SIZE32(Alloc_30c00, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30c00));
    void* x = 0;
    if (m) {
        ((Raw_30c00*)m)->FUN_0002d770(a1, a3);
        x = new (m) Closure4_30c00<CActorManager_30c00, void, const char*, float, int, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030c60 FUN_00030c60 (83 B): equivalent/0x00030c60.cpp
// sym: ?FUN_00030c60@Registry_30c60@fn_f8e68f21@@QAEXPBDPAVCActorManager_30c60@2@P832@AEX0MMM@Z@Z @1869dc344f1b @w671062ae3537
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030c60 @ 0x00030c60
// FUN_00030c60 @ 0x00030c60  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30c60::FUN_00030c60(const char* a1, CActorManager_30c60* a2, Fn_30c60 a3) {
    typedef Closure4_30c60<CActorManager_30c60, void, const char*, float, float, float> Alloc_30c60;
    HULK_SIZE32(Alloc_30c60, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30c60));
    void* x = 0;
    if (m) {
        ((Raw_30c60*)m)->FUN_0002d830(a1, a3);
        x = new (m) Closure4_30c60<CActorManager_30c60, void, const char*, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f8e68f21

// 0x00030cc0 FUN_00030cc0 (109 B): equivalent/0x00030cc0.cpp [wrapped: conflict: CActorManager; Closure0; Method0]
// sym: ?FUN_00030cc0@Registry_30cc0@fn_00030cc0@@QAEXPBDPAVCActorManager@2@P832@AEXXZ@Z @ca19b424712b @waab1df37046b
namespace fn_00030cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00030cc0 @ 0x00030cc0
// FUN_00030cc0 @ 0x00030cc0  (generated by work/closure/gen.py)
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


class CActorManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_30cc0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_30cc0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_30cc0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_30cc0(name, 0) {
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

struct Registry_30cc0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00030cc0(const char* name, CActorManager* owner, void (CActorManager::*fn)());
};

void Registry_30cc0::FUN_00030cc0(const char* name, CActorManager* owner, void (CActorManager::*fn)()) {
    typedef Closure0<CActorManager, void> Alloc_30cc0;
    HULK_SIZE32(Alloc_30cc0, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CActorManager, void>));
    Closure0<CActorManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CActorManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_00030cc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f8e68f21 {

// 0x00030d30 FUN_00030d30 (83 B): equivalent/0x00030d30.cpp
// sym: ?FUN_00030d30@Registry_30d30@fn_f8e68f21@@QAEXPBDPAVCActorManager_30d30@2@P832@AEX00MMM@Z@Z @b5e44df43da4 @wc973722eca75
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030d30 @ 0x00030d30
// FUN_00030d30 @ 0x00030d30  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30d30::FUN_00030d30(const char* a1, CActorManager_30d30* a2, Fn_30d30 a3) {
    typedef Closure5_30d30<CActorManager_30d30, void, const char*, const char*, float, float, float> Alloc_30d30;
    HULK_SIZE32(Alloc_30d30, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30d30));
    void* x = 0;
    if (m) {
        ((Raw_30d30*)m)->FUN_0002d960(a1, a3);
        x = new (m) Closure5_30d30<CActorManager_30d30, void, const char*, const char*, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030d90 FUN_00030d90 (83 B): equivalent/0x00030d90.cpp
// sym: ?FUN_00030d90@Registry_30d90@fn_f8e68f21@@QAEXPBDPAVCActorManager_30d90@2@P832@AE_N0MM@Z@Z @91888fbbf44c @w255885b63ea5
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030d90 @ 0x00030d90
// FUN_00030d90 @ 0x00030d90  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30d90::FUN_00030d90(const char* a1, CActorManager_30d90* a2, Fn_30d90 a3) {
    typedef Closure3_30d90<CActorManager_30d90, bool, const char*, float, float> Alloc_30d90;
    HULK_SIZE32(Alloc_30d90, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30d90));
    void* x = 0;
    if (m) {
        ((Raw_30d90*)m)->FUN_0002da60(a1, a3);
        x = new (m) Closure3_30d90<CActorManager_30d90, bool, const char*, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030df0 FUN_00030df0 (83 B): equivalent/0x00030df0.cpp
// sym: ?FUN_00030df0@Registry_30df0@fn_f8e68f21@@QAEXPBDPAVCActorManager_30df0@2@P832@AEX0MM@Z@Z @28632c009b9c @w6bc4127d3191
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030df0 @ 0x00030df0
// FUN_00030df0 @ 0x00030df0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30df0::FUN_00030df0(const char* a1, CActorManager_30df0* a2, Fn_30df0 a3) {
    typedef Closure3_30df0<CActorManager_30df0, void, const char*, float, float> Alloc_30df0;
    HULK_SIZE32(Alloc_30df0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30df0));
    void* x = 0;
    if (m) {
        ((Raw_30df0*)m)->FUN_0002db20(a1, a3);
        x = new (m) Closure3_30df0<CActorManager_30df0, void, const char*, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030ea0 FUN_00030ea0 (83 B): equivalent/0x00030ea0.cpp
// sym: ?FUN_00030ea0@Registry_30ea0@fn_f8e68f21@@QAEXPBDPAVCActorManager_30ea0@2@P832@AEX00M@Z@Z @c0af818f3063 @w614f85a8c621
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030ea0 @ 0x00030ea0
// FUN_00030ea0 @ 0x00030ea0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30ea0::FUN_00030ea0(const char* a1, CActorManager_30ea0* a2, Fn_30ea0 a3) {
    typedef Closure3_30ea0<CActorManager_30ea0, void, const char*, const char*, float> Alloc_30ea0;
    HULK_SIZE32(Alloc_30ea0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30ea0));
    void* x = 0;
    if (m) {
        ((Raw_30ea0*)m)->FUN_0002dc60(a1, a3);
        x = new (m) Closure3_30ea0<CActorManager_30ea0, void, const char*, const char*, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00030f00 FUN_00030f00 (83 B): equivalent/0x00030f00.cpp
// sym: ?FUN_00030f00@Registry_30f00@fn_f8e68f21@@QAEXPBDPAVCActorManager_30f00@2@P832@AEX00MM@Z@Z @7952045bcbc7 @w909628140cb4
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00030f00 @ 0x00030f00
// FUN_00030f00 @ 0x00030f00  (generated by tools/equiv_gen/reg_helper.py)
void Registry_30f00::FUN_00030f00(const char* a1, CActorManager_30f00* a2, Fn_30f00 a3) {
    typedef Closure4_30f00<CActorManager_30f00, void, const char*, const char*, float, float> Alloc_30f00;
    HULK_SIZE32(Alloc_30f00, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_30f00));
    void* x = 0;
    if (m) {
        ((Raw_30f00*)m)->FUN_0002dd00(a1, a3);
        x = new (m) Closure4_30f00<CActorManager_30f00, void, const char*, const char*, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00031000 FUN_00031000 (70 B): matches/0x00031000.cpp
// sym: ?FUN_00031000@Registry_31000@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEPBD00@Z@Z
void Registry_31000::FUN_00031000(const char* a1, Owner* a2, Fn_31000 a3) {
    HULK_SIZE32(Closure2_31000, 0x24);
    Closure2_31000* e = new Closure2_31000(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}


// 0x00031050 FUN_00031050 (70 B): matches/0x00031050.cpp
// sym: ?FUN_00031050@Registry_31050@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEXM@Z@Z
void Registry_31050::FUN_00031050(const char* a1, Owner* a2, Fn_31050 a3) {
    HULK_SIZE32(Closure1_31050, 0x24);
    Closure1_31050* e = new Closure1_31050(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}

} // namespace fn_f8e68f21

// 0x000310a0 FUN_000310a0 (109 B): equivalent/0x000310a0.cpp [wrapped: conflict: CActorManager; Closure0; Method0]
// sym: ?FUN_000310a0@Registry_310a0@fn_000310a0@@QAEXPBDPAVCActorManager@2@P832@AEMXZ@Z @56c31fbe0596 @wd1f2bed4c515
namespace fn_000310a0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000310a0 @ 0x000310a0
// FUN_000310a0 @ 0x000310a0  (generated by work/closure/gen.py)
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


class CActorManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_310a0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_310a0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_310a0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_310a0(name, 0) {
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

struct Registry_310a0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000310a0(const char* name, CActorManager* owner, float (CActorManager::*fn)());
};

void Registry_310a0::FUN_000310a0(const char* name, CActorManager* owner, float (CActorManager::*fn)()) {
    typedef Closure0<CActorManager, float> Alloc_310a0;
    HULK_SIZE32(Alloc_310a0, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CActorManager, float>));
    Closure0<CActorManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CActorManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_000310a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f8e68f21 {

// 0x000311b0 FUN_000311b0 (70 B): matches/0x000311b0.cpp
// sym: ?FUN_000311b0@Registry_311b0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AEX_N@Z@Z
void Registry_311b0::FUN_000311b0(const char* a1, Owner* a2, Fn_311b0 a3) {
    HULK_SIZE32(Closure1_311b0, 0x24);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(new Closure1_311b0(a1, a2, a3)));
}


// 0x00031200 FUN_00031200 (83 B): equivalent/0x00031200.cpp
// sym: ?FUN_00031200@Registry_31200@fn_f8e68f21@@QAEXPBDPAVCActorManager_31200@2@P832@AEXHHH@Z@Z @39326d2b8320 @w064c113405a7
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00031200 @ 0x00031200
// FUN_00031200 @ 0x00031200  (generated by tools/equiv_gen/reg_helper.py)
void Registry_31200::FUN_00031200(const char* a1, CActorManager_31200* a2, Fn_31200 a3) {
    typedef Closure3_31200<CActorManager_31200, void, int, int, int> Alloc_31200;
    HULK_SIZE32(Alloc_31200, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_31200));
    void* x = 0;
    if (m) {
        ((Raw_31200*)m)->FUN_0002e2b0(a1, a3);
        x = new (m) Closure3_31200<CActorManager_31200, void, int, int, int>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x00031260 FUN_00031260 (83 B): equivalent/0x00031260.cpp
// sym: ?FUN_00031260@Registry_31260@fn_f8e68f21@@QAEXPBDPAVCActorManager_31260@2@P832@AE_N0VVector_31260@math@@2@Z@Z @f4dcf3c0650e @wcfdb8e40a7c3
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_00031260 @ 0x00031260
// FUN_00031260 @ 0x00031260  (generated by tools/equiv_gen/reg_helper.py)
void Registry_31260::FUN_00031260(const char* a1, CActorManager_31260* a2, Fn_31260 a3) {
    typedef Closure3_31260<CActorManager_31260, bool, const char*, math::Vector_31260, math::Vector_31260> Alloc_31260;
    HULK_SIZE32(Alloc_31260, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_31260));
    void* x = 0;
    if (m) {
        ((Raw_31260*)m)->FUN_0002e350(a1, a3);
        x = new (m) Closure3_31260<CActorManager_31260, bool, const char*, math::Vector_31260, math::Vector_31260>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x000312c0 FUN_000312c0 (70 B): equivalent/0x000312c0.cpp
// sym: ?FUN_000312c0@Registry_312c0@fn_f8e68f21@@QAEXPBDPAVOwner@2@P832@AE_N0VVector_312c0@math@@@Z@Z @46ed78ee6ec7 @wa38084198f06
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000312c0 @ 0x000312c0
// FUN_000312c0 @ 0x000312c0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_312c0::FUN_000312c0(const char* a1, Owner* a2, Fn_312c0 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_312c0* e = (Closure2_312c0*)FUN_0008d690((int)sizeof(ScriptClosureView));
    void* x = 0;
    if (e)
        x = e->FUN_00030130(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f8e68f21

// 0x00031310 FUN_00031310 (12490 B): equivalent/0x00031310.cpp [wrapped: macros]
// sym: ?Register@CActorManager@fn_00031310@@QAEXXZ @d874a6e6706b @w2b7d11ce1754
namespace fn_00031310 {
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 314/314)
// FUN_00031310 @ 0x00031310

extern "C" void* FUN_0008d690(unsigned int);
class CActorManager;
extern char DAT_0048e128,DAT_0048e0e4,DAT_0048e0f0,DAT_0048e134,DAT_0048e100,DAT_0048e10c;
char FUN_001d04d0(const void*) throw();
class Base : public ScriptFunctionFields {public: virtual void v(); Base(const char*,int) throw();};
template<class C,class R,class A> class Method1:public Base {public: R (C::*f)(A); Method1(const char*n,R (C::*x)(A),const void*r,const void*a):Base(n,1){f=x;retType=FUN_001d04d0(r);argTypes[0]=FUN_001d04d0(a);} virtual void v();};
template<class C,class R,class A> class Closure1:public Method1<C,R,A> {public:C* owner; Closure1(const char*n,C*o,R (C::*f)(A),const void*r,const void*a):Method1<C,R,A>(n,f,r,a){owner=o;} virtual void v();};
typedef float Float; typedef bool Bool; typedef const char* String; typedef int Int; typedef void Void; struct Vector {float x,y,z;};
class CActorManager {
public:
    void Register();
    // The member functions bound to Lua below (types: the game's Closure<N> instantiations).
    int FUN_000241c0(const char*);
    const char* FUN_000243d0();
    bool FUN_00024480(const char*, bool);
    void FUN_000244b0(bool);
    void FUN_000244c0(float, float);
    void FUN_00024570(bool);
    void FUN_00024770(int);
    int FUN_00024780(const char*);
    int FUN_00024800();
    int FUN_00024840(const char*);
    const char* FUN_000248e0(int);
    void FUN_00024950(int);
    bool FUN_00024970(int);
    bool FUN_000249d0();
    bool FUN_00024a10();
    int FUN_00024a90(const char*);
    void FUN_00024b80();
    void FUN_00024b90(float);
    void FUN_00024bb0(int);
    float FUN_00024bd0(const char*);
    void FUN_00024c10(const char*, float);
    float FUN_00024c40(const char*);
    void FUN_00024c80(const char*, float);
    float FUN_00024cb0(const char*);
    void FUN_00024cf0(const char*, float);
    int FUN_00024d20(const char*);
    void FUN_00024d50(const char*, int);
    void FUN_00024e90(int, const char*);
    void FUN_00024f10();
    void FUN_00024f20(float);
    float FUN_00024f40();
    bool FUN_00024f50();
    int FUN_00024f60(const char*);
    const char* FUN_00025010(const char*, int);
    Vector FUN_00025420(Vector, float);
    void FUN_000254d0(int, int, int);
    void FUN_00025500();
    void FUN_00025530(float);
    void FUN_00025560();
    void FUN_00025570(int);
    int FUN_00025580();
    void FUN_00025820(const char*, const char*);
    void FUN_000258b0(const char*, Vector);
    const char* FUN_00025d50(Vector);
    void FUN_00025f10(const char*, bool);
    void FUN_00025fc0(const char*);
    bool FUN_00026890(const char*, bool);
    bool FUN_000268d0(const char*, bool);
    bool FUN_00026910(const char*, Vector);
    bool FUN_00026950(const char*, int);
    int FUN_00026990(const char*);
    void FUN_000269c0(const char*, bool);
    void FUN_00026ab0(const char*, bool);
    void FUN_00026ae0(const char*, int);
    void FUN_00026b10(const char*, Vector);
    Vector FUN_00026c30(const char*);
    Vector FUN_00026cc0(const char*);
    Vector FUN_00026d50(const char*);
    void FUN_00026db0(const char*, float);
    float FUN_00026df0(const char*);
    bool FUN_00026f30(const char*, const char*);
    void FUN_00026fb0(const char*, const char*);
    void FUN_00026ff0(const char*, int);
    void FUN_00027030(const char*, float);
    void FUN_00027060(const char*, const char*);
    int FUN_000270a0(const char*);
    void FUN_000270d0(const char*, int);
    bool FUN_00027100(const char*);
    void FUN_00027130(const char*, bool);
    bool FUN_00027160(const char*);
    void FUN_00027190(const char*, bool);
    void FUN_000271c0(const char*, const char*);
    void FUN_00027200(const char*, bool);
    void FUN_00027230(const char*, bool);
    bool FUN_00027270(const char*);
    void FUN_000272a0(const char*, bool);
    void FUN_000272d0(const char*, int);
    void FUN_00027300(const char*, float);
    void FUN_00027370(const char*, float);
    void FUN_000273a0(const char*, float);
    void FUN_000273d0(const char*, float);
    void FUN_00027400(const char*, float);
    void FUN_00027430(const char*, int);
    void FUN_00027460(const char*, float);
    void FUN_00027490(const char*, float);
    bool FUN_000274c0(const char*);
    void FUN_000274f0(const char*, bool);
    void FUN_00027520(const char*, float);
    float FUN_00027550(const char*);
    float FUN_00027590(const char*);
    void FUN_000275d0(const char*, bool);
    bool FUN_00027600(const char*);
    int FUN_00027630(const char*);
    void FUN_00027670(const char*, const char*);
    void FUN_000276b0(const char*, const char*);
    void FUN_000276f0(const char*, const char*);
    bool FUN_00027730(const char*, const char*);
    bool FUN_00027850(const char*, const char*);
    bool FUN_00027930(const char*, const char*);
    bool FUN_00027a50(const char*, const char*);
    void FUN_00027b50(const char*, float, float, float, float, float, const char*);
    void FUN_00027c90(const char*, const char*);
    void FUN_00027d60(const char*, const char*);
    bool FUN_00027e30(const char*, const char*);
    bool FUN_00027f00(const char*, const char*);
    bool FUN_00027fc0(const char*, const char*);
    bool FUN_00028050(const char*, const char*);
    bool FUN_000280e0(const char*);
    bool FUN_00028130(const char*, int);
    bool FUN_00028180(const char*);
    bool FUN_000281e0(const char*, bool);
    bool FUN_00028220(const char*, bool);
    int FUN_00028260(const char*);
    bool FUN_00028290(const char*, const char*);
    bool FUN_000282f0(const char*, float);
    bool FUN_00028330(const char*, float, float);
    void FUN_00028400(const char*, Vector);
    void FUN_00028470(const char*);
    float FUN_000284c0(const char*);
    bool FUN_00028500(const char*);
    void FUN_00028530(const char*, const char*, float);
    int FUN_000285b0(const char*, const char*);
    void FUN_00028630(const char*, const char*);
    const char* FUN_00028670(const char*, const char*);
    void FUN_000286b0(const char*, const char*);
    void FUN_00028720(const char*, const char*);
    void FUN_00028790(const char*, const char*, float);
    void FUN_000287d0(const char*, bool);
    void FUN_00028810(const char*, bool);
    void FUN_00028840(const char*, float);
    void FUN_000288b0(const char*, float, bool);
    float FUN_00028900(const char*);
    void FUN_00028940(const char*, float);
    float FUN_00028980(const char*);
    float FUN_000289c0(const char*);
    float FUN_00028a00(const char*);
    float FUN_00028a50(const char*);
    int FUN_00028aa0(const char*);
    void FUN_00028ad0(const char*, int);
    int FUN_00028b00(const char*);
    void FUN_00028b30(const char*, int);
    float FUN_00028b60(const char*);
    void FUN_00028ba0(const char*, float, const char*);
    const char* FUN_00028c20(const char*);
    int FUN_00028c60(const char*);
    void FUN_00028ca0(const char*);
    void FUN_00028ce0(const char*);
    bool FUN_00028d20(const char*);
    void FUN_00028d60(const char*);
    void FUN_00028da0(const char*);
    void FUN_00028de0(const char*, const char*);
    void FUN_00028e30(const char*);
    void FUN_00028e90(const char*, const char*);
    const char* FUN_00028ee0(const char*);
    int FUN_00028f30(const char*);
    int FUN_00028f80(const char*);
    void FUN_00028fd0(const char*);
    int FUN_00029010(const char*);
    void FUN_000290a0(const char*);
    void FUN_000290f0(const char*);
    void FUN_00029140(Vector, float);
    void FUN_00029340(const char*);
    void FUN_00029390(const char*, float, int, float);
    void FUN_000293f0(const char*, float, float, float);
    void FUN_00029440(const char*, bool);
    void FUN_00029470(const char*);
    void FUN_000294a0(const char*, const char*, float, float, float);
    void FUN_00029500(const char*, const char*);
    const char* FUN_000295a0(const char*);
    void FUN_00029620(const char*, bool);
    void FUN_00029660(const char*, bool);
    void FUN_000296a0(const char*, const char*, float);
    void FUN_00029740(const char*, const char*, float, float);
    bool FUN_00029820(const char*, const char*);
    void FUN_00029890(const char*);
    void FUN_000298d0(const char*, bool);
    void FUN_00029910(const char*, int);
    int FUN_00029950(const char*);
    int FUN_00029990();
    bool FUN_00029a50(const char*);
    void FUN_00029c50(const char*, int);
    void FUN_00029c90(const char*, bool);
    bool FUN_00029cd0(const char*);
    void FUN_00029d10(const char*, bool);
    bool FUN_00029d50(const char*);
    void FUN_00029d90(const char*, bool);
    bool FUN_00029dd0(const char*);
    void FUN_00029e20(const char*, bool);
    bool FUN_00029e60(const char*);
    bool FUN_00029ea0(const char*);
    float FUN_00029ed0(const char*);
    bool FUN_00029fc0(const char*);
    bool FUN_0002a000(const char*);
    void FUN_0002a030(const char*, bool);
    bool FUN_0002a060(const char*);
    void FUN_0002a0a0(const char*, Vector);
    bool FUN_0002a0e0(const char*, Vector, Vector);
    const char* FUN_0002a1a0(const char*);
    const char* FUN_0002a200(const char*);
    bool FUN_0002a250(const char*, const char*);
    const char* FUN_0002a2b0(const char*);
    void FUN_0002a310(const char*);
    void FUN_0002a350(const char*);
    void FUN_0002b310(const char*, float);
    void FUN_0002b380(const char*, float, float);
    float FUN_0002b450(const char*, const char*);
    float FUN_0002b4f0(const char*, const char*);
    bool FUN_0002b730(const char*);
    bool FUN_0002b830(const char*);
    bool FUN_0002b860(Vector);
    void FUN_0002bf50(int);
    bool FUN_0002bf80(const char*, Vector, float, const char*, const char*, bool, const char*);
    bool FUN_0002bfd0(const char*, Vector, float, const char*, const char*, bool, const char*);
    bool FUN_0002c050(const char*, const char*, const char*, const char*, bool, const char*);
    void FUN_0002c0e0(bool);
    bool FUN_0002c0f0();
    void FUN_0002c100(bool);
};
class Entry {public: void* FUN_0002e4f0(const char*, CActorManager*, bool (CActorManager::*)(const char*, bool)); void* FUN_0002e5a0(const char*, CActorManager*, void (CActorManager::*)(const char*, Vector)); void* FUN_0002e650(const char*, CActorManager*, void (CActorManager::*)(const char*, float)); void* FUN_0002e6f0(const char*, CActorManager*, void (CActorManager::*)(const char*, int)); void* FUN_0002ebe0(const char*, CActorManager*, void (CActorManager::*)(const char*, bool)); void* FUN_0002ec80(const char*, CActorManager*, void (CActorManager::*)(float, float)); void* FUN_0002ef40(const char*, CActorManager*, bool (CActorManager::*)(const char*, const char*)); void* FUN_0002eff0(const char*, CActorManager*, void (CActorManager::*)(const char*, const char*)); void* FUN_0002f3b0(const char*, CActorManager*, void (CActorManager::*)(int, const char*)); void* FUN_0002f450(const char*, CActorManager*, void (CActorManager::*)(Vector, float)); void* FUN_0002f500(const char*, CActorManager*, bool (CActorManager::*)(const char*, int)); void* FUN_0002f9c0(const char*, CActorManager*, bool (CActorManager::*)(const char*, float)); void* FUN_0002fb60(const char*, CActorManager*, const char* (CActorManager::*)(const char*, int)); void* FUN_0002fc10(const char*, CActorManager*, int (CActorManager::*)(const char*, const char*)); void* FUN_0002fcc0(const char*, CActorManager*, const char* (CActorManager::*)(const char*, const char*)); void* FUN_0002fe90(const char*, CActorManager*, Vector (CActorManager::*)(Vector, float)); void* FUN_0002ff20(const char*, CActorManager*, float (CActorManager::*)(const char*, const char*)); };
class Registry {public:void FUN_001d3b70(const char*,void*);
void* FUN_000303d0(const char*, CActorManager*, void (CActorManager::*)(const char*, float, bool)); void* FUN_00030430(const char*, CActorManager*, void (CActorManager::*)(const char*, float, const char*)); void* FUN_00030530(const char*, CActorManager*, bool (CActorManager::*)(const char*, const char*, const char*, const char*, bool, const char*)); void* FUN_00030590(const char*, CActorManager*, bool (CActorManager::*)(const char*, Vector, float, const char*, const char*, bool, const char*)); void* FUN_000306e0(const char*, CActorManager*, const char* (CActorManager::*)()); void* FUN_00030750(const char*, CActorManager*, int (CActorManager::*)()); void* FUN_000309f0(const char*, CActorManager*, void (CActorManager::*)(const char*, float, float, float, float, float, const char*)); void* FUN_00030b90(const char*, CActorManager*, bool (CActorManager::*)()); void* FUN_00030c00(const char*, CActorManager*, void (CActorManager::*)(const char*, float, int, float)); void* FUN_00030c60(const char*, CActorManager*, void (CActorManager::*)(const char*, float, float, float)); void* FUN_00030cc0(const char*, CActorManager*, void (CActorManager::*)()); void* FUN_00030d30(const char*, CActorManager*, void (CActorManager::*)(const char*, const char*, float, float, float)); void* FUN_00030d90(const char*, CActorManager*, bool (CActorManager::*)(const char*, float, float)); void* FUN_00030df0(const char*, CActorManager*, void (CActorManager::*)(const char*, float, float)); void* FUN_00030ea0(const char*, CActorManager*, void (CActorManager::*)(const char*, const char*, float)); void* FUN_00030f00(const char*, CActorManager*, void (CActorManager::*)(const char*, const char*, float, float)); void* FUN_000310a0(const char*, CActorManager*, float (CActorManager::*)()); void* FUN_00030380(const char*, CActorManager*, bool (CActorManager::*)(const char*)); void* FUN_00030240(const char*, CActorManager*, void (CActorManager::*)(const char*, Vector)); void* FUN_000311b0(const char*, CActorManager*, void (CActorManager::*)(bool)); void* FUN_00031200(const char*, CActorManager*, void (CActorManager::*)(int, int, int)); void* FUN_000305f0(const char*, CActorManager*, void (CActorManager::*)(const char*, bool)); void* FUN_00031050(const char*, CActorManager*, void (CActorManager::*)(float)); void* FUN_00031260(const char*, CActorManager*, bool (CActorManager::*)(const char*, Vector, Vector)); void* FUN_00030860(const char*, CActorManager*, void (CActorManager::*)(const char*, const char*)); void* FUN_000302e0(const char*, CActorManager*, void (CActorManager::*)(const char*, int)); void* FUN_00030290(const char*, CActorManager*, void (CActorManager::*)(const char*, float)); void* FUN_000304e0(const char*, CActorManager*, const char* (CActorManager::*)(const char*)); void* FUN_00030810(const char*, CActorManager*, bool (CActorManager::*)(const char*, const char*)); void* FUN_00030690(const char*, CActorManager*, void (CActorManager::*)(const char*)); void* FUN_000301f0(const char*, CActorManager*, bool (CActorManager::*)(const char*, bool)); void* FUN_000312c0(const char*, CActorManager*, bool (CActorManager::*)(const char*, Vector)); void* FUN_00030af0(const char*, CActorManager*, bool (CActorManager::*)(const char*, int)); void* FUN_00030490(const char*, CActorManager*, int (CActorManager::*)(const char*));
};
extern "C" Registry* FUN_001d4c90();
#define E(n,a,b) {HULK_SIZE32(ScriptClosureView,0x24);Entry*e=(Entry*)FUN_0008d690((unsigned int)sizeof(ScriptClosureView));void*x=0;if(e)x=e->FUN_##a("am_" #n,this,&CActorManager::FUN_##b);r->FUN_001d3b70("am_" #n,x);}
#define G(n,R,A,b) {r->FUN_001d3b70("am_" #n,new Closure1<CActorManager,R,A>("am_" #n,this,&CActorManager::FUN_##b,&t##R,&t##A));}
#define O(n,a,b) {r->FUN_##a("am_" #n,this,&CActorManager::FUN_##b);}
#define tFloat DAT_0048e128
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tInt DAT_0048e134
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
void CActorManager::Register(){Registry*r=FUN_001d4c90();if(!r)return;
E(LoadFightScript,0002e4f0,00024480) E(SetActorPosition,0002e5a0,00026b10) E(SetActorOrientation,0002e650,00026db0) E(SetActorCollectable,0002e6f0,00029c50)
G(GetCharacterHealth,Float,String,000284c0) E(SetCharacterHealth,0002e650,00028840) G(GetCharacterAllowedToRegenerate,Bool,String,00028500) O(ApplyCharacterDamage,000303d0,000288b0) G(GetCharacterMaxHealth,Float,String,00028900) E(SetCharacterMaxHealth,0002e650,00028940) G(GetTemplateMaxHealth,Float,String,00024bd0) E(SetTemplateMaxHealth,0002e650,00024c10) G(GetCharacterEnterRage,Float,String,00028980) G(GetCharacterEnterAdrenalineBoost,Float,String,000289c0) G(GetCharacterIncreaseOnEnterRage,Float,String,00028a00) G(GetCharacterDecreaseOnExitRage,Float,String,00028a50) G(GetCharacterCharge,Float,String,00028b60) O(SetCharacterCharge,00030430,00028ba0) G(GetTemplateInterruptAccumulatorMax,Float,String,00024c40) E(SetTemplateInterruptAccumulatorMax,0002e650,00024c80) G(GetTemplateInterruptAccumulatorRate,Float,String,00024cb0) E(SetTemplateInterruptAccumulatorRate,0002e650,00024cf0) G(GetTemplateInterruptPriority,Int,String,00024d20) E(SetTemplateInterruptPriority,0002e6f0,00024d50) G(GetCharacterInterruptPriority,Int,String,00028aa0) E(SetCharacterInterruptPriority,0002e6f0,00028ad0) G(GetCharacterTargetPriority,Int,String,00028b00) E(SetCharacterTargetPriority,0002e6f0,00028b30) G(GetCharacterGrapplee,String,String,00028c20) G(GetActorLifeState,Int,String,00028c60)
O(CreateActor,00030530,0002c050) O(CreateActorAtPosition,00030590,0002bf80) O(CreateActorAtPositionInAir,00030590,0002bfd0) E(SetNPCDisabled,0002ebe0,00025f10) E(EnergyDoorSetParams,0002ec80,000244c0) G(SetMainActor,Void,String,00025fc0) O(GetMainCharacterName,000306e0,000243d0) G(GetActorCountByName,Int,String,00024780) O(GetEnemyCount,00030750,00024800) G(GetEnemyCountByTeam,Int,String,00024840) G(GetEnemyName,String,Int,000248e0) E(IsActorOnTeam,0002ef40,00026f30) E(SetActorTeam,0002eff0,00026fb0) G(GetActorPosition,Vector,String,00026c30) G(GetActorStaticGroundPoint,Vector,String,00026d50) G(GetActorOrientation,Float,String,00026df0) G(GetActorVelocity,Vector,String,00026cc0) G(KillEnemy,Void,Int,0002bf50) G(KillTeam,Bool,String,0002b730) G(KillActorByName,Bool,String,0002b830) G(KillActorNearestPosition,Bool,Vector,0002b860) G(FindActorNearestPosition,String,Vector,00025d50) O(PlayHitReaction,000309f0,00027b50) E(PlayFightNode,0002eff0,00027c90) E(PlayAIFightNode,0002eff0,00027d60) E(IsFightNodeStarting,0002ef40,00027e30) E(IsFightNodePlaying,0002ef40,00027f00) E(IsFightNodePlayingAChildOf,0002ef40,00027fc0) E(IsAIFightNodePlayingAChildOf,0002ef40,00028050) G(IsActorBusy,Bool,String,000280e0) G(Leash,Void,String,00028ca0) G(Unleash,Void,String,00028ce0) G(IsLeashed,Bool,String,00028d20) G(UnleashAtEndOfPath,Void,String,00028d60) G(LeashAtEndOfPath,Void,String,00028da0) E(SetActorPath,0002eff0,00028de0) G(ResetActorPath,Void,String,00028e30) E(SetActorPathFromStart,0002eff0,00028e90) G(GetActorPath,String,String,00028ee0) G(FindActorIndex,Int,String,000241c0) G(GetLastWayPoint,Int,String,00028f30) G(GetNextWayPoint,Int,String,00028f80) G(AdvanceWayPoint,Void,String,00028fd0) G(GetWayPointCount,Int,String,00029010) E(SetAction,0002f3b0,00024e90) G(UpdateKnownPlayerPos,Void,String,000290a0) G(UpdateKnownPlayerPosNoAttack,Void,String,000290f0) G(ForgetKnownPlayerPos,Void,String,00029340) E(EmitInterestingSound,0002f450,00029140) E(SetActorControllerIndex,0002f500,00028130) G(GetActorControllerIndex,Int,String,00028260) G(SetAllActorControllerIndex,Bool,Int,00024970) O(ResetAllActorControllerIndex,00030b90,000249d0) O(ResetAllActorSequencers,00030b90,00024a10) G(ResetActorSequencer,Bool,String,00028180) E(SetIgnoreFriendlyFire,0002e4f0,00028220) E(SetMissilePunchAllowed,0002e4f0,000281e0) O(SetPatrolParams,00030c00,00029390) O(SetPatrolBreakOffParams,00030c60,000293f0) E(SetFightingOtherNPCMode,0002ebe0,00029440) G(UpdateNPCForcedTargetByName,Void,String,00029470) O(UpdateAllNPCForcedTargets,00030cc0,00024f10) O(SetGotoLocation,00030d30,000294a0) E(IsActorUsingTemplate,0002ef40,00028290) G(GetActorUsingTemplateCount,Int,String,00024a90) O(IsActorIntentionMotion,00030d90,00028330) E(SetActorIntentionFacing,0002e650,0002b310) O(SetActorIntentionFacingXZ,00030df0,0002b380) E(SetActorIntentionFacingVector,0002e5a0,00028400) G(ClearActorIntentionFacing,Void,String,00028470) E(IsActorExpendable,0002f9c0,000282f0) E(SetNeverExpendable,0002ebe0,00026ab0) E(SetExpendablePriority,0002e6f0,00026ae0) G(SetExpendablePriorityForNextSpawn,Void,Int,00024770) G(SetMaxActorCountForPerformance,Void,Int,00025570) O(GetMaxActorCountForPerformance,00030750,00025580) E(SetTarget,0002eff0,00029500) G(GetTarget,String,String,000295a0) E(SetCanFireAtTargetAlways,0002ebe0,00029620) E(AlwaysFaceTarget,0002ebe0,00029660) O(SetDefendActor,00030ea0,000296a0) O(SetDefendLocation,00030f00,00029740) E(IsDefendingLocation,0002ef40,00029820) G(NumDefendingLocation,Int,String,00024f60) E(GetActorDefendingLocation,0002fb60,00025010) G(StopDefending,Void,String,00029890) E(DisableMovement,0002ebe0,000298d0) E(SetAlertStatus,0002e6f0,00029910) G(GetAlertStatus,Int,String,00029950) O(GetHighestAlertStatus,00030750,00029990) G(GetActorHasEngaged,Bool,String,00029a50) E(OverrideAIState,0002e6f0,00026ff0) G(GetAIState,Int,String,00027630) E(SetActorAvoidMinSpeed,0002e650,00027370) E(SetActorAvoidTolerance,0002e650,000273a0) E(SetActorAvoidRadius,0002e650,00027030) E(SetShotFailsMin,0002e650,000273d0) E(SetShotFailsMax,0002e650,00027400) E(SetShotFailsCount,0002e6f0,00027430) E(SetSemaphoreTimeout,0002e650,00027520) E(SetDamageMultiplier,0002e650,00027460) G(GetDamageMultiplier,Float,String,00027550) E(SetHitReactionDamageMultiplier,0002e650,00027490) G(GetHitReactionDamageMultiplier,Float,String,00027590) G(GetAlwaysKillInNullRoom,Bool,String,000274c0) E(SetAlwaysKillInNullRoom,0002ebe0,000274f0) E(SetOnlyTakeDamageFromThrown,0002ebe0,000275d0) G(GetOnlyTakeDamageFromThrown,Bool,String,00027600) G(SetGroupMaxActive,Void,Int,00024950) E(AddToFormation,0002eff0,00027670) E(SetTemplateAlignment,0002eff0,000276f0) E(RemoveFromFormation,0002eff0,000276b0) O(SetCharacterVariable,00030ea0,00028530) E(GetCharacterVariable,0002fc10,000285b0) E(SetCharacterLocator,0002eff0,00028630) E(GetCharacterLocator,0002fcc0,00028670) E(AddToCharacterPropArray,0002eff0,000286b0) E(DeleteFromCharacterPropArray,0002eff0,00028720) O(SetKeywordWait,00030ea0,00028790) E(SetWaypointBacktrack,0002ebe0,000287d0) E(SetGroupManaged,0002ebe0,00028810) E(SetAlignment,0002eff0,00027060) G(GetRandomKeyWordWait,Int,String,000270a0) E(SetRandomKeyWordWait,0002e6f0,000270d0) E(SetUsesRandomKeyWordWait,0002ebe0,00027190) G(GetUsesRandomKeyWordWait,Bool,String,00027100) E(SetSPCVsSPCCollision,0002ebe0,00027130) G(GetSPCVsSPCCollision,Bool,String,00027160) O(GroupReset,00030cc0,00024b80) G(GroupSetActiveDistance,Void,Float,00024b90) G(GroupSetMinActive,Void,Int,00024bb0) G(GroupSetFloatDelay,Void,Float,00024f20) O(GroupGetFloatDelay,000310a0,00024f40) O(GroupGetPerformingFloatDelay,00030b90,00024f50) E(SignalWait,0002ef40,00027730) E(SignalReceived,0002ef40,00027850) E(SignalComplete,0002ef40,00027930) E(SignalClear,0002ef40,00027a50) E(RotateYVector,0002fe90,00025420) E(SetActorInvincible,0002ebe0,00029c90) G(IsActorInvincible,Bool,String,00029cd0) E(SetActorUninterruptible,0002ebe0,00029d10) G(IsActorUninterruptible,Bool,String,00029d50) E(SetActorInvulnerable,0002ebe0,00029d90) G(IsActorInvulnerable,Bool,String,00029dd0) E(SetActorIntangible,0002ebe0,00029e20) G(IsActorIntangible,Bool,String,00029e60) G(IsActorTargeting,Bool,String,00029ea0) G(GetActorTargetID,Float,String,00029ed0) E(GetActorActorDistance,0002ff20,0002b450) E(GetActorLocatorDistance,0002ff20,0002b4f0)
O(IsActorInRageMode,00030380,00029fc0) O(IsActorOnGround,00030380,0002a060) O(ActorAddMotionVelocity,00030240,0002a0a0) O(DisableSpawning,000311b0,000244b0) O(SetPropsCanBeDamaged,000311b0,0002c0e0) O(IsTimeSlicing,00030b90,0002c0f0) O(SetIsTimeSlicing,000311b0,0002c100) O(SetTimeSliceUpdateCounts,00031200,000254d0) O(ResetTimeSlicing,00030cc0,00025500) O(GetTimeSlicePriority,00030380,0002a000) O(SetTimeSlicePriority,000305f0,0002a030) O(SetCharacterMaxRelativeHeight,00031050,00025530) O(RayCast,00031260,0002a0e0) O(ClearRayCast,00030cc0,00025560) O(SetPatrolPathName,00030860,000271c0) O(SetNeverIgnore,000305f0,00027200) O(SetArmor,000305f0,00027230) O(SetMoveWhenSleepwalking,000305f0,000272a0) O(GetMoveWhenSleepwalking,00030380,00027270) O(SetGrappleReactionType,000302e0,000272d0) O(SetDefendResetRate,00030290,00027300) O(GetPropAttachedUID,000304e0,0002a1a0) O(GetPropAttachedNameDangerous,000304e0,0002a200) O(IsPropAttachedName,00030810,0002a250) O(GetPropAttachedWeaponizableType,000304e0,0002a2b0) O(CharacterReset,00030690,0002a310) O(CharacterResetHealth,00030690,0002a350) O(SetActorCanSleepwalk,000301f0,00026890) O(SetActorCanSleepwalkForNextSpawn,000311b0,00024570) O(SetActorPenguin,000301f0,000268d0) O(SetActorDriftToPosition,000312c0,00026910) O(SetActorLocomotionState,00030af0,00026950) O(GetActorLocomotionState,00030490,00026990) O(SetActorNISMode,000305f0,000269c0) O(SetCrusherString,00030860,00025820) O(SetComboMessageColour,00030240,000258b0)
}
} // namespace fn_00031310
#undef E
#undef G
#undef O
#undef tBool
#undef tFloat
#undef tInt
#undef tString
#undef tVector
#undef tVoid

