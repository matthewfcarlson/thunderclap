extern "C" float gFive = 5.0f;
extern "C" float gNegFive = -5.0f;
int FUN_000658d0(float* a, float* b, float* c, float* out) {
    float v = (a[1] * c[0] - a[0] * c[1]) + (b[0] * c[1] - b[1] * c[0]) + (b[1] * a[0] - b[0] * a[1]);  // the listing's order (MSVC 7.1 reassociates; clang does not)
    *out = v;
    if (v > gFive)
        return -1;
    if (v < gNegFive)
        return 1;
    return 0;
}