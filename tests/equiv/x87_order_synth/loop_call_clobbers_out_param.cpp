// Negative: a loop whose calls receive the local's address does not keep its value.
// expect: unmatched=1
extern "C" void fill(float* v);
extern "C" void ref(float* out, int n)
{
    float v[3];
    fill(v);
    for (int i = 0; i < n; i++) fill(v);
    out[0] = v[0] * v[1] + v[2];
}
extern "C" void test(float* out, int n)
{
    float w[3];
    fill(w);
    for (int k = 0; k < n; k++) fill(w);
    out[0] = w[1] * w[0] + w[2];
}
