// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 18/21, incomplete)
#include "decls/data/lua.h"

extern "C" {
int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token);
const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
void __cdecl FUN_002211e0(LuaVMFuncState* fs, LuaVMExpDesc* e);
void __cdecl FUN_002216e0(LuaVMFuncState* fs, LuaVMExpDesc* t, LuaVMExpDesc* k);
void __cdecl FUN_00221360(LuaVMFuncState* fs, LuaVMExpDesc* e, LuaVMExpDesc* key);
int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s);
// equiv-conv: FUN_0021d790 eax ebx
void FUN_0021d790(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021ccb0 eax ebx
void FUN_0021ccb0(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021d630 eax stack
void FUN_0021d630(LuaVMLexState* ls, LuaVMExpDesc* f);
}

// primaryexp: a prefix expression followed by any number of field,
// index, method-call and call suffixes. v arrives in eax, ls in esi.
// equiv-conv: FUN_0021d830 eax esi
extern "C" void FUN_0021d830(LuaVMExpDesc* v, LuaVMLexState* ls) {
    LuaVMExpDesc key;
    LuaVMExpDesc method;
    LuaVMFuncState* fs = ls->fs;

    FUN_0021d790(ls, v);
    for (;;) {
        switch (ls->t.token) {
        case '.':
            FUN_0021ccb0(ls, v);
            break;
        case '[':
            FUN_00221190(fs, v);
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            FUN_0021ded0(ls, &key, 0);
            FUN_002211e0(ls->fs, &key);
            if (ls->t.token != ']')
                FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, ']')));
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            FUN_002216e0(fs, v, &key);
            break;
        case ':': {
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            if (ls->t.token != 0x116)
                FUN_0021b060(ls, "<name> expected");
            LuaVMString* name = ls->t.seminfo.ts;
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            method.k = 4;
            method.info = FUN_002209b0(ls->fs, name);
            method.t = -1;
            method.f = -1;
            FUN_00221360(fs, v, &method);
            FUN_0021d630(ls, v);
            break;
        }
        case '(':
        case '{':
        case 0x11e:
            FUN_00221110(fs, v);
            FUN_0021d630(ls, v);
            break;
        default:
            return;
        }
    }
}
