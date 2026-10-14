// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0021cec0 @ 0x0021cec0
struct Exp_21cec0 { int k; int info; int aux; int t; int f; };
struct FuncState_21cec0 {
    char pad00[0x24];
    int freereg;
};
struct ConsControl_21cec0 {
    Exp_21cec0 v;
    Exp_21cec0* t;
    int nh;
    int na;
    int tostore;
};
void __cdecl FUN_00220a50(FuncState_21cec0* fs, Exp_21cec0* e, int nresults);
int __cdecl FUN_00220c10(FuncState_21cec0* fs, int op, int a, int bx);
void __cdecl FUN_00221110(FuncState_21cec0* fs, Exp_21cec0* e);

// Lua 5.0 lastlistfield(fs, cc): cc arrives in esi, fs in edi.
// equiv-conv: FUN_0021cec0 esi edi
void FUN_0021cec0(ConsControl_21cec0* cc, FuncState_21cec0* fs)
{
    if (cc->tostore == 0)
        return;
    if (cc->v.k == 12) {
        FUN_00220a50(fs, &cc->v, -1);
        FUN_00220c10(fs, 0x21, cc->t->info, cc->na - 1);
    } else {
        if (cc->v.k != 0)
            FUN_00221110(fs, &cc->v);
        FUN_00220c10(fs, 0x20, cc->t->info, cc->na - 1);
    }
    fs->freereg = cc->t->info + 1;
}
