// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 4/4)
// cl-flags: /GS
// luaV_tostring: convert a number in place to its string ("%.7g"); 0 when obj is not a number.
#include "decls/data/lua.h"

extern int __cdecl _sprintf(char*, const char*, ...);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

extern "C" int __cdecl FUN_00217640(LuaVMState* L, LuaVMTObject* obj) {
    char s[32];
    if (obj->tt != LUAVM_TNUMBER) {
        return 0;
    }
    _sprintf(s, "%.7g", (double)obj->value.n);
    const char* e = s;
    while (*e != 0)
        e++;
    obj->value.gc = (LuaVMGCObject*)FUN_00219430(L, s, (unsigned int)(e - s));
    obj->tt = LUAVM_TSTRING;
    return 1;
}
