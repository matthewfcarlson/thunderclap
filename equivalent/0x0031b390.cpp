// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_0031b390 @ 0x0031b390
#include "gen/owners.h"
struct GammaRamp {
    unsigned char red[256];
    unsigned char green[256];
    unsigned char blue[256];
};
namespace D3D8 {
void __stdcall D3DDevice_SetGammaRamp(unsigned long flags, GammaRamp* ramp);
}
extern "C" double pow(double, double);
void owners::GammaControl_31b390::FUN_0031b390(float r, float g, float b) {
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
