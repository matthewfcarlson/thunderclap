// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00221860 @ 0x00221860
// Lua 5.0 code generation for a binary operator (arithmetic, or comparison with swapped operands)
#include "decls/data/engine/unknown.h"

struct LexState_221860 {
    char pad[8];
    int lastline;       // 0x8
};

struct FuncState_221860 {
    char pad[0xc];
    LexState_221860* ls;       // 0xc
};

struct expdesc_221860 {
    int k;              // VRELOCABLE = 10, VJMP = 9
    int info;
    int aux;
    int t;
    int f;
};

                                              // opcode per operator
int __cdecl FUN_00220b20(FuncState_221860* fs, int instruction, int line);     // luaK_code
// condjump(fs, op, b, c) with the condition in eax
// equiv-conv: FUN_00220d10 stack stack stack eax
int FUN_00220d10(int op, int b, int c, int cond);

// equiv-conv: FUN_00221860 eax ecx edx edi stack
void FUN_00221860(int o1, int o2, int op, expdesc_221860* e, FuncState_221860* fs)
{
    if (op <= 4) {
        e->info = FUN_00220b20(fs, (((o2 << 9) | o1) << 6) | (op + 12), fs->ls->lastline);
        e->k = 10;
        return;
    }
    int cond = 1;
    if (op >= 10) {
        int tmp = o2;
        o2 = o1;
        o1 = tmp;
    } else if (op == 6) {
        cond = 0;
    }
    e->info = FUN_00220d10(((int*)((char*)&DAT_004271d4 + 32))[op], o2, o1, cond);
    e->k = 9;
}
