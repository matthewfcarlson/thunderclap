// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 6/6)
// funcname: name {. name} [: name]; returns 1 for a method (needself).
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021c790(LuaVMFuncState* fs, LuaVMString* n, LuaVMExpDesc* var, int base);
// equiv-conv: FUN_0021ccb0 eax ebx
extern "C" void FUN_0021ccb0(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021f220 ecx eax
extern "C" int FUN_0021f220(LuaVMLexState* ls, LuaVMExpDesc* v) {
    LuaVMString* name = FUN_0021c3d0(ls);
    FUN_0021c790(ls->fs, name, v, 1);
    while (ls->t.token == 0x2e)
        FUN_0021ccb0(ls, v);
    if (ls->t.token == 0x3a) {
        FUN_0021ccb0(ls, v);
        return 1;
    }
    return 0;
}
