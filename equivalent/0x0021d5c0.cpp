// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// FUN_0021d5c0 @ 0x0021d5c0
struct FuncState;
struct LexState_21d5c0 {
    int pad00;
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState* fs;
};
struct Exp_21d5c0 { int k; int info; int aux; int t; int f; };
extern "C" void __cdecl FUN_00221110(void *, void *);
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);
extern "C" int __cdecl FUN_0021bbc0(void *, void *);

// Lua 5.0 explist1(ls, v): ls arrives in esi, v in edi.
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int FUN_0021d5c0(void * ls_, void * v)
{
    LexState_21d5c0 * ls = (LexState_21d5c0 *)ls_;
    int n = 1;
    FUN_0021ded0((LexState_21d5c0 *)ls, (Exp_21d5c0 *)((Exp_21d5c0 *)v), 0);
    while (ls->token == ',') {
        ls->lastline = ls->linenumber;
        if (ls->lookaheadToken != 0x11f) {
            ls->token = ls->lookaheadToken;
            ls->seminfo = ls->lookaheadSeminfo;
            ls->lookaheadToken = 0x11f;
        } else {
            ls->token = FUN_0021bbc0((LexState_21d5c0 *)ls, (int *)(&ls->seminfo));
        }
        FUN_00221110((FuncState *)(ls->fs), (Exp_21d5c0 *)((Exp_21d5c0 *)v));
        FUN_0021ded0((LexState_21d5c0 *)ls, (Exp_21d5c0 *)((Exp_21d5c0 *)v), 0);
        n++;
    }
    return n;
}
