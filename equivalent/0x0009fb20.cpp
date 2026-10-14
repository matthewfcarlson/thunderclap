// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0009fb20 @ 0x0009fb20
extern "C" double __cdecl exp(double);
float __cdecl FUN_0009fb20(float a, float b, float c, float dt, float tau) {
    double factor = 1.0;
    if (tau != 0.0f) factor = 1.0 - exp(-(double)dt / tau);
    double second = 0.0;
    if (dt != 0.0f) second = 1.0 - factor / dt * tau;
    double result = a + ((double)b - a) * factor + ((double)c - b) * second;
    union { float f; unsigned int u; } magnitude;
    magnitude.f = (float)result;
    magnitude.u &= 0x7fffffff;
    if (magnitude.f <= 1e-5f) return 0.0f;
    return (float)result;
}