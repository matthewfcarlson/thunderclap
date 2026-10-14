extern "C" double atan2(double y, double x);
extern const float gZero_a0450;
extern const float gEps;
extern const float gDeg;
float __cdecl Wrap(float v);
union Bits_a0450 {
    float f;
    unsigned long u;
};
float __cdecl Fn(float* p) {
    Bits_a0450 a;
    a.f = p[0];
    a.u &= 0x7fffffffUL;
    if (a.f <= gEps) {
        Bits_a0450 b;
        b.f = p[2];
        b.u &= 0x7fffffffUL;
        if (b.f <= gEps)
            return gZero_a0450;
    }
    return Wrap((float)(atan2(p[0], p[2]) * gDeg));
}
