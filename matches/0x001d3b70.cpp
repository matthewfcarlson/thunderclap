#include "compat/ptr.h"
#include "decls/data/lua.h"
#include "gen/owners.h"
#include "decls/data/script.h"
extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
// 0x001d1180 (equivalent/0x001d1180.cpp): the handler's sorted list of closures (ScriptHandlerFields.functions).
class SortedList : public ScriptFunctionList {
  public:
    bool FUN_001d1180(ScriptFunctionView* e);
};
// field8 (include/gen/owners.h Obj_1d3b70 +0x08) is the lua_State, a void* there; a (the function's name) is a
// hulk_uintptr and b (the closure object) a hulk_intptr there: cast at the use.
void owners::Obj_1d3b70::FUN_001d3b70(hulk_uintptr a, hulk_intptr b) {
    ((owners::CAgent_1d04b0*)b)->FUN_001d04b0((hulk_intptr)a);
    ((SortedList*)&((ScriptHandlerView*)this)->f.functions)->FUN_001d1180((ScriptFunctionView*)b);
    LuaVMState* x = (LuaVMState*)field8;
    FUN_00213550(x, (void*)b);
    FUN_002134a0(x, FUN_001d22a0, 1);
    FUN_00213790(x, -10001, (const char*)a);
}
