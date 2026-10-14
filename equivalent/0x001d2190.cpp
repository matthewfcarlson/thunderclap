// STATUS: equivalent (tools/equiv.py level 3: 20044 inputs, branch coverage 20/20)
// FUN_001d2190 @ 0x001d2190
struct lua_State;

extern void __cdecl FUN_002133d0(lua_State *L, const char *s);
extern void __cdecl FUN_00213340(lua_State *L, int value);
extern void __cdecl FUN_00213570(lua_State *L, int index);
extern void __cdecl FUN_002135a0(lua_State *L, int index, const char *key);
extern int __cdecl FUN_00212f00(lua_State *L, int index);
extern void __cdecl FUN_00212d80(lua_State *L, int index);
extern int __cdecl FUN_002139f0(lua_State *L, int nargs, int nresults, int errfunc);

// A call description passed by value: function name, argument count and up to ten typed arguments.
struct ScriptCall {
    const char *function;
    int count;
    char strings[10][0x40];
    int numbers[10];
    char types[12];
    lua_State *L;
};

class ScriptRunner {
public:
    char pad00[4];
    int status;

    int FUN_001d2190(ScriptCall call);
};

// Calls a global Lua function with the 's' / 'f' / 'b' / 'i' typed arguments of `call`.
// Returns the new status: 0 when the function is missing or an argument type is unknown, 3 on
// a Lua error, 0 on success.
int ScriptRunner::FUN_001d2190(ScriptCall call)
{
    lua_State *L = call.L;
    const char *name = call.function;
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
