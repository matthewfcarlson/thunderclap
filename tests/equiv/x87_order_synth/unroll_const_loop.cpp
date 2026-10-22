// A loop over a constant count is unrolled: its roots pair with the unrolled reference.
// expect: clean=3
extern "C" void ref(float* a, float* b)
{
    b[0] = a[0] * a[1] + a[2];
    b[1] = a[1] * a[2] + a[3];
    b[2] = a[2] * a[3] + a[4];
}
extern "C" void test(float* a, float* b)
{
    for (int i = 0; i < 3; i++)
        b[i] = a[i] * a[i + 1] + a[i + 2];
}
