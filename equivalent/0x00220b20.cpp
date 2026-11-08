// STATUS: equivalent (tools/equiv.py level 3: 2760 inputs, branch coverage 4/4)
// luaK_code: discharge the pending jumps, then append instruction i (and its line).
#include "decls/data/lua.h"

// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00220650(int list, LuaVMFuncState* fs, int ttarget, int treg, int ftarget, int freg,
                                     int dtarget);
extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elem, int limit,
                                      const char* errormsg);

extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line) {
    LuaVMProto* f = fs->f;
    int pc = fs->pc;
    FUN_00220650(fs->jpc, fs, pc, 255, pc, 255, pc);
    fs->jpc = -1;
    if (fs->pc + 1 > f->sizecode)
        f->code = (LuaVMInstruction*)FUN_0021ae40(fs->L, f->code, &f->sizecode, (int)sizeof(LuaVMInstruction),
                                                  0x7ffffffd, "code size overflow");
    f->code[fs->pc] = i;
    if (fs->pc + 1 > f->sizelineinfo)
        f->lineinfo = (int*)FUN_0021ae40(fs->L, f->lineinfo, &f->sizelineinfo, (int)sizeof(int), 0x7ffffffd,
                                         "code size overflow");
    f->lineinfo[fs->pc] = line;
    int result = fs->pc;
    fs->pc = result + 1;
    return result;
}
