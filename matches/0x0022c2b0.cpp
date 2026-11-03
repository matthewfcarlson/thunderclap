#include "gen/owners.h"
void owners::Mat_22c2b0::FUN_0022c2b0(float* v, float* out) {
    float b = v[0] * x1 + v[1] * x5 + v[2] * x9 + x13;
    float c = v[0] * x2 + v[1] * x6 + v[2] * x10 + x14;
    float a = v[1] * x4 + v[2] * x8 + v[0] * x0 + x12;  // the listing's order (MSVC 7.1 reassociates)
    out[0] = a;
    out[1] = b;
    out[2] = c;
}
