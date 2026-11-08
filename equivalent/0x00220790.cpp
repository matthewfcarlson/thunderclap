// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaK_dischargejpc: patch the pending jumps to the current pc.
#include "decls/data/lua.h"

// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00220650(int list, LuaVMFuncState* fs, int ttarget, int treg, int ftarget, int freg,
                                     int dtarget);

// equiv-conv: FUN_00220790 eax
extern "C" void __cdecl FUN_00220790(LuaVMFuncState* fs) {
    int pc = fs->pc;
    int jpc = fs->jpc;
    FUN_00220650(jpc, fs, pc, 0xff, pc, 0xff, pc);
    fs->jpc = -1;
}
