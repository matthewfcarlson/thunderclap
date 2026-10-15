extern "C" double sin(double);
extern "C" float asinf(float);
char calc(float a, float b, float c, float* out) {
    float v = (float)(sin(b * 0.017453292519943295f) / a * c);
    if (v > 1.0f)
        return 0;
    *out = asinf(v) * 57.295776f;
    return 1;
}