#include "compat/ptr.h"
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl helper(void*, const char*, hulk_uintptr, const char*);
void __cdecl target(void* p, const char* s) {
    helper(p, s, strlen(s), s);
}
