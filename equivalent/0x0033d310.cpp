// STATUS: equivalent (tools/equiv.py level 3: 2655 inputs, branch coverage 18/18)
// FUN_0033d310 @ 0x0033d310
// lstrlib scanformat
#include "decls/data/lua.h"

extern "C" char* __cdecl strchr(const char*, int);
extern "C" int __cdecl isdigit(int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);

// equiv-conv: FUN_0033d310 ebx stack stack stack
const char* FUN_0033d310(const char* strfrmt, LuaVMState* L, char* form, int* hasprecision)
{
    const char* p = strfrmt;
    while (strchr("-+ #0", (signed char)*p)) ++p;
    if (isdigit((unsigned char)*p)) ++p;
    if (isdigit((unsigned char)*p)) ++p;
    if (*p == '.') {
        ++p;
        *hasprecision = 1;
        if (isdigit((unsigned char)*p)) ++p;
        if (isdigit((unsigned char)*p)) ++p;
    }
    if (isdigit((unsigned char)*p))
        FUN_00338e20(L, "invalid format (width or precision too long)");
    int length = (int)(p - strfrmt);
    if (length + 2 > 20)
        FUN_00338e20(L, "invalid format (too long)");
    *form = '%';
    strncpy(form + 1, strfrmt, (unsigned int)(length + 1));
    form[length + 2] = 0;
    return p;
}
