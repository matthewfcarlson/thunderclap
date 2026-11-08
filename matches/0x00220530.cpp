// luaK_getlabel: mark the current pc as a jump target.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220530(LuaVMFuncState* fs) {
    return fs->lasttarget = fs->pc;
}
