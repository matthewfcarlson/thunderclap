// STATUS: equivalent (tools/equiv.py level 3: 4477 inputs, branch coverage 92/120, incomplete)
// FUN_002142d0 @ 0x002142d0
struct TValue {
    int tt;
    int value;
};

struct Proto {
    char pad0[8];
    TValue *k;
    unsigned int *code;
    Proto **p;
    char pad14[0x28 - 0x14];
    int sizek;
    int sizecode;
    int sizelineinfo;
    int sizep;
    char pad38[0x44 - 0x38];
    unsigned char nups;
    char pad45[2];
    unsigned char maxstacksize;
};

extern unsigned char DAT_00426ba4[36];

// equiv-conv: FUN_00214280 eax ecx edx
int FUN_00214280(int mode, int r, Proto *pt);
// equiv-conv: FUN_00214250 eax edx
int FUN_00214250(Proto *pt, int pc);

// Lua 5.0 luaG_symbexec (with precheck)
unsigned int __cdecl FUN_002142d0(Proto *pt, int lastpc, int reg)
{
    int sizecode = pt->sizecode;
    int last = sizecode - 1;
    unsigned char maxstack = pt->maxstacksize;
    int pc;

    if (maxstack > 250)
        return 0;
    if (pt->sizelineinfo != sizecode && pt->sizelineinfo != 0)
        return 0;
    unsigned int *code = pt->code;
    if ((code[sizecode - 1] & 0x3f) != 0x1b)
        return 0;

    for (pc = 0; pc < lastpc; pc++) {
        unsigned int i = code[pc];
        int op = i & 0x3f;
        int a = i >> 24;
        int b = 0;
        int c = 0;
        int maxs;
        unsigned int m;

        if (op >= 0x24)
            return 0;
        maxs = maxstack;
        if (a >= maxs)
            return 0;
        m = DAT_00426ba4[op];
        switch (m & 3) {
        case 0:
            b = (i >> 15) & 0x1ff;
            c = (i >> 6) & 0x1ff;
            if (!FUN_00214280((m >> 4) & 3, b, pt))
                return 0;
            if (!FUN_00214280((m >> 2) & 3, c, pt))
                return 0;
            break;
        case 1:
            b = (i >> 6) & 0x3ffff;
            if ((m & 0x30) == 0x30) {
                if (b >= pt->sizek)
                    return 0;
            }
            break;
        case 2:
            b = ((i >> 6) & 0x3ffff) - 0x1ffff;
            if ((m & 0x30) == 0x20) {
                int dest = b + pc + 1;
                if (dest < 0 || dest >= sizecode)
                    return 0;
            }
            break;
        }

        m = DAT_00426ba4[op];
        if (m & 0x40) {
            if (a == reg)
                last = pc;
        }
        if (m & 0x80) {
            if (pc + 2 >= sizecode)
                return 0;
            if ((code[pc + 1] & 0x3f) != 0x14)
                return 0;
        }

        switch (op) {
        case 2:
            if (c != 0 && pc + 2 >= sizecode)
                return 0;
            break;
        case 3:
            if (a <= reg && reg <= b)
                last = pc;
            break;
        case 4:
        case 8:
            if (b >= pt->nups)
                return 0;
            break;
        case 5:
        case 7:
            if (pt->k[b].tt != 4)
                return 0;
            break;
        case 11:
            if (a + 1 >= maxs)
                return 0;
            if (reg == a + 1)
                last = pc;
            break;
        case 19:
            if (b >= c)
                return 0;
            break;
        case 30:
            if (a + 5 >= maxs)
                return 0;
            if (reg >= a)
                last = pc;
            break;
        case 28:
        case 29:
        case 31:
            if (a + 3 >= maxs)
                return 0;
            /* fall through */
        case 20: {
            int dest = pc + 1 + b;
            if (reg != 0xff && pc < dest && dest <= lastpc)
                pc += b;
            break;
        }
        case 25:
        case 26:
            if (b != 0) {
                if (a + b - 1 >= maxs)
                    return 0;
            }
            c--;
            if (c == -1) {
                if (!FUN_00214250(pt, pc))
                    return 0;
            } else if (c != 0) {
                if (a + c - 1 >= maxs)
                    return 0;
            }
            if (reg >= a)
                last = pc;
            break;
        case 27:
            b--;
            if (b > 0) {
                if (a + b - 1 >= maxs)
                    return 0;
            }
            break;
        case 32:
            b &= 0x1f;
            if (a + b + 1 >= maxs)
                return 0;
            break;
        case 35: {
            if (b >= pt->sizep)
                return 0;
            int nup = pt->p[b]->nups;
            if (pc + nup >= sizecode)
                return 0;
            for (; nup > 0; nup--) {
                unsigned int op1 = code[pc + nup] & 0x3f;
                if (op1 != 4 && op1 != 0)
                    return 0;
            }
            break;
        }
        default:
            break;
        }
    }
    return code[last];
}
