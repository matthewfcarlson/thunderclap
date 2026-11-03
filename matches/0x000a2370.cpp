#include "gen/owners.h"
extern const float gZero_a2370;
unsigned char owners::Obj_a2370::FUN_000a2370(float scale, float* out1, float* out2, unsigned char* outflag) {
    *out1 = 0.0f;
    *out2 = 0.0f;
    union {
        float f;
        unsigned int i;
    } x;
    x.f = a;
    x.i &= 0x7fffffff;
    unsigned char r = 0;
    if (x.f > 0.0f || c != 0.0f) {
        r = 1;
        *out1 = (c + c + x.f * a) * scale * 100.0f;
    }
    union {
        float f;
        unsigned int i;
    } y;
    y.f = b;
    y.i &= 0x7fffffff;
    if (x.f * 0.4f < y.f) {
        r = 1;
        *out2 = y.f * b * scale * 150.0f;
    }
    *outflag = flag;
    return r;
}