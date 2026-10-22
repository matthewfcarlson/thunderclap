// A local filled by a callee through a pointer argument is named by (call, argument, offset).
// expect: clean=2
extern "C" void fill(float* v);
extern "C" void ref(float* out)
{
    float v[3];
    fill(v);
    out[0] = v[0] * v[1] + v[2];
    out[1] = v[1] * v[2];
}
extern "C" void test(float* out)
{
    float w[4];
    fill(w);
    out[0] = w[1] * w[0] + w[2];
    out[1] = w[2] * w[1];
}
