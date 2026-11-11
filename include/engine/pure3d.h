// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_PURE3D_H
#define TREE_ENGINE_PURE3D_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
TREE_TU_BEGIN
void thunk(void*);
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
extern "C" char DAT_003f6098[];
TREE_TU_END
extern "C" void _ReadWriteBarrier();
void operator delete[](void*);
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
void __fastcall FUN_0027afd0(CEffectStopTrack*);
extern void __cdecl Cast(hulk_uintptr, int, const int*, const int*, int);
typedef unsigned __int64 U64;
extern U64 __cdecl getValue(void*);
TREE_TU_END
#ifdef TREE_LOCAL_pure3d
TREE_TU_BEGIN
#endif
namespace pure3d {
class Light;
}
#ifdef TREE_LOCAL_pure3d
TREE_TU_END
#endif
TREE_TU_BEGIN
void *thunk_FUN_0008d690(unsigned int size);
extern void* g_vftable2[];
void thunk(int);
extern char CameraRTTI;
struct Vec3 { float x, y, z; };
extern void __cdecl g(int);
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
TREE_TU_BEGIN
extern "C" void* __cdecl allocate(hulk_intptr);
extern void Init(void*, unsigned int, void*);
void ReleaseThing(void*);
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char *buf, const char *fmt, ...);
#endif
#endif
