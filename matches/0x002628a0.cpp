extern int gStepTable[16];
extern int gRateTable[16];
int FUN_002628a0(int flags, int* state, int* value) {
    int step = gStepTable[state[0]];
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
    state[0] += gRateTable[flags];
    if (state[0] < 0)
        state[0] = 0;
    else if (state[0] > 88)
        state[0] = 88;
    return *value;
}