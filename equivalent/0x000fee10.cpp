// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// FUN_000fee10 @ 0x000fee10
#include "decls/data/game/global.h"

inline void *operator new(unsigned int, void *p) { return p; }

struct Name8 {
    int lo, hi;
    void FUN_0027af00();
};

struct CCharacterGolem_fee10 {
    void FUN_000fed00();
};

struct Rng_fee10 {
    unsigned int s0;
    unsigned int s1;
};

Rng_fee10 *FUN_000964d0();

class CCharacterGolem {
public:
    virtual void vfunc_0();
    char pad04[0xf4];
    int f0f8;
    char pad0fc[4];
    int f100, f104, f108, f10c, f110, f114;
    Name8 n118;
    char pad120;
    char b121;
    char pad122[2];
    float f124;
    char b128, b129;
    char pad12a[2];
    float f12c;

    CCharacterGolem() {}
    CCharacterGolem *FUN_000fee10(int arg);
};

CCharacterGolem *CCharacterGolem::FUN_000fee10(int arg)
{
    ((CCharacterGolem_fee10 *)this)->FUN_000fed00();
    f0f8 = arg;
    new (this) CCharacterGolem;
    f100 = 0;
    f104 = 0;
    f108 = 0;
    f10c = 0;
    f110 = 0;
    f114 = 0;
    n118.FUN_0027af00();
    b121 = 0;

    // random float in [1, 2) from the shared multiply-with-carry generator
    Rng_fee10 *rng = FUN_000964d0();
    rng->s0 = (rng->s0 & 0xffff) * 0x9069 + (rng->s0 >> 16);
    rng->s1 = (rng->s1 & 0xffff) * 0x4650 + (rng->s1 >> 16);
    union {
        unsigned int bits;
        float value;
    } r;
    r.bits = (((rng->s0 << 16) + (rng->s1 & 0xffff)) & 0x7fffff) | 0x3f800000;
    b128 = 0;
    b129 = 0;
    f124 = r.value - 1.0f;
    f12c = -DAT_004e0a94;
    double next = DAT_004e0a94 + 0.03333333507180214f;
    DAT_004e0a94 = (float)next;
    if (next >= (*(float*)&DAT_0040d0f0))
        DAT_004e0a94 = DAT_004e0a94 - (*(float*)&DAT_0040d0f0);
    return this;
}
