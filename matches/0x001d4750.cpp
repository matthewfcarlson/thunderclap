#include "compat/ptr.h"
#include "decls/data/script.h"
#include "gen/owners.h"
#include "decls/data/records.h"
extern "C" void* __cdecl FUN_0008d690(int x);
extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
inline void* operator new(hulk_uintptr, void* p) throw() {
    return p;
}
// Closure1<ScriptHandler, ScriptHandler::script_state, const char*> (include/decls/data/script.h): Function's fields, the member-function pointer, the object.
class ScriptHandler_1d4750 {
  public:
    enum script_state { s0 };
};
typedef ScriptHandler_1d4750::script_state (ScriptHandler_1d4750::*Fn_1d4750)(const char*);
// 0x001d4320 (matches/0x001d4320.cpp): the closure's constructor (name, object, member function).
class Closure1 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d4750 fn;
    ScriptHandler_1d4750* owner;
    Closure1(const char* name, ScriptHandler_1d4750* object, Fn_1d4750 fn);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// ScriptHandler::AddFunction for this closure type (no caller: 0x001d4830 inlines it).
struct Owner_1d4750 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d4750(const char* a, ScriptHandler_1d4750* b, Fn_1d4750 c);
};
void Owner_1d4750::FUN_001d4750(const char* a, ScriptHandler_1d4750* b, Fn_1d4750 c) {
    HULK_SIZE32(Closure1, 0x24);
    Closure1* n = new (FUN_0008d690((int)sizeof(Closure1))) Closure1(a, b, c);
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&functions)->FUN_001d1180((ScriptFunctionView*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
