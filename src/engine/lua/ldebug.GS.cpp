// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00213f20..0x00214dd0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_ff752106 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff752106 {} using namespace fn_ff752106;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_ff752106 {
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);


// 0x00214900 FUN_00214900 (165 B): equivalent/0x00214900.cpp
// sym: _FUN_00214900 @7908035f0142 @wb01d7def6a8d
// STATUS: equivalent (tools/equiv.py level 3: 3091 inputs, branch coverage 12/16, incomplete)
// addinfo: prefix "chunk:line: " to msg (pushed) when the running function is a Lua function.
// equiv-conv: FUN_00214900 ebx stack
extern "C" void FUN_00214900(LuaVMState* L, const char* msg)
{
    struct Frame {
        char buff[60];
    } fr;
    LuaVMCallInfo* ci = L->ci;
    LuaVMTObject* func = ci->base - 1;
    if (func->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)func->value.gc)->c.isC == 0) {
        LuaVMProto* p = ((LuaVMClosure*)func->value.gc)->l.p;
        int pc = (int)(ci->savedpc - p->code) - 1;
        int line;
        if (pc < 0)
            line = -1;
        else if (p->lineinfo != 0)
            line = p->lineinfo[pc];
        else
            line = 0;
        FUN_00216340(fr.buff, LUAVM_GETSTR(p->source), 60);
        FUN_00216320(L, "%s:%d: %s", fr.buff, line, msg);
    }
}

} // namespace fn_ff752106
