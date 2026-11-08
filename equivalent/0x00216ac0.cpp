// STATUS: equivalent (tools/equiv.py level 3: 1088 inputs, branch coverage 17/17)
// propagatemarks: traverse gray objects (black afterwards; threads go onto grayagain) until lim bytes are done.
#include "decls/data/lua.h"

// equiv-conv: FUN_00216670 edi stack
extern "C" int __cdecl FUN_00216670(LuaVMTable* h, LuaVMGlobal* g);
// equiv-conv: FUN_002168d0 esi stack
extern "C" void __cdecl FUN_002168d0(LuaVMClosure* cl, LuaVMGlobal* g);
// equiv-conv: FUN_002169e0 edi stack
extern "C" void __cdecl FUN_002169e0(LuaVMState* L, LuaVMGlobal* g);
// equiv-conv: FUN_00216810 esi stack
extern "C" void __cdecl FUN_00216810(LuaVMProto* f, LuaVMGlobal* g);
// equiv-conv: FUN_00216ac0 eax stack
extern "C" int __cdecl FUN_00216ac0(int lim, LuaVMGlobal* g) {
    LuaVMGCObject* o = g->gray;
    if (!o)
        return lim;
    do {
        o->marked |= 4;
        switch (o->tt) {
        case LUAVM_TTABLE: {
            LuaVMTable* h = (LuaVMTable*)o;
            g->gray = h->gclist;
            if (FUN_00216670(h, g))
                o->marked &= ~4;
            lim -= (int)sizeof(LuaVMTable) + (int)sizeof(LuaVMTObject) * h->sizearray +
                   (int)sizeof(LuaVMNode) * (1 << (h->lsizenode & 31));
            break;
        }
        case LUAVM_TFUNCTION: {
            LuaVMClosure* cl = (LuaVMClosure*)o;
            g->gray = cl->c.gclist;
            FUN_002168d0(cl, g);
            lim -= cl->c.isC ? LUAVM_SIZECCLOSURE(cl->c.nupvalues) : LUAVM_SIZELCLOSURE(cl->l.nupvalues);
            break;
        }
        case LUAVM_TTHREAD: {
            LuaVMState* th = (LuaVMState*)o;
            g->gray = th->gclist;
            th->gclist = g->grayagain;
            g->grayagain = o;
            o->marked &= ~4;
            FUN_002169e0(th, g);
            lim -= (int)sizeof(LuaVMState) + (int)sizeof(LuaVMTObject) * th->stacksize +
                   (int)sizeof(LuaVMCallInfo) * th->size_ci;
            break;
        }
        case LUAVM_TPROTO: {
            LuaVMProto* p = (LuaVMProto*)o;
            g->gray = p->gclist;
            FUN_00216810(p, g);
            lim -= (int)sizeof(LuaVMProto) + (int)sizeof(LuaVMInstruction) * p->sizecode +
                   (int)sizeof(LuaVMProto*) * p->sizep + (int)sizeof(LuaVMTObject) * p->sizek +
                   (int)sizeof(int) * p->sizelineinfo + (int)sizeof(LuaVMLocVar) * p->sizelocvars +
                   (int)sizeof(LuaVMString*) * p->sizeupvalues;
            break;
        }
        }
        if (lim <= 0)
            break;
        o = g->gray;
    } while (o);
    return lim;
}
