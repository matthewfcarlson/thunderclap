// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00339ba0 @ 0x00339ba0
// lua_dobuffer
#include "decls/data/lua.h"
extern "C" const char* __cdecl FUN_00339a40(LuaVMState* L, void* ud, unsigned int* size);
extern "C" int __cdecl FUN_00213b20(LuaVMState* L, LuaVMReader reader, void* data, const char* chunkname);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
// equiv-conv: FUN_00339ad0 eax esi
extern "C" void __cdecl FUN_00339ad0(int status, LuaVMState* L);
extern "C" int __cdecl FUN_00339ba0(LuaVMState* source, const char* first, unsigned int second, const char* last)
{
    LuaVMLoadS data;
    data.s = first;
    data.size = second;
    int result = FUN_00213b20(source, FUN_00339a40, &data, last);
    if (result == 0)
        result = FUN_002139f0(source, 0, -1, 0);
    FUN_00339ad0(result, source);
    return result;
}
