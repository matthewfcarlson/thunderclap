// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_FIGHT_H
#define TREE_ENGINE_FIGHT_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern "C" char DAT_003f6098[];
void __cdecl thunk(void*);
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memset(void *, int, unsigned int);
#endif
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
extern "C" char DAT_004279fc[];
extern int base_vtable;
TREE_TU_END
void operator delete(void*);
TREE_TU_BEGIN
extern void* vSeq[];
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
TREE_TU_END
void* __cdecl operator new(size_t size);
TREE_TU_BEGIN
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
TREE_TU_BEGIN
class Factory {
  public:
    void Do(void*);
};
extern "C" void __cdecl FUN_00263f30(void* p);
class Part {
  public:
    Part();
};
TREE_TU_END
#endif
