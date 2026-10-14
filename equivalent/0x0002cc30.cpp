// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_0002cc30 @ 0x0002cc30
struct Triple_2cc30 {
    int a, b, c;
};

class Target_2cc30 {
public:
    unsigned char Method(int a0, Triple_2cc30 t, int a4, int a5, int a6, unsigned int flagWord, int a8);
};

typedef unsigned char (Target_2cc30::*Fn_2cc30)(int, Triple_2cc30, int, int, int, unsigned int, int);

struct Block_2cc30 {
    int a0;
    Triple_2cc30 t;
    int a4;
    int a5;
    int a6;
    unsigned char flag;
    char pad[3];
    int a8;
};

// The original reuses the dead `block` argument slot for the flag byte and pushes the whole
// dword, so the flag word keeps the pointer's high bytes: model it with a union.
union BlockArg {
    Block_2cc30* block;
    unsigned char flag;
    unsigned int word;
};

void FUN_0002cc30(Target_2cc30* self, BlockArg arg, unsigned char* out, Fn_2cc30 fn) {
    Block_2cc30* b = arg.block;
    int a0 = b->a0;
    Triple_2cc30 t = b->t;
    int a4 = b->a4;
    int a5 = b->a5;
    int a6 = b->a6;
    arg.flag = b->flag;
    unsigned char r = (self->*fn)(a0, t, a4, a5, a6, arg.word, b->a8);
    if (out)
        *out = r;
}
