// luaK_checkstack: grow the prototype's maxstacksize to cover n more registers.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: msg = DAT_004271d4

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);

extern "C" void __cdecl FUN_00220810(LuaVMFuncState* fs, int n) {
    int x = fs->freereg + n;
    if (x > (int)fs->f->maxstacksize) {
        if (x >= 250)
            FUN_0021b060(fs->ls, DAT_004271d4);
        fs->f->maxstacksize = (unsigned char)x;
    }
}
