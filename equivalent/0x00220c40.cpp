// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 10/10)
// FUN_00220c40 @ 0x00220c40
// Lua 5.0 luaK_nil: merge consecutive OP_LOADNIL instructions.
struct LexState {
    char pad[8];
    int lastline;               // 0x08
};

struct Proto {
    char pad[0xc];
    unsigned int *code;         // 0x0c
};

struct FuncState {
    Proto *f;                   // 0x00
    char pad04[8];
    LexState *ls;               // 0x0c
    char pad10[8];
    int pc;                     // 0x18
    int lasttarget;             // 0x1c
};

int __cdecl FUN_00220b20(FuncState *fs, unsigned int instruction, int line);     // luaK_code

void __cdecl FUN_00220c40(FuncState *fs, int from, int n) {
    if (fs->pc > fs->lasttarget) {
        unsigned int *previous = &fs->f->code[fs->pc - 1];
        unsigned int ins = *previous;
        if ((ins & 0x3f) == 3) {                         // OP_LOADNIL
            int pfrom = ins >> 24;
            int pto = (ins >> 15) & 0x1ff;
            if (pfrom <= from && from <= pto + 1) {
                if (from + n - 1 > pto)
                    *previous = (ins & ~0xff8000u) | (((from + n - 1) << 15) & 0xff8000u);
                return;
            }
        }
    }
    FUN_00220b20(fs, (((from + n - 1) | (from << 9)) << 15) | 3, fs->ls->lastline);
}
