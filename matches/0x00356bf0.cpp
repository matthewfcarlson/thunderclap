extern "C" double sin(double);
extern "C" double cos(double);
void FUN_00356bf0(float a, float b, float c, float* x, float* y, float* z) {
    float s = (float)sin(c) * a;
    *x = s * (float)cos(b);
    *y = s * (float)sin(b);
    *z = a * (float)cos(c);
}
