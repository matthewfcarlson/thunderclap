// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// FUN_0021d5c0 @ 0x0021d5c0
struct FuncState;
struct LexState {
    int pad00;
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState* fs;
};
struct Exp { int k; int info; int aux; int t; int f; };
void __cdecl FUN_00221110(FuncState* fs, Exp* e);
int __cdecl FUN_0021ded0(LexState* ls, Exp* v, unsigned int limit);
int __cdecl FUN_0021bbc0(LexState* ls, int* seminfo);

// Lua 5.0 explist1(ls, v): ls arrives in esi, v in edi.
// equiv-conv: FUN_0021d5c0 esi edi
int FUN_0021d5c0(LexState* ls, Exp* v)
{
    int n = 1;
    FUN_0021ded0(ls, v, 0);
    while (ls->token == ',') {
        ls->lastline = ls->linenumber;
        if (ls->lookaheadToken != 0x11f) {
            ls->token = ls->lookaheadToken;
            ls->seminfo = ls->lookaheadSeminfo;
            ls->lookaheadToken = 0x11f;
        } else {
            ls->token = FUN_0021bbc0(ls, &ls->seminfo);
        }
        FUN_00221110(ls->fs, v);
        FUN_0021ded0(ls, v, 0);
        n++;
    }
    return n;
}
