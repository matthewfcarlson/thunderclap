// A local filled by a callee keeps its value across a loop whose calls do not receive its address.
// expect: clean=1
extern "C" void fill(float* v);
extern "C" int other(int i);
extern "C" void ref(float* out, int n)
{
    float v[3];
    fill(v);
    for (int i = 0; i < n; i++) other(i);
    out[0] = v[0] * v[1] + v[2];
}
extern "C" void test(float* out, int n)
{
    float w[3];
    fill(w);
    for (int k = 0; k < n; k++) other(k);
    out[0] = w[1] * w[0] + w[2];
}
