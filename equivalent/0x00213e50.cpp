// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 15/16, incomplete)
// lua_setupvalue: pop the top value into upvalue n of the function at funcindex (the write barrier); its name or NULL.
#include "decls/data/lua.h"
#include "decls/data/game/global.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" const char* __cdecl FUN_00213e50(LuaVMState* L, int funcindex, int n) {
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
        name = LUAVM_GETSTR(p->upvalues[n - 1]);
        val = f->l.upvals[n - 1]->v;
        if (name == 0)
            return 0;
    }

    L->top--;
    *val = *L->top;
    if (L->top->tt >= LUAVM_TSTRING) {
        LuaVMGCObject* o = L->top->value.gc;
        if ((o->marked & 3) != 0 && (fi->value.gc->marked & 4) != 0)
            FUN_00217100(L, fi->value.gc, o);
    }
    return name;
}
