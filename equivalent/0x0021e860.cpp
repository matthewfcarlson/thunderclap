// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 12/12)
// FUN_0021e860 @ 0x0021e860
struct LexState_21e860;

struct FuncState_21e860 {
    char pad0[0xc];
    LexState_21e860* ls;
    char pad10[0x24 - 0x10];
    int freereg;
    char pad28[0x34 - 0x28];
    unsigned char nactvar;
    char pad35[0x76 - 0x35];
    unsigned short actvar[200];
};

struct LexState_21e860 {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState_21e860* fs;
};

struct ExpDesc_21e860 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct Frame_21e860 {
    int base;
    ExpDesc_21e860 e;
};

int __cdecl FUN_0021b080(LexState_21e860* ls, const char* s, int len);
unsigned short __cdecl FUN_0021c490(LexState_21e860* ls, int name);
int __cdecl FUN_0021bbc0(LexState_21e860* ls, int* seminfo);
int __cdecl FUN_0021ded0(LexState_21e860* ls, ExpDesc_21e860* v, unsigned int limit);
void __cdecl FUN_00221110(FuncState_21e860* fs, ExpDesc_21e860* e);
int __cdecl FUN_002209e0(FuncState_21e860* fs, float n);
int __cdecl FUN_00220c10(FuncState_21e860* fs, int op, int a, int bx);
void __cdecl FUN_00220850(FuncState_21e860* fs, int n);
// equiv-conv: FUN_0021c240 esi ecx edx
void FUN_0021c240(FuncState_21e860* fs, const char* what, int limit);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState_21e860* ls, int token);
// equiv-conv: FUN_0021e700 eax stack stack stack stack
void FUN_0021e700(LexState_21e860* ls, int base, int line, int nvars, int isnum);

// Lua 5.0 fornum(ls, varname, line): ls arrives in edi, the rest on the stack.
// equiv-conv: FUN_0021e860 edi stack stack
void FUN_0021e860(LexState_21e860* ls, int varname, int line)
{
    Frame_21e860 fr;
    FuncState_21e860* fs0 = ls->fs;
    FuncState_21e860* fs;
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
