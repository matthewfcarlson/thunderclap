// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 7/8, incomplete)
// FUN_0015cf40 @ 0x0015cf40
extern "C" double __cdecl floor(double);

union FloatBits_15cf40 {
    float f;
    unsigned int u;
};

// Wraps x into [0, 1); results within 1e-5 of 0 or 1 snap to 0.
float __cdecl FUN_0015cf40(float x)
{
    if (!(x < 0.0f) && !(x >= 1.0f))
        return x;
    double frac = -floor(x) + x;
    FloatBits_15cf40 d;
    d.f = (float)(frac - 1.0f);
    d.u &= 0x7fffffff;
    if (d.f <= 1e-5f)
        return 0.0f;
    d.f = (float)frac;
    d.u &= 0x7fffffff;
    if (d.f <= 1e-5f)
        return 0.0f;
    return (float)frac;
}
