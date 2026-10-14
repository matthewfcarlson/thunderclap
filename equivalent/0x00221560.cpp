// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00221560 @ 0x00221560
// Lua 5.0 style: discharge an expression and store it into the slot of the destination expdesc.
struct FuncState;

struct expdesc {
    int k;
    int info;
    int aux;
    int dst;
};

void __cdecl FUN_00220d90(FuncState* fs, expdesc* e);
int __cdecl FUN_00220cd0(FuncState* fs);
// equiv-conv: FUN_00221430 eax edi ebx
int FUN_00221430(FuncState* fs, expdesc* e, int flag);
void __cdecl FUN_002207c0(FuncState* fs, int* dst, int value);

void FUN_00221560(FuncState* fs, expdesc* e)
{
    FUN_00220d90(fs, e);
    int value;
    switch (e->k) {
    case 1:
    case 3:
        value = -1;
        break;
    case 2:
        value = FUN_00220cd0(fs);
        break;
    case 9:
        value = e->info;
        break;
    default:
        value = FUN_00221430(fs, e, 1);
        break;
    }
    FUN_002207c0(fs, &e->dst, value);
}
