// STATUS: equivalent (tools/equiv.py level 3: 3061 inputs, branch coverage 16/18, incomplete)
// getfuncname: name the function running in ci from the OP_CALL / OP_TAILCALL of its calling Lua function.
#include "decls/data/lua.h"

// equiv-conv: FUN_002146f0 eax stack stack
extern "C" const char* __cdecl FUN_002146f0(unsigned reg, LuaVMCallInfo* ci, const char** name);

// equiv-conv: FUN_00214840 ecx stack
extern "C" const char* __cdecl FUN_00214840(LuaVMCallInfo* ci, const char** name)
{
    LuaVMTObject* func = ci->base - 1;
    if (func->tt == LUAVM_TFUNCTION && !((LuaVMClosure*)func->value.gc)->c.isC && ci->tailcalls > 0) {
        return 0;
    }

    LuaVMCallInfo* caller = ci - 1;
    LuaVMTObject* callerFunc = caller->base - 1;
    if (callerFunc->tt != LUAVM_TFUNCTION || ((LuaVMClosure*)callerFunc->value.gc)->c.isC) {
        return 0;
    }

    int pc;
    callerFunc = caller->base - 1;
    if (callerFunc->tt == LUAVM_TFUNCTION && !((LuaVMClosure*)callerFunc->value.gc)->c.isC) {
        pc = (int)(caller->savedpc - ((LuaVMClosure*)callerFunc->value.gc)->l.p->code) - 1;
    } else {
        pc = -1;
    }

    unsigned instruction = ((LuaVMClosure*)caller->base[-1].value.gc)->l.p->code[pc];
    unsigned op = instruction & 0x3f;
    if (op == 0x19 || op == 0x1a) {
        return FUN_002146f0(instruction >> 24, caller, name);
    }
    return 0;
}
