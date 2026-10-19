// STATUS: equivalent (tools/equiv.py level 3: 7688 inputs, branch coverage 17/20, incomplete)
// FUN_001d3960 @ 0x001d3960
// cl-flags: /GS

struct LuaState;

int __cdecl FUN_00212d70(LuaState *L);
void __cdecl FUN_00212d80(LuaState *L, int index);
const char *__cdecl FUN_00213190(LuaState *L, int index);
void __cdecl FUN_00213380(LuaState *L, const char *s, int len);
void __cdecl FUN_002133d0(LuaState *L, const char *s);
void __cdecl FUN_00213600(LuaState *L, int index);
int __cdecl FUN_002139f0(LuaState *L, int a, int b, int c);
int __cdecl FUN_00339a60(LuaState *L, const char *buf, int len, const char *name);

class ScriptHandler {
public:
    char pad0[4];
    int resumeState;         // 0x04
    LuaState *L;             // 0x08
    char FUN_001d1080(const char *name, LuaState *L);
    void FUN_001d10e0(const char *name, LuaState *L);
    int FUN_001d3960();
};

int ScriptHandler::FUN_001d3960()
{
    const char *text = "__RESUME_RC__, __RESUME_ERR__ = coroutine.resume( __THE_SCENARIO_COROUTINE__ )";
    char script[79];
    for (int i = 0; i < 79; i++)
        script[i] = text[i];
    int len = 0;
    while (script[len] != 0)
        len++;

    LuaState *state = L;
    int top = FUN_00212d70(state);
    if (len == -1) {
        len = 0;
        while (script[4 + len] != 0)
            len++;
    }
    int err = FUN_00339a60(state, script, len, "=ScriptHandler::DoLuaBuffer");
    if (err == 0)
        err = FUN_002139f0(state, 0, -1, 0);
    if (err != 0)
        FUN_00212d80(state, top);
    resumeState = (err == 0) ? 3 : 0;

    if (FUN_001d1080("__RESUME_RC__", L)) {
        FUN_00213380(L, "coroutine", 9);
        FUN_00213600(L, -10001);
        FUN_002133d0(L, "status");
        FUN_00213600(L, -2);
        FUN_00213380(L, "__THE_SCENARIO_COROUTINE__", 26);
        FUN_00213600(L, -10001);
        FUN_002139f0(L, 1, 1, 0);
        const char *status = FUN_00213190(L, -1);
        FUN_00212d80(L, -3);

        const char *dead = "dead";
        int differs = 0;
        for (int i = 0; i < 5; i++) {
            if (status[i] != dead[i]) {
                differs = 1;
                break;
            }
        }
        if (differs && resumeState == 3)
            resumeState = 4;
    } else {
        FUN_001d10e0("__RESUME_ERR__", L);
    }
    return resumeState;
}
