// luaL_findstring: the index of name in a null-ended list, or -1.
#include "decls/data/lua.h"
extern "C" int strcmp(const char*, const char*);
extern "C" int __cdecl FUN_00338e50(const char* name, const char* const* list) {
    int i = 0;
    const char* p = list[0];
    while (p) {
        if (strcmp(p, name) == 0)
            return i;
        p = list[++i];
    }
    return -1;
}
