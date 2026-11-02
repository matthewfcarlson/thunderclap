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
extern "C" void __cdecl FUN_00221110(void *, void *);
// equiv-conv: FUN_00220fe0 eax stack stack
void FUN_00220fe0(FuncState* fs, ExpDesc* e, int reg);

extern "C" int __cdecl FUN_00221190(void * fs, void * e)
{
    FUN_00220d90(((FuncState *)fs), ((ExpDesc *)e));
    if (((ExpDesc *)e)->k == 11) {
        if (((ExpDesc *)e)->t == ((ExpDesc *)e)->f)
            return ((ExpDesc *)e)->info;
        if (((ExpDesc *)e)->info >= ((FuncState *)fs)->nactvar) {
            FUN_00220fe0(((FuncState *)fs), ((ExpDesc *)e), ((ExpDesc *)e)->info);
            return ((ExpDesc *)e)->info;
        }
    }
    FUN_00221110((FuncState *)((FuncState *)fs), (ExpDesc *)((ExpDesc *)e));
    return ((ExpDesc *)e)->info;
}
