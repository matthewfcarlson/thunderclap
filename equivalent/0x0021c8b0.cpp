// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0021c8b0 @ 0x0021c8b0
// Lua 5.0 adjust_assign
struct FuncState {
    char pad[0x24];
    int freereg;        // 0x24
};

struct LexState {
    char pad[0x1c];
    FuncState* fs;      // 0x1c
};

struct expdesc {
    int k;              // VVOID = 0, VCALL = 12
    int info;
    int aux;
    int t;
    int f;
};

void __cdecl FUN_00220a50(FuncState* fs, expdesc* e, int nresults);     // luaK_setcallreturns
void __cdecl FUN_00220850(FuncState* fs, int n);                        // luaK_reserveregs
void __cdecl FUN_00221110(FuncState* fs, expdesc* e);                   // luaK_exp2nextreg
void __cdecl FUN_00220c40(FuncState* fs, int from, int n);              // luaK_nil

// equiv-conv: FUN_0021c8b0 eax ecx edx stack
void FUN_0021c8b0(LexState* ls, expdesc* e, int nexps, int nvars)
{
    FuncState* fs = ls->fs;
    int extra = nvars - nexps;
    if (e->k == 12) {
        extra++;
        if (extra <= 0) {
            extra = 0;
            FUN_00220a50(fs, e, extra);
        } else {
            FUN_00220850(fs, extra - 1);
            FUN_00220a50(fs, e, extra);
        }
    } else {
        if (e->k != 0)
            FUN_00221110(fs, e);
        if (extra > 0) {
            int reg = fs->freereg;
            FUN_00220850(fs, extra);
            FUN_00220c40(fs, reg, extra);
        }
    }
}
