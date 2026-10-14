struct M_22c3b0 {
    float a[12];
    void f(float* p, float* out);
};
void M_22c3b0::f(float* p, float* out) {
    float x = a[1] * p[0] + a[5] * p[1] + a[9] * p[2];
    float y = a[2] * p[0] + a[6] * p[1] + a[10] * p[2];
    float z = a[0] * p[0] + a[4] * p[1] + a[8] * p[2];
    out[0] = z;
    out[1] = x;
    out[2] = y;
}