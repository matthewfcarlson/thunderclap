// luaF_newupval: a closed upvalue holding nil.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);

extern "C" LuaVMUpVal* __cdecl FUN_002195d0(LuaVMState* L) {
    LuaVMUpVal* uv = (LuaVMUpVal*)FUN_0021add0(L, 0, 0, sizeof(LuaVMUpVal));
    FUN_00217130(L, (LuaVMGCObject*)uv, LUAVM_TUPVAL);
    uv->v = &uv->value;
    uv->value.tt = LUAVM_TNIL;
    return uv;
}
