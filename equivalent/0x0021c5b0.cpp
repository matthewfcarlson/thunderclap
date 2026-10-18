// STATUS: equivalent (tools/equiv.py level 3: 123 inputs, branch coverage 4/4)
// FUN_0021c5b0 @ 0x0021c5b0
// Lua 5.0 removevars(ls, tolevel): close the scope of the active locals above tolevel
struct LocVar {
    void* name;
    int startpc;
    int endpc;
};
struct Proto {
    char pad0[0x18];
    LocVar* locvars;
};
struct FuncState {
    Proto* f;
    char pad4[0x14];
    int pc;
    char pad1c[0x18];
    unsigned char nactvar;
    char pad35[0x41];
    unsigned short actvar[200];
};
struct LexState {
    char pad0[0x1c];
    FuncState* fs;
};

// equiv-conv: FUN_0021c5b0 eax edx
void FUN_0021c5b0(LexState* ls, int tolevel)
{
    FuncState* fs = ls->fs;
    while (fs->nactvar > tolevel) {
        --fs->nactvar;
        fs->f->locvars[fs->actvar[fs->nactvar]].endpc = fs->pc;
    }
}
