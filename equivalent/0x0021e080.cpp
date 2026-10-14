// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 2/2)
// FUN_0021e080 @ 0x0021e080
// 0x0021e080: Lua parser block(ls): enter a block, parse the chunk, then leave the block
// equiv-conv: FUN_0021e080 eax
// equiv-conv: FUN_0021c5b0 eax edx
struct LexState;
struct BlockCnt;

struct FuncState {
    char pad00[0xc];
    LexState* ls;
    char pad10[4];
    BlockCnt* bl;
    char pad18[0xc];
    int freereg;
    char pad28[0xc];
    unsigned char nactvar;
};

struct LexState {
    char pad00[0x1c];
    FuncState* fs;
};

struct BlockCnt {
    BlockCnt* previous;
    int breaklist;
    unsigned char nactvar;
    unsigned char upval;
    unsigned char isbreakable;
};

void __cdecl FUN_0021f640(LexState* ls);
void FUN_0021c5b0(LexState* ls, int nactvar);
void __cdecl FUN_00220bd0(FuncState* fs, int op, int a, int b, int c);
void __cdecl FUN_00220d70(FuncState* fs, int list);

void FUN_0021e080(LexState* ls)
{
    FuncState* fs = ls->fs;
    BlockCnt bl;

    bl.breaklist = -1;
    bl.isbreakable = 0;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    FUN_0021f640(ls);

    BlockCnt* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}
