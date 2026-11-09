// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 4/4)
// FUN_001d3f00 @ 0x001d3f00
#include "decls/data/script.h"
extern "C" void __cdecl FUN_00212d80(LuaVMState *, int);
struct ScriptHandler_1d3f00 : public ScriptHandlerFields {
    virtual void v0();
    int FUN_001d2810(LuaVMState *, const char *, int, const char *);
    void FUN_001d3f00(const char *text, const char *value);
};
void ScriptHandler_1d3f00::FUN_001d3f00(const char *text, const char *value) {
    FUN_00212d80(L, 0);
    const char *end = text;
    while (*end) ++end;
    if (FUN_001d2810(L, text, (int)(end - text), value))
        status = 0;
    else
        status = 3;
}