// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// FUN_0021ede0 @ 0x0021ede0
// Lua 5.0 test_then_block: skip IF/ELSEIF, parse the condition, expect THEN, parse the block.
struct Token_21ede0 {
    int token;
    int seminfo;
};

struct FuncState;

struct LexState_21ede0 {
    int current;
    int linenumber;
    int lastline;
    Token_21ede0 t;                    // 0x0c
    Token_21ede0 lookahead;            // 0x14
    FuncState *fs;              // 0x1c
};

struct expdesc_21ede0 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

int __cdecl FUN_0021bbc0(LexState_21ede0 *ls, int *seminfo);                       // llex
int __cdecl FUN_0021ded0(LexState_21ede0 *ls, expdesc_21ede0 *v, unsigned int limit);     // subexpr
void __cdecl FUN_002214b0(FuncState *fs, expdesc_21ede0 *v);                       // luaK_goiftrue
void __cdecl FUN_00220d70(FuncState *fs, int list);                         // luaK_patchtohere
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState_21ede0 *ls, int token);                                 // check
// equiv-conv: FUN_0021e080 eax
void FUN_0021e080(LexState_21ede0 *ls);                                            // block

// equiv-conv: FUN_0021ede0 eax
int FUN_0021ede0(LexState_21ede0 *ls) {
    expdesc_21ede0 v;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 1)
        v.k = 3;
    FUN_002214b0(ls->fs, &v);
    FUN_00220d70(ls->fs, v.t);
    FUN_0021c2e0(ls, 0x112);
    FUN_0021e080(ls);
    return v.f;
}
