// luaG_concaterror: the type error for a concatenation (names p2 when p1 is a string).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);

extern "C" void __cdecl FUN_00214d20(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2) {
    const LuaVMTObject* o = p1;
    if (p1->tt == LUAVM_TSTRING)
        o = p2;
    FUN_00214c90(L, o, "concatenate");
}
