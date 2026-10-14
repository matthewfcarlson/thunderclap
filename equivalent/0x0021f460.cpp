// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// FUN_0021f460 @ 0x0021f460
// Lua 5.0 lparser breakstat (with luaX_next inlined)
struct BlockCnt {
    BlockCnt *previous;
    int breaklist;          // 0x4
    unsigned char nactvar;  // 0x8
    unsigned char upval;    // 0x9
    unsigned char isbreak;  // 0xa
};

struct FuncState {
    char pad0[0x14];
    BlockCnt *bl;           // 0x14
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
int __cdecl FUN_00220bd0(FuncState *fs, int op, int a, int b, int c);       // luaK_codeABC
int __cdecl FUN_00220cd0(FuncState *fs);                                    // luaK_jump
void __cdecl FUN_002207c0(FuncState *fs, int *l1, int l2);                  // luaK_concat

// equiv-conv: FUN_0021f460 edi
void FUN_0021f460(LexState *ls)
{
    FuncState *fs = ls->fs;
    BlockCnt *bl = fs->bl;
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
