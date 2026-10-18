// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 6/6)
// FUN_0021d790 @ 0x0021d790
// FUN_0021d790 @ 0x0021d790
// Lua 5.0 lparser primaryexp (with luaX_next inlined)
struct expdesc_21d790 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct FuncState_21d790 {
    char pad0[1];
};

struct Token_21d790 {
    int token;
    int seminfo;
};

struct LexState_21d790 {
    int current;
    int linenumber;
    int lastline;
    Token_21d790 t;                // 0xc
    Token_21d790 lookahead;        // 0x14
    FuncState_21d790 *fs;          // 0x1c
};

int __cdecl FUN_0021bbc0(LexState_21d790 *ls, int *seminfo);                       // llex
void __cdecl FUN_0021b060(LexState_21d790 *ls, const char *msg);                   // luaX_syntaxerror
void __cdecl FUN_0021ded0(LexState_21d790 *ls, expdesc_21d790 *v, int limit);             // subexpr
// equiv-conv: FUN_0021c340 eax esi edi stack
void FUN_0021c340(int line, LexState_21d790 *ls, int what, int who);               // check_match
// equiv-conv: FUN_0021c3d0 esi
int FUN_0021c3d0(LexState_21d790 *ls);                                             // str_checkname
void __cdecl FUN_0021c790(FuncState_21d790 *fs, int name, expdesc_21d790 *v, int base);   // singlevar
void __cdecl FUN_00220d90(FuncState_21d790 *fs, expdesc_21d790 *v);                       // luaK_dischargevars

// equiv-conv: FUN_0021d790 eax ebx
void FUN_0021d790(LexState_21d790 *ls, expdesc_21d790 *v)
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
        FUN_0021c340(line, ls, ')', '(');
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
