// luaK_patchtohere: getlabel, then add the list to the pending jumps.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);

extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list) {
    fs->lasttarget = fs->pc;
    FUN_002207c0(fs, &fs->jpc, list);
}
