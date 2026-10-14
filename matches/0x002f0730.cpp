extern float Compute(int, int, int);
extern const float gOne_2f0730;
bool Test(int a, int b, int c, int d, float* out) {
    float x = Compute(a, c, d);
    *out = x;
    if (x >= 0.0f) {
        if (x <= gOne_2f0730)
            return true;
    }
    return false;
}
