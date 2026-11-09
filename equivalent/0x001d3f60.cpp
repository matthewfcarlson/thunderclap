// STATUS: equivalent (tools/equiv.py level 3: 6847 inputs, branch coverage 13/16, incomplete)
// FUN_001d3f60 @ 0x001d3f60
// cl-flags: /GS
#include "decls/data/script.h"



int __cdecl FUN_000964a0(char *buffer, int size, const char *format, ...);
void __cdecl FUN_00212d80(LuaVMState *L, int index);
int __cdecl FUN_00212d70(LuaVMState *L);
int __cdecl FUN_00339a60(LuaVMState *L, const char *buffer, int size, const char *name);
int __cdecl FUN_002139f0(LuaVMState *L, int nargs, int nresults, int errfunc);

class ScriptHandler : public ScriptHandlerFields {
public:
    virtual void v0();

    void FUN_001d3f60();
};

struct Frame_1d3f60 {
    int top;
    char buf[0x100];
    unsigned int pad[1];
};

void ScriptHandler::FUN_001d3f60()
{
    Frame_1d3f60 f;
    for (int i = 0; i < watches.count; i++) {
        char *buf = f.buf;
        FUN_000964a0(buf, 0x100, "%s = %f", watches.names[i], (double)watches.values[i]);
        FUN_00212d80(L, 0);

        const char *p = buf;
        while (*p++ != 0)
            ;
        int len = (int)(p - (buf + 1));
        LuaVMState *state = L;
        f.top = FUN_00212d70(state);
        int err = FUN_00339a60(state, buf, len, "=ScriptHandler::DoLuaBuffer");
        if (err == 0)
            err = FUN_002139f0(state, 0, -1, 0);
        if (err != 0)
            FUN_00212d80(state, f.top);
        status = (err == 0) ? 3 : 0;
    }
}
