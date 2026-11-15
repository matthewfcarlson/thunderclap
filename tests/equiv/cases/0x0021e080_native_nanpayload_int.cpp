// STATUS: must fail, also with EQUIV_ON=nanpayload (tools/equiv.py --wine level 3)
// (rev3, D39 review) bl.breaklist is an int (Lua's NO_JUMP, -1); the mutant stores -2 on odd nactvar. 0xffffffff and
// 0xfffffffe both have a quiet-NaN bit pattern, but this is an integer difference the rule must never set aside.
// FUN_0021e080 @ 0x0021e080
// 0x0021e080: Lua parser block(ls): enter a block, parse the chunk, then leave the block
// equiv-conv: FUN_0021e080 eax
// equiv-conv: FUN_0021c5b0 eax edx
struct LexState_21e080;
struct BlockCnt_21e080;

struct FuncState_21e080 {
    char pad00[0xc];
    LexState_21e080* ls;
    char pad10[4];
    BlockCnt_21e080* bl;
    char pad18[0xc];
    int freereg;
    char pad28[0xc];
    unsigned char nactvar;
};

struct LexState_21e080 {
    char pad00[0x1c];
    FuncState_21e080* fs;
};

struct BlockCnt_21e080 {
    BlockCnt_21e080* previous;
    int breaklist;
    unsigned char nactvar;
    unsigned char upval;
    unsigned char isbreakable;
};

void __cdecl FUN_0021f640(LexState_21e080* ls);
void FUN_0021c5b0(LexState_21e080* ls, int nactvar);
void __cdecl FUN_00220bd0(FuncState_21e080* fs, int op, int a, int b, int c);
void __cdecl FUN_00220d70(FuncState_21e080* fs, int list);

void FUN_0021e080(LexState_21e080* ls)
{
    FuncState_21e080* fs = ls->fs;
    BlockCnt_21e080 bl;

    bl.breaklist = (fs->nactvar & 1) ? -2 : -1;   // WRONG on odd nactvar: an integer, not a float
    bl.isbreakable = 0;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    FUN_0021f640(ls);

    BlockCnt_21e080* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}
