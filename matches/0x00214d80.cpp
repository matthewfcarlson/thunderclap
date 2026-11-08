// luaG_ordererror: the error for comparing p1 with p2 (two values of one type, or of two types).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);

extern "C" int __cdecl FUN_00214d80(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2) {
    const char* t1 = DAT_00426948[p1->tt];
    const char* t2 = DAT_00426948[p2->tt];
    if (t1[2] == t2[2]) {
        FUN_00214a90(L, DAT_00426728, t1);
        return 0;
    }
    FUN_00214a90(L, DAT_00426708, t1, t2);
    return 0;
}
