// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0025e5f0 @ 0x0025e5f0
// Angle in degrees between two vectors.
struct Vec3_25e5f0 {
    float x, y, z;
};

extern "C" double sqrt(double);
float __cdecl FUN_00018a20(float cosine);      // acos

float FUN_0025e5f0(const Vec3_25e5f0* a, const Vec3_25e5f0* b)
{
    double dot = (b->z * a->z + b->y * a->y) + a->x * b->x;
    double lenB = sqrt((b->y * b->y + b->z * b->z) + b->x * b->x);
    double lenA = sqrt((a->y * a->y + a->z * a->z) + a->x * a->x);
    return FUN_00018a20((float)(dot / (lenA * lenB))) * 57.2958f;
}
