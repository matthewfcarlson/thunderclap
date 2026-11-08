// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 12/12)
// lua_setmetatable: pop the top table (or nil) into the metatable of the table or userdata at objindex.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" int __cdecl FUN_002138e0(LuaVMState* L, int objindex) {
    LuaVMTObject* obj = FUN_00212bb0(objindex, L);
    LuaVMTable* mt = 0;
    if (L->top[-1].tt != LUAVM_TNIL)
        mt = (LuaVMTable*)L->top[-1].value.gc;
    if (obj->tt != LUAVM_TTABLE && obj->tt != LUAVM_TUSERDATA) {
        L->top--;
        return 0;
    }
    ((LuaVMTable*)obj->value.gc)->metatable = mt;  // Udata's metatable is at the same offset
    if (mt != 0 && (mt->marked & 3) != 0 && (obj->value.gc->marked & 4) != 0)
        FUN_00217100(L, obj->value.gc, (LuaVMGCObject*)mt);
    L->top--;
    return 1;
}
