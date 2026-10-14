// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 13/14, incomplete)
// FUN_002205a0 @ 0x002205a0
// Lua 5.0 need_value
struct Proto { char pad0[0xc]; unsigned int *code; };
struct FuncState { Proto *f; };
extern unsigned char DAT_00426ba4[];

// equiv-conv: FUN_002205a0 ecx eax stack
int __cdecl FUN_002205a0(int list, FuncState *fs, int cond)
{
    while (list != -1) {
        unsigned int *pi = &fs->f->code[list];
        unsigned int *control = pi;
        if (list >= 1 && (DAT_00426ba4[pi[-1] & 0x3f] & 0x80))
            control = pi - 1;
        unsigned int i = *control;
        if ((i & 0x3f) != 0x18 || (int)((i >> 6) & 0x1ff) != cond)
            return 1;
        int offset = (int)((*pi >> 6) & 0x3ffff) - 0x1ffff;
        if (offset == -1)
            break;
        list = list + offset + 1;
    }
    return 0;
}
