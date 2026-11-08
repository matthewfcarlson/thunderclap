// luaF_newLclosure: a Lua closure with nelems (cleared) upvalue pointers and the globals table e.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);

extern "C" LuaVMClosure* __cdecl FUN_00219560(LuaVMState* L, int nelems, const LuaVMTObject* e) {
    int size = LUAVM_SIZELCLOSURE(nelems);
    LuaVMClosure* c = (LuaVMClosure*)FUN_0021add0(L, 0, 0, size);
    FUN_00217130(L, (LuaVMGCObject*)c, LUAVM_TFUNCTION);
    c->l.isC = 0;
    LUAVM_SETOBJ(&c->l.g, e);
    c->l.nupvalues = (unsigned char)nelems;
    if (nelems != 0) {
        LuaVMUpVal** p = c->l.upvals + nelems;
        do {
            --p;
            --nelems;
            *p = 0;
        } while (nelems != 0);
    }
    return c;
}
