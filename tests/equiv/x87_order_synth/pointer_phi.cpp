// A pointer chosen by a branch is a phi of its two values on both sides, so loads through it pair.
// expect: clean=1
extern "C" void ref(float* a, float* b, float* out, int c)
{
    float* p = c ? a : b;
    out[0] = p[0] * p[1] + p[2];
}
extern "C" void test(float* a, float* b, float* out, int c)
{
    float* p;
    if (c) p = a; else p = b;
    out[0] = p[2] + p[1] * p[0];
}
