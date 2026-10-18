// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 2/2)
// FUN_00221ae0 @ 0x00221ae0
// FUN_00221ae0 @ 0x00221ae0
// Lua 5.0 luaK_patchlist(fs, list, target)
struct FuncState {
    char pad0[0x18];
    int pc;
    int lasttarget;
    int jpc;
};

// luaK_concat(fs, &fs->jpc, list)
void __cdecl FUN_002207c0(FuncState* fs, int* l1, int l2);
// patchlistaux: fs in ebx, list in edx, five more stack words
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
void FUN_00220650(int list, FuncState* fs, int a, int b, int c, int d, int e);

void __cdecl FUN_00221ae0(FuncState* fs, int list, int target)
{
    if (target == fs->pc) {
        fs->lasttarget = fs->pc;
        FUN_002207c0(fs, &fs->jpc, list);
    } else {
        FUN_00220650(list, fs, target, 0xff, target, 0xff, target);
    }
}
