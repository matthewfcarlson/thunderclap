// A compare after a branch join pairs with the compares the reference makes in each arm.
// expect: clean=2
extern "C" void ref(float* a, int* out, int c)
{
    if (c) {
        if (a[0] * a[1] > 0.5f) out[0] = 1;
    } else {
        if (a[0] + a[1] > 0.5f) out[0] = 1;
    }
}
extern "C" void test(float* a, int* out, int c)
{
    float v = c ? a[0] * a[1] : a[0] + a[1];
    if (v > 0.5f) out[0] = 1;
}
