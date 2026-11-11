// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d0620..0x001d4d50 (kind game, layer game, confidence high), dominant class ScriptHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/lua.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f55829c3 {
#define TREE_TU_END }
namespace fn_f55829c3 {} using namespace fn_f55829c3;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f55829c3 {
extern "C" float __cdecl FUN_00339f40(LuaVMState* L, int narg, float def);
extern "C" void* __cdecl FUN_00213d30(LuaVMState* L, unsigned int size);
extern "C" void __cdecl FUN_00338f30(LuaVMState* L, const char* tname);
extern "C" int __cdecl FUN_002138e0(LuaVMState* L, int objindex);
extern "C" void* __cdecl FUN_00213260(LuaVMState*, int);
extern "C" void __cdecl FUN_002136d0(LuaVMState*, int);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" int __cdecl FUN_00212f70(LuaVMState*, int);
extern "C" float __cdecl FUN_002130e0(LuaVMState*, int);
extern "C" void __cdecl FUN_00213340(LuaVMState*, float);
extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
extern "C" void __cdecl FUN_00213c40(LuaVMState*);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int a, int b);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* msg, unsigned int len);
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00338eb0(LuaVMState* L, const char* tname);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
} // namespace fn_f55829c3
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned);
#endif
namespace fn_f55829c3 {
extern "C" void FUN_00267090(void*);
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_002135a0(LuaVMState*, int, const char*);
extern "C" void __cdecl FUN_002139a0(LuaVMState*, int, int);
extern "C" const char* __cdecl FUN_00213190(LuaVMState*, int);
typedef int(__cdecl* Fn_1d0cf0)(LuaVMState*);
extern "C" void __cdecl FUN_00212de0(LuaVMState*, int);
extern "C" int __cdecl FUN_00212fe0(LuaVMState* L, int idx);
typedef int(__cdecl* Fn_1d0d30)(LuaVMState*, void*);
extern float hulk_at_003f32e0;
extern "C" int __cdecl FUN_00213160(LuaVMState*, int);
class SortedList : public ScriptFunctionList {
public:
    bool FUN_001d1180(ScriptFunctionView *e);
};
struct Item_1d1360 : public ScriptFunctionFields {
    virtual ~Item_1d1360() throw();
};
class ItemList_1d1360 : public ScriptFunctionList {
public:
    bool FUN_001d1360(ScriptFunctionView *key);
};
struct Entry_1d1410 {
    int field_00;
    char name[1];
};
class SortedTable {
public:
    Entry_1d1410* items[20];
    int count;
    bool Insert(Entry_1d1410* e);
};
extern int __cdecl FUN_00096670(const char *, const char *, unsigned int);
struct Entry_1d1490 { int header; char text[1]; };
struct Table_1d1490 {
 Entry_1d1490 *entries[20];
 int count;
 char *FUN_001d1490(const char *prefix, const char *previous);
};
extern "C" void __cdecl FUN_00213ba0(LuaVMState*, int, int);
struct Obj {
    int first;
    char names[0x280];
    int values[10];
    char flags[10];
    Obj();
};
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
struct Target_1d16a0 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d16a0(const char *name, float val);
};
extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
struct ScriptHandler_1d3c90 {
    void FUN_001d1740(LuaVMState* L);
};
extern "C" {
LuaVMState* __cdecl FUN_00213290(void*, int);
}
extern "C++" __declspec(nothrow) void __cdecl FUN_00213380(void*, const char*, unsigned int);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213600(void*, int);
extern "C++" __declspec(nothrow) void __cdecl FUN_002133d0(void*, const char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212ed0(void*, int);
extern "C" {
void __cdecl FUN_002139f0(void*, int, int, int);
}
extern "C++" __declspec(nothrow) const char* __cdecl FUN_00213190(void*, int);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212d80(void*, int);
extern "C" void __cdecl FUN_00339710(LuaVMState* L, int t, int ref);
extern "C" void __cdecl FUN_00213640(LuaVMState*, int, int);
extern "C" void FUN_00267760(char* buffer, unsigned int size, const char* format, ...);
struct Owner_1d1a70 : public ScriptHandlerFields {
    virtual void v0();
    bool FUN_001d1a70(float*);
};
typedef unsigned int u32_1d1ac0;
typedef unsigned int U32_1d1b70;
extern "C" int __cdecl FUN_00339650(LuaVMState*, int);
class Obj_1d1b70 : public ScriptHandlerFields {
  public:
    virtual void v0();
    bool Target(U32_1d1b70* out);
};
extern "C" void __cdecl FUN_00213320(LuaVMState*);
extern "C" int __cdecl FUN_00213c50(LuaVMState*, int);
class Obj_1d1c70 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void FUN_001d1c70();
};
class Target_1d1d10 : public ScriptHandlerFields {
  public:
    virtual void v0();
    unsigned char FUN_001d1d10();
};
class Target_1d1d30 : public ScriptHandlerFields {
  public:
    virtual void v0();
    unsigned char FUN_001d1d30();
};
extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b);
struct Vec3_1d1e50 {
    float x, y, z;
};
struct Obj_1d1e50 : public ScriptHandlerFields {
    virtual void v0();
    bool FUN_001d1e50(const char* a, Vec3_1d1e50 b);
};
int __cdecl FUN_001d0870(LuaVMState* L, unsigned int* vec);
extern "C" int check(const char*, const char*);
extern "C" void __cdecl FUN_00213550(LuaVMState*, void*);
extern "C" void __cdecl FUN_002134a0(LuaVMState*, LuaVMCFunction, int);
int __cdecl FUN_001d0cf0(LuaVMState*);
int __cdecl FUN_001d0d30(LuaVMState*);
struct Arg_1d2110 {
    void* x;
    char name[0x80];
    void* value;
    unsigned char flag;
};
class A_1d2110 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void f(Arg_1d2110*);
};
extern "C" void __cdecl FUN_00213570(LuaVMState *L, int index);
extern int __cdecl FUN_002139f0(LuaVMState *L, int nargs, int nresults, int errfunc);
class ScriptRunner : public ScriptHandlerFields {
public:
    virtual void v0();
    int FUN_001d2190(const char *function, ScriptCallArgs call, LuaVMState *L);
};
class B_1d26d0 {
  public:
};
class D : public ScriptFunctionList {
  public:
    void FUN_001d1360(B_1d26d0*);
};
class C_1d26d0 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void g(hulk_uintptr, B_1d26d0*);
};
extern "C" void __cdecl FUN_002151e0(LuaVMState* L);
class Obj_1d2700 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void FUN_001d2700();
};
struct Object_1d2760 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d2760();
};
class Table : public ScriptWatchList {
  public:
    Table();
};
extern "C++" __declspec(nothrow) LuaVMState* __cdecl FUN_00213290(LuaVMState* h, int idx);
extern "C" {
int __cdecl FUN_00215d10(LuaVMState* a, int b);
}
extern "C" {
void __cdecl FUN_00213870(LuaVMState* h, int idx, int v);
}
struct Object : public ScriptHandlerFields {
    virtual void v0();
 void FUN_001d1980(const char* key, int mode);
 bool target(const char* key, int mode, bool retry);
};
extern "C" void __cdecl FUN_00213360(LuaVMState*, int);
extern void __cdecl F4_00267760(char*, int, const char*, const char*);
class Obj_1d3030 : public ScriptHandlerFields {
  public:
    virtual void v0();
    char Check_001d2ba0(const char*, int, int);
    const char* Run(const char*, const char*);
};
class CFEManager_1d3120 {
  public:
    void Call(const char*, int);
};
class Function_1d3120 {
  public:
    virtual void f0();
    virtual void f1();
};
class CActorManager_1d31a0;
typedef float (CActorManager_1d31a0::*Fn_1d31a0)(const char*);
class CActorManager_1d31a0 {
  public:
    float Get(const char* s);
};
class ScriptHandler_1d3230 {
  public:
    int Do(const char*);
};
class Function_1d3230 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(ScriptHandler_1d3230*, const char**, int*);
    char pad[24];
};
extern "C" char DAT_00422654[];
class ScriptHandler_1d3250 {};
typedef void (ScriptHandler_1d3250::*Fn_1d3250)(const char*, const char*, const char*, const char*);
class Method4_1d3250 {
  public:
    void* vft;
    ScriptFunctionFields f;
    Fn_1d3250 fn;
    void FUN_001d0480(const char*, int);  // Function::Function(name, argc)
    Method4_1d3250* FUN_001d3250(const char*, Fn_1d3250);
};
struct ScriptHandler_1d32e0 { void invoke(const char *, const char *, const char *, const char *); };
typedef void (ScriptHandler_1d32e0::*HandlerMethod)(const char *, const char *, const char *, const char *);
class ScriptHandler_1d3370;
class ScriptHandler_1d3370 {
  public:
    enum script_state { s0, s1 };
    script_state Get(const char* s);
};
typedef ScriptHandler_1d3370::script_state (ScriptHandler_1d3370::*Fn_1d3370)(const char*);
struct Function_1d3370 {
    virtual void f0();
    virtual void f1();
};
struct Stream {
 virtual void slot0(); virtual void release(); virtual void slot2(); virtual void read(char*, unsigned int, int);
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual unsigned int size();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void reset(); virtual void slot22(); virtual bool valid();
};
extern void __cdecl thunk_FUN_002710d0(Stream**, const char*, int,int,int,int,int,int);
extern "C" char* __cdecl FUN_0008d6d0(unsigned int);
struct ScriptHandler_nv_1d36e0 {
};
extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);
struct ScriptRefresh_1d3bc0;
class ScriptRegistry : public ScriptHandlerFields {
public:
    virtual void v0();
    void FUN_001d2110(ScriptRefresh_1d3bc0* entry);
    void FUN_001d3bc0();
};
struct ScriptHandler_1d3f00 : public ScriptHandlerFields {
    virtual void v0();
    int FUN_001d2810(LuaVMState *, const char *, int, const char *);
    void FUN_001d3f00(const char *text, const char *value);
};
class CActorManager_1d4150 {
  public:
    void Method(const char*, float);
};
struct Pair_1d4150 {
    const char* s;
    float f;
};
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_1d4170 : public CtorV_001d0480 {
  public:
    Function_1d4170(const char* x) : CtorV_001d0480(x, 1) { }
};
class ScriptHandler_1d4170 {};
typedef float (ScriptHandler_1d4170::*Fn_1d4170)(const char*);
class Method1_1d4170 : public Function_1d4170 {
  public:
    virtual void f();
    Fn_1d4170 fn;
    Method1_1d4170(const char* x, Fn_1d4170 z) : Function_1d4170(x) {
        fn = z;
        retType = FUN_001d04d0(((int*)&DAT_0048e128));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e0f0));
    }
};
class Closure1_1d4170 : public Method1_1d4170 {
  public:
    virtual void f();
    ScriptHandler_1d4170* val;
    Closure1_1d4170(const char*, ScriptHandler_1d4170*, Fn_1d4170);
};
class CActorManager_1d41e0 {
  public:
    float Method(const char*);
};
typedef float (CActorManager_1d41e0::*Fn_1d41e0)(const char*);
extern "C" char DAT_00422644[];
extern "C" char DAT_00422800[];
class ScriptHandler_1d4210 {};
typedef const char* (ScriptHandler_1d4210::*Fn_1d4210)(const char*);
class Closure1_1d4210 : public ScriptFunctionFields {
  public:
    virtual void V();
    void Init_001d0480(const char*, int);
    Fn_1d4210 fn;
    ScriptHandler_1d4210* owner;
    Closure1_1d4210* Run(const char*, ScriptHandler_1d4210*, Fn_1d4210);
};
class ScriptHandler_1d42f0 {
  public:
    void Call(const char*, const char*, const char*, const char*);
};
class CAction_1d4440 {
  public:
    virtual void a();
    virtual void b();
    virtual CAction_1d4440* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class ScriptHandler_1d4440 : public CAction_1d4440 {
  public:
    ScriptHandler_1d4440* vfunc_2(unsigned char);
};
struct ScriptHandler_nv_1d4440 {
    void FUN_001d3410();
};
extern void thunk_FUN_00267090(ScriptHandler_1d4440*);
struct R_1d4530 {
    void FUN_00092410();
};
struct ScriptHandler_nv_1d4530 {
    int FUN_001d3c90(LuaVMState** state);
    void FUN_001d3bc0();
};
struct H {
};
struct T_1d4530 {
    char pad[12];
    R_1d4530* r;
};
struct End_1d4530 {
    void FUN_001dbd50();
};
extern H* hulk_at_004dd6ec;
extern T_1d4530* hulk_at_004dd700;
struct ScriptHandler_1d4c90 {
    ScriptHandler_1d4c90* FUN_001d4830();
};
void* __cdecl FUN_0008d690(unsigned int);


// 0x001d0620 FUN_001d0620 (114 B): matches/0x001d0620.cpp
// sym: _FUN_001d0620
extern "C" int __cdecl FUN_001d0620(LuaVMState* L) {
    float x = FUN_00339f40(L, 1, 0.0f);
    float y = FUN_00339f40(L, 2, 0.0f);
    float z = FUN_00339f40(L, 3, 0.0f);
    float* v = (float*)FUN_00213d30(L, 12);
    FUN_00338f30(L, "Vector");
    FUN_002138e0(L, -2);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return 1;
}


// 0x001d06a0 FUN_001d06a0 (130 B): matches/0x001d06a0.cpp
// sym: _FUN_001d06a0
extern "C" int __cdecl FUN_001d06a0(LuaVMState* p) {
    float* a;
    int x;
    a = (float*)FUN_00213260(p, 1);
    FUN_002136d0(p, 1);
    FUN_00212ed0(p, 2);
    FUN_00213600(p, -2);
    x = FUN_00212f00(p, -1);
    if (x != 6) {
        if (FUN_00212f70(p, -1) != 0) {
            x = (int)FUN_002130e0(p, -1);
            FUN_00213340(p, a[x]);
            return 1;
        }
        FUN_002133d0(p, "invalid index");
        FUN_00213c40(p);
        return 0;
    }
    return 1;
}


// 0x001d0730 FUN_001d0730 (128 B): matches/0x001d0730.cpp
// sym: _FUN_001d0730
// FUN_001d0730 @ 0x001d0730
// 0x001d0730: Lua C function: array[(int)arg] = number (arg 3), with a subscript error
extern "C" int FUN_001d0730(LuaVMState* L)
{
    float* array = (float*)FUN_00213260(L, 1);
    FUN_00339d70(L, 3, 3);
    FUN_002136d0(L, 1);
    FUN_00212ed0(L, 2);
    FUN_00213600(L, -2);
    if (FUN_00212f70(L, -1) != 0) {
        int index = (int)FUN_002130e0(L, -1);
        array[index] = FUN_002130e0(L, 3);
        return 0;
    }
    FUN_00213380(L, "invalid subscript in assignment", 0x1f);
    FUN_00213c40(L);
    return 0;
}


// 0x001d07b0 FUN_001d07b0 (179 B): matches/0x001d07b0.cpp
// sym: _FUN_001d07b0
extern "C" int __cdecl FUN_001d07b0(LuaVMState* L) {
    FUN_00212ed0(L, -10001);
    FUN_003390d0(L, 0, (const LuaVMReg*)&DAT_004223c8, 0);
    FUN_00212d80(L, -2);
    FUN_00338eb0(L, DAT_00422404);
    FUN_003390d0(L, 0, (const LuaVMReg*)&DAT_004223d8, 0);
    FUN_00213380(L, DAT_00421bb4, 1);
    FUN_00213340(L, 0.0f);
    FUN_00213800(L, -3);
    FUN_00213380(L, DAT_00421bb0, 1);
    FUN_00213340(L, 1.0f);
    FUN_00213800(L, -3);
    FUN_00213380(L, DAT_00421bac, 1);
    FUN_00213340(L, 2.0f);
    FUN_00213800(L, -3);
    FUN_00212d80(L, -2);
    return 0;
}

} // namespace fn_f55829c3

// 0x001d0870 FUN_001d0870 (66 B): matches/0x001d0870.cpp [wrapped: conflict: FUN_002138e0]
// sym: ?FUN_001d0870@fn_001d0870@@YAHPAULuaVMState@@PAI@Z
namespace fn_001d0870 {
extern "C++" __declspec(nothrow) void* __cdecl FUN_00213d30(LuaVMState*, unsigned int);
extern "C++" __declspec(nothrow) void __cdecl FUN_00338f30(LuaVMState*, const char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_002138e0(LuaVMState*, int);

int __cdecl FUN_001d0870(LuaVMState* L, unsigned int* vec) {
    unsigned int* dst = (unsigned int*)FUN_00213d30(L, 0xc);
    FUN_00338f30(L, "Vector");
    FUN_002138e0(L, -2);
    dst[0] = vec[0];
    dst[1] = vec[1];
    dst[2] = vec[2];
    return 1;
}
} // namespace fn_001d0870

namespace fn_f55829c3 {

// 0x001d0990 FUN_001d0990 (107 B): matches/0x001d0990.cpp
// sym: _FUN_001d0990
// data: g_heap = DAT_004c5cfc
extern "C" void* __cdecl FUN_001d0990(void* ud, void* p, unsigned oldSize, unsigned newSize) {
    if (newSize == 0) {
        if (p)
            FUN_00267090(p);
        return 0;
    }
    void* n = FUN_00266e00(DAT_004c5cfc, (int)newSize);
    if (!n)
        return 0;
    if (p) {
        if (oldSize > newSize)
            oldSize = newSize;
        memcpy(n, p, oldSize);
        FUN_00267090(p);
    }
    return n;
}


// 0x001d0c60 FUN_001d0c60 (141 B): matches/0x001d0c60.cpp
// sym: _FUN_001d0c60
// data: gError = DAT_0042251c, gTostring = DAT_00422548
extern "C" int __cdecl FUN_001d0c60(LuaVMState* state) {
    int count = FUN_00212d70(state);
    FUN_002135a0(state, -10001, DAT_00422548);
    int i = 1;
    if (count >= i) {
        do {
            FUN_00212ed0(state, -1);
            FUN_00212ed0(state, i);
            FUN_002139a0(state, 1, 1);
            const char* ok = FUN_00213190(state, -1);
            if (!ok) {
                FUN_002133d0(state, DAT_0042251c);
                FUN_00213c40(state);
            }
            FUN_00212d80(state, -2);
            ++i;
        } while (i <= count);
    }
    FUN_00212d80(state, -2);
    return 0;
}


// 0x001d0cf0 FUN_001d0cf0 (51 B): matches/0x001d0cf0.cpp
// sym: ?FUN_001d0cf0@fn_f55829c3@@YAHPAULuaVMState@@@Z
int __cdecl FUN_001d0cf0(LuaVMState* param) {
    int i = FUN_00212d70(param);
    if (i < 1)
        return 0;
    Fn_1d0cf0 pc = (Fn_1d0cf0)FUN_00213260(param, -1);
    FUN_00212de0(param, -1);
    return pc(param);
}


// 0x001d0d30 FUN_001d0d30 (81 B): matches/0x001d0d30.cpp
// sym: ?FUN_001d0d30@fn_f55829c3@@YAHPAULuaVMState@@@Z
int __cdecl FUN_001d0d30(LuaVMState* L) {
    if (!FUN_00212fe0(L, -10002))
        return 0;
    Fn_1d0d30 f = (Fn_1d0d30)FUN_00213260(L, -10002);
    if (!FUN_00212fe0(L, -10003))
        return 0;
    return f(L, FUN_00213260(L, -10003));
}


// 0x001d1010 FUN_001d1010 (102 B): matches/0x001d1010.cpp
// sym: ?FUN_001d1010@fn_f55829c3@@YGMPBDPAULuaVMState@@@Z
float __stdcall FUN_001d1010(const char* name, LuaVMState* L) {
    if (name == 0)
        return hulk_at_003f32e0;
    FUN_002135a0(L, -10001, name);
    int r = FUN_00212f00(L, -1);
    if (r != 3) {
        FUN_00212d80(L, -2);
        return hulk_at_003f32e0;
    }
    float x = FUN_002130e0(L, -1);
    FUN_00212d80(L, -2);
    return x;
}


// 0x001d1080 FUN_001d1080 (95 B): matches/0x001d1080.cpp
// sym: ?FUN_001d1080@fn_f55829c3@@YGEPBDPAULuaVMState@@@Z
unsigned char __stdcall FUN_001d1080(const char* p1, LuaVMState* p2) {
    if (p1 == 0)
        return 0;
    FUN_002135a0(p2, (int)0xffffd8ef, p1);
    int r = FUN_00212f00(p2, -1);
    if (r != 1) {
        FUN_00212d80(p2, -2);
        return 0;
    }
    int q = FUN_00213160(p2, -1);
    FUN_00212d80(p2, -2);
    return q != 0;
}


// 0x001d10e0 FUN_001d10e0 (83 B): matches/0x001d10e0.cpp
// sym: ?FUN_001d10e0@fn_f55829c3@@YGPBDPBDPAULuaVMState@@@Z
const char* __stdcall FUN_001d10e0(const char* name, LuaVMState* L) {
    FUN_002135a0(L, 0xffffd8ef, name);
    int i = FUN_00212f00(L, -1);
    if (i != 4) {
        FUN_00212d80(L, -2);
        return 0;
    }
    const char* result = FUN_00213190(L, -1);
    FUN_00212d80(L, -2);
    return result;
}


// 0x001d1140 FUN_001d1140 (5 B): matches/0x001d1140.cpp
// sym: ?FUN_001d1140@fn_f55829c3@@YG_NH@Z
bool __stdcall FUN_001d1140(int a) {
    bool result = false;
    return result;
}


// 0x001d1150 FUN_001d1150 (5 B): matches/0x001d1150.cpp
// sym: ?FUN_001d1150@fn_f55829c3@@YGDH@Z
char __stdcall FUN_001d1150(int x) {
    return false;
}


// 0x001d1160 FUN_001d1160 (17 B): matches/0x001d1160.cpp
// sym: ?target@fn_f55829c3@@YIXPAUScriptHandlerView@@HH@Z
void __fastcall target(ScriptHandlerView* self, int arg, int extra) {
    FUN_00212d80(self->f.L, 0);
}


// 0x001d1180 FUN_001d1180 (149 B): equivalent/0x001d1180.cpp
// sym: ?FUN_001d1180@SortedList@fn_f55829c3@@QAE_NPAUScriptFunctionView@@@Z @c270604b1744 @we17eaab57ff0
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 20/20)
// FUN_001d1180 @ 0x001d1180
// ScriptHandler's function list (include/decls/data/script.h ScriptFunctionList): inserts a Function by its key,
// in order; false when the list is full.
bool SortedList::FUN_001d1180(ScriptFunctionView *e)
{
    const char *name = e->f.key;
    if (count >= 0x400)
        return false;
    int pos = -1;
    if (name != 0 && *name != 0) {
        for (int i = 0; i < count; i++) {
            const char *other = ((ScriptFunctionView *)items[i])->f.key;
            if (other == 0 || *other == 0 || FUN_00096600(other, name) >= 0) {
                pos = i;
                break;
            }
        }
    }
    if (pos < 0)
        pos = count;
    for (int j = count; j > pos; j--)
        items[j] = items[j - 1];
    items[pos] = e;
    count++;
    return true;
}

} // namespace fn_f55829c3

// 0x001d1220 FUN_001d1220 (315 B): equivalent/0x001d1220.cpp [wrapped: macros]
// sym: ?FUN_001d1220@Table_1d1220@fn_001d1220@@QAEPBDPBD0@Z @5515155a7f02 @w9d3352bc2fc4
namespace fn_001d1220 {
// STATUS: equivalent (tools/equiv.py level 3: 994 inputs, branch coverage 34/36, incomplete)
// FUN_001d1220 @ 0x001d1220
// ScriptHandler's function list (include/decls/data/script.h ScriptFunctionList): the next key that starts with
// prefix after previous (completion).
extern "C++" __declspec(nothrow) int __cdecl FUN_00096670(const char*, const char*, unsigned int);
extern "C" int __cdecl FUN_00096600(const char*, const char*);
struct Table_1d1220 : public ScriptFunctionList { const char* FUN_001d1220(const char* prefix, const char* previous); };
#define KEY_1d1220(i) (((ScriptFunctionView*)items[i])->f.key)
const char* Table_1d1220::FUN_001d1220(const char* prefix, const char* previous) {
 if (!prefix || !*prefix || count <= 0) return 0;
 int i = 0;
 for (;;) {
  const char* end = prefix; while (*end) ++end;
  if (FUN_00096670(prefix, KEY_1d1220(i), (unsigned int)(end-prefix)) == 0) break;
  ++i; if (i >= count) return 0;
 }
 if (i < 0) return 0;
 int first = i;
 if (!previous || !*previous) return KEY_1d1220(i);
 const char* end = prefix; while (*end) ++end;
 if (FUN_00096670(prefix, previous, (unsigned int)(end-prefix)) != 0) return KEY_1d1220(i);
 while (i < count) {
  if (FUN_00096600(KEY_1d1220(i), previous) == 0) {
   if (i >= 0 && i != count-1) {
    const char* finish = prefix; while (*finish) ++finish;
    if (FUN_00096670(prefix, KEY_1d1220(i+1), (unsigned int)(finish-prefix)) == 0) return KEY_1d1220(i+1);
   }
   return KEY_1d1220(first);
  }
  ++i;
 }
 return KEY_1d1220(first);
}
} // namespace fn_001d1220
#undef KEY_1d1220

namespace fn_f55829c3 {

// 0x001d1360 FUN_001d1360 (167 B): equivalent/0x001d1360.cpp
// sym: ?FUN_001d1360@ItemList_1d1360@fn_f55829c3@@QAE_NPAUScriptFunctionView@@@Z @416ce1cfa671 @w0ccae33744d3
// STATUS: equivalent (tools/equiv.py level 3: 2891 inputs, branch coverage 20/20)
// FUN_001d1360 @ 0x001d1360
// ScriptHandler's function list (include/decls/data/script.h ScriptFunctionList): deletes the Function whose key is
// the given Function's key and closes the gap.
bool ItemList_1d1360::FUN_001d1360(ScriptFunctionView *key)
{
    const char *want = key->f.key;
    if (want == 0 || *want == 0)
        return false;
    for (int i = 0; i < count; i++) {
        const char *name = ((Item_1d1360 *)items[i])->key;
        if (name != 0 && *name != 0 && FUN_00096600(name, want) == 0) {
            if (items[i] != 0) {
                delete (Item_1d1360 *)items[i];
                items[i] = 0;
            }
            for (int j = i + 1; j < count; j++)
                items[j - 1] = items[j];
            items[count - 1] = 0;
            count--;
            return true;
        }
    }
    return false;
}


// 0x001d1410 FUN_001d1410 (127 B): equivalent/0x001d1410.cpp
// sym: ?Insert@SortedTable@fn_f55829c3@@QAE_NPAUEntry_1d1410@2@@Z @c9a35c7c19db @w739514ce5580
// STATUS: equivalent (tools/equiv.py level 3: 2523 inputs, branch coverage 18/20, incomplete)
// FUN_001d1410 @ 0x001d1410
// 0x001d1410: insert an entry into a sorted pointer table of at most 20 entries
bool SortedTable::Insert(Entry_1d1410* e)
{
    if (count >= 20)
        return false;

    const char* name = e->name;
    int pos = 0;
    bool found = false;
    if (name != 0 && *name != 0) {
        for (int i = 0; i < count; i++) {
            const char* other = items[i]->name;
            if (other == 0 || *other == 0 || FUN_00096600(other, name) >= 0) {
                pos = i;
                found = true;
                break;
            }
        }
    }
    if (!found)
        pos = count;

    for (int i = count; i > pos; i--)
        items[i] = items[i - 1];
    items[pos] = e;
    count = count + 1;
    return true;
}


// 0x001d1490 FUN_001d1490 (309 B): equivalent/0x001d1490.cpp
// sym: ?FUN_001d1490@Table_1d1490@fn_f55829c3@@QAEPADPBD0@Z @15431395952e @wd8400cc37321
// STATUS: equivalent (tools/equiv.py level 3: 921 inputs, branch coverage 34/36, incomplete)
// FUN_001d1490 @ 0x001d1490
char *Table_1d1490::FUN_001d1490(const char *prefix, const char *previous) {
 if (!prefix || !*prefix || count <= 0) return 0;
 int i = 0;
 for (;;) {
  unsigned int length = 0;
  while (prefix[length]) ++length;
  if (FUN_00096670(prefix, entries[i]->text, length) == 0) break;
  ++i;
  if (i >= count) return 0;
 }
 if (i < 0) return 0;
 int first = i;
 if (!previous || !*previous) return entries[i]->text;
 unsigned int length = 0;
 while (prefix[length]) ++length;
 if (FUN_00096670(prefix, previous, length) != 0) return entries[i]->text;
 while (i < count) {
  if (FUN_00096600(entries[i]->text, previous) == 0) {
   if (i < 0 || i == count - 1) return entries[first]->text;
   length = 0;
   while (prefix[length]) ++length;
   if (FUN_00096670(prefix, entries[i+1]->text, length) == 0) return entries[i+1]->text;
   return entries[first]->text;
  }
  ++i;
 }
 return entries[first]->text;
}

} // namespace fn_f55829c3

// 0x001d15d0 FUN_001d15d0 (46 B): matches/0x001d15d0.cpp
// sym: ?FUN_001d15d0@Obj_1d15d0@owners@@QAEXD@Z
// value (include/gen/owners.h Obj_1d15d0 +0x08) is the lua_State, an int member there: cast at the use.
void owners::Obj_1d15d0::FUN_001d15d0(char flag) {
    if (flag)
        FUN_00213ba0((LuaVMState*)(hulk_intptr)value, 2, 0);
    else
        FUN_00213ba0((LuaVMState*)(hulk_intptr)value, 4, 2);
}

namespace fn_f55829c3 {

// 0x001d1630 FUN_001d1630 (63 B): matches/0x001d1630.cpp
// sym: ??0Obj@fn_f55829c3@@QAE@XZ
Obj::Obj() {
    first = 0;
    for (int i = 0; i < 10; ++i) {
        names[i * 64] = 0;
        values[i] = 0;
        flags[i] = 's';
    }
}


// 0x001d16a0 FUN_001d16a0 (109 B): equivalent/0x001d16a0.cpp
// sym: ?FUN_001d16a0@Target_1d16a0@fn_f55829c3@@QAEXPBDM@Z @b1dc57abf6dd @w1c0abf2b2854
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_001d16a0 @ 0x001d16a0
// ScriptHandler (include/decls/data/script.h): adds a watched number (dbg_AddWatch) while there is room and the
// name fits.
void Target_1d16a0::FUN_001d16a0(const char *name, float val)
{
    if (watches.count < 0x100) {
        const char *p = name;
        while (*p != 0)
            p++;
        if (p - name < 0x40) {
            FUN_000964a0(watches.names[watches.count], 0x40, "%s", name);
            watches.values[watches.count] = val;
            watches.count = watches.count + 1;
        }
    }
}


// 0x001d1710 FUN_001d1710 (1 B): matches/0x001d1710.cpp
// sym: ?FUN_001d1710@fn_f55829c3@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001d1710() {}


// 0x001d1740 FUN_001d1740 (140 B): matches/0x001d1740.cpp
// sym: ?FUN_001d1740@ScriptHandler_1d3c90@fn_f55829c3@@QAEXPAULuaVMState@@@Z
void ScriptHandler_1d3c90::FUN_001d1740(LuaVMState* L) {
    FUN_002133d0(L, DAT_004c5cf8);
    FUN_00213680(L, 0, 0);
    FUN_00213800(L, -10000);
    FUN_00212ed0(L, -10000);
    FUN_00213790(L, -10001, "HC_REGISTRY");
    FUN_00213380(L, "context", 7);
    FUN_00213680(L, 0, 0);
    FUN_00213380(L, "event", 5);
    FUN_00213680(L, 0, 0);
    FUN_00213800(L, -3);
    FUN_00213800(L, -10001);
}

} // namespace fn_f55829c3

// 0x001d17f0 FUN_001d17f0 (233 B): equivalent/0x001d17f0.cpp
// sym: ?FUN_001d17f0@Object_1d17f0@owners@@QAEHPAX@Z @0e72e3af33dc @wb784850f7dfc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001d17f0 @ 0x001d17f0
int owners::Object_1d17f0::FUN_001d17f0(void* context) {
if (!FUN_00213290(state, -1)) return 0;
FUN_00213380(context, "coroutine", 9);
FUN_00213600(context, -10001);
FUN_002133d0(context, "status");
FUN_00213600(context, -2);
FUN_00212ed0(context, -3);
FUN_002139f0(context, 1, 1, 0);
const char* text = FUN_00213190(context, -1);
FUN_00212d80(context, -3);
const char* names[3] = {"dead", "running", "suspended"};
const int lengths[3] = {5, 8, 10};
const int results[3] = {3, 1, 2};
for (int n=0; n<3; ++n) {
int i=0;
while (i<lengths[n] && text[i]==names[n][i]) ++i;
if (i==lengths[n]) return results[n];
}
return 0;
}


// 0x001d1900 FUN_001d1900 (37 B): matches/0x001d1900.cpp
// sym: ?FUN_001d1900@Obj_1d1900@owners@@QAE_NH@Z
// field (include/gen/owners.h Obj_1d1900 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::Obj_1d1900::FUN_001d1900(hulk_intptr n) {
    if (((int)n) < 1)
        return false;
    FUN_00339710((LuaVMState*)(hulk_intptr)field, -10000, ((int)n));
    return true;
}


// 0x001d1930 FUN_001d1930 (71 B): matches/0x001d1930.cpp
// sym: ?FUN_001d1930@C_1d1930@owners@@QAE_NH@Z
// m (include/gen/owners.h C_1d1930 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::C_1d1930::FUN_001d1930(int n) {
    if (n >= 1) {
        FUN_00213640((LuaVMState*)(hulk_intptr)m, -10000, n);
        if (FUN_00212f00((LuaVMState*)(hulk_intptr)m, -1) == 0) {
            FUN_00212d80((LuaVMState*)(hulk_intptr)m, -2);
            return false;
        }
        return true;
    }
    return false;
}


// 0x001d1980 FUN_001d1980 (69 B): matches/0x001d1980.cpp
// sym: ?FUN_001d1980@Obj_1d1980@owners@@QAE_NIE@Z
// member (include/gen/owners.h Obj_1d1980 +0x08) is the lua_State, an int member there, and arg (the table's
// name) is a hulk_uintptr there: cast at the use.
bool owners::Obj_1d1980::FUN_001d1980(hulk_uintptr arg, unsigned char flag) {
    int v = -3;
    if (flag)
        v = -10001;
    FUN_002133d0((LuaVMState*)(hulk_intptr)member, (const char*)arg);
    FUN_00213680((LuaVMState*)(hulk_intptr)member, 0, 0);
    FUN_00213800((LuaVMState*)(hulk_intptr)member, v);
    return true;
}


// 0x001d19d0 FUN_001d19d0 (27 B): matches/0x001d19d0.cpp
// sym: ?FUN_001d19d0@Obj_1d19d0@owners@@QAEEI@Z
// value (include/gen/owners.h Obj_1d19d0 +0x08) is the lua_State, an unsigned int member there: cast at the use.
unsigned char owners::Obj_1d19d0::FUN_001d19d0(unsigned int arg) {
    FUN_00212d80((LuaVMState*)(hulk_uintptr)value, (int)(0xffffffffu - arg));
    return 1;
}


// 0x001d19f0 FUN_001d19f0 (81 B): matches/0x001d19f0.cpp
// sym: ?FUN_001d19f0@Obj_1d19f0@owners@@QAE_NHHD@Z
// field (include/gen/owners.h Obj_1d19f0 +0x08) is the lua_State, an int member there, and a (the output
// buffer) is a hulk_intptr there: cast at the use.
bool owners::Obj_1d19f0::FUN_001d19f0(hulk_intptr a, int b, char flag) {
    const char* x = FUN_00213190((LuaVMState*)(hulk_intptr)field, -1);
    bool r = true;
    if (x == 0) {
        r = false;
    } else {
        FUN_00267760((char*)a, b, (const char*)&DAT_003f3f38, x);
    }
    if (flag)
        FUN_00212d80((LuaVMState*)(hulk_intptr)field, -2);
    return r;
}


// 0x001d1a50 FUN_001d1a50 (22 B): matches/0x001d1a50.cpp
// sym: ?FUN_001d1a50@C_1d1a50@owners@@QAE_NI@Z
// member (include/gen/owners.h C_1d1a50 +0x08) is the lua_State, an unsigned int member there: cast at the use.
bool owners::C_1d1a50::FUN_001d1a50(hulk_uintptr arg) {
    FUN_002133d0((LuaVMState*)(hulk_uintptr)member, (const char*)arg);
    return true;
}

namespace fn_f55829c3 {

// 0x001d1a70 FUN_001d1a70 (70 B): matches/0x001d1a70.cpp
// sym: ?FUN_001d1a70@Owner_1d1a70@fn_f55829c3@@QAE_NPAM@Z
bool Owner_1d1a70::FUN_001d1a70(float* out) {
    bool result = true;
    int state = FUN_00212f00(L, -1);
    if (state != 3)
        result = false;
    else
        *out = FUN_002130e0(L, -1);
    FUN_00212d80(L, -2);
    return result;
}

} // namespace fn_f55829c3

// 0x001d1ac0 FUN_001d1ac0 (22 B): matches/0x001d1ac0.cpp
// sym: ?FUN_001d1ac0@C_1d1ac0@owners@@QAE_NI@Z
// Same code shape as 0x001d1a50 (propagated; names are from that function)
// member (include/gen/owners.h C_1d1ac0 +0x08) is the lua_State, an unsigned int member there; arg is the float's
// bits (an unsigned int parameter there): cast at the use.
bool owners::C_1d1ac0::FUN_001d1ac0(u32_1d1ac0 arg) {
    FUN_00213340((LuaVMState*)(hulk_uintptr)member, *(float*)&arg);
    return true;
}


// 0x001d1ae0 FUN_001d1ae0 (144 B): matches/0x001d1ae0.cpp
// sym: ?FUN_001d1ae0@Owner_1d1ae0@owners@@QAEEPAE@Z
// value (include/gen/owners.h Owner_1d1ae0 +0x08) is the lua_State, an int member there: cast at the use.
unsigned char owners::Owner_1d1ae0::FUN_001d1ae0(unsigned char* out) {
    unsigned char result = 1;
    int x = FUN_00212f00((LuaVMState*)(hulk_intptr)value, -1);
    switch (x) {
    case 0:
        *out = 0;
        break;
    case 1:
        *out = FUN_00213160((LuaVMState*)(hulk_intptr)value, -1) != 0;
        break;
    case 3: {
        int b;
        if ((*(float*)&DAT_003f32e0) != FUN_002130e0((LuaVMState*)(hulk_intptr)value, -1))
            b = 1;
        else
            b = 0;
        *out = b;
        break;
    }
    default:
        result = 0;
        break;
    }
    FUN_00212d80((LuaVMState*)(hulk_intptr)value, -2);
    return result;
}

namespace fn_f55829c3 {

// 0x001d1b70 FUN_001d1b70 (78 B): matches/0x001d1b70.cpp
// sym: ?Target@Obj_1d1b70@fn_f55829c3@@QAE_NPAI@Z
bool Obj_1d1b70::Target(U32_1d1b70* out) {
    bool r = true;
    if (FUN_00212f00(L, -1) != 6) {
        r = false;
        FUN_00212d80(L, -2);
    } else {
        *out = ((unsigned int)FUN_00339650(L, -10000));
    }
    return r;
}

} // namespace fn_f55829c3

// 0x001d1bc0 FUN_001d1bc0 (68 B): matches/0x001d1bc0.cpp
// sym: ?FUN_001d1bc0@Obj_1d1bc0@owners@@QAE_NXZ
// value (include/gen/owners.h Obj_1d1bc0 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::Obj_1d1bc0::FUN_001d1bc0() {
    ScriptHandlerFields& h = ((ScriptHandlerView*)this)->f;  // the saved stack tops
    if (h.topIndex < 7 && h.topIndex >= -1) {
        ++h.topIndex;
        h.tops[h.topIndex] = FUN_00212d70((LuaVMState*)(hulk_intptr)value);
        FUN_00213320((LuaVMState*)(hulk_intptr)value);
        return true;
    }
    return false;
}


// 0x001d1c10 FUN_001d1c10 (91 B): matches/0x001d1c10.cpp
// sym: ?FUN_001d1c10@C_1d1c10@owners@@QAE_NH@Z
// obj (include/gen/owners.h C_1d1c10 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::C_1d1c10::FUN_001d1c10(int p) {
    ScriptHandlerFields& h = ((ScriptHandlerView*)this)->f;  // the saved stack tops
    if (h.topIndex < 0)
        return false;
    int n = FUN_00212d70((LuaVMState*)(hulk_intptr)obj);
    int v = h.tops[h.topIndex];
    if (n != v + 1) {
        FUN_00212d80((LuaVMState*)(hulk_intptr)obj, v);
        return false;
    }
    return FUN_00213c50((LuaVMState*)(hulk_intptr)obj, p) != 0;
}

namespace fn_f55829c3 {

// 0x001d1c70 FUN_001d1c70 (63 B): matches/0x001d1c70.cpp
// sym: ?FUN_001d1c70@Obj_1d1c70@fn_f55829c3@@QAEXXZ
void Obj_1d1c70::FUN_001d1c70() {
    if (topIndex >= 0) {
        int v = FUN_00212d70(L);
        int x = tops[topIndex];
        if (v != x)
            FUN_00212d80(L, x);
        --topIndex;
    }
}


// 0x001d1cb0 FUN_001d1cb0 (87 B): matches/0x001d1cb0.cpp
// sym: ?Target@fn_f55829c3@@YI_NPAUScriptHandlerView@@@Z
bool __fastcall Target(ScriptHandlerView* self) {
    int x = FUN_00212d70(self->f.L);
    FUN_00213380(self->f.L, "context", 7);
    FUN_00213600(self->f.L, 0xffffd8ef);
    int r = FUN_00212f00(self->f.L, -1);
    if (r != 5) {
        FUN_00212d80(self->f.L, x);
        return false;
    }
    return true;
}


// 0x001d1d10 FUN_001d1d10 (17 B): matches/0x001d1d10.cpp
// sym: ?FUN_001d1d10@Target_1d1d10@fn_f55829c3@@QAEEXZ
unsigned char Target_1d1d10::FUN_001d1d10() {
    FUN_00212d80(L, -3);
    return 1;
}


// 0x001d1d30 FUN_001d1d30 (17 B): matches/0x001d1d30.cpp
// sym: ?FUN_001d1d30@Target_1d1d30@fn_f55829c3@@QAEEXZ
unsigned char Target_1d1d30::FUN_001d1d30() {
    FUN_00212d80(L, -2);
    return 1;
}

} // namespace fn_f55829c3

// 0x001d1d50 FUN_001d1d50 (51 B): matches/0x001d1d50.cpp
// sym: ?FUN_001d1d50@Thing_1d1d50@owners@@QAE_NII@Z
// m (include/gen/owners.h Thing_1d1d50 +0x08) is the lua_State, a void* there, and a, b (key and value strings)
// are hulk_uintptr there: cast at the use.
bool owners::Thing_1d1d50::FUN_001d1d50(hulk_uintptr a, hulk_uintptr b) {
    FUN_002133d0((LuaVMState*)m, (const char*)a);
    FUN_002133d0((LuaVMState*)m, (const char*)b);
    FUN_00213800((LuaVMState*)m, -3);
    return true;
}


// 0x001d1d90 FUN_001d1d90 (51 B): matches/0x001d1d90.cpp
// sym: ?FUN_001d1d90@Obj_1d1d90@owners@@QAE_NHH@Z
// member (include/gen/owners.h Obj_1d1d90 +0x08) is the lua_State, an int member there; a (the key string) is a
// hulk_intptr and b (the number, a float) an int there: cast at the use.
bool owners::Obj_1d1d90::FUN_001d1d90(hulk_intptr a, int b) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)member, (const char*)a);
    FUN_00213340((LuaVMState*)(hulk_intptr)member, *(float*)&b);
    FUN_00213800((LuaVMState*)(hulk_intptr)member, -3);
    return true;
}


// 0x001d1dd0 FUN_001d1dd0 (56 B): matches/0x001d1dd0.cpp
// sym: ?FUN_001d1dd0@Obj_1d1dd0@owners@@QAE_NHH@Z
// field (include/gen/owners.h Obj_1d1dd0 +0x08) is the lua_State, an int member there, and a (the key string) a
// hulk_intptr there: cast at the use.
bool owners::Obj_1d1dd0::FUN_001d1dd0(hulk_intptr a, int b) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)field, (const char*)a);
    FUN_00213340((LuaVMState*)(hulk_intptr)field, (float)b);
    FUN_00213800((LuaVMState*)(hulk_intptr)field, -3);
    return true;
}


// 0x001d1e10 FUN_001d1e10 (52 B): matches/0x001d1e10.cpp
// sym: ?FUN_001d1e10@Obj_1d1e10@owners@@QAE_NHE@Z
// member (include/gen/owners.h Obj_1d1e10 +0x08) is the lua_State, a void* there, and a (the key string) a
// hulk_intptr there: cast at the use.
bool owners::Obj_1d1e10::FUN_001d1e10(hulk_intptr a, unsigned char b) {
    FUN_002133d0((LuaVMState*)member, (const char*)a);
    FUN_00213520((LuaVMState*)member, b);
    FUN_00213800((LuaVMState*)member, -3);
    return true;
}

namespace fn_f55829c3 {

// 0x001d1e50 FUN_001d1e50 (51 B): matches/0x001d1e50.cpp
// sym: ?FUN_001d1e50@Obj_1d1e50@fn_f55829c3@@QAE_NPBDUVec3_1d1e50@2@@Z
// b: a vector passed by value (FUN_001d0870 copies its three words).
bool Obj_1d1e50::FUN_001d1e50(const char* a, Vec3_1d1e50 b) {
    FUN_002133d0(L, a);
    FUN_001d0870(L, (unsigned int*)&b);
    FUN_00213800(L, -3);
    return true;
}

} // namespace fn_f55829c3

// 0x001d1f30 FUN_001d1f30 (40 B): matches/0x001d1f30.cpp
// sym: ?FUN_001d1f30@C_1d1f30@owners@@QAEXIII@Z
void owners::C_1d1f30::FUN_001d1f30(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int* q = p;
    if ((unsigned int)((char*)q - (char*)this + 8) < 0x40) {
        q[0] = a;
        q[1] = b;
        q[2] = c;
        p = (unsigned int*)((char*)p + 12);
    }
}

namespace fn_f55829c3 {

// 0x001d2000 FUN_001d2000 (19 B): matches/0x001d2000.cpp
// sym: ?target@fn_f55829c3@@YAHPBD@Z
int __cdecl target(const char* s) {
    return check(s, "/lua");
}


// 0x001d2110 FUN_001d2110 (115 B): matches/0x001d2110.cpp
// sym: ?f@A_1d2110@fn_f55829c3@@QAEXPAUArg_1d2110@2@@Z
void A_1d2110::f(Arg_1d2110* arg) {
    FUN_00213550(L, arg->x);
    if (arg->flag) {
        FUN_00213550(L, arg->value);
        FUN_002134a0(L, &FUN_001d0d30, 2);
    } else {
        FUN_002134a0(L, &FUN_001d0cf0, 1);
    }
    FUN_00213790(L, 0xffffd8ef, arg->name);
}


// 0x001d2190 FUN_001d2190 (260 B): equivalent/0x001d2190.cpp
// sym: ?FUN_001d2190@ScriptRunner@fn_f55829c3@@QAEHPBDUScriptCallArgs@@PAULuaVMState@@@Z @a53f8b22c72d @w75d4e71eaca8
// STATUS: equivalent (tools/equiv.py level 3: 3046 inputs, branch coverage 20/20)
// FUN_001d2190 @ 0x001d2190
// Calls a global Lua function with the 's' / 'f' / 'b' / 'i' typed arguments of `call` on the state L.
// Returns the new status: 0 when the function is missing or an argument type is unknown, 3 on
// a Lua error, 0 on success.
int ScriptRunner::FUN_001d2190(const char *name, ScriptCallArgs call, LuaVMState *L)
{
    FUN_002133d0(L, name);
    FUN_00213570(L, -10001);
    bool found = FUN_00212f00(L, -1) != 0;
    FUN_00212d80(L, -2);
    if (!found)
        return 0;
    FUN_002135a0(L, -10001, name);
    if (FUN_00212f00(L, -1) != 6) {
        FUN_00212d80(L, -2);
        return 0;
    }
    for (int i = 0; i < call.count; i++) {
        char type = call.types[i];
        if (type == 's') {
            FUN_002133d0(L, call.strings[i]);
        } else if (type == 'f' || type == 'b' || type == 'i') {
            FUN_00213340(L, call.numbers[i]);
        } else {
            FUN_00212d80(L, -2 - i);
            status = 0;
            return status;
        }
    }
    status = FUN_002139f0(L, call.count, 0, 0) == 0 ? 3 : 0;
    return status;
}


// 0x001d26d0 FUN_001d26d0 (34 B): matches/0x001d26d0.cpp
// sym: ?g@C_1d26d0@fn_f55829c3@@QAEXIPAVB_1d26d0@2@@Z
// ScriptHandler (include/decls/data/script.h): removes the Function registered under `name` (0x001d04b0 sets b's key,
// 0x001d1360 deletes the matching entry of the function list).
void C_1d26d0::g(hulk_uintptr a, B_1d26d0* b) {
    ((owners::CAgent_1d04b0 *)b)->FUN_001d04b0((hulk_intptr)a);
    ((D*)&functions)->FUN_001d1360(b);
}


// 0x001d2700 FUN_001d2700 (28 B): matches/0x001d2700.cpp
// sym: ?FUN_001d2700@Obj_1d2700@fn_f55829c3@@QAEXXZ
void Obj_1d2700::FUN_001d2700() {
    if (L) {
        FUN_002151e0(L);
        L = 0;
    }
}


// 0x001d2760 FUN_001d2760 (45 B): matches/0x001d2760.cpp
// sym: ?FUN_001d2760@Object_1d2760@fn_f55829c3@@QAEXXZ
void Object_1d2760::FUN_001d2760() {
    if (ownsState) {
        if (L) {
            FUN_002151e0(L);
            L = 0;
        }
        ownsState = 0;
    }
}

} // namespace fn_f55829c3

// 0x001d2790 FUN_001d2790 (17 B): matches/0x001d2790.cpp [wrapped: macros]
// sym: ?run@ScriptHandler_1d2790@fn_001d2790@@QAEMPBD@Z
namespace fn_001d2790 {
// sh_GetNumber: the Lua global `name` as a number (0x001d1010 on the handler's state). The caller keeps ecx: the
// game declared 0x001d1010 a member that does not use `this`; its source defines it as a __stdcall function, which
// the 64-bit build calls (a member call would pass `this` in the first argument register).
#if defined(HULK_PTR64)
float __stdcall FUN_001d1010(const char* name, LuaVMState* L);
#endif
class ScriptHandler_1d2790 : public ScriptHandlerFields {
  public:
    virtual void v0();
#if !defined(HULK_PTR64)
    float FUN_001d1010(const char* name, LuaVMState* L);
#endif
    hulk_freg run(const char* name);
};
hulk_freg ScriptHandler_1d2790::run(const char* name) {
    return FUN_001d1010(name, L);
}
} // namespace fn_001d2790


// 0x001d27b0 FUN_001d27b0 (17 B): matches/0x001d27b0.cpp [wrapped: macros]
// sym: ?Fn@ScriptHandler_1d27b0@fn_001d27b0@@QAEPBDPBD@Z
namespace fn_001d27b0 {
// sh_GetString: the Lua global `name` as a string (0x001d10e0 on the handler's state). The caller keeps ecx: the
// game declared 0x001d10e0 a member that does not use `this`; its source defines it as a __stdcall function, which
// the 64-bit build calls (a member call would pass `this` in the first argument register).
#if defined(HULK_PTR64)
const char* __stdcall FUN_001d10e0(const char* name, LuaVMState* L);
#endif
struct ScriptHandler_1d27b0 : public ScriptHandlerFields {
    virtual void v0();
#if !defined(HULK_PTR64)
    const char* FUN_001d10e0(const char* name, LuaVMState* L);
#endif
    const char* Fn(const char* name);
};
const char* ScriptHandler_1d27b0::Fn(const char* name) {
    return FUN_001d10e0(name, L);
}
} // namespace fn_001d27b0

namespace fn_f55829c3 {

// 0x001d27d0 FUN_001d27d0 (53 B): matches/0x001d27d0.cpp
// sym: ??0Table@fn_f55829c3@@QAE@XZ
// ScriptHandler's watch list (include/decls/data/script.h ScriptWatchList): empty, every name "0", every value 0.
Table::Table() {
    count = 0;
    for (int i = 0; i < 256; i++) {
        names[i][0] = '0';
        *(int*)&values[i] = 0;
    }
}

} // namespace fn_f55829c3

// 0x001d2810 FUN_001d2810 (118 B): equivalent/0x001d2810.cpp [wrapped: conflict: ScriptHandler]
// sym: ?FUN_001d2810@ScriptHandler@fn_001d2810@@QAEHPAULuaVMState@@PBDH1@Z @9bc5171b7339 @w21d8502cf883
namespace fn_001d2810 {
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 10/10)
// FUN_001d2810 @ 0x001d2810

extern "C++" __declspec(nothrow) int __cdecl FUN_00212d70(LuaVMState *L);
extern "C" int __cdecl FUN_00339a60(LuaVMState *L, const char *buf, unsigned int len, const char *name);
extern "C++" __declspec(nothrow) int __cdecl FUN_002139f0(LuaVMState *L, int nargs, int nresults, int errfunc);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212d80(LuaVMState *L, int top);

class ScriptHandler : public ScriptHandlerFields {
public:
    virtual void v0();
    int FUN_001d2810(LuaVMState *L, const char *buf, int len, const char *name);
};

int ScriptHandler::FUN_001d2810(LuaVMState *L, const char *buf, int len, const char *name)
{
    int top = FUN_00212d70(this->L);  // the handler's state (the chunk runs on the given one)
    if (len == -1) {
        const char *e = buf;
        while (*e != 0)
            e++;
        len = (int)(e - buf);
    }
    if (name == 0)
        name = "=ScriptHandler::DoLuaBuffer";
    int r = FUN_00339a60(L, buf, len, name);
    if (r != 0 || (r = FUN_002139f0(L, 0, -1, 0)) != 0)
        FUN_00212d80(L, top);
    return r;
}
} // namespace fn_001d2810


// 0x001d29b0 FUN_001d29b0 (345 B): matches/0x001d29b0.cpp
// sym: ?FUN_001d29b0@Runner_1d29b0@owners@@QAEDHPAD@Z
// FUN_001d29b0 @ 0x001d29b0
// handle (include/gen/owners.h Runner_1d29b0 +0x08) is the lua_State, an int member there, and the gen
// declaration of FUN_001d17f0 takes it as an int: cast at the use.
char owners::Runner_1d29b0::FUN_001d29b0(hulk_intptr arg, char *failed)
{
    if (((int)arg) == 0) {
        *failed = 1;
        return 0;
    }
    FUN_002133d0((LuaVMState*)(hulk_intptr)handle, DAT_004c5cf8);
    FUN_00213600((LuaVMState*)(hulk_intptr)handle, -10000);
    FUN_00213640((LuaVMState*)(hulk_intptr)handle, -1, ((int)arg));
    LuaVMState* r = FUN_00213290((LuaVMState*)(hulk_intptr)handle, -1);
    if (r == 0) {
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
        *failed = 1;
        return 0;
    }
    if (FUN_001d17f0(handle) != 2) {
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
        *failed = 1;
        return 0;
    }
    FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
    if (FUN_00215d10(r, 0) != 0) {
        *failed = 1;
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, 0);
        return 0;
    }
    FUN_002133d0((LuaVMState*)(hulk_intptr)handle, DAT_004c5cf8);
    FUN_00213600((LuaVMState*)(hulk_intptr)handle, -10000);
    FUN_00213640((LuaVMState*)(hulk_intptr)handle, -1, ((int)arg));
    if (FUN_001d17f0(handle) == 3) {
        FUN_002133d0((LuaVMState*)(hulk_intptr)handle, DAT_004c5cf8);
        FUN_00213600((LuaVMState*)(hulk_intptr)handle, -10000);
        FUN_00213320((LuaVMState*)(hulk_intptr)handle);
        FUN_00213870((LuaVMState*)(hulk_intptr)handle, -2, ((int)arg));
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -4);
        return 0;
    }
    FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
    return 1;
}


// 0x001d2b10 FUN_001d2b10 (137 B): matches/0x001d2b10.cpp
// sym: ?FUN_001d2b10@Obj_1d2b10@owners@@QAEHHH@Z
// data (include/gen/owners.h Obj_1d2b10 +0x08) is the lua_State, a void* there: cast at the use.
int owners::Obj_1d2b10::FUN_001d2b10(int start, int end) {
    int len = FUN_00212d70((LuaVMState*)data);
    if (len == 0)
        return -1;
    if (start != 0) {
        int absStart = start;
        if (start < 0)
            absStart = -start;
        if (absStart <= len) {
            if (FUN_00212f00((LuaVMState*)data, start) == 6) {
                if (end == -1) {
                    if (start > 0)
                        end = len - start;
                    else
                        end = len + start;
                }
                LuaVMState* d = (LuaVMState*)data;
                if (FUN_002139f0(d, end, -1, 0) == 0)
                    return FUN_00212d70((LuaVMState*)data);
            }
        }
    }
    return -1;
}

namespace fn_f55829c3 {

// 0x001d2ba0 FUN_001d2ba0 (185 B): equivalent/0x001d2ba0.cpp
// sym: ?target@Object@fn_f55829c3@@QAE_NPBDH_N@Z @237ef19cb865 @w05d882c79acc
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_001d2ba0 @ 0x001d2ba0
bool Object::target(const char* key, int mode, bool retry) {
 int index = (unsigned char)mode ? -10001 : -2;
 int saved = FUN_00212d70(L);
 FUN_002133d0(L, key);
 FUN_00213600(L, index);
 if (FUN_00212f00(L, -1) == 5) return true;
 if (retry) {
  FUN_00212d80(L, -2);
  FUN_001d1980(key, mode);
  FUN_002133d0(L, key);
  FUN_00213600(L, index);
  if (FUN_00212f00(L, -1) == 5) return true;
 }
 FUN_00212d80(L, saved);
 return false;
}

} // namespace fn_f55829c3

// 0x001d2c60 FUN_001d2c60 (98 B): matches/0x001d2c60.cpp
// sym: ?FUN_001d2c60@K_1d2c60@owners@@QAE_NHHH@Z
// state (include/gen/owners.h K_1d2c60 +0x08) is the lua_State, an int member there; a (the key string) and b
// (the output buffer) are hulk_intptr there: cast at the use.
bool owners::K_1d2c60::FUN_001d2c60(hulk_intptr a, hulk_intptr b, int c) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)state, (const char*)a);
    FUN_00213600((LuaVMState*)(hulk_intptr)state, -2);
    const char* v = FUN_00213190((LuaVMState*)(hulk_intptr)state, -1);
    bool r = true;
    if (v == 0)
        r = false;
    else
        FUN_00267760((char*)b, c, "%s", v);
    FUN_00212d80((LuaVMState*)(hulk_intptr)state, -2);
    return r;
}


// 0x001d2cd0 FUN_001d2cd0 (98 B): matches/0x001d2cd0.cpp
// sym: ?FUN_001d2cd0@C_1d2cd0@owners@@QAE_NHHH@Z
// field (include/gen/owners.h C_1d2cd0 +0x08) is the lua_State, an int member there; b (the buffer) a hulk_intptr
// parameter there: cast at the use.
bool owners::C_1d2cd0::FUN_001d2cd0(int a, hulk_intptr b, int c) {
    FUN_00213360((LuaVMState*)(hulk_intptr)field, a);
    FUN_00213600((LuaVMState*)(hulk_intptr)field, -2);
    const char* r = FUN_00213190((LuaVMState*)(hulk_intptr)field, -1);
    bool ok = true;
    if (!r)
        ok = false;
    else
        F4_00267760((char*)b, c, (const char*)&DAT_003f3f38, r);
    FUN_00212d80((LuaVMState*)(hulk_intptr)field, -2);
    return ok;
}


// 0x001d2d40 FUN_001d2d40 (95 B): matches/0x001d2d40.cpp
// sym: ?FUN_001d2d40@Obj_1d2d40@owners@@QAE_NHPAM@Z
// field (include/gen/owners.h Obj_1d2d40 +0x08) is the lua_State, an int member there, and arg (the key string)
// a hulk_intptr there: cast at the use.
bool owners::Obj_1d2d40::FUN_001d2d40(hulk_intptr arg, float* out) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)field, (const char*)arg);
    FUN_00213600((LuaVMState*)(hulk_intptr)field, -2);
    bool result = true;
    if (FUN_00212f00((LuaVMState*)(hulk_intptr)field, -1) != 3)
        result = false;
    if (result)
        *out = FUN_002130e0((LuaVMState*)(hulk_intptr)field, -1);
    FUN_00212d80((LuaVMState*)(hulk_intptr)field, -2);
    return result;
}


// 0x001d2da0 FUN_001d2da0 (49 B): matches/0x001d2da0.cpp
// sym: ?FUN_001d2da0@Converter_1d2da0@owners@@QAEEIPAH@Z
unsigned char owners::Converter_1d2da0::FUN_001d2da0(hulk_uintptr value, int* result) {
    float number;
    unsigned char ok = FUN_001d2d40(((unsigned int)value), &number);
    if (ok)
        *result = (int)(__int64)(number + 0.5f);
    return ok;
}


// 0x001d2de0 FUN_001d2de0 (47 B): matches/0x001d2de0.cpp
// sym: ?FUN_001d2de0@C_1d2de0@owners@@QAEHHH@Z
// member (include/gen/owners.h C_1d2de0 +0x08) is the lua_State, an int member there: cast at the use.
int owners::C_1d2de0::FUN_001d2de0(hulk_intptr a, hulk_intptr b) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)member, (const char*)a);
    FUN_00213600((LuaVMState*)(hulk_intptr)member, -2);
    return finish(((int)b));
}


// 0x001d2e10 FUN_001d2e10 (103 B): matches/0x001d2e10.cpp
// sym: ?FUN_001d2e10@C_1d2e10@owners@@QAE_NHPAH@Z
// L (include/gen/owners.h C_1d2e10 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::C_1d2e10::FUN_001d2e10(hulk_intptr a, int* out) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)L, (const char*)a);
    FUN_00213600((LuaVMState*)(hulk_intptr)L, -2);
    bool r = true;
    if (FUN_00212f00((LuaVMState*)(hulk_intptr)L, -1) != 6) {
        r = false;
        FUN_00212d80((LuaVMState*)(hulk_intptr)L, -2);
    } else {
        *out = FUN_00339650((LuaVMState*)(hulk_intptr)L, -10000);
    }
    return r;
}


// 0x001d2e80 FUN_001d2e80 (94 B): matches/0x001d2e80.cpp
// sym: ?FUN_001d2e80@Obj_1d2e80@owners@@QAE_NXZ
// m is a void* member of include/gen/owners.h Obj_1d2e80: cast at the use.
bool owners::Obj_1d2e80::FUN_001d2e80() {
    int v = FUN_00212d70((LuaVMState*)m);
    F1d1cb0();
    FUN_00213380((LuaVMState*)m, DAT_003f8eb0, 5);
    FUN_00213600((LuaVMState*)m, -2);
    int r = FUN_00212f00((LuaVMState*)m, -1);
    if (r != 5) {
        FUN_00212d80((LuaVMState*)m, v);
        return false;
    }
    return true;
}

namespace fn_f55829c3 {

// 0x001d3030 FUN_001d3030 (124 B): matches/0x001d3030.cpp
// sym: ?Run@Obj_1d3030@fn_f55829c3@@QAEPBDPBD0@Z
const char* Obj_1d3030::Run(const char* a, const char* b) {
    const char* result = 0;
    if (Check_001d2ba0(DAT_003f6378, 1, 1)) {
        if (Check_001d2ba0(a, 0, 1)) {
            if (Check_001d2ba0(DAT_00422618, 0, 1)) {
                FUN_002133d0(L, b);
                FUN_00213600(L, -2);
                result = FUN_00213190(L, -1);
            }
        }
    }
    FUN_00212d80(L, 0);
    return result;
}

} // namespace fn_f55829c3

// 0x001d3100 Method2<ScriptHandler,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001d3100.cpp
// sym: ??_G?$Method2@VScriptHandler@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<ScriptHandler, void, const char *, const char *>::~Method2() {}


// 0x001d3120 Method2<ScriptHandler,void,const_char_*,const_char_*>::vfunc_2 (23 B): matches/0x001d3120.cpp
// sym: ?vfunc_2@?$Method2@VScriptHandler@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<ScriptHandler, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_1d3120* m = (CFEManager_1d3120*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_1d3120::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<ScriptHandler, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d3100)
#endif


// 0x001d3180 Method1<ScriptHandler,float,const_char_*>::vfunc_0 (30 B): matches/0x001d3180.cpp
// sym: ??_G?$Method1@VScriptHandler@@MPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<ScriptHandler, float, const char *>::~Method1() {}


// 0x001d31a0 Method1<ScriptHandler,float,const_char_*>::vfunc_2 (42 B): matches/0x001d31a0.cpp
// sym: ?vfunc_2@?$Method1@VScriptHandler@@MPBD@@UAEXPAX00@Z
// Same code shape as 0x0002c760 (propagated; names are from that function)
template <> void Method1<ScriptHandler, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1d31a0 * a = (CActorManager_1d31a0 *)__p0; const char ** p = (const char **)__p1; float * out = (float *)__p2;

    Fn_1d31a0 f = (*(Fn_1d31a0 *)&this->f_1c);
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
#if defined(HULK_PTR64)
template class Method1<ScriptHandler, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d3180)
#endif


// 0x001d3210 Method1<ScriptHandler,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001d3210.cpp
// sym: ??_G?$Method1@VScriptHandler@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<ScriptHandler, const char *, const char *>::~Method1() {}


// 0x001d3230 Method1<ScriptHandler,const_char_*,const_char_*>::vfunc_2 (29 B): matches/0x001d3230.cpp
// sym: ?vfunc_2@?$Method1@VScriptHandler@@PBDPBD@@UAEXPAX00@Z
template <> void Method1<ScriptHandler, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { ScriptHandler_1d3230 * obj = (ScriptHandler_1d3230 *)__p0; const char ** arg = (const char **)__p1; int * out = (int *)__p2;

    int (ScriptHandler_1d3230::*fn)(const char*) = (*(int (ScriptHandler_1d3230::**)(const char *))&this->f_1c);
    const char* v = *arg;
    int result = (obj->*fn)(v);
    if (out)
        *out = result;
}
#if defined(HULK_PTR64)
template class Method1<ScriptHandler, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d3210)
#endif

namespace fn_f55829c3 {

// 0x001d3250 FUN_001d3250 (102 B): matches/0x001d3250.cpp
// sym: ?FUN_001d3250@Method4_1d3250@fn_f55829c3@@QAEPAV12@PBDP8ScriptHandler_1d3250@2@AEX0000@Z@Z
// data: text0f0 = DAT_0048e0f0, text100 = DAT_0048e100
Method4_1d3250* Method4_1d3250::FUN_001d3250(const char* a, Fn_1d3250 b) {
    FUN_001d0480(a, 4);
    vft = (void*)DAT_00422654;
    fn = b;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    f.argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    return this;
}

} // namespace fn_f55829c3

// 0x001d32c0 Method4<ScriptHandler,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001d32c0.cpp
// sym: ??_G?$Method4@VScriptHandler@@XPBDPBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<ScriptHandler, void, const char *, const char *, const char *, const char *>::~Method4() {}


// 0x001d32e0 Method4<ScriptHandler,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (40 B): equivalent/0x001d32e0.cpp
// sym: ?vfunc_2@?$Method4@VScriptHandler@@XPBDPBDPBDPBD@@UAEXPAX00@Z @06f2e20faa8a @we84ffb84b326
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<ScriptHandler,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x001d32e0
template <> void Method4<ScriptHandler, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { ScriptHandler_1d32e0 * handler = (ScriptHandler_1d32e0 *)__p0; const char ** args = (const char **)__p1; void * unused = (void *)__p2;
 (handler->*(*(HandlerMethod *)&this->f_1c))(args[0], args[1], args[2], args[3]); }
#if defined(HULK_PTR64)
template class Method4<ScriptHandler, void, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d32c0)
#endif


// 0x001d3350 Method1<ScriptHandler,ScriptHandler::script_state,const_char_*>::vfunc_0 (30 B): matches/0x001d3350.cpp
// sym: ??_G?$Method1@VScriptHandler@@W4script_state@1@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<ScriptHandler,ScriptHandler::script_state, const char *>::~Method1() {}


// 0x001d3370 Method1<ScriptHandler,ScriptHandler::script_state,const_char_*>::vfunc_2 (29 B): matches/0x001d3370.cpp
// sym: ?vfunc_2@?$Method1@VScriptHandler@@PBDPBD@@UAEXPAX00@Z
template <> void Method1<ScriptHandler,ScriptHandler::script_state, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { ScriptHandler_1d3370 * a = (ScriptHandler_1d3370 *)__p0; const char ** p = (const char **)__p1; ScriptHandler_1d3370::script_state * out = (ScriptHandler_1d3370::script_state *)__p2;

    Fn_1d3370 f = (*(Fn_1d3370 *)&this->f_1c);
    const char* s = *p;
    ScriptHandler_1d3370::script_state x = (a->*f)(s);
    if (out)
        *out = x;
}
#if defined(HULK_PTR64)
template class Method1<ScriptHandler,ScriptHandler::script_state, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d3350)
#endif


// 0x001d33d0 Method1<ScriptHandler,bool,const_char_*>::vfunc_0 (30 B): matches/0x001d33d0.cpp
// sym: ??_G?$Method1@VScriptHandler@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<ScriptHandler, bool, const char *>::~Method1() {}
#if defined(HULK_PTR64)
template class Method1<ScriptHandler, bool, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d33d0)
#endif


// 0x001d33f0 Method1<ScriptHandler,bool,const_char_*>::vfunc_2 (29 B): matches/0x001d33f0.cpp [wrapped: conflict: Function; Method1; ScriptHandler]
// sym: ?f2@Method1@fn_001d33f0@@UAEXPAVScriptHandler@2@PAPBDPA_N@Z
namespace fn_001d33f0 {
class ScriptHandler {
  public:
    bool Do(const char*);
};
class Function : public ScriptFunctionFields {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(ScriptHandler*, const char**, bool*);
};
class Method1 : public Function {
  public:
    typedef bool (ScriptHandler::*Fn)(const char*);
    Fn fn;
    virtual void f2(ScriptHandler*, const char**, bool*);
};
inline bool invoke(ScriptHandler* obj, Method1::Fn fun, const char* arg) {
    return (obj->*fun)(arg);
}
void Method1::f2(ScriptHandler* a, const char** b, bool* c) {
    Fn fun = fn;
    bool r = invoke(a, fun, *b);
    if (c)
        *c = r;
}
} // namespace fn_001d33f0


// 0x001d3410 FUN_001d3410 (89 B): matches/0x001d3410.cpp [wrapped: conflict: ScriptHandler]
// sym: ??1ScriptHandler@fn_001d3410@@QAE@XZ
namespace fn_001d3410 {
extern "C" void _ReadWriteBarrier();
extern "C++" __declspec(nothrow) void __cdecl FUN_002151e0(LuaVMState* L);
extern void* hulk_at_00422684;
class Item_1d3410 {
  public:
    virtual void Release(int);
};
// ScriptHandler's destructor (include/decls/data/script.h ScriptHandlerFields): closes the Lua state and releases
// every registered Function.
class ScriptHandler : public ScriptHandlerView {
  public:
    ~ScriptHandler();
};
ScriptHandler::~ScriptHandler() {
    vftable = &hulk_at_00422684;
    _ReadWriteBarrier();
    if (f.L) {
        FUN_002151e0(f.L);
        f.L = 0;
    }
    for (int i = 0; i < f.functions.count; ++i) {
        Item_1d3410* p = (Item_1d3410*)f.functions.items[i];
        if (p)
            p->Release(1);
    }
    f.functions.count = 0;
}
} // namespace fn_001d3410


// 0x001d3600 FUN_001d3600 (219 B): equivalent/0x001d3600.cpp
// sym: ?FUN_001d3600@Object_1d3600@owners@@QAEHPBDI@Z @e538d7d60991 @w07b790a5de7c
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001d3600 @ 0x001d3600
int owners::Object_1d3600::FUN_001d3600(const char* name, unsigned int unused) {
 const char* savedName = name;
 Stream* stream;
 thunk_FUN_002710d0(&stream, savedName,0,0,1,0,1,1);
 stream->reset();
 if (!stream->valid()) { stream->release(); return 0; }
 unsigned int length = stream->size();
 if (!length) { stream->release(); return status; }
 char* buffer = FUN_0008d6d0(length + 1);
 stream->read(buffer,length,1);
 stream->reset();
 buffer[length] = 0;
 stream->release();
 int result = FUN_001d2810(context,buffer,length,savedName);
 status = result ? 0 : 3;
 FUN_0008d340(buffer);
 return status;
}


// 0x001d36e0 FUN_001d36e0 (15 B): matches/0x001d36e0.cpp
// sym: ?FUN_001d36e0@ScriptHandler@@QAEXH@Z
void ScriptHandler::FUN_001d36e0(int a) {
    ((owners::Object_1d3600 *)(((ScriptHandler_nv_1d36e0*)(this))))->FUN_001d3600((const char *)(hulk_uintptr)(int)a, 0);
}


// 0x001d3b00 FUN_001d3b00 (47 B): matches/0x001d3b00.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_001d3b00@@QAEHPBDUScriptCallArgs@@@Z
namespace fn_001d3b00 {
// ScriptHandler (include/decls/data/script.h): calls the global Lua function `name` with `args` on the handler's
// state (0x001d2190).
class Obj : public ScriptHandlerFields {
  public:
    virtual void v0();
    int FUN_001d2190(const char* name, ScriptCallArgs args, LuaVMState* state);
    int Fn(const char* name, ScriptCallArgs args);
};
int Obj::Fn(const char* name, ScriptCallArgs args) {
    return FUN_001d2190(name, args, L);
}
} // namespace fn_001d3b00


// 0x001d3b70 FUN_001d3b70 (74 B): matches/0x001d3b70.cpp
// sym: ?FUN_001d3b70@Obj_1d3b70@owners@@QAEXIH@Z
// field8 (include/gen/owners.h Obj_1d3b70 +0x08) is the lua_State, a void* there; a (the function's name) is a
// hulk_uintptr and b (the closure object) a hulk_intptr there: cast at the use.
void owners::Obj_1d3b70::FUN_001d3b70(hulk_uintptr a, hulk_intptr b) {
    ((owners::CAgent_1d04b0*)b)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&((ScriptHandlerView*)this)->f.functions)->FUN_001d1180((ScriptFunctionView*)b);
    LuaVMState* x = (LuaVMState*)field8;
    FUN_00213550(x, (void*)b);
    FUN_002134a0(x, FUN_001d22a0, 1);
    FUN_00213790(x, -10001, (const char*)a);
}

namespace fn_f55829c3 {

// 0x001d3bc0 FUN_001d3bc0 (141 B): matches/0x001d3bc0.cpp
// sym: ?FUN_001d3bc0@ScriptRegistry@fn_f55829c3@@QAEXXZ
// FUN_001d3bc0 @ 0x001d3bc0
// Register every script-visible object as a Lua global, then refresh the second list.
void ScriptRegistry::FUN_001d3bc0()
{
    for (int i = 0; i < functions.count; i++) {
        ScriptFunctionView* object = (ScriptFunctionView*)functions.items[i];
        LuaVMState* state = L;
        const char* name = object->f.key;
        FUN_00213550(state, object);
        FUN_002134a0(state, FUN_001d22a0, 1);
        FUN_00213790(state, -10001, name);
    }
    for (int i = 0; i < refreshCount; i++) {
        FUN_001d2110((ScriptRefresh_1d3bc0*)refreshList[i]);
    }
}

} // namespace fn_f55829c3

// 0x001d3c50 FUN_001d3c50 (59 B): matches/0x001d3c50.cpp
// sym: ?FUN_001d3c50@Thing_1d3c50@owners@@QAEXXZ
void owners::Thing_1d3c50::FUN_001d3c50() {
    Load("init.lua", 0);
    Load("scripts/physics.lua", 0);
    Load("scripts/damage.lua", 0);
    Load("scripts/config.lua", 0);
}


// 0x001d3c90 FUN_001d3c90 (265 B): matches/0x001d3c90.cpp [wrapped: conflict: ScriptHandler_1d3c90]
// sym: ?FUN_001d3c90@ScriptHandler_1d3c90@fn_001d3c90@@QAEHPAPAULuaVMState@@@Z
namespace fn_001d3c90 {
// the Lua state's allocator (0x001d0990: unused context, block, old size, new size)
extern "C++" __declspec(nothrow) void* __cdecl FUN_001d0990(void*, void*, unsigned int, unsigned int);
extern int __cdecl FUN_001d2000(LuaVMState*);
extern "C" int __cdecl FUN_001d2020(LuaVMState*);
extern "C++" __declspec(nothrow) void __cdecl FUN_002151e0(LuaVMState*);
extern "C" LuaVMState* __cdecl FUN_002150e0(LuaVMAlloc, void*);
extern "C" void __cdecl FUN_0033eb30(LuaVMState*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" void __cdecl FUN_0033d6c0(LuaVMState*);
extern "C" void __cdecl FUN_0033bca0(LuaVMState*);
extern "C" void __cdecl FUN_0033b560(LuaVMState*);
extern "C" void __cdecl FUN_0033ac90(LuaVMState*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C++" __declspec(nothrow) void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C++" __declspec(nothrow) int __cdecl FUN_001d07b0(LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_002134a0(LuaVMState*, LuaVMCFunction, int);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213790(LuaVMState*, int, const char*);
struct ScriptHandler_1d3c90 {
#if defined(HULK_PTR64)
    void FUN_001d1740(LuaVMState*);  // (the definition's type: it returns nothing)
#else
    int FUN_001d1740(LuaVMState*);   // (the original returns what 0x001d1740 left in eax)
#endif
    int FUN_001d3c90(LuaVMState**);
};
int ScriptHandler_1d3c90::FUN_001d3c90(LuaVMState** state) {
    if (*state) {
        FUN_002151e0(*state);
        *state = 0;
    }
    *state = FUN_002150e0(FUN_001d0990, 0);
    FUN_0033eb30(*state);
    FUN_00212d80(*state, 0);
    FUN_0033d6c0(*state);
    FUN_00212d80(*state, 0);
    FUN_0033bca0(*state);
    FUN_00212d80(*state, 0);
    FUN_0033b560(*state);
    FUN_00212d80(*state, 0);
    FUN_0033ac90(*state);
    FUN_00212d80(*state, 0);
    FUN_00212ed0(*state, -10001);
    FUN_003390d0(*state, 0, (const LuaVMReg*)DAT_00422458, 0);
    FUN_00212d80(*state, -2);
    FUN_001d07b0(*state);
    LuaVMState* saved = *state;
    FUN_002134a0(saved, FUN_001d2000, 0);
    FUN_00213790(saved, -10001, "debug");
    FUN_002134a0(saved, FUN_001d2020, 0);
    FUN_00213790(saved, -10001, "cdebug");
#if defined(HULK_PTR64)
    FUN_001d1740(*state);
    return 0;  // (no caller reads it: 0x001d4830 calls this as void)
#else
    return FUN_001d1740(*state);
#endif
}
} // namespace fn_001d3c90

namespace fn_f55829c3 {

// 0x001d3f00 FUN_001d3f00 (86 B): equivalent/0x001d3f00.cpp
// sym: ?FUN_001d3f00@ScriptHandler_1d3f00@fn_f55829c3@@QAEXPBD0@Z @3cb426702b40 @w929a6dde0232
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 4/4)
// FUN_001d3f00 @ 0x001d3f00
void ScriptHandler_1d3f00::FUN_001d3f00(const char *text, const char *value) {
    FUN_00212d80(L, 0);
    const char *end = text;
    while (*end) ++end;
    if (FUN_001d2810(L, text, (int)(end - text), value))
        status = 0;
    else
        status = 3;
}

} // namespace fn_f55829c3

// 0x001d40d0 FUN_001d40d0 (89 B): matches/0x001d40d0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_001d40d0@@QAE@PBDPAVScriptHandler_1d40d0@1@P821@AEX00@Z@Z
namespace fn_001d40d0 {
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


extern void* hulk_at_00422624[2];
extern void* hulk_at_004227e0[2];

// Closure2<ScriptHandler, void, const char*, const char*>'s constructor (name, object, member function): Function's
// fields (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class ScriptHandler_1d40d0 {};
typedef void (ScriptHandler_1d40d0::*Fn_1d40d0)(const char*, const char*);
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_1d40d0 fn;            // 0x1c
    ScriptHandler_1d40d0* owner;  // 0x20

    Closure2(const char* a1, ScriptHandler_1d40d0* a2, Fn_1d40d0 a3);
};

Closure2::Closure2(const char* a1, ScriptHandler_1d40d0* a2, Fn_1d40d0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_00422624;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_004227e0;
    owner = a2;
}
} // namespace fn_001d40d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d4130 Closure2<ScriptHandler,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001d4130.cpp
// sym: ??_G?$Method1@VScriptHandler@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<ScriptHandler, void, const char *, const char *>::~Closure2() {}


// 0x001d4150 Closure2<ScriptHandler,void,const_char_*,const_char_*>::vfunc_2 (22 B): matches/0x001d4150.cpp
// sym: ?vfunc_2@?$Closure2@VScriptHandler@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<ScriptHandler, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_1d4150 * p = (Pair_1d4150 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_1d4150 * *)&this->f_20)->*(*(void (CActorManager_1d4150::**)(const char *, float))&this->f_1c))(p->s, p->f);
}
#if defined(HULK_PTR64)
template class Closure2<ScriptHandler, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d4130)
#endif

namespace fn_f55829c3 {

// 0x001d4170 FUN_001d4170 (76 B): matches/0x001d4170.cpp
// sym: ??0Closure1_1d4170@fn_f55829c3@@QAE@PBDPAVScriptHandler_1d4170@1@P821@AEM0@Z@Z
// Closure1<ScriptHandler, float, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
Closure1_1d4170::Closure1_1d4170(const char* x, ScriptHandler_1d4170* y, Fn_1d4170 z) : Method1_1d4170(x, z) {
    val = y;
}

} // namespace fn_f55829c3

// 0x001d41c0 Closure1<ScriptHandler,float,const_char_*>::vfunc_0 (30 B): matches/0x001d41c0.cpp
// sym: ??_G?$Method1@VScriptHandler@@W4script_state@1@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<ScriptHandler, float, const char *>::~Closure1() {}


// 0x001d41e0 Closure1<ScriptHandler,float,const_char_*>::vfunc_2 (43 B): matches/0x001d41e0.cpp
// sym: ?vfunc_2@?$Closure1@VScriptHandler@@MPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e800 (propagated; names are from that function)
template <> void Closure1<ScriptHandler, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr ignored = (hulk_intptr)__p0; const char ** arg = (const char **)__p1; float * out = (float *)__p2;

    CActorManager_1d41e0* obj = (*(CActorManager_1d41e0 * *)&this->f_20);
    Fn_1d41e0 fn = (*(Fn_1d41e0 *)&this->f_1c);
    float value = (obj->*fn)(*arg);
    if (out)
        *out = value;
}
#if defined(HULK_PTR64)
template class Closure1<ScriptHandler, float, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d41c0)
#endif

namespace fn_f55829c3 {

// 0x001d4210 FUN_001d4210 (76 B): matches/0x001d4210.cpp
// sym: ?Run@Closure1_1d4210@fn_f55829c3@@QAEPAV12@PBDPAVScriptHandler_1d4210@2@P832@AEPBD0@Z@Z
Closure1_1d4210* Closure1_1d4210::Run(const char* a, ScriptHandler_1d4210* b, Fn_1d4210 c) {
    Init_001d0480(a, 1);
    *(void**)this = (void*)DAT_00422644;
    fn = c;
    retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    *(void**)this = (void*)DAT_00422800;
    owner = b;
    return this;
}

} // namespace fn_f55829c3

// 0x001d4260 Closure1<ScriptHandler,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x001d4260.cpp
// sym: ??_G?$Method1@VScriptHandler@@_NPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<ScriptHandler, const char *, const char *>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<ScriptHandler, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1d4260)
#endif


// 0x001d4280 Closure1<ScriptHandler,const_char_*,const_char_*>::vfunc_2 (30 B): matches/0x001d4280.cpp [wrapped: conflict: ScriptHandler]
// sym: ?vfunc_2@Closure1_ScriptHandler@fn_001d4280@@UAEPBDPAXPAPBD1@Z
namespace fn_001d4280 {
struct ScriptHandler {
    const char* invoke(const char*);
};
struct Closure1_ScriptHandler : public ScriptFunctionFields {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual const char* vfunc_2(void* unused, const char** argument, const char** result);
    const char* (ScriptHandler::*callback)(const char*);
    ScriptHandler* handler;
};
const char* Closure1_ScriptHandler::vfunc_2(void* unused, const char** argument, const char** result) {
    ScriptHandler* h = handler;
    const char* arg = *argument;
    const char* (ScriptHandler::*fn)(const char*) = callback;
    const char* value = (h->*fn)(arg);
    if (result)
        *result = value;
    return value;
}
} // namespace fn_001d4280


// 0x001d42f0 Closure4<ScriptHandler,void,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 (39 B): matches/0x001d42f0.cpp
// sym: ?vfunc_2@?$Closure4@VScriptHandler@@XPBDPBDPBDPBD@@UAEXPAX00@Z
template <> void Closure4<ScriptHandler, void, const char *, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** args = (const char **)__p1; void * b = (void *)__p2;

    const char** p = args;
    const char* x = *p++;
    const char* y = *p++;
    const char* z = *p++;
    const char* w = *p++;
    ((*(ScriptHandler_1d42f0 * *)&this->f_20)->*(*(void (ScriptHandler_1d42f0::**)(const char *, const char *, const char *, const char *))&this->f_1c))(x, y, z, w);
}


// 0x001d4320 FUN_001d4320 (76 B): matches/0x001d4320.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_001d4320@@QAE@PBDPAVScriptHandler_1d4320@1@P821@AE?AW4script_state@21@0@Z@Z
namespace fn_001d4320 {
// data: tag1 = DAT_004c5d10, tag2 = DAT_0048e0f0

// Closure1<ScriptHandler, ScriptHandler::script_state, const char*>'s constructor (name, object, member function):
// Function's fields (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class ScriptHandler_1d4320 {
  public:
    enum script_state { s0 };
};
typedef ScriptHandler_1d4320::script_state (ScriptHandler_1d4320::*Fn_1d4320)(const char*);
class Root : public ScriptFunctionFields {
  public:
    Root(const char*, int);
    virtual void f();
    Fn_1d4320 x;
};
extern int check_001d04d0(const char*);
class Closure1_1d4320 : public Root {
  public:
    Closure1_1d4320(const char*, ScriptHandler_1d4320*, Fn_1d4320);
    virtual void f();
};
class Closure1 : public Closure1_1d4320 {
  public:
    Closure1(const char*, ScriptHandler_1d4320*, Fn_1d4320);
    virtual void f();
    ScriptHandler_1d4320* y;
};
Closure1_1d4320::Closure1_1d4320(const char* s, ScriptHandler_1d4320* x0, Fn_1d4320 x1) : Root(s, 1) {
    x = x1;
    retType = check_001d04d0(((const char*)&DAT_004c5d10));
    argTypes[0] = check_001d04d0(((const char*)&DAT_0048e0f0));
}
Closure1::Closure1(const char* s, ScriptHandler_1d4320* x0, Fn_1d4320 x1) : Closure1_1d4320(s, x0, x1) {
    y = x0;
}
} // namespace fn_001d4320


// 0x001d4390 Closure1<ScriptHandler,ScriptHandler::script_state,const_char_*>::vfunc_2 (30 B): matches/0x001d4390.cpp [wrapped: conflict: Closure1; ScriptHandler]
// sym: ?vfunc_2@Closure1@fn_001d4390@@UAEHPAXPAPBDPAH@Z
namespace fn_001d4390 {
struct ScriptHandler {
    enum script_state { initial_state };
};
struct Closure1 : public ScriptFunctionFields {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void* unused, const char** argument, int* result);
    int (ScriptHandler::*method)(const char*);
    ScriptHandler* object;
};
int Closure1::vfunc_2(void* unused, const char** argument, int* result) {
    ScriptHandler* obj = object;
    int (ScriptHandler::*fn)(const char*) = method;
    const char* arg = *argument;
    int value = (obj->*fn)(arg);
    if (result)
        *result = value;
    return value;
}
} // namespace fn_001d4390


// 0x001d43b0 FUN_001d43b0 (76 B): matches/0x001d43b0.cpp [wrapped: conflict: ScriptHandler]
// sym: ??0Closure1_1d43b0@fn_001d43b0@@QAE@PBDPAVScriptHandler@1@P821@AE_N0@Z@Z
namespace fn_001d43b0 {
// data: gName1 = DAT_0048e0e4, gName2 = DAT_0048e0f0

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

extern "C" char DAT_00422674[];
extern "C" char DAT_00422830[];
// Closure1<ScriptHandler, bool, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class ScriptHandler {};
typedef bool (ScriptHandler::*Fn_1d43b0)(const char*);
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Closure1_1d43b0 : public FUN_001d0480 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d43b0 fn;
    ScriptHandler* owner;
    Closure1_1d43b0(const char*, ScriptHandler*, Fn_1d43b0);
};
Closure1_1d43b0::Closure1_1d43b0(const char* a, ScriptHandler* b, Fn_1d43b0 c) : FUN_001d0480(a, 1) {
    vftable = (void*)DAT_00422674;
    fn = c;
    f.retType = (char)FUN_001d04d0((const char*)&(*(int*)&DAT_0048e0e4));
    f.argTypes[0] = (char)FUN_001d04d0((const char*)&(*(int*)&DAT_0048e0f0));
    vftable = (void*)DAT_00422830;
    owner = b;
}
} // namespace fn_001d43b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d4420 Closure1<ScriptHandler,bool,const_char_*>::vfunc_2 (30 B): matches/0x001d4420.cpp [wrapped: conflict: Closure1]
// sym: ?V2@Closure1@fn_001d4420@@UAEXPAXPAPBDPA_N@Z
namespace fn_001d4420 {
// Same code shape as 0x00106cc0 (propagated; names are from that function)
class Closure1 : public ScriptFunctionFields {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void*, const char**, bool*);
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
} // namespace fn_001d4420

namespace fn_f55829c3 {

// 0x001d4440 ScriptHandler::vfunc_0 (30 B): matches/0x001d4440.cpp
// sym: ?vfunc_2@ScriptHandler_1d4440@fn_f55829c3@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
ScriptHandler_1d4440* ScriptHandler_1d4440::vfunc_2(unsigned char flags) {
    ((ScriptHandler_nv_1d4440*)(((ScriptHandler*)(this))))->FUN_001d3410();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001d4530 FUN_001d4530 (71 B): matches/0x001d4530.cpp
// sym: ?target@fn_f55829c3@@YIXPAUScriptHandlerView@@@Z
// ScriptHandler (include/decls/data/script.h): (re)creates the Lua state once, then registers the functions.
void __fastcall target(ScriptHandlerView* self) {
    if (!self->f.ownsState) {
        self->f.ownsState = 1;
        ((ScriptHandler_nv_1d4530*)(self))->FUN_001d3c90(&self->f.L);
        ((ScriptHandler_nv_1d4530*)(self))->FUN_001d3bc0();
        ((R_1d4530 *)((owners::A_86340 *)hulk_at_004dd6ec)->FUN_00086340())->FUN_00092410();
        ((End_1d4530*)hulk_at_004dd700->r)->FUN_001dbd50();
    }
}

} // namespace fn_f55829c3

// 0x001d4580 FUN_001d4580 (108 B): matches/0x001d4580.cpp [wrapped: conflict: Closure2]
// sym: ?FUN_001d4580@Owner_1d4580@fn_001d4580@@QAEXPBDPAVScriptHandler_1d4580@2@P832@AEX00@Z@Z
inline void* operator new(hulk_uintptr, void* p) throw() {
    return p;
}
namespace fn_001d4580 {
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(int x);
extern "C++" __declspec(nothrow) int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C++" __declspec(nothrow) void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);

// Closure2<ScriptHandler, void, const char*, const char*> (include/decls/data/script.h): Function's fields, the member-function pointer, the object.
class ScriptHandler_1d4580 {
  public:
};
typedef void (ScriptHandler_1d4580::*Fn_1d4580)(const char*, const char*);
// 0x001d40d0 (matches/0x001d40d0.cpp): the closure's constructor (name, object, member function).
class Closure2 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d4580 fn;
    ScriptHandler_1d4580* owner;
    Closure2(const char* name, ScriptHandler_1d4580* object, Fn_1d4580 fn);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// ScriptHandler::AddFunction for this closure type (no caller: 0x001d4830 inlines it).
struct Owner_1d4580 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d4580(const char* a, ScriptHandler_1d4580* b, Fn_1d4580 c);
};
void Owner_1d4580::FUN_001d4580(const char* a, ScriptHandler_1d4580* b, Fn_1d4580 c) {
    HULK_SIZE32(Closure2, 0x24);
    Closure2* n = new (FUN_0008d690((int)sizeof(Closure2))) Closure2(a, b, c);
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&functions)->FUN_001d1180((ScriptFunctionView*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
} // namespace fn_001d4580


// 0x001d45f0 FUN_001d45f0 (108 B): matches/0x001d45f0.cpp [wrapped: conflict: Closure1_1d4170]
// sym: ?FUN_001d45f0@Owner_1d45f0@fn_001d45f0@@QAEXPBDPAVScriptHandler_1d45f0@2@P832@AEM0@Z@Z
namespace fn_001d45f0 {
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(int x);
extern "C++" __declspec(nothrow) int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C++" __declspec(nothrow) void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);

// Closure1<ScriptHandler, float, const char*> (include/decls/data/script.h): Function's fields, the member-function pointer, the object.
class ScriptHandler_1d45f0 {
  public:
};
typedef float (ScriptHandler_1d45f0::*Fn_1d45f0)(const char*);
// 0x001d4170 (matches/0x001d4170.cpp): the closure's constructor (name, object, member function).
class Closure1_1d4170 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d45f0 fn;
    ScriptHandler_1d45f0* owner;
    Closure1_1d4170(const char* name, ScriptHandler_1d45f0* object, Fn_1d45f0 fn);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// ScriptHandler::AddFunction for this closure type (no caller: 0x001d4830 inlines it).
struct Owner_1d45f0 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d45f0(const char* a, ScriptHandler_1d45f0* b, Fn_1d45f0 c);
};
void Owner_1d45f0::FUN_001d45f0(const char* a, ScriptHandler_1d45f0* b, Fn_1d45f0 c) {
    HULK_SIZE32(Closure1_1d4170, 0x24);
    Closure1_1d4170* n = new (FUN_0008d690((int)sizeof(Closure1_1d4170))) Closure1_1d4170(a, b, c);
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&functions)->FUN_001d1180((ScriptFunctionView*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
} // namespace fn_001d45f0


// 0x001d4660 FUN_001d4660 (108 B): matches/0x001d4660.cpp [wrapped: conflict: Closure1_1d4210]
// sym: ?FUN_001d4660@Owner_1d4660@fn_001d4660@@QAEXPBDPAVScriptHandler_1d4660@2@P832@AEPBD0@Z@Z
namespace fn_001d4660 {
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(int x);
extern "C++" __declspec(nothrow) int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C++" __declspec(nothrow) void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
// Closure1<ScriptHandler, const char*, const char*> (include/decls/data/script.h): Function's fields, the
// member-function pointer, the object.
class ScriptHandler_1d4660 {};
typedef const char* (ScriptHandler_1d4660::*Fn_1d4660)(const char*);
// 0x001d4210 (matches/0x001d4210.cpp): the closure's initializer (name, object, member function); returns this.
class Closure1_1d4210 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d4660 fn;
    ScriptHandler_1d4660* owner;
    Closure1_1d4210* Run_001d4210(const char*, ScriptHandler_1d4660*, Fn_1d4660);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// ScriptHandler::AddFunction for this closure type (no caller: 0x001d4830 inlines it).
struct Owner_1d4660 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d4660(const char* a, ScriptHandler_1d4660* b, Fn_1d4660 c);
};
void Owner_1d4660::FUN_001d4660(const char* a, ScriptHandler_1d4660* b, Fn_1d4660 c) {
    HULK_SIZE32(Closure1_1d4210, 0x24);
    Closure1_1d4210* p = (Closure1_1d4210*)FUN_0008d690((int)sizeof(Closure1_1d4210));
    Closure1_1d4210* n;
    if (p)
        n = p->Run_001d4210(a, b, c);
    else
        n = 0;
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&functions)->FUN_001d1180((ScriptFunctionView*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
} // namespace fn_001d4660


// 0x001d4750 FUN_001d4750 (108 B): matches/0x001d4750.cpp [wrapped: conflict: Closure1]
// sym: ?FUN_001d4750@Owner_1d4750@fn_001d4750@@QAEXPBDPAVScriptHandler_1d4750@2@P832@AE?AW4script_state@32@0@Z@Z
namespace fn_001d4750 {
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(int x);
extern "C++" __declspec(nothrow) int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C++" __declspec(nothrow) void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);

// Closure1<ScriptHandler, ScriptHandler::script_state, const char*> (include/decls/data/script.h): Function's fields, the member-function pointer, the object.
class ScriptHandler_1d4750 {
  public:
    enum script_state { s0 };
};
typedef ScriptHandler_1d4750::script_state (ScriptHandler_1d4750::*Fn_1d4750)(const char*);
// 0x001d4320 (matches/0x001d4320.cpp): the closure's constructor (name, object, member function).
class Closure1 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d4750 fn;
    ScriptHandler_1d4750* owner;
    Closure1(const char* name, ScriptHandler_1d4750* object, Fn_1d4750 fn);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// ScriptHandler::AddFunction for this closure type (no caller: 0x001d4830 inlines it).
struct Owner_1d4750 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d4750(const char* a, ScriptHandler_1d4750* b, Fn_1d4750 c);
};
void Owner_1d4750::FUN_001d4750(const char* a, ScriptHandler_1d4750* b, Fn_1d4750 c) {
    HULK_SIZE32(Closure1, 0x24);
    Closure1* n = new (FUN_0008d690((int)sizeof(Closure1))) Closure1(a, b, c);
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&functions)->FUN_001d1180((ScriptFunctionView*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
} // namespace fn_001d4750


// 0x001d47c0 FUN_001d47c0 (108 B): matches/0x001d47c0.cpp [wrapped: conflict: Closure1_1d43b0]
// sym: ?FUN_001d47c0@Owner_1d47c0@fn_001d47c0@@QAEXPBDPAVScriptHandler_1d47c0@2@P832@AE_N0@Z@Z
namespace fn_001d47c0 {
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(int x);
extern "C++" __declspec(nothrow) int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C++" __declspec(nothrow) void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);

// Closure1<ScriptHandler, bool, const char*> (include/decls/data/script.h): Function's fields, the member-function pointer, the object.
class ScriptHandler_1d47c0 {
  public:
};
typedef bool (ScriptHandler_1d47c0::*Fn_1d47c0)(const char*);
// 0x001d43b0 (matches/0x001d43b0.cpp): the closure's constructor (name, object, member function).
class Closure1_1d43b0 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d47c0 fn;
    ScriptHandler_1d47c0* owner;
    Closure1_1d43b0(const char* name, ScriptHandler_1d47c0* object, Fn_1d47c0 fn);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// ScriptHandler::AddFunction for this closure type (no caller: 0x001d4830 inlines it).
struct Owner_1d47c0 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d47c0(const char* a, ScriptHandler_1d47c0* b, Fn_1d47c0 c);
};
void Owner_1d47c0::FUN_001d47c0(const char* a, ScriptHandler_1d47c0* b, Fn_1d47c0 c) {
    HULK_SIZE32(Closure1_1d43b0, 0x24);
    Closure1_1d43b0* n = new (FUN_0008d690((int)sizeof(Closure1_1d43b0))) Closure1_1d43b0(a, b, c);
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&functions)->FUN_001d1180((ScriptFunctionView*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
} // namespace fn_001d47c0


// 0x001d4830 FUN_001d4830 (1114 B): equivalent/0x001d4830.cpp [wrapped: conflict: Closure1; Closure2; Method1; Method2 (+1)]
// sym: ??0ScriptHandler@fn_001d4830@@QAE@XZ @50592479c1e6 @wf75ffbdf0d7a
namespace fn_001d4830 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001d4830 @ 0x001d4830
// ScriptHandler's constructor (include/decls/data/script.h): the Lua state (0x001d3c90), the watch list, and the
// script functions it binds itself (sh_DoString, sh_GetNumber, sh_GetString, sh_CallFuncInGlobalState,
// sh_ProcessFile, dbg_AddWatch, dbg_DeleteWatch): each a Method<N> / Closure<N> on Function's fields, allocated with
// its own size (0x24 bytes on 32-bit), sorted into the function list and set as a Lua global closure over
// 0x001d22a0.
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

void *FUN_0008d690(unsigned int size);


class __declspec(novtable) MethodBase_1d4830 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char *, int);
    void FUN_001d04b0(const char *name);
    MethodBase_1d4830(const char *n, int k) { FUN_001d0480(n, k); }
};

extern "C++" __declspec(nothrow) int __cdecl FUN_001d22a0(LuaVMState *L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213550(LuaVMState *L, void *p);
extern "C++" __declspec(nothrow) void __cdecl FUN_002134a0(LuaVMState *L, LuaVMCFunction fn, int n);
extern "C++" __declspec(nothrow) void __cdecl FUN_00213790(LuaVMState *L, int idx, const char *k);

struct HandlerTable_1d4830 : public ScriptFunctionList {
    void FUN_001d1180(ScriptFunctionView *closure);
};
struct WatchList : public ScriptWatchList {
    void FUN_001d27d0();
};

// The fields are a member, not a base: a base after the vfptr would give pointers to ScriptHandler's members (the
// closures' Method<N> slots) the multiple-inheritance form, 8 bytes instead of 4.
class ScriptHandler {
  public:
    enum script_state { state0 };
    virtual void* v0_001d4440(char);
    ScriptHandlerFields h;

    void FUN_001d3f00(const char *, const char *);
    float FUN_001d2790(const char *);
    const char *FUN_001d27b0(const char *);
    void FUN_001d4460(const char *, const char *, const char *, const char *);
    script_state FUN_001d36e0(const char *);
    bool FUN_001d1140(const char *);
    bool FUN_001d1150(const char *);
    void FUN_001d46d0(const char *name, ScriptHandler *obj,
                      void (ScriptHandler::*fn)(const char *, const char *, const char *, const char *));
    void FUN_001d3c90(LuaVMState **pL);
    ScriptHandler();
};

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<ScriptHandler::script_state> { static const void *get() { return &DAT_004c5d10; } };

template <class T, class R, class A>
class Method1 : public MethodBase_1d4830 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_1d4830(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

template <class T, class R, class A, class B>
class Method2 : public MethodBase_1d4830 {
  public:
    typedef R (T::*Fn)(A, B);
    Method2(const char *name, Fn f) : MethodBase_1d4830(name, 2) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
        argTypes[1] = FUN_001d04d0(TypeTag<B>::get());
    }
    Fn fn;
};

template <class T, class R, class A, class B>
class Closure2 : public Method2<T, R, A, B> {
  public:
    Closure2(const char *name, T *o, typename Method2<T, R, A, B>::Fn f) : Method2<T, R, A, B>(name, f), owner(o) {}
    T *owner;
};

ScriptHandler::ScriptHandler() {
    h.status = 0;
    h.L = 0;
    h.functions.count = 0;
    h.refreshCount = 0;
    h.ownsState = 1;
    ((WatchList *)&h.watches)->FUN_001d27d0();
    h.coroutineId = 0;
    for (int i = 0; i < 8; i++)
        h.tops[i] = -1;
    h.topIndex = -1;
    FUN_001d3c90(&h.L);

    void *mem;
    mem = FUN_0008d690((int)sizeof(Closure2<ScriptHandler, void, const char *, const char *>));
    Closure2<ScriptHandler, void, const char *, const char *> *doString = 0;
    if (mem)
        doString = new (mem) Closure2<ScriptHandler, void, const char *, const char *>("sh_DoString", this, &ScriptHandler::FUN_001d3f00);
    doString->FUN_001d04b0("sh_DoString");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)doString);
    LuaVMState *l_doString = h.L;
    FUN_00213550(l_doString, doString);
    FUN_002134a0(l_doString, FUN_001d22a0, 1);
    FUN_00213790(l_doString, -10001, "sh_DoString");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, float, const char *>));
    Closure1<ScriptHandler, float, const char *> *getNumber = 0;
    if (mem)
        getNumber = new (mem) Closure1<ScriptHandler, float, const char *>("sh_GetNumber", this, &ScriptHandler::FUN_001d2790);
    getNumber->FUN_001d04b0("sh_GetNumber");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)getNumber);
    LuaVMState *l_getNumber = h.L;
    FUN_00213550(l_getNumber, getNumber);
    FUN_002134a0(l_getNumber, FUN_001d22a0, 1);
    FUN_00213790(l_getNumber, -10001, "sh_GetNumber");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, const char *, const char *>));
    Closure1<ScriptHandler, const char *, const char *> *getString = 0;
    if (mem)
        getString = new (mem) Closure1<ScriptHandler, const char *, const char *>("sh_GetString", this, &ScriptHandler::FUN_001d27b0);
    getString->FUN_001d04b0("sh_GetString");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)getString);
    LuaVMState *l_getString = h.L;
    FUN_00213550(l_getString, getString);
    FUN_002134a0(l_getString, FUN_001d22a0, 1);
    FUN_00213790(l_getString, -10001, "sh_GetString");

    FUN_001d46d0("sh_CallFuncInGlobalState", this, &ScriptHandler::FUN_001d4460);

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, ScriptHandler::script_state, const char *>));
    Closure1<ScriptHandler, ScriptHandler::script_state, const char *> *processFile = 0;
    if (mem)
        processFile = new (mem) Closure1<ScriptHandler, ScriptHandler::script_state, const char *>("sh_ProcessFile", this, &ScriptHandler::FUN_001d36e0);
    processFile->FUN_001d04b0("sh_ProcessFile");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)processFile);
    LuaVMState *l_processFile = h.L;
    FUN_00213550(l_processFile, processFile);
    FUN_002134a0(l_processFile, FUN_001d22a0, 1);
    FUN_00213790(l_processFile, -10001, "sh_ProcessFile");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, bool, const char *>));
    Closure1<ScriptHandler, bool, const char *> *addWatch = 0;
    if (mem)
        addWatch = new (mem) Closure1<ScriptHandler, bool, const char *>("dbg_AddWatch", this, &ScriptHandler::FUN_001d1140);
    addWatch->FUN_001d04b0("dbg_AddWatch");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)addWatch);
    LuaVMState *l_addWatch = h.L;
    FUN_00213550(l_addWatch, addWatch);
    FUN_002134a0(l_addWatch, FUN_001d22a0, 1);
    FUN_00213790(l_addWatch, -10001, "dbg_AddWatch");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, bool, const char *>));
    Closure1<ScriptHandler, bool, const char *> *delWatch = 0;
    if (mem)
        delWatch = new (mem) Closure1<ScriptHandler, bool, const char *>("dbg_DeleteWatch", this, &ScriptHandler::FUN_001d1150);
    delWatch->FUN_001d04b0("dbg_DeleteWatch");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)delWatch);
    LuaVMState *l_delWatch = h.L;
    FUN_00213550(l_delWatch, delWatch);
    FUN_002134a0(l_delWatch, FUN_001d22a0, 1);
    FUN_00213790(l_delWatch, -10001, "dbg_DeleteWatch");
}
} // namespace fn_001d4830
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f55829c3 {

// 0x001d4c90 FUN_001d4c90 (47 B): matches/0x001d4c90.cpp
// sym: _FUN_001d4c90
// The ScriptHandler singleton (DAT_004e23cc): allocated with ScriptHandler's size (include/decls/data/script.h
// ScriptHandlerView: 0x5494 bytes on 32-bit) and constructed by 0x001d4830.
extern "C" ScriptHandler_1d4c90* FUN_001d4c90() {
    if (!(*(ScriptHandler_1d4c90**)&DAT_004e23cc)) {
        HULK_SIZE32(ScriptHandlerView, 0x5494);
        void* memory = FUN_0008d690((int)sizeof(ScriptHandlerView));
        if (memory) {
            (*(ScriptHandler_1d4c90**)&DAT_004e23cc) = ((ScriptHandler_1d4c90*)memory)->FUN_001d4830();
            return (*(ScriptHandler_1d4c90**)&DAT_004e23cc);
        }
        (*(ScriptHandler_1d4c90**)&DAT_004e23cc) = 0;
    }
    return (*(ScriptHandler_1d4c90**)&DAT_004e23cc);
}

} // namespace fn_f55829c3
