// STATUS: equivalent (tools/equiv.py level 3: 2137 inputs, branch coverage 18/18)
// luaV_gettable: t[key] into val, following __index (a table or a function) up to 100 times.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);
extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);
extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

extern "C" void __cdecl FUN_00217830(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val) {
    for (int loop = 0; loop < 100; ++loop) {
        const LuaVMTObject* tm = 0;
        if (t->tt == LUAVM_TTABLE) {
            LuaVMTable* h = (LuaVMTable*)t->value.gc;
            const LuaVMTObject* res = FUN_00219e90(h, key);
            if (res->tt == LUAVM_TNIL) {
                LuaVMTable* mt = h->metatable;
                if (mt && !(mt->flags & 1))
                    tm = FUN_00217580(mt, 0, L->l_G->tmname[0]);
            }
            if (!tm) {
                *val = *res;
                return;
            }
        } else {
            tm = FUN_002175b0(L, t, 0);
            if (tm->tt == LUAVM_TNIL)
                FUN_00214c90(L, t, "index");
        }

        if (tm->tt == LUAVM_TFUNCTION) {
            L->top[0] = *tm;
            L->top[1] = *t;
            L->top[2] = *key;
            hulk_intptr result = (char*)val - (char*)L->stack;  // callTMres, inlined
            if ((char*)L->stack_last - (char*)L->top <= 3 * (int)sizeof(LuaVMTObject))
                FUN_00215460(L, 3);
            L->top += 3;
            FUN_002159e0(L, L->top - 3, 1);
            L->top -= 1;
            LuaVMTObject* dst = (LuaVMTObject*)((char*)L->stack + result);
            *dst = *L->top;
            return;
        }
        t = tm;
    }
    FUN_00214a90(L, "loop in gettable");
}
