extern "C" float FUN_000186b0(float* a, float* b, float* c) {
    if (*a >= *b && *a <= *c)
        return *a;
    if (*a > *c)
        return *c;
    return *b;
}