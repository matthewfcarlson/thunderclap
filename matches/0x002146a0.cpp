// luaG_checkcode: the whole of pt's code passes symbexec.
#include "decls/data/lua.h"

extern "C" LuaVMInstruction __cdecl FUN_002142d0(const LuaVMProto* pt, int lastpc, int reg);

extern "C" int __cdecl FUN_002146a0(const LuaVMProto* pt) {
    return FUN_002142d0(pt, pt->sizecode, 0xff) != 0;
}
