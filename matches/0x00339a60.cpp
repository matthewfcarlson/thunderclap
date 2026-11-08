// luaL_loadbuffer
#include "decls/data/lua.h"
extern "C" const char* __cdecl FUN_00339a40(LuaVMState* L, void* ud, unsigned int* size);
extern "C" int __cdecl FUN_00213b20(LuaVMState* L, LuaVMReader reader, void* data, const char* chunkname);
extern "C" int __cdecl FUN_00339a60(LuaVMState* L, const char* buff, unsigned int size, const char* name) {
    LuaVMLoadS ls;
    ls.s = buff;
    ls.size = size;
    return FUN_00213b20(L, FUN_00339a40, &ls, name);
}
