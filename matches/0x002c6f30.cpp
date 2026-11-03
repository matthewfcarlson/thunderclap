#include "gen/owners.h"
void owners::C_2c6f30::FUN_002c6f30(int a, float* b, int c, float d) {
    float* p = arr[c] + a * 2;
    p[0] = (b[0] - p[0]) * d + p[0];
    p[1] = (b[1] - p[1]) * d + p[1];
}