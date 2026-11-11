// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_GAME_HULKFIGHT_AI_H
#define TREE_GAME_HULKFIGHT_AI_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
TREE_TU_BEGIN
extern "C" void FUN_00234810(void*, void*);
TREE_TU_END
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern char DAT_0049850c;
extern "C" void opdel(void*);
TREE_TU_END
void* __cdecl operator new(size_t size);
TREE_TU_BEGIN
extern "C" char DAT_0040d9a4[];
TREE_TU_END
void __cdecl operator delete(void* p);
void operator delete[](void*);
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
TREE_TU_BEGIN
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
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void Free(void*) throw();
extern int g2;
void* __cdecl operator_new(unsigned int);
extern "C" hulk_freg FUN_00224fc0(float from, float to);
extern "C" float FUN_00083d90(float *v);
extern int tdcVtable;
TREE_TU_END
#endif
