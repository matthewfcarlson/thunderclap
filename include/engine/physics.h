// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_PHYSICS_H
#define TREE_ENGINE_PHYSICS_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
struct Vector { float x,y,z; };
extern "C" void __cdecl FUN_002f46a0(unsigned short *, unsigned short *, int);
TREE_TU_END
#ifdef TREE_LOCAL_CAction
TREE_TU_BEGIN
#endif
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
#ifdef TREE_LOCAL_CAction
TREE_TU_END
#endif
TREE_TU_BEGIN
void *thunk_FUN_0008d690(unsigned int size);
TREE_TU_END
void __cdecl operator delete(void*);
TREE_TU_BEGIN
void __cdecl release(void*);
extern "C" char DAT_004317dc[];
class Node;
hulk_freg __cdecl FUN_00018a20(float);
TREE_TU_END
#ifdef TREE_LOCAL_CEffectStopTrack
TREE_TU_BEGIN
#endif
class CEffectStopTrack {
  public:
};
#ifdef TREE_LOCAL_CEffectStopTrack
TREE_TU_END
#endif
TREE_TU_BEGIN
extern "C" char DAT_00431d1c[];
TREE_TU_END
#endif
