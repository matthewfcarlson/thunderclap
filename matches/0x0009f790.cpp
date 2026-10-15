extern "C" double tan(double);
extern "C" double atan(double);
extern const float ratio, scaleOut;
void FUN_0009f790(float a, float b, float* c, float* d) {
    double t = tan(a * 0.008726646f) * ratio;
    *c = (float)(atan(b * t) * scaleOut);
    *d = (float)(atan(t) * scaleOut);
}