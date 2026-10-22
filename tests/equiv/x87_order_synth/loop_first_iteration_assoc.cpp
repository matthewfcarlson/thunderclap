// A grouping difference inside a loop of unknown trip count is found in its first iteration.
// expect: assoc=1
extern "C" void ref(float* a, float* out, int n)
{
    for (int i = 0; i < n; i++) out[i] = a[i] + a[i + 1] + a[i + 2];
}
extern "C" void test(float* a, float* out, int n)
{
    for (int i = 0; i < n; i++) out[i] = a[i] + (a[i + 1] + a[i + 2]);
}
