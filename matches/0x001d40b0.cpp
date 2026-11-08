#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data);
// 0x001d3f60 (equivalent/0x001d3f60.cpp): a ScriptHandler member; `this` is the same object.
class ScriptHandler {
  public:
    void FUN_001d3f60();
};
// value (include/gen/owners.h Obj_1d40b0 +0x08) is the lua_State, an int member there: cast at the use.
void owners::Obj_1d40b0::FUN_001d40b0() {
    ((ScriptHandler*)this)->FUN_001d3f60();
    FUN_00213ba0((LuaVMState*)(hulk_intptr)value, 2, 0);
}
