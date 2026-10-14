// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// FUN_00221430 @ 0x00221430
struct Proto {
    char pad0[0xc];
    unsigned int* code;     // 0x0c
};

struct FuncState {
    Proto* f;               // 0x00
    char pad4[0x14];
    int pc;                 // 0x18
    char pad1c[8];
    int freereg;            // 0x24
    char pad28[0xc];
    unsigned char nactvar;  // 0x34
};

struct ExpDesc {
    int k;
    int info;
};

// equiv-conv: FUN_00220d10 eax stack stack stack
int FUN_00220d10(int a, int op, int b, int c);
// equiv-conv: FUN_00220f80 eax stack
void FUN_00220f80(FuncState* fs, ExpDesc* e);

// Emits a TEST on an expression: folds a preceding NOT, otherwise discharges the expression first.
// equiv-conv: FUN_00221430 eax edi ebx
int FUN_00221430(FuncState* fs, ExpDesc* e, int cond)
{
    if (e->k == 10) {
        unsigned int i = fs->f->code[e->info];
        if ((i & 0x3f) == 0x12) {
            fs->pc--;
            return FUN_00220d10(0xff, 0x18, (i >> 15) & 0x1ff, cond == 0);
        }
    }
    FUN_00220f80(fs, e);
    if (e->k == 11) {
        if (e->info >= fs->nactvar && e->info < 0xfa)
            fs->freereg--;
    }
    return FUN_00220d10(0xff, 0x18, e->info, cond);
}
