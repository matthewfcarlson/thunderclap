// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// FUN_0033a740 @ 0x0033a740
// gethooktable: pushes registry[KEY_HOOK] (created on first use).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_00213550(LuaVMState *, void *);
extern "C" void __cdecl FUN_00213600(LuaVMState *, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState *, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState *, int);
extern "C" void __cdecl FUN_00213680(LuaVMState *, int, int);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *, int);
extern "C" void __cdecl FUN_00213800(LuaVMState *, int);
// equiv-conv: FUN_0033a740 esi
extern "C" void __cdecl FUN_0033a740(LuaVMState *context)
{
    FUN_00213550(context, ((void*)&DAT_00434708));
    FUN_00213600(context, -10000);
    if (FUN_00212f00(context, -1) != 5) {
        FUN_00212d80(context, -2);
        FUN_00213680(context, 0, 0);
        FUN_00213550(context, ((void*)&DAT_00434708));
        FUN_00212ed0(context, -2);
        FUN_00213800(context, -10000);
    }
}
