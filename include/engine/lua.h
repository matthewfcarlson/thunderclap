// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_LUA_H
#define TREE_ENGINE_LUA_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
TREE_TU_BEGIN
extern "C" int __cdecl FUN_00215f70(unsigned int x);
extern "C" void __cdecl FUN_00216340(char* out, const char* source, int bufflen);
TREE_TU_END
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *strncpy(char *dst, const char *src, unsigned int n);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __fastcall __security_check_cookie(unsigned int);
#endif
TREE_TU_BEGIN
extern "C" int* __cdecl FUN_00347ba4();
extern "C" const char* __cdecl FUN_00347b53(int);
extern "C" int __cdecl FUN_00345475(int);
TREE_TU_END
#endif
