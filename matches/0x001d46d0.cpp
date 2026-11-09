#include "compat/ptr.h"
#include "decls/data/script.h"
#include "gen/owners.h"
#include "decls/data/records.h"
extern "C" void* __cdecl FUN_0008d690(int x);
extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" char DAT_00422810[];
class ScriptHandler;
// The bound member function: ScriptHandler::FUN_001d4460 (sh_CallFuncInGlobalState: a global Lua function and up to
// three string arguments).
class ScriptHandlerFn_1d46d0 {};
typedef void (ScriptHandlerFn_1d46d0::*Fn_1d46d0)(const char*, const char*, const char*, const char*);
// 0x001d3250 (matches/0x001d3250.cpp): Method4's initializer (name, member function); returns this.
class Method4_1d3250 {
  public:
    Method4_1d3250* Create(const char*, Fn_1d46d0);
};
// Closure4<ScriptHandler, void, const char* x4> (include/decls/data/script.h): Function's fields, the
// member-function pointer, the object; vftable DAT_00422810.
struct Closure4_1d46d0 {
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d46d0 fn;
    ScriptHandler* owner;
};
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of Functions (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// 0x001d4830 calls it as ScriptHandler::FUN_001d46d0("sh_CallFuncInGlobalState", this, &ScriptHandler::FUN_001d4460).
class ScriptHandler {
  public:
    void FUN_001d46d0(const char* name, ScriptHandler* obj, Fn_1d46d0 fn);
};
void ScriptHandler::FUN_001d46d0(const char* name, ScriptHandler* obj, Fn_1d46d0 fn) {
    ScriptHandlerView* self = (ScriptHandlerView*)this;
    HULK_SIZE32(Closure4_1d46d0, 0x24);
    Closure4_1d46d0* p = (Closure4_1d46d0*)FUN_0008d690((int)sizeof(Closure4_1d46d0));
    if (p) {
        ((Method4_1d3250*)p)->Create(name, fn);
        p->vftable = (void*)DAT_00422810;
        p->owner = obj;
    } else
        p = 0;
    ((owners::CAgent_1d04b0*)p)->FUN_001d04b0((hulk_intptr)name);
    ((SortedList*)&self->f.functions)->FUN_001d1180((ScriptFunctionView*)p);
    LuaVMState* x = self->f.L;
    FUN_00213550(x, p);
    FUN_002134a0(x, FUN_001d22a0, 1);
    FUN_00213790(x, -10001, name);
}
