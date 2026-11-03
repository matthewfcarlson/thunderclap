#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
char owners::Obj_10cb00::FUN_0010cb00(const char* p) {
    Free(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)Alloc(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}