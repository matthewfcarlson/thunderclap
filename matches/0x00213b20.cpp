// lua_load: load a chunk through reader (chunkname "?" when NULL).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_0021a5e0(LuaVMState* L, LuaVMZio* z, LuaVMReader reader, void* data);
extern "C" int __cdecl FUN_00215ee0(LuaVMState* L, LuaVMZio* z, const char* name);

extern "C" int __cdecl FUN_00213b20(LuaVMState* L, LuaVMReader reader, void* data, const char* chunkname) {
    LuaVMZio z;
    if (!chunkname)
        chunkname = DAT_00426608;
    FUN_0021a5e0(L, &z, reader, data);
    return FUN_00215ee0(L, &z, chunkname);
}
