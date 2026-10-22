// A loop whose trip count is not constant keeps what it does not write: the store after it still pairs.
// The first iteration pairs too (it runs on the entry state).
// expect: clean=2
extern "C" void ref(float* a, float* out, int n)
{
    for (int i = 0; i < n; i++) out[i + 1] = out[i] * 2.0f;
    out[0] = a[0] * a[1] + a[2];
}
extern "C" void test(float* a, float* out, int n)
{
    for (int i = 0; i < n; i++) out[i + 1] = out[i] * 2.0f;
    out[0] = a[2] + a[1] * a[0];
}
