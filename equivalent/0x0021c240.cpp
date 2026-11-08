// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 2/2)
// errorlimit: "main function has more than N what" / "function at line L has more than N what" as a lexer error.
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
// equiv-conv: FUN_0021c240 esi ecx edx
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit) {
    if (fs->f->lineDefined == 0) {
        const char* msg = FUN_00216320(fs->L, "main function has more than %d %s", limit, what);
        FUN_0021afd0(fs->ls, msg, 0);
    } else {
        const char* msg =
            FUN_00216320(fs->L, "function at line %d has more than %d %s", fs->f->lineDefined, limit, what);
        FUN_0021afd0(fs->ls, msg, 0);
    }
}
