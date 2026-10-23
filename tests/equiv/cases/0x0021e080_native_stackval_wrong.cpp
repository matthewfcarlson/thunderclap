// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 2/2)
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

    bl.breaklist = -1;
    bl.isbreakable = 1;   // WRONG: the node the callee finds through fs->bl (lua: a breakable block)
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
