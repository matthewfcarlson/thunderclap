// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// luaD_callhook: call the debug hook (a lua_Debug on the stack) with LUA_MINSTACK slots and hooks off.
// cl-flags: /GS
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

extern "C" void __cdecl FUN_00215520(LuaVMState* L, int event, int line) {
    LuaVMHook hook = L->hook;
    if (hook && L->allowhook) {
        int top = (int)((char*)L->top - (char*)L->stack);
        int ci_top = (int)((char*)L->ci->top - (char*)L->stack);
        LuaVMDebug ar;
        ar.event = event;
        ar.currentline = line;
        ar.i_ci = event == 4 ? 0 : (int)(L->ci - L->base_ci);
        if ((char*)L->stack_last - (char*)L->top <= 20 * (int)sizeof(LuaVMTObject))
            FUN_00215460(L, 20);
        L->ci->top = L->top + 20;
        L->allowhook = 0;
        hook(L, &ar);
        L->allowhook = 1;
        L->ci->top = (LuaVMTObject*)((char*)L->stack + ci_top);
        L->top = (LuaVMTObject*)((char*)L->stack + top);
    }
}
