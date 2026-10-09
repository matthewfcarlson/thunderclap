extern "C" double atan2(double y, double x);
extern const float gZero;
extern const float gEps;
extern const float gDeg;
float __cdecl Wrap(float v);
union Bits {
    float f;
    unsigned long u;
};
float __cdecl Fn(float* p) {
    Bits a;
    a.f = p[0];
    a.u &= 0x7fffffffUL;
    if (a.f <= gEps) {
        Bits b;
        b.f = p[2];
        b.u &= 0x7fffffffUL;
        if (b.f <= gEps)
            return gZero;
    }
    return Wrap((float)(atan2(p[0], p[2]) * gDeg));
}
