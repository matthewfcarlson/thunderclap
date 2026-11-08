// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// str_checkname: expect a name token, return its string and advance.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls) {
    if (ls->t.token != 0x116)
        FUN_0021b060(ls, "<name> expected");
    ls->lastline = ls->linenumber;
    LuaVMString* ts = ls->t.seminfo.ts;
    if (ls->lookahead.token != 0x11f) {
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->t.token = ls->lookahead.token;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    return ts;
}
