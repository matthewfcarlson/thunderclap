extern const float one;
extern "C" double sqrt(double);
void __fastcall Normalize(float* p, void*) {
    float f = one / (float)sqrt(p[2] * p[2] + p[1] * p[1] + p[0] * p[0]);
    p[0] = f * p[0];
    p[1] = f * p[1];
    p[2] = f * p[2];
}