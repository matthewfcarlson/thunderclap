#include "compat/ptr.h"
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl helper(void*, const char*, hulk_uintptr, const char*);
extern "C" void __cdecl FUN_00339c00(void* p, const char* s) {
    helper(p, s, strlen(s), s);
}
