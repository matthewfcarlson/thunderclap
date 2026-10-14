extern const float zero_83d90;
extern const float one;
extern const float negone;
float FUN_00083d90(float* p) {
    if (*p < zero_83d90)
        return negone;
    if (*p > zero_83d90)
        return one;
    return zero_83d90;
}
