// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0004af40 @ 0x0004af40
extern "C" double __cdecl __floor_default(double);
extern float DAT_003f6b28;
union FloatBits { float f; unsigned u; };
float __cdecl FUN_0004af40(float a, float b, float x) {
    if (!(x < a) && !(x >= b)) return x;
    FloatBits d; d.f = a-b; d.u &= 0x7fffffff;
    if (d.f <= DAT_003f6b28) return a;
    float width = b-a;
    double n = __floor_default((double)((x-a)/width));
    float result = (float)(x - n*width);
    d.f = result-b; d.u &= 0x7fffffff;
    if (d.f <= DAT_003f6b28) return a;
    d.f = result-a; d.u &= 0x7fffffff;
    if (d.f <= DAT_003f6b28) return a;
    return result;
}