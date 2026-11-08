// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_003397c0 @ 0x003397c0
// errfile: "cannot read <file name>: <strerror(errno)>" in place of the chunk name.
#include "decls/data/lua.h"
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" int* __cdecl FUN_00347ba4();               // _errno
extern "C" const char* __cdecl FUN_00347b53(int);     // strerror
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00212de0(LuaVMState* L, int idx);

// equiv-conv: FUN_003397c0 edi ebx
extern "C" int __cdecl FUN_003397c0(LuaVMState* L, int fnameindex)
{
    const char* filename = FUN_00213190(L, fnameindex) + 1;
    int code = *FUN_00347ba4();
    const char* description = FUN_00347b53(code);
    FUN_00213470(L, "cannot read %s: %s", filename, description);
    FUN_00212de0(L, fnameindex);
    return 2;
}
