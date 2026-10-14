// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// FUN_0021f280 @ 0x0021f280
// Lua 5.0 luaX_next followed by an expression-parsing step
struct expdesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct FuncState {
    char pad[1];
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
    FuncState* fs;          // 0x1c
};

int __cdecl FUN_0021bbc0(LexState* ls, int* seminfo);                       // llex
// equiv-conv: FUN_0021f220 eax ecx
expdesc* FUN_0021f220(expdesc* out, LexState* ls);
void __cdecl FUN_0021d4b0(expdesc* dst, expdesc* src, int arg);
void __cdecl FUN_00221280(FuncState* fs, expdesc* a, expdesc* b);
void __cdecl FUN_00220b00(FuncState* fs, int arg);

struct Frame {
    expdesc second;
    expdesc first;
};

// equiv-conv: FUN_0021f280 eax esi
void FUN_0021f280(LexState* ls, int arg)
{
    Frame f;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    expdesc* r = FUN_0021f220(&f.first, ls);
    FUN_0021d4b0(&f.second, r, arg);
    FUN_00221280(ls->fs, &f.first, &f.second);
    FUN_00220b00(ls->fs, arg);
}
