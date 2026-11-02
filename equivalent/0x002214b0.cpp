// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
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
extern "C" int __cdecl FUN_00220cd0(void *);
// equiv-conv: FUN_00220ab0 ecx eax
void FUN_00220ab0(FuncState* fs, expdesc_2214b0* e);
// equiv-conv: FUN_00221430 eax edi ebx
extern "C" int __cdecl FUN_00221430(void *, void *, int);
void __cdecl FUN_002207c0(FuncState* fs, int* dst, int value);

extern "C" void FUN_002214b0(void * fs, void * e_)
{
    expdesc_2214b0 * e = (expdesc_2214b0 *)e_;
    FUN_00220d90(((FuncState *)fs), e);
    int value;
    switch (e->k) {
    case 2:
    case 4:
        value = -1;
        break;
    case 3:
        value = FUN_00220cd0((FuncState *)((FuncState *)fs));
        break;
    case 9:
        FUN_00220ab0(((FuncState *)fs), e);
        value = e->info;
        break;
    default:
        value = FUN_00221430((FuncState *)((FuncState *)fs), (expdesc_2214b0 *)e, 0);
        break;
    }
    FUN_002207c0(((FuncState *)fs), &e->dst, value);
}
