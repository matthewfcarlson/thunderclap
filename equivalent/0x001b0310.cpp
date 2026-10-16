// STATUS: equivalent (tools/equiv.py level 3: 3029 inputs, branch coverage 23/23)
// FUN_001b0310 @ 0x001b0310
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"

extern "C" int atexit(void (*)());

struct Key_1b0310 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

void FUN_00363fd0();
bool FUN_00044500(void *p);


struct Inner_1b0310 {
    char pad0[0x14];
    void *f14;
};

struct Attacker_1b0310 {
    char pad0[0x11c];
    Inner_1b0310 *f11c;
    int FUN_00036e40(Key_1b0310 *k);
};

struct Victim {
    char pad0[0x230];
    float f230;
    int FUN_001d64a0();
};

// equiv-conv: FUN_001b0310 esi edi
float FUN_001b0310(Attacker_1b0310 *atk, Victim *vic)
{
    float v;
    if (atk != 0) {
        if ((DAT_004e1800 & 1) == 0) {
            DAT_004e1800 |= 1;
            (*(Key_1b0310*)((char*)&DAT_004e17c0 + 56)).FUN_0027af00();
            atexit(FUN_00363fd0);
        }
        (*(Key_1b0310*)((char*)&DAT_004e17c0 + 56)).FUN_0027b040("no_thrown_damage");
        if (atk->FUN_00036e40(((Key_1b0310*)((char*)&DAT_004e17c0 + 56))) != 0)
            return (*(float*)&DAT_003f32e0);
    }
    v = vic->f230;
    if (v >= (*(float*)&DAT_003f32e0))
        return v;
    switch (vic->FUN_001d64a0()) {
    case 2:
    case 6:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3700 : DAT_004c3704;
    case 3:
    case 7:
    case 10:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3708 : DAT_004c370c;
    case 4:
    case 11:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c3710 : DAT_004c3714;
    case 5:
        return FUN_00044500(atk->f11c->f14) ? DAT_004c36f8 : DAT_004c36fc;
    }
    return v;
}
