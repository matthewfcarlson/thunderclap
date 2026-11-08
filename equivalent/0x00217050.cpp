// STATUS: equivalent (tools/equiv.py level 3: 2933 inputs, branch coverage 6/6)
// atomic: finish the mark phase (upvalues, weak tables, the running thread, grayagain, finalizable userdata), clear
// the weak tables, flip the white and start sweeping the strings.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00216ff0(LuaVMGlobal* g);
extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);
// equiv-conv: FUN_00216ac0 eax stack
extern "C" int __cdecl FUN_00216ac0(int lim, LuaVMGlobal* g);
extern "C" unsigned int __cdecl FUN_002165c0(LuaVMState* L, int all);
// equiv-conv: FUN_00216c40 eax
extern "C" void __cdecl FUN_00216c40(LuaVMGCObject* l);
// equiv-conv: FUN_00217050 eax
extern "C" void __cdecl FUN_00217050(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    FUN_00216ff0(g);
    g->gray = g->weak;
    g->weak = 0;
    if (L->marked & 3)
        FUN_002164b0(g, (LuaVMGCObject*)L);
    FUN_00216ac0(0x7fffffff, g);
    g->gray = g->grayagain;
    g->grayagain = 0;
    FUN_00216ac0(0x7fffffff, g);
    FUN_002165c0(L, 0);
    for (LuaVMGCObject* o = g->tmudata; o; o = o->next) {
        o->marked = (o->marked & 0xf8) | (unsigned char)g->currentwhite;
        FUN_002164b0(g, o);
    }
    FUN_00216ac0(0x7fffffff, g);
    FUN_00216c40(g->weak);
    g->currentwhite ^= 3;
    g->gcstate = 1;
}
