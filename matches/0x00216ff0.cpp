// remarkupvals: mark the values of the gray open upvalues of the white threads.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);

extern "C" void __cdecl FUN_00216ff0(LuaVMGlobal* g) {
    LuaVMGCObject* o = (LuaVMGCObject*)g->mainthread;
    while (o) {
        if (o->marked & 3) {
            LuaVMGCObject* curr = ((LuaVMState*)o)->openupval;
            while (curr) {
                if ((curr->marked & 7) == 0) {
                    LuaVMTObject* v = ((LuaVMUpVal*)curr)->v;
                    if (v->tt >= LUAVM_TSTRING) {
                        LuaVMGCObject* gc = v->value.gc;
                        if (gc->marked & 3)
                            FUN_002164b0(g, gc);
                    }
                }
                curr = curr->next;
            }
        }
        o = o->next;
    }
}
