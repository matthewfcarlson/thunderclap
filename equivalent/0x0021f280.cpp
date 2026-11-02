// STATUS: equivalent (tools/equiv.py level 3: 10855 inputs, branch coverage 2/2)
// FUN_0021f280 @ 0x0021f280
// FUN_0021f280 @ 0x0021f280
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

extern "C" int __cdecl FUN_0021bbc0(void *, void *);                       // llex
// equiv-conv: FUN_0021f220 ecx eax
expdesc_21f280* FUN_0021f220(LexState_21f280* ls, expdesc_21f280* out);
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
void __cdecl FUN_0021d4b0(LexState_21f280* ls, expdesc_21f280* dst, expdesc_21f280* src, int arg);
extern "C" void __cdecl FUN_00221280(void *, void *, void *);
extern "C" void __cdecl FUN_00220b00(void *, int);

struct Frame_21f280 {
    expdesc_21f280 second;
    expdesc_21f280 first;
};

// equiv-conv: FUN_0021f280 eax esi
extern "C" void FUN_0021f280(void * ls_, int arg)
{
    LexState_21f280 * ls = (LexState_21f280 *)ls_;
    Frame_21f280 f;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0((LexState_21f280 *)ls, (int *)(&ls->t.seminfo));
    }
    expdesc_21f280* r = FUN_0021f220(ls, &f.first);
    FUN_0021d4b0(ls, &f.second, r, arg);
    FUN_00221280((FuncState_21f280 *)(ls->fs), (expdesc_21f280 *)(&f.first), (expdesc_21f280 *)(&f.second));
    FUN_00220b00((FuncState_21f280 *)(ls->fs), arg);
}
