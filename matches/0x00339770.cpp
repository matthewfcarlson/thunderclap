// getF: luaL_loadfile's reader (a LuaVMReader; ud is the LuaVMLoadF).
#include "decls/data/lua.h"
#include "decls/data/game/global.h"
// data: marker = DAT_00422518

extern "C" unsigned int __cdecl fread(void*, unsigned int, unsigned int, LuaVMFile*);
extern "C" const char* __cdecl FUN_00339770(LuaVMState* L, void* ud, unsigned int* count) {
    LuaVMLoadF* b = (LuaVMLoadF*)ud;
    if (b->extraline) {
        b->extraline = 0;
        *count = 1;
        return ((const char*)&DAT_00422518);
    }
    LuaVMFile* f = b->f;
    if (f->flag & 16)
        return 0;
    unsigned int n = fread(b->buff, 1, LUAVM_BUFFERSIZE, f);
    *count = n;
    return n > 0 ? b->buff : 0;
}
