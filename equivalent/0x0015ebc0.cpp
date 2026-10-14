// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 11/12, incomplete)
// FUN_0015ebc0 @ 0x0015ebc0
extern float DAT_004e11bc;
extern unsigned int DAT_004e11c0;

float __cdecl FUN_00224fc0(float a, float b);
float __cdecl FUN_0004af40(float lo, float hi, float v);

class Table_15ebc0 {
public:
    char pad0[0x28];
    float lo[4];
    float hi[4];
    float FUN_0015ebc0(float t, float a, float b);
};

float Table_15ebc0::FUN_0015ebc0(float t, float a, float b)
{
    if (!(t > 0.0f))
        return 0.0f;
    float r1 = FUN_00224fc0(a, b);
    float r2 = FUN_0004af40(0.0f, 6.2831855f, r1);
    if (!(DAT_004e11c0 & 1)) {
        DAT_004e11c0 |= 1;
        DAT_004e11bc = 1.5707964f;
    }
    float inv = 1.0f / DAT_004e11bc;
    int quad = (int)(inv * r2);
    int i0 = quad % 4;
    int i1 = (i0 + 1) % 4;
    float f = (r2 - (float)i0 * DAT_004e11bc) * inv;
    if (!(t > 0.5f)) {
        return ((1.0f - f) * lo[i0] + f * lo[i1]) * (t + t);
    }
    if (t < 1.0f) {
        float h = (t - 0.5f) + (t - 0.5f);
        float a1 = (1.0f - f) * lo[i0] + f * lo[i1];
        float b1 = (1.0f - f) * hi[i0] + f * hi[i1];
        return (1.0f - h) * a1 + b1 * h;
    }
    return ((1.0f - f) * hi[i0] + f * hi[i1]) * t;
}
