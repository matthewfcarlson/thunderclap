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

extern "C" int __cdecl FUN_0021bbc0(void *, void *);                       // llex
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);     // subexpr
extern "C" void __cdecl FUN_002214b0(void *, void *);                       // luaK_goiftrue
void __cdecl FUN_00220d70(FuncState *fs, int list);                         // luaK_patchtohere
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void __cdecl FUN_0021c2e0(void *, int);                                 // check
// equiv-conv: FUN_0021e080 eax
extern "C" void __cdecl FUN_0021e080(void *);                                            // block

// equiv-conv: FUN_0021ede0 eax
extern "C" int FUN_0021ede0(void * ls_) {
    LexState_21ede0 * ls = (LexState_21ede0 *)ls_;
    expdesc_21ede0 v;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0((LexState_21ede0 *)ls, (int *)(&ls->t.seminfo));
    }
    FUN_0021ded0((LexState_21ede0 *)ls, (expdesc_21ede0 *)(&v), 0);
    if (v.k == 1)
        v.k = 3;
    FUN_002214b0((FuncState *)(ls->fs), (expdesc_21ede0 *)(&v));
    FUN_00220d70(ls->fs, v.t);
    FUN_0021c2e0((LexState_21ede0 *)ls, 0x112);
    FUN_0021e080((LexState_21ede0 *)ls);
    return v.f;
}
