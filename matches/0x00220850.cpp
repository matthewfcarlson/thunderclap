// luaK_reserveregs: checkstack, then take n registers.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);

extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n) {
    int sum = fs->freereg + n;
    if (sum > (int)fs->f->maxstacksize) {
        if (sum >= 0xfa)
            FUN_0021b060(fs->ls, "function or expression too complex");
        fs->f->maxstacksize = (unsigned char)sum;
    }
    fs->freereg += n;
}
