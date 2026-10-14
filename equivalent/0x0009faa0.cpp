// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0009faa0 @ 0x0009faa0
extern "C" double exp(double x);

float __cdecl FUN_0009faa0(float from, float to, float a, float b)
{
    float t;
    if (b == 0.0f)
        t = 1.0f;
    else
        t = 1.0f - (float)exp(-(a / b));
    float r = from + (to - from) * t;
    if (r < 0.0f ? -r <= 1e-05f : r <= 1e-05f)
        return 0.0f;
    return r;
}
