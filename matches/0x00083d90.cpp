extern const float zero;
extern const float one;
extern const float negone;
float FUN_00083d90(float* p) {
    if (*p < zero)
        return negone;
    if (*p > zero)
        return one;
    return zero;
}
