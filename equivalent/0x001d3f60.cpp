// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 13/16, incomplete)
// FUN_001d3f60 @ 0x001d3f60
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;

struct LuaState;

int __cdecl FUN_000964a0(char *buffer, int size, const char *format, ...);
void __cdecl FUN_00212d80(LuaState *L, int index);
int __cdecl FUN_00212d70(LuaState *L);
int __cdecl FUN_00339a60(LuaState *L, const char *buffer, int size, const char *name);
int __cdecl FUN_002139f0(LuaState *L, int nargs, int nresults, int errfunc);

class ScriptHandler {
public:
    char pad0[4];
    int status;
    LuaState *L;
    char pad0c[0x1068 - 0xc];
    int count;
    char names[256][64];
    float values[256];

    void FUN_001d3f60();
};

struct Frame_1d3f60 {
    int top;
    char buf[0x100];
    unsigned int pad[1];
    volatile unsigned int cookie;
};

void ScriptHandler::FUN_001d3f60()
{
    Frame_1d3f60 f;
    f.cookie = DAT_004d9968;
    for (int i = 0; i < count; i++) {
        char *buf = f.buf;
        FUN_000964a0(buf, 0x100, "%s = %f", names[i], (double)values[i]);
        FUN_00212d80(L, 0);

        const char *p = buf;
        while (*p++ != 0)
            ;
        int len = (int)(p - (buf + 1));
        LuaState *state = L;
        f.top = FUN_00212d70(state);
        int err = FUN_00339a60(state, buf, len, "=ScriptHandler::DoLuaBuffer");
        if (err == 0)
            err = FUN_002139f0(state, 0, -1, 0);
        if (err != 0)
            FUN_00212d80(state, f.top);
        status = (err == 0) ? 3 : 0;
    }
    __security_check_cookie(f.cookie);
}
