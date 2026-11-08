// luaF_freeproto: free a prototype's arrays and the prototype.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" void __cdecl FUN_00219730(LuaVMState* L, LuaVMProto* f) {
    FUN_0021add0(L, f->code, f->sizecode * (unsigned int)sizeof(LuaVMInstruction), 0);
    FUN_0021add0(L, f->p, f->sizep * (unsigned int)sizeof(LuaVMProto*), 0);
    FUN_0021add0(L, f->k, f->sizek * (unsigned int)sizeof(LuaVMTObject), 0);
    FUN_0021add0(L, f->lineinfo, f->sizelineinfo * (unsigned int)sizeof(int), 0);
    FUN_0021add0(L, f->locvars, f->sizelocvars * (unsigned int)sizeof(LuaVMLocVar), 0);
    FUN_0021add0(L, f->upvalues, f->sizeupvalues * (unsigned int)sizeof(LuaVMString*), 0);
    FUN_0021add0(L, f, sizeof(LuaVMProto), 0);
}
