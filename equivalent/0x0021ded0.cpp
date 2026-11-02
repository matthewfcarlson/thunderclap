// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 16/16)
// FUN_0021ded0 @ 0x0021ded0
#include "decls/data/engine/unknown.h"

struct ExpDesc_21ded0 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct FuncState;

struct LexState_21ded0 {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState *fs;
    char pad20[0x30 - 0x20];
    int nestlevel;
};

extern "C" int __cdecl FUN_0021bbc0(void *, void *);
void FUN_0021afd0(LexState_21ded0 *ls, const char *msg, int token);
// equiv-conv: FUN_0021db50 eax edi
extern "C" void __cdecl FUN_0021db50(void *, void *);
// equiv-conv: FUN_0021dd30 eax
extern "C" int FUN_0021dd30(int token);
extern "C" void __cdecl FUN_00221700(void *, int, void *);
extern "C" void __cdecl FUN_002217c0(void *, int, void *);
extern "C" void __cdecl FUN_002218d0(void *, int, void *, void *);


static void next(LexState_21ded0 *ls)
{
    ls->lastline = ls->linenumber;
    if (ls->lookaheadToken != 0x11f) {
        ls->token = ls->lookaheadToken;
        ls->seminfo = ls->lookaheadSeminfo;
        ls->lookaheadToken = 0x11f;
    } else {
        ls->token = FUN_0021bbc0((LexState_21ded0 *)ls, (int *)(&ls->seminfo));
    }
}

extern "C" int FUN_0021ded0(void *ls, void *v, unsigned int limit)
{
    ExpDesc_21ded0 v2;
    int op;

    ((LexState_21ded0 *)ls)->nestlevel++;
    if (((LexState_21ded0 *)ls)->nestlevel > 200)
        FUN_0021afd0(((LexState_21ded0 *)ls), "chunk has too many syntax levels", 0);

    if (((LexState_21ded0 *)ls)->token == '-' || ((LexState_21ded0 *)ls)->token == 0x10e) {
        int uop = (((LexState_21ded0 *)ls)->token == 0x10e);
        next(((LexState_21ded0 *)ls));
        FUN_0021ded0((LexState_21ded0 *)((LexState_21ded0 *)ls), (ExpDesc_21ded0 *)((ExpDesc_21ded0 *)v), 8);
        FUN_00221700((FuncState *)(((LexState_21ded0 *)ls)->fs), uop, (ExpDesc_21ded0 *)((ExpDesc_21ded0 *)v));
    } else {
        FUN_0021db50((LexState_21ded0 *)((LexState_21ded0 *)ls), (ExpDesc_21ded0 *)((ExpDesc_21ded0 *)v));
    }
    op = FUN_0021dd30(((LexState_21ded0 *)ls)->token);
    while (op != 0xe && DAT_00426e00[op * 2] > limit) {
        next(((LexState_21ded0 *)ls));
        FUN_002217c0((FuncState *)(((LexState_21ded0 *)ls)->fs), op, (ExpDesc_21ded0 *)((ExpDesc_21ded0 *)v));
        int nextop = FUN_0021ded0((LexState_21ded0 *)((LexState_21ded0 *)ls), (ExpDesc_21ded0 *)(&v2), DAT_00426e00[op * 2 + 1]);
        FUN_002218d0((FuncState *)(((LexState_21ded0 *)ls)->fs), op, (ExpDesc_21ded0 *)((ExpDesc_21ded0 *)v), (ExpDesc_21ded0 *)(&v2));
        op = nextop;
    }
    ((LexState_21ded0 *)ls)->nestlevel--;
    return op;
}
