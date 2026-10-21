// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 6/6)
// FUN_000189c0 @ 0x000189c0
// Clamping asin: the argument is limited to [-1, 1] (NaN becomes -1) before the CRT's __CIasin.
extern "C" double asin(double);

// equiv-map: __CIasin = 0x003442bc
float __cdecl FUN_000189c0(float x)
{
    if (!(x >= -1.0f && x <= 1.0f))
        x = (x > 1.0f) ? 0.5f : -1.0f;
    double r = asin(x);
    return (float)r;
}
