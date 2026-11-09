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
// Closure1<ScriptHandler, bool, const char*> (include/decls/data/script.h): Function's fields, the member-function pointer, the object.
class ScriptHandler_1d47c0 {
  public:
};
typedef bool (ScriptHandler_1d47c0::*Fn_1d47c0)(const char*);
// 0x001d43b0 (matches/0x001d43b0.cpp): the closure's constructor (name, object, member function).
class Closure1_1d43b0 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d47c0 fn;
    ScriptHandler_1d47c0* owner;
    Closure1_1d43b0(const char* name, ScriptHandler_1d47c0* object, Fn_1d47c0 fn);
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// ScriptHandler::AddFunction for this closure type (no caller: 0x001d4830 inlines it).
struct Owner_1d47c0 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d47c0(const char* a, ScriptHandler_1d47c0* b, Fn_1d47c0 c);
};
void Owner_1d47c0::FUN_001d47c0(const char* a, ScriptHandler_1d47c0* b, Fn_1d47c0 c) {
    HULK_SIZE32(Closure1_1d43b0, 0x24);
    Closure1_1d43b0* n = new (FUN_0008d690((int)sizeof(Closure1_1d43b0))) Closure1_1d43b0(a, b, c);
    ((owners::CAgent_1d04b0*)n)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&functions)->FUN_001d1180((ScriptFunctionView*)n);
    LuaVMState* m = L;
    FUN_00213550(m, n);
    FUN_002134a0(m, FUN_001d22a0, 1);
    FUN_00213790(m, -10001, a);
}
