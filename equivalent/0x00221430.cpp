// STATUS: equivalent (tools/equiv.py level 3: 15657 inputs, branch coverage 12/12)
// FUN_00221430 @ 0x00221430
// FUN_00221430 @ 0x00221430
struct Proto_221430 {
    char pad0[0xc];
    unsigned int* code;     // 0x0c
};

struct FuncState_221430 {
    Proto_221430* f;               // 0x00
    char pad4[0x14];
    int pc;                 // 0x18
    char pad1c[8];
    int freereg;            // 0x24
    char pad28[0xc];
    unsigned char nactvar;  // 0x34
};

struct ExpDesc_221430 {
    int k;
    int info;
};

// equiv-conv: FUN_00220d10 eax esi stack stack stack
extern "C" unsigned int __cdecl FUN_00220d10(unsigned int, void *, unsigned int, unsigned int, unsigned int);
// equiv-conv: FUN_00220f80 eax stack
extern "C" void __cdecl FUN_00220f80(void *, int *);

// Emits a TEST on an expression: folds a preceding NOT, otherwise discharges the expression first.
// equiv-conv: FUN_00221430 eax edi ebx
extern "C" int FUN_00221430(void * fs, void * e, int cond)
{
    if (((ExpDesc_221430 *)e)->k == 10) {
        unsigned int i = ((FuncState_221430 *)fs)->f->code[((ExpDesc_221430 *)e)->info];
        if ((i & 0x3f) == 0x12) {
            ((FuncState_221430 *)fs)->pc--;
            return ((int)FUN_00220d10(0xff, (FuncState_221430 *)((FuncState_221430 *)fs), 0x18, (int)((i >> 15) & 0x1ff), (int)(cond == 0)));
        }
    }
    FUN_00220f80((FuncState_221430 *)((FuncState_221430 *)fs), (int *)(ExpDesc_221430 *)((ExpDesc_221430 *)e));
    if (((ExpDesc_221430 *)e)->k == 11) {
        if (((ExpDesc_221430 *)e)->info >= ((FuncState_221430 *)fs)->nactvar && ((ExpDesc_221430 *)e)->info < 0xfa)
            ((FuncState_221430 *)fs)->freereg--;
    }
    return ((int)FUN_00220d10(0xff, (FuncState_221430 *)((FuncState_221430 *)fs), 0x18, (int)(((ExpDesc_221430 *)e)->info), (int)cond));
}
