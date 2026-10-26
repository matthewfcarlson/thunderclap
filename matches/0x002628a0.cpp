#include "decls/data/engine/audio.h"
// data: gRateTable = DAT_0042ac18, gStepTable = DAT_0042ac58

int FUN_002628a0(int flags, int* state, int* value) {
    int step = ((int*)&DAT_0042ac58)[state[0]];
    int delta = step >> 3;
    if (flags & 1)
        delta += step >> 2;
    if (flags & 2)
        delta += step >> 1;
    if (flags & 4)
        delta += step;
    if (flags & 8)
        delta = -delta;
    *value += delta;
    if (*value > 32767)
        *value = 32767;
    else if (*value < -32768)
        *value = -32768;
    state[0] += ((int*)&DAT_0042ac18)[flags];
    if (state[0] < 0)
        state[0] = 0;
    else if (state[0] > 88)
        state[0] = 88;
    return *value;
}