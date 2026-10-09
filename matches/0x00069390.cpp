extern const float zero;
double __stdcall target(float a, float b) {
    if (a <= zero)
        return zero;
    return b / a + b / a;
}