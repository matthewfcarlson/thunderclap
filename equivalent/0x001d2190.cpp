// STATUS: equivalent (tools/equiv.py level 3: 3046 inputs, branch coverage 20/20)
// FUN_001d2190 @ 0x001d2190
#include "decls/data/script.h"

extern void __cdecl FUN_002133d0(LuaVMState *L, const char *s);
extern void __cdecl FUN_00213340(LuaVMState *L, float value);
extern "C" void __cdecl FUN_00213570(LuaVMState *L, int index);
extern void __cdecl FUN_002135a0(LuaVMState *L, int index, const char *key);
extern int __cdecl FUN_00212f00(LuaVMState *L, int index);
extern void __cdecl FUN_00212d80(LuaVMState *L, int index);
extern int __cdecl FUN_002139f0(LuaVMState *L, int nargs, int nresults, int errfunc);

// ScriptHandler (include/decls/data/script.h).
class ScriptRunner : public ScriptHandlerFields {
public:
    virtual void v0();
    int FUN_001d2190(const char *function, ScriptCallArgs call, LuaVMState *L);
};
// Calls a global Lua function with the 's' / 'f' / 'b' / 'i' typed arguments of `call` on the state L.
// Returns the new status: 0 when the function is missing or an argument type is unknown, 3 on
// a Lua error, 0 on success.
int ScriptRunner::FUN_001d2190(const char *name, ScriptCallArgs call, LuaVMState *L)
{
    FUN_002133d0(L, name);
    FUN_00213570(L, -10001);
    bool found = FUN_00212f00(L, -1) != 0;
    FUN_00212d80(L, -2);
    if (!found)
        return 0;
    FUN_002135a0(L, -10001, name);
    if (FUN_00212f00(L, -1) != 6) {
        FUN_00212d80(L, -2);
        return 0;
    }
    for (int i = 0; i < call.count; i++) {
        char type = call.types[i];
        if (type == 's') {
            FUN_002133d0(L, call.strings[i]);
        } else if (type == 'f' || type == 'b' || type == 'i') {
            FUN_00213340(L, call.numbers[i]);
        } else {
            FUN_00212d80(L, -2 - i);
            status = 0;
            return status;
        }
    }
    status = FUN_002139f0(L, call.count, 0, 0) == 0 ? 3 : 0;
    return status;
}
