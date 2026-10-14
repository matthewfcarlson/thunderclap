// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002214b0 @ 0x002214b0
// Lua 5.0 style: discharge an expression and store it into the slot of the destination expdesc.
struct FuncState;

struct expdesc_2214b0 {
    int k;
    int info;
    int aux;
    int pad;
    int dst;
};

void __cdecl FUN_00220d90(FuncState* fs, expdesc_2214b0* e);
int __cdecl FUN_00220cd0(FuncState* fs);
// equiv-conv: FUN_00220ab0 ecx eax
void FUN_00220ab0(FuncState* fs, expdesc_2214b0* e);
// equiv-conv: FUN_00221430 eax edi ebx
int FUN_00221430(FuncState* fs, expdesc_2214b0* e, int flag);
void __cdecl FUN_002207c0(FuncState* fs, int* dst, int value);

void FUN_002214b0(FuncState* fs, expdesc_2214b0* e)
{
    FUN_00220d90(fs, e);
    int value;
    switch (e->k) {
    case 2:
    case 4:
        value = -1;
        break;
    case 3:
        value = FUN_00220cd0(fs);
        break;
    case 9:
        FUN_00220ab0(fs, e);
        value = e->info;
        break;
    default:
        value = FUN_00221430(fs, e, 0);
        break;
    }
    FUN_002207c0(fs, &e->dst, value);
}
