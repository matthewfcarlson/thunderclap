extern "C" double sqrt(double);
extern "C" double pow(double, double);
extern "C" void _ReadWriteBarrier();
extern const float gOne;
extern const float gZero;
float FUN_0024cdd0(float* a, float* b) {
    float x = a[0] - b[0];
    float y = a[1] - b[1];
    float z = a[2] - b[2];
    double s = sqrt(x * x + y * y + z * z);
    float d = (float)s;
    if ((float)s <= b[15])
        return gOne;
    if (d >= b[16])
        return gZero;
    float r = (float)pow(b[17], (d - b[15]) / (b[16] - b[15]));
    _ReadWriteBarrier();
    return r;
}