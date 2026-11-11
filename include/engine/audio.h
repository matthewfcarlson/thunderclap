// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_AUDIO_H
#define TREE_ENGINE_AUDIO_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif
TREE_TU_BEGIN
extern "C" void __cdecl FUN_0024a450(void *);
extern "C" void __cdecl FUN_0024a4a0(void *);
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
void Free(void* pool, void* p);
extern "C" void __fastcall FUN_0025fd10(void*);
TREE_TU_END
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern char bss;
extern "C" char DAT_004298fc[];
class PosHelper {
  public:
    bool test(void*);
};
extern void Register(void*, void*);
struct Link {
    Link* next;
};
struct List {
    Link* head;
    Link* tail;
};
extern "C" char DAT_0042aa7c[];
extern "C" void __cdecl FUN_002603e0(void *, void *);
TREE_TU_END
#endif
