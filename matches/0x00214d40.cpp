// luaG_aritherror: the type error for arithmetic (names p1 when it does not convert to a number, else p2).
#include "decls/data/lua.h"

extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n);
extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);

extern "C" void __cdecl FUN_00214d40(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2) {
    LuaVMTObject temp;
    const LuaVMTObject* o;
    if (FUN_00217600(p1, &temp) == 0)
        o = p1;
    else
        o = p2;
    FUN_00214c90(L, o, "perform arithmetic on");
}
