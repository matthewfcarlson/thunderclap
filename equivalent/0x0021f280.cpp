// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// FUN_0021f280 @ 0x0021f280
// Lua 5.0 luaX_next followed by an expression-parsing step
struct expdesc_21f280 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct FuncState_21f280 {
    char pad[1];
};

struct Token_21f280 {
    int token;
    int seminfo;
};

struct LexState_21f280 {
    int current;
    int linenumber;
    int lastline;
    Token_21f280 t;                // 0xc
    Token_21f280 lookahead;        // 0x14
    FuncState_21f280* fs;          // 0x1c
};

int __cdecl FUN_0021bbc0(LexState_21f280* ls, int* seminfo);                       // llex
// equiv-conv: FUN_0021f220 eax ecx
expdesc_21f280* FUN_0021f220(expdesc_21f280* out, LexState_21f280* ls);
void __cdecl FUN_0021d4b0(expdesc_21f280* dst, expdesc_21f280* src, int arg);
void __cdecl FUN_00221280(FuncState_21f280* fs, expdesc_21f280* a, expdesc_21f280* b);
void __cdecl FUN_00220b00(FuncState_21f280* fs, int arg);

struct Frame_21f280 {
    expdesc_21f280 second;
    expdesc_21f280 first;
};

// equiv-conv: FUN_0021f280 eax esi
void FUN_0021f280(LexState_21f280* ls, int arg)
{
    Frame_21f280 f;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    expdesc_21f280* r = FUN_0021f220(&f.first, ls);
    FUN_0021d4b0(&f.second, r, arg);
    FUN_00221280(ls->fs, &f.first, &f.second);
    FUN_00220b00(ls->fs, arg);
}
