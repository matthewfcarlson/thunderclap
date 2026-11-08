// STATUS: equivalent (tools/equiv.py level 3: 2694 inputs, branch coverage 4/4)
// setarrayvector: resize a table's array part to size slots (the new ones nil).
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

// equiv-conv: FUN_00219be0 esi edi stack
extern "C" void __cdecl FUN_00219be0(LuaVMTable* t, int size, LuaVMState* L) {
    t->array = (LuaVMTObject*)FUN_0021add0(L, t->array, t->sizearray * (unsigned int)sizeof(LuaVMTObject),
                                           size * (unsigned int)sizeof(LuaVMTObject));
    for (int i = t->sizearray; i < size; ++i)
        t->array[i].tt = LUAVM_TNIL;
    t->sizearray = size;
}
