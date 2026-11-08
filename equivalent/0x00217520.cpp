// STATUS: equivalent (tools/equiv.py level 3: 2768 inputs, branch coverage 4/4)
// luaT_init: intern the event names (luaT_eventname, DAT_00426a24) into the global state's tmname, fixed.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

extern "C" void __cdecl FUN_00217520(LuaVMState* L) {
    for (int i = 0; i < LUAVM_TM_N; ++i) {
        const char* name = DAT_00426a24[i];
        const char* end = name;
        while (*end)
            ++end;
        L->l_G->tmname[i] = FUN_00219430(L, name, (unsigned int)(end - name));
        L->l_G->tmname[i]->marked |= 0x20;
    }
}
