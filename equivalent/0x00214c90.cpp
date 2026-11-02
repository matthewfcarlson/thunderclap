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
extern "C" const char * __cdecl FUN_002146f0(unsigned, void *, char **);
void __cdecl FUN_00214a90(lua_State_214c90* L, const char* fmt, ...);   // luaG_runerror

extern "C" void __cdecl FUN_00214c90(void * L, const void * o, const char* op)
{
    const char* typeName = ((const char**)&DAT_00426948)[((const TObject_214c90 *)o)->tt];
    const char* name = 0;

    for (const TObject_214c90* p = ((lua_State_214c90 *)L)->ci->base; p < ((lua_State_214c90 *)L)->ci->top; ++p) {
        if (p == ((const TObject_214c90 *)o)) {
            const char* kind = FUN_002146f0((hulk_uintptr)(((const TObject_214c90 *)o) - ((lua_State_214c90 *)L)->base), (CallInfo_214c90 *)(((lua_State_214c90 *)L)->ci), (char **)(const char * *)(&name));
            if (kind != 0) {
                FUN_00214a90(((lua_State_214c90 *)L), "attempt to %s %s `%s' (a %s value)", op, kind, name, typeName);
                return;
            }
            break;
        }
    }
    FUN_00214a90(((lua_State_214c90 *)L), "attempt to %s a %s value", op, typeName);
}
