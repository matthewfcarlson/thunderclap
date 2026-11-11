// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_GAME_RENDER_H
#define TREE_GAME_RENDER_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern void* g_vftable2[];
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
#ifdef TREE_LOCAL_CCollisionAction
TREE_TU_BEGIN
#endif
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
#ifdef TREE_LOCAL_CCollisionAction
TREE_TU_END
#endif
TREE_TU_BEGIN
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
TREE_TU_END
#endif
