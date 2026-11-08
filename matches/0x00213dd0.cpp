// lua_getupvalue: push upvalue n of the function at funcindex; its name ("" for a C function) or NULL.
#include "decls/data/lua.h"
#include "decls/data/game/global.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" const char* __cdecl FUN_00213dd0(LuaVMState* L, int funcindex, int n) {
    LuaVMTObject* fi = FUN_00212bb0(funcindex, L);
    if (fi->tt != LUAVM_TFUNCTION)
        return 0;
    LuaVMClosure* f = (LuaVMClosure*)fi->value.gc;
    LuaVMTObject* val;
    const char* name;
    if (f->c.isC) {
        if (n > f->c.nupvalues)
            return 0;
        val = &f->c.upvalue[n - 1];
        name = (const char*)&DAT_003f335c;
    } else {
        LuaVMProto* p = f->l.p;
        if (n > p->sizeupvalues)
            return 0;
        val = f->l.upvals[n - 1]->v;
        name = LUAVM_GETSTR(p->upvalues[n - 1]);
    }
    if (name) {
        LuaVMTObject* o = L->top;
        o->tt = val->tt;
        o->value = val->value;
        L->top++;
    }
    return name;
}
