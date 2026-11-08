// luaT_gettm: the event's metamethod in events, or 0 (an absent one is cached in the table's flags).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);

extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename) {
    const LuaVMTObject* tm = FUN_00219e50(events, ename);
    if (tm->tt == LUAVM_TNIL) {
        events->flags |= (unsigned char)(1 << event);
        return 0;
    }
    return tm;
}
