// luaD_protectedparser: run f_parser protected over an SParser on the stack, then free its buffer.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00215de0(LuaVMState* L, void(__cdecl* func)(LuaVMState* L, void* ud), void* u, int oldtop,
                                    int ef);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00215c00(LuaVMState* L, void* ud);

extern "C" int __cdecl FUN_00215ee0(LuaVMState* L, LuaVMZio* z, const char* name) {
    LuaVMSParser p;
    p.z = z;
    p.name = name;
    p.buff.buffer = 0;
    p.buff.buffsize = 0;
    int status = FUN_00215de0(L, FUN_00215c00, &p, (int)((char*)L->top - (char*)L->stack), L->errfunc);
    FUN_0021add0(L, p.buff.buffer, p.buff.buffsize, 0);
    return status;
}
