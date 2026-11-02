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
extern "C" int __cdecl FUN_0021bbc0(void *, void *);
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_00221110(void *, void *);
int __cdecl FUN_002209e0(FuncState_21e860* fs, float n);
extern "C" int __cdecl FUN_00220c10(void *, unsigned int, int, unsigned int);
extern "C" void __cdecl FUN_00220850(void *, int);
// equiv-conv: FUN_0021c240 esi ecx edx
void FUN_0021c240(FuncState_21e860* fs, const char* what, int limit);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void __cdecl FUN_0021c2e0(void *, int);
// equiv-conv: FUN_0021e700 eax stack stack stack stack
extern "C" void __cdecl FUN_0021e700(void *, int, int, int, int);

// Lua 5.0 fornum(ls, varname, line): ls arrives in edi, the rest on the stack.
// equiv-conv: FUN_0021e860 edi stack stack
extern "C" void FUN_0021e860(void * ls_, int varname, int line)
{
    LexState_21e860 * ls = (LexState_21e860 *)ls_;
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

    FUN_0021c2e0((LexState_21e860 *)ls, '=');
    FUN_0021ded0((LexState_21e860 *)ls, (ExpDesc_21e860 *)(&fr.e), 0);
    FUN_00221110((FuncState_21e860 *)(ls->fs), (ExpDesc_21e860 *)(&fr.e));
    FUN_0021c2e0((LexState_21e860 *)ls, ',');
    FUN_0021ded0((LexState_21e860 *)ls, (ExpDesc_21e860 *)(&fr.e), 0);
    FUN_00221110((FuncState_21e860 *)(ls->fs), (ExpDesc_21e860 *)(&fr.e));

    if (ls->token == ',') {
        ls->lastline = ls->linenumber;
        if (ls->lookaheadToken != 0x11f) {
            ls->token = ls->lookaheadToken;
            ls->seminfo = ls->lookaheadSeminfo;
            ls->lookaheadToken = 0x11f;
        } else {
            ls->token = FUN_0021bbc0((LexState_21e860 *)ls, (int *)(&ls->seminfo));
        }
        FUN_0021ded0((LexState_21e860 *)ls, (ExpDesc_21e860 *)(&fr.e), 0);
        FUN_00221110((FuncState_21e860 *)(ls->fs), (ExpDesc_21e860 *)(&fr.e));
    } else {
        int k = FUN_002209e0(fs0, 1.0f);
        FUN_00220c10((FuncState_21e860 *)fs0, 1, fs0->freereg, (int)k);
        FUN_00220850((FuncState_21e860 *)fs0, 1);
    }
    FUN_0021e700((LexState_21e860 *)ls, fr.base, line, 1, 1);
}
