extern "C" double atan2(double, double);
extern const float kEps;
extern const float kZero;
extern const float kTwoPi;
union FU {
    float f;
    unsigned u;
};
inline float Abs(float x) {
    FU t;
    t.f = x;
    t.u &= 0x7fffffff;
    return t.f;
}
float Angle(float a, float b) {
    if (Abs(a) <= kEps && Abs(b) <= kEps)
        return kZero;
    float r = (float)atan2(-a, -b);
    if (r < kZero)
        r += kTwoPi;
    return r;
}
