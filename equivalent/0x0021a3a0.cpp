// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// rehash: resize a table to the sizes its use asks for.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00219a60(const LuaVMTable* t, int* narray, int* nhash);
extern "C" int __cdecl FUN_00215f70(unsigned int x);
// equiv-conv: FUN_0021a0f0 eax ecx stack stack
extern "C" void __cdecl FUN_0021a0f0(int nasize, LuaVMTable* t, LuaVMState* L, int lsize);

// equiv-conv: FUN_0021a3a0 esi stack
extern "C" void __cdecl FUN_0021a3a0(LuaVMTable* t, LuaVMState* L) {
    int nhsize;
    int nasize;
    FUN_00219a60(t, &nasize, &nhsize);
    int lsize = FUN_00215f70((unsigned int)nhsize);
    FUN_0021a0f0(nasize, t, L, lsize + 1);
}
