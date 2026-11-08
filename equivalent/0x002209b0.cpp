// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaK_stringK: the constant index of string s.
#include "decls/data/lua.h"

// equiv-conv: FUN_002208e0 ebx ecx stack
extern "C" int __cdecl FUN_002208e0(LuaVMFuncState* fs, LuaVMTObject* k, LuaVMTObject* v);

extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s) {
    LuaVMTObject o;
    o.tt = LUAVM_TSTRING;
    o.value.gc = (LuaVMGCObject*)s;
    return FUN_002208e0(fs, &o, &o);
}
