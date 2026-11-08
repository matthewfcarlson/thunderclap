// STATUS: equivalent (tools/equiv.py level 3: 2124 inputs, branch coverage 24/24)
// luaV_settable: t[key] = val (with the barrier), following __newindex (a table or a function) up to 100 times.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);
extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

extern "C" void __cdecl FUN_00217980(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val) {
    for (int loop = 0; loop < 100; loop++) {
        const LuaVMTObject* tm;
        if (t->tt == LUAVM_TTABLE) {
            LuaVMTable* h = (LuaVMTable*)t->value.gc;
            LuaVMTObject* oldval = FUN_00219ef0(L, h, key);
            LuaVMTable* mt;
            tm = 0;
            if (oldval->tt != LUAVM_TNIL || (mt = h->metatable) == 0 || (mt->flags & 2) != 0 ||
                (tm = FUN_00217580(mt, 1, L->l_G->tmname[1])) == 0) {
                *oldval = *val;
                if (val->tt >= LUAVM_TSTRING && (val->value.gc->marked & 3) != 0 && (h->marked & 4) != 0)
                    FUN_00217100(L, (LuaVMGCObject*)h, val->value.gc);
                return;
            }
        } else {
            tm = FUN_002175b0(L, t, 1);
            if (tm->tt == LUAVM_TNIL)
                FUN_00214c90(L, t, "index");
        }
        if (tm->tt == LUAVM_TFUNCTION) {
            L->top[0] = *tm;
            L->top[1] = *t;
            L->top[2] = *key;
            L->top[3] = *val;
            if ((char*)L->stack_last - (char*)L->top <= 4 * (int)sizeof(LuaVMTObject))
                FUN_00215460(L, 4);
            LuaVMTObject* func = L->top;
            L->top = func + 4;
            FUN_002159e0(L, func, 0);
            return;
        }
        t = tm;
    }
    FUN_00214a90(L, "loop in settable");
}
