// Negative: a local the loop writes is not kept across it: the first iteration pairs, the store after the loop
// (which reads the loop-carried value) stays unmatched (generic-iteration roots are not compared).
// expect: clean=1 unmatched=1
extern "C" void ref(float* a, float* out, int n)
{
    float acc = a[0];
    for (int i = 0; i < n; i++) acc = acc * a[1];
    out[0] = acc + a[2];
}
extern "C" void test(float* a, float* out, int n)
{
    float acc = a[0];
    for (int i = 0; i < n; i++) acc = acc * a[1];
    out[0] = a[2] + acc;
}
