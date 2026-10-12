// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 12/12)
// FUN_0021e860 @ 0x0021e860
struct LexState;

struct FuncState {
    char pad0[0xc];
    LexState* ls;
    char pad10[0x24 - 0x10];
    int freereg;
    char pad28[0x34 - 0x28];
    unsigned char nactvar;
    char pad35[0x76 - 0x35];
    unsigned short actvar[200];
};

struct LexState {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState* fs;
};

struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct Frame {
    int base;
    ExpDesc e;
};

int __cdecl FUN_0021b080(LexState* ls, const char* s, int len);
unsigned short __cdecl FUN_0021c490(LexState* ls, int name);
int __cdecl FUN_0021bbc0(LexState* ls, int* seminfo);
int __cdecl FUN_0021ded0(LexState* ls, ExpDesc* v, unsigned int limit);
void __cdecl FUN_00221110(FuncState* fs, ExpDesc* e);
int __cdecl FUN_002209e0(FuncState* fs, float n);
int __cdecl FUN_00220c10(FuncState* fs, int op, int a, int bx);
void __cdecl FUN_00220850(FuncState* fs, int n);
// equiv-conv: FUN_0021c240 esi ecx edx
void FUN_0021c240(FuncState* fs, const char* what, int limit);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState* ls, int token);
// equiv-conv: FUN_0021e700 eax stack stack stack stack
void FUN_0021e700(LexState* ls, int base, int line, int nvars, int isnum);

// Lua 5.0 fornum(ls, varname, line): ls arrives in edi, the rest on the stack.
// equiv-conv: FUN_0021e860 edi stack stack
void FUN_0021e860(LexState* ls, int varname, int line)
{
    Frame fr;
    FuncState* fs0 = ls->fs;
    FuncState* fs;
    fr.base = fs0->freereg;

    int name = FUN_0021b080(ls, "(for index)", 11);
    fs = ls->fs;
    if (fs->nactvar + 1 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 0] = FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for limit)", 11);
    fs = ls->fs;
    if (fs->nactvar + 2 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 1] = FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for step)", 10);
    fs = ls->fs;
    if (fs->nactvar + 3 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 2] = FUN_0021c490(ls, name);

    fs = ls->fs;
    if (fs->nactvar + 4 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 3] = FUN_0021c490(ls, varname);

    FUN_0021c2e0(ls, '=');
    FUN_0021ded0(ls, &fr.e, 0);
    FUN_00221110(ls->fs, &fr.e);
    FUN_0021c2e0(ls, ',');
    FUN_0021ded0(ls, &fr.e, 0);
    FUN_00221110(ls->fs, &fr.e);

    if (ls->token == ',') {
        ls->lastline = ls->linenumber;
        if (ls->lookaheadToken != 0x11f) {
            ls->token = ls->lookaheadToken;
            ls->seminfo = ls->lookaheadSeminfo;
            ls->lookaheadToken = 0x11f;
        } else {
            ls->token = FUN_0021bbc0(ls, &ls->seminfo);
        }
        FUN_0021ded0(ls, &fr.e, 0);
        FUN_00221110(ls->fs, &fr.e);
    } else {
        int k = FUN_002209e0(fs0, 1.0f);
        FUN_00220c10(fs0, 1, fs0->freereg, k);
        FUN_00220850(fs0, 1);
    }
    FUN_0021e700(ls, fr.base, line, 1, 1);
}
