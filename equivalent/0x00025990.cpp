// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00025990 @ 0x00025990
struct Vec3 { float x, y, z; };
float __cdecl FUN_00025990(const Vec3* a, const Vec3* b)
{
    float x = a->x - b->x;
    float y = a->y - b->y;
    float z = a->z - b->z;
    return x*x + y*y + z*z;
}