// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_GAME_GLOBAL_H
#define TREE_GAME_GLOBAL_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
TREE_TU_BEGIN
extern "C" char DAT_003f3390[];
extern char vftableD[];
extern char vftableA[];
TREE_TU_END
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern void* gD[];
extern int vtableAction;
extern int vtableSweep;
extern "C" char DAT_003f3c90[];
TREE_TU_END
void operator delete(void*);
TREE_TU_BEGIN
extern void* g_vftable2[];
hulk_freg __cdecl FUN_00225be0(float a, float b, float c, int d);
extern char __cdecl ReadValue(const char*);
void __cdecl invoke(int, hulk_intptr, hulk_intptr, int);
extern "C" void FUN_00234810(void*, void*);
extern "C" char DAT_003f7394[];
extern "C" char DAT_003f7404[];
extern void __fastcall FUN_002345b0(void*);
extern hulk_freg __cdecl FUN_0004af40(float, float, float);
extern "C" char __cdecl FUN_00018960(float a, float b, float c);
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
extern void* g_vftable[];
extern char DAT_00491ca8;
extern "C" void FUN_002361a0();
extern void* CFightNodeConditionVtable;
extern "C" void FUN_00236250();
extern "C" void FUN_00236340();
extern void* conditionVtable;
struct Input {  };
extern "C" void FUN_00054240();
extern "C" void FUN_00052c40();
extern "C" void FUN_00052a40();
extern "C" void FUN_000528d0();
extern "C" void FUN_000527d0();
extern "C" void FUN_00053fe0();
extern "C" void FUN_00056570();
void __cdecl FUN_0008d330(void*);
void __cdecl FUN_0008d340(void*);
TREE_TU_END
#ifdef TREE_LOCAL_CCollisionTrack
TREE_TU_BEGIN
#endif
class CCollisionTrack;
#ifdef TREE_LOCAL_CCollisionTrack
TREE_TU_END
#endif
TREE_TU_BEGIN
class ParamFloatPtrConstRange {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(void*, float);
    char pad[0x10 - 4];
    int offset;
};
extern int* gTable;
extern char DAT_0049850c;
extern "C" void FUN_00061850();
extern "C" void FUN_000610c0();
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void FUN_000612e0();
extern "C" void FUN_000645c0();
extern "C" void FUN_0005fbe0();
extern "C" void FUN_00071430();
extern "C" void FUN_00071700();
extern "C" void FUN_000717e0();
extern "C" void FUN_00071a80();
extern "C" void FUN_000719a0();
extern "C" void FUN_00072360();
extern "C" void FUN_00070d50();
extern "C" void FUN_00072280();
extern "C" void FUN_00071fb0();
extern "C" void FUN_00074d90();
extern void* gV[];
extern void __cdecl FUN_002656a0();
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
typedef unsigned __int64 U64;
void FreeMem(void*);
TREE_TU_END
extern int __cdecl __vsnprintf(char*, int, const char*, void*);
TREE_TU_BEGIN
extern hulk_freg __cdecl FUN_000189c0(float);
hulk_freg FUN_000a02a0(float angle);
hulk_freg __cdecl FUN_00018a20(float x);
TREE_TU_END
struct World;
TREE_TU_BEGIN
extern "C" char DAT_003f6098[];
extern "C" void FUN_002684c0();
extern "C" void CopyBytes(void*, const void*, unsigned int);
TREE_TU_END
extern "C" char* __cdecl _strncpy(char* dst, const char* src, unsigned int n);
TREE_TU_BEGIN
template <class T> struct TypeTag;
struct Sprite {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};
extern "C" void __cdecl FUN_000cb7d0(float *cur, float *target, float step);
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif
TREE_TU_BEGIN
extern unsigned int DAT_004d9968;
extern int billboardVtable;
extern int animationVtable;
void thunk(unsigned int);
extern "C" char DAT_0040bfe0[];
void ReleaseThing(void*);
extern void* handvtable;
typedef unsigned __int64 ID;
extern "C" void* FUN_00266e00(int heap, int size);
extern "C" int __cdecl FUN_00096600(const char *a, const char *b);
void thunk(void*);
extern "C" void __cdecl FUN_00240bb0();
extern "C" int __cdecl FUN_002673a0(int, int);
TREE_TU_END
#endif
