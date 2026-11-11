// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_GAME_UNKNOWN_H
#define TREE_GAME_UNKNOWN_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern void* g_vftable2[];
TREE_TU_END
void operator delete(void*);
TREE_TU_BEGIN
typedef unsigned __int64 U64;
extern "C" void FUN_00234810(void*, void*);
struct V3 {
    int x, y, z;
};
struct Src {
    int a;
    int b;
    int c;
};
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char* dst, const char* fmt, ...);
#endif
TREE_TU_BEGIN
void __cdecl thunk(int);
extern "C" void __cdecl FUN_000fc160();
extern "C" void opdel(void*);
extern int check(void*, int, int*, int*, int);
TREE_TU_END
#endif
