// STATUS: equivalent (tools/equiv.py level 3: 2951 inputs, branch coverage 8/8)
// luaG_typeerror: "attempt to <op> <kind> `<name>' (a <type> value)" when o is a named stack value, else the short form.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

// equiv-conv: FUN_002146f0 eax stack stack
extern "C" const char* __cdecl FUN_002146f0(unsigned reg, LuaVMCallInfo* ci, const char** name);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);

extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op)
{
    const char* typeName = DAT_00426948[o->tt];
    const char* name = 0;

    for (const LuaVMTObject* p = L->ci->base; p < L->ci->top; ++p) {
        if (p == o) {
            const char* kind = FUN_002146f0((unsigned)(o - L->base), L->ci, &name);
            if (kind != 0) {
                FUN_00214a90(L, "attempt to %s %s `%s' (a %s value)", op, kind, name, typeName);
                return;
            }
            break;
        }
    }
    FUN_00214a90(L, "attempt to %s a %s value", op, typeName);
}
