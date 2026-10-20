// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 8/8)
// FUN_00214c90 @ 0x00214c90
// Lua 5.0 luaG_typeerror(L, o, op): "attempt to <op> <kind> `<name>' (a <type> value)".
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

struct TObject_214c90 {
    int tt;
    int value;
};

struct CallInfo_214c90 {
    TObject_214c90* base;
    TObject_214c90* top;
};

struct lua_State_214c90 {
    char pad0[0xc];
    TObject_214c90* base;
    char pad10[4];
    CallInfo_214c90* ci;
};

                      // luaT_typenames

// equiv-conv: FUN_002146f0 eax stack stack
const char* __cdecl FUN_002146f0(hulk_uintptr reg, CallInfo_214c90* ci, const char** name);
void __cdecl FUN_00214a90(lua_State_214c90* L, const char* fmt, ...);   // luaG_runerror

void __cdecl FUN_00214c90(lua_State_214c90* L, const TObject_214c90* o, const char* op)
{
    const char* typeName = ((const char**)&DAT_00426948)[o->tt];
    const char* name = 0;

    for (const TObject_214c90* p = L->ci->base; p < L->ci->top; ++p) {
        if (p == o) {
            const char* kind = FUN_002146f0(o - L->base, L->ci, &name);
            if (kind != 0) {
                FUN_00214a90(L, "attempt to %s %s `%s' (a %s value)", op, kind, name, typeName);
                return;
            }
            break;
        }
    }
    FUN_00214a90(L, "attempt to %s a %s value", op, typeName);
}
