// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// lua_replace: pop the top value into idx (the write barrier for a C upvalue).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" void __cdecl FUN_00212e60(LuaVMState* L, int idx) {
    LuaVMTObject* src = L->top - 1;
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    *o = *src;
    if (idx < -10001) {
        if (L->top[-1].tt >= LUAVM_TSTRING) {
            LuaVMGCObject* v = L->top[-1].value.gc;
            if ((v->marked & 3) != 0) {
                LuaVMGCObject* f = L->base[-1].value.gc;
                if ((f->marked & 4) != 0)
                    FUN_00217100(L, f, v);
            }
        }
    }
    L->top--;
}
