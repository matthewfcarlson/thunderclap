#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl release(void*);
extern "C" void* __cdecl alloc(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
char owners::Obj_11c470::FUN_0011c470(const char* s) {
    release(str);
    if (!s) {
        str = (char*)s;
        return 1;
    }
    str = (char*)alloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}