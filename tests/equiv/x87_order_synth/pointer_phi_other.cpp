// Negative: the same pointer pair chosen the other way round is not the same leaves.
// expect: clean=0 unmatched>=1
extern "C" void ref(float* a, float* b, float* out, int c)
{
    float* p = c ? a : b;
    out[0] = p[0] * p[1] + p[2];
}
extern "C" void test(float* a, float* b, float* out, int c)
{
    float* p = c ? a : out;
    out[0] = p[0] * p[1] + p[2];
}
