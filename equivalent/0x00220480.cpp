// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 6/6)
// luaU_undump: load a precompiled chunk (the header, then the main function).
// equiv-conv: FUN_00220310 eax
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_00220310(LuaVMLoadState* S);
extern "C" LuaVMProto* __cdecl FUN_00220050(LuaVMLoadState* S, LuaVMString* p);

extern "C" LuaVMProto* __cdecl FUN_00220480(LuaVMState* L, LuaVMZio* Z, LuaVMBuffer* buff, const char* name) {
    LuaVMLoadState S;
    if (*name == '@' || *name == '=')
        S.name = name + 1;
    else if (*name == '\x1b')
        S.name = DAT_004271a8;
    else
        S.name = name;
    S.L = L;
    S.Z = Z;
    S.b = buff;
    FUN_00220310(&S);
    return FUN_00220050(&S, 0);
}
