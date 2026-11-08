// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 20/20)
// traverseclosure: mark a C closure's upvalues, or a Lua closure's globals table, prototype and upvalues.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);

// equiv-conv: FUN_002168d0 esi stack
extern "C" void __cdecl FUN_002168d0(LuaVMClosure* cl, LuaVMGlobal* g) {
    if (cl->c.isC) {
        for (int i = 0; i < cl->c.nupvalues; ++i) {
            LuaVMTObject* o = &cl->c.upvalue[i];
            if (o->tt >= LUAVM_TSTRING && (o->value.gc->marked & 3))
                FUN_002164b0(g, o->value.gc);
        }
    } else {
        LuaVMGCObject* o = cl->l.g.value.gc;
        if (o->marked & 3)
            FUN_002164b0(g, o);
        o = (LuaVMGCObject*)cl->l.p;
        if (o->marked & 3)
            FUN_002164b0(g, o);
        for (int i = 0; i < cl->l.nupvalues; ++i) {
            o = (LuaVMGCObject*)cl->l.upvals[i];
            if (o->marked & 3)
                FUN_002164b0(g, o);
        }
    }
}
