// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_UNKNOWN_H
#define TREE_ENGINE_UNKNOWN_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif
TREE_TU_BEGIN
struct Vec3N {
    float x, y, z;
    void FUN_0022d180();
};
void thunk(int);
void FUN_0008d330(void* p);
TREE_TU_END
extern "C" void _ReadWriteBarrier();
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
typedef unsigned char bool8;
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif
TREE_TU_BEGIN
void thunk(void*);
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
struct V3 {
    float x, y, z;
};
void __cdecl FUN_0008d340(void*);
TREE_TU_END
void __cdecl operator delete(void*);
#endif
