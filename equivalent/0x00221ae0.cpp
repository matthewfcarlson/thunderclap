// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2)
// luaK_patchlist: patch the list to target (to the pending jumps when target is the current pc).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00220650(int list, LuaVMFuncState* fs, int ttarget, int treg, int ftarget, int freg,
                                     int dtarget);

extern "C" void __cdecl FUN_00221ae0(LuaVMFuncState* fs, int list, int target) {
    if (target == fs->pc) {
        fs->lasttarget = fs->pc;
        FUN_002207c0(fs, &fs->jpc, list);
    } else {
        FUN_00220650(list, fs, target, 0xff, target, 0xff, target);
    }
}
