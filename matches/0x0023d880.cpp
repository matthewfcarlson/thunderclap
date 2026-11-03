#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FreeMem(void*);
extern "C" void* __cdecl AllocMem(hulk_uintptr);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
char owners::Obj_23d880::FUN_0023d880(const char* s) {
    FreeMem(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)AllocMem(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}