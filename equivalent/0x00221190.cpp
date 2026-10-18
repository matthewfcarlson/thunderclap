// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_00221190 @ 0x00221190
// Lua 5.0 luaK_exp2anyreg
struct FuncState {
    char pad[0x34];
    unsigned char nactvar;
};

struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

void __cdecl FUN_00220d90(FuncState* fs, ExpDesc* e);
void __cdecl FUN_00221110(FuncState* fs, ExpDesc* e);
// equiv-conv: FUN_00220fe0 eax stack stack
void FUN_00220fe0(FuncState* fs, ExpDesc* e, int reg);

int __cdecl FUN_00221190(FuncState* fs, ExpDesc* e)
{
    FUN_00220d90(fs, e);
    if (e->k == 11) {
        if (e->t == e->f)
            return e->info;
        if (e->info >= fs->nactvar) {
            FUN_00220fe0(fs, e, e->info);
            return e->info;
        }
    }
    FUN_00221110(fs, e);
    return e->info;
}
