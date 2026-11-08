// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// test_then_block: skip IF/ELSEIF, parse the condition, expect THEN, parse the block; returns the false list.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);               // llex
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit); // subexpr
extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e);                   // luaK_goiftrue
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list); // luaK_patchtohere
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c); // checknext
// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls); // block

// equiv-conv: FUN_0021ede0 eax
extern "C" int FUN_0021ede0(LuaVMLexState* ls) {
    LuaVMExpDesc v;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 1) // VNIL
        v.k = 3;  // VFALSE
    FUN_002214b0(ls->fs, &v);
    FUN_00220d70(ls->fs, v.t);
    FUN_0021c2e0(ls, 0x112); // TK_THEN
    FUN_0021e080(ls);
    return v.f;
}
