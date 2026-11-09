// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001d4460 @ 0x001d4460
// cl-flags: /GS
#include "decls/data/script.h"
// ScriptCallArgs (include/decls/data/script.h) with 0x001d1630's constructor.
struct Request : public ScriptCallArgs {
    void FUN_001d1630();
};
extern "C" int __cdecl FUN_000964a0(char*, int, const char*, ...);
// sh_CallFuncInGlobalState (bound by 0x001d4830 through 0x001d46d0): calls the global Lua function `function` with
// three string arguments on the handler's state.
struct Owner_1d4460 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d2190(const char*, ScriptCallArgs, LuaVMState*);
    void FUN_001d4460(const char* function, const char* a, const char* b, const char* c);
};
void Owner_1d4460::FUN_001d4460(const char* function, const char* a, const char* b, const char* c) {
    Request request;
    request.FUN_001d1630();
    request.count = 3;
    FUN_000964a0(request.strings[0], 64, "%s", a);
    FUN_000964a0(request.strings[1], 64, "%s", b);
    FUN_000964a0(request.strings[2], 64, "%s", c);
    FUN_001d2190(function, request, L);
}
