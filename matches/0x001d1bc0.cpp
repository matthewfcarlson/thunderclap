#include "decls/data/script.h"
#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00213320(LuaVMState*);
// value (include/gen/owners.h Obj_1d1bc0 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::Obj_1d1bc0::FUN_001d1bc0() {
    ScriptHandlerFields& h = ((ScriptHandlerView*)this)->f;  // the saved stack tops
    if (h.topIndex < 7 && h.topIndex >= -1) {
        ++h.topIndex;
        h.tops[h.topIndex] = FUN_00212d70((LuaVMState*)(hulk_intptr)value);
        FUN_00213320((LuaVMState*)(hulk_intptr)value);
        return true;
    }
    return false;
}
