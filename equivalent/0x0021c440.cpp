// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// codestring: e = a string constant (VK) of s.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s);
// equiv-conv: FUN_0021c440 ecx eax esi
extern "C" void FUN_0021c440(LuaVMLexState* ls, LuaVMString* s, LuaVMExpDesc* e) {
    int info = FUN_002209b0(ls->fs, s);
    e->t = -1;
    e->f = -1;
    e->k = 4; // VK
    e->info = info;
}
