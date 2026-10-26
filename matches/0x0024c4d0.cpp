#include "decls/data/engine/audio.h"

struct Entry {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
unsigned __cdecl FUN_0024c4d0(unsigned* p, unsigned n) {
    unsigned x = *p;
    int i = (int)(x << 28) >> 28;
    unsigned d = ((x >> 4) & 31) * ((Entry*)&DAT_004cc254)[i].b;
    unsigned q = n / d;
    unsigned r = n % d;
    unsigned v = ((Entry*)&DAT_004cc254)[i].a;
    unsigned z = q * v;
    return z + r * v / d;
}