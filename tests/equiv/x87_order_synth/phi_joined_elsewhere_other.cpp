// Negative: one alternative differs (the arms are not the reference's), so the roots stay unmatched.
// expect: clean=1 unmatched=1
extern "C" void ref(float* a, float* out, int c)
{
    if (c)
        out[0] = (a[0] * a[1]) * a[2] + a[3];
    else
        out[0] = (a[0] + a[1]) * a[2] + a[3];
}
extern "C" void test(float* a, float* out, int c)
{
    float s = c ? a[0] * a[1] : a[0] - a[1];
    out[0] = s * a[2] + a[3];
}
