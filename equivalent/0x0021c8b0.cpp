// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0021c8b0 @ 0x0021c8b0
// Lua 5.0 adjust_assign
struct FuncState_21c8b0 {
    char pad[0x24];
    int freereg;        // 0x24
};

struct LexState_21c8b0 {
    char pad[0x1c];
    FuncState_21c8b0* fs;      // 0x1c
};

struct expdesc_21c8b0 {
    int k;              // VVOID = 0, VCALL = 12
    int info;
    int aux;
    int t;
    int f;
};

extern "C" void __cdecl FUN_00220a50(void *, void *, int);     // luaK_setcallreturns
extern "C" void __cdecl FUN_00220850(void *, int);                        // luaK_reserveregs
extern "C" void __cdecl FUN_00221110(void *, void *);                   // luaK_exp2nextreg
void __cdecl FUN_00220c40(FuncState_21c8b0* fs, int from, int n);              // luaK_nil

// equiv-conv: FUN_0021c8b0 eax ecx edx stack
extern "C" void FUN_0021c8b0(void * ls, void * e, int nexps, int nvars)
{
    FuncState_21c8b0* fs = ((LexState_21c8b0 *)ls)->fs;
    int extra = nvars - nexps;
    if (((expdesc_21c8b0 *)e)->k == 12) {
        extra++;
        if (extra <= 0) {
            extra = 0;
            FUN_00220a50((FuncState_21c8b0 *)fs, (expdesc_21c8b0 *)((expdesc_21c8b0 *)e), extra);
        } else {
            FUN_00220850((FuncState_21c8b0 *)fs, extra - 1);
            FUN_00220a50((FuncState_21c8b0 *)fs, (expdesc_21c8b0 *)((expdesc_21c8b0 *)e), extra);
        }
    } else {
        if (((expdesc_21c8b0 *)e)->k != 0)
            FUN_00221110((FuncState_21c8b0 *)fs, (expdesc_21c8b0 *)((expdesc_21c8b0 *)e));
        if (extra > 0) {
            int reg = fs->freereg;
            FUN_00220850((FuncState_21c8b0 *)fs, extra);
            FUN_00220c40(fs, reg, extra);
        }
    }
}
