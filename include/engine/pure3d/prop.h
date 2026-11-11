// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_PURE3D_PROP_H
#define TREE_ENGINE_PURE3D_PROP_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
TREE_TU_BEGIN
extern void __cdecl Cast(hulk_uintptr, int, const int*, const int*, int);
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
extern void thunk_FUN_00267090(CCollisionAction*);
TREE_TU_END
#endif
