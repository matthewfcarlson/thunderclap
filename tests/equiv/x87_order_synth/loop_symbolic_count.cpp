// A loop whose trip count is not a constant is not unrolled: its first iteration pairs (the generic iteration is
// not compared), with no finding.
// expect: clean=1
extern "C" float ref(float* a, int n)
{
    float s = 0;
    for (int i = 0; i < n; i++) s = s + a[i] * a[i];
    return s;
}
extern "C" float test(float* a, int n)
{
    float s = 0;
    for (int i = 0; i < n; i++) s = s + a[i] * a[i];
    return s;
}
