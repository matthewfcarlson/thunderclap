// Negative: unrolling must still expose a grouping difference.
// expect: assoc=1 clean=2
extern "C" void ref(float* a, float* b)
{
    b[0] = a[0] + a[1] + a[2];
    b[1] = a[1] + a[2] + a[3];
    b[2] = a[2] + a[3] + a[4];
}
extern "C" void test(float* a, float* b)
{
    for (int i = 0; i < 3; i++)
        b[i] = (i == 1) ? a[i] + (a[i + 1] + a[i + 2]) : a[i] + a[i + 1] + a[i + 2];
}
