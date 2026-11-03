#include "gen/owners.h"
void owners::Obj_2848b0::FUN_002848b0(hulk_intptr index, int value, int* out) {
    H1(value);
    H2(value);
    H3(value);
    H4(value);
    ++count;
    int* q = (int*)((char*)base + (((int)index) << 6) + 0x30);
    out[0] = q[0];
    out[1] = q[1];
    out[2] = q[2];
}