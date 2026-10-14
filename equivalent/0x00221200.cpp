// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00221200 @ 0x00221200
// Lua 5.0 luaK_exp2RK
struct FuncState {
    char pad[0x28];
    int nk;
};

struct expdesc {
    int k;          // VNIL = 1, VK = 4
    int info;
    int aux;
    int t;
    int f;
};

void __cdecl FUN_00220d90(FuncState* fs, expdesc* e);       // luaK_dischargevars
int __cdecl FUN_00221190(FuncState* fs, expdesc* e);        // luaK_exp2anyreg
// nil_constant(fs)
// equiv-conv: FUN_00220a10 eax
int FUN_00220a10(FuncState* fs);

int FUN_00221200(FuncState* fs, expdesc* e)
{
    if (e->t == e->f)
        FUN_00220d90(fs, e);
    else
        FUN_00221190(fs, e);
    switch (e->k) {
    case 1:
        if (fs->nk + 250 <= 511) {
            e->info = FUN_00220a10(fs);
            e->k = 4;
            return e->info + 250;
        }
        break;
    case 4:
        if (e->info + 250 <= 511)
            return e->info + 250;
        break;
    }
    return FUN_00221190(fs, e);
}
