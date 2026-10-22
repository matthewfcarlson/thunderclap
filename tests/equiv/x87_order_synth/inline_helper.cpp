// A helper the native build calls (clang -O0 does not inline) is executed in place: its return value and its
// stores through pointer arguments pair with the reference's inline code.
// expect: clean=3
static float dot3(const float* a, const float* b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
static void scale(float* v, float k) { v[0] = v[0] * k; v[1] = v[1] * k; }
extern "C" void ref(float* a, float* b, float* out, float k)
{
    out[0] = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    out[1] = out[1] * k;
    out[2] = out[2] * k;
}
extern "C" void test(float* a, float* b, float* out, float k)
{
    out[0] = dot3(a, b);
    scale(out + 1, k);
}
