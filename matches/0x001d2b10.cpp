#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
// data (include/gen/owners.h Obj_1d2b10 +0x08) is the lua_State, a void* there: cast at the use.
int owners::Obj_1d2b10::FUN_001d2b10(int start, int end) {
    int len = FUN_00212d70((LuaVMState*)data);
    if (len == 0)
        return -1;
    if (start != 0) {
        int absStart = start;
        if (start < 0)
            absStart = -start;
        if (absStart <= len) {
            if (FUN_00212f00((LuaVMState*)data, start) == 6) {
                if (end == -1) {
                    if (start > 0)
                        end = len - start;
                    else
                        end = len + start;
                }
                LuaVMState* d = (LuaVMState*)data;
                if (FUN_002139f0(d, end, -1, 0) == 0)
                    return FUN_00212d70((LuaVMState*)data);
            }
        }
    }
    return -1;
}
