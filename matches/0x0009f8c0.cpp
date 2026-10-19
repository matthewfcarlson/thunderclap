extern "C" double sin(double);
extern "C" double cos(double);
extern const float rad;
float* FUN_0009f8c0(float* out, volatile float a, volatile float b, float r) {
    float aa = a * rad;
    float bb = b * rad;
    a = (float)cos(bb);
    out[0] = (float)(sin(aa) * a * r);
    out[1] = (float)(sin(bb) * r);
    out[2] = (float)(cos(aa) * a * r);
    return out;
}