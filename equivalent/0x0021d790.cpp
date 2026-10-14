// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 6/6)
// FUN_0021d790 @ 0x0021d790
// Lua 5.0 lparser primaryexp (with luaX_next inlined)
struct expdesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct FuncState {
    char pad0[1];
};

struct Token {
    int token;
    int seminfo;
};

struct LexState {
    int current;
    int linenumber;
    int lastline;
    Token t;                // 0xc
    Token lookahead;        // 0x14
    FuncState *fs;          // 0x1c
};

int __cdecl FUN_0021bbc0(LexState *ls, int *seminfo);                       // llex
void __cdecl FUN_0021b060(LexState *ls, const char *msg);                   // luaX_syntaxerror
void __cdecl FUN_0021ded0(LexState *ls, expdesc *v, int limit);             // subexpr
// equiv-conv: FUN_0021c340 esi edi stack eax
void FUN_0021c340(LexState *ls, int what, int who, int line);               // check_match
// equiv-conv: FUN_0021c3d0 esi
int FUN_0021c3d0(LexState *ls);                                             // str_checkname
void __cdecl FUN_0021c790(FuncState *fs, int name, expdesc *v, int base);   // singlevar
void __cdecl FUN_00220d90(FuncState *fs, expdesc *v);                       // luaK_dischargevars

// equiv-conv: FUN_0021d790 eax ebx
void FUN_0021d790(LexState *ls, expdesc *v)
{
    switch (ls->t.token) {
    case '(': {
        int line = ls->linenumber;
        // luaX_next(ls)
        ls->lastline = line;
        if (ls->lookahead.token != 0x11f) {
            ls->t = ls->lookahead;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021ded0(ls, v, 0);
        FUN_0021c340(ls, ')', '(', line);
        FUN_00220d90(ls->fs, v);
        return;
    }
    case 0x116:
        FUN_0021c790(ls->fs, FUN_0021c3d0(ls), v, 1);
        return;
    default:
        FUN_0021b060(ls, "unexpected symbol");
        return;
    }
}
