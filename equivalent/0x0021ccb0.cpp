// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// field: v.name (v into a register, the name as a string constant key, VINDEXED).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls);
extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s);
extern "C" void __cdecl FUN_002216e0(LuaVMFuncState* fs, LuaVMExpDesc* t, LuaVMExpDesc* k);

// equiv-conv: FUN_0021ccb0 eax ebx
extern "C" void FUN_0021ccb0(LuaVMLexState* ls, LuaVMExpDesc* v) {
    LuaVMFuncState* fs = ls->fs;
    FUN_00221190(fs, v);
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    LuaVMExpDesc key;
    LuaVMString* name = FUN_0021c3d0(ls);
    key.info = FUN_002209b0(ls->fs, name);
    key.k = 4; // VK
    key.t = -1;
    key.f = -1;
    FUN_002216e0(fs, v, &key);
}
