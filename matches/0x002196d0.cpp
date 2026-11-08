// luaF_newproto: an empty function prototype.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);

extern "C" LuaVMProto* __cdecl FUN_002196d0(LuaVMState* L) {
    LuaVMProto* f = (LuaVMProto*)FUN_0021add0(L, 0, 0, sizeof(LuaVMProto));
    FUN_00217130(L, (LuaVMGCObject*)f, LUAVM_TPROTO);
    f->k = 0;
    f->sizek = 0;
    f->p = 0;
    f->sizep = 0;
    f->code = 0;
    f->sizecode = 0;
    f->sizelineinfo = 0;
    f->sizeupvalues = 0;
    f->nups = 0;
    f->upvalues = 0;
    f->numparams = 0;
    f->is_vararg = 0;
    f->maxstacksize = 0;
    f->lineinfo = 0;
    f->sizelocvars = 0;
    f->locvars = 0;
    f->lineDefined = 0;
    f->source = 0;
    return f;
}
