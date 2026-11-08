// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// nilK: the constant index of nil (keyed by the constant table itself).
#include "decls/data/lua.h"

// equiv-conv: FUN_002208e0 ebx ecx stack
extern "C" int __cdecl FUN_002208e0(LuaVMFuncState* fs, LuaVMTObject* k, LuaVMTObject* v);

// equiv-conv: FUN_00220a10 eax
extern "C" int __cdecl FUN_00220a10(LuaVMFuncState* fs) {
    LuaVMTObject o[2];
    o[0].tt = LUAVM_TTABLE;
    o[0].value.gc = (LuaVMGCObject*)fs->h;
    o[1].tt = LUAVM_TNIL;
    return FUN_002208e0(fs, &o[0], &o[1]);
}
