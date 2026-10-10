// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_0031b390 @ 0x0031b390
struct GammaRamp {
    unsigned char red[256];
    unsigned char green[256];
    unsigned char blue[256];
};
namespace D3D8 {
void __stdcall D3DDevice_SetGammaRamp(unsigned long flags, GammaRamp* ramp);
}
extern "C" double pow(double, double);
struct GammaControl {
    char pad0[0x12c];
    unsigned char srcRed[256];
    unsigned char srcGreen[256];
    unsigned char srcBlue[256];
    char pad1[0x484 - 0x42c];
    float gammaR;
    float gammaG;
    float gammaB;
    void Apply(float r, float g, float b);
};
void GammaControl::Apply(float r, float g, float b) {
    GammaRamp ramp;
    gammaR = r;
    gammaG = g;
    gammaB = b;
    double invR = 1.0 / r;
    double invG = 1.0 / g;
    double invB = 1.0 / b;
    for (int i = 0; i < 256; i++) {
        double vr = pow(srcRed[i] * 0.00390625, invR);
        double vg = pow(srcGreen[i] * 0.00390625, invG);
        double vb = pow(srcBlue[i] * 0.00390625, invB);
        if (vr > 1.0)
            vr = 1.0;
        ramp.red[i] = (unsigned char)(int)(vr * 256.0);
        if (vg > 1.0)
            vg = 1.0;
        ramp.green[i] = (unsigned char)(int)(vg * 256.0);
        if (vb > 1.0)
            vb = 1.0;
        ramp.blue[i] = (unsigned char)(int)(vb * 256.0);
    }
    D3D8::D3DDevice_SetGammaRamp(1, &ramp);
}
