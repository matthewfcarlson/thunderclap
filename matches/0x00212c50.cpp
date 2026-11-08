// lua_checkstack: room for size more slots (at most 2048 in the frame); raises the frame's top.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

extern "C" int __cdecl FUN_00212c50(LuaVMState* L, int size) {
    if ((L->top - L->base) + size > 0x800)
        return 0;
    if ((char*)L->stack_last - (char*)L->top <= size * (int)sizeof(LuaVMTObject))
        FUN_00215460(L, size);
    LuaVMTObject* t = L->top + size;
    if (L->ci->top < t)
        L->ci->top = t;
    return 1;
}
