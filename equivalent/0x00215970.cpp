// STATUS: equivalent (tools/equiv.py level 3: 2578 inputs, branch coverage 12/12)
// luaD_poscall: leave the call: move up to wanted results down to the function's slot (nil-padded).
#include "decls/data/lua.h"

// equiv-conv: FUN_00215910 eax esi
extern "C" LuaVMTObject* __cdecl FUN_00215910(LuaVMTObject* firstResult, LuaVMState* L);

extern "C" void __cdecl FUN_00215970(LuaVMState* L, int wanted, LuaVMTObject* firstResult) {
    if (L->hookmask & 2)
        firstResult = FUN_00215910(firstResult, L);
    LuaVMCallInfo* ci = L->ci - 1;
    LuaVMTObject* res = L->base - 1;
    L->ci = ci;
    L->base = ci->base;
    if (wanted != 0) {
        do {
            if (firstResult >= L->top)
                break;
            LUAVM_SETOBJ(res, firstResult);
            firstResult++;
            res++;
            wanted--;
        } while (wanted != 0);
        if (wanted > 0) {
            do {
                res->tt = LUAVM_TNIL;
                res++;
                wanted--;
            } while (wanted != 0);
        }
    }
    L->top = res;
}
