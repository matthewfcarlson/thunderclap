// luaC_linkupval: put a closed upvalue on the root list; a gray one turns black (with the barrier) or white.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" void __cdecl FUN_00217160(LuaVMState* L, LuaVMUpVal* uv) {
    LuaVMGlobal* g = L->l_G;
    LuaVMGCObject* o = (LuaVMGCObject*)uv;
    o->next = g->rootgc;
    g->rootgc = o;
    unsigned char b = uv->marked;
    if ((b & 7) == 0) {
        if (g->gcstate == 0) {
            uv->marked = b | 4;
            LuaVMTObject* v = uv->v;
            if (v->tt >= LUAVM_TSTRING) {
                LuaVMGCObject* gc = v->value.gc;
                if ((gc->marked & 3) != 0 && (uv->marked & 4))
                    FUN_00217100(L, o, gc);
            }
        } else
            uv->marked = (b & 0xf8) | (unsigned char)g->currentwhite;
    }
}
