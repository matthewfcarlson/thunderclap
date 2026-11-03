#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl releaseMem(void*);
extern "C" void* __cdecl allocMem(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
void owners::Obj_28fe80::FUN_0028fe80(const char* src) {
    if (text) {
        releaseMem(text);
        text = 0;
    }
    if (src) {
        text = (char*)allocMem(strlen(src) + 1);
        strcpy(text, src);
    }
}