// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_GAME_HULKFIGHT_MOTION_H
#define TREE_GAME_HULKFIGHT_MOTION_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
TREE_TU_BEGIN
extern "C" void FUN_00234810(void*, void*);
void* FUN_00263ea0(unsigned int size);
struct One {
    void* f();
};
struct Three {
    void f(void*, int);
};
TREE_TU_END
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern void* g_vftable_00411dc4[];
struct P8 {
    int Get();
    void Set(int);
};
extern void* g_vftable2[];
TREE_TU_END
void operator delete(void*);
TREE_TU_BEGIN
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};
extern "C" hulk_intptr __fastcall Construct(void*);
TREE_TU_END
void* __cdecl operator new(size_t size);
TREE_TU_BEGIN
extern "C" hulk_intptr FUN_0005a3f0(hulk_intptr);
hulk_freg __cdecl FUN_0004af40(float,float,float);
extern void* g_vftable[];
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
extern char DAT_00491ca8;
extern "C" void opdel(void*);
template <class T>
class ParamEnumConstList : public ParamEnumBase {
public:
    ParamEnumConstList(const char* name, char** t, int n, void (T::*s)()) : ParamEnumBase(name) { table = t; count = n; setter = s; }
    virtual void v0();
    char** table;
    int count;
    void (T::*setter)();
    int unused1c;
};
extern void *thunk_FUN_0008d690(unsigned int size);
Owner *__fastcall FUN_000592a0(Owner *owner);
extern "C" float FUN_00083d90(float* p);
hulk_freg __cdecl FUN_00224ea0(float x, float z);
struct SubSkel {
    hulk_freg FUN_002220d0();
};
struct Animation {
    char pad0[8];
    int dummy;
};
class Child {
  public:
    Child(int);
};
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
TREE_TU_BEGIN
void thunk(int);
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
TREE_TU_BEGIN
hulk_freg __cdecl FUN_00018a20(float);
extern "C" int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);
TREE_TU_END
#endif
