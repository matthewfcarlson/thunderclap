// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// FUN_00216d30 @ 0x00216d30
// equiv-conv: FUN_00216d30 ecx eax
struct Ctx;

struct Op {
    char pad0[4];
    unsigned char kind;
    char pad5[7];
    int arg;
};

void __cdecl FUN_00219730(Ctx *c, Op *o);
void __cdecl FUN_002197d0(Ctx *c, Op *o);
void __cdecl FUN_0021add0(Ctx *c, Op *o, int a, int b);
void __cdecl FUN_00219d20(Ctx *c, Op *o);
void __cdecl FUN_00215090(Ctx *c, Op *o);

void __cdecl FUN_00216d30(Ctx *c, Op *o)
{
    switch (o->kind) {
    case 4:
        FUN_0021add0(c, o, o->arg + 0x11, 0);
        break;
    case 5:
        FUN_00219d20(c, o);
        break;
    case 6:
        FUN_002197d0(c, o);
        break;
    case 7:
        FUN_0021add0(c, o, o->arg + 0x10, 0);
        break;
    case 8:
        FUN_00215090(c, o);
        break;
    case 9:
        FUN_00219730(c, o);
        break;
    case 10:
        FUN_0021add0(c, o, 0x14, 0);
        break;
    }
}
