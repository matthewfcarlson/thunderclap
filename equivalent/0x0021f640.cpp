// STATUS: equivalent (tools/equiv.py level 3: 2728 inputs, branch coverage 12/12)
// chunk: { stat [';'] } with a nesting-depth guard
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
// equiv-conv: FUN_0021f500 eax
extern "C" int FUN_0021f500(LuaVMLexState* ls);

static void next(LuaVMLexState* ls) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}

// TK_ELSE, TK_ELSEIF, TK_END, TK_UNTIL, TK_EOS
static bool block_follow(int token) {
    switch (token) {
    case 0x104:
    case 0x105:
    case 0x106:
    case 0x114:
    case 0x11f:
        return true;
    default:
        return false;
    }
}

extern "C" void __cdecl FUN_0021f640(LuaVMLexState* ls) {
    ls->nestlevel++;
    if (ls->nestlevel > 200)
        FUN_0021afd0(ls, "chunk has too many syntax levels", 0);

    while (!block_follow(ls->t.token)) {
        int islast = FUN_0021f500(ls);
        if (ls->t.token == ';')
            next(ls);
        ls->fs->freereg = ls->fs->nactvar;
        if (islast)
            break;
    }
    ls->nestlevel--;
}
