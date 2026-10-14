// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// FUN_0021f460 @ 0x0021f460
// Lua 5.0 lparser breakstat (with luaX_next inlined)
struct BlockCnt_21f460 {
    BlockCnt_21f460 *previous;
    int breaklist;          // 0x4
    unsigned char nactvar;  // 0x8
    unsigned char upval;    // 0x9
    unsigned char isbreak;  // 0xa
};

struct FuncState_21f460 {
    char pad0[0x14];
    BlockCnt_21f460 *bl;           // 0x14
};

struct Token_21f460 {
    int token;
    int seminfo;
};

struct LexState_21f460 {
    int current;
    int linenumber;
    int lastline;
    Token_21f460 t;                // 0xc
    Token_21f460 lookahead;        // 0x14
    FuncState_21f460 *fs;          // 0x1c
};

int __cdecl FUN_0021bbc0(LexState_21f460 *ls, int *seminfo);                       // llex
void __cdecl FUN_0021b060(LexState_21f460 *ls, const char *msg);                   // luaX_syntaxerror
int __cdecl FUN_00220bd0(FuncState_21f460 *fs, int op, int a, int b, int c);       // luaK_codeABC
int __cdecl FUN_00220cd0(FuncState_21f460 *fs);                                    // luaK_jump
void __cdecl FUN_002207c0(FuncState_21f460 *fs, int *l1, int l2);                  // luaK_concat

// equiv-conv: FUN_0021f460 edi
void FUN_0021f460(LexState_21f460 *ls)
{
    FuncState_21f460 *fs = ls->fs;
    BlockCnt_21f460 *bl = fs->bl;
    int upval = 0;

    // luaX_next(ls)
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t = ls->lookahead;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }

    while (bl != 0 && !bl->isbreak) {
        upval |= bl->upval;
        bl = bl->previous;
    }
    if (bl == 0)
        FUN_0021b060(ls, "no loop to break");
    if (upval)
        FUN_00220bd0(fs, 0x22, bl->nactvar, 0, 0);
    FUN_002207c0(fs, &bl->breaklist, FUN_00220cd0(fs));
}
