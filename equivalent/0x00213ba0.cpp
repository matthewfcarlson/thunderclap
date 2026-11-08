// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 13/13)
// lua_gc: stop, restart, collect, count (KB) or step the collector.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217490(LuaVMState* L);
extern "C" void __cdecl FUN_00217440(LuaVMState* L);

extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data) {
    LuaVMGlobal* g = L->l_G;
    switch (what) {
    case 0:
        g->GCthreshold = 0x7fffffff;
        return 0;
    case 1:
        g->GCthreshold = g->totalbytes;
        return 0;
    case 2:
        FUN_00217490(L);
        return 0;
    case 3:
        return g->totalbytes >> 10;
    case 4:
        if (data > 0) {
            int n = data;
            do {
                if (g->totalbytes < g->GCthreshold)
                    g->GCthreshold = g->totalbytes;
                FUN_00217440(L);
                n--;
            } while (n != 0);
        }
        return 0;
    }
    return -1;
}
