#include "decls/data/game/global.h"

struct Object {
    char pad0[0x1f4];
    unsigned a[6];
    char pad1[8];
    unsigned b214, b218;
    float b21c, b220;
    unsigned b224, b228, b22c, b230;
    char pad2[0x2cc - 0x234];
    unsigned c[6];
    char pad3[0x444 - 0x2e4];
    unsigned field444;
    float field448;
    unsigned field44c;
    char pad4[0x488 - 0x450];
    unsigned field488;
    void FUN_000a2cc0(unsigned, unsigned, unsigned, float, unsigned);
    void FUN_000a2de0(unsigned, unsigned, unsigned, unsigned);
    void FUN_000a2e60(unsigned arg, unsigned char flag);
};
void Object::FUN_000a2e60(unsigned arg, unsigned char flag) {
    if (flag)
        FUN_000a2cc0(arg, field44c, field444, (*(float*)&DAT_0049ec64), 0);
    else
        FUN_000a2de0(arg, field44c, field444, 0);
    for (int i = 5; i >= 0; --i)
        a[i] = 0;
    for (int j = 5; j >= 0; --j)
        c[j] = 0;
    float value = field448;
    b220 = value;
    b228 = 0;
    b224 = 0;
    b21c = value;
    b218 = 0;
    b214 = 0;
    b230 = 0;
    b22c = 0;
    field488 = 0;
}
