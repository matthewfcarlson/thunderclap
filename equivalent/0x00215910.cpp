// STATUS: equivalent (tools/equiv.py level 3: 2981 inputs, branch coverage 6/6)
// callrethooks: the return hook (and one tail-return hook per tail call of a Lua function); the results may move.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215520(LuaVMState* L, int event, int line);

// equiv-conv: FUN_00215910 eax esi
extern "C" LuaVMTObject* __cdecl FUN_00215910(LuaVMTObject* firstResult, LuaVMState* L) {
    int fr = (int)((char*)firstResult - (char*)L->stack);
    FUN_00215520(L, 1, -1);
    LuaVMClosure* cl = (LuaVMClosure*)(L->ci->base - 1)->value.gc;
    if (!cl->c.isC) {
        while (L->ci->tailcalls != 0) {
            --L->ci->tailcalls;
            FUN_00215520(L, 4, -1);
        }
        --L->ci->tailcalls;
    }
    return (LuaVMTObject*)((char*)L->stack + fr);
}
