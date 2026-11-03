#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
unsigned char owners::X_181670::FUN_00181670(const char* s) {
    Free(p);
    if (!s) {
        p = 0;
        return 1;
    }
    p = (char*)Alloc(strlen(s) + 1);
    strcpy(p, s);
    return 1;
}