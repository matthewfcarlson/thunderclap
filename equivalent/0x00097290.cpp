// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 2/2)
// FUN_00097290 @ 0x00097290
extern "C" double sqrt(double);
float __cdecl FUN_00018a20(float cosine);

float FUN_00097290(float ax, float ay, float az, float bx, float by, float bz)
{
    double lenB = sqrt(bz * bz + by * by + bx * bx);
    double lenA = sqrt(az * az + ay * ay + ax * ax);
    double product = lenA * lenB;
    if (product <= 0.0f)
        return 0.0f;
    return FUN_00018a20((float)((bz * az + by * ay + bx * ax) / product));
}
