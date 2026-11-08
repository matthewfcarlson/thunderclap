// luaV_tonumber: obj itself when a number; a string converted into n; else 0.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00215ff0(const char* s, float* result);

extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n) {
    if (obj->tt == LUAVM_TNUMBER)
        return obj;
    if (obj->tt == LUAVM_TSTRING) {
        float num;
        if (FUN_00215ff0(LUAVM_GETSTR(obj->value.gc), &num)) {
            n->value.n = num;
            n->tt = LUAVM_TNUMBER;
            return n;
        }
    }
    return 0;
}
