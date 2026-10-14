// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// FUN_0021ccb0 @ 0x0021ccb0
struct FuncState;

struct LexState {
    int current;            // 0x00
    int linenumber;         // 0x04
    int lastline;           // 0x08
    int token;              // 0x0c
    int seminfo;            // 0x10
    int lookaheadToken;     // 0x14
    int lookaheadSeminfo;   // 0x18
    FuncState* fs;          // 0x1c
};

struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

void __cdecl FUN_00221190(FuncState* fs, int x);
int __cdecl FUN_0021bbc0(LexState* ls, int* seminfo);
int __cdecl FUN_0021c3d0();
int __cdecl FUN_002209b0(FuncState* fs, int v);
int __cdecl FUN_002216e0(FuncState* fs, int x, ExpDesc* e, FuncState* fs2, int v);

// equiv-conv: FUN_0021ccb0 eax ebx
int FUN_0021ccb0(LexState* ls, int x)
{
    FuncState* fs = ls->fs;
    FUN_00221190(fs, x);
    ls->lastline = ls->linenumber;
    if (ls->lookaheadToken != 0x11f) {
        ls->token = ls->lookaheadToken;
        ls->seminfo = ls->lookaheadSeminfo;
        ls->lookaheadToken = 0x11f;
    } else {
        ls->token = FUN_0021bbc0(ls, &ls->seminfo);
    }
    ExpDesc e;
    int v = FUN_0021c3d0();
    e.info = FUN_002209b0(ls->fs, v);
    e.k = 4;
    e.t = -1;
    e.f = -1;
    return FUN_002216e0(fs, x, &e, ls->fs, v);
}
