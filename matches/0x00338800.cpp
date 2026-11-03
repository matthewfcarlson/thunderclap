#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" unsigned int __cdecl strlen(const char*);
char* owners::Obj_338800::FUN_00338800(const char* name) {
    char* s = text;
    hulk_uintptr len = strlen(name);
    while (*s) {
        if (Match(name, s, len))
            return s;
        s += strlen(s) + 1;
    }
    return 0;
}