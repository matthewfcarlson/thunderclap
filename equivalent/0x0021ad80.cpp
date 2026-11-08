// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaU_dump: dump a function as a precompiled chunk through w.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021acc0 esi
extern "C" void __cdecl FUN_0021acc0(LuaVMDumpState* D);
extern "C" void __cdecl FUN_0021ab30(const LuaVMProto* f, const LuaVMString* p, LuaVMDumpState* D);

extern "C" int __cdecl FUN_0021ad80(LuaVMState* L, const LuaVMProto* f, LuaVMWriter w, void* data, int strip) {
    LuaVMDumpState D;
    D.L = L;
    D.writer = w;
    D.data = data;
    D.strip = strip;
    FUN_0021acc0(&D);
    FUN_0021ab30(f, 0, &D);
    return 1;
}
