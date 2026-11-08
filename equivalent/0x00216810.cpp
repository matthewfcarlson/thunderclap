// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 30/30)
// traverseproto: mark a prototype's source, constants, upvalue names, nested prototypes and local names.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);

// equiv-conv: FUN_00216810 esi stack
extern "C" void __cdecl FUN_00216810(LuaVMProto* f, LuaVMGlobal* g) {
    if (f->source)
        f->source->marked &= 0xfc;
    for (int i = 0; i < f->sizek; ++i) {
        LuaVMTObject* o = &f->k[i];
        if (o->tt >= LUAVM_TSTRING && (o->value.gc->marked & 3))
            FUN_002164b0(g, o->value.gc);
    }
    for (int i = 0; i < f->sizeupvalues; ++i) {
        LuaVMString* s = f->upvalues[i];
        if (s)
            s->marked &= 0xfc;
    }
    for (int i = 0; i < f->sizep; ++i) {
        LuaVMProto* p = f->p[i];
        if (p && (p->marked & 3))
            FUN_002164b0(g, (LuaVMGCObject*)p);
    }
    for (int i = 0; i < f->sizelocvars; ++i) {
        LuaVMString* s = f->locvars[i].varname;
        if (s)
            s->marked &= 0xfc;
    }
}
