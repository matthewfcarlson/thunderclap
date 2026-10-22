// Negative: a helper that groups the sum differently is a finding.
// expect: assoc=1
static float dot3(const float* a, const float* b) { return a[0] * b[0] + (a[1] * b[1] + a[2] * b[2]); }
extern "C" void ref(float* a, float* b, float* out)
{
    out[0] = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
extern "C" void test(float* a, float* b, float* out)
{
    out[0] = dot3(a, b);
}
