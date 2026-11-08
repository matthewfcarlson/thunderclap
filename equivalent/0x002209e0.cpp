// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaK_numberK: the constant index of number r.
#include "decls/data/lua.h"

// equiv-conv: FUN_002208e0 ebx ecx stack
extern "C" int __cdecl FUN_002208e0(LuaVMFuncState* fs, LuaVMTObject* k, LuaVMTObject* v);

extern "C" int __cdecl FUN_002209e0(LuaVMFuncState* fs, float r) {
    LuaVMTObject o;
    o.tt = LUAVM_TNUMBER;
    o.value.n = r;
    return FUN_002208e0(fs, &o, &o);
}
