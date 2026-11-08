// luaF_newCclosure: a C closure with nelems upvalues.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);

extern "C" LuaVMClosure* __cdecl FUN_00219520(LuaVMState* L, int nelems) {
    LuaVMClosure* c = (LuaVMClosure*)FUN_0021add0(L, 0, 0, LUAVM_SIZECCLOSURE(nelems));
    FUN_00217130(L, (LuaVMGCObject*)c, LUAVM_TFUNCTION);
    c->c.nupvalues = (unsigned char)nelems;
    c->c.isC = 1;
    return c;
}
