// luaL_pushresult
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* p) {
    unsigned int diff = (unsigned int)(p->p - p->buffer);
    if (diff != 0) {
        char* dst = p->buffer;
        FUN_00213380(p->L, dst, diff);
        p->p = dst;
        p->lvl = p->lvl + 1;
    }
    FUN_00213c90(p->L, p->lvl);
    p->lvl = 1;
}
