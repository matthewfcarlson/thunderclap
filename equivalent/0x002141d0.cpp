// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 0/0)
// info_tailcall: fill ar for a tail call's lost activation; push nil as its function.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_00216340(char* out, const char* source, int bufflen);

// equiv-conv: FUN_002141d0 esi stack
extern "C" void __cdecl FUN_002141d0(LuaVMDebug* ar, LuaVMState* L) {
    ar->name = (const char*)&DAT_003f335c;
    ar->namewhat = (const char*)&DAT_003f335c;
    ar->currentline = -1;
    ar->linedefined = -1;
    ar->what = DAT_0042662c;
    ar->source = DAT_00426634;
    FUN_00216340(ar->short_src, DAT_00426634, 60);
    ar->nups = 0;
    L->top->tt = LUAVM_TNIL;
}
