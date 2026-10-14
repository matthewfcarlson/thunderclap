// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00221110 @ 0x00221110
// Lua 5.0 luaK_exp2nextreg
struct Proto_221110 { char pad0[0x47]; unsigned char maxstacksize; };
struct LexState;
struct FuncState_221110 {
    Proto_221110 *f;
    char pad4[8];
    LexState *ls;
    char pad10[0x14];
    int freereg;
    char pad28[0xc];
    unsigned char nactvar;
};
struct expdesc_221110 { int k; int info; };

void __cdecl FUN_00220d90(FuncState_221110 *fs, expdesc_221110 *e);
void __cdecl FUN_0021b060(LexState *ls, const char *msg);
// equiv-conv: FUN_00220fe0 eax stack stack
void __cdecl FUN_00220fe0(FuncState_221110 *fs, expdesc_221110 *e, int reg);

void FUN_00221110(FuncState_221110 *fs, expdesc_221110 *e)
{
    FUN_00220d90(fs, e);
    if (e->k == 0xb && e->info >= fs->nactvar && e->info < 0xfa)
        fs->freereg--;
    int newstack = fs->freereg + 1;
    if (newstack > fs->f->maxstacksize) {
        if (newstack >= 0xfa)
            FUN_0021b060(fs->ls, "function or expression too complex");
        fs->f->maxstacksize = (unsigned char)newstack;
    }
    fs->freereg = fs->freereg + 1;
    FUN_00220fe0(fs, e, fs->freereg - 1);
}
